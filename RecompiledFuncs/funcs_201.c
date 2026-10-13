#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _gczoombox_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B80: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B80);
    return;
    // 0x80087B84: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_8009DF58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DF58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009DF5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DF60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8009DF64: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009DF68: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009DF6C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8009DF70: addiu       $t7, $zero, 0x55F0
    ctx->r15 = ADD32(0, 0X55F0);
    // 0x8009DF74: lbu         $a1, 0x3($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X3);
    // 0x8009DF78: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8009DF7C: jal         0x8009DCCC
    // 0x8009DF80: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8009DCCC(rdram, ctx);
        goto after_0;
    // 0x8009DF80: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8009DF84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DF88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009DF8C: jr          $ra
    // 0x8009DF90: nop

    return;
    // 0x8009DF90: nop

;}
RECOMP_FUNC void func_800EA390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA390: jr          $ra
    // 0x800EA394: nop

    return;
    // 0x800EA394: nop

;}
RECOMP_FUNC void func_808002BC_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002C4: jal         0x8010CD28
    // 0x808002C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010CD28(rdram, ctx);
        goto after_0;
    // 0x808002C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002D0: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808002D4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808002D8: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x808002DC: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    // 0x808002E0: jal         0x80102BF8
    // 0x808002E4: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_80102BF8(rdram, ctx);
        goto after_1;
    // 0x808002E4: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_1:
    // 0x808002E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002F0: jr          $ra
    // 0x808002F4: nop

    return;
    // 0x808002F4: nop

;}
RECOMP_FUNC void func_808001D4_chdoubloon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001DC: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x808001E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001E4: beq         $a1, $at, L_8080024C
    if (ctx->r5 == ctx->r1) {
        // 0x808001E8: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8080024C;
    }
    // 0x808001E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001EC: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x808001F0: bne         $a1, $at, L_80800254
    if (ctx->r5 != ctx->r1) {
        // 0x808001F4: addiu       $a0, $zero, 0x165
        ctx->r4 = ADD32(0, 0X165);
            goto L_80800254;
    }
    // 0x808001F4: addiu       $a0, $zero, 0x165
    ctx->r4 = ADD32(0, 0X165);
    // 0x808001F8: jal         0x8008A298
    // 0x808001FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _sudialog_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808001FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80800200: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x80800204: jal         0x800D0BD4
    // 0x80800208: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_800D0BD4(rdram, ctx);
        goto after_1;
    // 0x80800208: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x8080020C: jal         0x800D1844
    // 0x80800210: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    func_800D1844(rdram, ctx);
        goto after_2;
    // 0x80800210: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_2:
    // 0x80800214: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800218: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2256, 0X290) << 16);
    // 0x8080021C: addiu       $a2, $a2, 0x290
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2256, 0X290));
    // 0x80800220: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800224: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80800228: jal         0x80089D18
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800230: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800234: jal         0x800888C8
    // 0x80800238: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800238: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_4:
    // 0x8080023C: jal         0x800FFAB0
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800244: b           L_80800260
    // 0x80800248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800260;
    // 0x80800248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080024C:
    // 0x8080024C: b           L_8080025C
    // 0x80800250: sw          $a2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r6;
        goto L_8080025C;
    // 0x80800250: sw          $a2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r6;
L_80800254:
    // 0x80800254: b           L_80800260
    // 0x80800258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800260;
    // 0x80800258: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080025C:
    // 0x8080025C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800260:
    // 0x80800260: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800268: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
RECOMP_FUNC void func_800BCFC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCFC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BCFC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BCFCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BCFD0: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x800BCFD4: lbu         $a1, 0x8($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X8);
    // 0x800BCFD8: jal         0x800BCCC0
    // 0x800BCFDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    static_16_800BCCC0(rdram, ctx);
        goto after_0;
    // 0x800BCFDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800BCFE0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCFE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800BCFE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BCFEC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800BCFF0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800BCFF4: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800BCFF8: addu        $t3, $a1, $t8
    ctx->r11 = ADD32(ctx->r5, ctx->r24);
    // 0x800BCFFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BD000: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800BD004: sltiu       $v0, $t0, 0x1
    ctx->r2 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x800BD008: beq         $v0, $zero, L_800BD028
    if (ctx->r2 == 0) {
        // 0x800BD00C: nop
    
            goto L_800BD028;
    }
    // 0x800BD00C: nop

    // 0x800BD010: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800BD014: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800BD018: srl         $t5, $t4, 1
    ctx->r13 = S32(U32(ctx->r12) >> 1);
    // 0x800BD01C: subu        $v0, $t2, $t5
    ctx->r2 = SUB32(ctx->r10, ctx->r13);
    // 0x800BD020: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800BD024: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
L_800BD028:
    // 0x800BD028: jr          $ra
    // 0x800BD02C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800BD02C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void chmrsboggy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(888, 0XAD8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xAD8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(888, 0XAD8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xAD8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(888, 0XAD8));
;}
RECOMP_FUNC void basub_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080089C: jal         0x80800458
    // 0x808008A0: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80800458_basub(rdram, ctx);
        goto after_0;
    // 0x808008A0: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_0:
    // 0x808008A4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808008A8: lw          $t7, 0x130($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X130);
    // 0x808008AC: jal         0x800C2FDC
    // 0x808008B0: lbu         $a0, 0xC($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0XC);
    func_800C2FDC(rdram, ctx);
        goto after_1;
    // 0x808008B0: lbu         $a0, 0xC($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0XC);
    after_1:
    // 0x808008B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808008B8: lw          $t8, 0x130($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X130);
    // 0x808008BC: jal         0x80085450
    // 0x808008C0: sb          $zero, 0xC($t8)
    MEM_B(0XC, ctx->r24) = 0;
    _bawobble_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808008C0: sb          $zero, 0xC($t8)
    MEM_B(0XC, ctx->r24) = 0;
    after_2:
    // 0x808008C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008CC: jr          $ra
    // 0x808008D0: nop

    return;
    // 0x808008D0: nop

;}
RECOMP_FUNC void func_80800150_chmermaidstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800158: jal         0x800DA298
    // 0x8080015C: addiu       $a0, $zero, 0x6AE
    ctx->r4 = ADD32(0, 0X6AE);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080015C: addiu       $a0, $zero, 0x6AE
    ctx->r4 = ADD32(0, 0X6AE);
    after_0:
    // 0x80800160: bne         $v0, $zero, L_80800198
    if (ctx->r2 != 0) {
        // 0x80800164: addiu       $a0, $zero, 0x6AF
        ctx->r4 = ADD32(0, 0X6AF);
            goto L_80800198;
    }
    // 0x80800164: addiu       $a0, $zero, 0x6AF
    ctx->r4 = ADD32(0, 0X6AF);
    // 0x80800168: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080016C: jal         0x800DC128
    // 0x80800170: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80800170: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800174: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800178: addiu       $a0, $zero, 0x6AF
    ctx->r4 = ADD32(0, 0X6AF);
    // 0x8080017C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800180: jal         0x800DA7A8
    // 0x80800184: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800DA7A8(rdram, ctx);
        goto after_2;
    // 0x80800184: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x80800188: jal         0x800DA544
    // 0x8080018C: addiu       $a0, $zero, 0x6AE
    ctx->r4 = ADD32(0, 0X6AE);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x8080018C: addiu       $a0, $zero, 0x6AE
    ctx->r4 = ADD32(0, 0X6AE);
    after_3:
    // 0x80800190: b           L_808001A0
    // 0x80800194: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_808001A0;
    // 0x80800194: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80800198:
    // 0x80800198: jal         0x800DA564
    // 0x8080019C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_4;
    // 0x8080019C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
L_808001A0:
    // 0x808001A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001A8: jr          $ra
    // 0x808001AC: nop

    return;
    // 0x808001AC: nop

;}
RECOMP_FUNC void func_80800084_fxkern(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800088: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080008C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2854, 0X488) << 16);
    // 0x80800090: addiu       $v0, $v0, 0x488
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2854, 0X488));
    // 0x80800094: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800098: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8080009C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x808000A0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x808000A4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808000A8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x808000AC: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808000B0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808000B4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808000B8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808000BC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x808000C0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x808000C4: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x808000C8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x808000CC: sll         $t7, $s3, 3
    ctx->r15 = S32(ctx->r19 << 3);
    // 0x808000D0: beq         $t6, $zero, L_808001F0
    if (ctx->r14 == 0) {
        // 0x808000D4: lui         $t8, 0x8080
        ctx->r24 = S32(RELOC_HI16(2854, 0X488) << 16);
            goto L_808001F0;
    }
    // 0x808000D4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2854, 0X488) << 16);
    // 0x808000D8: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x808000DC: addiu       $t8, $t8, 0x488
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2854, 0X488));
    // 0x808000E0: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2854, 0X480) << 16);
    // 0x808000E4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808000E8: addiu       $s2, $s2, 0x480
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2854, 0X480));
    // 0x808000EC: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x808000F0: addu        $s1, $s3, $a0
    ctx->r17 = ADD32(ctx->r19, ctx->r4);
    // 0x808000F4: addiu       $s6, $zero, 0x40
    ctx->r22 = ADD32(0, 0X40);
    // 0x808000F8: addiu       $s5, $sp, 0x54
    ctx->r21 = ADD32(ctx->r29, 0X54);
    // 0x808000FC: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // 0x80800100: lwc1        $f4, -0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0X8);
L_80800104:
    // 0x80800104: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800108: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8080010C: jal         0x800D36C4
    // 0x80800110: lbu         $a1, -0x1($s1)
    ctx->r5 = MEM_BU(ctx->r17, -0X1);
    func_800D36C4(rdram, ctx);
        goto after_0;
    // 0x80800110: lbu         $a1, -0x1($s1)
    ctx->r5 = MEM_BU(ctx->r17, -0X1);
    after_0:
    // 0x80800114: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80800118: bgez        $v0, L_80800128
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8080011C: sra         $t9, $v0, 1
        ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80800128;
    }
    // 0x8080011C: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80800120: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80800124: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80800128:
    // 0x80800128: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8080012C: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800130: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800134: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800138: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8080013C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80800140: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80800144: jal         0x800D36C4
    // 0x80800148: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    func_800D36C4(rdram, ctx);
        goto after_1;
    // 0x80800148: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    after_1:
    // 0x8080014C: lwc1        $f20, 0x0($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80800150: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800154: bgez        $v0, L_80800164
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80800158: sra         $t0, $v0, 1
        ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80800164;
    }
    // 0x80800158: sra         $t0, $v0, 1
    ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8080015C: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80800160: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_80800164:
    // 0x80800164: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80800168: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8080016C: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80800170: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800174: mul.s       $f18, $f20, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80800178: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8080017C: mul.s       $f6, $f20, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x80800180: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x80800184: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800188: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080018C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80800190: lbu         $a1, -0x1($s1)
    ctx->r5 = MEM_BU(ctx->r17, -0X1);
    // 0x80800194: jal         0x80800000
    // 0x80800198: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    func_80800000_fxkern(rdram, ctx);
        goto after_2;
    // 0x80800198: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    after_2:
    // 0x8080019C: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x808001A0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x808001A4: lwc1        $f20, 0x0($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X0);
    // 0x808001A8: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x808001AC: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x808001B0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808001B4: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808001B8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x808001BC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x808001C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808001C4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808001C8: mul.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x808001CC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x808001D0: mul.s       $f16, $f18, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x808001D4: swc1        $f6, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->f6.u32l;
    // 0x808001D8: swc1        $f16, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f16.u32l;
    // 0x808001DC: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
    // 0x808001E0: beql        $t3, $zero, L_808001F4
    if (ctx->r11 == 0) {
        // 0x808001E4: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808001F4;
    }
    goto skip_0;
    // 0x808001E4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x808001E8: bnel        $s3, $s6, L_80800104
    if (ctx->r19 != ctx->r22) {
        // 0x808001EC: lwc1        $f4, -0x8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, -0X8);
            goto L_80800104;
    }
    goto skip_1;
    // 0x808001EC: lwc1        $f4, -0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0X8);
    skip_1:
L_808001F0:
    // 0x808001F0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808001F4:
    // 0x808001F4: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x808001F8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808001FC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800200: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800204: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800208: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8080020C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800210: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800214: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80800218: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8080021C: jr          $ra
    // 0x80800220: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800220: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80110728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110728: jr          $ra
    // 0x8011072C: sb          $a1, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r5;
    return;
    // 0x8011072C: sb          $a1, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void _bsfirstp_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084330: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084330);
    return;
    // 0x80084334: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_808015E0_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808015E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808015E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808015EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808015F0: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
    // 0x808015F4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808015F8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x808015FC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80801600: jal         0x800EEB40
    // 0x80801604: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800EEB40(rdram, ctx);
        goto after_0;
    // 0x80801604: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801608: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080160C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80801610: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801614: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80801618: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080161C: nop

    // 0x80801620: bc1f        L_80801630
    if (!c1cs) {
        // 0x80801624: nop
    
            goto L_80801630;
    }
    // 0x80801624: nop

    // 0x80801628: b           L_80801674
    // 0x8080162C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801674;
    // 0x8080162C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801630:
    // 0x80801630: jal         0x800F18FC
    // 0x80801634: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800F18FC(rdram, ctx);
        goto after_1;
    // 0x80801634: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80801638: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080163C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801640: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801644: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80801648: jal         0x800EF214
    // 0x8080164C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800EF214(rdram, ctx);
        goto after_2;
    // 0x8080164C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80801650: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801654: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80801658: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8080165C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801660: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    // 0x80801664: lui         $a3, 0x4496
    ctx->r7 = S32(0X4496 << 16);
    // 0x80801668: jal         0x80102BF8
    // 0x8080166C: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    func_80102BF8(rdram, ctx);
        goto after_3;
    // 0x8080166C: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    after_3:
    // 0x80801670: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801674:
    // 0x80801674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801678: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080167C: jr          $ra
    // 0x80801680: nop

    return;
    // 0x80801680: nop

;}
RECOMP_FUNC void func_80800000_gctransitionDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2654, 0XCB0) << 16);
    // 0x80800004: addiu       $v1, $v0, 0xCB0
    ctx->r3 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2654, 0XCB0));
    // 0x80800008: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8080000C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2654, 0XCB0) << 16);
    // 0x80800010: addiu       $t7, $t7, 0xCB0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2654, 0XCB0));
    // 0x80800014: beql        $t6, $zero, L_80800044
    if (ctx->r14 == 0) {
        // 0x80800018: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800044;
    }
    goto skip_0;
    // 0x80800018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8080001C: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
L_80800020:
    // 0x80800020: bnel        $a0, $v0, L_80800034
    if (ctx->r4 != ctx->r2) {
        // 0x80800024: lbu         $v0, 0x14($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X14);
            goto L_80800034;
    }
    goto skip_1;
    // 0x80800024: lbu         $v0, 0x14($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X14);
    skip_1:
    // 0x80800028: jr          $ra
    // 0x8080002C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8080002C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800030: lbu         $v0, 0x14($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X14);
L_80800034:
    // 0x80800034: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x80800038: bne         $v0, $zero, L_80800020
    if (ctx->r2 != 0) {
        // 0x8080003C: nop
    
            goto L_80800020;
    }
    // 0x8080003C: nop

    // 0x80800040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800044:
    // 0x80800044: jr          $ra
    // 0x80800048: nop

    return;
    // 0x80800048: nop

;}
RECOMP_FUNC void chjellycastle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2444, 0XA0) << 16);
    // 0x80800094: jr          $ra
    // 0x80800098: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2444, 0XA0));
    return;
    // 0x80800098: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2444, 0XA0));
    // 0x8080009C: nop

;}
RECOMP_FUNC void _chdoormake_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868A0: syscall     393
    recomp_syscall_handler(rdram, ctx, 0x800868A0);
    return;
    // 0x800868A4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bstimeout_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808001B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(400, 0X330) << 16);
    // 0x808001B8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808001BC: jr          $ra
    // 0x808001C0: lw          $v0, 0x330($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(400, 0X330));
    return;
    // 0x808001C0: lw          $v0, 0x330($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(400, 0X330));
;}
RECOMP_FUNC void _bashoes_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085068: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085068);
    return;
    // 0x8008506C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void _bsdronelook_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083130: syscall     45
    recomp_syscall_handler(rdram, ctx, 0x80083130);
    return;
    // 0x80083134: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bafpctrl_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C90: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084C90);
    return;
    // 0x80084C94: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800CA6E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA6E8: jr          $ra
    // 0x800CA6EC: lwc1        $f0, 0x164($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X164);
    return;
    // 0x800CA6EC: lwc1        $f0, 0x164($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X164);
;}
RECOMP_FUNC void func_800DC060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC064: beq         $a0, $zero, L_800DC078
    if (ctx->r4 == 0) {
        // 0x800DC068: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800DC078;
    }
    // 0x800DC068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC06C: jal         0x8001BAFC
    // 0x800DC070: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800DC070: nop

    after_0:
    // 0x800DC074: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800DC078:
    // 0x800DC078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC07C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC080: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800DC084: jr          $ra
    // 0x800DC088: nop

    return;
    // 0x800DC088: nop

    // 0x800DC08C: nop

;}
RECOMP_FUNC void func_80800548_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800548: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080054C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800550: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800554: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800558: jal         0x8008CABC
    // 0x8080055C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080055C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80800560: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800564: jal         0x80082840
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080056C: jal         0x80800058
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800058_bsbeemain(rdram, ctx);
        goto after_2;
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: jal         0x8009BB24
    // 0x8080057C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_3;
    // 0x8080057C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: jal         0x80091A30
    // 0x80800588: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_4;
    // 0x80800588: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x8080058C: beq         $v0, $zero, L_808005B4
    if (ctx->r2 == 0) {
        // 0x80800590: lwc1        $f6, 0x28($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
            goto L_808005B4;
    }
    // 0x80800590: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800594: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800598: nop

    // 0x8080059C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808005A0: nop

    // 0x808005A4: bc1fl       L_808005B8
    if (!c1cs) {
        // 0x808005A8: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_808005B8;
    }
    goto skip_0;
    // 0x808005A8: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_0:
    // 0x808005AC: jal         0x8009BC6C
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_5;
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_808005B4:
    // 0x808005B4: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
L_808005B8:
    // 0x808005B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: beq         $v0, $zero, L_808005F0
    if (ctx->r2 == 0) {
        // 0x808005C4: nop
    
            goto L_808005F0;
    }
    // 0x808005C4: nop

    // 0x808005C8: beq         $v0, $at, L_8080064C
    if (ctx->r2 == ctx->r1) {
        // 0x808005CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080064C;
    }
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005D4: beq         $v0, $at, L_8080067C
    if (ctx->r2 == ctx->r1) {
        // 0x808005D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080067C;
    }
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005E0: beq         $v0, $at, L_808006BC
    if (ctx->r2 == ctx->r1) {
        // 0x808005E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006BC;
    }
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E8: b           L_808006E8
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808006E8;
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005F0:
    // 0x808005F0: jal         0x8008DF8C
    // 0x808005F4: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_6;
    // 0x808005F4: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_6:
    // 0x808005F8: beq         $v0, $zero, L_80800620
    if (ctx->r2 == 0) {
        // 0x808005FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800620;
    }
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: lui         $a1, 0x3F37
    ctx->r5 = S32(0X3F37 << 16);
    // 0x80800604: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800608: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080060C: jal         0x8008CF1C
    // 0x80800610: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_7;
    // 0x80800610: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    after_7:
    // 0x80800614: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800618: b           L_808006E4
    // 0x8080061C: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_808006E4;
    // 0x8080061C: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800620:
    // 0x80800620: jal         0x8008B324
    // 0x80800624: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_8;
    // 0x80800624: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x80800628: beq         $v0, $zero, L_808006E4
    if (ctx->r2 == 0) {
        // 0x8080062C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006E4;
    }
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800630: lui         $a1, 0x3F02
    ctx->r5 = S32(0X3F02 << 16);
    // 0x80800634: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x80800638: jal         0x8008CF1C
    // 0x8080063C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_9;
    // 0x8080063C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_9:
    // 0x80800640: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800644: b           L_808006E4
    // 0x80800648: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_808006E4;
    // 0x80800648: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_8080064C:
    // 0x8080064C: jal         0x8008DF8C
    // 0x80800650: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_10;
    // 0x80800650: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_10:
    // 0x80800654: beq         $v0, $zero, L_808006E4
    if (ctx->r2 == 0) {
        // 0x80800658: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006E4;
    }
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080065C: lui         $a1, 0x3F37
    ctx->r5 = S32(0X3F37 << 16);
    // 0x80800660: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80800664: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800668: jal         0x8008CF1C
    // 0x8080066C: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_11;
    // 0x8080066C: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    after_11:
    // 0x80800670: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80800674: b           L_808006E4
    // 0x80800678: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
        goto L_808006E4;
    // 0x80800678: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_8080067C:
    // 0x8080067C: jal         0x8009D3A8
    // 0x80800680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_12;
    // 0x80800680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800684: jal         0x8008E078
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_13;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080068C: beql        $v0, $zero, L_808006E8
    if (ctx->r2 == 0) {
        // 0x80800690: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006E8;
    }
    goto skip_1;
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800694: jal         0x80800000
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbeemain(rdram, ctx);
        goto after_14;
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080069C: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808006A0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A8: jal         0x8008CF1C
    // 0x808006AC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_15;
    // 0x808006AC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_15:
    // 0x808006B0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x808006B4: b           L_808006E4
    // 0x808006B8: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
        goto L_808006E4;
    // 0x808006B8: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
L_808006BC:
    // 0x808006BC: jal         0x8009D3A8
    // 0x808006C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_16;
    // 0x808006C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x808006C4: jal         0x8008B324
    // 0x808006C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_17;
    // 0x808006C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_17:
    // 0x808006CC: beq         $v0, $zero, L_808006E4
    if (ctx->r2 == 0) {
        // 0x808006D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006E4;
    }
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D4: jal         0x8009B9B0
    // 0x808006D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x808006D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_18:
    // 0x808006DC: addiu       $t0, $zero, 0x85
    ctx->r8 = ADD32(0, 0X85);
    // 0x808006E0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_808006E4:
    // 0x808006E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006E8:
    // 0x808006E8: jal         0x800919F4
    // 0x808006EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_19;
    // 0x808006EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x808006F0: beq         $v0, $zero, L_80800700
    if (ctx->r2 == 0) {
        // 0x808006F4: nop
    
            goto L_80800700;
    }
    // 0x808006F4: nop

    // 0x808006F8: jal         0x80084550
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babee_entrypoint_2(rdram, ctx);
        goto after_20;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
L_80800700:
    // 0x80800700: jal         0x8008E078
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_21;
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800708: beq         $v0, $zero, L_80800740
    if (ctx->r2 == 0) {
        // 0x8080070C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800740;
    }
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800710: jal         0x8009EF10
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_22;
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800718: blez        $v0, L_80800728
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080071C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800728;
    }
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800720: addiu       $t1, $zero, 0x86
    ctx->r9 = ADD32(0, 0X86);
    // 0x80800724: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_80800728:
    // 0x80800728: jal         0x80091A58
    // 0x8080072C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_23;
    // 0x8080072C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_23:
    // 0x80800730: beq         $v0, $zero, L_80800754
    if (ctx->r2 == 0) {
        // 0x80800734: addiu       $t2, $zero, 0x87
        ctx->r10 = ADD32(0, 0X87);
            goto L_80800754;
    }
    // 0x80800734: addiu       $t2, $zero, 0x87
    ctx->r10 = ADD32(0, 0X87);
    // 0x80800738: b           L_80800754
    // 0x8080073C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
        goto L_80800754;
    // 0x8080073C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80800740:
    // 0x80800740: jal         0x80091A58
    // 0x80800744: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_24;
    // 0x80800744: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_24:
    // 0x80800748: beq         $v0, $zero, L_80800754
    if (ctx->r2 == 0) {
        // 0x8080074C: addiu       $t3, $zero, 0x8C
        ctx->r11 = ADD32(0, 0X8C);
            goto L_80800754;
    }
    // 0x8080074C: addiu       $t3, $zero, 0x8C
    ctx->r11 = ADD32(0, 0X8C);
    // 0x80800750: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80800754:
    // 0x80800754: jal         0x8008E35C
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_25;
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x8080075C: beq         $v0, $zero, L_8080076C
    if (ctx->r2 == 0) {
        // 0x80800760: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080076C;
    }
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800764: addiu       $t4, $zero, 0x8C
    ctx->r12 = ADD32(0, 0X8C);
    // 0x80800768: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_8080076C:
    // 0x8080076C: jal         0x8009E5C8
    // 0x80800770: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_26;
    // 0x80800770: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_26:
    // 0x80800774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800778: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080077C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800780: jr          $ra
    // 0x80800784: nop

    return;
    // 0x80800784: nop

;}
RECOMP_FUNC void func_80800334_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800334: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800338: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080033C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800340: lbu         $v0, 0x168($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X168);
    // 0x80800344: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800348: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080034C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80800350: bne         $v0, $zero, L_808003BC
    if (ctx->r2 != 0) {
        // 0x80800354: sb          $t6, 0x168($a0)
        MEM_B(0X168, ctx->r4) = ctx->r14;
            goto L_808003BC;
    }
    // 0x80800354: sb          $t6, 0x168($a0)
    MEM_B(0X168, ctx->r4) = ctx->r14;
    // 0x80800358: jal         0x800DC128
    // 0x8080035C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x8080035C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800360: lbu         $v1, 0x169($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X169);
    // 0x80800364: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(304, 0X1340) << 16);
    // 0x80800368: sb          $v0, 0x168($s0)
    MEM_B(0X168, ctx->r16) = ctx->r2;
    // 0x8080036C: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80800370: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80800374: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x80800378: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8080037C: lh          $a1, 0x1340($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(304, 0X1340));
    // 0x80800380: sltiu       $at, $t9, 0x3
    ctx->r1 = ctx->r25 < 0X3 ? 1 : 0;
    // 0x80800384: bne         $at, $zero, L_80800390
    if (ctx->r1 != 0) {
        // 0x80800388: sb          $t8, 0x169($s0)
        MEM_B(0X169, ctx->r16) = ctx->r24;
            goto L_80800390;
    }
    // 0x80800388: sb          $t8, 0x169($s0)
    MEM_B(0X169, ctx->r16) = ctx->r24;
    // 0x8080038C: sb          $zero, 0x169($s0)
    MEM_B(0X169, ctx->r16) = 0;
L_80800390:
    // 0x80800390: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(304, 0X1310) << 16);
    // 0x80800394: lwc1        $f12, 0x1310($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(304, 0X1310));
    // 0x80800398: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080039C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003A0: jal         0x800DC178
    // 0x808003A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808003A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x808003A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808003AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: jal         0x8009DF18
    // 0x808003B8: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DF18(rdram, ctx);
        goto after_2;
    // 0x808003B8: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_2:
L_808003BC:
    // 0x808003BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003C8: jr          $ra
    // 0x808003CC: nop

    return;
    // 0x808003CC: nop

;}
RECOMP_FUNC void func_800901CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800901CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800901D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800901D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800901D8: jal         0x800F54E4
    // 0x800901DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800901DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800901E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800901E4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800901E8: jal         0x800F66BC
    // 0x800901EC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F66BC(rdram, ctx);
        goto after_1;
    // 0x800901EC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800901F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800901F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800901F8: jr          $ra
    // 0x800901FC: nop

    return;
    // 0x800901FC: nop

;}
RECOMP_FUNC void subaddiedialog_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808012D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808012E0: sh          $a1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r5;
    // 0x808012E4: sh          $a2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r6;
    // 0x808012E8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808012EC: jal         0x8010114C
    // 0x808012F0: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x808012F0: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_0:
    // 0x808012F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808012FC: jr          $ra
    // 0x80801300: nop

    return;
    // 0x80801300: nop

;}
RECOMP_FUNC void func_80800DC8_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800DCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800DD4: addiu       $a0, $zero, 0x33F
    ctx->r4 = ADD32(0, 0X33F);
    // 0x80800DD8: jal         0x801084B0
    // 0x80800DDC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x80800DDC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80800DE0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800DE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800DE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DEC: jal         0x80102FDC
    // 0x80800DF0: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x80800DF0: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    after_1:
    // 0x80800DF4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800DF8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DFC: jal         0x8008A4B0
    // 0x80800E00: lhu         $a1, 0x7C($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X7C);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800E00: lhu         $a1, 0x7C($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X7C);
    after_2:
    // 0x80800E04: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800E08: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E0C: lwc1        $f4, 0x44($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X44);
    // 0x80800E10: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800E14: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    // 0x80800E18: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800E1C: sw          $t9, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r25;
    // 0x80800E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E28: jr          $ra
    // 0x80800E2C: nop

    return;
    // 0x80800E2C: nop

;}
RECOMP_FUNC void chdiggerboss_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004FC: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(1480, 0X9E8C) << 16);
    // 0x80800500: jr          $ra
    // 0x80800504: addiu       $v0, $v0, -0x6174
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1480, 0X9E8C));
    return;
    // 0x80800504: addiu       $v0, $v0, -0x6174
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1480, 0X9E8C));
;}
RECOMP_FUNC void bakaztorpedo_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8080012C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800130: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800134: jal         0x800D8FF8
    // 0x80800138: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800138: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080013C: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80800140: lw          $v1, 0xB0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB0);
    // 0x80800144: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800148: lbu         $a0, 0xC($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XC);
    // 0x8080014C: beq         $a0, $at, L_80800170
    if (ctx->r4 == ctx->r1) {
        // 0x80800150: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800170;
    }
    // 0x80800150: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800154: beq         $a0, $at, L_80800180
    if (ctx->r4 == ctx->r1) {
        // 0x80800158: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800180;
    }
    // 0x80800158: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080015C: beql        $a0, $at, L_80800194
    if (ctx->r4 == ctx->r1) {
        // 0x80800160: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80800194;
    }
    goto skip_0;
    // 0x80800160: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_0:
    // 0x80800164: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800168: b           L_808001A0
    // 0x8080016C: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
        goto L_808001A0;
    // 0x8080016C: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
L_80800170:
    // 0x80800170: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800174: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800178: b           L_808001A0
    // 0x8080017C: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
        goto L_808001A0;
    // 0x8080017C: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
L_80800180:
    // 0x80800180: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800184: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800188: b           L_808001A0
    // 0x8080018C: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
        goto L_808001A0;
    // 0x8080018C: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80800190: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_80800194:
    // 0x80800194: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800198: nop

    // 0x8080019C: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
L_808001A0:
    // 0x808001A0: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: jal         0x8008E124
    // 0x808001AC: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    func_8008E124(rdram, ctx);
        goto after_1;
    // 0x808001AC: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x808001B0: jal         0x800C954C
    // 0x808001B4: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    func_800C954C(rdram, ctx);
        goto after_2;
    // 0x808001B4: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    after_2:
    // 0x808001B8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x808001BC: jal         0x800F8004
    // 0x808001C0: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F8004(rdram, ctx);
        goto after_3;
    // 0x808001C0: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_3:
    // 0x808001C4: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x808001C8: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x808001CC: sltiu       $a0, $v1, 0x1
    ctx->r4 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x808001D0: beq         $a0, $zero, L_808001EC
    if (ctx->r4 == 0) {
        // 0x808001D4: nop
    
            goto L_808001EC;
    }
    // 0x808001D4: nop

    // 0x808001D8: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x808001DC: sltiu       $a0, $v1, 0x1
    ctx->r4 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x808001E0: beq         $a0, $zero, L_808001EC
    if (ctx->r4 == 0) {
        // 0x808001E4: nop
    
            goto L_808001EC;
    }
    // 0x808001E4: nop

    // 0x808001E8: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
L_808001EC:
    // 0x808001EC: beq         $a0, $zero, L_80800210
    if (ctx->r4 == 0) {
        // 0x808001F0: nop
    
            goto L_80800210;
    }
    // 0x808001F0: nop

    // 0x808001F4: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808001F8: lw          $a0, 0xB0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB0);
    // 0x808001FC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800200: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80800204: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800208: jal         0x800F1574
    // 0x8080020C: nop

    func_800F1574(rdram, ctx);
        goto after_4;
    // 0x8080020C: nop

    after_4:
L_80800210:
    // 0x80800210: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(544, 0X410) << 16);
    // 0x80800214: lwc1        $f0, 0x410($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(544, 0X410));
    // 0x80800218: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8080021C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800220: nop

    // 0x80800224: bc1fl       L_80800250
    if (!c1cs) {
        // 0x80800228: lw          $t9, 0xB0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XB0);
            goto L_80800250;
    }
    goto skip_1;
    // 0x80800228: lw          $t9, 0xB0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XB0);
    skip_1:
    // 0x8080022C: lw          $t8, 0xB0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XB0);
    // 0x80800230: lwc1        $f16, 0x10($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80800234: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80800238: nop

    // 0x8080023C: bc1fl       L_80800250
    if (!c1cs) {
        // 0x80800240: lw          $t9, 0xB0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XB0);
            goto L_80800250;
    }
    goto skip_2;
    // 0x80800240: lw          $t9, 0xB0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XB0);
    skip_2:
    // 0x80800244: jal         0x800FC660
    // 0x80800248: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_800FC660(rdram, ctx);
        goto after_5;
    // 0x80800248: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_5:
    // 0x8080024C: lw          $t9, 0xB0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XB0);
L_80800250:
    // 0x80800250: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800254: lwc1        $f12, 0x10($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80800258: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x8080025C: nop

    // 0x80800260: bc1f        L_80800290
    if (!c1cs) {
        // 0x80800264: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(544, 0X414) << 16);
            goto L_80800290;
    }
    // 0x80800264: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(544, 0X414) << 16);
    // 0x80800268: lwc1        $f4, 0x414($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(544, 0X414));
    // 0x8080026C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800270: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80800274: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800278: jal         0x800F10B4
    // 0x8080027C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x8080027C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80800280: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800284: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800288: b           L_80800298
    // 0x8080028C: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
        goto L_80800298;
    // 0x8080028C: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
L_80800290:
    // 0x80800290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800294: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
L_80800298:
    // 0x80800298: jal         0x800D2498
    // 0x8080029C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_7;
    // 0x8080029C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x808002A0: lw          $v1, 0xB0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB0);
    // 0x808002A4: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808002A8: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
    // 0x808002AC: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x808002B0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808002B4: jal         0x800136E4
    // 0x808002B8: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    func_800136E4(rdram, ctx);
        goto after_8;
    // 0x808002B8: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    after_8:
    // 0x808002BC: lw          $t1, 0xB0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XB0);
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: jal         0x80092AD8
    // 0x808002C8: swc1        $f0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f0.u32l;
    func_80092AD8(rdram, ctx);
        goto after_9;
    // 0x808002C8: swc1        $f0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f0.u32l;
    after_9:
    // 0x808002CC: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x808002D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002D4: jal         0x800E0AF0
    // 0x808002D8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E0AF0(rdram, ctx);
        goto after_10;
    // 0x808002D8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_10:
    // 0x808002DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808002E0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808002E4: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x808002E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808002EC: lw          $t2, 0xB0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XB0);
    // 0x808002F0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808002F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002F8: lwc1        $f4, 0x14($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X14);
    // 0x808002FC: jal         0x800E0AFC
    // 0x80800300: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_11;
    // 0x80800300: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x80800304: jal         0x8008E35C
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_12;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080030C: beq         $v0, $zero, L_80800378
    if (ctx->r2 == 0) {
        // 0x80800310: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800378;
    }
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: jal         0x8009C128
    // 0x80800318: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_8009C128(rdram, ctx);
        goto after_13;
    // 0x80800318: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_13:
    // 0x8080031C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800320: lw          $t3, 0xB0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XB0);
    // 0x80800324: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800328: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080032C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800330: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x80800334: lwc1        $f12, 0x18($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X18);
    // 0x80800338: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x8080033C: lui         $a2, 0x4496
    ctx->r6 = S32(0X4496 << 16);
    // 0x80800340: jal         0x800F10B4
    // 0x80800344: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x80800344: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x80800348: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8080034C: lw          $t4, 0xB0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XB0);
    // 0x80800350: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800354: jal         0x800C35E8
    // 0x80800358: lbu         $a0, 0x1C($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X1C);
    func_800C35E8(rdram, ctx);
        goto after_15;
    // 0x80800358: lbu         $a0, 0x1C($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X1C);
    after_15:
    // 0x8080035C: lw          $t5, 0xB0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XB0);
    // 0x80800360: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800364: jal         0x800C31DC
    // 0x80800368: lbu         $a0, 0x1C($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X1C);
    func_800C31DC(rdram, ctx);
        goto after_16;
    // 0x80800368: lbu         $a0, 0x1C($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X1C);
    after_16:
    // 0x8080036C: lw          $t6, 0xB0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XB0);
    // 0x80800370: jal         0x800C3BDC
    // 0x80800374: lbu         $a0, 0x1C($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X1C);
    func_800C3BDC(rdram, ctx);
        goto after_17;
    // 0x80800374: lbu         $a0, 0x1C($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X1C);
    after_17:
L_80800378:
    // 0x80800378: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080037C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800380: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800384: lw          $v1, 0xB0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB0);
    // 0x80800388: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080038C: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800390: lwc1        $f14, 0x4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800394: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800398: jal         0x800F15F8
    // 0x8080039C: nop

    func_800F15F8(rdram, ctx);
        goto after_18;
    // 0x8080039C: nop

    after_18:
    // 0x808003A0: lw          $t7, 0xB0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB0);
    // 0x808003A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808003A8: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    // 0x808003AC: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x808003B0: lw          $t8, 0xB0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XB0);
    // 0x808003B4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808003B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808003BC: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x808003C0: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x808003C4: jal         0x800E0AFC
    // 0x808003C8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_19;
    // 0x808003C8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_19:
    // 0x808003CC: lw          $t9, 0xB0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XB0);
    // 0x808003D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808003D4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808003D8: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x808003DC: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    // 0x808003E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808003E4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808003E8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x808003EC: jal         0x800E0AFC
    // 0x808003F0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_20;
    // 0x808003F0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_20:
    // 0x808003F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003FC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80800400: jr          $ra
    // 0x80800404: nop

    return;
    // 0x80800404: nop

    // 0x80800408: nop

    // 0x8080040C: nop

;}
RECOMP_FUNC void _chdiggerbossinterior_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086818: syscall     383
    recomp_syscall_handler(rdram, ctx, 0x80086818);
    return;
    // 0x8008681C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80090E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090E48: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80090E4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80090E50: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80090E54: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x80090E58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80090E5C: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x80090E60: beql        $t7, $zero, L_80090E80
    if (ctx->r15 == 0) {
        // 0x80090E64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80090E80;
    }
    goto skip_0;
    // 0x80090E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80090E68: jal         0x8008FD48
    // 0x80090E6C: nop

    func_8008FD48(rdram, ctx);
        goto after_0;
    // 0x80090E6C: nop

    after_0:
    // 0x80090E70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80090E74: beq         $v0, $at, L_80090E90
    if (ctx->r2 == ctx->r1) {
        // 0x80090E78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80090E90;
    }
    // 0x80090E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80090E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80090E80:
    // 0x80090E80: jal         0x80092E5C
    // 0x80090E84: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80092E5C(rdram, ctx);
        goto after_1;
    // 0x80090E84: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80090E88: b           L_80090E9C
    // 0x80090E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80090E9C;
    // 0x80090E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80090E90:
    // 0x80090E90: jal         0x80092DE4
    // 0x80090E94: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80092DE4(rdram, ctx);
        goto after_2;
    // 0x80090E94: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80090E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80090E9C:
    // 0x80090E9C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80090EA0: jal         0x8009FBB0
    // 0x80090EA4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009FBB0(rdram, ctx);
        goto after_3;
    // 0x80090EA4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_3:
    // 0x80090EA8: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80090EAC: addiu       $t8, $t8, 0x7DB0
    ctx->r24 = ADD32(ctx->r24, 0X7DB0);
    // 0x80090EB0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80090EB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090EB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80090EBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80090EC0: jal         0x800BABB8
    // 0x80090EC4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80090EC4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80090EC8: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x80090ECC: lbu         $t9, 0xF($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF);
    // 0x80090ED0: beql        $t9, $zero, L_80090F28
    if (ctx->r25 == 0) {
        // 0x80090ED4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80090F28;
    }
    goto skip_1;
    // 0x80090ED4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80090ED8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80090EDC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80090EE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090EE4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80090EE8: nop

    // 0x80090EEC: bc1fl       L_80090F28
    if (!c1cs) {
        // 0x80090EF0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80090F28;
    }
    goto skip_2;
    // 0x80090EF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80090EF4: lwc1        $f8, 0x4D00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4D00);
    // 0x80090EF8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80090EFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80090F00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090F04: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x80090F08: jal         0x800DC178
    // 0x80090F0C: lwc1        $f14, 0x4D04($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X4D04);
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80090F0C: lwc1        $f14, 0x4D04($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X4D04);
    after_5:
    // 0x80090F10: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80090F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80090F18: addiu       $a1, $zero, 0x3ED
    ctx->r5 = ADD32(0, 0X3ED);
    // 0x80090F1C: jal         0x8009DF94
    // 0x80090F20: addiu       $a3, $zero, 0x1770
    ctx->r7 = ADD32(0, 0X1770);
    func_8009DF94(rdram, ctx);
        goto after_6;
    // 0x80090F20: addiu       $a3, $zero, 0x1770
    ctx->r7 = ADD32(0, 0X1770);
    after_6:
    // 0x80090F24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80090F28:
    // 0x80090F28: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80090F2C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80090F30: jr          $ra
    // 0x80090F34: nop

    return;
    // 0x80090F34: nop

;}
RECOMP_FUNC void func_80800000_chfactorylinkgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080000C: lw          $a1, 0x6C($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X6C);
    // 0x80800010: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800014: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x80800018: srl         $t6, $a1, 21
    ctx->r14 = S32(U32(ctx->r5) >> 21);
    // 0x8080001C: jal         0x800882C8
    // 0x80800020: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    _gccubesearch_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
    // 0x80800024: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800028: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x8080002C: lbu         $t0, 0x79($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X79);
    // 0x80800030: andi        $t1, $t0, 0xFF0F
    ctx->r9 = ctx->r8 & 0XFF0F;
    // 0x80800034: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800038: andi        $a0, $t2, 0xFF
    ctx->r4 = ctx->r10 & 0XFF;
    // 0x8080003C: srl         $t3, $a0, 4
    ctx->r11 = S32(U32(ctx->r4) >> 4);
    // 0x80800040: addiu       $a0, $t3, 0x1C0
    ctx->r4 = ADD32(ctx->r11, 0X1C0);
    // 0x80800044: jal         0x800DA298
    // 0x80800048: sb          $t2, 0x79($a2)
    MEM_B(0X79, ctx->r6) = ctx->r10;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800048: sb          $t2, 0x79($a2)
    MEM_B(0X79, ctx->r6) = ctx->r10;
    after_1:
    // 0x8080004C: beq         $v0, $zero, L_8080005C
    if (ctx->r2 == 0) {
        // 0x80800050: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8080005C;
    }
    // 0x80800050: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800054: jal         0x800FFAB0
    // 0x80800058: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800058: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_8080005C:
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800064: jr          $ra
    // 0x80800068: nop

    return;
    // 0x80800068: nop

;}
RECOMP_FUNC void func_800BF8E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF8E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BF8E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800BF8EC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800BF8F0: addiu       $s1, $s1, -0x7A50
    ctx->r17 = ADD32(ctx->r17, -0X7A50);
    // 0x800BF8F4: lb          $v1, 0x84($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X84);
    // 0x800BF8F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BF8FC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BF900: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800BF904: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800BF908: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800BF90C: bne         $v1, $at, L_800BF978
    if (ctx->r3 != ctx->r1) {
        // 0x800BF910: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800BF978;
    }
    // 0x800BF910: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BF914: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800BF918: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800BF91C: sb          $zero, 0x84($s1)
    MEM_B(0X84, ctx->r17) = 0;
    // 0x800BF920: addiu       $s4, $s4, -0x79F8
    ctx->r20 = ADD32(ctx->r20, -0X79F8);
    // 0x800BF924: addiu       $s0, $s0, -0x7A50
    ctx->r16 = ADD32(ctx->r16, -0X7A50);
    // 0x800BF928: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x800BF92C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800BF930: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_800BF934:
    // 0x800BF934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BF938: beql        $t6, $zero, L_800BF948
    if (ctx->r14 == 0) {
        // 0x800BF93C: lw          $t7, 0x1C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X1C);
            goto L_800BF948;
    }
    goto skip_0;
    // 0x800BF93C: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    skip_0:
    // 0x800BF940: sb          $s2, 0x84($s1)
    MEM_B(0X84, ctx->r17) = ctx->r18;
    // 0x800BF944: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
L_800BF948:
    // 0x800BF948: beql        $t7, $zero, L_800BF968
    if (ctx->r15 == 0) {
        // 0x800BF94C: addiu       $s0, $s0, 0x2C
        ctx->r16 = ADD32(ctx->r16, 0X2C);
            goto L_800BF968;
    }
    goto skip_1;
    // 0x800BF94C: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    skip_1:
    // 0x800BF950: jal         0x800879A0
    // 0x800BF954: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    _dbvpl_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800BF954: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_0:
    // 0x800BF958: beql        $v0, $zero, L_800BF968
    if (ctx->r2 == 0) {
        // 0x800BF95C: addiu       $s0, $s0, 0x2C
        ctx->r16 = ADD32(ctx->r16, 0X2C);
            goto L_800BF968;
    }
    goto skip_2;
    // 0x800BF95C: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    skip_2:
    // 0x800BF960: sb          $s3, 0x84($s1)
    MEM_B(0X84, ctx->r17) = ctx->r19;
    // 0x800BF964: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
L_800BF968:
    // 0x800BF968: bnel        $s0, $s4, L_800BF934
    if (ctx->r16 != ctx->r20) {
        // 0x800BF96C: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_800BF934;
    }
    goto skip_3;
    // 0x800BF96C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_3:
    // 0x800BF970: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BF974: lb          $v1, -0x79CC($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X79CC);
L_800BF978:
    // 0x800BF978: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF97C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BF980: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF984: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800BF988: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800BF98C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800BF990: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BF994: jr          $ra
    // 0x800BF998: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800BF998: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_808001F4_chfoodwarn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001F8: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808001FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800200: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800204: beq         $a1, $at, L_8080024C
    if (ctx->r5 == ctx->r1) {
        // 0x80800208: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080024C;
    }
    // 0x80800208: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080020C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800210: bne         $a1, $at, L_80800244
    if (ctx->r5 != ctx->r1) {
        // 0x80800214: nop
    
            goto L_80800244;
    }
    // 0x80800214: nop

    // 0x80800218: jal         0x80105010
    // 0x8080021C: nop

    func_80105010(rdram, ctx);
        goto after_0;
    // 0x8080021C: nop

    after_0:
    // 0x80800220: jal         0x8010C500
    // 0x80800224: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010C500(rdram, ctx);
        goto after_1;
    // 0x80800224: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800228: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8080022C: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80800230: lhu         $t8, 0x6E($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X6E);
    // 0x80800234: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800238: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8080023C: b           L_8080024C
    // 0x80800240: sh          $t0, 0x6E($v1)
    MEM_H(0X6E, ctx->r3) = ctx->r8;
        goto L_8080024C;
    // 0x80800240: sh          $t0, 0x6E($v1)
    MEM_H(0X6E, ctx->r3) = ctx->r8;
L_80800244:
    // 0x80800244: b           L_80800250
    // 0x80800248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800250;
    // 0x80800248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080024C:
    // 0x8080024C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800250:
    // 0x80800250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800258: jr          $ra
    // 0x8080025C: nop

    return;
    // 0x8080025C: nop

;}
RECOMP_FUNC void func_80101BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101BE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80101BE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80101BE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80101BEC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80101BF0: jal         0x80102394
    // 0x80101BF4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80102394(rdram, ctx);
        goto after_0;
    // 0x80101BF4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80101BF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80101BFC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80101C00: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80101C04: lbu         $t9, 0x72($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X72);
    // 0x80101C08: sll         $v1, $s0, 3
    ctx->r3 = S32(ctx->r16 << 3);
    // 0x80101C0C: addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // 0x80101C10: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x80101C14: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80101C18: bne         $v0, $zero, L_80101C28
    if (ctx->r2 != 0) {
        // 0x80101C1C: sb          $t1, 0x72($a0)
        MEM_B(0X72, ctx->r4) = ctx->r9;
            goto L_80101C28;
    }
    // 0x80101C1C: sb          $t1, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r9;
    // 0x80101C20: b           L_80101CC8
    // 0x80101C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80101CC8;
    // 0x80101C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101C28:
    // 0x80101C28: lhu         $t3, 0x4($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X4);
    // 0x80101C2C: beq         $t3, $zero, L_80101CBC
    if (ctx->r11 == 0) {
        // 0x80101C30: nop
    
            goto L_80101CBC;
    }
    // 0x80101C30: nop

    // 0x80101C34: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80101C38: jal         0x80104248
    // 0x80101C3C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80104248(rdram, ctx);
        goto after_1;
    // 0x80101C3C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x80101C40: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80101C44: bne         $v0, $zero, L_80101C60
    if (ctx->r2 != 0) {
        // 0x80101C48: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80101C60;
    }
    // 0x80101C48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80101C4C: jal         0x801042B8
    // 0x80101C50: nop

    func_801042B8(rdram, ctx);
        goto after_2;
    // 0x80101C50: nop

    after_2:
    // 0x80101C54: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80101C58: jal         0x8008AF24
    // 0x80101C5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_3;
    // 0x80101C5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
L_80101C60:
    // 0x80101C60: jal         0x8008B284
    // 0x80101C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_getPlaybackType(rdram, ctx);
        goto after_4;
    // 0x80101C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80101C68: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80101C6C: bne         $v0, $at, L_80101C7C
    if (ctx->r2 != ctx->r1) {
        // 0x80101C70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80101C7C;
    }
    // 0x80101C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80101C74: jal         0x8008B134
    // 0x80101C78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80101C78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
L_80101C7C:
    // 0x80101C7C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80101C80: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80101C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80101C88: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80101C8C: lhu         $a1, 0x4($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X4);
    // 0x80101C90: jal         0x8008AED4
    // 0x80101C94: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    anctrl_setIndex(rdram, ctx);
        goto after_6;
    // 0x80101C94: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_6:
    // 0x80101C98: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80101C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80101CA0: jal         0x8008B1BC
    // 0x80101CA4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    anctrl_setDuration(rdram, ctx);
        goto after_7;
    // 0x80101CA4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    after_7:
    // 0x80101CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80101CAC: jal         0x8008B188
    // 0x80101CB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008B188(rdram, ctx);
        goto after_8;
    // 0x80101CB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80101CB4: b           L_80101CC8
    // 0x80101CB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80101CC8;
    // 0x80101CB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80101CBC:
    // 0x80101CBC: jal         0x80104328
    // 0x80101CC0: nop

    func_80104328(rdram, ctx);
        goto after_9;
    // 0x80101CC0: nop

    after_9:
    // 0x80101CC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80101CC8:
    // 0x80101CC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80101CCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80101CD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80101CD4: jr          $ra
    // 0x80101CD8: nop

    return;
    // 0x80101CD8: nop

;}
RECOMP_FUNC void func_800F49D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F49D4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F49D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F49DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F49E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F49E4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F49E8: jal         0x80084840
    // 0x800F49EC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _badrone_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x800F49EC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F49F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F49F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F49F8: jr          $ra
    // 0x800F49FC: nop

    return;
    // 0x800F49FC: nop

;}
RECOMP_FUNC void func_80800274_chsignpost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800278: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080027C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800280: lw          $a1, 0x28($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X28);
    // 0x80800284: addiu       $a1, $a1, 0x1686
    ctx->r5 = ADD32(ctx->r5, 0X1686);
    // 0x80800288: slti        $at, $a1, 0x16B7
    ctx->r1 = SIGNED(ctx->r5) < 0X16B7 ? 1 : 0;
    // 0x8080028C: bne         $at, $zero, L_808002B0
    if (ctx->r1 != 0) {
        // 0x80800290: slti        $at, $a1, 0x16BF
        ctx->r1 = SIGNED(ctx->r5) < 0X16BF ? 1 : 0;
            goto L_808002B0;
    }
    // 0x80800290: slti        $at, $a1, 0x16BF
    ctx->r1 = SIGNED(ctx->r5) < 0X16BF ? 1 : 0;
    // 0x80800294: beq         $at, $zero, L_808002B0
    if (ctx->r1 == 0) {
        // 0x80800298: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_808002B0;
    }
    // 0x80800298: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8080029C: jal         0x800D3E40
    // 0x808002A0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800D3E40(rdram, ctx);
        goto after_0;
    // 0x808002A0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002A4: bne         $v0, $zero, L_808002B0
    if (ctx->r2 != 0) {
        // 0x808002A8: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_808002B0;
    }
    // 0x808002A8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808002AC: addiu       $a1, $zero, 0x16BF
    ctx->r5 = ADD32(0, 0X16BF);
L_808002B0:
    // 0x808002B0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808002B4: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x808002B8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808002BC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x808002C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808002C4: jal         0x8008A208
    // 0x808002C8: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808002C8: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    after_1:
    // 0x808002CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void func_800D5250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D5254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5258: jal         0x800D52B0
    // 0x800D525C: nop

    func_800D52B0(rdram, ctx);
        goto after_0;
    // 0x800D525C: nop

    after_0:
    // 0x800D5260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D5264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D5268: jr          $ra
    // 0x800D526C: nop

    return;
    // 0x800D526C: nop

;}
RECOMP_FUNC void _baeggfire_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B10: syscall     129
    recomp_syscall_handler(rdram, ctx, 0x80084B10);
    return;
    // 0x80084B14: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void _gspropctrl_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C08: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088C08);
    return;
    // 0x80088C0C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _changlerboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800865A0: syscall     339
    recomp_syscall_handler(rdram, ctx, 0x800865A0);
    return;
    // 0x800865A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _glcrc_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088708: syscall     700
    recomp_syscall_handler(rdram, ctx, 0x80088708);
    return;
    // 0x8008870C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chterryegg_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1112, 0X1328) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1328
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1112, 0X1328));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1328
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1112, 0X1328));
;}
RECOMP_FUNC void func_8080000C_chdinofoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: jal         0x80088848
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800020: beq         $v0, $zero, L_8080003C
    if (ctx->r2 == 0) {
        // 0x80800024: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080003C;
    }
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800028: jal         0x80102424
    // 0x8080002C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80800030: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1040, 0X7A0) << 16);
    // 0x80800034: lwc1        $f4, 0x7A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1040, 0X7A0));
    // 0x80800038: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_8080003C:
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x80800044: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80800048: jal         0x80089CF0
    // 0x8080004C: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    _subaddiefade_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x8080004C: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_2:
    // 0x80800050: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800054: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800058: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800064: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800068: jal         0x80102FDC
    // 0x8080006C: nop

    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x8080006C: nop

    after_3:
    // 0x80800070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800074: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800078: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void func_80800010_chlavaentrancebridge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800014: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800018: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x8080001C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800024: beq         $a1, $at, L_8080005C
    if (ctx->r5 == ctx->r1) {
        // 0x80800028: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8080005C;
    }
    // 0x80800028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080002C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800030: bne         $a1, $at, L_80800070
    if (ctx->r5 != ctx->r1) {
        // 0x80800034: addiu       $a0, $zero, 0x391
        ctx->r4 = ADD32(0, 0X391);
            goto L_80800070;
    }
    // 0x80800034: addiu       $a0, $zero, 0x391
    ctx->r4 = ADD32(0, 0X391);
    // 0x80800038: jal         0x800DA298
    // 0x8080003C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080003C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800040: beq         $v0, $zero, L_80800078
    if (ctx->r2 == 0) {
        // 0x80800044: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800078;
    }
    // 0x80800044: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800048: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080004C: jal         0x80101FDC
    // 0x80800050: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800050: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80800054: b           L_8080007C
    // 0x80800058: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080007C;
    // 0x80800058: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080005C:
    // 0x8080005C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800060: jal         0x80101FDC
    // 0x80800064: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800064: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800068: b           L_8080007C
    // 0x8080006C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080007C;
    // 0x8080006C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800070:
    // 0x80800070: b           L_8080007C
    // 0x80800074: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080007C;
    // 0x80800074: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800078:
    // 0x80800078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080007C:
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void func_808008F8_chbadbeehive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800900: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800904: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800908: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080090C: jal         0x80100094
    // 0x80800910: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800910: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800914: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800918: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080091C: jal         0x80102424
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800924: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800928: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080092C: beq         $a1, $at, L_8080097C
    if (ctx->r5 == ctx->r1) {
        // 0x80800930: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080097C;
    }
    // 0x80800930: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800934: beq         $a1, $at, L_8080094C
    if (ctx->r5 == ctx->r1) {
        // 0x80800938: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080094C;
    }
    // 0x80800938: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080093C: beql        $a1, $at, L_8080095C
    if (ctx->r5 == ctx->r1) {
        // 0x80800940: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8080095C;
    }
    goto skip_0;
    // 0x80800940: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800944: b           L_80800980
    // 0x80800948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800980;
    // 0x80800948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080094C:
    // 0x8080094C: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800950: b           L_8080097C
    // 0x80800954: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
        goto L_8080097C;
    // 0x80800954: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80800958: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_8080095C:
    // 0x8080095C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800960: jal         0x800EE7F8
    // 0x80800964: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800964: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_2:
    // 0x80800968: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080096C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800970: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800974: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800978: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
L_8080097C:
    // 0x8080097C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800980:
    // 0x80800980: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800988: jr          $ra
    // 0x8080098C: nop

    return;
    // 0x8080098C: nop

;}
RECOMP_FUNC void func_800C87B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C87B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C87BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C87C0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C87C4: jal         0x800EE830
    // 0x800C87C8: addiu       $a1, $a1, -0x54FC
    ctx->r5 = ADD32(ctx->r5, -0X54FC);
    func_800EE830(rdram, ctx);
        goto after_0;
    // 0x800C87C8: addiu       $a1, $a1, -0x54FC
    ctx->r5 = ADD32(ctx->r5, -0X54FC);
    after_0:
    // 0x800C87CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C87D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C87D4: jr          $ra
    // 0x800C87D8: nop

    return;
    // 0x800C87D8: nop

;}
RECOMP_FUNC void func_80112550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80112554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80112558: jal         0x80112168
    // 0x8011255C: nop

    func_80112168(rdram, ctx);
        goto after_0;
    // 0x8011255C: nop

    after_0:
    // 0x80112560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80112564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80112568: jr          $ra
    // 0x8011256C: nop

    return;
    // 0x8011256C: nop

;}
RECOMP_FUNC void func_800DA298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DA29C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DA2A0: bltz        $a0, L_800DA2DC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800DA2A4: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800DA2DC;
    }
    // 0x800DA2A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DA2A8: slti        $at, $a0, 0x20
    ctx->r1 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x800DA2AC: beq         $at, $zero, L_800DA2DC
    if (ctx->r1 == 0) {
        // 0x800DA2B0: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800DA2DC;
    }
    // 0x800DA2B0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800DA2B4: lw          $t8, -0x4670($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4670);
    // 0x800DA2B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DA2BC: sllv        $t7, $t6, $a0
    ctx->r15 = S32(ctx->r14 << (ctx->r4 & 31));
    // 0x800DA2C0: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x800DA2C4: beq         $t9, $zero, L_800DA2D4
    if (ctx->r25 == 0) {
        // 0x800DA2C8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800DA2D4;
    }
    // 0x800DA2C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800DA2CC: b           L_800DA3A8
    // 0x800DA2D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800DA3A8;
    // 0x800DA2D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800DA2D4:
    // 0x800DA2D4: b           L_800DA3A8
    // 0x800DA2D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800DA3A8;
    // 0x800DA2D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800DA2DC:
    // 0x800DA2DC: slti        $at, $a2, 0x29
    ctx->r1 = SIGNED(ctx->r6) < 0X29 ? 1 : 0;
    // 0x800DA2E0: bne         $at, $zero, L_800DA304
    if (ctx->r1 != 0) {
        // 0x800DA2E4: slti        $at, $a2, 0x5A5
        ctx->r1 = SIGNED(ctx->r6) < 0X5A5 ? 1 : 0;
            goto L_800DA304;
    }
    // 0x800DA2E4: slti        $at, $a2, 0x5A5
    ctx->r1 = SIGNED(ctx->r6) < 0X5A5 ? 1 : 0;
    // 0x800DA2E8: beq         $at, $zero, L_800DA304
    if (ctx->r1 == 0) {
        // 0x800DA2EC: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA304;
    }
    // 0x800DA2EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA2F0: lw          $a0, -0x3890($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3890);
    // 0x800DA2F4: jal         0x800D9E60
    // 0x800DA2F8: addiu       $a1, $a2, -0x28
    ctx->r5 = ADD32(ctx->r6, -0X28);
    bitfield_get_bit(rdram, ctx);
        goto after_0;
    // 0x800DA2F8: addiu       $a1, $a2, -0x28
    ctx->r5 = ADD32(ctx->r6, -0X28);
    after_0:
    // 0x800DA2FC: b           L_800DA3AC
    // 0x800DA300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DA3AC;
    // 0x800DA300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DA304:
    // 0x800DA304: slti        $at, $a2, 0x641
    ctx->r1 = SIGNED(ctx->r6) < 0X641 ? 1 : 0;
    // 0x800DA308: bne         $at, $zero, L_800DA32C
    if (ctx->r1 != 0) {
        // 0x800DA30C: slti        $at, $a2, 0x6ED
        ctx->r1 = SIGNED(ctx->r6) < 0X6ED ? 1 : 0;
            goto L_800DA32C;
    }
    // 0x800DA30C: slti        $at, $a2, 0x6ED
    ctx->r1 = SIGNED(ctx->r6) < 0X6ED ? 1 : 0;
    // 0x800DA310: beq         $at, $zero, L_800DA32C
    if (ctx->r1 == 0) {
        // 0x800DA314: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA32C;
    }
    // 0x800DA314: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA318: lw          $a0, -0x388C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X388C);
    // 0x800DA31C: jal         0x800D9E60
    // 0x800DA320: addiu       $a1, $a2, -0x640
    ctx->r5 = ADD32(ctx->r6, -0X640);
    bitfield_get_bit(rdram, ctx);
        goto after_1;
    // 0x800DA320: addiu       $a1, $a2, -0x640
    ctx->r5 = ADD32(ctx->r6, -0X640);
    after_1:
    // 0x800DA324: b           L_800DA3AC
    // 0x800DA328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DA3AC;
    // 0x800DA328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DA32C:
    // 0x800DA32C: slti        $at, $a2, 0x9C5
    ctx->r1 = SIGNED(ctx->r6) < 0X9C5 ? 1 : 0;
    // 0x800DA330: bne         $at, $zero, L_800DA354
    if (ctx->r1 != 0) {
        // 0x800DA334: slti        $at, $a2, 0xAC4
        ctx->r1 = SIGNED(ctx->r6) < 0XAC4 ? 1 : 0;
            goto L_800DA354;
    }
    // 0x800DA334: slti        $at, $a2, 0xAC4
    ctx->r1 = SIGNED(ctx->r6) < 0XAC4 ? 1 : 0;
    // 0x800DA338: beq         $at, $zero, L_800DA354
    if (ctx->r1 == 0) {
        // 0x800DA33C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA354;
    }
    // 0x800DA33C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA340: lw          $a0, -0x3888($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3888);
    // 0x800DA344: jal         0x800D9E60
    // 0x800DA348: addiu       $a1, $a2, -0x9C4
    ctx->r5 = ADD32(ctx->r6, -0X9C4);
    bitfield_get_bit(rdram, ctx);
        goto after_2;
    // 0x800DA348: addiu       $a1, $a2, -0x9C4
    ctx->r5 = ADD32(ctx->r6, -0X9C4);
    after_2:
    // 0x800DA34C: b           L_800DA3AC
    // 0x800DA350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DA3AC;
    // 0x800DA350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DA354:
    // 0x800DA354: slti        $at, $a2, 0xBB9
    ctx->r1 = SIGNED(ctx->r6) < 0XBB9 ? 1 : 0;
    // 0x800DA358: bne         $at, $zero, L_800DA37C
    if (ctx->r1 != 0) {
        // 0x800DA35C: slti        $at, $a2, 0xC16
        ctx->r1 = SIGNED(ctx->r6) < 0XC16 ? 1 : 0;
            goto L_800DA37C;
    }
    // 0x800DA35C: slti        $at, $a2, 0xC16
    ctx->r1 = SIGNED(ctx->r6) < 0XC16 ? 1 : 0;
    // 0x800DA360: beq         $at, $zero, L_800DA37C
    if (ctx->r1 == 0) {
        // 0x800DA364: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA37C;
    }
    // 0x800DA364: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA368: addiu       $a0, $a0, -0x3880
    ctx->r4 = ADD32(ctx->r4, -0X3880);
    // 0x800DA36C: jal         0x800D9E60
    // 0x800DA370: addiu       $a1, $a2, -0xBB8
    ctx->r5 = ADD32(ctx->r6, -0XBB8);
    bitfield_get_bit(rdram, ctx);
        goto after_3;
    // 0x800DA370: addiu       $a1, $a2, -0xBB8
    ctx->r5 = ADD32(ctx->r6, -0XBB8);
    after_3:
    // 0x800DA374: b           L_800DA3AC
    // 0x800DA378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DA3AC;
    // 0x800DA378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DA37C:
    // 0x800DA37C: slti        $at, $a2, 0xD49
    ctx->r1 = SIGNED(ctx->r6) < 0XD49 ? 1 : 0;
    // 0x800DA380: bne         $at, $zero, L_800DA3A8
    if (ctx->r1 != 0) {
        // 0x800DA384: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DA3A8;
    }
    // 0x800DA384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800DA388: slti        $at, $a2, 0xD75
    ctx->r1 = SIGNED(ctx->r6) < 0XD75 ? 1 : 0;
    // 0x800DA38C: beq         $at, $zero, L_800DA3A8
    if (ctx->r1 == 0) {
        // 0x800DA390: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DA3A8;
    }
    // 0x800DA390: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DA394: addiu       $a0, $a0, -0x3874
    ctx->r4 = ADD32(ctx->r4, -0X3874);
    // 0x800DA398: jal         0x800D9E60
    // 0x800DA39C: addiu       $a1, $a2, -0xD48
    ctx->r5 = ADD32(ctx->r6, -0XD48);
    bitfield_get_bit(rdram, ctx);
        goto after_4;
    // 0x800DA39C: addiu       $a1, $a2, -0xD48
    ctx->r5 = ADD32(ctx->r6, -0XD48);
    after_4:
    // 0x800DA3A0: b           L_800DA3AC
    // 0x800DA3A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DA3AC;
    // 0x800DA3A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DA3A8:
    // 0x800DA3A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DA3AC:
    // 0x800DA3AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DA3B0: jr          $ra
    // 0x800DA3B4: nop

    return;
    // 0x800DA3B4: nop

;}
RECOMP_FUNC void func_80800E58_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800E64: jal         0x80100094
    // 0x80800E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800E70: jal         0x800904C8
    // 0x80800E74: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800904C8(rdram, ctx);
        goto after_1;
    // 0x80800E74: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_1:
    // 0x80800E78: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800E7C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E80: beql        $t6, $zero, L_80800E94
    if (ctx->r14 == 0) {
        // 0x80800E84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800E94;
    }
    goto skip_0;
    // 0x80800E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800E88: jal         0x800903D0
    // 0x80800E8C: addiu       $a0, $a0, 0x928
    ctx->r4 = ADD32(ctx->r4, 0X928);
    func_800903D0(rdram, ctx);
        goto after_2;
    // 0x80800E8C: addiu       $a0, $a0, 0x928
    ctx->r4 = ADD32(ctx->r4, 0X928);
    after_2:
    // 0x80800E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E94:
    // 0x80800E94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E98: jr          $ra
    // 0x80800E9C: nop

    return;
    // 0x80800E9C: nop

;}
