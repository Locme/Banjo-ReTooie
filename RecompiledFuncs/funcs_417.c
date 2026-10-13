#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void static_16_80097978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097978: lw          $t6, 0xA4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA4);
    // 0x8009797C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80097980: sllv        $t9, $t8, $a1
    ctx->r25 = S32(ctx->r24 << (ctx->r5 & 31));
    // 0x80097984: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80097988: jr          $ra
    // 0x8009798C: and         $v0, $t7, $t9
    ctx->r2 = ctx->r15 & ctx->r25;
    return;
    // 0x8009798C: and         $v0, $t7, $t9
    ctx->r2 = ctx->r15 & ctx->r25;
;}
RECOMP_FUNC void static_304_80800324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void static_344_80800000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void static_344_8080003C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800048: jal         0x80095748
    // 0x8080004C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    baflag_isFalse(rdram, ctx);
        goto after_0;
    // 0x8080004C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_0:
    // 0x80800050: bne         $v0, $zero, L_80800070
    if (ctx->r2 != 0) {
        // 0x80800054: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800070;
    }
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800058: jal         0x80095774
    // 0x8080005C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    baflag_clear(rdram, ctx);
        goto after_1;
    // 0x8080005C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_1:
    // 0x80800060: jal         0x800A4CA8
    // 0x80800064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4CA8(rdram, ctx);
        goto after_2;
    // 0x80800064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800068: jal         0x80110C2C
    // 0x8080006C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110C2C(rdram, ctx);
        goto after_3;
    // 0x8080006C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
L_80800070:
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void static_344_80800080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800088: jal         0x800A4CA8
    // 0x8080008C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x8080008C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800090: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800094: jal         0x8009CC68
    // 0x80800098: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8009CC68(rdram, ctx);
        goto after_1;
    // 0x80800098: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8080009C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000A0: bne         $v0, $at, L_808000D4
    if (ctx->r2 != ctx->r1) {
        // 0x808000A4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808000D4;
    }
    // 0x808000A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000A8: jal         0x80095760
    // 0x808000AC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    baflag_set(rdram, ctx);
        goto after_2;
    // 0x808000AC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_2:
    // 0x808000B0: jal         0x80110BF0
    // 0x808000B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80110BF0(rdram, ctx);
        goto after_3;
    // 0x808000B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808000B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000BC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808000C0: jal         0x800F3BD0
    // 0x808000C4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800F3BD0(rdram, ctx);
        goto after_4;
    // 0x808000C4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x808000C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000CC: jal         0x800893F8
    // 0x808000D0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _ncba1p_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x808000D0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_5:
L_808000D4:
    // 0x808000D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000DC: jr          $ra
    // 0x808000E0: nop

    return;
    // 0x808000E0: nop

;}
RECOMP_FUNC void static_344_808000E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808000E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000F0: jal         0x800A4CA8
    // 0x808000F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x808000F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000F8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x808000FC: jal         0x8009CC68
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CC68(rdram, ctx);
        goto after_1;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800104: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800108: bne         $v0, $at, L_80800174
    if (ctx->r2 != ctx->r1) {
        // 0x8080010C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800174;
    }
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: jal         0x80095748
    // 0x80800114: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    baflag_isFalse(rdram, ctx);
        goto after_2;
    // 0x80800114: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_2:
    // 0x80800118: bne         $v0, $zero, L_80800174
    if (ctx->r2 != 0) {
        // 0x8080011C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800174;
    }
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800124: jal         0x800F3BD0
    // 0x80800128: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800F3BD0(rdram, ctx);
        goto after_3;
    // 0x80800128: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x8080012C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800130: jal         0x800893F8
    // 0x80800134: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _ncba1p_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800134: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800140: jal         0x800F3BD0
    // 0x80800144: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800F3BD0(rdram, ctx);
        goto after_5;
    // 0x80800144: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x8009CC18
    // 0x80800150: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8009CC18(rdram, ctx);
        goto after_6;
    // 0x80800150: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x80800154: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800160: jal         0x800A516C
    // 0x80800164: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800A516C(rdram, ctx);
        goto after_7;
    // 0x80800164: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x80800168: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8080016C: jal         0x80089400
    // 0x80800170: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _ncba1p_entrypoint_7(rdram, ctx);
        goto after_8;
    // 0x80800170: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
L_80800174:
    // 0x80800174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800178: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080017C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void static_344_8080020C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080020C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800210: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800214: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800218: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080021C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800220: jal         0x8008CABC
    // 0x80800224: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800224: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800228: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8080022C: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x80800230: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800234: bne         $a3, $at, L_808002E0
    if (ctx->r7 != ctx->r1) {
        // 0x80800238: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002E0;
    }
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800240: jal         0x800A0CF4
    // 0x80800244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_1;
    // 0x80800244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800248: jal         0x8008CABC
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_2;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800250: jal         0x8008B264
    // 0x80800254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getIndex(rdram, ctx);
        goto after_3;
    // 0x80800254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800258: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x8080025C: beq         $v0, $at, L_80800278
    if (ctx->r2 == ctx->r1) {
        // 0x80800260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800278;
    }
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x80800268: beq         $v0, $at, L_8080028C
    if (ctx->r2 == ctx->r1) {
        // 0x8080026C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080028C;
    }
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: b           L_808002C4
    // 0x80800274: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
        goto L_808002C4;
    // 0x80800274: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
L_80800278:
    // 0x80800278: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080027C: jal         0x8008CB3C
    // 0x80800280: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_4;
    // 0x80800280: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80800284: b           L_808002F0
    // 0x80800288: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
        goto L_808002F0;
    // 0x80800288: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
L_8080028C:
    // 0x8080028C: jal         0x8008AF24
    // 0x80800290: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_reset(rdram, ctx);
        goto after_5;
    // 0x80800290: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800294: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800298: jal         0x8008AED4
    // 0x8080029C: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    anctrl_setIndex(rdram, ctx);
        goto after_6;
    // 0x8080029C: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    after_6:
    // 0x808002A0: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x808002A4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808002A8: jal         0x8008B1BC
    // 0x808002AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_setDuration(rdram, ctx);
        goto after_7;
    // 0x808002AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x808002B0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808002B4: jal         0x8008B134
    // 0x808002B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x808002B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808002BC: b           L_808002F0
    // 0x808002C0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
        goto L_808002F0;
    // 0x808002C0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
L_808002C4:
    // 0x808002C4: jal         0x8008CCBC
    // 0x808002C8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_9;
    // 0x808002C8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_9:
    // 0x808002CC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808002D0: jal         0x8008B134
    // 0x808002D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_10;
    // 0x808002D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808002D8: b           L_808002F0
    // 0x808002DC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
        goto L_808002F0;
    // 0x808002DC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
L_808002E0:
    // 0x808002E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808002E4: jal         0x8008CB3C
    // 0x808002E8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_11;
    // 0x808002E8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_11:
    // 0x808002EC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
L_808002F0:
    // 0x808002F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800300: jal         0x8009FFD8
    // 0x80800304: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_12;
    // 0x80800304: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_12:
    // 0x80800308: jal         0x80800000
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    static_344_80800000(rdram, ctx);
        goto after_13;
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800310: jal         0x80800188
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsrest_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800318: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080031C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800320: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800324: jr          $ra
    // 0x80800328: nop

    return;
    // 0x80800328: nop

;}
RECOMP_FUNC void static_344_8080032C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080032C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800330: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800334: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800338: jal         0x8008CABC
    // 0x8080033C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080033C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800340: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800344: jal         0x80800188
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsrest_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080034C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80800350: jal         0x8008B264
    // 0x80800354: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_getIndex(rdram, ctx);
        goto after_2;
    // 0x80800354: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800358: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x8080035C: beq         $v0, $at, L_808003BC
    if (ctx->r2 == ctx->r1) {
        // 0x80800360: addiu       $at, $zero, 0x5B
        ctx->r1 = ADD32(0, 0X5B);
            goto L_808003BC;
    }
    // 0x80800360: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x80800364: bne         $v0, $at, L_808003D4
    if (ctx->r2 != ctx->r1) {
        // 0x80800368: nop
    
            goto L_808003D4;
    }
    // 0x80800368: nop

    // 0x8080036C: jal         0x8008CAEC
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_3;
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800374: beql        $v0, $zero, L_808003EC
    if (ctx->r2 == 0) {
        // 0x80800378: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003EC;
    }
    goto skip_0;
    // 0x80800378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080037C: jal         0x8008B28C
    // 0x80800380: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8008B28C(rdram, ctx);
        goto after_4;
    // 0x80800380: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800384: beq         $v0, $zero, L_808003A4
    if (ctx->r2 == 0) {
        // 0x80800388: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A4;
    }
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: lui         $a2, 0x4136
    ctx->r6 = S32(0X4136 << 16);
    // 0x80800390: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800394: jal         0x8008CB3C
    // 0x80800398: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_5;
    // 0x80800398: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_5:
    // 0x8080039C: b           L_808003EC
    // 0x808003A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003EC;
    // 0x808003A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003A4:
    // 0x808003A4: jal         0x8009CC68
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CC68(rdram, ctx);
        goto after_6;
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003AC: bne         $v0, $zero, L_808003E8
    if (ctx->r2 != 0) {
        // 0x808003B0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808003E8;
    }
    // 0x808003B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808003B4: b           L_808003E8
    // 0x808003B8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
        goto L_808003E8;
    // 0x808003B8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
L_808003BC:
    // 0x808003BC: jal         0x8009CC68
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CC68(rdram, ctx);
        goto after_7;
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808003C4: bne         $v0, $zero, L_808003E8
    if (ctx->r2 != 0) {
        // 0x808003C8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_808003E8;
    }
    // 0x808003C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808003CC: b           L_808003E8
    // 0x808003D0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
        goto L_808003E8;
    // 0x808003D0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_808003D4:
    // 0x808003D4: jal         0x8009CC68
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CC68(rdram, ctx);
        goto after_8;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808003DC: bne         $v0, $zero, L_808003E8
    if (ctx->r2 != 0) {
        // 0x808003E0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_808003E8;
    }
    // 0x808003E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808003E4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_808003E8:
    // 0x808003E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003EC:
    // 0x808003EC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808003F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003F4: jr          $ra
    // 0x808003F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808003F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void static_344_808003FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800404: jal         0x800A0C20
    // 0x80800408: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A0C20(rdram, ctx);
        goto after_0;
    // 0x80800408: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080040C: beq         $v0, $zero, L_80800420
    if (ctx->r2 == 0) {
        // 0x80800410: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800420;
    }
    // 0x80800410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800418: jal         0x800A0D14
    // 0x8080041C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_800A0D14(rdram, ctx);
        goto after_1;
    // 0x8080041C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_1:
L_80800420:
    // 0x80800420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800428: jr          $ra
    // 0x8080042C: nop

    return;
    // 0x8080042C: nop

;}
