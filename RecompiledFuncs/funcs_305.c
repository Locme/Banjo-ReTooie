#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void gcboundDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080014C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800150: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800154: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800158: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080015C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800160: jal         0x808000AC
    // 0x80800164: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_808000AC_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x80800164: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x80800170: jal         0x808000AC
    // 0x80800174: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    func_808000AC_gcboundDll(rdram, ctx);
        goto after_1;
    // 0x80800174: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    after_1:
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x80800180: jal         0x808000AC
    // 0x80800184: addiu       $a2, $s0, 0x14
    ctx->r6 = ADD32(ctx->r16, 0X14);
    func_808000AC_gcboundDll(rdram, ctx);
        goto after_2;
    // 0x80800184: addiu       $a2, $s0, 0x14
    ctx->r6 = ADD32(ctx->r16, 0X14);
    after_2:
    // 0x80800188: jal         0x800B42DC
    // 0x8080018C: lw          $a0, 0xE0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XE0);
    func_800B42DC(rdram, ctx);
        goto after_3;
    // 0x8080018C: lw          $a0, 0xE0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XE0);
    after_3:
    // 0x80800190: sw          $zero, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = 0;
    // 0x80800194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080019C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void func_80800274_bssplat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080027C: jal         0x8008E95C
    // 0x80800280: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E95C(rdram, ctx);
        goto after_0;
    // 0x80800280: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800284: jal         0x8009BD88
    // 0x80800288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8009BD88(rdram, ctx);
        goto after_1;
    // 0x80800288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080028C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800294: jr          $ra
    // 0x80800298: nop

    return;
    // 0x80800298: nop

;}
RECOMP_FUNC void func_80800898_chfactorycrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800898: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080089C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008A0: jal         0x80106790
    // 0x808008A4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808008A4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808008A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008B0: jr          $ra
    // 0x808008B4: nop

    return;
    // 0x808008B4: nop

;}
RECOMP_FUNC void bswalk_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808009F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(435, 0X1530) << 16);
    // 0x808009F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808009F8: jr          $ra
    // 0x808009FC: lw          $v0, 0x1530($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(435, 0X1530));
    return;
    // 0x808009FC: lw          $v0, 0x1530($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(435, 0X1530));
;}
RECOMP_FUNC void _bawasher_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085418: syscall     161
    recomp_syscall_handler(rdram, ctx, 0x80085418);
    return;
    // 0x8008541C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800230_choctopus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800230: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800234: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800238: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080023C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800240: jal         0x801015D0
    // 0x80800244: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_801015D0(rdram, ctx);
        goto after_0;
    // 0x80800244: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800248: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080024C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800250: lui         $a2, 0x3FA0
    ctx->r6 = S32(0X3FA0 << 16);
    // 0x80800254: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800258: beq         $t6, $at, L_8080027C
    if (ctx->r14 == ctx->r1) {
        // 0x8080025C: lui         $a3, 0x437F
        ctx->r7 = S32(0X437F << 16);
            goto L_8080027C;
    }
    // 0x8080025C: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800260: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800264: beq         $t6, $at, L_808002A0
    if (ctx->r14 == ctx->r1) {
        // 0x80800268: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808002A0;
    }
    // 0x80800268: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080026C: beq         $t6, $at, L_808002A8
    if (ctx->r14 == ctx->r1) {
        // 0x80800270: lui         $a2, 0x4070
        ctx->r6 = S32(0X4070 << 16);
            goto L_808002A8;
    }
    // 0x80800270: lui         $a2, 0x4070
    ctx->r6 = S32(0X4070 << 16);
    // 0x80800274: b           L_808002D0
    // 0x80800278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002D0;
    // 0x80800278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080027C:
    // 0x8080027C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800280: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800284: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800288: jal         0x800F10B4
    // 0x8080028C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x8080028C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800290: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800294: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80800298: b           L_808002D4
    // 0x8080029C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_808002D4;
    // 0x8080029C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_808002A0:
    // 0x808002A0: b           L_808002D0
    // 0x808002A4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_808002D0;
    // 0x808002A4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_808002A8:
    // 0x808002A8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808002AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002B0: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808002B4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002B8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808002BC: jal         0x800F10B4
    // 0x808002C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808002C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x808002C4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808002C8: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x808002CC: nop

L_808002D0:
    // 0x808002D0: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_808002D4:
    // 0x808002D4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808002D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002DC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808002E0: lhu         $t9, 0x76($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X76);
    // 0x808002E4: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1028, 0X950) << 16);
    // 0x808002E8: addiu       $t3, $t3, 0x950
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1028, 0X950));
    // 0x808002EC: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x808002F0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808002F4: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808002F8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x808002FC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800300: addiu       $t2, $t1, -0x258
    ctx->r10 = ADD32(ctx->r9, -0X258);
    // 0x80800304: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1028, 0X980) << 16);
    // 0x80800308: addiu       $a2, $a2, 0x980
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1028, 0X980));
    // 0x8080030C: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    // 0x80800310: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800314: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800318: jal         0x800F3214
    // 0x8080031C: nop

    func_800F3214(rdram, ctx);
        goto after_3;
    // 0x8080031C: nop

    after_3:
    // 0x80800320: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800324: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800328: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8080032C: jal         0x800DF5D8
    // 0x80800330: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800DF5D8(rdram, ctx);
        goto after_4;
    // 0x80800330: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x80800334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800338: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080033C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800340: jr          $ra
    // 0x80800344: nop

    return;
    // 0x80800344: nop

;}
RECOMP_FUNC void chmrsicecube_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1204, 0X99C) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x99C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1204, 0X99C));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x99C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1204, 0X99C));
;}
RECOMP_FUNC void _chdoormake_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086880: syscall     393
    recomp_syscall_handler(rdram, ctx, 0x80086880);
    return;
    // 0x80086884: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800A300C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A300C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A3018: lw          $t7, 0x124($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X124);
    // 0x800A301C: jal         0x800BC3F0
    // 0x800A3020: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_800BC3F0(rdram, ctx);
        goto after_0;
    // 0x800A3020: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x800A3024: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800A3028: lw          $t9, 0x124($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X124);
    // 0x800A302C: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x800A3030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3038: jr          $ra
    // 0x800A303C: nop

    return;
    // 0x800A303C: nop

;}
RECOMP_FUNC void func_80800FEC_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800FF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FF4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800FF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800FFC: jal         0x80100094
    // 0x80801000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801004: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801008: lw          $t6, 0xA0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA0);
    // 0x8080100C: beql        $t6, $zero, L_8080102C
    if (ctx->r14 == 0) {
        // 0x80801010: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080102C;
    }
    goto skip_0;
    // 0x80801010: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80801014: jal         0x80106790
    // 0x80801018: lw          $a0, 0xA0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XA0);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80801018: lw          $a0, 0xA0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XA0);
    after_1:
    // 0x8080101C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801020: jal         0x80101870
    // 0x80801024: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101870(rdram, ctx);
        goto after_2;
    // 0x80801024: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80801028: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8080102C:
    // 0x8080102C: jal         0x801018A4
    // 0x80801030: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_801018A4(rdram, ctx);
        goto after_3;
    // 0x80801030: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80801034: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80801038: lw          $a0, 0x9C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X9C);
    // 0x8080103C: beql        $a0, $zero, L_80801064
    if (ctx->r4 == 0) {
        // 0x80801040: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801064;
    }
    goto skip_1;
    // 0x80801040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801044: jal         0x80106790
    // 0x80801048: nop

    func_80106790(rdram, ctx);
        goto after_4;
    // 0x80801048: nop

    after_4:
    // 0x8080104C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80801050: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80801054: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x80801058: jal         0x8008A0E0
    // 0x8080105C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x8080105C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_5:
    // 0x80801060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801064:
    // 0x80801064: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801068: jr          $ra
    // 0x8080106C: nop

    return;
    // 0x8080106C: nop

;}
RECOMP_FUNC void func_80101918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101918: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8010191C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80101920: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80101924: addiu       $v0, $v1, 0x43E0
    ctx->r2 = ADD32(ctx->r3, 0X43E0);
    // 0x80101928: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8010192C: jr          $ra
    // 0x80101930: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x80101930: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void _bsvan_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084138: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084138);
    return;
    // 0x8008413C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800524_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800524: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080052C: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80800530: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800534: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800538: bnel        $t6, $at, L_80800580
    if (ctx->r14 != ctx->r1) {
        // 0x8080053C: lw          $t7, 0x15C($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X15C);
            goto L_80800580;
    }
    goto skip_0;
    // 0x8080053C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    skip_0:
    // 0x80800540: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800544: jal         0x8008CAEC
    // 0x80800548: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_isStopped(rdram, ctx);
        goto after_0;
    // 0x80800548: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x8080054C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800550: beq         $v0, $zero, L_8080057C
    if (ctx->r2 == 0) {
        // 0x80800554: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_8080057C;
    }
    // 0x80800554: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80800558: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x8080055C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800560: addiu       $a1, $zero, 0x281
    ctx->r5 = ADD32(0, 0X281);
    // 0x80800564: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800568: jal         0x8008CB3C
    // 0x8080056C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x8080056C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800570: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800574: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80800578: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
L_8080057C:
    // 0x8080057C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
L_80800580:
    // 0x80800580: bne         $t7, $zero, L_8080058C
    if (ctx->r15 != 0) {
        // 0x80800584: nop
    
            goto L_8080058C;
    }
    // 0x80800584: nop

    // 0x80800588: addiu       $a3, $zero, 0x2F
    ctx->r7 = ADD32(0, 0X2F);
L_8080058C:
    // 0x8080058C: jal         0x8009E5C8
    // 0x80800590: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800590: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
    // 0x80800594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800598: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080059C: jr          $ra
    // 0x808005A0: nop

    return;
    // 0x808005A0: nop

;}
RECOMP_FUNC void func_80029A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029A04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80029A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029A0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80029A10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80029A14: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80029A18: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80029A1C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80029A20: lw          $t7, 0x6C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X6C);
    // 0x80029A24: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80029A28: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80029A2C: lbu         $t9, 0x89($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X89);
    // 0x80029A30: lbu         $t0, 0x88($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X88);
    // 0x80029A34: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80029A38: beq         $at, $zero, L_80029A48
    if (ctx->r1 == 0) {
        // 0x80029A3C: nop
    
            goto L_80029A48;
    }
    // 0x80029A3C: nop

    // 0x80029A40: b           L_80029B08
    // 0x80029A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80029B08;
    // 0x80029A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80029A48:
    // 0x80029A48: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80029A4C: beq         $t1, $zero, L_80029AF8
    if (ctx->r9 == 0) {
        // 0x80029A50: nop
    
            goto L_80029AF8;
    }
    // 0x80029A50: nop

    // 0x80029A54: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80029A58: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80029A5C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80029A60: sw          $t3, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->r11;
    // 0x80029A64: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80029A68: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x80029A6C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80029A70: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x80029A74: bne         $t7, $zero, L_80029A8C
    if (ctx->r15 != 0) {
        // 0x80029A78: nop
    
            goto L_80029A8C;
    }
    // 0x80029A78: nop

    // 0x80029A7C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80029A80: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80029A84: b           L_80029A9C
    // 0x80029A88: sw          $t8, 0x64($t9)
    MEM_W(0X64, ctx->r25) = ctx->r24;
        goto L_80029A9C;
    // 0x80029A88: sw          $t8, 0x64($t9)
    MEM_W(0X64, ctx->r25) = ctx->r24;
L_80029A8C:
    // 0x80029A8C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80029A90: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80029A94: lw          $t2, 0x68($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X68);
    // 0x80029A98: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
L_80029A9C:
    // 0x80029A9C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80029AA0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80029AA4: sw          $t3, 0x68($t4)
    MEM_W(0X68, ctx->r12) = ctx->r11;
    // 0x80029AA8: lbu         $t5, 0x2F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2F);
    // 0x80029AAC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80029AB0: sb          $t5, 0x35($t6)
    MEM_B(0X35, ctx->r14) = ctx->r13;
    // 0x80029AB4: lbu         $t7, 0x27($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X27);
    // 0x80029AB8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80029ABC: sb          $t7, 0x36($t8)
    MEM_B(0X36, ctx->r24) = ctx->r15;
    // 0x80029AC0: lbu         $t9, 0x2B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2B);
    // 0x80029AC4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80029AC8: sb          $t9, 0x37($t1)
    MEM_B(0X37, ctx->r9) = ctx->r25;
    // 0x80029ACC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80029AD0: sw          $t0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r8;
    // 0x80029AD4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80029AD8: sw          $zero, 0x28($t2)
    MEM_W(0X28, ctx->r10) = 0;
    // 0x80029ADC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80029AE0: lbu         $t4, 0x89($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X89);
    // 0x80029AE4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80029AE8: sb          $t5, 0x89($t3)
    MEM_B(0X89, ctx->r11) = ctx->r13;
    // 0x80029AEC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80029AF0: jal         0x800E9070
    // 0x80029AF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800E9070(rdram, ctx);
        goto after_0;
    // 0x80029AF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
L_80029AF8:
    // 0x80029AF8: b           L_80029B08
    // 0x80029AFC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_80029B08;
    // 0x80029AFC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80029B00: b           L_80029B08
    // 0x80029B04: nop

        goto L_80029B08;
    // 0x80029B04: nop

L_80029B08:
    // 0x80029B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029B0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80029B10: jr          $ra
    // 0x80029B14: nop

    return;
    // 0x80029B14: nop

;}
RECOMP_FUNC void func_8080395C_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080395C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80803960: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80803964: bne         $a1, $at, L_80803974
    if (ctx->r5 != ctx->r1) {
        // 0x80803968: sw          $a2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r6;
            goto L_80803974;
    }
    // 0x80803968: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8080396C: jr          $ra
    // 0x80803970: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80803970: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80803974:
    // 0x80803974: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80803978: jr          $ra
    // 0x8080397C: nop

    return;
    // 0x8080397C: nop

;}
RECOMP_FUNC void _bskazshoesspringjump_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800835A8: syscall     67
    recomp_syscall_handler(rdram, ctx, 0x800835A8);
    return;
    // 0x800835AC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chfriesstand_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(940, 0XF58) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0xF58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(940, 0XF58));
    return;
    // 0x80800020: addiu       $v0, $v0, 0xF58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(940, 0XF58));
;}
RECOMP_FUNC void bsbfly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801878: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080187C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(96, 0X1D88) << 16);
    // 0x80801880: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801884: jr          $ra
    // 0x80801888: lw          $v0, 0x1D88($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1D88));
    return;
    // 0x80801888: lw          $v0, 0x1D88($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1D88));
;}
RECOMP_FUNC void _suegg_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A3F8: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A3F8);
    return;
    // 0x8008A3FC: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void chstatuebossbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1424, 0X780) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x780
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1424, 0X780));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x780
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1424, 0X780));
;}
RECOMP_FUNC void func_800C73A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C73A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C73A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C73AC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800C73B0: addiu       $s1, $s1, -0x5760
    ctx->r17 = ADD32(ctx->r17, -0X5760);
    // 0x800C73B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C73B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C73BC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800C73C0: jal         0x800FF000
    // 0x800C73C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FF000(rdram, ctx);
        goto after_0;
    // 0x800C73C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800C73C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C73CC: jal         0x800FC9B4
    // 0x800C73D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_800FC9B4(rdram, ctx);
        goto after_1;
    // 0x800C73D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x800C73D4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_800C73D8:
    // 0x800C73D8: jal         0x800882E8
    // 0x800C73DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gccubesearch_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x800C73DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800C73E0: beq         $v0, $zero, L_800C73FC
    if (ctx->r2 == 0) {
        // 0x800C73E4: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_800C73FC;
    }
    // 0x800C73E4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800C73E8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800C73EC: beql        $v0, $zero, L_800C7400
    if (ctx->r2 == 0) {
        // 0x800C73F0: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800C7400;
    }
    goto skip_0;
    // 0x800C73F0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_0:
    // 0x800C73F4: jalr        $v0
    // 0x800C73F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x800C73F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_800C73FC:
    // 0x800C73FC: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_800C7400:
    // 0x800C7400: addiu       $t6, $s1, 0x64
    ctx->r14 = ADD32(ctx->r17, 0X64);
    // 0x800C7404: bnel        $s0, $t6, L_800C73D8
    if (ctx->r16 != ctx->r14) {
        // 0x800C7408: lh          $a0, 0x0($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X0);
            goto L_800C73D8;
    }
    goto skip_1;
    // 0x800C7408: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    skip_1:
    // 0x800C740C: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
    // 0x800C7410: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800C7414: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    // 0x800C7418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C741C: jal         0x800C7364
    // 0x800C7420: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    func_800C7364(rdram, ctx);
        goto after_4;
    // 0x800C7420: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_4:
    // 0x800C7424: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    // 0x800C7428: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C742C: jal         0x800C7364
    // 0x800C7430: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800C7364(rdram, ctx);
        goto after_5;
    // 0x800C7430: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x800C7434: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    // 0x800C7438: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C743C: jal         0x800C7364
    // 0x800C7440: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800C7364(rdram, ctx);
        goto after_6;
    // 0x800C7440: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
    // 0x800C7444: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    // 0x800C7448: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800C744C: jal         0x800C7364
    // 0x800C7450: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800C7364(rdram, ctx);
        goto after_7;
    // 0x800C7450: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x800C7454: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x800C7458: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800C745C: jal         0x800C7364
    // 0x800C7460: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800C7364(rdram, ctx);
        goto after_8;
    // 0x800C7460: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_8:
    // 0x800C7464: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800C7468: bnel        $a3, $zero, L_800C7478
    if (ctx->r7 != 0) {
        // 0x800C746C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800C7478;
    }
    goto skip_2;
    // 0x800C746C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_2:
    // 0x800C7470: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800C7474: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_800C7478:
    // 0x800C7478: jal         0x80015178
    // 0x800C747C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80015178(rdram, ctx);
        goto after_9;
    // 0x800C747C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_9:
    // 0x800C7480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7484: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C7488: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C748C: jr          $ra
    // 0x800C7490: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C7490: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80807900_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807900: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80807904: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80807908: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080790C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80807910: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80807914: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80807918: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080791C: bnel        $t7, $at, L_808079B8
    if (ctx->r15 != ctx->r1) {
        // 0x80807920: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808079B8;
    }
    goto skip_0;
    // 0x80807920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80807924: jal         0x800D8FF8
    // 0x80807928: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80807928: nop

    after_0:
    // 0x8080792C: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80807930: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80807934: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80807938: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8080793C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80807940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807944: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80807948: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8080794C: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x80807950: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80807954: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80807958: nop

    // 0x8080795C: bc1fl       L_80807974
    if (!c1cs) {
        // 0x80807960: mfc1        $a3, $f2
        ctx->r7 = (int32_t)ctx->f2.u32l;
            goto L_80807974;
    }
    goto skip_1;
    // 0x80807960: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    skip_1:
    // 0x80807964: jal         0x80101FDC
    // 0x80807968: swc1        $f12, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f12.u32l;
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80807968: swc1        $f12, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f12.u32l;
    after_1:
    // 0x8080796C: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80807970: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
L_80807974:
    // 0x80807974: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80807978: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080797C: jal         0x800EFE50
    // 0x80807980: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EFE50(rdram, ctx);
        goto after_2;
    // 0x80807980: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_2:
    // 0x80807984: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80807988: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x8080798C: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x80807990: jal         0x800F16AC
    // 0x80807994: lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X34);
    func_800F16AC(rdram, ctx);
        goto after_3;
    // 0x80807994: lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x80807998: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080799C: jal         0x800E39D8
    // 0x808079A0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800E39D8(rdram, ctx);
        goto after_4;
    // 0x808079A0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x808079A4: addiu       $a0, $zero, 0x4AB
    ctx->r4 = ADD32(0, 0X4AB);
    // 0x808079A8: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x808079AC: jal         0x80101180
    // 0x808079B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x808079B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x808079B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808079B8:
    // 0x808079B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808079BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808079C0: jr          $ra
    // 0x808079C4: nop

    return;
    // 0x808079C4: nop

;}
RECOMP_FUNC void func_80809C30_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80809C34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80809C38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80809C3C: jal         0x80093DF4
    // 0x80809C40: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80093DF4(rdram, ctx);
        goto after_0;
    // 0x80809C40: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80809C44: beql        $v0, $zero, L_80809C84
    if (ctx->r2 == 0) {
        // 0x80809C48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80809C84;
    }
    goto skip_0;
    // 0x80809C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80809C4C: jal         0x800936F4
    // 0x80809C50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800936F4(rdram, ctx);
        goto after_1;
    // 0x80809C50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80809C54: beql        $v0, $zero, L_80809C84
    if (ctx->r2 == 0) {
        // 0x80809C58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80809C84;
    }
    goto skip_1;
    // 0x80809C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80809C5C: jal         0x8009239C
    // 0x80809C60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8009239C(rdram, ctx);
        goto after_2;
    // 0x80809C60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80809C64: beql        $v0, $zero, L_80809C84
    if (ctx->r2 == 0) {
        // 0x80809C68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80809C84;
    }
    goto skip_2;
    // 0x80809C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80809C6C: jal         0x800A7180
    // 0x80809C70: nop

    func_800A7180(rdram, ctx);
        goto after_3;
    // 0x80809C70: nop

    after_3:
    // 0x80809C74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80809C78: jal         0x80093E18
    // 0x80809C7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80093E18(rdram, ctx);
        goto after_4;
    // 0x80809C7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80809C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80809C84:
    // 0x80809C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80809C88: jr          $ra
    // 0x80809C8C: nop

    return;
    // 0x80809C8C: nop

;}
RECOMP_FUNC void _sucoasterfly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EC0: syscall     813
    recomp_syscall_handler(rdram, ctx, 0x80089EC0);
    return;
    // 0x80089EC4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800F80E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F80E4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F80E8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800F80EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F80F0: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x800F80F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F80F8: beq         $a1, $zero, L_800F8108
    if (ctx->r5 == 0) {
        // 0x800F80FC: lw          $a3, 0x5490($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X5490);
            goto L_800F8108;
    }
    // 0x800F80FC: lw          $a3, 0x5490($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5490);
    // 0x800F8100: b           L_800F810C
    // 0x800F8104: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800F810C;
    // 0x800F8104: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800F8108:
    // 0x800F8108: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800F810C:
    // 0x800F810C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F8110: jal         0x800947EC
    // 0x800F8114: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_0;
    // 0x800F8114: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800F8118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F811C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8120: jr          $ra
    // 0x800F8124: nop

    return;
    // 0x800F8124: nop

;}
RECOMP_FUNC void bakaztorpedo_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800068: lw          $t6, 0xB0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB0);
    // 0x8080006C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800070: nop

    // 0x80800074: swc1        $f4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f4.u32l;
    // 0x80800078: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x8080007C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800080: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80800084: lw          $t7, 0xB0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB0);
    // 0x80800088: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x8080008C: jal         0x8009EA88
    // 0x80800090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009EA88(rdram, ctx);
        goto after_0;
    // 0x80800090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800094: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800098: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080009C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808000A0: lw          $t8, 0xB0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XB0);
    // 0x808000A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(544, 0X420) << 16);
    // 0x808000A8: addiu       $a2, $a2, 0x420
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(544, 0X420));
    // 0x808000AC: swc1        $f0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f0.u32l;
    // 0x808000B0: lw          $t0, 0xB0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XB0);
    // 0x808000B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000B8: sb          $t9, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r25;
    // 0x808000BC: lw          $t1, 0xB0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XB0);
    // 0x808000C0: swc1        $f6, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f6.u32l;
    // 0x808000C4: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x808000C8: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x808000CC: jal         0x8009D454
    // 0x808000D0: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    func_8009D454(rdram, ctx);
        goto after_1;
    // 0x808000D0: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    after_1:
    // 0x808000D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000D8: lw          $t2, 0xB0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XB0);
    // 0x808000DC: sb          $v0, 0x1C($t2)
    MEM_B(0X1C, ctx->r10) = ctx->r2;
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void ncbajig_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808000CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D8: jal         0x80800028
    // 0x808000DC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_80800028_ncbajig(rdram, ctx);
        goto after_0;
    // 0x808000DC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_0:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x801107F0
    // 0x808000E8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x808000E8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x808000EC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808000F0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808000F4: jal         0x800EFB24
    // 0x808000F8: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x808000F8: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_2:
    // 0x808000FC: jal         0x800EEF94
    // 0x80800100: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_800EEF94(rdram, ctx);
        goto after_3;
    // 0x80800100: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_3:
    // 0x80800104: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800108: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8080010C: jal         0x800F1A88
    // 0x80800110: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F1A88(rdram, ctx);
        goto after_4;
    // 0x80800110: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800118: jal         0x80115358
    // 0x8080011C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80115358(rdram, ctx);
        goto after_5;
    // 0x8080011C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x80800120: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x80800124: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800128: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8080012C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800130: nop

    // 0x80800134: bc1fl       L_80800144
    if (!c1cs) {
        // 0x80800138: lwc1        $f0, 0x4($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
            goto L_80800144;
    }
    goto skip_0;
    // 0x80800138: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x8080013C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80800140: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
L_80800144:
    // 0x80800144: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800150: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800154: jal         0x80115828
    // 0x80800158: nop

    func_80115828(rdram, ctx);
        goto after_6;
    // 0x80800158: nop

    after_6:
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: jal         0x80115750
    // 0x80800164: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80115750(rdram, ctx);
        goto after_7;
    // 0x80800164: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80800168: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800170: jal         0x80112C3C
    // 0x80800174: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80112C3C(rdram, ctx);
        goto after_8;
    // 0x80800174: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x80800178: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8080017C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800180: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800184: jal         0x800EEBF0
    // 0x80800188: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_800EEBF0(rdram, ctx);
        goto after_9;
    // 0x80800188: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_9:
    // 0x8080018C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800190: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80800194: jal         0x800EE780
    // 0x80800198: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_800EE780(rdram, ctx);
        goto after_10;
    // 0x80800198: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_10:
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: jal         0x80111CC8
    // 0x808001A4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80111CC8(rdram, ctx);
        goto after_11;
    // 0x808001A4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_11:
    // 0x808001A8: beql        $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001DC;
    }
    goto skip_1;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808001B0: jal         0x801138A0
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138A0(rdram, ctx);
        goto after_12;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001B8: beql        $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001DC;
    }
    goto skip_2;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808001C0: jal         0x801138F4
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_13;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001C8: beql        $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001DC;
    }
    goto skip_3;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x808001D0: jal         0x80110F44
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110F44(rdram, ctx);
        goto after_14;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001DC:
    // 0x808001DC: jal         0x80800008
    // 0x808001E0: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_80800008_ncbajig(rdram, ctx);
        goto after_15;
    // 0x808001E0: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_15:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808001EC: jal         0x80110A68
    // 0x808001F0: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_80110A68(rdram, ctx);
        goto after_16;
    // 0x808001F0: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_16:
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x80110790
    // 0x808001FC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80110790(rdram, ctx);
        goto after_17;
    // 0x808001FC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_17:
    // 0x80800200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800204: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800208: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8080020C: jr          $ra
    // 0x80800210: nop

    return;
    // 0x80800210: nop

    // 0x80800214: nop

    // 0x80800218: nop

    // 0x8080021C: nop

;}
RECOMP_FUNC void func_800EEAA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEAA4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EEAA8: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EEAAC: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EEAB0: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EEAB4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800EEAB8: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EEABC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800EEAC0: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EEAC4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800EEAC8: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800EEACC: jr          $ra
    // 0x800EEAD0: add.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f4.fl;
    return;
    // 0x800EEAD0: add.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f4.fl;
;}
RECOMP_FUNC void func_80801A6C_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801A70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801A78: jal         0x80801840
    // 0x80801A7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80801840_chevilspirit(rdram, ctx);
        goto after_0;
    // 0x80801A7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801A80: beq         $v0, $zero, L_80801AEC
    if (ctx->r2 == 0) {
        // 0x80801A84: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801AEC;
    }
    // 0x80801A84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801A88: jal         0x80100094
    // 0x80801A8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801A8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801A90: jal         0x8008A040
    // 0x80801A94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80801A94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80801A98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801A9C: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x80801AA0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80801AA4: jal         0x8010108C
    // 0x80801AA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8010108C(rdram, ctx);
        goto after_3;
    // 0x80801AA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80801AAC: blez        $v0, L_80801ABC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801AB0: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_80801ABC;
    }
    // 0x80801AB0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80801AB4: b           L_80801AF0
    // 0x80801AB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801AF0;
    // 0x80801AB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801ABC:
    // 0x80801ABC: lbu         $t6, 0x64($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X64);
    // 0x80801AC0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801AC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801AC8: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x80801ACC: sb          $t7, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r15;
    // 0x80801AD0: jal         0x8010108C
    // 0x80801AD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_4;
    // 0x80801AD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80801AD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801ADC: jal         0x80100094
    // 0x80801AE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x80801AE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80801AE4: jal         0x8008A020
    // 0x80801AE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80801AE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
L_80801AEC:
    // 0x80801AEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801AF0:
    // 0x80801AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801AF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801AF8: jr          $ra
    // 0x80801AFC: nop

    return;
    // 0x80801AFC: nop

;}
RECOMP_FUNC void func_80800A4C_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A4C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800A50: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800A54: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80800A58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A5C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800A60: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800A64: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800A68: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800A6C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800A70: jal         0x800EFB24
    // 0x80800A74: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x80800A74: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_0:
    // 0x80800A78: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800A7C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800A80: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(924, 0X2198) << 16);
    // 0x80800A84: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80800A88: lwc1        $f10, 0x2198($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(924, 0X2198));
    // 0x80800A8C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800A90: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80800A94: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80800A98: add.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800A9C: c.le.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl <= ctx->f20.fl;
    // 0x80800AA0: nop

    // 0x80800AA4: bc1tl       L_80800BEC
    if (c1cs) {
        // 0x80800AA8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800BEC;
    }
    goto skip_0;
    // 0x80800AA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800AAC: jal         0x8002DCA0
    // 0x80800AB0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80800AB0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80800AB4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800AB8: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800ABC: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800AC0: jal         0x80013B70
    // 0x80800AC4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_80013B70(rdram, ctx);
        goto after_2;
    // 0x80800AC4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x80800AC8: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800ACC: jal         0x800136E4
    // 0x80800AD0: sub.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x80800AD0: sub.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
    after_3:
    // 0x80800AD4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800AD8: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x80800ADC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800AE0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800AE4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800AE8: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    // 0x80800AEC: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800AF0: jal         0x800F10B4
    // 0x80800AF4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800AF4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80800AF8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80800AFC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800B00: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800B04: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x80800B08: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800B0C: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80800B10: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800B14: nop

    // 0x80800B18: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800B1C: beql        $t7, $zero, L_80800B6C
    if (ctx->r15 == 0) {
        // 0x80800B20: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_80800B6C;
    }
    goto skip_1;
    // 0x80800B20: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x80800B24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800B28: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800B2C: sub.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80800B30: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800B34: nop

    // 0x80800B38: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800B3C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800B40: nop

    // 0x80800B44: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800B48: bne         $t7, $zero, L_80800B60
    if (ctx->r15 != 0) {
        // 0x80800B4C: nop
    
            goto L_80800B60;
    }
    // 0x80800B4C: nop

    // 0x80800B50: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80800B54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800B58: b           L_80800B78
    // 0x80800B5C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80800B78;
    // 0x80800B5C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80800B60:
    // 0x80800B60: b           L_80800B78
    // 0x80800B64: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80800B78;
    // 0x80800B64: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800B68: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_80800B6C:
    // 0x80800B6C: nop

    // 0x80800B70: bltz        $t7, L_80800B60
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800B74: nop
    
            goto L_80800B60;
    }
    // 0x80800B74: nop

L_80800B78:
    // 0x80800B78: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800B7C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80800B80: beq         $t8, $zero, L_80800BE8
    if (ctx->r24 == 0) {
        // 0x80800B84: sb          $t7, 0x3($v0)
        MEM_B(0X3, ctx->r2) = ctx->r15;
            goto L_80800BE8;
    }
    // 0x80800B84: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
    // 0x80800B88: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(924, 0X219C) << 16);
    // 0x80800B8C: lwc1        $f6, 0x219C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(924, 0X219C));
    // 0x80800B90: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800B94: mul.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80800B98: jal         0x800137F4
    // 0x80800B9C: nop

    func_800137F4(rdram, ctx);
        goto after_5;
    // 0x80800B9C: nop

    after_5:
    // 0x80800BA0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80800BA4: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80800BA8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800BAC: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80800BB0: jal         0x80013788
    // 0x80800BB4: sh          $t0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r8;
    func_80013788(rdram, ctx);
        goto after_6;
    // 0x80800BB4: sh          $t0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r8;
    after_6:
    // 0x80800BB8: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x80800BBC: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80800BC0: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80800BC4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800BC8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80800BCC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80800BD0: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80800BD4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800BD8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800BDC: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80800BE0: jal         0x80800BFC
    // 0x80800BE4: sh          $t2, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r10;
    func_80800BFC_chevilspirit(rdram, ctx);
        goto after_7;
    // 0x80800BE4: sh          $t2, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r10;
    after_7:
L_80800BE8:
    // 0x80800BE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800BEC:
    // 0x80800BEC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800BF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800BF4: jr          $ra
    // 0x80800BF8: nop

    return;
    // 0x80800BF8: nop

;}
RECOMP_FUNC void func_80094B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094B14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80094B18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094B1C: jal         0x80094510
    // 0x80094B20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80094510(rdram, ctx);
        goto after_0;
    // 0x80094B20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80094B24: jal         0x800883E0
    // 0x80094B28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcegg_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80094B28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80094B2C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80094B30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80094B34: jal         0x80095738
    // 0x80094B38: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x80094B38: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_2:
    // 0x80094B3C: bne         $v0, $zero, L_80094B64
    if (ctx->r2 != 0) {
        // 0x80094B40: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80094B64;
    }
    // 0x80094B40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80094B44: jal         0x80094348
    // 0x80094B48: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80094348(rdram, ctx);
        goto after_3;
    // 0x80094B48: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80094B4C: bne         $v0, $zero, L_80094B7C
    if (ctx->r2 != 0) {
        // 0x80094B50: nop
    
            goto L_80094B7C;
    }
    // 0x80094B50: nop

    // 0x80094B54: jal         0x800D1C38
    // 0x80094B58: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800D1C38(rdram, ctx);
        goto after_4;
    // 0x80094B58: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x80094B5C: beq         $v0, $zero, L_80094B7C
    if (ctx->r2 == 0) {
        // 0x80094B60: nop
    
            goto L_80094B7C;
    }
    // 0x80094B60: nop

L_80094B64:
    // 0x80094B64: jal         0x800D1824
    // 0x80094B68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800D1824(rdram, ctx);
        goto after_5;
    // 0x80094B68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_5:
    // 0x80094B6C: jal         0x800FC660
    // 0x80094B70: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC660(rdram, ctx);
        goto after_6;
    // 0x80094B70: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_6:
    // 0x80094B74: b           L_80094BB0
    // 0x80094B78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80094BB0;
    // 0x80094B78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80094B7C:
    // 0x80094B7C: jal         0x80094510
    // 0x80094B80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80094510(rdram, ctx);
        goto after_7;
    // 0x80094B80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x80094B84: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80094B88: bnel        $v0, $at, L_80094BB0
    if (ctx->r2 != ctx->r1) {
        // 0x80094B8C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80094BB0;
    }
    goto skip_0;
    // 0x80094B8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80094B90: jal         0x800878A0
    // 0x80094B94: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80094B94: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_8:
    // 0x80094B98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094B9C: beql        $v0, $at, L_80094BB0
    if (ctx->r2 == ctx->r1) {
        // 0x80094BA0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80094BB0;
    }
    goto skip_1;
    // 0x80094BA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80094BA4: b           L_80094BB0
    // 0x80094BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80094BB0;
    // 0x80094BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80094BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80094BB0:
    // 0x80094BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094BB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80094BB8: jr          $ra
    // 0x80094BBC: nop

    return;
    // 0x80094BBC: nop

;}
RECOMP_FUNC void _Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030B30: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80030B34: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80030B38: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80030B3C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80030B40: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80030B44: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80030B48: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80030B4C: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x80030B50: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x80030B54: lui         $s6, 0x8004
    ctx->r22 = S32(0X8004 << 16);
    // 0x80030B58: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x80030B5C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80030B60: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80030B64: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80030B68: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80030B6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80030B70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80030B74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80030B78: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x80030B7C: sw          $zero, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = 0;
    // 0x80030B80: addiu       $s7, $s7, 0x1430
    ctx->r23 = ADD32(ctx->r23, 0X1430);
    // 0x80030B84: addiu       $s6, $s6, 0x1E44
    ctx->r22 = ADD32(ctx->r22, 0X1E44);
    // 0x80030B88: addiu       $s5, $s5, 0x1454
    ctx->r21 = ADD32(ctx->r21, 0X1454);
    // 0x80030B8C: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
L_80030B90:
    // 0x80030B90: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80030B94: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80030B98: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x80030B9C: beq         $v0, $zero, L_80030BC4
    if (ctx->r2 == 0) {
        // 0x80030BA0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80030BC4;
    }
    // 0x80030BA0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80030BA4: beql        $v1, $v0, L_80030BC8
    if (ctx->r3 == ctx->r2) {
        // 0x80030BA8: subu        $v0, $s2, $a3
        ctx->r2 = SUB32(ctx->r18, ctx->r7);
            goto L_80030BC8;
    }
    goto skip_0;
    // 0x80030BA8: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
    skip_0:
    // 0x80030BAC: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
L_80030BB0:
    // 0x80030BB0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80030BB4: beq         $v0, $zero, L_80030BC4
    if (ctx->r2 == 0) {
        // 0x80030BB8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80030BC4;
    }
    // 0x80030BB8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80030BBC: bnel        $v1, $v0, L_80030BB0
    if (ctx->r3 != ctx->r2) {
        // 0x80030BC0: lbu         $v0, 0x1($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X1);
            goto L_80030BB0;
    }
    goto skip_1;
    // 0x80030BC0: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    skip_1:
L_80030BC4:
    // 0x80030BC4: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
L_80030BC8:
    // 0x80030BC8: blez        $v0, L_80030C00
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80030BCC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80030C00;
    }
    // 0x80030BCC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80030BD0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80030BD4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80030BD8: jalr        $s4
    // 0x80030BDC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x80030BDC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_0:
    // 0x80030BE0: beq         $v0, $zero, L_80030BF8
    if (ctx->r2 == 0) {
        // 0x80030BE4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80030BF8;
    }
    // 0x80030BE4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80030BE8: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x80030BEC: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80030BF0: b           L_80030C00
    // 0x80030BF4: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_80030C00;
    // 0x80030BF4: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_80030BF8:
    // 0x80030BF8: b           L_80031148
    // 0x80030BFC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80031148;
    // 0x80030BFC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80030C00:
    // 0x80030C00: bne         $s0, $zero, L_80030C10
    if (ctx->r16 != 0) {
        // 0x80030C04: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80030C10;
    }
    // 0x80030C04: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80030C08: b           L_80031148
    // 0x80030C0C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80031148;
    // 0x80030C0C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80030C10:
    // 0x80030C10: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
    // 0x80030C14: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x80030C18: jal         0x80032A70
    // 0x80030C1C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    strchr_recomp(rdram, ctx);
        goto after_1;
    // 0x80030C1C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x80030C20: beq         $v0, $zero, L_80030C60
    if (ctx->r2 == 0) {
        // 0x80030C24: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80030C60;
    }
    // 0x80030C24: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80030C28:
    // 0x80030C28: subu        $t9, $s0, $s6
    ctx->r25 = SUB32(ctx->r16, ctx->r22);
    // 0x80030C2C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80030C30: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80030C34: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80030C38: lw          $t1, 0x1E4C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1E4C);
    // 0x80030C3C: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x80030C40: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80030C44: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80030C48: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x80030C4C: sw          $t2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r10;
    // 0x80030C50: jal         0x80032A70
    // 0x80030C54: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    strchr_recomp(rdram, ctx);
        goto after_2;
    // 0x80030C54: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_2:
    // 0x80030C58: bne         $v0, $zero, L_80030C28
    if (ctx->r2 != 0) {
        // 0x80030C5C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80030C28;
    }
    // 0x80030C5C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80030C60:
    // 0x80030C60: lbu         $t3, 0x0($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X0);
    // 0x80030C64: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80030C68: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x80030C6C: bne         $v0, $t3, L_80030CB4
    if (ctx->r2 != ctx->r11) {
        // 0x80030C70: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80030CB4;
    }
    // 0x80030C70: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80030C74: addiu       $t5, $t4, 0x3
    ctx->r13 = ADD32(ctx->r12, 0X3);
    // 0x80030C78: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80030C7C: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x80030C80: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x80030C84: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x80030C88: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80030C8C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80030C90: bgez        $t9, L_80030CAC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80030C94: sw          $t9, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r25;
            goto L_80030CAC;
    }
    // 0x80030C94: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x80030C98: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x80030C9C: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x80030CA0: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x80030CA4: ori         $t1, $t8, 0x4
    ctx->r9 = ctx->r24 | 0X4;
    // 0x80030CA8: sw          $t1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r9;
L_80030CAC:
    // 0x80030CAC: b           L_80030D10
    // 0x80030CB0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_80030D10;
    // 0x80030CB0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_80030CB4:
    // 0x80030CB4: sw          $zero, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = 0;
    // 0x80030CB8: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x80030CBC: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80030CC0: bne         $at, $zero, L_80030D10
    if (ctx->r1 != 0) {
        // 0x80030CC4: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_80030D10;
    }
    // 0x80030CC4: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80030CC8: beql        $at, $zero, L_80030D14
    if (ctx->r1 == 0) {
        // 0x80030CCC: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80030D14;
    }
    goto skip_2;
    // 0x80030CCC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_2:
    // 0x80030CD0: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
L_80030CD4:
    // 0x80030CD4: slti        $at, $t2, 0x3E7
    ctx->r1 = SIGNED(ctx->r10) < 0X3E7 ? 1 : 0;
    // 0x80030CD8: beql        $at, $zero, L_80030CF8
    if (ctx->r1 == 0) {
        // 0x80030CDC: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_80030CF8;
    }
    goto skip_3;
    // 0x80030CDC: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_3:
    // 0x80030CE0: multu       $t2, $fp
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030CE4: mflo        $t3
    ctx->r11 = lo;
    // 0x80030CE8: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x80030CEC: addiu       $t5, $t4, -0x30
    ctx->r13 = ADD32(ctx->r12, -0X30);
    // 0x80030CF0: sw          $t5, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r13;
    // 0x80030CF4: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_80030CF8:
    // 0x80030CF8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80030CFC: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80030D00: bne         $at, $zero, L_80030D10
    if (ctx->r1 != 0) {
        // 0x80030D04: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_80030D10;
    }
    // 0x80030D04: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80030D08: bnel        $at, $zero, L_80030CD4
    if (ctx->r1 != 0) {
        // 0x80030D0C: lw          $t2, 0xC8($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XC8);
            goto L_80030CD4;
    }
    goto skip_4;
    // 0x80030D0C: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    skip_4:
L_80030D10:
    // 0x80030D10: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_80030D14:
    // 0x80030D14: beq         $a1, $at, L_80030D28
    if (ctx->r5 == ctx->r1) {
        // 0x80030D18: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_80030D28;
    }
    // 0x80030D18: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80030D1C: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x80030D20: b           L_80030DBC
    // 0x80030D24: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_80030DBC;
    // 0x80030D24: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_80030D28:
    // 0x80030D28: lbu         $t6, 0x1($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X1);
    // 0x80030D2C: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x80030D30: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80030D34: bne         $v0, $t6, L_80030D60
    if (ctx->r2 != ctx->r14) {
        // 0x80030D38: addiu       $t0, $t9, 0x3
        ctx->r8 = ADD32(ctx->r25, 0X3);
            goto L_80030D60;
    }
    // 0x80030D38: addiu       $t0, $t9, 0x3
    ctx->r8 = ADD32(ctx->r25, 0X3);
    // 0x80030D3C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80030D40: and         $t8, $t0, $at
    ctx->r24 = ctx->r8 & ctx->r1;
    // 0x80030D44: addiu       $t1, $t8, 0x4
    ctx->r9 = ADD32(ctx->r24, 0X4);
    // 0x80030D48: sw          $t1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r9;
    // 0x80030D4C: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x80030D50: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80030D54: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    // 0x80030D58: b           L_80030DBC
    // 0x80030D5C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_80030DBC;
    // 0x80030D5C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_80030D60:
    // 0x80030D60: sw          $zero, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = 0;
    // 0x80030D64: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x80030D68: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80030D6C: bne         $at, $zero, L_80030DBC
    if (ctx->r1 != 0) {
        // 0x80030D70: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_80030DBC;
    }
    // 0x80030D70: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80030D74: beq         $at, $zero, L_80030DBC
    if (ctx->r1 == 0) {
        // 0x80030D78: nop
    
            goto L_80030DBC;
    }
    // 0x80030D78: nop

    // 0x80030D7C: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
L_80030D80:
    // 0x80030D80: slti        $at, $t3, 0x3E7
    ctx->r1 = SIGNED(ctx->r11) < 0X3E7 ? 1 : 0;
    // 0x80030D84: beql        $at, $zero, L_80030DA4
    if (ctx->r1 == 0) {
        // 0x80030D88: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_80030DA4;
    }
    goto skip_5;
    // 0x80030D88: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_5:
    // 0x80030D8C: multu       $t3, $fp
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80030D90: mflo        $t4
    ctx->r12 = lo;
    // 0x80030D94: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x80030D98: addiu       $t7, $t5, -0x30
    ctx->r15 = ADD32(ctx->r13, -0X30);
    // 0x80030D9C: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x80030DA0: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_80030DA4:
    // 0x80030DA4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80030DA8: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80030DAC: bne         $at, $zero, L_80030DBC
    if (ctx->r1 != 0) {
        // 0x80030DB0: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_80030DBC;
    }
    // 0x80030DB0: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80030DB4: bnel        $at, $zero, L_80030D80
    if (ctx->r1 != 0) {
        // 0x80030DB8: lw          $t3, 0xC4($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XC4);
            goto L_80030D80;
    }
    goto skip_6;
    // 0x80030DB8: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    skip_6:
L_80030DBC:
    // 0x80030DBC: jal         0x80032A70
    // 0x80030DC0: addiu       $a0, $a0, 0x1E40
    ctx->r4 = ADD32(ctx->r4, 0X1E40);
    strchr_recomp(rdram, ctx);
        goto after_3;
    // 0x80030DC0: addiu       $a0, $a0, 0x1E40
    ctx->r4 = ADD32(ctx->r4, 0X1E40);
    after_3:
    // 0x80030DC4: beq         $v0, $zero, L_80030DDC
    if (ctx->r2 == 0) {
        // 0x80030DC8: addiu       $a0, $sp, 0xA0
        ctx->r4 = ADD32(ctx->r29, 0XA0);
            goto L_80030DDC;
    }
    // 0x80030DC8: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x80030DCC: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x80030DD0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80030DD4: b           L_80030DE0
    // 0x80030DD8: sb          $t6, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r14;
        goto L_80030DE0;
    // 0x80030DD8: sb          $t6, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r14;
L_80030DDC:
    // 0x80030DDC: sb          $zero, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = 0;
L_80030DE0:
    // 0x80030DE0: lbu         $t9, 0xD4($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XD4);
    // 0x80030DE4: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x80030DE8: addiu       $a1, $sp, 0xE4
    ctx->r5 = ADD32(ctx->r29, 0XE4);
    // 0x80030DEC: bne         $v0, $t9, L_80030E0C
    if (ctx->r2 != ctx->r25) {
        // 0x80030DF0: addiu       $a3, $sp, 0x74
        ctx->r7 = ADD32(ctx->r29, 0X74);
            goto L_80030E0C;
    }
    // 0x80030DF0: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    // 0x80030DF4: lbu         $t0, 0x0($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X0);
    // 0x80030DF8: addiu       $t1, $zero, 0x4C
    ctx->r9 = ADD32(0, 0X4C);
    // 0x80030DFC: bne         $v0, $t0, L_80030E0C
    if (ctx->r2 != ctx->r8) {
        // 0x80030E00: nop
    
            goto L_80030E0C;
    }
    // 0x80030E00: nop

    // 0x80030E04: sb          $t1, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r9;
    // 0x80030E08: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80030E0C:
    // 0x80030E0C: jal         0x80031178
    // 0x80030E10: lbu         $a2, 0x0($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X0);
    static_13_80031178(rdram, ctx);
        goto after_4;
    // 0x80030E10: lbu         $a2, 0x0($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X0);
    after_4:
    // 0x80030E14: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x80030E18: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80030E1C: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x80030E20: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x80030E24: subu        $t3, $t8, $t2
    ctx->r11 = SUB32(ctx->r24, ctx->r10);
    // 0x80030E28: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x80030E2C: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80030E30: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x80030E34: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x80030E38: lw          $t4, 0xD0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD0);
    // 0x80030E3C: subu        $t6, $t5, $t7
    ctx->r14 = SUB32(ctx->r13, ctx->r15);
    // 0x80030E40: subu        $t0, $t6, $t9
    ctx->r8 = SUB32(ctx->r14, ctx->r25);
    // 0x80030E44: subu        $t8, $t0, $t1
    ctx->r24 = SUB32(ctx->r8, ctx->r9);
    // 0x80030E48: subu        $t3, $t8, $t2
    ctx->r11 = SUB32(ctx->r24, ctx->r10);
    // 0x80030E4C: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x80030E50: bne         $t5, $zero, L_80030EC0
    if (ctx->r13 != 0) {
        // 0x80030E54: sw          $t3, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r11;
            goto L_80030EC0;
    }
    // 0x80030E54: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x80030E58: slt         $t7, $zero, $t3
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80030E5C: beql        $t7, $zero, L_80030EC4
    if (ctx->r15 == 0) {
        // 0x80030E60: lw          $t0, 0xAC($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XAC);
            goto L_80030EC4;
    }
    goto skip_7;
    // 0x80030E60: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    skip_7:
    // 0x80030E64: beq         $t7, $zero, L_80030EC0
    if (ctx->r15 == 0) {
        // 0x80030E68: or          $s1, $t3, $zero
        ctx->r17 = ctx->r11 | 0;
            goto L_80030EC0;
    }
    // 0x80030E68: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80030E6C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80030E70:
    // 0x80030E70: bne         $at, $zero, L_80030E80
    if (ctx->r1 != 0) {
        // 0x80030E74: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80030E80;
    }
    // 0x80030E74: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80030E78: b           L_80030E80
    // 0x80030E7C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80030E80;
    // 0x80030E7C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80030E80:
    // 0x80030E80: blez        $s0, L_80030EB4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80030E84: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80030EB4;
    }
    // 0x80030E84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80030E88: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80030E8C: jalr        $s4
    // 0x80030E90: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x80030E90: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80030E94: beq         $v0, $zero, L_80030EAC
    if (ctx->r2 == 0) {
        // 0x80030E98: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80030EAC;
    }
    // 0x80030E98: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80030E9C: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x80030EA0: addu        $t9, $t6, $s0
    ctx->r25 = ADD32(ctx->r14, ctx->r16);
    // 0x80030EA4: b           L_80030EB4
    // 0x80030EA8: sw          $t9, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r25;
        goto L_80030EB4;
    // 0x80030EA8: sw          $t9, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r25;
L_80030EAC:
    // 0x80030EAC: b           L_80031148
    // 0x80030EB0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80031148;
    // 0x80030EB0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80030EB4:
    // 0x80030EB4: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80030EB8: bgtzl       $s1, L_80030E70
    if (SIGNED(ctx->r17) > 0) {
        // 0x80030EBC: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80030E70;
    }
    goto skip_8;
    // 0x80030EBC: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_8:
L_80030EC0:
    // 0x80030EC0: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
L_80030EC4:
    // 0x80030EC4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80030EC8: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80030ECC: blezl       $t0, L_80030F04
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80030ED0: lw          $t4, 0xB0($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XB0);
            goto L_80030F04;
    }
    goto skip_9;
    // 0x80030ED0: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    skip_9:
    // 0x80030ED4: jalr        $s4
    // 0x80030ED8: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_6;
    // 0x80030ED8: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_6:
    // 0x80030EDC: beq         $v0, $zero, L_80030EF8
    if (ctx->r2 == 0) {
        // 0x80030EE0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80030EF8;
    }
    // 0x80030EE0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80030EE4: lw          $t1, 0xCC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XCC);
    // 0x80030EE8: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x80030EEC: addu        $t2, $t1, $t8
    ctx->r10 = ADD32(ctx->r9, ctx->r24);
    // 0x80030EF0: b           L_80030F00
    // 0x80030EF4: sw          $t2, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r10;
        goto L_80030F00;
    // 0x80030EF4: sw          $t2, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r10;
L_80030EF8:
    // 0x80030EF8: b           L_80031148
    // 0x80030EFC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80031148;
    // 0x80030EFC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80030F00:
    // 0x80030F00: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
L_80030F04:
    // 0x80030F04: slt         $t5, $zero, $t4
    ctx->r13 = SIGNED(0) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80030F08: beql        $t5, $zero, L_80030F70
    if (ctx->r13 == 0) {
        // 0x80030F0C: lw          $t6, 0xB4($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XB4);
            goto L_80030F70;
    }
    goto skip_10;
    // 0x80030F0C: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    skip_10:
    // 0x80030F10: beq         $t5, $zero, L_80030F6C
    if (ctx->r13 == 0) {
        // 0x80030F14: or          $s1, $t4, $zero
        ctx->r17 = ctx->r12 | 0;
            goto L_80030F6C;
    }
    // 0x80030F14: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x80030F18: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80030F1C:
    // 0x80030F1C: bne         $at, $zero, L_80030F2C
    if (ctx->r1 != 0) {
        // 0x80030F20: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80030F2C;
    }
    // 0x80030F20: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80030F24: b           L_80030F2C
    // 0x80030F28: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80030F2C;
    // 0x80030F28: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80030F2C:
    // 0x80030F2C: blez        $s0, L_80030F60
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80030F30: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80030F60;
    }
    // 0x80030F30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80030F34: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80030F38: jalr        $s4
    // 0x80030F3C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_7;
    // 0x80030F3C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80030F40: beq         $v0, $zero, L_80030F58
    if (ctx->r2 == 0) {
        // 0x80030F44: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80030F58;
    }
    // 0x80030F44: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80030F48: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x80030F4C: addu        $t7, $t3, $s0
    ctx->r15 = ADD32(ctx->r11, ctx->r16);
    // 0x80030F50: b           L_80030F60
    // 0x80030F54: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_80030F60;
    // 0x80030F54: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_80030F58:
    // 0x80030F58: b           L_80031148
    // 0x80030F5C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80031148;
    // 0x80030F5C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80030F60:
    // 0x80030F60: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80030F64: bgtzl       $s1, L_80030F1C
    if (SIGNED(ctx->r17) > 0) {
        // 0x80030F68: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80030F1C;
    }
    goto skip_11;
    // 0x80030F68: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_11:
L_80030F6C:
    // 0x80030F6C: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
L_80030F70:
    // 0x80030F70: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80030F74: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x80030F78: blezl       $t6, L_80030FB0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80030F7C: lw          $t8, 0xB8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XB8);
            goto L_80030FB0;
    }
    goto skip_12;
    // 0x80030F7C: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    skip_12:
    // 0x80030F80: jalr        $s4
    // 0x80030F84: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_8;
    // 0x80030F84: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_8:
    // 0x80030F88: beq         $v0, $zero, L_80030FA4
    if (ctx->r2 == 0) {
        // 0x80030F8C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80030FA4;
    }
    // 0x80030F8C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80030F90: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x80030F94: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x80030F98: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80030F9C: b           L_80030FAC
    // 0x80030FA0: sw          $t1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r9;
        goto L_80030FAC;
    // 0x80030FA0: sw          $t1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r9;
L_80030FA4:
    // 0x80030FA4: b           L_80031148
    // 0x80030FA8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80031148;
    // 0x80030FA8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80030FAC:
    // 0x80030FAC: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
L_80030FB0:
    // 0x80030FB0: slt         $t2, $zero, $t8
    ctx->r10 = SIGNED(0) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80030FB4: beql        $t2, $zero, L_8003101C
    if (ctx->r10 == 0) {
        // 0x80030FB8: lw          $t3, 0xBC($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XBC);
            goto L_8003101C;
    }
    goto skip_13;
    // 0x80030FB8: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    skip_13:
    // 0x80030FBC: beq         $t2, $zero, L_80031018
    if (ctx->r10 == 0) {
        // 0x80030FC0: or          $s1, $t8, $zero
        ctx->r17 = ctx->r24 | 0;
            goto L_80031018;
    }
    // 0x80030FC0: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x80030FC4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80030FC8:
    // 0x80030FC8: bne         $at, $zero, L_80030FD8
    if (ctx->r1 != 0) {
        // 0x80030FCC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80030FD8;
    }
    // 0x80030FCC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80030FD0: b           L_80030FD8
    // 0x80030FD4: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80030FD8;
    // 0x80030FD4: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80030FD8:
    // 0x80030FD8: blez        $s0, L_8003100C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80030FDC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8003100C;
    }
    // 0x80030FDC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80030FE0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80030FE4: jalr        $s4
    // 0x80030FE8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_9;
    // 0x80030FE8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x80030FEC: beq         $v0, $zero, L_80031004
    if (ctx->r2 == 0) {
        // 0x80030FF0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80031004;
    }
    // 0x80030FF0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80030FF4: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x80030FF8: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80030FFC: b           L_8003100C
    // 0x80031000: sw          $t5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r13;
        goto L_8003100C;
    // 0x80031000: sw          $t5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r13;
L_80031004:
    // 0x80031004: b           L_80031148
    // 0x80031008: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80031148;
    // 0x80031008: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003100C:
    // 0x8003100C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80031010: bgtzl       $s1, L_80030FC8
    if (SIGNED(ctx->r17) > 0) {
        // 0x80031014: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80030FC8;
    }
    goto skip_14;
    // 0x80031014: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_14:
L_80031018:
    // 0x80031018: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
L_8003101C:
    // 0x8003101C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80031020: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x80031024: blez        $t3, L_8003105C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80031028: lw          $t6, 0xB4($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XB4);
            goto L_8003105C;
    }
    // 0x80031028: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8003102C: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    // 0x80031030: jalr        $s4
    // 0x80031034: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_10;
    // 0x80031034: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_10:
    // 0x80031038: beq         $v0, $zero, L_80031054
    if (ctx->r2 == 0) {
        // 0x8003103C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80031054;
    }
    // 0x8003103C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80031040: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x80031044: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x80031048: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8003104C: b           L_8003105C
    // 0x80031050: sw          $t1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r9;
        goto L_8003105C;
    // 0x80031050: sw          $t1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r9;
L_80031054:
    // 0x80031054: b           L_80031148
    // 0x80031058: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80031148;
    // 0x80031058: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003105C:
    // 0x8003105C: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x80031060: slt         $t2, $zero, $t8
    ctx->r10 = SIGNED(0) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80031064: beql        $t2, $zero, L_800310CC
    if (ctx->r10 == 0) {
        // 0x80031068: lw          $t7, 0xD0($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XD0);
            goto L_800310CC;
    }
    goto skip_15;
    // 0x80031068: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    skip_15:
    // 0x8003106C: beq         $t2, $zero, L_800310C8
    if (ctx->r10 == 0) {
        // 0x80031070: or          $s1, $t8, $zero
        ctx->r17 = ctx->r24 | 0;
            goto L_800310C8;
    }
    // 0x80031070: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x80031074: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80031078:
    // 0x80031078: bne         $at, $zero, L_80031088
    if (ctx->r1 != 0) {
        // 0x8003107C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80031088;
    }
    // 0x8003107C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80031080: b           L_80031088
    // 0x80031084: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80031088;
    // 0x80031084: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80031088:
    // 0x80031088: blez        $s0, L_800310BC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8003108C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800310BC;
    }
    // 0x8003108C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80031090: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80031094: jalr        $s4
    // 0x80031098: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_11;
    // 0x80031098: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x8003109C: beq         $v0, $zero, L_800310B4
    if (ctx->r2 == 0) {
        // 0x800310A0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800310B4;
    }
    // 0x800310A0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800310A4: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x800310A8: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x800310AC: b           L_800310BC
    // 0x800310B0: sw          $t5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r13;
        goto L_800310BC;
    // 0x800310B0: sw          $t5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r13;
L_800310B4:
    // 0x800310B4: b           L_80031148
    // 0x800310B8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80031148;
    // 0x800310B8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800310BC:
    // 0x800310BC: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800310C0: bgtzl       $s1, L_80031078
    if (SIGNED(ctx->r17) > 0) {
        // 0x800310C4: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80031078;
    }
    goto skip_16;
    // 0x800310C4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_16:
L_800310C8:
    // 0x800310C8: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
L_800310CC:
    // 0x800310CC: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x800310D0: andi        $t6, $t7, 0x4
    ctx->r14 = ctx->r15 & 0X4;
    // 0x800310D4: beq         $t6, $zero, L_80031140
    if (ctx->r14 == 0) {
        // 0x800310D8: slt         $t9, $zero, $t3
        ctx->r25 = SIGNED(0) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80031140;
    }
    // 0x800310D8: slt         $t9, $zero, $t3
    ctx->r25 = SIGNED(0) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800310DC: beq         $t9, $zero, L_80031140
    if (ctx->r25 == 0) {
        // 0x800310E0: nop
    
            goto L_80031140;
    }
    // 0x800310E0: nop

    // 0x800310E4: beq         $t9, $zero, L_80031140
    if (ctx->r25 == 0) {
        // 0x800310E8: or          $s1, $t3, $zero
        ctx->r17 = ctx->r11 | 0;
            goto L_80031140;
    }
    // 0x800310E8: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x800310EC: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800310F0:
    // 0x800310F0: bne         $at, $zero, L_80031100
    if (ctx->r1 != 0) {
        // 0x800310F4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80031100;
    }
    // 0x800310F4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800310F8: b           L_80031100
    // 0x800310FC: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80031100;
    // 0x800310FC: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80031100:
    // 0x80031100: blez        $s0, L_80031134
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80031104: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80031134;
    }
    // 0x80031104: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80031108: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8003110C: jalr        $s4
    // 0x80031110: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_12;
    // 0x80031110: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x80031114: beq         $v0, $zero, L_8003112C
    if (ctx->r2 == 0) {
        // 0x80031118: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003112C;
    }
    // 0x80031118: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003111C: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x80031120: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80031124: b           L_80031134
    // 0x80031128: sw          $t1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r9;
        goto L_80031134;
    // 0x80031128: sw          $t1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r9;
L_8003112C:
    // 0x8003112C: b           L_80031148
    // 0x80031130: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_80031148;
    // 0x80031130: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80031134:
    // 0x80031134: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80031138: bgtzl       $s1, L_800310F0
    if (SIGNED(ctx->r17) > 0) {
        // 0x8003113C: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800310F0;
    }
    goto skip_17;
    // 0x8003113C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_17:
L_80031140:
    // 0x80031140: b           L_80030B90
    // 0x80031144: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
        goto L_80030B90;
    // 0x80031144: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
L_80031148:
    // 0x80031148: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003114C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80031150: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80031154: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80031158: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8003115C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80031160: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80031164: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80031168: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8003116C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80031170: jr          $ra
    // 0x80031174: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x80031174: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void _baeggfire_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B30: syscall     129
    recomp_syscall_handler(rdram, ctx, 0x80084B30);
    return;
    // 0x80084B34: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _glglobalsettings_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886F8: syscall     699
    recomp_syscall_handler(rdram, ctx, 0x800886F8);
    return;
    // 0x800886FC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800128_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8080012C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800130: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800134: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800138: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080013C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800140: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x80800144: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x80800148: jal         0x800139F8
    // 0x8080014C: sw          $a3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r7;
    func_800139F8(rdram, ctx);
        goto after_0;
    // 0x8080014C: sw          $a3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800150: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800154: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800158: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x8080015C: lw          $a1, 0xEC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XEC);
    // 0x80800160: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800164: jal         0x800D93A0
    // 0x80800168: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    func_800D93A0(rdram, ctx);
        goto after_1;
    // 0x80800168: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8080016C: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x80800170: jal         0x800D965C
    // 0x80800174: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800D965C(rdram, ctx);
        goto after_2;
    // 0x80800174: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_2:
    // 0x80800178: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x8080017C: jal         0x800D9624
    // 0x80800180: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    func_800D9624(rdram, ctx);
        goto after_3;
    // 0x80800180: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    after_3:
    // 0x80800184: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x80800188: jal         0x800D965C
    // 0x8080018C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800D965C(rdram, ctx);
        goto after_4;
    // 0x8080018C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x80800190: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x80800194: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    // 0x80800198: jal         0x800EFB24
    // 0x8080019C: lw          $a2, 0xE8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE8);
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x8080019C: lw          $a2, 0xE8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE8);
    after_5:
    // 0x808001A0: addiu       $a1, $sp, 0xD4
    ctx->r5 = ADD32(ctx->r29, 0XD4);
    // 0x808001A4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808001A8: jal         0x800F23D0
    // 0x808001AC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800F23D0(rdram, ctx);
        goto after_6;
    // 0x808001AC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x808001B0: lw          $v0, 0xF0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XF0);
    // 0x808001B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808001B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001BC: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x808001C0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x808001C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001CC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x808001D0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x808001D4: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x808001D8: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808001DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808001E0: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x808001E4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x808001E8: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808001EC: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x808001F0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x808001F4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808001F8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808001FC: mul.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80800200: lwc1        $f18, 0xD4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80800204: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80800208: nop

    // 0x8080020C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800210: nop

    // 0x80800214: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80800218: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8080021C: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x80800220: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x80800224: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x80800228: lwc1        $f16, 0xD8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8080022C: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80800230: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80800234: nop

    // 0x80800238: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080023C: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80800240: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800244: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800248: nop

    // 0x8080024C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80800250: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80800254: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80800258: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8080025C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800260: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80800264: nop

    // 0x80800268: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080026C: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80800270: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800274: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x80800278: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8080027C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80800280: nop

    // 0x80800284: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800288: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8080028C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x80800290: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800298: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8080029C: nop

    // 0x808002A0: bc1t        L_80800324
    if (c1cs) {
        // 0x808002A4: nop
    
            goto L_80800324;
    }
    // 0x808002A4: nop

    // 0x808002A8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x808002AC: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808002B0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x808002B4: nop

    // 0x808002B8: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808002BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808002C0: nop

    // 0x808002C4: bc1t        L_80800324
    if (c1cs) {
        // 0x808002C8: nop
    
            goto L_80800324;
    }
    // 0x808002C8: nop

    // 0x808002CC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808002D0: nop

    // 0x808002D4: bc1t        L_80800324
    if (c1cs) {
        // 0x808002D8: nop
    
            goto L_80800324;
    }
    // 0x808002D8: nop

    // 0x808002DC: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x808002E0: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808002E4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808002E8: nop

    // 0x808002EC: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002F0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x808002F4: nop

    // 0x808002F8: bc1t        L_80800324
    if (c1cs) {
        // 0x808002FC: nop
    
            goto L_80800324;
    }
    // 0x808002FC: nop

    // 0x80800300: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80800304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800308: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8080030C: nop

    // 0x80800310: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800314: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800318: nop

    // 0x8080031C: bc1f        L_8080032C
    if (!c1cs) {
        // 0x80800320: nop
    
            goto L_8080032C;
    }
    // 0x80800320: nop

L_80800324:
    // 0x80800324: b           L_8080032C
    // 0x80800328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080032C;
    // 0x80800328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080032C:
    // 0x8080032C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800330: jr          $ra
    // 0x80800334: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x80800334: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_800E4BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4BF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E4BF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E4BFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E4C00: jal         0x800E4730
    // 0x800E4C04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800E4730(rdram, ctx);
        goto after_0;
    // 0x800E4C04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800E4C08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E4C0C: bne         $v0, $at, L_800E4C1C
    if (ctx->r2 != ctx->r1) {
        // 0x800E4C10: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_800E4C1C;
    }
    // 0x800E4C10: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800E4C14: b           L_800E4C68
    // 0x800E4C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E4C68;
    // 0x800E4C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E4C1C:
    // 0x800E4C1C: jal         0x800E488C
    // 0x800E4C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E488C(rdram, ctx);
        goto after_1;
    // 0x800E4C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800E4C24: bnel        $v0, $zero, L_800E4C40
    if (ctx->r2 != 0) {
        // 0x800E4C28: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_800E4C40;
    }
    goto skip_0;
    // 0x800E4C28: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_800E4C2C:
    // 0x800E4C2C: jal         0x800E488C
    // 0x800E4C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E488C(rdram, ctx);
        goto after_2;
    // 0x800E4C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800E4C34: beq         $v0, $zero, L_800E4C2C
    if (ctx->r2 == 0) {
        // 0x800E4C38: nop
    
            goto L_800E4C2C;
    }
    // 0x800E4C38: nop

    // 0x800E4C3C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_800E4C40:
    // 0x800E4C40: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800E4C44: addiu       $t8, $t8, -0x2AA0
    ctx->r24 = ADD32(ctx->r24, -0X2AA0);
    // 0x800E4C48: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800E4C4C: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x800E4C50: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800E4C54: lw          $t9, 0x34($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X34);
    // 0x800E4C58: jal         0x8001B084
    // 0x800E4C5C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    heap_free(rdram, ctx);
        goto after_3;
    // 0x800E4C5C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_3:
    // 0x800E4C60: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800E4C64: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_800E4C68:
    // 0x800E4C68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E4C6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E4C70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E4C74: jr          $ra
    // 0x800E4C78: nop

    return;
    // 0x800E4C78: nop

;}
RECOMP_FUNC void func_80800CA4_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800CB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800CB4: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800CB8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800CBC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800CC0: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800CC4: beq         $t6, $zero, L_80800CE8
    if (ctx->r14 == 0) {
        // 0x80800CC8: addiu       $a1, $zero, 0x18
        ctx->r5 = ADD32(0, 0X18);
            goto L_80800CE8;
    }
    // 0x80800CC8: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80800CCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800CD0: beq         $t6, $at, L_80800D08
    if (ctx->r14 == ctx->r1) {
        // 0x80800CD4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800D08;
    }
    // 0x80800CD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800CD8: beql        $t6, $at, L_80800CFC
    if (ctx->r14 == ctx->r1) {
        // 0x80800CDC: lhu         $t7, 0x6E($a3)
        ctx->r15 = MEM_HU(ctx->r7, 0X6E);
            goto L_80800CFC;
    }
    goto skip_0;
    // 0x80800CDC: lhu         $t7, 0x6E($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X6E);
    skip_0:
    // 0x80800CE0: b           L_80800D1C
    // 0x80800CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D1C;
    // 0x80800CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CE8:
    // 0x80800CE8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800CEC: jal         0x800856B0
    // 0x80800CF0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800CF0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800CF4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800CF8: lhu         $t7, 0x6E($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X6E);
L_80800CFC:
    // 0x80800CFC: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800D00: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80800D04: sh          $t9, 0x6E($a3)
    MEM_H(0X6E, ctx->r7) = ctx->r25;
L_80800D08:
    // 0x80800D08: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800D0C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D10: jal         0x800856D0
    // 0x80800D14: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800D14: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D1C:
    // 0x80800D1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D20: jr          $ra
    // 0x80800D24: nop

    return;
    // 0x80800D24: nop

    // 0x80800D28: nop

    // 0x80800D2C: nop

;}
RECOMP_FUNC void _subaddiedialog_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A200: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A200);
    return;
    // 0x8008A204: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80800808_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800808: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080080C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800810: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800814: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800818: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080081C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800820: jal         0x80100094
    // 0x80800824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800828: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080082C: addiu       $at, $zero, 0x108B
    ctx->r1 = ADD32(0, 0X108B);
    // 0x80800830: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800834: beq         $a1, $at, L_80800898
    if (ctx->r5 == ctx->r1) {
        // 0x80800838: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80800898;
    }
    // 0x80800838: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8080083C: addiu       $at, $zero, 0x1093
    ctx->r1 = ADD32(0, 0X1093);
    // 0x80800840: beq         $a1, $at, L_80800868
    if (ctx->r5 == ctx->r1) {
        // 0x80800844: addiu       $a2, $zero, 0x4E
        ctx->r6 = ADD32(0, 0X4E);
            goto L_80800868;
    }
    // 0x80800844: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x80800848: addiu       $at, $zero, 0x1095
    ctx->r1 = ADD32(0, 0X1095);
    // 0x8080084C: beq         $a1, $at, L_80800888
    if (ctx->r5 == ctx->r1) {
        // 0x80800850: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800888;
    }
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800854: addiu       $at, $zero, 0x1111
    ctx->r1 = ADD32(0, 0X1111);
    // 0x80800858: beq         $a1, $at, L_80800888
    if (ctx->r5 == ctx->r1) {
        // 0x8080085C: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1540, 0X1128) << 16);
            goto L_80800888;
    }
    // 0x8080085C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1540, 0X1128) << 16);
    // 0x80800860: b           L_808008E4
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008E4;
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800868:
    // 0x80800868: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080086C: addiu       $t6, $zero, 0x3D
    ctx->r14 = ADD32(0, 0X3D);
    // 0x80800870: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800874: addiu       $a1, $zero, 0x108B
    ctx->r5 = ADD32(0, 0X108B);
    // 0x80800878: jal         0x8008A208
    // 0x8080087C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x8080087C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800880: b           L_80800968
    // 0x80800884: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800968;
    // 0x80800884: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800888:
    // 0x80800888: jal         0x80102424
    // 0x8080088C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x8080088C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800890: b           L_80800968
    // 0x80800894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800968;
    // 0x80800894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800898:
    // 0x80800898: blez        $t7, L_808008C4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8080089C: addiu       $a1, $zero, 0x1094
        ctx->r5 = ADD32(0, 0X1094);
            goto L_808008C4;
    }
    // 0x8080089C: addiu       $a1, $zero, 0x1094
    ctx->r5 = ADD32(0, 0X1094);
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x808008A8: jal         0x80102424
    // 0x808008AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808008AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_3:
    // 0x808008B0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808008B4: jal         0x80089FE0
    // 0x808008B8: addiu       $a0, $v1, 0xC
    ctx->r4 = ADD32(ctx->r3, 0XC);
    _subaddieitem_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808008B8: addiu       $a0, $v1, 0xC
    ctx->r4 = ADD32(ctx->r3, 0XC);
    after_4:
    // 0x808008BC: b           L_80800968
    // 0x808008C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800968;
    // 0x808008C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008C4:
    // 0x808008C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808008C8: addiu       $t8, $zero, 0x3D
    ctx->r24 = ADD32(0, 0X3D);
    // 0x808008CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808008D0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808008D4: jal         0x8008A208
    // 0x808008D8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808008D8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x808008DC: b           L_80800968
    // 0x808008E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800968;
    // 0x808008E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008E4:
    // 0x808008E4: addiu       $a2, $a2, 0x1128
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1540, 0X1128));
    // 0x808008E8: jal         0x8008A1F8
    // 0x808008EC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x808008EC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_6:
    // 0x808008F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008F4: bne         $v0, $at, L_8080095C
    if (ctx->r2 != ctx->r1) {
        // 0x808008F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080095C;
    }
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008FC: jal         0x800DA544
    // 0x80800900: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x80800900: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    after_7:
    // 0x80800904: jal         0x80800FE0
    // 0x80800908: addiu       $a0, $zero, 0x3CA
    ctx->r4 = ADD32(0, 0X3CA);
    func_80800FE0_chboggyfatboy(rdram, ctx);
        goto after_8;
    // 0x80800908: addiu       $a0, $zero, 0x3CA
    ctx->r4 = ADD32(0, 0X3CA);
    after_8:
    // 0x8080090C: beq         $v0, $zero, L_80800938
    if (ctx->r2 == 0) {
        // 0x80800910: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_80800938;
    }
    // 0x80800910: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x80800914: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800918: addiu       $t9, $zero, 0x3D
    ctx->r25 = ADD32(0, 0X3D);
    // 0x8080091C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800920: addiu       $a1, $zero, 0x1093
    ctx->r5 = ADD32(0, 0X1093);
    // 0x80800924: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800928: jal         0x8008A208
    // 0x8080092C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x8080092C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80800930: b           L_80800968
    // 0x80800934: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800968;
    // 0x80800934: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800938:
    // 0x80800938: jal         0x800C01A8
    // 0x8080093C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_10;
    // 0x8080093C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800940: jal         0x800C0850
    // 0x80800944: nop

    func_800C0850(rdram, ctx);
        goto after_11;
    // 0x80800944: nop

    after_11:
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080094C: jal         0x80102424
    // 0x80800950: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x80800950: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800954: b           L_80800968
    // 0x80800958: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800968;
    // 0x80800958: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080095C:
    // 0x8080095C: jal         0x80102424
    // 0x80800960: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x80800960: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800964: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800968:
    // 0x80800968: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080096C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800970: jr          $ra
    // 0x80800974: nop

    return;
    // 0x80800974: nop

;}
RECOMP_FUNC void func_80800000_chlavahand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lbu         $t7, 0x64($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X64);
    // 0x80800004: lbu         $t9, 0x65($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X65);
    // 0x80800008: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8080000C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800010: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x80800014: sb          $t8, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r24;
    // 0x80800018: sb          $t0, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r8;
    // 0x8080001C: jr          $ra
    // 0x80800020: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80800020: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void glintrosyncDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800320: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800324: jr          $ra
    // 0x80800328: swc1        $f12, 0x75D8($at)
    MEM_W(0X75D8, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x80800328: swc1        $f12, 0x75D8($at)
    MEM_W(0X75D8, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800970_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800970: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800974: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800978: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080097C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800980: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800984: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800988: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080098C: lbu         $v0, 0x14($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X14);
    // 0x80800990: beq         $v0, $at, L_808009A8
    if (ctx->r2 == ctx->r1) {
        // 0x80800994: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808009A8;
    }
    // 0x80800994: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800998: beq         $v0, $at, L_80800AB8
    if (ctx->r2 == ctx->r1) {
        // 0x8080099C: nop
    
            goto L_80800AB8;
    }
    // 0x8080099C: nop

    // 0x808009A0: b           L_80800B78
    // 0x808009A4: nop

        goto L_80800B78;
    // 0x808009A4: nop

L_808009A8:
    // 0x808009A8: jal         0x80800904
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800904_bafpctrl(rdram, ctx);
        goto after_0;
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808009B0: bne         $v0, $zero, L_808009C8
    if (ctx->r2 != 0) {
        // 0x808009B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009C8;
    }
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B8: jal         0x80095738
    // 0x808009BC: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x808009BC: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_1:
    // 0x808009C0: beql        $v0, $zero, L_808009D8
    if (ctx->r2 == 0) {
        // 0x808009C4: lw          $t9, 0x90($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X90);
            goto L_808009D8;
    }
    goto skip_0;
    // 0x808009C4: lw          $t9, 0x90($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X90);
    skip_0:
L_808009C8:
    // 0x808009C8: lw          $t8, 0x90($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X90);
    // 0x808009CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808009D0: sb          $t7, 0x15($t8)
    MEM_B(0X15, ctx->r24) = ctx->r15;
    // 0x808009D4: lw          $t9, 0x90($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X90);
L_808009D8:
    // 0x808009D8: lbu         $t0, 0x15($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X15);
    // 0x808009DC: beq         $t0, $zero, L_80800A34
    if (ctx->r8 == 0) {
        // 0x808009E0: nop
    
            goto L_80800A34;
    }
    // 0x808009E0: nop

    // 0x808009E4: jal         0x80084AC0
    // 0x808009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggcursor_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808009EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808009F0: bne         $v0, $at, L_80800A34
    if (ctx->r2 != ctx->r1) {
        // 0x808009F4: nop
    
            goto L_80800A34;
    }
    // 0x808009F4: nop

    // 0x808009F8: jal         0x800A4CA8
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_3;
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800A00: jal         0x80089420
    // 0x80800A04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncba1p_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800A04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800A08: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800A0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A14: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800A18: nop

    // 0x80800A1C: bc1f        L_80800A34
    if (!c1cs) {
        // 0x80800A20: nop
    
            goto L_80800A34;
    }
    // 0x80800A20: nop

    // 0x80800A24: jal         0x80800424
    // 0x80800A28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800424_bafpctrl(rdram, ctx);
        goto after_5;
    // 0x80800A28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800A2C: b           L_80800B78
    // 0x80800A30: nop

        goto L_80800B78;
    // 0x80800A30: nop

L_80800A34:
    // 0x80800A34: jal         0x80800008
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800008_bafpctrl(rdram, ctx);
        goto after_6;
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800A3C: beq         $v0, $zero, L_80800A68
    if (ctx->r2 == 0) {
        // 0x80800A40: nop
    
            goto L_80800A68;
    }
    // 0x80800A40: nop

    // 0x80800A44: jal         0x800A4CA8
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_7;
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800A4C: jal         0x80089418
    // 0x80800A50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncba1p_entrypoint_10(rdram, ctx);
        goto after_8;
    // 0x80800A50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800A54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A58: bne         $v0, $at, L_80800A68
    if (ctx->r2 != ctx->r1) {
        // 0x80800A5C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80800A68;
    }
    // 0x80800A5C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800A60: b           L_80800B78
    // 0x80800A64: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
        goto L_80800B78;
    // 0x80800A64: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80800A68:
    // 0x80800A68: jal         0x80800C10
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bafpctrl_entrypoint_6(rdram, ctx);
        goto after_9;
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800A70: beq         $v0, $zero, L_80800B78
    if (ctx->r2 == 0) {
        // 0x80800A74: nop
    
            goto L_80800B78;
    }
    // 0x80800A74: nop

    // 0x80800A78: lw          $t2, 0x90($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X90);
    // 0x80800A7C: lbu         $t3, 0x11($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X11);
    // 0x80800A80: beq         $t3, $zero, L_80800A98
    if (ctx->r11 == 0) {
        // 0x80800A84: nop
    
            goto L_80800A98;
    }
    // 0x80800A84: nop

    // 0x80800A88: jal         0x8080022C
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080022C_bafpctrl(rdram, ctx);
        goto after_10;
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800A90: b           L_80800AA0
    // 0x80800A94: nop

        goto L_80800AA0;
    // 0x80800A94: nop

L_80800A98:
    // 0x80800A98: jal         0x808002A4
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002A4_bafpctrl(rdram, ctx);
        goto after_11;
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_80800AA0:
    // 0x80800AA0: jal         0x80800880
    // 0x80800AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800880_bafpctrl(rdram, ctx);
        goto after_12;
    // 0x80800AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800AA8: jal         0x808008CC
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008CC_bafpctrl(rdram, ctx);
        goto after_13;
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800AB0: b           L_80800B78
    // 0x80800AB4: nop

        goto L_80800B78;
    // 0x80800AB4: nop

L_80800AB8:
    // 0x80800AB8: jal         0x80094AB4
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094AB4(rdram, ctx);
        goto after_14;
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800AC0: jal         0x80800904
    // 0x80800AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800904_bafpctrl(rdram, ctx);
        goto after_15;
    // 0x80800AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800AC8: beq         $v0, $zero, L_80800B10
    if (ctx->r2 == 0) {
        // 0x80800ACC: nop
    
            goto L_80800B10;
    }
    // 0x80800ACC: nop

    // 0x80800AD0: jal         0x80084AC0
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggcursor_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800AD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800ADC: bne         $v0, $at, L_80800B10
    if (ctx->r2 != ctx->r1) {
        // 0x80800AE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B10;
    }
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE4: jal         0x80095738
    // 0x80800AE8: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    baflag_isTrue(rdram, ctx);
        goto after_17;
    // 0x80800AE8: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_17:
    // 0x80800AEC: beq         $v0, $zero, L_80800B00
    if (ctx->r2 == 0) {
        // 0x80800AF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B00;
    }
    // 0x80800AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800AF8: b           L_80800B78
    // 0x80800AFC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
        goto L_80800B78;
    // 0x80800AFC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
L_80800B00:
    // 0x80800B00: jal         0x80800424
    // 0x80800B04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800424_bafpctrl(rdram, ctx);
        goto after_18;
    // 0x80800B04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80800B08: b           L_80800B78
    // 0x80800B0C: nop

        goto L_80800B78;
    // 0x80800B0C: nop

L_80800B10:
    // 0x80800B10: jal         0x80800008
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800008_bafpctrl(rdram, ctx);
        goto after_19;
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800B18: beq         $v0, $zero, L_80800B28
    if (ctx->r2 == 0) {
        // 0x80800B1C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80800B28;
    }
    // 0x80800B1C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800B20: b           L_80800B78
    // 0x80800B24: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
        goto L_80800B78;
    // 0x80800B24: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_80800B28:
    // 0x80800B28: jal         0x80800C10
    // 0x80800B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bafpctrl_entrypoint_6(rdram, ctx);
        goto after_20;
    // 0x80800B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800B30: beq         $v0, $zero, L_80800B78
    if (ctx->r2 == 0) {
        // 0x80800B34: nop
    
            goto L_80800B78;
    }
    // 0x80800B34: nop

    // 0x80800B38: lw          $t6, 0x90($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X90);
    // 0x80800B3C: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x80800B40: beq         $t7, $zero, L_80800B58
    if (ctx->r15 == 0) {
        // 0x80800B44: nop
    
            goto L_80800B58;
    }
    // 0x80800B44: nop

    // 0x80800B48: jal         0x8080022C
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080022C_bafpctrl(rdram, ctx);
        goto after_21;
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800B50: b           L_80800B60
    // 0x80800B54: nop

        goto L_80800B60;
    // 0x80800B54: nop

L_80800B58:
    // 0x80800B58: jal         0x808003BC
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003BC_bafpctrl(rdram, ctx);
        goto after_22;
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
L_80800B60:
    // 0x80800B60: jal         0x808008CC
    // 0x80800B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008CC_bafpctrl(rdram, ctx);
        goto after_23;
    // 0x80800B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800B68: jal         0x80800880
    // 0x80800B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800880_bafpctrl(rdram, ctx);
        goto after_24;
    // 0x80800B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800B70: jal         0x80084AA8
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggaim_entrypoint_3(rdram, ctx);
        goto after_25;
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
L_80800B78:
    // 0x80800B78: jal         0x80800114
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800114_bafpctrl(rdram, ctx);
        goto after_26;
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800B80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B84: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800B88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B8C: jr          $ra
    // 0x80800B90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800B90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bsbansack_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826B0: syscall     7
    recomp_syscall_handler(rdram, ctx, 0x800826B0);
    return;
    // 0x800826B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chlavacolumnswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1880, 0X80) << 16);
    // 0x8080006C: jr          $ra
    // 0x80800070: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1880, 0X80));
    return;
    // 0x80800070: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1880, 0X80));
    // 0x80800074: nop

    // 0x80800078: nop

    // 0x8080007C: nop

;}
RECOMP_FUNC void _bschokedie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EA0: syscall     32
    recomp_syscall_handler(rdram, ctx, 0x80082EA0);
    return;
    // 0x80082EA4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chlagoonbits_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FE0: syscall     268
    recomp_syscall_handler(rdram, ctx, 0x80085FE0);
    return;
    // 0x80085FE4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _sucoasterflydata_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A270: syscall     832
    recomp_syscall_handler(rdram, ctx, 0x8008A270);
    return;
    // 0x8008A274: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80097104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097104: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80097108: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8009710C: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80097110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097114: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80097118: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x8009711C: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80097120: jal         0x800EFA20
    // 0x80097124: lw          $a1, 0x98($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X98);
    func_800EFA20(rdram, ctx);
        goto after_0;
    // 0x80097124: lw          $a1, 0x98($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X98);
    after_0:
    // 0x80097128: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8009712C: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    // 0x80097130: jal         0x800EFB24
    // 0x80097134: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x80097134: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_1:
    // 0x80097138: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8009713C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80097140: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80097144: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80097148: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8009714C: jal         0x800EFA4C
    // 0x80097150: nop

    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80097150: nop

    after_2:
    // 0x80097154: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80097158: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8009715C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80097160: jal         0x800EE97C
    // 0x80097164: lw          $a1, 0x98($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X98);
    func_800EE97C(rdram, ctx);
        goto after_3;
    // 0x80097164: lw          $a1, 0x98($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X98);
    after_3:
    // 0x80097168: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8009716C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80097170: jal         0x800EFA20
    // 0x80097174: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    func_800EFA20(rdram, ctx);
        goto after_4;
    // 0x80097174: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_4:
    // 0x80097178: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8009717C: jal         0x8009BB24
    // 0x80097180: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009BB24(rdram, ctx);
        goto after_5;
    // 0x80097180: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_5:
    // 0x80097184: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80097188: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8009718C: jal         0x800EF2A0
    // 0x80097190: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_800EF2A0(rdram, ctx);
        goto after_6;
    // 0x80097190: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80097194: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80097198: jal         0x800EEAA4
    // 0x8009719C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800EEAA4(rdram, ctx);
        goto after_7;
    // 0x8009719C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_7:
    // 0x800971A0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800971A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800971A8: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800971AC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800971B0: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800971B4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800971B8: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800971BC: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800971C0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800971C4: jal         0x800EFA4C
    // 0x800971C8: nop

    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x800971C8: nop

    after_8:
    // 0x800971CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800971D0: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800971D4: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800971D8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800971DC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800971E0: nop

    // 0x800971E4: bc1fl       L_8009723C
    if (!c1cs) {
        // 0x800971E8: lwc1        $f8, 0x28($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8009723C;
    }
    goto skip_0;
    // 0x800971E8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x800971EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800971F0: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800971F4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800971F8: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800971FC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80097200: jal         0x800970A4
    // 0x80097204: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800970A4(rdram, ctx);
        goto after_9;
    // 0x80097204: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x80097208: beq         $v0, $zero, L_80097218
    if (ctx->r2 == 0) {
        // 0x8009720C: lwc1        $f0, 0x18($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
            goto L_80097218;
    }
    // 0x8009720C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80097210: b           L_800972AC
    // 0x80097214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800972AC;
    // 0x80097214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097218:
    // 0x80097218: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009721C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80097220: jal         0x800970A4
    // 0x80097224: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800970A4(rdram, ctx);
        goto after_10;
    // 0x80097224: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_10:
    // 0x80097228: beql        $v0, $zero, L_8009723C
    if (ctx->r2 == 0) {
        // 0x8009722C: lwc1        $f8, 0x28($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8009723C;
    }
    goto skip_1;
    // 0x8009722C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80097230: b           L_800972AC
    // 0x80097234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800972AC;
    // 0x80097234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80097238: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
L_8009723C:
    // 0x8009723C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80097240: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80097244: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80097248: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8009724C: nop

    // 0x80097250: bc1fl       L_800972AC
    if (!c1cs) {
        // 0x80097254: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800972AC;
    }
    goto skip_2;
    // 0x80097254: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x80097258: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009725C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80097260: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80097264: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80097268: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8009726C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80097270: jal         0x800970A4
    // 0x80097274: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800970A4(rdram, ctx);
        goto after_11;
    // 0x80097274: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x80097278: beq         $v0, $zero, L_80097288
    if (ctx->r2 == 0) {
        // 0x8009727C: lwc1        $f0, 0x18($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
            goto L_80097288;
    }
    // 0x8009727C: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80097280: b           L_800972AC
    // 0x80097284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800972AC;
    // 0x80097284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097288:
    // 0x80097288: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009728C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80097290: jal         0x800970A4
    // 0x80097294: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800970A4(rdram, ctx);
        goto after_12;
    // 0x80097294: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_12:
    // 0x80097298: beql        $v0, $zero, L_800972AC
    if (ctx->r2 == 0) {
        // 0x8009729C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800972AC;
    }
    goto skip_3;
    // 0x8009729C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x800972A0: b           L_800972AC
    // 0x800972A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800972AC;
    // 0x800972A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800972A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800972AC:
    // 0x800972AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800972B0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x800972B4: jr          $ra
    // 0x800972B8: nop

    return;
    // 0x800972B8: nop

;}
RECOMP_FUNC void _bsstand_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B78: syscall     90
    recomp_syscall_handler(rdram, ctx, 0x80083B78);
    return;
    // 0x80083B7C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800FF3EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF3EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FF3F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FF3F4: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x800FF3F8: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x800FF3FC: bltzl       $t8, L_800FF440
    if (SIGNED(ctx->r24) < 0) {
        // 0x800FF400: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FF440;
    }
    goto skip_0;
    // 0x800FF400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800FF404: jal         0x80100368
    // 0x800FF408: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100368(rdram, ctx);
        goto after_0;
    // 0x800FF408: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800FF40C: lw          $t9, 0x28($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X28);
    // 0x800FF410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800FF414: beql        $t9, $zero, L_800FF434
    if (ctx->r25 == 0) {
        // 0x800FF418: lbu         $t1, 0x64($a0)
        ctx->r9 = MEM_BU(ctx->r4, 0X64);
            goto L_800FF434;
    }
    goto skip_1;
    // 0x800FF418: lbu         $t1, 0x64($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X64);
    skip_1:
    // 0x800FF41C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800FF420: lw          $t9, 0x28($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X28);
    // 0x800FF424: jalr        $t9
    // 0x800FF428: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800FF428: nop

    after_1:
    // 0x800FF42C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800FF430: lbu         $t1, 0x64($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X64);
L_800FF434:
    // 0x800FF434: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x800FF438: sb          $t2, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r10;
    // 0x800FF43C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FF440:
    // 0x800FF440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FF444: jr          $ra
    // 0x800FF448: nop

    return;
    // 0x800FF448: nop

;}
