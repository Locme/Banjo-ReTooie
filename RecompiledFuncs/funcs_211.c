#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800AC638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC638: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800AC63C: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x800AC640: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x800AC644: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AC648: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x800AC64C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800AC650: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x800AC654: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x800AC658: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x800AC65C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800AC660: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x800AC664: sw          $s7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r23;
    // 0x800AC668: sw          $s6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r22;
    // 0x800AC66C: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x800AC670: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x800AC674: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x800AC678: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800AC67C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800AC680: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800AC684: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800AC688: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800AC68C: jal         0x800EFB24
    // 0x800AC690: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800AC690: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x800AC694: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800AC698: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800AC69C: lwc1        $f26, 0xD0($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800AC6A0: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x800AC6A4: addiu       $t7, $sp, 0xBC
    ctx->r15 = ADD32(ctx->r29, 0XBC);
    // 0x800AC6A8: add.s       $f4, $f26, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f26.fl + ctx->f28.fl;
    // 0x800AC6AC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800AC6B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AC6B4: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x800AC6B8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x800AC6BC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800AC6C0: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x800AC6C4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800AC6C8: jal         0x800ABCE0
    // 0x800AC6CC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_800ABCE0(rdram, ctx);
        goto after_1;
    // 0x800AC6CC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_1:
    // 0x800AC6D0: bne         $v0, $zero, L_800AC6E0
    if (ctx->r2 != 0) {
        // 0x800AC6D4: addiu       $s3, $sp, 0x88
        ctx->r19 = ADD32(ctx->r29, 0X88);
            goto L_800AC6E0;
    }
    // 0x800AC6D4: addiu       $s3, $sp, 0x88
    ctx->r19 = ADD32(ctx->r29, 0X88);
    // 0x800AC6D8: b           L_800AC808
    // 0x800AC6DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AC808;
    // 0x800AC6DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AC6E0:
    // 0x800AC6E0: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x800AC6E4: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x800AC6E8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800AC6EC: jal         0x800AC100
    // 0x800AC6F0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_800AC100(rdram, ctx);
        goto after_2;
    // 0x800AC6F0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_2:
    // 0x800AC6F4: bne         $v0, $zero, L_800AC704
    if (ctx->r2 != 0) {
        // 0x800AC6F8: or          $s6, $v0, $zero
        ctx->r22 = ctx->r2 | 0;
            goto L_800AC704;
    }
    // 0x800AC6F8: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800AC6FC: b           L_800AC808
    // 0x800AC700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AC808;
    // 0x800AC700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AC704:
    // 0x800AC704: lw          $s7, 0xD4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XD4);
    // 0x800AC708: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AC70C: jal         0x800EE7F8
    // 0x800AC710: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x800AC710: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_3:
    // 0x800AC714: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x800AC718: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800AC71C: jal         0x800EFB24
    // 0x800AC720: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EFB24(rdram, ctx);
        goto after_4;
    // 0x800AC720: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_4:
    // 0x800AC724: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800AC728: jal         0x800EE7F8
    // 0x800AC72C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x800AC72C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800AC730: lw          $s4, 0xD8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XD8);
    // 0x800AC734: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AC738: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800AC73C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800AC740: blez        $s4, L_800AC7E0
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800AC744: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800AC7E0;
    }
    // 0x800AC744: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AC748: addiu       $s2, $sp, 0x94
    ctx->r18 = ADD32(ctx->r29, 0X94);
    // 0x800AC74C: add.s       $f6, $f22, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f22.fl + ctx->f24.fl;
L_800AC750:
    // 0x800AC750: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800AC754: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800AC758: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800AC75C: mul.s       $f20, $f6, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x800AC760: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x800AC764: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x800AC768: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800AC76C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800AC770: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800AC774: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AC778: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800AC77C: lwc1        $f16, 0xB8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800AC780: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
    // 0x800AC784: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800AC788: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800AC78C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AC790: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x800AC794: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800AC798: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AC79C: jal         0x800AC100
    // 0x800AC7A0: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
    func_800AC100(rdram, ctx);
        goto after_6;
    // 0x800AC7A0: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x800AC7A4: beq         $v0, $zero, L_800AC7C8
    if (ctx->r2 == 0) {
        // 0x800AC7A8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800AC7C8;
    }
    // 0x800AC7A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800AC7AC: mov.s       $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    ctx->f24.fl = ctx->f20.fl;
    // 0x800AC7B0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800AC7B4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800AC7B8: jal         0x800EE7F8
    // 0x800AC7BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x800AC7BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x800AC7C0: b           L_800AC7D8
    // 0x800AC7C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800AC7D8;
    // 0x800AC7C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800AC7C8:
    // 0x800AC7C8: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x800AC7CC: jal         0x800EE7F8
    // 0x800AC7D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x800AC7D0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x800AC7D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800AC7D8:
    // 0x800AC7D8: bnel        $s0, $s4, L_800AC750
    if (ctx->r16 != ctx->r20) {
        // 0x800AC7DC: add.s       $f6, $f22, $f24
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f22.fl + ctx->f24.fl;
            goto L_800AC750;
    }
    goto skip_0;
    // 0x800AC7DC: add.s       $f6, $f22, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f22.fl + ctx->f24.fl;
    skip_0:
L_800AC7E0:
    // 0x800AC7E0: bne         $s6, $zero, L_800AC7F0
    if (ctx->r22 != 0) {
        // 0x800AC7E4: nop
    
            goto L_800AC7F0;
    }
    // 0x800AC7E4: nop

    // 0x800AC7E8: b           L_800AC808
    // 0x800AC7EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AC808;
    // 0x800AC7EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AC7F0:
    // 0x800AC7F0: jal         0x800EF2A0
    // 0x800AC7F4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_9;
    // 0x800AC7F4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_9:
    // 0x800AC7F8: lw          $a0, 0x24($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X24);
    // 0x800AC7FC: jal         0x800AA3B4
    // 0x800AC800: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    func_800AA3B4(rdram, ctx);
        goto after_10;
    // 0x800AC800: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    after_10:
    // 0x800AC804: lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X24);
L_800AC808:
    // 0x800AC808: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800AC80C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800AC810: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800AC814: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800AC818: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800AC81C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800AC820: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x800AC824: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x800AC828: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x800AC82C: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x800AC830: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x800AC834: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x800AC838: lw          $s6, 0x64($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X64);
    // 0x800AC83C: lw          $s7, 0x68($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X68);
    // 0x800AC840: jr          $ra
    // 0x800AC844: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800AC844: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_80800054_chboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800058: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080005C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800060: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X790) << 16);
    // 0x80800064: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800068: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080006C: addiu       $a2, $a2, 0x790
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X790));
    // 0x80800070: jal         0x8008A1F8
    // 0x80800074: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800074: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x80800078: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X7C8) << 16);
    // 0x8080007C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800080: addiu       $a2, $a2, 0x7C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X7C8));
    // 0x80800084: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800088: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080008C: jal         0x8008A1F8
    // 0x80800090: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800090: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_1:
    // 0x80800094: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800098: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8080009C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000A0: bne         $t6, $v1, L_808000C0
    if (ctx->r14 != ctx->r3) {
        // 0x808000A4: nop
    
            goto L_808000C0;
    }
    // 0x808000A4: nop

    // 0x808000A8: jal         0x80101FDC
    // 0x808000AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808000AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808000B0: jal         0x800DA544
    // 0x808000B4: addiu       $a0, $zero, 0x447
    ctx->r4 = ADD32(0, 0X447);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x808000B4: addiu       $a0, $zero, 0x447
    ctx->r4 = ADD32(0, 0X447);
    after_3:
    // 0x808000B8: b           L_808000E0
    // 0x808000BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000E0;
    // 0x808000BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000C0:
    // 0x808000C0: bnel        $v0, $v1, L_808000E0
    if (ctx->r2 != ctx->r3) {
        // 0x808000C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000E0;
    }
    goto skip_0;
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000C8: jal         0x800F54E4
    // 0x808000CC: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808000CC: nop

    after_4:
    // 0x808000D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000D4: jal         0x800F82D4
    // 0x808000D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_5;
    // 0x808000D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808000DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000E0:
    // 0x808000E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000E4: jr          $ra
    // 0x808000E8: nop

    return;
    // 0x808000E8: nop

;}
RECOMP_FUNC void func_808006AC_badata(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808006B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808006BC: jal         0x80800000
    // 0x808006C0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x808006C0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x808006C4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808006C8: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x808006CC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808006D0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x808006D4: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x808006D8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x808006DC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x808006E0: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x808006E4: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x808006E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006F0: jr          $ra
    // 0x808006F4: nop

    return;
    // 0x808006F4: nop

;}
RECOMP_FUNC void _surestart_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A7A0: syscall     851
    recomp_syscall_handler(rdram, ctx, 0x8008A7A0);
    return;
    // 0x8008A7A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808004B8_glsavegame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808004BC: jr          $ra
    // 0x808004C0: sb          $a0, 0x762A($at)
    MEM_B(0X762A, ctx->r1) = ctx->r4;
    return;
    // 0x808004C0: sb          $a0, 0x762A($at)
    MEM_B(0X762A, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _chfiregen_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869D0: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x800869D0);
    return;
    // 0x800869D4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void subaddiedraw25d_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800254: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800258: lw          $a0, 0x70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70);
    // 0x8080025C: sll         $t7, $a0, 11
    ctx->r15 = S32(ctx->r4 << 11);
    // 0x80800260: jal         0x800E24C0
    // 0x80800264: srl         $a0, $t7, 31
    ctx->r4 = S32(U32(ctx->r15) >> 31);
    func_800E24C0(rdram, ctx);
        goto after_0;
    // 0x80800264: srl         $a0, $t7, 31
    ctx->r4 = S32(U32(ctx->r15) >> 31);
    after_0:
    // 0x80800268: jal         0x80100368
    // 0x8080026C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80100368(rdram, ctx);
        goto after_1;
    // 0x8080026C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800270: lhu         $a0, 0x1A($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X1A);
    // 0x80800274: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800278: beql        $a0, $zero, L_80800294
    if (ctx->r4 == 0) {
        // 0x8080027C: lw          $t0, 0x0($t9)
        ctx->r8 = MEM_W(ctx->r25, 0X0);
            goto L_80800294;
    }
    goto skip_0;
    // 0x8080027C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    skip_0:
    // 0x80800280: jal         0x800E249C
    // 0x80800284: nop

    func_800E249C(rdram, ctx);
        goto after_2;
    // 0x80800284: nop

    after_2:
    // 0x80800288: b           L_808002B8
    // 0x8080028C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002B8;
    // 0x8080028C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800290: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
L_80800294:
    // 0x80800294: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80800298: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8080029C: bnel        $t2, $zero, L_808002B8
    if (ctx->r10 != 0) {
        // 0x808002A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002B8;
    }
    goto skip_1;
    // 0x808002A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808002A4: jal         0x800D2F20
    // 0x808002A8: nop

    func_800D2F20(rdram, ctx);
        goto after_3;
    // 0x808002A8: nop

    after_3:
    // 0x808002AC: jal         0x800E249C
    // 0x808002B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E249C(rdram, ctx);
        goto after_4;
    // 0x808002B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808002B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002B8:
    // 0x808002B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002BC: jr          $ra
    // 0x808002C0: nop

    return;
    // 0x808002C0: nop

    // 0x808002C4: nop

    // 0x808002C8: nop

    // 0x808002CC: nop

;}
RECOMP_FUNC void func_80802CB4_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802CB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802CB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802CBC: jal         0x80802248
    // 0x80802CC0: nop

    func_80802248_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x80802CC0: nop

    after_0:
    // 0x80802CC4: jal         0x800F4B20
    // 0x80802CC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4B20(rdram, ctx);
        goto after_1;
    // 0x80802CC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80802CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802CD4: jr          $ra
    // 0x80802CD8: nop

    return;
    // 0x80802CD8: nop

;}
RECOMP_FUNC void _gclightsDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EA8: syscall     660
    recomp_syscall_handler(rdram, ctx, 0x80087EA8);
    return;
    // 0x80087EAC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087CD8: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087CD8);
    return;
    // 0x80087CDC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80027214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027214: jr          $ra
    // 0x80027218: nop

    return;
    // 0x80027218: nop

;}
RECOMP_FUNC void func_808001B4_bsmumattack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001C4: jal         0x8008CABC
    // 0x808001C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808001D0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808001D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808001D8: beq         $a1, $zero, L_80800204
    if (ctx->r5 == 0) {
        // 0x808001DC: sw          $a1, 0x15C($a2)
        MEM_W(0X15C, ctx->r6) = ctx->r5;
            goto L_80800204;
    }
    // 0x808001DC: sw          $a1, 0x15C($a2)
    MEM_W(0X15C, ctx->r6) = ctx->r5;
    // 0x808001E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001E4: beq         $a1, $at, L_80800218
    if (ctx->r5 == ctx->r1) {
        // 0x808001E8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800218;
    }
    // 0x808001E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001EC: beq         $a1, $at, L_80800228
    if (ctx->r5 == ctx->r1) {
        // 0x808001F0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800228;
    }
    // 0x808001F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001F4: beq         $a1, $at, L_808002A0
    if (ctx->r5 == ctx->r1) {
        // 0x808001F8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808002A0;
    }
    // 0x808001F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808001FC: b           L_808002D8
    // 0x80800200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002D8;
    // 0x80800200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800204:
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x8008B2E8
    // 0x8080020C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008B2E8(rdram, ctx);
        goto after_1;
    // 0x8080020C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800210: b           L_808002D8
    // 0x80800214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002D8;
    // 0x80800214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800218:
    // 0x80800218: jal         0x800853D0
    // 0x8080021C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _bawandglow_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x8080021C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80800220: b           L_808002D8
    // 0x80800224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002D8;
    // 0x80800224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800228:
    // 0x80800228: jal         0x8008B2B4
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_3;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800230: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(312, 0X6E0) << 16);
    // 0x80800234: lwc1        $f4, 0x6E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(312, 0X6E0));
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: lui         $a1, 0x3F11
    ctx->r5 = S32(0X3F11 << 16);
    // 0x80800240: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80800244: nop

    // 0x80800248: bc1fl       L_8080025C
    if (!c1cs) {
        // 0x8080024C: lui         $a1, 0x3F11
        ctx->r5 = S32(0X3F11 << 16);
            goto L_8080025C;
    }
    goto skip_0;
    // 0x8080024C: lui         $a1, 0x3F11
    ctx->r5 = S32(0X3F11 << 16);
    skip_0:
    // 0x80800250: jal         0x8008B10C
    // 0x80800254: ori         $a1, $a1, 0xCB3
    ctx->r5 = ctx->r5 | 0XCB3;
    func_8008B10C(rdram, ctx);
        goto after_4;
    // 0x80800254: ori         $a1, $a1, 0xCB3
    ctx->r5 = ctx->r5 | 0XCB3;
    after_4:
    // 0x80800258: lui         $a1, 0x3F11
    ctx->r5 = S32(0X3F11 << 16);
L_8080025C:
    // 0x8080025C: lui         $a2, 0x3F22
    ctx->r6 = S32(0X3F22 << 16);
    // 0x80800260: ori         $a2, $a2, 0x1FF3
    ctx->r6 = ctx->r6 | 0X1FF3;
    // 0x80800264: ori         $a1, $a1, 0xCB3
    ctx->r5 = ctx->r5 | 0XCB3;
    // 0x80800268: jal         0x8008B1D4
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setSubrange(rdram, ctx);
        goto after_5;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: jal         0x8008B134
    // 0x80800278: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x80800278: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: jal         0x8008B2E8
    // 0x80800284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008B2E8(rdram, ctx);
        goto after_7;
    // 0x80800284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800288: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080028C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800290: jal         0x80085338
    // 0x80800294: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    _batimer_set(rdram, ctx);
        goto after_8;
    // 0x80800294: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_8:
    // 0x80800298: b           L_808002D8
    // 0x8080029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002D8;
    // 0x8080029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002A0:
    // 0x808002A0: jal         0x80095774
    // 0x808002A4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    baflag_clear(rdram, ctx);
        goto after_9;
    // 0x808002A4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_9:
    // 0x808002A8: jal         0x800853E8
    // 0x808002AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bawandglow_entrypoint_7(rdram, ctx);
        goto after_10;
    // 0x808002AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_10:
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: jal         0x8008B2E8
    // 0x808002B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008B2E8(rdram, ctx);
        goto after_11;
    // 0x808002B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C0: jal         0x8008B134
    // 0x808002C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_12;
    // 0x808002C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808002C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002CC: jal         0x8008CED4
    // 0x808002D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_13;
    // 0x808002D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_13:
    // 0x808002D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002D8:
    // 0x808002D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002E0: jr          $ra
    // 0x808002E4: nop

    return;
    // 0x808002E4: nop

;}
RECOMP_FUNC void func_8009AD44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AD44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009AD48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009AD4C: lw          $a0, 0xC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC0);
    // 0x8009AD50: jal         0x800EE7F8
    // 0x8009AD54: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009AD54: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x8009AD58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009AD5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009AD60: jr          $ra
    // 0x8009AD64: nop

    return;
    // 0x8009AD64: nop

    // 0x8009AD68: nop

    // 0x8009AD6C: nop

;}
RECOMP_FUNC void chquiz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FF8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2484, 0X72CC) << 16);
    // 0x80801FFC: jr          $ra
    // 0x80802000: addiu       $v0, $v0, 0x72CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2484, 0X72CC));
    return;
    // 0x80802000: addiu       $v0, $v0, 0x72CC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2484, 0X72CC));
;}
RECOMP_FUNC void bahold_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: lw          $t6, 0x9C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C);
    // 0x808001D4: jr          $ra
    // 0x808001D8: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    return;
    // 0x808001D8: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
;}
RECOMP_FUNC void chfactoryentrydoors_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800298: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2016, 0X3A0) << 16);
    // 0x8080029C: jr          $ra
    // 0x808002A0: addiu       $v0, $v0, 0x3A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2016, 0X3A0));
    return;
    // 0x808002A0: addiu       $v0, $v0, 0x3A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2016, 0X3A0));
    // 0x808002A4: nop

    // 0x808002A8: nop

    // 0x808002AC: nop

;}
RECOMP_FUNC void _bsbswim_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B68: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082B68);
    return;
    // 0x80082B6C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800950FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800950FC: lw          $t7, 0x78($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X78);
    // 0x80095100: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80095104: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80095108: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8009510C: sb          $t6, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r14;
    // 0x80095110: lw          $t9, 0x78($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X78);
    // 0x80095114: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80095118: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8009511C: jr          $ra
    // 0x80095120: swc1        $f12, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f12.u32l;
    return;
    // 0x80095120: swc1        $f12, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f12.u32l;
;}
RECOMP_FUNC void _chstonepillar_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CD8: syscall     225
    recomp_syscall_handler(rdram, ctx, 0x80085CD8);
    return;
    // 0x80085CDC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808002AC_chboxingglove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x808002B0: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808002B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002B8: lbu         $t6, 0x65($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X65);
    // 0x808002BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002C0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x808002C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002C8: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x808002CC: sb          $t7, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r15;
    // 0x808002D0: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x808002D4: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x808002D8: jr          $ra
    // 0x808002DC: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x808002DC: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_8080003C_chlavacolumnswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800048: jal         0x80085808
    // 0x8080004C: addiu       $a1, $zero, 0x390
    ctx->r5 = ADD32(0, 0X390);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x8080004C: addiu       $a1, $zero, 0x390
    ctx->r5 = ADD32(0, 0X390);
    after_0:
    // 0x80800050: jal         0x80085818
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_800E1664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1664: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E1668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E166C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800E1670: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800E1674: jal         0x800E1540
    // 0x800E1678: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800E1540(rdram, ctx);
        goto after_0;
    // 0x800E1678: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E167C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800E1680: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E1684: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800E1688: jal         0x800E14F8
    // 0x800E168C: lh          $a2, 0x36($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X36);
    func_800E14F8(rdram, ctx);
        goto after_1;
    // 0x800E168C: lh          $a2, 0x36($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X36);
    after_1:
    // 0x800E1690: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1694: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800E1698: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800E169C: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800E16A0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800E16A4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800E16A8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800E16AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E16B0: addiu       $t7, $t7, -0x3070
    ctx->r15 = ADD32(ctx->r15, -0X3070);
    // 0x800E16B4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800E16B8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800E16BC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800E16C0: sb          $t8, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r24;
    // 0x800E16C4: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
    // 0x800E16C8: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x800E16CC: bc1f        L_800E16E4
    if (!c1cs) {
        // 0x800E16D0: swc1        $f4, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
            goto L_800E16E4;
    }
    // 0x800E16D0: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x800E16D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E16D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800E16DC: b           L_800E16F4
    // 0x800E16E0: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
        goto L_800E16F4;
    // 0x800E16E0: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
L_800E16E4:
    // 0x800E16E4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800E16E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800E16EC: nop

    // 0x800E16F0: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
L_800E16F4:
    // 0x800E16F4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800E16F8: beql        $a1, $zero, L_800E1710
    if (ctx->r5 == 0) {
        // 0x800E16FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E1710;
    }
    goto skip_0;
    // 0x800E16FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E1700: jal         0x800E14B8
    // 0x800E1704: nop

    func_800E14B8(rdram, ctx);
        goto after_2;
    // 0x800E1704: nop

    after_2:
    // 0x800E1708: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800E170C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E1710:
    // 0x800E1710: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E1714: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800E1718: jr          $ra
    // 0x800E171C: nop

    return;
    // 0x800E171C: nop

;}
RECOMP_FUNC void func_8080911C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080911C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80809120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80809124: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80809128: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x8080912C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80809130: beq         $a1, $zero, L_8080914C
    if (ctx->r5 == 0) {
        // 0x80809134: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_8080914C;
    }
    // 0x80809134: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80809138: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080913C: beq         $a1, $at, L_80809168
    if (ctx->r5 == ctx->r1) {
        // 0x80809140: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80809168;
    }
    // 0x80809140: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80809144: b           L_80809180
    // 0x80809148: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_80809180;
    // 0x80809148: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_8080914C:
    // 0x8080914C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80809150: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80809154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80809158: jal         0x8009FFD8
    // 0x8080915C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_0;
    // 0x8080915C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x80809160: b           L_80809180
    // 0x80809164: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_80809180;
    // 0x80809164: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_80809168:
    // 0x80809168: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8080916C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80809170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80809174: jal         0x8009FFD8
    // 0x80809178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80809178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8080917C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_80809180:
    // 0x80809180: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80809184: sw          $t0, 0x108($t1)
    MEM_W(0X108, ctx->r9) = ctx->r8;
    // 0x80809188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080918C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80809190: jr          $ra
    // 0x80809194: nop

    return;
    // 0x80809194: nop

;}
RECOMP_FUNC void _subaddie3d_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089838: syscall     796
    recomp_syscall_handler(rdram, ctx, 0x80089838);
    return;
    // 0x8008983C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808000AC_ncpod(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B4: lbu         $t6, 0x43($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X43);
    // 0x808000B8: beql        $t6, $zero, L_808000D4
    if (ctx->r14 == 0) {
        // 0x808000BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000D4;
    }
    goto skip_0;
    // 0x808000BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000C0: jal         0x80088830
    // 0x808000C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x808000C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000CC: sb          $zero, 0x43($a0)
    MEM_B(0X43, ctx->r4) = 0;
    // 0x808000D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000D4:
    // 0x808000D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void bsdrone_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B4: jal         0x80800000
    // 0x808000B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_bsdrone(rdram, ctx);
        goto after_0;
    // 0x808000B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000BC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808000C0: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x808000C4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808000C8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(160, 0X188) << 16);
    // 0x808000CC: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x808000D0: lw          $t9, 0x188($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(160, 0X188));
    // 0x808000D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000D8: jalr        $t9
    // 0x808000DC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x808000DC: nop

    after_1:
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_8010C964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C964: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010C968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C96C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8010C970: jal         0x80103F38
    // 0x8010C974: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80103F38(rdram, ctx);
        goto after_0;
    // 0x8010C974: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8010C978: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8010C97C: jal         0x8010A40C
    // 0x8010C980: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8010A40C(rdram, ctx);
        goto after_1;
    // 0x8010C980: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8010C984: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010C988: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8010C98C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8010C990: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010C994: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8010C998: jal         0x8008FB58
    // 0x8010C99C: nop

    func_8008FB58(rdram, ctx);
        goto after_2;
    // 0x8010C99C: nop

    after_2:
    // 0x8010C9A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C9A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8010C9A8: jr          $ra
    // 0x8010C9AC: nop

    return;
    // 0x8010C9AC: nop

;}
RECOMP_FUNC void func_80800064_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080006C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800070: jal         0x80100074
    // 0x80800074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80800074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800078: jal         0x800FDC28
    // 0x8080007C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_1;
    // 0x8080007C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_8080322C_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080322C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80803230: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803234: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80803238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080323C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80803240: jal         0x800F54E4
    // 0x80803244: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80803244: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80803248: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x8080324C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80803250: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803254: jal         0x8010D09C
    // 0x80803258: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_8010D09C(rdram, ctx);
        goto after_1;
    // 0x80803258: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x8080325C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803260: jal         0x80803304
    // 0x80803264: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80803304_chklungo(rdram, ctx);
        goto after_2;
    // 0x80803264: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80803268: beql        $v0, $zero, L_808032B0
    if (ctx->r2 == 0) {
        // 0x8080326C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808032B0;
    }
    goto skip_0;
    // 0x8080326C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80803270: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x80803274: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803278: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x8080327C: srl         $t6, $a2, 26
    ctx->r14 = S32(U32(ctx->r6) >> 26);
    // 0x80803280: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x80803284: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80803288: jal         0x800CC338
    // 0x8080328C: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    func_800CC338(rdram, ctx);
        goto after_3;
    // 0x8080328C: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    after_3:
    // 0x80803290: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80803294: beq         $v0, $at, L_808032AC
    if (ctx->r2 == ctx->r1) {
        // 0x80803298: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_808032AC;
    }
    // 0x80803298: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080329C: jal         0x800EE7F8
    // 0x808032A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808032A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x808032A4: b           L_808032F4
    // 0x808032A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808032F4;
    // 0x808032A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808032AC:
    // 0x808032AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808032B0:
    // 0x808032B0: jal         0x80803390
    // 0x808032B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80803390_chklungo(rdram, ctx);
        goto after_5;
    // 0x808032B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x808032B8: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    // 0x808032BC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x808032C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808032C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808032C8: jal         0x80803464
    // 0x808032CC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80803464_chklungo(rdram, ctx);
        goto after_6;
    // 0x808032CC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_6:
    // 0x808032D0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808032D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808032D8: jal         0x80803304
    // 0x808032DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80803304_chklungo(rdram, ctx);
        goto after_7;
    // 0x808032DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x808032E0: bne         $v0, $zero, L_808032F0
    if (ctx->r2 != 0) {
        // 0x808032E4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808032F0;
    }
    // 0x808032E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808032E8: jal         0x800EE7F8
    // 0x808032EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x808032EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
L_808032F0:
    // 0x808032F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808032F4:
    // 0x808032F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808032F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808032FC: jr          $ra
    // 0x80803300: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80803300: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808000B8_chfootwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808000BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C4: lw          $a1, 0x30($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X30);
    // 0x808000C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D0: beq         $a1, $at, L_808000F8
    if (ctx->r5 == ctx->r1) {
        // 0x808000D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000F8;
    }
    // 0x808000D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000D8: beq         $a1, $at, L_80800294
    if (ctx->r5 == ctx->r1) {
        // 0x808000DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800294;
    }
    // 0x808000DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000E0: beq         $a1, $at, L_808002E4
    if (ctx->r5 == ctx->r1) {
        // 0x808000E4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808002E4;
    }
    // 0x808000E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000E8: beq         $a1, $at, L_80800338
    if (ctx->r5 == ctx->r1) {
        // 0x808000EC: nop
    
            goto L_80800338;
    }
    // 0x808000EC: nop

    // 0x808000F0: b           L_80800354
    // 0x808000F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800354;
    // 0x808000F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F8:
    // 0x808000F8: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x808000FC: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80800100: beq         $at, $zero, L_80800218
    if (ctx->r1 == 0) {
        // 0x80800104: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800218;
    }
    // 0x80800104: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800108: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2448, 0X6C0) << 16);
    // 0x8080010C: addu        $at, $at, $t6
    gpr jr_addend_80800114 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800110: lw          $t6, 0x6C0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2448, 0X6C0));
    // 0x80800114: jr          $t6
    // 0x80800118: nop

    switch (jr_addend_80800114 >> 2) {
        case 0: goto L_8080011C; break;
        case 1: goto L_808001A0; break;
        case 2: goto L_808001C0; break;
        case 3: goto L_808001C0; break;
        case 4: goto L_8080011C; break;
        default: switch_error(__func__, 0x80800114, 0x808006C0);
    }
    // 0x80800118: nop

L_8080011C:
    // 0x8080011C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800120: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2448, 0X754) << 16);
    // 0x80800124: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2448, 0X768) << 16);
    // 0x80800128: addiu       $a3, $a3, 0x768
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2448, 0X768));
    // 0x8080012C: addiu       $a2, $a2, 0x754
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2448, 0X754));
    // 0x80800130: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800134: jal         0x80089D28
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080013C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800140: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80800144: jal         0x800EFCD8
    // 0x80800148: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_800EFCD8(rdram, ctx);
        goto after_1;
    // 0x80800148: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_1:
    // 0x8080014C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800150: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800154: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800158: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x8080015C: jal         0x800EE780
    // 0x80800160: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    func_800EE780(rdram, ctx);
        goto after_2;
    // 0x80800160: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800164: jal         0x800D8FF8
    // 0x80800168: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x80800168: nop

    after_3:
    // 0x8080016C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800170: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800174: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800178: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080017C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800180: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800184: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800188: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x8080018C: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800190: jal         0x800136E4
    // 0x80800194: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x80800194: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_4:
    // 0x80800198: b           L_80800218
    // 0x8080019C: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
        goto L_80800218;
    // 0x8080019C: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
L_808001A0:
    // 0x808001A0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2448, 0X774) << 16);
    // 0x808001A4: addiu       $a2, $a2, 0x774
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2448, 0X774));
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001B0: jal         0x80089D20
    // 0x808001B4: lui         $a3, 0x3E80
    ctx->r7 = S32(0X3E80 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808001B4: lui         $a3, 0x3E80
    ctx->r7 = S32(0X3E80 << 16);
    after_5:
    // 0x808001B8: b           L_80800218
    // 0x808001BC: nop

        goto L_80800218;
    // 0x808001BC: nop

L_808001C0:
    // 0x808001C0: jal         0x8010D23C
    // 0x808001C4: nop

    func_8010D23C(rdram, ctx);
        goto after_6;
    // 0x808001C4: nop

    after_6:
    // 0x808001C8: beq         $v0, $zero, L_808001E0
    if (ctx->r2 == 0) {
        // 0x808001CC: nop
    
            goto L_808001E0;
    }
    // 0x808001CC: nop

    // 0x808001D0: jal         0x8010D254
    // 0x808001D4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_8010D254(rdram, ctx);
        goto after_7;
    // 0x808001D4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_7:
    // 0x808001D8: b           L_808001E8
    // 0x808001DC: nop

        goto L_808001E8;
    // 0x808001DC: nop

L_808001E0:
    // 0x808001E0: jal         0x800E3980
    // 0x808001E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800E3980(rdram, ctx);
        goto after_8;
    // 0x808001E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_8:
L_808001E8:
    // 0x808001E8: jal         0x8010D600
    // 0x808001EC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_8010D600(rdram, ctx);
        goto after_9;
    // 0x808001EC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_9:
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: jal         0x80102D78
    // 0x808001F8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80102D78(rdram, ctx);
        goto after_10;
    // 0x808001F8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_10:
    // 0x808001FC: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800200: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800204: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x80800210: jal         0x80102BF8
    // 0x80800214: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    func_80102BF8(rdram, ctx);
        goto after_11;
    // 0x80800214: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    after_11:
L_80800218:
    // 0x80800218: jal         0x800F54E4
    // 0x8080021C: nop

    func_800F54E4(rdram, ctx);
        goto after_12;
    // 0x8080021C: nop

    after_12:
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: jal         0x80800644
    // 0x80800228: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800644_chfootwear(rdram, ctx);
        goto after_13;
    // 0x80800228: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x8080022C: bnel        $v0, $zero, L_80800248
    if (ctx->r2 != 0) {
        // 0x80800230: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_80800248;
    }
    goto skip_0;
    // 0x80800230: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    skip_0:
    // 0x80800234: jal         0x80088848
    // 0x80800238: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_14;
    // 0x80800238: nop

    after_14:
    // 0x8080023C: beq         $v0, $zero, L_80800250
    if (ctx->r2 == 0) {
        // 0x80800240: addiu       $t8, $zero, 0x78
        ctx->r24 = ADD32(0, 0X78);
            goto L_80800250;
    }
    // 0x80800240: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x80800244: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
L_80800248:
    // 0x80800248: b           L_80800254
    // 0x8080024C: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
        goto L_80800254;
    // 0x8080024C: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
L_80800250:
    // 0x80800250: sw          $t8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r24;
L_80800254:
    // 0x80800254: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x80800258: lbu         $v0, 0x9B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9B);
    // 0x8080025C: addiu       $t9, $v1, -0x5
    ctx->r25 = ADD32(ctx->r3, -0X5);
    // 0x80800260: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800264: beq         $at, $zero, L_80800278
    if (ctx->r1 == 0) {
        // 0x80800268: addiu       $t1, $v1, 0x5
        ctx->r9 = ADD32(ctx->r3, 0X5);
            goto L_80800278;
    }
    // 0x80800268: addiu       $t1, $v1, 0x5
    ctx->r9 = ADD32(ctx->r3, 0X5);
    // 0x8080026C: addiu       $t0, $v0, 0x5
    ctx->r8 = ADD32(ctx->r2, 0X5);
    // 0x80800270: b           L_80800350
    // 0x80800274: sb          $t0, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r8;
        goto L_80800350;
    // 0x80800274: sb          $t0, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r8;
L_80800278:
    // 0x80800278: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080027C: beq         $at, $zero, L_8080028C
    if (ctx->r1 == 0) {
        // 0x80800280: addiu       $t2, $v0, -0x5
        ctx->r10 = ADD32(ctx->r2, -0X5);
            goto L_8080028C;
    }
    // 0x80800280: addiu       $t2, $v0, -0x5
    ctx->r10 = ADD32(ctx->r2, -0X5);
    // 0x80800284: b           L_80800350
    // 0x80800288: sb          $t2, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r10;
        goto L_80800350;
    // 0x80800288: sb          $t2, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r10;
L_8080028C:
    // 0x8080028C: b           L_80800350
    // 0x80800290: sb          $v1, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r3;
        goto L_80800350;
    // 0x80800290: sb          $v1, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r3;
L_80800294:
    // 0x80800294: jal         0x800D90A4
    // 0x80800298: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    func_800D90A4(rdram, ctx);
        goto after_15;
    // 0x80800298: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    after_15:
    // 0x8080029C: beql        $v0, $zero, L_80800354
    if (ctx->r2 == 0) {
        // 0x808002A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800354;
    }
    goto skip_1;
    // 0x808002A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808002A4: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x808002A8: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2448, 0X6E4) << 16);
    // 0x808002AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808002B0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x808002B4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x808002B8: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x808002BC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x808002C0: lh          $t5, 0x6E4($t5)
    ctx->r13 = MEM_H(ctx->r13, (int16_t)RELOC_LO16(2448, 0X6E4));
    // 0x808002C4: beq         $t5, $zero, L_808002D4
    if (ctx->r13 == 0) {
        // 0x808002C8: nop
    
            goto L_808002D4;
    }
    // 0x808002C8: nop

    // 0x808002CC: b           L_808002D4
    // 0x808002D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_808002D4;
    // 0x808002D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_808002D4:
    // 0x808002D4: jal         0x80800424
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800424_chfootwear(rdram, ctx);
        goto after_16;
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808002DC: b           L_80800354
    // 0x808002E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800354;
    // 0x808002E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002E4:
    // 0x808002E4: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x808002E8: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x808002EC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2448, 0X6E4) << 16);
    // 0x808002F0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808002F4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x808002F8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x808002FC: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80800300: srl         $t6, $a0, 4
    ctx->r14 = S32(U32(ctx->r4) >> 4);
    // 0x80800304: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80800308: jal         0x800F549C
    // 0x8080030C: lh          $a1, 0x6E4($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(2448, 0X6E4));
    func_800F549C(rdram, ctx);
        goto after_17;
    // 0x8080030C: lh          $a1, 0x6E4($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(2448, 0X6E4));
    after_17:
    // 0x80800310: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x8080031C: nop

    // 0x80800320: bc1fl       L_80800354
    if (!c1cs) {
        // 0x80800324: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800354;
    }
    goto skip_2;
    // 0x80800324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800328: jal         0x80800424
    // 0x8080032C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800424_chfootwear(rdram, ctx);
        goto after_18;
    // 0x8080032C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_18:
    // 0x80800330: b           L_80800354
    // 0x80800334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800354;
    // 0x80800334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800338:
    // 0x80800338: jal         0x800D90A4
    // 0x8080033C: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    func_800D90A4(rdram, ctx);
        goto after_19;
    // 0x8080033C: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    after_19:
    // 0x80800340: beq         $v0, $zero, L_80800350
    if (ctx->r2 == 0) {
        // 0x80800344: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800350;
    }
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: jal         0x80800424
    // 0x8080034C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800424_chfootwear(rdram, ctx);
        goto after_20;
    // 0x8080034C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
L_80800350:
    // 0x80800350: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800354:
    // 0x80800354: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800358: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080035C: jr          $ra
    // 0x80800360: nop

    return;
    // 0x80800360: nop

;}
RECOMP_FUNC void func_80800068_chminegrilldoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080006C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800070: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800078: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080007C: addiu       $a0, $zero, 0x43B
    ctx->r4 = ADD32(0, 0X43B);
    // 0x80800080: jal         0x800DA298
    // 0x80800084: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800084: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800088: bne         $v0, $zero, L_80800124
    if (ctx->r2 != 0) {
        // 0x8080008C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80800124;
    }
    // 0x8080008C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800090: slti        $at, $a1, 0x79
    ctx->r1 = SIGNED(ctx->r5) < 0X79 ? 1 : 0;
    // 0x80800094: bne         $at, $zero, L_80800124
    if (ctx->r1 != 0) {
        // 0x80800098: slti        $at, $a1, 0x7D
        ctx->r1 = SIGNED(ctx->r5) < 0X7D ? 1 : 0;
            goto L_80800124;
    }
    // 0x80800098: slti        $at, $a1, 0x7D
    ctx->r1 = SIGNED(ctx->r5) < 0X7D ? 1 : 0;
    // 0x8080009C: beq         $at, $zero, L_80800124
    if (ctx->r1 == 0) {
        // 0x808000A0: addiu       $v1, $a1, -0x79
        ctx->r3 = ADD32(ctx->r5, -0X79);
            goto L_80800124;
    }
    // 0x808000A0: addiu       $v1, $a1, -0x79
    ctx->r3 = ADD32(ctx->r5, -0X79);
    // 0x808000A4: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x808000A8: beq         $t6, $zero, L_808000B8
    if (ctx->r14 == 0) {
        // 0x808000AC: andi        $t2, $v1, 0x1
        ctx->r10 = ctx->r3 & 0X1;
            goto L_808000B8;
    }
    // 0x808000AC: andi        $t2, $v1, 0x1
    ctx->r10 = ctx->r3 & 0X1;
    // 0x808000B0: b           L_808000BC
    // 0x808000B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808000BC;
    // 0x808000B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808000B8:
    // 0x808000B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000BC:
    // 0x808000BC: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000C0: lw          $t8, 0x6C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X6C);
    // 0x808000C4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x808000C8: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x808000CC: subu        $t0, $t9, $v0
    ctx->r8 = SUB32(ctx->r25, ctx->r2);
    // 0x808000D0: and         $t1, $t8, $t0
    ctx->r9 = ctx->r24 & ctx->r8;
    // 0x808000D4: andi        $t9, $t7, 0xFE00
    ctx->r25 = ctx->r15 & 0XFE00;
    // 0x808000D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000DC: mflo        $t3
    ctx->r11 = lo;
    // 0x808000E0: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x808000E4: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x808000E8: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x808000EC: sh          $t8, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r24;
    // 0x808000F0: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    // 0x808000F4: andi        $t2, $t0, 0x1FF
    ctx->r10 = ctx->r8 & 0X1FF;
    // 0x808000F8: bne         $t2, $at, L_8080011C
    if (ctx->r10 != ctx->r1) {
        // 0x808000FC: nop
    
            goto L_8080011C;
    }
    // 0x808000FC: nop

    // 0x80800100: jal         0x800DA544
    // 0x80800104: addiu       $a0, $zero, 0x43B
    ctx->r4 = ADD32(0, 0X43B);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800104: addiu       $a0, $zero, 0x43B
    ctx->r4 = ADD32(0, 0X43B);
    after_1:
    // 0x80800108: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080010C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800110: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80800114: jal         0x80085708
    // 0x80800118: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800118: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
L_8080011C:
    // 0x8080011C: b           L_80800130
    // 0x80800120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800130;
    // 0x80800120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800124:
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x80086248
    // 0x8080012C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8080012C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_3:
L_80800130:
    // 0x80800130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800134: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080013C: jr          $ra
    // 0x80800140: nop

    return;
    // 0x80800140: nop

;}
RECOMP_FUNC void _chmoley_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868F8: syscall     396
    recomp_syscall_handler(rdram, ctx, 0x800868F8);
    return;
    // 0x800868FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsmum_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E50: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800E54: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(308, 0X11A0) << 16);
    // 0x80800E58: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800E5C: jr          $ra
    // 0x80800E60: lw          $v0, 0x11A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X11A0));
    return;
    // 0x80800E60: lw          $v0, 0x11A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(308, 0X11A0));
;}
RECOMP_FUNC void func_800DF490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF490: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF494: addiu       $v0, $v0, -0x3658
    ctx->r2 = ADD32(ctx->r2, -0X3658);
    // 0x800DF498: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x800DF49C: jr          $ra
    // 0x800DF4A0: sw          $a1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r5;
    return;
    // 0x800DF4A0: sw          $a1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_801168AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801168AC: ld          $a3, 0x0($a0)
    ctx->r7 = LD(ctx->r4, 0X0);
    // 0x801168B0: dsll32      $a2, $a3, 31
    ctx->r6 = ctx->r7 << (31 + 32);
    // 0x801168B4: dsll        $a1, $a3, 31
    ctx->r5 = ctx->r7 << 31;
    // 0x801168B8: dsrl        $a2, $a2, 31
    ctx->r6 = ctx->r6 >> 31;
    // 0x801168BC: dsrl32      $a1, $a1, 0
    ctx->r5 = ctx->r5 >> (0 + 32);
    // 0x801168C0: dsll32      $a3, $a3, 12
    ctx->r7 = ctx->r7 << (12 + 32);
    // 0x801168C4: or          $a2, $a2, $a1
    ctx->r6 = ctx->r6 | ctx->r5;
    // 0x801168C8: dsrl32      $a3, $a3, 0
    ctx->r7 = ctx->r7 >> (0 + 32);
    // 0x801168CC: xor         $a2, $a2, $a3
    ctx->r6 = ctx->r6 ^ ctx->r7;
    // 0x801168D0: dsrl        $a3, $a2, 20
    ctx->r7 = ctx->r6 >> 20;
    // 0x801168D4: andi        $a3, $a3, 0xFFF
    ctx->r7 = ctx->r7 & 0XFFF;
    // 0x801168D8: xor         $a3, $a3, $a2
    ctx->r7 = ctx->r7 ^ ctx->r6;
    // 0x801168DC: dsll32      $v0, $a3, 0
    ctx->r2 = ctx->r7 << (0 + 32);
    // 0x801168E0: sd          $a3, 0x0($a0)
    SD(ctx->r7, 0X0, ctx->r4);
    // 0x801168E4: jr          $ra
    // 0x801168E8: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x801168E8: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    // 0x801168EC: nop

;}
RECOMP_FUNC void _plsu_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878A0: syscall     638
    recomp_syscall_handler(rdram, ctx, 0x800878A0);
    return;
    // 0x800878A4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800710_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800710: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800718: jal         0x8009E6EC
    // 0x8080071C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x8080071C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800720: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800724: bne         $v0, $at, L_80800764
    if (ctx->r2 != ctx->r1) {
        // 0x80800728: nop
    
            goto L_80800764;
    }
    // 0x80800728: nop

    // 0x8080072C: jal         0x8008CABC
    // 0x80800730: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x80800730: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800734: jal         0x8008B2B4
    // 0x80800738: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_2;
    // 0x80800738: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080073C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(41, 0X1DB0) << 16);
    // 0x80800740: lwc1        $f4, 0x1DB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1DB0));
    // 0x80800744: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800748: nop

    // 0x8080074C: bc1fl       L_80800770
    if (!c1cs) {
        // 0x80800750: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800770;
    }
    goto skip_0;
    // 0x80800750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800754: jal         0x80099B94
    // 0x80800758: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_3;
    // 0x80800758: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8080075C: b           L_80800770
    // 0x80800760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800770;
    // 0x80800760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800764:
    // 0x80800764: jal         0x80800168
    // 0x80800768: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800168_bsbansack(rdram, ctx);
        goto after_4;
    // 0x80800768: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x8080076C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800770:
    // 0x80800770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800774: jr          $ra
    // 0x80800778: nop

    return;
    // 0x80800778: nop

;}
RECOMP_FUNC void _chglowbo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086AD8: syscall     414
    recomp_syscall_handler(rdram, ctx, 0x80086AD8);
    return;
    // 0x80086ADC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808005E0_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005F0: jal         0x80100094
    // 0x808005F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808005F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808005FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800600: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800604: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x80800608: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(972, 0XF40) << 16);
    // 0x8080060C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800610: nop

    // 0x80800614: bc1f        L_80800658
    if (!c1cs) {
        // 0x80800618: nop
    
            goto L_80800658;
    }
    // 0x80800618: nop

    // 0x8080061C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(972, 0XF40) << 16);
    // 0x80800620: jal         0x80088FE8
    // 0x80800624: addiu       $a1, $a1, 0xF40
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(972, 0XF40));
    _mlwave_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800624: addiu       $a1, $a1, 0xF40
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(972, 0XF40));
    after_1:
    // 0x80800628: beq         $v0, $zero, L_80800688
    if (ctx->r2 == 0) {
        // 0x8080062C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(972, 0XE98) << 16);
            goto L_80800688;
    }
    // 0x8080062C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(972, 0XE98) << 16);
    // 0x80800630: jal         0x800DC298
    // 0x80800634: lwc1        $f12, 0xE98($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(972, 0XE98));
    func_800DC298(rdram, ctx);
        goto after_2;
    // 0x80800634: lwc1        $f12, 0xE98($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(972, 0XE98));
    after_2:
    // 0x80800638: beq         $v0, $zero, L_80800688
    if (ctx->r2 == 0) {
        // 0x8080063C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800688;
    }
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800640: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(972, 0XF4C) << 16);
    // 0x80800644: addiu       $a2, $a2, 0xF4C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(972, 0XF4C));
    // 0x80800648: jal         0x80089D18
    // 0x8080064C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8080064C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800650: b           L_8080068C
    // 0x80800654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080068C;
    // 0x80800654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800658:
    // 0x80800658: jal         0x80088FE8
    // 0x8080065C: addiu       $a1, $a1, 0xF40
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(972, 0XF40));
    _mlwave_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x8080065C: addiu       $a1, $a1, 0xF40
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(972, 0XF40));
    after_4:
    // 0x80800660: beq         $v0, $zero, L_80800688
    if (ctx->r2 == 0) {
        // 0x80800664: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(972, 0XE9C) << 16);
            goto L_80800688;
    }
    // 0x80800664: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(972, 0XE9C) << 16);
    // 0x80800668: jal         0x800DC298
    // 0x8080066C: lwc1        $f12, 0xE9C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(972, 0XE9C));
    func_800DC298(rdram, ctx);
        goto after_5;
    // 0x8080066C: lwc1        $f12, 0xE9C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(972, 0XE9C));
    after_5:
    // 0x80800670: beq         $v0, $zero, L_80800688
    if (ctx->r2 == 0) {
        // 0x80800674: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800688;
    }
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800678: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(972, 0XF58) << 16);
    // 0x8080067C: addiu       $a2, $a2, 0xF58
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(972, 0XF58));
    // 0x80800680: jal         0x80089D18
    // 0x80800684: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800684: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_6:
L_80800688:
    // 0x80800688: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080068C:
    // 0x8080068C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800690: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800694: jr          $ra
    // 0x80800698: nop

    return;
    // 0x80800698: nop

;}
RECOMP_FUNC void _bsjig_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800831F8: syscall     51
    recomp_syscall_handler(rdram, ctx, 0x800831F8);
    return;
    // 0x800831FC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808007F8_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808007FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800800: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800804: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800808: jal         0x8008CABC
    // 0x8080080C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080080C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80800810: lui         $a1, 0x3EC2
    ctx->r5 = S32(0X3EC2 << 16);
    // 0x80800814: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800818: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x8080081C: jal         0x8008B348
    // 0x80800820: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x80800820: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800824: beq         $v0, $zero, L_80800834
    if (ctx->r2 == 0) {
        // 0x80800828: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800834;
    }
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: jal         0x8009FD24
    // 0x80800830: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009FD24(rdram, ctx);
        goto after_2;
    // 0x80800830: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80800834:
    // 0x80800834: lui         $a1, 0x3F61
    ctx->r5 = S32(0X3F61 << 16);
    // 0x80800838: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x8080083C: jal         0x8008B348
    // 0x80800840: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x80800840: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80800844: beq         $v0, $zero, L_80800854
    if (ctx->r2 == 0) {
        // 0x80800848: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800854;
    }
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080084C: jal         0x8009FD24
    // 0x80800850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009FD24(rdram, ctx);
        goto after_4;
    // 0x80800850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80800854:
    // 0x80800854: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800858: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080085C: jal         0x8008B348
    // 0x80800860: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x80800860: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80800864: beq         $v0, $zero, L_80800884
    if (ctx->r2 == 0) {
        // 0x80800868: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_80800884;
    }
    // 0x80800868: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x8080086C: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x80800870: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800874: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080087C: jal         0x8009DE74
    // 0x80800880: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    func_8009DE74(rdram, ctx);
        goto after_6;
    // 0x80800880: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    after_6:
L_80800884:
    // 0x80800884: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800888: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8080088C: jal         0x8008B348
    // 0x80800890: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x80800890: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x80800894: beq         $v0, $zero, L_808008B4
    if (ctx->r2 == 0) {
        // 0x80800898: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_808008B4;
    }
    // 0x80800898: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x8080089C: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x808008A0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808008A4: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008AC: jal         0x8009DE74
    // 0x808008B0: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    func_8009DE74(rdram, ctx);
        goto after_8;
    // 0x808008B0: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    after_8:
L_808008B4:
    // 0x808008B4: jal         0x80800178
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800178_bsswim(rdram, ctx);
        goto after_9;
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808008BC: jal         0x8009EF10
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_10;
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808008C4: bne         $v0, $zero, L_808008D0
    if (ctx->r2 != 0) {
        // 0x808008C8: addiu       $t6, $zero, 0x2D
        ctx->r14 = ADD32(0, 0X2D);
            goto L_808008D0;
    }
    // 0x808008C8: addiu       $t6, $zero, 0x2D
    ctx->r14 = ADD32(0, 0X2D);
    // 0x808008CC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_808008D0:
    // 0x808008D0: jal         0x8008E35C
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_11;
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808008D8: bne         $v0, $zero, L_808008E4
    if (ctx->r2 != 0) {
        // 0x808008DC: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_808008E4;
    }
    // 0x808008DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808008E0: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_808008E4:
    // 0x808008E4: jal         0x8009650C
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009650C(rdram, ctx);
        goto after_12;
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808008EC: beq         $v0, $zero, L_80800968
    if (ctx->r2 == 0) {
        // 0x808008F0: nop
    
            goto L_80800968;
    }
    // 0x808008F0: nop

    // 0x808008F4: jal         0x8008D214
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D214(rdram, ctx);
        goto after_13;
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808008FC: beq         $v0, $zero, L_80800968
    if (ctx->r2 == 0) {
        // 0x80800900: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800968;
    }
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800904: jal         0x80096440
    // 0x80800908: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80096440(rdram, ctx);
        goto after_14;
    // 0x80800908: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_14:
    // 0x8080090C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(384, 0XB84) << 16);
    // 0x80800910: lwc1        $f6, 0xB84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0XB84));
    // 0x80800914: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800918: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080091C: nop

    // 0x80800920: bc1f        L_80800968
    if (!c1cs) {
        // 0x80800924: nop
    
            goto L_80800968;
    }
    // 0x80800924: nop

    // 0x80800928: jal         0x800964DC
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800964DC(rdram, ctx);
        goto after_15;
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800930: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800934: jal         0x8009C150
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C150(rdram, ctx);
        goto after_16;
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080093C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800940: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800944: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800948: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8080094C: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80800950: nop

    // 0x80800954: bc1f        L_80800968
    if (!c1cs) {
        // 0x80800958: nop
    
            goto L_80800968;
    }
    // 0x80800958: nop

    // 0x8080095C: jal         0x80800000
    // 0x80800960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsswim(rdram, ctx);
        goto after_17;
    // 0x80800960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800964: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80800968:
    // 0x80800968: jal         0x80097F48
    // 0x8080096C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_dive(rdram, ctx);
        goto after_18;
    // 0x8080096C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800970: beq         $v0, $zero, L_80800984
    if (ctx->r2 == 0) {
        // 0x80800974: nop
    
            goto L_80800984;
    }
    // 0x80800974: nop

    // 0x80800978: jal         0x80800000
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsswim(rdram, ctx);
        goto after_19;
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800980: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80800984:
    // 0x80800984: jal         0x80096500
    // 0x80800988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096500(rdram, ctx);
        goto after_20;
    // 0x80800988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080098C: beq         $v0, $zero, L_808009A8
    if (ctx->r2 == 0) {
        // 0x80800990: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009A8;
    }
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800994: jal         0x80091A58
    // 0x80800998: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_21;
    // 0x80800998: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_21:
    // 0x8080099C: beq         $v0, $zero, L_808009A8
    if (ctx->r2 == 0) {
        // 0x808009A0: addiu       $t8, $zero, 0x5
        ctx->r24 = ADD32(0, 0X5);
            goto L_808009A8;
    }
    // 0x808009A0: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x808009A4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_808009A8:
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009AC: jal         0x80095738
    // 0x808009B0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baflag_isTrue(rdram, ctx);
        goto after_22;
    // 0x808009B0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_22:
    // 0x808009B4: bne         $v0, $zero, L_808009C8
    if (ctx->r2 != 0) {
        // 0x808009B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009C8;
    }
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009BC: jal         0x80095738
    // 0x808009C0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    baflag_isTrue(rdram, ctx);
        goto after_23;
    // 0x808009C0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_23:
    // 0x808009C4: beq         $v0, $zero, L_808009D0
    if (ctx->r2 == 0) {
        // 0x808009C8: addiu       $t9, $zero, 0xD
        ctx->r25 = ADD32(0, 0XD);
            goto L_808009D0;
    }
L_808009C8:
    // 0x808009C8: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
    // 0x808009CC: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_808009D0:
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D4: jal         0x8009E5C8
    // 0x808009D8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_24;
    // 0x808009D8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_24:
    // 0x808009DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808009E8: jr          $ra
    // 0x808009EC: nop

    return;
    // 0x808009EC: nop

;}
RECOMP_FUNC void _chwaspnestgame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B50: syscall     198
    recomp_syscall_handler(rdram, ctx, 0x80085B50);
    return;
    // 0x80085B54: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801D6C_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801D70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D74: jal         0x80801C20
    // 0x80801D78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80801C20_chtntmineshoot(rdram, ctx);
        goto after_0;
    // 0x80801D78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801D7C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80801D80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801D84: lhu         $v0, 0x72($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X72);
    // 0x80801D88: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80801D8C: beq         $t6, $at, L_80801DDC
    if (ctx->r14 == ctx->r1) {
        // 0x80801D90: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801DDC;
    }
    // 0x80801D90: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801D94: beq         $t6, $at, L_80801DAC
    if (ctx->r14 == ctx->r1) {
        // 0x80801D98: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80801DAC;
    }
    // 0x80801D98: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801D9C: beql        $t6, $at, L_80801DE0
    if (ctx->r14 == ctx->r1) {
        // 0x80801DA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801DE0;
    }
    goto skip_0;
    // 0x80801DA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801DA4: b           L_80801DE0
    // 0x80801DA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801DE0;
    // 0x80801DA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801DAC:
    // 0x80801DAC: jal         0x800D9078
    // 0x80801DB0: addiu       $a0, $v1, 0x58
    ctx->r4 = ADD32(ctx->r3, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80801DB0: addiu       $a0, $v1, 0x58
    ctx->r4 = ADD32(ctx->r3, 0X58);
    after_1:
    // 0x80801DB4: beq         $v0, $zero, L_80801DDC
    if (ctx->r2 == 0) {
        // 0x80801DB8: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_80801DDC;
    }
    // 0x80801DB8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80801DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801DC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801DC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801DC8: jal         0x800D1000
    // 0x80801DCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_2;
    // 0x80801DCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80801DD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801DD4: jal         0x80101FDC
    // 0x80801DD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80801DD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_80801DDC:
    // 0x80801DDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801DE0:
    // 0x80801DE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801DE4: jr          $ra
    // 0x80801DE8: nop

    return;
    // 0x80801DE8: nop

;}
RECOMP_FUNC void func_8080000C_chlightdemon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x80105834
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80105834(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: lw          $a0, 0x28($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X28);
    // 0x80800024: jal         0x800C8CB8
    // 0x80800028: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    after_1:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void _chfreezy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F78: syscall     266
    recomp_syscall_handler(rdram, ctx, 0x80085F78);
    return;
    // 0x80085F7C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080436C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080436C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804374: jal         0x808090D8
    // 0x80804378: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808090D8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80804378: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080437C: jal         0x80807C8C
    // 0x80804380: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80804380: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80804384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080438C: jr          $ra
    // 0x80804390: nop

    return;
    // 0x80804390: nop

;}
RECOMP_FUNC void rare_memmove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BBF0: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8001BBF4: beq         $at, $zero, L_8001BC2C
    if (ctx->r1 == 0) {
        // 0x8001BBF8: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_8001BC2C;
    }
    // 0x8001BBF8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001BBFC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001BC00: beq         $a2, $zero, L_8001BC60
    if (ctx->r6 == 0) {
        // 0x8001BC04: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8001BC60;
    }
    // 0x8001BC04: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001BC08:
    // 0x8001BC08: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x8001BC0C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001BC10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001BC14: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001BC18: sb          $t6, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r14;
    // 0x8001BC1C: bne         $a2, $zero, L_8001BC08
    if (ctx->r6 != 0) {
        // 0x8001BC20: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8001BC08;
    }
    // 0x8001BC20: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001BC24: jr          $ra
    // 0x8001BC28: nop

    return;
    // 0x8001BC28: nop

L_8001BC2C:
    // 0x8001BC2C: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8001BC30: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x8001BC34: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8001BC38: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001BC3C: beq         $a2, $zero, L_8001BC60
    if (ctx->r6 == 0) {
        // 0x8001BC40: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8001BC60;
    }
    // 0x8001BC40: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001BC44:
    // 0x8001BC44: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x8001BC48: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001BC4C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8001BC50: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001BC54: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x8001BC58: bne         $a2, $zero, L_8001BC44
    if (ctx->r6 != 0) {
        // 0x8001BC5C: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8001BC44;
    }
    // 0x8001BC5C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001BC60:
    // 0x8001BC60: jr          $ra
    // 0x8001BC64: nop

    return;
    // 0x8001BC64: nop

;}
RECOMP_FUNC void bsjig_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800300: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800304: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800308: jal         0x808002B4
    // 0x8080030C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bsjig_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080030C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: jal         0x800A0CF4
    // 0x80800318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_1;
    // 0x80800318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080031C: jal         0x800A4E30
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E30(rdram, ctx);
        goto after_2;
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800324: jal         0x800A4C68
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_3;
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080032C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800330: jal         0x800C53EC
    // 0x80800334: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C53EC(rdram, ctx);
        goto after_4;
    // 0x80800334: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800338: jal         0x8008E95C
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E95C(rdram, ctx);
        goto after_5;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800340: jal         0x8009CEE8
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CEE8(rdram, ctx);
        goto after_6;
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080034C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800354: jr          $ra
    // 0x80800358: nop

    return;
    // 0x80800358: nop

;}
RECOMP_FUNC void func_80800524_gspropsDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800524: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800528: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080052C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800530: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800534: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800538: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080053C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800540: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800544: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800548: lh          $s6, 0x2($a0)
    ctx->r22 = MEM_H(ctx->r4, 0X2);
    // 0x8080054C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800550: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80800554: blez        $s6, L_80800668
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80800558: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80800668;
    }
    // 0x80800558: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8080055C: addiu       $s3, $sp, 0x44
    ctx->r19 = ADD32(ctx->r29, 0X44);
    // 0x80800560: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800564:
    // 0x80800564: jal         0x800E9BF4
    // 0x80800568: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800E9BF4(rdram, ctx);
        goto after_0;
    // 0x80800568: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x8080056C: jal         0x808004E0
    // 0x80800570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808004E0_gspropsDll(rdram, ctx);
        goto after_1;
    // 0x80800570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800574: beq         $v0, $zero, L_8080065C
    if (ctx->r2 == 0) {
        // 0x80800578: or          $s1, $s4, $zero
        ctx->r17 = ctx->r20 | 0;
            goto L_8080065C;
    }
    // 0x80800578: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x8080057C: blez        $s4, L_8080065C
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80800580: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8080065C;
    }
    // 0x80800580: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80800584: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800588: jal         0x800E9BF4
    // 0x8080058C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800E9BF4(rdram, ctx);
        goto after_2;
    // 0x8080058C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x80800590: jal         0x808004E0
    // 0x80800594: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808004E0_gspropsDll(rdram, ctx);
        goto after_3;
    // 0x80800594: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800598: beq         $v0, $zero, L_8080065C
    if (ctx->r2 == 0) {
        // 0x8080059C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080065C;
    }
    // 0x8080059C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808005A0: jal         0x800E9BF4
    // 0x808005A4: addiu       $a1, $s4, -0x1
    ctx->r5 = ADD32(ctx->r20, -0X1);
    func_800E9BF4(rdram, ctx);
        goto after_4;
    // 0x808005A4: addiu       $a1, $s4, -0x1
    ctx->r5 = ADD32(ctx->r20, -0X1);
    after_4:
    // 0x808005A8: jal         0x808004E0
    // 0x808005AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808004E0_gspropsDll(rdram, ctx);
        goto after_5;
    // 0x808005AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808005B0: bne         $v0, $zero, L_8080065C
    if (ctx->r2 != 0) {
        // 0x808005B4: addiu       $s0, $s1, -0x1
        ctx->r16 = ADD32(ctx->r17, -0X1);
            goto L_8080065C;
    }
    // 0x808005B4: addiu       $s0, $s1, -0x1
    ctx->r16 = ADD32(ctx->r17, -0X1);
    // 0x808005B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808005BC:
    // 0x808005BC: jal         0x800E9BF4
    // 0x808005C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800E9BF4(rdram, ctx);
        goto after_6;
    // 0x808005C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x808005C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808005C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808005CC: jal         0x8001BBC8
    // 0x808005D0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    aligned4_memcpy(rdram, ctx);
        goto after_7;
    // 0x808005D0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_7:
    // 0x808005D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808005D8: jal         0x800E9BF4
    // 0x808005DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800E9BF4(rdram, ctx);
        goto after_8;
    // 0x808005DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x808005E0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808005E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808005E8: jal         0x800E9BF4
    // 0x808005EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E9BF4(rdram, ctx);
        goto after_9;
    // 0x808005EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x808005F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808005F8: jal         0x8001BBC8
    // 0x808005FC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    aligned4_memcpy(rdram, ctx);
        goto after_10;
    // 0x808005FC: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_10:
    // 0x80800600: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800604: jal         0x800E9BF4
    // 0x80800608: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E9BF4(rdram, ctx);
        goto after_11;
    // 0x80800608: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x8080060C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800610: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800614: jal         0x8001BBC8
    // 0x80800618: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    aligned4_memcpy(rdram, ctx);
        goto after_12;
    // 0x80800618: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_12:
    // 0x8080061C: blez        $s0, L_8080065C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80800620: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_8080065C;
    }
    // 0x80800620: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80800624: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800628: jal         0x800E9BF4
    // 0x8080062C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E9BF4(rdram, ctx);
        goto after_13;
    // 0x8080062C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x80800630: jal         0x808004E0
    // 0x80800634: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808004E0_gspropsDll(rdram, ctx);
        goto after_14;
    // 0x80800634: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x80800638: beq         $v0, $zero, L_8080065C
    if (ctx->r2 == 0) {
        // 0x8080063C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080065C;
    }
    // 0x8080063C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800640: addiu       $s0, $s1, -0x1
    ctx->r16 = ADD32(ctx->r17, -0X1);
    // 0x80800644: jal         0x800E9BF4
    // 0x80800648: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E9BF4(rdram, ctx);
        goto after_15;
    // 0x80800648: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
    // 0x8080064C: jal         0x808004E0
    // 0x80800650: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808004E0_gspropsDll(rdram, ctx);
        goto after_16;
    // 0x80800650: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_16:
    // 0x80800654: beql        $v0, $zero, L_808005BC
    if (ctx->r2 == 0) {
        // 0x80800658: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808005BC;
    }
    goto skip_0;
    // 0x80800658: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_8080065C:
    // 0x8080065C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800660: bnel        $s4, $s6, L_80800564
    if (ctx->r20 != ctx->r22) {
        // 0x80800664: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800564;
    }
    goto skip_1;
    // 0x80800664: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_80800668:
    // 0x80800668: jal         0x800BE5C4
    // 0x8080066C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800BE5C4(rdram, ctx);
        goto after_17;
    // 0x8080066C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x80800670: sb          $s5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r21;
    // 0x80800674: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800678: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8080067C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800680: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800684: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800688: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080068C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800690: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800694: jr          $ra
    // 0x80800698: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800698: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800D3FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3FC0: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D3FC4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D3FC8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D3FCC: jr          $ra
    // 0x800D3FD0: lhu         $v0, -0x4A42($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4A42);
    return;
    // 0x800D3FD0: lhu         $v0, -0x4A42($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4A42);
;}
