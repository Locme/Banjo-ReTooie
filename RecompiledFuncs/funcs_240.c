#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080102C_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080102C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801030: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801034: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801038: jal         0x8008CABC
    // 0x8080103C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080103C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801040: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801044: jal         0x8008B264
    // 0x80801048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getIndex(rdram, ctx);
        goto after_1;
    // 0x80801048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080104C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80801050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801054: jal         0x8008CA4C
    // 0x80801058: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008CA4C(rdram, ctx);
        goto after_2;
    // 0x80801058: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080105C: jal         0x8009BB94
    // 0x80801060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB94(rdram, ctx);
        goto after_3;
    // 0x80801060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801064: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80801068: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080106C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801070: addiu       $at, $zero, 0x12F
    ctx->r1 = ADD32(0, 0X12F);
    // 0x80801074: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801078: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8080107C: bc1f        L_808010D4
    if (!c1cs) {
        // 0x80801080: nop
    
            goto L_808010D4;
    }
    // 0x80801080: nop

    // 0x80801084: addiu       $at, $zero, 0x12E
    ctx->r1 = ADD32(0, 0X12E);
    // 0x80801088: beq         $t6, $at, L_808010AC
    if (ctx->r14 == ctx->r1) {
        // 0x8080108C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010AC;
    }
    // 0x8080108C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801090: addiu       $a1, $zero, 0x12E
    ctx->r5 = ADD32(0, 0X12E);
    // 0x80801094: jal         0x8008CB3C
    // 0x80801098: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_4;
    // 0x80801098: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    after_4:
    // 0x8080109C: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x808010A0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808010A4: jal         0x8008B1C8
    // 0x808010A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8008B1C8(rdram, ctx);
        goto after_5;
    // 0x808010A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
L_808010AC:
    // 0x808010AC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808010B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808010B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808010BC: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    // 0x808010C0: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x808010C4: jal         0x8008C9F0
    // 0x808010C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_6;
    // 0x808010C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x808010CC: b           L_80801120
    // 0x808010D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801120;
    // 0x808010D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808010D4:
    // 0x808010D4: beq         $t7, $at, L_808010FC
    if (ctx->r15 == ctx->r1) {
        // 0x808010D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010FC;
    }
    // 0x808010D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010DC: lui         $a2, 0x3EE6
    ctx->r6 = S32(0X3EE6 << 16);
    // 0x808010E0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808010E4: jal         0x8008CB3C
    // 0x808010E8: addiu       $a1, $zero, 0x12F
    ctx->r5 = ADD32(0, 0X12F);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_7;
    // 0x808010E8: addiu       $a1, $zero, 0x12F
    ctx->r5 = ADD32(0, 0X12F);
    after_7:
    // 0x808010EC: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x808010F0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808010F4: jal         0x8008B1C8
    // 0x808010F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8008B1C8(rdram, ctx);
        goto after_8;
    // 0x808010F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_8:
L_808010FC:
    // 0x808010FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(380, 0X16DC) << 16);
    // 0x80801100: lwc1        $f8, 0x16DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16DC));
    // 0x80801104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801108: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080110C: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    // 0x80801110: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x80801114: jal         0x8008C9F0
    // 0x80801118: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_9;
    // 0x80801118: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x8080111C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801120:
    // 0x80801120: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801124: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801128: jr          $ra
    // 0x8080112C: nop

    return;
    // 0x8080112C: nop

;}
RECOMP_FUNC void _gsattract_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C60: syscall     731
    recomp_syscall_handler(rdram, ctx, 0x80088C60);
    return;
    // 0x80088C64: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800AF8_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B00: jal         0x8080021C
    // 0x80800B04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080021C_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x80800B04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B08: jal         0x80082FE0
    // 0x80800B0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800B0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B18: jr          $ra
    // 0x80800B1C: nop

    return;
    // 0x80800B1C: nop

;}
RECOMP_FUNC void func_800F2108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2108: mfc1        $t0, $f12
    ctx->r8 = (int32_t)ctx->f12.u32l;
    // 0x800F210C: lui         $t1, 0x3F80
    ctx->r9 = S32(0X3F80 << 16);
    // 0x800F2110: srl         $t2, $t0, 31
    ctx->r10 = S32(U32(ctx->r8) >> 31);
    // 0x800F2114: sll         $t2, $t2, 31
    ctx->r10 = S32(ctx->r10 << 31);
    // 0x800F2118: beql        $t0, $t2, L_800F2124
    if (ctx->r8 == ctx->r10) {
        // 0x800F211C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800F2124;
    }
    goto skip_0;
    // 0x800F211C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    skip_0:
    // 0x800F2120: or          $t0, $t1, $t2
    ctx->r8 = ctx->r9 | ctx->r10;
L_800F2124:
    // 0x800F2124: jr          $ra
    // 0x800F2128: mtc1        $t0, $f0
    ctx->f0.u32l = ctx->r8;
    return;
    // 0x800F2128: mtc1        $t0, $f0
    ctx->f0.u32l = ctx->r8;
;}
RECOMP_FUNC void chmole_maya_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1596, 0X258) << 16);
    // 0x808001CC: jr          $ra
    // 0x808001D0: addiu       $v0, $v0, 0x258
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1596, 0X258));
    return;
    // 0x808001D0: addiu       $v0, $v0, 0x258
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1596, 0X258));
    // 0x808001D4: nop

    // 0x808001D8: nop

    // 0x808001DC: nop

;}
RECOMP_FUNC void badrone_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080044C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800450: lw          $a0, 0x54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54);
    // 0x80800454: jal         0x800EE7F8
    // 0x80800458: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800458: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_0:
    // 0x8080045C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800460: jal         0x80800348
    // 0x80800464: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800348_badrone(rdram, ctx);
        goto after_1;
    // 0x80800464: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_1:
    // 0x80800468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080046C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800470: jr          $ra
    // 0x80800474: nop

    return;
    // 0x80800474: nop

;}
RECOMP_FUNC void chnests_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F68: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X1308) << 16);
    // 0x80800F6C: jr          $ra
    // 0x80800F70: addiu       $v0, $v0, 0x1308
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1308));
    return;
    // 0x80800F70: addiu       $v0, $v0, 0x1308
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1308));
;}
RECOMP_FUNC void func_800F0008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0008: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F000C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800F0010: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800F0014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0018: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800F001C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800F0020: jal         0x800EFB24
    // 0x800F0024: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800F0024: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800F0028: jal         0x800EEFD4
    // 0x800F002C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EEFD4(rdram, ctx);
        goto after_1;
    // 0x800F002C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x800F0030: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F0034: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F0038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0040: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F0044: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F0048: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x800F004C: nop

    // 0x800F0050: bc1f        L_800F005C
    if (!c1cs) {
        // 0x800F0054: nop
    
            goto L_800F005C;
    }
    // 0x800F0054: nop

    // 0x800F0058: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F005C:
    // 0x800F005C: jr          $ra
    // 0x800F0060: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F0060: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800E5EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E5EC0: addiu       $sp, $sp, -0x580
    ctx->r29 = ADD32(ctx->r29, -0X580);
    // 0x800E5EC4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800E5EC8: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x800E5ECC: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x800E5ED0: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800E5ED4: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800E5ED8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800E5EDC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800E5EE0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800E5EE4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800E5EE8: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x800E5EEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E5EF0: sw          $t6, 0x560($sp)
    MEM_W(0X560, ctx->r29) = ctx->r14;
    // 0x800E5EF4: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x800E5EF8: sw          $t7, 0x55C($sp)
    MEM_W(0X55C, ctx->r29) = ctx->r15;
    // 0x800E5EFC: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x800E5F00: sw          $t8, 0x568($sp)
    MEM_W(0X568, ctx->r29) = ctx->r24;
    // 0x800E5F04: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x800E5F08: sw          $t9, 0x564($sp)
    MEM_W(0X564, ctx->r29) = ctx->r25;
    // 0x800E5F0C: lw          $s3, 0x10($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X10);
    // 0x800E5F10: lw          $s4, 0xC($a0)
    ctx->r20 = MEM_W(ctx->r4, 0XC);
    // 0x800E5F14: sltiu       $at, $s3, 0x5
    ctx->r1 = ctx->r19 < 0X5 ? 1 : 0;
    // 0x800E5F18: beql        $at, $zero, L_800E5F80
    if (ctx->r1 == 0) {
        // 0x800E5F1C: andi        $t6, $s4, 0x1F
        ctx->r14 = ctx->r20 & 0X1F;
            goto L_800E5F80;
    }
    goto skip_0;
    // 0x800E5F1C: andi        $t6, $s4, 0x1F
    ctx->r14 = ctx->r20 & 0X1F;
    skip_0:
    // 0x800E5F20: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
L_800E5F24:
    // 0x800E5F24: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5F28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E5F2C: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E5F30: bnel        $at, $zero, L_800E5F5C
    if (ctx->r1 != 0) {
        // 0x800E5F34: addu        $t2, $s1, $v0
        ctx->r10 = ADD32(ctx->r17, ctx->r2);
            goto L_800E5F5C;
    }
    goto skip_1;
    // 0x800E5F34: addu        $t2, $s1, $v0
    ctx->r10 = ADD32(ctx->r17, ctx->r2);
    skip_1:
    // 0x800E5F38: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E5F3C: jal         0x8001311C
    // 0x800E5F40: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_0;
    // 0x800E5F40: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_0:
    // 0x800E5F44: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x800E5F48: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5F4C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E5F50: addiu       $t1, $t0, 0x1800
    ctx->r9 = ADD32(ctx->r8, 0X1800);
    // 0x800E5F54: sw          $t1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r9;
    // 0x800E5F58: addu        $t2, $s1, $v0
    ctx->r10 = ADD32(ctx->r17, ctx->r2);
L_800E5F5C:
    // 0x800E5F5C: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800E5F60: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x800E5F64: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800E5F68: sllv        $t4, $t3, $s3
    ctx->r12 = S32(ctx->r11 << (ctx->r19 & 31));
    // 0x800E5F6C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800E5F70: sltiu       $at, $s3, 0x5
    ctx->r1 = ctx->r19 < 0X5 ? 1 : 0;
    // 0x800E5F74: bne         $at, $zero, L_800E5F24
    if (ctx->r1 != 0) {
        // 0x800E5F78: or          $s4, $s4, $t4
        ctx->r20 = ctx->r20 | ctx->r12;
            goto L_800E5F24;
    }
    // 0x800E5F78: or          $s4, $s4, $t4
    ctx->r20 = ctx->r20 | ctx->r12;
    // 0x800E5F7C: andi        $t6, $s4, 0x1F
    ctx->r14 = ctx->r20 & 0X1F;
L_800E5F80:
    // 0x800E5F80: addiu       $s3, $s3, -0x5
    ctx->r19 = ADD32(ctx->r19, -0X5);
    // 0x800E5F84: addiu       $t7, $t6, 0x101
    ctx->r15 = ADD32(ctx->r14, 0X101);
    // 0x800E5F88: srl         $t8, $s4, 5
    ctx->r24 = S32(U32(ctx->r20) >> 5);
    // 0x800E5F8C: sltiu       $at, $s3, 0x5
    ctx->r1 = ctx->r19 < 0X5 ? 1 : 0;
    // 0x800E5F90: sw          $t7, 0x554($sp)
    MEM_W(0X554, ctx->r29) = ctx->r15;
    // 0x800E5F94: beq         $at, $zero, L_800E5FF8
    if (ctx->r1 == 0) {
        // 0x800E5F98: or          $s4, $t8, $zero
        ctx->r20 = ctx->r24 | 0;
            goto L_800E5FF8;
    }
    // 0x800E5F98: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x800E5F9C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E5FA0:
    // 0x800E5FA0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E5FA8: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E5FAC: bnel        $at, $zero, L_800E5FD8
    if (ctx->r1 != 0) {
        // 0x800E5FB0: addu        $t1, $s1, $v0
        ctx->r9 = ADD32(ctx->r17, ctx->r2);
            goto L_800E5FD8;
    }
    goto skip_2;
    // 0x800E5FB0: addu        $t1, $s1, $v0
    ctx->r9 = ADD32(ctx->r17, ctx->r2);
    skip_2:
    // 0x800E5FB4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E5FB8: jal         0x8001311C
    // 0x800E5FBC: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_1;
    // 0x800E5FBC: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_1:
    // 0x800E5FC0: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800E5FC4: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5FC8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E5FCC: addiu       $t0, $t9, 0x1800
    ctx->r8 = ADD32(ctx->r25, 0X1800);
    // 0x800E5FD0: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x800E5FD4: addu        $t1, $s1, $v0
    ctx->r9 = ADD32(ctx->r17, ctx->r2);
L_800E5FD8:
    // 0x800E5FD8: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800E5FDC: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x800E5FE0: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x800E5FE4: sllv        $t3, $t2, $s3
    ctx->r11 = S32(ctx->r10 << (ctx->r19 & 31));
    // 0x800E5FE8: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800E5FEC: sltiu       $at, $s3, 0x5
    ctx->r1 = ctx->r19 < 0X5 ? 1 : 0;
    // 0x800E5FF0: bne         $at, $zero, L_800E5FA0
    if (ctx->r1 != 0) {
        // 0x800E5FF4: or          $s4, $s4, $t3
        ctx->r20 = ctx->r20 | ctx->r11;
            goto L_800E5FA0;
    }
    // 0x800E5FF4: or          $s4, $s4, $t3
    ctx->r20 = ctx->r20 | ctx->r11;
L_800E5FF8:
    // 0x800E5FF8: andi        $t5, $s4, 0x1F
    ctx->r13 = ctx->r20 & 0X1F;
    // 0x800E5FFC: addiu       $s3, $s3, -0x5
    ctx->r19 = ADD32(ctx->r19, -0X5);
    // 0x800E6000: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800E6004: srl         $t7, $s4, 5
    ctx->r15 = S32(U32(ctx->r20) >> 5);
    // 0x800E6008: sltiu       $at, $s3, 0x4
    ctx->r1 = ctx->r19 < 0X4 ? 1 : 0;
    // 0x800E600C: sw          $t6, 0x550($sp)
    MEM_W(0X550, ctx->r29) = ctx->r14;
    // 0x800E6010: beq         $at, $zero, L_800E6074
    if (ctx->r1 == 0) {
        // 0x800E6014: or          $s4, $t7, $zero
        ctx->r20 = ctx->r15 | 0;
            goto L_800E6074;
    }
    // 0x800E6014: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x800E6018: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E601C:
    // 0x800E601C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E6020: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E6024: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E6028: bnel        $at, $zero, L_800E6054
    if (ctx->r1 != 0) {
        // 0x800E602C: addu        $t0, $s1, $v0
        ctx->r8 = ADD32(ctx->r17, ctx->r2);
            goto L_800E6054;
    }
    goto skip_3;
    // 0x800E602C: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
    skip_3:
    // 0x800E6030: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E6034: jal         0x8001311C
    // 0x800E6038: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_2;
    // 0x800E6038: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_2:
    // 0x800E603C: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x800E6040: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E6044: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E6048: addiu       $t9, $t8, 0x1800
    ctx->r25 = ADD32(ctx->r24, 0X1800);
    // 0x800E604C: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
    // 0x800E6050: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
L_800E6054:
    // 0x800E6054: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x800E6058: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x800E605C: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800E6060: sllv        $t2, $t1, $s3
    ctx->r10 = S32(ctx->r9 << (ctx->r19 & 31));
    // 0x800E6064: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800E6068: sltiu       $at, $s3, 0x4
    ctx->r1 = ctx->r19 < 0X4 ? 1 : 0;
    // 0x800E606C: bne         $at, $zero, L_800E601C
    if (ctx->r1 != 0) {
        // 0x800E6070: or          $s4, $s4, $t2
        ctx->r20 = ctx->r20 | ctx->r10;
            goto L_800E601C;
    }
    // 0x800E6070: or          $s4, $s4, $t2
    ctx->r20 = ctx->r20 | ctx->r10;
L_800E6074:
    // 0x800E6074: andi        $s6, $s4, 0xF
    ctx->r22 = ctx->r20 & 0XF;
    // 0x800E6078: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800E607C: srl         $t4, $s4, 4
    ctx->r12 = S32(U32(ctx->r20) >> 4);
    // 0x800E6080: or          $s4, $t4, $zero
    ctx->r20 = ctx->r12 | 0;
    // 0x800E6084: addiu       $s3, $s3, -0x4
    ctx->r19 = ADD32(ctx->r19, -0X4);
    // 0x800E6088: beq         $s6, $zero, L_800E6130
    if (ctx->r22 == 0) {
        // 0x800E608C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800E6130;
    }
    // 0x800E608C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800E6090: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800E6094: addiu       $s5, $s5, 0x31F0
    ctx->r21 = ADD32(ctx->r21, 0X31F0);
    // 0x800E6098: addiu       $s7, $sp, 0x60
    ctx->r23 = ADD32(ctx->r29, 0X60);
L_800E609C:
    // 0x800E609C: sltiu       $at, $s3, 0x3
    ctx->r1 = ctx->r19 < 0X3 ? 1 : 0;
    // 0x800E60A0: beql        $at, $zero, L_800E6108
    if (ctx->r1 == 0) {
        // 0x800E60A4: lbu         $t2, 0x0($s5)
        ctx->r10 = MEM_BU(ctx->r21, 0X0);
            goto L_800E6108;
    }
    goto skip_4;
    // 0x800E60A4: lbu         $t2, 0x0($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X0);
    skip_4:
    // 0x800E60A8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E60AC:
    // 0x800E60AC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E60B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E60B4: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E60B8: bnel        $at, $zero, L_800E60E4
    if (ctx->r1 != 0) {
        // 0x800E60BC: addu        $t7, $s1, $v0
        ctx->r15 = ADD32(ctx->r17, ctx->r2);
            goto L_800E60E4;
    }
    goto skip_5;
    // 0x800E60BC: addu        $t7, $s1, $v0
    ctx->r15 = ADD32(ctx->r17, ctx->r2);
    skip_5:
    // 0x800E60C0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E60C4: jal         0x8001311C
    // 0x800E60C8: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_3;
    // 0x800E60C8: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_3:
    // 0x800E60CC: lw          $t5, 0x30($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X30);
    // 0x800E60D0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E60D4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E60D8: addiu       $t6, $t5, 0x1800
    ctx->r14 = ADD32(ctx->r13, 0X1800);
    // 0x800E60DC: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
    // 0x800E60E0: addu        $t7, $s1, $v0
    ctx->r15 = ADD32(ctx->r17, ctx->r2);
L_800E60E4:
    // 0x800E60E4: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800E60E8: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x800E60EC: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x800E60F0: sllv        $t9, $t8, $s3
    ctx->r25 = S32(ctx->r24 << (ctx->r19 & 31));
    // 0x800E60F4: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800E60F8: sltiu       $at, $s3, 0x3
    ctx->r1 = ctx->r19 < 0X3 ? 1 : 0;
    // 0x800E60FC: bne         $at, $zero, L_800E60AC
    if (ctx->r1 != 0) {
        // 0x800E6100: or          $s4, $s4, $t9
        ctx->r20 = ctx->r20 | ctx->r25;
            goto L_800E60AC;
    }
    // 0x800E6100: or          $s4, $s4, $t9
    ctx->r20 = ctx->r20 | ctx->r25;
    // 0x800E6104: lbu         $t2, 0x0($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X0);
L_800E6108:
    // 0x800E6108: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800E610C: andi        $t1, $s4, 0x7
    ctx->r9 = ctx->r20 & 0X7;
    // 0x800E6110: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800E6114: addu        $t4, $s7, $t3
    ctx->r12 = ADD32(ctx->r23, ctx->r11);
    // 0x800E6118: srl         $t5, $s4, 3
    ctx->r13 = S32(U32(ctx->r20) >> 3);
    // 0x800E611C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800E6120: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x800E6124: or          $s4, $t5, $zero
    ctx->r20 = ctx->r13 | 0;
    // 0x800E6128: bne         $s2, $s6, L_800E609C
    if (ctx->r18 != ctx->r22) {
        // 0x800E612C: addiu       $s3, $s3, -0x3
        ctx->r19 = ADD32(ctx->r19, -0X3);
            goto L_800E609C;
    }
    // 0x800E612C: addiu       $s3, $s3, -0x3
    ctx->r19 = ADD32(ctx->r19, -0X3);
L_800E6130:
    // 0x800E6130: sltiu       $at, $s2, 0x13
    ctx->r1 = ctx->r18 < 0X13 ? 1 : 0;
    // 0x800E6134: beq         $at, $zero, L_800E616C
    if (ctx->r1 == 0) {
        // 0x800E6138: addiu       $s7, $sp, 0x60
        ctx->r23 = ADD32(ctx->r29, 0X60);
            goto L_800E616C;
    }
    // 0x800E6138: addiu       $s7, $sp, 0x60
    ctx->r23 = ADD32(ctx->r29, 0X60);
    // 0x800E613C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800E6140: addiu       $t6, $t6, 0x31F0
    ctx->r14 = ADD32(ctx->r14, 0X31F0);
    // 0x800E6144: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800E6148: addiu       $v0, $v0, 0x3203
    ctx->r2 = ADD32(ctx->r2, 0X3203);
    // 0x800E614C: addu        $s5, $s2, $t6
    ctx->r21 = ADD32(ctx->r18, ctx->r14);
L_800E6150:
    // 0x800E6150: lbu         $t7, 0x0($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X0);
    // 0x800E6154: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800E6158: sltu        $at, $s5, $v0
    ctx->r1 = ctx->r21 < ctx->r2 ? 1 : 0;
    // 0x800E615C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800E6160: addu        $t9, $s7, $t8
    ctx->r25 = ADD32(ctx->r23, ctx->r24);
    // 0x800E6164: bne         $at, $zero, L_800E6150
    if (ctx->r1 != 0) {
        // 0x800E6168: sw          $zero, 0x0($t9)
        MEM_W(0X0, ctx->r25) = 0;
            goto L_800E6150;
    }
    // 0x800E6168: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_800E616C:
    // 0x800E616C: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800E6170: addiu       $t2, $sp, 0x568
    ctx->r10 = ADD32(ctx->r29, 0X568);
    // 0x800E6174: addiu       $t3, $sp, 0x560
    ctx->r11 = ADD32(ctx->r29, 0X560);
    // 0x800E6178: sw          $t0, 0x560($sp)
    MEM_W(0X560, ctx->r29) = ctx->r8;
    // 0x800E617C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800E6180: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800E6184: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800E6188: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x800E618C: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x800E6190: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E6194: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800E6198: jal         0x800E589C
    // 0x800E619C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_800E589C(rdram, ctx);
        goto after_4;
    // 0x800E619C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_4:
    // 0x800E61A0: lw          $t5, 0x560($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X560);
    // 0x800E61A4: lw          $t1, 0x554($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X554);
    // 0x800E61A8: lw          $t4, 0x550($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X550);
    // 0x800E61AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800E61B0: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800E61B4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800E61B8: lhu         $t7, 0x32C0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X32C0);
    // 0x800E61BC: addu        $v0, $t1, $t4
    ctx->r2 = ADD32(ctx->r9, ctx->r12);
    // 0x800E61C0: sw          $v0, 0x56C($sp)
    MEM_W(0X56C, ctx->r29) = ctx->r2;
    // 0x800E61C4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800E61C8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800E61CC: beq         $v0, $zero, L_800E64BC
    if (ctx->r2 == 0) {
        // 0x800E61D0: sw          $t7, 0x570($sp)
        MEM_W(0X570, ctx->r29) = ctx->r15;
            goto L_800E64BC;
    }
    // 0x800E61D0: sw          $t7, 0x570($sp)
    MEM_W(0X570, ctx->r29) = ctx->r15;
    // 0x800E61D4: lw          $t8, 0x560($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X560);
L_800E61D8:
    // 0x800E61D8: sltu        $at, $s3, $t8
    ctx->r1 = ctx->r19 < ctx->r24 ? 1 : 0;
    // 0x800E61DC: beql        $at, $zero, L_800E6248
    if (ctx->r1 == 0) {
        // 0x800E61E0: lw          $t6, 0x570($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X570);
            goto L_800E6248;
    }
    goto skip_6;
    // 0x800E61E0: lw          $t6, 0x570($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X570);
    skip_6:
    // 0x800E61E4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E61E8:
    // 0x800E61E8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E61EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E61F0: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E61F4: bnel        $at, $zero, L_800E6220
    if (ctx->r1 != 0) {
        // 0x800E61F8: addu        $t2, $s1, $v0
        ctx->r10 = ADD32(ctx->r17, ctx->r2);
            goto L_800E6220;
    }
    goto skip_7;
    // 0x800E61F8: addu        $t2, $s1, $v0
    ctx->r10 = ADD32(ctx->r17, ctx->r2);
    skip_7:
    // 0x800E61FC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E6200: jal         0x8001311C
    // 0x800E6204: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_5;
    // 0x800E6204: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_5:
    // 0x800E6208: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800E620C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E6210: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E6214: addiu       $t0, $t9, 0x1800
    ctx->r8 = ADD32(ctx->r25, 0X1800);
    // 0x800E6218: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x800E621C: addu        $t2, $s1, $v0
    ctx->r10 = ADD32(ctx->r17, ctx->r2);
L_800E6220:
    // 0x800E6220: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800E6224: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x800E6228: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x800E622C: lw          $t5, 0x560($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X560);
    // 0x800E6230: sllv        $t1, $t3, $s3
    ctx->r9 = S32(ctx->r11 << (ctx->r19 & 31));
    // 0x800E6234: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800E6238: sltu        $at, $s3, $t5
    ctx->r1 = ctx->r19 < ctx->r13 ? 1 : 0;
    // 0x800E623C: bne         $at, $zero, L_800E61E8
    if (ctx->r1 != 0) {
        // 0x800E6240: or          $s4, $s4, $t1
        ctx->r20 = ctx->r20 | ctx->r9;
            goto L_800E61E8;
    }
    // 0x800E6240: or          $s4, $s4, $t1
    ctx->r20 = ctx->r20 | ctx->r9;
    // 0x800E6244: lw          $t6, 0x570($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X570);
L_800E6248:
    // 0x800E6248: lw          $t9, 0x568($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X568);
    // 0x800E624C: sll         $t2, $s5, 2
    ctx->r10 = S32(ctx->r21 << 2);
    // 0x800E6250: and         $t7, $s4, $t6
    ctx->r15 = ctx->r20 & ctx->r14;
    // 0x800E6254: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800E6258: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800E625C: sw          $t0, 0x564($sp)
    MEM_W(0X564, ctx->r29) = ctx->r8;
    // 0x800E6260: lbu         $s2, 0x1($t0)
    ctx->r18 = MEM_BU(ctx->r8, 0X1);
    // 0x800E6264: addu        $t3, $s7, $t2
    ctx->r11 = ADD32(ctx->r23, ctx->r10);
    // 0x800E6268: srlv        $s4, $s4, $s2
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r18 & 31));
    // 0x800E626C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800E6270: lhu         $s2, 0x4($t0)
    ctx->r18 = MEM_HU(ctx->r8, 0X4);
    // 0x800E6274: sltiu       $at, $s2, 0x10
    ctx->r1 = ctx->r18 < 0X10 ? 1 : 0;
    // 0x800E6278: beql        $at, $zero, L_800E6294
    if (ctx->r1 == 0) {
        // 0x800E627C: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800E6294;
    }
    goto skip_8;
    // 0x800E627C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_8:
    // 0x800E6280: or          $s6, $s2, $zero
    ctx->r22 = ctx->r18 | 0;
    // 0x800E6284: sw          $s2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r18;
    // 0x800E6288: b           L_800E64AC
    // 0x800E628C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
        goto L_800E64AC;
    // 0x800E628C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800E6290: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_800E6294:
    // 0x800E6294: bne         $s2, $at, L_800E6348
    if (ctx->r18 != ctx->r1) {
        // 0x800E6298: sltiu       $at, $s3, 0x2
        ctx->r1 = ctx->r19 < 0X2 ? 1 : 0;
            goto L_800E6348;
    }
    // 0x800E6298: sltiu       $at, $s3, 0x2
    ctx->r1 = ctx->r19 < 0X2 ? 1 : 0;
    // 0x800E629C: beql        $at, $zero, L_800E6304
    if (ctx->r1 == 0) {
        // 0x800E62A0: andi        $s2, $s4, 0x3
        ctx->r18 = ctx->r20 & 0X3;
            goto L_800E6304;
    }
    goto skip_9;
    // 0x800E62A0: andi        $s2, $s4, 0x3
    ctx->r18 = ctx->r20 & 0X3;
    skip_9:
    // 0x800E62A4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E62A8:
    // 0x800E62A8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E62AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E62B0: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E62B4: bnel        $at, $zero, L_800E62E0
    if (ctx->r1 != 0) {
        // 0x800E62B8: addu        $t5, $s1, $v0
        ctx->r13 = ADD32(ctx->r17, ctx->r2);
            goto L_800E62E0;
    }
    goto skip_10;
    // 0x800E62B8: addu        $t5, $s1, $v0
    ctx->r13 = ADD32(ctx->r17, ctx->r2);
    skip_10:
    // 0x800E62BC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E62C0: jal         0x8001311C
    // 0x800E62C4: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_6;
    // 0x800E62C4: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_6:
    // 0x800E62C8: lw          $t1, 0x30($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X30);
    // 0x800E62CC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E62D0: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E62D4: addiu       $t4, $t1, 0x1800
    ctx->r12 = ADD32(ctx->r9, 0X1800);
    // 0x800E62D8: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
    // 0x800E62DC: addu        $t5, $s1, $v0
    ctx->r13 = ADD32(ctx->r17, ctx->r2);
L_800E62E0:
    // 0x800E62E0: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800E62E4: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x800E62E8: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800E62EC: sllv        $t7, $t6, $s3
    ctx->r15 = S32(ctx->r14 << (ctx->r19 & 31));
    // 0x800E62F0: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800E62F4: sltiu       $at, $s3, 0x2
    ctx->r1 = ctx->r19 < 0X2 ? 1 : 0;
    // 0x800E62F8: bne         $at, $zero, L_800E62A8
    if (ctx->r1 != 0) {
        // 0x800E62FC: or          $s4, $s4, $t7
        ctx->r20 = ctx->r20 | ctx->r15;
            goto L_800E62A8;
    }
    // 0x800E62FC: or          $s4, $s4, $t7
    ctx->r20 = ctx->r20 | ctx->r15;
    // 0x800E6300: andi        $s2, $s4, 0x3
    ctx->r18 = ctx->r20 & 0X3;
L_800E6304:
    // 0x800E6304: addiu       $s2, $s2, 0x3
    ctx->r18 = ADD32(ctx->r18, 0X3);
    // 0x800E6308: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800E630C: srl         $t9, $s4, 2
    ctx->r25 = S32(U32(ctx->r20) >> 2);
    // 0x800E6310: or          $s4, $t9, $zero
    ctx->r20 = ctx->r25 | 0;
    // 0x800E6314: addiu       $s3, $s3, -0x2
    ctx->r19 = ADD32(ctx->r19, -0X2);
    // 0x800E6318: beq         $s2, $zero, L_800E64AC
    if (ctx->r18 == 0) {
        // 0x800E631C: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_800E64AC;
    }
    // 0x800E631C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800E6320: sll         $t0, $s5, 2
    ctx->r8 = S32(ctx->r21 << 2);
    // 0x800E6324: addu        $v0, $s7, $t0
    ctx->r2 = ADD32(ctx->r23, ctx->r8);
L_800E6328:
    // 0x800E6328: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800E632C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x800E6330: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800E6334: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800E6338: bne         $s2, $zero, L_800E6328
    if (ctx->r18 != 0) {
        // 0x800E633C: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_800E6328;
    }
    // 0x800E633C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800E6340: b           L_800E64B0
    // 0x800E6344: lw          $t7, 0x56C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X56C);
        goto L_800E64B0;
    // 0x800E6344: lw          $t7, 0x56C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X56C);
L_800E6348:
    // 0x800E6348: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800E634C: bne         $s2, $at, L_800E6404
    if (ctx->r18 != ctx->r1) {
        // 0x800E6350: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_800E6404;
    }
    // 0x800E6350: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800E6354: sltiu       $at, $s3, 0x3
    ctx->r1 = ctx->r19 < 0X3 ? 1 : 0;
    // 0x800E6358: beql        $at, $zero, L_800E63C0
    if (ctx->r1 == 0) {
        // 0x800E635C: andi        $s2, $s4, 0x7
        ctx->r18 = ctx->r20 & 0X7;
            goto L_800E63C0;
    }
    goto skip_11;
    // 0x800E635C: andi        $s2, $s4, 0x7
    ctx->r18 = ctx->r20 & 0X7;
    skip_11:
    // 0x800E6360: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E6364:
    // 0x800E6364: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E6368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E636C: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E6370: bnel        $at, $zero, L_800E639C
    if (ctx->r1 != 0) {
        // 0x800E6374: addu        $t1, $s1, $v0
        ctx->r9 = ADD32(ctx->r17, ctx->r2);
            goto L_800E639C;
    }
    goto skip_12;
    // 0x800E6374: addu        $t1, $s1, $v0
    ctx->r9 = ADD32(ctx->r17, ctx->r2);
    skip_12:
    // 0x800E6378: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E637C: jal         0x8001311C
    // 0x800E6380: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_7;
    // 0x800E6380: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_7:
    // 0x800E6384: lw          $t2, 0x30($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X30);
    // 0x800E6388: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E638C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E6390: addiu       $t3, $t2, 0x1800
    ctx->r11 = ADD32(ctx->r10, 0X1800);
    // 0x800E6394: sw          $t3, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r11;
    // 0x800E6398: addu        $t1, $s1, $v0
    ctx->r9 = ADD32(ctx->r17, ctx->r2);
L_800E639C:
    // 0x800E639C: lbu         $t4, 0x0($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X0);
    // 0x800E63A0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800E63A4: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800E63A8: sllv        $t5, $t4, $s3
    ctx->r13 = S32(ctx->r12 << (ctx->r19 & 31));
    // 0x800E63AC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800E63B0: sltiu       $at, $s3, 0x3
    ctx->r1 = ctx->r19 < 0X3 ? 1 : 0;
    // 0x800E63B4: bne         $at, $zero, L_800E6364
    if (ctx->r1 != 0) {
        // 0x800E63B8: or          $s4, $s4, $t5
        ctx->r20 = ctx->r20 | ctx->r13;
            goto L_800E6364;
    }
    // 0x800E63B8: or          $s4, $s4, $t5
    ctx->r20 = ctx->r20 | ctx->r13;
    // 0x800E63BC: andi        $s2, $s4, 0x7
    ctx->r18 = ctx->r20 & 0X7;
L_800E63C0:
    // 0x800E63C0: addiu       $s2, $s2, 0x3
    ctx->r18 = ADD32(ctx->r18, 0X3);
    // 0x800E63C4: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800E63C8: srl         $t7, $s4, 3
    ctx->r15 = S32(U32(ctx->r20) >> 3);
    // 0x800E63CC: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x800E63D0: addiu       $s3, $s3, -0x3
    ctx->r19 = ADD32(ctx->r19, -0X3);
    // 0x800E63D4: beq         $s2, $zero, L_800E64AC
    if (ctx->r18 == 0) {
        // 0x800E63D8: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_800E64AC;
    }
    // 0x800E63D8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800E63DC: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x800E63E0: addu        $v0, $s7, $t8
    ctx->r2 = ADD32(ctx->r23, ctx->r24);
L_800E63E4:
    // 0x800E63E4: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800E63E8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800E63EC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800E63F0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800E63F4: bne         $s2, $zero, L_800E63E4
    if (ctx->r18 != 0) {
        // 0x800E63F8: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_800E63E4;
    }
    // 0x800E63F8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800E63FC: b           L_800E64B0
    // 0x800E6400: lw          $t7, 0x56C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X56C);
        goto L_800E64B0;
    // 0x800E6400: lw          $t7, 0x56C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X56C);
L_800E6404:
    // 0x800E6404: sltiu       $at, $s3, 0x7
    ctx->r1 = ctx->r19 < 0X7 ? 1 : 0;
    // 0x800E6408: beql        $at, $zero, L_800E6470
    if (ctx->r1 == 0) {
        // 0x800E640C: andi        $s2, $s4, 0x7F
        ctx->r18 = ctx->r20 & 0X7F;
            goto L_800E6470;
    }
    goto skip_13;
    // 0x800E640C: andi        $s2, $s4, 0x7F
    ctx->r18 = ctx->r20 & 0X7F;
    skip_13:
    // 0x800E6410: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E6414:
    // 0x800E6414: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E6418: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E641C: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E6420: bnel        $at, $zero, L_800E644C
    if (ctx->r1 != 0) {
        // 0x800E6424: addu        $t2, $s1, $v0
        ctx->r10 = ADD32(ctx->r17, ctx->r2);
            goto L_800E644C;
    }
    goto skip_14;
    // 0x800E6424: addu        $t2, $s1, $v0
    ctx->r10 = ADD32(ctx->r17, ctx->r2);
    skip_14:
    // 0x800E6428: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E642C: jal         0x8001311C
    // 0x800E6430: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_8;
    // 0x800E6430: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_8:
    // 0x800E6434: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800E6438: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E643C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E6440: addiu       $t0, $t9, 0x1800
    ctx->r8 = ADD32(ctx->r25, 0X1800);
    // 0x800E6444: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x800E6448: addu        $t2, $s1, $v0
    ctx->r10 = ADD32(ctx->r17, ctx->r2);
L_800E644C:
    // 0x800E644C: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800E6450: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x800E6454: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x800E6458: sllv        $t1, $t3, $s3
    ctx->r9 = S32(ctx->r11 << (ctx->r19 & 31));
    // 0x800E645C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800E6460: sltiu       $at, $s3, 0x7
    ctx->r1 = ctx->r19 < 0X7 ? 1 : 0;
    // 0x800E6464: bne         $at, $zero, L_800E6414
    if (ctx->r1 != 0) {
        // 0x800E6468: or          $s4, $s4, $t1
        ctx->r20 = ctx->r20 | ctx->r9;
            goto L_800E6414;
    }
    // 0x800E6468: or          $s4, $s4, $t1
    ctx->r20 = ctx->r20 | ctx->r9;
    // 0x800E646C: andi        $s2, $s4, 0x7F
    ctx->r18 = ctx->r20 & 0X7F;
L_800E6470:
    // 0x800E6470: addiu       $s2, $s2, 0xB
    ctx->r18 = ADD32(ctx->r18, 0XB);
    // 0x800E6474: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800E6478: srl         $t5, $s4, 7
    ctx->r13 = S32(U32(ctx->r20) >> 7);
    // 0x800E647C: or          $s4, $t5, $zero
    ctx->r20 = ctx->r13 | 0;
    // 0x800E6480: addiu       $s3, $s3, -0x7
    ctx->r19 = ADD32(ctx->r19, -0X7);
    // 0x800E6484: beq         $s2, $zero, L_800E64AC
    if (ctx->r18 == 0) {
        // 0x800E6488: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_800E64AC;
    }
    // 0x800E6488: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800E648C: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x800E6490: addu        $v0, $s7, $t6
    ctx->r2 = ADD32(ctx->r23, ctx->r14);
L_800E6494:
    // 0x800E6494: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800E6498: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800E649C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800E64A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800E64A4: bne         $s2, $zero, L_800E6494
    if (ctx->r18 != 0) {
        // 0x800E64A8: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_800E6494;
    }
    // 0x800E64A8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_800E64AC:
    // 0x800E64AC: lw          $t7, 0x56C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X56C);
L_800E64B0:
    // 0x800E64B0: sltu        $at, $s5, $t7
    ctx->r1 = ctx->r21 < ctx->r15 ? 1 : 0;
    // 0x800E64B4: bnel        $at, $zero, L_800E61D8
    if (ctx->r1 != 0) {
        // 0x800E64B8: lw          $t8, 0x560($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X560);
            goto L_800E61D8;
    }
    goto skip_15;
    // 0x800E64B8: lw          $t8, 0x560($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X560);
    skip_15:
L_800E64BC:
    // 0x800E64BC: sw          $s4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r20;
    // 0x800E64C0: sw          $s3, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r19;
    // 0x800E64C4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800E64C8: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x800E64CC: addiu       $t9, $t9, 0x3244
    ctx->r25 = ADD32(ctx->r25, 0X3244);
    // 0x800E64D0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800E64D4: addiu       $t0, $sp, 0x568
    ctx->r8 = ADD32(ctx->r29, 0X568);
    // 0x800E64D8: addiu       $t2, $sp, 0x560
    ctx->r10 = ADD32(ctx->r29, 0X560);
    // 0x800E64DC: sw          $t8, 0x560($sp)
    MEM_W(0X560, ctx->r29) = ctx->r24;
    // 0x800E64E0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800E64E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800E64E8: addiu       $a3, $a3, 0x3204
    ctx->r7 = ADD32(ctx->r7, 0X3204);
    // 0x800E64EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800E64F0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800E64F4: lw          $a1, 0x554($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X554);
    // 0x800E64F8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800E64FC: jal         0x800E589C
    // 0x800E6500: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    func_800E589C(rdram, ctx);
        goto after_9;
    // 0x800E6500: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    after_9:
    // 0x800E6504: lw          $t1, 0x554($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X554);
    // 0x800E6508: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800E650C: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800E6510: addiu       $t5, $t5, 0x32A0
    ctx->r13 = ADD32(ctx->r13, 0X32A0);
    // 0x800E6514: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800E6518: addiu       $t6, $sp, 0x564
    ctx->r14 = ADD32(ctx->r29, 0X564);
    // 0x800E651C: addiu       $t7, $sp, 0x55C
    ctx->r15 = ADD32(ctx->r29, 0X55C);
    // 0x800E6520: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x800E6524: sw          $t3, 0x55C($sp)
    MEM_W(0X55C, ctx->r29) = ctx->r11;
    // 0x800E6528: addu        $a0, $s7, $t4
    ctx->r4 = ADD32(ctx->r23, ctx->r12);
    // 0x800E652C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800E6530: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800E6534: addiu       $a3, $a3, 0x3264
    ctx->r7 = ADD32(ctx->r7, 0X3264);
    // 0x800E6538: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800E653C: lw          $a1, 0x550($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X550);
    // 0x800E6540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E6544: jal         0x800E589C
    // 0x800E6548: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_800E589C(rdram, ctx);
        goto after_10;
    // 0x800E6548: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_10:
    // 0x800E654C: lw          $t8, 0x560($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X560);
    // 0x800E6550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E6554: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x800E6558: lw          $t9, 0x55C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X55C);
    // 0x800E655C: sw          $t9, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r25;
    // 0x800E6560: lw          $t0, 0x568($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X568);
    // 0x800E6564: sw          $t0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r8;
    // 0x800E6568: lw          $t2, 0x564($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X564);
    // 0x800E656C: sw          $t2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r10;
    // 0x800E6570: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800E6574: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x800E6578: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x800E657C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800E6580: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800E6584: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800E6588: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800E658C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800E6590: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800E6594: jr          $ra
    // 0x800E6598: addiu       $sp, $sp, 0x580
    ctx->r29 = ADD32(ctx->r29, 0X580);
    return;
    // 0x800E6598: addiu       $sp, $sp, 0x580
    ctx->r29 = ADD32(ctx->r29, 0X580);
;}
RECOMP_FUNC void _ncbapan_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800891B8: syscall     765
    recomp_syscall_handler(rdram, ctx, 0x800891B8);
    return;
    // 0x800891BC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chbiggafoot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1216, 0X10DC) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x10DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1216, 0X10DC));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x10DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1216, 0X10DC));
;}
RECOMP_FUNC void func_80800000_chwumbawigwam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
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
    // 0x80800014: addiu       $at, $zero, 0x112
    ctx->r1 = ADD32(0, 0X112);
    // 0x80800018: bnel        $v0, $at, L_80800148
    if (ctx->r2 != ctx->r1) {
        // 0x8080001C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800148;
    }
    goto skip_0;
    // 0x8080001C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800020: jal         0x800DA298
    // 0x80800024: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800024: addiu       $a0, $zero, 0x18A
    ctx->r4 = ADD32(0, 0X18A);
    after_1:
    // 0x80800028: beql        $v0, $zero, L_80800054
    if (ctx->r2 == 0) {
        // 0x8080002C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800054;
    }
    goto skip_1;
    // 0x8080002C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x80800030: jal         0x800EA05C
    // 0x80800034: nop

    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x80800034: nop

    after_2:
    // 0x80800038: addiu       $at, $zero, 0x112
    ctx->r1 = ADD32(0, 0X112);
    // 0x8080003C: bne         $v0, $at, L_80800050
    if (ctx->r2 != ctx->r1) {
        // 0x80800040: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2272, 0X1080) << 16);
            goto L_80800050;
    }
    // 0x80800040: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2272, 0X1080) << 16);
    // 0x80800044: lwc1        $f4, 0x1080($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2272, 0X1080));
    // 0x80800048: b           L_80800060
    // 0x8080004C: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
        goto L_80800060;
    // 0x8080004C: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
L_80800050:
    // 0x80800050: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800054:
    // 0x80800054: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800058: nop

    // 0x8080005C: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
L_80800060:
    // 0x80800060: jal         0x80103EAC
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_3;
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800068: jal         0x800F54E4
    // 0x8080006C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x8080006C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80800070: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800074: jal         0x800F64A4
    // 0x80800078: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    func_800F64A4(rdram, ctx);
        goto after_5;
    // 0x80800078: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    after_5:
    // 0x8080007C: beq         $v0, $zero, L_80800094
    if (ctx->r2 == 0) {
        // 0x80800080: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2272, 0X1084) << 16);
            goto L_80800094;
    }
    // 0x80800080: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2272, 0X1084) << 16);
    // 0x80800084: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800088: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080008C: b           L_80800098
    // 0x80800090: nop

        goto L_80800098;
    // 0x80800090: nop

L_80800094:
    // 0x80800094: lwc1        $f2, 0x1084($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2272, 0X1084));
L_80800098:
    // 0x80800098: jal         0x800F54E4
    // 0x8080009C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x8080009C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x808000A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000A4: jal         0x800F64A4
    // 0x808000A8: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    func_800F64A4(rdram, ctx);
        goto after_7;
    // 0x808000A8: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    after_7:
    // 0x808000AC: beq         $v0, $zero, L_808000C4
    if (ctx->r2 == 0) {
        // 0x808000B0: lwc1        $f2, 0x2C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_808000C4;
    }
    // 0x808000B0: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808000B4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808000B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808000BC: b           L_808000DC
    // 0x808000C0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
        goto L_808000DC;
    // 0x808000C0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
L_808000C4:
    // 0x808000C4: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x808000C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808000CC: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808000D0: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808000D4: nop

    // 0x808000D8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
L_808000DC:
    // 0x808000DC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808000E0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808000E4: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x808000E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808000EC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808000F0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808000F4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808000F8: jal         0x8010C9FC
    // 0x808000FC: nop

    func_8010C9FC(rdram, ctx);
        goto after_8;
    // 0x808000FC: nop

    after_8:
    // 0x80800100: beq         $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x80800104: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080011C;
    }
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x80800B9C
    // 0x80800110: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800B9C_chwumbawigwam(rdram, ctx);
        goto after_9;
    // 0x80800110: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800114: b           L_80800128
    // 0x80800118: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_80800128;
    // 0x80800118: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8080011C:
    // 0x8080011C: jal         0x80800B9C
    // 0x80800120: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800B9C_chwumbawigwam(rdram, ctx);
        goto after_10;
    // 0x80800120: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800124: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800128:
    // 0x80800128: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080012C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800130: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800134: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800138: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080013C: jal         0x800EFA4C
    // 0x80800140: nop

    func_800EFA4C(rdram, ctx);
        goto after_11;
    // 0x80800140: nop

    after_11:
    // 0x80800144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800148:
    // 0x80800148: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080014C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800150: jr          $ra
    // 0x80800154: nop

    return;
    // 0x80800154: nop

;}
RECOMP_FUNC void func_8080000C_chmumboskulls(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x8010A800
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A800(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

;}
RECOMP_FUNC void func_8010A980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A980: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010A984: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010A988: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010A98C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010A990: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8010A994: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8010A998: jal         0x8010A698
    // 0x8010A99C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_8010A698(rdram, ctx);
        goto after_0;
    // 0x8010A99C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010A9A0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8010A9A4: jal         0x8010A624
    // 0x8010A9A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_1;
    // 0x8010A9A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8010A9AC: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8010A9B0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8010A9B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010A9B8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8010A9BC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010A9C0: addiu       $a2, $a2, 0x6F30
    ctx->r6 = ADD32(ctx->r6, 0X6F30);
    // 0x8010A9C4: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8010A9C8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8010A9CC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8010A9D0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8010A9D4: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8010A9D8: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x8010A9DC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8010A9E0: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8010A9E4: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8010A9E8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8010A9EC: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8010A9F0: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8010A9F4: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8010A9F8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8010A9FC: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8010AA00: jal         0x800C6A7C
    // 0x8010AA04: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800C6A7C(rdram, ctx);
        goto after_2;
    // 0x8010AA04: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_2:
    // 0x8010AA08: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010AA0C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8010AA10: addiu       $a0, $a0, 0x6F20
    ctx->r4 = ADD32(ctx->r4, 0X6F20);
    // 0x8010AA14: jal         0x800EE7F8
    // 0x8010AA18: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x8010AA18: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x8010AA1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010AA20: jal         0x8010A654
    // 0x8010AA24: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8010A654(rdram, ctx);
        goto after_4;
    // 0x8010AA24: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x8010AA28: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8010AA2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010AA30: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010AA34: beq         $t6, $zero, L_8010AA44
    if (ctx->r14 == 0) {
        // 0x8010AA38: nop
    
            goto L_8010AA44;
    }
    // 0x8010AA38: nop

    // 0x8010AA3C: b           L_8010AA44
    // 0x8010AA40: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8010AA44;
    // 0x8010AA40: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8010AA44:
    // 0x8010AA44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010AA48: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8010AA4C: jr          $ra
    // 0x8010AA50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8010AA50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _idwater_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E68: syscall     744
    recomp_syscall_handler(rdram, ctx, 0x80088E68);
    return;
    // 0x80088E6C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _capod_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856B0: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x800856B0);
    return;
    // 0x800856B4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chnests_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A98: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085A98);
    return;
    // 0x80085A9C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void subaddiedialog_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808001BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808001C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001CC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808001D0: jal         0x80800000
    // 0x808001D4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_80800000_subaddiedialog(rdram, ctx);
        goto after_0;
    // 0x808001D4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x808001D8: bne         $v0, $zero, L_808001E8
    if (ctx->r2 != 0) {
        // 0x808001DC: nop
    
            goto L_808001E8;
    }
    // 0x808001DC: nop

    // 0x808001E0: b           L_80800250
    // 0x808001E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800250;
    // 0x808001E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001E8:
    // 0x808001E8: jal         0x800F54E4
    // 0x808001EC: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808001EC: nop

    after_1:
    // 0x808001F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001F4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808001F8: jal         0x800F4B8C
    // 0x808001FC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800F4B8C(rdram, ctx);
        goto after_2;
    // 0x808001FC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800200: bne         $v0, $zero, L_80800210
    if (ctx->r2 != 0) {
        // 0x80800204: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800210;
    }
    // 0x80800204: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800208: b           L_80800250
    // 0x8080020C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800250;
    // 0x8080020C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800210:
    // 0x80800210: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800214: jal         0x8080110C
    // 0x80800218: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_8080110C_subaddiedialog(rdram, ctx);
        goto after_3;
    // 0x80800218: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x8080021C: beq         $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x80800220: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080023C;
    }
    // 0x80800220: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800224: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800228: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080022C: jal         0x8080118C
    // 0x80800230: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_8080118C_subaddiedialog(rdram, ctx);
        goto after_4;
    // 0x80800230: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800234: bnel        $v0, $zero, L_80800250
    if (ctx->r2 != 0) {
        // 0x80800238: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800250;
    }
    goto skip_0;
    // 0x80800238: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
L_8080023C:
    // 0x8080023C: jal         0x8080141C
    // 0x80800240: nop

    func_8080141C_subaddiedialog(rdram, ctx);
        goto after_5;
    // 0x80800240: nop

    after_5:
    // 0x80800244: b           L_80800254
    // 0x80800248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800254;
    // 0x80800248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080024C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800250:
    // 0x80800250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800254:
    // 0x80800254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800258: jr          $ra
    // 0x8080025C: nop

    return;
    // 0x8080025C: nop

;}
RECOMP_FUNC void func_8009BFD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BFD8: lw          $t6, 0xDC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XDC);
    // 0x8009BFDC: jr          $ra
    // 0x8009BFE0: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
    return;
    // 0x8009BFE0: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
;}
RECOMP_FUNC void _sumole_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800899E8: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x800899E8);
    return;
    // 0x800899EC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _sukickball_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AE8: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089AE8);
    return;
    // 0x80089AEC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800C9DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9DE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9DE8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800C9DEC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C9DF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9DF4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C9DF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C9DFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C9E00: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C9E04: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C9E08: jal         0x800C9750
    // 0x800C9E0C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_800C9750(rdram, ctx);
        goto after_0;
    // 0x800C9E0C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x800C9E10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9E14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9E18: jr          $ra
    // 0x800C9E1C: nop

    return;
    // 0x800C9E1C: nop

;}
RECOMP_FUNC void func_8008E618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E618: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008E61C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008E620: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008E624: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008E628: jal         0x8009C128
    // 0x8008E62C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8008E62C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8008E630: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8008E634: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008E638: jal         0x800EBFD4
    // 0x8008E63C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800EBFD4(rdram, ctx);
        goto after_1;
    // 0x8008E63C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8008E640: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8008E644: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8008E648: addiu       $t1, $t1, -0x1290
    ctx->r9 = ADD32(ctx->r9, -0X1290);
    // 0x8008E64C: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8008E650: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8008E654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008E658: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8008E65C: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x8008E660: lbu         $t9, 0x2A($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2A);
    // 0x8008E664: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x8008E668: sb          $t0, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r8;
    // 0x8008E66C: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x8008E670: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8008E674: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x8008E678: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x8008E67C: lw          $t6, 0x184($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X184);
    // 0x8008E680: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x8008E684: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x8008E688: lhu         $t9, 0x1A($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X1A);
    // 0x8008E68C: andi        $t0, $t9, 0x1F
    ctx->r8 = ctx->r25 & 0X1F;
    // 0x8008E690: or          $t2, $t8, $t0
    ctx->r10 = ctx->r24 | ctx->r8;
    // 0x8008E694: jal         0x80095774
    // 0x8008E698: sh          $t2, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r10;
    baflag_clear(rdram, ctx);
        goto after_2;
    // 0x8008E698: sh          $t2, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r10;
    after_2:
    // 0x8008E69C: lw          $t3, 0xC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC);
    // 0x8008E6A0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8008E6A4: sw          $t1, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r9;
    // 0x8008E6A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E6AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008E6B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008E6B4: jr          $ra
    // 0x8008E6B8: nop

    return;
    // 0x8008E6B8: nop

;}
RECOMP_FUNC void ncpoddialog_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027D0: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x808027D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808027D8: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x808027DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808027E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808027E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808027E8: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x808027EC: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x808027F0: jal         0x800EE7F8
    // 0x808027F4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808027F4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808027F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808027FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802800: jr          $ra
    // 0x80802804: nop

    return;
    // 0x80802804: nop

;}
RECOMP_FUNC void func_80800218_chstinger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080021C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800220: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800224: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800228: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8080022C: jal         0x800F1A88
    // 0x80800230: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_800F1A88(rdram, ctx);
        goto after_0;
    // 0x80800230: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80800234: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800238: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080023C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800240: swc1        $f6, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f6.u32l;
    // 0x80800244: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800248: swc1        $f8, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->f8.u32l;
    // 0x8080024C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800254: jr          $ra
    // 0x80800258: nop

    return;
    // 0x80800258: nop

;}
RECOMP_FUNC void subaddieaudioquick_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800008: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8080000C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80800010: beq         $a1, $zero, L_80800038
    if (ctx->r5 == 0) {
        // 0x80800014: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800038;
    }
    // 0x80800014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080001C: jal         0x800C3418
    // 0x80800020: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    func_800C3418(rdram, ctx);
        goto after_0;
    // 0x80800020: sb          $t6, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800024: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x80800028: jal         0x800C32C4
    // 0x8080002C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_800C32C4(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x80800030: b           L_80800044
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800044;
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800038:
    // 0x80800038: jal         0x800C3418
    // 0x8080003C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C3418(rdram, ctx);
        goto after_2;
    // 0x8080003C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800044:
    // 0x80800044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800048: jr          $ra
    // 0x8080004C: nop

    return;
    // 0x8080004C: nop

;}
RECOMP_FUNC void _chswitch_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857E8: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x800857E8);
    return;
    // 0x800857EC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80092C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092C24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092C28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092C2C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80092C30: jal         0x800921E0
    // 0x80092C34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800921E0(rdram, ctx);
        goto after_0;
    // 0x80092C34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80092C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092C3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092C40: jr          $ra
    // 0x80092C44: nop

    return;
    // 0x80092C44: nop

;}
RECOMP_FUNC void func_80800000_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8008E23C
    // 0x8080000C: nop

    func_8008E23C(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: beq         $v0, $zero, L_80800020
    if (ctx->r2 == 0) {
        // 0x80800014: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800020;
    }
    // 0x80800014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800018: b           L_80800024
    // 0x8080001C: addiu       $v1, $zero, 0x6D
    ctx->r3 = ADD32(0, 0X6D);
        goto L_80800024;
    // 0x8080001C: addiu       $v1, $zero, 0x6D
    ctx->r3 = ADD32(0, 0X6D);
L_80800020:
    // 0x80800020: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
L_80800024:
    // 0x80800024: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8080034C_chgruntyfireballbig(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080034C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800350: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800354: sw          $s7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r23;
    // 0x80800358: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8080035C: sw          $s6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r22;
    // 0x80800360: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x80800364: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x80800368: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x8080036C: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80800370: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80800374: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80800378: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8080037C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800380: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800384: jal         0x8010A570
    // 0x80800388: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_8010A570(rdram, ctx);
        goto after_0;
    // 0x80800388: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x8080038C: addiu       $s4, $s7, 0x4
    ctx->r20 = ADD32(ctx->r23, 0X4);
    // 0x80800390: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1500, 0X714) << 16);
    // 0x80800394: addiu       $a2, $a2, 0x714
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1500, 0X714));
    // 0x80800398: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8080039C: jal         0x80089D18
    // 0x808003A0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808003A0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x808003A4: addiu       $s6, $sp, 0x7C
    ctx->r22 = ADD32(ctx->r29, 0X7C);
    // 0x808003A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808003AC: jal         0x800EE7F8
    // 0x808003B0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808003B0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x808003B4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x808003B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003BC: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x808003C0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x808003C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808003C8: jal         0x800B53A4
    // 0x808003CC: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    func_800B53A4(rdram, ctx);
        goto after_3;
    // 0x808003CC: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x808003D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003D4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808003D8: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x808003DC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808003E0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808003E4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808003E8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808003EC: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1500, 0X724) << 16);
    // 0x808003F0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808003F4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808003F8: addiu       $s2, $s2, 0x724
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1500, 0X724));
    // 0x808003FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800400: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x80800404: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x80800408: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_8080040C:
    // 0x8080040C: jal         0x800DC178
    // 0x80800410: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800410: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_4:
    // 0x80800414: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x80800418: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800424: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x80800428: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080042C: jal         0x800EEB9C
    // 0x80800430: nop

    func_800EEB9C(rdram, ctx);
        goto after_5;
    // 0x80800430: nop

    after_5:
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800438: jal         0x800EF04C
    // 0x8080043C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x8080043C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x80800440: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800444: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800448: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080044C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800450: jal         0x800BABB8
    // 0x80800454: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80800454: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_7:
    // 0x80800458: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080045C: bnel        $s1, $s3, L_8080040C
    if (ctx->r17 != ctx->r19) {
        // 0x80800460: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_8080040C;
    }
    goto skip_0;
    // 0x80800460: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_0:
    // 0x80800464: lw          $a0, 0x24($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X24);
    // 0x80800468: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8080046C: beq         $a0, $zero, L_80800480
    if (ctx->r4 == 0) {
        // 0x80800470: nop
    
            goto L_80800480;
    }
    // 0x80800470: nop

    // 0x80800474: jal         0x800863E8
    // 0x80800478: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800478: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x8080047C: sw          $v0, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->r2;
L_80800480:
    // 0x80800480: jal         0x800FFAB0
    // 0x80800484: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x80800484: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_9:
    // 0x80800488: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8080048C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800490: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800494: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800498: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8080049C: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x808004A0: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x808004A4: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x808004A8: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x808004AC: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x808004B0: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x808004B4: lw          $s6, 0x54($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X54);
    // 0x808004B8: lw          $s7, 0x58($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X58);
    // 0x808004BC: jr          $ra
    // 0x808004C0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x808004C0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8009F3BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F3BC: mtc1        $a3, $f0
    ctx->f0.u32l = ctx->r7;
    // 0x8009F3C0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009F3C4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8009F3C8: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8009F3CC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8009F3D0: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8009F3D4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8009F3D8: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x8009F3DC: bc1t        L_8009F3F0
    if (c1cs) {
        // 0x8009F3E0: mov.s       $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
            goto L_8009F3F0;
    }
    // 0x8009F3E0: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8009F3E4: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x8009F3E8: nop

    // 0x8009F3EC: bc1f        L_8009F430
    if (!c1cs) {
        // 0x8009F3F0: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8009F430;
    }
L_8009F3F0:
    // 0x8009F3F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009F3F4: lwc1        $f18, 0x53A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X53A0);
    // 0x8009F3F8: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8009F3FC: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8009F400: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8009F404: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8009F408: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x8009F40C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8009F410: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8009F414: nop

    // 0x8009F418: bc1t        L_8009F3F0
    if (c1cs) {
        // 0x8009F41C: nop
    
            goto L_8009F3F0;
    }
    // 0x8009F41C: nop

    // 0x8009F420: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x8009F424: nop

    // 0x8009F428: bc1t        L_8009F3F0
    if (c1cs) {
        // 0x8009F42C: nop
    
            goto L_8009F3F0;
    }
    // 0x8009F42C: nop

L_8009F430:
    // 0x8009F430: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8009F434: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8009F438: jr          $ra
    // 0x8009F43C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8009F43C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void chtrashcangame_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C34: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2384, 0X33A0) << 16);
    // 0x80802C38: jr          $ra
    // 0x80802C3C: addiu       $v0, $v0, 0x33A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2384, 0X33A0));
    return;
    // 0x80802C3C: addiu       $v0, $v0, 0x33A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2384, 0X33A0));
;}
RECOMP_FUNC void sumole_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080156C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801570: jal         0x80106790
    // 0x80801574: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801574: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80801578: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080157C: jal         0x80086918
    // 0x80801580: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _chmolehill_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80801580: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80801584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080158C: jr          $ra
    // 0x80801590: nop

    return;
    // 0x80801590: nop

;}
RECOMP_FUNC void func_80800E98_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EA0: jal         0x80800AEC
    // 0x80800EA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800AEC_bssub(rdram, ctx);
        goto after_0;
    // 0x80800EA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800EA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800EAC: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80800EB0: beq         $t6, $zero, L_80800EC8
    if (ctx->r14 == 0) {
        // 0x80800EB4: nop
    
            goto L_80800EC8;
    }
    // 0x80800EB4: nop

    // 0x80800EB8: jal         0x80800BD8
    // 0x80800EBC: nop

    func_80800BD8_bssub(rdram, ctx);
        goto after_1;
    // 0x80800EBC: nop

    after_1:
    // 0x80800EC0: b           L_80800ED4
    // 0x80800EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800ED4;
    // 0x80800EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800EC8:
    // 0x80800EC8: jal         0x80085250
    // 0x80800ECC: nop

    _basudie_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800ECC: nop

    after_2:
    // 0x80800ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800ED4:
    // 0x80800ED4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800ED8: jr          $ra
    // 0x80800EDC: nop

    return;
    // 0x80800EDC: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A600: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A600);
    return;
    // 0x8008A604: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80800A1C_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A1C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800A20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A28: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800A2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A30: jal         0x80100094
    // 0x80800A34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800A38: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A40: jal         0x80101FDC
    // 0x80800A44: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800A44: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_1:
    // 0x80800A48: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80800A4C: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80800A50: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x80800A54: beq         $at, $zero, L_80800D28
    if (ctx->r1 == 0) {
        // 0x80800A58: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800D28;
    }
    // 0x80800A58: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800A5C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12EC) << 16);
    // 0x80800A60: addu        $at, $at, $t7
    gpr jr_addend_80800A68 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800A64: lw          $t7, 0x12EC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12EC));
    // 0x80800A68: jr          $t7
    // 0x80800A6C: nop

    switch (jr_addend_80800A68 >> 2) {
        case 0: goto L_80800A70; break;
        case 1: goto L_80800B58; break;
        case 2: goto L_80800B44; break;
        case 3: goto L_80800B44; break;
        case 4: goto L_80800B94; break;
        case 5: goto L_80800BA4; break;
        case 6: goto L_80800BEC; break;
        case 7: goto L_80800D28; break;
        case 8: goto L_80800D28; break;
        case 9: goto L_80800CD0; break;
        case 10: goto L_80800BC4; break;
        default: switch_error(__func__, 0x80800A68, 0x808012EC);
    }
    // 0x80800A6C: nop

L_80800A70:
    // 0x80800A70: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X1318) << 16);
    // 0x80800A74: lwc1        $f4, 0x1318($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X1318));
    // 0x80800A78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800A7C: jal         0x80086C68
    // 0x80800A80: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800A80: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80800A84: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80800A88: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80800A8C: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A98: jal         0x80089840
    // 0x80800A9C: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800A9C: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    after_3:
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA4: jal         0x80100094
    // 0x80800AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800AAC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800AB0: jal         0x80089850
    // 0x80800AB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800AB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800AB8: jal         0x80089860
    // 0x80800ABC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    _sumumbofx_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80800ABC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_6:
    // 0x80800AC0: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800AC4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800AC8: jal         0x800898B8
    // 0x80800ACC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_7;
    // 0x80800ACC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_7:
    // 0x80800AD0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1640, 0X13B4) << 16);
    // 0x80800AD4: addiu       $a2, $a2, 0x13B4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1640, 0X13B4));
    // 0x80800AD8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800ADC: jal         0x80089908
    // 0x80800AE0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    _sumumbofx_entrypoint_25(rdram, ctx);
        goto after_8;
    // 0x80800AE0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_8:
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE8: jal         0x8010A800
    // 0x80800AEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_9;
    // 0x80800AEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800AF0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800AF4: jal         0x80089858
    // 0x80800AF8: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    _sumumbofx_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80800AF8: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    after_10:
    // 0x80800AFC: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800B00: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800B04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800B08: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80800B0C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800B10: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1640, 0X13C0) << 16);
    // 0x80800B14: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1640, 0X13C8) << 16);
    // 0x80800B18: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800B1C: addiu       $a3, $a3, 0x13C8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1640, 0X13C8));
    // 0x80800B20: addiu       $a2, $a2, 0x13C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1640, 0X13C0));
    // 0x80800B24: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800B28: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x80800B2C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800B30: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800B34: jal         0x800898A0
    // 0x80800B38: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    _sumumbofx_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x80800B38: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x80800B3C: b           L_80800D2C
    // 0x80800B40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D2C;
    // 0x80800B40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B44:
    // 0x80800B44: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800B48: jal         0x800898C0
    // 0x80800B4C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_12;
    // 0x80800B4C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_12:
    // 0x80800B50: b           L_80800D2C
    // 0x80800B54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D2C;
    // 0x80800B54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B58:
    // 0x80800B58: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800B5C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1640, 0X1360) << 16);
    // 0x80800B60: addiu       $a2, $a2, 0x1360
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1640, 0X1360));
    // 0x80800B64: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800B68: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800B6C: jal         0x80089D18
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800B74: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800B78: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800B7C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800B80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800B84: jal         0x800E1610
    // 0x80800B88: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_800E1610(rdram, ctx);
        goto after_14;
    // 0x80800B88: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_14:
    // 0x80800B8C: b           L_80800D2C
    // 0x80800B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D2C;
    // 0x80800B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B94:
    // 0x80800B94: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800B98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800B9C: b           L_80800D28
    // 0x80800BA0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
        goto L_80800D28;
    // 0x80800BA0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
L_80800BA4:
    // 0x80800BA4: jal         0x800DA544
    // 0x80800BA8: addiu       $a0, $zero, 0x4FF
    ctx->r4 = ADD32(0, 0X4FF);
    func_800DA544(rdram, ctx);
        goto after_15;
    // 0x80800BA8: addiu       $a0, $zero, 0x4FF
    ctx->r4 = ADD32(0, 0X4FF);
    after_15:
    // 0x80800BAC: jal         0x800DA544
    // 0x80800BB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_16;
    // 0x80800BB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x80800BB4: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
    // 0x80800BB8: andi        $t0, $t9, 0xFFBF
    ctx->r8 = ctx->r25 & 0XFFBF;
    // 0x80800BBC: b           L_80800D28
    // 0x80800BC0: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
        goto L_80800D28;
    // 0x80800BC0: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
L_80800BC4:
    // 0x80800BC4: jal         0x80089D40
    // 0x80800BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_17;
    // 0x80800BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800BCC: jal         0x80089D48
    // 0x80800BD0: lbu         $a0, 0x24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X24);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_18;
    // 0x80800BD0: lbu         $a0, 0x24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X24);
    after_18:
    // 0x80800BD4: sb          $v0, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r2;
    // 0x80800BD8: lwl         $t1, 0x3F($sp)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r29, 0X3F);
    // 0x80800BDC: lwr         $t1, 0x42($sp)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r29, 0X42);
    // 0x80800BE0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80800BE4: b           L_80800D28
    // 0x80800BE8: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_80800D28;
    // 0x80800BE8: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80800BEC:
    // 0x80800BEC: jal         0x80086C68
    // 0x80800BF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_19;
    // 0x80800BF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x80800BF4: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80800BF8: sra         $t2, $a3, 16
    ctx->r10 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80800BFC: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x80800C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C08: jal         0x80089840
    // 0x80800C0C: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x80800C0C: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    after_20:
    // 0x80800C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C14: jal         0x80100094
    // 0x80800C18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_21;
    // 0x80800C18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x80800C1C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800C20: jal         0x80089850
    // 0x80800C24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_22;
    // 0x80800C24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_22:
    // 0x80800C28: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80800C2C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800C30: jal         0x80089900
    // 0x80800C34: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_23;
    // 0x80800C34: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_23:
    // 0x80800C38: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800C3C: jal         0x800898B8
    // 0x80800C40: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_24;
    // 0x80800C40: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_24:
    // 0x80800C44: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1640, 0X13B4) << 16);
    // 0x80800C48: addiu       $a2, $a2, 0x13B4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1640, 0X13B4));
    // 0x80800C4C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800C50: jal         0x80089908
    // 0x80800C54: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    _sumumbofx_entrypoint_25(rdram, ctx);
        goto after_25;
    // 0x80800C54: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_25:
    // 0x80800C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C5C: jal         0x8010A800
    // 0x80800C60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_26;
    // 0x80800C60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_26:
    // 0x80800C64: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800C68: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800C6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800C70: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80800C74: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800C78: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1640, 0X13C0) << 16);
    // 0x80800C7C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1640, 0X13C8) << 16);
    // 0x80800C80: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800C84: addiu       $a3, $a3, 0x13C8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1640, 0X13C8));
    // 0x80800C88: addiu       $a2, $a2, 0x13C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1640, 0X13C0));
    // 0x80800C8C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800C90: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x80800C94: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800C98: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800C9C: jal         0x800898A0
    // 0x80800CA0: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    _sumumbofx_entrypoint_12(rdram, ctx);
        goto after_27;
    // 0x80800CA0: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_27:
    // 0x80800CA4: jal         0x80800210
    // 0x80800CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800210_chcrusherboulder(rdram, ctx);
        goto after_28;
    // 0x80800CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800CAC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800CB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800CB4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800CB8: jal         0x80085708
    // 0x80800CBC: addiu       $a3, $zero, 0x4810
    ctx->r7 = ADD32(0, 0X4810);
    _capod_entrypoint_13(rdram, ctx);
        goto after_29;
    // 0x80800CBC: addiu       $a3, $zero, 0x4810
    ctx->r7 = ADD32(0, 0X4810);
    after_29:
    // 0x80800CC0: lui         $at, 0x41B4
    ctx->r1 = S32(0X41B4 << 16);
    // 0x80800CC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800CC8: b           L_80800D28
    // 0x80800CCC: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800D28;
    // 0x80800CCC: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800CD0:
    // 0x80800CD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800CD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800CD8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80800CDC: jal         0x80085708
    // 0x80800CE0: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    _capod_entrypoint_13(rdram, ctx);
        goto after_30;
    // 0x80800CE0: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    after_30:
    // 0x80800CE4: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800CE8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800CEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800CF0: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x80800CF4: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    // 0x80800CF8: jal         0x808010EC
    // 0x80800CFC: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    func_808010EC_chcrusherboulder(rdram, ctx);
        goto after_31;
    // 0x80800CFC: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_31:
    // 0x80800D00: addiu       $a0, $zero, 0x180
    ctx->r4 = ADD32(0, 0X180);
    // 0x80800D04: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800D08: jal         0x80101180
    // 0x80800D0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_32;
    // 0x80800D0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_32:
    // 0x80800D10: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1640, 0X13D4) << 16);
    // 0x80800D14: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1640, 0X1374) << 16);
    // 0x80800D18: addiu       $a2, $a2, 0x1374
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1640, 0X1374));
    // 0x80800D1C: addiu       $a1, $a1, 0x13D4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1640, 0X13D4));
    // 0x80800D20: jal         0x80089D18
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_33;
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
L_80800D28:
    // 0x80800D28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D2C:
    // 0x80800D2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D30: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800D34: jr          $ra
    // 0x80800D38: nop

    return;
    // 0x80800D38: nop

;}
RECOMP_FUNC void func_80800C68_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800C78: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800C7C: lh          $t7, 0xE($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XE);
    // 0x80800C80: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2814) << 16);
    // 0x80800C84: lwc1        $f4, 0x2814($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2814));
    // 0x80800C88: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80800C8C: lwc1        $f16, 0x24($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80800C90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C94: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800C98: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80800C9C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800CA0: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800CA4: nop

    // 0x80800CA8: bc1f        L_80800CD8
    if (!c1cs) {
        // 0x80800CAC: nop
    
            goto L_80800CD8;
    }
    // 0x80800CAC: nop

    // 0x80800CB0: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800CB4: jal         0x800F20BC
    // 0x80800CB8: lwc1        $f14, 0x54($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X54);
    func_800F20BC(rdram, ctx);
        goto after_0;
    // 0x80800CB8: lwc1        $f14, 0x54($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X54);
    after_0:
    // 0x80800CBC: bne         $v0, $zero, L_80800CD8
    if (ctx->r2 != 0) {
        // 0x80800CC0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(3274, 0X2818) << 16);
            goto L_80800CD8;
    }
    // 0x80800CC0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2818) << 16);
    // 0x80800CC4: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800CC8: lwc1        $f6, 0x2818($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2818));
    // 0x80800CCC: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80800CD0: b           L_80800D08
    // 0x80800CD4: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_80800D08;
    // 0x80800CD4: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_80800CD8:
    // 0x80800CD8: jal         0x80107C00
    // 0x80800CDC: nop

    func_80107C00(rdram, ctx);
        goto after_1;
    // 0x80800CDC: nop

    after_1:
    // 0x80800CE0: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800CE4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800CE8: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800CEC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800CF0: lh          $t9, 0xE($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XE);
    // 0x80800CF4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80800CF8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800CFC: jal         0x800F15F8
    // 0x80800D00: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    func_800F15F8(rdram, ctx);
        goto after_2;
    // 0x80800D00: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    after_2:
    // 0x80800D04: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_80800D08:
    // 0x80800D08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D14: jr          $ra
    // 0x80800D18: nop

    return;
    // 0x80800D18: nop

;}
RECOMP_FUNC void func_80800CE0_chseaweedbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CE0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800CE4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800CE8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800CEC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800CF0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800CF4: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1024, 0XFAC) << 16);
    // 0x80800CF8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1024, 0XFB4) << 16);
    // 0x80800CFC: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80800D00: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800D04: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800D08: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80800D0C: addiu       $s1, $s1, 0xFB4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1024, 0XFB4));
    // 0x80800D10: addiu       $s0, $s0, 0xFAC
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1024, 0XFAC));
L_80800D14:
    // 0x80800D14: jal         0x80013728
    // 0x80800D18: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80013728(rdram, ctx);
        goto after_0;
    // 0x80800D18: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80800D1C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800D20: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80800D24: nop

    // 0x80800D28: bc1fl       L_80800D58
    if (!c1cs) {
        // 0x80800D2C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80800D58;
    }
    goto skip_0;
    // 0x80800D2C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80800D30: jal         0x80013728
    // 0x80800D34: lwc1        $f12, 0x48($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X48);
    func_80013728(rdram, ctx);
        goto after_1;
    // 0x80800D34: lwc1        $f12, 0x48($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X48);
    after_1:
    // 0x80800D38: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800D3C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800D40: nop

    // 0x80800D44: bc1f        L_80800D54
    if (!c1cs) {
        // 0x80800D48: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800D54;
    }
    // 0x80800D48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800D4C: b           L_80800D60
    // 0x80800D50: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
        goto L_80800D60;
    // 0x80800D50: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
L_80800D54:
    // 0x80800D54: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80800D58:
    // 0x80800D58: bne         $s0, $s1, L_80800D14
    if (ctx->r16 != ctx->r17) {
        // 0x80800D5C: nop
    
            goto L_80800D14;
    }
    // 0x80800D5C: nop

L_80800D60:
    // 0x80800D60: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800D64: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800D68: beql        $t7, $zero, L_80800DC0
    if (ctx->r15 == 0) {
        // 0x80800D6C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80800DC0;
    }
    goto skip_1;
    // 0x80800D6C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80800D70: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800D74: lwc1        $f12, 0x50($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X50);
    // 0x80800D78: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1024, 0XE30) << 16);
    // 0x80800D7C: lui         $a2, 0x442F
    ctx->r6 = S32(0X442F << 16);
    // 0x80800D80: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80800D84: nop

    // 0x80800D88: bc1fl       L_80800DC0
    if (!c1cs) {
        // 0x80800D8C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80800DC0;
    }
    goto skip_2;
    // 0x80800D8C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80800D90: lwc1        $f8, 0xE30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1024, 0XE30));
    // 0x80800D94: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800D98: jal         0x800F10B4
    // 0x80800D9C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800D9C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800DA0: jal         0x800C4B64
    // 0x80800DA4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800C4B64(rdram, ctx);
        goto after_3;
    // 0x80800DA4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80800DA8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1024, 0XFB4) << 16);
    // 0x80800DAC: addiu       $a2, $a2, 0xFB4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1024, 0XFB4));
    // 0x80800DB0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800DB4: jal         0x80089D18
    // 0x80800DB8: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800DB8: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    after_4:
    // 0x80800DBC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800DC0:
    // 0x80800DC0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800DC4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800DC8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800DCC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800DD0: jr          $ra
    // 0x80800DD4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800DD4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800DD8: nop

    // 0x80800DDC: nop

;}
RECOMP_FUNC void func_800C725C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C725C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7264: lui         $a1, 0x3F02
    ctx->r5 = S32(0X3F02 << 16);
    // 0x800C7268: jal         0x800C71B0
    // 0x800C726C: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    func_800C71B0(rdram, ctx);
        goto after_0;
    // 0x800C726C: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    after_0:
    // 0x800C7270: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C7274: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C7278: jal         0x800C4308
    // 0x800C727C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800C4308(rdram, ctx);
        goto after_1;
    // 0x800C727C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x800C7280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7288: jr          $ra
    // 0x800C728C: nop

    return;
    // 0x800C728C: nop

;}
RECOMP_FUNC void _chwitchyshockpadswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086778: syscall     369
    recomp_syscall_handler(rdram, ctx, 0x80086778);
    return;
    // 0x8008677C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void susplinet_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: lh          $t6, 0x30($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X30);
    // 0x80800188: lh          $t7, 0x4E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4E);
    // 0x8080018C: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x80800190: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80800194: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80800198: jr          $ra
    // 0x8080019C: lh          $v0, -0x2($t9)
    ctx->r2 = MEM_H(ctx->r25, -0X2);
    return;
    // 0x8080019C: lh          $v0, -0x2($t9)
    ctx->r2 = MEM_H(ctx->r25, -0X2);
;}
RECOMP_FUNC void glglobaldata_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800004: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800010: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800014: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800018: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2734, 0X230) << 16);
    // 0x8080001C: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2734, 0X238) << 16);
    // 0x80800020: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800024: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80800028: addiu       $s4, $s4, 0x238
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2734, 0X238));
    // 0x8080002C: addiu       $s0, $s0, 0x230
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2734, 0X230));
    // 0x80800030: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // 0x80800034: addiu       $s3, $sp, 0x38
    ctx->r19 = ADD32(ctx->r29, 0X38);
L_80800038:
    // 0x80800038: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8080003C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800040: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800044: jalr        $t9
    // 0x80800048: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80800048: nop

    after_0:
    // 0x8080004C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80800050: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800054: bne         $s0, $s4, L_80800038
    if (ctx->r16 != ctx->r20) {
        // 0x80800058: addu        $s1, $s1, $t6
        ctx->r17 = ADD32(ctx->r17, ctx->r14);
            goto L_80800038;
    }
    // 0x80800058: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x8080005C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800064: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800068: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080006C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800070: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800074: jr          $ra
    // 0x80800078: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800078: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800EDE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDE54: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800EDE58: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800EDE5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800EDE60: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800EDE64: nop

    // 0x800EDE68: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EDE6C: swc1        $f6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f6.u32l;
    // 0x800EDE70: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800EDE74: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800EDE78: nop

    // 0x800EDE7C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EDE80: swc1        $f10, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f10.u32l;
    // 0x800EDE84: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800EDE88: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800EDE8C: nop

    // 0x800EDE90: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EDE94: swc1        $f18, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->f18.u32l;
    // 0x800EDE98: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x800EDE9C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800EDEA0: nop

    // 0x800EDEA4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EDEA8: swc1        $f6, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f6.u32l;
    // 0x800EDEAC: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x800EDEB0: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800EDEB4: nop

    // 0x800EDEB8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EDEBC: swc1        $f10, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f10.u32l;
    // 0x800EDEC0: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x800EDEC4: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800EDEC8: nop

    // 0x800EDECC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EDED0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800EDED4: nop

    // 0x800EDED8: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x800EDEDC: swc1        $f18, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f18.u32l;
    // 0x800EDEE0: lw          $t2, 0x8($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X8);
    // 0x800EDEE4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800EDEE8: nop

    // 0x800EDEEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EDEF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800EDEF4: swc1        $f6, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f6.u32l;
    // 0x800EDEF8: lw          $t3, 0xC($a2)
    ctx->r11 = MEM_W(ctx->r6, 0XC);
    // 0x800EDEFC: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
    // 0x800EDF00: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800EDF04: nop

    // 0x800EDF08: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EDF0C: bc1f        L_800EDF1C
    if (!c1cs) {
        // 0x800EDF10: swc1        $f10, 0x94($a0)
        MEM_W(0X94, ctx->r4) = ctx->f10.u32l;
            goto L_800EDF1C;
    }
    // 0x800EDF10: swc1        $f10, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f10.u32l;
    // 0x800EDF14: b           L_800EDF24
    // 0x800EDF18: swc1        $f12, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->f12.u32l;
        goto L_800EDF24;
    // 0x800EDF18: swc1        $f12, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->f12.u32l;
L_800EDF1C:
    // 0x800EDF1C: lwc1        $f18, 0x5E6C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5E6C);
    // 0x800EDF20: swc1        $f18, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->f18.u32l;
L_800EDF24:
    // 0x800EDF24: jr          $ra
    // 0x800EDF28: swc1        $f4, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800EDF28: swc1        $f4, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_8080052C_chcheatomenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080052C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800530: beq         $a3, $zero, L_80800564
    if (ctx->r7 == 0) {
        // 0x80800534: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800564;
    }
    // 0x80800534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800538: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080053C: beq         $a3, $at, L_80800554
    if (ctx->r7 == ctx->r1) {
        // 0x80800540: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800554;
    }
    // 0x80800540: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800544: beq         $a3, $at, L_80800574
    if (ctx->r7 == ctx->r1) {
        // 0x80800548: nop
    
            goto L_80800574;
    }
    // 0x80800548: nop

    // 0x8080054C: b           L_80800580
    // 0x80800550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800580;
    // 0x80800550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800554:
    // 0x80800554: jal         0x80800194
    // 0x80800558: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800194_chcheatomenu(rdram, ctx);
        goto after_0;
    // 0x80800558: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8080055C: b           L_80800580
    // 0x80800560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800580;
    // 0x80800560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800564:
    // 0x80800564: jal         0x80800428
    // 0x80800568: nop

    func_80800428_chcheatomenu(rdram, ctx);
        goto after_1;
    // 0x80800568: nop

    after_1:
    // 0x8080056C: b           L_80800580
    // 0x80800570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800580;
    // 0x80800570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800574:
    // 0x80800574: jal         0x80101FDC
    // 0x80800578: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800578: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x8080057C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800580:
    // 0x80800580: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800584: jr          $ra
    // 0x80800588: nop

    return;
    // 0x80800588: nop

;}
RECOMP_FUNC void _chfriendlystonehead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F30: syscall     476
    recomp_syscall_handler(rdram, ctx, 0x80086F30);
    return;
    // 0x80086F34: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808017A4_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808017A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808017AC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808017B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808017B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808017B8: beq         $a1, $at, L_808018F0
    if (ctx->r5 == ctx->r1) {
        // 0x808017BC: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_808018F0;
    }
    // 0x808017BC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808017C0: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x808017C4: beq         $a1, $at, L_808018B0
    if (ctx->r5 == ctx->r1) {
        // 0x808017C8: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_808018B0;
    }
    // 0x808017C8: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x808017CC: beq         $a1, $at, L_808018D0
    if (ctx->r5 == ctx->r1) {
        // 0x808017D0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_808018D0;
    }
    // 0x808017D0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808017D4: bne         $a1, $at, L_80801928
    if (ctx->r5 != ctx->r1) {
        // 0x808017D8: nop
    
            goto L_80801928;
    }
    // 0x808017D8: nop

    // 0x808017DC: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808017E0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808017E4: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x808017E8: bne         $at, $zero, L_80801930
    if (ctx->r1 != 0) {
        // 0x808017EC: slti        $at, $t6, 0x6
        ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
            goto L_80801930;
    }
    // 0x808017EC: slti        $at, $t6, 0x6
    ctx->r1 = SIGNED(ctx->r14) < 0X6 ? 1 : 0;
    // 0x808017F0: beq         $at, $zero, L_80801930
    if (ctx->r1 == 0) {
        // 0x808017F4: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80801930;
    }
    // 0x808017F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808017F8: jal         0x8008A0B0
    // 0x808017FC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    _subaddiemulti_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x808017FC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801800: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801804: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x80801808: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8080180C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80801810: jal         0x80106790
    // 0x80801814: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80801814: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x80801818: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080181C: jal         0x80100094
    // 0x80801820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80801820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801824: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80801828: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080182C: addiu       $a0, $v1, 0x30
    ctx->r4 = ADD32(ctx->r3, 0X30);
    // 0x80801830: beq         $t9, $zero, L_80801850
    if (ctx->r25 == 0) {
        // 0x80801834: lw          $t1, 0x20($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X20);
            goto L_80801850;
    }
    // 0x80801834: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80801838: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080183C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80801840: jal         0x800899A0
    // 0x80801844: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    _sumultiscore_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80801844: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80801848: b           L_80801860
    // 0x8080184C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_80801860;
    // 0x8080184C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80801850:
    // 0x80801850: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80801854: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80801858: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8080185C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80801860:
    // 0x80801860: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80801864: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801868: jal         0x80086468
    // 0x8080186C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _chscorepoints_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x8080186C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80801870: jal         0x80801948
    // 0x80801874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801948_chballoonburst(rdram, ctx);
        goto after_5;
    // 0x80801874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801878: jal         0x8010A570
    // 0x8080187C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_6;
    // 0x8080187C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801880: jal         0x800FFAB0
    // 0x80801884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x80801884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801888: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080188C: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    // 0x80801890: lhu         $t3, 0x18($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X18);
    // 0x80801894: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80801898: beql        $t4, $zero, L_80801934
    if (ctx->r12 == 0) {
        // 0x8080189C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801934;
    }
    goto skip_0;
    // 0x8080189C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808018A0: jal         0x8010114C
    // 0x808018A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_8;
    // 0x808018A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x808018A8: b           L_80801934
    // 0x808018AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x808018AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018B0:
    // 0x808018B0: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x808018B4: sll         $t7, $t5, 11
    ctx->r15 = S32(ctx->r13 << 11);
    // 0x808018B8: bgezl       $t7, L_80801934
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808018BC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801934;
    }
    goto skip_1;
    // 0x808018BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x808018C0: jal         0x8010DC50
    // 0x808018C4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_8010DC50(rdram, ctx);
        goto after_9;
    // 0x808018C4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_9:
    // 0x808018C8: b           L_80801934
    // 0x808018CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x808018CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018D0:
    // 0x808018D0: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x808018D4: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x808018D8: bgezl       $t0, L_80801934
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808018DC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801934;
    }
    goto skip_2;
    // 0x808018DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x808018E0: jal         0x8010DCB4
    // 0x808018E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_8010DCB4(rdram, ctx);
        goto after_10;
    // 0x808018E4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_10:
    // 0x808018E8: b           L_80801934
    // 0x808018EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x808018EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018F0:
    // 0x808018F0: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x808018F4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x808018F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018FC: sll         $t3, $t1, 11
    ctx->r11 = S32(ctx->r9 << 11);
    // 0x80801900: bgez        $t3, L_80801918
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80801904: nop
    
            goto L_80801918;
    }
    // 0x80801904: nop

    // 0x80801908: jal         0x8010DD20
    // 0x8080190C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8010DD20(rdram, ctx);
        goto after_11;
    // 0x8080190C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80801910: b           L_80801934
    // 0x80801914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x80801914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801918:
    // 0x80801918: jal         0x801015D0
    // 0x8080191C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_12;
    // 0x8080191C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801920: b           L_80801934
    // 0x80801924: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801934;
    // 0x80801924: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801928:
    // 0x80801928: b           L_80801934
    // 0x8080192C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801934;
    // 0x8080192C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801930:
    // 0x80801930: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801934:
    // 0x80801934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801938: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080193C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801940: jr          $ra
    // 0x80801944: nop

    return;
    // 0x80801944: nop

;}
RECOMP_FUNC void _bskazstill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083610: syscall     70
    recomp_syscall_handler(rdram, ctx, 0x80083610);
    return;
    // 0x80083614: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chtntblockage_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D18: syscall     230
    recomp_syscall_handler(rdram, ctx, 0x80085D18);
    return;
    // 0x80085D1C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void dbzone_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808002DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808002E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808002E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002EC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x808002F0: addiu       $s2, $sp, 0x2C
    ctx->r18 = ADD32(ctx->r29, 0X2C);
    // 0x808002F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808002F8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x808002FC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800300: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80800304: addu        $s1, $t7, $a0
    ctx->r17 = ADD32(ctx->r15, ctx->r4);
    // 0x80800308: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8080030C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800310: jal         0x800EE940
    // 0x80800314: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800EE940(rdram, ctx);
        goto after_0;
    // 0x80800314: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800318: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8080031C: addiu       $v0, $a2, 0x2
    ctx->r2 = ADD32(ctx->r6, 0X2);
    // 0x80800320: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x80800324: beq         $at, $zero, L_80800370
    if (ctx->r1 == 0) {
        // 0x80800328: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800370;
    }
    // 0x80800328: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080032C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800334:
    // 0x80800334: jal         0x8080010C
    // 0x80800338: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8080010C_dbzone(rdram, ctx);
        goto after_1;
    // 0x80800338: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x8080033C: beql        $v0, $zero, L_80800364
    if (ctx->r2 == 0) {
        // 0x80800340: addiu       $s0, $s0, 0xE
        ctx->r16 = ADD32(ctx->r16, 0XE);
            goto L_80800364;
    }
    goto skip_0;
    // 0x80800340: addiu       $s0, $s0, 0xE
    ctx->r16 = ADD32(ctx->r16, 0XE);
    skip_0:
    // 0x80800344: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800348: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8080034C: subu        $v0, $s0, $t8
    ctx->r2 = SUB32(ctx->r16, ctx->r24);
    // 0x80800350: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80800354: mflo        $v0
    ctx->r2 = lo;
    // 0x80800358: b           L_80800378
    // 0x8080035C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800378;
    // 0x8080035C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800360: addiu       $s0, $s0, 0xE
    ctx->r16 = ADD32(ctx->r16, 0XE);
L_80800364:
    // 0x80800364: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80800368: bnel        $at, $zero, L_80800334
    if (ctx->r1 != 0) {
        // 0x8080036C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800334;
    }
    goto skip_1;
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_80800370:
    // 0x80800370: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800378:
    // 0x80800378: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080037C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800380: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800384: jr          $ra
    // 0x80800388: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800388: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8080010C_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800118: jal         0x80097AD0
    // 0x8080011C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_0;
    // 0x8080011C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800120: beq         $v0, $zero, L_80800134
    if (ctx->r2 == 0) {
        // 0x80800124: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800134;
    }
    // 0x80800124: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800128: jal         0x800848A8
    // 0x8080012C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _badrone_entrypoint_24(rdram, ctx);
        goto after_1;
    // 0x8080012C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800130: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800134:
    // 0x80800134: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800138: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8080013C: jal         0x80091A58
    // 0x80800140: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    bakey_pressed(rdram, ctx);
        goto after_2;
    // 0x80800140: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800144: beq         $v0, $zero, L_80800150
    if (ctx->r2 == 0) {
        // 0x80800148: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800150;
    }
    // 0x80800148: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080014C: addiu       $v1, $zero, 0x17F
    ctx->r3 = ADD32(0, 0X17F);
L_80800150:
    // 0x80800150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800158: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

;}
