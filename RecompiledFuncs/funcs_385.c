#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800BD8_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BE0: jal         0x80800B78
    // 0x80800BE4: nop

    func_80800B78_chhoneyb(rdram, ctx);
        goto after_0;
    // 0x80800BE4: nop

    after_0:
    // 0x80800BE8: jal         0x80800B98
    // 0x80800BEC: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    func_80800B98_chhoneyb(rdram, ctx);
        goto after_1;
    // 0x80800BEC: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    after_1:
    // 0x80800BF0: jal         0x80800B58
    // 0x80800BF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800B58_chhoneyb(rdram, ctx);
        goto after_2;
    // 0x80800BF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BFC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C04: jr          $ra
    // 0x80800C08: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
    return;
    // 0x80800C08: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
;}
RECOMP_FUNC void chweldarboss_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1360, 0X480C) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x480C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1360, 0X480C));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x480C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1360, 0X480C));
;}
RECOMP_FUNC void dbid_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X0);
    // 0x80800090: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800094: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // 0x80800098: blez        $a2, L_808000C0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8080009C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808000C0;
    }
    // 0x8080009C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_808000A0:
    // 0x808000A0: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x808000A4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x808000A8: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808000AC: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x808000B0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808000B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808000B8: bne         $at, $zero, L_808000A0
    if (ctx->r1 != 0) {
        // 0x808000BC: addu        $v1, $v1, $a0
        ctx->r3 = ADD32(ctx->r3, ctx->r4);
            goto L_808000A0;
    }
    // 0x808000BC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
L_808000C0:
    // 0x808000C0: jr          $ra
    // 0x808000C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808000C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _sulights_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8D8: syscall     854
    recomp_syscall_handler(rdram, ctx, 0x8008A8D8);
    return;
    // 0x8008A8DC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800C7230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7238: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x800C723C: jal         0x800C71B0
    // 0x800C7240: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_800C71B0(rdram, ctx);
        goto after_0;
    // 0x800C7240: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x800C7244: jal         0x800FF01C
    // 0x800C7248: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800FF01C(rdram, ctx);
        goto after_1;
    // 0x800C7248: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x800C724C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7254: jr          $ra
    // 0x800C7258: nop

    return;
    // 0x800C7258: nop

;}
RECOMP_FUNC void func_80800BA8_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BB0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800BB4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800BB8: jal         0x8010D254
    // 0x80800BBC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80800BBC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80800BC0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800BC4: jal         0x800F1EA4
    // 0x80800BC8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F1EA4(rdram, ctx);
        goto after_1;
    // 0x80800BC8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800BCC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800BD0: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800BD4: jal         0x800F1F38
    // 0x80800BD8: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_800F1F38(rdram, ctx);
        goto after_2;
    // 0x80800BD8: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_2:
    // 0x80800BDC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800BE0: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80800BE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800BE8: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80800BEC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800BF0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800BF4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800BF8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800BFC: jal         0x800EFCD8
    // 0x80800C00: nop

    func_800EFCD8(rdram, ctx);
        goto after_3;
    // 0x80800C00: nop

    after_3:
    // 0x80800C04: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800C08: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800C0C: swc1        $f10, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f10.u32l;
    // 0x80800C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800C18: jr          $ra
    // 0x80800C1C: nop

    return;
    // 0x80800C1C: nop

;}
RECOMP_FUNC void func_80800000_chwitchyentrygates(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x8008A738
    // 0x80800010: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _sujiggy_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80800014: beq         $v0, $zero, L_80800024
    if (ctx->r2 == 0) {
        // 0x80800018: nop
    
            goto L_80800024;
    }
    // 0x80800018: nop

    // 0x8080001C: jal         0x800DA544
    // 0x80800020: addiu       $a0, $zero, 0x394
    ctx->r4 = ADD32(0, 0X394);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800020: addiu       $a0, $zero, 0x394
    ctx->r4 = ADD32(0, 0X394);
    after_1:
L_80800024:
    // 0x80800024: jal         0x800D3E40
    // 0x80800028: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800D3E40(rdram, ctx);
        goto after_2;
    // 0x80800028: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_2:
    // 0x8080002C: beql        $v0, $zero, L_80800060
    if (ctx->r2 == 0) {
        // 0x80800030: addiu       $a3, $zero, 0x394
        ctx->r7 = ADD32(0, 0X394);
            goto L_80800060;
    }
    goto skip_0;
    // 0x80800030: addiu       $a3, $zero, 0x394
    ctx->r7 = ADD32(0, 0X394);
    skip_0:
    // 0x80800034: jal         0x80088840
    // 0x80800038: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x80800038: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_3:
    // 0x8080003C: bne         $v0, $zero, L_8080005C
    if (ctx->r2 != 0) {
        // 0x80800040: addiu       $a3, $zero, -0x1
        ctx->r7 = ADD32(0, -0X1);
            goto L_8080005C;
    }
    // 0x80800040: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80800044: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800048: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080004C: jal         0x80101FDC
    // 0x80800050: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800050: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_4:
    // 0x80800054: b           L_80800060
    // 0x80800058: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_80800060;
    // 0x80800058: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8080005C:
    // 0x8080005C: addiu       $a3, $zero, 0x394
    ctx->r7 = ADD32(0, 0X394);
L_80800060:
    // 0x80800060: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800064: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80800068: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x8080006C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800070: bne         $t7, $at, L_80800084
    if (ctx->r15 != ctx->r1) {
        // 0x80800074: lui         $at, 0x4296
        ctx->r1 = S32(0X4296 << 16);
            goto L_80800084;
    }
    // 0x80800074: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80800078: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080007C: b           L_80800094
    // 0x80800080: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
        goto L_80800094;
    // 0x80800080: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80800084:
    // 0x80800084: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
    // 0x80800088: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080008C: nop

    // 0x80800090: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80800094:
    // 0x80800094: jal         0x80086880
    // 0x80800098: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chdoormake_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800098: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8080009C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000A0: jal         0x800868A8
    // 0x808000A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x808000A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void func_808002A0_cheel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002A8: lwc1        $f14, 0x54($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X54);
    // 0x808002AC: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    // 0x808002B0: jal         0x800F1DCC
    // 0x808002B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F1DCC(rdram, ctx);
        goto after_0;
    // 0x808002B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808002BC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808002C0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808002C4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808002C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002CC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808002D0: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x808002D4: bc1f        L_808002E0
    if (!c1cs) {
        // 0x808002D8: addiu       $a0, $a3, 0x18
        ctx->r4 = ADD32(ctx->r7, 0X18);
            goto L_808002E0;
    }
    // 0x808002D8: addiu       $a0, $a3, 0x18
    ctx->r4 = ADD32(ctx->r7, 0X18);
    // 0x808002DC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_808002E0:
    // 0x808002E0: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x808002E4: nop

    // 0x808002E8: bc1t        L_80800300
    if (c1cs) {
        // 0x808002EC: nop
    
            goto L_80800300;
    }
    // 0x808002EC: nop

    // 0x808002F0: jal         0x800EFFB4
    // 0x808002F4: addiu       $a2, $a3, 0x4
    ctx->r6 = ADD32(ctx->r7, 0X4);
    func_800EFFB4(rdram, ctx);
        goto after_1;
    // 0x808002F4: addiu       $a2, $a3, 0x4
    ctx->r6 = ADD32(ctx->r7, 0X4);
    after_1:
    // 0x808002F8: beql        $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x808002FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080030C;
    }
    goto skip_0;
    // 0x808002FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80800300:
    // 0x80800300: b           L_8080030C
    // 0x80800304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080030C;
    // 0x80800304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080030C:
    // 0x8080030C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800314: jr          $ra
    // 0x80800318: nop

    return;
    // 0x80800318: nop

;}
RECOMP_FUNC void func_80800480_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800488: jal         0x800EA05C
    // 0x8080048C: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080048C: nop

    after_0:
    // 0x80800490: addiu       $at, $zero, 0x101
    ctx->r1 = ADD32(0, 0X101);
    // 0x80800494: beq         $v0, $at, L_808004C0
    if (ctx->r2 == ctx->r1) {
        // 0x80800498: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004C0;
    }
    // 0x80800498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080049C: addiu       $at, $zero, 0x106
    ctx->r1 = ADD32(0, 0X106);
    // 0x808004A0: beq         $v0, $at, L_808004C8
    if (ctx->r2 == ctx->r1) {
        // 0x808004A4: addiu       $at, $zero, 0x109
        ctx->r1 = ADD32(0, 0X109);
            goto L_808004C8;
    }
    // 0x808004A4: addiu       $at, $zero, 0x109
    ctx->r1 = ADD32(0, 0X109);
    // 0x808004A8: beq         $v0, $at, L_808004D0
    if (ctx->r2 == ctx->r1) {
        // 0x808004AC: addiu       $at, $zero, 0x10B
        ctx->r1 = ADD32(0, 0X10B);
            goto L_808004D0;
    }
    // 0x808004AC: addiu       $at, $zero, 0x10B
    ctx->r1 = ADD32(0, 0X10B);
    // 0x808004B0: beq         $v0, $at, L_808004D8
    if (ctx->r2 == ctx->r1) {
        // 0x808004B4: nop
    
            goto L_808004D8;
    }
    // 0x808004B4: nop

    // 0x808004B8: b           L_808004E0
    // 0x808004BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004E0;
    // 0x808004BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004C0:
    // 0x808004C0: b           L_808004E0
    // 0x808004C4: addiu       $v0, $zero, 0x1B0
    ctx->r2 = ADD32(0, 0X1B0);
        goto L_808004E0;
    // 0x808004C4: addiu       $v0, $zero, 0x1B0
    ctx->r2 = ADD32(0, 0X1B0);
L_808004C8:
    // 0x808004C8: b           L_808004E0
    // 0x808004CC: addiu       $v0, $zero, 0x1B1
    ctx->r2 = ADD32(0, 0X1B1);
        goto L_808004E0;
    // 0x808004CC: addiu       $v0, $zero, 0x1B1
    ctx->r2 = ADD32(0, 0X1B1);
L_808004D0:
    // 0x808004D0: b           L_808004E0
    // 0x808004D4: addiu       $v0, $zero, 0x1B2
    ctx->r2 = ADD32(0, 0X1B2);
        goto L_808004E0;
    // 0x808004D4: addiu       $v0, $zero, 0x1B2
    ctx->r2 = ADD32(0, 0X1B2);
L_808004D8:
    // 0x808004D8: b           L_808004E0
    // 0x808004DC: addiu       $v0, $zero, 0x1B3
    ctx->r2 = ADD32(0, 0X1B3);
        goto L_808004E0;
    // 0x808004DC: addiu       $v0, $zero, 0x1B3
    ctx->r2 = ADD32(0, 0X1B3);
L_808004E0:
    // 0x808004E0: jr          $ra
    // 0x808004E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808004E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80092444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092444: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80092448: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009244C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80092450: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092454: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80092458: lbu         $t7, 0xA2($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA2);
    // 0x8009245C: beq         $t7, $zero, L_80092474
    if (ctx->r15 == 0) {
        // 0x80092460: nop
    
            goto L_80092474;
    }
    // 0x80092460: nop

    // 0x80092464: jal         0x80093AB8
    // 0x80092468: nop

    func_80093AB8(rdram, ctx);
        goto after_0;
    // 0x80092468: nop

    after_0:
    // 0x8009246C: b           L_8009271C
    // 0x80092470: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8009271C;
    // 0x80092470: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80092474:
    // 0x80092474: jal         0x800A89F8
    // 0x80092478: nop

    func_800A89F8(rdram, ctx);
        goto after_1;
    // 0x80092478: nop

    after_1:
    // 0x8009247C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80092480: jal         0x800A4C68
    // 0x80092484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_2;
    // 0x80092484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80092488: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8009248C: bnel        $v0, $t8, L_800924A8
    if (ctx->r2 != ctx->r24) {
        // 0x80092490: lw          $v1, 0x50($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X50);
            goto L_800924A8;
    }
    goto skip_0;
    // 0x80092490: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    skip_0:
    // 0x80092494: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x80092498: lbu         $t0, 0x18($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X18);
    // 0x8009249C: beql        $t0, $zero, L_8009271C
    if (ctx->r8 == 0) {
        // 0x800924A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009271C;
    }
    goto skip_1;
    // 0x800924A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800924A4: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
L_800924A8:
    // 0x800924A8: lbu         $t1, 0x17($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X17);
    // 0x800924AC: beql        $t1, $zero, L_8009271C
    if (ctx->r9 == 0) {
        // 0x800924B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009271C;
    }
    goto skip_2;
    // 0x800924B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800924B4: lw          $t2, 0x84($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X84);
    // 0x800924B8: addiu       $v0, $v1, 0x78
    ctx->r2 = ADD32(ctx->r3, 0X78);
    // 0x800924BC: beql        $t2, $zero, L_8009250C
    if (ctx->r10 == 0) {
        // 0x800924C0: lwc1        $f4, 0x1C($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_8009250C;
    }
    goto skip_3;
    // 0x800924C0: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    skip_3:
    // 0x800924C4: lbu         $t3, 0x4($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4);
    // 0x800924C8: beql        $t3, $zero, L_800924EC
    if (ctx->r11 == 0) {
        // 0x800924CC: lbu         $t4, 0x9($v0)
        ctx->r12 = MEM_BU(ctx->r2, 0X9);
            goto L_800924EC;
    }
    goto skip_4;
    // 0x800924CC: lbu         $t4, 0x9($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X9);
    skip_4:
    // 0x800924D0: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x800924D4: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800924D8: jal         0x800A7108
    // 0x800924DC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    func_800A7108(rdram, ctx);
        goto after_3;
    // 0x800924DC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    after_3:
    // 0x800924E0: b           L_80092508
    // 0x800924E4: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
        goto L_80092508;
    // 0x800924E4: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x800924E8: lbu         $t4, 0x9($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X9);
L_800924EC:
    // 0x800924EC: beql        $t4, $zero, L_8009250C
    if (ctx->r12 == 0) {
        // 0x800924F0: lwc1        $f4, 0x1C($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_8009250C;
    }
    goto skip_5;
    // 0x800924F0: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    skip_5:
    // 0x800924F4: sb          $zero, 0x9($v0)
    MEM_B(0X9, ctx->r2) = 0;
    // 0x800924F8: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800924FC: jal         0x800A7130
    // 0x80092500: lbu         $a1, 0x8($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X8);
    func_800A7130(rdram, ctx);
        goto after_4;
    // 0x80092500: lbu         $a1, 0x8($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X8);
    after_4:
    // 0x80092504: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
L_80092508:
    // 0x80092508: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
L_8009250C:
    // 0x8009250C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092510: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80092514: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x80092518: jal         0x8009216C
    // 0x8009251C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    func_8009216C(rdram, ctx);
        goto after_5;
    // 0x8009251C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80092520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092524: jal         0x80094070
    // 0x80092528: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_80094070(rdram, ctx);
        goto after_6;
    // 0x80092528: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_6:
    // 0x8009252C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80092530: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80092534: jal         0x800EE7F8
    // 0x80092538: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80092538: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_7:
    // 0x8009253C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80092540: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80092544: jal         0x800EF04C
    // 0x80092548: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x80092548: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_8:
    // 0x8009254C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80092550: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80092554: jal         0x800EF04C
    // 0x80092558: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x80092558: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_9:
    // 0x8009255C: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80092560: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80092564: lwc1        $f6, 0x74($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80092568: lwc1        $f8, 0x1C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8009256C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80092570: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80092574: jal         0x800E3E8C
    // 0x80092578: nop

    func_800E3E8C(rdram, ctx);
        goto after_10;
    // 0x80092578: nop

    after_10:
    // 0x8009257C: beql        $v0, $zero, L_8009271C
    if (ctx->r2 == 0) {
        // 0x80092580: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009271C;
    }
    goto skip_6;
    // 0x80092580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x80092584: lw          $t5, 0x50($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X50);
    // 0x80092588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009258C: lh          $t6, 0xC($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XC);
    // 0x80092590: beql        $t6, $zero, L_8009271C
    if (ctx->r14 == 0) {
        // 0x80092594: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009271C;
    }
    goto skip_7;
    // 0x80092594: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x80092598: jal         0x80092B04
    // 0x8009259C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80092B04(rdram, ctx);
        goto after_11;
    // 0x8009259C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x800925A0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800925A4: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x800925A8: lbu         $t7, 0x10($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X10);
    // 0x800925AC: bnel        $t7, $zero, L_80092604
    if (ctx->r15 != 0) {
        // 0x800925B0: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80092604;
    }
    goto skip_8;
    // 0x800925B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_8:
    // 0x800925B4: jal         0x8008CA98
    // 0x800925B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008CA98(rdram, ctx);
        goto after_12;
    // 0x800925B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800925BC: jal         0x800B27E0
    // 0x800925C0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800B27E0(rdram, ctx);
        goto after_13;
    // 0x800925C0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_13:
    // 0x800925C4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800925C8: jal         0x8008CABC
    // 0x800925CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_14;
    // 0x800925CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800925D0: jal         0x8008AEDC
    // 0x800925D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008AEDC(rdram, ctx);
        goto after_15;
    // 0x800925D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x800925D8: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x800925DC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800925E0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800925E4: jal         0x8008C200
    // 0x800925E8: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    func_8008C200(rdram, ctx);
        goto after_16;
    // 0x800925E8: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    after_16:
    // 0x800925EC: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x800925F0: lbu         $t9, 0x13($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X13);
    // 0x800925F4: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x800925F8: sb          $t0, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r8;
    // 0x800925FC: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80092600: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80092604:
    // 0x80092604: sb          $t1, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r9;
    // 0x80092608: jal         0x800A06E8
    // 0x8009260C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A06E8(rdram, ctx);
        goto after_17;
    // 0x8009260C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80092610: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80092614: lbu         $t2, 0xC4($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC4);
    // 0x80092618: beql        $t2, $zero, L_80092658
    if (ctx->r10 == 0) {
        // 0x8009261C: lbu         $v0, 0x12($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X12);
            goto L_80092658;
    }
    goto skip_9;
    // 0x8009261C: lbu         $v0, 0x12($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X12);
    skip_9:
    // 0x80092620: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80092624: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80092628: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x8009262C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80092630: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80092634: jal         0x800EFA4C
    // 0x80092638: nop

    func_800EFA4C(rdram, ctx);
        goto after_18;
    // 0x80092638: nop

    after_18:
    // 0x8009263C: lw          $t3, 0x50($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X50);
    // 0x80092640: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80092644: lwc1        $f16, 0xC8($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XC8);
    // 0x80092648: jal         0x800DF4CC
    // 0x8009264C: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    func_800DF4CC(rdram, ctx);
        goto after_19;
    // 0x8009264C: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    after_19:
    // 0x80092650: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80092654: lbu         $v0, 0x12($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X12);
L_80092658:
    // 0x80092658: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009265C: beq         $v0, $zero, L_8009267C
    if (ctx->r2 == 0) {
        // 0x80092660: sll         $a0, $v0, 16
        ctx->r4 = S32(ctx->r2 << 16);
            goto L_8009267C;
    }
    // 0x80092660: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80092664: sra         $t4, $a0, 16
    ctx->r12 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80092668: jal         0x80100A74
    // 0x8009266C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_80100A74(rdram, ctx);
        goto after_20;
    // 0x8009266C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_20:
    // 0x80092670: jal         0x800DF818
    // 0x80092674: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF818(rdram, ctx);
        goto after_21;
    // 0x80092674: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
    // 0x80092678: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
L_8009267C:
    // 0x8009267C: jal         0x800AE080
    // 0x80092680: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    func_800AE080(rdram, ctx);
        goto after_22;
    // 0x80092680: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    after_22:
    // 0x80092684: jal         0x800DF72C
    // 0x80092688: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF72C(rdram, ctx);
        goto after_23;
    // 0x80092688: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x8009268C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80092690: addiu       $a0, $a0, 0x2234
    ctx->r4 = ADD32(ctx->r4, 0X2234);
    // 0x80092694: jal         0x800DF47C
    // 0x80092698: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_24;
    // 0x80092698: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_24:
    // 0x8009269C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800926A0: jal         0x800923A8
    // 0x800926A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800923A8(rdram, ctx);
        goto after_25;
    // 0x800926A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x800926A8: lw          $t5, 0x50($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X50);
    // 0x800926AC: jal         0x80100AC4
    // 0x800926B0: lbu         $a0, 0x12($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X12);
    func_80100AC4(rdram, ctx);
        goto after_26;
    // 0x800926B0: lbu         $a0, 0x12($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X12);
    after_26:
    // 0x800926B4: jal         0x800DF720
    // 0x800926B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF720(rdram, ctx);
        goto after_27;
    // 0x800926B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_27:
    // 0x800926BC: jal         0x800DF440
    // 0x800926C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_28;
    // 0x800926C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_28:
    // 0x800926C4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800926C8: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800926CC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x800926D0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800926D4: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x800926D8: jal         0x800DE448
    // 0x800926DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800DE448(rdram, ctx);
        goto after_29;
    // 0x800926DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_29:
    // 0x800926E0: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x800926E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800926E8: lbu         $t8, 0x11($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X11);
    // 0x800926EC: beql        $t8, $zero, L_8009271C
    if (ctx->r24 == 0) {
        // 0x800926F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009271C;
    }
    goto skip_10;
    // 0x800926F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x800926F4: jal         0x800923A8
    // 0x800926F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800923A8(rdram, ctx);
        goto after_30;
    // 0x800926F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_30:
    // 0x800926FC: addiu       $t9, $sp, 0x54
    ctx->r25 = ADD32(ctx->r29, 0X54);
    // 0x80092700: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80092704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092708: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8009270C: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x80092710: jal         0x80084500
    // 0x80092714: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    _babackpack_entrypoint_3(rdram, ctx);
        goto after_31;
    // 0x80092714: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    after_31:
    // 0x80092718: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009271C:
    // 0x8009271C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80092720: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80092724: jr          $ra
    // 0x80092728: nop

    return;
    // 0x80092728: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800464: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080046C: jal         0x808007D4
    // 0x80800470: nop

    sujiggy_entrypoint_21(rdram, ctx);
        goto after_0;
    // 0x80800470: nop

    after_0:
    // 0x80800474: beq         $v0, $zero, L_808004A0
    if (ctx->r2 == 0) {
        // 0x80800478: nop
    
            goto L_808004A0;
    }
    // 0x80800478: nop

    // 0x8080047C: jal         0x800DA298
    // 0x80800480: addiu       $a0, $zero, 0xD4D
    ctx->r4 = ADD32(0, 0XD4D);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800480: addiu       $a0, $zero, 0xD4D
    ctx->r4 = ADD32(0, 0XD4D);
    after_1:
    // 0x80800484: beq         $v0, $zero, L_80800498
    if (ctx->r2 == 0) {
        // 0x80800488: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_80800498;
    }
    // 0x80800488: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8080048C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800490: b           L_808004BC
    // 0x80800494: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
        goto L_808004BC;
    // 0x80800494: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800498:
    // 0x80800498: b           L_808004BC
    // 0x8080049C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
        goto L_808004BC;
    // 0x8080049C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_808004A0:
    // 0x808004A0: jal         0x800DA298
    // 0x808004A4: addiu       $a0, $zero, 0xD4D
    ctx->r4 = ADD32(0, 0XD4D);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808004A4: addiu       $a0, $zero, 0xD4D
    ctx->r4 = ADD32(0, 0XD4D);
    after_2:
    // 0x808004A8: beq         $v0, $zero, L_808004B8
    if (ctx->r2 == 0) {
        // 0x808004AC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_808004B8;
    }
    // 0x808004AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808004B0: b           L_808004BC
    // 0x808004B4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
        goto L_808004BC;
    // 0x808004B4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_808004B8:
    // 0x808004B8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_808004BC:
    // 0x808004BC: addiu       $a0, $zero, 0xD50
    ctx->r4 = ADD32(0, 0XD50);
    // 0x808004C0: jal         0x800DA564
    // 0x808004C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA564(rdram, ctx);
        goto after_3;
    // 0x808004C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x808004C8: addiu       $a0, $zero, 0x35C
    ctx->r4 = ADD32(0, 0X35C);
    // 0x808004CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808004D0: jal         0x800DA7A8
    // 0x808004D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800DA7A8(rdram, ctx);
        goto after_4;
    // 0x808004D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x808004D8: jal         0x808007D4
    // 0x808004DC: nop

    sujiggy_entrypoint_21(rdram, ctx);
        goto after_5;
    // 0x808004DC: nop

    after_5:
    // 0x808004E0: beq         $v0, $zero, L_80800504
    if (ctx->r2 == 0) {
        // 0x808004E4: nop
    
            goto L_80800504;
    }
    // 0x808004E4: nop

    // 0x808004E8: jal         0x800DA298
    // 0x808004EC: addiu       $a0, $zero, 0xD49
    ctx->r4 = ADD32(0, 0XD49);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808004EC: addiu       $a0, $zero, 0xD49
    ctx->r4 = ADD32(0, 0XD49);
    after_6:
    // 0x808004F0: addiu       $a0, $zero, 0x589
    ctx->r4 = ADD32(0, 0X589);
    // 0x808004F4: jal         0x800DA3B8
    // 0x808004F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_7;
    // 0x808004F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x808004FC: b           L_80800518
    // 0x80800500: nop

        goto L_80800518;
    // 0x80800500: nop

L_80800504:
    // 0x80800504: jal         0x800DA298
    // 0x80800508: addiu       $a0, $zero, 0xD49
    ctx->r4 = ADD32(0, 0XD49);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800508: addiu       $a0, $zero, 0xD49
    ctx->r4 = ADD32(0, 0XD49);
    after_8:
    // 0x8080050C: addiu       $a0, $zero, 0x3E9
    ctx->r4 = ADD32(0, 0X3E9);
    // 0x80800510: jal         0x800DA3B8
    // 0x80800514: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_9;
    // 0x80800514: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
L_80800518:
    // 0x80800518: jal         0x800DA298
    // 0x8080051C: addiu       $a0, $zero, 0xD74
    ctx->r4 = ADD32(0, 0XD74);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x8080051C: addiu       $a0, $zero, 0xD74
    ctx->r4 = ADD32(0, 0XD74);
    after_10:
    // 0x80800520: addiu       $a0, $zero, 0x57B
    ctx->r4 = ADD32(0, 0X57B);
    // 0x80800524: jal         0x800DA3B8
    // 0x80800528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_11;
    // 0x80800528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x8080052C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800530: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800534: addiu       $a0, $zero, 0x35C
    ctx->r4 = ADD32(0, 0X35C);
    // 0x80800538: bne         $t9, $at, L_80800548
    if (ctx->r25 != ctx->r1) {
        // 0x8080053C: nop
    
            goto L_80800548;
    }
    // 0x8080053C: nop

    // 0x80800540: jal         0x800DA944
    // 0x80800544: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA944(rdram, ctx);
        goto after_12;
    // 0x80800544: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
L_80800548:
    // 0x80800548: jal         0x800DA524
    // 0x8080054C: addiu       $a0, $zero, 0xD4F
    ctx->r4 = ADD32(0, 0XD4F);
    func_800DA524(rdram, ctx);
        goto after_13;
    // 0x8080054C: addiu       $a0, $zero, 0xD4F
    ctx->r4 = ADD32(0, 0XD4F);
    after_13:
    // 0x80800550: jal         0x800DA524
    // 0x80800554: addiu       $a0, $zero, 0xD4E
    ctx->r4 = ADD32(0, 0XD4E);
    func_800DA524(rdram, ctx);
        goto after_14;
    // 0x80800554: addiu       $a0, $zero, 0xD4E
    ctx->r4 = ADD32(0, 0XD4E);
    after_14:
    // 0x80800558: jal         0x800DA298
    // 0x8080055C: addiu       $a0, $zero, 0xD73
    ctx->r4 = ADD32(0, 0XD73);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x8080055C: addiu       $a0, $zero, 0xD73
    ctx->r4 = ADD32(0, 0XD73);
    after_15:
    // 0x80800560: beql        $v0, $zero, L_8080058C
    if (ctx->r2 == 0) {
        // 0x80800564: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080058C;
    }
    goto skip_0;
    // 0x80800564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800568: jal         0x80800854
    // 0x8080056C: nop

    sujiggy_entrypoint_24(rdram, ctx);
        goto after_16;
    // 0x8080056C: nop

    after_16:
    // 0x80800570: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800574: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80800578: jal         0x800D2054
    // 0x8080057C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800D2054(rdram, ctx);
        goto after_17;
    // 0x8080057C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_17:
    // 0x80800580: jal         0x800DA524
    // 0x80800584: addiu       $a0, $zero, 0xD73
    ctx->r4 = ADD32(0, 0XD73);
    func_800DA524(rdram, ctx);
        goto after_18;
    // 0x80800584: addiu       $a0, $zero, 0xD73
    ctx->r4 = ADD32(0, 0XD73);
    after_18:
    // 0x80800588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080058C:
    // 0x8080058C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800590: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800594: jr          $ra
    // 0x80800598: nop

    return;
    // 0x80800598: nop

;}
RECOMP_FUNC void func_80800690_chtransparentfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800690: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800698: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080069C: jal         0x80101870
    // 0x808006A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x808006A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808006A4: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x808006A8: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808006AC: bgezl       $t8, L_8080077C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808006B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080077C;
    }
    goto skip_0;
    // 0x808006B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808006B4: jal         0x80104130
    // 0x808006B8: nop

    func_80104130(rdram, ctx);
        goto after_1;
    // 0x808006B8: nop

    after_1:
    // 0x808006BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808006C4: jal         0x800DBEFC
    // 0x808006C8: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x808006C8: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_2:
    // 0x808006CC: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x808006D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808006D4: andi        $t9, $v0, 0x1FF
    ctx->r25 = ctx->r2 & 0X1FF;
    // 0x808006D8: beq         $t9, $zero, L_80800700
    if (ctx->r25 == 0) {
        // 0x808006DC: sltiu       $at, $t9, 0xD
        ctx->r1 = ctx->r25 < 0XD ? 1 : 0;
            goto L_80800700;
    }
    // 0x808006DC: sltiu       $at, $t9, 0xD
    ctx->r1 = ctx->r25 < 0XD ? 1 : 0;
    // 0x808006E0: beq         $at, $zero, L_80800700
    if (ctx->r1 == 0) {
        // 0x808006E4: sll         $t0, $t9, 2
        ctx->r8 = S32(ctx->r25 << 2);
            goto L_80800700;
    }
    // 0x808006E4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x808006E8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x808006EC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808006F0: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2232, 0XFB4) << 16);
    // 0x808006F4: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x808006F8: b           L_80800700
    // 0x808006FC: lw          $v1, 0xFB4($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(2232, 0XFB4));
        goto L_80800700;
    // 0x808006FC: lw          $v1, 0xFB4($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(2232, 0XFB4));
L_80800700:
    // 0x80800700: beql        $v1, $zero, L_8080077C
    if (ctx->r3 == 0) {
        // 0x80800704: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080077C;
    }
    goto skip_1;
    // 0x80800704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800708: jal         0x80104130
    // 0x8080070C: nop

    func_80104130(rdram, ctx);
        goto after_3;
    // 0x8080070C: nop

    after_3:
    // 0x80800710: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800714: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800718: jal         0x800DBEFC
    // 0x8080071C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800DBEFC(rdram, ctx);
        goto after_4;
    // 0x8080071C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80800720: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80800724: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800728: andi        $t1, $v0, 0x1FF
    ctx->r9 = ctx->r2 & 0X1FF;
    // 0x8080072C: beq         $t1, $zero, L_80800754
    if (ctx->r9 == 0) {
        // 0x80800730: sltiu       $at, $t1, 0xD
        ctx->r1 = ctx->r9 < 0XD ? 1 : 0;
            goto L_80800754;
    }
    // 0x80800730: sltiu       $at, $t1, 0xD
    ctx->r1 = ctx->r9 < 0XD ? 1 : 0;
    // 0x80800734: beq         $at, $zero, L_80800754
    if (ctx->r1 == 0) {
        // 0x80800738: sll         $t2, $t1, 2
        ctx->r10 = S32(ctx->r9 << 2);
            goto L_80800754;
    }
    // 0x80800738: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8080073C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80800740: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800744: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2232, 0XFB8) << 16);
    // 0x80800748: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8080074C: b           L_80800754
    // 0x80800750: lw          $v1, 0xFB8($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(2232, 0XFB8));
        goto L_80800754;
    // 0x80800750: lw          $v1, 0xFB8($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(2232, 0XFB8));
L_80800754:
    // 0x80800754: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80800758: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800760: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800764: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800768: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080076C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800770: jal         0x80800AC4
    // 0x80800774: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    func_80800AC4_chtransparentfish(rdram, ctx);
        goto after_5;
    // 0x80800774: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80800778: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080077C:
    // 0x8080077C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800780: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800784: jr          $ra
    // 0x80800788: nop

    return;
    // 0x80800788: nop

;}
RECOMP_FUNC void func_80800380_chcrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800380: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x80800384: addiu       $t7, $zero, 0x31
    ctx->r15 = ADD32(0, 0X31);
    // 0x80800388: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080038C: srl         $t6, $v1, 7
    ctx->r14 = S32(U32(ctx->r3) >> 7);
    // 0x80800390: slti        $at, $t6, 0x32
    ctx->r1 = SIGNED(ctx->r14) < 0X32 ? 1 : 0;
    // 0x80800394: beq         $at, $zero, L_808003A4
    if (ctx->r1 == 0) {
        // 0x80800398: subu        $a0, $t7, $t6
        ctx->r4 = SUB32(ctx->r15, ctx->r14);
            goto L_808003A4;
    }
    // 0x80800398: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
    // 0x8080039C: jr          $ra
    // 0x808003A0: addiu       $v0, $a0, 0xA40
    ctx->r2 = ADD32(ctx->r4, 0XA40);
    return;
    // 0x808003A0: addiu       $v0, $a0, 0xA40
    ctx->r2 = ADD32(ctx->r4, 0XA40);
L_808003A4:
    // 0x808003A4: jr          $ra
    // 0x808003A8: nop

    return;
    // 0x808003A8: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A158: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A158);
    return;
    // 0x8008A15C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80800E54_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E5C: jal         0x8080076C
    // 0x80800E60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080076C_bskaztorpedo(rdram, ctx);
        goto after_0;
    // 0x80800E60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E64: jal         0x808002E0
    // 0x80800E68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808002E0_bskaztorpedo(rdram, ctx);
        goto after_1;
    // 0x80800E68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800E6C: jal         0x80082FE8
    // 0x80800E70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800E70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E7C: jr          $ra
    // 0x80800E80: nop

    return;
    // 0x80800E80: nop

;}
RECOMP_FUNC void func_808032F8_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808032F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808032FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80803300: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80803304: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803308: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080330C: bne         $at, $zero, L_80803328
    if (ctx->r1 != 0) {
        // 0x80803310: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80803328;
    }
    // 0x80803310: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80803314: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80803318: beq         $a1, $at, L_80803588
    if (ctx->r5 == ctx->r1) {
        // 0x8080331C: nop
    
            goto L_80803588;
    }
    // 0x8080331C: nop

    // 0x80803320: b           L_80803638
    // 0x80803324: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803638;
    // 0x80803324: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803328:
    // 0x80803328: addiu       $t6, $a1, -0xB
    ctx->r14 = ADD32(ctx->r5, -0XB);
    // 0x8080332C: sltiu       $at, $t6, 0x25
    ctx->r1 = ctx->r14 < 0X25 ? 1 : 0;
    // 0x80803330: beq         $at, $zero, L_8080362C
    if (ctx->r1 == 0) {
        // 0x80803334: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8080362C;
    }
    // 0x80803334: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80803338: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3894) << 16);
    // 0x8080333C: addu        $at, $at, $t6
    gpr jr_addend_80803344 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80803340: lw          $t6, 0x3894($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3894));
    // 0x80803344: jr          $t6
    // 0x80803348: nop

    switch (jr_addend_80803344 >> 2) {
        case 0: goto L_808035C8; break;
        case 1: goto L_8080362C; break;
        case 2: goto L_808033DC; break;
        case 3: goto L_8080334C; break;
        case 4: goto L_8080362C; break;
        case 5: goto L_8080362C; break;
        case 6: goto L_8080362C; break;
        case 7: goto L_8080362C; break;
        case 8: goto L_8080362C; break;
        case 9: goto L_8080362C; break;
        case 10: goto L_8080362C; break;
        case 11: goto L_8080362C; break;
        case 12: goto L_8080362C; break;
        case 13: goto L_8080362C; break;
        case 14: goto L_8080362C; break;
        case 15: goto L_8080362C; break;
        case 16: goto L_8080362C; break;
        case 17: goto L_8080362C; break;
        case 18: goto L_8080362C; break;
        case 19: goto L_8080362C; break;
        case 20: goto L_80803610; break;
        case 21: goto L_8080362C; break;
        case 22: goto L_8080362C; break;
        case 23: goto L_8080362C; break;
        case 24: goto L_8080362C; break;
        case 25: goto L_8080362C; break;
        case 26: goto L_8080362C; break;
        case 27: goto L_8080362C; break;
        case 28: goto L_8080362C; break;
        case 29: goto L_8080362C; break;
        case 30: goto L_8080362C; break;
        case 31: goto L_8080362C; break;
        case 32: goto L_8080362C; break;
        case 33: goto L_8080362C; break;
        case 34: goto L_8080362C; break;
        case 35: goto L_80803454; break;
        case 36: goto L_80803360; break;
        default: switch_error(__func__, 0x80803344, 0x80803894);
    }
    // 0x80803348: nop

L_8080334C:
    // 0x8080334C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803350: jal         0x80801B90
    // 0x80803354: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80801B90_chclockworkmouse(rdram, ctx);
        goto after_0;
    // 0x80803354: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x80803358: b           L_80803638
    // 0x8080335C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80803638;
    // 0x8080335C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80803360:
    // 0x80803360: jal         0x80106790
    // 0x80803364: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80803364: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x80803368: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080336C: jal         0x80100094
    // 0x80803370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80803370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80803374: lh          $v1, 0x40($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X40);
    // 0x80803378: addiu       $at, $zero, 0x142A
    ctx->r1 = ADD32(0, 0X142A);
    // 0x8080337C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80803380: beq         $v1, $at, L_8080339C
    if (ctx->r3 == ctx->r1) {
        // 0x80803384: addiu       $a0, $zero, 0x4A
        ctx->r4 = ADD32(0, 0X4A);
            goto L_8080339C;
    }
    // 0x80803384: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x80803388: addiu       $at, $zero, 0x142E
    ctx->r1 = ADD32(0, 0X142E);
    // 0x8080338C: beq         $v1, $at, L_808033BC
    if (ctx->r3 == ctx->r1) {
        // 0x80803390: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_808033BC;
    }
    // 0x80803390: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80803394: b           L_80803638
    // 0x80803398: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803638;
    // 0x80803398: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080339C:
    // 0x8080339C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x808033A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808033A4: addiu       $a2, $t0, 0x114
    ctx->r6 = ADD32(ctx->r8, 0X114);
    // 0x808033A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808033AC: jal         0x800D1000
    // 0x808033B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800D1000(rdram, ctx);
        goto after_3;
    // 0x808033B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x808033B4: b           L_80803638
    // 0x808033B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803638;
    // 0x808033B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808033BC:
    // 0x808033BC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x808033C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808033C4: addiu       $a2, $t0, 0x114
    ctx->r6 = ADD32(ctx->r8, 0X114);
    // 0x808033C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808033CC: jal         0x800D1000
    // 0x808033D0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800D1000(rdram, ctx);
        goto after_4;
    // 0x808033D0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_4:
    // 0x808033D4: b           L_80803638
    // 0x808033D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803638;
    // 0x808033D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808033DC:
    // 0x808033DC: jal         0x80106790
    // 0x808033E0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x808033E0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_5:
    // 0x808033E4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x808033E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808033EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808033F0: andi        $t9, $v1, 0xFFFF
    ctx->r25 = ctx->r3 & 0XFFFF;
    // 0x808033F4: beq         $t9, $at, L_8080340C
    if (ctx->r25 == ctx->r1) {
        // 0x808033F8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080340C;
    }
    // 0x808033F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808033FC: beq         $t9, $at, L_80803430
    if (ctx->r25 == ctx->r1) {
        // 0x80803400: nop
    
            goto L_80803430;
    }
    // 0x80803400: nop

    // 0x80803404: b           L_80803638
    // 0x80803408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803638;
    // 0x80803408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080340C:
    // 0x8080340C: jal         0x80101080
    // 0x80803410: nop

    func_80101080(rdram, ctx);
        goto after_6;
    // 0x80803410: nop

    after_6:
    // 0x80803414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803418: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x8080341C: addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // 0x80803420: jal         0x80800850
    // 0x80803424: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80800850_chclockworkmouse(rdram, ctx);
        goto after_7;
    // 0x80803424: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_7:
    // 0x80803428: b           L_80803638
    // 0x8080342C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803638;
    // 0x8080342C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803430:
    // 0x80803430: jal         0x80101080
    // 0x80803434: nop

    func_80101080(rdram, ctx);
        goto after_8;
    // 0x80803434: nop

    after_8:
    // 0x80803438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080343C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x80803440: addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // 0x80803444: jal         0x80800850
    // 0x80803448: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80800850_chclockworkmouse(rdram, ctx);
        goto after_9;
    // 0x80803448: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_9:
    // 0x8080344C: b           L_80803638
    // 0x80803450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803638;
    // 0x80803450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803454:
    // 0x80803454: jal         0x80106790
    // 0x80803458: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_10;
    // 0x80803458: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_10:
    // 0x8080345C: lh          $v1, 0x40($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X40);
    // 0x80803460: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80803464: slti        $at, $v1, 0xCED
    ctx->r1 = SIGNED(ctx->r3) < 0XCED ? 1 : 0;
    // 0x80803468: bne         $at, $zero, L_80803490
    if (ctx->r1 != 0) {
        // 0x8080346C: addiu       $t1, $v1, -0x1426
        ctx->r9 = ADD32(ctx->r3, -0X1426);
            goto L_80803490;
    }
    // 0x8080346C: addiu       $t1, $v1, -0x1426
    ctx->r9 = ADD32(ctx->r3, -0X1426);
    // 0x80803470: sltiu       $at, $t1, 0xA
    ctx->r1 = ctx->r9 < 0XA ? 1 : 0;
    // 0x80803474: beq         $at, $zero, L_80803578
    if (ctx->r1 == 0) {
        // 0x80803478: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80803578;
    }
    // 0x80803478: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8080347C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3928) << 16);
    // 0x80803480: addu        $at, $at, $t1
    gpr jr_addend_80803488 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80803484: lw          $t1, 0x3928($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3928));
    // 0x80803488: jr          $t1
    // 0x8080348C: nop

    switch (jr_addend_80803488 >> 2) {
        case 0: goto L_808034A4; break;
        case 1: goto L_80803578; break;
        case 2: goto L_808034F4; break;
        case 3: goto L_808034D0; break;
        case 4: goto L_80803578; break;
        case 5: goto L_8080352C; break;
        case 6: goto L_80803510; break;
        case 7: goto L_808034D0; break;
        case 8: goto L_80803578; break;
        case 9: goto L_80803564; break;
        default: switch_error(__func__, 0x80803488, 0x80803928);
    }
    // 0x8080348C: nop

L_80803490:
    // 0x80803490: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x80803494: beq         $v1, $at, L_808034C0
    if (ctx->r3 == ctx->r1) {
        // 0x80803498: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808034C0;
    }
    // 0x80803498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080349C: b           L_8080357C
    // 0x808034A0: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_8080357C;
    // 0x808034A0: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_808034A4:
    // 0x808034A4: jal         0x808009F4
    // 0x808034A8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808009F4_chclockworkmouse(rdram, ctx);
        goto after_11;
    // 0x808034A8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_11:
    // 0x808034AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808034B0: jal         0x808026E0
    // 0x808034B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_12;
    // 0x808034B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x808034B8: b           L_8080357C
    // 0x808034BC: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_8080357C;
    // 0x808034BC: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_808034C0:
    // 0x808034C0: jal         0x808026E0
    // 0x808034C4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_13;
    // 0x808034C4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_13:
    // 0x808034C8: b           L_8080357C
    // 0x808034CC: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_8080357C;
    // 0x808034CC: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_808034D0:
    // 0x808034D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808034D4: jal         0x80800158
    // 0x808034D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800158_chclockworkmouse(rdram, ctx);
        goto after_14;
    // 0x808034D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x808034DC: jal         0x808000B4
    // 0x808034E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B4_chclockworkmouse(rdram, ctx);
        goto after_15;
    // 0x808034E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808034E4: jal         0x800904C8
    // 0x808034E8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800904C8(rdram, ctx);
        goto after_16;
    // 0x808034E8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_16:
    // 0x808034EC: b           L_8080357C
    // 0x808034F0: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_8080357C;
    // 0x808034F0: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_808034F4:
    // 0x808034F4: jal         0x808009F4
    // 0x808034F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808009F4_chclockworkmouse(rdram, ctx);
        goto after_17;
    // 0x808034F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_17:
    // 0x808034FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803500: jal         0x808026E0
    // 0x80803504: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_18;
    // 0x80803504: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
    // 0x80803508: b           L_8080357C
    // 0x8080350C: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_8080357C;
    // 0x8080350C: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_80803510:
    // 0x80803510: jal         0x808009F4
    // 0x80803514: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808009F4_chclockworkmouse(rdram, ctx);
        goto after_19;
    // 0x80803514: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_19:
    // 0x80803518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080351C: jal         0x808026E0
    // 0x80803520: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_20;
    // 0x80803520: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_20:
    // 0x80803524: b           L_8080357C
    // 0x80803528: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_8080357C;
    // 0x80803528: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_8080352C:
    // 0x8080352C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80803530: jal         0x808009F4
    // 0x80803534: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_808009F4_chclockworkmouse(rdram, ctx);
        goto after_21;
    // 0x80803534: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_21:
    // 0x80803538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080353C: jal         0x808026E0
    // 0x80803540: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_22;
    // 0x80803540: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_22:
    // 0x80803544: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80803548: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8080354C: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x80803550: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    // 0x80803554: lbu         $t6, 0x65($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X65);
    // 0x80803558: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x8080355C: b           L_80803578
    // 0x80803560: sb          $t7, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r15;
        goto L_80803578;
    // 0x80803560: sb          $t7, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r15;
L_80803564:
    // 0x80803564: jal         0x808009F4
    // 0x80803568: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808009F4_chclockworkmouse(rdram, ctx);
        goto after_23;
    // 0x80803568: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_23:
    // 0x8080356C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803570: jal         0x808026E0
    // 0x80803574: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_24;
    // 0x80803574: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_24:
L_80803578:
    // 0x80803578: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_8080357C:
    // 0x8080357C: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x80803580: b           L_80803634
    // 0x80803584: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
        goto L_80803634;
    // 0x80803584: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
L_80803588:
    // 0x80803588: jal         0x801022E4
    // 0x8080358C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_25;
    // 0x8080358C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80803590: addiu       $at, $zero, 0x7D
    ctx->r1 = ADD32(0, 0X7D);
    // 0x80803594: bne         $v0, $at, L_808035B4
    if (ctx->r2 != ctx->r1) {
        // 0x80803598: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1564, 0X3EE0) << 16);
            goto L_808035B4;
    }
    // 0x80803598: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1564, 0X3EE0) << 16);
    // 0x8080359C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1564, 0X3ED0) << 16);
    // 0x808035A0: addiu       $a0, $a0, 0x3ED0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1564, 0X3ED0));
    // 0x808035A4: jal         0x80088090
    // 0x808035A8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_26;
    // 0x808035A8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_26:
    // 0x808035AC: b           L_80803638
    // 0x808035B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803638;
    // 0x808035B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808035B4:
    // 0x808035B4: addiu       $a0, $a0, 0x3EE0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1564, 0X3EE0));
    // 0x808035B8: jal         0x80088090
    // 0x808035BC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_27;
    // 0x808035BC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_27:
    // 0x808035C0: b           L_80803638
    // 0x808035C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803638;
    // 0x808035C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808035C8:
    // 0x808035C8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x808035CC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808035D0: bne         $t1, $at, L_80803608
    if (ctx->r9 != ctx->r1) {
        // 0x808035D4: nop
    
            goto L_80803608;
    }
    // 0x808035D4: nop

    // 0x808035D8: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
    // 0x808035DC: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x808035E0: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x808035E4: bne         $t3, $at, L_80803608
    if (ctx->r11 != ctx->r1) {
        // 0x808035E8: nop
    
            goto L_80803608;
    }
    // 0x808035E8: nop

    // 0x808035EC: jal         0x80085710
    // 0x808035F0: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_28;
    // 0x808035F0: nop

    after_28:
    // 0x808035F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808035F8: jal         0x808026E0
    // 0x808035FC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_29;
    // 0x808035FC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_29:
    // 0x80803600: b           L_80803638
    // 0x80803604: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80803638;
    // 0x80803604: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80803608:
    // 0x80803608: b           L_80803638
    // 0x8080360C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80803638;
    // 0x8080360C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80803610:
    // 0x80803610: jal         0x801015D0
    // 0x80803614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_30;
    // 0x80803614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80803618: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8080361C: jal         0x800DF744
    // 0x80803620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_31;
    // 0x80803620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x80803624: b           L_80803638
    // 0x80803628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803638;
    // 0x80803628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080362C:
    // 0x8080362C: b           L_80803638
    // 0x80803630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803638;
    // 0x80803630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803634:
    // 0x80803634: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803638:
    // 0x80803638: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080363C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80803640: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80803644: jr          $ra
    // 0x80803648: nop

    return;
    // 0x80803648: nop

;}
RECOMP_FUNC void func_80800104_chvandoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800108: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080010C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800110: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800114: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80800118: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080011C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800120: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800124: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800128: beq         $t6, $at, L_80800150
    if (ctx->r14 == ctx->r1) {
        // 0x8080012C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800150;
    }
    // 0x8080012C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800130: beq         $t6, $at, L_80800158
    if (ctx->r14 == ctx->r1) {
        // 0x80800134: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800158;
    }
    // 0x80800134: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800138: beq         $t6, $at, L_808001BC
    if (ctx->r14 == ctx->r1) {
        // 0x8080013C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808001BC;
    }
    // 0x8080013C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800140: beq         $t6, $at, L_808001EC
    if (ctx->r14 == ctx->r1) {
        // 0x80800144: nop
    
            goto L_808001EC;
    }
    // 0x80800144: nop

    // 0x80800148: b           L_80800254
    // 0x8080014C: addiu       $s1, $a0, 0x4
    ctx->r17 = ADD32(ctx->r4, 0X4);
        goto L_80800254;
    // 0x8080014C: addiu       $s1, $a0, 0x4
    ctx->r17 = ADD32(ctx->r4, 0X4);
L_80800150:
    // 0x80800150: b           L_80800254
    // 0x80800154: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
        goto L_80800254;
    // 0x80800154: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
L_80800158:
    // 0x80800158: jal         0x800D9078
    // 0x8080015C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x8080015C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_0:
    // 0x80800160: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800164: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800168: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080016C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80800170: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800174: jal         0x800F10B4
    // 0x80800178: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800178: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8080017C: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x80800180: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800188: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x8080018C: jal         0x800EFE50
    // 0x80800190: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    func_800EFE50(rdram, ctx);
        goto after_2;
    // 0x80800190: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    after_2:
    // 0x80800194: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: beql        $t7, $zero, L_808001B0
    if (ctx->r15 == 0) {
        // 0x808001A0: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_808001B0;
    }
    goto skip_0;
    // 0x808001A0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x808001A4: jal         0x80800388
    // 0x808001A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800388_chvandoor(rdram, ctx);
        goto after_3;
    // 0x808001A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808001AC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
L_808001B0:
    // 0x808001B0: sltiu       $t9, $t8, 0x1
    ctx->r25 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x808001B4: b           L_80800254
    // 0x808001B8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
        goto L_80800254;
    // 0x808001B8: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_808001BC:
    // 0x808001BC: jal         0x8080044C
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080044C_chvandoor(rdram, ctx);
        goto after_4;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001C4: beq         $v0, $zero, L_808001E4
    if (ctx->r2 == 0) {
        // 0x808001C8: nop
    
            goto L_808001E4;
    }
    // 0x808001C8: nop

    // 0x808001CC: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x808001D0: addiu       $a0, $zero, 0x3CC
    ctx->r4 = ADD32(0, 0X3CC);
    // 0x808001D4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808001D8: srl         $t0, $a2, 7
    ctx->r8 = S32(U32(ctx->r6) >> 7);
    // 0x808001DC: jal         0x80101180
    // 0x808001E0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x808001E0: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_5:
L_808001E4:
    // 0x808001E4: b           L_80800254
    // 0x808001E8: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
        goto L_80800254;
    // 0x808001E8: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
L_808001EC:
    // 0x808001EC: jal         0x800D9078
    // 0x808001F0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x808001F0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x808001F4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800200: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800204: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800208: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8080020C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80800210: jal         0x800F10B4
    // 0x80800214: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80800214: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80800218: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x8080021C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800224: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800228: jal         0x800EFE50
    // 0x8080022C: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    func_800EFE50(rdram, ctx);
        goto after_8;
    // 0x8080022C: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    after_8:
    // 0x80800230: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: beql        $t1, $zero, L_8080024C
    if (ctx->r9 == 0) {
        // 0x8080023C: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_8080024C;
    }
    goto skip_1;
    // 0x8080023C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80800240: jal         0x80800388
    // 0x80800244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800388_chvandoor(rdram, ctx);
        goto after_9;
    // 0x80800244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800248: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
L_8080024C:
    // 0x8080024C: sltiu       $t3, $t2, 0x1
    ctx->r11 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80800250: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80800254:
    // 0x80800254: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1168, 0X688) << 16);
    // 0x80800258: addiu       $a3, $a3, 0x688
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1168, 0X688));
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800264: jal         0x80089D50
    // 0x80800268: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x80800268: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_10:
    // 0x8080026C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800270: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800274: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800278: jr          $ra
    // 0x8080027C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080027C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800A7088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A708C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7090: lhu         $a0, 0x76($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X76);
    // 0x800A7094: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x800A7098: jal         0x800F7364
    // 0x800A709C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800F7364(rdram, ctx);
        goto after_0;
    // 0x800A709C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x800A70A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A70A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A70A8: jr          $ra
    // 0x800A70AC: nop

    return;
    // 0x800A70AC: nop

;}
RECOMP_FUNC void func_808000CC_chbeehive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808000DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000E0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808000E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1664, 0X2F0) << 16);
    // 0x808000E8: addiu       $a2, $a2, 0x2F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1664, 0X2F0));
    // 0x808000EC: jal         0x80089D18
    // 0x808000F0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808000F0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1664, 0X300) << 16);
    // 0x808000F8: addiu       $a2, $a2, 0x300
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1664, 0X300));
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: jal         0x80089D18
    // 0x80800104: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800104: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800108: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1664, 0X320) << 16);
    // 0x8080010C: addiu       $t6, $t6, 0x320
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1664, 0X320));
    // 0x80800110: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800114: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800118: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080011C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800120: jal         0x800BBCB8
    // 0x80800124: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x80800124: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80800128: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8080012C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x80800130: beql        $a0, $zero, L_80800144
    if (ctx->r4 == 0) {
        // 0x80800134: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_80800144;
    }
    goto skip_0;
    // 0x80800134: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80800138: jal         0x8010114C
    // 0x8080013C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_3;
    // 0x8080013C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800140: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_80800144:
    // 0x80800144: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800148: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x8080014C: jal         0x800EE88C
    // 0x80800150: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE88C(rdram, ctx);
        goto after_4;
    // 0x80800150: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x80800154: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800160: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x80800164: jal         0x80086670
    // 0x80800168: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800168: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8080016C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800170: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800174: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void func_8080121C_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080121C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801220: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801224: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801228: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080122C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801230: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801234: jal         0x80100094
    // 0x80801238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080123C: jal         0x800883A0
    // 0x80801240: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    _gcstatusDll_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x80801240: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801244: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801248: jal         0x80801ADC
    // 0x8080124C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801ADC_chfpsgame(rdram, ctx);
        goto after_2;
    // 0x8080124C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801250: beq         $v0, $zero, L_80801260
    if (ctx->r2 == 0) {
        // 0x80801254: nop
    
            goto L_80801260;
    }
    // 0x80801254: nop

    // 0x80801258: b           L_808012B4
    // 0x8080125C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808012B4;
    // 0x8080125C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801260:
    // 0x80801260: beql        $s2, $zero, L_808012B4
    if (ctx->r18 == 0) {
        // 0x80801264: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808012B4;
    }
    goto skip_0;
    // 0x80801264: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80801268: jal         0x80088368
    // 0x8080126C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x8080126C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_3:
    // 0x80801270: blez        $v0, L_808012B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801274: lw          $s1, 0x2C($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X2C);
            goto L_808012B0;
    }
    // 0x80801274: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80801278: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x8080127C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801280:
    // 0x80801280: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801284: jal         0x800899A8
    // 0x80801288: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80801288: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x8080128C: bne         $v0, $s2, L_8080129C
    if (ctx->r2 != ctx->r18) {
        // 0x80801290: nop
    
            goto L_8080129C;
    }
    // 0x80801290: nop

    // 0x80801294: b           L_808012B4
    // 0x80801298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808012B4;
    // 0x80801298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080129C:
    // 0x8080129C: jal         0x80088368
    // 0x808012A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808012A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_5:
    // 0x808012A4: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808012A8: bnel        $at, $zero, L_80801280
    if (ctx->r1 != 0) {
        // 0x808012AC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801280;
    }
    goto skip_1;
    // 0x808012AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
L_808012B0:
    // 0x808012B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808012B4:
    // 0x808012B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808012B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808012BC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808012C0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808012C4: jr          $ra
    // 0x808012C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808012C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808000D4_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808000E4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808000E8: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x808000EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808000F4: srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
    // 0x808000F8: beq         $v0, $zero, L_80800120
    if (ctx->r2 == 0) {
        // 0x808000FC: nop
    
            goto L_80800120;
    }
    // 0x808000FC: nop

    // 0x80800100: beq         $v0, $at, L_80800130
    if (ctx->r2 == ctx->r1) {
        // 0x80800104: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800130;
    }
    // 0x80800104: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800108: beq         $v0, $at, L_80800130
    if (ctx->r2 == ctx->r1) {
        // 0x8080010C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800130;
    }
    // 0x8080010C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800110: beql        $v0, $at, L_80800140
    if (ctx->r2 == ctx->r1) {
        // 0x80800114: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800140;
    }
    goto skip_0;
    // 0x80800114: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800118: b           L_80800150
    // 0x8080011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800150;
    // 0x8080011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800120:
    // 0x80800120: jal         0x80800000
    // 0x80800124: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_chhumba(rdram, ctx);
        goto after_0;
    // 0x80800124: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800128: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080012C: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
L_80800130:
    // 0x80800130: andi        $t6, $v1, 0x7F
    ctx->r14 = ctx->r3 & 0X7F;
    // 0x80800134: ori         $t7, $t6, 0x180
    ctx->r15 = ctx->r14 | 0X180;
    // 0x80800138: sh          $t7, 0x76($a0)
    MEM_H(0X76, ctx->r4) = ctx->r15;
    // 0x8080013C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80800140:
    // 0x80800140: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800144: jal         0x80085740
    // 0x80800148: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800148: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080014C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800150:
    // 0x80800150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800154: jr          $ra
    // 0x80800158: nop

    return;
    // 0x80800158: nop

;}
RECOMP_FUNC void func_800FB1EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB1EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FB1F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FB1F4: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x800FB1F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FB1FC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800FB200: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800FB204: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800FB208: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800FB20C: jal         0x800C7A68
    // 0x800FB210: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800C7A68(rdram, ctx);
        goto after_0;
    // 0x800FB210: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x800FB214: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800FB218: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800FB21C: jal         0x800FB1B0
    // 0x800FB220: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_800FB1B0(rdram, ctx);
        goto after_1;
    // 0x800FB220: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x800FB224: bne         $v0, $zero, L_800FB234
    if (ctx->r2 != 0) {
        // 0x800FB228: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_800FB234;
    }
    // 0x800FB228: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800FB22C: b           L_800FB298
    // 0x800FB230: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
        goto L_800FB298;
    // 0x800FB230: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
L_800FB234:
    // 0x800FB234: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800FB238: jal         0x800C7A68
    // 0x800FB23C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800C7A68(rdram, ctx);
        goto after_2;
    // 0x800FB23C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800FB240: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800FB244: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800FB248: jal         0x800FB1B0
    // 0x800FB24C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_800FB1B0(rdram, ctx);
        goto after_3;
    // 0x800FB24C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x800FB250: bne         $v0, $zero, L_800FB268
    if (ctx->r2 != 0) {
        // 0x800FB254: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_800FB268;
    }
    // 0x800FB254: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800FB258: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FB25C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800FB260: b           L_800FB29C
    // 0x800FB264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800FB29C;
    // 0x800FB264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FB268:
    // 0x800FB268: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800FB26C: jal         0x800C7A68
    // 0x800FB270: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800C7A68(rdram, ctx);
        goto after_4;
    // 0x800FB270: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x800FB274: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800FB278: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800FB27C: jal         0x800FB1B0
    // 0x800FB280: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_800FB1B0(rdram, ctx);
        goto after_5;
    // 0x800FB280: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_5:
    // 0x800FB284: bne         $v0, $zero, L_800FB298
    if (ctx->r2 != 0) {
        // 0x800FB288: lwc1        $f0, 0x34($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
            goto L_800FB298;
    }
    // 0x800FB288: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800FB28C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FB290: b           L_800FB29C
    // 0x800FB294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800FB29C;
    // 0x800FB294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FB298:
    // 0x800FB298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FB29C:
    // 0x800FB29C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FB2A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800FB2A4: jr          $ra
    // 0x800FB2A8: nop

    return;
    // 0x800FB2A8: nop

;}
RECOMP_FUNC void func_80800024_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800030: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800034: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800038: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080003C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800040: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800044: jal         0x80102FDC
    // 0x80800048: nop

    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800048: nop

    after_0:
    // 0x8080004C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x80800054: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800058: jal         0x80088848
    // 0x8080005C: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x8080005C: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    after_1:
    // 0x80800060: beq         $v0, $zero, L_80800070
    if (ctx->r2 == 0) {
        // 0x80800064: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800070;
    }
    // 0x80800064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800068: jal         0x80102424
    // 0x8080006C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x8080006C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
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
RECOMP_FUNC void func_800BFFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFFF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BFFF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800BFFFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C0000: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C0004: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C0008: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C000C: addiu       $s1, $s1, -0x7888
    ctx->r17 = ADD32(ctx->r17, -0X7888);
    // 0x800C0010: addiu       $s0, $s0, -0x7890
    ctx->r16 = ADD32(ctx->r16, -0X7890);
    // 0x800C0014: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
L_800C0018:
    // 0x800C0018: beql        $a0, $zero, L_800C0030
    if (ctx->r4 == 0) {
        // 0x800C001C: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800C0030;
    }
    goto skip_0;
    // 0x800C001C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800C0020: jal         0x800EE5D8
    // 0x800C0024: nop

    func_800EE5D8(rdram, ctx);
        goto after_0;
    // 0x800C0024: nop

    after_0:
    // 0x800C0028: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x800C002C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800C0030:
    // 0x800C0030: beql        $a0, $zero, L_800C0048
    if (ctx->r4 == 0) {
        // 0x800C0034: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800C0048;
    }
    goto skip_1;
    // 0x800C0034: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x800C0038: jal         0x800DC060
    // 0x800C003C: nop

    func_800DC060(rdram, ctx);
        goto after_1;
    // 0x800C003C: nop

    after_1:
    // 0x800C0040: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800C0044: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800C0048:
    // 0x800C0048: bnel        $s0, $s1, L_800C0018
    if (ctx->r16 != ctx->r17) {
        // 0x800C004C: lw          $a0, 0x8($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X8);
            goto L_800C0018;
    }
    goto skip_2;
    // 0x800C004C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x800C0050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0054: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C0058: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C005C: jr          $ra
    // 0x800C0060: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C0060: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80801140_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801148: jal         0x808001A8
    // 0x8080114C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsvan_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080114C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801154: jal         0x800845D8
    // 0x80801158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080115C: lui         $a2, 0x3F03
    ctx->r6 = S32(0X3F03 << 16);
    // 0x80801160: ori         $a2, $a2, 0x46DC
    ctx->r6 = ctx->r6 | 0X46DC;
    // 0x80801164: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801168: jal         0x800845E0
    // 0x8080116C: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x8080116C: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    after_2:
    // 0x80801170: jal         0x8008CABC
    // 0x80801174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_3;
    // 0x80801174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80801178: lui         $a1, 0x3DD2
    ctx->r5 = S32(0X3DD2 << 16);
    // 0x8080117C: ori         $a1, $a1, 0x1FF3
    ctx->r5 = ctx->r5 | 0X1FF3;
    // 0x80801180: jal         0x8008B10C
    // 0x80801184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B10C(rdram, ctx);
        goto after_4;
    // 0x80801184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80801188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080118C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801190: jr          $ra
    // 0x80801194: nop

    return;
    // 0x80801194: nop

;}
RECOMP_FUNC void func_800EC854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC854: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800EC858: addiu       $a0, $a0, 0x2ED0
    ctx->r4 = ADD32(ctx->r4, 0X2ED0);
    // 0x800EC85C: lw          $v1, 0x259C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X259C);
    // 0x800EC860: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800EC864: addiu       $t8, $zero, 0x6B7
    ctx->r24 = ADD32(0, 0X6B7);
    // 0x800EC868: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800EC86C: slt         $at, $t6, $at
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800EC870: bne         $at, $zero, L_800EC87C
    if (ctx->r1 != 0) {
        // 0x800EC874: sw          $t6, 0x259C($a0)
        MEM_W(0X259C, ctx->r4) = ctx->r14;
            goto L_800EC87C;
    }
    // 0x800EC874: sw          $t6, 0x259C($a0)
    MEM_W(0X259C, ctx->r4) = ctx->r14;
    // 0x800EC878: sw          $t8, 0x259C($a0)
    MEM_W(0X259C, ctx->r4) = ctx->r24;
L_800EC87C:
    // 0x800EC87C: jr          $ra
    // 0x800EC880: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800EC880: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800EC884: nop

    // 0x800EC888: nop

    // 0x800EC88C: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080046C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800474: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800478: jal         0x80800330
    // 0x8080047C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    glcutDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080047C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800480: jal         0x808004A8
    // 0x80800484: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    glcutDll_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800484: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800488: jal         0x8080067C
    // 0x8080048C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    glcutDll_entrypoint_22(rdram, ctx);
        goto after_2;
    // 0x8080048C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800490: jal         0x80800544
    // 0x80800494: nop

    glcutDll_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x80800494: nop

    after_3:
    // 0x80800498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080049C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004A0: jr          $ra
    // 0x808004A4: nop

    return;
    // 0x808004A4: nop

;}
RECOMP_FUNC void func_8080084C_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080084C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800850: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800854: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800858: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080085C: jal         0x80800350
    // 0x80800860: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    bsstatue_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800860: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800868: jal         0x8009BB24
    // 0x8080086C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_8009BB24(rdram, ctx);
        goto after_1;
    // 0x8080086C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: jal         0x80091A30
    // 0x80800878: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_2;
    // 0x80800878: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x8080087C: beq         $v0, $zero, L_8080089C
    if (ctx->r2 == 0) {
        // 0x80800880: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8080089C;
    }
    // 0x80800880: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800884: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800888: nop

    // 0x8080088C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800890: nop

    // 0x80800894: bc1t        L_808008AC
    if (c1cs) {
        // 0x80800898: nop
    
            goto L_808008AC;
    }
    // 0x80800898: nop

L_8080089C:
    // 0x8080089C: jal         0x8008D544
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D544(rdram, ctx);
        goto after_3;
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808008A4: bnel        $v0, $zero, L_808008B8
    if (ctx->r2 != 0) {
        // 0x808008A8: lbu         $t6, 0x15C($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X15C);
            goto L_808008B8;
    }
    goto skip_0;
    // 0x808008A8: lbu         $t6, 0x15C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X15C);
    skip_0:
L_808008AC:
    // 0x808008AC: jal         0x8009BC6C
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_4;
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808008B4: lbu         $t6, 0x15C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X15C);
L_808008B8:
    // 0x808008B8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808008BC: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x808008C0: beq         $at, $zero, L_8080098C
    if (ctx->r1 == 0) {
        // 0x808008C4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8080098C;
    }
    // 0x808008C4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808008C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(372, 0X1574) << 16);
    // 0x808008CC: addu        $at, $at, $t7
    gpr jr_addend_808008D4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808008D0: lw          $t7, 0x1574($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(372, 0X1574));
    // 0x808008D4: jr          $t7
    // 0x808008D8: nop

    switch (jr_addend_808008D4 >> 2) {
        case 0: goto L_808008DC; break;
        case 1: goto L_808008FC; break;
        case 2: goto L_80800924; break;
        case 3: goto L_80800950; break;
        case 4: goto L_80800978; break;
        default: switch_error(__func__, 0x808008D4, 0x80801574);
    }
    // 0x808008D8: nop

L_808008DC:
    // 0x808008DC: jal         0x8008CAEC
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_5;
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808008E4: beq         $v0, $zero, L_8080098C
    if (ctx->r2 == 0) {
        // 0x808008E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080098C;
    }
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008EC: jal         0x8080054C
    // 0x808008F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080054C_bsstatue(rdram, ctx);
        goto after_6;
    // 0x808008F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808008F4: b           L_80800990
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800990;
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008FC:
    // 0x808008FC: jal         0x80800790
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800790_bsstatue(rdram, ctx);
        goto after_7;
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800904: jal         0x8008CAEC
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_8;
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080090C: beq         $v0, $zero, L_8080098C
    if (ctx->r2 == 0) {
        // 0x80800910: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080098C;
    }
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800914: jal         0x8080054C
    // 0x80800918: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080054C_bsstatue(rdram, ctx);
        goto after_9;
    // 0x80800918: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x8080091C: b           L_80800990
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800990;
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800924:
    // 0x80800924: jal         0x80800790
    // 0x80800928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800790_bsstatue(rdram, ctx);
        goto after_10;
    // 0x80800928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800930: jal         0x8008DF8C
    // 0x80800934: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_11;
    // 0x80800934: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_11:
    // 0x80800938: beq         $v0, $zero, L_8080098C
    if (ctx->r2 == 0) {
        // 0x8080093C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080098C;
    }
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800940: jal         0x8080054C
    // 0x80800944: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080054C_bsstatue(rdram, ctx);
        goto after_12;
    // 0x80800944: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x80800948: b           L_80800990
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800990;
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800950:
    // 0x80800950: jal         0x80800790
    // 0x80800954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800790_bsstatue(rdram, ctx);
        goto after_13;
    // 0x80800954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800958: jal         0x8008E078
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_14;
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800960: beq         $v0, $zero, L_8080098C
    if (ctx->r2 == 0) {
        // 0x80800964: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080098C;
    }
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800968: jal         0x8080054C
    // 0x8080096C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080054C_bsstatue(rdram, ctx);
        goto after_15;
    // 0x8080096C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_15:
    // 0x80800970: b           L_80800990
    // 0x80800974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800990;
    // 0x80800974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800978:
    // 0x80800978: jal         0x8008CAEC
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_16;
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800980: beq         $v0, $zero, L_8080098C
    if (ctx->r2 == 0) {
        // 0x80800984: addiu       $t8, $zero, 0xF9
        ctx->r24 = ADD32(0, 0XF9);
            goto L_8080098C;
    }
    // 0x80800984: addiu       $t8, $zero, 0xF9
    ctx->r24 = ADD32(0, 0XF9);
    // 0x80800988: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_8080098C:
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800990:
    // 0x80800990: jal         0x8009E5C8
    // 0x80800994: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_17;
    // 0x80800994: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_17:
    // 0x80800998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080099C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808009A4: jr          $ra
    // 0x808009A8: nop

    return;
    // 0x808009A8: nop

;}
RECOMP_FUNC void func_808036F0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808036F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808036F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808036FC: jal         0x80807BB8
    // 0x80803700: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80803700: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80803704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080370C: jal         0x800A38F0
    // 0x80803710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_1;
    // 0x80803710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80803714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803718: jal         0x808061AC
    // 0x8080371C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808061AC_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x8080371C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80803720: jal         0x8008CABC
    // 0x80803724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_3;
    // 0x80803724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80803728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080372C: jal         0x8008B134
    // 0x80803730: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x80803730: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80803734: jal         0x808001FC
    // 0x80803738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001FC_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80803738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080373C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80803740: addiu       $a0, $a0, 0x42E8
    ctx->r4 = ADD32(ctx->r4, 0X42E8);
    // 0x80803744: jal         0x80086D30
    // 0x80803748: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80803748: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    after_6:
    // 0x8080374C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803750: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803754: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803758: jr          $ra
    // 0x8080375C: nop

    return;
    // 0x8080375C: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BC8: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087BC8);
    return;
    // 0x80087BCC: addi        $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
;}
RECOMP_FUNC void _chskeletonexplode_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DF0: syscall     459
    recomp_syscall_handler(rdram, ctx, 0x80086DF0);
    return;
    // 0x80086DF4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800D9C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9C4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D9C50: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D9C54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D9C58: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800D9C5C: nop

    // 0x800D9C60: bc1f        L_800D9C6C
    if (!c1cs) {
        // 0x800D9C64: nop
    
            goto L_800D9C6C;
    }
    // 0x800D9C64: nop

    // 0x800D9C68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9C6C:
    // 0x800D9C6C: beq         $v0, $zero, L_800D9CE0
    if (ctx->r2 == 0) {
        // 0x800D9C70: nop
    
            goto L_800D9CE0;
    }
    // 0x800D9C70: nop

    // 0x800D9C74: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800D9C78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D9C7C: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800D9C80: nop

    // 0x800D9C84: bc1f        L_800D9C90
    if (!c1cs) {
        // 0x800D9C88: nop
    
            goto L_800D9C90;
    }
    // 0x800D9C88: nop

    // 0x800D9C8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9C90:
    // 0x800D9C90: beq         $v0, $zero, L_800D9CE0
    if (ctx->r2 == 0) {
        // 0x800D9C94: nop
    
            goto L_800D9CE0;
    }
    // 0x800D9C94: nop

    // 0x800D9C98: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800D9C9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D9CA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D9CA4: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x800D9CA8: nop

    // 0x800D9CAC: bc1f        L_800D9CB8
    if (!c1cs) {
        // 0x800D9CB0: nop
    
            goto L_800D9CB8;
    }
    // 0x800D9CB0: nop

    // 0x800D9CB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9CB8:
    // 0x800D9CB8: beq         $v0, $zero, L_800D9CE0
    if (ctx->r2 == 0) {
        // 0x800D9CBC: nop
    
            goto L_800D9CE0;
    }
    // 0x800D9CBC: nop

    // 0x800D9CC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D9CC4: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800D9CC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D9CCC: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800D9CD0: nop

    // 0x800D9CD4: bc1f        L_800D9CE0
    if (!c1cs) {
        // 0x800D9CD8: nop
    
            goto L_800D9CE0;
    }
    // 0x800D9CD8: nop

    // 0x800D9CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9CE0:
    // 0x800D9CE0: jr          $ra
    // 0x800D9CE4: nop

    return;
    // 0x800D9CE4: nop

;}
RECOMP_FUNC void func_8008F8D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F8D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F8DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F8E0: jal         0x800F54E4
    // 0x8008F8E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008F8E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008F8E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F8EC: jal         0x800F49A8
    // 0x8008F8F0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F49A8(rdram, ctx);
        goto after_1;
    // 0x8008F8F0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008F8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F8F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F8FC: jr          $ra
    // 0x8008F900: nop

    return;
    // 0x8008F900: nop

;}
RECOMP_FUNC void sumole_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801378: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080137C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801380: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801384: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801388: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080138C: jal         0x8010D254
    // 0x80801390: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80801390: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80801394: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80801398: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080139C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808013A0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808013A4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808013A8: jal         0x8008A1B0
    // 0x808013AC: nop

    _subaddiedialog_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808013AC: nop

    after_1:
    // 0x808013B0: beq         $v0, $zero, L_808013E4
    if (ctx->r2 == 0) {
        // 0x808013B4: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_808013E4;
    }
    // 0x808013B4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x808013B8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x808013BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808013C0: beq         $v0, $at, L_808013DC
    if (ctx->r2 == ctx->r1) {
        // 0x808013C4: nop
    
            goto L_808013DC;
    }
    // 0x808013C4: nop

    // 0x808013C8: lbu         $t0, 0x72($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X72);
    // 0x808013CC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x808013D0: andi        $t1, $t0, 0xFF03
    ctx->r9 = ctx->r8 & 0XFF03;
    // 0x808013D4: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x808013D8: sb          $t2, 0x72($v1)
    MEM_B(0X72, ctx->r3) = ctx->r10;
L_808013DC:
    // 0x808013DC: b           L_808013E8
    // 0x808013E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808013E8;
    // 0x808013E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808013E4:
    // 0x808013E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808013E8:
    // 0x808013E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808013F0: jr          $ra
    // 0x808013F4: nop

    return;
    // 0x808013F4: nop

;}
RECOMP_FUNC void chstonepillar_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(880, 0X1438) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1438
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(880, 0X1438));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1438
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(880, 0X1438));
;}
RECOMP_FUNC void func_800A5B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5B8C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5B90: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x800A5B94: jr          $ra
    // 0x800A5B98: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
    return;
    // 0x800A5B98: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
;}
RECOMP_FUNC void _baflamethrower_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BA0: syscall     131
    recomp_syscall_handler(rdram, ctx, 0x80084BA0);
    return;
    // 0x80084BA4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801B44_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801B48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801B50: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80801B54: ori         $t6, $a2, 0x4
    ctx->r14 = ctx->r6 | 0X4;
    // 0x80801B58: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80801B5C: addiu       $t8, $zero, 0x36
    ctx->r24 = ADD32(0, 0X36);
    // 0x80801B60: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80801B64: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801B68: jal         0x8008A208
    // 0x80801B6C: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80801B6C: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    after_0:
    // 0x80801B70: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80801B74: lbu         $t0, 0x74($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X74);
    // 0x80801B78: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x80801B7C: sb          $t1, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r9;
    // 0x80801B80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801B88: jr          $ra
    // 0x80801B8C: nop

    return;
    // 0x80801B8C: nop

;}
RECOMP_FUNC void glsavegame_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x808005D8: addiu       $v1, $v1, 0x7618
    ctx->r3 = ADD32(ctx->r3, 0X7618);
    // 0x808005DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808005E4: addu        $a1, $v1, $a0
    ctx->r5 = ADD32(ctx->r3, ctx->r4);
    // 0x808005E8: lb          $a0, 0xC($a1)
    ctx->r4 = MEM_B(ctx->r5, 0XC);
    // 0x808005EC: lb          $t7, 0xF($v1)
    ctx->r15 = MEM_B(ctx->r3, 0XF);
    // 0x808005F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005F4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x808005F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005FC: jal         0x8080036C
    // 0x80800600: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8080036C_glsavegame(rdram, ctx);
        goto after_0;
    // 0x80800600: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80800604: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80800608: addiu       $v1, $v1, 0x7618
    ctx->r3 = ADD32(ctx->r3, 0X7618);
    // 0x8080060C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800610: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800614: bne         $v0, $zero, L_8080064C
    if (ctx->r2 != 0) {
        // 0x80800618: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8080064C;
    }
    // 0x80800618: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8080061C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80800620: sb          $t8, 0xC($a1)
    MEM_B(0XC, ctx->r5) = ctx->r24;
    // 0x80800624: lbu         $t9, 0x10($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X10);
    // 0x80800628: sb          $a0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r4;
    // 0x8080062C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80800630: beq         $t9, $zero, L_8080064C
    if (ctx->r25 == 0) {
        // 0x80800634: sll         $t1, $t0, 2
        ctx->r9 = S32(ctx->r8 << 2);
            goto L_8080064C;
    }
    // 0x80800634: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800638: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x8080063C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80800640: jal         0x800885A0
    // 0x80800644: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    _glgamedata_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800644: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800648: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_8080064C:
    // 0x8080064C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800650: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800654: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80800658: jr          $ra
    // 0x8080065C: nop

    return;
    // 0x8080065C: nop

;}
RECOMP_FUNC void func_8010FF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FF80: jr          $ra
    // 0x8010FF84: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    return;
    // 0x8010FF84: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
;}
RECOMP_FUNC void func_80800000_ncpod(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lbu         $t6, 0x42($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X42);
    // 0x8080000C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800014: bnel        $t6, $zero, L_8080002C
    if (ctx->r14 != 0) {
        // 0x80800018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080002C;
    }
    goto skip_0;
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080001C: sb          $t7, 0x42($a0)
    MEM_B(0X42, ctx->r4) = ctx->r15;
    // 0x80800020: jal         0x800F82D4
    // 0x80800024: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    func_800F82D4(rdram, ctx);
        goto after_0;
    // 0x80800024: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    after_0:
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080002C:
    // 0x8080002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void func_80102A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102A04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102A08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80102A0C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80102A10: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80102A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102A18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102A1C: c.eq.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl == ctx->f4.fl;
    // 0x80102A20: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80102A24: bc1fl       L_80102A38
    if (!c1cs) {
        // 0x80102A28: sub.s       $f12, $f14, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f6.fl;
            goto L_80102A38;
    }
    goto skip_0;
    // 0x80102A28: sub.s       $f12, $f14, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f6.fl;
    skip_0:
    // 0x80102A2C: b           L_80102B1C
    // 0x80102A30: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
        goto L_80102B1C;
    // 0x80102A30: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    // 0x80102A34: sub.s       $f12, $f14, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f6.fl;
L_80102A38:
    // 0x80102A38: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80102A3C: jal         0x80013728
    // 0x80102A40: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    func_80013728(rdram, ctx);
        goto after_0;
    // 0x80102A40: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80102A44: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80102A48: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80102A4C: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80102A50: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80102A54: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80102A58: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80102A5C: sll         $t9, $t7, 27
    ctx->r25 = S32(ctx->r15 << 27);
    // 0x80102A60: bgezl       $t9, L_80102AA4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80102A64: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80102AA4;
    }
    goto skip_1;
    // 0x80102A64: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_1:
    // 0x80102A68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80102A6C: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80102A70: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80102A74: nop

    // 0x80102A78: bc1t        L_80102A98
    if (c1cs) {
        // 0x80102A7C: nop
    
            goto L_80102A98;
    }
    // 0x80102A7C: nop

    // 0x80102A80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80102A84: nop

    // 0x80102A88: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80102A8C: nop

    // 0x80102A90: bc1fl       L_80102AA4
    if (!c1cs) {
        // 0x80102A94: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80102AA4;
    }
    goto skip_2;
    // 0x80102A94: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_2:
L_80102A98:
    // 0x80102A98: b           L_80102B1C
    // 0x80102A9C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_80102B1C;
    // 0x80102A9C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x80102AA0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80102AA4:
    // 0x80102AA4: negu        $t0, $a3
    ctx->r8 = SUB32(0, ctx->r7);
    // 0x80102AA8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80102AAC: nop

    // 0x80102AB0: bc1fl       L_80102AEC
    if (!c1cs) {
        // 0x80102AB4: mtc1        $t0, $f4
        ctx->f4.u32l = ctx->r8;
            goto L_80102AEC;
    }
    goto skip_3;
    // 0x80102AB4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    skip_3:
    // 0x80102AB8: mtc1        $a3, $f18
    ctx->f18.u32l = ctx->r7;
    // 0x80102ABC: nop

    // 0x80102AC0: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80102AC4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80102AC8: nop

    // 0x80102ACC: bc1fl       L_80102AE0
    if (!c1cs) {
        // 0x80102AD0: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_80102AE0;
    }
    goto skip_4;
    // 0x80102AD0: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    skip_4:
    // 0x80102AD4: b           L_80102B14
    // 0x80102AD8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80102B14;
    // 0x80102AD8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80102ADC: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
L_80102AE0:
    // 0x80102AE0: b           L_80102B14
    // 0x80102AE4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_80102B14;
    // 0x80102AE4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x80102AE8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_80102AEC:
    // 0x80102AEC: nop

    // 0x80102AF0: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80102AF4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80102AF8: nop

    // 0x80102AFC: bc1fl       L_80102B10
    if (!c1cs) {
        // 0x80102B00: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_80102B10;
    }
    goto skip_5;
    // 0x80102B00: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    skip_5:
    // 0x80102B04: b           L_80102B10
    // 0x80102B08: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_80102B10;
    // 0x80102B08: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80102B0C: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
L_80102B10:
    // 0x80102B10: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_80102B14:
    // 0x80102B14: jal         0x800136E4
    // 0x80102B18: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x80102B18: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
    after_1:
L_80102B1C:
    // 0x80102B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102B20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102B24: jr          $ra
    // 0x80102B28: nop

    return;
    // 0x80102B28: nop

;}
RECOMP_FUNC void bswalk_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801454: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80801458: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080145C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80801460: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801468: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8080146C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80801470: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(435, 0X1514) << 16);
    // 0x80801474: lui         $a2, 0x4361
    ctx->r6 = S32(0X4361 << 16);
    // 0x80801478: bc1f        L_808014B0
    if (!c1cs) {
        // 0x8080147C: lui         $a3, 0x43FA
        ctx->r7 = S32(0X43FA << 16);
            goto L_808014B0;
    }
    // 0x8080147C: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x80801480: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(435, 0X150C) << 16);
    // 0x80801484: lwc1        $f4, 0x150C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0X150C));
    // 0x80801488: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(435, 0X1510) << 16);
    // 0x8080148C: lwc1        $f6, 0x1510($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0X1510));
    // 0x80801490: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801494: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801498: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x8080149C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808014A0: jal         0x8009FF44
    // 0x808014A4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_8009FF44(rdram, ctx);
        goto after_0;
    // 0x808014A4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x808014A8: b           L_808014CC
    // 0x808014AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014CC;
    // 0x808014AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808014B0:
    // 0x808014B0: lwc1        $f8, 0x1514($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0X1514));
    // 0x808014B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(435, 0X1518) << 16);
    // 0x808014B8: lwc1        $f10, 0x1518($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0X1518));
    // 0x808014BC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808014C0: jal         0x8009FF44
    // 0x808014C4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_8009FF44(rdram, ctx);
        goto after_1;
    // 0x808014C4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x808014C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808014CC:
    // 0x808014CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808014D0: jr          $ra
    // 0x808014D4: nop

    return;
    // 0x808014D4: nop

    // 0x808014D8: nop

    // 0x808014DC: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C40: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C40);
    return;
    // 0x80082C44: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void chchuffycont_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AAC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1704, 0XB84) << 16);
    // 0x80800AB0: jr          $ra
    // 0x80800AB4: addiu       $v0, $v0, 0xB84
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1704, 0XB84));
    return;
    // 0x80800AB4: addiu       $v0, $v0, 0xB84
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1704, 0XB84));
;}
RECOMP_FUNC void func_800C9750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9750: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9754: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C9758: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C975C: addiu       $s0, $s0, -0x54A0
    ctx->r16 = ADD32(ctx->r16, -0X54A0);
    // 0x800C9760: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800C9764: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9768: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C976C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C9770: bne         $a0, $zero, L_800C9794
    if (ctx->r4 != 0) {
        // 0x800C9774: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_800C9794;
    }
    // 0x800C9774: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800C9778: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x800C977C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800C9780: jal         0x800B2D70
    // 0x800C9784: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    vector_new(rdram, ctx);
        goto after_0;
    // 0x800C9784: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800C9788: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C978C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800C9790: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800C9794:
    // 0x800C9794: jal         0x800B28C4
    // 0x800C9798: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x800C9798: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800C979C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800C97A0: jal         0x800B296C
    // 0x800C97A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    vector_end(rdram, ctx);
        goto after_2;
    // 0x800C97A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x800C97A8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C97AC: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C97B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C97B4: bne         $v0, $a2, L_800C97C8
    if (ctx->r2 != ctx->r6) {
        // 0x800C97B8: sltu        $at, $a2, $v0
        ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
            goto L_800C97C8;
    }
    // 0x800C97B8: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x800C97BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C97C0: b           L_800C97D0
    // 0x800C97C4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
        goto L_800C97D0;
    // 0x800C97C4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
L_800C97C8:
    // 0x800C97C8: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800C97CC: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_800C97D0:
    // 0x800C97D0: beq         $at, $zero, L_800C97FC
    if (ctx->r1 == 0) {
        // 0x800C97D4: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_800C97FC;
    }
    // 0x800C97D4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800C97D8: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
L_800C97DC:
    // 0x800C97DC: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800C97E0: nop

    // 0x800C97E4: bc1tl       L_800C9800
    if (c1cs) {
        // 0x800C97E8: subu        $a1, $v1, $a2
        ctx->r5 = SUB32(ctx->r3, ctx->r6);
            goto L_800C9800;
    }
    goto skip_0;
    // 0x800C97E8: subu        $a1, $v1, $a2
    ctx->r5 = SUB32(ctx->r3, ctx->r6);
    skip_0:
    // 0x800C97EC: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
    // 0x800C97F0: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800C97F4: bnel        $at, $zero, L_800C97DC
    if (ctx->r1 != 0) {
        // 0x800C97F8: lwc1        $f8, 0x0($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
            goto L_800C97DC;
    }
    goto skip_1;
    // 0x800C97F8: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    skip_1:
L_800C97FC:
    // 0x800C97FC: subu        $a1, $v1, $a2
    ctx->r5 = SUB32(ctx->r3, ctx->r6);
L_800C9800:
    // 0x800C9800: addiu       $at, $zero, 0x70
    ctx->r1 = ADD32(0, 0X70);
    // 0x800C9804: div         $zero, $a1, $at
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r1)));
    // 0x800C9808: mflo        $a1
    ctx->r5 = lo;
    // 0x800C980C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C9810: jal         0x800B2B38
    // 0x800C9814: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    vector_insert(rdram, ctx);
        goto after_3;
    // 0x800C9814: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x800C9818: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C981C: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x800C9820: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9824: sb          $t7, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r15;
    // 0x800C9828: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800C982C: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x800C9830: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800C9834: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x800C9838: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800C983C: sw          $t0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r8;
    // 0x800C9840: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800C9844: sw          $t1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r9;
    // 0x800C9848: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800C984C: sw          $t2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r10;
    // 0x800C9850: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800C9854: sw          $t3, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r11;
    // 0x800C9858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C985C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C9860: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9864: jr          $ra
    // 0x800C9868: nop

    return;
    // 0x800C9868: nop

;}
RECOMP_FUNC void func_808003A8_chmumbohealspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003AC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808003B0: beq         $a1, $at, L_808003EC
    if (ctx->r5 == ctx->r1) {
        // 0x808003B4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808003EC;
    }
    // 0x808003B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B8: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x808003BC: beq         $a1, $at, L_8080041C
    if (ctx->r5 == ctx->r1) {
        // 0x808003C0: addiu       $at, $zero, 0x4B
        ctx->r1 = ADD32(0, 0X4B);
            goto L_8080041C;
    }
    // 0x808003C0: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x808003C4: bne         $a1, $at, L_80800440
    if (ctx->r5 != ctx->r1) {
        // 0x808003C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800440;
    }
    // 0x808003C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808003D0: jal         0x80800450
    // 0x808003D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800450_chmumbohealspell(rdram, ctx);
        goto after_0;
    // 0x808003D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003DC: jal         0x80103110
    // 0x808003E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x808003E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808003E4: b           L_80800440
    // 0x808003E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800440;
    // 0x808003E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003EC:
    // 0x808003EC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x808003F0: bne         $a2, $at, L_80800414
    if (ctx->r6 != ctx->r1) {
        // 0x808003F4: nop
    
            goto L_80800414;
    }
    // 0x808003F4: nop

    // 0x808003F8: jal         0x80085710
    // 0x808003FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _capod_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x808003FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800400: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800404: jal         0x80800450
    // 0x80800408: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800450_chmumbohealspell(rdram, ctx);
        goto after_3;
    // 0x80800408: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_3:
    // 0x8080040C: b           L_80800440
    // 0x80800410: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800440;
    // 0x80800410: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800414:
    // 0x80800414: b           L_80800440
    // 0x80800418: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800440;
    // 0x80800418: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080041C:
    // 0x8080041C: addiu       $at, $zero, 0x71
    ctx->r1 = ADD32(0, 0X71);
    // 0x80800420: bne         $a2, $at, L_80800438
    if (ctx->r6 != ctx->r1) {
        // 0x80800424: nop
    
            goto L_80800438;
    }
    // 0x80800424: nop

    // 0x80800428: jal         0x80800450
    // 0x8080042C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800450_chmumbohealspell(rdram, ctx);
        goto after_4;
    // 0x8080042C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x80800430: b           L_80800440
    // 0x80800434: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800440;
    // 0x80800434: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800438:
    // 0x80800438: b           L_80800440
    // 0x8080043C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800440;
    // 0x8080043C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800440:
    // 0x80800440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800448: jr          $ra
    // 0x8080044C: nop

    return;
    // 0x8080044C: nop

;}
RECOMP_FUNC void func_800AE6BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE6BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE6C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE6C4: lh          $a1, 0xC($a0)
    ctx->r5 = MEM_H(ctx->r4, 0XC);
    // 0x800AE6C8: beql        $a1, $zero, L_800AE6EC
    if (ctx->r5 == 0) {
        // 0x800AE6CC: lw          $v0, 0x8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8);
            goto L_800AE6EC;
    }
    goto skip_0;
    // 0x800AE6CC: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x800AE6D0: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x800AE6D4: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AE6D8: jal         0x800E0A28
    // 0x800AE6DC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800E0A28(rdram, ctx);
        goto after_0;
    // 0x800AE6DC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x800AE6E0: b           L_800AE6F0
    // 0x800AE6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800AE6F0;
    // 0x800AE6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE6E8: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
L_800AE6EC:
    // 0x800AE6EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AE6F0:
    // 0x800AE6F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE6F4: jr          $ra
    // 0x800AE6F8: nop

    return;
    // 0x800AE6F8: nop

;}
RECOMP_FUNC void func_808003B0_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808003B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003BC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808003C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003C4: jal         0x80100094
    // 0x808003C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003CC: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x808003D0: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x808003D4: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x808003D8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x808003DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808003E0: srl         $t6, $a0, 10
    ctx->r14 = S32(U32(ctx->r4) >> 10);
    // 0x808003E4: beq         $t7, $t6, L_80800758
    if (ctx->r15 == ctx->r14) {
        // 0x808003E8: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80800758;
    }
    // 0x808003E8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x808003EC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x808003F0: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x808003F4: sltiu       $at, $t9, 0xC
    ctx->r1 = ctx->r25 < 0XC ? 1 : 0;
    // 0x808003F8: beq         $at, $zero, L_808006F0
    if (ctx->r1 == 0) {
        // 0x808003FC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808006F0;
    }
    // 0x808003FC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800400: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(740, 0X17B0) << 16);
    // 0x80800404: addu        $at, $at, $t9
    gpr jr_addend_8080040C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800408: lw          $t9, 0x17B0($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(740, 0X17B0));
    // 0x8080040C: jr          $t9
    // 0x80800410: nop

    switch (jr_addend_8080040C >> 2) {
        case 0: goto L_80800448; break;
        case 1: goto L_8080062C; break;
        case 2: goto L_80800598; break;
        case 3: goto L_808005D8; break;
        case 4: goto L_80800640; break;
        case 5: goto L_80800614; break;
        case 6: goto L_80800680; break;
        case 7: goto L_808006A8; break;
        case 8: goto L_80800474; break;
        case 9: goto L_8080056C; break;
        case 10: goto L_808004A0; break;
        case 11: goto L_80800414; break;
        default: switch_error(__func__, 0x8080040C, 0x808017B0);
    }
    // 0x80800410: nop

L_80800414:
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: jal         0x8008A2C0
    // 0x8080041C: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080041C: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    after_1:
    // 0x80800420: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800424: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800428: jal         0x808002E8
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002E8_chfishshootgame(rdram, ctx);
        goto after_2;
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800430: jal         0x800FFAB0
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800438: jal         0x800FFA88
    // 0x8080043C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_800FFA88(rdram, ctx);
        goto after_4;
    // 0x8080043C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_4:
    // 0x80800440: b           L_8080075C
    // 0x80800444: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080075C;
    // 0x80800444: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800448:
    // 0x80800448: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080044C: beq         $a0, $at, L_808006F0
    if (ctx->r4 == ctx->r1) {
        // 0x80800450: addiu       $a1, $v1, 0xB0
        ctx->r5 = ADD32(ctx->r3, 0XB0);
            goto L_808006F0;
    }
    // 0x80800450: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800458: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080045C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800460: jal         0x8008A2C8
    // 0x80800464: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800464: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80800468: addiu       $t0, $zero, 0xFEF
    ctx->r8 = ADD32(0, 0XFEF);
    // 0x8080046C: b           L_808006F0
    // 0x80800470: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
        goto L_808006F0;
    // 0x80800470: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
L_80800474:
    // 0x80800474: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800478: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(740, 0X17E0) << 16);
    // 0x8080047C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800480: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    // 0x80800484: lwc1        $f6, 0x17E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(740, 0X17E0));
    // 0x80800488: sb          $zero, 0x30($v1)
    MEM_B(0X30, ctx->r3) = 0;
    // 0x8080048C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800490: jal         0x800DA3B8
    // 0x80800494: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    func_800DA3B8(rdram, ctx);
        goto after_6;
    // 0x80800494: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    after_6:
    // 0x80800498: b           L_808006F4
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808006F4;
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004A0:
    // 0x808004A0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808004A4: bne         $a0, $at, L_80800530
    if (ctx->r4 != ctx->r1) {
        // 0x808004A8: addiu       $t2, $zero, 0x1023
        ctx->r10 = ADD32(0, 0X1023);
            goto L_80800530;
    }
    // 0x808004A8: addiu       $t2, $zero, 0x1023
    ctx->r10 = ADD32(0, 0X1023);
    // 0x808004AC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x808004B0: jal         0x800FC6B0
    // 0x808004B4: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    func_800FC6B0(rdram, ctx);
        goto after_7;
    // 0x808004B4: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_7:
    // 0x808004B8: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    // 0x808004BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004C0: jal         0x800FCAE0
    // 0x808004C4: addiu       $a2, $zero, 0xFA0
    ctx->r6 = ADD32(0, 0XFA0);
    func_800FCAE0(rdram, ctx);
        goto after_8;
    // 0x808004C4: addiu       $a2, $zero, 0xFA0
    ctx->r6 = ADD32(0, 0XFA0);
    after_8:
    // 0x808004C8: jal         0x800FCA90
    // 0x808004CC: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800FCA90(rdram, ctx);
        goto after_9;
    // 0x808004CC: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_9:
    // 0x808004D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004D4: jal         0x800DA3B8
    // 0x808004D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_10;
    // 0x808004D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808004DC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x808004E0: addiu       $t1, $zero, 0x1024
    ctx->r9 = ADD32(0, 0X1024);
    // 0x808004E4: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808004F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808004F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808004F8: jal         0x8008A2C8
    // 0x808004FC: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_11;
    // 0x808004FC: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    after_11:
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: jal         0x80800A90
    // 0x80800508: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80800A90_chfishshootgame(rdram, ctx);
        goto after_12;
    // 0x80800508: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_12:
    // 0x8080050C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800510: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800514: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800518: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080051C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800520: jal         0x80088098
    // 0x80800524: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_13;
    // 0x80800524: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x80800528: b           L_808006F4
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808006F4;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800530:
    // 0x80800530: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80800534: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80800538: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800540: jal         0x808002E8
    // 0x80800544: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    func_808002E8_chfishshootgame(rdram, ctx);
        goto after_14;
    // 0x80800544: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_14:
    // 0x80800548: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800554: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800558: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080055C: jal         0x8008A2C8
    // 0x80800560: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x80800560: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    after_15:
    // 0x80800564: b           L_808006F4
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808006F4;
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080056C:
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800570: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    // 0x80800574: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80800578: addiu       $a3, $zero, 0x2090
    ctx->r7 = ADD32(0, 0X2090);
    // 0x8080057C: jal         0x8008A2D0
    // 0x80800580: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_16;
    // 0x80800580: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_16:
    // 0x80800584: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800588: jal         0x800DA3B8
    // 0x8080058C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_17;
    // 0x8080058C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800590: b           L_808006F4
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808006F4;
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800598:
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080059C: jal         0x8008A2C0
    // 0x808005A0: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_18;
    // 0x808005A0: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    after_18:
    // 0x808005A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808005A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005AC: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x808005B0: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x808005B4: jal         0x800CE8D8
    // 0x808005B8: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    func_800CE8D8(rdram, ctx);
        goto after_19;
    // 0x808005B8: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    after_19:
    // 0x808005BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005C0: jal         0x800CE88C
    // 0x808005C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_20;
    // 0x808005C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x808005C8: jal         0x800FC6B0
    // 0x808005CC: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800FC6B0(rdram, ctx);
        goto after_21;
    // 0x808005CC: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_21:
    // 0x808005D0: b           L_808006F4
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808006F4;
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005D8:
    // 0x808005D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005E0: jal         0x800CE88C
    // 0x808005E4: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    func_800CE88C(rdram, ctx);
        goto after_22;
    // 0x808005E4: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_22:
    // 0x808005E8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(740, 0X1984) << 16);
    // 0x808005EC: addiu       $a2, $a2, 0x1984
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(740, 0X1984));
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F4: jal         0x80089D18
    // 0x808005F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_23;
    // 0x808005F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_23:
    // 0x808005FC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80800600: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800604: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800608: sb          $t3, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r11;
    // 0x8080060C: b           L_808006F0
    // 0x80800610: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_808006F0;
    // 0x80800610: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80800614:
    // 0x80800614: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800618: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x8080061C: jal         0x808001F0
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001F0_chfishshootgame(rdram, ctx);
        goto after_24;
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800624: b           L_808006F4
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808006F4;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080062C:
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800630: jal         0x808002E8
    // 0x80800634: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_808002E8_chfishshootgame(rdram, ctx);
        goto after_25;
    // 0x80800634: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_25:
    // 0x80800638: b           L_808006F4
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808006F4;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800640:
    // 0x80800640: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(740, 0X17E4) << 16);
    // 0x80800644: lwc1        $f4, 0x17E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(740, 0X17E4));
    // 0x80800648: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080064C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800650: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800654: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800658: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x8080065C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800660: nop

    // 0x80800664: bc1fl       L_808006F4
    if (!c1cs) {
        // 0x80800668: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006F4;
    }
    goto skip_0;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080066C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800670: nop

    // 0x80800674: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800678: b           L_808006F0
    // 0x8080067C: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
        goto L_808006F0;
    // 0x8080067C: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
L_80800680:
    // 0x80800680: addiu       $t6, $zero, 0xFEE
    ctx->r14 = ADD32(0, 0XFEE);
    // 0x80800684: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    // 0x80800690: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800694: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800698: jal         0x8008A2C8
    // 0x8080069C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_26;
    // 0x8080069C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_26:
    // 0x808006A0: b           L_808006F4
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808006F4;
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006A8:
    // 0x808006A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808006AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808006B0: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x808006B4: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x808006B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808006BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(740, 0X17E8) << 16);
    // 0x808006C0: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
    // 0x808006C4: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x808006C8: swc1        $f0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f0.u32l;
    // 0x808006CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D0: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    // 0x808006D4: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x808006D8: lwc1        $f6, 0x17E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(740, 0X17E8));
    // 0x808006DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808006E0: addiu       $a3, $zero, 0x2090
    ctx->r7 = ADD32(0, 0X2090);
    // 0x808006E4: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    // 0x808006E8: jal         0x8008A2D0
    // 0x808006EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_27;
    // 0x808006EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_27:
L_808006F0:
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006F4:
    // 0x808006F4: jal         0x80102424
    // 0x808006F8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_80102424(rdram, ctx);
        goto after_28;
    // 0x808006F8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_28:
    // 0x808006FC: jal         0x80106790
    // 0x80800700: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_29;
    // 0x80800700: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_29:
    // 0x80800704: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800708: jal         0x80102424
    // 0x8080070C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_80102424(rdram, ctx);
        goto after_30;
    // 0x8080070C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_30:
    // 0x80800710: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80800714: beql        $t7, $zero, L_80800748
    if (ctx->r15 == 0) {
        // 0x80800718: lw          $t9, 0x44($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X44);
            goto L_80800748;
    }
    goto skip_1;
    // 0x80800718: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x8080071C: jal         0x80090270
    // 0x80800720: nop

    func_80090270(rdram, ctx);
        goto after_31;
    // 0x80800720: nop

    after_31:
    // 0x80800724: bne         $v0, $zero, L_80800744
    if (ctx->r2 != 0) {
        // 0x80800728: lw          $a1, 0x48($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X48);
            goto L_80800744;
    }
    // 0x80800728: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8080072C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800730: addiu       $t8, $zero, 0x63
    ctx->r24 = ADD32(0, 0X63);
    // 0x80800734: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800738: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8080073C: jal         0x8008A208
    // 0x80800740: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_32;
    // 0x80800740: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_32:
L_80800744:
    // 0x80800744: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_80800748:
    // 0x80800748: beql        $t9, $zero, L_8080075C
    if (ctx->r25 == 0) {
        // 0x8080074C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080075C;
    }
    goto skip_2;
    // 0x8080074C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800750: jal         0x800DA544
    // 0x80800754: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_33;
    // 0x80800754: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_33:
L_80800758:
    // 0x80800758: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080075C:
    // 0x8080075C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800760: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800764: jr          $ra
    // 0x80800768: nop

    return;
    // 0x80800768: nop

;}
RECOMP_FUNC void func_80801D28_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D28: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80801D2C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801D30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801D34: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801D38: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80801D3C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80801D40: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80801D44: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80801D48: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801D4C: jal         0x80106790
    // 0x80801D50: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801D50: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80801D54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801D58: jal         0x80100094
    // 0x80801D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801D60: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x80801D64: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80801D68: jal         0x800E3980
    // 0x80801D6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E3980(rdram, ctx);
        goto after_2;
    // 0x80801D6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80801D70: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801D74: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    // 0x80801D78: jal         0x800EEAD4
    // 0x80801D7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_3;
    // 0x80801D7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80801D80: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x80801D84: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80801D88: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80801D8C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80801D90: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80801D94: or          $s5, $v1, $zero
    ctx->r21 = ctx->r3 | 0;
L_80801D98:
    // 0x80801D98: lwc1        $f2, 0x18($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X18);
    // 0x80801D9C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80801DA0: nop

    // 0x80801DA4: bc1tl       L_80801DCC
    if (c1cs) {
        // 0x80801DA8: slti        $at, $s4, 0x2
        ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
            goto L_80801DCC;
    }
    goto skip_0;
    // 0x80801DA8: slti        $at, $s4, 0x2
    ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
    skip_0:
    // 0x80801DAC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80801DB0: nop

    // 0x80801DB4: bc1tl       L_80801DCC
    if (c1cs) {
        // 0x80801DB8: slti        $at, $s4, 0x2
        ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
            goto L_80801DCC;
    }
    goto skip_1;
    // 0x80801DB8: slti        $at, $s4, 0x2
    ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
    skip_1:
    // 0x80801DBC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80801DC0: bne         $s4, $v0, L_80801D98
    if (ctx->r20 != ctx->r2) {
        // 0x80801DC4: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_80801D98;
    }
    // 0x80801DC4: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80801DC8: slti        $at, $s4, 0x2
    ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
L_80801DCC:
    // 0x80801DCC: beql        $at, $zero, L_80801E38
    if (ctx->r1 == 0) {
        // 0x80801DD0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80801E38;
    }
    goto skip_2;
    // 0x80801DD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80801DD4: bgtz        $s4, L_80801E14
    if (SIGNED(ctx->r20) > 0) {
        // 0x80801DD8: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_80801E14;
    }
    // 0x80801DD8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80801DDC: addiu       $s1, $v1, 0xC
    ctx->r17 = ADD32(ctx->r3, 0XC);
    // 0x80801DE0: addiu       $s3, $s1, -0xC
    ctx->r19 = ADD32(ctx->r17, -0XC);
    // 0x80801DE4: addiu       $s0, $v1, 0x4
    ctx->r16 = ADD32(ctx->r3, 0X4);
L_80801DE8:
    // 0x80801DE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801DEC: jal         0x800EE7F8
    // 0x80801DF0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80801DF0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x80801DF4: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80801DF8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80801DFC: addiu       $s1, $s1, -0xC
    ctx->r17 = ADD32(ctx->r17, -0XC);
    // 0x80801E00: addiu       $s3, $s3, -0xC
    ctx->r19 = ADD32(ctx->r19, -0XC);
    // 0x80801E04: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // 0x80801E08: bne         $s4, $s2, L_80801DE8
    if (ctx->r20 != ctx->r18) {
        // 0x80801E0C: swc1        $f4, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
            goto L_80801DE8;
    }
    // 0x80801E0C: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x80801E10: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
L_80801E14:
    // 0x80801E14: sll         $t6, $s4, 2
    ctx->r14 = S32(ctx->r20 << 2);
    // 0x80801E18: subu        $t6, $t6, $s4
    ctx->r14 = SUB32(ctx->r14, ctx->r20);
    // 0x80801E1C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801E20: addu        $a0, $v1, $t6
    ctx->r4 = ADD32(ctx->r3, ctx->r14);
    // 0x80801E24: jal         0x800EE7F8
    // 0x80801E28: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80801E28: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_5:
    // 0x80801E2C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80801E30: swc1        $f6, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->f6.u32l;
    // 0x80801E34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80801E38:
    // 0x80801E38: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801E3C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801E40: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801E44: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801E48: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80801E4C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80801E50: jr          $ra
    // 0x80801E54: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80801E54: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80801E58: nop

    // 0x80801E5C: nop

;}
