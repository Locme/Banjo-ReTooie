#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080076C_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080076C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800774: jal         0x800951B4
    // 0x80800778: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800951B4(rdram, ctx);
        goto after_0;
    // 0x80800778: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080077C: jal         0x80800000
    // 0x80800780: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bsbansnooze(rdram, ctx);
        goto after_1;
    // 0x80800780: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080078C: jr          $ra
    // 0x80800790: nop

    return;
    // 0x80800790: nop

;}
RECOMP_FUNC void func_80800070_chcheatopage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800078: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080007C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800080: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800084: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800088: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080008C: beq         $t6, $at, L_808000A4
    if (ctx->r14 == ctx->r1) {
        // 0x80800090: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000A4;
    }
    // 0x80800090: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800094: beq         $t6, $at, L_808000D8
    if (ctx->r14 == ctx->r1) {
        // 0x80800098: nop
    
            goto L_808000D8;
    }
    // 0x80800098: nop

    // 0x8080009C: b           L_80800114
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800114;
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000A4:
    // 0x808000A4: jal         0x800D8FF8
    // 0x808000A8: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808000A8: nop

    after_0:
    // 0x808000AC: lui         $at, 0x433A
    ctx->r1 = S32(0X433A << 16);
    // 0x808000B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000B4: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000C4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808000C8: jal         0x80103110
    // 0x808000CC: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x808000CC: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x808000D0: b           L_80800114
    // 0x808000D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800114;
    // 0x808000D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000D8:
    // 0x808000D8: jal         0x800D9078
    // 0x808000DC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x808000DC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x808000E0: beql        $v0, $zero, L_80800114
    if (ctx->r2 == 0) {
        // 0x808000E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800114;
    }
    goto skip_0;
    // 0x808000E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000E8: jal         0x800F54E4
    // 0x808000EC: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808000EC: nop

    after_3:
    // 0x808000F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000F4: jal         0x800F82D4
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_4;
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000FC: jal         0x800FFAB0
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800104: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    // 0x80800108: jal         0x800887D8
    // 0x8080010C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x8080010C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800114:
    // 0x80800114: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void func_80800DA4_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800DB0: jal         0x80100094
    // 0x80800DB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800DBC: jal         0x8008A0A0
    // 0x80800DC0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _subaddiemulti_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800DC0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x80800DC4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800DC8: lhu         $t6, 0x6E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X6E);
    // 0x80800DCC: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800DD0: ori         $t8, $t7, 0x5
    ctx->r24 = ctx->r15 | 0X5;
    // 0x80800DD4: sh          $t8, 0x6E($v0)
    MEM_H(0X6E, ctx->r2) = ctx->r24;
    // 0x80800DD8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DDC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x80800DE0: jal         0x80089980
    // 0x80800DE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _sumultiscore_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800DE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800DE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800DEC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800DF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800DF4: jal         0x80089988
    // 0x80800DF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800DF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80800DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E04: jr          $ra
    // 0x80800E08: nop

    return;
    // 0x80800E08: nop

;}
RECOMP_FUNC void _glid_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088688: syscall     697
    recomp_syscall_handler(rdram, ctx, 0x80088688);
    return;
    // 0x8008868C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80801180_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801184: addiu       $at, $zero, 0x17F8
    ctx->r1 = ADD32(0, 0X17F8);
    // 0x80801188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080118C: bne         $a1, $at, L_808011A8
    if (ctx->r5 != ctx->r1) {
        // 0x80801190: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808011A8;
    }
    // 0x80801190: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801194: jal         0x80100094
    // 0x80801198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080119C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x808011A0: b           L_808011AC
    // 0x808011A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_808011AC;
    // 0x808011A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_808011A8:
    // 0x808011A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808011AC:
    // 0x808011AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011B4: jr          $ra
    // 0x808011B8: nop

    return;
    // 0x808011B8: nop

;}
RECOMP_FUNC void func_8080038C_chklungophial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080038C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800390: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800398: bne         $a1, $at, L_808003B0
    if (ctx->r5 != ctx->r1) {
        // 0x8080039C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808003B0;
    }
    // 0x8080039C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808003A0: jal         0x808003C8
    // 0x808003A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808003C8_chklungophial(rdram, ctx);
        goto after_0;
    // 0x808003A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003A8: b           L_808003B8
    // 0x808003AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003B8;
    // 0x808003AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003B0:
    // 0x808003B0: b           L_808003B8
    // 0x808003B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003B8;
    // 0x808003B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003B8:
    // 0x808003B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003C0: jr          $ra
    // 0x808003C4: nop

    return;
    // 0x808003C4: nop

;}
RECOMP_FUNC void _chtntminecelldoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D38: syscall     233
    recomp_syscall_handler(rdram, ctx, 0x80085D38);
    return;
    // 0x80085D3C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void sumole_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000FC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800100: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800104: jal         0x80090178
    // 0x80800108: addiu       $a0, $zero, 0x1701
    ctx->r4 = ADD32(0, 0X1701);
    func_80090178(rdram, ctx);
        goto after_0;
    // 0x80800108: addiu       $a0, $zero, 0x1701
    ctx->r4 = ADD32(0, 0X1701);
    after_0:
    // 0x8080010C: bne         $v0, $zero, L_8080011C
    if (ctx->r2 != 0) {
        // 0x80800110: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_8080011C;
    }
    // 0x80800110: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800114: b           L_808001CC
    // 0x80800118: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001CC;
    // 0x80800118: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080011C:
    // 0x8080011C: beq         $t6, $zero, L_80800178
    if (ctx->r14 == 0) {
        // 0x80800120: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800178;
    }
    // 0x80800120: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800124: jal         0x8010CAC0
    // 0x80800128: addiu       $a1, $zero, 0x177
    ctx->r5 = ADD32(0, 0X177);
    func_8010CAC0(rdram, ctx);
        goto after_1;
    // 0x80800128: addiu       $a1, $zero, 0x177
    ctx->r5 = ADD32(0, 0X177);
    after_1:
    // 0x8080012C: beq         $v0, $zero, L_80800178
    if (ctx->r2 == 0) {
        // 0x80800130: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800178;
    }
    // 0x80800130: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800134: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800138: beq         $a0, $at, L_80800150
    if (ctx->r4 == ctx->r1) {
        // 0x8080013C: nop
    
            goto L_80800150;
    }
    // 0x8080013C: nop

    // 0x80800140: jal         0x800C6E38
    // 0x80800144: nop

    func_800C6E38(rdram, ctx);
        goto after_2;
    // 0x80800144: nop

    after_2:
    // 0x80800148: bnel        $v0, $zero, L_8080017C
    if (ctx->r2 != 0) {
        // 0x8080014C: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080017C;
    }
    goto skip_0;
    // 0x8080014C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_0:
L_80800150:
    // 0x80800150: jal         0x800D035C
    // 0x80800154: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800D035C(rdram, ctx);
        goto after_3;
    // 0x80800154: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_3:
    // 0x80800158: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    // 0x8080015C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800160: jal         0x800D2498
    // 0x80800164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_4;
    // 0x80800164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800168: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    // 0x8080016C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800170: jal         0x800D2498
    // 0x80800174: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_5;
    // 0x80800174: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_80800178:
    // 0x80800178: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_8080017C:
    // 0x8080017C: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x80800180: jal         0x8008A1D0
    // 0x80800184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80800184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800188: beql        $v0, $zero, L_808001CC
    if (ctx->r2 == 0) {
        // 0x8080018C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808001CC;
    }
    goto skip_1;
    // 0x8080018C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80800190: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800194: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800198: beql        $v0, $at, L_808001B8
    if (ctx->r2 == ctx->r1) {
        // 0x8080019C: lhu         $t3, 0x6E($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X6E);
            goto L_808001B8;
    }
    goto skip_2;
    // 0x8080019C: lhu         $t3, 0x6E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6E);
    skip_2:
    // 0x808001A0: lbu         $t0, 0x72($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X72);
    // 0x808001A4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x808001A8: andi        $t1, $t0, 0xFF03
    ctx->r9 = ctx->r8 & 0XFF03;
    // 0x808001AC: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x808001B0: sb          $t2, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r10;
    // 0x808001B4: lhu         $t3, 0x6E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6E);
L_808001B8:
    // 0x808001B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808001BC: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x808001C0: b           L_808001CC
    // 0x808001C4: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
        goto L_808001CC;
    // 0x808001C4: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
    // 0x808001C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001CC:
    // 0x808001CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001D8: jr          $ra
    // 0x808001DC: nop

    return;
    // 0x808001DC: nop

;}
RECOMP_FUNC void func_800DE448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DE44C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DE450: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DE454: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800DE458: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800DE45C: jal         0x800A7180
    // 0x800DE460: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800A7180(rdram, ctx);
        goto after_0;
    // 0x800DE460: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800DE464: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800DE468: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800DE46C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800DE470: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800DE474: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800DE478: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800DE47C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800DE480: jal         0x800DE498
    // 0x800DE484: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_800DE498(rdram, ctx);
        goto after_1;
    // 0x800DE484: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x800DE488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DE48C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DE490: jr          $ra
    // 0x800DE494: nop

    return;
    // 0x800DE494: nop

;}
RECOMP_FUNC void chnests_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FBC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X1500) << 16);
    // 0x80800FC0: jr          $ra
    // 0x80800FC4: addiu       $v0, $v0, 0x1500
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1500));
    return;
    // 0x80800FC4: addiu       $v0, $v0, 0x1500
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1500));
;}
RECOMP_FUNC void func_8008B954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B954: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8008B958: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8008B95C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008B960: lw          $t9, 0x6CC0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CC0);
    // 0x8008B964: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8008B968: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B96C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8008B970: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8008B974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B978: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008B97C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8008B980: lh          $a1, -0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, -0X6);
    // 0x8008B984: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x8008B988: beq         $a1, $zero, L_8008B9A8
    if (ctx->r5 == 0) {
        // 0x8008B98C: sll         $a0, $a1, 16
        ctx->r4 = S32(ctx->r5 << 16);
            goto L_8008B9A8;
    }
    // 0x8008B98C: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x8008B990: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8008B994: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8008B998: jal         0x800DFCC0
    // 0x8008B99C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DFCC0(rdram, ctx);
        goto after_0;
    // 0x8008B99C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8008B9A0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B9A4: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_8008B9A8:
    // 0x8008B9A8: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8008B9AC: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x8008B9B0: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
    // 0x8008B9B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B9B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B9BC: jr          $ra
    // 0x8008B9C0: nop

    return;
    // 0x8008B9C0: nop

;}
RECOMP_FUNC void _bsvanswim_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841C8: syscall     106
    recomp_syscall_handler(rdram, ctx, 0x800841C8);
    return;
    // 0x800841CC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800738_chflamer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800738: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080073C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800740: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800744: jal         0x80100094
    // 0x80800748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080074C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800750: jal         0x8008A040
    // 0x80800754: addiu       $a0, $v0, 0x1B4
    ctx->r4 = ADD32(ctx->r2, 0X1B4);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800754: addiu       $a0, $v0, 0x1B4
    ctx->r4 = ADD32(ctx->r2, 0X1B4);
    after_1:
    // 0x80800758: beq         $v0, $zero, L_80800778
    if (ctx->r2 == 0) {
        // 0x8080075C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800778;
    }
    // 0x8080075C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800760: lbu         $t6, 0x74($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X74);
    // 0x80800764: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x80800768: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080076C: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80800770: jal         0x8010108C
    // 0x80800774: sb          $t7, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r15;
    func_8010108C(rdram, ctx);
        goto after_2;
    // 0x80800774: sb          $t7, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r15;
    after_2:
L_80800778:
    // 0x80800778: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080077C: jal         0x8008A020
    // 0x80800780: addiu       $a0, $a0, 0x1B4
    ctx->r4 = ADD32(ctx->r4, 0X1B4);
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800780: addiu       $a0, $a0, 0x1B4
    ctx->r4 = ADD32(ctx->r4, 0X1B4);
    after_3:
    // 0x80800784: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800788: lbu         $t8, 0x72($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X72);
    // 0x8080078C: andi        $t9, $t8, 0xFF03
    ctx->r25 = ctx->r24 & 0XFF03;
    // 0x80800790: ori         $t0, $t9, 0xC
    ctx->r8 = ctx->r25 | 0XC;
    // 0x80800794: sb          $t0, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r8;
    // 0x80800798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080079C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007A0: jr          $ra
    // 0x808007A4: nop

    return;
    // 0x808007A4: nop

;}
RECOMP_FUNC void func_808000B8_chminegrill2switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C0: addiu       $t6, $zero, 0x79
    ctx->r14 = ADD32(0, 0X79);
    // 0x808000C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000C8: jal         0x80800030
    // 0x808000CC: addiu       $a3, $zero, 0x7A
    ctx->r7 = ADD32(0, 0X7A);
    func_80800030_chminegrill2switches(rdram, ctx);
        goto after_0;
    // 0x808000CC: addiu       $a3, $zero, 0x7A
    ctx->r7 = ADD32(0, 0X7A);
    after_0:
    // 0x808000D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void func_8080087C_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080087C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800880: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800884: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800888: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8080088C: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80800890: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(936, 0XBC0) << 16);
    // 0x80800894: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800898: beq         $t6, $zero, L_8080092C
    if (ctx->r14 == 0) {
        // 0x8080089C: addiu       $a2, $a2, 0xBC0
        ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(936, 0XBC0));
            goto L_8080092C;
    }
    // 0x8080089C: addiu       $a2, $a2, 0xBC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(936, 0XBC0));
    // 0x808008A0: jal         0x8008A1F8
    // 0x808008A4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x808008A4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x808008A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808008AC: bnel        $v0, $at, L_80800930
    if (ctx->r2 != ctx->r1) {
        // 0x808008B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800930;
    }
    goto skip_0;
    // 0x808008B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808008B4: jal         0x8010D254
    // 0x808008B8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x808008B8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x808008BC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808008C0: jal         0x800EE7F8
    // 0x808008C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808008C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x808008C8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808008CC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808008D0: jal         0x800EF1B8
    // 0x808008D4: lui         $a2, 0x43AA
    ctx->r6 = S32(0X43AA << 16);
    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x808008D4: lui         $a2, 0x43AA
    ctx->r6 = S32(0X43AA << 16);
    after_3:
    // 0x808008D8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808008DC: jal         0x800EEAD4
    // 0x808008E0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EEAD4(rdram, ctx);
        goto after_4;
    // 0x808008E0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x808008E4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808008E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808008EC: nop

    // 0x808008F0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808008F4: nop

    // 0x808008F8: bc1fl       L_80800930
    if (!c1cs) {
        // 0x808008FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800930;
    }
    goto skip_1;
    // 0x808008FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800900: jal         0x80090708
    // 0x80800904: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_5;
    // 0x80800904: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80800908: jal         0x8008F8B0
    // 0x8080090C: nop

    func_8008F8B0(rdram, ctx);
        goto after_6;
    // 0x8080090C: nop

    after_6:
    // 0x80800910: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800914: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80800918: jal         0x8008F904
    // 0x8080091C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8008F904(rdram, ctx);
        goto after_7;
    // 0x8080091C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80800920: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800924: jal         0x8008F990
    // 0x80800928: lui         $a1, 0x432A
    ctx->r5 = S32(0X432A << 16);
    func_8008F990(rdram, ctx);
        goto after_8;
    // 0x80800928: lui         $a1, 0x432A
    ctx->r5 = S32(0X432A << 16);
    after_8:
L_8080092C:
    // 0x8080092C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800930:
    // 0x80800930: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800934: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800938: jr          $ra
    // 0x8080093C: nop

    return;
    // 0x8080093C: nop

;}
RECOMP_FUNC void _gcaudiolist_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800880D0: syscall     670
    recomp_syscall_handler(rdram, ctx, 0x800880D0);
    return;
    // 0x800880D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801ACC_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801AD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801AD4: jal         0x8009E6EC
    // 0x80801AD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80801AD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801ADC: slti        $at, $v0, 0x34
    ctx->r1 = SIGNED(ctx->r2) < 0X34 ? 1 : 0;
    // 0x80801AE0: bne         $at, $zero, L_80801B0C
    if (ctx->r1 != 0) {
        // 0x80801AE4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801B0C;
    }
    // 0x80801AE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801AE8: addiu       $t6, $v0, -0x4E
    ctx->r14 = ADD32(ctx->r2, -0X4E);
    // 0x80801AEC: sltiu       $at, $t6, 0x24
    ctx->r1 = ctx->r14 < 0X24 ? 1 : 0;
    // 0x80801AF0: beq         $at, $zero, L_80801B6C
    if (ctx->r1 == 0) {
        // 0x80801AF4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801B6C;
    }
    // 0x80801AF4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801AF8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(120, 0X1D74) << 16);
    // 0x80801AFC: addu        $at, $at, $t6
    gpr jr_addend_80801B04 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801B00: lw          $t6, 0x1D74($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(120, 0X1D74));
    // 0x80801B04: jr          $t6
    // 0x80801B08: nop

    switch (jr_addend_80801B04 >> 2) {
        case 0: goto L_80801B48; break;
        case 1: goto L_80801B6C; break;
        case 2: goto L_80801B6C; break;
        case 3: goto L_80801B48; break;
        case 4: goto L_80801B48; break;
        case 5: goto L_80801B6C; break;
        case 6: goto L_80801B6C; break;
        case 7: goto L_80801B6C; break;
        case 8: goto L_80801B6C; break;
        case 9: goto L_80801B6C; break;
        case 10: goto L_80801B6C; break;
        case 11: goto L_80801B6C; break;
        case 12: goto L_80801B6C; break;
        case 13: goto L_80801B6C; break;
        case 14: goto L_80801B6C; break;
        case 15: goto L_80801B6C; break;
        case 16: goto L_80801B6C; break;
        case 17: goto L_80801B6C; break;
        case 18: goto L_80801B6C; break;
        case 19: goto L_80801B6C; break;
        case 20: goto L_80801B6C; break;
        case 21: goto L_80801B6C; break;
        case 22: goto L_80801B6C; break;
        case 23: goto L_80801B6C; break;
        case 24: goto L_80801B6C; break;
        case 25: goto L_80801B6C; break;
        case 26: goto L_80801B48; break;
        case 27: goto L_80801B6C; break;
        case 28: goto L_80801B6C; break;
        case 29: goto L_80801B6C; break;
        case 30: goto L_80801B6C; break;
        case 31: goto L_80801B6C; break;
        case 32: goto L_80801B6C; break;
        case 33: goto L_80801B48; break;
        case 34: goto L_80801B6C; break;
        case 35: goto L_80801B30; break;
        default: switch_error(__func__, 0x80801B04, 0x80801D74);
    }
    // 0x80801B08: nop

L_80801B0C:
    // 0x80801B0C: addiu       $t7, $v0, -0x1F
    ctx->r15 = ADD32(ctx->r2, -0X1F);
    // 0x80801B10: sltiu       $at, $t7, 0x15
    ctx->r1 = ctx->r15 < 0X15 ? 1 : 0;
    // 0x80801B14: beq         $at, $zero, L_80801B6C
    if (ctx->r1 == 0) {
        // 0x80801B18: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80801B6C;
    }
    // 0x80801B18: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801B1C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(120, 0X1E04) << 16);
    // 0x80801B20: addu        $at, $at, $t7
    gpr jr_addend_80801B28 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80801B24: lw          $t7, 0x1E04($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(120, 0X1E04));
    // 0x80801B28: jr          $t7
    // 0x80801B2C: nop

    switch (jr_addend_80801B28 >> 2) {
        case 0: goto L_80801B48; break;
        case 1: goto L_80801B48; break;
        case 2: goto L_80801B48; break;
        case 3: goto L_80801B6C; break;
        case 4: goto L_80801B6C; break;
        case 5: goto L_80801B48; break;
        case 6: goto L_80801B6C; break;
        case 7: goto L_80801B6C; break;
        case 8: goto L_80801B6C; break;
        case 9: goto L_80801B6C; break;
        case 10: goto L_80801B6C; break;
        case 11: goto L_80801B6C; break;
        case 12: goto L_80801B6C; break;
        case 13: goto L_80801B6C; break;
        case 14: goto L_80801B48; break;
        case 15: goto L_80801B48; break;
        case 16: goto L_80801B6C; break;
        case 17: goto L_80801B6C; break;
        case 18: goto L_80801B48; break;
        case 19: goto L_80801B6C; break;
        case 20: goto L_80801B48; break;
        default: switch_error(__func__, 0x80801B28, 0x80801E04);
    }
    // 0x80801B2C: nop

L_80801B30:
    // 0x80801B30: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801B34: sb          $t8, 0x167($a0)
    MEM_B(0X167, ctx->r4) = ctx->r24;
    // 0x80801B38: jal         0x8009E830
    // 0x80801B3C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_1;
    // 0x80801B3C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80801B40: b           L_80801B78
    // 0x80801B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801B78;
    // 0x80801B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801B48:
    // 0x80801B48: lbu         $t9, 0x167($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X167);
    // 0x80801B4C: bnel        $t9, $zero, L_80801B78
    if (ctx->r25 != 0) {
        // 0x80801B50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801B78;
    }
    goto skip_0;
    // 0x80801B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801B54: jal         0x800F9BC4
    // 0x80801B58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F9BC4(rdram, ctx);
        goto after_2;
    // 0x80801B58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80801B5C: jal         0x80099B94
    // 0x80801B60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_3;
    // 0x80801B60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80801B64: b           L_80801B78
    // 0x80801B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801B78;
    // 0x80801B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801B6C:
    // 0x80801B6C: jal         0x80099B94
    // 0x80801B70: nop

    func_80099B94(rdram, ctx);
        goto after_4;
    // 0x80801B70: nop

    after_4:
    // 0x80801B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801B78:
    // 0x80801B78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801B7C: jr          $ra
    // 0x80801B80: nop

    return;
    // 0x80801B80: nop

;}
RECOMP_FUNC void _baflamethrower_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BA8: syscall     131
    recomp_syscall_handler(rdram, ctx, 0x80084BA8);
    return;
    // 0x80084BAC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bakaztorpedo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080001C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800020: lw          $t7, 0xB0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB0);
    // 0x80800024: jal         0x8009EA08
    // 0x80800028: lwc1        $f12, 0x10($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X10);
    func_8009EA08(rdram, ctx);
        goto after_0;
    // 0x80800028: lwc1        $f12, 0x10($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X10);
    after_0:
    // 0x8080002C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: lw          $t9, 0xB0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XB0);
    // 0x80800034: jal         0x800C2FDC
    // 0x80800038: lbu         $a0, 0x1C($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X1C);
    func_800C2FDC(rdram, ctx);
        goto after_1;
    // 0x80800038: lbu         $a0, 0x1C($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X1C);
    after_1:
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800044: jr          $ra
    // 0x80800048: nop

    return;
    // 0x80800048: nop

;}
RECOMP_FUNC void _idflasha_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D68: syscall     738
    recomp_syscall_handler(rdram, ctx, 0x80088D68);
    return;
    // 0x80088D6C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80802558_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802558: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080255C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802560: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802564: jal         0x80100094
    // 0x80802568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080256C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802570: jal         0x8008A2C0
    // 0x80802574: addiu       $a1, $v0, 0x88
    ctx->r5 = ADD32(ctx->r2, 0X88);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80802574: addiu       $a1, $v0, 0x88
    ctx->r5 = ADD32(ctx->r2, 0X88);
    after_1:
    // 0x80802578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080257C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802580: jr          $ra
    // 0x80802584: nop

    return;
    // 0x80802584: nop

;}
RECOMP_FUNC void func_800A9998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9998: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A999C: addiu       $v1, $v1, 0x7760
    ctx->r3 = ADD32(ctx->r3, 0X7760);
    // 0x800A99A0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800A99A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A99A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A99AC: beq         $v0, $at, L_800A99C8
    if (ctx->r2 == ctx->r1) {
        // 0x800A99B0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800A99C8;
    }
    // 0x800A99B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A99B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A99B8: beq         $v0, $at, L_800A99DC
    if (ctx->r2 == ctx->r1) {
        // 0x800A99BC: nop
    
            goto L_800A99DC;
    }
    // 0x800A99BC: nop

    // 0x800A99C0: b           L_800A99F0
    // 0x800A99C4: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
        goto L_800A99F0;
    // 0x800A99C4: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
L_800A99C8:
    // 0x800A99C8: jal         0x800E80A0
    // 0x800A99CC: nop

    func_800E80A0(rdram, ctx);
        goto after_0;
    // 0x800A99CC: nop

    after_0:
    // 0x800A99D0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A99D4: b           L_800A99EC
    // 0x800A99D8: addiu       $v1, $v1, 0x7760
    ctx->r3 = ADD32(ctx->r3, 0X7760);
        goto L_800A99EC;
    // 0x800A99D8: addiu       $v1, $v1, 0x7760
    ctx->r3 = ADD32(ctx->r3, 0X7760);
L_800A99DC:
    // 0x800A99DC: jal         0x80088C58
    // 0x800A99E0: nop

    _gsattract_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x800A99E0: nop

    after_1:
    // 0x800A99E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A99E8: addiu       $v1, $v1, 0x7760
    ctx->r3 = ADD32(ctx->r3, 0X7760);
L_800A99EC:
    // 0x800A99EC: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
L_800A99F0:
    // 0x800A99F0: beq         $t6, $zero, L_800A99FC
    if (ctx->r14 == 0) {
        // 0x800A99F4: nop
    
            goto L_800A99FC;
    }
    // 0x800A99F4: nop

    // 0x800A99F8: sb          $zero, 0x4($v1)
    MEM_B(0X4, ctx->r3) = 0;
L_800A99FC:
    // 0x800A99FC: jal         0x800A1618
    // 0x800A9A00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A1618(rdram, ctx);
        goto after_2;
    // 0x800A9A00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800A9A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9A08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9A0C: jr          $ra
    // 0x800A9A10: nop

    return;
    // 0x800A9A10: nop

;}
RECOMP_FUNC void func_808022F0_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808022F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808022F4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1840, 0X4E4C) << 16);
    // 0x808022F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808022FC: addiu       $t6, $t6, 0x4E4C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1840, 0X4E4C));
    // 0x80802300: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802308: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080230C: jal         0x800BBCB8
    // 0x80802310: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80802310: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x80802314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802318: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080231C: jr          $ra
    // 0x80802320: nop

    return;
    // 0x80802320: nop

;}
RECOMP_FUNC void func_80800000_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80100094
    // 0x80800010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800014: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800018: lbu         $t6, 0x95($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X95);
    // 0x8080001C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800020: bnel        $t6, $at, L_8080008C
    if (ctx->r14 != ctx->r1) {
        // 0x80800024: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080008C;
    }
    goto skip_0;
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800028: jal         0x800F54E4
    // 0x8080002C: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x8080002C: nop

    after_1:
    // 0x80800030: jal         0x800F6C88
    // 0x80800034: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C88(rdram, ctx);
        goto after_2;
    // 0x80800034: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800038: bne         $v0, $zero, L_80800088
    if (ctx->r2 != 0) {
        // 0x8080003C: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_80800088;
    }
    // 0x8080003C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800040: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800044: jal         0x800EE7F8
    // 0x80800048: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800048: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x8080004C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800050: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800054: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800058: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080005C: jal         0x800F54E4
    // 0x80800060: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800060: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80800064: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800068: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8080006C: jal         0x80087900
    // 0x80800070: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _plcamera_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80800070: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_5:
    // 0x80800074: bne         $v0, $zero, L_80800088
    if (ctx->r2 != 0) {
        // 0x80800078: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80800088;
    }
    // 0x80800078: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8080007C: sb          $zero, 0x95($t7)
    MEM_B(0X95, ctx->r15) = 0;
    // 0x80800080: jal         0x808000BC
    // 0x80800084: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_808000BC_chevilmumbo(rdram, ctx);
        goto after_6;
    // 0x80800084: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
L_80800088:
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080008C:
    // 0x8080008C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void _glsavegame_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088560: syscall     692
    recomp_syscall_handler(rdram, ctx, 0x80088560);
    return;
    // 0x80088564: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800130_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800138: jal         0x8009E6EC
    // 0x8080013C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x8080013C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800140: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80800144: bne         $v0, $at, L_80800154
    if (ctx->r2 != ctx->r1) {
        // 0x80800148: nop
    
            goto L_80800154;
    }
    // 0x80800148: nop

    // 0x8080014C: jal         0x80099B94
    // 0x80800150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_1;
    // 0x80800150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80800154:
    // 0x80800154: jal         0x80082FF8
    // 0x80800158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080015C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800164: jr          $ra
    // 0x80800168: nop

    return;
    // 0x80800168: nop

;}
RECOMP_FUNC void _chdinoswitches_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F90: syscall     267
    recomp_syscall_handler(rdram, ctx, 0x80085F90);
    return;
    // 0x80085F94: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void __baanim_applyBottlesBonus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C4DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008C4E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C4E4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8008C4E8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8008C4EC: jal         0x800F53D0
    // 0x8008C4F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x8008C4F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8008C4F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8008C4F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008C4FC: jal         0x80098218
    // 0x8008C500: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_80098218(rdram, ctx);
        goto after_1;
    // 0x8008C500: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8008C504: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8008C508: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C50C: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x8008C510: lh          $a1, 0xE($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XE);
    // 0x8008C514: jal         0x800DFC20
    // 0x8008C518: addiu       $a2, $v0, 0x10
    ctx->r6 = ADD32(ctx->r2, 0X10);
    func_800DFC20(rdram, ctx);
        goto after_2;
    // 0x8008C518: addiu       $a2, $v0, 0x10
    ctx->r6 = ADD32(ctx->r2, 0X10);
    after_2:
    // 0x8008C51C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8008C520: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8008C524: lbu         $t9, 0xC($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XC);
    // 0x8008C528: beq         $t9, $zero, L_8008C550
    if (ctx->r25 == 0) {
        // 0x8008C52C: nop
    
            goto L_8008C550;
    }
    // 0x8008C52C: nop

    // 0x8008C530: jal         0x800EFD24
    // 0x8008C534: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x8008C534: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x8008C538: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8008C53C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C540: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8008C544: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8008C548: jal         0x800DFFA0
    // 0x8008C54C: lh          $a1, 0xE($t1)
    ctx->r5 = MEM_H(ctx->r9, 0XE);
    func_800DFFA0(rdram, ctx);
        goto after_4;
    // 0x8008C54C: lh          $a1, 0xE($t1)
    ctx->r5 = MEM_H(ctx->r9, 0XE);
    after_4:
L_8008C550:
    // 0x8008C550: jal         0x800A8258
    // 0x8008C554: nop

    func_800A8258(rdram, ctx);
        goto after_5;
    // 0x8008C554: nop

    after_5:
    // 0x8008C558: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008C55C: lw          $t2, 0x6CD0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6CD0);
    // 0x8008C560: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8008C564: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8008C568: beq         $t3, $zero, L_8008C5A0
    if (ctx->r11 == 0) {
        // 0x8008C56C: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_8008C5A0;
    }
    // 0x8008C56C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8008C570: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008C574: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8008C578: jal         0x8008C3FC
    // 0x8008C57C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    __baanim_oscillateScale(rdram, ctx);
        goto after_6;
    // 0x8008C57C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_6:
    // 0x8008C580: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C584: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8008C588: jal         0x800DFF64
    // 0x8008C58C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800DFF64(rdram, ctx);
        goto after_7;
    // 0x8008C58C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_7:
    // 0x8008C590: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C594: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8008C598: jal         0x800DFF64
    // 0x8008C59C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800DFF64(rdram, ctx);
        goto after_8;
    // 0x8008C59C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_8:
L_8008C5A0:
    // 0x8008C5A0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008C5A4: lw          $t4, 0x6CD0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6CD0);
    // 0x8008C5A8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8008C5AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008C5B0: andi        $t5, $t4, 0x2
    ctx->r13 = ctx->r12 & 0X2;
    // 0x8008C5B4: beq         $t5, $zero, L_8008C5E4
    if (ctx->r13 == 0) {
        // 0x8008C5B8: lui         $a2, 0x4000
        ctx->r6 = S32(0X4000 << 16);
            goto L_8008C5E4;
    }
    // 0x8008C5B8: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8008C5BC: jal         0x8008C3FC
    // 0x8008C5C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    __baanim_oscillateScale(rdram, ctx);
        goto after_9;
    // 0x8008C5C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_9:
    // 0x8008C5C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C5C8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8008C5CC: jal         0x800DFF64
    // 0x8008C5D0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800DFF64(rdram, ctx);
        goto after_10;
    // 0x8008C5D0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_10:
    // 0x8008C5D4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C5D8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8008C5DC: jal         0x800DFF64
    // 0x8008C5E0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800DFF64(rdram, ctx);
        goto after_11;
    // 0x8008C5E0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_11:
L_8008C5E4:
    // 0x8008C5E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008C5E8: lw          $t6, 0x6CD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6CD0);
    // 0x8008C5EC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8008C5F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008C5F4: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8008C5F8: beq         $t7, $zero, L_8008C618
    if (ctx->r15 == 0) {
        // 0x8008C5FC: lui         $a2, 0x4000
        ctx->r6 = S32(0X4000 << 16);
            goto L_8008C618;
    }
    // 0x8008C5FC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8008C600: jal         0x8008C3FC
    // 0x8008C604: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    __baanim_oscillateScale(rdram, ctx);
        goto after_12;
    // 0x8008C604: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_12:
    // 0x8008C608: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C60C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8008C610: jal         0x800DFF64
    // 0x8008C614: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800DFF64(rdram, ctx);
        goto after_13;
    // 0x8008C614: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_13:
L_8008C618:
    // 0x8008C618: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008C61C: lw          $t8, 0x6CD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6CD0);
    // 0x8008C620: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8008C624: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008C628: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8008C62C: beq         $t9, $zero, L_8008C650
    if (ctx->r25 == 0) {
        // 0x8008C630: lui         $a2, 0x3E4C
        ctx->r6 = S32(0X3E4C << 16);
            goto L_8008C650;
    }
    // 0x8008C630: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8008C634: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8008C638: jal         0x8008C3FC
    // 0x8008C63C: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    __baanim_oscillateScale(rdram, ctx);
        goto after_14;
    // 0x8008C63C: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_14:
    // 0x8008C640: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C644: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8008C648: jal         0x800DFF64
    // 0x8008C64C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800DFF64(rdram, ctx);
        goto after_15;
    // 0x8008C64C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_15:
L_8008C650:
    // 0x8008C650: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008C654: lw          $t0, 0x6CD0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6CD0);
    // 0x8008C658: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C65C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008C660: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x8008C664: beq         $t1, $zero, L_8008C674
    if (ctx->r9 == 0) {
        // 0x8008C668: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_8008C674;
    }
    // 0x8008C668: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8008C66C: jal         0x800DFFA0
    // 0x8008C670: addiu       $a2, $a2, 0x7C70
    ctx->r6 = ADD32(ctx->r6, 0X7C70);
    func_800DFFA0(rdram, ctx);
        goto after_16;
    // 0x8008C670: addiu       $a2, $a2, 0x7C70
    ctx->r6 = ADD32(ctx->r6, 0X7C70);
    after_16:
L_8008C674:
    // 0x8008C674: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008C678: lw          $t2, 0x6CD0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6CD0);
    // 0x8008C67C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8008C680: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008C684: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x8008C688: beq         $t3, $zero, L_8008C6A8
    if (ctx->r11 == 0) {
        // 0x8008C68C: lui         $a2, 0x4000
        ctx->r6 = S32(0X4000 << 16);
            goto L_8008C6A8;
    }
    // 0x8008C68C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8008C690: jal         0x8008C3FC
    // 0x8008C694: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    __baanim_oscillateScale(rdram, ctx);
        goto after_17;
    // 0x8008C694: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_17:
    // 0x8008C698: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C69C: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    // 0x8008C6A0: jal         0x800DFF64
    // 0x8008C6A4: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800DFF64(rdram, ctx);
        goto after_18;
    // 0x8008C6A4: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_18:
L_8008C6A8:
    // 0x8008C6A8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008C6AC: lw          $t4, 0x6CD0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6CD0);
    // 0x8008C6B0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8008C6B4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008C6B8: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x8008C6BC: beq         $t5, $zero, L_8008C6EC
    if (ctx->r13 == 0) {
        // 0x8008C6C0: lui         $a2, 0x4000
        ctx->r6 = S32(0X4000 << 16);
            goto L_8008C6EC;
    }
    // 0x8008C6C0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8008C6C4: jal         0x8008C3FC
    // 0x8008C6C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    __baanim_oscillateScale(rdram, ctx);
        goto after_19;
    // 0x8008C6C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_19:
    // 0x8008C6CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C6D0: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x8008C6D4: jal         0x800DFF64
    // 0x8008C6D8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800DFF64(rdram, ctx);
        goto after_20;
    // 0x8008C6D8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_20:
    // 0x8008C6DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C6E0: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    // 0x8008C6E4: jal         0x800DFF64
    // 0x8008C6E8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800DFF64(rdram, ctx);
        goto after_21;
    // 0x8008C6E8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_21:
L_8008C6EC:
    // 0x8008C6EC: jal         0x800A4C88
    // 0x8008C6F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800A4C88(rdram, ctx);
        goto after_22;
    // 0x8008C6F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_22:
    // 0x8008C6F4: jal         0x8010FFD8
    // 0x8008C6F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010FFD8(rdram, ctx);
        goto after_23;
    // 0x8008C6F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x8008C6FC: beq         $v0, $zero, L_8008C734
    if (ctx->r2 == 0) {
        // 0x8008C700: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_8008C734;
    }
    // 0x8008C700: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8008C704: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x8008C708: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8008C70C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8008C710: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8008C714: jal         0x8008C3FC
    // 0x8008C718: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    __baanim_oscillateScale(rdram, ctx);
        goto after_24;
    // 0x8008C718: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_24:
    // 0x8008C71C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8008C720: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C724: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8008C728: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8008C72C: jal         0x800DFF64
    // 0x8008C730: lh          $a1, 0xE($t7)
    ctx->r5 = MEM_H(ctx->r15, 0XE);
    func_800DFF64(rdram, ctx);
        goto after_25;
    // 0x8008C730: lh          $a1, 0xE($t7)
    ctx->r5 = MEM_H(ctx->r15, 0XE);
    after_25:
L_8008C734:
    // 0x8008C734: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8008C738: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8008C73C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8008C740: lw          $v0, 0x4($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X4);
    // 0x8008C744: beql        $v0, $zero, L_8008C758
    if (ctx->r2 == 0) {
        // 0x8008C748: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008C758;
    }
    goto skip_0;
    // 0x8008C748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008C74C: jalr        $v0
    // 0x8008C750: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_26;
    // 0x8008C750: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_26:
    // 0x8008C754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008C758:
    // 0x8008C758: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8008C75C: jr          $ra
    // 0x8008C760: nop

    return;
    // 0x8008C760: nop

;}
RECOMP_FUNC void func_800FEC60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FEC60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FEC64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FEC68: jal         0x800FEC28
    // 0x800FEC6C: nop

    func_800FEC28(rdram, ctx);
        goto after_0;
    // 0x800FEC6C: nop

    after_0:
    // 0x800FEC70: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FEC74: addiu       $t6, $t6, 0x5A10
    ctx->r14 = ADD32(ctx->r14, 0X5A10);
    // 0x800FEC78: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800FEC7C: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x800FEC80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800FEC84: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800FEC88: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800FEC8C: bne         $v0, $at, L_800FECA4
    if (ctx->r2 != ctx->r1) {
        // 0x800FEC90: sb          $t8, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r24;
            goto L_800FECA4;
    }
    // 0x800FEC90: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x800FEC94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FEC98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FEC9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FECA0: swc1        $f4, 0x59F0($at)
    MEM_W(0X59F0, ctx->r1) = ctx->f4.u32l;
L_800FECA4:
    // 0x800FECA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FECA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FECAC: sw          $t9, 0x3E60($at)
    MEM_W(0X3E60, ctx->r1) = ctx->r25;
    // 0x800FECB0: jr          $ra
    // 0x800FECB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800FECB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void chscorepoints_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1276, 0X3C0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x3C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1276, 0X3C0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x3C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1276, 0X3C0));
;}
RECOMP_FUNC void func_80802764_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802764: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80802768: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080276C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80802770: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80802774: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80802778: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8080277C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80802780: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80802784: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80802788: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080278C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80802790: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802794: jal         0x800BE3F8
    // 0x80802798: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800BE3F8(rdram, ctx);
        goto after_0;
    // 0x80802798: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8080279C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808027A0: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x808027A4: addiu       $s7, $zero, 0x40
    ctx->r23 = ADD32(0, 0X40);
    // 0x808027A8: beq         $t6, $zero, L_808028A0
    if (ctx->r14 == 0) {
        // 0x808027AC: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_808028A0;
    }
    // 0x808027AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x808027B0: addiu       $s6, $zero, 0x43
    ctx->r22 = ADD32(0, 0X43);
    // 0x808027B4: addiu       $s5, $zero, 0x42
    ctx->r21 = ADD32(0, 0X42);
    // 0x808027B8: addiu       $s4, $zero, 0x44
    ctx->r20 = ADD32(0, 0X44);
L_808027BC:
    // 0x808027BC: jal         0x800E9E88
    // 0x808027C0: nop

    func_800E9E88(rdram, ctx);
        goto after_1;
    // 0x808027C0: nop

    after_1:
    // 0x808027C4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808027C8: jal         0x800E9EB4
    // 0x808027CC: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_2;
    // 0x808027CC: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    after_2:
    // 0x808027D0: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x808027D4: beq         $at, $zero, L_80802890
    if (ctx->r1 == 0) {
        // 0x808027D8: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80802890;
    }
    // 0x808027D8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808027DC: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
L_808027E0:
    // 0x808027E0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x808027E4: beql        $t8, $zero, L_80802884
    if (ctx->r24 == 0) {
        // 0x808027E8: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80802884;
    }
    goto skip_0;
    // 0x808027E8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_0:
    // 0x808027EC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x808027F0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x808027F4: beql        $s0, $t9, L_80802884
    if (ctx->r16 == ctx->r25) {
        // 0x808027F8: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80802884;
    }
    goto skip_1;
    // 0x808027F8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_1:
    // 0x808027FC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80802800: srl         $t0, $v0, 22
    ctx->r8 = S32(U32(ctx->r2) >> 22);
    // 0x80802804: beq         $s4, $t0, L_8080281C
    if (ctx->r20 == ctx->r8) {
        // 0x80802808: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8080281C;
    }
    // 0x80802808: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8080280C: beq         $s5, $t0, L_8080281C
    if (ctx->r21 == ctx->r8) {
        // 0x80802810: nop
    
            goto L_8080281C;
    }
    // 0x80802810: nop

    // 0x80802814: bne         $s6, $t0, L_8080283C
    if (ctx->r22 != ctx->r8) {
        // 0x80802818: nop
    
            goto L_8080283C;
    }
    // 0x80802818: nop

L_8080281C:
    // 0x8080281C: jal         0x80106790
    // 0x80802820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80802820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80802824: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802828: jal         0x808028D0
    // 0x8080282C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808028D0_chcollballcontrol(rdram, ctx);
        goto after_4;
    // 0x8080282C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80802830: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80802834: srl         $t1, $v0, 22
    ctx->r9 = S32(U32(ctx->r2) >> 22);
    // 0x80802838: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8080283C:
    // 0x8080283C: bne         $v0, $zero, L_80802864
    if (ctx->r2 != 0) {
        // 0x80802840: nop
    
            goto L_80802864;
    }
    // 0x80802840: nop

    // 0x80802844: lhu         $a1, 0x1A($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X1A);
    // 0x80802848: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080284C: srl         $t2, $a1, 5
    ctx->r10 = S32(U32(ctx->r5) >> 5);
    // 0x80802850: jal         0x80802964
    // 0x80802854: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_80802964_chcollballcontrol(rdram, ctx);
        goto after_5;
    // 0x80802854: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_5:
    // 0x80802858: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8080285C: srl         $t3, $v0, 22
    ctx->r11 = S32(U32(ctx->r2) >> 22);
    // 0x80802860: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80802864:
    // 0x80802864: bnel        $s7, $v0, L_80802884
    if (ctx->r23 != ctx->r2) {
        // 0x80802868: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80802884;
    }
    goto skip_2;
    // 0x80802868: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_2:
    // 0x8080286C: jal         0x80106790
    // 0x80802870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x80802870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80802874: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802878: jal         0x808029D8
    // 0x8080287C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808029D8_chcollballcontrol(rdram, ctx);
        goto after_7;
    // 0x8080287C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80802880: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80802884:
    // 0x80802884: sltu        $at, $s1, $s3
    ctx->r1 = ctx->r17 < ctx->r19 ? 1 : 0;
    // 0x80802888: bnel        $at, $zero, L_808027E0
    if (ctx->r1 != 0) {
        // 0x8080288C: lw          $t7, 0x8($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X8);
            goto L_808027E0;
    }
    goto skip_3;
    // 0x8080288C: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    skip_3:
L_80802890:
    // 0x80802890: lw          $a0, 0x4($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X4);
    // 0x80802894: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80802898: bne         $a0, $zero, L_808027BC
    if (ctx->r4 != 0) {
        // 0x8080289C: nop
    
            goto L_808027BC;
    }
    // 0x8080289C: nop

L_808028A0:
    // 0x808028A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808028A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808028A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808028AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808028B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808028B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808028B8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808028BC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x808028C0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x808028C4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x808028C8: jr          $ra
    // 0x808028CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808028CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80800348_chflysaucercrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800348: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080034C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800350: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800354: lhu         $v1, 0x72($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X72);
    // 0x80800358: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080035C: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800360: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80800364: beq         $at, $zero, L_808003B4
    if (ctx->r1 == 0) {
        // 0x80800368: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_808003B4;
    }
    // 0x80800368: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8080036C: lui         $at, 0x42E6
    ctx->r1 = S32(0X42E6 << 16);
    // 0x80800370: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800374: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800378: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080037C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800380: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800384: jal         0x8008FAC8
    // 0x80800388: lui         $a2, 0x432F
    ctx->r6 = S32(0X432F << 16);
    func_8008FAC8(rdram, ctx);
        goto after_0;
    // 0x80800388: lui         $a2, 0x432F
    ctx->r6 = S32(0X432F << 16);
    after_0:
    // 0x8080038C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80800390: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800394: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800398: lui         $a1, 0x432A
    ctx->r5 = S32(0X432A << 16);
    // 0x8080039C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808003A0: jal         0x80089F20
    // 0x808003A4: lui         $a3, 0x4320
    ctx->r7 = S32(0X4320 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808003A4: lui         $a3, 0x4320
    ctx->r7 = S32(0X4320 << 16);
    after_1:
    // 0x808003A8: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808003AC: srl         $t8, $v1, 10
    ctx->r24 = S32(U32(ctx->r3) >> 10);
    // 0x808003B0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_808003B4:
    // 0x808003B4: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x808003B8: sltiu       $at, $t9, 0xA
    ctx->r1 = ctx->r25 < 0XA ? 1 : 0;
    // 0x808003BC: beq         $at, $zero, L_808008F0
    if (ctx->r1 == 0) {
        // 0x808003C0: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808008F0;
    }
    // 0x808003C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808003C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XC6C) << 16);
    // 0x808003C8: addu        $at, $at, $t9
    gpr jr_addend_808003D0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808003CC: lw          $t9, 0xC6C($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1696, 0XC6C));
    // 0x808003D0: jr          $t9
    // 0x808003D4: nop

    switch (jr_addend_808003D0 >> 2) {
        case 0: goto L_808003D8; break;
        case 1: goto L_8080048C; break;
        case 2: goto L_80800520; break;
        case 3: goto L_808005D4; break;
        case 4: goto L_80800694; break;
        case 5: goto L_80800718; break;
        case 6: goto L_808007B0; break;
        case 7: goto L_80800844; break;
        case 8: goto L_808008A0; break;
        case 9: goto L_808008E8; break;
        default: switch_error(__func__, 0x808003D0, 0x80800C6C);
    }
    // 0x808003D4: nop

L_808003D8:
    // 0x808003D8: addiu       $t0, $s0, 0x4
    ctx->r8 = ADD32(ctx->r16, 0X4);
    // 0x808003DC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x808003E0: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x808003E4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x808003E8: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x808003EC: bltz        $t3, L_80800468
    if (SIGNED(ctx->r11) < 0) {
        // 0x808003F0: nop
    
            goto L_80800468;
    }
    // 0x808003F0: nop

    // 0x808003F4: jal         0x8010C9B0
    // 0x808003F8: addiu       $a1, $zero, 0x15E
    ctx->r5 = ADD32(0, 0X15E);
    func_8010C9B0(rdram, ctx);
        goto after_2;
    // 0x808003F8: addiu       $a1, $zero, 0x15E
    ctx->r5 = ADD32(0, 0X15E);
    after_2:
    // 0x808003FC: beq         $v0, $zero, L_80800468
    if (ctx->r2 == 0) {
        // 0x80800400: addiu       $a0, $zero, 0x4001
        ctx->r4 = ADD32(0, 0X4001);
            goto L_80800468;
    }
    // 0x80800400: addiu       $a0, $zero, 0x4001
    ctx->r4 = ADD32(0, 0X4001);
    // 0x80800404: jal         0x8008FA60
    // 0x80800408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008FA60(rdram, ctx);
        goto after_3;
    // 0x80800408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8080040C: beq         $v0, $zero, L_80800468
    if (ctx->r2 == 0) {
        // 0x80800410: nop
    
            goto L_80800468;
    }
    // 0x80800410: nop

    // 0x80800414: jal         0x800DA298
    // 0x80800418: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800418: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_4:
    // 0x8080041C: bne         $v0, $zero, L_80800468
    if (ctx->r2 != 0) {
        // 0x80800420: addiu       $a0, $zero, 0x90
        ctx->r4 = ADD32(0, 0X90);
            goto L_80800468;
    }
    // 0x80800420: addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
    // 0x80800424: jal         0x800DA9E4
    // 0x80800428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_5;
    // 0x80800428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080042C: bne         $v0, $zero, L_8080044C
    if (ctx->r2 != 0) {
        // 0x80800430: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080044C;
    }
    // 0x80800430: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800438: addiu       $a1, $zero, 0xF92
    ctx->r5 = ADD32(0, 0XF92);
    // 0x8080043C: jal         0x8080028C
    // 0x80800440: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8080028C_chflysaucercrate(rdram, ctx);
        goto after_6;
    // 0x80800440: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_6:
    // 0x80800444: b           L_80800468
    // 0x80800448: nop

        goto L_80800468;
    // 0x80800448: nop

L_8080044C:
    // 0x8080044C: jal         0x80016B30
    // 0x80800450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_7;
    // 0x80800450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800454: beq         $v0, $zero, L_80800468
    if (ctx->r2 == 0) {
        // 0x80800458: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800468;
    }
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: addiu       $a1, $zero, 0xFA5
    ctx->r5 = ADD32(0, 0XFA5);
    // 0x80800460: jal         0x8080028C
    // 0x80800464: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080028C_chflysaucercrate(rdram, ctx);
        goto after_8;
    // 0x80800464: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
L_80800468:
    // 0x80800468: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1696, 0XD00) << 16);
    // 0x8080046C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1696, 0XDE4) << 16);
    // 0x80800470: addiu       $a3, $a3, 0xDE4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1696, 0XDE4));
    // 0x80800474: addiu       $a2, $a2, 0xD00
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1696, 0XD00));
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080047C: jal         0x80089D28
    // 0x80800480: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80800480: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_9:
    // 0x80800484: b           L_808008F4
    // 0x80800488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008F4;
    // 0x80800488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080048C:
    // 0x8080048C: jal         0x80800904
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800904_chflysaucercrate(rdram, ctx);
        goto after_10;
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800494: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XC94) << 16);
    // 0x80800498: lwc1        $f6, 0xC94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XC94));
    // 0x8080049C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808004A8: nop

    // 0x808004AC: bc1f        L_808004D8
    if (!c1cs) {
        // 0x808004B0: nop
    
            goto L_808004D8;
    }
    // 0x808004B0: nop

    // 0x808004B4: jal         0x800D8FF8
    // 0x808004B8: nop

    func_800D8FF8(rdram, ctx);
        goto after_11;
    // 0x808004B8: nop

    after_11:
    // 0x808004BC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808004C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808004C4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808004C8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808004CC: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x808004D0: b           L_808004E0
    // 0x808004D4: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
        goto L_808004E0;
    // 0x808004D4: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_808004D8:
    // 0x808004D8: jal         0x8080000C
    // 0x808004DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_12;
    // 0x808004DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
L_808004E0:
    // 0x808004E0: lui         $at, 0x43EF
    ctx->r1 = S32(0X43EF << 16);
    // 0x808004E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XC98) << 16);
    // 0x808004EC: lwc1        $f4, 0xC98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XC98));
    // 0x808004F0: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808004F4: lui         $a2, 0x4403
    ctx->r6 = S32(0X4403 << 16);
    // 0x808004F8: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808004FC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800500: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x80800504: jal         0x800F10B4
    // 0x80800508: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_13;
    // 0x80800508: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x8080050C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800510: jal         0x808002D8
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D8_chflysaucercrate(rdram, ctx);
        goto after_14;
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800518: b           L_808008F4
    // 0x8080051C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008F4;
    // 0x8080051C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800520:
    // 0x80800520: jal         0x80800904
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800904_chflysaucercrate(rdram, ctx);
        goto after_15;
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800528: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XC9C) << 16);
    // 0x8080052C: lwc1        $f10, 0xC9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XC9C));
    // 0x80800530: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800534: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80800538: nop

    // 0x8080053C: bc1f        L_80800568
    if (!c1cs) {
        // 0x80800540: nop
    
            goto L_80800568;
    }
    // 0x80800540: nop

    // 0x80800544: jal         0x800D8FF8
    // 0x80800548: nop

    func_800D8FF8(rdram, ctx);
        goto after_16;
    // 0x80800548: nop

    after_16:
    // 0x8080054C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCA0) << 16);
    // 0x80800550: lwc1        $f16, 0xCA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCA0));
    // 0x80800554: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800558: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8080055C: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80800560: b           L_80800594
    // 0x80800564: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
        goto L_80800594;
    // 0x80800564: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
L_80800568:
    // 0x80800568: jal         0x800DA298
    // 0x8080056C: addiu       $a0, $zero, 0xB3
    ctx->r4 = ADD32(0, 0XB3);
    func_800DA298(rdram, ctx);
        goto after_17;
    // 0x8080056C: addiu       $a0, $zero, 0xB3
    ctx->r4 = ADD32(0, 0XB3);
    after_17:
    // 0x80800570: beq         $v0, $zero, L_8080058C
    if (ctx->r2 == 0) {
        // 0x80800574: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080058C;
    }
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: jal         0x8080000C
    // 0x80800580: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_18;
    // 0x80800580: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_18:
    // 0x80800584: b           L_80800598
    // 0x80800588: lui         $at, 0x43EF
    ctx->r1 = S32(0X43EF << 16);
        goto L_80800598;
    // 0x80800588: lui         $at, 0x43EF
    ctx->r1 = S32(0X43EF << 16);
L_8080058C:
    // 0x8080058C: jal         0x8080000C
    // 0x80800590: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_19;
    // 0x80800590: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_19:
L_80800594:
    // 0x80800594: lui         $at, 0x43EF
    ctx->r1 = S32(0X43EF << 16);
L_80800598:
    // 0x80800598: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080059C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCA4) << 16);
    // 0x808005A0: lwc1        $f6, 0xCA4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCA4));
    // 0x808005A4: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808005A8: lui         $a2, 0x4403
    ctx->r6 = S32(0X4403 << 16);
    // 0x808005AC: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808005B0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808005B4: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x808005B8: jal         0x800F10B4
    // 0x808005BC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_20;
    // 0x808005BC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_20:
    // 0x808005C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005C4: jal         0x808002D8
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D8_chflysaucercrate(rdram, ctx);
        goto after_21;
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808005CC: b           L_808008F4
    // 0x808005D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008F4;
    // 0x808005D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005D4:
    // 0x808005D4: jal         0x80800904
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800904_chflysaucercrate(rdram, ctx);
        goto after_22;
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808005DC: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x808005E0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808005E4: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x808005E8: bltzl       $t6, L_80800658
    if (SIGNED(ctx->r14) < 0) {
        // 0x808005EC: lui         $at, 0x43EF
        ctx->r1 = S32(0X43EF << 16);
            goto L_80800658;
    }
    goto skip_0;
    // 0x808005EC: lui         $at, 0x43EF
    ctx->r1 = S32(0X43EF << 16);
    skip_0:
    // 0x808005F0: jal         0x8010C9B0
    // 0x808005F4: addiu       $a1, $zero, 0x15E
    ctx->r5 = ADD32(0, 0X15E);
    func_8010C9B0(rdram, ctx);
        goto after_23;
    // 0x808005F4: addiu       $a1, $zero, 0x15E
    ctx->r5 = ADD32(0, 0X15E);
    after_23:
    // 0x808005F8: beq         $v0, $zero, L_80800654
    if (ctx->r2 == 0) {
        // 0x808005FC: addiu       $a0, $zero, 0x4001
        ctx->r4 = ADD32(0, 0X4001);
            goto L_80800654;
    }
    // 0x808005FC: addiu       $a0, $zero, 0x4001
    ctx->r4 = ADD32(0, 0X4001);
    // 0x80800600: jal         0x8008FA60
    // 0x80800604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008FA60(rdram, ctx);
        goto after_24;
    // 0x80800604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x80800608: beq         $v0, $zero, L_80800654
    if (ctx->r2 == 0) {
        // 0x8080060C: addiu       $a0, $zero, 0x92
        ctx->r4 = ADD32(0, 0X92);
            goto L_80800654;
    }
    // 0x8080060C: addiu       $a0, $zero, 0x92
    ctx->r4 = ADD32(0, 0X92);
    // 0x80800610: jal         0x800DA9E4
    // 0x80800614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_25;
    // 0x80800614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x80800618: bne         $v0, $zero, L_80800638
    if (ctx->r2 != 0) {
        // 0x8080061C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800638;
    }
    // 0x8080061C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800624: addiu       $a1, $zero, 0xF94
    ctx->r5 = ADD32(0, 0XF94);
    // 0x80800628: jal         0x8080028C
    // 0x8080062C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8080028C_chflysaucercrate(rdram, ctx);
        goto after_26;
    // 0x8080062C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_26:
    // 0x80800630: b           L_80800658
    // 0x80800634: lui         $at, 0x43EF
    ctx->r1 = S32(0X43EF << 16);
        goto L_80800658;
    // 0x80800634: lui         $at, 0x43EF
    ctx->r1 = S32(0X43EF << 16);
L_80800638:
    // 0x80800638: jal         0x80016B30
    // 0x8080063C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_27;
    // 0x8080063C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x80800640: beq         $v0, $zero, L_80800654
    if (ctx->r2 == 0) {
        // 0x80800644: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800654;
    }
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: addiu       $a1, $zero, 0xFA6
    ctx->r5 = ADD32(0, 0XFA6);
    // 0x8080064C: jal         0x8080028C
    // 0x80800650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080028C_chflysaucercrate(rdram, ctx);
        goto after_28;
    // 0x80800650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_28:
L_80800654:
    // 0x80800654: lui         $at, 0x43EF
    ctx->r1 = S32(0X43EF << 16);
L_80800658:
    // 0x80800658: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080065C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCA8) << 16);
    // 0x80800660: lwc1        $f10, 0xCA8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCA8));
    // 0x80800664: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800668: lui         $a2, 0x4403
    ctx->r6 = S32(0X4403 << 16);
    // 0x8080066C: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800670: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800674: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x80800678: jal         0x800F10B4
    // 0x8080067C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_29;
    // 0x8080067C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_29:
    // 0x80800680: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800684: jal         0x808002D8
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D8_chflysaucercrate(rdram, ctx);
        goto after_30;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8080068C: b           L_808008F4
    // 0x80800690: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008F4;
    // 0x80800690: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800694:
    // 0x80800694: jal         0x80800904
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800904_chflysaucercrate(rdram, ctx);
        goto after_31;
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x8080069C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCAC) << 16);
    // 0x808006A0: lwc1        $f8, 0xCAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCAC));
    // 0x808006A4: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808006A8: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x808006AC: nop

    // 0x808006B0: bc1fl       L_808006DC
    if (!c1cs) {
        // 0x808006B4: lui         $at, 0x43EF
        ctx->r1 = S32(0X43EF << 16);
            goto L_808006DC;
    }
    goto skip_1;
    // 0x808006B4: lui         $at, 0x43EF
    ctx->r1 = S32(0X43EF << 16);
    skip_1:
    // 0x808006B8: jal         0x800D8FF8
    // 0x808006BC: nop

    func_800D8FF8(rdram, ctx);
        goto after_32;
    // 0x808006BC: nop

    after_32:
    // 0x808006C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCB0) << 16);
    // 0x808006C4: lwc1        $f4, 0xCB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCB0));
    // 0x808006C8: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808006CC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808006D0: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x808006D4: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x808006D8: lui         $at, 0x43EF
    ctx->r1 = S32(0X43EF << 16);
L_808006DC:
    // 0x808006DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808006E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCB4) << 16);
    // 0x808006E4: lwc1        $f16, 0xCB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCB4));
    // 0x808006E8: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808006EC: lui         $a2, 0x4403
    ctx->r6 = S32(0X4403 << 16);
    // 0x808006F0: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808006F4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808006F8: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x808006FC: jal         0x800F10B4
    // 0x80800700: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_33;
    // 0x80800700: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_33:
    // 0x80800704: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800708: jal         0x808002D8
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D8_chflysaucercrate(rdram, ctx);
        goto after_34;
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800710: b           L_808008F4
    // 0x80800714: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008F4;
    // 0x80800714: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800718:
    // 0x80800718: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x8080071C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800720: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x80800724: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800728: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8080072C: lui         $a2, 0xC55A
    ctx->r6 = S32(0XC55A << 16);
    // 0x80800730: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x80800734: lui         $a3, 0x44C8
    ctx->r7 = S32(0X44C8 << 16);
    // 0x80800738: jal         0x800F10B4
    // 0x8080073C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_35;
    // 0x8080073C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_35:
    // 0x80800740: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800744: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80800748: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080074C: jal         0x808002D8
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D8_chflysaucercrate(rdram, ctx);
        goto after_36;
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800754: jal         0x80800904
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800904_chflysaucercrate(rdram, ctx);
        goto after_37;
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x8080075C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCB8) << 16);
    // 0x80800760: lwc1        $f18, 0xCB8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCB8));
    // 0x80800764: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080076C: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80800770: nop

    // 0x80800774: bc1f        L_808007A0
    if (!c1cs) {
        // 0x80800778: nop
    
            goto L_808007A0;
    }
    // 0x80800778: nop

    // 0x8080077C: jal         0x800D8FF8
    // 0x80800780: nop

    func_800D8FF8(rdram, ctx);
        goto after_38;
    // 0x80800780: nop

    after_38:
    // 0x80800784: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCBC) << 16);
    // 0x80800788: lwc1        $f10, 0xCBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCBC));
    // 0x8080078C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800790: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800794: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80800798: b           L_808008F0
    // 0x8080079C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_808008F0;
    // 0x8080079C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_808007A0:
    // 0x808007A0: jal         0x8080000C
    // 0x808007A4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_39;
    // 0x808007A4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_39:
    // 0x808007A8: b           L_808008F4
    // 0x808007AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008F4;
    // 0x808007AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007B0:
    // 0x808007B0: jal         0x80800A2C
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A2C_chflysaucercrate(rdram, ctx);
        goto after_40;
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x808007B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCC0) << 16);
    // 0x808007BC: lwc1        $f0, 0xCC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCC0));
    // 0x808007C0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808007CC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808007D0: nop

    // 0x808007D4: bc1f        L_80800800
    if (!c1cs) {
        // 0x808007D8: nop
    
            goto L_80800800;
    }
    // 0x808007D8: nop

    // 0x808007DC: jal         0x800D8FF8
    // 0x808007E0: nop

    func_800D8FF8(rdram, ctx);
        goto after_41;
    // 0x808007E0: nop

    after_41:
    // 0x808007E4: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808007E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808007EC: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808007F0: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808007F4: sub.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x808007F8: b           L_80800808
    // 0x808007FC: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
        goto L_80800808;
    // 0x808007FC: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_80800800:
    // 0x80800800: jal         0x8080000C
    // 0x80800804: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_42;
    // 0x80800804: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    after_42:
L_80800808:
    // 0x80800808: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCC4) << 16);
    // 0x8080080C: lwc1        $f14, 0xCC4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCC4));
    // 0x80800810: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCC8) << 16);
    // 0x80800814: lwc1        $f8, 0xCC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCC8));
    // 0x80800818: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080081C: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800820: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800824: lui         $a2, 0x44E1
    ctx->r6 = S32(0X44E1 << 16);
    // 0x80800828: jal         0x800F10B4
    // 0x8080082C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_43;
    // 0x8080082C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_43:
    // 0x80800830: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800834: jal         0x808002D8
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D8_chflysaucercrate(rdram, ctx);
        goto after_44;
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x8080083C: b           L_808008F4
    // 0x80800840: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008F4;
    // 0x80800840: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800844:
    // 0x80800844: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x80800848: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8080084C: jal         0x80800A2C
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A2C_chflysaucercrate(rdram, ctx);
        goto after_45;
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80800854: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1696, 0XD0C) << 16);
    // 0x80800858: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1696, 0XE04) << 16);
    // 0x8080085C: addiu       $a3, $a3, 0xE04
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1696, 0XE04));
    // 0x80800860: addiu       $a2, $a2, 0xD0C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1696, 0XD0C));
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800868: jal         0x80089D28
    // 0x8080086C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_46;
    // 0x8080086C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_46:
    // 0x80800870: jal         0x80800A2C
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A2C_chflysaucercrate(rdram, ctx);
        goto after_47;
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80800878: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x8080087C: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800880: jal         0x80101E14
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_48;
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x80800888: beq         $v0, $zero, L_808008F0
    if (ctx->r2 == 0) {
        // 0x8080088C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008F0;
    }
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800890: jal         0x8080000C
    // 0x80800894: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8080000C_chflysaucercrate(rdram, ctx);
        goto after_49;
    // 0x80800894: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_49:
    // 0x80800898: b           L_808008F4
    // 0x8080089C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008F4;
    // 0x8080089C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008A0:
    // 0x808008A0: jal         0x80800A2C
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A2C_chflysaucercrate(rdram, ctx);
        goto after_50;
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x808008A8: jal         0x800D8FF8
    // 0x808008AC: nop

    func_800D8FF8(rdram, ctx);
        goto after_51;
    // 0x808008AC: nop

    after_51:
    // 0x808008B0: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808008B4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808008B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808008BC: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808008C0: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x808008C4: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808008C8: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x808008CC: nop

    // 0x808008D0: bc1fl       L_808008F4
    if (!c1cs) {
        // 0x808008D4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808008F4;
    }
    goto skip_2;
    // 0x808008D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808008D8: jal         0x80089CB8
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_5(rdram, ctx);
        goto after_52;
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x808008E0: b           L_808008F4
    // 0x808008E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008F4;
    // 0x808008E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008E8:
    // 0x808008E8: jal         0x800FFAB0
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_53;
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
L_808008F0:
    // 0x808008F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008F4:
    // 0x808008F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808008FC: jr          $ra
    // 0x80800900: nop

    return;
    // 0x80800900: nop

;}
RECOMP_FUNC void func_808008C0_chmoley(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808008C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808008C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008D0: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x808008D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808008D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808008DC: jal         0x800897C0
    // 0x808008E0: addiu       $a2, $zero, 0x6F
    ctx->r6 = ADD32(0, 0X6F);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808008E0: addiu       $a2, $zero, 0x6F
    ctx->r6 = ADD32(0, 0X6F);
    after_0:
    // 0x808008E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808008E8: jal         0x80100094
    // 0x808008EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808008EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808008F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808008F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808008FC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800900: jal         0x800897E8
    // 0x80800904: nop

    _suexpression_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800904: nop

    after_2:
    // 0x80800908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080090C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800910: jr          $ra
    // 0x80800914: nop

    return;
    // 0x80800914: nop

;}
RECOMP_FUNC void func_80801330_chdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801334: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801338: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080133C: jal         0x80100094
    // 0x80801340: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801340: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801344: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80801348: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080134C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80801350: beql        $t6, $at, L_808013B4
    if (ctx->r14 == ctx->r1) {
        // 0x80801354: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808013B4;
    }
    goto skip_0;
    // 0x80801354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801358: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8080135C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80801360: andi        $t7, $v1, 0x20
    ctx->r15 = ctx->r3 & 0X20;
    // 0x80801364: bne         $t7, $zero, L_808013B0
    if (ctx->r15 != 0) {
        // 0x80801368: andi        $t9, $v1, 0x10
        ctx->r25 = ctx->r3 & 0X10;
            goto L_808013B0;
    }
    // 0x80801368: andi        $t9, $v1, 0x10
    ctx->r25 = ctx->r3 & 0X10;
    // 0x8080136C: beq         $t8, $zero, L_8080137C
    if (ctx->r24 == 0) {
        // 0x80801370: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8080137C;
    }
    // 0x80801370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801374: b           L_8080137C
    // 0x80801378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8080137C;
    // 0x80801378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080137C:
    // 0x8080137C: beq         $t9, $zero, L_808013A8
    if (ctx->r25 == 0) {
        // 0x80801380: nop
    
            goto L_808013A8;
    }
    // 0x80801380: nop

    // 0x80801384: beql        $a1, $zero, L_80801398
    if (ctx->r5 == 0) {
        // 0x80801388: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80801398;
    }
    goto skip_1;
    // 0x80801388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_1:
    // 0x8080138C: b           L_80801398
    // 0x80801390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80801398;
    // 0x80801390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80801398:
    // 0x80801398: jal         0x800DA3B8
    // 0x8080139C: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    func_800DA3B8(rdram, ctx);
        goto after_1;
    // 0x8080139C: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    after_1:
    // 0x808013A0: b           L_808013B4
    // 0x808013A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808013B4;
    // 0x808013A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013A8:
    // 0x808013A8: jal         0x800DA3B8
    // 0x808013AC: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    func_800DA3B8(rdram, ctx);
        goto after_2;
    // 0x808013AC: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    after_2:
L_808013B0:
    // 0x808013B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013B4:
    // 0x808013B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013B8: jr          $ra
    // 0x808013BC: nop

    return;
    // 0x808013BC: nop

;}
RECOMP_FUNC void func_80800000_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800010: lui         $a2, 0xC53E
    ctx->r6 = S32(0XC53E << 16);
    // 0x80800014: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800018: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080001C: ori         $a2, $a2, 0xA000
    ctx->r6 = ctx->r6 | 0XA000;
    // 0x80800020: jal         0x800EFA4C
    // 0x80800024: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800024: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800028: jal         0x80088848
    // 0x8080002C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x8080002C: nop

    after_1:
    // 0x80800030: beq         $v0, $zero, L_8080004C
    if (ctx->r2 == 0) {
        // 0x80800034: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080004C;
    }
    // 0x80800034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080003C: jal         0x80801494
    // 0x80800040: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80801494_chlakemonster(rdram, ctx);
        goto after_2;
    // 0x80800040: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_2:
    // 0x80800044: b           L_80800058
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800058;
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080004C:
    // 0x8080004C: jal         0x80801494
    // 0x80800050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801494_chlakemonster(rdram, ctx);
        goto after_3;
    // 0x80800050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_80802CF0_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802CF0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80802CF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802CF8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802CFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802D00: jal         0x80100094
    // 0x80802D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802D08: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80802D0C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80802D10: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80802D14: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80802D18: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80802D1C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80802D20: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80802D24: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80802D28: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80802D2C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80802D30: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x80802D34: lbu         $v1, 0x24($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X24);
    // 0x80802D38: beql        $v1, $zero, L_80802E38
    if (ctx->r3 == 0) {
        // 0x80802D3C: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80802E38;
    }
    goto skip_0;
    // 0x80802D3C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x80802D40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802D44: beq         $v1, $at, L_80802DE8
    if (ctx->r3 == ctx->r1) {
        // 0x80802D48: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_80802DE8;
    }
    // 0x80802D48: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80802D4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802D50: beq         $v1, $at, L_80802D68
    if (ctx->r3 == ctx->r1) {
        // 0x80802D54: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80802D68;
    }
    // 0x80802D54: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802D58: beq         $v1, $at, L_80802E70
    if (ctx->r3 == ctx->r1) {
        // 0x80802D5C: addiu       $a0, $sp, 0x48
        ctx->r4 = ADD32(ctx->r29, 0X48);
            goto L_80802E70;
    }
    // 0x80802D5C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80802D60: b           L_80802EB4
    // 0x80802D64: nop

        goto L_80802EB4;
    // 0x80802D64: nop

L_80802D68:
    // 0x80802D68: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80802D6C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80802D70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802D74: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x80802D78: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80802D7C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80802D80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802D84: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80802D88: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80802D8C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80802D90: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80802D94: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80802D98: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80802D9C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80802DA0: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80802DA4: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80802DA8: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80802DAC: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80802DB0: jal         0x800F54E4
    // 0x80802DB4: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80802DB4: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80802DB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802DBC: jal         0x800F81D4
    // 0x80802DC0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F81D4(rdram, ctx);
        goto after_2;
    // 0x80802DC0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x80802DC4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80802DC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802DCC: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80802DD0: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80802DD4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80802DD8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80802DDC: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80802DE0: b           L_80802EB4
    // 0x80802DE4: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
        goto L_80802EB4;
    // 0x80802DE4: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
L_80802DE8:
    // 0x80802DE8: jal         0x800EE7F8
    // 0x80802DEC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80802DEC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    after_3:
    // 0x80802DF0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80802DF4: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80802DF8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80802DFC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80802E00: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80802E04: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80802E08: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x80802E0C: lui         $a3, 0xC28C
    ctx->r7 = S32(0XC28C << 16);
    // 0x80802E10: jal         0x800EF6A8
    // 0x80802E14: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800EF6A8(rdram, ctx);
        goto after_4;
    // 0x80802E14: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x80802E18: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80802E1C: jal         0x800EF04C
    // 0x80802E20: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80802E20: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80802E24: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80802E28: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80802E2C: b           L_80802EB4
    // 0x80802E30: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
        goto L_80802EB4;
    // 0x80802E30: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80802E34: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80802E38:
    // 0x80802E38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802E3C: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x80802E40: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80802E44: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80802E48: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80802E4C: jal         0x800EF4E4
    // 0x80802E50: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_6;
    // 0x80802E50: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x80802E54: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80802E58: jal         0x800EF04C
    // 0x80802E5C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80802E5C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80802E60: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80802E64: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80802E68: b           L_80802EB4
    // 0x80802E6C: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
        goto L_80802EB4;
    // 0x80802E6C: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
L_80802E70:
    // 0x80802E70: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80802E74: lwc1        $f0, 0x10($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80802E78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80802E7C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80802E80: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x80802E84: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80802E88: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80802E8C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80802E90: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80802E94: jal         0x800EF4E4
    // 0x80802E98: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_8;
    // 0x80802E98: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80802E9C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80802EA0: jal         0x800EF04C
    // 0x80802EA4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x80802EA4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80802EA8: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80802EAC: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80802EB0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
L_80802EB4:
    // 0x80802EB4: jal         0x800906B0
    // 0x80802EB8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800906B0(rdram, ctx);
        goto after_10;
    // 0x80802EB8: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_10:
    // 0x80802EBC: jal         0x800906DC
    // 0x80802EC0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800906DC(rdram, ctx);
        goto after_11;
    // 0x80802EC0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_11:
    // 0x80802EC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802EC8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802ECC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80802ED0: jr          $ra
    // 0x80802ED4: nop

    return;
    // 0x80802ED4: nop

;}
RECOMP_FUNC void bsbflap_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800018: jal         0x8008CDB8
    // 0x8080001C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    baanim_playForDuration_once(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_0:
    // 0x80800020: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800024: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080002C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800030: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800034: jal         0x8009FFD8
    // 0x80800038: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800038: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8080003C: jal         0x8009EF04
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_2;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800044: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800048: nop

    // 0x8080004C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800050: nop

    // 0x80800054: bc1t        L_80800070
    if (c1cs) {
        // 0x80800058: nop
    
            goto L_80800070;
    }
    // 0x80800058: nop

    // 0x8080005C: jal         0x8009EEB8
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_3;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800064: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800068: jal         0x8009C914
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_4;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80800070:
    // 0x80800070: jal         0x8009C990
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_5;
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800078: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080007C: jal         0x8009B9C0
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_6;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800084: jal         0x800841D8
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080008C: jal         0x8009C990
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_8;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800094: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800098: jal         0x8009BB00
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_9;
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808000A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x8009BA68
    // 0x808000AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x808000AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x8009BA58
    // 0x808000B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_11;
    // 0x808000B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x808000BC: lui         $a1, 0xC489
    ctx->r5 = S32(0XC489 << 16);
    // 0x808000C0: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808000C4: jal         0x8009BCB4
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_12;
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: jal         0x800A0CF4
    // 0x808000D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_13;
    // 0x808000D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: jal         0x80095760
    // 0x808000E0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    baflag_set(rdram, ctx);
        goto after_14;
    // 0x808000E0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_14:
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000EC: jal         0x80085338
    // 0x808000F0: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    _batimer_set(rdram, ctx);
        goto after_15;
    // 0x808000F0: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    after_15:
    // 0x808000F4: jal         0x8009D874
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D874(rdram, ctx);
        goto after_16;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808000FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800100: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80800104: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x80800108: swc1        $f6, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f6.u32l;
    // 0x8080010C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800110: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800114: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void func_8080014C_chhotwatersteam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080014C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800150: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800158: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8080015C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800160: jal         0x800E3E8C
    // 0x80800164: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    func_800E3E8C(rdram, ctx);
        goto after_0;
    // 0x80800164: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_0:
    // 0x80800168: beq         $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x8080016C: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_808001D4;
    }
    // 0x8080016C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800170: jal         0x800EE7F8
    // 0x80800174: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800174: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x80800178: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080017C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800180: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800184: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800188: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8080018C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800190: jal         0x800EE7F8
    // 0x80800194: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800194: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800198: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080019C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001A0: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808001A4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1428, 0X288) << 16);
    // 0x808001A8: addiu       $t6, $t6, 0x288
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1428, 0X288));
    // 0x808001AC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808001B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001B4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x808001B8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808001BC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x808001C0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001C4: jal         0x800BBCB8
    // 0x808001C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x808001C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x808001CC: b           L_808001D8
    // 0x808001D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001D8;
    // 0x808001D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001D4:
    // 0x808001D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001D8:
    // 0x808001D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808001E0: jr          $ra
    // 0x808001E4: nop

    return;
    // 0x808001E4: nop

;}
RECOMP_FUNC void func_8080044C_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080044C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800450: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800454: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800458: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080045C: jal         0x80100094
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800464: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    // 0x80800470: jal         0x8008A2A0
    // 0x80800474: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800474: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80800478: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080047C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1932, 0X1098) << 16);
    // 0x80800480: addiu       $a1, $a1, 0x1098
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1932, 0X1098));
    // 0x80800484: jal         0x8008A300
    // 0x80800488: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    _susubgame_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800488: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_2:
    // 0x8080048C: jal         0x80088848
    // 0x80800490: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800490: nop

    after_3:
    // 0x80800494: beq         $v0, $zero, L_808004AC
    if (ctx->r2 == 0) {
        // 0x80800498: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004AC;
    }
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080049C: jal         0x80102424
    // 0x808004A0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x808004A0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_4:
    // 0x808004A4: b           L_80800508
    // 0x808004A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800508;
    // 0x808004A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004AC:
    // 0x808004AC: jal         0x800DA298
    // 0x808004B0: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808004B0: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    after_5:
    // 0x808004B4: beq         $v0, $zero, L_808004E0
    if (ctx->r2 == 0) {
        // 0x808004B8: nop
    
            goto L_808004E0;
    }
    // 0x808004B8: nop

    // 0x808004BC: jal         0x800EA05C
    // 0x808004C0: nop

    func_800EA05C(rdram, ctx);
        goto after_6;
    // 0x808004C0: nop

    after_6:
    // 0x808004C4: addiu       $at, $zero, 0xB9
    ctx->r1 = ADD32(0, 0XB9);
    // 0x808004C8: bne         $v0, $at, L_808004E0
    if (ctx->r2 != ctx->r1) {
        // 0x808004CC: nop
    
            goto L_808004E0;
    }
    // 0x808004CC: nop

    // 0x808004D0: jal         0x800FFAB0
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808004D8: b           L_80800508
    // 0x808004DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800508;
    // 0x808004DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004E0:
    // 0x808004E0: jal         0x80800DAC
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DAC_chprisonbits(rdram, ctx);
        goto after_8;
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808004E8: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    // 0x808004EC: jal         0x80088278
    // 0x808004F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x808004F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x808004F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808004F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004FC: jal         0x80088C00
    // 0x80800500: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800500: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_10:
    // 0x80800504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800508:
    // 0x80800508: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080050C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800510: jr          $ra
    // 0x80800514: nop

    return;
    // 0x80800514: nop

;}
RECOMP_FUNC void func_8008E938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E938: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8008E93C: jr          $ra
    // 0x8008E940: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    return;
    // 0x8008E940: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
;}
RECOMP_FUNC void func_800F6B94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6B94: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6B98: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6B9C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6BA0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F6BA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F6BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6BAC: jal         0x800A3274
    // 0x800F6BB0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x800F6BB0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6BB4: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x800F6BB8: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F6BBC: beq         $v0, $zero, L_800F6BD4
    if (ctx->r2 == 0) {
        // 0x800F6BC0: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F6BD4;
    }
    // 0x800F6BC0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6BC4: jal         0x800A1718
    // 0x800F6BC8: nop

    func_800A1718(rdram, ctx);
        goto after_1;
    // 0x800F6BC8: nop

    after_1:
    // 0x800F6BCC: slti        $t8, $v0, 0x5
    ctx->r24 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800F6BD0: xori        $v0, $t8, 0x1
    ctx->r2 = ctx->r24 ^ 0X1;
L_800F6BD4:
    // 0x800F6BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6BD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F6BDC: jr          $ra
    // 0x800F6BE0: nop

    return;
    // 0x800F6BE0: nop

;}
RECOMP_FUNC void func_80800894_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800894: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800898: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080089C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x808008A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008A4: beq         $a1, $at, L_808008CC
    if (ctx->r5 == ctx->r1) {
        // 0x808008A8: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_808008CC;
    }
    // 0x808008A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008AC: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x808008B0: beq         $a1, $at, L_8080090C
    if (ctx->r5 == ctx->r1) {
        // 0x808008B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080090C;
    }
    // 0x808008B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B8: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x808008BC: beq         $a1, $at, L_80800928
    if (ctx->r5 == ctx->r1) {
        // 0x808008C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800928;
    }
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C4: b           L_80800934
    // 0x808008C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800934;
    // 0x808008C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008CC:
    // 0x808008CC: jal         0x80800348
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800348_chhillbilly(rdram, ctx);
        goto after_0;
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D8: addiu       $a1, $zero, 0x789
    ctx->r5 = ADD32(0, 0X789);
    // 0x808008DC: jal         0x808009D8
    // 0x808008E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808009D8_chhillbilly(rdram, ctx);
        goto after_1;
    // 0x808008E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808008E4: jal         0x8010A570
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F0: jal         0x8008A148
    // 0x808008F4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x808008F4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_3:
    // 0x808008F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x808008FC: lbu         $t7, 0x2A($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2A);
    // 0x80800900: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80800904: b           L_80800930
    // 0x80800908: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
        goto L_80800930;
    // 0x80800908: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
L_8080090C:
    // 0x8080090C: jal         0x8008A148
    // 0x80800910: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800910: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_4:
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800918: jal         0x8008A128
    // 0x8080091C: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    _sucoaster_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x8080091C: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    after_5:
    // 0x80800920: b           L_80800934
    // 0x80800924: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800934;
    // 0x80800924: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800928:
    // 0x80800928: jal         0x8008A148
    // 0x8080092C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x8080092C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_6:
L_80800930:
    // 0x80800930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800934:
    // 0x80800934: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800938: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080093C: jr          $ra
    // 0x80800940: nop

    return;
    // 0x80800940: nop

;}
RECOMP_FUNC void func_80801DDC_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801DE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801DE8: jal         0x80100094
    // 0x80801DEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801DEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801DF0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80801DF4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801DF8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X267C) << 16);
    // 0x80801DFC: lbu         $a0, 0x5F($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X5F);
    // 0x80801E00: addiu       $a2, $a2, 0x267C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X267C));
    // 0x80801E04: addiu       $a1, $v1, 0x14
    ctx->r5 = ADD32(ctx->r3, 0X14);
    // 0x80801E08: bne         $a0, $zero, L_80801E28
    if (ctx->r4 != 0) {
        // 0x80801E0C: lui         $at, 0x44FA
        ctx->r1 = S32(0X44FA << 16);
            goto L_80801E28;
    }
    // 0x80801E0C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80801E10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801E14: jal         0x800C4350
    // 0x80801E18: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800C4350(rdram, ctx);
        goto after_1;
    // 0x80801E18: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80801E1C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80801E20: b           L_80801E9C
    // 0x80801E24: sb          $v0, 0x5F($a3)
    MEM_B(0X5F, ctx->r7) = ctx->r2;
        goto L_80801E9C;
    // 0x80801E24: sb          $v0, 0x5F($a3)
    MEM_B(0X5F, ctx->r7) = ctx->r2;
L_80801E28:
    // 0x80801E28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801E2C: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80801E30: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80801E34: nop

    // 0x80801E38: bc1fl       L_80801E8C
    if (!c1cs) {
        // 0x80801E3C: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_80801E8C;
    }
    goto skip_0;
    // 0x80801E3C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    skip_0:
    // 0x80801E40: lw          $t6, 0x7C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X7C);
    // 0x80801E44: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80801E48: bgezl       $t8, L_80801E8C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801E4C: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_80801E8C;
    }
    goto skip_1;
    // 0x80801E4C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    skip_1:
    // 0x80801E50: lwc1        $f8, 0x3C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80801E54: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80801E58: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80801E5C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80801E60: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801E64: jal         0x800C3058
    // 0x80801E68: nop

    func_800C3058(rdram, ctx);
        goto after_2;
    // 0x80801E68: nop

    after_2:
    // 0x80801E6C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801E70: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80801E74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801E78: addiu       $a1, $v1, 0x14
    ctx->r5 = ADD32(ctx->r3, 0X14);
    // 0x80801E7C: jal         0x800C4350
    // 0x80801E80: lbu         $a0, 0x5F($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X5F);
    func_800C4350(rdram, ctx);
        goto after_3;
    // 0x80801E80: lbu         $a0, 0x5F($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X5F);
    after_3:
    // 0x80801E84: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801E88: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
L_80801E8C:
    // 0x80801E8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801E90: lwc1        $f16, 0x3C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80801E94: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80801E98: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
L_80801E9C:
    // 0x80801E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801EA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801EA4: jr          $ra
    // 0x80801EA8: nop

    return;
    // 0x80801EA8: nop

;}
RECOMP_FUNC void func_80800138_chweather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080013C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800140: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800144: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800148: bne         $a1, $at, L_80800160
    if (ctx->r5 != ctx->r1) {
        // 0x8080014C: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80800160;
    }
    // 0x8080014C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800150: jal         0x800B7C10
    // 0x80800154: nop

    func_800B7C10(rdram, ctx);
        goto after_0;
    // 0x80800154: nop

    after_0:
    // 0x80800158: jal         0x80088958
    // 0x8080015C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _fxleaves_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x8080015C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
L_80800160:
    // 0x80800160: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800164: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800168: lhu         $t8, 0x72($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X72);
    // 0x8080016C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800170: bnel        $t9, $at, L_8080018C
    if (ctx->r25 != ctx->r1) {
        // 0x80800174: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_8080018C;
    }
    goto skip_0;
    // 0x80800174: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800178: jal         0x800B7C10
    // 0x8080017C: nop

    func_800B7C10(rdram, ctx);
        goto after_2;
    // 0x8080017C: nop

    after_2:
    // 0x80800180: jal         0x80088960
    // 0x80800184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _fxleaves_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800188: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_8080018C:
    // 0x8080018C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800190: bnel        $t0, $at, L_80800210
    if (ctx->r8 != ctx->r1) {
        // 0x80800194: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_80800210;
    }
    goto skip_1;
    // 0x80800194: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80800198: jal         0x800B7C54
    // 0x8080019C: nop

    func_800B7C54(rdram, ctx);
        goto after_4;
    // 0x8080019C: nop

    after_4:
    // 0x808001A0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808001A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808001A8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(732, 0X410) << 16);
    // 0x808001AC: lw          $t2, 0x6C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X6C);
    // 0x808001B0: addiu       $t7, $t7, 0x410
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(732, 0X410));
    // 0x808001B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001B8: sll         $t3, $t2, 11
    ctx->r11 = S32(ctx->r10 << 11);
    // 0x808001BC: srl         $t4, $t3, 20
    ctx->r12 = S32(U32(ctx->r11) >> 20);
    // 0x808001C0: addiu       $t5, $t4, -0x204
    ctx->r13 = ADD32(ctx->r12, -0X204);
    // 0x808001C4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x808001C8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x808001CC: jal         0x80088918
    // 0x808001D0: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    _fxrain_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x808001D0: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_5:
    // 0x808001D4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808001D8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808001DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808001E0: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x808001E4: beql        $t0, $zero, L_80800210
    if (ctx->r8 == 0) {
        // 0x808001E8: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_80800210;
    }
    goto skip_2;
    // 0x808001E8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x808001EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808001F0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808001F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808001F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001FC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800200: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800204: jal         0x80088910
    // 0x80800208: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    _fxrain_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x80800208: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x8080020C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
L_80800210:
    // 0x80800210: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800214: lhu         $t2, 0x72($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X72);
    // 0x80800218: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x8080021C: bnel        $t3, $at, L_80800238
    if (ctx->r11 != ctx->r1) {
        // 0x80800220: lw          $t4, 0x2C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X2C);
            goto L_80800238;
    }
    goto skip_3;
    // 0x80800220: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x80800224: jal         0x800B7C54
    // 0x80800228: nop

    func_800B7C54(rdram, ctx);
        goto after_7;
    // 0x80800228: nop

    after_7:
    // 0x8080022C: jal         0x80088920
    // 0x80800230: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _fxrain_entrypoint_8(rdram, ctx);
        goto after_8;
    // 0x80800230: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800234: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
L_80800238:
    // 0x80800238: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080023C: bnel        $t4, $at, L_80800258
    if (ctx->r12 != ctx->r1) {
        // 0x80800240: lw          $t5, 0x28($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X28);
            goto L_80800258;
    }
    goto skip_4;
    // 0x80800240: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    skip_4:
    // 0x80800244: jal         0x800B7CA4
    // 0x80800248: nop

    func_800B7CA4(rdram, ctx);
        goto after_9;
    // 0x80800248: nop

    after_9:
    // 0x8080024C: jal         0x800B90C8
    // 0x80800250: nop

    func_800B90C8(rdram, ctx);
        goto after_10;
    // 0x80800250: nop

    after_10:
    // 0x80800254: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
L_80800258:
    // 0x80800258: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080025C: lhu         $t6, 0x72($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X72);
    // 0x80800260: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800264: bnel        $t7, $at, L_80800280
    if (ctx->r15 != ctx->r1) {
        // 0x80800268: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_80800280;
    }
    goto skip_5;
    // 0x80800268: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    skip_5:
    // 0x8080026C: jal         0x800B7CA4
    // 0x80800270: nop

    func_800B7CA4(rdram, ctx);
        goto after_11;
    // 0x80800270: nop

    after_11:
    // 0x80800274: jal         0x800B90E8
    // 0x80800278: nop

    func_800B90E8(rdram, ctx);
        goto after_12;
    // 0x80800278: nop

    after_12:
    // 0x8080027C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
L_80800280:
    // 0x80800280: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80800284: lbu         $t3, 0x72($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X72);
    // 0x80800288: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8080028C: andi        $t4, $t3, 0xFF03
    ctx->r12 = ctx->r11 & 0XFF03;
    // 0x80800290: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80800294: sb          $t5, 0x72($t2)
    MEM_B(0X72, ctx->r10) = ctx->r13;
    // 0x80800298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080029C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002A0: jr          $ra
    // 0x808002A4: nop

    return;
    // 0x808002A4: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009E8: jal         0x80800960
    // 0x808009EC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_80800960_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x808009EC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x808009F0: bne         $v0, $zero, L_80800A00
    if (ctx->r2 != 0) {
        // 0x808009F4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800A00;
    }
    // 0x808009F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808009F8: b           L_80800A0C
    // 0x808009FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x808009FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A00:
    // 0x80800A00: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800A04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800A08: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_80800A0C:
    // 0x80800A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A14: jr          $ra
    // 0x80800A18: nop

    return;
    // 0x80800A18: nop

;}
RECOMP_FUNC void func_80800284_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800284: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800288: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080028C: jal         0x80800720
    // 0x80800290: nop

    func_80800720_chburgerstand(rdram, ctx);
        goto after_0;
    // 0x80800290: nop

    after_0:
    // 0x80800294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080029C: jr          $ra
    // 0x808002A0: nop

    return;
    // 0x808002A0: nop

;}
RECOMP_FUNC void func_800D119C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D119C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D11A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D11A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D11A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D11AC: jal         0x800D0B68
    // 0x800D11B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800D0B68(rdram, ctx);
        goto after_0;
    // 0x800D11B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D11B4: bne         $v0, $zero, L_800D1204
    if (ctx->r2 != 0) {
        // 0x800D11B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D1204;
    }
    // 0x800D11B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D11BC: jal         0x800D0A9C
    // 0x800D11C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x800D11C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800D11C4: beq         $v0, $zero, L_800D1204
    if (ctx->r2 == 0) {
        // 0x800D11C8: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_800D1204;
    }
    // 0x800D11C8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800D11CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D11D0: bne         $t6, $at, L_800D11F8
    if (ctx->r14 != ctx->r1) {
        // 0x800D11D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D11F8;
    }
    // 0x800D11D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D11D8: jal         0x800D0634
    // 0x800D11DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0634(rdram, ctx);
        goto after_2;
    // 0x800D11DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x800D11E0: jal         0x800FFA88
    // 0x800D11E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800FFA88(rdram, ctx);
        goto after_3;
    // 0x800D11E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800D11E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D11EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D11F0: jal         0x800D05E4
    // 0x800D11F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D05E4(rdram, ctx);
        goto after_4;
    // 0x800D11F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_800D11F8:
    // 0x800D11F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D11FC: jal         0x800D0B38
    // 0x800D1200: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800D0B38(rdram, ctx);
        goto after_5;
    // 0x800D1200: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
L_800D1204:
    // 0x800D1204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1208: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D120C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D1210: jr          $ra
    // 0x800D1214: nop

    return;
    // 0x800D1214: nop

;}
RECOMP_FUNC void func_800944E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800944E0: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800944E4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800944E8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800944EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800944F0: jr          $ra
    // 0x800944F4: lbu         $v0, 0x7E3C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7E3C);
    return;
    // 0x800944F4: lbu         $v0, 0x7E3C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7E3C);
;}
RECOMP_FUNC void susplinet_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080044C: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x80800450: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800458: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8080045C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800460: lh          $t6, 0x30($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X30);
    // 0x80800464: lh          $t7, 0x32($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X32);
    // 0x80800468: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8080046C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800470: addu        $a3, $a0, $t6
    ctx->r7 = ADD32(ctx->r4, ctx->r14);
    // 0x80800474: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80800478: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x8080047C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80800480: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80800484: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800488: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080048C: jal         0x80800384
    // 0x80800490: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    func_80800384_susplinet(rdram, ctx);
        goto after_0;
    // 0x80800490: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80800494: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800498: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8080049C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x808004A0: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x808004A4: lh          $t9, 0x4E($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4E);
    // 0x808004A8: addiu       $a0, $t6, 0x1
    ctx->r4 = ADD32(ctx->r14, 0X1);
    // 0x808004AC: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x808004B0: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x808004B4: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x808004B8: sra         $t8, $t0, 16
    ctx->r24 = S32(SIGNED(ctx->r8) >> 16);
    // 0x808004BC: sra         $t5, $t1, 16
    ctx->r13 = S32(SIGNED(ctx->r9) >> 16);
    // 0x808004C0: sra         $t7, $t2, 16
    ctx->r15 = S32(SIGNED(ctx->r10) >> 16);
    // 0x808004C4: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x808004C8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x808004CC: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808004D0: or          $t1, $t5, $zero
    ctx->r9 = ctx->r13 | 0;
    // 0x808004D4: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x808004D8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x808004DC: bne         $at, $zero, L_808004F8
    if (ctx->r1 != 0) {
        // 0x808004E0: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_808004F8;
    }
    // 0x808004E0: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x808004E4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x808004E8: jal         0x808002AC
    // 0x808004EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    susplinet_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x808004EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x808004F0: b           L_80800614
    // 0x808004F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800614;
    // 0x808004F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004F8:
    // 0x808004F8: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x808004FC: sll         $t4, $t0, 1
    ctx->r12 = S32(ctx->r8 << 1);
    // 0x80800500: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x80800504: addu        $t3, $a3, $v0
    ctx->r11 = ADD32(ctx->r7, ctx->r2);
    // 0x80800508: lh          $v1, 0x0($t3)
    ctx->r3 = MEM_H(ctx->r11, 0X0);
    // 0x8080050C: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80800510: beql        $v1, $t6, L_80800530
    if (ctx->r3 == ctx->r14) {
        // 0x80800514: mtc1        $v1, $f6
        ctx->f6.u32l = ctx->r3;
            goto L_80800530;
    }
    goto skip_0;
    // 0x80800514: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    skip_0:
    // 0x80800518: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8080051C: jal         0x808002AC
    // 0x80800520: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    susplinet_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800520: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80800524: b           L_80800614
    // 0x80800528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800614;
    // 0x80800528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080052C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
L_80800530:
    // 0x80800530: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800534: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800538: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8080053C: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80800540: nop

    // 0x80800544: bc1fl       L_80800564
    if (!c1cs) {
        // 0x80800548: lh          $t9, 0x0($t8)
        ctx->r25 = MEM_H(ctx->r24, 0X0);
            goto L_80800564;
    }
    goto skip_1;
    // 0x80800548: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    skip_1:
    // 0x8080054C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800550: jal         0x808002AC
    // 0x80800554: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    susplinet_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800554: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80800558: b           L_80800614
    // 0x8080055C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800614;
    // 0x8080055C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800560: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
L_80800564:
    // 0x80800564: addiu       $a0, $zero, 0x644
    ctx->r4 = ADD32(0, 0X644);
    // 0x80800568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080056C: andi        $t3, $t9, 0x1
    ctx->r11 = ctx->r25 & 0X1;
    // 0x80800570: beql        $t3, $zero, L_80800608
    if (ctx->r11 == 0) {
        // 0x80800574: mfc1        $a1, $f12
        ctx->r5 = (int32_t)ctx->f12.u32l;
            goto L_80800608;
    }
    goto skip_2;
    // 0x80800574: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    skip_2:
    // 0x80800578: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080057C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800580: sh          $t1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r9;
    // 0x80800584: jal         0x800DA9E4
    // 0x80800588: sh          $t2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r10;
    func_800DA9E4(rdram, ctx);
        goto after_4;
    // 0x80800588: sh          $t2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r10;
    after_4:
    // 0x8080058C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800590: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800594: lh          $t1, 0x1C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X1C);
    // 0x80800598: bne         $v0, $zero, L_808005D0
    if (ctx->r2 != 0) {
        // 0x8080059C: lh          $t2, 0x1A($sp)
        ctx->r10 = MEM_H(ctx->r29, 0X1A);
            goto L_808005D0;
    }
    // 0x8080059C: lh          $t2, 0x1A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1A);
    // 0x808005A0: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x808005A4: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x808005A8: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x808005AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808005B0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x808005B4: nop

    // 0x808005B8: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808005BC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808005C0: jal         0x808002AC
    // 0x808005C4: nop

    susplinet_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x808005C4: nop

    after_5:
    // 0x808005C8: b           L_80800614
    // 0x808005CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800614;
    // 0x808005CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005D0:
    // 0x808005D0: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x808005D4: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x808005D8: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x808005DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808005E0: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x808005E4: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x808005E8: nop

    // 0x808005EC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808005F0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808005F4: jal         0x808002AC
    // 0x808005F8: nop

    susplinet_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x808005F8: nop

    after_6:
    // 0x808005FC: b           L_80800614
    // 0x80800600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800614;
    // 0x80800600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800604: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
L_80800608:
    // 0x80800608: jal         0x808002AC
    // 0x8080060C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    susplinet_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x8080060C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_7:
    // 0x80800610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800614:
    // 0x80800614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800618: jr          $ra
    // 0x8080061C: nop

    return;
    // 0x8080061C: nop

;}
RECOMP_FUNC void _subaddiedialog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A1B0: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A1B0);
    return;
    // 0x8008A1B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
