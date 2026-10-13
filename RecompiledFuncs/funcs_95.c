#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void boot___osSiDeviceBusy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_808000B4_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000C0: jal         0x80100094
    // 0x808000C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000C8: lbu         $a1, 0xF($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XF);
    // 0x808000CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000D4: beq         $a1, $zero, L_80800120
    if (ctx->r5 == 0) {
        // 0x808000D8: nop
    
            goto L_80800120;
    }
    // 0x808000D8: nop

    // 0x808000DC: beq         $a1, $at, L_808000F4
    if (ctx->r5 == ctx->r1) {
        // 0x808000E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000F4;
    }
    // 0x808000E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000E4: beq         $a1, $at, L_80800120
    if (ctx->r5 == ctx->r1) {
        // 0x808000E8: nop
    
            goto L_80800120;
    }
    // 0x808000E8: nop

    // 0x808000EC: b           L_80800188
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800188;
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F4:
    // 0x808000F4: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808000F8: addiu       $a0, $zero, 0x16F
    ctx->r4 = ADD32(0, 0X16F);
    // 0x808000FC: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800100: bgez        $t8, L_80800110
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800104: nop
    
            goto L_80800110;
    }
    // 0x80800104: nop

    // 0x80800108: b           L_80800110
    // 0x8080010C: addiu       $a0, $zero, 0x170
    ctx->r4 = ADD32(0, 0X170);
        goto L_80800110;
    // 0x8080010C: addiu       $a0, $zero, 0x170
    ctx->r4 = ADD32(0, 0X170);
L_80800110:
    // 0x80800110: jal         0x80087A58
    // 0x80800114: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800114: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800118: b           L_80800188
    // 0x8080011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800188;
    // 0x8080011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800120:
    // 0x80800120: jal         0x80800090
    // 0x80800124: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800090_chhandcart(rdram, ctx);
        goto after_2;
    // 0x80800124: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800128: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080012C: bne         $v0, $at, L_80800160
    if (ctx->r2 != ctx->r1) {
        // 0x80800130: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800160;
    }
    // 0x80800130: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800134: lw          $t9, 0x64($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X64);
    // 0x80800138: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x8080013C: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x80800140: bgez        $t1, L_80800150
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800144: nop
    
            goto L_80800150;
    }
    // 0x80800144: nop

    // 0x80800148: b           L_80800150
    // 0x8080014C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
        goto L_80800150;
    // 0x8080014C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
L_80800150:
    // 0x80800150: jal         0x80087A58
    // 0x80800154: addiu       $a0, $zero, 0xC7
    ctx->r4 = ADD32(0, 0XC7);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800154: addiu       $a0, $zero, 0xC7
    ctx->r4 = ADD32(0, 0XC7);
    after_3:
    // 0x80800158: b           L_80800188
    // 0x8080015C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800188;
    // 0x8080015C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800160:
    // 0x80800160: lw          $t2, 0x64($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X64);
    // 0x80800164: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80800168: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x8080016C: bgez        $t4, L_8080017C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800170: nop
    
            goto L_8080017C;
    }
    // 0x80800170: nop

    // 0x80800174: b           L_8080017C
    // 0x80800178: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
        goto L_8080017C;
    // 0x80800178: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
L_8080017C:
    // 0x8080017C: jal         0x80087A58
    // 0x80800180: addiu       $a0, $zero, 0xC7
    ctx->r4 = ADD32(0, 0XC7);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800180: addiu       $a0, $zero, 0xC7
    ctx->r4 = ADD32(0, 0XC7);
    after_4:
    // 0x80800184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800188:
    // 0x80800188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void _sumole_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A60: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A60);
    return;
    // 0x80089A64: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_800BFA1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFA1C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BFA20: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BFA24: addiu       $v0, $v0, -0x7A44
    ctx->r2 = ADD32(ctx->r2, -0X7A44);
    // 0x800BFA28: addiu       $a1, $a1, -0x7A50
    ctx->r5 = ADD32(ctx->r5, -0X7A50);
    // 0x800BFA2C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800BFA30:
    // 0x800BFA30: lw          $t6, 0x180($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X180);
    // 0x800BFA34: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BFA38: addiu       $t7, $t6, -0x64
    ctx->r15 = ADD32(ctx->r14, -0X64);
    // 0x800BFA3C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800BFA40: nop

    // 0x800BFA44: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BFA48: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800BFA4C: nop

    // 0x800BFA50: bc1fl       L_800BFA64
    if (!c1cs) {
        // 0x800BFA54: lw          $t8, 0x18C($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X18C);
            goto L_800BFA64;
    }
    goto skip_0;
    // 0x800BFA54: lw          $t8, 0x18C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X18C);
    skip_0:
    // 0x800BFA58: jr          $ra
    // 0x800BFA5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800BFA5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BFA60: lw          $t8, 0x18C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X18C);
L_800BFA64:
    // 0x800BFA64: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800BFA68: addiu       $t9, $t8, 0x64
    ctx->r25 = ADD32(ctx->r24, 0X64);
    // 0x800BFA6C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800BFA70: nop

    // 0x800BFA74: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BFA78: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800BFA7C: nop

    // 0x800BFA80: bc1f        L_800BFA90
    if (!c1cs) {
        // 0x800BFA84: nop
    
            goto L_800BFA90;
    }
    // 0x800BFA84: nop

    // 0x800BFA88: jr          $ra
    // 0x800BFA8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800BFA8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BFA90:
    // 0x800BFA90: bne         $a1, $v0, L_800BFA30
    if (ctx->r5 != ctx->r2) {
        // 0x800BFA94: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800BFA30;
    }
    // 0x800BFA94: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800BFA98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800BFA9C: jr          $ra
    // 0x800BFAA0: nop

    return;
    // 0x800BFAA0: nop

;}
RECOMP_FUNC void func_80802C04_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802C08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802C14: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80802C18: jal         0x80100094
    // 0x80802C1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802C1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802C20: lui         $a1, 0x3F70
    ctx->r5 = S32(0X3F70 << 16);
    // 0x80802C24: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802C28: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x80802C2C: jal         0x80105998
    // 0x80802C30: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80105998(rdram, ctx);
        goto after_1;
    // 0x80802C30: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80802C34: beq         $v0, $zero, L_80802C54
    if (ctx->r2 == 0) {
        // 0x80802C38: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80802C54;
    }
    // 0x80802C38: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80802C3C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80802C40: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80802C44: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80802C48: sb          $zero, 0xFE($t6)
    MEM_B(0XFE, ctx->r14) = 0;
    // 0x80802C4C: jal         0x808008DC
    // 0x80802C50: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    func_808008DC_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x80802C50: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    after_2:
L_80802C54:
    // 0x80802C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802C58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802C5C: jr          $ra
    // 0x80802C60: nop

    return;
    // 0x80802C60: nop

;}
RECOMP_FUNC void func_808011F8_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808011FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801200: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801204: jal         0x800839E8
    // 0x80801208: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80801208: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x8080120C: beq         $v0, $zero, L_80801220
    if (ctx->r2 == 0) {
        // 0x80801210: nop
    
            goto L_80801220;
    }
    // 0x80801210: nop

    // 0x80801214: jal         0x800839B0
    // 0x80801218: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80801218: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080121C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80801220:
    // 0x80801220: jal         0x808005DC
    // 0x80801224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bstrexsmall_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80801228: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080122C: jal         0x8009E5C8
    // 0x80801230: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80801230: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80801234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801238: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080123C: jr          $ra
    // 0x80801240: nop

    return;
    // 0x80801240: nop

;}
RECOMP_FUNC void bssplitup_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800478: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080047C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800480: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800484: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80800488: jal         0x800852F0
    // 0x8080048C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x8080048C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800490: beq         $v0, $zero, L_808004A4
    if (ctx->r2 == 0) {
        // 0x80800494: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_808004A4;
    }
    // 0x80800494: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800498: jal         0x80084998
    // 0x8080049C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _baduo_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x8080049C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808004A0: addiu       $a2, $zero, 0xB9
    ctx->r6 = ADD32(0, 0XB9);
L_808004A4:
    // 0x808004A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004A8: jal         0x8009E5C8
    // 0x808004AC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x808004AC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x808004B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004B8: jr          $ra
    // 0x808004BC: nop

    return;
    // 0x808004BC: nop

;}
RECOMP_FUNC void bstrexlarge_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808015F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(412, 0X1A20) << 16);
    // 0x808015F8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808015FC: jr          $ra
    // 0x80801600: lw          $v0, 0x1A20($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X1A20));
    return;
    // 0x80801600: lw          $v0, 0x1A20($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X1A20));
;}
RECOMP_FUNC void fxstep_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800510: jr          $ra
    // 0x80800514: sb          $a1, 0x26($a0)
    MEM_B(0X26, ctx->r4) = ctx->r5;
    return;
    // 0x80800514: sb          $a1, 0x26($a0)
    MEM_B(0X26, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void bssnowball_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800234: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800238: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080023C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800240: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800244: jal         0x8009E77C
    // 0x80800248: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x80800248: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_0:
    // 0x8080024C: bnel        $v0, $zero, L_808002E8
    if (ctx->r2 != 0) {
        // 0x80800250: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002E8;
    }
    goto skip_0;
    // 0x80800250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800254: jal         0x800850E8
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basnowball_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800264: jal         0x8009BFE4
    // 0x80800268: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_2;
    // 0x80800268: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_2:
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800274: jal         0x8009C554
    // 0x80800278: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_3;
    // 0x80800278: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_3:
    // 0x8080027C: jal         0x8009EFA8
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_4;
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800284: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x80800288: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x8009F1C8
    // 0x80800294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_5;
    // 0x80800294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080029C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002A0: jal         0x8009F1C8
    // 0x808002A4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_6;
    // 0x808002A4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_6:
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: jal         0x80095760
    // 0x808002B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_set(rdram, ctx);
        goto after_7;
    // 0x808002B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: jal         0x80095760
    // 0x808002BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    baflag_set(rdram, ctx);
        goto after_8;
    // 0x808002BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002C8: jal         0x800947EC
    // 0x808002CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_9;
    // 0x808002CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x808002D0: lui         $a1, 0x3F8C
    ctx->r5 = S32(0X3F8C << 16);
    // 0x808002D4: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x808002D8: ori         $a1, $a1, 0xCC80
    ctx->r5 = ctx->r5 | 0XCC80;
    // 0x808002DC: jal         0x80092864
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092864(rdram, ctx);
        goto after_10;
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808002E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002E8:
    // 0x808002E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002F0: jr          $ra
    // 0x808002F4: nop

    return;
    // 0x808002F4: nop

;}
RECOMP_FUNC void func_80800218_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8080021C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800220: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800224: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800228: jal         0x80100094
    // 0x8080022C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080022C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800230: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800234: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80800238: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x8080023C: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x80800240: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80800244: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800248: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x8080024C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800250: sltiu       $at, $t0, 0x18
    ctx->r1 = ctx->r8 < 0X18 ? 1 : 0;
    // 0x80800254: beq         $at, $zero, L_8080084C
    if (ctx->r1 == 0) {
        // 0x80800258: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8080084C;
    }
    // 0x80800258: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8080025C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1232, 0X1A10) << 16);
    // 0x80800260: addu        $at, $at, $t0
    gpr jr_addend_80800268 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800264: lw          $t0, 0x1A10($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1232, 0X1A10));
    // 0x80800268: jr          $t0
    // 0x8080026C: nop

    switch (jr_addend_80800268 >> 2) {
        case 0: goto L_8080084C; break;
        case 1: goto L_80800270; break;
        case 2: goto L_808002B4; break;
        case 3: goto L_808002D4; break;
        case 4: goto L_80800338; break;
        case 5: goto L_8080084C; break;
        case 6: goto L_80800374; break;
        case 7: goto L_80800430; break;
        case 8: goto L_80800464; break;
        case 9: goto L_80800520; break;
        case 10: goto L_80800560; break;
        case 11: goto L_8080084C; break;
        case 12: goto L_80800570; break;
        case 13: goto L_80800578; break;
        case 14: goto L_808005D4; break;
        case 15: goto L_80800628; break;
        case 16: goto L_80800638; break;
        case 17: goto L_80800648; break;
        case 18: goto L_8080066C; break;
        case 19: goto L_808006CC; break;
        case 20: goto L_80800744; break;
        case 21: goto L_80800790; break;
        case 22: goto L_808007B0; break;
        case 23: goto L_8080084C; break;
        default: switch_error(__func__, 0x80800268, 0x80801A10);
    }
    // 0x8080026C: nop

L_80800270:
    // 0x80800270: jal         0x800D9078
    // 0x80800274: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80800274: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80800278: beq         $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x8080027C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080084C;
    }
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: jal         0x808011F8
    // 0x80800284: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_2;
    // 0x80800284: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800288: addiu       $a0, $zero, 0x1FE
    ctx->r4 = ADD32(0, 0X1FE);
    // 0x8080028C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800290: jal         0x80101180
    // 0x80800294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x80800294: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080029C: jal         0x8010A85C
    // 0x808002A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A85C(rdram, ctx);
        goto after_4;
    // 0x808002A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808002A4: lbu         $t2, 0x75($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X75);
    // 0x808002A8: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x808002AC: b           L_8080084C
    // 0x808002B0: sb          $t3, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r11;
        goto L_8080084C;
    // 0x808002B0: sb          $t3, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r11;
L_808002B4:
    // 0x808002B4: jal         0x80101DDC
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_5;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808002BC: beq         $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x808002C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080084C;
    }
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: jal         0x808011F8
    // 0x808002C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_6;
    // 0x808002C8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x808002CC: b           L_80800850
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002D4:
    // 0x808002D4: jal         0x80101DDC
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_7;
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808002DC: beq         $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x808002E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080084C;
    }
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808002E8: jal         0x80801724
    // 0x808002EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80801724_chsabreman(rdram, ctx);
        goto after_8;
    // 0x808002EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x808002F0: jal         0x8010A590
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_9;
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808002F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002FC: addiu       $t4, $zero, 0xAA
    ctx->r12 = ADD32(0, 0XAA);
    // 0x80800300: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800304: addiu       $a1, $zero, 0x1271
    ctx->r5 = ADD32(0, 0X1271);
    // 0x80800308: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8080030C: jal         0x8008A208
    // 0x80800310: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800310: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_10:
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: jal         0x808011F8
    // 0x8080031C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_11;
    // 0x8080031C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_11:
    // 0x80800320: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    // 0x80800324: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800328: jal         0x800DA7A8
    // 0x8080032C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800DA7A8(rdram, ctx);
        goto after_12;
    // 0x8080032C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_12:
    // 0x80800330: b           L_80800850
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800338:
    // 0x80800338: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x8080033C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1232, 0X1E16) << 16);
    // 0x80800340: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1E08) << 16);
    // 0x80800344: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1232, 0X1BF8) << 16);
    // 0x80800348: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8080034C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x80800350: sb          $t5, 0x1E16($at)
    MEM_B((int16_t)RELOC_LO16(1232, 0X1E16), ctx->r1) = ctx->r13;
    // 0x80800354: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800358: addiu       $a3, $a3, 0x1BF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1232, 0X1BF8));
    // 0x8080035C: addiu       $a2, $a2, 0x1E08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1E08));
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x8008A1F0
    // 0x80800368: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_13;
    // 0x80800368: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x8080036C: b           L_80800850
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800374:
    // 0x80800374: jal         0x80101DDC
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_14;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080037C: beq         $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x80800380: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080084C;
    }
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: jal         0x8008A4B0
    // 0x80800388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x80800388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x8080038C: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80800398: bne         $at, $zero, L_80800420
    if (ctx->r1 != 0) {
        // 0x8080039C: nop
    
            goto L_80800420;
    }
    // 0x8080039C: nop

    // 0x808003A0: jal         0x800F54E4
    // 0x808003A4: nop

    func_800F54E4(rdram, ctx);
        goto after_16;
    // 0x808003A4: nop

    after_16:
    // 0x808003A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003AC: jal         0x800F82D4
    // 0x808003B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_17;
    // 0x808003B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x808003B4: jal         0x800F54E4
    // 0x808003B8: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x808003B8: nop

    after_18:
    // 0x808003BC: jal         0x800F6CC8
    // 0x808003C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6CC8(rdram, ctx);
        goto after_19;
    // 0x808003C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
    // 0x808003C4: bne         $v0, $zero, L_80800410
    if (ctx->r2 != 0) {
        // 0x808003C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800410;
    }
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: jal         0x80100094
    // 0x808003D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_20;
    // 0x808003D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808003E0: addiu       $a2, $zero, 0x7F1
    ctx->r6 = ADD32(0, 0X7F1);
    // 0x808003E4: jal         0x8008A070
    // 0x808003E8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    _subaddiepalette_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x808003E8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_21:
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F0: jal         0x808011F8
    // 0x808003F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_22;
    // 0x808003F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_22:
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800400: jal         0x808017D8
    // 0x80800404: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_808017D8_chsabreman(rdram, ctx);
        goto after_23;
    // 0x80800404: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_23:
    // 0x80800408: b           L_80800850
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800410:
    // 0x80800410: jal         0x808011F8
    // 0x80800414: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_24;
    // 0x80800414: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_24:
    // 0x80800418: b           L_80800850
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800420:
    // 0x80800420: jal         0x808011F8
    // 0x80800424: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_25;
    // 0x80800424: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_25:
    // 0x80800428: b           L_80800850
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800430:
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800434: jal         0x80100094
    // 0x80800438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_26;
    // 0x80800438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x8080043C: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800444: bnel        $t8, $zero, L_80800850
    if (ctx->r24 != 0) {
        // 0x80800448: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800850;
    }
    goto skip_0;
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080044C: jal         0x808011F8
    // 0x80800450: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_27;
    // 0x80800450: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_27:
    // 0x80800454: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800458: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x8080045C: b           L_8080084C
    // 0x80800460: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
        goto L_8080084C;
    // 0x80800460: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
L_80800464:
    // 0x80800464: lui         $a1, 0x3E6B
    ctx->r5 = S32(0X3E6B << 16);
    // 0x80800468: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x8080046C: jal         0x80101E14
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_28;
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800474: beq         $v0, $zero, L_80800494
    if (ctx->r2 == 0) {
        // 0x80800478: addiu       $a0, $zero, 0x1FE
        ctx->r4 = ADD32(0, 0X1FE);
            goto L_80800494;
    }
    // 0x80800478: addiu       $a0, $zero, 0x1FE
    ctx->r4 = ADD32(0, 0X1FE);
    // 0x8080047C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80800480: jal         0x80101180
    // 0x80800484: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80101180(rdram, ctx);
        goto after_29;
    // 0x80800484: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_29:
    // 0x80800488: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x8080048C: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x80800490: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80800494:
    // 0x80800494: jal         0x80101DDC
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_30;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8080049C: beql        $v0, $zero, L_80800850
    if (ctx->r2 == 0) {
        // 0x808004A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800850;
    }
    goto skip_1;
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808004A4: jal         0x800F54E4
    // 0x808004A8: nop

    func_800F54E4(rdram, ctx);
        goto after_31;
    // 0x808004A8: nop

    after_31:
    // 0x808004AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004B0: jal         0x800F64A4
    // 0x808004B4: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_800F64A4(rdram, ctx);
        goto after_32;
    // 0x808004B4: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_32:
    // 0x808004B8: beq         $v0, $zero, L_808004CC
    if (ctx->r2 == 0) {
        // 0x808004BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004CC;
    }
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: addiu       $t4, $zero, 0x12D9
    ctx->r12 = ADD32(0, 0X12D9);
    // 0x808004C4: b           L_808004D4
    // 0x808004C8: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
        goto L_808004D4;
    // 0x808004C8: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
L_808004CC:
    // 0x808004CC: addiu       $t5, $zero, 0x1273
    ctx->r13 = ADD32(0, 0X1273);
    // 0x808004D0: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
L_808004D4:
    // 0x808004D4: jal         0x808011F8
    // 0x808004D8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_33;
    // 0x808004D8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_33:
    // 0x808004DC: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    // 0x808004E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004E4: jal         0x800DA7A8
    // 0x808004E8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800DA7A8(rdram, ctx);
        goto after_34;
    // 0x808004E8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_34:
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004F4: jal         0x80801724
    // 0x808004F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80801724_chsabreman(rdram, ctx);
        goto after_35;
    // 0x808004F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_35:
    // 0x808004FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800500: addiu       $t6, $zero, 0xAA
    ctx->r14 = ADD32(0, 0XAA);
    // 0x80800504: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800508: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8080050C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800510: jal         0x8008A208
    // 0x80800514: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_36;
    // 0x80800514: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_36:
    // 0x80800518: b           L_80800850
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800520:
    // 0x80800520: jal         0x808011AC
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808011AC_chsabreman(rdram, ctx);
        goto after_37;
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800528: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x8080052C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1232, 0X1E16) << 16);
    // 0x80800530: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1232, 0X1E08) << 16);
    // 0x80800534: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1232, 0X1C20) << 16);
    // 0x80800538: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8080053C: sb          $t7, 0x1E16($at)
    MEM_B((int16_t)RELOC_LO16(1232, 0X1E16), ctx->r1) = ctx->r15;
    // 0x80800540: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800544: addiu       $a3, $a3, 0x1C20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1232, 0X1C20));
    // 0x80800548: addiu       $a2, $a2, 0x1E08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1232, 0X1E08));
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: jal         0x8008A1F0
    // 0x80800554: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_38;
    // 0x80800554: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_38:
    // 0x80800558: b           L_80800850
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800560:
    // 0x80800560: jal         0x808011AC
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808011AC_chsabreman(rdram, ctx);
        goto after_39;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80800568: b           L_80800850
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800570:
    // 0x80800570: b           L_8080084C
    // 0x80800574: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
        goto L_8080084C;
    // 0x80800574: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
L_80800578:
    // 0x80800578: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x8080057C: jal         0x808011AC
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808011AC_chsabreman(rdram, ctx);
        goto after_40;
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800588: jal         0x8008A500
    // 0x8080058C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _subaddietaxi_entrypoint_1(rdram, ctx);
        goto after_41;
    // 0x8080058C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_41:
    // 0x80800590: beq         $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x80800594: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080084C;
    }
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800598: jal         0x808011F8
    // 0x8080059C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_42;
    // 0x8080059C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_42:
    // 0x808005A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808005A4: addiu       $t9, $zero, 0xAA
    ctx->r25 = ADD32(0, 0XAA);
    // 0x808005A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808005AC: addiu       $a1, $zero, 0x1275
    ctx->r5 = ADD32(0, 0X1275);
    // 0x808005B0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808005B4: jal         0x8008A208
    // 0x808005B8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_43;
    // 0x808005B8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_43:
    // 0x808005BC: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    // 0x808005C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808005C4: jal         0x800DA7A8
    // 0x808005C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800DA7A8(rdram, ctx);
        goto after_44;
    // 0x808005C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_44:
    // 0x808005CC: b           L_80800850
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005D4:
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D8: jal         0x8008A550
    // 0x808005DC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _subaddietaxi_entrypoint_11(rdram, ctx);
        goto after_45;
    // 0x808005DC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_45:
    // 0x808005E0: beq         $v0, $zero, L_80800614
    if (ctx->r2 == 0) {
        // 0x808005E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800614;
    }
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E8: jal         0x8008A520
    // 0x808005EC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _subaddietaxi_entrypoint_5(rdram, ctx);
        goto after_46;
    // 0x808005EC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_46:
    // 0x808005F0: beq         $v0, $zero, L_80800614
    if (ctx->r2 == 0) {
        // 0x808005F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800614;
    }
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F8: jal         0x8008A568
    // 0x808005FC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _subaddietaxi_entrypoint_14(rdram, ctx);
        goto after_47;
    // 0x808005FC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_47:
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800604: jal         0x808011F8
    // 0x80800608: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_48;
    // 0x80800608: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_48:
    // 0x8080060C: jal         0x8010A590
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_49;
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
L_80800614:
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800618: jal         0x8008A558
    // 0x8080061C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _subaddietaxi_entrypoint_12(rdram, ctx);
        goto after_50;
    // 0x8080061C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_50:
    // 0x80800620: b           L_8080084C
    // 0x80800624: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
        goto L_8080084C;
    // 0x80800624: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
L_80800628:
    // 0x80800628: jal         0x808011AC
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808011AC_chsabreman(rdram, ctx);
        goto after_51;
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80800630: b           L_80800850
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800638:
    // 0x80800638: jal         0x808011AC
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808011AC_chsabreman(rdram, ctx);
        goto after_52;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x80800640: b           L_80800850
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800648:
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080064C: jal         0x8008A570
    // 0x80800650: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _subaddietaxi_entrypoint_15(rdram, ctx);
        goto after_53;
    // 0x80800650: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_53:
    // 0x80800654: beq         $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x80800658: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080084C;
    }
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080065C: jal         0x808011F8
    // 0x80800660: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_54;
    // 0x80800660: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_54:
    // 0x80800664: b           L_80800850
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080066C:
    // 0x8080066C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800670: jal         0x800EE88C
    // 0x80800674: addiu       $a1, $v1, 0x81A
    ctx->r5 = ADD32(ctx->r3, 0X81A);
    func_800EE88C(rdram, ctx);
        goto after_55;
    // 0x80800674: addiu       $a1, $v1, 0x81A
    ctx->r5 = ADD32(ctx->r3, 0X81A);
    after_55:
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080067C: jal         0x80102D78
    // 0x80800680: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_80102D78(rdram, ctx);
        goto after_56;
    // 0x80800680: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_56:
    // 0x80800684: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800688: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8080068C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800694: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800698: jal         0x80102BF8
    // 0x8080069C: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    func_80102BF8(rdram, ctx);
        goto after_57;
    // 0x8080069C: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    after_57:
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A4: jal         0x80102CF4
    // 0x808006A8: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102CF4(rdram, ctx);
        goto after_58;
    // 0x808006A8: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_58:
    // 0x808006AC: beq         $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x808006B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080084C;
    }
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B4: jal         0x808011F8
    // 0x808006B8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_59;
    // 0x808006B8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_59:
    // 0x808006BC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808006C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006C4: b           L_8080084C
    // 0x808006C8: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_8080084C;
    // 0x808006C8: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_808006CC:
    // 0x808006CC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808006D0: jal         0x800EE88C
    // 0x808006D4: addiu       $a1, $v1, 0x81A
    ctx->r5 = ADD32(ctx->r3, 0X81A);
    func_800EE88C(rdram, ctx);
        goto after_60;
    // 0x808006D4: addiu       $a1, $v1, 0x81A
    ctx->r5 = ADD32(ctx->r3, 0X81A);
    after_60:
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006DC: jal         0x80102D78
    // 0x808006E0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80102D78(rdram, ctx);
        goto after_61;
    // 0x808006E0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_61:
    // 0x808006E4: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808006E8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808006EC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F4: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x808006F8: jal         0x80102BF8
    // 0x808006FC: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    func_80102BF8(rdram, ctx);
        goto after_62;
    // 0x808006FC: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    after_62:
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800704: jal         0x8010B990
    // 0x80800708: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    func_8010B990(rdram, ctx);
        goto after_63;
    // 0x80800708: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    after_63:
    // 0x8080070C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800710: jal         0x800EEB40
    // 0x80800714: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EEB40(rdram, ctx);
        goto after_64;
    // 0x80800714: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_64:
    // 0x80800718: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1232, 0X1A70) << 16);
    // 0x8080071C: lwc1        $f6, 0x1A70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1232, 0X1A70));
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800724: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800728: nop

    // 0x8080072C: bc1fl       L_80800850
    if (!c1cs) {
        // 0x80800730: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800850;
    }
    goto skip_2;
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800734: jal         0x808011F8
    // 0x80800738: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_65;
    // 0x80800738: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_65:
    // 0x8080073C: b           L_80800850
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800744:
    // 0x80800744: lh          $t0, 0x818($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X818);
    // 0x80800748: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x8080074C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800750: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800758: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x8080075C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800760: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    // 0x80800764: jal         0x80102BF8
    // 0x80800768: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    func_80102BF8(rdram, ctx);
        goto after_66;
    // 0x80800768: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    after_66:
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800770: jal         0x80102CF4
    // 0x80800774: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102CF4(rdram, ctx);
        goto after_67;
    // 0x80800774: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_67:
    // 0x80800778: beq         $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x8080077C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080084C;
    }
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800780: jal         0x808011F8
    // 0x80800784: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_68;
    // 0x80800784: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_68:
    // 0x80800788: b           L_80800850
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800790:
    // 0x80800790: jal         0x80101DDC
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_69;
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_69:
    // 0x80800798: beq         $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x8080079C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080084C;
    }
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A0: jal         0x808011F8
    // 0x808007A4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_70;
    // 0x808007A4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_70:
    // 0x808007A8: b           L_80800850
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800850;
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007B0:
    // 0x808007B0: jal         0x800C0638
    // 0x808007B4: nop

    func_800C0638(rdram, ctx);
        goto after_71;
    // 0x808007B4: nop

    after_71:
    // 0x808007B8: bnel        $v0, $zero, L_80800850
    if (ctx->r2 != 0) {
        // 0x808007BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800850;
    }
    goto skip_3;
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x808007C0: jal         0x800D90A4
    // 0x808007C4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_72;
    // 0x808007C4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_72:
    // 0x808007C8: beq         $v0, $zero, L_8080084C
    if (ctx->r2 == 0) {
        // 0x808007CC: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080084C;
    }
    // 0x808007CC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808007D0: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x808007D4: jal         0x8010CAC0
    // 0x808007D8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_8010CAC0(rdram, ctx);
        goto after_73;
    // 0x808007D8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_73:
    // 0x808007DC: beql        $v0, $zero, L_80800850
    if (ctx->r2 == 0) {
        // 0x808007E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800850;
    }
    goto skip_4;
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x808007E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808007E8: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808007EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007F0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x808007F4: nop

    // 0x808007F8: bc1fl       L_80800850
    if (!c1cs) {
        // 0x808007FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800850;
    }
    goto skip_5;
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x80800800: jal         0x800DC128
    // 0x80800804: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_74;
    // 0x80800804: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_74:
    // 0x80800808: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080080C: addiu       $t1, $zero, 0xAA
    ctx->r9 = ADD32(0, 0XAA);
    // 0x80800810: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800814: addiu       $a1, $v0, 0x1293
    ctx->r5 = ADD32(ctx->r2, 0X1293);
    // 0x80800818: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080081C: jal         0x8008A208
    // 0x80800820: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_75;
    // 0x80800820: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_75:
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800828: jal         0x80102424
    // 0x8080082C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80102424(rdram, ctx);
        goto after_76;
    // 0x8080082C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_76:
    // 0x80800830: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800834: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800838: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8080083C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800840: jal         0x800DC178
    // 0x80800844: nop

    func_800DC178(rdram, ctx);
        goto after_77;
    // 0x80800844: nop

    after_77:
    // 0x80800848: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_8080084C:
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800850:
    // 0x80800850: jal         0x8008A540
    // 0x80800854: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _subaddietaxi_entrypoint_9(rdram, ctx);
        goto after_78;
    // 0x80800854: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_78:
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080085C: jal         0x80100094
    // 0x80800860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_79;
    // 0x80800860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_79:
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800868: jal         0x8008A068
    // 0x8080086C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddiepalette_entrypoint_1(rdram, ctx);
        goto after_80;
    // 0x8080086C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_80:
    // 0x80800870: jal         0x80801218
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801218_chsabreman(rdram, ctx);
        goto after_81;
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_81:
    // 0x80800878: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8080087C: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800884: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800888: or          $a3, $t2, $t3
    ctx->r7 = ctx->r10 | ctx->r11;
    // 0x8080088C: beq         $a3, $zero, L_808008B4
    if (ctx->r7 == 0) {
        // 0x80800890: addiu       $a2, $sp, 0x34
        ctx->r6 = ADD32(ctx->r29, 0X34);
            goto L_808008B4;
    }
    // 0x80800890: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800894: jal         0x8008A0D0
    // 0x80800898: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_82;
    // 0x80800898: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_82:
    // 0x8080089C: beq         $v0, $zero, L_808008B4
    if (ctx->r2 == 0) {
        // 0x808008A0: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_808008B4;
    }
    // 0x808008A0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808008A4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808008A8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808008AC: jal         0x80089F18
    // 0x808008B0: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_83;
    // 0x808008B0: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_83:
L_808008B4:
    // 0x808008B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x808008C0: jr          $ra
    // 0x808008C4: nop

    return;
    // 0x808008C4: nop

;}
RECOMP_FUNC void func_808005E4_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005EC: jal         0x8080016C
    // 0x808005F0: nop

    bsmum_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808005F0: nop

    after_0:
    // 0x808005F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005FC: jr          $ra
    // 0x80800600: nop

    return;
    // 0x80800600: nop

;}
RECOMP_FUNC void bsbbuster_setSubstate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: jal         0x8008CABC
    // 0x80800014: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800018: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8080001C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800020: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80800024: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80800028: beq         $at, $zero, L_80800190
    if (ctx->r1 == 0) {
        // 0x8080002C: sb          $v1, 0x161($s0)
        MEM_B(0X161, ctx->r16) = ctx->r3;
            goto L_80800190;
    }
    // 0x8080002C: sb          $v1, 0x161($s0)
    MEM_B(0X161, ctx->r16) = ctx->r3;
    // 0x80800030: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800034: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(65, 0X700) << 16);
    // 0x80800038: addu        $at, $at, $t6
    gpr jr_addend_80800040 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080003C: lw          $t6, 0x700($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(65, 0X700));
    // 0x80800040: jr          $t6
    // 0x80800044: nop

    switch (jr_addend_80800040 >> 2) {
        case 0: goto L_80800190; break;
        case 1: goto L_80800048; break;
        case 2: goto L_8080005C; break;
        case 3: goto L_808000AC; break;
        case 4: goto L_80800128; break;
        default: switch_error(__func__, 0x80800040, 0x80800700);
    }
    // 0x80800044: nop

L_80800048:
    // 0x80800048: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8080004C: jal         0x8008B1BC
    // 0x80800050: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    anctrl_setDuration(rdram, ctx);
        goto after_1;
    // 0x80800050: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_1:
    // 0x80800054: b           L_80800194
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800194;
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080005C:
    // 0x8080005C: jal         0x8009BC6C
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_2;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800064: lui         $a1, 0xC59C
    ctx->r5 = S32(0XC59C << 16);
    // 0x80800068: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x8080006C: jal         0x8009BCC4
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800074: lui         $a1, 0xC69C
    ctx->r5 = S32(0XC69C << 16);
    // 0x80800078: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x8080007C: jal         0x8009BCB4
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_4;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800084: lui         $a1, 0x450F
    ctx->r5 = S32(0X450F << 16);
    // 0x80800088: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x8080008C: jal         0x8009BA58
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_5;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x8009B9B0
    // 0x8080009C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x8080009C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808000A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808000A4: b           L_80800190
    // 0x808000A8: sb          $t7, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r15;
        goto L_80800190;
    // 0x808000A8: sb          $t7, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r15;
L_808000AC:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: jal         0x80095760
    // 0x808000B4: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    baflag_set(rdram, ctx);
        goto after_7;
    // 0x808000B4: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_7:
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808000C0: jal         0x80084FD0
    // 0x808000C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _bashake_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x808000C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x800A2EEC
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A2EEC(rdram, ctx);
        goto after_9;
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: jal         0x80084A18
    // 0x808000DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _badust_entrypoint_10(rdram, ctx);
        goto after_10;
    // 0x808000DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x8009BA9C
    // 0x808000E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_11;
    // 0x808000E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x8009BCB4
    // 0x808000F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_12;
    // 0x808000F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_12:
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: jal         0x8009B9B0
    // 0x80800100: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_13;
    // 0x80800100: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_13:
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: jal         0x8008EE88
    // 0x8080010C: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    func_8008EE88(rdram, ctx);
        goto after_14;
    // 0x8080010C: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    after_14:
    // 0x80800110: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80800114: sb          $t8, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r24;
    // 0x80800118: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(65, 0X714) << 16);
    // 0x8080011C: lwc1        $f4, 0x714($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(65, 0X714));
    // 0x80800120: b           L_80800190
    // 0x80800124: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
        goto L_80800190;
    // 0x80800124: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
L_80800128:
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x80095738
    // 0x80800130: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    baflag_isTrue(rdram, ctx);
        goto after_15;
    // 0x80800130: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_15:
    // 0x80800134: beq         $v0, $zero, L_8080015C
    if (ctx->r2 == 0) {
        // 0x80800138: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080015C;
    }
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: jal         0x8009BA58
    // 0x80800144: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_16;
    // 0x80800144: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_16:
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x8009BCB4
    // 0x80800150: lui         $a1, 0xC448
    ctx->r5 = S32(0XC448 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_17;
    // 0x80800150: lui         $a1, 0xC448
    ctx->r5 = S32(0XC448 << 16);
    after_17:
    // 0x80800154: b           L_8080017C
    // 0x80800158: lui         $a1, 0x3F3A
    ctx->r5 = S32(0X3F3A << 16);
        goto L_8080017C;
    // 0x80800158: lui         $a1, 0x3F3A
    ctx->r5 = S32(0X3F3A << 16);
L_8080015C:
    // 0x8080015C: lui         $a1, 0x4436
    ctx->r5 = S32(0X4436 << 16);
    // 0x80800160: jal         0x8009BA58
    // 0x80800164: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_18;
    // 0x80800164: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    after_18:
    // 0x80800168: lui         $a1, 0xC503
    ctx->r5 = S32(0XC503 << 16);
    // 0x8080016C: ori         $a1, $a1, 0xE000
    ctx->r5 = ctx->r5 | 0XE000;
    // 0x80800170: jal         0x8009BCB4
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_19;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800178: lui         $a1, 0x3F3A
    ctx->r5 = S32(0X3F3A << 16);
L_8080017C:
    // 0x8080017C: lui         $a2, 0x3FF3
    ctx->r6 = S32(0X3FF3 << 16);
    // 0x80800180: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800184: ori         $a1, $a1, 0xDABA
    ctx->r5 = ctx->r5 | 0XDABA;
    // 0x80800188: jal         0x8008CF1C
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_20;
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
L_80800190:
    // 0x80800190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800194:
    // 0x80800194: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800198: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080019C: jr          $ra
    // 0x808001A0: nop

    return;
    // 0x808001A0: nop

;}
RECOMP_FUNC void func_8011349C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011349C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801134A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801134A4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801134A8: jal         0x800EE7F8
    // 0x801134AC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x801134AC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x801134B0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801134B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801134B8: lui         $a3, 0x82
    ctx->r7 = S32(0X82 << 16);
    // 0x801134BC: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x801134C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801134C4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x801134C8: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x801134CC: jal         0x800FAB50
    // 0x801134D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800FAB50(rdram, ctx);
        goto after_1;
    // 0x801134D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801134D4: beq         $v0, $zero, L_801134E4
    if (ctx->r2 == 0) {
        // 0x801134D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801134E4;
    }
    // 0x801134D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801134DC: b           L_801134E8
    // 0x801134E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801134E8;
    // 0x801134E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801134E4:
    // 0x801134E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801134E8:
    // 0x801134E8: jr          $ra
    // 0x801134EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801134EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800A946C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A946C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9470: jr          $ra
    // 0x800A9474: lh          $v0, 0x76D2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X76D2);
    return;
    // 0x800A9474: lh          $v0, 0x76D2($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X76D2);
;}
RECOMP_FUNC void mlMtx_set_translation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018E8C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80018E90: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80018E94: addiu       $v1, $v1, -0x4350
    ctx->r3 = ADD32(ctx->r3, -0X4350);
    // 0x80018E98: addiu       $v0, $t6, -0x4B10
    ctx->r2 = ADD32(ctx->r14, -0X4B10);
    // 0x80018E9C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80018EA0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80018EA4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80018EA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018EAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80018EB0: swc1        $f14, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f14.u32l;
    // 0x80018EB4: swc1        $f12, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f12.u32l;
    // 0x80018EB8: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80018EBC: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x80018EC0: swc1        $f2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f2.u32l;
    // 0x80018EC4: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x80018EC8: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    // 0x80018ECC: swc1        $f2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f2.u32l;
    // 0x80018ED0: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
    // 0x80018ED4: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    // 0x80018ED8: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
    // 0x80018EDC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80018EE0: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x80018EE4: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x80018EE8: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80018EEC: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x80018EF0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80018EF4: jr          $ra
    // 0x80018EF8: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x80018EF8: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80800188_chdiggerbossshell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080018C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800194: beq         $a1, $at, L_808001B8
    if (ctx->r5 == ctx->r1) {
        // 0x80800198: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808001B8;
    }
    // 0x80800198: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080019C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808001A0: bne         $a1, $at, L_808001D0
    if (ctx->r5 != ctx->r1) {
        // 0x808001A4: nop
    
            goto L_808001D0;
    }
    // 0x808001A4: nop

    // 0x808001A8: jal         0x808001EC
    // 0x808001AC: nop

    func_808001EC_chdiggerbossshell(rdram, ctx);
        goto after_0;
    // 0x808001AC: nop

    after_0:
    // 0x808001B0: b           L_808001DC
    // 0x808001B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001DC;
    // 0x808001B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001B8:
    // 0x808001B8: jal         0x80800330
    // 0x808001BC: nop

    func_80800330_chdiggerbossshell(rdram, ctx);
        goto after_1;
    // 0x808001BC: nop

    after_1:
    // 0x808001C0: jal         0x800FFAB0
    // 0x808001C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x808001C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808001C8: b           L_808001DC
    // 0x808001CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001DC;
    // 0x808001CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001D0:
    // 0x808001D0: b           L_808001DC
    // 0x808001D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001DC;
    // 0x808001D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001DC:
    // 0x808001DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001E4: jr          $ra
    // 0x808001E8: nop

    return;
    // 0x808001E8: nop

;}
RECOMP_FUNC void _bsbshock_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B20: syscall     27
    recomp_syscall_handler(rdram, ctx, 0x80082B20);
    return;
    // 0x80082B24: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800744_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080074C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800750: jal         0x800DA298
    // 0x80800754: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800754: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    after_0:
    // 0x80800758: beq         $v0, $zero, L_8080076C
    if (ctx->r2 == 0) {
        // 0x8080075C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080076C;
    }
    // 0x8080075C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800760: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(748, 0X1AF4) << 16);
    // 0x80800764: b           L_80800774
    // 0x80800768: addiu       $a2, $a2, 0x1AF4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(748, 0X1AF4));
        goto L_80800774;
    // 0x80800768: addiu       $a2, $a2, 0x1AF4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(748, 0X1AF4));
L_8080076C:
    // 0x8080076C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(748, 0X1AD8) << 16);
    // 0x80800770: addiu       $a2, $a2, 0x1AD8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(748, 0X1AD8));
L_80800774:
    // 0x80800774: jal         0x8008A1E8
    // 0x80800778: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800778: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x8080077C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800784: jr          $ra
    // 0x80800788: nop

    return;
    // 0x80800788: nop

;}
RECOMP_FUNC void func_800E8F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8F68: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x800E8F6C: lw          $t7, 0x20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X20);
    // 0x800E8F70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E8F74: beq         $t6, $t7, L_800E8F84
    if (ctx->r14 == ctx->r15) {
        // 0x800E8F78: nop
    
            goto L_800E8F84;
    }
    // 0x800E8F78: nop

    // 0x800E8F7C: jr          $ra
    // 0x800E8F80: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
    return;
    // 0x800E8F80: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_800E8F84:
    // 0x800E8F84: jr          $ra
    // 0x800E8F88: nop

    return;
    // 0x800E8F88: nop

;}
RECOMP_FUNC void func_8080011C_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800124: jal         0x80100094
    // 0x80800128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080012C: addiu       $a0, $zero, 0xA37
    ctx->r4 = ADD32(0, 0XA37);
    // 0x80800130: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800134: jal         0x800DA564
    // 0x80800138: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DA564(rdram, ctx);
        goto after_1;
    // 0x80800138: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080013C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800140: sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080014C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80800150: jr          $ra
    // 0x80800154: nop

    return;
    // 0x80800154: nop

;}
RECOMP_FUNC void func_80809F74_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809F74: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80809F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80809F7C: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80809F80: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80809F84: jal         0x80096628
    // 0x80809F88: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    func_80096628(rdram, ctx);
        goto after_0;
    // 0x80809F88: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    after_0:
    // 0x80809F8C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80809F90: jal         0x8009C984
    // 0x80809F94: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x80809F94: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x80809F98: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80809F9C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80809FA0: jal         0x800963C0
    // 0x80809FA4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800963C0(rdram, ctx);
        goto after_2;
    // 0x80809FA4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80809FA8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80809FAC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80809FB0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80809FB4: jal         0x800F1B78
    // 0x80809FB8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800F1B78(rdram, ctx);
        goto after_3;
    // 0x80809FB8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80809FBC: beq         $v0, $zero, L_8080A000
    if (ctx->r2 == 0) {
        // 0x80809FC0: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_8080A000;
    }
    // 0x80809FC0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80809FC4: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80809FC8: bltz        $t7, L_8080A000
    if (SIGNED(ctx->r15) < 0) {
        // 0x80809FCC: lw          $v0, 0x44($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X44);
            goto L_8080A000;
    }
    // 0x80809FCC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80809FD0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80809FD4: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80809FD8: addiu       $v0, $v0, 0x254
    ctx->r2 = ADD32(ctx->r2, 0X254);
    // 0x80809FDC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80809FE0: bgez        $t8, L_80809FF4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80809FE4: swc1        $f6, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
            goto L_80809FF4;
    }
    // 0x80809FE4: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x80809FE8: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80809FEC: b           L_8080A02C
    // 0x80809FF0: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
        goto L_8080A02C;
    // 0x80809FF0: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
L_80809FF4:
    // 0x80809FF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80809FF8: b           L_8080A02C
    // 0x80809FFC: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
        goto L_8080A02C;
    // 0x80809FFC: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
L_8080A000:
    // 0x8080A000: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8080A004: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080A008: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080A00C: sll         $t1, $v1, 3
    ctx->r9 = S32(ctx->r3 << 3);
    // 0x8080A010: addiu       $v0, $v0, 0x254
    ctx->r2 = ADD32(ctx->r2, 0X254);
    // 0x8080A014: bgez        $t1, L_8080A028
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8080A018: swc1        $f8, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
            goto L_8080A028;
    }
    // 0x8080A018: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x8080A01C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8080A020: b           L_8080A02C
    // 0x8080A024: sw          $t2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r10;
        goto L_8080A02C;
    // 0x8080A024: sw          $t2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r10;
L_8080A028:
    // 0x8080A028: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
L_8080A02C:
    // 0x8080A02C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080A030: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080A034: jr          $ra
    // 0x8080A038: nop

    return;
    // 0x8080A038: nop

;}
RECOMP_FUNC void bskaztorpedo_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801470: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801474: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(296, 0X1894) << 16);
    // 0x80801478: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080147C: jr          $ra
    // 0x80801480: lw          $v0, 0x1894($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X1894));
    return;
    // 0x80801480: lw          $v0, 0x1894($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X1894));
;}
RECOMP_FUNC void func_800286FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800286FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80028700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028704: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80028708: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002870C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80028710: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80028714: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80028718: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8002871C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80028720: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80028724: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
    // 0x80028728: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002872C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80028730: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80028734: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80028738: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8002873C: lui         $t1, 0xB00
    ctx->r9 = S32(0XB00 << 16);
    // 0x80028740: ori         $t1, $t1, 0x20
    ctx->r9 = ctx->r9 | 0X20;
    // 0x80028744: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80028748: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8002874C: jal         0x8002E330
    // 0x80028750: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80028750: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x80028754: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80028758: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x8002875C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80028760: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80028764: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80028768: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8002876C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80028770: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80028774: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x80028778: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x8002877C: lh          $t1, 0x2($t6)
    ctx->r9 = MEM_H(ctx->r14, 0X2);
    // 0x80028780: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80028784: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80028788: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x8002878C: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80028790: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80028794: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80028798: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8002879C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800287A0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800287A4: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800287A8: jal         0x8002E330
    // 0x800287AC: lw          $a0, 0x2C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X2C);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800287AC: lw          $a0, 0x2C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X2C);
    after_1:
    // 0x800287B0: lh          $t1, 0x22($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X22);
    // 0x800287B4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800287B8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800287BC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800287C0: andi        $t0, $t1, 0xFF
    ctx->r8 = ctx->r9 & 0XFF;
    // 0x800287C4: sll         $t2, $t0, 24
    ctx->r10 = S32(ctx->r8 << 24);
    // 0x800287C8: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x800287CC: or          $t3, $t6, $t2
    ctx->r11 = ctx->r14 | ctx->r10;
    // 0x800287D0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800287D4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800287D8: sw          $zero, 0x28($t7)
    MEM_W(0X28, ctx->r15) = 0;
    // 0x800287DC: b           L_800287EC
    // 0x800287E0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_800287EC;
    // 0x800287E0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800287E4: b           L_800287EC
    // 0x800287E8: nop

        goto L_800287EC;
    // 0x800287E8: nop

L_800287EC:
    // 0x800287EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800287F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800287F4: jr          $ra
    // 0x800287F8: nop

    return;
    // 0x800287F8: nop

;}
RECOMP_FUNC void func_80800CF8_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CFC: beq         $a1, $zero, L_80800D18
    if (ctx->r5 == 0) {
        // 0x80800D00: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800D18;
    }
    // 0x80800D00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D08: beql        $a1, $at, L_80800D2C
    if (ctx->r5 == ctx->r1) {
        // 0x80800D0C: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800D2C;
    }
    goto skip_0;
    // 0x80800D0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    skip_0:
    // 0x80800D10: b           L_80800D54
    // 0x80800D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D54;
    // 0x80800D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D18:
    // 0x80800D18: jal         0x800F82D4
    // 0x80800D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_0;
    // 0x80800D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D20: b           L_80800D54
    // 0x80800D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D54;
    // 0x80800D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80800D2C:
    // 0x80800D2C: jal         0x800F82D4
    // 0x80800D30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F82D4(rdram, ctx);
        goto after_1;
    // 0x80800D30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800D34: jal         0x800F53D0
    // 0x80800D38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F53D0(rdram, ctx);
        goto after_2;
    // 0x80800D38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800D3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D40: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800D44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800D48: jal         0x80084468
    // 0x80800D4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _baattach_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800D4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80800D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D54:
    // 0x80800D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D58: jr          $ra
    // 0x80800D5C: nop

    return;
    // 0x80800D5C: nop

;}
RECOMP_FUNC void _baattach_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084438: syscall     111
    recomp_syscall_handler(rdram, ctx, 0x80084438);
    return;
    // 0x8008443C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_800E7A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7A2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E7A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E7A34: jal         0x800E7620
    // 0x800E7A38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800E7620(rdram, ctx);
        goto after_0;
    // 0x800E7A38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E7A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E7A40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E7A44: jr          $ra
    // 0x800E7A48: nop

    return;
    // 0x800E7A48: nop

;}
RECOMP_FUNC void func_800AE5F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE5F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE5F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE5F8: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    // 0x800AE5FC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800AE600: beq         $a2, $zero, L_800AE618
    if (ctx->r6 == 0) {
        // 0x800AE604: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800AE618;
    }
    // 0x800AE604: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800AE608: jal         0x800E0A98
    // 0x800AE60C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800E0A98(rdram, ctx);
        goto after_0;
    // 0x800AE60C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800AE610: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800AE614: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
L_800AE618:
    // 0x800AE618: jal         0x8001BAFC
    // 0x800AE61C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    defrag(rdram, ctx);
        goto after_1;
    // 0x800AE61C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x800AE620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE628: jr          $ra
    // 0x800AE62C: nop

    return;
    // 0x800AE62C: nop

;}
RECOMP_FUNC void func_808074C8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808074C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808074CC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x808074D0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808074D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808074D8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x808074DC: jal         0x80106790
    // 0x808074E0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808074E0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808074E4: lw          $s0, 0x2C($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X2C);
    // 0x808074E8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x808074EC: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x808074F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808074F4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x808074F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808074FC: addiu       $a1, $a1, -0x5E94
    ctx->r5 = ADD32(ctx->r5, -0X5E94);
    // 0x80807500: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80807504: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80807508: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080750C: jal         0x8080714C
    // 0x80807510: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    func_8080714C_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80807510: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_1:
    // 0x80807514: jal         0x800AA240
    // 0x80807518: nop

    func_800AA240(rdram, ctx);
        goto after_2;
    // 0x80807518: nop

    after_2:
    // 0x8080751C: beq         $v0, $zero, L_80807548
    if (ctx->r2 == 0) {
        // 0x80807520: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80807548;
    }
    // 0x80807520: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80807524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807528: addiu       $a1, $zero, 0x18F3
    ctx->r5 = ADD32(0, 0X18F3);
    // 0x8080752C: jal         0x80802640
    // 0x80807530: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802640_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80807530: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80807534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807538: jal         0x808026C8
    // 0x8080753C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_4;
    // 0x8080753C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_4:
    // 0x80807540: b           L_808075B4
    // 0x80807544: lbu         $t2, 0x65($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X65);
        goto L_808075B4;
    // 0x80807544: lbu         $t2, 0x65($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X65);
L_80807548:
    // 0x80807548: jal         0x80100094
    // 0x8080754C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x8080754C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80807550: jal         0x800AA0C4
    // 0x80807554: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_800AA0C4(rdram, ctx);
        goto after_6;
    // 0x80807554: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_6:
    // 0x80807558: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8080755C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(804, 0X8588) << 16);
    // 0x80807560: jal         0x800AA0D0
    // 0x80807564: sw          $t8, -0x7A78($at)
    MEM_W((int16_t)RELOC_LO16(804, 0X8588), ctx->r1) = ctx->r24;
    func_800AA0D0(rdram, ctx);
        goto after_7;
    // 0x80807564: sw          $t8, -0x7A78($at)
    MEM_W((int16_t)RELOC_LO16(804, 0X8588), ctx->r1) = ctx->r24;
    after_7:
    // 0x80807568: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8080756C: lui         $v1, 0x8081
    ctx->r3 = S32(RELOC_HI16(804, 0X8588) << 16);
    // 0x80807570: addiu       $v1, $v1, -0x7A78
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(804, 0X8588));
    // 0x80807574: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80807578: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    // 0x8080757C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80807580: addiu       $a1, $zero, 0x18F3
    ctx->r5 = ADD32(0, 0X18F3);
    // 0x80807584: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x80807588: jal         0x80803E94
    // 0x8080758C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80803E94_chgameselect(rdram, ctx);
        goto after_8;
    // 0x8080758C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_8:
    // 0x80807590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80807598: jal         0x80802640
    // 0x8080759C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802640_chgameselect(rdram, ctx);
        goto after_9;
    // 0x8080759C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x808075A0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x808075A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808075A8: jal         0x80802730
    // 0x808075AC: lw          $a1, 0x20($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X20);
    func_80802730_chgameselect(rdram, ctx);
        goto after_10;
    // 0x808075AC: lw          $a1, 0x20($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X20);
    after_10:
    // 0x808075B0: lbu         $t2, 0x65($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X65);
L_808075B4:
    // 0x808075B4: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x808075B8: sb          $t3, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r11;
    // 0x808075BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808075C0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x808075C4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808075C8: jr          $ra
    // 0x808075CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808075CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8080367C_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080367C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803684: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80803688: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080368C: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x80803690: bne         $at, $zero, L_808036B8
    if (ctx->r1 != 0) {
        // 0x80803694: slti        $at, $t6, 0x2D
        ctx->r1 = SIGNED(ctx->r14) < 0X2D ? 1 : 0;
            goto L_808036B8;
    }
    // 0x80803694: slti        $at, $t6, 0x2D
    ctx->r1 = SIGNED(ctx->r14) < 0X2D ? 1 : 0;
    // 0x80803698: beql        $at, $zero, L_808036BC
    if (ctx->r1 == 0) {
        // 0x8080369C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808036BC;
    }
    goto skip_0;
    // 0x8080369C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808036A0: jal         0x80100094
    // 0x808036A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808036A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808036A8: addiu       $a0, $zero, 0xFD
    ctx->r4 = ADD32(0, 0XFD);
    // 0x808036AC: lbu         $a1, 0x6F($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X6F);
    // 0x808036B0: jal         0x800D2498
    // 0x808036B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_1;
    // 0x808036B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_808036B8:
    // 0x808036B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808036BC:
    // 0x808036BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808036C0: jr          $ra
    // 0x808036C4: nop

    return;
    // 0x808036C4: nop

;}
RECOMP_FUNC void func_808003A8_chanemone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808003AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003B4: jal         0x800D8FF8
    // 0x808003B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808003B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808003BC: jal         0x8010D23C
    // 0x808003C0: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    func_8010D23C(rdram, ctx);
        goto after_1;
    // 0x808003C0: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x808003C4: beql        $v0, $zero, L_808004D4
    if (ctx->r2 == 0) {
        // 0x808003C8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_808004D4;
    }
    goto skip_0;
    // 0x808003C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x808003CC: jal         0x8010D254
    // 0x808003D0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_8010D254(rdram, ctx);
        goto after_2;
    // 0x808003D0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x808003D4: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808003D8: jal         0x800EE7F8
    // 0x808003DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808003DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808003E0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808003E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003E8: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808003EC: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808003F0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808003F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808003F8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808003FC: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800400: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800404: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80800408: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080040C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800410: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800414: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800418: jal         0x800EF1B8
    // 0x8080041C: nop

    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x8080041C: nop

    after_4:
    // 0x80800420: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800424: jal         0x800EEB40
    // 0x80800428: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800EEB40(rdram, ctx);
        goto after_5;
    // 0x80800428: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x8080042C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1032, 0X8A4) << 16);
    // 0x80800430: lwc1        $f4, 0x8A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1032, 0X8A4));
    // 0x80800434: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800438: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8080043C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800440: nop

    // 0x80800444: bc1f        L_80800474
    if (!c1cs) {
        // 0x80800448: nop
    
            goto L_80800474;
    }
    // 0x80800448: nop

    // 0x8080044C: jal         0x800F18FC
    // 0x80800450: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800F18FC(rdram, ctx);
        goto after_6;
    // 0x80800450: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x80800454: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800458: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080045C: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80800460: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x80800464: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800468: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8080046C: b           L_808004E0
    // 0x80800470: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
        goto L_808004E0;
    // 0x80800470: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
L_80800474:
    // 0x80800474: jal         0x800D9078
    // 0x80800478: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_800D9078(rdram, ctx);
        goto after_7;
    // 0x80800478: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_7:
    // 0x8080047C: beq         $v0, $zero, L_808004E0
    if (ctx->r2 == 0) {
        // 0x80800480: lui         $at, 0xC270
        ctx->r1 = S32(0XC270 << 16);
            goto L_808004E0;
    }
    // 0x80800480: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x80800484: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800488: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8080048C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800490: jal         0x800DC178
    // 0x80800494: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80800494: nop

    after_8:
    // 0x80800498: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8080049C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808004A0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808004A4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004A8: jal         0x800DC178
    // 0x808004AC: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x808004AC: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    after_9:
    // 0x808004B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808004B4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808004B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808004BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004C0: jal         0x800DC178
    // 0x808004C4: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x808004C4: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    after_10:
    // 0x808004C8: b           L_808004E0
    // 0x808004CC: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
        goto L_808004E0;
    // 0x808004CC: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x808004D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_808004D4:
    // 0x808004D4: nop

    // 0x808004D8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808004DC: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
L_808004E0:
    // 0x808004E0: jal         0x80013728
    // 0x808004E4: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    func_80013728(rdram, ctx);
        goto after_11;
    // 0x808004E4: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    after_11:
    // 0x808004E8: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x808004EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004F0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808004F4: jal         0x800F0D50
    // 0x808004F8: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    func_800F0D50(rdram, ctx);
        goto after_12;
    // 0x808004F8: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    after_12:
    // 0x808004FC: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800500: jal         0x80013728
    // 0x80800504: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    func_80013728(rdram, ctx);
        goto after_13;
    // 0x80800504: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    after_13:
    // 0x80800508: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8080050C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800510: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800514: jal         0x800F0D50
    // 0x80800518: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    func_800F0D50(rdram, ctx);
        goto after_14;
    // 0x80800518: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    after_14:
    // 0x8080051C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800520: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800524: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800528: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8080052C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800530: mul.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800534: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80800538: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080053C: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80800540: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800544: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80800548: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080054C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800550: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80800554: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80800558: jal         0x800F1FF0
    // 0x8080055C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_15;
    // 0x8080055C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x80800560: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800564: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800568: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x8080056C: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800570: lwc1        $f14, 0x50($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800574: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80800578: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8080057C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800580: jal         0x800F1FF0
    // 0x80800584: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_16;
    // 0x80800584: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_16:
    // 0x80800588: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8080058C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800590: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800594: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800598: jr          $ra
    // 0x8080059C: nop

    return;
    // 0x8080059C: nop

;}
RECOMP_FUNC void idtwinklecolour_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080060C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800610: jal         0x8001B084
    // 0x80800614: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    heap_free(rdram, ctx);
        goto after_0;
    // 0x80800614: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    after_0:
    // 0x80800618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080061C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800620: jr          $ra
    // 0x80800624: nop

    return;
    // 0x80800624: nop

;}
RECOMP_FUNC void mlwave_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800178: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080017C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800188: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8080018C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800190: jal         0x8080011C
    // 0x80800194: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    mlwave_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800194: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080019C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void func_80800B84_chfantasycannon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B8C: jal         0x80101870
    // 0x80800B90: nop

    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800B90: nop

    after_0:
    // 0x80800B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B9C: jr          $ra
    // 0x80800BA0: nop

    return;
    // 0x80800BA0: nop

;}
RECOMP_FUNC void func_80800130_chbigterrysbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800138: jal         0x80088848
    // 0x8080013C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x8080013C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800140: beql        $v0, $zero, L_80800154
    if (ctx->r2 == 0) {
        // 0x80800144: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800154;
    }
    goto skip_0;
    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800148: jal         0x800FFAB0
    // 0x8080014C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x8080014C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800154:
    // 0x80800154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800158: jr          $ra
    // 0x8080015C: nop

    return;
    // 0x8080015C: nop

;}
RECOMP_FUNC void plcamera_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080048C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800494: jal         0x800F5EF8
    // 0x80800498: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x80800498: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080049C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004A0: jal         0x8010FDEC
    // 0x808004A4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8010FDEC(rdram, ctx);
        goto after_1;
    // 0x808004A4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808004A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004B0: jr          $ra
    // 0x808004B4: nop

    return;
    // 0x808004B4: nop

;}
RECOMP_FUNC void _bskazdie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833C8: syscall     58
    recomp_syscall_handler(rdram, ctx, 0x800833C8);
    return;
    // 0x800833CC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80025BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025BF0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80025BF4: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x80025BF8: lbu         $t7, 0x118($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X118);
    // 0x80025BFC: beq         $t7, $zero, L_80025C4C
    if (ctx->r15 == 0) {
        // 0x80025C00: nop
    
            goto L_80025C4C;
    }
    // 0x80025C00: nop

    // 0x80025C04: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80025C08: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80025C0C: lw          $t0, 0x98($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X98);
    // 0x80025C10: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x80025C14: sb          $t1, 0xF($sp)
    MEM_B(0XF, ctx->r29) = ctx->r9;
    // 0x80025C18: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x80025C1C: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80025C20: lw          $t4, 0x98($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X98);
    // 0x80025C24: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80025C28: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80025C2C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80025C30: sw          $t5, 0x98($t7)
    MEM_W(0X98, ctx->r15) = ctx->r13;
    // 0x80025C34: addu        $t8, $a0, $a1
    ctx->r24 = ADD32(ctx->r4, ctx->r5);
    // 0x80025C38: lbu         $t9, 0x118($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X118);
    // 0x80025C3C: addu        $t1, $a0, $a1
    ctx->r9 = ADD32(ctx->r4, ctx->r5);
    // 0x80025C40: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80025C44: b           L_80025DCC
    // 0x80025C48: sb          $t0, 0x118($t1)
    MEM_B(0X118, ctx->r9) = ctx->r8;
        goto L_80025DCC;
    // 0x80025C48: sb          $t0, 0x118($t1)
    MEM_B(0X118, ctx->r9) = ctx->r8;
L_80025C4C:
    // 0x80025C4C: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x80025C50: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80025C54: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x80025C58: lbu         $t6, 0x0($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X0);
    // 0x80025C5C: sb          $t6, 0xF($sp)
    MEM_B(0XF, ctx->r29) = ctx->r14;
    // 0x80025C60: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x80025C64: addu        $t7, $a0, $t5
    ctx->r15 = ADD32(ctx->r4, ctx->r13);
    // 0x80025C68: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80025C6C: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80025C70: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x80025C74: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80025C78: sw          $t9, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r25;
    // 0x80025C7C: lbu         $t2, 0xF($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XF);
    // 0x80025C80: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x80025C84: bne         $t2, $at, L_80025DCC
    if (ctx->r10 != ctx->r1) {
        // 0x80025C88: nop
    
            goto L_80025DCC;
    }
    // 0x80025C88: nop

    // 0x80025C8C: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80025C90: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80025C94: lw          $t6, 0x18($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X18);
    // 0x80025C98: lbu         $t5, 0x0($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X0);
    // 0x80025C9C: sb          $t5, 0xB($sp)
    MEM_B(0XB, ctx->r29) = ctx->r13;
    // 0x80025CA0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80025CA4: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80025CA8: lw          $t0, 0x18($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X18);
    // 0x80025CAC: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80025CB0: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80025CB4: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x80025CB8: sw          $t9, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r25;
    // 0x80025CBC: lbu         $t3, 0xB($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XB);
    // 0x80025CC0: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x80025CC4: beq         $t3, $at, L_80025DCC
    if (ctx->r11 == ctx->r1) {
        // 0x80025CC8: nop
    
            goto L_80025DCC;
    }
    // 0x80025CC8: nop

    // 0x80025CCC: lbu         $t4, 0xB($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XB);
    // 0x80025CD0: sb          $t4, 0xD($sp)
    MEM_B(0XD, ctx->r29) = ctx->r12;
    // 0x80025CD4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80025CD8: addu        $t5, $a0, $t6
    ctx->r13 = ADD32(ctx->r4, ctx->r14);
    // 0x80025CDC: lw          $t7, 0x18($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X18);
    // 0x80025CE0: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80025CE4: sb          $t8, 0xE($sp)
    MEM_B(0XE, ctx->r29) = ctx->r24;
    // 0x80025CE8: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80025CEC: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x80025CF0: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x80025CF4: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80025CF8: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80025CFC: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80025D00: sw          $t2, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r10;
    // 0x80025D04: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80025D08: addu        $t5, $a0, $t6
    ctx->r13 = ADD32(ctx->r4, ctx->r14);
    // 0x80025D0C: lw          $t7, 0x18($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X18);
    // 0x80025D10: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80025D14: sb          $t8, 0xC($sp)
    MEM_B(0XC, ctx->r29) = ctx->r24;
    // 0x80025D18: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80025D1C: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x80025D20: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x80025D24: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x80025D28: addu        $t4, $a0, $t2
    ctx->r12 = ADD32(ctx->r4, ctx->r10);
    // 0x80025D2C: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x80025D30: sw          $t3, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r11;
    // 0x80025D34: lbu         $t6, 0xD($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XD);
    // 0x80025D38: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80025D3C: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80025D40: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x80025D44: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x80025D48: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80025D4C: lbu         $t0, 0xE($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XE);
    // 0x80025D50: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80025D54: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x80025D58: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80025D5C: addu        $t2, $a0, $t9
    ctx->r10 = ADD32(ctx->r4, ctx->r25);
    // 0x80025D60: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x80025D64: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80025D68: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80025D6C: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80025D70: subu        $t6, $t3, $t4
    ctx->r14 = SUB32(ctx->r11, ctx->r12);
    // 0x80025D74: addiu       $t5, $t6, -0x4
    ctx->r13 = ADD32(ctx->r14, -0X4);
    // 0x80025D78: sw          $t5, 0x98($t8)
    MEM_W(0X98, ctx->r24) = ctx->r13;
    // 0x80025D7C: lbu         $t0, 0xC($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XC);
    // 0x80025D80: addu        $t1, $a0, $a1
    ctx->r9 = ADD32(ctx->r4, ctx->r5);
    // 0x80025D84: sb          $t0, 0x118($t1)
    MEM_B(0X118, ctx->r9) = ctx->r8;
    // 0x80025D88: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80025D8C: addu        $t2, $a0, $t9
    ctx->r10 = ADD32(ctx->r4, ctx->r25);
    // 0x80025D90: lw          $t3, 0x98($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X98);
    // 0x80025D94: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80025D98: sb          $t4, 0xF($sp)
    MEM_B(0XF, ctx->r29) = ctx->r12;
    // 0x80025D9C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80025DA0: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80025DA4: lw          $t5, 0x98($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X98);
    // 0x80025DA8: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80025DAC: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x80025DB0: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x80025DB4: sw          $t8, 0x98($t1)
    MEM_W(0X98, ctx->r9) = ctx->r24;
    // 0x80025DB8: addu        $t9, $a0, $a1
    ctx->r25 = ADD32(ctx->r4, ctx->r5);
    // 0x80025DBC: lbu         $t2, 0x118($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X118);
    // 0x80025DC0: addu        $t4, $a0, $a1
    ctx->r12 = ADD32(ctx->r4, ctx->r5);
    // 0x80025DC4: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80025DC8: sb          $t3, 0x118($t4)
    MEM_B(0X118, ctx->r12) = ctx->r11;
L_80025DCC:
    // 0x80025DCC: b           L_80025DDC
    // 0x80025DD0: lbu         $v0, 0xF($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XF);
        goto L_80025DDC;
    // 0x80025DD0: lbu         $v0, 0xF($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XF);
    // 0x80025DD4: b           L_80025DDC
    // 0x80025DD8: nop

        goto L_80025DDC;
    // 0x80025DD8: nop

L_80025DDC:
    // 0x80025DDC: jr          $ra
    // 0x80025DE0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80025DE0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80025670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025670: jr          $ra
    // 0x80025674: nop

    return;
    // 0x80025674: nop

;}
RECOMP_FUNC void func_80800064_chcrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800068: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800074: beq         $a1, $at, L_80800090
    if (ctx->r5 == ctx->r1) {
        // 0x80800078: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800090;
    }
    // 0x80800078: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080007C: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800080: beq         $a1, $at, L_808000D8
    if (ctx->r5 == ctx->r1) {
        // 0x80800084: nop
    
            goto L_808000D8;
    }
    // 0x80800084: nop

    // 0x80800088: b           L_808000F4
    // 0x8080008C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000F4;
    // 0x8080008C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800090:
    // 0x80800090: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800094: addiu       $a1, $a3, 0x18
    ctx->r5 = ADD32(ctx->r7, 0X18);
    // 0x80800098: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8080009C: jal         0x800EC398
    // 0x808000A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800EC398(rdram, ctx);
        goto after_0;
    // 0x808000A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000A4: jal         0x800EC708
    // 0x808000A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800EC708(rdram, ctx);
        goto after_1;
    // 0x808000A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808000AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808000B4: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x808000B8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808000BC: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x808000C0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C4: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x808000C8: jal         0x80086678
    // 0x808000CC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _chexploder_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808000CC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x808000D0: b           L_808000F4
    // 0x808000D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000F4;
    // 0x808000D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000D8:
    // 0x808000D8: jal         0x80800104
    // 0x808000DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800104_chcrate(rdram, ctx);
        goto after_3;
    // 0x808000DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x808000E0: b           L_808000F4
    // 0x808000E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000F4;
    // 0x808000E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000E8: b           L_808000F4
    // 0x808000EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000F4;
    // 0x808000EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000F4:
    // 0x808000F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void func_80800290_gztrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800290: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800294: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80800298: subu        $a0, $a3, $a1
    ctx->r4 = SUB32(ctx->r7, ctx->r5);
    // 0x8080029C: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x808002A0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x808002A4: beq         $at, $zero, L_808003C8
    if (ctx->r1 == 0) {
        // 0x808002A8: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_808003C8;
    }
    // 0x808002A8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x808002AC: subu        $a0, $a3, $a0
    ctx->r4 = SUB32(ctx->r7, ctx->r4);
    // 0x808002B0: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x808002B4: beq         $t6, $zero, L_80800318
    if (ctx->r14 == 0) {
        // 0x808002B8: addiu       $t0, $sp, 0x0
        ctx->r8 = ADD32(ctx->r29, 0X0);
            goto L_80800318;
    }
    // 0x808002B8: addiu       $t0, $sp, 0x0
    ctx->r8 = ADD32(ctx->r29, 0X0);
    // 0x808002BC: addu        $a1, $t0, $v0
    ctx->r5 = ADD32(ctx->r8, ctx->r2);
    // 0x808002C0: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x808002C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808002C8: sra         $t8, $t7, 4
    ctx->r24 = S32(SIGNED(ctx->r15) >> 4);
    // 0x808002CC: addiu       $t9, $t8, 0x30
    ctx->r25 = ADD32(ctx->r24, 0X30);
    // 0x808002D0: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
    // 0x808002D4: slti        $at, $v1, 0x3A
    ctx->r1 = SIGNED(ctx->r3) < 0X3A ? 1 : 0;
    // 0x808002D8: bne         $at, $zero, L_808002E8
    if (ctx->r1 != 0) {
        // 0x808002DC: sb          $t9, 0x0($a2)
        MEM_B(0X0, ctx->r6) = ctx->r25;
            goto L_808002E8;
    }
    // 0x808002DC: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x808002E0: addiu       $t1, $v1, 0x27
    ctx->r9 = ADD32(ctx->r3, 0X27);
    // 0x808002E4: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
L_808002E8:
    // 0x808002E8: lbu         $t2, 0x0($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X0);
    // 0x808002EC: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x808002F0: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x808002F4: addiu       $t4, $t3, 0x30
    ctx->r12 = ADD32(ctx->r11, 0X30);
    // 0x808002F8: andi        $a0, $t4, 0xFF
    ctx->r4 = ctx->r12 & 0XFF;
    // 0x808002FC: slti        $at, $a0, 0x3A
    ctx->r1 = SIGNED(ctx->r4) < 0X3A ? 1 : 0;
    // 0x80800300: bne         $at, $zero, L_80800310
    if (ctx->r1 != 0) {
        // 0x80800304: sb          $t4, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r12;
            goto L_80800310;
    }
    // 0x80800304: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x80800308: addiu       $t5, $a0, 0x27
    ctx->r13 = ADD32(ctx->r4, 0X27);
    // 0x8080030C: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
L_80800310:
    // 0x80800310: beq         $v0, $a3, L_808003C8
    if (ctx->r2 == ctx->r7) {
        // 0x80800314: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_808003C8;
    }
    // 0x80800314: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800318:
    // 0x80800318: addiu       $t0, $sp, 0x0
    ctx->r8 = ADD32(ctx->r29, 0X0);
L_8080031C:
    // 0x8080031C: addu        $a1, $t0, $v0
    ctx->r5 = ADD32(ctx->r8, ctx->r2);
    // 0x80800320: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80800324: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80800328: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x8080032C: addiu       $t8, $t7, 0x30
    ctx->r24 = ADD32(ctx->r15, 0X30);
    // 0x80800330: andi        $a0, $t8, 0xFF
    ctx->r4 = ctx->r24 & 0XFF;
    // 0x80800334: slti        $at, $a0, 0x3A
    ctx->r1 = SIGNED(ctx->r4) < 0X3A ? 1 : 0;
    // 0x80800338: bne         $at, $zero, L_80800348
    if (ctx->r1 != 0) {
        // 0x8080033C: sb          $t8, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r24;
            goto L_80800348;
    }
    // 0x8080033C: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x80800340: addiu       $t9, $a0, 0x27
    ctx->r25 = ADD32(ctx->r4, 0X27);
    // 0x80800344: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
L_80800348:
    // 0x80800348: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x8080034C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800350: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x80800354: addiu       $t3, $t2, 0x30
    ctx->r11 = ADD32(ctx->r10, 0X30);
    // 0x80800358: andi        $a0, $t3, 0xFF
    ctx->r4 = ctx->r11 & 0XFF;
    // 0x8080035C: slti        $at, $a0, 0x3A
    ctx->r1 = SIGNED(ctx->r4) < 0X3A ? 1 : 0;
    // 0x80800360: bne         $at, $zero, L_80800370
    if (ctx->r1 != 0) {
        // 0x80800364: sb          $t3, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r11;
            goto L_80800370;
    }
    // 0x80800364: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80800368: addiu       $t4, $a0, 0x27
    ctx->r12 = ADD32(ctx->r4, 0X27);
    // 0x8080036C: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
L_80800370:
    // 0x80800370: lbu         $t5, 0x1($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X1);
    // 0x80800374: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800378: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8080037C: addiu       $t7, $t6, 0x30
    ctx->r15 = ADD32(ctx->r14, 0X30);
    // 0x80800380: andi        $a0, $t7, 0xFF
    ctx->r4 = ctx->r15 & 0XFF;
    // 0x80800384: slti        $at, $a0, 0x3A
    ctx->r1 = SIGNED(ctx->r4) < 0X3A ? 1 : 0;
    // 0x80800388: bne         $at, $zero, L_80800398
    if (ctx->r1 != 0) {
        // 0x8080038C: sb          $t7, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r15;
            goto L_80800398;
    }
    // 0x8080038C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x80800390: addiu       $t8, $a0, 0x27
    ctx->r24 = ADD32(ctx->r4, 0X27);
    // 0x80800394: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_80800398:
    // 0x80800398: lbu         $t9, 0x1($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1);
    // 0x8080039C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808003A0: andi        $t1, $t9, 0xF
    ctx->r9 = ctx->r25 & 0XF;
    // 0x808003A4: addiu       $t2, $t1, 0x30
    ctx->r10 = ADD32(ctx->r9, 0X30);
    // 0x808003A8: andi        $a0, $t2, 0xFF
    ctx->r4 = ctx->r10 & 0XFF;
    // 0x808003AC: slti        $at, $a0, 0x3A
    ctx->r1 = SIGNED(ctx->r4) < 0X3A ? 1 : 0;
    // 0x808003B0: bne         $at, $zero, L_808003C0
    if (ctx->r1 != 0) {
        // 0x808003B4: sb          $t2, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r10;
            goto L_808003C0;
    }
    // 0x808003B4: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x808003B8: addiu       $t3, $a0, 0x27
    ctx->r11 = ADD32(ctx->r4, 0X27);
    // 0x808003BC: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
L_808003C0:
    // 0x808003C0: bne         $v0, $a3, L_8080031C
    if (ctx->r2 != ctx->r7) {
        // 0x808003C4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8080031C;
    }
    // 0x808003C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_808003C8:
    // 0x808003C8: jr          $ra
    // 0x808003CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808003CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8002976C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002976C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80029770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029774: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80029778: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8002977C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80029780: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80029784: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80029788: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8002978C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80029790: lbu         $t9, 0x38($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X38);
    // 0x80029794: bne         $t9, $zero, L_80029848
    if (ctx->r25 != 0) {
        // 0x80029798: nop
    
            goto L_80029848;
    }
    // 0x80029798: nop

    // 0x8002979C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800297A0: lw          $t1, 0x50($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X50);
    // 0x800297A4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800297A8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800297AC: beq         $t2, $zero, L_80029848
    if (ctx->r10 == 0) {
        // 0x800297B0: nop
    
            goto L_80029848;
    }
    // 0x800297B0: nop

L_800297B4:
    // 0x800297B4: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800297B8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800297BC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x800297C0: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800297C4: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800297C8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800297CC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800297D0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800297D4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800297D8: lh          $t8, 0xC($t7)
    ctx->r24 = MEM_H(ctx->r15, 0XC);
    // 0x800297DC: bne         $t8, $at, L_80029834
    if (ctx->r24 != ctx->r1) {
        // 0x800297E0: nop
    
            goto L_80029834;
    }
    // 0x800297E0: nop

    // 0x800297E4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800297E8: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800297EC: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x800297F0: bne         $t0, $t1, L_80029834
    if (ctx->r8 != ctx->r9) {
        // 0x800297F4: nop
    
            goto L_80029834;
    }
    // 0x800297F4: nop

    // 0x800297F8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800297FC: beq         $t2, $zero, L_8002981C
    if (ctx->r10 == 0) {
        // 0x80029800: nop
    
            goto L_8002981C;
    }
    // 0x80029800: nop

    // 0x80029804: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80029808: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8002980C: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80029810: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80029814: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80029818: sw          $t7, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r15;
L_8002981C:
    // 0x8002981C: jal         0x80020E74
    // 0x80029820: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80020E74(rdram, ctx);
        goto after_0;
    // 0x80029820: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x80029824: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80029828: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8002982C: jal         0x80020E40
    // 0x80029830: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    func_80020E40(rdram, ctx);
        goto after_1;
    // 0x80029830: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    after_1:
L_80029834:
    // 0x80029834: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80029838: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8002983C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80029840: bne         $t9, $zero, L_800297B4
    if (ctx->r25 != 0) {
        // 0x80029844: nop
    
            goto L_800297B4;
    }
    // 0x80029844: nop

L_80029848:
    // 0x80029848: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8002984C: sb          $zero, 0x37($t0)
    MEM_B(0X37, ctx->r8) = 0;
    // 0x80029850: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80029854: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80029858: sb          $t1, 0x38($t2)
    MEM_B(0X38, ctx->r10) = ctx->r9;
    // 0x8002985C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80029860: sb          $zero, 0x34($t5)
    MEM_B(0X34, ctx->r13) = 0;
    // 0x80029864: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80029868: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8002986C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80029870: lw          $t6, 0x1C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X1C);
    // 0x80029874: addu        $t3, $t6, $t7
    ctx->r11 = ADD32(ctx->r14, ctx->r15);
    // 0x80029878: sw          $t3, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r11;
    // 0x8002987C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80029880: jal         0x8002C5A0
    // 0x80029884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002C5A0(rdram, ctx);
        goto after_2;
    // 0x80029884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80029888: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8002988C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029890: jal         0x80026BE0
    // 0x80029894: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    func_80026BE0(rdram, ctx);
        goto after_3;
    // 0x80029894: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x80029898: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8002989C: sh          $t9, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r25;
    // 0x800298A0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800298A4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800298A8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800298AC: addiu       $t2, $t1, 0x7D00
    ctx->r10 = ADD32(ctx->r9, 0X7D00);
    // 0x800298B0: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x800298B4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800298B8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800298BC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800298C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800298C4: jal         0x80026500
    // 0x800298C8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_4;
    // 0x800298C8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_4:
    // 0x800298CC: b           L_800298D4
    // 0x800298D0: nop

        goto L_800298D4;
    // 0x800298D0: nop

L_800298D4:
    // 0x800298D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800298D8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800298DC: jr          $ra
    // 0x800298E0: nop

    return;
    // 0x800298E0: nop

;}
RECOMP_FUNC void func_8080009C_chjadesnake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A8: jal         0x800F54E4
    // 0x808000AC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808000AC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808000B4: jal         0x800F651C
    // 0x808000B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F651C(rdram, ctx);
        goto after_1;
    // 0x808000B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808000BC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808000C0: jal         0x800F6C5C
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_2;
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000C8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808000CC: jal         0x800F72DC
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F72DC(rdram, ctx);
        goto after_3;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000D4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808000D8: jal         0x800F56AC
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F56AC(rdram, ctx);
        goto after_4;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000E0: xori        $t6, $v0, 0x10
    ctx->r14 = ctx->r2 ^ 0X10;
    // 0x808000E4: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x808000E8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x808000EC: jal         0x800F6478
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6478(rdram, ctx);
        goto after_5;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000F4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808000F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808000FC: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
    // 0x80800100: bne         $t7, $zero, L_80800110
    if (ctx->r15 != 0) {
        // 0x80800104: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800110;
    }
    // 0x80800104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800108: b           L_80800144
    // 0x8080010C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800144;
    // 0x8080010C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800110:
    // 0x80800110: beql        $v0, $zero, L_80800148
    if (ctx->r2 == 0) {
        // 0x80800114: lw          $s0, 0x18($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X18);
            goto L_80800148;
    }
    goto skip_0;
    // 0x80800114: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800118: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8080011C: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800120: bne         $t8, $zero, L_80800144
    if (ctx->r24 != 0) {
        // 0x80800124: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80800144;
    }
    // 0x80800124: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80800128: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8080012C: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800130: beq         $t9, $zero, L_80800144
    if (ctx->r25 == 0) {
        // 0x80800134: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80800144;
    }
    // 0x80800134: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80800138: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8080013C: sltiu       $t0, $v0, 0x1
    ctx->r8 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800140: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80800144:
    // 0x80800144: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
L_80800148:
    // 0x80800148: jr          $ra
    // 0x8080014C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080014C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8009DEC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DEC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009DEC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DEC8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009DECC: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8009DED0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009DED4: jal         0x800DC178
    // 0x8009DED8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8009DED8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009DEDC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8009DEE0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8009DEE4: jal         0x800DC128
    // 0x8009DEE8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x8009DEE8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x8009DEEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8009DEF0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8009DEF4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8009DEF8: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009DEFC: lbu         $a1, 0x2($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X2);
    // 0x8009DF00: jal         0x8009DCCC
    // 0x8009DF04: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8009DCCC(rdram, ctx);
        goto after_2;
    // 0x8009DF04: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x8009DF08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DF0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009DF10: jr          $ra
    // 0x8009DF14: nop

    return;
    // 0x8009DF14: nop

;}
RECOMP_FUNC void bashoessuck_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800004: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8080000C: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80800010: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80800014: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800018: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8080001C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800020: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800024: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800028: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080002C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800030: jal         0x8009C128
    // 0x80800034: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800034: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    after_0:
    // 0x80800038: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(596, 0X740) << 16);
    // 0x8080003C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(596, 0X730) << 16);
    // 0x80800040: lui         $s7, 0x8080
    ctx->r23 = S32(RELOC_HI16(596, 0X800) << 16);
    // 0x80800044: lui         $s6, 0x2
    ctx->r22 = S32(0X2 << 16);
    // 0x80800048: addiu       $s1, $sp, 0x74
    ctx->r17 = ADD32(ctx->r29, 0X74);
    // 0x8080004C: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    // 0x80800050: ori         $s6, $s6, 0x20
    ctx->r22 = ctx->r22 | 0X20;
    // 0x80800054: addiu       $s7, $s7, 0x800
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(596, 0X800));
    // 0x80800058: lwc1        $f20, 0x730($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(596, 0X730));
    // 0x8080005C: addiu       $s2, $s2, 0x740
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(596, 0X740));
    // 0x80800060: addiu       $s5, $sp, 0x68
    ctx->r21 = ADD32(ctx->r29, 0X68);
    // 0x80800064: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
    // 0x80800068: addiu       $s0, $sp, 0x8C
    ctx->r16 = ADD32(ctx->r29, 0X8C);
    // 0x8080006C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
L_80800070:
    // 0x80800070: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x80800074: addiu       $v0, $sp, 0x80
    ctx->r2 = ADD32(ctx->r29, 0X80);
L_80800078:
    // 0x80800078: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8080007C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800080: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800084: sltu        $at, $v0, $s0
    ctx->r1 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x80800088: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080008C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800090: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800094: bne         $at, $zero, L_80800078
    if (ctx->r1 != 0) {
        // 0x80800098: swc1        $f8, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f8.u32l;
            goto L_80800078;
    }
    // 0x80800098: swc1        $f8, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f8.u32l;
    // 0x8080009C: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x808000A0: addiu       $v0, $sp, 0x80
    ctx->r2 = ADD32(ctx->r29, 0X80);
    // 0x808000A4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x808000A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808000AC: beq         $a0, $s1, L_808000D4
    if (ctx->r4 == ctx->r17) {
        // 0x808000B0: lwc1        $f18, 0xC($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
            goto L_808000D4;
    }
    // 0x808000B0: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
L_808000B4:
    // 0x808000B4: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808000B8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808000BC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808000C0: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x808000C4: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x808000C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808000CC: bne         $a0, $s1, L_808000B4
    if (ctx->r4 != ctx->r17) {
        // 0x808000D0: swc1        $f16, -0x8($a0)
        MEM_W(-0X8, ctx->r4) = ctx->f16.u32l;
            goto L_808000B4;
    }
    // 0x808000D0: swc1        $f16, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f16.u32l;
L_808000D4:
    // 0x808000D4: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808000D8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808000DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808000E0: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x808000E4: swc1        $f16, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f16.u32l;
    // 0x808000E8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808000EC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808000F0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808000F4: jal         0x800C6A7C
    // 0x808000F8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_800C6A7C(rdram, ctx);
        goto after_1;
    // 0x808000F8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_1:
    // 0x808000FC: beq         $v0, $zero, L_80800128
    if (ctx->r2 == 0) {
        // 0x80800100: lwc1        $f4, 0x60($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
            goto L_80800128;
    }
    // 0x80800100: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800104: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x80800108: nop

    // 0x8080010C: bc1fl       L_8080012C
    if (!c1cs) {
        // 0x80800110: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_8080012C;
    }
    goto skip_0;
    // 0x80800110: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    skip_0:
    // 0x80800114: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x80800118: jal         0x800EE7F8
    // 0x8080011C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8080011C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x80800120: b           L_80800154
    // 0x80800124: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800154;
    // 0x80800124: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800128:
    // 0x80800128: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
L_8080012C:
    // 0x8080012C: bnel        $s2, $s7, L_80800070
    if (ctx->r18 != ctx->r23) {
        // 0x80800130: addiu       $a0, $sp, 0x74
        ctx->r4 = ADD32(ctx->r29, 0X74);
            goto L_80800070;
    }
    goto skip_1;
    // 0x80800130: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    skip_1:
    // 0x80800134: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800138: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x8080013C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800140: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800144: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800148: jal         0x800EFA4C
    // 0x8080014C: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x8080014C: nop

    after_3:
    // 0x80800150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800154:
    // 0x80800154: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800158: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8080015C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800160: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800164: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800168: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8080016C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800170: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800174: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80800178: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x8080017C: jr          $ra
    // 0x80800180: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80800180: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void _gcdialogcamera_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088090: syscall     669
    recomp_syscall_handler(rdram, ctx, 0x80088090);
    return;
    // 0x80088094: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void ncpodfixpos_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A0: jr          $ra
    // 0x808001A4: sh          $a1, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r5;
    return;
    // 0x808001A4: sh          $a1, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_80800D3C_gcsectionskip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D48: jal         0x800F54E4
    // 0x80800D4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800D4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800D50: jal         0x800F5410
    // 0x80800D54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x80800D54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800D58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D5C: beq         $v0, $at, L_80800D6C
    if (ctx->r2 == ctx->r1) {
        // 0x80800D60: nop
    
            goto L_80800D6C;
    }
    // 0x80800D60: nop

    // 0x80800D64: b           L_80800EE8
    // 0x80800D68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EE8;
    // 0x80800D68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D6C:
    // 0x80800D6C: jal         0x800EA05C
    // 0x80800D70: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x80800D70: nop

    after_2:
    // 0x80800D74: slti        $at, $v0, 0xB0
    ctx->r1 = SIGNED(ctx->r2) < 0XB0 ? 1 : 0;
    // 0x80800D78: bne         $at, $zero, L_80800DA0
    if (ctx->r1 != 0) {
        // 0x80800D7C: addiu       $t6, $v0, -0x142
        ctx->r14 = ADD32(ctx->r2, -0X142);
            goto L_80800DA0;
    }
    // 0x80800D7C: addiu       $t6, $v0, -0x142
    ctx->r14 = ADD32(ctx->r2, -0X142);
    // 0x80800D80: sltiu       $at, $t6, 0x1E
    ctx->r1 = ctx->r14 < 0X1E ? 1 : 0;
    // 0x80800D84: beq         $at, $zero, L_80800EE4
    if (ctx->r1 == 0) {
        // 0x80800D88: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800EE4;
    }
    // 0x80800D88: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800D8C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2574, 0XFC4) << 16);
    // 0x80800D90: addu        $at, $at, $t6
    gpr jr_addend_80800D98 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800D94: lw          $t6, 0xFC4($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2574, 0XFC4));
    // 0x80800D98: jr          $t6
    // 0x80800D9C: nop

    switch (jr_addend_80800D98 >> 2) {
        case 0: goto L_80800DD4; break;
        case 1: goto L_80800EE4; break;
        case 2: goto L_80800EE4; break;
        case 3: goto L_80800EE4; break;
        case 4: goto L_80800EE4; break;
        case 5: goto L_80800EE4; break;
        case 6: goto L_80800EE4; break;
        case 7: goto L_80800EE4; break;
        case 8: goto L_80800EE4; break;
        case 9: goto L_80800EE4; break;
        case 10: goto L_80800EE4; break;
        case 11: goto L_80800EE4; break;
        case 12: goto L_80800EE4; break;
        case 13: goto L_80800EE4; break;
        case 14: goto L_80800EE4; break;
        case 15: goto L_80800EE4; break;
        case 16: goto L_80800EE4; break;
        case 17: goto L_80800EE4; break;
        case 18: goto L_80800E44; break;
        case 19: goto L_80800EE4; break;
        case 20: goto L_80800EE4; break;
        case 21: goto L_80800EE4; break;
        case 22: goto L_80800EE4; break;
        case 23: goto L_80800EE4; break;
        case 24: goto L_80800E0C; break;
        case 25: goto L_80800EE4; break;
        case 26: goto L_80800EE4; break;
        case 27: goto L_80800E6C; break;
        case 28: goto L_80800EE4; break;
        case 29: goto L_80800EB0; break;
        default: switch_error(__func__, 0x80800D98, 0x80800FC4);
    }
    // 0x80800D9C: nop

L_80800DA0:
    // 0x80800DA0: addiu       $at, $zero, 0xAF
    ctx->r1 = ADD32(0, 0XAF);
    // 0x80800DA4: bnel        $v0, $at, L_80800EE8
    if (ctx->r2 != ctx->r1) {
        // 0x80800DA8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800EE8;
    }
    goto skip_0;
    // 0x80800DA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800DAC: jal         0x800DA298
    // 0x80800DB0: addiu       $a0, $zero, 0x318
    ctx->r4 = ADD32(0, 0X318);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800DB0: addiu       $a0, $zero, 0x318
    ctx->r4 = ADD32(0, 0X318);
    after_3:
    // 0x80800DB4: beq         $v0, $zero, L_80800EE4
    if (ctx->r2 == 0) {
        // 0x80800DB8: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_80800EE4;
    }
    // 0x80800DB8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800DBC: addiu       $t7, $zero, 0x142
    ctx->r15 = ADD32(0, 0X142);
    // 0x80800DC0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80800DC4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DC8: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80800DCC: b           L_80800EE4
    // 0x80800DD0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_80800EE4;
    // 0x80800DD0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_80800DD4:
    // 0x80800DD4: jal         0x800DA298
    // 0x80800DD8: addiu       $a0, $zero, 0x318
    ctx->r4 = ADD32(0, 0X318);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800DD8: addiu       $a0, $zero, 0x318
    ctx->r4 = ADD32(0, 0X318);
    after_4:
    // 0x80800DDC: beq         $v0, $zero, L_80800E00
    if (ctx->r2 == 0) {
        // 0x80800DE0: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80800E00;
    }
    // 0x80800DE0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DE4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80800DE8: addiu       $t1, $zero, 0xAF
    ctx->r9 = ADD32(0, 0XAF);
    // 0x80800DEC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80800DF0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80800DF4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DF8: b           L_80800EE4
    // 0x80800DFC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
        goto L_80800EE4;
    // 0x80800DFC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_80800E00:
    // 0x80800E00: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800E04: b           L_80800EE4
    // 0x80800E08: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
        goto L_80800EE4;
    // 0x80800E08: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_80800E0C:
    // 0x80800E0C: jal         0x800DA298
    // 0x80800E10: addiu       $a0, $zero, 0x319
    ctx->r4 = ADD32(0, 0X319);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800E10: addiu       $a0, $zero, 0x319
    ctx->r4 = ADD32(0, 0X319);
    after_5:
    // 0x80800E14: beq         $v0, $zero, L_80800E38
    if (ctx->r2 == 0) {
        // 0x80800E18: lw          $t2, 0x1C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X1C);
            goto L_80800E38;
    }
    // 0x80800E18: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E1C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800E20: addiu       $t7, $zero, 0x154
    ctx->r15 = ADD32(0, 0X154);
    // 0x80800E24: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80800E28: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80800E2C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E30: b           L_80800EE4
    // 0x80800E34: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_80800EE4;
    // 0x80800E34: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_80800E38:
    // 0x80800E38: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800E3C: b           L_80800EE4
    // 0x80800E40: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
        goto L_80800EE4;
    // 0x80800E40: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_80800E44:
    // 0x80800E44: jal         0x800DA298
    // 0x80800E48: addiu       $a0, $zero, 0x319
    ctx->r4 = ADD32(0, 0X319);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800E48: addiu       $a0, $zero, 0x319
    ctx->r4 = ADD32(0, 0X319);
    after_6:
    // 0x80800E4C: beq         $v0, $zero, L_80800EE4
    if (ctx->r2 == 0) {
        // 0x80800E50: lw          $t4, 0x18($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X18);
            goto L_80800EE4;
    }
    // 0x80800E50: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80800E54: addiu       $t3, $zero, 0x15A
    ctx->r11 = ADD32(0, 0X15A);
    // 0x80800E58: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80800E5C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E60: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800E64: b           L_80800EE4
    // 0x80800E68: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
        goto L_80800EE4;
    // 0x80800E68: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_80800E6C:
    // 0x80800E6C: jal         0x800DA298
    // 0x80800E70: addiu       $a0, $zero, 0x31A
    ctx->r4 = ADD32(0, 0X31A);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800E70: addiu       $a0, $zero, 0x31A
    ctx->r4 = ADD32(0, 0X31A);
    after_7:
    // 0x80800E74: beq         $v0, $zero, L_80800EE4
    if (ctx->r2 == 0) {
        // 0x80800E78: addiu       $t7, $zero, 0x15F
        ctx->r15 = ADD32(0, 0X15F);
            goto L_80800EE4;
    }
    // 0x80800E78: addiu       $t7, $zero, 0x15F
    ctx->r15 = ADD32(0, 0X15F);
    // 0x80800E7C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800E80: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    // 0x80800E84: jal         0x800DA298
    // 0x80800E88: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800E88: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    after_8:
    // 0x80800E8C: beq         $v0, $zero, L_80800EA4
    if (ctx->r2 == 0) {
        // 0x80800E90: lw          $t2, 0x1C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X1C);
            goto L_80800EA4;
    }
    // 0x80800E90: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E94: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E98: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80800E9C: b           L_80800EE4
    // 0x80800EA0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_80800EE4;
    // 0x80800EA0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_80800EA4:
    // 0x80800EA4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800EA8: b           L_80800EE4
    // 0x80800EAC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
        goto L_80800EE4;
    // 0x80800EAC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_80800EB0:
    // 0x80800EB0: jal         0x800DA298
    // 0x80800EB4: addiu       $a0, $zero, 0x31A
    ctx->r4 = ADD32(0, 0X31A);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x80800EB4: addiu       $a0, $zero, 0x31A
    ctx->r4 = ADD32(0, 0X31A);
    after_9:
    // 0x80800EB8: beq         $v0, $zero, L_80800EDC
    if (ctx->r2 == 0) {
        // 0x80800EBC: lw          $t8, 0x1C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1C);
            goto L_80800EDC;
    }
    // 0x80800EBC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EC0: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80800EC4: addiu       $t3, $zero, 0x15D
    ctx->r11 = ADD32(0, 0X15D);
    // 0x80800EC8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80800ECC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80800ED0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800ED4: b           L_80800EE4
    // 0x80800ED8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
        goto L_80800EE4;
    // 0x80800ED8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_80800EDC:
    // 0x80800EDC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800EE0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_80800EE4:
    // 0x80800EE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EE8:
    // 0x80800EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EF0: jr          $ra
    // 0x80800EF4: nop

    return;
    // 0x80800EF4: nop

;}
RECOMP_FUNC void func_800CC684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC684: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800CC688: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CC68C: lw          $t7, -0x517C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X517C);
    // 0x800CC690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CC694: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CC698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC69C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CC6A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CC6A4: jal         0x800CB948
    // 0x800CC6A8: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    func_800CB948(rdram, ctx);
        goto after_0;
    // 0x800CC6A8: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x800CC6AC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC6B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CC6B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CC6B8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800CC6BC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800CC6C0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800CC6C4: jr          $ra
    // 0x800CC6C8: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    return;
    // 0x800CC6C8: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
;}
RECOMP_FUNC void func_808007A0_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007A8: addiu       $at, $zero, 0x10DF
    ctx->r1 = ADD32(0, 0X10DF);
    // 0x808007AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007B4: beq         $a1, $at, L_808007D0
    if (ctx->r5 == ctx->r1) {
        // 0x808007B8: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808007D0;
    }
    // 0x808007B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808007BC: addiu       $at, $zero, 0x10FE
    ctx->r1 = ADD32(0, 0X10FE);
    // 0x808007C0: beq         $a1, $at, L_808007EC
    if (ctx->r5 == ctx->r1) {
        // 0x808007C4: nop
    
            goto L_808007EC;
    }
    // 0x808007C4: nop

    // 0x808007C8: b           L_80800808
    // 0x808007CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800808;
    // 0x808007CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007D0:
    // 0x808007D0: jal         0x80085710
    // 0x808007D4: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808007D4: nop

    after_0:
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007DC: jal         0x80102424
    // 0x808007E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x808007E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808007E4: b           L_8080086C
    // 0x808007E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080086C;
    // 0x808007E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007EC:
    // 0x808007EC: jal         0x8008FC9C
    // 0x808007F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8008FC9C(rdram, ctx);
        goto after_2;
    // 0x808007F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F8: jal         0x80102424
    // 0x808007FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808007FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800800: b           L_8080086C
    // 0x80800804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080086C;
    // 0x80800804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800808:
    // 0x80800808: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
    // 0x8080080C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(936, 0XBC0) << 16);
    // 0x80800810: addiu       $a2, $a2, 0xBC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(936, 0XBC0));
    // 0x80800814: beql        $t6, $zero, L_80800858
    if (ctx->r14 == 0) {
        // 0x80800818: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800858;
    }
    goto skip_0;
    // 0x80800818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080081C: jal         0x8008A1F8
    // 0x80800820: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800820: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_4:
    // 0x80800824: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800828: bne         $v0, $at, L_80800854
    if (ctx->r2 != ctx->r1) {
        // 0x8080082C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800854;
    }
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800830: jal         0x80102424
    // 0x80800834: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800834: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800838: jal         0x80106790
    // 0x8080083C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x8080083C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_6:
    // 0x80800840: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800844: jal         0x80102424
    // 0x80800848: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800848: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x8080084C: b           L_8080086C
    // 0x80800850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080086C;
    // 0x80800850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800854:
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800858:
    // 0x80800858: jal         0x80102424
    // 0x8080085C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x8080085C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800860: jal         0x80090708
    // 0x80800864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_9;
    // 0x80800864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80800868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080086C:
    // 0x8080086C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800870: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800874: jr          $ra
    // 0x80800878: nop

    return;
    // 0x80800878: nop

;}
