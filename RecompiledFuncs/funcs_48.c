#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080013C_bskazstilt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800140: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800144: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800148: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080014C: jal         0x8009E77C
    // 0x80800150: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x80800150: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80800154: bnel        $v0, $zero, L_80800224
    if (ctx->r2 != 0) {
        // 0x80800158: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800224;
    }
    goto skip_0;
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080015C: jal         0x800832E0
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x80095774
    // 0x8080016C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    baflag_clear(rdram, ctx);
        goto after_2;
    // 0x8080016C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_2:
    // 0x80800170: jal         0x8009E4AC
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_3;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800180: jal         0x8009E5A4
    // 0x80800184: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009E5A4(rdram, ctx);
        goto after_4;
    // 0x80800184: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800190: jal         0x8009E55C
    // 0x80800194: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_8009E55C(rdram, ctx);
        goto after_5;
    // 0x80800194: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_5:
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001A0: jal         0x8009E53C
    // 0x808001A4: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    func_8009E53C(rdram, ctx);
        goto after_6;
    // 0x808001A4: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    after_6:
    // 0x808001A8: jal         0x8009EFA8
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_7;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001B0: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x808001B4: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x8009F1C8
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_8;
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001CC: jal         0x8009F1C8
    // 0x808001D0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_9;
    // 0x808001D0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_9:
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: jal         0x800A0CF4
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_10;
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: jal         0x800A0CE8
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CE8(rdram, ctx);
        goto after_11;
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x800A0DD0
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0DD0(rdram, ctx);
        goto after_12;
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800200: jal         0x8009BFE4
    // 0x80800204: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_13;
    // 0x80800204: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_13:
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800210: jal         0x8009C554
    // 0x80800214: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_14;
    // 0x80800214: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_14:
    // 0x80800218: jal         0x80084428
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baalarm_new(rdram, ctx);
        goto after_15;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800224:
    // 0x80800224: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800228: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080022C: jr          $ra
    // 0x80800230: nop

    return;
    // 0x80800230: nop

;}
RECOMP_FUNC void _chmineprospector_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D00: syscall     228
    recomp_syscall_handler(rdram, ctx, 0x80085D00);
    return;
    // 0x80085D04: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800030_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080003C: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800040: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800048: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x8080004C: beq         $t6, $at, L_80800074
    if (ctx->r14 == ctx->r1) {
        // 0x80800050: sw          $zero, 0x30($a0)
        MEM_W(0X30, ctx->r4) = 0;
            goto L_80800074;
    }
    // 0x80800050: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x80800054: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80800058: beq         $t6, $at, L_80800088
    if (ctx->r14 == ctx->r1) {
        // 0x8080005C: addiu       $t9, $zero, 0x325
        ctx->r25 = ADD32(0, 0X325);
            goto L_80800088;
    }
    // 0x8080005C: addiu       $t9, $zero, 0x325
    ctx->r25 = ADD32(0, 0X325);
    // 0x80800060: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80800064: beq         $t6, $at, L_80800098
    if (ctx->r14 == ctx->r1) {
        // 0x80800068: addiu       $t1, $zero, 0x326
        ctx->r9 = ADD32(0, 0X326);
            goto L_80800098;
    }
    // 0x80800068: addiu       $t1, $zero, 0x326
    ctx->r9 = ADD32(0, 0X326);
    // 0x8080006C: b           L_808000A4
    // 0x80800070: nop

        goto L_808000A4;
    // 0x80800070: nop

L_80800074:
    // 0x80800074: addiu       $t7, $zero, 0x324
    ctx->r15 = ADD32(0, 0X324);
    // 0x80800078: addiu       $t8, $zero, 0x16C
    ctx->r24 = ADD32(0, 0X16C);
    // 0x8080007C: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
    // 0x80800080: b           L_808000A4
    // 0x80800084: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
        goto L_808000A4;
    // 0x80800084: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
L_80800088:
    // 0x80800088: addiu       $t0, $zero, 0x16D
    ctx->r8 = ADD32(0, 0X16D);
    // 0x8080008C: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    // 0x80800090: b           L_808000A4
    // 0x80800094: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
        goto L_808000A4;
    // 0x80800094: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
L_80800098:
    // 0x80800098: addiu       $t2, $zero, 0x16E
    ctx->r10 = ADD32(0, 0X16E);
    // 0x8080009C: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
    // 0x808000A0: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
L_808000A4:
    // 0x808000A4: jal         0x80088848
    // 0x808000A8: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x808000A8: nop

    after_0:
    // 0x808000AC: beq         $v0, $zero, L_808000BC
    if (ctx->r2 == 0) {
        // 0x808000B0: nop
    
            goto L_808000BC;
    }
    // 0x808000B0: nop

    // 0x808000B4: b           L_80800104
    // 0x808000B8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
        goto L_80800104;
    // 0x808000B8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
L_808000BC:
    // 0x808000BC: jal         0x800DA298
    // 0x808000C0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808000C0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_1:
    // 0x808000C4: beq         $v0, $zero, L_808000EC
    if (ctx->r2 == 0) {
        // 0x808000C8: nop
    
            goto L_808000EC;
    }
    // 0x808000C8: nop

    // 0x808000CC: jal         0x800DA298
    // 0x808000D0: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808000D0: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_2:
    // 0x808000D4: beq         $v0, $zero, L_808000E4
    if (ctx->r2 == 0) {
        // 0x808000D8: nop
    
            goto L_808000E4;
    }
    // 0x808000D8: nop

    // 0x808000DC: b           L_80800104
    // 0x808000E0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
        goto L_80800104;
    // 0x808000E0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_808000E4:
    // 0x808000E4: b           L_80800104
    // 0x808000E8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
        goto L_80800104;
    // 0x808000E8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_808000EC:
    // 0x808000EC: jal         0x800DA298
    // 0x808000F0: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808000F0: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_3:
    // 0x808000F4: beq         $v0, $zero, L_80800104
    if (ctx->r2 == 0) {
        // 0x808000F8: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800104;
    }
    // 0x808000F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000FC: b           L_80800104
    // 0x80800100: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
        goto L_80800104;
    // 0x80800100: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_80800104:
    // 0x80800104: jal         0x80102424
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080010C: jal         0x80801200
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801200_chnicecavemen(rdram, ctx);
        goto after_5;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800118: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800120: jr          $ra
    // 0x80800124: nop

    return;
    // 0x80800124: nop

;}
RECOMP_FUNC void func_808013C4_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013CC: jal         0x800845D0
    // 0x808013D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808013D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808013D4: jal         0x808008D8
    // 0x808013D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808008D8_bssub(rdram, ctx);
        goto after_1;
    // 0x808013D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808013DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013E4: jr          $ra
    // 0x808013E8: nop

    return;
    // 0x808013E8: nop

;}
RECOMP_FUNC void func_800A4C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4C88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4C8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4C90: jal         0x800A93E4
    // 0x800A4C94: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800A93E4(rdram, ctx);
        goto after_0;
    // 0x800A4C94: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x800A4C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4CA0: jr          $ra
    // 0x800A4CA4: nop

    return;
    // 0x800A4CA4: nop

;}
RECOMP_FUNC void baroll_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C4A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C4A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C4AC: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x8009C4B0: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x8009C4B4: jal         0x8009C2D8
    // 0x8009C4B8: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    __baroll_update(rdram, ctx);
        goto after_0;
    // 0x8009C4B8: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    after_0:
    // 0x8009C4BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C4C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C4C4: jr          $ra
    // 0x8009C4C8: nop

    return;
    // 0x8009C4C8: nop

;}
RECOMP_FUNC void _gccollectDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088030: syscall     666
    recomp_syscall_handler(rdram, ctx, 0x80088030);
    return;
    // 0x80088034: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void chdrawbridgeswitches_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800204: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2060, 0X2A0) << 16);
    // 0x80800208: jr          $ra
    // 0x8080020C: addiu       $v0, $v0, 0x2A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2060, 0X2A0));
    return;
    // 0x8080020C: addiu       $v0, $v0, 0x2A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2060, 0X2A0));
;}
RECOMP_FUNC void func_80800670_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800670: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800674: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800678: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8080067C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800680: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800684: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800688: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8080068C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800690: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800694: jal         0x80100094
    // 0x80800698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080069C: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x808006A0: addiu       $s4, $s3, 0x4
    ctx->r20 = ADD32(ctx->r19, 0X4);
    // 0x808006A4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808006A8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808006AC: jal         0x800EE7F8
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B8: jal         0x800EECE0
    // 0x808006BC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EECE0(rdram, ctx);
        goto after_2;
    // 0x808006BC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x808006C0: bne         $v0, $zero, L_808006E4
    if (ctx->r2 != 0) {
        // 0x808006C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006E4;
    }
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C8: jal         0x800EEB40
    // 0x808006CC: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x808006CC: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    after_3:
    // 0x808006D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3D28) << 16);
    // 0x808006D4: lwc1        $f20, 0x3D28($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3D28));
    // 0x808006D8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808006DC: nop

    // 0x808006E0: bc1f        L_80800744
    if (!c1cs) {
        // 0x808006E4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1676, 0X3D2C) << 16);
            goto L_80800744;
    }
L_808006E4:
    // 0x808006E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3D2C) << 16);
    // 0x808006E8: lwc1        $f20, 0x3D2C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3D2C));
    // 0x808006EC: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x808006F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808006F4: jal         0x800DC128
    // 0x808006F8: lbu         $a1, 0x91($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X91);
    func_800DC128(rdram, ctx);
        goto after_4;
    // 0x808006F8: lbu         $a1, 0x91($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X91);
    after_4:
    // 0x808006FC: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800704: mflo        $t6
    ctx->r14 = lo;
    // 0x80800708: addu        $a1, $s1, $t6
    ctx->r5 = ADD32(ctx->r17, ctx->r14);
    // 0x8080070C: jal         0x800EE7F8
    // 0x80800710: nop

    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800710: nop

    after_5:
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800718: jal         0x800EECE0
    // 0x8080071C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EECE0(rdram, ctx);
        goto after_6;
    // 0x8080071C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x80800720: bne         $v0, $zero, L_808006E4
    if (ctx->r2 != 0) {
        // 0x80800724: nop
    
            goto L_808006E4;
    }
    // 0x80800724: nop

    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080072C: jal         0x800EEB40
    // 0x80800730: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    func_800EEB40(rdram, ctx);
        goto after_7;
    // 0x80800730: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    after_7:
    // 0x80800734: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800738: nop

    // 0x8080073C: bc1t        L_808006E4
    if (c1cs) {
        // 0x80800740: nop
    
            goto L_808006E4;
    }
    // 0x80800740: nop

L_80800744:
    // 0x80800744: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800748: jal         0x800EE7F8
    // 0x8080074C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x8080074C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80800750: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800754: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800758: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080075C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800760: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800764: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800768: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8080076C: jr          $ra
    // 0x80800770: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800770: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800878_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080087C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800880: jal         0x80800264
    // 0x80800884: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_0;
    // 0x80800884: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_0:
    // 0x80800888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080088C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800890: jr          $ra
    // 0x80800894: nop

    return;
    // 0x80800894: nop

;}
RECOMP_FUNC void _chfactorytoxicpools_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086260: syscall     295
    recomp_syscall_handler(rdram, ctx, 0x80086260);
    return;
    // 0x80086264: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bstaxi_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083DF8: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083DF8);
    return;
    // 0x80083DFC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800570_chboggyboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800570: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800574: slti        $at, $a1, 0x53
    ctx->r1 = SIGNED(ctx->r5) < 0X53 ? 1 : 0;
    // 0x80800578: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080057C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800580: bne         $at, $zero, L_8080059C
    if (ctx->r1 != 0) {
        // 0x80800584: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080059C;
    }
    // 0x80800584: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800588: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080058C: beq         $a1, $at, L_808005EC
    if (ctx->r5 == ctx->r1) {
        // 0x80800590: nop
    
            goto L_808005EC;
    }
    // 0x80800590: nop

    // 0x80800594: b           L_808006B4
    // 0x80800598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006B4;
    // 0x80800598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080059C:
    // 0x8080059C: addiu       $t6, $a1, -0x29
    ctx->r14 = ADD32(ctx->r5, -0X29);
    // 0x808005A0: sltiu       $at, $t6, 0x2A
    ctx->r1 = ctx->r14 < 0X2A ? 1 : 0;
    // 0x808005A4: beq         $at, $zero, L_808006A8
    if (ctx->r1 == 0) {
        // 0x808005A8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808006A8;
    }
    // 0x808005A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808005AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1532, 0XB4C) << 16);
    // 0x808005B0: addu        $at, $at, $t6
    gpr jr_addend_808005B8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808005B4: lw          $t6, 0xB4C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1532, 0XB4C));
    // 0x808005B8: jr          $t6
    // 0x808005BC: nop

    switch (jr_addend_808005B8 >> 2) {
        case 0: goto L_808005FC; break;
        case 1: goto L_80800698; break;
        case 2: goto L_808006A8; break;
        case 3: goto L_808006A8; break;
        case 4: goto L_80800624; break;
        case 5: goto L_808005C0; break;
        case 6: goto L_808006A8; break;
        case 7: goto L_80800680; break;
        case 8: goto L_808006A8; break;
        case 9: goto L_808006A8; break;
        case 10: goto L_808006A8; break;
        case 11: goto L_808006A8; break;
        case 12: goto L_808006A8; break;
        case 13: goto L_808006A8; break;
        case 14: goto L_808006A8; break;
        case 15: goto L_808006A8; break;
        case 16: goto L_808006A8; break;
        case 17: goto L_808006A8; break;
        case 18: goto L_808006A8; break;
        case 19: goto L_808006A8; break;
        case 20: goto L_808006A8; break;
        case 21: goto L_808006A8; break;
        case 22: goto L_808006A8; break;
        case 23: goto L_808005D8; break;
        case 24: goto L_808006A8; break;
        case 25: goto L_808006A8; break;
        case 26: goto L_808006A8; break;
        case 27: goto L_808006A8; break;
        case 28: goto L_808006A8; break;
        case 29: goto L_808006A8; break;
        case 30: goto L_808006A8; break;
        case 31: goto L_808006A8; break;
        case 32: goto L_808006A8; break;
        case 33: goto L_808006A8; break;
        case 34: goto L_808006A8; break;
        case 35: goto L_808006A8; break;
        case 36: goto L_808006A8; break;
        case 37: goto L_808006A8; break;
        case 38: goto L_808006A8; break;
        case 39: goto L_808006A8; break;
        case 40: goto L_808006A8; break;
        case 41: goto L_8080060C; break;
        default: switch_error(__func__, 0x808005B8, 0x80800B4C);
    }
    // 0x808005BC: nop

L_808005C0:
    // 0x808005C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808005C4: lh          $a1, 0x40($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X40);
    // 0x808005C8: jal         0x808006C4
    // 0x808005CC: lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X42);
    func_808006C4_chboggyboy(rdram, ctx);
        goto after_0;
    // 0x808005CC: lh          $a2, 0x42($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X42);
    after_0:
    // 0x808005D0: b           L_808006B4
    // 0x808005D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006B4;
    // 0x808005D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005D8:
    // 0x808005D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808005DC: jal         0x80800978
    // 0x808005E0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80800978_chboggyboy(rdram, ctx);
        goto after_1;
    // 0x808005E0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x808005E4: b           L_808006B4
    // 0x808005E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006B4;
    // 0x808005E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005EC:
    // 0x808005EC: jal         0x80089F60
    // 0x808005F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808005F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x808005F4: b           L_808006B4
    // 0x808005F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006B4;
    // 0x808005F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005FC:
    // 0x808005FC: jal         0x80800A64
    // 0x80800600: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800A64_chboggyboy(rdram, ctx);
        goto after_3;
    // 0x80800600: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x80800604: b           L_808006B4
    // 0x80800608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006B4;
    // 0x80800608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080060C:
    // 0x8080060C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1532, 0XD10) << 16);
    // 0x80800610: addiu       $a0, $a0, 0xD10
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1532, 0XD10));
    // 0x80800614: jal         0x80088090
    // 0x80800618: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800618: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_4:
    // 0x8080061C: b           L_808006B4
    // 0x80800620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006B4;
    // 0x80800620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800624:
    // 0x80800624: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80800628: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1532, 0XD20) << 16);
    // 0x8080062C: addiu       $a2, $a2, 0xD20
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1532, 0XD20));
    // 0x80800630: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800634: jal         0x80089D18
    // 0x80800638: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800638: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
    // 0x8080063C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800640: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800644: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800648: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080064C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1532, 0XBF4) << 16);
    // 0x80800650: lwc1        $f6, 0xBF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1532, 0XBF4));
    // 0x80800654: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800658: lui         $a2, 0x3F86
    ctx->r6 = S32(0X3F86 << 16);
    // 0x8080065C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800660: addiu       $a1, $zero, 0x525
    ctx->r5 = ADD32(0, 0X525);
    // 0x80800664: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    // 0x80800668: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8080066C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80800670: jal         0x800C9C70
    // 0x80800674: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800C9C70(rdram, ctx);
        goto after_6;
    // 0x80800674: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_6:
    // 0x80800678: b           L_808006B4
    // 0x8080067C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006B4;
    // 0x8080067C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800680:
    // 0x80800680: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // 0x80800684: jal         0x800DA980
    // 0x80800688: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA980(rdram, ctx);
        goto after_7;
    // 0x80800688: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x8080068C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80800690: b           L_808006B4
    // 0x80800694: subu        $v0, $t8, $v0
    ctx->r2 = SUB32(ctx->r24, ctx->r2);
        goto L_808006B4;
    // 0x80800694: subu        $v0, $t8, $v0
    ctx->r2 = SUB32(ctx->r24, ctx->r2);
L_80800698:
    // 0x80800698: jal         0x80800AD0
    // 0x8080069C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800AD0_chboggyboy(rdram, ctx);
        goto after_8;
    // 0x8080069C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_8:
    // 0x808006A0: b           L_808006B4
    // 0x808006A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006B4;
    // 0x808006A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006A8:
    // 0x808006A8: b           L_808006B4
    // 0x808006AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006B4;
    // 0x808006AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808006B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006B4:
    // 0x808006B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808006BC: jr          $ra
    // 0x808006C0: nop

    return;
    // 0x808006C0: nop

;}
RECOMP_FUNC void func_800BFF28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFF28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BFF2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BFF30: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BFF34: jal         0x80088058
    // 0x800BFF38: addiu       $a0, $a0, -0x7890
    ctx->r4 = ADD32(ctx->r4, -0X7890);
    _gcskyDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800BFF38: addiu       $a0, $a0, -0x7890
    ctx->r4 = ADD32(ctx->r4, -0X7890);
    after_0:
    // 0x800BFF3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BFF40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BFF44: jr          $ra
    // 0x800BFF48: nop

    return;
    // 0x800BFF48: nop

;}
RECOMP_FUNC void func_80800914_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800914: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800918: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8080091C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800924: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800928: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080092C: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x80800930: jal         0x80100094
    // 0x80800934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800938: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8080093C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800940: slti        $at, $a2, 0x4A
    ctx->r1 = SIGNED(ctx->r6) < 0X4A ? 1 : 0;
    // 0x80800944: bne         $at, $zero, L_8080096C
    if (ctx->r1 != 0) {
        // 0x80800948: addiu       $t6, $a2, -0x70
        ctx->r14 = ADD32(ctx->r6, -0X70);
            goto L_8080096C;
    }
    // 0x80800948: addiu       $t6, $a2, -0x70
    ctx->r14 = ADD32(ctx->r6, -0X70);
    // 0x8080094C: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80800950: beq         $at, $zero, L_80800BB0
    if (ctx->r1 == 0) {
        // 0x80800954: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800BB0;
    }
    // 0x80800954: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800958: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2216, 0X2120) << 16);
    // 0x8080095C: addu        $at, $at, $t6
    gpr jr_addend_80800964 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800960: lw          $t6, 0x2120($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2216, 0X2120));
    // 0x80800964: jr          $t6
    // 0x80800968: nop

    switch (jr_addend_80800964 >> 2) {
        case 0: goto L_80800994; break;
        case 1: goto L_80800AA4; break;
        case 2: goto L_80800AFC; break;
        case 3: goto L_80800B24; break;
        case 4: goto L_80800B48; break;
        case 5: goto L_80800B6C; break;
        default: switch_error(__func__, 0x80800964, 0x80802120);
    }
    // 0x80800968: nop

L_8080096C:
    // 0x8080096C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800970: beq         $a2, $at, L_80800B94
    if (ctx->r6 == ctx->r1) {
        // 0x80800974: lh          $t0, 0x40($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X40);
            goto L_80800B94;
    }
    // 0x80800974: lh          $t0, 0x40($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X40);
    // 0x80800978: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x8080097C: bne         $a2, $at, L_80800BB0
    if (ctx->r6 != ctx->r1) {
        // 0x80800980: nop
    
            goto L_80800BB0;
    }
    // 0x80800980: nop

    // 0x80800984: jal         0x8080019C
    // 0x80800988: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_8080019C_chfpsgame(rdram, ctx);
        goto after_1;
    // 0x80800988: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_1:
    // 0x8080098C: b           L_80800BBC
    // 0x80800990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BBC;
    // 0x80800990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800994:
    // 0x80800994: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80800998: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8080099C: andi        $t7, $a3, 0xF
    ctx->r15 = ctx->r7 & 0XF;
    // 0x808009A0: sra         $t8, $a3, 4
    ctx->r24 = S32(SIGNED(ctx->r7) >> 4);
    // 0x808009A4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x808009A8: jal         0x80088380
    // 0x808009AC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    _gcstatusDll_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x808009AC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_2:
    // 0x808009B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808009B4: beq         $v0, $at, L_80800A2C
    if (ctx->r2 == ctx->r1) {
        // 0x808009B8: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_80800A2C;
    }
    // 0x808009B8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x808009BC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808009C0: beq         $v0, $at, L_808009D8
    if (ctx->r2 == ctx->r1) {
        // 0x808009C4: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_808009D8;
    }
    // 0x808009C4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808009C8: beq         $v0, $at, L_80800A4C
    if (ctx->r2 == ctx->r1) {
        // 0x808009CC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800A4C;
    }
    // 0x808009CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808009D0: b           L_80800A80
    // 0x808009D4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_80800A80;
    // 0x808009D4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_808009D8:
    // 0x808009D8: jal         0x80088388
    // 0x808009DC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    _gcstatusDll_entrypoint_15(rdram, ctx);
        goto after_3;
    // 0x808009DC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_3:
    // 0x808009E0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x808009E4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x808009E8: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x808009EC: bnel        $v0, $t9, L_80800A20
    if (ctx->r2 != ctx->r25) {
        // 0x808009F0: lw          $t0, 0x8($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X8);
            goto L_80800A20;
    }
    goto skip_0;
    // 0x808009F0: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    skip_0:
    // 0x808009F4: jal         0x800FC660
    // 0x808009F8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x808009F8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_4:
    // 0x808009FC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800A00: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800A04: jal         0x80800BCC
    // 0x80800A08: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80800BCC_chfpsgame(rdram, ctx);
        goto after_5;
    // 0x80800A08: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800A0C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800A10: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80800A14: b           L_80800BB8
    // 0x80800A18: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
        goto L_80800BB8;
    // 0x80800A18: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
    // 0x80800A1C: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
L_80800A20:
    // 0x80800A20: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80800A24: b           L_80800BB8
    // 0x80800A28: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
        goto L_80800BB8;
    // 0x80800A28: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
L_80800A2C:
    // 0x80800A2C: jal         0x800FC660
    // 0x80800A30: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_800FC660(rdram, ctx);
        goto after_6;
    // 0x80800A30: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_6:
    // 0x80800A34: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800A38: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800A3C: jal         0x80800BCC
    // 0x80800A40: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80800BCC_chfpsgame(rdram, ctx);
        goto after_7;
    // 0x80800A40: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80800A44: b           L_80800BBC
    // 0x80800A48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BBC;
    // 0x80800A48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A4C:
    // 0x80800A4C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800A50: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A54: jal         0x80800BCC
    // 0x80800A58: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_80800BCC_chfpsgame(rdram, ctx);
        goto after_8;
    // 0x80800A58: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_8:
    // 0x80800A5C: jal         0x800F5410
    // 0x80800A60: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F5410(rdram, ctx);
        goto after_9;
    // 0x80800A60: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x80800A64: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800A68: bne         $v0, $at, L_80800BB8
    if (ctx->r2 != ctx->r1) {
        // 0x80800A6C: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_80800BB8;
    }
    // 0x80800A6C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800A70: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x80800A74: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80800A78: b           L_80800BB8
    // 0x80800A7C: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
        goto L_80800BB8;
    // 0x80800A7C: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
L_80800A80:
    // 0x80800A80: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800A84: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A88: jal         0x80800BCC
    // 0x80800A8C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_80800BCC_chfpsgame(rdram, ctx);
        goto after_10;
    // 0x80800A8C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_10:
    // 0x80800A90: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800A94: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x80800A98: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80800A9C: b           L_80800BB8
    // 0x80800AA0: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
        goto L_80800BB8;
    // 0x80800AA0: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
L_80800AA4:
    // 0x80800AA4: jal         0x80088380
    // 0x80800AA8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    _gcstatusDll_entrypoint_14(rdram, ctx);
        goto after_11;
    // 0x80800AA8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_11:
    // 0x80800AAC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800AB0: bne         $v0, $at, L_80800AD4
    if (ctx->r2 != ctx->r1) {
        // 0x80800AB4: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_80800AD4;
    }
    // 0x80800AB4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800AB8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800ABC: addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    // 0x80800AC0: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800AC4: jal         0x800F7C0C
    // 0x80800AC8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_800F7C0C(rdram, ctx);
        goto after_12;
    // 0x80800AC8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_12:
    // 0x80800ACC: b           L_80800AEC
    // 0x80800AD0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
        goto L_80800AEC;
    // 0x80800AD0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_80800AD4:
    // 0x80800AD4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800AD8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800ADC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800AE0: jal         0x808013DC
    // 0x80800AE4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_808013DC_chfpsgame(rdram, ctx);
        goto after_13;
    // 0x80800AE4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_13:
    // 0x80800AE8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_80800AEC:
    // 0x80800AEC: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80800AF0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800AF4: b           L_80800BB8
    // 0x80800AF8: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
        goto L_80800BB8;
    // 0x80800AF8: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
L_80800AFC:
    // 0x80800AFC: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800B00: addiu       $a0, $v1, 0x14
    ctx->r4 = ADD32(ctx->r3, 0X14);
    // 0x80800B04: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800B08: sra         $a3, $v0, 4
    ctx->r7 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80800B0C: andi        $t8, $a3, 0xF
    ctx->r24 = ctx->r7 & 0XF;
    // 0x80800B10: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80800B14: jal         0x80089990
    // 0x80800B18: andi        $a1, $v0, 0xF
    ctx->r5 = ctx->r2 & 0XF;
    _sumultiscore_entrypoint_5(rdram, ctx);
        goto after_14;
    // 0x80800B18: andi        $a1, $v0, 0xF
    ctx->r5 = ctx->r2 & 0XF;
    after_14:
    // 0x80800B1C: b           L_80800BBC
    // 0x80800B20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BBC;
    // 0x80800B20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B24:
    // 0x80800B24: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800B28: jal         0x8008A3B0
    // 0x80800B2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _suegg_entrypoint_7(rdram, ctx);
        goto after_15;
    // 0x80800B2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_15:
    // 0x80800B30: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800B34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800B38: jal         0x80801D40
    // 0x80800B3C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_80801D40_chfpsgame(rdram, ctx);
        goto after_16;
    // 0x80800B3C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_16:
    // 0x80800B40: b           L_80800BBC
    // 0x80800B44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BBC;
    // 0x80800B44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B48:
    // 0x80800B48: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800B4C: jal         0x8008A3B0
    // 0x80800B50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _suegg_entrypoint_7(rdram, ctx);
        goto after_17;
    // 0x80800B50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_17:
    // 0x80800B54: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800B58: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800B5C: jal         0x80802020
    // 0x80800B60: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_80802020_chfpsgame(rdram, ctx);
        goto after_18;
    // 0x80800B60: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_18:
    // 0x80800B64: b           L_80800BBC
    // 0x80800B68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BBC;
    // 0x80800B68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B6C:
    // 0x80800B6C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800B70: addiu       $a0, $v1, 0x14
    ctx->r4 = ADD32(ctx->r3, 0X14);
    // 0x80800B74: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800B78: sra         $a3, $v0, 16
    ctx->r7 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80800B7C: andi        $t9, $a3, 0xFFFF
    ctx->r25 = ctx->r7 & 0XFFFF;
    // 0x80800B80: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80800B84: jal         0x800899B0
    // 0x80800B88: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    _sumultiscore_entrypoint_9(rdram, ctx);
        goto after_19;
    // 0x80800B88: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_19:
    // 0x80800B8C: b           L_80800BBC
    // 0x80800B90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BBC;
    // 0x80800B90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B94:
    // 0x80800B94: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x80800B98: bne         $t0, $at, L_80800BB8
    if (ctx->r8 != ctx->r1) {
        // 0x80800B9C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800BB8;
    }
    // 0x80800B9C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800BA0: jal         0x80800CF8
    // 0x80800BA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800CF8_chfpsgame(rdram, ctx);
        goto after_20;
    // 0x80800BA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_20:
    // 0x80800BA8: b           L_80800BBC
    // 0x80800BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BBC;
    // 0x80800BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BB0:
    // 0x80800BB0: b           L_80800BBC
    // 0x80800BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BBC;
    // 0x80800BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BB8:
    // 0x80800BB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BBC:
    // 0x80800BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800BC4: jr          $ra
    // 0x80800BC8: nop

    return;
    // 0x80800BC8: nop

;}
RECOMP_FUNC void func_800B36C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B36C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B36C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B36C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B36CC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B36D0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800B36D4: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x800B36D8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800B36DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B36E0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800B36E4: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x800B36E8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B36EC: sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // 0x800B36F0: beq         $at, $zero, L_800B3738
    if (ctx->r1 == 0) {
        // 0x800B36F4: nop
    
            goto L_800B3738;
    }
    // 0x800B36F4: nop

    // 0x800B36F8: jal         0x800EE7F8
    // 0x800B36FC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800B36FC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x800B3700: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B3704: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800B3708: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    // 0x800B370C: jal         0x800EE830
    // 0x800B3710: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE830(rdram, ctx);
        goto after_1;
    // 0x800B3710: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_1:
    // 0x800B3714: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800B3718: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B371C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B3720: lw          $t9, 0x10($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X10);
    // 0x800B3724: swc1        $f4, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f4.u32l;
    // 0x800B3728: lw          $t0, 0x10($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X10);
    // 0x800B372C: addiu       $t1, $t0, 0x1C
    ctx->r9 = ADD32(ctx->r8, 0X1C);
    // 0x800B3730: b           L_800B3738
    // 0x800B3734: sw          $t1, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r9;
        goto L_800B3738;
    // 0x800B3734: sw          $t1, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r9;
L_800B3738:
    // 0x800B3738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B373C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B3740: jr          $ra
    // 0x800B3744: nop

    return;
    // 0x800B3744: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089808: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x80089808);
    return;
    // 0x8008980C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void _bsbflip_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082948: syscall     21
    recomp_syscall_handler(rdram, ctx, 0x80082948);
    return;
    // 0x8008294C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void babee_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C0: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x808002C4: lbu         $t6, 0x1C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1C);
    // 0x808002C8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x808002CC: jr          $ra
    // 0x808002D0: sb          $t7, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r15;
    return;
    // 0x808002D0: sb          $t7, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_800985B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800985B8: lw          $t6, 0xE0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE0);
    // 0x800985BC: jr          $ra
    // 0x800985C0: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
    return;
    // 0x800985C0: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
;}
RECOMP_FUNC void func_808019F4_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808019F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808019FC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A04: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801A08: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801A0C: lui         $at, 0xC343
    ctx->r1 = S32(0XC343 << 16);
    // 0x80801A10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801A14: lwc1        $f0, 0x38($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80801A18: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80801A1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801A20: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801A24: lui         $at, 0x43C3
    ctx->r1 = S32(0X43C3 << 16);
    // 0x80801A28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801A2C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80801A30: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80801A34: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801A38: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80801A3C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80801A40: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80801A44: jal         0x800EFA4C
    // 0x80801A48: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80801A48: nop

    after_0:
    // 0x80801A4C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801A50: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801A54: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80801A58: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80801A5C: jal         0x800EE780
    // 0x80801A60: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800EE780(rdram, ctx);
        goto after_1;
    // 0x80801A60: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80801A64: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80801A68: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x80801A6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801A70: lwc1        $f4, 0x38($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X38);
    // 0x80801A74: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80801A78: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801A7C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801A80: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80801A84: jal         0x800EE780
    // 0x80801A88: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    func_800EE780(rdram, ctx);
        goto after_2;
    // 0x80801A88: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80801A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801A94: jr          $ra
    // 0x80801A98: nop

    return;
    // 0x80801A98: nop

;}
RECOMP_FUNC void _chboxingglove_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085DD0: syscall     241
    recomp_syscall_handler(rdram, ctx, 0x80085DD0);
    return;
    // 0x80085DD4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80094824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009482C: jal         0x80097C7C
    // 0x80094830: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bainput_func_80097C7C(rdram, ctx);
        goto after_0;
    // 0x80094830: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80094834: beq         $v0, $zero, L_8009484C
    if (ctx->r2 == 0) {
        // 0x80094838: nop
    
            goto L_8009484C;
    }
    // 0x80094838: nop

    // 0x8009483C: jal         0x80094A10
    // 0x80094840: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80094A10(rdram, ctx);
        goto after_1;
    // 0x80094840: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80094844: jal         0x80094C88
    // 0x80094848: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80094C88(rdram, ctx);
        goto after_2;
    // 0x80094848: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8009484C:
    // 0x8009484C: jal         0x80094D04
    // 0x80094850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80094D04(rdram, ctx);
        goto after_3;
    // 0x80094850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80094854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009485C: jr          $ra
    // 0x80094860: nop

    return;
    // 0x80094860: nop

;}
RECOMP_FUNC void _chdinoswitches_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FB0: syscall     267
    recomp_syscall_handler(rdram, ctx, 0x80085FB0);
    return;
    // 0x80085FB4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080031C_cheel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080031C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800320: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800324: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800328: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8080032C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800330: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800334: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800338: jal         0x80100094
    // 0x8080033C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080033C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800340: jal         0x800D8FF8
    // 0x80800344: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800344: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_1:
    // 0x80800348: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8080034C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80800350: jal         0x8010262C
    // 0x80800354: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8010262C(rdram, ctx);
        goto after_2;
    // 0x80800354: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x80800358: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8080035C: beq         $v0, $zero, L_808006E4
    if (ctx->r2 == 0) {
        // 0x80800360: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808006E4;
    }
    // 0x80800360: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800364: lw          $t6, 0x64($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X64);
    // 0x80800368: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080036C: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800370: bgezl       $t8, L_808003C0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800374: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_808003C0;
    }
    goto skip_0;
    // 0x80800374: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_0:
    // 0x80800378: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080037C: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80800380: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80800384: nop

    // 0x80800388: bc1f        L_808003B4
    if (!c1cs) {
        // 0x8080038C: nop
    
            goto L_808003B4;
    }
    // 0x8080038C: nop

    // 0x80800390: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80800394: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80800398: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8080039C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x808003A0: nop

    // 0x808003A4: bc1f        L_808003B4
    if (!c1cs) {
        // 0x808003A8: nop
    
            goto L_808003B4;
    }
    // 0x808003A8: nop

    // 0x808003AC: swc1        $f12, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f12.u32l;
    // 0x808003B0: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
L_808003B4:
    // 0x808003B4: b           L_808003FC
    // 0x808003B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
        goto L_808003FC;
    // 0x808003B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003BC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_808003C0:
    // 0x808003C0: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x808003C4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x808003C8: nop

    // 0x808003CC: bc1fl       L_808003FC
    if (!c1cs) {
        // 0x808003D0: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_808003FC;
    }
    goto skip_1;
    // 0x808003D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x808003D4: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x808003D8: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    // 0x808003DC: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x808003E0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x808003E4: nop

    // 0x808003E8: bc1fl       L_808003FC
    if (!c1cs) {
        // 0x808003EC: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_808003FC;
    }
    goto skip_2;
    // 0x808003EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_2:
    // 0x808003F0: swc1        $f14, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f14.u32l;
    // 0x808003F4: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x808003F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_808003FC:
    // 0x808003FC: jal         0x800E0AF0
    // 0x80800400: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    func_800E0AF0(rdram, ctx);
        goto after_3;
    // 0x80800400: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    after_3:
    // 0x80800404: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x80800408: addiu       $s0, $s2, 0x20
    ctx->r16 = ADD32(ctx->r18, 0X20);
L_8080040C:
    // 0x8080040C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800410: jal         0x800F1DCC
    // 0x80800414: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    func_800F1DCC(rdram, ctx);
        goto after_4;
    // 0x80800414: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    after_4:
    // 0x80800418: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080041C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800420: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800424: lwc1        $f12, 0x70($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80800428: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080042C: lwc1        $f14, 0x74($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80800430: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80800434: jal         0x800F1DCC
    // 0x80800438: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_5;
    // 0x80800438: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    after_5:
    // 0x8080043C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800440: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800444: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80800448: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8080044C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800450: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // 0x80800454: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80800458: bgez        $s1, L_8080040C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8080045C: swc1        $f8, 0x78($s0)
        MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
            goto L_8080040C;
    }
    // 0x8080045C: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
    // 0x80800460: jal         0x800136E4
    // 0x80800464: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x80800464: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    after_6:
    // 0x80800468: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    // 0x8080046C: lwc1        $f12, 0x48($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X48);
    // 0x80800470: jal         0x800F1DCC
    // 0x80800474: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_7;
    // 0x80800474: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_7:
    // 0x80800478: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080047C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800480: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80800484: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800488: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8080048C: swc1        $f4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f4.u32l;
    // 0x80800490: lwc1        $f14, 0x48($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X48);
    // 0x80800494: jal         0x800F1DCC
    // 0x80800498: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    func_800F1DCC(rdram, ctx);
        goto after_8;
    // 0x80800498: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    after_8:
    // 0x8080049C: swc1        $f0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f0.u32l;
    // 0x808004A0: jal         0x800136E4
    // 0x808004A4: lwc1        $f12, 0x70($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X70);
    func_800136E4(rdram, ctx);
        goto after_9;
    // 0x808004A4: lwc1        $f12, 0x70($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X70);
    after_9:
    // 0x808004A8: swc1        $f0, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f0.u32l;
    // 0x808004AC: lwc1        $f12, 0x44($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X44);
    // 0x808004B0: jal         0x800F1DCC
    // 0x808004B4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_10;
    // 0x808004B4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_10:
    // 0x808004B8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808004BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004C0: lwc1        $f10, 0x70($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X70);
    // 0x808004C4: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808004C8: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x808004CC: swc1        $f16, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f16.u32l;
    // 0x808004D0: lwc1        $f14, 0x44($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X44);
    // 0x808004D4: jal         0x800F1DCC
    // 0x808004D8: lwc1        $f12, 0x70($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X70);
    func_800F1DCC(rdram, ctx);
        goto after_11;
    // 0x808004D8: lwc1        $f12, 0x70($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X70);
    after_11:
    // 0x808004DC: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x808004E0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x808004E4: swc1        $f6, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->f6.u32l;
    // 0x808004E8: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
L_808004EC:
    // 0x808004EC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808004F0: jal         0x800F1DCC
    // 0x808004F4: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    func_800F1DCC(rdram, ctx);
        goto after_12;
    // 0x808004F4: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    after_12:
    // 0x808004F8: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x808004FC: lwc1        $f12, 0x70($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80800500: jal         0x800F1DCC
    // 0x80800504: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    func_800F1DCC(rdram, ctx);
        goto after_13;
    // 0x80800504: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    after_13:
    // 0x80800508: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080050C: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80800510: slti        $at, $s1, 0x9
    ctx->r1 = SIGNED(ctx->r17) < 0X9 ? 1 : 0;
    // 0x80800514: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800518: bne         $at, $zero, L_808004EC
    if (ctx->r1 != 0) {
        // 0x8080051C: swc1        $f4, 0x90($s0)
        MEM_W(0X90, ctx->r16) = ctx->f4.u32l;
            goto L_808004EC;
    }
    // 0x8080051C: swc1        $f4, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f4.u32l;
    // 0x80800520: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800524: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80800528:
    // 0x80800528: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080052C: jal         0x800F1DCC
    // 0x80800530: lwc1        $f14, 0x4C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4C);
    func_800F1DCC(rdram, ctx);
        goto after_14;
    // 0x80800530: lwc1        $f14, 0x4C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4C);
    after_14:
    // 0x80800534: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800538: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080053C: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800540: lwc1        $f12, 0x94($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80800544: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800548: lwc1        $f14, 0xB8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x8080054C: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80800550: jal         0x800F1DCC
    // 0x80800554: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_15;
    // 0x80800554: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    after_15:
    // 0x80800558: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080055C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800560: lwc1        $f6, 0xB8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB8);
    // 0x80800564: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800568: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080056C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800570: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800574: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800578: bne         $s1, $at, L_80800528
    if (ctx->r17 != ctx->r1) {
        // 0x8080057C: swc1        $f8, 0xB4($s0)
        MEM_W(0XB4, ctx->r16) = ctx->f8.u32l;
            goto L_80800528;
    }
    // 0x8080057C: swc1        $f8, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->f8.u32l;
    // 0x80800580: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800584: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800588: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080058C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800590: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80800594: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800598: jal         0x800E0AFC
    // 0x8080059C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_16;
    // 0x8080059C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x808005A0: lwc1        $f18, 0x4C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x808005A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808005A8: lw          $a3, 0xB8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XB8);
    // 0x808005AC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808005B0: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x808005B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808005B8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x808005BC: jal         0x800E0AFC
    // 0x808005C0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_17;
    // 0x808005C0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_17:
    // 0x808005C4: lwc1        $f4, 0x50($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X50);
    // 0x808005C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808005CC: lw          $a3, 0xBC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XBC);
    // 0x808005D0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808005D4: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x808005D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808005DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808005E0: jal         0x800E0AFC
    // 0x808005E4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_18;
    // 0x808005E4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_18:
    // 0x808005E8: lwc1        $f10, 0x54($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X54);
    // 0x808005EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808005F0: lw          $a3, 0xC0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XC0);
    // 0x808005F4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808005F8: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x808005FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800600: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800604: jal         0x800E0AFC
    // 0x80800608: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_19;
    // 0x80800608: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_19:
    // 0x8080060C: lwc1        $f18, 0x58($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X58);
    // 0x80800610: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800614: lw          $a3, 0xC4($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XC4);
    // 0x80800618: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8080061C: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80800620: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800624: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80800628: jal         0x800E0AFC
    // 0x8080062C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_20;
    // 0x8080062C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_20:
    // 0x80800630: lwc1        $f4, 0x5C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X5C);
    // 0x80800634: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800638: lw          $a3, 0xC8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XC8);
    // 0x8080063C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800640: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x80800644: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800648: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8080064C: jal         0x800E0AFC
    // 0x80800650: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_21;
    // 0x80800650: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_21:
    // 0x80800654: lwc1        $f10, 0x60($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X60);
    // 0x80800658: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080065C: lw          $a3, 0xCC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XCC);
    // 0x80800660: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800664: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x80800668: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080066C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800670: jal         0x800E0AFC
    // 0x80800674: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_22;
    // 0x80800674: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_22:
    // 0x80800678: lwc1        $f18, 0x64($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X64);
    // 0x8080067C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800680: lw          $a3, 0xD0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XD0);
    // 0x80800684: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800688: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8080068C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800690: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80800694: jal         0x800E0AFC
    // 0x80800698: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_23;
    // 0x80800698: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_23:
    // 0x8080069C: lwc1        $f4, 0x68($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X68);
    // 0x808006A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808006A4: lw          $a3, 0xD4($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XD4);
    // 0x808006A8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808006AC: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x808006B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808006B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808006B8: jal         0x800E0AFC
    // 0x808006BC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_24;
    // 0x808006BC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_24:
    // 0x808006C0: lwc1        $f10, 0x6C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X6C);
    // 0x808006C4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808006C8: lw          $a3, 0xD8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XD8);
    // 0x808006CC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808006D0: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x808006D4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808006D8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x808006DC: jal         0x800E0AFC
    // 0x808006E0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_25;
    // 0x808006E0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_25:
L_808006E4:
    // 0x808006E4: lhu         $t9, 0x72($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X72);
    // 0x808006E8: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x808006EC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x808006F0: sltiu       $at, $t1, 0x9
    ctx->r1 = ctx->r9 < 0X9 ? 1 : 0;
    // 0x808006F4: beq         $at, $zero, L_80800D44
    if (ctx->r1 == 0) {
        // 0x808006F8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80800D44;
    }
    // 0x808006F8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808006FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1792, 0X14F0) << 16);
    // 0x80800700: addu        $at, $at, $t1
    gpr jr_addend_80800708 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80800704: lw          $t1, 0x14F0($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1792, 0X14F0));
    // 0x80800708: jr          $t1
    // 0x8080070C: nop

    switch (jr_addend_80800708 >> 2) {
        case 0: goto L_80800710; break;
        case 1: goto L_808007FC; break;
        case 2: goto L_808008AC; break;
        case 3: goto L_808009F0; break;
        case 4: goto L_80800AA0; break;
        case 5: goto L_80800B54; break;
        case 6: goto L_80800C1C; break;
        case 7: goto L_80800CFC; break;
        case 8: goto L_80800D1C; break;
        default: switch_error(__func__, 0x80800708, 0x808014F0);
    }
    // 0x8080070C: nop

L_80800710:
    // 0x80800710: jal         0x80800168
    // 0x80800714: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800168_cheel(rdram, ctx);
        goto after_26;
    // 0x80800714: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_26:
    // 0x80800718: jal         0x8080020C
    // 0x8080071C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8080020C_cheel(rdram, ctx);
        goto after_27;
    // 0x8080071C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_27:
    // 0x80800720: bne         $v0, $zero, L_80800738
    if (ctx->r2 != 0) {
        // 0x80800724: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800738;
    }
    // 0x80800724: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800728: jal         0x80801200
    // 0x8080072C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801200_cheel(rdram, ctx);
        goto after_28;
    // 0x8080072C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_28:
    // 0x80800730: b           L_80800794
    // 0x80800734: nop

        goto L_80800794;
    // 0x80800734: nop

L_80800738:
    // 0x80800738: jal         0x8010C500
    // 0x8080073C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8010C500(rdram, ctx);
        goto after_29;
    // 0x8080073C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_29:
    // 0x80800740: beq         $v0, $zero, L_8080075C
    if (ctx->r2 == 0) {
        // 0x80800744: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_8080075C;
    }
    // 0x80800744: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800748: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080074C: jal         0x80801200
    // 0x80800750: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801200_cheel(rdram, ctx);
        goto after_30;
    // 0x80800750: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_30:
    // 0x80800754: b           L_80800794
    // 0x80800758: nop

        goto L_80800794;
    // 0x80800758: nop

L_8080075C:
    // 0x8080075C: lwc1        $f2, 0x38($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X38);
    // 0x80800760: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800764: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80800768: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080076C: mul.s       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80800770: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800774: nop

    // 0x80800778: bc1f        L_80800794
    if (!c1cs) {
        // 0x8080077C: nop
    
            goto L_80800794;
    }
    // 0x8080077C: nop

    // 0x80800780: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800784: nop

    // 0x80800788: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8080078C: sub.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80800790: swc1        $f10, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f10.u32l;
L_80800794:
    // 0x80800794: jal         0x80800D60
    // 0x80800798: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800D60_cheel(rdram, ctx);
        goto after_31;
    // 0x80800798: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_31:
    // 0x8080079C: lw          $t2, 0x64($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X64);
    // 0x808007A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808007A4: addiu       $a1, $s3, 0x54
    ctx->r5 = ADD32(ctx->r19, 0X54);
    // 0x808007A8: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x808007AC: bgezl       $t4, L_80800D48
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808007B0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800D48;
    }
    goto skip_3;
    // 0x808007B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x808007B4: jal         0x80089BF0
    // 0x808007B8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_32;
    // 0x808007B8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_32:
    // 0x808007BC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808007C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808007C4: lwc1        $f2, 0x38($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X38);
    // 0x808007C8: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808007CC: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808007D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007D4: mul.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x808007D8: nop

    // 0x808007DC: mul.s       $f14, $f16, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x808007E0: swc1        $f12, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f12.u32l;
    // 0x808007E4: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x808007E8: nop

    // 0x808007EC: bc1f        L_80800D44
    if (!c1cs) {
        // 0x808007F0: nop
    
            goto L_80800D44;
    }
    // 0x808007F0: nop

    // 0x808007F4: b           L_80800D44
    // 0x808007F8: swc1        $f14, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f14.u32l;
        goto L_80800D44;
    // 0x808007F8: swc1        $f14, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f14.u32l;
L_808007FC:
    // 0x808007FC: jal         0x80801120
    // 0x80800800: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80801120_cheel(rdram, ctx);
        goto after_33;
    // 0x80800800: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_33:
    // 0x80800804: addiu       $s0, $s3, 0x4
    ctx->r16 = ADD32(ctx->r19, 0X4);
    // 0x80800808: addiu       $s1, $s3, 0x18
    ctx->r17 = ADD32(ctx->r19, 0X18);
    // 0x8080080C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800810: jal         0x800F1DF4
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_34;
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800818: swc1        $f0, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f0.u32l;
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800820: jal         0x800F1828
    // 0x80800824: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F1828(rdram, ctx);
        goto after_35;
    // 0x80800824: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_35:
    // 0x80800828: swc1        $f0, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f0.u32l;
    // 0x8080082C: jal         0x80800168
    // 0x80800830: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800168_cheel(rdram, ctx);
        goto after_36;
    // 0x80800830: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_36:
    // 0x80800834: jal         0x808002A0
    // 0x80800838: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808002A0_cheel(rdram, ctx);
        goto after_37;
    // 0x80800838: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_37:
    // 0x8080083C: beq         $v0, $zero, L_80800864
    if (ctx->r2 == 0) {
        // 0x80800840: lui         $at, 0x4448
        ctx->r1 = S32(0X4448 << 16);
            goto L_80800864;
    }
    // 0x80800840: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800844: jal         0x8080020C
    // 0x80800848: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8080020C_cheel(rdram, ctx);
        goto after_38;
    // 0x80800848: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_38:
    // 0x8080084C: beq         $v0, $zero, L_8080089C
    if (ctx->r2 == 0) {
        // 0x80800850: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8080089C;
    }
    // 0x80800850: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800854: jal         0x80801200
    // 0x80800858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801200_cheel(rdram, ctx);
        goto after_39;
    // 0x80800858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_39:
    // 0x8080085C: b           L_8080089C
    // 0x80800860: nop

        goto L_8080089C;
    // 0x80800860: nop

L_80800864:
    // 0x80800864: lwc1        $f2, 0x38($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X38);
    // 0x80800868: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080086C: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80800870: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800874: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80800878: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8080087C: nop

    // 0x80800880: bc1f        L_8080089C
    if (!c1cs) {
        // 0x80800884: nop
    
            goto L_8080089C;
    }
    // 0x80800884: nop

    // 0x80800888: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080088C: nop

    // 0x80800890: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80800894: sub.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80800898: swc1        $f18, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f18.u32l;
L_8080089C:
    // 0x8080089C: jal         0x80800D60
    // 0x808008A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800D60_cheel(rdram, ctx);
        goto after_40;
    // 0x808008A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_40:
    // 0x808008A4: b           L_80800D48
    // 0x808008A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800D48;
    // 0x808008A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808008AC:
    // 0x808008AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808008B0: jal         0x8010CE28
    // 0x808008B4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_8010CE28(rdram, ctx);
        goto after_41;
    // 0x808008B4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_41:
    // 0x808008B8: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808008BC: lw          $t5, 0x64($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X64);
    // 0x808008C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808008C4: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x808008C8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x808008CC: bgez        $t7, L_80800920
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808008D0: swc1        $f4, 0x50($s3)
        MEM_W(0X50, ctx->r19) = ctx->f4.u32l;
            goto L_80800920;
    }
    // 0x808008D0: swc1        $f4, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f4.u32l;
    // 0x808008D4: addiu       $a1, $s3, 0x54
    ctx->r5 = ADD32(ctx->r19, 0X54);
    // 0x808008D8: jal         0x80089BF0
    // 0x808008DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_42;
    // 0x808008DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_42:
    // 0x808008E0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808008E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008E8: lwc1        $f2, 0x38($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X38);
    // 0x808008EC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808008F0: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808008F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808008F8: mul.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x808008FC: nop

    // 0x80800900: mul.s       $f14, $f8, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80800904: swc1        $f12, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f12.u32l;
    // 0x80800908: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8080090C: nop

    // 0x80800910: bc1f        L_8080095C
    if (!c1cs) {
        // 0x80800914: nop
    
            goto L_8080095C;
    }
    // 0x80800914: nop

    // 0x80800918: b           L_8080095C
    // 0x8080091C: swc1        $f14, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f14.u32l;
        goto L_8080095C;
    // 0x8080091C: swc1        $f14, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f14.u32l;
L_80800920:
    // 0x80800920: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800924: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1792, 0X1514) << 16);
    // 0x80800928: swc1        $f18, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f18.u32l;
    // 0x8080092C: jal         0x800DC298
    // 0x80800930: lwc1        $f12, 0x1514($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1792, 0X1514));
    func_800DC298(rdram, ctx);
        goto after_43;
    // 0x80800930: lwc1        $f12, 0x1514($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1792, 0X1514));
    after_43:
    // 0x80800934: beq         $v0, $zero, L_8080095C
    if (ctx->r2 == 0) {
        // 0x80800938: lui         $at, 0xC2B4
        ctx->r1 = S32(0XC2B4 << 16);
            goto L_8080095C;
    }
    // 0x80800938: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8080093C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800940: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800944: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800948: jal         0x800DC178
    // 0x8080094C: nop

    func_800DC178(rdram, ctx);
        goto after_44;
    // 0x8080094C: nop

    after_44:
    // 0x80800950: lwc1        $f16, 0x54($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X54);
    // 0x80800954: add.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80800958: swc1        $f4, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f4.u32l;
L_8080095C:
    // 0x8080095C: jal         0x80800168
    // 0x80800960: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800168_cheel(rdram, ctx);
        goto after_45;
    // 0x80800960: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_45:
    // 0x80800964: jal         0x8010C500
    // 0x80800968: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8010C500(rdram, ctx);
        goto after_46;
    // 0x80800968: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_46:
    // 0x8080096C: bne         $v0, $zero, L_80800984
    if (ctx->r2 != 0) {
        // 0x80800970: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800984;
    }
    // 0x80800970: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800974: jal         0x80801200
    // 0x80800978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801200_cheel(rdram, ctx);
        goto after_47;
    // 0x80800978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_47:
    // 0x8080097C: b           L_808009E0
    // 0x80800980: nop

        goto L_808009E0;
    // 0x80800980: nop

L_80800984:
    // 0x80800984: jal         0x8080020C
    // 0x80800988: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8080020C_cheel(rdram, ctx);
        goto after_48;
    // 0x80800988: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_48:
    // 0x8080098C: bne         $v0, $zero, L_808009A8
    if (ctx->r2 != 0) {
        // 0x80800990: lui         $at, 0x44C8
        ctx->r1 = S32(0X44C8 << 16);
            goto L_808009A8;
    }
    // 0x80800990: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x80800994: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800998: jal         0x80801200
    // 0x8080099C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80801200_cheel(rdram, ctx);
        goto after_49;
    // 0x8080099C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_49:
    // 0x808009A0: b           L_808009E0
    // 0x808009A4: nop

        goto L_808009E0;
    // 0x808009A4: nop

L_808009A8:
    // 0x808009A8: lwc1        $f2, 0x38($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X38);
    // 0x808009AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808009B0: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x808009B4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808009B8: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808009BC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808009C0: nop

    // 0x808009C4: bc1f        L_808009E0
    if (!c1cs) {
        // 0x808009C8: nop
    
            goto L_808009E0;
    }
    // 0x808009C8: nop

    // 0x808009CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808009D0: nop

    // 0x808009D4: mul.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x808009D8: add.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x808009DC: swc1        $f16, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f16.u32l;
L_808009E0:
    // 0x808009E0: jal         0x80800D60
    // 0x808009E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800D60_cheel(rdram, ctx);
        goto after_50;
    // 0x808009E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_50:
    // 0x808009E8: b           L_80800D48
    // 0x808009EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800D48;
    // 0x808009EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808009F0:
    // 0x808009F0: jal         0x80801120
    // 0x808009F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80801120_cheel(rdram, ctx);
        goto after_51;
    // 0x808009F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_51:
    // 0x808009F8: addiu       $s0, $s3, 0x4
    ctx->r16 = ADD32(ctx->r19, 0X4);
    // 0x808009FC: addiu       $s1, $s3, 0x18
    ctx->r17 = ADD32(ctx->r19, 0X18);
    // 0x80800A00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800A04: jal         0x800F1DF4
    // 0x80800A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_52;
    // 0x80800A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x80800A0C: swc1        $f0, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f0.u32l;
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A14: jal         0x800F1828
    // 0x80800A18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F1828(rdram, ctx);
        goto after_53;
    // 0x80800A18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_53:
    // 0x80800A1C: swc1        $f0, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f0.u32l;
    // 0x80800A20: jal         0x80800168
    // 0x80800A24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800168_cheel(rdram, ctx);
        goto after_54;
    // 0x80800A24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_54:
    // 0x80800A28: jal         0x808002A0
    // 0x80800A2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808002A0_cheel(rdram, ctx);
        goto after_55;
    // 0x80800A2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_55:
    // 0x80800A30: beq         $v0, $zero, L_80800A58
    if (ctx->r2 == 0) {
        // 0x80800A34: lui         $at, 0x4448
        ctx->r1 = S32(0X4448 << 16);
            goto L_80800A58;
    }
    // 0x80800A34: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800A38: jal         0x8080020C
    // 0x80800A3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8080020C_cheel(rdram, ctx);
        goto after_56;
    // 0x80800A3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_56:
    // 0x80800A40: beq         $v0, $zero, L_80800A90
    if (ctx->r2 == 0) {
        // 0x80800A44: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800A90;
    }
    // 0x80800A44: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800A48: jal         0x80801200
    // 0x80800A4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801200_cheel(rdram, ctx);
        goto after_57;
    // 0x80800A4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_57:
    // 0x80800A50: b           L_80800A90
    // 0x80800A54: nop

        goto L_80800A90;
    // 0x80800A54: nop

L_80800A58:
    // 0x80800A58: lwc1        $f2, 0x38($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X38);
    // 0x80800A5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A60: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80800A64: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800A68: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80800A6C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800A70: nop

    // 0x80800A74: bc1f        L_80800A90
    if (!c1cs) {
        // 0x80800A78: nop
    
            goto L_80800A90;
    }
    // 0x80800A78: nop

    // 0x80800A7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800A80: nop

    // 0x80800A84: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80800A88: sub.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80800A8C: swc1        $f18, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f18.u32l;
L_80800A90:
    // 0x80800A90: jal         0x80800D60
    // 0x80800A94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800D60_cheel(rdram, ctx);
        goto after_58;
    // 0x80800A94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_58:
    // 0x80800A98: b           L_80800D48
    // 0x80800A9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800D48;
    // 0x80800A9C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800AA0:
    // 0x80800AA0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800AA4: jal         0x8010CE28
    // 0x80800AA8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_8010CE28(rdram, ctx);
        goto after_59;
    // 0x80800AA8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_59:
    // 0x80800AAC: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800AB0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800AB4: swc1        $f16, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f16.u32l;
    // 0x80800AB8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800ABC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800AC0: jal         0x80800168
    // 0x80800AC4: swc1        $f6, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f6.u32l;
    func_80800168_cheel(rdram, ctx);
        goto after_60;
    // 0x80800AC4: swc1        $f6, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f6.u32l;
    after_60:
    // 0x80800AC8: jal         0x8010C500
    // 0x80800ACC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8010C500(rdram, ctx);
        goto after_61;
    // 0x80800ACC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_61:
    // 0x80800AD0: bne         $v0, $zero, L_80800AE8
    if (ctx->r2 != 0) {
        // 0x80800AD4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800AE8;
    }
    // 0x80800AD4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800AD8: jal         0x80801200
    // 0x80800ADC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801200_cheel(rdram, ctx);
        goto after_62;
    // 0x80800ADC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_62:
    // 0x80800AE0: b           L_80800B44
    // 0x80800AE4: nop

        goto L_80800B44;
    // 0x80800AE4: nop

L_80800AE8:
    // 0x80800AE8: jal         0x8080020C
    // 0x80800AEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8080020C_cheel(rdram, ctx);
        goto after_63;
    // 0x80800AEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_63:
    // 0x80800AF0: bne         $v0, $zero, L_80800B0C
    if (ctx->r2 != 0) {
        // 0x80800AF4: lui         $at, 0x44C8
        ctx->r1 = S32(0X44C8 << 16);
            goto L_80800B0C;
    }
    // 0x80800AF4: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x80800AF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800AFC: jal         0x80801200
    // 0x80800B00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801200_cheel(rdram, ctx);
        goto after_64;
    // 0x80800B00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_64:
    // 0x80800B04: b           L_80800B44
    // 0x80800B08: nop

        goto L_80800B44;
    // 0x80800B08: nop

L_80800B0C:
    // 0x80800B0C: lwc1        $f2, 0x38($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X38);
    // 0x80800B10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800B14: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80800B18: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800B1C: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80800B20: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800B24: nop

    // 0x80800B28: bc1f        L_80800B44
    if (!c1cs) {
        // 0x80800B2C: nop
    
            goto L_80800B44;
    }
    // 0x80800B2C: nop

    // 0x80800B30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800B34: nop

    // 0x80800B38: mul.s       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80800B3C: add.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800B40: swc1        $f4, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f4.u32l;
L_80800B44:
    // 0x80800B44: jal         0x80800D60
    // 0x80800B48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800D60_cheel(rdram, ctx);
        goto after_65;
    // 0x80800B48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_65:
    // 0x80800B4C: b           L_80800D48
    // 0x80800B50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800D48;
    // 0x80800B50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800B54:
    // 0x80800B54: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800B58: jal         0x8010CE28
    // 0x80800B5C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8010CE28(rdram, ctx);
        goto after_66;
    // 0x80800B5C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_66:
    // 0x80800B60: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800B64: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800B68: swc1        $f6, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f6.u32l;
    // 0x80800B6C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800B70: neg.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = -ctx->f10.fl;
    // 0x80800B74: jal         0x80800168
    // 0x80800B78: swc1        $f8, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f8.u32l;
    func_80800168_cheel(rdram, ctx);
        goto after_67;
    // 0x80800B78: swc1        $f8, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f8.u32l;
    after_67:
    // 0x80800B7C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800B80: lwc1        $f16, 0x58($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X58);
    // 0x80800B84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800B88: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80800B8C: nop

    // 0x80800B90: bc1f        L_80800C0C
    if (!c1cs) {
        // 0x80800B94: nop
    
            goto L_80800C0C;
    }
    // 0x80800B94: nop

    // 0x80800B98: jal         0x800D8FF8
    // 0x80800B9C: nop

    func_800D8FF8(rdram, ctx);
        goto after_68;
    // 0x80800B9C: nop

    after_68:
    // 0x80800BA0: lwc1        $f4, 0x58($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X58);
    // 0x80800BA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800BA8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800BAC: jal         0x8080020C
    // 0x80800BB0: swc1        $f6, 0x58($s3)
    MEM_W(0X58, ctx->r19) = ctx->f6.u32l;
    func_8080020C_cheel(rdram, ctx);
        goto after_69;
    // 0x80800BB0: swc1        $f6, 0x58($s3)
    MEM_W(0X58, ctx->r19) = ctx->f6.u32l;
    after_69:
    // 0x80800BB4: bne         $v0, $zero, L_80800BD0
    if (ctx->r2 != 0) {
        // 0x80800BB8: lui         $at, 0x44C8
        ctx->r1 = S32(0X44C8 << 16);
            goto L_80800BD0;
    }
    // 0x80800BB8: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x80800BBC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800BC0: jal         0x80801200
    // 0x80800BC4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80801200_cheel(rdram, ctx);
        goto after_70;
    // 0x80800BC4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_70:
    // 0x80800BC8: b           L_80800D48
    // 0x80800BCC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800D48;
    // 0x80800BCC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800BD0:
    // 0x80800BD0: lwc1        $f2, 0x38($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X38);
    // 0x80800BD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800BD8: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80800BDC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800BE0: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80800BE4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800BE8: nop

    // 0x80800BEC: bc1fl       L_80800D48
    if (!c1cs) {
        // 0x80800BF0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800D48;
    }
    goto skip_4;
    // 0x80800BF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x80800BF4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800BF8: nop

    // 0x80800BFC: mul.s       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80800C00: add.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800C04: b           L_80800D44
    // 0x80800C08: swc1        $f4, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f4.u32l;
        goto L_80800D44;
    // 0x80800C08: swc1        $f4, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f4.u32l;
L_80800C0C:
    // 0x80800C0C: jal         0x80801200
    // 0x80800C10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801200_cheel(rdram, ctx);
        goto after_71;
    // 0x80800C10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_71:
    // 0x80800C14: b           L_80800D48
    // 0x80800C18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800D48;
    // 0x80800C18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800C1C:
    // 0x80800C1C: jal         0x80801120
    // 0x80800C20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80801120_cheel(rdram, ctx);
        goto after_72;
    // 0x80800C20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_72:
    // 0x80800C24: addiu       $s0, $s3, 0x4
    ctx->r16 = ADD32(ctx->r19, 0X4);
    // 0x80800C28: addiu       $s1, $s3, 0x18
    ctx->r17 = ADD32(ctx->r19, 0X18);
    // 0x80800C2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800C30: jal         0x800F1DF4
    // 0x80800C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_73;
    // 0x80800C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_73:
    // 0x80800C38: swc1        $f0, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f0.u32l;
    // 0x80800C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C40: jal         0x800F1828
    // 0x80800C44: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F1828(rdram, ctx);
        goto after_74;
    // 0x80800C44: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_74:
    // 0x80800C48: swc1        $f0, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f0.u32l;
    // 0x80800C4C: jal         0x80800168
    // 0x80800C50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800168_cheel(rdram, ctx);
        goto after_75;
    // 0x80800C50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_75:
    // 0x80800C54: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800C58: lwc1        $f10, 0x58($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X58);
    // 0x80800C5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800C60: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80800C64: nop

    // 0x80800C68: bc1f        L_80800C88
    if (!c1cs) {
        // 0x80800C6C: nop
    
            goto L_80800C88;
    }
    // 0x80800C6C: nop

    // 0x80800C70: jal         0x800D8FF8
    // 0x80800C74: nop

    func_800D8FF8(rdram, ctx);
        goto after_76;
    // 0x80800C74: nop

    after_76:
    // 0x80800C78: lwc1        $f8, 0x58($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X58);
    // 0x80800C7C: sub.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800C80: b           L_80800C90
    // 0x80800C84: swc1        $f18, 0x58($s3)
    MEM_W(0X58, ctx->r19) = ctx->f18.u32l;
        goto L_80800C90;
    // 0x80800C84: swc1        $f18, 0x58($s3)
    MEM_W(0X58, ctx->r19) = ctx->f18.u32l;
L_80800C88:
    // 0x80800C88: jal         0x80801200
    // 0x80800C8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801200_cheel(rdram, ctx);
        goto after_77;
    // 0x80800C8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_77:
L_80800C90:
    // 0x80800C90: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800C94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800C98: lwc1        $f2, 0x38($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X38);
    // 0x80800C9C: lwc1        $f0, 0x24($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X24);
    // 0x80800CA0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800CA4: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80800CA8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800CAC: nop

    // 0x80800CB0: bc1f        L_80800CCC
    if (!c1cs) {
        // 0x80800CB4: nop
    
            goto L_80800CCC;
    }
    // 0x80800CB4: nop

    // 0x80800CB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800CBC: nop

    // 0x80800CC0: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80800CC4: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80800CC8: swc1        $f8, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f8.u32l;
L_80800CCC:
    // 0x80800CCC: jal         0x808002A0
    // 0x80800CD0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808002A0_cheel(rdram, ctx);
        goto after_78;
    // 0x80800CD0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_78:
    // 0x80800CD4: beql        $v0, $zero, L_80800D48
    if (ctx->r2 == 0) {
        // 0x80800CD8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800D48;
    }
    goto skip_5;
    // 0x80800CD8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x80800CDC: jal         0x8080020C
    // 0x80800CE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8080020C_cheel(rdram, ctx);
        goto after_79;
    // 0x80800CE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_79:
    // 0x80800CE4: beq         $v0, $zero, L_80800D44
    if (ctx->r2 == 0) {
        // 0x80800CE8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800D44;
    }
    // 0x80800CE8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800CEC: jal         0x80801200
    // 0x80800CF0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80801200_cheel(rdram, ctx);
        goto after_80;
    // 0x80800CF0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_80:
    // 0x80800CF4: b           L_80800D48
    // 0x80800CF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800D48;
    // 0x80800CF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800CFC:
    // 0x80800CFC: jal         0x80101DDC
    // 0x80800D00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80101DDC(rdram, ctx);
        goto after_81;
    // 0x80800D00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_81:
    // 0x80800D04: beq         $v0, $zero, L_80800D44
    if (ctx->r2 == 0) {
        // 0x80800D08: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800D44;
    }
    // 0x80800D08: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800D0C: jal         0x80801200
    // 0x80800D10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801200_cheel(rdram, ctx);
        goto after_82;
    // 0x80800D10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_82:
    // 0x80800D14: b           L_80800D48
    // 0x80800D18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800D48;
    // 0x80800D18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800D1C:
    // 0x80800D1C: jal         0x80101DDC
    // 0x80800D20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80101DDC(rdram, ctx);
        goto after_83;
    // 0x80800D20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_83:
    // 0x80800D24: beq         $v0, $zero, L_80800D44
    if (ctx->r2 == 0) {
        // 0x80800D28: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800D44;
    }
    // 0x80800D28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800D2C: jal         0x80107070
    // 0x80800D30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80107070(rdram, ctx);
        goto after_84;
    // 0x80800D30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_84:
    // 0x80800D34: bnel        $v0, $zero, L_80800D48
    if (ctx->r2 != 0) {
        // 0x80800D38: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800D48;
    }
    goto skip_6;
    // 0x80800D38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_6:
    // 0x80800D3C: jal         0x800FFAB0
    // 0x80800D40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_85;
    // 0x80800D40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_85:
L_80800D44:
    // 0x80800D44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800D48:
    // 0x80800D48: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D4C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800D50: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800D54: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800D58: jr          $ra
    // 0x80800D5C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800D5C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80800A44_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A44: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800A48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A4C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800A50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A54: beq         $a1, $zero, L_80800A70
    if (ctx->r5 == 0) {
        // 0x80800A58: sw          $a0, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r4;
            goto L_80800A70;
    }
    // 0x80800A58: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80800A5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A60: beq         $a1, $at, L_80800A70
    if (ctx->r5 == ctx->r1) {
        // 0x80800A64: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A70;
    }
    // 0x80800A64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A68: bnel        $a1, $at, L_80800BB8
    if (ctx->r5 != ctx->r1) {
        // 0x80800A6C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800BB8;
    }
    goto skip_0;
    // 0x80800A6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_80800A70:
    // 0x80800A70: jal         0x800D3948
    // 0x80800A74: nop

    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x80800A74: nop

    after_0:
    // 0x80800A78: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800A7C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800A80: jal         0x80100094
    // 0x80800A84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800A84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800A88: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800A8C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800A90: jal         0x8008A2B0
    // 0x80800A94: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800A94: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    after_2:
    // 0x80800A98: beq         $v0, $zero, L_80800AB8
    if (ctx->r2 == 0) {
        // 0x80800A9C: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_80800AB8;
    }
    // 0x80800A9C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80800AA0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80800AA4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800AA8: jal         0x800EE7F8
    // 0x80800AAC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800AAC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x80800AB0: b           L_80800AD0
    // 0x80800AB4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
        goto L_80800AD0;
    // 0x80800AB4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_80800AB8:
    // 0x80800AB8: lw          $a0, 0x70($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X70);
    // 0x80800ABC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800AC0: srl         $t7, $a0, 25
    ctx->r15 = S32(U32(ctx->r4) >> 25);
    // 0x80800AC4: jal         0x800CD08C
    // 0x80800AC8: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    func_800CD08C(rdram, ctx);
        goto after_4;
    // 0x80800AC8: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    after_4:
    // 0x80800ACC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_80800AD0:
    // 0x80800AD0: addiu       $t9, $sp, 0x3C
    ctx->r25 = ADD32(ctx->r29, 0X3C);
    // 0x80800AD4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800AD8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800ADC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800AE0: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80800AE4: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    // 0x80800AE8: jal         0x80105138
    // 0x80800AEC: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    func_80105138(rdram, ctx);
        goto after_5;
    // 0x80800AEC: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80800AF0: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800AF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800AF8: addiu       $a1, $zero, 0x167
    ctx->r5 = ADD32(0, 0X167);
    // 0x80800AFC: jal         0x800DC128
    // 0x80800B00: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    func_800DC128(rdram, ctx);
        goto after_6;
    // 0x80800B00: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x80800B04: addiu       $a0, $s0, 0x452
    ctx->r4 = ADD32(ctx->r16, 0X452);
    // 0x80800B08: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800B0C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800B10: jal         0x80108528
    // 0x80800B14: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    func_80108528(rdram, ctx);
        goto after_7;
    // 0x80800B14: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_7:
    // 0x80800B18: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80800B1C: lbu         $t6, 0x65($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X65);
    // 0x80800B20: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80800B24: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800B28: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x80800B2C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80800B30: sw          $s0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r16;
    // 0x80800B34: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80800B38: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80800B3C: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80800B40: sb          $t8, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r24;
    // 0x80800B44: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80800B48: lhu         $t3, 0x6E($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X6E);
    // 0x80800B4C: lw          $t1, 0x6C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X6C);
    // 0x80800B50: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x80800B54: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x80800B58: or          $t6, $t2, $t4
    ctx->r14 = ctx->r10 | ctx->r12;
    // 0x80800B5C: sh          $t6, 0x6E($v0)
    MEM_H(0X6E, ctx->r2) = ctx->r14;
    // 0x80800B60: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800B64: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800B68: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800B6C: jal         0x8008A2B0
    // 0x80800B70: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800B70: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_8:
    // 0x80800B74: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800B78: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80800B7C: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x80800B80: lbu         $t9, 0x65($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X65);
    // 0x80800B84: lbu         $t5, 0x70($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X70);
    // 0x80800B88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800B8C: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x80800B90: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800B94: sb          $t1, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r9;
    // 0x80800B98: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80800B9C: andi        $t7, $t5, 0xFFFE
    ctx->r15 = ctx->r13 & 0XFFFE;
    // 0x80800BA0: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80800BA4: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x80800BA8: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80800BAC: jal         0x80800BC8
    // 0x80800BB0: sb          $t9, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r25;
    func_80800BC8_chmonsterinterior(rdram, ctx);
        goto after_9;
    // 0x80800BB0: sb          $t9, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r25;
    after_9:
    // 0x80800BB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800BB8:
    // 0x80800BB8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800BBC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800BC0: jr          $ra
    // 0x80800BC4: nop

    return;
    // 0x80800BC4: nop

;}
RECOMP_FUNC void subaddiefind_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808006B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808006B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006BC: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x808006C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006C4: jal         0x801067C4
    // 0x808006C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x808006C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x808006CC: beq         $v0, $zero, L_80800710
    if (ctx->r2 == 0) {
        // 0x808006D0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800710;
    }
    // 0x808006D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808006D4:
    // 0x808006D4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808006D8: lhu         $t7, 0x12($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X12);
    // 0x808006DC: srl         $t8, $t7, 1
    ctx->r24 = S32(U32(ctx->r15) >> 1);
    // 0x808006E0: bne         $s0, $t8, L_80800700
    if (ctx->r16 != ctx->r24) {
        // 0x808006E4: nop
    
            goto L_80800700;
    }
    // 0x808006E4: nop

    // 0x808006E8: lw          $t9, 0x64($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X64);
    // 0x808006EC: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x808006F0: bltz        $t1, L_80800700
    if (SIGNED(ctx->r9) < 0) {
        // 0x808006F4: nop
    
            goto L_80800700;
    }
    // 0x808006F4: nop

    // 0x808006F8: b           L_80800714
    // 0x808006FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800714;
    // 0x808006FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800700:
    // 0x80800700: jal         0x8010682C
    // 0x80800704: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010682C(rdram, ctx);
        goto after_1;
    // 0x80800704: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800708: bne         $v0, $zero, L_808006D4
    if (ctx->r2 != 0) {
        // 0x8080070C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808006D4;
    }
    // 0x8080070C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800710:
    // 0x80800710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800714:
    // 0x80800714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800718: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080071C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800720: jr          $ra
    // 0x80800724: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800724: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void batimer_isNonzero(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: lw          $t6, 0x13C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X13C);
    // 0x80800278: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8080027C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800280: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800284: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80800288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080028C: c.eq.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl == ctx->f4.fl;
    // 0x80800290: nop

    // 0x80800294: bc1t        L_808002A0
    if (c1cs) {
        // 0x80800298: nop
    
            goto L_808002A0;
    }
    // 0x80800298: nop

    // 0x8080029C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002A0:
    // 0x808002A0: jr          $ra
    // 0x808002A4: nop

    return;
    // 0x808002A4: nop

;}
RECOMP_FUNC void chswappy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800668: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2156, 0X6D4) << 16);
    // 0x8080066C: jr          $ra
    // 0x80800670: addiu       $v0, $v0, 0x6D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2156, 0X6D4));
    return;
    // 0x80800670: addiu       $v0, $v0, 0x6D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2156, 0X6D4));
    // 0x80800674: nop

    // 0x80800678: nop

    // 0x8080067C: nop

;}
RECOMP_FUNC void func_800EC898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC898: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EC89C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EC8A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800EC8A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800EC8A8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x800EC8AC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800EC8B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800EC8B4: jal         0x800EA05C
    // 0x800EC8B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x800EC8B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800EC8BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800EC8C0: addiu       $t0, $v1, 0x3580
    ctx->r8 = ADD32(ctx->r3, 0X3580);
    // 0x800EC8C4: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x800EC8C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800EC8CC: addiu       $t7, $t7, 0x3580
    ctx->r15 = ADD32(ctx->r15, 0X3580);
    // 0x800EC8D0: beql        $t6, $zero, L_800EC904
    if (ctx->r14 == 0) {
        // 0x800EC8D4: lh          $t9, 0x4($t0)
        ctx->r25 = MEM_H(ctx->r8, 0X4);
            goto L_800EC904;
    }
    goto skip_0;
    // 0x800EC8D4: lh          $t9, 0x4($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X4);
    skip_0:
    // 0x800EC8D8: lh          $v1, 0x0($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X0);
L_800EC8DC:
    // 0x800EC8DC: bnel        $v0, $v1, L_800EC8F4
    if (ctx->r2 != ctx->r3) {
        // 0x800EC8E0: lh          $v1, 0x8($t0)
        ctx->r3 = MEM_H(ctx->r8, 0X8);
            goto L_800EC8F4;
    }
    goto skip_1;
    // 0x800EC8E0: lh          $v1, 0x8($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X8);
    skip_1:
    // 0x800EC8E4: lh          $t8, 0x2($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X2);
    // 0x800EC8E8: beql        $s0, $t8, L_800EC904
    if (ctx->r16 == ctx->r24) {
        // 0x800EC8EC: lh          $t9, 0x4($t0)
        ctx->r25 = MEM_H(ctx->r8, 0X4);
            goto L_800EC904;
    }
    goto skip_2;
    // 0x800EC8EC: lh          $t9, 0x4($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X4);
    skip_2:
    // 0x800EC8F0: lh          $v1, 0x8($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X8);
L_800EC8F4:
    // 0x800EC8F4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800EC8F8: bne         $v1, $zero, L_800EC8DC
    if (ctx->r3 != 0) {
        // 0x800EC8FC: nop
    
            goto L_800EC8DC;
    }
    // 0x800EC8FC: nop

    // 0x800EC900: lh          $t9, 0x4($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X4);
L_800EC904:
    // 0x800EC904: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x800EC908: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EC90C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800EC910: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800EC914: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800EC918: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EC91C: addiu       $a3, $s1, 0x6
    ctx->r7 = ADD32(ctx->r17, 0X6);
    // 0x800EC920: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800EC924: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x800EC928: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x800EC92C: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x800EC930: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800EC934: nop

    // 0x800EC938: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EC93C: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
    // 0x800EC940: jal         0x80088888
    // 0x800EC944: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _glidmake_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x800EC944: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800EC948: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800EC94C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800EC950: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800EC954: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800EC958: mflo        $v0
    ctx->r2 = lo;
    // 0x800EC95C: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x800EC960: beq         $t4, $zero, L_800EC974
    if (ctx->r12 == 0) {
        // 0x800EC964: andi        $t5, $v0, 0x2
        ctx->r13 = ctx->r2 & 0X2;
            goto L_800EC974;
    }
    // 0x800EC964: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x800EC968: sb          $zero, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = 0;
    // 0x800EC96C: b           L_800EC978
    // 0x800EC970: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800EC978;
    // 0x800EC970: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800EC974:
    // 0x800EC974: sb          $v1, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r3;
L_800EC978:
    // 0x800EC978: beq         $t5, $zero, L_800EC988
    if (ctx->r13 == 0) {
        // 0x800EC97C: andi        $t6, $v0, 0x4
        ctx->r14 = ctx->r2 & 0X4;
            goto L_800EC988;
    }
    // 0x800EC97C: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x800EC980: b           L_800EC98C
    // 0x800EC984: sb          $zero, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = 0;
        goto L_800EC98C;
    // 0x800EC984: sb          $zero, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = 0;
L_800EC988:
    // 0x800EC988: sb          $v1, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r3;
L_800EC98C:
    // 0x800EC98C: beql        $t6, $zero, L_800EC9A0
    if (ctx->r14 == 0) {
        // 0x800EC990: sb          $v1, 0x1C($s1)
        MEM_B(0X1C, ctx->r17) = ctx->r3;
            goto L_800EC9A0;
    }
    goto skip_3;
    // 0x800EC990: sb          $v1, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r3;
    skip_3:
    // 0x800EC994: b           L_800EC9A0
    // 0x800EC998: sb          $zero, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = 0;
        goto L_800EC9A0;
    // 0x800EC998: sb          $zero, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = 0;
    // 0x800EC99C: sb          $v1, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r3;
L_800EC9A0:
    // 0x800EC9A0: lh          $v0, 0x18($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X18);
    // 0x800EC9A4: bnel        $v0, $zero, L_800EC9B8
    if (ctx->r2 != 0) {
        // 0x800EC9A8: mtc1        $v0, $f4
        ctx->f4.u32l = ctx->r2;
            goto L_800EC9B8;
    }
    goto skip_4;
    // 0x800EC9A8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    skip_4:
    // 0x800EC9AC: b           L_800EC9CC
    // 0x800EC9B0: sb          $zero, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = 0;
        goto L_800EC9CC;
    // 0x800EC9B0: sb          $zero, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = 0;
    // 0x800EC9B4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
L_800EC9B8:
    // 0x800EC9B8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800EC9BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800EC9C0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EC9C4: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800EC9C8: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
L_800EC9CC:
    // 0x800EC9CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EC9D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800EC9D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800EC9D8: jr          $ra
    // 0x800EC9DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800EC9DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void suexpressmorph_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800710: jr          $ra
    // 0x80800714: sb          $a1, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r5;
    return;
    // 0x80800714: sb          $a1, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void _scinfobar_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A588: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A588);
    return;
    // 0x8008A58C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080032C_chgobihailfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080032C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800330: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800334: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800338: beq         $a1, $at, L_808004A8
    if (ctx->r5 == ctx->r1) {
        // 0x8080033C: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_808004A8;
    }
    // 0x8080033C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800340: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800344: beq         $a1, $at, L_808004E8
    if (ctx->r5 == ctx->r1) {
        // 0x80800348: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_808004E8;
    }
    // 0x80800348: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x8080034C: beq         $a1, $at, L_80800370
    if (ctx->r5 == ctx->r1) {
        // 0x80800350: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_80800370;
    }
    // 0x80800350: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800354: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800358: bnel        $a1, $at, L_80800528
    if (ctx->r5 != ctx->r1) {
        // 0x8080035C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800528;
    }
    goto skip_0;
    // 0x8080035C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800360: jal         0x80800538
    // 0x80800364: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80800538_chgobihailfire(rdram, ctx);
        goto after_0;
    // 0x80800364: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800368: b           L_8080052C
    // 0x8080036C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080052C;
    // 0x8080036C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800370:
    // 0x80800370: lbu         $t8, 0x65($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X65);
    // 0x80800374: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80800378: sb          $t9, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r25;
    // 0x8080037C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80800380: jal         0x8008FCC8
    // 0x80800384: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_8008FCC8(rdram, ctx);
        goto after_1;
    // 0x80800384: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_1:
    // 0x80800388: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080038C: bnel        $v0, $at, L_80800528
    if (ctx->r2 != ctx->r1) {
        // 0x80800390: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800528;
    }
    goto skip_1;
    // 0x80800390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80800394: jal         0x800DA298
    // 0x80800398: addiu       $a0, $zero, 0x171
    ctx->r4 = ADD32(0, 0X171);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800398: addiu       $a0, $zero, 0x171
    ctx->r4 = ADD32(0, 0X171);
    after_2:
    // 0x8080039C: bnel        $v0, $zero, L_8080046C
    if (ctx->r2 != 0) {
        // 0x808003A0: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_8080046C;
    }
    goto skip_2;
    // 0x808003A0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x808003A4: jal         0x800DA298
    // 0x808003A8: addiu       $a0, $zero, 0x4F2
    ctx->r4 = ADD32(0, 0X4F2);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808003A8: addiu       $a0, $zero, 0x4F2
    ctx->r4 = ADD32(0, 0X4F2);
    after_3:
    // 0x808003AC: beq         $v0, $zero, L_80800468
    if (ctx->r2 == 0) {
        // 0x808003B0: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_80800468;
    }
    // 0x808003B0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808003B4: lhu         $t2, 0x72($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X72);
    // 0x808003B8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808003BC: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x808003C0: beql        $t3, $at, L_80800528
    if (ctx->r11 == ctx->r1) {
        // 0x808003C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800528;
    }
    goto skip_3;
    // 0x808003C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x808003C8: jal         0x80090658
    // 0x808003CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090658(rdram, ctx);
        goto after_4;
    // 0x808003CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x808003D0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x808003D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003D8: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x808003DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808003E0: jal         0x80085708
    // 0x808003E4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x808003E4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    after_5:
    // 0x808003E8: jal         0x800C064C
    // 0x808003EC: nop

    func_800C064C(rdram, ctx);
        goto after_6;
    // 0x808003EC: nop

    after_6:
    // 0x808003F0: addiu       $at, $zero, 0x12C3
    ctx->r1 = ADD32(0, 0X12C3);
    // 0x808003F4: bnel        $v0, $at, L_80800408
    if (ctx->r2 != ctx->r1) {
        // 0x808003F8: lw          $t5, 0x28($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X28);
            goto L_80800408;
    }
    goto skip_4;
    // 0x808003F8: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    skip_4:
    // 0x808003FC: jal         0x800C067C
    // 0x80800400: addiu       $a0, $zero, 0x12C3
    ctx->r4 = ADD32(0, 0X12C3);
    func_800C067C(rdram, ctx);
        goto after_7;
    // 0x80800400: addiu       $a0, $zero, 0x12C3
    ctx->r4 = ADD32(0, 0X12C3);
    after_7:
    // 0x80800404: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
L_80800408:
    // 0x80800408: addiu       $t7, $zero, 0x38
    ctx->r15 = ADD32(0, 0X38);
    // 0x8080040C: addiu       $a1, $zero, 0x12C4
    ctx->r5 = ADD32(0, 0X12C4);
    // 0x80800410: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80800414: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800418: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8080041C: jal         0x8008A208
    // 0x80800420: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800420: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    after_8:
    // 0x80800424: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800428: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1208, 0X818) << 16);
    // 0x8080042C: addiu       $a2, $a2, 0x818
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1208, 0X818));
    // 0x80800430: jal         0x80089D18
    // 0x80800434: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800434: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_9:
    // 0x80800438: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080043C: jal         0x80102424
    // 0x80800440: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x80800440: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_10:
    // 0x80800444: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800448: jal         0x80108B04
    // 0x8080044C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_11;
    // 0x8080044C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800450: jal         0x8010A570
    // 0x80800454: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8010A570(rdram, ctx);
        goto after_12;
    // 0x80800454: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x80800458: jal         0x800DA544
    // 0x8080045C: addiu       $a0, $zero, 0x171
    ctx->r4 = ADD32(0, 0X171);
    func_800DA544(rdram, ctx);
        goto after_13;
    // 0x8080045C: addiu       $a0, $zero, 0x171
    ctx->r4 = ADD32(0, 0X171);
    after_13:
    // 0x80800460: b           L_80800528
    // 0x80800464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800528;
    // 0x80800464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800468:
    // 0x80800468: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
L_8080046C:
    // 0x8080046C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800470: lhu         $t6, 0x72($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X72);
    // 0x80800474: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80800478: srl         $t0, $t6, 10
    ctx->r8 = S32(U32(ctx->r14) >> 10);
    // 0x8080047C: beql        $t0, $at, L_80800528
    if (ctx->r8 == ctx->r1) {
        // 0x80800480: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800528;
    }
    goto skip_5;
    // 0x80800480: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80800484: jal         0x80102424
    // 0x80800488: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800488: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_14:
    // 0x8080048C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800490: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1208, 0X818) << 16);
    // 0x80800494: addiu       $a2, $a2, 0x818
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1208, 0X818));
    // 0x80800498: jal         0x80089D18
    // 0x8080049C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x8080049C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_15:
    // 0x808004A0: b           L_80800528
    // 0x808004A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800528;
    // 0x808004A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004A8:
    // 0x808004A8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808004AC: bne         $a2, $at, L_808004E0
    if (ctx->r6 != ctx->r1) {
        // 0x808004B0: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_808004E0;
    }
    // 0x808004B0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x808004B4: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x808004B8: addiu       $t3, $zero, 0x42
    ctx->r11 = ADD32(0, 0X42);
    // 0x808004BC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808004C0: addiu       $a1, $zero, 0x12C6
    ctx->r5 = ADD32(0, 0X12C6);
    // 0x808004C4: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x808004C8: jal         0x8008A208
    // 0x808004CC: addiu       $a3, $t2, 0x4
    ctx->r7 = ADD32(ctx->r10, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x808004CC: addiu       $a3, $t2, 0x4
    ctx->r7 = ADD32(ctx->r10, 0X4);
    after_16:
    // 0x808004D0: jal         0x80090658
    // 0x808004D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090658(rdram, ctx);
        goto after_17;
    // 0x808004D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x808004D8: jal         0x8010A590
    // 0x808004DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8010A590(rdram, ctx);
        goto after_18;
    // 0x808004DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_18:
L_808004E0:
    // 0x808004E0: b           L_80800528
    // 0x808004E4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800528;
    // 0x808004E4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808004E8:
    // 0x808004E8: addiu       $a0, $zero, 0x500
    ctx->r4 = ADD32(0, 0X500);
    // 0x808004EC: jal         0x801084B0
    // 0x808004F0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_801084B0(rdram, ctx);
        goto after_19;
    // 0x808004F0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_19:
    // 0x808004F4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x808004F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808004FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800500: jal         0x80102FDC
    // 0x80800504: lw          $a1, 0x38($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_20;
    // 0x80800504: lw          $a1, 0x38($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X38);
    after_20:
    // 0x80800508: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8080050C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800510: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800514: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80800518: sw          $t7, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->r15;
    // 0x8080051C: jal         0x80101EE4
    // 0x80800520: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80101EE4(rdram, ctx);
        goto after_21;
    // 0x80800520: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_21:
    // 0x80800524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800528:
    // 0x80800528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080052C:
    // 0x8080052C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800530: jr          $ra
    // 0x80800534: nop

    return;
    // 0x80800534: nop

;}
RECOMP_FUNC void func_808008A4_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008A8: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x808008AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008B0: bne         $a1, $at, L_808008EC
    if (ctx->r5 != ctx->r1) {
        // 0x808008B4: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808008EC;
    }
    // 0x808008B4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808008B8: jal         0x80101080
    // 0x808008BC: nop

    func_80101080(rdram, ctx);
        goto after_0;
    // 0x808008BC: nop

    after_0:
    // 0x808008C0: jal         0x80106790
    // 0x808008C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808008C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808008C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808008CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008D0: lui         $a1, 0x4496
    ctx->r5 = S32(0X4496 << 16);
    // 0x808008D4: jal         0x80086688
    // 0x808008D8: lui         $a2, 0x44AF
    ctx->r6 = S32(0X44AF << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808008D8: lui         $a2, 0x44AF
    ctx->r6 = S32(0X44AF << 16);
    after_2:
    // 0x808008DC: jal         0x80089CA8
    // 0x808008E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808008E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808008E4: b           L_80800904
    // 0x808008E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800904;
    // 0x808008E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008EC:
    // 0x808008EC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808008F0: bne         $a1, $at, L_80800904
    if (ctx->r5 != ctx->r1) {
        // 0x808008F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800904;
    }
    // 0x808008F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808008F8: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x808008FC: b           L_80800904
    // 0x80800900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800904;
    // 0x80800900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800904:
    // 0x80800904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800908: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080090C: jr          $ra
    // 0x80800910: nop

    return;
    // 0x80800910: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A848: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A848);
    return;
    // 0x8008A84C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void _idglowa_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D80: syscall     739
    recomp_syscall_handler(rdram, ctx, 0x80088D80);
    return;
    // 0x80088D84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808000D0_chminelobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000DC: jal         0x800C6E38
    // 0x808000E0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x808000E0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_0:
    // 0x808000E4: beq         $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x808000E8: addiu       $a0, $zero, 0x1A
        ctx->r4 = ADD32(0, 0X1A);
            goto L_808000F4;
    }
    // 0x808000E8: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x808000EC: b           L_808000F8
    // 0x808000F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_808000F8;
    // 0x808000F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808000F4:
    // 0x808000F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808000F8:
    // 0x808000F8: jal         0x800C6E38
    // 0x808000FC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800C6E38(rdram, ctx);
        goto after_1;
    // 0x808000FC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800100: beq         $v0, $zero, L_80800110
    if (ctx->r2 == 0) {
        // 0x80800104: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800110;
    }
    // 0x80800104: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800108: b           L_80800114
    // 0x8080010C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800114;
    // 0x8080010C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800110:
    // 0x80800110: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800114:
    // 0x80800114: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80800118: beq         $v1, $zero, L_8080016C
    if (ctx->r3 == 0) {
        // 0x8080011C: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(2196, 0X238) << 16);
            goto L_8080016C;
    }
    // 0x8080011C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2196, 0X238) << 16);
    // 0x80800120: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800124: beq         $v1, $at, L_80800148
    if (ctx->r3 == ctx->r1) {
        // 0x80800128: addiu       $t6, $zero, 0xF9F
        ctx->r14 = ADD32(0, 0XF9F);
            goto L_80800148;
    }
    // 0x80800128: addiu       $t6, $zero, 0xF9F
    ctx->r14 = ADD32(0, 0XF9F);
    // 0x8080012C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800130: beq         $v1, $at, L_8080016C
    if (ctx->r3 == ctx->r1) {
        // 0x80800134: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080016C;
    }
    // 0x80800134: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800138: beq         $v1, $at, L_8080015C
    if (ctx->r3 == ctx->r1) {
        // 0x8080013C: addiu       $t8, $zero, 0xFA1
        ctx->r24 = ADD32(0, 0XFA1);
            goto L_8080015C;
    }
    // 0x8080013C: addiu       $t8, $zero, 0xFA1
    ctx->r24 = ADD32(0, 0XFA1);
    // 0x80800140: b           L_80800170
    // 0x80800144: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_80800170;
    // 0x80800144: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800148:
    // 0x80800148: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2196, 0X23C) << 16);
    // 0x8080014C: addiu       $t7, $zero, 0xFA0
    ctx->r15 = ADD32(0, 0XFA0);
    // 0x80800150: sh          $t6, 0x23C($at)
    MEM_H((int16_t)RELOC_LO16(2196, 0X23C), ctx->r1) = ctx->r14;
    // 0x80800154: b           L_8080016C
    // 0x80800158: sh          $t7, 0x23E($at)
    MEM_H((int16_t)RELOC_LO16(2196, 0X23E), ctx->r1) = ctx->r15;
        goto L_8080016C;
    // 0x80800158: sh          $t7, 0x23E($at)
    MEM_H((int16_t)RELOC_LO16(2196, 0X23E), ctx->r1) = ctx->r15;
L_8080015C:
    // 0x8080015C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2196, 0X23C) << 16);
    // 0x80800160: addiu       $t9, $zero, 0xFA1
    ctx->r25 = ADD32(0, 0XFA1);
    // 0x80800164: sh          $t8, 0x23C($at)
    MEM_H((int16_t)RELOC_LO16(2196, 0X23C), ctx->r1) = ctx->r24;
    // 0x80800168: sh          $t9, 0x23E($at)
    MEM_H((int16_t)RELOC_LO16(2196, 0X23E), ctx->r1) = ctx->r25;
L_8080016C:
    // 0x8080016C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800170:
    // 0x80800170: addiu       $a2, $a2, 0x238
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2196, 0X238));
    // 0x80800174: jal         0x8008A1E8
    // 0x80800178: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800178: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x8080017C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800184: jr          $ra
    // 0x80800188: nop

    return;
    // 0x80800188: nop

;}
RECOMP_FUNC void func_808002B4_chgoldsnakehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808002C4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x808002C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002CC: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x808002D0: sll         $t0, $t8, 18
    ctx->r8 = S32(ctx->r24 << 18);
    // 0x808002D4: bgez        $t0, L_808002E4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808002D8: nop
    
            goto L_808002E4;
    }
    // 0x808002D8: nop

    // 0x808002DC: b           L_808002E4
    // 0x808002E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_808002E4;
    // 0x808002E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_808002E4:
    // 0x808002E4: jal         0x800DF744
    // 0x808002E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x808002E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x808002EC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x808002F0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808002F4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x808002F8: lw          $a1, 0x28($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X28);
    // 0x808002FC: sll         $t3, $a1, 18
    ctx->r11 = S32(ctx->r5 << 18);
    // 0x80800300: jal         0x800DF744
    // 0x80800304: srl         $a1, $t3, 31
    ctx->r5 = S32(U32(ctx->r11) >> 31);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800304: srl         $a1, $t3, 31
    ctx->r5 = S32(U32(ctx->r11) >> 31);
    after_1:
    // 0x80800308: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080030C: jal         0x80101870
    // 0x80800310: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_2;
    // 0x80800310: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080031C: jr          $ra
    // 0x80800320: nop

    return;
    // 0x80800320: nop

;}
RECOMP_FUNC void _ncpoddialog_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089620: syscall     784
    recomp_syscall_handler(rdram, ctx, 0x80089620);
    return;
    // 0x80089624: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _sumultiscore_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089988: syscall     799
    recomp_syscall_handler(rdram, ctx, 0x80089988);
    return;
    // 0x8008998C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _subaddieaudioloop_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D40: syscall     810
    recomp_syscall_handler(rdram, ctx, 0x80089D40);
    return;
    // 0x80089D44: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void sucoasterflydata_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: sltiu       $at, $a0, 0x5
    ctx->r1 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x808000BC: beq         $at, $zero, L_8080012C
    if (ctx->r1 == 0) {
        // 0x808000C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080012C;
    }
    // 0x808000C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808000C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3286, 0X240) << 16);
    // 0x808000CC: addu        $at, $at, $t6
    gpr jr_addend_808000D4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808000D0: lw          $t6, 0x240($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3286, 0X240));
    // 0x808000D4: jr          $t6
    // 0x808000D8: nop

    switch (jr_addend_808000D4 >> 2) {
        case 0: goto L_808000DC; break;
        case 1: goto L_808000F0; break;
        case 2: goto L_808000F0; break;
        case 3: goto L_80800104; break;
        case 4: goto L_80800118; break;
        default: switch_error(__func__, 0x808000D4, 0x80800240);
    }
    // 0x808000D8: nop

L_808000DC:
    // 0x808000DC: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x808000E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3286, 0X358) << 16);
    // 0x808000E4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x808000E8: jr          $ra
    // 0x808000EC: addiu       $v0, $v0, 0x358
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3286, 0X358));
    return;
    // 0x808000EC: addiu       $v0, $v0, 0x358
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3286, 0X358));
L_808000F0:
    // 0x808000F0: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x808000F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3286, 0X3AC) << 16);
    // 0x808000F8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x808000FC: jr          $ra
    // 0x80800100: addiu       $v0, $v0, 0x3AC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3286, 0X3AC));
    return;
    // 0x80800100: addiu       $v0, $v0, 0x3AC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3286, 0X3AC));
L_80800104:
    // 0x80800104: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80800108: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3286, 0X3F4) << 16);
    // 0x8080010C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80800110: jr          $ra
    // 0x80800114: addiu       $v0, $v0, 0x3F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3286, 0X3F4));
    return;
    // 0x80800114: addiu       $v0, $v0, 0x3F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3286, 0X3F4));
L_80800118:
    // 0x80800118: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8080011C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3286, 0X43C) << 16);
    // 0x80800120: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80800124: jr          $ra
    // 0x80800128: addiu       $v0, $v0, 0x43C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3286, 0X43C));
    return;
    // 0x80800128: addiu       $v0, $v0, 0x43C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3286, 0X43C));
L_8080012C:
    // 0x8080012C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80800130: jr          $ra
    // 0x80800134: nop

    return;
    // 0x80800134: nop

;}
RECOMP_FUNC void _gspropsDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BA0: syscall     727
    recomp_syscall_handler(rdram, ctx, 0x80088BA0);
    return;
    // 0x80088BA4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _idbounce_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CA0: syscall     733
    recomp_syscall_handler(rdram, ctx, 0x80088CA0);
    return;
    // 0x80088CA4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _suquiz_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A7F0: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A7F0);
    return;
    // 0x8008A7F4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void subaddieaudioloop_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808001B0: beq         $a2, $zero, L_80800220
    if (ctx->r6 == 0) {
        // 0x808001B4: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_80800220;
    }
    // 0x808001B4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808001B8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808001BC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808001C0: jal         0x8010D640
    // 0x808001C4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_8010D640(rdram, ctx);
        goto after_0;
    // 0x808001C4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808001C8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x808001CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808001D0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x808001D4: bne         $a3, $at, L_808001E0
    if (ctx->r7 != ctx->r1) {
        // 0x808001D8: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_808001E0;
    }
    // 0x808001D8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808001DC: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
L_808001E0:
    // 0x808001E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808001E4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808001E8: jal         0x800EEB40
    // 0x808001EC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x808001EC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_1:
    // 0x808001F0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x808001F4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x808001F8: multu       $a3, $a3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808001FC: mflo        $t6
    ctx->r14 = lo;
    // 0x80800200: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800204: nop

    // 0x80800208: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080020C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800210: nop

    // 0x80800214: bc1fl       L_80800224
    if (!c1cs) {
        // 0x80800218: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_80800224;
    }
    goto skip_0;
    // 0x80800218: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8080021C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80800220:
    // 0x80800220: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_80800224:
    // 0x80800224: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    // 0x80800228: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080022C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80800230: jal         0x80800248
    // 0x80800234: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800234: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x80800238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080023C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800240: jr          $ra
    // 0x80800244: nop

    return;
    // 0x80800244: nop

;}
RECOMP_FUNC void func_800E9DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9DC4: jr          $ra
    // 0x800E9DC8: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    return;
    // 0x800E9DC8: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
;}
RECOMP_FUNC void func_800C145C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C145C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C1460: lbu         $t6, -0x7378($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7378);
    // 0x800C1464: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C1468: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C146C: bne         $t6, $zero, L_800C1480
    if (ctx->r14 != 0) {
        // 0x800C1470: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800C1480;
    }
    // 0x800C1470: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1474: sb          $t7, -0x7378($at)
    MEM_B(-0X7378, ctx->r1) = ctx->r15;
    // 0x800C1478: jr          $ra
    // 0x800C147C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800C147C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C1480:
    // 0x800C1480: lbu         $t8, -0x72F8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X72F8);
    // 0x800C1484: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C1488: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C148C: bne         $t8, $zero, L_800C14A0
    if (ctx->r24 != 0) {
        // 0x800C1490: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800C14A0;
    }
    // 0x800C1490: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C1494: sb          $t9, -0x72F8($at)
    MEM_B(-0X72F8, ctx->r1) = ctx->r25;
    // 0x800C1498: jr          $ra
    // 0x800C149C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800C149C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800C14A0:
    // 0x800C14A0: lbu         $t0, -0x7278($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X7278);
    // 0x800C14A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C14A8: addiu       $a0, $a0, -0x7270
    ctx->r4 = ADD32(ctx->r4, -0X7270);
    // 0x800C14AC: bne         $t0, $zero, L_800C14C8
    if (ctx->r8 != 0) {
        // 0x800C14B0: addiu       $v1, $zero, 0x4
        ctx->r3 = ADD32(0, 0X4);
            goto L_800C14C8;
    }
    // 0x800C14B0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800C14B4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C14B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C14BC: sb          $t1, -0x7278($at)
    MEM_B(-0X7278, ctx->r1) = ctx->r9;
    // 0x800C14C0: jr          $ra
    // 0x800C14C4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x800C14C4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800C14C8:
    // 0x800C14C8: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_800C14CC:
    // 0x800C14CC: lbu         $t2, 0x78($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X78);
    // 0x800C14D0: bne         $t2, $zero, L_800C14E4
    if (ctx->r10 != 0) {
        // 0x800C14D4: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800C14E4;
    }
    // 0x800C14D4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C14D8: sb          $t3, 0x78($a0)
    MEM_B(0X78, ctx->r4) = ctx->r11;
    // 0x800C14DC: jr          $ra
    // 0x800C14E0: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x800C14E0: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
L_800C14E4:
    // 0x800C14E4: lbu         $t4, 0xF8($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0XF8);
    // 0x800C14E8: bnel        $t4, $zero, L_800C150C
    if (ctx->r12 != 0) {
        // 0x800C14EC: lbu         $t7, 0x178($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X178);
            goto L_800C150C;
    }
    goto skip_0;
    // 0x800C14EC: lbu         $t7, 0x178($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X178);
    skip_0:
    // 0x800C14F0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800C14F4: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x800C14F8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800C14FC: sb          $t5, 0xF8($a0)
    MEM_B(0XF8, ctx->r4) = ctx->r13;
    // 0x800C1500: jr          $ra
    // 0x800C1504: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x800C1504: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800C1508: lbu         $t7, 0x178($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X178);
L_800C150C:
    // 0x800C150C: bnel        $t7, $zero, L_800C1530
    if (ctx->r15 != 0) {
        // 0x800C1510: lbu         $t0, 0x1F8($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X1F8);
            goto L_800C1530;
    }
    goto skip_1;
    // 0x800C1510: lbu         $t0, 0x1F8($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1F8);
    skip_1:
    // 0x800C1514: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x800C1518: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x800C151C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C1520: sb          $t8, 0x178($a0)
    MEM_B(0X178, ctx->r4) = ctx->r24;
    // 0x800C1524: jr          $ra
    // 0x800C1528: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    return;
    // 0x800C1528: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800C152C: lbu         $t0, 0x1F8($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1F8);
L_800C1530:
    // 0x800C1530: bnel        $t0, $zero, L_800C1554
    if (ctx->r8 != 0) {
        // 0x800C1534: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800C1554;
    }
    goto skip_2;
    // 0x800C1534: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_2:
    // 0x800C1538: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x800C153C: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x800C1540: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C1544: sb          $t1, 0x1F8($a0)
    MEM_B(0X1F8, ctx->r4) = ctx->r9;
    // 0x800C1548: jr          $ra
    // 0x800C154C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    return;
    // 0x800C154C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800C1550: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800C1554:
    // 0x800C1554: bne         $v1, $v0, L_800C14CC
    if (ctx->r3 != ctx->r2) {
        // 0x800C1558: addiu       $a0, $a0, 0x200
        ctx->r4 = ADD32(ctx->r4, 0X200);
            goto L_800C14CC;
    }
    // 0x800C1558: addiu       $a0, $a0, 0x200
    ctx->r4 = ADD32(ctx->r4, 0X200);
    // 0x800C155C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1560: jr          $ra
    // 0x800C1564: nop

    return;
    // 0x800C1564: nop

;}
RECOMP_FUNC void _bskazcrouch_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083318: syscall     54
    recomp_syscall_handler(rdram, ctx, 0x80083318);
    return;
    // 0x8008331C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C28: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C28);
    return;
    // 0x80082C2C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
