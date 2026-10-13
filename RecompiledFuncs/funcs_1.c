#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _sujiggy_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A760: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A760);
    return;
    // 0x8008A764: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void func_80802324_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802324: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802328: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1840, 0X4E94) << 16);
    // 0x8080232C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802330: addiu       $t6, $t6, 0x4E94
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1840, 0X4E94));
    // 0x80802334: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802338: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080233C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802340: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80802344: jal         0x800BBCB8
    // 0x80802348: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80802348: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_0:
    // 0x8080234C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1840, 0X4EE4) << 16);
    // 0x80802350: addiu       $t7, $t7, 0x4EE4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1840, 0X4EE4));
    // 0x80802354: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802358: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080235C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802360: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80802364: jal         0x800BBCB8
    // 0x80802368: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x80802368: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_1:
    // 0x8080236C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802370: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802374: jr          $ra
    // 0x80802378: nop

    return;
    // 0x80802378: nop

;}
RECOMP_FUNC void func_8080160C_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080160C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801610: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801614: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80801618: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080161C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801620: andi        $t6, $s0, 0x200
    ctx->r14 = ctx->r16 & 0X200;
    // 0x80801624: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801628: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080162C: bne         $t6, $zero, L_8080164C
    if (ctx->r14 != 0) {
        // 0x80801630: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_8080164C;
    }
    // 0x80801630: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80801634: jal         0x808006D0
    // 0x80801638: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_808006D0_subaddierouteDll(rdram, ctx);
        goto after_0;
    // 0x80801638: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080163C: bnel        $v0, $zero, L_80801650
    if (ctx->r2 != 0) {
        // 0x80801640: andi        $t7, $s0, 0x100
        ctx->r15 = ctx->r16 & 0X100;
            goto L_80801650;
    }
    goto skip_0;
    // 0x80801640: andi        $t7, $s0, 0x100
    ctx->r15 = ctx->r16 & 0X100;
    skip_0:
    // 0x80801644: b           L_808016DC
    // 0x80801648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808016DC;
    // 0x80801648: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080164C:
    // 0x8080164C: andi        $t7, $s0, 0x100
    ctx->r15 = ctx->r16 & 0X100;
L_80801650:
    // 0x80801650: bne         $t7, $zero, L_8080167C
    if (ctx->r15 != 0) {
        // 0x80801654: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080167C;
    }
    // 0x80801654: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801658: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080165C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80801660: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80801664: jal         0x80800828
    // 0x80801668: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80800828_subaddierouteDll(rdram, ctx);
        goto after_1;
    // 0x80801668: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_1:
    // 0x8080166C: bnel        $v0, $zero, L_80801680
    if (ctx->r2 != 0) {
        // 0x80801670: andi        $t8, $s0, 0x400
        ctx->r24 = ctx->r16 & 0X400;
            goto L_80801680;
    }
    goto skip_1;
    // 0x80801670: andi        $t8, $s0, 0x400
    ctx->r24 = ctx->r16 & 0X400;
    skip_1:
    // 0x80801674: b           L_808016DC
    // 0x80801678: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808016DC;
    // 0x80801678: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080167C:
    // 0x8080167C: andi        $t8, $s0, 0x400
    ctx->r24 = ctx->r16 & 0X400;
L_80801680:
    // 0x80801680: bne         $t8, $zero, L_808016CC
    if (ctx->r24 != 0) {
        // 0x80801684: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_808016CC;
    }
    // 0x80801684: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80801688: jal         0x800DC128
    // 0x8080168C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x8080168C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x80801690: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80801694: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80801698: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080169C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808016A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808016A4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808016A8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x808016AC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808016B0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808016B4: jal         0x80800A74
    // 0x808016B8: nop

    func_80800A74_subaddierouteDll(rdram, ctx);
        goto after_3;
    // 0x808016B8: nop

    after_3:
    // 0x808016BC: bnel        $v0, $zero, L_808016D0
    if (ctx->r2 != 0) {
        // 0x808016C0: lwc1        $f16, 0x30($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
            goto L_808016D0;
    }
    goto skip_2;
    // 0x808016C0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    skip_2:
    // 0x808016C4: b           L_808016DC
    // 0x808016C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808016DC;
    // 0x808016C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808016CC:
    // 0x808016CC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
L_808016D0:
    // 0x808016D0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x808016D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808016D8: swc1        $f16, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->f16.u32l;
L_808016DC:
    // 0x808016DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808016E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808016E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808016E8: jr          $ra
    // 0x808016EC: nop

    return;
    // 0x808016EC: nop

;}
RECOMP_FUNC void func_800BA714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA714: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800BA718: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800BA71C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800BA720: sb          $t0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r8;
    // 0x800BA724: sh          $a1, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r5;
    // 0x800BA728: jr          $ra
    // 0x800BA72C: sh          $a2, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r6;
    return;
    // 0x800BA72C: sh          $a2, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r6;
;}
RECOMP_FUNC void _sucoaster_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A120: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A120);
    return;
    // 0x8008A124: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808001B4_chgruntyfireballbig(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808001B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001BC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808001C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001C8: beq         $a1, $at, L_808001F4
    if (ctx->r5 == ctx->r1) {
        // 0x808001CC: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_808001F4;
    }
    // 0x808001CC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808001D0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808001D4: beq         $a1, $at, L_808002AC
    if (ctx->r5 == ctx->r1) {
        // 0x808001D8: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808002AC;
    }
    // 0x808001D8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808001DC: beq         $a1, $at, L_808002BC
    if (ctx->r5 == ctx->r1) {
        // 0x808001E0: addiu       $at, $zero, 0x9B
        ctx->r1 = ADD32(0, 0X9B);
            goto L_808002BC;
    }
    // 0x808001E0: addiu       $at, $zero, 0x9B
    ctx->r1 = ADD32(0, 0X9B);
    // 0x808001E4: beq         $a1, $at, L_808002EC
    if (ctx->r5 == ctx->r1) {
        // 0x808001E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002EC;
    }
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: b           L_80800338
    // 0x808001F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800338;
    // 0x808001F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001F4:
    // 0x808001F4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x808001F8: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x808001FC: sra         $t9, $t6, 16
    ctx->r25 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800200: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x80800204: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x80800208: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x8080020C: jal         0x80101068
    // 0x80800210: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
    func_80101068(rdram, ctx);
        goto after_0;
    // 0x80800210: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
    after_0:
    // 0x80800214: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80800218: jal         0x8010A590
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: jal         0x80101FDC
    // 0x80800228: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800228: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080022C: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800230: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800234: andi        $t4, $a0, 0x1FF
    ctx->r12 = ctx->r4 & 0X1FF;
    // 0x80800238: jal         0x800F5A00
    // 0x8080023C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x8080023C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_3:
    // 0x80800240: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800244: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800248: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080024C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800250: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800254: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800258: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8080025C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800260: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800264: jal         0x800EFB24
    // 0x80800268: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    func_800EFB24(rdram, ctx);
        goto after_4;
    // 0x80800268: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8080026C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80800270: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800274: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80800278: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8080027C: nop

    // 0x80800280: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800284: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800288: jal         0x800EF368
    // 0x8080028C: nop

    func_800EF368(rdram, ctx);
        goto after_5;
    // 0x8080028C: nop

    after_5:
    // 0x80800290: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1500, 0X6F8) << 16);
    // 0x80800294: addiu       $a2, $a2, 0x6F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1500, 0X6F8));
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080029C: jal         0x80089D18
    // 0x808002A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808002A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x808002A4: b           L_80800338
    // 0x808002A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800338;
    // 0x808002A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002AC:
    // 0x808002AC: jal         0x8080034C
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080034C_chgruntyfireballbig(rdram, ctx);
        goto after_7;
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808002B4: b           L_80800338
    // 0x808002B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800338;
    // 0x808002B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002BC:
    // 0x808002BC: jal         0x800C8A98
    // 0x808002C0: nop

    func_800C8A98(rdram, ctx);
        goto after_8;
    // 0x808002C0: nop

    after_8:
    // 0x808002C4: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x808002C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002CC: jal         0x800C8CB8
    // 0x808002D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_9;
    // 0x808002D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x808002D4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1500, 0X70C) << 16);
    // 0x808002D8: addiu       $a1, $a1, 0x70C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1500, 0X70C));
    // 0x808002DC: jal         0x800C8D4C
    // 0x808002E0: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    func_800C8D4C(rdram, ctx);
        goto after_10;
    // 0x808002E0: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_10:
    // 0x808002E4: b           L_80800338
    // 0x808002E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800338;
    // 0x808002E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002EC:
    // 0x808002EC: jal         0x80101FDC
    // 0x808002F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x808002F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x808002F4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x808002F8: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x808002FC: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x80800300: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80800304: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800308: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8080030C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800310: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x80800314: beq         $a0, $zero, L_80800334
    if (ctx->r4 == 0) {
        // 0x80800318: swc1        $f18, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
            goto L_80800334;
    }
    // 0x80800318: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x8080031C: jal         0x800863E8
    // 0x80800320: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x80800320: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_12:
    // 0x80800324: b           L_80800334
    // 0x80800328: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
        goto L_80800334;
    // 0x80800328: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8080032C: b           L_80800338
    // 0x80800330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800338;
    // 0x80800330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800334:
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800338:
    // 0x80800338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080033C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800340: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800344: jr          $ra
    // 0x80800348: nop

    return;
    // 0x80800348: nop

;}
RECOMP_FUNC void func_8080241C_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080241C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80802420: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80802424: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80802428: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8080242C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80802430: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80802434: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80802438: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080243C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802440: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80802444: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802448: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8080244C: blez        $t6, L_80802508
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80802450: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80802508;
    }
    // 0x80802450: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80802454: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80802458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080245C:
    // 0x8080245C: jal         0x80800070
    // 0x80802460: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80800070_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80802460: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x80802464: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x80802468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080246C: beql        $v0, $t7, L_808024F8
    if (ctx->r2 == ctx->r15) {
        // 0x80802470: lh          $t6, 0x2($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X2);
            goto L_808024F8;
    }
    goto skip_0;
    // 0x80802470: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    skip_0:
    // 0x80802474: jal         0x80800000
    // 0x80802478: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_1;
    // 0x80802478: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x8080247C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80802480: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x80802484: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80802488: jal         0x80087AF8
    // 0x8080248C: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080248C: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    after_2:
    // 0x80802490: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x80802494: beq         $at, $zero, L_808024EC
    if (ctx->r1 == 0) {
        // 0x80802498: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_808024EC;
    }
    // 0x80802498: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8080249C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x808024A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X302C) << 16);
    // 0x808024A4: addu        $at, $at, $t0
    gpr jr_addend_808024AC = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808024A8: lw          $t0, 0x302C($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2590, 0X302C));
    // 0x808024AC: jr          $t0
    // 0x808024B0: nop

    switch (jr_addend_808024AC >> 2) {
        case 0: goto L_808024B4; break;
        case 1: goto L_808024EC; break;
        case 2: goto L_808024B4; break;
        case 3: goto L_808024B4; break;
        case 4: goto L_808024E4; break;
        case 5: goto L_808024E4; break;
        default: switch_error(__func__, 0x808024AC, 0x8080302C);
    }
    // 0x808024B0: nop

L_808024B4:
    // 0x808024B4: addu        $s1, $s0, $s2
    ctx->r17 = ADD32(ctx->r16, ctx->r18);
    // 0x808024B8: lb          $t1, 0x94($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X94);
    // 0x808024BC: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x808024C0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x808024C4: beq         $v0, $t1, L_808024F0
    if (ctx->r2 == ctx->r9) {
        // 0x808024C8: addu        $t3, $s0, $t2
        ctx->r11 = ADD32(ctx->r16, ctx->r10);
            goto L_808024F0;
    }
    // 0x808024C8: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x808024CC: jal         0x80087BE8
    // 0x808024D0: lw          $a0, 0x3C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X3C);
    _gczoombox_entrypoint_33(rdram, ctx);
        goto after_3;
    // 0x808024D0: lw          $a0, 0x3C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X3C);
    after_3:
    // 0x808024D4: sll         $t4, $s2, 1
    ctx->r12 = S32(ctx->r18 << 1);
    // 0x808024D8: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x808024DC: b           L_808024F0
    // 0x808024E0: sh          $s6, 0x50($t5)
    MEM_H(0X50, ctx->r13) = ctx->r22;
        goto L_808024F0;
    // 0x808024E0: sh          $s6, 0x50($t5)
    MEM_H(0X50, ctx->r13) = ctx->r22;
L_808024E4:
    // 0x808024E4: b           L_808024F0
    // 0x808024E8: addu        $s1, $s0, $s2
    ctx->r17 = ADD32(ctx->r16, ctx->r18);
        goto L_808024F0;
    // 0x808024E8: addu        $s1, $s0, $s2
    ctx->r17 = ADD32(ctx->r16, ctx->r18);
L_808024EC:
    // 0x808024EC: addu        $s1, $s0, $s2
    ctx->r17 = ADD32(ctx->r16, ctx->r18);
L_808024F0:
    // 0x808024F0: sb          $s4, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r20;
    // 0x808024F4: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
L_808024F8:
    // 0x808024F8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x808024FC: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80802500: bnel        $at, $zero, L_8080245C
    if (ctx->r1 != 0) {
        // 0x80802504: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080245C;
    }
    goto skip_1;
    // 0x80802504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_80802508:
    // 0x80802508: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080250C: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80802510: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80802514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802518: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080251C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80802520: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80802524: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80802528: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8080252C: jr          $ra
    // 0x80802530: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80802530: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void chskeletonexplode_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A90: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80800A94: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x80800A98: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80800A9C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800AA0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800AA4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800AA8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800AAC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800AB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800AB4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800AB8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800ABC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80800AC0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800AC4: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80800AC8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800ACC: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80800AD0: jal         0x80106790
    // 0x80800AD4: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800AD4: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80800AD8: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800ADC: addiu       $a0, $zero, 0x304
    ctx->r4 = ADD32(0, 0X304);
    // 0x80800AE0: jal         0x801084B0
    // 0x80800AE4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x80800AE4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_1:
    // 0x80800AE8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800AEC: jal         0x80106790
    // 0x80800AF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800AF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80800AF4: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800AF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AFC: jal         0x80100094
    // 0x80800B00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800B00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800B04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800B08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B0C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80800B10: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80800B14: jal         0x808004DC
    // 0x80800B18: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    func_808004DC_chskeletonexplode(rdram, ctx);
        goto after_4;
    // 0x80800B18: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    after_4:
    // 0x80800B1C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80800B20: lh          $t7, 0x10($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X10);
    // 0x80800B24: bnel        $t7, $zero, L_80800B40
    if (ctx->r15 != 0) {
        // 0x80800B28: lw          $t9, 0x50($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X50);
            goto L_80800B40;
    }
    goto skip_0;
    // 0x80800B28: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x80800B2C: jal         0x800AE020
    // 0x80800B30: nop

    func_800AE020(rdram, ctx);
        goto after_5;
    // 0x80800B30: nop

    after_5:
    // 0x80800B34: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80800B38: sh          $v0, 0x10($t8)
    MEM_H(0X10, ctx->r24) = ctx->r2;
    // 0x80800B3C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
L_80800B40:
    // 0x80800B40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B44: lbu         $t0, 0x65($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X65);
    // 0x80800B48: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x80800B4C: jal         0x80800594
    // 0x80800B50: sb          $t1, 0x65($t9)
    MEM_B(0X65, ctx->r25) = ctx->r9;
    func_80800594_chskeletonexplode(rdram, ctx);
        goto after_6;
    // 0x80800B50: sb          $t1, 0x65($t9)
    MEM_B(0X65, ctx->r25) = ctx->r9;
    after_6:
    // 0x80800B54: jal         0x80104248
    // 0x80800B58: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80104248(rdram, ctx);
        goto after_7;
    // 0x80800B58: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_7:
    // 0x80800B5C: beq         $v0, $zero, L_80800B7C
    if (ctx->r2 == 0) {
        // 0x80800B60: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800B7C;
    }
    // 0x80800B60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B68: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80800B6C: jal         0x808005CC
    // 0x80800B70: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_808005CC_chskeletonexplode(rdram, ctx);
        goto after_8;
    // 0x80800B70: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_8:
    // 0x80800B74: b           L_80800B8C
    // 0x80800B78: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
        goto L_80800B8C;
    // 0x80800B78: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_80800B7C:
    // 0x80800B7C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80800B80: jal         0x80800894
    // 0x80800B84: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_80800894_chskeletonexplode(rdram, ctx);
        goto after_9;
    // 0x80800B84: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_9:
    // 0x80800B88: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_80800B8C:
    // 0x80800B8C: sb          $zero, 0xF4($s0)
    MEM_B(0XF4, ctx->r16) = 0;
    // 0x80800B90: sb          $zero, 0xF5($s0)
    MEM_B(0XF5, ctx->r16) = 0;
    // 0x80800B94: lhu         $t2, 0x18($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X18);
    // 0x80800B98: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80800B9C: beql        $t3, $zero, L_80800BC0
    if (ctx->r11 == 0) {
        // 0x80800BA0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800BC0;
    }
    goto skip_1;
    // 0x80800BA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x80800BA4: jal         0x80101074
    // 0x80800BA8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_80101074(rdram, ctx);
        goto after_10;
    // 0x80800BA8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_10:
    // 0x80800BAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800BB0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80800BB4: jal         0x8010114C
    // 0x80800BB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_11;
    // 0x80800BB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80800BBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800BC0:
    // 0x80800BC0: jal         0x80100094
    // 0x80800BC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x80800BC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800BC8: lw          $t4, 0x6C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X6C);
    // 0x80800BCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800BD0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800BD4: andi        $t5, $t4, 0x1FF
    ctx->r13 = ctx->r12 & 0X1FF;
    // 0x80800BD8: beq         $t5, $zero, L_80800C54
    if (ctx->r13 == 0) {
        // 0x80800BDC: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_80800C54;
    }
    // 0x80800BDC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800BE0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800BE4: nop

    // 0x80800BE8: lwc1        $f12, 0x28($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X28);
L_80800BEC:
    // 0x80800BEC: jal         0x800DC178
    // 0x80800BF0: lwc1        $f14, 0x2C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X2C);
    func_800DC178(rdram, ctx);
        goto after_13;
    // 0x80800BF0: lwc1        $f14, 0x2C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X2C);
    after_13:
    // 0x80800BF4: div.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800BF8: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x80800BFC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800C00: jal         0x800EF334
    // 0x80800C04: nop

    func_800EF334(rdram, ctx);
        goto after_14;
    // 0x80800C04: nop

    after_14:
    // 0x80800C08: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80800C0C: jal         0x800DC178
    // 0x80800C10: lwc1        $f14, 0x18($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X18);
    func_800DC178(rdram, ctx);
        goto after_15;
    // 0x80800C10: lwc1        $f14, 0x18($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X18);
    after_15:
    // 0x80800C14: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80800C18: lwc1        $f14, 0x18($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80800C1C: jal         0x800DC178
    // 0x80800C20: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    func_800DC178(rdram, ctx);
        goto after_16;
    // 0x80800C20: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    after_16:
    // 0x80800C24: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80800C28: lwc1        $f14, 0x18($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80800C2C: jal         0x800DC178
    // 0x80800C30: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    func_800DC178(rdram, ctx);
        goto after_17;
    // 0x80800C30: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    after_17:
    // 0x80800C34: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80800C38: lw          $t6, 0x6C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X6C);
    // 0x80800C3C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800C40: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x80800C44: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800C48: sltu        $at, $s2, $t7
    ctx->r1 = ctx->r18 < ctx->r15 ? 1 : 0;
    // 0x80800C4C: bnel        $at, $zero, L_80800BEC
    if (ctx->r1 != 0) {
        // 0x80800C50: lwc1        $f12, 0x28($s1)
        ctx->f12.u32l = MEM_W(ctx->r17, 0X28);
            goto L_80800BEC;
    }
    goto skip_2;
    // 0x80800C50: lwc1        $f12, 0x28($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X28);
    skip_2:
L_80800C54:
    // 0x80800C54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C58: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800C5C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C60: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800C64: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800C68: jr          $ra
    // 0x80800C6C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800C6C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8080000C_chbadbeehive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800010: lbu         $t6, 0x762C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X762C);
    // 0x80800014: addiu       $t7, $t6, -0xF
    ctx->r15 = ADD32(ctx->r14, -0XF);
    // 0x80800018: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x8080001C: beq         $at, $zero, L_808000DC
    if (ctx->r1 == 0) {
        // 0x80800020: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808000DC;
    }
    // 0x80800020: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800024: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1760, 0XA20) << 16);
    // 0x80800028: addu        $at, $at, $t7
    gpr jr_addend_80800030 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080002C: lw          $t7, 0xA20($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1760, 0XA20));
    // 0x80800030: jr          $t7
    // 0x80800034: nop

    switch (jr_addend_80800030 >> 2) {
        case 0: goto L_80800058; break;
        case 1: goto L_80800048; break;
        case 2: goto L_808000DC; break;
        case 3: goto L_80800068; break;
        case 4: goto L_80800038; break;
        case 5: goto L_80800078; break;
        case 6: goto L_80800088; break;
        case 7: goto L_80800094; break;
        case 8: goto L_808000A4; break;
        case 9: goto L_808000B0; break;
        case 10: goto L_808000C0; break;
        case 11: goto L_808000CC; break;
        default: switch_error(__func__, 0x80800030, 0x80800A20);
    }
    // 0x80800034: nop

L_80800038:
    // 0x80800038: lui         $at, 0x43D2
    ctx->r1 = S32(0X43D2 << 16);
    // 0x8080003C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

L_80800048:
    // 0x80800048: lui         $at, 0x43DC
    ctx->r1 = S32(0X43DC << 16);
    // 0x8080004C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

L_80800058:
    // 0x80800058: lui         $at, 0x43E6
    ctx->r1 = S32(0X43E6 << 16);
    // 0x8080005C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

L_80800068:
    // 0x80800068: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x8080006C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

L_80800078:
    // 0x80800078: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8080007C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

L_80800088:
    // 0x80800088: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1760, 0XA50) << 16);
    // 0x8080008C: jr          $ra
    // 0x80800090: lwc1        $f0, 0xA50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1760, 0XA50));
    return;
    // 0x80800090: lwc1        $f0, 0xA50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1760, 0XA50));
L_80800094:
    // 0x80800094: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800098: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

L_808000A4:
    // 0x808000A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1760, 0XA54) << 16);
    // 0x808000A8: jr          $ra
    // 0x808000AC: lwc1        $f0, 0xA54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1760, 0XA54));
    return;
    // 0x808000AC: lwc1        $f0, 0xA54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1760, 0XA54));
L_808000B0:
    // 0x808000B0: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x808000B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

L_808000C0:
    // 0x808000C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1760, 0XA58) << 16);
    // 0x808000C4: jr          $ra
    // 0x808000C8: lwc1        $f0, 0xA58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1760, 0XA58));
    return;
    // 0x808000C8: lwc1        $f0, 0xA58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1760, 0XA58));
L_808000CC:
    // 0x808000CC: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x808000D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

L_808000DC:
    // 0x808000DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000E0: nop

    // 0x808000E4: jr          $ra
    // 0x808000E8: nop

    return;
    // 0x808000E8: nop

;}
RECOMP_FUNC void bswalk_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D9C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800DA0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(435, 0X1540) << 16);
    // 0x80800DA4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800DA8: jr          $ra
    // 0x80800DAC: lw          $v0, 0x1540($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(435, 0X1540));
    return;
    // 0x80800DAC: lw          $v0, 0x1540($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(435, 0X1540));
;}
RECOMP_FUNC void babounce_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x8080003C: jr          $ra
    // 0x80800040: lbu         $v0, 0xC($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XC);
    return;
    // 0x80800040: lbu         $v0, 0xC($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XC);
;}
RECOMP_FUNC void func_80800F8C_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F94: jal         0x800EA05C
    // 0x80800F98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800F98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800F9C: jal         0x800D3934
    // 0x80800FA0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800D3934(rdram, ctx);
        goto after_1;
    // 0x80800FA0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800FA4: bne         $v0, $zero, L_80800FB4
    if (ctx->r2 != 0) {
        // 0x80800FA8: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80800FB4;
    }
    // 0x80800FA8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800FAC: b           L_80800FE8
    // 0x80800FB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FE8;
    // 0x80800FB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800FB4:
    // 0x80800FB4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(924, 0X22E0) << 16);
    // 0x80800FB8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(924, 0X22E2) << 16);
    // 0x80800FBC: addiu       $a0, $a0, 0x22E2
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(924, 0X22E2));
    // 0x80800FC0: addiu       $v0, $v0, 0x22E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(924, 0X22E0));
    // 0x80800FC4: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
L_80800FC8:
    // 0x80800FC8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80800FCC: bne         $v1, $t6, L_80800FDC
    if (ctx->r3 != ctx->r14) {
        // 0x80800FD0: nop
    
            goto L_80800FDC;
    }
    // 0x80800FD0: nop

    // 0x80800FD4: b           L_80800FE8
    // 0x80800FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FE8;
    // 0x80800FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800FDC:
    // 0x80800FDC: bnel        $v0, $a0, L_80800FC8
    if (ctx->r2 != ctx->r4) {
        // 0x80800FE0: lhu         $t6, 0x0($v0)
        ctx->r14 = MEM_HU(ctx->r2, 0X0);
            goto L_80800FC8;
    }
    goto skip_0;
    // 0x80800FE0: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    skip_0:
    // 0x80800FE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800FE8:
    // 0x80800FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800FF0: jr          $ra
    // 0x80800FF4: nop

    return;
    // 0x80800FF4: nop

;}
RECOMP_FUNC void func_800F2E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2E60: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800F2E64: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800F2E68: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800F2E6C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800F2E70: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800F2E74: jr          $ra
    // 0x800F2E78: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    return;
    // 0x800F2E78: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80802484_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080248C: jal         0x800A3280
    // 0x80802490: nop

    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x80802490: nop

    after_0:
    // 0x80802494: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80802498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080249C: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XA890) << 16);
    // 0x808024A0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808024A4: lw          $v0, -0x5770($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XA890));
    // 0x808024A8: jr          $ra
    // 0x808024AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808024AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808005FC_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800604: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800608: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080060C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800610: jal         0x800F3BD0
    // 0x80800614: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800F3BD0(rdram, ctx);
        goto after_0;
    // 0x80800614: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80800618: jal         0x8009C984
    // 0x8080061C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x8080061C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800620: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800624: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800628: jal         0x800EEB9C
    // 0x8080062C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_2;
    // 0x8080062C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_2:
    // 0x80800630: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800634: jal         0x800EF04C
    // 0x80800638: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80800638: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x8080063C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800640: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800644: jr          $ra
    // 0x80800648: nop

    return;
    // 0x80800648: nop

;}
RECOMP_FUNC void _chfactoryrobot_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086228: syscall     291
    recomp_syscall_handler(rdram, ctx, 0x80086228);
    return;
    // 0x8008622C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80092880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092880: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092884: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80092888: sb          $a1, 0x80($t6)
    MEM_B(0X80, ctx->r14) = ctx->r5;
    // 0x8009288C: lw          $t8, 0x50($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X50);
    // 0x80092890: jr          $ra
    // 0x80092894: sb          $t7, 0x81($t8)
    MEM_B(0X81, ctx->r24) = ctx->r15;
    return;
    // 0x80092894: sb          $t7, 0x81($t8)
    MEM_B(0X81, ctx->r24) = ctx->r15;
;}
RECOMP_FUNC void func_80800AEC_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AEC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800AF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800AF8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800AFC: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80800B00: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(940, 0XE50) << 16);
    // 0x80800B04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B08: beq         $t6, $zero, L_80800B9C
    if (ctx->r14 == 0) {
        // 0x80800B0C: addiu       $a2, $a2, 0xE50
        ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(940, 0XE50));
            goto L_80800B9C;
    }
    // 0x80800B0C: addiu       $a2, $a2, 0xE50
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(940, 0XE50));
    // 0x80800B10: jal         0x8008A1F8
    // 0x80800B14: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800B14: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x80800B18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B1C: bnel        $v0, $at, L_80800BA0
    if (ctx->r2 != ctx->r1) {
        // 0x80800B20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BA0;
    }
    goto skip_0;
    // 0x80800B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800B24: jal         0x8010D254
    // 0x80800B28: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x80800B28: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80800B2C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800B30: jal         0x800EE7F8
    // 0x80800B34: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800B34: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80800B38: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800B3C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800B40: jal         0x800EF1B8
    // 0x80800B44: lui         $a2, 0x437F
    ctx->r6 = S32(0X437F << 16);
    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x80800B44: lui         $a2, 0x437F
    ctx->r6 = S32(0X437F << 16);
    after_3:
    // 0x80800B48: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800B4C: jal         0x800EEAD4
    // 0x80800B50: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EEAD4(rdram, ctx);
        goto after_4;
    // 0x80800B50: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80800B54: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800B58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800B5C: nop

    // 0x80800B60: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800B64: nop

    // 0x80800B68: bc1fl       L_80800BA0
    if (!c1cs) {
        // 0x80800B6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BA0;
    }
    goto skip_1;
    // 0x80800B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800B70: jal         0x80090708
    // 0x80800B74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_5;
    // 0x80800B74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80800B78: jal         0x8008F8B0
    // 0x80800B7C: nop

    func_8008F8B0(rdram, ctx);
        goto after_6;
    // 0x80800B7C: nop

    after_6:
    // 0x80800B80: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800B84: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80800B88: jal         0x8008F904
    // 0x80800B8C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8008F904(rdram, ctx);
        goto after_7;
    // 0x80800B8C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80800B90: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800B94: jal         0x8008F990
    // 0x80800B98: lui         $a1, 0x432A
    ctx->r5 = S32(0X432A << 16);
    func_8008F990(rdram, ctx);
        goto after_8;
    // 0x80800B98: lui         $a1, 0x432A
    ctx->r5 = S32(0X432A << 16);
    after_8:
L_80800B9C:
    // 0x80800B9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BA0:
    // 0x80800BA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BA4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800BA8: jr          $ra
    // 0x80800BAC: nop

    return;
    // 0x80800BAC: nop

;}
RECOMP_FUNC void _chdiggerboss_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867D8: syscall     377
    recomp_syscall_handler(rdram, ctx, 0x800867D8);
    return;
    // 0x800867DC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800584_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800584: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800588: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080058C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80800590: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80800594: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800598: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080059C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005A0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x808005A4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x808005A8: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x808005AC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808005B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x808005B4: jal         0x80800128
    // 0x808005B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80800128_ncpoddialog(rdram, ctx);
        goto after_0;
    // 0x808005B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x808005BC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x808005C0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808005C4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808005C8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x808005CC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808005D0: bnel        $t7, $zero, L_80800608
    if (ctx->r15 != 0) {
        // 0x808005D4: lwc1        $f18, 0x0($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
            goto L_80800608;
    }
    goto skip_0;
    // 0x808005D4: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x808005D8: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x808005DC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808005E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808005E4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x808005E8: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x808005EC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808005F0: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x808005F4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808005F8: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x808005FC: b           L_80800680
    // 0x80800600: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_80800680;
    // 0x80800600: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80800604: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
L_80800608:
    // 0x80800608: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8080060C: nop

    // 0x80800610: bc1fl       L_80800624
    if (!c1cs) {
        // 0x80800614: lwc1        $f4, 0x0($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
            goto L_80800624;
    }
    goto skip_1;
    // 0x80800614: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80800618: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x8080061C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800620: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
L_80800624:
    // 0x80800624: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800628: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080062C: nop

    // 0x80800630: bc1fl       L_80800644
    if (!c1cs) {
        // 0x80800634: lwc1        $f8, 0x34($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80800644;
    }
    goto skip_2;
    // 0x80800634: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80800638: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x8080063C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800640: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
L_80800644:
    // 0x80800644: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800648: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8080064C: nop

    // 0x80800650: bc1fl       L_80800664
    if (!c1cs) {
        // 0x80800654: lwc1        $f18, 0x4($s1)
        ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
            goto L_80800664;
    }
    goto skip_3;
    // 0x80800654: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    skip_3:
    // 0x80800658: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8080065C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800660: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
L_80800664:
    // 0x80800664: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800668: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8080066C: nop

    // 0x80800670: bc1fl       L_80800684
    if (!c1cs) {
        // 0x80800674: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800684;
    }
    goto skip_4;
    // 0x80800674: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80800678: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x8080067C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800680:
    // 0x80800680: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800684:
    // 0x80800684: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800688: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080068C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800690: jr          $ra
    // 0x80800694: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800694: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80801448_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080144C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801450: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801454: jal         0x800BEA88
    // 0x80801458: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_0;
    // 0x80801458: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8080145C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80801460: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80801464: addiu       $a2, $a2, 0x5B18
    ctx->r6 = ADD32(ctx->r6, 0X5B18);
    // 0x80801468: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080146C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801470: jal         0x80088660
    // 0x80801474: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801474: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x80801478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080147C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801480: jr          $ra
    // 0x80801484: nop

    return;
    // 0x80801484: nop

;}
RECOMP_FUNC void func_80800100_bsbbilldrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: jal         0x80092BF4
    // 0x8080010C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80092BF4(rdram, ctx);
        goto after_0;
    // 0x8080010C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800110: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800114: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800118: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8080011C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800120: nop

    // 0x80800124: bc1fl       L_80800138
    if (!c1cs) {
        // 0x80800128: neg.s       $f2, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
            goto L_80800138;
    }
    goto skip_0;
    // 0x80800128: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    skip_0:
    // 0x8080012C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800130: nop

    // 0x80800134: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80800138:
    // 0x80800138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080013C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800140: jal         0x80093300
    // 0x80800144: nop

    func_80093300(rdram, ctx);
        goto after_1;
    // 0x80800144: nop

    after_1:
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080014C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800150: jr          $ra
    // 0x80800154: nop

    return;
    // 0x80800154: nop

;}
RECOMP_FUNC void subaddieDll_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808004E8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808004EC: lh          $a1, 0x4($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X4);
    // 0x808004F0: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    // 0x808004F4: jal         0x800DC128
    // 0x808004F8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x808004F8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808004FC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800500: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800504: sh          $v0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r2;
    // 0x80800508: lh          $a1, 0x6($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X6);
    // 0x8080050C: jal         0x800DC128
    // 0x80800510: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80800510: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    after_1:
    // 0x80800514: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800518: sh          $v0, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r2;
    // 0x8080051C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800524: jr          $ra
    // 0x80800528: nop

    return;
    // 0x80800528: nop

    // 0x8080052C: nop

;}
RECOMP_FUNC void func_80803E84_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803E84: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80803E88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803E8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80803E90: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80803E94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803E98: jal         0x8008CABC
    // 0x80803E9C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80803E9C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_0:
    // 0x80803EA0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80803EA4: jal         0x80807BB8
    // 0x80803EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80803EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80803EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803EB0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80803EB4: jal         0x808026AC
    // 0x80803EB8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_808026AC_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80803EB8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80803EBC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80803EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803EC4: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x80803EC8: jal         0x80800424
    // 0x80803ECC: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    func_80800424_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80803ECC: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    after_3:
    // 0x80803ED0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80803ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803ED8: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    // 0x80803EDC: jal         0x8008CCBC
    // 0x80803EE0: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_4;
    // 0x80803EE0: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    after_4:
    // 0x80803EE4: lui         $a2, 0x3EDC
    ctx->r6 = S32(0X3EDC << 16);
    // 0x80803EE8: ori         $a2, $a2, 0x28F6
    ctx->r6 = ctx->r6 | 0X28F6;
    // 0x80803EEC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80803EF0: jal         0x8008B1D4
    // 0x80803EF4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_5;
    // 0x80803EF4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80803EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803EFC: jal         0x80802A40
    // 0x80803F00: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80802A40_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80803F00: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_6:
    // 0x80803F04: bne         $v0, $zero, L_80803F14
    if (ctx->r2 != 0) {
        // 0x80803F08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803F14;
    }
    // 0x80803F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803F0C: jal         0x8009D89C
    // 0x80803F10: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009D89C(rdram, ctx);
        goto after_7;
    // 0x80803F10: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_7:
L_80803F14:
    // 0x80803F14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803F18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80803F1C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80803F20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803F24: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803F28: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80803F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803F30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80803F34: jal         0x800854E0
    // 0x80803F38: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _bainvisible_entrypoint_7(rdram, ctx);
        goto after_8;
    // 0x80803F38: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80803F3C: jal         0x80808F38
    // 0x80803F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808F38_bsfirstp(rdram, ctx);
        goto after_9;
    // 0x80803F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80803F44: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80803F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803F4C: lui         $a1, 0x3FA0
    ctx->r5 = S32(0X3FA0 << 16);
    // 0x80803F50: jal         0x8009BDAC
    // 0x80803F54: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    func_8009BDAC(rdram, ctx);
        goto after_10;
    // 0x80803F54: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    after_10:
    // 0x80803F58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80803F5C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80803F60: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80803F64: jr          $ra
    // 0x80803F68: nop

    return;
    // 0x80803F68: nop

;}
RECOMP_FUNC void func_80800748_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800748: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080074C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800750: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800754: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800758: jal         0x800DA524
    // 0x8080075C: addiu       $a0, $zero, 0x9FE
    ctx->r4 = ADD32(0, 0X9FE);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x8080075C: addiu       $a0, $zero, 0x9FE
    ctx->r4 = ADD32(0, 0X9FE);
    after_0:
    // 0x80800760: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x80800764: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800768: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080076C: srl         $t6, $a1, 10
    ctx->r14 = S32(U32(ctx->r5) >> 10);
    // 0x80800770: beq         $t6, $at, L_80800794
    if (ctx->r14 == ctx->r1) {
        // 0x80800774: addiu       $a1, $zero, 0xFA
        ctx->r5 = ADD32(0, 0XFA);
            goto L_80800794;
    }
    // 0x80800774: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x80800778: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080077C: beq         $t6, $at, L_80800924
    if (ctx->r14 == ctx->r1) {
        // 0x80800780: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800924;
    }
    // 0x80800780: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800784: beq         $t6, $at, L_808009DC
    if (ctx->r14 == ctx->r1) {
        // 0x80800788: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009DC;
    }
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080078C: b           L_808009F0
    // 0x80800790: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
        goto L_808009F0;
    // 0x80800790: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
L_80800794:
    // 0x80800794: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80800798: addiu       $a3, $zero, -0x32
    ctx->r7 = ADD32(0, -0X32);
    // 0x8080079C: jal         0x8010C9FC
    // 0x808007A0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_8010C9FC(rdram, ctx);
        goto after_1;
    // 0x808007A0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_1:
    // 0x808007A4: beql        $v0, $zero, L_808009F0
    if (ctx->r2 == 0) {
        // 0x808007A8: lw          $t0, 0x64($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X64);
            goto L_808009F0;
    }
    goto skip_0;
    // 0x808007A8: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x808007AC: jal         0x808000B4
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B4_chwarppad(rdram, ctx);
        goto after_2;
    // 0x808007B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808007B4: jal         0x800F54E4
    // 0x808007B8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808007B8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_3:
    // 0x808007BC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808007C0: jal         0x80800380
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800380_chwarppad(rdram, ctx);
        goto after_4;
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808007C8: bne         $v0, $zero, L_808007E4
    if (ctx->r2 != 0) {
        // 0x808007CC: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_808007E4;
    }
    // 0x808007CC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D4: jal         0x80800418
    // 0x808007D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800418_chwarppad(rdram, ctx);
        goto after_5;
    // 0x808007D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808007DC: b           L_808009F0
    // 0x808007E0: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
        goto L_808009F0;
    // 0x808007E0: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
L_808007E4:
    // 0x808007E4: blez        $t7, L_80800850
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808007E8: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800850;
    }
    // 0x808007E8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808007EC: lhu         $t0, 0x76($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X76);
    // 0x808007F0: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x808007F4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(780, 0XE60) << 16);
    // 0x808007F8: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x808007FC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80800800: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800804: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80800808: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8080080C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800810: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800814: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80800818: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x8080081C: jal         0x800F64A4
    // 0x80800820: lw          $a1, 0xE60($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(780, 0XE60));
    func_800F64A4(rdram, ctx);
        goto after_6;
    // 0x80800820: lw          $a1, 0xE60($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(780, 0XE60));
    after_6:
    // 0x80800824: bne         $v0, $zero, L_80800850
    if (ctx->r2 != 0) {
        // 0x80800828: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800850;
    }
    // 0x80800828: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080082C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80800830: jal         0x8008A1D0
    // 0x80800834: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800834: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x80800838: beq         $v0, $zero, L_80800850
    if (ctx->r2 == 0) {
        // 0x8080083C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800850;
    }
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800840: jal         0x80800418
    // 0x80800844: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800418_chwarppad(rdram, ctx);
        goto after_8;
    // 0x80800844: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80800848: b           L_808009F0
    // 0x8080084C: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
        goto L_808009F0;
    // 0x8080084C: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
L_80800850:
    // 0x80800850: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800854: jal         0x80016B30
    // 0x80800858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_9;
    // 0x80800858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8080085C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800860: bnel        $v0, $at, L_808009F0
    if (ctx->r2 != ctx->r1) {
        // 0x80800864: lw          $t0, 0x64($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X64);
            goto L_808009F0;
    }
    goto skip_1;
    // 0x80800864: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    skip_1:
    // 0x80800868: jal         0x800F8004
    // 0x8080086C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800F8004(rdram, ctx);
        goto after_10;
    // 0x8080086C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_10:
    // 0x80800870: bne         $v0, $zero, L_808009EC
    if (ctx->r2 != 0) {
        // 0x80800874: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808009EC;
    }
    // 0x80800874: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800878: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8080087C: jal         0x800F4BB8
    // 0x80800880: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800F4BB8(rdram, ctx);
        goto after_11;
    // 0x80800880: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_11:
    // 0x80800884: beq         $v0, $zero, L_808009EC
    if (ctx->r2 == 0) {
        // 0x80800888: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_808009EC;
    }
    // 0x80800888: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8080088C: blez        $t4, L_808008F0
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80800890: addiu       $t2, $zero, 0xCEF
        ctx->r10 = ADD32(0, 0XCEF);
            goto L_808008F0;
    }
    // 0x80800890: addiu       $t2, $zero, 0xCEF
    ctx->r10 = ADD32(0, 0XCEF);
    // 0x80800894: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
    // 0x80800898: lw          $t5, 0x28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28);
    // 0x8080089C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(780, 0XE60) << 16);
    // 0x808008A0: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x808008A4: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x808008A8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x808008AC: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x808008B0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x808008B4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808008B8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808008BC: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x808008C0: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x808008C4: lw          $a1, 0xE60($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(780, 0XE60));
    // 0x808008C8: jal         0x800F64A4
    // 0x808008CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800F64A4(rdram, ctx);
        goto after_12;
    // 0x808008CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_12:
    // 0x808008D0: beq         $v0, $zero, L_808008E8
    if (ctx->r2 == 0) {
        // 0x808008D4: addiu       $t9, $zero, 0xCF0
        ctx->r25 = ADD32(0, 0XCF0);
            goto L_808008E8;
    }
    // 0x808008D4: addiu       $t9, $zero, 0xCF0
    ctx->r25 = ADD32(0, 0XCF0);
    // 0x808008D8: jal         0x808006C0
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006C0_chwarppad(rdram, ctx);
        goto after_13;
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808008E0: b           L_808008F4
    // 0x808008E4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_808008F4;
    // 0x808008E4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_808008E8:
    // 0x808008E8: b           L_808008F4
    // 0x808008EC: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
        goto L_808008F4;
    // 0x808008EC: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_808008F0:
    // 0x808008F0: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_808008F4:
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808008FC: jal         0x80800F34
    // 0x80800900: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800F34_chwarppad(rdram, ctx);
        goto after_14;
    // 0x80800900: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x80800904: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800908: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080090C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800910: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800914: jal         0x8008A208
    // 0x80800918: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x80800918: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x8080091C: b           L_808009F0
    // 0x80800920: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
        goto L_808009F0;
    // 0x80800920: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
L_80800924:
    // 0x80800924: jal         0x800DA298
    // 0x80800928: addiu       $a0, $zero, 0x3EE
    ctx->r4 = ADD32(0, 0X3EE);
    func_800DA298(rdram, ctx);
        goto after_16;
    // 0x80800928: addiu       $a0, $zero, 0x3EE
    ctx->r4 = ADD32(0, 0X3EE);
    after_16:
    // 0x8080092C: bne         $v0, $zero, L_808009B8
    if (ctx->r2 != 0) {
        // 0x80800930: nop
    
            goto L_808009B8;
    }
    // 0x80800930: nop

    // 0x80800934: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80800938: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x8080093C: bltz        $t5, L_808009B8
    if (SIGNED(ctx->r13) < 0) {
        // 0x80800940: nop
    
            goto L_808009B8;
    }
    // 0x80800940: nop

    // 0x80800944: jal         0x808000B4
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B4_chwarppad(rdram, ctx);
        goto after_17;
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080094C: bne         $v0, $zero, L_8080095C
    if (ctx->r2 != 0) {
        // 0x80800950: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_8080095C;
    }
    // 0x80800950: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80800954: b           L_80800960
    // 0x80800958: addiu       $a1, $zero, 0xCED
    ctx->r5 = ADD32(0, 0XCED);
        goto L_80800960;
    // 0x80800958: addiu       $a1, $zero, 0xCED
    ctx->r5 = ADD32(0, 0XCED);
L_8080095C:
    // 0x8080095C: addiu       $a1, $zero, 0xCEE
    ctx->r5 = ADD32(0, 0XCEE);
L_80800960:
    // 0x80800960: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800964: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800968: jal         0x8008A208
    // 0x8080096C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x8080096C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_18:
    // 0x80800970: beq         $v0, $zero, L_808009B8
    if (ctx->r2 == 0) {
        // 0x80800974: nop
    
            goto L_808009B8;
    }
    // 0x80800974: nop

    // 0x80800978: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800980: ori         $t6, $t8, 0x40
    ctx->r14 = ctx->r24 | 0X40;
    // 0x80800984: jal         0x808003B8
    // 0x80800988: sb          $t6, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r14;
    func_808003B8_chwarppad(rdram, ctx);
        goto after_19;
    // 0x80800988: sb          $t6, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r14;
    after_19:
    // 0x8080098C: jal         0x800F54E4
    // 0x80800990: nop

    func_800F54E4(rdram, ctx);
        goto after_20;
    // 0x80800990: nop

    after_20:
    // 0x80800994: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    // 0x80800998: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x8080099C: jal         0x800F64A4
    // 0x808009A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F64A4(rdram, ctx);
        goto after_21;
    // 0x808009A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
    // 0x808009A4: bne         $v0, $zero, L_808009B8
    if (ctx->r2 != 0) {
        // 0x808009A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009B8;
    }
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808009B0: jal         0x80800F34
    // 0x808009B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800F34_chwarppad(rdram, ctx);
        goto after_22;
    // 0x808009B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_22:
L_808009B8:
    // 0x808009B8: jal         0x80089C90
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_23;
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808009C0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x808009C4: bne         $v0, $at, L_808009EC
    if (ctx->r2 != ctx->r1) {
        // 0x808009C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009EC;
    }
    // 0x808009C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009CC: jal         0x80800418
    // 0x808009D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800418_chwarppad(rdram, ctx);
        goto after_24;
    // 0x808009D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x808009D4: b           L_808009F0
    // 0x808009D8: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
        goto L_808009F0;
    // 0x808009D8: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
L_808009DC:
    // 0x808009DC: jal         0x80100094
    // 0x808009E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_25;
    // 0x808009E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x808009E4: jal         0x80087C98
    // 0x808009E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcnewoption_entrypoint_0(rdram, ctx);
        goto after_26;
    // 0x808009E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_26:
L_808009EC:
    // 0x808009EC: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
L_808009F0:
    // 0x808009F0: sll         $t9, $t0, 12
    ctx->r25 = S32(ctx->r8 << 12);
    // 0x808009F4: bgezl       $t9, L_80800A0C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808009F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800A0C;
    }
    goto skip_2;
    // 0x808009F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808009FC: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800A00: andi        $t3, $t2, 0xFFF7
    ctx->r11 = ctx->r10 & 0XFFF7;
    // 0x80800A04: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x80800A08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A0C:
    // 0x80800A0C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800A10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800A14: jr          $ra
    // 0x80800A18: nop

    return;
    // 0x80800A18: nop

;}
RECOMP_FUNC void _chklungo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863A8: syscall     316
    recomp_syscall_handler(rdram, ctx, 0x800863A8);
    return;
    // 0x800863AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800544_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800544: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080054C: jal         0x800F54E4
    // 0x80800550: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800550: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800554: jal         0x800F5410
    // 0x80800558: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x80800558: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080055C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800560: beq         $v0, $at, L_8080057C
    if (ctx->r2 == ctx->r1) {
        // 0x80800564: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080057C;
    }
    // 0x80800564: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800568: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8080056C: beq         $v0, $at, L_80800594
    if (ctx->r2 == ctx->r1) {
        // 0x80800570: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800594;
    }
    // 0x80800570: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800574: b           L_808005AC
    // 0x80800578: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_808005AC;
    // 0x80800578: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8080057C:
    // 0x8080057C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1236, 0X12C4) << 16);
    // 0x80800580: addiu       $a1, $a1, 0x12C4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1236, 0X12C4));
    // 0x80800584: jal         0x800C4AF0
    // 0x80800588: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800C4AF0(rdram, ctx);
        goto after_2;
    // 0x80800588: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x8080058C: b           L_808005BC
    // 0x80800590: nop

        goto L_808005BC;
    // 0x80800590: nop

L_80800594:
    // 0x80800594: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1236, 0X12D4) << 16);
    // 0x80800598: addiu       $a1, $a1, 0x12D4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1236, 0X12D4));
    // 0x8080059C: jal         0x800C4AF0
    // 0x808005A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800C4AF0(rdram, ctx);
        goto after_3;
    // 0x808005A0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x808005A4: b           L_808005BC
    // 0x808005A8: nop

        goto L_808005BC;
    // 0x808005A8: nop

L_808005AC:
    // 0x808005AC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1236, 0X12E4) << 16);
    // 0x808005B0: addiu       $a1, $a1, 0x12E4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1236, 0X12E4));
    // 0x808005B4: jal         0x800C4AF0
    // 0x808005B8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800C4AF0(rdram, ctx);
        goto after_4;
    // 0x808005B8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_4:
L_808005BC:
    // 0x808005BC: jal         0x800F54E4
    // 0x808005C0: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x808005C0: nop

    after_5:
    // 0x808005C4: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x808005C8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808005CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808005D4: jal         0x800F7620
    // 0x808005D8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_800F7620(rdram, ctx);
        goto after_6;
    // 0x808005D8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_6:
    // 0x808005DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005E4: jr          $ra
    // 0x808005E8: nop

    return;
    // 0x808005E8: nop

;}
RECOMP_FUNC void func_80800000_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80100094
    // 0x80800010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800014: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800018: jal         0x808003A8
    // 0x8080001C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808003A8_chclinker(rdram, ctx);
        goto after_1;
    // 0x8080001C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800020: jal         0x800D395C
    // 0x80800024: nop

    func_800D395C(rdram, ctx);
        goto after_2;
    // 0x80800024: nop

    after_2:
    // 0x80800028: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8080002C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x80800030: jal         0x800D0A9C
    // 0x80800034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_3;
    // 0x80800034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800038: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080003C: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800040: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800044: bnel        $t6, $zero, L_80800058
    if (ctx->r14 != 0) {
        // 0x80800048: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80800058;
    }
    goto skip_0;
    // 0x80800048: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    skip_0:
    // 0x8080004C: beq         $t7, $zero, L_80800060
    if (ctx->r15 == 0) {
        // 0x80800050: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_80800060;
    }
    // 0x80800050: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800054: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80800058:
    // 0x80800058: b           L_80800078
    // 0x8080005C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
        goto L_80800078;
    // 0x8080005C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
L_80800060:
    // 0x80800060: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80800064: jal         0x8010A570
    // 0x80800068: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x80800068: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8080006C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800070: jal         0x80103110
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_5;
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_80800078:
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080007C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

;}
RECOMP_FUNC void func_80800804_chbeanstalkseed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800804: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800808: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080080C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800810: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800814: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800818: beq         $a1, $at, L_8080084C
    if (ctx->r5 == ctx->r1) {
        // 0x8080081C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8080084C;
    }
    // 0x8080081C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800820: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800824: beq         $a1, $at, L_8080085C
    if (ctx->r5 == ctx->r1) {
        // 0x80800828: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080085C;
    }
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800830: beq         $a1, $at, L_80800890
    if (ctx->r5 == ctx->r1) {
        // 0x80800834: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800890;
    }
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800838: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080083C: beql        $a1, $at, L_80800904
    if (ctx->r5 == ctx->r1) {
        // 0x80800840: lhu         $a0, 0x76($s0)
        ctx->r4 = MEM_HU(ctx->r16, 0X76);
            goto L_80800904;
    }
    goto skip_0;
    // 0x80800840: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    skip_0:
    // 0x80800844: b           L_80800934
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800934;
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080084C:
    // 0x8080084C: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800850: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80800854: b           L_80800930
    // 0x80800858: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
        goto L_80800930;
    // 0x80800858: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_8080085C:
    // 0x8080085C: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800860: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80800864: addiu       $a1, $zero, 0x8CF
    ctx->r5 = ADD32(0, 0X8CF);
    // 0x80800868: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8080086C: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800870: jal         0x80103140
    // 0x80800874: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x80800874: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    after_0:
    // 0x80800878: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x8080087C: srl         $t3, $a0, 7
    ctx->r11 = S32(U32(ctx->r4) >> 7);
    // 0x80800880: jal         0x800DA544
    // 0x80800884: addiu       $a0, $t3, 0x323
    ctx->r4 = ADD32(ctx->r11, 0X323);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800884: addiu       $a0, $t3, 0x323
    ctx->r4 = ADD32(ctx->r11, 0X323);
    after_1:
    // 0x80800888: b           L_80800934
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800934;
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800890:
    // 0x80800890: jal         0x8008A4B0
    // 0x80800894: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800894: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800898: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A0: addiu       $a1, $zero, 0x8DD
    ctx->r5 = ADD32(0, 0X8DD);
    // 0x808008A4: jal         0x80103140
    // 0x808008A8: lhu         $a2, 0x16($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X16);
    func_80103140(rdram, ctx);
        goto after_3;
    // 0x808008A8: lhu         $a2, 0x16($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X16);
    after_3:
    // 0x808008AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808008B0: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x808008B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2356, 0XBB8) << 16);
    // 0x808008B8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x808008BC: lwc1        $f6, 0xBB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XBB8));
    // 0x808008C0: srl         $t5, $a2, 7
    ctx->r13 = S32(U32(ctx->r6) >> 7);
    // 0x808008C4: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x808008C8: addiu       $a2, $t6, -0x58
    ctx->r6 = ADD32(ctx->r14, -0X58);
    // 0x808008CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808008D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008D4: addiu       $a3, $zero, 0x6810
    ctx->r7 = ADD32(0, 0X6810);
    // 0x808008D8: jal         0x80085708
    // 0x808008DC: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x808008DC: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x808008E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808008E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808008E8: lui         $a0, 0x3FFB
    ctx->r4 = S32(0X3FFB << 16);
    // 0x808008EC: ori         $a0, $a0, 0x5C1D
    ctx->r4 = ctx->r4 | 0X5C1D;
    // 0x808008F0: jal         0x800C3F48
    // 0x808008F4: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    func_800C3F48(rdram, ctx);
        goto after_5;
    // 0x808008F4: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    after_5:
    // 0x808008F8: b           L_80800934
    // 0x808008FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800934;
    // 0x808008FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800900: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
L_80800904:
    // 0x80800904: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x80800908: jal         0x800DA544
    // 0x8080090C: addiu       $a0, $t7, 0x325
    ctx->r4 = ADD32(ctx->r15, 0X325);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x8080090C: addiu       $a0, $t7, 0x325
    ctx->r4 = ADD32(ctx->r15, 0X325);
    after_6:
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800914: jal         0x8008A4B0
    // 0x80800918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8080091C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800920: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800928: jal         0x8010A63C
    // 0x8080092C: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    func_8010A63C(rdram, ctx);
        goto after_8;
    // 0x8080092C: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    after_8:
L_80800930:
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800934:
    // 0x80800934: jal         0x80102424
    // 0x80800938: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800938: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x8080093C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800940: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800944: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800948: jr          $ra
    // 0x8080094C: nop

    return;
    // 0x8080094C: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B78: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B78);
    return;
    // 0x80087B7C: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_801039E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801039E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801039E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801039EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801039F0: jal         0x80103964
    // 0x801039F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80103964(rdram, ctx);
        goto after_0;
    // 0x801039F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x801039F8: bne         $v0, $zero, L_80103A08
    if (ctx->r2 != 0) {
        // 0x801039FC: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80103A08;
    }
    // 0x801039FC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80103A00: b           L_80103A8C
    // 0x80103A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103A8C;
    // 0x80103A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80103A08:
    // 0x80103A08: jal         0x80106790
    // 0x80103A0C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80103A0C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80103A10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80103A14: jal         0x80103D48
    // 0x80103A18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80103D48(rdram, ctx);
        goto after_2;
    // 0x80103A18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80103A1C: jal         0x80103508
    // 0x80103A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103508(rdram, ctx);
        goto after_3;
    // 0x80103A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80103A24: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x80103A28: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80103A2C: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80103A30: bne         $t7, $zero, L_80103A80
    if (ctx->r15 != 0) {
        // 0x80103A34: nop
    
            goto L_80103A80;
    }
    // 0x80103A34: nop

    // 0x80103A38: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80103A3C: bne         $t9, $zero, L_80103A80
    if (ctx->r25 != 0) {
        // 0x80103A40: nop
    
            goto L_80103A80;
    }
    // 0x80103A40: nop

    // 0x80103A44: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x80103A48: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80103A4C: sll         $t3, $t1, 30
    ctx->r11 = S32(ctx->r9 << 30);
    // 0x80103A50: bgezl       $t3, L_80103A78
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80103A54: lbu         $t5, 0x74($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X74);
            goto L_80103A78;
    }
    goto skip_0;
    // 0x80103A54: lbu         $t5, 0x74($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X74);
    skip_0:
    // 0x80103A58: jal         0x800B2824
    // 0x80103A5C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800B2824(rdram, ctx);
        goto after_4;
    // 0x80103A5C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80103A60: beq         $v0, $zero, L_80103A74
    if (ctx->r2 == 0) {
        // 0x80103A64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80103A74;
    }
    // 0x80103A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80103A68: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80103A6C: jal         0x80089FF0
    // 0x80103A70: addiu       $a1, $a1, -0x6008
    ctx->r5 = ADD32(ctx->r5, -0X6008);
    _subaddiecustomhits_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80103A70: addiu       $a1, $a1, -0x6008
    ctx->r5 = ADD32(ctx->r5, -0X6008);
    after_5:
L_80103A74:
    // 0x80103A74: lbu         $t5, 0x74($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X74);
L_80103A78:
    // 0x80103A78: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x80103A7C: sb          $t6, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r14;
L_80103A80:
    // 0x80103A80: jal         0x80103D70
    // 0x80103A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103D70(rdram, ctx);
        goto after_6;
    // 0x80103A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80103A88: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80103A8C:
    // 0x80103A8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80103A90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80103A94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80103A98: jr          $ra
    // 0x80103A9C: nop

    return;
    // 0x80103A9C: nop

;}
RECOMP_FUNC void _badrone_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084820: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084820);
    return;
    // 0x80084824: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bsbegghead_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828F8: syscall     19
    recomp_syscall_handler(rdram, ctx, 0x800828F8);
    return;
    // 0x800828FC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800080_chsounder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: jr          $ra
    // 0x80800084: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800084: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800F3C_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800F48: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800F4C: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x80800F50: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800F54: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800F58: beq         $v0, $zero, L_80800F84
    if (ctx->r2 == 0) {
        // 0x80800F5C: addiu       $a1, $zero, 0x10
        ctx->r5 = ADD32(0, 0X10);
            goto L_80800F84;
    }
    // 0x80800F5C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800F60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F64: beq         $v0, $at, L_80800F9C
    if (ctx->r2 == ctx->r1) {
        // 0x80800F68: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800F9C;
    }
    // 0x80800F68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800F6C: beq         $v0, $at, L_80800F94
    if (ctx->r2 == ctx->r1) {
        // 0x80800F70: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800F94;
    }
    // 0x80800F70: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800F74: beql        $v0, $at, L_80800F98
    if (ctx->r2 == ctx->r1) {
        // 0x80800F78: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800F98;
    }
    goto skip_0;
    // 0x80800F78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_0:
    // 0x80800F7C: b           L_80800FB0
    // 0x80800F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800FB0;
    // 0x80800F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F84:
    // 0x80800F84: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800F88: jal         0x800856B0
    // 0x80800F8C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800F8C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800F90: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80800F94:
    // 0x80800F94: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80800F98:
    // 0x80800F98: sw          $t6, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r14;
L_80800F9C:
    // 0x80800F9C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800FA0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FA4: jal         0x800856D0
    // 0x80800FA8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800FA8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800FB0:
    // 0x80800FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FB4: jr          $ra
    // 0x80800FB8: nop

    return;
    // 0x80800FB8: nop

;}
RECOMP_FUNC void bstrexsmall_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C14: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800C18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800C1C: jal         0x8009C128
    // 0x80800C20: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800C20: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80800C24: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80800C28: jal         0x800EFC7C
    // 0x80800C2C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EFC7C(rdram, ctx);
        goto after_1;
    // 0x80800C2C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800C30: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(416, 0X1AD4) << 16);
    // 0x80800C34: lwc1        $f4, 0x1AD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(416, 0X1AD4));
    // 0x80800C38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(416, 0X1AD8) << 16);
    // 0x80800C3C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800C40: nop

    // 0x80800C44: bc1f        L_80800C54
    if (!c1cs) {
        // 0x80800C48: nop
    
            goto L_80800C54;
    }
    // 0x80800C48: nop

    // 0x80800C4C: b           L_80800C94
    // 0x80800C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800C94;
    // 0x80800C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C54:
    // 0x80800C54: lwc1        $f6, 0x1AD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(416, 0X1AD8));
    // 0x80800C58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800C5C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C60: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800C64: nop

    // 0x80800C68: bc1f        L_80800C78
    if (!c1cs) {
        // 0x80800C6C: nop
    
            goto L_80800C78;
    }
    // 0x80800C6C: nop

    // 0x80800C70: b           L_80800C94
    // 0x80800C74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800C94;
    // 0x80800C74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C78:
    // 0x80800C78: jal         0x8008DAE8
    // 0x80800C7C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    func_8008DAE8(rdram, ctx);
        goto after_2;
    // 0x80800C7C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_2:
    // 0x80800C80: bnel        $v0, $zero, L_80800C94
    if (ctx->r2 != 0) {
        // 0x80800C84: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800C94;
    }
    goto skip_0;
    // 0x80800C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800C88: b           L_80800C94
    // 0x80800C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800C94;
    // 0x80800C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800C90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C94:
    // 0x80800C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800C9C: jr          $ra
    // 0x80800CA0: nop

    return;
    // 0x80800CA0: nop

;}
RECOMP_FUNC void func_800961AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800961AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800961B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800961B4: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    // 0x800961B8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800961BC: lw          $v1, 0x9C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C);
    // 0x800961C0: beq         $v1, $at, L_800961D8
    if (ctx->r3 == ctx->r1) {
        // 0x800961C4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800961D8;
    }
    // 0x800961C4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800961C8: beql        $v1, $at, L_800961F8
    if (ctx->r3 == ctx->r1) {
        // 0x800961CC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800961F8;
    }
    goto skip_0;
    // 0x800961CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x800961D0: b           L_80096210
    // 0x800961D4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
        goto L_80096210;
    // 0x800961D4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_800961D8:
    // 0x800961D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800961DC: jal         0x80097858
    // 0x800961E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80097858(rdram, ctx);
        goto after_0;
    // 0x800961E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800961E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800961E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800961EC: b           L_8009620C
    // 0x800961F0: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
        goto L_8009620C;
    // 0x800961F0: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    // 0x800961F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_800961F8:
    // 0x800961F8: jal         0x80084D58
    // 0x800961FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _bahitspline_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x800961FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80096200: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80096204: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80096208: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
L_8009620C:
    // 0x8009620C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_80096210:
    // 0x80096210: beq         $a1, $at, L_8009622C
    if (ctx->r5 == ctx->r1) {
        // 0x80096214: sw          $a1, 0x9C($v0)
        MEM_W(0X9C, ctx->r2) = ctx->r5;
            goto L_8009622C;
    }
    // 0x80096214: sw          $a1, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r5;
    // 0x80096218: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8009621C: beq         $a1, $at, L_8009623C
    if (ctx->r5 == ctx->r1) {
        // 0x80096220: nop
    
            goto L_8009623C;
    }
    // 0x80096220: nop

    // 0x80096224: b           L_80096248
    // 0x80096228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80096248;
    // 0x80096228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009622C:
    // 0x8009622C: jal         0x8009788C
    // 0x80096230: nop

    func_8009788C(rdram, ctx);
        goto after_2;
    // 0x80096230: nop

    after_2:
    // 0x80096234: b           L_80096248
    // 0x80096238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80096248;
    // 0x80096238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009623C:
    // 0x8009623C: jal         0x80084D60
    // 0x80096240: nop

    _bahitspline_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80096240: nop

    after_3:
    // 0x80096244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80096248:
    // 0x80096248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009624C: jr          $ra
    // 0x80096250: nop

    return;
    // 0x80096250: nop

;}
RECOMP_FUNC void func_808003B0_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X49B8) << 16);
    // 0x808003B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003B8: lwc1        $f12, 0x49B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X49B8));
    // 0x808003BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X49BC) << 16);
    // 0x808003C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003C8: jal         0x800DC178
    // 0x808003CC: lwc1        $f14, 0x49BC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X49BC));
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x808003CC: lwc1        $f14, 0x49BC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X49BC));
    after_0:
    // 0x808003D0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x808003D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808003D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X49C0) << 16);
    // 0x808003DC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x808003E0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x808003E4: lwc1        $f12, 0x49C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X49C0));
    // 0x808003E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X49C4) << 16);
    // 0x808003EC: jal         0x800DC178
    // 0x808003F0: lwc1        $f14, 0x49C4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X49C4));
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808003F0: lwc1        $f14, 0x49C4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X49C4));
    after_1:
    // 0x808003F4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808003F8: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x808003FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800404: jr          $ra
    // 0x80800408: nop

    return;
    // 0x80800408: nop

;}
RECOMP_FUNC void func_8010E204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E204: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010E208: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8010E20C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8010E210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010E214: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8010E218: bgez        $a1, L_8010E228
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8010E21C: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_8010E228;
    }
    // 0x8010E21C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8010E220: b           L_8010E22C
    // 0x8010E224: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
        goto L_8010E22C;
    // 0x8010E224: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_8010E228:
    // 0x8010E228: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_8010E22C:
    // 0x8010E22C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010E230: lw          $a0, 0x7074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7074);
    // 0x8010E234: jal         0x800B388C
    // 0x8010E238: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    func_800B388C(rdram, ctx);
        goto after_0;
    // 0x8010E238: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_0:
    // 0x8010E23C: jal         0x800DF8B4
    // 0x8010E240: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800DF8B4(rdram, ctx);
        goto after_1;
    // 0x8010E240: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8010E244: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010E248: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8010E24C: jal         0x800B237C
    // 0x8010E250: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800B237C(rdram, ctx);
        goto after_2;
    // 0x8010E250: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x8010E254: jal         0x800DF8C4
    // 0x8010E258: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800DF8C4(rdram, ctx);
        goto after_3;
    // 0x8010E258: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8010E25C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8010E260: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8010E264: jal         0x80019224
    // 0x8010E268: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80019224(rdram, ctx);
        goto after_4;
    // 0x8010E268: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_4:
    // 0x8010E26C: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8010E270: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010E274: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010E278: lw          $a0, 0x7074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7074);
    // 0x8010E27C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010E280: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8010E284: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8010E288: jal         0x800B3494
    // 0x8010E28C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_800B3494(rdram, ctx);
        goto after_5;
    // 0x8010E28C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8010E290: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8010E294: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010E298: bgez        $t6, L_8010E2A8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8010E29C: nop
    
            goto L_8010E2A8;
    }
    // 0x8010E29C: nop

    // 0x8010E2A0: jal         0x800B3748
    // 0x8010E2A4: lw          $a0, 0x7074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7074);
    func_800B3748(rdram, ctx);
        goto after_6;
    // 0x8010E2A4: lw          $a0, 0x7074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7074);
    after_6:
L_8010E2A8:
    // 0x8010E2A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010E2AC: jal         0x800B38C8
    // 0x8010E2B0: lw          $a0, 0x7074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7074);
    func_800B38C8(rdram, ctx);
        goto after_7;
    // 0x8010E2B0: lw          $a0, 0x7074($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7074);
    after_7:
    // 0x8010E2B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010E2B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8010E2BC: jr          $ra
    // 0x8010E2C0: nop

    return;
    // 0x8010E2C0: nop

;}
RECOMP_FUNC void sumissilehome_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800050: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800054: sb          $t6, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r14;
    // 0x80800058: jr          $ra
    // 0x8080005C: sh          $a2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r6;
    return;
    // 0x8080005C: sh          $a2, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_80115484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80115488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011548C: jal         0x80112524
    // 0x80115490: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80115490: nop

    after_0:
    // 0x80115494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80115498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8011549C: jr          $ra
    // 0x801154A0: nop

    return;
    // 0x801154A0: nop

;}
RECOMP_FUNC void bakey_func_80091C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091C74: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80091C78: jr          $ra
    // 0x80091C7C: sb          $a1, 0x9($t6)
    MEM_B(0X9, ctx->r14) = ctx->r5;
    return;
    // 0x80091C7C: sb          $a1, 0x9($t6)
    MEM_B(0X9, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_808024F8_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808024F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808024FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802500: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802504: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802508: jal         0x80106790
    // 0x8080250C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080250C: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80802510: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80802514: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80802518: addiu       $at, $zero, 0x253
    ctx->r1 = ADD32(0, 0X253);
    // 0x8080251C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80802520: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80802524: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x80802528: bnel        $t8, $at, L_80802578
    if (ctx->r24 != ctx->r1) {
        // 0x8080252C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802578;
    }
    goto skip_0;
    // 0x8080252C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802530: jal         0x80802648
    // 0x80802534: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80802648_chstoneballcontrol(rdram, ctx);
        goto after_1;
    // 0x80802534: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80802538: jal         0x80802F14
    // 0x8080253C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802F14_chstoneballcontrol(rdram, ctx);
        goto after_2;
    // 0x8080253C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802540: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1608, 0X4FD4) << 16);
    // 0x80802544: addiu       $a2, $a2, 0x4FD4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1608, 0X4FD4));
    // 0x80802548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080254C: jal         0x80089D18
    // 0x80802550: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80802550: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80802554: jal         0x80089CA8
    // 0x80802558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80802558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080255C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802560: jal         0x80801944
    // 0x80802564: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80801944_chstoneballcontrol(rdram, ctx);
        goto after_5;
    // 0x80802564: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80802568: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080256C: jal         0x80800DB4
    // 0x80802570: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800DB4_chstoneballcontrol(rdram, ctx);
        goto after_6;
    // 0x80802570: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80802574: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802578:
    // 0x80802578: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080257C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802580: jr          $ra
    // 0x80802584: nop

    return;
    // 0x80802584: nop

;}
RECOMP_FUNC void subaddieskeleton_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800014: jal         0x801040A8
    // 0x80800018: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    func_801040A8(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080001C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800020: jal         0x800AE0D0
    // 0x80800024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AE0D0(rdram, ctx);
        goto after_1;
    // 0x80800024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800028: beq         $v0, $zero, L_80800098
    if (ctx->r2 == 0) {
        // 0x8080002C: nop
    
            goto L_80800098;
    }
    // 0x8080002C: nop

    // 0x80800030: jal         0x801039E4
    // 0x80800034: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_2;
    // 0x80800034: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80800038: jal         0x800B27E0
    // 0x8080003C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27E0(rdram, ctx);
        goto after_3;
    // 0x8080003C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800040: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800044: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800048: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8080004C: jal         0x800AE630
    // 0x80800050: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    func_800AE630(rdram, ctx);
        goto after_4;
    // 0x80800050: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80800054: beq         $v0, $zero, L_808000FC
    if (ctx->r2 == 0) {
        // 0x80800058: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_808000FC;
    }
    // 0x80800058: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080005C: jal         0x800EF334
    // 0x80800060: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_800EF334(rdram, ctx);
        goto after_5;
    // 0x80800060: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x80800064: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800068: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080006C: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x80800070: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80800074: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80800078: jal         0x800EF5A0
    // 0x8080007C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_6;
    // 0x8080007C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80800080: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800084: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800088: jal         0x800EE780
    // 0x8080008C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800EE780(rdram, ctx);
        goto after_7;
    // 0x8080008C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80800090: b           L_80800100
    // 0x80800094: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800100;
    // 0x80800094: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800098:
    // 0x80800098: jal         0x801039E4
    // 0x8080009C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_8;
    // 0x8080009C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x808000A0: jal         0x800B27E0
    // 0x808000A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27E0(rdram, ctx);
        goto after_9;
    // 0x808000A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x808000A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000AC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x808000B0: jal         0x80087A18
    // 0x808000B4: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _dbskeleton_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x808000B4: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_10:
    // 0x808000B8: beq         $v0, $zero, L_808000FC
    if (ctx->r2 == 0) {
        // 0x808000BC: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_808000FC;
    }
    // 0x808000BC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808000C0: jal         0x800EF334
    // 0x808000C4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_800EF334(rdram, ctx);
        goto after_11;
    // 0x808000C4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_11:
    // 0x808000C8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808000CC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808000D0: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x808000D4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808000D8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x808000DC: jal         0x800EF5A0
    // 0x808000E0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_12;
    // 0x808000E0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x808000E4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808000E8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808000EC: jal         0x800EE780
    // 0x808000F0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800EE780(rdram, ctx);
        goto after_13;
    // 0x808000F0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x808000F4: b           L_80800100
    // 0x808000F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800100;
    // 0x808000F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000FC:
    // 0x808000FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800100:
    // 0x80800100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800104: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800108: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_80092D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092D1C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80092D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092D24: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80092D28: lw          $a1, 0x50($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X50);
    // 0x80092D2C: jal         0x800EE7F8
    // 0x80092D30: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80092D30: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_0:
    // 0x80092D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092D38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092D3C: jr          $ra
    // 0x80092D40: nop

    return;
    // 0x80092D40: nop

;}
RECOMP_FUNC void choctopus_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1028, 0X8F4) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x8F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1028, 0X8F4));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x8F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1028, 0X8F4));
;}
RECOMP_FUNC void func_8080186C_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080186C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801874: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801878: jal         0x800848D8
    // 0x8080187C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _badrone_entrypoint_30(rdram, ctx);
        goto after_0;
    // 0x8080187C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80801880: beq         $v0, $zero, L_8080188C
    if (ctx->r2 == 0) {
        // 0x80801884: addiu       $t6, $zero, 0xBB
        ctx->r14 = ADD32(0, 0XBB);
            goto L_8080188C;
    }
    // 0x80801884: addiu       $t6, $zero, 0xBB
    ctx->r14 = ADD32(0, 0XBB);
    // 0x80801888: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_8080188C:
    // 0x8080188C: jal         0x80082FE8
    // 0x80801890: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80801890: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80801894: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801898: jal         0x8009E5C8
    // 0x8080189C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x8080189C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808018A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808018A8: jr          $ra
    // 0x808018AC: nop

    return;
    // 0x808018AC: nop

;}
RECOMP_FUNC void func_800132BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800132BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800132C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800132C4: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800132C8: addiu       $a0, $a0, 0x695C
    ctx->r4 = ADD32(ctx->r4, 0X695C);
    // 0x800132CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800132D0: jal         0x8002E1F0
    // 0x800132D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800132D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800132D8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800132DC: lw          $v0, -0x3390($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3390);
    // 0x800132E0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800132E4: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800132E8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800132EC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800132F0: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x800132F4: lw          $a1, 0x69D0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X69D0);
    // 0x800132F8: lw          $a0, 0x69CC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X69CC);
    // 0x800132FC: jal         0x8002E6E0
    // 0x80013300: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x80013300: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    after_1:
    // 0x80013304: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80013308: addiu       $v0, $v0, -0x3390
    ctx->r2 = ADD32(ctx->r2, -0X3390);
    // 0x8001330C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80013310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80013318: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8001331C: jr          $ra
    // 0x80013320: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x80013320: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void _gcnewoption_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C98: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087C98);
    return;
    // 0x80087C9C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808016A4_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016A4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2658, 0X20A8) << 16);
    // 0x808016A8: addiu       $a1, $a1, 0x20A8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2658, 0X20A8));
    // 0x808016AC: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x808016B0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2658, 0X20A8) << 16);
    // 0x808016B4: addiu       $v0, $v0, 0x20A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2658, 0X20A8));
    // 0x808016B8: beq         $t6, $zero, L_808016E0
    if (ctx->r14 == 0) {
        // 0x808016BC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808016E0;
    }
    // 0x808016BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808016C0: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
L_808016C4:
    // 0x808016C4: beql        $a0, $t7, L_808016E4
    if (ctx->r4 == ctx->r15) {
        // 0x808016C8: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_808016E4;
    }
    goto skip_0;
    // 0x808016C8: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    skip_0:
    // 0x808016CC: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x808016D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808016D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808016D8: bnel        $t8, $zero, L_808016C4
    if (ctx->r24 != 0) {
        // 0x808016DC: lh          $t7, 0x2($v0)
        ctx->r15 = MEM_H(ctx->r2, 0X2);
            goto L_808016C4;
    }
    goto skip_1;
    // 0x808016DC: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    skip_1:
L_808016E0:
    // 0x808016E0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_808016E4:
    // 0x808016E4: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x808016E8: jr          $ra
    // 0x808016EC: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    return;
    // 0x808016EC: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
;}
