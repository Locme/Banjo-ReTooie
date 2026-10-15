#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800E9708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9708: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E970C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9710: jal         0x800EA370
    // 0x800E9714: nop

    func_800EA370(rdram, ctx);
        goto after_0;
    // 0x800E9714: nop

    after_0:
    // 0x800E9718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E971C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9720: jr          $ra
    // 0x800E9724: nop

    return;
    // 0x800E9724: nop

;}
RECOMP_FUNC void func_800D395C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D395C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D3960: lbu         $v0, -0x4C0E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4C0E);
    // 0x800D3964: xori        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 ^ 0X2;
    // 0x800D3968: jr          $ra
    // 0x800D396C: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    return;
    // 0x800D396C: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_800AD1AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD1AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800AD1B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AD1B4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800AD1B8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800AD1BC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800AD1C0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800AD1C4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800AD1C8: jal         0x80019CD4
    // 0x800AD1CC: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_80019CD4(rdram, ctx);
        goto after_0;
    // 0x800AD1CC: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_0:
    // 0x800AD1D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD1D4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800AD1D8: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800AD1DC: jal         0x8001980C
    // 0x800AD1E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8001980C(rdram, ctx);
        goto after_1;
    // 0x800AD1E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800AD1E4: addiu       $s1, $sp, 0x3C
    ctx->r17 = ADD32(ctx->r29, 0X3C);
    // 0x800AD1E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800AD1EC: jal         0x80019224
    // 0x800AD1F0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_80019224(rdram, ctx);
        goto after_2;
    // 0x800AD1F0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_2:
    // 0x800AD1F4: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800AD1F8: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800AD1FC: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800AD200: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800AD204: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AD208: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800AD20C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800AD210: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800AD214: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800AD218: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800AD21C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800AD220: jal         0x800AC978
    // 0x800AD224: nop

    func_800AC978(rdram, ctx);
        goto after_3;
    // 0x800AD224: nop

    after_3:
    // 0x800AD228: bne         $v0, $zero, L_800AD238
    if (ctx->r2 != 0) {
        // 0x800AD22C: sw          $v0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r2;
            goto L_800AD238;
    }
    // 0x800AD22C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800AD230: b           L_800AD2B4
    // 0x800AD234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AD2B4;
    // 0x800AD234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AD238:
    // 0x800AD238: jal         0x80019CD4
    // 0x800AD23C: nop

    func_80019CD4(rdram, ctx);
        goto after_4;
    // 0x800AD23C: nop

    after_4:
    // 0x800AD240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD244: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800AD248: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800AD24C: jal         0x80019750
    // 0x800AD250: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80019750(rdram, ctx);
        goto after_5;
    // 0x800AD250: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x800AD254: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800AD258: jal         0x80019224
    // 0x800AD25C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80019224(rdram, ctx);
        goto after_6;
    // 0x800AD25C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800AD260: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800AD264: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800AD268: addiu       $s1, $s1, 0x795C
    ctx->r17 = ADD32(ctx->r17, 0X795C);
    // 0x800AD26C: addiu       $s0, $s0, 0x7938
    ctx->r16 = ADD32(ctx->r16, 0X7938);
    // 0x800AD270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800AD274:
    // 0x800AD274: jal         0x80019224
    // 0x800AD278: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80019224(rdram, ctx);
        goto after_7;
    // 0x800AD278: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800AD27C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800AD280: bnel        $s0, $s1, L_800AD274
    if (ctx->r16 != ctx->r17) {
        // 0x800AD284: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800AD274;
    }
    goto skip_0;
    // 0x800AD284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800AD288: jal         0x80019CD4
    // 0x800AD28C: nop

    func_80019CD4(rdram, ctx);
        goto after_8;
    // 0x800AD28C: nop

    after_8:
    // 0x800AD290: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AD294: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800AD298: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800AD29C: jal         0x80019750
    // 0x800AD2A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80019750(rdram, ctx);
        goto after_9;
    // 0x800AD2A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x800AD2A4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x800AD2A8: jal         0x80019224
    // 0x800AD2AC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80019224(rdram, ctx);
        goto after_10;
    // 0x800AD2AC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_10:
    // 0x800AD2B0: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_800AD2B4:
    // 0x800AD2B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AD2B8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD2BC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800AD2C0: jr          $ra
    // 0x800AD2C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800AD2C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80802964_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802964: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080296C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80802970: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80802974: jal         0x80106790
    // 0x80802978: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802978: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x8080297C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80802980: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802984: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802988: lhu         $t8, 0x72($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X72);
    // 0x8080298C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80802990: beql        $t9, $at, L_808029CC
    if (ctx->r25 == ctx->r1) {
        // 0x80802994: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808029CC;
    }
    goto skip_0;
    // 0x80802994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802998: jal         0x80089AF8
    // 0x8080299C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x8080299C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x808029A0: beq         $v0, $zero, L_808029C8
    if (ctx->r2 == 0) {
        // 0x808029A4: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_808029C8;
    }
    // 0x808029A4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808029A8: jal         0x800F5A00
    // 0x808029AC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x808029AC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x808029B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808029B4: lui         $a2, 0x427B
    ctx->r6 = S32(0X427B << 16);
    // 0x808029B8: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x808029BC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x808029C0: jal         0x80089B00
    // 0x808029C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _sukickball_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x808029C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
L_808029C8:
    // 0x808029C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808029CC:
    // 0x808029CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808029D0: jr          $ra
    // 0x808029D4: nop

    return;
    // 0x808029D4: nop

;}
RECOMP_FUNC void func_80012030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80012034: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80012038: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001203C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80012040: addiu       $a0, $a0, 0x3380
    ctx->r4 = ADD32(ctx->r4, 0X3380);
    // 0x80012044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012048: addiu       $t6, $t6, 0x15C0
    ctx->r14 = ADD32(ctx->r14, 0X15C0);
    // 0x8001204C: jal         0x8002D6E0
    // 0x80012050: subu        $a1, $t6, $a0
    ctx->r5 = SUB32(ctx->r14, ctx->r4);
    _bzero(rdram, ctx);
        goto after_0;
    // 0x80012050: subu        $a1, $t6, $a0
    ctx->r5 = SUB32(ctx->r14, ctx->r4);
    after_0:
    // 0x80012054: jal         0x8002D780
    // 0x80012058: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_1;
    // 0x80012058: nop

    after_1:
    // 0x8001205C: jal         0x8002D7B0
    // 0x80012060: nop

    osInitialize_recomp(rdram, ctx);
        goto after_2;
    // 0x80012060: nop

    after_2:
    // 0x80012064: jal         0x80013620
    // 0x80012068: nop

    func_80013620(rdram, ctx);
        goto after_3;
    // 0x80012068: nop

    after_3:
    // 0x8001206C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80012074: jr          $ra
    // 0x80012078: nop

    return;
    // 0x80012078: nop

;}
RECOMP_FUNC void chprisonbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1932, 0XFC0) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xFC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1932, 0XFC0));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xFC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1932, 0XFC0));
;}
RECOMP_FUNC void ncbadie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000D8: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x808000DC: jr          $ra
    // 0x808000E0: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808000E0: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void bsbpeck_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080021C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800220: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800224: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800228: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080022C: jal         0x8008CABC
    // 0x80800230: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800230: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800234: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800238: jal         0x800841D8
    // 0x8080023C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080023C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800240: lw          $t6, 0x164($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X164);
    // 0x80800244: beql        $t6, $zero, L_80800274
    if (ctx->r14 == 0) {
        // 0x80800248: lw          $v0, 0x15C($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X15C);
            goto L_80800274;
    }
    goto skip_0;
    // 0x80800248: lw          $v0, 0x15C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X15C);
    skip_0:
    // 0x8080024C: jal         0x8009BB00
    // 0x80800250: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800250: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800254: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(108, 0X49C) << 16);
    // 0x80800258: lwc1        $f4, 0x49C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(108, 0X49C));
    // 0x8080025C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800260: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800264: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800268: jal         0x8009B9B0
    // 0x8080026C: nop

    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x8080026C: nop

    after_3:
    // 0x80800270: lw          $v0, 0x15C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X15C);
L_80800274:
    // 0x80800274: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: beq         $v0, $zero, L_808002A0
    if (ctx->r2 == 0) {
        // 0x80800280: lui         $a1, 0x3F69
        ctx->r5 = S32(0X3F69 << 16);
            goto L_808002A0;
    }
    // 0x80800280: lui         $a1, 0x3F69
    ctx->r5 = S32(0X3F69 << 16);
    // 0x80800284: beq         $v0, $at, L_80800300
    if (ctx->r2 == ctx->r1) {
        // 0x80800288: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800300;
    }
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800290: beq         $v0, $at, L_808003C4
    if (ctx->r2 == ctx->r1) {
        // 0x80800294: nop
    
            goto L_808003C4;
    }
    // 0x80800294: nop

    // 0x80800298: b           L_808003D8
    // 0x8080029C: nop

        goto L_808003D8;
    // 0x8080029C: nop

L_808002A0:
    // 0x808002A0: jal         0x8008B348
    // 0x808002A4: ori         $a1, $a1, 0xA027
    ctx->r5 = ctx->r5 | 0XA027;
    anctrl_isAt(rdram, ctx);
        goto after_4;
    // 0x808002A4: ori         $a1, $a1, 0xA027
    ctx->r5 = ctx->r5 | 0XA027;
    after_4:
    // 0x808002A8: beq         $v0, $zero, L_808003D8
    if (ctx->r2 == 0) {
        // 0x808002AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D8;
    }
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: jal         0x8008AED4
    // 0x808002B4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x808002B4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_5:
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002BC: jal         0x8008B24C
    // 0x808002C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x808002C0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808002C4: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    // 0x808002C8: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808002CC: jal         0x8008B1BC
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_7;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: jal         0x8008B134
    // 0x808002DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x808002DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x808002E0: jal         0x8008B064
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808002E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808002EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808002F4: sw          $t7, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r15;
    // 0x808002F8: b           L_808003D8
    // 0x808002FC: swc1        $f8, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f8.u32l;
        goto L_808003D8;
    // 0x808002FC: swc1        $f8, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f8.u32l;
L_80800300:
    // 0x80800300: lui         $a1, 0x3E25
    ctx->r5 = S32(0X3E25 << 16);
    // 0x80800304: jal         0x8008B348
    // 0x80800308: ori         $a1, $a1, 0xFD8B
    ctx->r5 = ctx->r5 | 0XFD8B;
    anctrl_isAt(rdram, ctx);
        goto after_10;
    // 0x80800308: ori         $a1, $a1, 0xFD8B
    ctx->r5 = ctx->r5 | 0XFD8B;
    after_10:
    // 0x8080030C: beql        $v0, $zero, L_80800320
    if (ctx->r2 == 0) {
        // 0x80800310: lui         $a1, 0x3F33
        ctx->r5 = S32(0X3F33 << 16);
            goto L_80800320;
    }
    goto skip_1;
    // 0x80800310: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    skip_1:
    // 0x80800314: jal         0x80800168
    // 0x80800318: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800168_bsbpeck(rdram, ctx);
        goto after_11;
    // 0x80800318: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8080031C: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
L_80800320:
    // 0x80800320: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800324: jal         0x8008B348
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_12;
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080032C: beq         $v0, $zero, L_8080033C
    if (ctx->r2 == 0) {
        // 0x80800330: nop
    
            goto L_8080033C;
    }
    // 0x80800330: nop

    // 0x80800334: jal         0x80800168
    // 0x80800338: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800168_bsbpeck(rdram, ctx);
        goto after_13;
    // 0x80800338: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
L_8080033C:
    // 0x8080033C: jal         0x800D8FF8
    // 0x80800340: nop

    func_800D8FF8(rdram, ctx);
        goto after_14;
    // 0x80800340: nop

    after_14:
    // 0x80800344: lwc1        $f10, 0x16C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X16C);
    // 0x80800348: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080034C: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80800350: swc1        $f16, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f16.u32l;
    // 0x80800354: lwc1        $f18, 0x16C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X16C);
    // 0x80800358: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8080035C: nop

    // 0x80800360: bc1f        L_808003D8
    if (!c1cs) {
        // 0x80800364: nop
    
            goto L_808003D8;
    }
    // 0x80800364: nop

    // 0x80800368: jal         0x8008AF24
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_15;
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: jal         0x8008B1A0
    // 0x80800378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_16;
    // 0x80800378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800380: jal         0x8008AED4
    // 0x80800384: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    anctrl_setIndex(rdram, ctx);
        goto after_17;
    // 0x80800384: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_17:
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: jal         0x8008B188
    // 0x80800390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008B188(rdram, ctx);
        goto after_18;
    // 0x80800390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80800394: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800398: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080039C: jal         0x8008B1BC
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_19;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A8: jal         0x8008B134
    // 0x808003AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_20;
    // 0x808003AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x808003B0: jal         0x8008B064
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_21;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808003B8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x808003BC: b           L_808003D8
    // 0x808003C0: sw          $t8, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r24;
        goto L_808003D8;
    // 0x808003C0: sw          $t8, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->r24;
L_808003C4:
    // 0x808003C4: jal         0x8008B324
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_22;
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808003CC: beq         $v0, $zero, L_808003D8
    if (ctx->r2 == 0) {
        // 0x808003D0: addiu       $t9, $zero, 0x2F
        ctx->r25 = ADD32(0, 0X2F);
            goto L_808003D8;
    }
    // 0x808003D0: addiu       $t9, $zero, 0x2F
    ctx->r25 = ADD32(0, 0X2F);
    // 0x808003D4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_808003D8:
    // 0x808003D8: jal         0x8008E078
    // 0x808003DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    player_isStable(rdram, ctx);
        goto after_23;
    // 0x808003DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x808003E0: beq         $v0, $zero, L_808003F8
    if (ctx->r2 == 0) {
        // 0x808003E4: nop
    
            goto L_808003F8;
    }
    // 0x808003E4: nop

    // 0x808003E8: jal         0x8009FE58
    // 0x808003EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009FE58(rdram, ctx);
        goto after_24;
    // 0x808003EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_24:
    // 0x808003F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808003F4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_808003F8:
    // 0x808003F8: jal         0x8008E35C
    // 0x808003FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    player_inWater(rdram, ctx);
        goto after_25;
    // 0x808003FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x80800400: beq         $v0, $zero, L_80800410
    if (ctx->r2 == 0) {
        // 0x80800404: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800410;
    }
    // 0x80800404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800408: addiu       $t1, $zero, 0x4C
    ctx->r9 = ADD32(0, 0X4C);
    // 0x8080040C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80800410:
    // 0x80800410: jal         0x8009E5C8
    // 0x80800414: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_26;
    // 0x80800414: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_26:
    // 0x80800418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080041C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800420: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800424: jr          $ra
    // 0x80800428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _fxsplash_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088AE0: syscall     722
    recomp_syscall_handler(rdram, ctx, 0x80088AE0);
    return;
    // 0x80088AE4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bssplitup_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A88: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083A88);
    return;
    // 0x80083A8C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8010FD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FD60: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8010FD64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010FD68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010FD6C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8010FD70: jal         0x80114CC0
    // 0x8010FD74: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    func_80114CC0(rdram, ctx);
        goto after_0;
    // 0x8010FD74: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    after_0:
    // 0x8010FD78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010FD7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010FD80: jr          $ra
    // 0x8010FD84: nop

    return;
    // 0x8010FD84: nop

;}
RECOMP_FUNC void func_800D902C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D902C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D9030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9034: jal         0x800D8FF8
    // 0x800D9038: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800D9038: nop

    after_0:
    // 0x800D903C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800D9040: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D9044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D9048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D904C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800D9050: jr          $ra
    // 0x800D9054: nop

    return;
    // 0x800D9054: nop

;}
RECOMP_FUNC void chlavagargoyle_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CB4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2324, 0XF20) << 16);
    // 0x80800CB8: jr          $ra
    // 0x80800CBC: addiu       $v0, $v0, 0xF20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2324, 0XF20));
    return;
    // 0x80800CBC: addiu       $v0, $v0, 0xF20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2324, 0XF20));
;}
RECOMP_FUNC void func_80111310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80111314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80111318: jal         0x80110840
    // 0x8011131C: nop

    func_80110840(rdram, ctx);
        goto after_0;
    // 0x8011131C: nop

    after_0:
    // 0x80111320: jal         0x800F53D0
    // 0x80111324: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x80111324: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80111328: jal         0x800A509C
    // 0x8011132C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A509C(rdram, ctx);
        goto after_2;
    // 0x8011132C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80111330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80111334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80111338: jr          $ra
    // 0x8011133C: nop

    return;
    // 0x8011133C: nop

;}
RECOMP_FUNC void func_80800214_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080021C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800220: jal         0x8009C128
    // 0x80800224: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800224: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800228: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8080022C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x80800230: jal         0x801013A8
    // 0x80800234: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_801013A8(rdram, ctx);
        goto after_1;
    // 0x80800234: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800238: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080023C: jal         0x8009E5C8
    // 0x80800240: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800240: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_2:
    // 0x80800244: jal         0x800844B8
    // 0x80800248: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _bababykaz_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800248: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8080024C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800250: jal         0x800F82C0
    // 0x80800254: lw          $a0, 0x184($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X184);
    func_800F82C0(rdram, ctx);
        goto after_4;
    // 0x80800254: lw          $a0, 0x184($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X184);
    after_4:
    // 0x80800258: jal         0x800F9AFC
    // 0x8080025C: nop

    func_800F9AFC(rdram, ctx);
        goto after_5;
    // 0x8080025C: nop

    after_5:
    // 0x80800260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800264: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800268: jr          $ra
    // 0x8080026C: nop

    return;
    // 0x8080026C: nop

;}
RECOMP_FUNC void _chexploder_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086658: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x80086658);
    return;
    // 0x8008665C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808015DC_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015DC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808015E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808015E4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x808015E8: jal         0x80100094
    // 0x808015EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808015EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808015F0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x808015F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808015F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808015FC: jal         0x800897D8
    // 0x80801600: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80801600: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x80801604: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80801608: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080160C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801610: lwc1        $f4, 0x38($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X38);
    // 0x80801614: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801618: jal         0x8080144C
    // 0x8080161C: nop

    func_8080144C_chhumba(rdram, ctx);
        goto after_2;
    // 0x8080161C: nop

    after_2:
    // 0x80801620: jal         0x800C0638
    // 0x80801624: nop

    func_800C0638(rdram, ctx);
        goto after_3;
    // 0x80801624: nop

    after_3:
    // 0x80801628: beq         $v0, $zero, L_80801644
    if (ctx->r2 == 0) {
        // 0x8080162C: lw          $t9, 0x50($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X50);
            goto L_80801644;
    }
    // 0x8080162C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80801630: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80801634: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801638: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8080163C: b           L_80801674
    // 0x80801640: swc1        $f8, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f8.u32l;
        goto L_80801674;
    // 0x80801640: swc1        $f8, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f8.u32l;
L_80801644:
    // 0x80801644: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80801648: lwc1        $f16, 0x24($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X24);
    // 0x8080164C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80801650: nop

    // 0x80801654: bc1f        L_80801674
    if (!c1cs) {
        // 0x80801658: nop
    
            goto L_80801674;
    }
    // 0x80801658: nop

    // 0x8080165C: jal         0x800D8FF8
    // 0x80801660: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x80801660: nop

    after_4:
    // 0x80801664: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80801668: lwc1        $f18, 0x24($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X24);
    // 0x8080166C: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80801670: swc1        $f4, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f4.u32l;
L_80801674:
    // 0x80801674: jal         0x80800878
    // 0x80801678: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800878_chhumba(rdram, ctx);
        goto after_5;
    // 0x80801678: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_5:
    // 0x8080167C: beq         $v0, $zero, L_80801694
    if (ctx->r2 == 0) {
        // 0x80801680: lw          $t1, 0x50($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X50);
            goto L_80801694;
    }
    // 0x80801680: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80801684: jal         0x80800D74
    // 0x80801688: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800D74_chhumba(rdram, ctx);
        goto after_6;
    // 0x80801688: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_6:
    // 0x8080168C: b           L_808016D8
    // 0x80801690: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
        goto L_808016D8;
    // 0x80801690: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
L_80801694:
    // 0x80801694: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80801698: lwc1        $f8, 0x24($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X24);
    // 0x8080169C: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x808016A0: nop

    // 0x808016A4: bc1fl       L_808016D8
    if (!c1cs) {
        // 0x808016A8: lw          $t5, 0x50($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X50);
            goto L_808016D8;
    }
    goto skip_0;
    // 0x808016A8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x808016AC: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x808016B0: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x808016B4: bgez        $t4, L_808016CC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808016B8: nop
    
            goto L_808016CC;
    }
    // 0x808016B8: nop

    // 0x808016BC: jal         0x800D1824
    // 0x808016C0: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_800D1824(rdram, ctx);
        goto after_7;
    // 0x808016C0: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_7:
    // 0x808016C4: b           L_808016D8
    // 0x808016C8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
        goto L_808016D8;
    // 0x808016C8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
L_808016CC:
    // 0x808016CC: jal         0x800D1824
    // 0x808016D0: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    func_800D1824(rdram, ctx);
        goto after_8;
    // 0x808016D0: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_8:
    // 0x808016D4: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
L_808016D8:
    // 0x808016D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X24C8) << 16);
    // 0x808016DC: lwc1        $f10, 0x24C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1688, 0X24C8));
    // 0x808016E0: lwc1        $f0, 0x38($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X38);
    // 0x808016E4: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x808016E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808016EC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808016F0: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x808016F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808016F8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808016FC: addiu       $a0, $t5, 0x4
    ctx->r4 = ADD32(ctx->r13, 0X4);
    // 0x80801700: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801704: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80801708: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8080170C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80801710: jal         0x8008FB10
    // 0x80801714: nop

    func_8008FB10(rdram, ctx);
        goto after_9;
    // 0x80801714: nop

    after_9:
    // 0x80801718: jal         0x80090178
    // 0x8080171C: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    func_80090178(rdram, ctx);
        goto after_10;
    // 0x8080171C: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    after_10:
    // 0x80801720: bne         $v0, $zero, L_80801DA0
    if (ctx->r2 != 0) {
        // 0x80801724: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_80801DA0;
    }
    // 0x80801724: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80801728: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x8080172C: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80801730: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80801734: sltiu       $at, $t9, 0x13
    ctx->r1 = ctx->r25 < 0X13 ? 1 : 0;
    // 0x80801738: beq         $at, $zero, L_80801DA0
    if (ctx->r1 == 0) {
        // 0x8080173C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80801DA0;
    }
    // 0x8080173C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80801740: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X24CC) << 16);
    // 0x80801744: addu        $at, $at, $t9
    gpr jr_addend_8080174C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80801748: lw          $t9, 0x24CC($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1688, 0X24CC));
    // 0x8080174C: jr          $t9
    // 0x80801750: nop

    switch (jr_addend_8080174C >> 2) {
        case 0: goto L_80801754; break;
        case 1: goto L_80801DA0; break;
        case 2: goto L_8080186C; break;
        case 3: goto L_8080194C; break;
        case 4: goto L_808019E4; break;
        case 5: goto L_808019E4; break;
        case 6: goto L_80801A04; break;
        case 7: goto L_80801A84; break;
        case 8: goto L_80801A98; break;
        case 9: goto L_80801DA0; break;
        case 10: goto L_80801DA0; break;
        case 11: goto L_80801B58; break;
        case 12: goto L_80801BD4; break;
        case 13: goto L_80801BE8; break;
        case 14: goto L_80801DA0; break;
        case 15: goto L_80801DA0; break;
        case 16: goto L_80801C5C; break;
        case 17: goto L_80801928; break;
        case 18: goto L_80801CF8; break;
        default: switch_error(__func__, 0x8080174C, 0x808024CC);
    }
    // 0x80801750: nop

L_80801754:
    // 0x80801754: jal         0x800EA05C
    // 0x80801758: nop

    func_800EA05C(rdram, ctx);
        goto after_11;
    // 0x80801758: nop

    after_11:
    // 0x8080175C: addiu       $at, $zero, 0x120
    ctx->r1 = ADD32(0, 0X120);
    // 0x80801760: bne         $v0, $at, L_80801800
    if (ctx->r2 != ctx->r1) {
        // 0x80801764: lui         $a0, 0x6
        ctx->r4 = S32(0X6 << 16);
            goto L_80801800;
    }
    // 0x80801764: lui         $a0, 0x6
    ctx->r4 = S32(0X6 << 16);
    // 0x80801768: jal         0x8010D254
    // 0x8080176C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_8010D254(rdram, ctx);
        goto after_12;
    // 0x8080176C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_12:
    // 0x80801770: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80801774: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801778: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8080177C: lui         $a0, 0x6
    ctx->r4 = S32(0X6 << 16);
    // 0x80801780: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80801784: nop

    // 0x80801788: bc1fl       L_808017DC
    if (!c1cs) {
        // 0x8080178C: lui         $a1, 0x6
        ctx->r5 = S32(0X6 << 16);
            goto L_808017DC;
    }
    goto skip_1;
    // 0x8080178C: lui         $a1, 0x6
    ctx->r5 = S32(0X6 << 16);
    skip_1:
    // 0x80801790: jal         0x80090178
    // 0x80801794: ori         $a0, $a0, 0xC8E3
    ctx->r4 = ctx->r4 | 0XC8E3;
    func_80090178(rdram, ctx);
        goto after_13;
    // 0x80801794: ori         $a0, $a0, 0xC8E3
    ctx->r4 = ctx->r4 | 0XC8E3;
    after_13:
    // 0x80801798: beq         $v0, $zero, L_808017D8
    if (ctx->r2 == 0) {
        // 0x8080179C: lw          $t0, 0x50($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X50);
            goto L_808017D8;
    }
    // 0x8080179C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x808017A0: lwc1        $f18, 0x48($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X48);
    // 0x808017A4: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x808017A8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808017AC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808017B0: addiu       $a0, $t0, 0x4
    ctx->r4 = ADD32(ctx->r8, 0X4);
    // 0x808017B4: addiu       $a2, $zero, 0x15E
    ctx->r6 = ADD32(0, 0X15E);
    // 0x808017B8: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x808017BC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808017C0: jal         0x8008A1E0
    // 0x808017C4: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_14;
    // 0x808017C4: nop

    after_14:
    // 0x808017C8: beq         $v0, $zero, L_808017D8
    if (ctx->r2 == 0) {
        // 0x808017CC: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_808017D8;
    }
    // 0x808017CC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808017D0: jal         0x80800E44
    // 0x808017D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800E44_chhumba(rdram, ctx);
        goto after_15;
    // 0x808017D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
L_808017D8:
    // 0x808017D8: lui         $a1, 0x6
    ctx->r5 = S32(0X6 << 16);
L_808017DC:
    // 0x808017DC: ori         $a1, $a1, 0xC8E3
    ctx->r5 = ctx->r5 | 0XC8E3;
    // 0x808017E0: jal         0x80800934
    // 0x808017E4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800934_chhumba(rdram, ctx);
        goto after_16;
    // 0x808017E4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_16:
    // 0x808017E8: beq         $v0, $zero, L_80801DA0
    if (ctx->r2 == 0) {
        // 0x808017EC: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80801DA0;
    }
    // 0x808017EC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808017F0: jal         0x80800E44
    // 0x808017F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800E44_chhumba(rdram, ctx);
        goto after_17;
    // 0x808017F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
    // 0x808017F8: b           L_80801DA4
    // 0x808017FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x808017FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801800:
    // 0x80801800: jal         0x80090178
    // 0x80801804: ori         $a0, $a0, 0xC8E3
    ctx->r4 = ctx->r4 | 0XC8E3;
    func_80090178(rdram, ctx);
        goto after_18;
    // 0x80801804: ori         $a0, $a0, 0xC8E3
    ctx->r4 = ctx->r4 | 0XC8E3;
    after_18:
    // 0x80801808: beq         $v0, $zero, L_80801844
    if (ctx->r2 == 0) {
        // 0x8080180C: lw          $t3, 0x50($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X50);
            goto L_80801844;
    }
    // 0x8080180C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80801810: lwc1        $f6, 0x48($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X48);
    // 0x80801814: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801818: addiu       $a0, $t3, 0x4
    ctx->r4 = ADD32(ctx->r11, 0X4);
    // 0x8080181C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80801820: addiu       $a2, $zero, 0x15E
    ctx->r6 = ADD32(0, 0X15E);
    // 0x80801824: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80801828: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080182C: jal         0x8008A1E0
    // 0x80801830: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_19;
    // 0x80801830: nop

    after_19:
    // 0x80801834: beq         $v0, $zero, L_80801844
    if (ctx->r2 == 0) {
        // 0x80801838: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80801844;
    }
    // 0x80801838: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8080183C: jal         0x80800E44
    // 0x80801840: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800E44_chhumba(rdram, ctx);
        goto after_20;
    // 0x80801840: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_20:
L_80801844:
    // 0x80801844: lui         $a1, 0x6
    ctx->r5 = S32(0X6 << 16);
    // 0x80801848: ori         $a1, $a1, 0xC8E3
    ctx->r5 = ctx->r5 | 0XC8E3;
    // 0x8080184C: jal         0x80800934
    // 0x80801850: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800934_chhumba(rdram, ctx);
        goto after_21;
    // 0x80801850: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_21:
    // 0x80801854: beq         $v0, $zero, L_80801DA0
    if (ctx->r2 == 0) {
        // 0x80801858: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80801DA0;
    }
    // 0x80801858: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8080185C: jal         0x80800E44
    // 0x80801860: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800E44_chhumba(rdram, ctx);
        goto after_22;
    // 0x80801860: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_22:
    // 0x80801864: b           L_80801DA4
    // 0x80801868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080186C:
    // 0x8080186C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80801870: lw          $v0, 0x74($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X74);
    // 0x80801874: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80801878: bltz        $t7, L_80801DA0
    if (SIGNED(ctx->r15) < 0) {
        // 0x8080187C: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80801DA0;
    }
    // 0x8080187C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80801880: bgez        $t9, L_808018D8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80801884: nop
    
            goto L_808018D8;
    }
    // 0x80801884: nop

    // 0x80801888: jal         0x800D1A04
    // 0x8080188C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_800D1A04(rdram, ctx);
        goto after_23;
    // 0x8080188C: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_23:
    // 0x80801890: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801894: jal         0x808007EC
    // 0x80801898: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_808007EC_chhumba(rdram, ctx);
        goto after_24;
    // 0x80801898: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_24:
    // 0x8080189C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808018A0: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x808018A4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808018A8: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808018AC: bne         $at, $zero, L_808018C8
    if (ctx->r1 != 0) {
        // 0x808018B0: addiu       $a1, $zero, 0x11BF
        ctx->r5 = ADD32(0, 0X11BF);
            goto L_808018C8;
    }
    // 0x808018B0: addiu       $a1, $zero, 0x11BF
    ctx->r5 = ADD32(0, 0X11BF);
    // 0x808018B4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808018B8: jal         0x80800338
    // 0x808018BC: addiu       $a1, $zero, 0x11BE
    ctx->r5 = ADD32(0, 0X11BE);
    func_80800338_chhumba(rdram, ctx);
        goto after_25;
    // 0x808018BC: addiu       $a1, $zero, 0x11BE
    ctx->r5 = ADD32(0, 0X11BE);
    after_25:
    // 0x808018C0: b           L_80801DA4
    // 0x808018C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x808018C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018C8:
    // 0x808018C8: jal         0x80800338
    // 0x808018CC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800338_chhumba(rdram, ctx);
        goto after_26;
    // 0x808018CC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_26:
    // 0x808018D0: b           L_80801DA4
    // 0x808018D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x808018D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018D8:
    // 0x808018D8: jal         0x800D1A04
    // 0x808018DC: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    func_800D1A04(rdram, ctx);
        goto after_27;
    // 0x808018DC: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_27:
    // 0x808018E0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808018E4: jal         0x808007EC
    // 0x808018E8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_808007EC_chhumba(rdram, ctx);
        goto after_28;
    // 0x808018E8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_28:
    // 0x808018EC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x808018F0: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x808018F4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808018F8: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808018FC: bne         $at, $zero, L_80801918
    if (ctx->r1 != 0) {
        // 0x80801900: addiu       $a1, $zero, 0x11B3
        ctx->r5 = ADD32(0, 0X11B3);
            goto L_80801918;
    }
    // 0x80801900: addiu       $a1, $zero, 0x11B3
    ctx->r5 = ADD32(0, 0X11B3);
    // 0x80801904: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801908: jal         0x80800338
    // 0x8080190C: addiu       $a1, $zero, 0x11B0
    ctx->r5 = ADD32(0, 0X11B0);
    func_80800338_chhumba(rdram, ctx);
        goto after_29;
    // 0x8080190C: addiu       $a1, $zero, 0x11B0
    ctx->r5 = ADD32(0, 0X11B0);
    after_29:
    // 0x80801910: b           L_80801DA4
    // 0x80801914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801918:
    // 0x80801918: jal         0x80800338
    // 0x8080191C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800338_chhumba(rdram, ctx);
        goto after_30;
    // 0x8080191C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_30:
    // 0x80801920: b           L_80801DA4
    // 0x80801924: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801924: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801928:
    // 0x80801928: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8080192C: jal         0x80800BA8
    // 0x80801930: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80800BA8_chhumba(rdram, ctx);
        goto after_31;
    // 0x80801930: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_31:
    // 0x80801934: jal         0x8008F964
    // 0x80801938: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_8008F964(rdram, ctx);
        goto after_32;
    // 0x80801938: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_32:
    // 0x8080193C: jal         0x80800CC8
    // 0x80801940: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800CC8_chhumba(rdram, ctx);
        goto after_33;
    // 0x80801940: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_33:
    // 0x80801944: b           L_80801DA4
    // 0x80801948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080194C:
    // 0x8080194C: jal         0x800EA05C
    // 0x80801950: nop

    func_800EA05C(rdram, ctx);
        goto after_34;
    // 0x80801950: nop

    after_34:
    // 0x80801954: addiu       $at, $zero, 0x120
    ctx->r1 = ADD32(0, 0X120);
    // 0x80801958: bne         $v0, $at, L_80801974
    if (ctx->r2 != ctx->r1) {
        // 0x8080195C: lw          $t2, 0x50($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X50);
            goto L_80801974;
    }
    // 0x8080195C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80801960: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801964: jal         0x80108B04
    // 0x80801968: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_35;
    // 0x80801968: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_35:
    // 0x8080196C: b           L_80801DA4
    // 0x80801970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801974:
    // 0x80801974: lw          $t3, 0x74($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X74);
    // 0x80801978: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8080197C: lui         $a1, 0x451C
    ctx->r5 = S32(0X451C << 16);
    // 0x80801980: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80801984: bgez        $t5, L_80801994
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80801988: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80801994;
    }
    // 0x80801988: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080198C: b           L_80801998
    // 0x80801990: addiu       $a2, $zero, 0x523
    ctx->r6 = ADD32(0, 0X523);
        goto L_80801998;
    // 0x80801990: addiu       $a2, $zero, 0x523
    ctx->r6 = ADD32(0, 0X523);
L_80801994:
    // 0x80801994: addiu       $a2, $zero, 0x29F
    ctx->r6 = ADD32(0, 0X29F);
L_80801998:
    // 0x80801998: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x8080199C: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x808019A0: jal         0x800902E4
    // 0x808019A4: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    func_800902E4(rdram, ctx);
        goto after_36;
    // 0x808019A4: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_36:
    // 0x808019A8: beq         $v0, $zero, L_80801DA0
    if (ctx->r2 == 0) {
        // 0x808019AC: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_80801DA0;
    }
    // 0x808019AC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808019B0: jal         0x8008FE14
    // 0x808019B4: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    func_8008FE14(rdram, ctx);
        goto after_37;
    // 0x808019B4: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_37:
    // 0x808019B8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808019BC: bnel        $v0, $a2, L_80801DA4
    if (ctx->r2 != ctx->r6) {
        // 0x808019C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801DA4;
    }
    goto skip_2;
    // 0x808019C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808019C4: jal         0x80090818
    // 0x808019C8: nop

    func_80090818(rdram, ctx);
        goto after_38;
    // 0x808019C8: nop

    after_38:
    // 0x808019CC: beq         $v0, $zero, L_80801DA0
    if (ctx->r2 == 0) {
        // 0x808019D0: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80801DA0;
    }
    // 0x808019D0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808019D4: jal         0x80800E44
    // 0x808019D8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800E44_chhumba(rdram, ctx);
        goto after_39;
    // 0x808019D8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_39:
    // 0x808019DC: b           L_80801DA4
    // 0x808019E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x808019E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808019E4:
    // 0x808019E4: jal         0x808008A0
    // 0x808019E8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_808008A0_chhumba(rdram, ctx);
        goto after_40;
    // 0x808019E8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_40:
    // 0x808019EC: beq         $v0, $zero, L_80801DA0
    if (ctx->r2 == 0) {
        // 0x808019F0: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80801DA0;
    }
    // 0x808019F0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808019F4: jal         0x80800E44
    // 0x808019F8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800E44_chhumba(rdram, ctx);
        goto after_41;
    // 0x808019F8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_41:
    // 0x808019FC: b           L_80801DA4
    // 0x80801A00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801A00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801A04:
    // 0x80801A04: lui         $a0, 0x6
    ctx->r4 = S32(0X6 << 16);
    // 0x80801A08: jal         0x80090178
    // 0x80801A0C: ori         $a0, $a0, 0xC8E3
    ctx->r4 = ctx->r4 | 0XC8E3;
    func_80090178(rdram, ctx);
        goto after_42;
    // 0x80801A0C: ori         $a0, $a0, 0xC8E3
    ctx->r4 = ctx->r4 | 0XC8E3;
    after_42:
    // 0x80801A10: beq         $v0, $zero, L_80801A44
    if (ctx->r2 == 0) {
        // 0x80801A14: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_80801A44;
    }
    // 0x80801A14: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80801A18: lwc1        $f10, 0x48($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X48);
    // 0x80801A1C: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80801A20: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801A24: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80801A28: addiu       $a0, $t6, 0x4
    ctx->r4 = ADD32(ctx->r14, 0X4);
    // 0x80801A2C: addiu       $a2, $zero, 0x15E
    ctx->r6 = ADD32(0, 0X15E);
    // 0x80801A30: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80801A34: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80801A38: jal         0x8008A1E0
    // 0x80801A3C: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_43;
    // 0x80801A3C: nop

    after_43:
    // 0x80801A40: bne         $v0, $zero, L_80801A5C
    if (ctx->r2 != 0) {
        // 0x80801A44: lui         $a1, 0x6
        ctx->r5 = S32(0X6 << 16);
            goto L_80801A5C;
    }
L_80801A44:
    // 0x80801A44: lui         $a1, 0x6
    ctx->r5 = S32(0X6 << 16);
    // 0x80801A48: ori         $a1, $a1, 0xC8E3
    ctx->r5 = ctx->r5 | 0XC8E3;
    // 0x80801A4C: jal         0x80800934
    // 0x80801A50: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800934_chhumba(rdram, ctx);
        goto after_44;
    // 0x80801A50: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_44:
    // 0x80801A54: beq         $v0, $zero, L_80801A74
    if (ctx->r2 == 0) {
        // 0x80801A58: nop
    
            goto L_80801A74;
    }
    // 0x80801A58: nop

L_80801A5C:
    // 0x80801A5C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801A60: addiu       $a1, $zero, 0x11B8
    ctx->r5 = ADD32(0, 0X11B8);
    // 0x80801A64: jal         0x80800338
    // 0x80801A68: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800338_chhumba(rdram, ctx);
        goto after_45;
    // 0x80801A68: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_45:
    // 0x80801A6C: b           L_80801DA4
    // 0x80801A70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801A70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801A74:
    // 0x80801A74: jal         0x8080138C
    // 0x80801A78: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8080138C_chhumba(rdram, ctx);
        goto after_46;
    // 0x80801A78: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_46:
    // 0x80801A7C: b           L_80801DA4
    // 0x80801A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801A84:
    // 0x80801A84: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801A88: jal         0x80800E44
    // 0x80801A8C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800E44_chhumba(rdram, ctx);
        goto after_47;
    // 0x80801A8C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_47:
    // 0x80801A90: b           L_80801DA4
    // 0x80801A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801A98:
    // 0x80801A98: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80801A9C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80801AA0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801AA4: lwc1        $f4, 0x58($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X58);
    // 0x80801AA8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80801AAC: nop

    // 0x80801AB0: bc1f        L_80801B20
    if (!c1cs) {
        // 0x80801AB4: nop
    
            goto L_80801B20;
    }
    // 0x80801AB4: nop

    // 0x80801AB8: jal         0x800D8FF8
    // 0x80801ABC: nop

    func_800D8FF8(rdram, ctx);
        goto after_48;
    // 0x80801ABC: nop

    after_48:
    // 0x80801AC0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80801AC4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80801AC8: lwc1        $f6, 0x58($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X58);
    // 0x80801ACC: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80801AD0: swc1        $f8, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f8.u32l;
    // 0x80801AD4: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80801AD8: lw          $t2, 0x64($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X64);
    // 0x80801ADC: sll         $t4, $t2, 11
    ctx->r12 = S32(ctx->r10 << 11);
    // 0x80801AE0: bgez        $t4, L_80801B48
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80801AE4: nop
    
            goto L_80801B48;
    }
    // 0x80801AE4: nop

    // 0x80801AE8: lwc1        $f10, 0x58($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X58);
    // 0x80801AEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801AF0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80801AF4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80801AF8: nop

    // 0x80801AFC: bc1f        L_80801B48
    if (!c1cs) {
        // 0x80801B00: nop
    
            goto L_80801B48;
    }
    // 0x80801B00: nop

    // 0x80801B04: jal         0x80086D28
    // 0x80801B08: addiu       $a0, $a0, 0x6AE0
    ctx->r4 = ADD32(ctx->r4, 0X6AE0);
    _chbaddiesetup_entrypoint_0(rdram, ctx);
        goto after_49;
    // 0x80801B08: addiu       $a0, $a0, 0x6AE0
    ctx->r4 = ADD32(ctx->r4, 0X6AE0);
    after_49:
    // 0x80801B0C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80801B10: lbu         $t6, 0x65($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X65);
    // 0x80801B14: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80801B18: b           L_80801B48
    // 0x80801B1C: sb          $t7, 0x65($t5)
    MEM_B(0X65, ctx->r13) = ctx->r15;
        goto L_80801B48;
    // 0x80801B1C: sb          $t7, 0x65($t5)
    MEM_B(0X65, ctx->r13) = ctx->r15;
L_80801B20:
    // 0x80801B20: jal         0x800903D0
    // 0x80801B24: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800903D0(rdram, ctx);
        goto after_50;
    // 0x80801B24: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_50:
    // 0x80801B28: beq         $v0, $zero, L_80801B48
    if (ctx->r2 == 0) {
        // 0x80801B2C: lw          $t8, 0x50($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X50);
            goto L_80801B48;
    }
    // 0x80801B2C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80801B30: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    // 0x80801B34: jal         0x800904F4
    // 0x80801B38: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    func_800904F4(rdram, ctx);
        goto after_51;
    // 0x80801B38: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    after_51:
    // 0x80801B3C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801B40: jal         0x80800E44
    // 0x80801B44: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800E44_chhumba(rdram, ctx);
        goto after_52;
    // 0x80801B44: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_52:
L_80801B48:
    // 0x80801B48: jal         0x80801260
    // 0x80801B4C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80801260_chhumba(rdram, ctx);
        goto after_53;
    // 0x80801B4C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_53:
    // 0x80801B50: b           L_80801DA4
    // 0x80801B54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801B54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801B58:
    // 0x80801B58: lui         $a0, 0x6
    ctx->r4 = S32(0X6 << 16);
    // 0x80801B5C: jal         0x80090178
    // 0x80801B60: ori         $a0, $a0, 0xC8E3
    ctx->r4 = ctx->r4 | 0XC8E3;
    func_80090178(rdram, ctx);
        goto after_54;
    // 0x80801B60: ori         $a0, $a0, 0xC8E3
    ctx->r4 = ctx->r4 | 0XC8E3;
    after_54:
    // 0x80801B64: beq         $v0, $zero, L_80801B94
    if (ctx->r2 == 0) {
        // 0x80801B68: lw          $t9, 0x50($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X50);
            goto L_80801B94;
    }
    // 0x80801B68: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80801B6C: lwc1        $f18, 0x48($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X48);
    // 0x80801B70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801B74: addiu       $a0, $t9, 0x4
    ctx->r4 = ADD32(ctx->r25, 0X4);
    // 0x80801B78: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80801B7C: addiu       $a2, $zero, 0x15E
    ctx->r6 = ADD32(0, 0X15E);
    // 0x80801B80: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80801B84: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80801B88: jal         0x8008A1E0
    // 0x80801B8C: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_55;
    // 0x80801B8C: nop

    after_55:
    // 0x80801B90: bne         $v0, $zero, L_80801BAC
    if (ctx->r2 != 0) {
        // 0x80801B94: lui         $a1, 0x6
        ctx->r5 = S32(0X6 << 16);
            goto L_80801BAC;
    }
L_80801B94:
    // 0x80801B94: lui         $a1, 0x6
    ctx->r5 = S32(0X6 << 16);
    // 0x80801B98: ori         $a1, $a1, 0xC8E3
    ctx->r5 = ctx->r5 | 0XC8E3;
    // 0x80801B9C: jal         0x80800934
    // 0x80801BA0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800934_chhumba(rdram, ctx);
        goto after_56;
    // 0x80801BA0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_56:
    // 0x80801BA4: beq         $v0, $zero, L_80801BC4
    if (ctx->r2 == 0) {
        // 0x80801BA8: nop
    
            goto L_80801BC4;
    }
    // 0x80801BA8: nop

L_80801BAC:
    // 0x80801BAC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801BB0: addiu       $a1, $zero, 0x11B9
    ctx->r5 = ADD32(0, 0X11B9);
    // 0x80801BB4: jal         0x80800338
    // 0x80801BB8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800338_chhumba(rdram, ctx);
        goto after_57;
    // 0x80801BB8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_57:
    // 0x80801BBC: b           L_80801DA4
    // 0x80801BC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801BC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801BC4:
    // 0x80801BC4: jal         0x8080138C
    // 0x80801BC8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8080138C_chhumba(rdram, ctx);
        goto after_58;
    // 0x80801BC8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_58:
    // 0x80801BCC: b           L_80801DA4
    // 0x80801BD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801BD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801BD4:
    // 0x80801BD4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801BD8: jal         0x80800E44
    // 0x80801BDC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80800E44_chhumba(rdram, ctx);
        goto after_59;
    // 0x80801BDC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_59:
    // 0x80801BE0: b           L_80801DA4
    // 0x80801BE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801BE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801BE8:
    // 0x80801BE8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80801BEC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80801BF0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801BF4: lwc1        $f8, 0x58($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X58);
    // 0x80801BF8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80801BFC: nop

    // 0x80801C00: bc1f        L_80801C24
    if (!c1cs) {
        // 0x80801C04: nop
    
            goto L_80801C24;
    }
    // 0x80801C04: nop

    // 0x80801C08: jal         0x800D8FF8
    // 0x80801C0C: nop

    func_800D8FF8(rdram, ctx);
        goto after_60;
    // 0x80801C0C: nop

    after_60:
    // 0x80801C10: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80801C14: lwc1        $f10, 0x58($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X58);
    // 0x80801C18: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80801C1C: b           L_80801C4C
    // 0x80801C20: swc1        $f16, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f16.u32l;
        goto L_80801C4C;
    // 0x80801C20: swc1        $f16, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f16.u32l;
L_80801C24:
    // 0x80801C24: jal         0x800903D0
    // 0x80801C28: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800903D0(rdram, ctx);
        goto after_61;
    // 0x80801C28: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_61:
    // 0x80801C2C: beq         $v0, $zero, L_80801C4C
    if (ctx->r2 == 0) {
        // 0x80801C30: lw          $t4, 0x50($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X50);
            goto L_80801C4C;
    }
    // 0x80801C30: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80801C34: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    // 0x80801C38: jal         0x800904F4
    // 0x80801C3C: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    func_800904F4(rdram, ctx);
        goto after_62;
    // 0x80801C3C: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    after_62:
    // 0x80801C40: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801C44: jal         0x80800E44
    // 0x80801C48: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80800E44_chhumba(rdram, ctx);
        goto after_63;
    // 0x80801C48: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_63:
L_80801C4C:
    // 0x80801C4C: jal         0x80801260
    // 0x80801C50: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80801260_chhumba(rdram, ctx);
        goto after_64;
    // 0x80801C50: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_64:
    // 0x80801C54: b           L_80801DA4
    // 0x80801C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801C5C:
    // 0x80801C5C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80801C60: addiu       $a2, $zero, 0x15E
    ctx->r6 = ADD32(0, 0X15E);
    // 0x80801C64: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80801C68: lwc1        $f18, 0x48($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X48);
    // 0x80801C6C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801C70: addiu       $a0, $t1, 0x4
    ctx->r4 = ADD32(ctx->r9, 0X4);
    // 0x80801C74: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80801C78: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80801C7C: jal         0x8008A1E0
    // 0x80801C80: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_65;
    // 0x80801C80: nop

    after_65:
    // 0x80801C84: bne         $v0, $zero, L_80801C9C
    if (ctx->r2 != 0) {
        // 0x80801C88: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80801C9C;
    }
    // 0x80801C88: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801C8C: jal         0x80800934
    // 0x80801C90: addiu       $a1, $zero, 0x600
    ctx->r5 = ADD32(0, 0X600);
    func_80800934_chhumba(rdram, ctx);
        goto after_66;
    // 0x80801C90: addiu       $a1, $zero, 0x600
    ctx->r5 = ADD32(0, 0X600);
    after_66:
    // 0x80801C94: beq         $v0, $zero, L_80801CB4
    if (ctx->r2 == 0) {
        // 0x80801C98: lw          $t7, 0x50($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X50);
            goto L_80801CB4;
    }
    // 0x80801C98: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
L_80801C9C:
    // 0x80801C9C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801CA0: addiu       $a1, $zero, 0x11BC
    ctx->r5 = ADD32(0, 0X11BC);
    // 0x80801CA4: jal         0x80800338
    // 0x80801CA8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800338_chhumba(rdram, ctx);
        goto after_67;
    // 0x80801CA8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_67:
    // 0x80801CAC: b           L_80801DA4
    // 0x80801CB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801CB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801CB4:
    // 0x80801CB4: lw          $t5, 0x64($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X64);
    // 0x80801CB8: sll         $t9, $t5, 12
    ctx->r25 = S32(ctx->r13 << 12);
    // 0x80801CBC: bltzl       $t9, L_80801DA4
    if (SIGNED(ctx->r25) < 0) {
        // 0x80801CC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801DA4;
    }
    goto skip_3;
    // 0x80801CC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80801CC4: jal         0x80800A50
    // 0x80801CC8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_80800A50_chhumba(rdram, ctx);
        goto after_68;
    // 0x80801CC8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_68:
    // 0x80801CCC: beq         $v0, $zero, L_80801DA0
    if (ctx->r2 == 0) {
        // 0x80801CD0: lw          $t0, 0x50($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X50);
            goto L_80801DA0;
    }
    // 0x80801CD0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80801CD4: lbu         $t3, 0x65($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X65);
    // 0x80801CD8: addiu       $a1, $zero, 0x11BA
    ctx->r5 = ADD32(0, 0X11BA);
    // 0x80801CDC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80801CE0: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x80801CE4: sb          $t4, 0x65($t0)
    MEM_B(0X65, ctx->r8) = ctx->r12;
    // 0x80801CE8: jal         0x80800338
    // 0x80801CEC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800338_chhumba(rdram, ctx);
        goto after_69;
    // 0x80801CEC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_69:
    // 0x80801CF0: b           L_80801DA4
    // 0x80801CF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801CF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801CF8:
    // 0x80801CF8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80801CFC: addiu       $a2, $zero, 0x15E
    ctx->r6 = ADD32(0, 0X15E);
    // 0x80801D00: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80801D04: lwc1        $f6, 0x48($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X48);
    // 0x80801D08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801D0C: addiu       $a0, $t1, 0x4
    ctx->r4 = ADD32(ctx->r9, 0X4);
    // 0x80801D10: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80801D14: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80801D18: jal         0x8008A1E0
    // 0x80801D1C: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_70;
    // 0x80801D1C: nop

    after_70:
    // 0x80801D20: bne         $v0, $zero, L_80801D38
    if (ctx->r2 != 0) {
        // 0x80801D24: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80801D38;
    }
    // 0x80801D24: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801D28: jal         0x80800934
    // 0x80801D2C: addiu       $a1, $zero, 0x600
    ctx->r5 = ADD32(0, 0X600);
    func_80800934_chhumba(rdram, ctx);
        goto after_71;
    // 0x80801D2C: addiu       $a1, $zero, 0x600
    ctx->r5 = ADD32(0, 0X600);
    after_71:
    // 0x80801D30: beq         $v0, $zero, L_80801D64
    if (ctx->r2 == 0) {
        // 0x80801D34: lw          $t5, 0x50($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X50);
            goto L_80801D64;
    }
    // 0x80801D34: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
L_80801D38:
    // 0x80801D38: jal         0x80090178
    // 0x80801D3C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_80090178(rdram, ctx);
        goto after_72;
    // 0x80801D3C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_72:
    // 0x80801D40: beq         $v0, $zero, L_80801D50
    if (ctx->r2 == 0) {
        // 0x80801D44: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80801D50;
    }
    // 0x80801D44: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801D48: b           L_80801D54
    // 0x80801D4C: addiu       $a1, $zero, 0x121C
    ctx->r5 = ADD32(0, 0X121C);
        goto L_80801D54;
    // 0x80801D4C: addiu       $a1, $zero, 0x121C
    ctx->r5 = ADD32(0, 0X121C);
L_80801D50:
    // 0x80801D50: addiu       $a1, $zero, 0x121D
    ctx->r5 = ADD32(0, 0X121D);
L_80801D54:
    // 0x80801D54: jal         0x80800338
    // 0x80801D58: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800338_chhumba(rdram, ctx);
        goto after_73;
    // 0x80801D58: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_73:
    // 0x80801D5C: b           L_80801DA4
    // 0x80801D60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DA4;
    // 0x80801D60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801D64:
    // 0x80801D64: lw          $t8, 0x64($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X64);
    // 0x80801D68: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80801D6C: bltzl       $t7, L_80801DA4
    if (SIGNED(ctx->r15) < 0) {
        // 0x80801D70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801DA4;
    }
    goto skip_4;
    // 0x80801D70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80801D74: jal         0x80800A50
    // 0x80801D78: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_80800A50_chhumba(rdram, ctx);
        goto after_74;
    // 0x80801D78: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_74:
    // 0x80801D7C: beq         $v0, $zero, L_80801DA0
    if (ctx->r2 == 0) {
        // 0x80801D80: lw          $t2, 0x50($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X50);
            goto L_80801DA0;
    }
    // 0x80801D80: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80801D84: lbu         $t4, 0x65($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X65);
    // 0x80801D88: addiu       $a1, $zero, 0x11BB
    ctx->r5 = ADD32(0, 0X11BB);
    // 0x80801D8C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80801D90: ori         $t0, $t4, 0x8
    ctx->r8 = ctx->r12 | 0X8;
    // 0x80801D94: sb          $t0, 0x65($t2)
    MEM_B(0X65, ctx->r10) = ctx->r8;
    // 0x80801D98: jal         0x80800338
    // 0x80801D9C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800338_chhumba(rdram, ctx);
        goto after_75;
    // 0x80801D9C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_75:
L_80801DA0:
    // 0x80801DA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801DA4:
    // 0x80801DA4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801DA8: jr          $ra
    // 0x80801DAC: nop

    return;
    // 0x80801DAC: nop

;}
RECOMP_FUNC void func_800192FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800192FC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80019300: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80019304: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80019308: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
    // 0x8001930C: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019310: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80019314: addiu       $a0, $a0, -0x4350
    ctx->r4 = ADD32(ctx->r4, -0X4350);
    // 0x80019318: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x8001931C: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019320: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x80019324: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80019328: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x8001932C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80019330: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x80019334: lwc1        $f18, 0x0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X0);
    // 0x80019338: beq         $a2, $a1, L_80019384
    if (ctx->r6 == ctx->r5) {
        // 0x8001933C: addu        $v0, $t6, $a2
        ctx->r2 = ADD32(ctx->r14, ctx->r6);
            goto L_80019384;
    }
    // 0x8001933C: addu        $v0, $t6, $a2
    ctx->r2 = ADD32(ctx->r14, ctx->r6);
L_80019340:
    // 0x80019340: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80019344: lwc1        $f14, 0x4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80019348: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001934C: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80019350: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80019354: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80019358: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8001935C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80019360: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80019364: mul.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80019368: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8001936C: add.s       $f12, $f8, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80019370: swc1        $f12, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f12.u32l;
    // 0x80019374: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80019378: lwc1        $f18, 0x0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8001937C: bne         $a2, $a1, L_80019340
    if (ctx->r6 != ctx->r5) {
        // 0x80019380: addu        $v0, $t6, $a2
        ctx->r2 = ADD32(ctx->r14, ctx->r6);
            goto L_80019340;
    }
    // 0x80019380: addu        $v0, $t6, $a2
    ctx->r2 = ADD32(ctx->r14, ctx->r6);
L_80019384:
    // 0x80019384: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80019388: lwc1        $f14, 0x4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8001938C: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80019390: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80019394: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80019398: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8001939C: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800193A0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800193A4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800193A8: mul.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800193AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800193B0: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x800193B4: add.s       $f12, $f8, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800193B8: swc1        $f12, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f12.u32l;
    // 0x800193BC: jr          $ra
    // 0x800193C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800193C0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8080050C_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080050C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800514: jal         0x8009BC34
    // 0x80800518: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009BC34(rdram, ctx);
        goto after_0;
    // 0x80800518: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080051C: jal         0x8008E95C
    // 0x80800520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E95C(rdram, ctx);
        goto after_1;
    // 0x80800520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800524: jal         0x8009BD88
    // 0x80800528: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8009BD88(rdram, ctx);
        goto after_2;
    // 0x80800528: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080052C: jal         0x80800000
    // 0x80800530: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bskazglide(rdram, ctx);
        goto after_3;
    // 0x80800530: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080053C: jr          $ra
    // 0x80800540: nop

    return;
    // 0x80800540: nop

;}
RECOMP_FUNC void func_808003C0_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808003D0: jal         0x80800444
    // 0x808003D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800444_chfactorybattery(rdram, ctx);
        goto after_0;
    // 0x808003D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808003D8: bnel        $v0, $zero, L_80800434
    if (ctx->r2 != 0) {
        // 0x808003DC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800434;
    }
    goto skip_0;
    // 0x808003DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808003E0: jal         0x808004E8
    // 0x808003E4: nop

    func_808004E8_chfactorybattery(rdram, ctx);
        goto after_1;
    // 0x808003E4: nop

    after_1:
    // 0x808003E8: beql        $v0, $zero, L_80800434
    if (ctx->r2 == 0) {
        // 0x808003EC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800434;
    }
    goto skip_1;
    // 0x808003EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x808003F0: jal         0x80800580
    // 0x808003F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800580_chfactorybattery(rdram, ctx);
        goto after_2;
    // 0x808003F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808003F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003FC: jal         0x800EEAD4
    // 0x80800400: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800EEAD4(rdram, ctx);
        goto after_3;
    // 0x80800400: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800404: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800408: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080040C: nop

    // 0x80800410: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800414: nop

    // 0x80800418: bc1f        L_80800428
    if (!c1cs) {
        // 0x8080041C: nop
    
            goto L_80800428;
    }
    // 0x8080041C: nop

    // 0x80800420: b           L_80800434
    // 0x80800424: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800434;
    // 0x80800424: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800428:
    // 0x80800428: b           L_80800434
    // 0x8080042C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800434;
    // 0x8080042C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800434:
    // 0x80800434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080043C: jr          $ra
    // 0x80800440: nop

    return;
    // 0x80800440: nop

;}
RECOMP_FUNC void _suautobaddies_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FB8: syscall     820
    recomp_syscall_handler(rdram, ctx, 0x80089FB8);
    return;
    // 0x80089FBC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsfirstp_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B74: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80803B78: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x80803B7C: addiu       $s5, $sp, 0x84
    ctx->r21 = ADD32(ctx->r29, 0X84);
    // 0x80803B80: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80803B84: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x80803B88: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80803B8C: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80803B90: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80803B94: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80803B98: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80803B9C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80803BA0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80803BA4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80803BA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803BAC: lw          $s4, 0x184($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X184);
    // 0x80803BB0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80803BB4: jal         0x8009E154
    // 0x80803BB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009E154(rdram, ctx);
        goto after_0;
    // 0x80803BB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803BC0: jal         0x8009E138
    // 0x80803BC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009E138(rdram, ctx);
        goto after_1;
    // 0x80803BC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80803BC8: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x80803BCC: jal         0x800F5898
    // 0x80803BD0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_2;
    // 0x80803BD0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_2:
    // 0x80803BD4: blez        $v0, L_80803CA0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80803BD8: addiu       $s3, $sp, 0x5C
        ctx->r19 = ADD32(ctx->r29, 0X5C);
            goto L_80803CA0;
    }
    // 0x80803BD8: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
    // 0x80803BDC: addiu       $s2, $sp, 0x70
    ctx->r18 = ADD32(ctx->r29, 0X70);
L_80803BE0:
    // 0x80803BE0: beq         $s1, $s4, L_80803C8C
    if (ctx->r17 == ctx->r20) {
        // 0x80803BE4: nop
    
            goto L_80803C8C;
    }
    // 0x80803BE4: nop

    // 0x80803BE8: jal         0x800F53E4
    // 0x80803BEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F53E4(rdram, ctx);
        goto after_3;
    // 0x80803BEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80803BF0: beq         $v0, $zero, L_80803C8C
    if (ctx->r2 == 0) {
        // 0x80803BF4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80803C8C;
    }
    // 0x80803BF4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80803BF8: mul.s       $f22, $f26, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x80803BFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803C00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80803C04: jal         0x8009E154
    // 0x80803C08: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8009E154(rdram, ctx);
        goto after_4;
    // 0x80803C08: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_4:
    // 0x80803C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803C14: jal         0x8009E154
    // 0x80803C18: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8009E154(rdram, ctx);
        goto after_5;
    // 0x80803C18: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_5:
    // 0x80803C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C20: jal         0x8009E138
    // 0x80803C24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E138(rdram, ctx);
        goto after_6;
    // 0x80803C24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80803C28: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80803C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C30: jal         0x8009E138
    // 0x80803C34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E138(rdram, ctx);
        goto after_7;
    // 0x80803C34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80803C38: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80803C3C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80803C40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80803C44: jal         0x800EEB40
    // 0x80803C48: add.s       $f24, $f4, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f22.fl;
    func_800EEB40(rdram, ctx);
        goto after_8;
    // 0x80803C48: add.s       $f24, $f4, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f22.fl;
    after_8:
    // 0x80803C4C: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80803C50: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80803C54: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x80803C58: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80803C5C: nop

    // 0x80803C60: bc1tl       L_80803C80
    if (c1cs) {
        // 0x80803C64: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80803C80;
    }
    goto skip_0;
    // 0x80803C64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80803C68: jal         0x800EEB40
    // 0x80803C6C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEB40(rdram, ctx);
        goto after_9;
    // 0x80803C6C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_9:
    // 0x80803C70: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80803C74: nop

    // 0x80803C78: bc1f        L_80803C8C
    if (!c1cs) {
        // 0x80803C7C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80803C8C;
    }
    // 0x80803C7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80803C80:
    // 0x80803C80: addiu       $a1, $zero, 0x6D
    ctx->r5 = ADD32(0, 0X6D);
    // 0x80803C84: jal         0x800F7C58
    // 0x80803C88: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800F7C58(rdram, ctx);
        goto after_10;
    // 0x80803C88: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_10:
L_80803C8C:
    // 0x80803C8C: jal         0x800F5898
    // 0x80803C90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_800F5898(rdram, ctx);
        goto after_11;
    // 0x80803C90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_11:
    // 0x80803C94: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80803C98: bne         $at, $zero, L_80803BE0
    if (ctx->r1 != 0) {
        // 0x80803C9C: nop
    
            goto L_80803BE0;
    }
    // 0x80803C9C: nop

L_80803CA0:
    // 0x80803CA0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80803CA4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80803CA8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80803CAC: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80803CB0: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80803CB4: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80803CB8: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80803CBC: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80803CC0: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80803CC4: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x80803CC8: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x80803CCC: jr          $ra
    // 0x80803CD0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80803CD0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void _gcmapsects_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F60: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F60);
    return;
    // 0x80087F64: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _bsow_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083938: syscall     82
    recomp_syscall_handler(rdram, ctx, 0x80083938);
    return;
    // 0x8008393C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800AB0_chdinofamilysick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800AB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800AB8: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800ABC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AC4: beq         $a1, $at, L_80800CBC
    if (ctx->r5 == ctx->r1) {
        // 0x80800AC8: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80800CBC;
    }
    // 0x80800AC8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800ACC: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80800AD0: beq         $a1, $at, L_80800D14
    if (ctx->r5 == ctx->r1) {
        // 0x80800AD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D14;
    }
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD8: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800ADC: beq         $a1, $at, L_80800AF4
    if (ctx->r5 == ctx->r1) {
        // 0x80800AE0: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800AF4;
    }
    // 0x80800AE0: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800AE4: beq         $a1, $at, L_80800D24
    if (ctx->r5 == ctx->r1) {
        // 0x80800AE8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800D24;
    }
    // 0x80800AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800AEC: b           L_80800D44
    // 0x80800AF0: nop

        goto L_80800D44;
    // 0x80800AF0: nop

L_80800AF4:
    // 0x80800AF4: jal         0x800EA05C
    // 0x80800AF8: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800AF8: nop

    after_0:
    // 0x80800AFC: addiu       $at, $zero, 0x114
    ctx->r1 = ADD32(0, 0X114);
    // 0x80800B00: beq         $v0, $at, L_80800B20
    if (ctx->r2 == ctx->r1) {
        // 0x80800B04: addiu       $at, $zero, 0x118
        ctx->r1 = ADD32(0, 0X118);
            goto L_80800B20;
    }
    // 0x80800B04: addiu       $at, $zero, 0x118
    ctx->r1 = ADD32(0, 0X118);
    // 0x80800B08: beq         $v0, $at, L_80800B60
    if (ctx->r2 == ctx->r1) {
        // 0x80800B0C: addiu       $at, $zero, 0x121
        ctx->r1 = ADD32(0, 0X121);
            goto L_80800B60;
    }
    // 0x80800B0C: addiu       $at, $zero, 0x121
    ctx->r1 = ADD32(0, 0X121);
    // 0x80800B10: beq         $v0, $at, L_80800BEC
    if (ctx->r2 == ctx->r1) {
        // 0x80800B14: nop
    
            goto L_80800BEC;
    }
    // 0x80800B14: nop

    // 0x80800B18: b           L_80800D44
    // 0x80800B1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D44;
    // 0x80800B1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B20:
    // 0x80800B20: jal         0x80088840
    // 0x80800B24: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80800B24: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_1:
    // 0x80800B28: beq         $v0, $zero, L_80800CB4
    if (ctx->r2 == 0) {
        // 0x80800B2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CB4;
    }
    // 0x80800B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B30: jal         0x80102424
    // 0x80800B34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800B34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80800B38: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800B3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B40: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800B44: jal         0x80085708
    // 0x80800B48: addiu       $a3, $zero, 0x2831
    ctx->r7 = ADD32(0, 0X2831);
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800B48: addiu       $a3, $zero, 0x2831
    ctx->r7 = ADD32(0, 0X2831);
    after_3:
    // 0x80800B4C: lbu         $t6, 0x77($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X77);
    // 0x80800B50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800B54: andi        $t7, $t6, 0xFFF0
    ctx->r15 = ctx->r14 & 0XFFF0;
    // 0x80800B58: b           L_80800D44
    // 0x80800B5C: sb          $t7, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r15;
        goto L_80800D44;
    // 0x80800B5C: sb          $t7, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r15;
L_80800B60:
    // 0x80800B60: jal         0x80088840
    // 0x80800B64: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800B64: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_4:
    // 0x80800B68: beq         $v0, $zero, L_80800CB4
    if (ctx->r2 == 0) {
        // 0x80800B6C: nop
    
            goto L_80800CB4;
    }
    // 0x80800B6C: nop

    // 0x80800B70: jal         0x80105494
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105494(rdram, ctx);
        goto after_5;
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800B78: beq         $v0, $zero, L_80800BDC
    if (ctx->r2 == 0) {
        // 0x80800B7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BDC;
    }
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B80: jal         0x80102424
    // 0x80800B84: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800B84: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x80800B88: jal         0x800DA298
    // 0x80800B8C: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800B8C: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_7:
    // 0x80800B90: beql        $v0, $zero, L_80800BB4
    if (ctx->r2 == 0) {
        // 0x80800B94: addiu       $v0, $zero, 0x100
        ctx->r2 = ADD32(0, 0X100);
            goto L_80800BB4;
    }
    goto skip_0;
    // 0x80800B94: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    skip_0:
    // 0x80800B98: jal         0x800DA298
    // 0x80800B9C: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800B9C: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    after_8:
    // 0x80800BA0: beql        $v0, $zero, L_80800BB4
    if (ctx->r2 == 0) {
        // 0x80800BA4: addiu       $v0, $zero, 0x100
        ctx->r2 = ADD32(0, 0X100);
            goto L_80800BB4;
    }
    goto skip_1;
    // 0x80800BA4: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    skip_1:
    // 0x80800BA8: b           L_80800BB4
    // 0x80800BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BB4;
    // 0x80800BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800BB0: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_80800BB4:
    // 0x80800BB4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800BB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BBC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800BC0: jal         0x80085708
    // 0x80800BC4: ori         $a3, $v0, 0x2831
    ctx->r7 = ctx->r2 | 0X2831;
    _capod_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x80800BC4: ori         $a3, $v0, 0x2831
    ctx->r7 = ctx->r2 | 0X2831;
    after_9:
    // 0x80800BC8: lbu         $t8, 0x77($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X77);
    // 0x80800BCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800BD0: andi        $t9, $t8, 0xFFF0
    ctx->r25 = ctx->r24 & 0XFFF0;
    // 0x80800BD4: b           L_80800D44
    // 0x80800BD8: sb          $t9, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r25;
        goto L_80800D44;
    // 0x80800BD8: sb          $t9, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r25;
L_80800BDC:
    // 0x80800BDC: jal         0x800FFAB0
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800BE4: b           L_80800D44
    // 0x80800BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D44;
    // 0x80800BE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BEC:
    // 0x80800BEC: jal         0x80088840
    // 0x80800BF0: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_11;
    // 0x80800BF0: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    after_11:
    // 0x80800BF4: beq         $v0, $zero, L_80800CB4
    if (ctx->r2 == 0) {
        // 0x80800BF8: nop
    
            goto L_80800CB4;
    }
    // 0x80800BF8: nop

    // 0x80800BFC: jal         0x800C8A98
    // 0x80800C00: nop

    func_800C8A98(rdram, ctx);
        goto after_12;
    // 0x80800C00: nop

    after_12:
    // 0x80800C04: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x80800C08: jal         0x80103EAC
    // 0x80800C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_13;
    // 0x80800C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800C10: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800C14: jal         0x80103EAC
    // 0x80800C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_14;
    // 0x80800C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800C1C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800C20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800C24: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800C28: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800C2C: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x80800C30: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800C34: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800C38: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800C3C: jal         0x800C8E54
    // 0x80800C40: nop

    func_800C8E54(rdram, ctx);
        goto after_15;
    // 0x80800C40: nop

    after_15:
    // 0x80800C44: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x80800C48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C4C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80800C50: jal         0x800C8FB0
    // 0x80800C54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C8FB0(rdram, ctx);
        goto after_16;
    // 0x80800C54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_16:
    // 0x80800C58: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x80800C5C: jal         0x800C8F64
    // 0x80800C60: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C8F64(rdram, ctx);
        goto after_17;
    // 0x80800C60: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
    // 0x80800C64: jal         0x80103EAC
    // 0x80800C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_18;
    // 0x80800C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800C6C: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800C70: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800C74: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x80800C78: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800C7C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800C80: jal         0x800EEC30
    // 0x80800C84: nop

    func_800EEC30(rdram, ctx);
        goto after_19;
    // 0x80800C84: nop

    after_19:
    // 0x80800C88: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800C8C: jal         0x800EF04C
    // 0x80800C90: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_20;
    // 0x80800C90: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_20:
    // 0x80800C94: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x80800C98: jal         0x800C8CB8
    // 0x80800C9C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800C8CB8(rdram, ctx);
        goto after_21;
    // 0x80800C9C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_21:
    // 0x80800CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA4: jal         0x80102424
    // 0x80800CA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x80800CA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_22:
    // 0x80800CAC: b           L_80800D44
    // 0x80800CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D44;
    // 0x80800CB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CB4:
    // 0x80800CB4: b           L_80800D44
    // 0x80800CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D44;
    // 0x80800CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CBC:
    // 0x80800CBC: jal         0x801015D0
    // 0x80800CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_23;
    // 0x80800CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800CC4: jal         0x801022E4
    // 0x80800CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_24;
    // 0x80800CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800CCC: addiu       $at, $zero, 0x3F7
    ctx->r1 = ADD32(0, 0X3F7);
    // 0x80800CD0: bne         $v0, $at, L_80800CEC
    if (ctx->r2 != ctx->r1) {
        // 0x80800CD4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800CEC;
    }
    // 0x80800CD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800CD8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800CDC: jal         0x800DF744
    // 0x80800CE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_25;
    // 0x80800CE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x80800CE4: b           L_80800D44
    // 0x80800CE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D44;
    // 0x80800CE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CEC:
    // 0x80800CEC: jal         0x800DF744
    // 0x80800CF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_26;
    // 0x80800CF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x80800CF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800CF8: jal         0x800DF744
    // 0x80800CFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_27;
    // 0x80800CFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x80800D00: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800D04: jal         0x800DF744
    // 0x80800D08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_28;
    // 0x80800D08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_28:
    // 0x80800D0C: b           L_80800D44
    // 0x80800D10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D44;
    // 0x80800D10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D14:
    // 0x80800D14: jal         0x80102424
    // 0x80800D18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_29;
    // 0x80800D18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_29:
    // 0x80800D1C: b           L_80800D44
    // 0x80800D20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D44;
    // 0x80800D20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D24:
    // 0x80800D24: jal         0x80088098
    // 0x80800D28: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_30;
    // 0x80800D28: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_30:
    // 0x80800D2C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2408, 0XF68) << 16);
    // 0x80800D30: addiu       $a0, $a0, 0xF68
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2408, 0XF68));
    // 0x80800D34: jal         0x80088090
    // 0x80800D38: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_31;
    // 0x80800D38: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_31:
    // 0x80800D3C: b           L_80800D44
    // 0x80800D40: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800D44;
    // 0x80800D40: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800D44:
    // 0x80800D44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800D50: jr          $ra
    // 0x80800D54: nop

    return;
    // 0x80800D54: nop

;}
RECOMP_FUNC void func_800901A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800901A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800901A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800901AC: jal         0x800F54E4
    // 0x800901B0: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800901B0: nop

    after_0:
    // 0x800901B4: jal         0x800F6634
    // 0x800901B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6634(rdram, ctx);
        goto after_1;
    // 0x800901B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800901BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800901C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800901C4: jr          $ra
    // 0x800901C8: nop

    return;
    // 0x800901C8: nop

;}
RECOMP_FUNC void func_808010D8_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808010DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808010E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808010E8: jal         0x80106790
    // 0x808010EC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808010EC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808010F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808010F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808010F8: jal         0x80800FA0
    // 0x808010FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80800FA0_chhandcart(rdram, ctx);
        goto after_1;
    // 0x808010FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80801100: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801104: jal         0x80802CE8
    // 0x80801108: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80802CE8_chhandcart(rdram, ctx);
        goto after_2;
    // 0x80801108: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8080110C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801114: jr          $ra
    // 0x80801118: nop

    return;
    // 0x80801118: nop

;}
RECOMP_FUNC void func_808000C4_chmineentrygrille(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000D0: jal         0x8008A738
    // 0x808000D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _sujiggy_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x808000D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x808000D8: beq         $v0, $zero, L_808000F8
    if (ctx->r2 == 0) {
        // 0x808000DC: nop
    
            goto L_808000F8;
    }
    // 0x808000DC: nop

    // 0x808000E0: jal         0x800DA544
    // 0x808000E4: addiu       $a0, $zero, 0x393
    ctx->r4 = ADD32(0, 0X393);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x808000E4: addiu       $a0, $zero, 0x393
    ctx->r4 = ADD32(0, 0X393);
    after_1:
    // 0x808000E8: jal         0x800FFAB0
    // 0x808000EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x808000EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808000F0: b           L_80800124
    // 0x808000F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800124;
    // 0x808000F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F8:
    // 0x808000F8: jal         0x800D3E40
    // 0x808000FC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800D3E40(rdram, ctx);
        goto after_3;
    // 0x808000FC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_3:
    // 0x80800100: beql        $v0, $zero, L_80800124
    if (ctx->r2 == 0) {
        // 0x80800104: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800124;
    }
    goto skip_0;
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800108: jal         0x80088840
    // 0x8080010C: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x8080010C: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_4:
    // 0x80800110: bnel        $v0, $zero, L_80800124
    if (ctx->r2 != 0) {
        // 0x80800114: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800124;
    }
    goto skip_1;
    // 0x80800114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800118: jal         0x800FFAB0
    // 0x8080011C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x8080011C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800124:
    // 0x80800124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void _capod_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085750: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x80085750);
    return;
    // 0x80085754: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_800A4EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4ECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4ED0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A4ED4: jal         0x800A3F14
    // 0x800A4ED8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A3F14(rdram, ctx);
        goto after_0;
    // 0x800A4ED8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x800A4EDC: jal         0x800A4CA8
    // 0x800A4EE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4CA8(rdram, ctx);
        goto after_1;
    // 0x800A4EE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A4EE4: jal         0x80110C2C
    // 0x800A4EE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110C2C(rdram, ctx);
        goto after_2;
    // 0x800A4EE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800A4EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4EF4: jr          $ra
    // 0x800A4EF8: nop

    return;
    // 0x800A4EF8: nop

;}
RECOMP_FUNC void bsmum_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CC0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800CC4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(308, 0X1180) << 16);
    // 0x80800CC8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800CCC: jr          $ra
    // 0x80800CD0: lw          $v0, 0x1180($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X1180));
    return;
    // 0x80800CD0: lw          $v0, 0x1180($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X1180));
;}
RECOMP_FUNC void _gleeprom_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088508: syscall     691
    recomp_syscall_handler(rdram, ctx, 0x80088508);
    return;
    // 0x8008850C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chshockjump_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085798: syscall     174
    recomp_syscall_handler(rdram, ctx, 0x80085798);
    return;
    // 0x8008579C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801DC8_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DC8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801DCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801DD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801DD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801DD8: jal         0x80100094
    // 0x80801DDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801DDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801DE0: lh          $v1, 0x138($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X138);
    // 0x80801DE4: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80801DE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801DEC: beql        $v1, $zero, L_80801E80
    if (ctx->r3 == 0) {
        // 0x80801DF0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801E80;
    }
    goto skip_0;
    // 0x80801DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801DF4: beq         $v1, $at, L_80801E1C
    if (ctx->r3 == ctx->r1) {
        // 0x80801DF8: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_80801E1C;
    }
    // 0x80801DF8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80801DFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801E00: beq         $v1, $at, L_80801E70
    if (ctx->r3 == ctx->r1) {
        // 0x80801E04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801E70;
    }
    // 0x80801E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801E0C: beql        $v1, $at, L_80801E74
    if (ctx->r3 == ctx->r1) {
        // 0x80801E10: addiu       $a1, $t0, 0x16C
        ctx->r5 = ADD32(ctx->r8, 0X16C);
            goto L_80801E74;
    }
    goto skip_1;
    // 0x80801E10: addiu       $a1, $t0, 0x16C
    ctx->r5 = ADD32(ctx->r8, 0X16C);
    skip_1:
    // 0x80801E14: b           L_80801E80
    // 0x80801E18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801E80;
    // 0x80801E18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801E1C:
    // 0x80801E1C: jal         0x8008FE68
    // 0x80801E20: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_8008FE68(rdram, ctx);
        goto after_1;
    // 0x80801E20: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80801E24: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80801E28: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80801E2C: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80801E30: lui         $a3, 0x452F
    ctx->r7 = S32(0X452F << 16);
    // 0x80801E34: jal         0x800EEC30
    // 0x80801E38: lw          $a2, 0x160($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X160);
    func_800EEC30(rdram, ctx);
        goto after_2;
    // 0x80801E38: lw          $a2, 0x160($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X160);
    after_2:
    // 0x80801E3C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80801E40: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801E44: jal         0x800EF934
    // 0x80801E48: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    func_800EF934(rdram, ctx);
        goto after_3;
    // 0x80801E48: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    after_3:
    // 0x80801E4C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80801E50: jal         0x800EF04C
    // 0x80801E54: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x80801E54: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80801E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E5C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80801E60: jal         0x8080232C
    // 0x80801E64: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_8080232C_chdinoboss(rdram, ctx);
        goto after_5;
    // 0x80801E64: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x80801E68: b           L_80801E80
    // 0x80801E6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801E80;
    // 0x80801E6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801E70:
    // 0x80801E70: addiu       $a1, $t0, 0x16C
    ctx->r5 = ADD32(ctx->r8, 0X16C);
L_80801E74:
    // 0x80801E74: jal         0x8080232C
    // 0x80801E78: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_8080232C_chdinoboss(rdram, ctx);
        goto after_6;
    // 0x80801E78: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80801E7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801E80:
    // 0x80801E80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801E84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801E88: jr          $ra
    // 0x80801E8C: nop

    return;
    // 0x80801E8C: nop

;}
RECOMP_FUNC void _anseq_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082650: syscall     3
    recomp_syscall_handler(rdram, ctx, 0x80082650);
    return;
    // 0x80082654: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_8080009C_fxegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000A8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808000AC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808000B0: jal         0x800B5BE4
    // 0x808000B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x808000B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808000B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808000BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000C0: jal         0x800BA670
    // 0x808000C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800BA670(rdram, ctx);
        goto after_1;
    // 0x808000C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808000C8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808000CC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2834, 0X574) << 16);
    // 0x808000D0: addiu       $t6, $t6, 0x574
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2834, 0X574));
    // 0x808000D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808000DC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808000E0: jal         0x800BABB8
    // 0x808000E4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808000E4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_2:
    // 0x808000E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000F0: jr          $ra
    // 0x808000F4: nop

    return;
    // 0x808000F4: nop

;}
RECOMP_FUNC void gcnewpause_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808004C8: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x808004CC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808004D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004D4: beq         $v0, $at, L_808004F0
    if (ctx->r2 == ctx->r1) {
        // 0x808004D8: addiu       $a0, $s0, 0x30
        ctx->r4 = ADD32(ctx->r16, 0X30);
            goto L_808004F0;
    }
    // 0x808004D8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x808004DC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808004E0: beq         $v0, $at, L_80800500
    if (ctx->r2 == ctx->r1) {
        // 0x808004E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800500;
    }
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: b           L_8080050C
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080050C;
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004F0:
    // 0x808004F0: jal         0x80087CA0
    // 0x808004F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _gcnewoption_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808004F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x808004F8: b           L_8080050C
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080050C;
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800500:
    // 0x80800500: jal         0x80801DA0
    // 0x80800504: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80801DA0_gcnewpause(rdram, ctx);
        goto after_1;
    // 0x80800504: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080050C:
    // 0x8080050C: jal         0x80801410
    // 0x80800510: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80801410_gcnewpause(rdram, ctx);
        goto after_2;
    // 0x80800510: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800518: jal         0x808012CC
    // 0x8080051C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_808012CC_gcnewpause(rdram, ctx);
        goto after_3;
    // 0x8080051C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    tooie_totals_checklist_draw(rdram, ctx);
    // 0x80800520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800524: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800528: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080052C: jr          $ra
    // 0x80800530: nop

    return;
    // 0x80800530: nop

;}
RECOMP_FUNC void func_808009F8_choildrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009FC: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x80800A00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A04: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x80800A08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A10: beq         $at, $zero, L_80800B70
    if (ctx->r1 == 0) {
        // 0x80800A14: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80800B70;
    }
    // 0x80800A14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800A18: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800A1C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2412, 0X1278) << 16);
    // 0x80800A20: addu        $at, $at, $t7
    gpr jr_addend_80800A28 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800A24: lw          $t7, 0x1278($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2412, 0X1278));
    // 0x80800A28: jr          $t7
    // 0x80800A2C: nop

    switch (jr_addend_80800A28 >> 2) {
        case 0: goto L_80800A30; break;
        case 1: goto L_80800A48; break;
        case 2: goto L_80800B70; break;
        case 3: goto L_80800A60; break;
        case 4: goto L_80800A9C; break;
        case 5: goto L_80800AE0; break;
        case 6: goto L_80800B14; break;
        case 7: goto L_80800B28; break;
        case 8: goto L_80800B44; break;
        default: switch_error(__func__, 0x80800A28, 0x80801278);
    }
    // 0x80800A2C: nop

L_80800A30:
    // 0x80800A30: jal         0x80800B90
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B90_choildrill(rdram, ctx);
        goto after_0;
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800A38: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800A3C: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80800A40: b           L_80800B70
    // 0x80800A44: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_80800B70;
    // 0x80800A44: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_80800A48:
    // 0x80800A48: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800A4C: nop

    // 0x80800A50: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80800A54: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800A58: b           L_80800B70
    // 0x80800A5C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
        goto L_80800B70;
    // 0x80800A5C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
L_80800A60:
    // 0x80800A60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800A64: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A6C: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    // 0x80800A70: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    // 0x80800A74: jal         0x80085708
    // 0x80800A78: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800A78: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x80800A7C: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80800A80: jal         0x800C3F48
    // 0x80800A84: ori         $a0, $a0, 0xFD1C
    ctx->r4 = ctx->r4 | 0XFD1C;
    func_800C3F48(rdram, ctx);
        goto after_2;
    // 0x80800A84: ori         $a0, $a0, 0xFD1C
    ctx->r4 = ctx->r4 | 0XFD1C;
    after_2:
    // 0x80800A88: lhu         $t0, 0x76($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X76);
    // 0x80800A8C: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x80800A90: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x80800A94: b           L_80800B70
    // 0x80800A98: sh          $t2, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r10;
        goto L_80800B70;
    // 0x80800A98: sh          $t2, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r10;
L_80800A9C:
    // 0x80800A9C: jal         0x800FC6B0
    // 0x80800AA0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_800FC6B0(rdram, ctx);
        goto after_3;
    // 0x80800AA0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_3:
    // 0x80800AA4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800AA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800AAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2412, 0X129C) << 16);
    // 0x80800AB0: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80800AB4: lwc1        $f12, 0x129C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2412, 0X129C));
    // 0x80800AB8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800ABC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800AC0: jal         0x800DC178
    // 0x80800AC4: nop

    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800AC4: nop

    after_4:
    // 0x80800AC8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800ACC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800AD0: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80800AD4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800AD8: b           L_80800B70
    // 0x80800ADC: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800B70;
    // 0x80800ADC: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800AE0:
    // 0x80800AE0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800AE4: jal         0x800EE7F8
    // 0x80800AE8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800AE8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800AEC: jal         0x80800B90
    // 0x80800AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B90_choildrill(rdram, ctx);
        goto after_6;
    // 0x80800AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800AF4: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x80800AF8: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800AFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800B00: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x80800B04: ori         $t5, $t4, 0x40
    ctx->r13 = ctx->r12 | 0X40;
    // 0x80800B08: sb          $t5, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r13;
    // 0x80800B0C: b           L_80800B70
    // 0x80800B10: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80800B70;
    // 0x80800B10: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_80800B14:
    // 0x80800B14: jal         0x800DC0C0
    // 0x80800B18: nop

    func_800DC0C0(rdram, ctx);
        goto after_7;
    // 0x80800B18: nop

    after_7:
    // 0x80800B1C: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800B20: b           L_80800B70
    // 0x80800B24: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80800B70;
    // 0x80800B24: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80800B28:
    // 0x80800B28: jal         0x80800B90
    // 0x80800B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B90_choildrill(rdram, ctx);
        goto after_8;
    // 0x80800B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800B30: jal         0x800DC0C0
    // 0x80800B34: nop

    func_800DC0C0(rdram, ctx);
        goto after_9;
    // 0x80800B34: nop

    after_9:
    // 0x80800B38: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800B3C: b           L_80800B70
    // 0x80800B40: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
        goto L_80800B70;
    // 0x80800B40: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_80800B44:
    // 0x80800B44: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800B48: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800B4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800B50: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800B54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800B58: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B64: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    // 0x80800B68: jal         0x808007DC
    // 0x80800B6C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_808007DC_choildrill(rdram, ctx);
        goto after_10;
    // 0x80800B6C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_10:
L_80800B70:
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B74: jal         0x80102424
    // 0x80800B78: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800B78: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x80800B7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B88: jr          $ra
    // 0x80800B8C: nop

    return;
    // 0x80800B8C: nop

;}
RECOMP_FUNC void func_80800F08_choildrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F08: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800F0C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800F10: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800F14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F18: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800F1C: jal         0x80101870
    // 0x80800F20: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800F20: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800F24: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800F28: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800F2C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800F30: bnel        $t7, $at, L_808010A4
    if (ctx->r15 != ctx->r1) {
        // 0x80800F34: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808010A4;
    }
    goto skip_0;
    // 0x80800F34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800F38: jal         0x800D674C
    // 0x80800F3C: addiu       $a0, $zero, 0x610
    ctx->r4 = ADD32(0, 0X610);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80800F3C: addiu       $a0, $zero, 0x610
    ctx->r4 = ADD32(0, 0X610);
    after_1:
    // 0x80800F40: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800F44: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800F48: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800F4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800F50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F54: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80800F58: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800F5C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800F60: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800F64: jal         0x800F10B4
    // 0x80800F68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800F68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800F6C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2412, 0X1490) << 16);
    // 0x80800F70: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2412, 0X149C) << 16);
    // 0x80800F74: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800F78: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80800F7C: addiu       $a2, $a2, 0x149C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2412, 0X149C));
    // 0x80800F80: addiu       $a1, $a1, 0x1490
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2412, 0X1490));
    // 0x80800F84: jal         0x800EFE50
    // 0x80800F88: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_800EFE50(rdram, ctx);
        goto after_3;
    // 0x80800F88: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_3:
    // 0x80800F8C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800F90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800F94: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800F98: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x80800F9C: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800FA0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800FA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800FA8: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x80800FAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800FB0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800FB4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800FB8: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x80800FBC: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800FC0: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800FC4: jal         0x800F10B4
    // 0x80800FC8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800FC8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80800FCC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800FD0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800FD4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800FD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800FDC: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80800FE0: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800FE4: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80800FE8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800FEC: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    // 0x80800FF0: jal         0x800F10B4
    // 0x80800FF4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800FF4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80800FF8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800FFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801000: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80801004: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80801008: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080100C: jal         0x80013970
    // 0x80801010: nop

    func_80013970(rdram, ctx);
        goto after_6;
    // 0x80801010: nop

    after_6:
    // 0x80801014: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801018: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8080101C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80801020: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801024: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801028: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8080102C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80801030: jal         0x800DC178
    // 0x80801034: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80801034: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80801038: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8080103C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801040: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80801044: jal         0x800DC178
    // 0x80801048: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80801048: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_8:
    // 0x8080104C: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x80801050: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801058: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080105C: jal         0x800EEC30
    // 0x80801060: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_800EEC30(rdram, ctx);
        goto after_9;
    // 0x80801060: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_9:
    // 0x80801064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801068: jal         0x800EF04C
    // 0x8080106C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x8080106C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_10:
    // 0x80801070: jal         0x80088AA8
    // 0x80801074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _fxtwinkle_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80801074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801078: jal         0x800DF830
    // 0x8080107C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_12;
    // 0x8080107C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x80801080: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80801084: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80801088: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8080108C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80801090: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801094: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801098: jal         0x800DE498
    // 0x8080109C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_800DE498(rdram, ctx);
        goto after_13;
    // 0x8080109C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_13:
    // 0x808010A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808010A4:
    // 0x808010A4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808010A8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808010AC: jr          $ra
    // 0x808010B0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x808010B0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80801558_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801558: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080155C: slti        $at, $a1, 0x13FB
    ctx->r1 = SIGNED(ctx->r5) < 0X13FB ? 1 : 0;
    // 0x80801560: bne         $at, $zero, L_8080158C
    if (ctx->r1 != 0) {
        // 0x80801564: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8080158C;
    }
    // 0x80801564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801568: addiu       $t6, $a1, -0x1443
    ctx->r14 = ADD32(ctx->r5, -0X1443);
    // 0x8080156C: sltiu       $at, $t6, 0xF
    ctx->r1 = ctx->r14 < 0XF ? 1 : 0;
    // 0x80801570: beq         $at, $zero, L_808016A0
    if (ctx->r1 == 0) {
        // 0x80801574: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808016A0;
    }
    // 0x80801574: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801578: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2F24) << 16);
    // 0x8080157C: addu        $at, $at, $t6
    gpr jr_addend_80801584 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801580: lw          $t6, 0x2F24($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2F24));
    // 0x80801584: jr          $t6
    // 0x80801588: nop

    switch (jr_addend_80801584 >> 2) {
        case 0: goto L_80801648; break;
        case 1: goto L_80801650; break;
        case 2: goto L_80801670; break;
        case 3: goto L_80801670; break;
        case 4: goto L_80801670; break;
        case 5: goto L_808016A0; break;
        case 6: goto L_808016A0; break;
        case 7: goto L_808016A0; break;
        case 8: goto L_808016A0; break;
        case 9: goto L_808016A0; break;
        case 10: goto L_808016A0; break;
        case 11: goto L_808016A0; break;
        case 12: goto L_808016A0; break;
        case 13: goto L_808016A0; break;
        case 14: goto L_80801698; break;
        default: switch_error(__func__, 0x80801584, 0x80802F24);
    }
    // 0x80801588: nop

L_8080158C:
    // 0x8080158C: addiu       $t7, $a1, -0x13EF
    ctx->r15 = ADD32(ctx->r5, -0X13EF);
    // 0x80801590: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x80801594: beq         $at, $zero, L_808016A0
    if (ctx->r1 == 0) {
        // 0x80801598: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808016A0;
    }
    // 0x80801598: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080159C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2F60) << 16);
    // 0x808015A0: addu        $at, $at, $t7
    gpr jr_addend_808015A8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808015A4: lw          $t7, 0x2F60($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2F60));
    // 0x808015A8: jr          $t7
    // 0x808015AC: nop

    switch (jr_addend_808015A8 >> 2) {
        case 0: goto L_808015B0; break;
        case 1: goto L_808015B8; break;
        case 2: goto L_808015B0; break;
        case 3: goto L_808015B0; break;
        case 4: goto L_808016A0; break;
        case 5: goto L_808015C8; break;
        case 6: goto L_808015E0; break;
        case 7: goto L_80801638; break;
        case 8: goto L_80801638; break;
        case 9: goto L_80801600; break;
        case 10: goto L_80801638; break;
        case 11: goto L_80801628; break;
        default: switch_error(__func__, 0x808015A8, 0x80802F60);
    }
    // 0x808015AC: nop

L_808015B0:
    // 0x808015B0: b           L_808016A4
    // 0x808015B4: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
        goto L_808016A4;
    // 0x808015B4: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_808015B8:
    // 0x808015B8: jal         0x800D211C
    // 0x808015BC: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800D211C(rdram, ctx);
        goto after_0;
    // 0x808015BC: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_0:
    // 0x808015C0: b           L_808016A8
    // 0x808015C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808016A8;
    // 0x808015C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808015C8:
    // 0x808015C8: beq         $a2, $zero, L_808015D8
    if (ctx->r6 == 0) {
        // 0x808015CC: nop
    
            goto L_808015D8;
    }
    // 0x808015CC: nop

    // 0x808015D0: b           L_808016A4
    // 0x808015D4: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
        goto L_808016A4;
    // 0x808015D4: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_808015D8:
    // 0x808015D8: b           L_808016A4
    // 0x808015DC: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
        goto L_808016A4;
    // 0x808015DC: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_808015E0:
    // 0x808015E0: beq         $a2, $zero, L_808015F8
    if (ctx->r6 == 0) {
        // 0x808015E4: nop
    
            goto L_808015F8;
    }
    // 0x808015E4: nop

    // 0x808015E8: jal         0x800D211C
    // 0x808015EC: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800D211C(rdram, ctx);
        goto after_1;
    // 0x808015EC: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_1:
    // 0x808015F0: b           L_808016A8
    // 0x808015F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808016A8;
    // 0x808015F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808015F8:
    // 0x808015F8: b           L_808016A4
    // 0x808015FC: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
        goto L_808016A4;
    // 0x808015FC: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_80801600:
    // 0x80801600: beq         $a2, $zero, L_80801618
    if (ctx->r6 == 0) {
        // 0x80801604: nop
    
            goto L_80801618;
    }
    // 0x80801604: nop

    // 0x80801608: jal         0x800D211C
    // 0x8080160C: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800D211C(rdram, ctx);
        goto after_2;
    // 0x8080160C: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_2:
    // 0x80801610: b           L_808016A8
    // 0x80801614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808016A8;
    // 0x80801614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801618:
    // 0x80801618: jal         0x80800014
    // 0x8080161C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_3;
    // 0x8080161C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801620: b           L_808016A8
    // 0x80801624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808016A8;
    // 0x80801624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801628:
    // 0x80801628: jal         0x80800014
    // 0x8080162C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_4;
    // 0x8080162C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80801630: b           L_808016A8
    // 0x80801634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808016A8;
    // 0x80801634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801638:
    // 0x80801638: jal         0x80800014
    // 0x8080163C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_5;
    // 0x8080163C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80801640: b           L_808016A8
    // 0x80801644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808016A8;
    // 0x80801644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801648:
    // 0x80801648: b           L_808016A4
    // 0x8080164C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
        goto L_808016A4;
    // 0x8080164C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_80801650:
    // 0x80801650: beq         $a2, $zero, L_80801668
    if (ctx->r6 == 0) {
        // 0x80801654: nop
    
            goto L_80801668;
    }
    // 0x80801654: nop

    // 0x80801658: jal         0x800D211C
    // 0x8080165C: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800D211C(rdram, ctx);
        goto after_6;
    // 0x8080165C: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_6:
    // 0x80801660: b           L_808016A8
    // 0x80801664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808016A8;
    // 0x80801664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801668:
    // 0x80801668: b           L_808016A4
    // 0x8080166C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
        goto L_808016A4;
    // 0x8080166C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_80801670:
    // 0x80801670: beq         $a2, $zero, L_80801688
    if (ctx->r6 == 0) {
        // 0x80801674: nop
    
            goto L_80801688;
    }
    // 0x80801674: nop

    // 0x80801678: jal         0x800D211C
    // 0x8080167C: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800D211C(rdram, ctx);
        goto after_7;
    // 0x8080167C: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_7:
    // 0x80801680: b           L_808016A8
    // 0x80801684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808016A8;
    // 0x80801684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801688:
    // 0x80801688: jal         0x80800014
    // 0x8080168C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_8;
    // 0x8080168C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80801690: b           L_808016A8
    // 0x80801694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808016A8;
    // 0x80801694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801698:
    // 0x80801698: b           L_808016A4
    // 0x8080169C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
        goto L_808016A4;
    // 0x8080169C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_808016A0:
    // 0x808016A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808016A4:
    // 0x808016A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808016A8:
    // 0x808016A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808016AC: jr          $ra
    // 0x808016B0: nop

    return;
    // 0x808016B0: nop

;}
RECOMP_FUNC void func_808012A4_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808012A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808012B0: jal         0x800845C8
    // 0x808012B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _babounce_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808012B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808012B8: beq         $v0, $zero, L_808012C8
    if (ctx->r2 == 0) {
        // 0x808012BC: nop
    
            goto L_808012C8;
    }
    // 0x808012BC: nop

    // 0x808012C0: jal         0x80800000
    // 0x808012C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800000_bsvan(rdram, ctx);
        goto after_1;
    // 0x808012C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
L_808012C8:
    // 0x808012C8: jal         0x80084600
    // 0x808012CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _babounce_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808012CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808012D0: beq         $v0, $zero, L_808012DC
    if (ctx->r2 == 0) {
        // 0x808012D4: addiu       $t6, $zero, 0x11A
        ctx->r14 = ADD32(0, 0X11A);
            goto L_808012DC;
    }
    // 0x808012D4: addiu       $t6, $zero, 0x11A
    ctx->r14 = ADD32(0, 0X11A);
    // 0x808012D8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_808012DC:
    // 0x808012DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808012E0: jal         0x8009E5C8
    // 0x808012E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x808012E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808012E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808012F0: jr          $ra
    // 0x808012F4: nop

    return;
    // 0x808012F4: nop

;}
RECOMP_FUNC void func_80807FBC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807FBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80807FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80807FC4: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80807FC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80807FCC: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    // 0x80807FD0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80807FD4: jal         0x80808100
    // 0x80807FD8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80808100_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80807FD8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80807FDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80807FE0: jal         0x808080A4
    // 0x80807FE4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_808080A4_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80807FE4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_1:
    // 0x80807FE8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80807FEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80807FF0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80807FF4: jal         0x808080B4
    // 0x80807FF8: lbu         $a2, 0x72($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X72);
    func_808080B4_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80807FF8: lbu         $a2, 0x72($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X72);
    after_2:
    // 0x80807FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80808000: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80808004: jr          $ra
    // 0x80808008: nop

    return;
    // 0x80808008: nop

;}
RECOMP_FUNC void func_8080079C_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080079C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808007A4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808007A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808007AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007B0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x808007B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808007B8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x808007BC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x808007C0: jal         0x8080084C
    // 0x808007C4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_8080084C_chboilerid(rdram, ctx);
        goto after_0;
    // 0x808007C4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x808007C8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808007CC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808007D0: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x808007D4: lh          $t6, 0x58($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X58);
    // 0x808007D8: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x808007DC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808007E0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x808007E4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x808007E8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808007EC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808007F0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808007F4: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x808007F8: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808007FC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80800800: nop

    // 0x80800804: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x80800808: lh          $t0, 0x58($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X58);
    // 0x8080080C: lh          $t1, 0xA($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XA);
    // 0x80800810: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800814: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80800818: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8080081C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800820: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800824: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800828: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8080082C: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800830: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80800834: nop

    // 0x80800838: sh          $t3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r11;
    // 0x8080083C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800844: jr          $ra
    // 0x80800848: nop

    return;
    // 0x80800848: nop

;}
RECOMP_FUNC void func_80016068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016068: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001606C: addiu       $t7, $t7, -0x6508
    ctx->r15 = ADD32(ctx->r15, -0X6508);
    // 0x80016070: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80016074: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80016078: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8001607C: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80016080: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80016084: jr          $ra
    // 0x80016088: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    return;
    // 0x80016088: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80800018_chpumproomswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080001C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800020: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800028: jal         0x800DA298
    // 0x8080002C: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080002C: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    after_0:
    // 0x80800030: beq         $v0, $zero, L_80800048
    if (ctx->r2 == 0) {
        // 0x80800034: nop
    
            goto L_80800048;
    }
    // 0x80800034: nop

    // 0x80800038: jal         0x8080016C
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080016C_chpumproomswitch(rdram, ctx);
        goto after_1;
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800040: jal         0x800DA544
    // 0x80800044: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800044: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
L_80800048:
    // 0x80800048: jal         0x8080016C
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080016C_chpumproomswitch(rdram, ctx);
        goto after_3;
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: jal         0x80085808
    // 0x80800058: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800058: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8080005C: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800060: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800064: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x80800068: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080006C: bne         $t7, $at, L_8080007C
    if (ctx->r15 != ctx->r1) {
        // 0x80800070: nop
    
            goto L_8080007C;
    }
    // 0x80800070: nop

    // 0x80800074: b           L_8080007C
    // 0x80800078: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
        goto L_8080007C;
    // 0x80800078: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
L_8080007C:
    // 0x8080007C: jal         0x80085810
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800084: jal         0x800DA298
    // 0x80800088: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800088: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    after_6:
    // 0x8080008C: beql        $v0, $zero, L_808000AC
    if (ctx->r2 == 0) {
        // 0x80800090: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000AC;
    }
    goto skip_0;
    // 0x80800090: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800094: jal         0x80085818
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: jal         0x80103110
    // 0x808000A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_8;
    // 0x808000A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000AC:
    // 0x808000AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void func_80800B80_chnutsnbolts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B88: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800B8C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1304, 0XCC0) << 16);
    // 0x80800B90: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1304, 0XF3C) << 16);
    // 0x80800B94: addiu       $a3, $a3, 0xF3C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1304, 0XF3C));
    // 0x80800B98: addiu       $a2, $a2, 0xCC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1304, 0XCC0));
    // 0x80800B9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800BA0: jal         0x80089D28
    // 0x80800BA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800BA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BA8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1304, 0XF2C) << 16);
    // 0x80800BAC: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80800BB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800BB4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BB8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800BBC: jal         0x80089D20
    // 0x80800BC0: addiu       $a2, $a2, 0xF2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1304, 0XF2C));
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800BC0: addiu       $a2, $a2, 0xF2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1304, 0XF2C));
    after_1:
    // 0x80800BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BCC: jr          $ra
    // 0x80800BD0: nop

    return;
    // 0x80800BD0: nop

;}
RECOMP_FUNC void func_8010E81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E81C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010E820: addiu       $t0, $t0, 0x7080
    ctx->r8 = ADD32(ctx->r8, 0X7080);
    // 0x8010E824: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x8010E828: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010E82C: addiu       $v1, $v0, 0x709C
    ctx->r3 = ADD32(ctx->r2, 0X709C);
    // 0x8010E830: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8010E834: beq         $at, $zero, L_8010E860
    if (ctx->r1 == 0) {
        // 0x8010E838: addiu       $t1, $zero, 0x28
        ctx->r9 = ADD32(0, 0X28);
            goto L_8010E860;
    }
    // 0x8010E838: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x8010E83C: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
L_8010E840:
    // 0x8010E840: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8010E844: nop

    // 0x8010E848: bc1t        L_8010E860
    if (c1cs) {
        // 0x8010E84C: nop
    
            goto L_8010E860;
    }
    // 0x8010E84C: nop

    // 0x8010E850: addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
    // 0x8010E854: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8010E858: bnel        $at, $zero, L_8010E840
    if (ctx->r1 != 0) {
        // 0x8010E85C: lwc1        $f4, 0x24($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
            goto L_8010E840;
    }
    goto skip_0;
    // 0x8010E85C: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
    skip_0:
L_8010E860:
    // 0x8010E860: bnel        $v1, $a0, L_8010E894
    if (ctx->r3 != ctx->r4) {
        // 0x8010E864: lw          $t8, 0x18($t0)
        ctx->r24 = MEM_W(ctx->r8, 0X18);
            goto L_8010E894;
    }
    goto skip_1;
    // 0x8010E864: lw          $t8, 0x18($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X18);
    skip_1:
    // 0x8010E868: lw          $t6, 0x18($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X18);
    // 0x8010E86C: addiu       $t7, $a0, 0x28
    ctx->r15 = ADD32(ctx->r4, 0X28);
    // 0x8010E870: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8010E874: sltu        $at, $a0, $t6
    ctx->r1 = ctx->r4 < ctx->r14 ? 1 : 0;
    // 0x8010E878: beq         $at, $zero, L_8010E888
    if (ctx->r1 == 0) {
        // 0x8010E87C: nop
    
            goto L_8010E888;
    }
    // 0x8010E87C: nop

    // 0x8010E880: jr          $ra
    // 0x8010E884: sw          $t7, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r15;
    return;
    // 0x8010E884: sw          $t7, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r15;
L_8010E888:
    // 0x8010E888: jr          $ra
    // 0x8010E88C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8010E88C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010E890: lw          $t8, 0x18($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X18);
L_8010E894:
    // 0x8010E894: bnel        $t8, $a0, L_8010E8AC
    if (ctx->r24 != ctx->r4) {
        // 0x8010E898: subu        $t2, $a0, $v1
        ctx->r10 = SUB32(ctx->r4, ctx->r3);
            goto L_8010E8AC;
    }
    goto skip_2;
    // 0x8010E898: subu        $t2, $a0, $v1
    ctx->r10 = SUB32(ctx->r4, ctx->r3);
    skip_2:
    // 0x8010E89C: addiu       $t9, $a0, -0x28
    ctx->r25 = ADD32(ctx->r4, -0X28);
    // 0x8010E8A0: sw          $t9, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r25;
    // 0x8010E8A4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8010E8A8: subu        $t2, $a0, $v1
    ctx->r10 = SUB32(ctx->r4, ctx->r3);
L_8010E8AC:
    // 0x8010E8AC: div         $zero, $t2, $t1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r9)));
    // 0x8010E8B0: mflo        $t3
    ctx->r11 = lo;
    // 0x8010E8B4: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    // 0x8010E8B8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8010E8BC: multu       $t3, $t1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010E8C0: bne         $t1, $zero, L_8010E8CC
    if (ctx->r9 != 0) {
        // 0x8010E8C4: nop
    
            goto L_8010E8CC;
    }
    // 0x8010E8C4: nop

    // 0x8010E8C8: break       7
    do_break(2148591816);
L_8010E8CC:
    // 0x8010E8CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010E8D0: bne         $t1, $at, L_8010E8E4
    if (ctx->r9 != ctx->r1) {
        // 0x8010E8D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8010E8E4;
    }
    // 0x8010E8D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8010E8D8: bne         $t2, $at, L_8010E8E4
    if (ctx->r10 != ctx->r1) {
        // 0x8010E8DC: nop
    
            goto L_8010E8E4;
    }
    // 0x8010E8DC: nop

    // 0x8010E8E0: break       6
    do_break(2148591840);
L_8010E8E4:
    // 0x8010E8E4: mflo        $a2
    ctx->r6 = lo;
    // 0x8010E8E8: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8010E8EC: blez        $a2, L_8010E914
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8010E8F0: addiu       $a3, $a0, -0x4
        ctx->r7 = ADD32(ctx->r4, -0X4);
            goto L_8010E914;
    }
    // 0x8010E8F0: addiu       $a3, $a0, -0x4
    ctx->r7 = ADD32(ctx->r4, -0X4);
L_8010E8F4:
    // 0x8010E8F4: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x8010E8F8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8010E8FC: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8010E900: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x8010E904: bgtz        $a2, L_8010E8F4
    if (SIGNED(ctx->r6) > 0) {
        // 0x8010E908: sw          $t4, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r12;
            goto L_8010E8F4;
    }
    // 0x8010E908: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8010E90C: lw          $a1, 0x14($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X14);
    // 0x8010E910: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
L_8010E914:
    // 0x8010E914: sw          $a1, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r5;
    // 0x8010E918: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8010E91C: jr          $ra
    // 0x8010E920: nop

    return;
    // 0x8010E920: nop

;}
RECOMP_FUNC void func_80801464_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801464: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801468: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080146C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801470: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801474: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801478: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8080147C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801480: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801484: beq         $v0, $zero, L_808014A8
    if (ctx->r2 == 0) {
        // 0x80801488: addiu       $a1, $zero, 0x13
        ctx->r5 = ADD32(0, 0X13);
            goto L_808014A8;
    }
    // 0x80801488: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x8080148C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801490: beq         $v0, $at, L_808014B0
    if (ctx->r2 == ctx->r1) {
        // 0x80801494: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808014B0;
    }
    // 0x80801494: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801498: beql        $v0, $at, L_808014EC
    if (ctx->r2 == ctx->r1) {
        // 0x8080149C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808014EC;
    }
    goto skip_0;
    // 0x8080149C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808014A0: b           L_808014F8
    // 0x808014A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F8;
    // 0x808014A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808014A8:
    // 0x808014A8: jal         0x800856B0
    // 0x808014AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808014AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
L_808014B0:
    // 0x808014B0: jal         0x800856E0
    // 0x808014B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808014B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x808014B8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808014BC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1096, 0X18D8) << 16);
    // 0x808014C0: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x808014C4: addiu       $a0, $a0, 0x18D8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1096, 0X18D8));
    // 0x808014C8: jal         0x80088090
    // 0x808014CC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808014CC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x808014D0: jal         0x80088098
    // 0x808014D4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808014D4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808014D8: jal         0x800880A0
    // 0x808014DC: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x808014DC: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_4:
    // 0x808014E0: jal         0x800880B8
    // 0x808014E4: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x808014E4: nop

    after_5:
    // 0x808014E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_808014EC:
    // 0x808014EC: jal         0x800856D8
    // 0x808014F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x808014F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x808014F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808014F8:
    // 0x808014F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808014FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801500: jr          $ra
    // 0x80801504: nop

    return;
    // 0x80801504: nop

;}
RECOMP_FUNC void ncpod_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808000EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000F4: jal         0x8001B668
    // 0x808000F8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    func_8001B668(rdram, ctx);
        goto after_0;
    // 0x808000F8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_0:
    // 0x808000FC: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80800100: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80800104: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x80800108: jal         0x808002B0
    // 0x8080010C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    ncpod_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080010C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x80800110: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800114: jal         0x800A940C
    // 0x80800118: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800A940C(rdram, ctx);
        goto after_2;
    // 0x80800118: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8080011C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800120: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800124: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80800128: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8080012C: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80800130: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x80800134: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x80800138: jal         0x800EFD24
    // 0x8080013C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x8080013C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_3:
    // 0x80800140: jal         0x800EFD24
    // 0x80800144: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    func_800EFD24(rdram, ctx);
        goto after_4;
    // 0x80800144: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    after_4:
    // 0x80800148: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080014C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800150: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800154: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800158: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x8080015C: jal         0x80015184
    // 0x80800160: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    func_80015184(rdram, ctx);
        goto after_5;
    // 0x80800160: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x80800164: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80800168: sb          $zero, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = 0;
    // 0x8080016C: sb          $zero, 0x42($s0)
    MEM_B(0X42, ctx->r16) = 0;
    // 0x80800170: sb          $zero, 0x40($s0)
    MEM_B(0X40, ctx->r16) = 0;
    // 0x80800174: sb          $zero, 0x43($s0)
    MEM_B(0X43, ctx->r16) = 0;
    // 0x80800178: sh          $zero, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = 0;
    // 0x8080017C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800180: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x80800184: sb          $zero, 0x41($s0)
    MEM_B(0X41, ctx->r16) = 0;
    // 0x80800188: sw          $t8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r24;
    // 0x8080018C: jal         0x800C517C
    // 0x80800190: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800C517C(rdram, ctx);
        goto after_6;
    // 0x80800190: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80800194: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80800198: jal         0x800C5190
    // 0x8080019C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800C5190(rdram, ctx);
        goto after_7;
    // 0x8080019C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x808001A0: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x808001A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001AC: lh          $v0, 0x2E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X2E);
    // 0x808001B0: jr          $ra
    // 0x808001B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808001B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800C77DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C77DC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800C77E0: addiu       $v1, $v1, 0x760C
    ctx->r3 = ADD32(ctx->r3, 0X760C);
    // 0x800C77E4: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x800C77E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C77EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C77F0: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x800C77F4: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x800C77F8: beq         $at, $zero, L_800C7840
    if (ctx->r1 == 0) {
        // 0x800C77FC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800C7840;
    }
    // 0x800C77FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C7800: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C7804: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7808: addu        $at, $at, $t6
    gpr jr_addend_800C7810 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C780C: lw          $t6, 0x58E0($at)
    ctx->r14 = ADD32(ctx->r1, 0X58E0);
    // 0x800C7810: jr          $t6
    // 0x800C7814: nop

    switch (jr_addend_800C7810 >> 2) {
        case 0: goto L_800C7840; break;
        case 1: goto L_800C7818; break;
        case 2: goto L_800C7818; break;
        case 3: goto L_800C7818; break;
        case 4: goto L_800C7818; break;
        case 5: goto L_800C7818; break;
        case 6: goto L_800C7818; break;
        case 7: goto L_800C7818; break;
        default: switch_error(__func__, 0x800C7810, 0x801258E0);
    }
    // 0x800C7814: nop

L_800C7818:
    // 0x800C7818: jal         0x800C75A0
    // 0x800C781C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800C75A0(rdram, ctx);
        goto after_0;
    // 0x800C781C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800C7820: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C7824: jal         0x800C7618
    // 0x800C7828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C7618(rdram, ctx);
        goto after_1;
    // 0x800C7828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800C782C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800C7830: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800C7834: addiu       $v1, $v1, 0x760C
    ctx->r3 = ADD32(ctx->r3, 0X760C);
    // 0x800C7838: b           L_800C7864
    // 0x800C783C: lb          $v0, 0x760D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X760D);
        goto L_800C7864;
    // 0x800C783C: lb          $v0, 0x760D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X760D);
L_800C7840:
    // 0x800C7840: lb          $v0, 0x1($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X1);
    // 0x800C7844: bnel        $v0, $zero, L_800C7868
    if (ctx->r2 != 0) {
        // 0x800C7848: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_800C7868;
    }
    goto skip_0;
    // 0x800C7848: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x800C784C: jal         0x800FEC60
    // 0x800C7850: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800FEC60(rdram, ctx);
        goto after_2;
    // 0x800C7850: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
    // 0x800C7854: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800C7858: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800C785C: addiu       $v1, $v1, 0x760C
    ctx->r3 = ADD32(ctx->r3, 0X760C);
    // 0x800C7860: lb          $v0, 0x760D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X760D);
L_800C7864:
    // 0x800C7864: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
L_800C7868:
    // 0x800C7868: bne         $v0, $zero, L_800C78BC
    if (ctx->r2 != 0) {
        // 0x800C786C: sb          $t7, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r15;
            goto L_800C78BC;
    }
    // 0x800C786C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x800C7870: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
    // 0x800C7874: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x800C7878: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x800C787C: beq         $at, $zero, L_800C78B4
    if (ctx->r1 == 0) {
        // 0x800C7880: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800C78B4;
    }
    // 0x800C7880: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800C7884: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C7888: addu        $at, $at, $t8
    gpr jr_addend_800C7890 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800C788C: lw          $t8, 0x5900($at)
    ctx->r24 = ADD32(ctx->r1, 0X5900);
    // 0x800C7890: jr          $t8
    // 0x800C7894: nop

    switch (jr_addend_800C7890 >> 2) {
        case 0: goto L_800C78B4; break;
        case 1: goto L_800C7898; break;
        case 2: goto L_800C7898; break;
        case 3: goto L_800C7898; break;
        case 4: goto L_800C7898; break;
        case 5: goto L_800C7898; break;
        case 6: goto L_800C7898; break;
        case 7: goto L_800C7898; break;
        default: switch_error(__func__, 0x800C7890, 0x80125900);
    }
    // 0x800C7894: nop

L_800C7898:
    // 0x800C7898: jal         0x800C75A0
    // 0x800C789C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800C75A0(rdram, ctx);
        goto after_3;
    // 0x800C789C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x800C78A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C78A4: jal         0x800C7618
    // 0x800C78A8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800C7618(rdram, ctx);
        goto after_4;
    // 0x800C78A8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_4:
    // 0x800C78AC: b           L_800C78C0
    // 0x800C78B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C78C0;
    // 0x800C78B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C78B4:
    // 0x800C78B4: jal         0x800FECB8
    // 0x800C78B8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800FECB8(rdram, ctx);
        goto after_5;
    // 0x800C78B8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_5:
L_800C78BC:
    // 0x800C78BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C78C0:
    // 0x800C78C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C78C4: jr          $ra
    // 0x800C78C8: nop

    return;
    // 0x800C78C8: nop

;}
