#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8010105C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010105C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80101060: jr          $ra
    // 0x80101064: swc1        $f12, 0x5A7C($at)
    MEM_W(0X5A7C, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x80101064: swc1        $f12, 0x5A7C($at)
    MEM_W(0X5A7C, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void _bsfirstp_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084310: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084310);
    return;
    // 0x80084314: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_800BBED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BBED8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800BBEDC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800BBEE0: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x800BBEE4: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x800BBEE8: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x800BBEEC: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x800BBEF0: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x800BBEF4: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x800BBEF8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800BBEFC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800BBF00: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800BBF04: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800BBF08: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BBF0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BBF10: lwc1        $f4, 0x5C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x800BBF14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BBF18: mtc1        $a1, $f26
    ctx->f26.u32l = ctx->r5;
    // 0x800BBF1C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800BBF20: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800BBF24: mul.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800BBF28: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800BBF2C: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800BBF30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BBF34: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BBF38: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
L_800BBF3C:
    // 0x800BBF3C: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x800BBF40: addu        $s1, $s4, $s2
    ctx->r17 = ADD32(ctx->r20, ctx->r18);
    // 0x800BBF44: c.eq.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl == ctx->f8.fl;
    // 0x800BBF48: nop

    // 0x800BBF4C: bc1tl       L_800BBFA0
    if (c1cs) {
        // 0x800BBF50: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800BBFA0;
    }
    goto skip_0;
    // 0x800BBF50: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_0:
    // 0x800BBF54: lwc1        $f10, 0x60($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X60);
    // 0x800BBF58: lwc1        $f14, 0x5C($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X5C);
    // 0x800BBF5C: jal         0x800F13C4
    // 0x800BBF60: add.s       $f12, $f10, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f26.fl;
    func_800F13C4(rdram, ctx);
        goto after_0;
    // 0x800BBF60: add.s       $f12, $f10, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f26.fl;
    after_0:
    // 0x800BBF64: jal         0x800F2100
    // 0x800BBF68: sub.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f20.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x800BBF68: sub.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f20.fl;
    after_1:
    // 0x800BBF6C: lwc1        $f2, 0x6C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x800BBF70: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800BBF74: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800BBF78: sub.s       $f16, $f24, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f24.fl - ctx->f2.fl;
    // 0x800BBF7C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x800BBF80: add.s       $f18, $f2, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x800BBF84: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800BBF88: jal         0x800F10B4
    // 0x800BBF8C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x800BBF8C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x800BBF90: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BBF94: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800BBF98: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x800BBF9C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_800BBFA0:
    // 0x800BBFA0: bne         $s2, $s5, L_800BBF3C
    if (ctx->r18 != ctx->r21) {
        // 0x800BBFA4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800BBF3C;
    }
    // 0x800BBFA4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800BBFA8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800BBFAC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800BBFB0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800BBFB4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800BBFB8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800BBFBC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x800BBFC0: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x800BBFC4: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x800BBFC8: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x800BBFCC: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x800BBFD0: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x800BBFD4: jr          $ra
    // 0x800BBFD8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800BBFD8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8009BC08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BC08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BC0C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8009BC10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BC14: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8009BC18: lw          $a1, 0xC8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC8);
    // 0x8009BC1C: jal         0x800EE7F8
    // 0x8009BC20: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009BC20: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x8009BC24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BC28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BC2C: jr          $ra
    // 0x8009BC30: nop

    return;
    // 0x8009BC30: nop

;}
RECOMP_FUNC void func_8080084C_sccustom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080084C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800850: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800858: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3342, 0X950) << 16);
    // 0x8080085C: jal         0x800E73D4
    // 0x80800860: addiu       $a0, $a0, 0x950
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3342, 0X950));
    func_800E73D4(rdram, ctx);
        goto after_0;
    // 0x80800860: addiu       $a0, $a0, 0x950
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3342, 0X950));
    after_0:
    // 0x80800864: jal         0x8008A618
    // 0x80800868: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _scinfobar_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80800868: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080086C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3342, 0X950) << 16);
    // 0x80800870: addiu       $a0, $a0, 0x950
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3342, 0X950));
    // 0x80800874: jal         0x800DB8BC
    // 0x80800878: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DB8BC(rdram, ctx);
        goto after_2;
    // 0x80800878: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8080087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800880: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3342, 0X950) << 16);
    // 0x80800884: addiu       $v0, $v0, 0x950
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3342, 0X950));
    // 0x80800888: jr          $ra
    // 0x8080088C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080088C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _sccustom_big_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A920: syscall     856
    recomp_syscall_handler(rdram, ctx, 0x8008A920);
    return;
    // 0x8008A924: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800208_sucoasterhit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080020C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800210: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800214: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800218: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    // 0x8080021C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800220: srl         $t6, $v0, 22
    ctx->r14 = S32(U32(ctx->r2) >> 22);
    // 0x80800224: xori        $v1, $t6, 0x27D
    ctx->r3 = ctx->r14 ^ 0X27D;
    // 0x80800228: bne         $v1, $zero, L_80800244
    if (ctx->r3 != 0) {
        // 0x8080022C: sltiu       $a2, $t6, 0x1
        ctx->r6 = ctx->r14 < 0X1 ? 1 : 0;
            goto L_80800244;
    }
    // 0x8080022C: sltiu       $a2, $t6, 0x1
    ctx->r6 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80800230: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80800234: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80800238: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8080023C: b           L_80800284
    // 0x80800240: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
        goto L_80800284;
    // 0x80800240: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_80800244:
    // 0x80800244: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80800248: bnel        $t0, $zero, L_80800284
    if (ctx->r8 != 0) {
        // 0x8080024C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800284;
    }
    goto skip_0;
    // 0x8080024C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800250: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x80800254: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800258: bne         $a1, $zero, L_80800268
    if (ctx->r5 != 0) {
        // 0x8080025C: nop
    
            goto L_80800268;
    }
    // 0x8080025C: nop

    // 0x80800260: beql        $a2, $zero, L_80800280
    if (ctx->r6 == 0) {
        // 0x80800264: sw          $zero, 0x0($a3)
        MEM_W(0X0, ctx->r7) = 0;
            goto L_80800280;
    }
    goto skip_1;
    // 0x80800264: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    skip_1:
L_80800268:
    // 0x80800268: jal         0x800F0E28
    // 0x8080026C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800F0E28(rdram, ctx);
        goto after_0;
    // 0x8080026C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800270: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800274: b           L_80800280
    // 0x80800278: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
        goto L_80800280;
    // 0x80800278: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8080027C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80800280:
    // 0x80800280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800284:
    // 0x80800284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080028C: jr          $ra
    // 0x80800290: nop

    return;
    // 0x80800290: nop

;}
RECOMP_FUNC void _cheggfire_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800871E8: syscall     535
    recomp_syscall_handler(rdram, ctx, 0x800871E8);
    return;
    // 0x800871EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _mlspline_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089128: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x80089128);
    return;
    // 0x8008912C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_808006C4_chmrsicecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808006C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006CC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808006D0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808006D4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808006D8: jal         0x80100094
    // 0x808006DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006E0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808006E4: jal         0x8008A040
    // 0x808006E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808006E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808006EC: lw          $v1, 0x28($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X28);
    // 0x808006F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006F4: addiu       $a1, $zero, 0x12D3
    ctx->r5 = ADD32(0, 0X12D3);
    // 0x808006F8: bne         $v1, $zero, L_80800730
    if (ctx->r3 != 0) {
        // 0x808006FC: addiu       $a2, $zero, 0x44
        ctx->r6 = ADD32(0, 0X44);
            goto L_80800730;
    }
    // 0x808006FC: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800700: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800704: addiu       $t6, $zero, 0xA7
    ctx->r14 = ADD32(0, 0XA7);
    // 0x80800708: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080070C: jal         0x8008A208
    // 0x80800710: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800710: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80800714: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1204, 0XA54) << 16);
    // 0x80800718: addiu       $a2, $a2, 0xA54
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1204, 0XA54));
    // 0x8080071C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800720: jal         0x80089D18
    // 0x80800724: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800724: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_3:
    // 0x80800728: jal         0x800DA544
    // 0x8080072C: addiu       $a0, $zero, 0x378
    ctx->r4 = ADD32(0, 0X378);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x8080072C: addiu       $a0, $zero, 0x378
    ctx->r4 = ADD32(0, 0X378);
    after_4:
L_80800730:
    // 0x80800730: beq         $s0, $zero, L_808007F4
    if (ctx->r16 == 0) {
        // 0x80800734: nop
    
            goto L_808007F4;
    }
    // 0x80800734: nop

    // 0x80800738: jal         0x8008A020
    // 0x8080073C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080073C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800740: jal         0x8010A590
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_6;
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080074C: jal         0x80102F74
    // 0x80800750: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    func_80102F74(rdram, ctx);
        goto after_7;
    // 0x80800750: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_7:
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800758: jal         0x8010A654
    // 0x8080075C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010A654(rdram, ctx);
        goto after_8;
    // 0x8080075C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800764: jal         0x80102190
    // 0x80800768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80102190(rdram, ctx);
        goto after_9;
    // 0x80800768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8080076C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80800770: ori         $a1, $a1, 0x800
    ctx->r5 = ctx->r5 | 0X800;
    // 0x80800774: jal         0x80102F74
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102F74(rdram, ctx);
        goto after_10;
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800780: jal         0x80103110
    // 0x80800784: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    func_80103110(rdram, ctx);
        goto after_11;
    // 0x80800784: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    after_11:
    // 0x80800788: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8080078C: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x80800790: jal         0x80102F74
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102F74(rdram, ctx);
        goto after_12;
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800798: lbu         $t9, 0x64($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X64);
    // 0x8080079C: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x808007A0: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x808007A4: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x808007A8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808007AC: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x808007B0: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
    // 0x808007B4: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    // 0x808007B8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x808007BC: lbu         $t0, 0x75($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X75);
    // 0x808007C0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1204, 0X912) << 16);
    // 0x808007C4: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x808007C8: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x808007CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808007D0: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x808007D4: andi        $t8, $t9, 0x10
    ctx->r24 = ctx->r25 & 0X10;
    // 0x808007D8: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x808007DC: sb          $t2, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r10;
    // 0x808007E0: lw          $t3, 0x28($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X28);
    // 0x808007E4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x808007E8: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x808007EC: jal         0x800858F0
    // 0x808007F0: lhu         $a0, 0x912($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(1204, 0X912));
    _chbounce_entrypoint_5(rdram, ctx);
        goto after_13;
    // 0x808007F0: lhu         $a0, 0x912($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(1204, 0X912));
    after_13:
L_808007F4:
    // 0x808007F4: jal         0x80800818
    // 0x808007F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800818_chmrsicecube(rdram, ctx);
        goto after_14;
    // 0x808007F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x808007FC: jal         0x800FFAB0
    // 0x80800800: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_15;
    // 0x80800800: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80800804: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800808: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080080C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800810: jr          $ra
    // 0x80800814: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800814: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800F9070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9078: jal         0x800F88A0
    // 0x800F907C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F88A0(rdram, ctx);
        goto after_0;
    // 0x800F907C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800F9080: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800F9084: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    // 0x800F9088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F908C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F9090: jr          $ra
    // 0x800F9094: nop

    return;
    // 0x800F9094: nop

;}
RECOMP_FUNC void glzone_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800098: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x8080009C: jr          $ra
    // 0x808000A0: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    return;
    // 0x808000A0: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_80800C9C_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800CAC: beq         $a2, $at, L_80800CD4
    if (ctx->r6 == ctx->r1) {
        // 0x80800CB0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800CD4;
    }
    // 0x80800CB0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800CB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800CB8: beq         $a2, $at, L_80800CF0
    if (ctx->r6 == ctx->r1) {
        // 0x80800CBC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800CF0;
    }
    // 0x80800CBC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800CC0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800CC4: beq         $a2, $at, L_80800D08
    if (ctx->r6 == ctx->r1) {
        // 0x80800CC8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800D08;
    }
    // 0x80800CC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800CCC: b           L_80800D1C
    // 0x80800CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D1C;
    // 0x80800CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CD4:
    // 0x80800CD4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800CD8: jal         0x80108B04
    // 0x80800CDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_0;
    // 0x80800CDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800CE0: jal         0x800DA544
    // 0x80800CE4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800CE4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80800CE8: b           L_80800D1C
    // 0x80800CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D1C;
    // 0x80800CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CF0:
    // 0x80800CF0: jal         0x80108B04
    // 0x80800CF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x80800CF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800CF8: jal         0x800DA544
    // 0x80800CFC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800CFC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80800D00: b           L_80800D1C
    // 0x80800D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D1C;
    // 0x80800D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D08:
    // 0x80800D08: jal         0x800DA544
    // 0x80800D0C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80800D0C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_4:
    // 0x80800D10: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800D14: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x80800D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D1C:
    // 0x80800D1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D20: jr          $ra
    // 0x80800D24: nop

    return;
    // 0x80800D24: nop

;}
RECOMP_FUNC void func_80800118_chchompaslunch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080011C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800124: beq         $a1, $at, L_80800140
    if (ctx->r5 == ctx->r1) {
        // 0x80800128: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800140;
    }
    // 0x80800128: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080012C: addiu       $at, $zero, 0xBC
    ctx->r1 = ADD32(0, 0XBC);
    // 0x80800130: beq         $a1, $at, L_80800150
    if (ctx->r5 == ctx->r1) {
        // 0x80800134: nop
    
            goto L_80800150;
    }
    // 0x80800134: nop

    // 0x80800138: b           L_8080016C
    // 0x8080013C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080016C;
    // 0x8080013C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800140:
    // 0x80800140: jal         0x8080017C
    // 0x80800144: nop

    func_8080017C_chchompaslunch(rdram, ctx);
        goto after_0;
    // 0x80800144: nop

    after_0:
    // 0x80800148: b           L_8080016C
    // 0x8080014C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080016C;
    // 0x8080014C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800150:
    // 0x80800150: jal         0x800FFAB0
    // 0x80800154: nop

    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800154: nop

    after_1:
    // 0x80800158: b           L_8080016C
    // 0x8080015C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080016C;
    // 0x8080015C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800160: b           L_8080016C
    // 0x80800164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080016C;
    // 0x80800164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080016C:
    // 0x8080016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

;}
RECOMP_FUNC void func_80800780_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800780: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800784: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800788: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080078C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800790: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800794: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800798: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080079C: addiu       $t6, $zero, 0x7D
    ctx->r14 = ADD32(0, 0X7D);
    // 0x808007A0: addiu       $t7, $zero, 0xFA
    ctx->r15 = ADD32(0, 0XFA);
    // 0x808007A4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x808007A8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x808007AC: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x808007B0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x808007B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808007B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808007BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808007C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808007C4: jal         0x800B4470
    // 0x808007C8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800B4470(rdram, ctx);
        goto after_0;
    // 0x808007C8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x808007CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(824, 0XCC8) << 16);
    // 0x808007D0: lwc1        $f8, 0xCC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(824, 0XCC8));
    // 0x808007D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(824, 0XCCC) << 16);
    // 0x808007D8: lwc1        $f10, 0xCCC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(824, 0XCCC));
    // 0x808007DC: addiu       $a0, $zero, 0x417
    ctx->r4 = ADD32(0, 0X417);
    // 0x808007E0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808007E4: addiu       $a2, $zero, 0x7D00
    ctx->r6 = ADD32(0, 0X7D00);
    // 0x808007E8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808007EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808007F0: jal         0x800C4104
    // 0x808007F4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C4104(rdram, ctx);
        goto after_1;
    // 0x808007F4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x808007F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808007FC: jal         0x80101FDC
    // 0x80800800: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800800: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800804: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800808: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080080C: jal         0x8008A4B0
    // 0x80800810: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800810: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
    after_3:
    // 0x80800814: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800818: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080081C: jr          $ra
    // 0x80800820: nop

    return;
    // 0x80800820: nop

;}
RECOMP_FUNC void _chfactoryroofbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087498: syscall     578
    recomp_syscall_handler(rdram, ctx, 0x80087498);
    return;
    // 0x8008749C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void ncbaspline_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808005F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800600: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x80800604: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800608: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080060C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800614: beql        $t6, $at, L_80800784
    if (ctx->r14 == ctx->r1) {
        // 0x80800618: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800784;
    }
    goto skip_0;
    // 0x80800618: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080061C: lbu         $t7, 0x2C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2C);
    // 0x80800620: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800624: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80800628: bne         $t7, $at, L_80800634
    if (ctx->r15 != ctx->r1) {
        // 0x8080062C: nop
    
            goto L_80800634;
    }
    // 0x8080062C: nop

    // 0x80800630: sb          $t8, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = ctx->r24;
L_80800634:
    // 0x80800634: jal         0x801107F0
    // 0x80800638: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_801107F0(rdram, ctx);
        goto after_0;
    // 0x80800638: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x8080063C: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x80800640: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: lw          $t9, 0x28($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X28);
    // 0x8080064C: beq         $t9, $at, L_80800668
    if (ctx->r25 == ctx->r1) {
        // 0x80800650: nop
    
            goto L_80800668;
    }
    // 0x80800650: nop

    // 0x80800654: jal         0x80800318
    // 0x80800658: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80800318_ncbaspline(rdram, ctx);
        goto after_1;
    // 0x80800658: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x8080065C: bne         $v0, $zero, L_80800670
    if (ctx->r2 != 0) {
        // 0x80800660: nop
    
            goto L_80800670;
    }
    // 0x80800660: nop

    // 0x80800664: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
L_80800668:
    // 0x80800668: b           L_80800780
    // 0x8080066C: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
        goto L_80800780;
    // 0x8080066C: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
L_80800670:
    // 0x80800670: jal         0x80800008
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800008_ncbaspline(rdram, ctx);
        goto after_2;
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800678: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x8080067C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800680: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800684: jal         0x800C7A68
    // 0x80800688: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    func_800C7A68(rdram, ctx);
        goto after_3;
    // 0x80800688: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    after_3:
    // 0x8080068C: lw          $t1, 0x44($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X44);
    // 0x80800690: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800694: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800698: lwc1        $f12, 0x18($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X18);
    // 0x8080069C: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x808006A0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808006A4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x808006A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808006AC: bc1fl       L_80800750
    if (!c1cs) {
        // 0x808006B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800750;
    }
    goto skip_1;
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808006B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808006B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3062, 0XA48) << 16);
    // 0x808006BC: lwc1        $f4, 0xA48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3062, 0XA48));
    // 0x808006C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808006C4: jal         0x800F10B4
    // 0x808006C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808006C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x808006CC: jal         0x800D8FF8
    // 0x808006D0: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x808006D0: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x808006D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808006D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006DC: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808006E0: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x808006E4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808006E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006EC: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x808006F0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808006F4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808006F8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808006FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800700: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80800704: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x80800708: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x8080070C: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800710: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800714: nop

    // 0x80800718: bc1fl       L_80800750
    if (!c1cs) {
        // 0x8080071C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800750;
    }
    goto skip_2;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800720: jal         0x800EFB24
    // 0x80800724: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x80800724: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
    after_6:
    // 0x80800728: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
    // 0x8080072C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800730: jal         0x800EF334
    // 0x80800734: lw          $a1, 0x18($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X18);
    func_800EF334(rdram, ctx);
        goto after_7;
    // 0x80800734: lw          $a1, 0x18($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X18);
    after_7:
    // 0x80800738: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x8080073C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800740: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x80800744: jal         0x800EE780
    // 0x80800748: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE780(rdram, ctx);
        goto after_8;
    // 0x80800748: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_8:
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800750:
    // 0x80800750: jal         0x80110770
    // 0x80800754: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80110770(rdram, ctx);
        goto after_9;
    // 0x80800754: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_9:
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080075C: jal         0x80112524
    // 0x80800760: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_80112524(rdram, ctx);
        goto after_10;
    // 0x80800760: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_10:
    // 0x80800764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800768: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080076C: jal         0x80110A68
    // 0x80800770: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_80110A68(rdram, ctx);
        goto after_11;
    // 0x80800770: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_11:
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800778: jal         0x80110790
    // 0x8080077C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80110790(rdram, ctx);
        goto after_12;
    // 0x8080077C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_12:
L_80800780:
    // 0x80800780: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800784:
    // 0x80800784: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800788: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8080078C: jr          $ra
    // 0x80800790: nop

    return;
    // 0x80800790: nop

;}
RECOMP_FUNC void func_808003D8_chbeanstalkseed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808003DC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808003E0: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x808003E4: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x808003E8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808003EC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808003F0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808003F4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808003F8: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808003FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800400: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800404: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800408: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x8080040C: beq         $at, $zero, L_808007E0
    if (ctx->r1 == 0) {
        // 0x80800410: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808007E0;
    }
    // 0x80800410: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800414: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2356, 0XB98) << 16);
    // 0x80800418: addu        $at, $at, $t8
    gpr jr_addend_80800420 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080041C: lw          $t8, 0xB98($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2356, 0XB98));
    // 0x80800420: jr          $t8
    // 0x80800424: nop

    switch (jr_addend_80800420 >> 2) {
        case 0: goto L_80800428; break;
        case 1: goto L_80800478; break;
        case 2: goto L_808004E0; break;
        case 3: goto L_808004F0; break;
        case 4: goto L_8080070C; break;
        default: switch_error(__func__, 0x80800420, 0x80800B98);
    }
    // 0x80800424: nop

L_80800428:
    // 0x80800428: jal         0x80800328
    // 0x8080042C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800328_chbeanstalkseed(rdram, ctx);
        goto after_0;
    // 0x8080042C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80800430: beq         $v0, $zero, L_808007E0
    if (ctx->r2 == 0) {
        // 0x80800434: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808007E0;
    }
    // 0x80800434: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080043C: jal         0x801000D8
    // 0x80800440: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_801000D8(rdram, ctx);
        goto after_1;
    // 0x80800440: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_1:
    // 0x80800444: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800448: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080044C: addiu       $a1, $zero, 0x481
    ctx->r5 = ADD32(0, 0X481);
    // 0x80800450: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    // 0x80800454: jal         0x80089FD0
    // 0x80800458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddieitem_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800458: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8080045C: jal         0x80089FE0
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieitem_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800464: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800468: jal         0x80101FDC
    // 0x8080046C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x8080046C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800470: b           L_808007E4
    // 0x80800474: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808007E4;
    // 0x80800474: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800478:
    // 0x80800478: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080047C: jal         0x80100094
    // 0x80800480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x80800480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800484: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800488: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x8080048C: jal         0x80089FE8
    // 0x80800490: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _subaddieitem_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800490: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
    // 0x80800494: beq         $v0, $zero, L_808007E0
    if (ctx->r2 == 0) {
        // 0x80800498: addiu       $a0, $zero, 0x481
        ctx->r4 = ADD32(0, 0X481);
            goto L_808007E0;
    }
    // 0x80800498: addiu       $a0, $zero, 0x481
    ctx->r4 = ADD32(0, 0X481);
    // 0x8080049C: jal         0x80089C30
    // 0x808004A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x808004A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808004A4: beql        $v0, $zero, L_808004C0
    if (ctx->r2 == 0) {
        // 0x808004A8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808004C0;
    }
    goto skip_0;
    // 0x808004A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x808004AC: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x808004B0: swc1        $f4, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f4.u32l;
    // 0x808004B4: jal         0x800FFA88
    // 0x808004B8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_8;
    // 0x808004B8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_8:
    // 0x808004BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808004C0:
    // 0x808004C0: jal         0x80800804
    // 0x808004C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800804_chbeanstalkseed(rdram, ctx);
        goto after_9;
    // 0x808004C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x808004C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004D0: jal         0x80100074
    // 0x808004D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_10;
    // 0x808004D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x808004D8: b           L_808007E4
    // 0x808004DC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808007E4;
    // 0x808004DC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808004E0:
    // 0x808004E0: jal         0x8010C964
    // 0x808004E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010C964(rdram, ctx);
        goto after_11;
    // 0x808004E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x808004E8: b           L_808007E4
    // 0x808004EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808007E4;
    // 0x808004EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808004F0:
    // 0x808004F0: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    // 0x808004F4: jal         0x800D91EC
    // 0x808004F8: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    func_800D91EC(rdram, ctx);
        goto after_12;
    // 0x808004F8: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    after_12:
    // 0x808004FC: beq         $v0, $zero, L_80800518
    if (ctx->r2 == 0) {
        // 0x80800500: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2356, 0XBAC) << 16);
            goto L_80800518;
    }
    // 0x80800500: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2356, 0XBAC) << 16);
    // 0x80800504: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800508: jal         0x80800804
    // 0x8080050C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800804_chbeanstalkseed(rdram, ctx);
        goto after_13;
    // 0x8080050C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_13:
    // 0x80800510: b           L_808007E4
    // 0x80800514: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808007E4;
    // 0x80800514: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800518:
    // 0x80800518: lwc1        $f22, 0xBAC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XBAC));
    // 0x8080051C: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80800520: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800524: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800528: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8080052C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80800530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800534: lwc1        $f12, 0x58($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X58);
L_80800538:
    // 0x80800538: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8080053C: addiu       $s0, $v0, 0x1
    ctx->r16 = ADD32(ctx->r2, 0X1);
    // 0x80800540: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800544: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80800548: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8080054C: nop

    // 0x80800550: bc1fl       L_80800564
    if (!c1cs) {
        // 0x80800554: mtc1        $s0, $f16
        ctx->f16.u32l = ctx->r16;
            goto L_80800564;
    }
    goto skip_1;
    // 0x80800554: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    skip_1:
    // 0x80800558: b           L_808005C4
    // 0x8080055C: addiu       $s0, $v0, 0x1
    ctx->r16 = ADD32(ctx->r2, 0X1);
        goto L_808005C4;
    // 0x8080055C: addiu       $s0, $v0, 0x1
    ctx->r16 = ADD32(ctx->r2, 0X1);
    // 0x80800560: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
L_80800564:
    // 0x80800564: nop

    // 0x80800568: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080056C: mul.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x80800570: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80800574: nop

    // 0x80800578: bc1f        L_80800588
    if (!c1cs) {
        // 0x8080057C: nop
    
            goto L_80800588;
    }
    // 0x8080057C: nop

    // 0x80800580: b           L_808005C4
    // 0x80800584: add.s       $f22, $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
        goto L_808005C4;
    // 0x80800584: add.s       $f22, $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
L_80800588:
    // 0x80800588: jal         0x800F13C4
    // 0x8080058C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800F13C4(rdram, ctx);
        goto after_14;
    // 0x8080058C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_14:
    // 0x80800590: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800594: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800598: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8080059C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x808005A0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808005A4: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x808005A8: jal         0x800F10B4
    // 0x808005AC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_15;
    // 0x808005AC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x808005B0: jal         0x80013970
    // 0x808005B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013970(rdram, ctx);
        goto after_16;
    // 0x808005B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_16:
    // 0x808005B8: mul.s       $f8, $f0, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x808005BC: lwc1        $f12, 0x58($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X58);
    // 0x808005C0: add.s       $f22, $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f8.fl;
L_808005C4:
    // 0x808005C4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808005C8: bne         $s0, $at, L_80800538
    if (ctx->r16 != ctx->r1) {
        // 0x808005CC: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80800538;
    }
    // 0x808005CC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808005D0: lwc1        $f10, 0x54($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X54);
    // 0x808005D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005DC: swc1        $f22, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f22.u32l;
    // 0x808005E0: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x808005E4: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x808005E8: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x808005EC: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x808005F0: jal         0x800F10B4
    // 0x808005F4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_17;
    // 0x808005F4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_17:
    // 0x808005F8: mul.s       $f18, $f0, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x808005FC: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80800600: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x80800604: jal         0x800F13C4
    // 0x80800608: swc1        $f18, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f18.u32l;
    func_800F13C4(rdram, ctx);
        goto after_18;
    // 0x80800608: swc1        $f18, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f18.u32l;
    after_18:
    // 0x8080060C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800610: lwc1        $f12, 0x54($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X54);
    // 0x80800614: jal         0x800F13C4
    // 0x80800618: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800F13C4(rdram, ctx);
        goto after_19;
    // 0x80800618: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_19:
    // 0x8080061C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80800620: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2356, 0XBB0) << 16);
    // 0x80800624: bc1fl       L_808007E4
    if (!c1cs) {
        // 0x80800628: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808007E4;
    }
    goto skip_2;
    // 0x80800628: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x8080062C: lwc1        $f12, 0x58($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X58);
    // 0x80800630: lwc1        $f4, 0xBB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XBB0));
    // 0x80800634: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800638: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x8080063C: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80800640: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80800644: bc1fl       L_808007E4
    if (!c1cs) {
        // 0x80800648: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808007E4;
    }
    goto skip_3;
    // 0x80800648: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x8080064C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800650: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80800654: jal         0x800F10B4
    // 0x80800658: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_20;
    // 0x80800658: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_20:
    // 0x8080065C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2356, 0XBB4) << 16);
    // 0x80800660: lwc1        $f8, 0xBB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2356, 0XBB4));
    // 0x80800664: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800668: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080066C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800670: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800674: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80800678: nop

    // 0x8080067C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800680: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80800684: nop

    // 0x80800688: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8080068C: beql        $a0, $zero, L_808006DC
    if (ctx->r4 == 0) {
        // 0x80800690: mfc1        $a0, $f16
        ctx->r4 = (int32_t)ctx->f16.u32l;
            goto L_808006DC;
    }
    goto skip_4;
    // 0x80800690: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    skip_4:
    // 0x80800694: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800698: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080069C: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808006A0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808006A4: nop

    // 0x808006A8: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x808006AC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808006B0: nop

    // 0x808006B4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808006B8: bne         $a0, $zero, L_808006D0
    if (ctx->r4 != 0) {
        // 0x808006BC: nop
    
            goto L_808006D0;
    }
    // 0x808006BC: nop

    // 0x808006C0: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x808006C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808006C8: b           L_808006E8
    // 0x808006CC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_808006E8;
    // 0x808006CC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_808006D0:
    // 0x808006D0: b           L_808006E8
    // 0x808006D4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_808006E8;
    // 0x808006D4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808006D8: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
L_808006DC:
    // 0x808006DC: nop

    // 0x808006E0: bltz        $a0, L_808006D0
    if (SIGNED(ctx->r4) < 0) {
        // 0x808006E4: nop
    
            goto L_808006D0;
    }
    // 0x808006E4: nop

L_808006E8:
    // 0x808006E8: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x808006EC: lui         $at, 0x1B
    ctx->r1 = S32(0X1B << 16);
    // 0x808006F0: ori         $at, $at, 0x5C1D
    ctx->r1 = ctx->r1 | 0X5C1D;
    // 0x808006F4: sll         $t1, $t0, 21
    ctx->r9 = S32(ctx->r8 << 21);
    // 0x808006F8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x808006FC: jal         0x800C3F48
    // 0x80800700: addu        $a0, $t1, $at
    ctx->r4 = ADD32(ctx->r9, ctx->r1);
    func_800C3F48(rdram, ctx);
        goto after_21;
    // 0x80800700: addu        $a0, $t1, $at
    ctx->r4 = ADD32(ctx->r9, ctx->r1);
    after_21:
    // 0x80800704: b           L_808007E4
    // 0x80800708: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808007E4;
    // 0x80800708: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8080070C:
    // 0x8080070C: jal         0x8010D254
    // 0x80800710: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    func_8010D254(rdram, ctx);
        goto after_22;
    // 0x80800710: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_22:
    // 0x80800714: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800718: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080071C: lwc1        $f18, 0x38($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800720: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80800724: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800728: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8080072C: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80800730: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800734: jal         0x800F0064
    // 0x80800738: nop

    func_800F0064(rdram, ctx);
        goto after_23;
    // 0x80800738: nop

    after_23:
    // 0x8080073C: beq         $v0, $zero, L_808007D4
    if (ctx->r2 == 0) {
        // 0x80800740: lwc1        $f10, 0x60($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
            goto L_808007D4;
    }
    // 0x80800740: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800744: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80800748: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8080074C: nop

    // 0x80800750: bc1fl       L_808007D8
    if (!c1cs) {
        // 0x80800754: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808007D8;
    }
    goto skip_5;
    // 0x80800754: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_5:
    // 0x80800758: lwc1        $f16, 0x2C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8080075C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800760: c.le.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl <= ctx->f16.fl;
    // 0x80800764: nop

    // 0x80800768: bc1fl       L_808007D8
    if (!c1cs) {
        // 0x8080076C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808007D8;
    }
    goto skip_6;
    // 0x8080076C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_6:
    // 0x80800770: jal         0x8008A4B0
    // 0x80800774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_24;
    // 0x80800774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80800778: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x8080077C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800780: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80800784: lw          $a2, 0x2C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2C);
    // 0x80800788: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8080078C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80800790: jal         0x800F10B4
    // 0x80800794: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_25;
    // 0x80800794: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_25:
    // 0x80800798: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x8080079C: mul.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808007A0: jal         0x800F54E4
    // 0x808007A4: nop

    func_800F54E4(rdram, ctx);
        goto after_26;
    // 0x808007A4: nop

    after_26:
    // 0x808007A8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808007AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808007B0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808007B4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808007B8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808007BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808007C4: jal         0x800F7F50
    // 0x808007C8: addiu       $a2, $s1, 0x28
    ctx->r6 = ADD32(ctx->r17, 0X28);
    func_800F7F50(rdram, ctx);
        goto after_27;
    // 0x808007C8: addiu       $a2, $s1, 0x28
    ctx->r6 = ADD32(ctx->r17, 0X28);
    after_27:
    // 0x808007CC: b           L_808007E4
    // 0x808007D0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808007E4;
    // 0x808007D0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808007D4:
    // 0x808007D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808007D8:
    // 0x808007D8: jal         0x8008A4B0
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_28;
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
L_808007E0:
    // 0x808007E0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808007E4:
    // 0x808007E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808007E8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808007EC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808007F0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808007F4: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x808007F8: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x808007FC: jr          $ra
    // 0x80800800: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80800800: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void _bskazjump_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083450: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083450);
    return;
    // 0x80083454: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bsledge_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808012F4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(304, 0X13A8) << 16);
    // 0x808012F8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808012FC: jr          $ra
    // 0x80801300: lw          $v0, 0x13A8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(304, 0X13A8));
    return;
    // 0x80801300: lw          $v0, 0x13A8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(304, 0X13A8));
;}
RECOMP_FUNC void _bsbwhirl_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D98: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082D98);
    return;
    // 0x80082D9C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void sumissilehome_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800248: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080024C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800250: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800254: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80800258: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080025C: addiu       $a0, $a1, 0xC
    ctx->r4 = ADD32(ctx->r5, 0XC);
    // 0x80800260: beql        $t6, $zero, L_808002A4
    if (ctx->r14 == 0) {
        // 0x80800264: lbu         $t7, 0x9($a3)
        ctx->r15 = MEM_BU(ctx->r7, 0X9);
            goto L_808002A4;
    }
    goto skip_0;
    // 0x80800264: lbu         $t7, 0x9($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X9);
    skip_0:
    // 0x80800268: jal         0x8008A040
    // 0x8080026C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080026C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800270: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80800274: bne         $v0, $zero, L_80800284
    if (ctx->r2 != 0) {
        // 0x80800278: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800284;
    }
    // 0x80800278: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080027C: b           L_8080030C
    // 0x80800280: sb          $zero, 0x8($a3)
    MEM_B(0X8, ctx->r7) = 0;
        goto L_8080030C;
    // 0x80800280: sb          $zero, 0x8($a3)
    MEM_B(0X8, ctx->r7) = 0;
L_80800284:
    // 0x80800284: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800288: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8080028C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800290: jal         0x8010A2FC
    // 0x80800294: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_8010A2FC(rdram, ctx);
        goto after_1;
    // 0x80800294: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_1:
    // 0x80800298: b           L_808002DC
    // 0x8080029C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
        goto L_808002DC;
    // 0x8080029C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808002A0: lbu         $t7, 0x9($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X9);
L_808002A4:
    // 0x808002A4: beql        $t7, $zero, L_80800310
    if (ctx->r15 == 0) {
        // 0x808002A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800310;
    }
    goto skip_1;
    // 0x808002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808002AC: lb          $a0, 0x1($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X1);
    // 0x808002B0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808002B4: bltzl       $a0, L_80800310
    if (SIGNED(ctx->r4) < 0) {
        // 0x808002B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800310;
    }
    goto skip_2;
    // 0x808002B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x808002BC: jal         0x800F5A00
    // 0x808002C0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x808002C0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_2:
    // 0x808002C4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808002C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002CC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808002D0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808002D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808002D8: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
L_808002DC:
    // 0x808002DC: lbu         $t8, 0xA($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XA);
    // 0x808002E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002E4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808002E8: bne         $t8, $at, L_80800304
    if (ctx->r24 != ctx->r1) {
        // 0x808002EC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800304;
    }
    // 0x808002EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808002F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808002F4: jal         0x808001C8
    // 0x808002F8: lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4);
    func_808001C8_sumissilehome(rdram, ctx);
        goto after_3;
    // 0x808002F8: lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4);
    after_3:
    // 0x808002FC: b           L_80800310
    // 0x80800300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800310;
    // 0x80800300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800304:
    // 0x80800304: jal         0x80800178
    // 0x80800308: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80800178_sumissilehome(rdram, ctx);
        goto after_4;
    // 0x80800308: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
L_8080030C:
    // 0x8080030C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800310:
    // 0x80800310: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800314: jr          $ra
    // 0x80800318: nop

    return;
    // 0x80800318: nop

    // 0x8080031C: nop

;}
RECOMP_FUNC void func_8080052C_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080052C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800530: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800534: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800538: lb          $t6, 0x158($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X158);
    // 0x8080053C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800540: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800544: bltzl       $t6, L_8080063C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800548: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8080063C;
    }
    goto skip_0;
    // 0x80800548: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8080054C: jal         0x80088718
    // 0x80800550: addiu       $a1, $zero, 0x1865
    ctx->r5 = ADD32(0, 0X1865);
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800550: addiu       $a1, $zero, 0x1865
    ctx->r5 = ADD32(0, 0X1865);
    after_0:
    // 0x80800554: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800558: jal         0x80088720
    // 0x8080055C: lb          $a1, 0x158($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X158);
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080055C: lb          $a1, 0x158($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X158);
    after_1:
    // 0x80800560: addiu       $a0, $s0, 0x130
    ctx->r4 = ADD32(ctx->r16, 0X130);
    // 0x80800564: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800568: jal         0x800E715C
    // 0x8080056C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E715C(rdram, ctx);
        goto after_2;
    // 0x8080056C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800570: jal         0x80088728
    // 0x80800574: addiu       $a0, $zero, 0x1865
    ctx->r4 = ADD32(0, 0X1865);
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800574: addiu       $a0, $zero, 0x1865
    ctx->r4 = ADD32(0, 0X1865);
    after_3:
    // 0x80800578: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8080057C: addiu       $t7, $t7, 0x890
    ctx->r15 = ADD32(ctx->r15, 0X890);
    // 0x80800580: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800584: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    // 0x80800588: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x8080058C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800590: jal         0x80087B08
    // 0x80800594: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _gczoombox_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800594: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80800598: lb          $t8, 0x158($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X158);
    // 0x8080059C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2594, 0X2EA0) << 16);
    // 0x808005A0: sw          $v0, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r2;
    // 0x808005A4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808005A8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808005AC: lwc1        $f0, 0x2EA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2594, 0X2EA0));
    // 0x808005B0: lui         $at, 0x4398
    ctx->r1 = S32(0X4398 << 16);
    // 0x808005B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005B8: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x808005BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808005C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005C8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808005CC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808005D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808005D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808005DC: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x808005E0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808005E4: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808005E8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808005EC: jal         0x80087BB0
    // 0x808005F0: nop

    _gczoombox_entrypoint_26(rdram, ctx);
        goto after_5;
    // 0x808005F0: nop

    after_5:
    // 0x808005F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2594, 0X2E10) << 16);
    // 0x808005F8: lwc1        $f4, 0x2E10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2594, 0X2E10));
    // 0x808005FC: lw          $a0, 0x12C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X12C);
    // 0x80800600: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80800604: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800608: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x8080060C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800610: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80800614: jal         0x80087B80
    // 0x80800618: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _gczoombox_entrypoint_20(rdram, ctx);
        goto after_6;
    // 0x80800618: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x8080061C: lw          $a0, 0x12C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X12C);
    // 0x80800620: jal         0x80087B20
    // 0x80800624: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _gczoombox_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x80800624: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x80800628: jal         0x80087B28
    // 0x8080062C: lw          $a0, 0x12C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X12C);
    _gczoombox_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x8080062C: lw          $a0, 0x12C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X12C);
    after_8:
    // 0x80800630: jal         0x80087B38
    // 0x80800634: lw          $a0, 0x12C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X12C);
    _gczoombox_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80800634: lw          $a0, 0x12C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X12C);
    after_9:
    // 0x80800638: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080063C:
    // 0x8080063C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800640: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800644: jr          $ra
    // 0x80800648: nop

    return;
    // 0x80800648: nop

;}
RECOMP_FUNC void func_80090E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090E30: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80090E34: jr          $ra
    // 0x80090E38: lbu         $v0, 0x1A($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1A);
    return;
    // 0x80090E38: lbu         $v0, 0x1A($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1A);
;}
RECOMP_FUNC void _gctransitionDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800881C8: syscall     674
    recomp_syscall_handler(rdram, ctx, 0x800881C8);
    return;
    // 0x800881CC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808003C4_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003CC: beq         $a2, $zero, L_808003E8
    if (ctx->r6 == 0) {
        // 0x808003D0: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_808003E8;
    }
    // 0x808003D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808003D4: jal         0x80800024
    // 0x808003D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80800024_bstrexlarge(rdram, ctx);
        goto after_0;
    // 0x808003D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808003DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808003E0: b           L_808003F0
    // 0x808003E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_808003F0;
    // 0x808003E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_808003E8:
    // 0x808003E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808003EC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_808003F0:
    // 0x808003F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003F4: jal         0x8009EF10
    // 0x808003F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x808003F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x808003FC: beq         $v0, $zero, L_8080042C
    if (ctx->r2 == 0) {
        // 0x80800400: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8080042C;
    }
    // 0x80800400: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800404: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800408: beq         $v0, $at, L_80800420
    if (ctx->r2 == ctx->r1) {
        // 0x8080040C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800420;
    }
    // 0x8080040C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800410: beql        $v0, $at, L_8080042C
    if (ctx->r2 == ctx->r1) {
        // 0x80800414: addiu       $a1, $zero, 0x150
        ctx->r5 = ADD32(0, 0X150);
            goto L_8080042C;
    }
    goto skip_0;
    // 0x80800414: addiu       $a1, $zero, 0x150
    ctx->r5 = ADD32(0, 0X150);
    skip_0:
    // 0x80800418: b           L_80800430
    // 0x8080041C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_80800430;
    // 0x8080041C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800420:
    // 0x80800420: b           L_8080042C
    // 0x80800424: addiu       $a1, $zero, 0x152
    ctx->r5 = ADD32(0, 0X152);
        goto L_8080042C;
    // 0x80800424: addiu       $a1, $zero, 0x152
    ctx->r5 = ADD32(0, 0X152);
    // 0x80800428: addiu       $a1, $zero, 0x150
    ctx->r5 = ADD32(0, 0X150);
L_8080042C:
    // 0x8080042C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800430:
    // 0x80800430: jal         0x80097AD0
    // 0x80800434: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_2;
    // 0x80800434: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800438: beq         $v0, $zero, L_8080044C
    if (ctx->r2 == 0) {
        // 0x8080043C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8080044C;
    }
    // 0x8080043C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800440: jal         0x800848A8
    // 0x80800444: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _badrone_entrypoint_24(rdram, ctx);
        goto after_3;
    // 0x80800444: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800448: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8080044C:
    // 0x8080044C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800450: jal         0x80800140
    // 0x80800454: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80800140_bstrexlarge(rdram, ctx);
        goto after_4;
    // 0x80800454: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x80800458: beq         $v0, $zero, L_80800464
    if (ctx->r2 == 0) {
        // 0x8080045C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80800464;
    }
    // 0x8080045C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800460: addiu       $a1, $zero, 0x14F
    ctx->r5 = ADD32(0, 0X14F);
L_80800464:
    // 0x80800464: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800468: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080046C: beql        $t7, $zero, L_8080048C
    if (ctx->r15 == 0) {
        // 0x80800470: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080048C;
    }
    goto skip_1;
    // 0x80800470: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80800474: jal         0x8008DD04
    // 0x80800478: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8008DD04(rdram, ctx);
        goto after_5;
    // 0x80800478: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_5:
    // 0x8080047C: beq         $v0, $zero, L_80800488
    if (ctx->r2 == 0) {
        // 0x80800480: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80800488;
    }
    // 0x80800480: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800484: addiu       $a1, $zero, 0x14A
    ctx->r5 = ADD32(0, 0X14A);
L_80800488:
    // 0x80800488: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8080048C:
    // 0x8080048C: jal         0x80800160
    // 0x80800490: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80800160_bstrexlarge(rdram, ctx);
        goto after_6;
    // 0x80800490: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_6:
    // 0x80800494: beq         $v0, $zero, L_808004A0
    if (ctx->r2 == 0) {
        // 0x80800498: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_808004A0;
    }
    // 0x80800498: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080049C: addiu       $a1, $zero, 0x14B
    ctx->r5 = ADD32(0, 0X14B);
L_808004A0:
    // 0x808004A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004A8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x808004AC: jr          $ra
    // 0x808004B0: nop

    return;
    // 0x808004B0: nop

;}
RECOMP_FUNC void func_8080182C_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080182C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801830: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801834: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80801838: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080183C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801840: bne         $a1, $at, L_80801A40
    if (ctx->r5 != ctx->r1) {
        // 0x80801844: sw          $a2, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r6;
            goto L_80801A40;
    }
    // 0x80801844: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80801848: jal         0x8080106C
    // 0x8080184C: nop

    func_8080106C_chpiranha(rdram, ctx);
        goto after_0;
    // 0x8080184C: nop

    after_0:
    // 0x80801850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801854: jal         0x80100094
    // 0x80801858: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801858: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080185C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801860: jal         0x808016D0
    // 0x80801864: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_808016D0_chpiranha(rdram, ctx);
        goto after_2;
    // 0x80801864: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x80801868: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8080186C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801870: addiu       $a2, $v1, 0x4
    ctx->r6 = ADD32(ctx->r3, 0X4);
    // 0x80801874: swc1        $f4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f4.u32l;
    // 0x80801878: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
    // 0x8080187C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801880: beq         $t6, $zero, L_80801894
    if (ctx->r14 == 0) {
        // 0x80801884: addiu       $t7, $s0, 0x4
        ctx->r15 = ADD32(ctx->r16, 0X4);
            goto L_80801894;
    }
    // 0x80801884: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x80801888: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8080188C: b           L_8080189C
    // 0x80801890: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
        goto L_8080189C;
    // 0x80801890: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
L_80801894:
    // 0x80801894: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801898: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
L_8080189C:
    // 0x8080189C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x808018A0: jal         0x800EE7F8
    // 0x808018A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808018A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x808018A8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x808018AC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808018B0: addiu       $at, $zero, 0x2C1
    ctx->r1 = ADD32(0, 0X2C1);
    // 0x808018B4: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x808018B8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808018BC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808018C0: srl         $t0, $t9, 22
    ctx->r8 = S32(U32(ctx->r25) >> 22);
    // 0x808018C4: bne         $t0, $at, L_808018E0
    if (ctx->r8 != ctx->r1) {
        // 0x808018C8: lui         $at, 0x437A
        ctx->r1 = S32(0X437A << 16);
            goto L_808018E0;
    }
    // 0x808018C8: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808018CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808018D0: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808018D4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808018D8: b           L_808018F4
    // 0x808018DC: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
        goto L_808018F4;
    // 0x808018DC: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
L_808018E0:
    // 0x808018E0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808018E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808018E8: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808018EC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808018F0: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
L_808018F4:
    // 0x808018F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808018F8: jal         0x800EE7F8
    // 0x808018FC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808018FC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_4:
    // 0x80801900: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80801904: jal         0x800EE7F8
    // 0x80801908: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80801908: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x8080190C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80801910: jal         0x800EE7F8
    // 0x80801914: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80801914: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80801918: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080191C: jal         0x800EE7F8
    // 0x80801920: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80801920: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80801924: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80801928: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080192C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80801930: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801934: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801938: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080193C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801940: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80801944: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80801948: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8080194C: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80801950: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80801954: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80801958: jal         0x800BEF00
    // 0x8080195C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_8;
    // 0x8080195C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_8:
    // 0x80801960: beq         $v0, $zero, L_80801970
    if (ctx->r2 == 0) {
        // 0x80801964: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_80801970;
    }
    // 0x80801964: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80801968: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080196C: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
L_80801970:
    // 0x80801970: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80801974: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80801978: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x8080197C: beql        $v0, $zero, L_80801998
    if (ctx->r2 == 0) {
        // 0x80801980: sw          $zero, 0x18($v1)
        MEM_W(0X18, ctx->r3) = 0;
            goto L_80801998;
    }
    goto skip_0;
    // 0x80801980: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    skip_0:
    // 0x80801984: lhu         $t1, 0x12($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X12);
    // 0x80801988: srl         $t2, $t1, 1
    ctx->r10 = S32(U32(ctx->r9) >> 1);
    // 0x8080198C: b           L_80801998
    // 0x80801990: sw          $t2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r10;
        goto L_80801998;
    // 0x80801990: sw          $t2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r10;
    // 0x80801994: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
L_80801998:
    // 0x80801998: sb          $t3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r11;
    // 0x8080199C: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x808019A0: beql        $v0, $zero, L_808019B8
    if (ctx->r2 == 0) {
        // 0x808019A4: lw          $t4, 0x0($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X0);
            goto L_808019B8;
    }
    goto skip_1;
    // 0x808019A4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x808019A8: jal         0x800DA3B8
    // 0x808019AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_9;
    // 0x808019AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808019B0: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x808019B4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
L_808019B8:
    // 0x808019B8: addiu       $at, $zero, 0x2C1
    ctx->r1 = ADD32(0, 0X2C1);
    // 0x808019BC: lw          $t5, 0x24($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X24);
    // 0x808019C0: srl         $t6, $t5, 22
    ctx->r14 = S32(U32(ctx->r13) >> 22);
    // 0x808019C4: bne         $t6, $at, L_808019EC
    if (ctx->r14 != ctx->r1) {
        // 0x808019C8: nop
    
            goto L_808019EC;
    }
    // 0x808019C8: nop

    // 0x808019CC: beq         $v0, $zero, L_808019DC
    if (ctx->r2 == 0) {
        // 0x808019D0: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_808019DC;
    }
    // 0x808019D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808019D4: b           L_808019DC
    // 0x808019D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_808019DC;
    // 0x808019D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808019DC:
    // 0x808019DC: jal         0x80800218
    // 0x808019E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800218_chpiranha(rdram, ctx);
        goto after_10;
    // 0x808019E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808019E4: b           L_80801A08
    // 0x808019E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
        goto L_80801A08;
    // 0x808019E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_808019EC:
    // 0x808019EC: beq         $v0, $zero, L_808019FC
    if (ctx->r2 == 0) {
        // 0x808019F0: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_808019FC;
    }
    // 0x808019F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808019F4: b           L_808019FC
    // 0x808019F8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
        goto L_808019FC;
    // 0x808019F8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_808019FC:
    // 0x808019FC: jal         0x80800218
    // 0x80801A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800218_chpiranha(rdram, ctx);
        goto after_11;
    // 0x80801A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801A04: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80801A08:
    // 0x80801A08: jal         0x800DB9B0
    // 0x80801A0C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    func_800DB9B0(rdram, ctx);
        goto after_12;
    // 0x80801A0C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_12:
    // 0x80801A10: addiu       $a0, $zero, 0x650
    ctx->r4 = ADD32(0, 0X650);
    // 0x80801A14: jal         0x800DA298
    // 0x80801A18: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x80801A18: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_13:
    // 0x80801A1C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801A20: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80801A24: or          $t8, $v0, $a1
    ctx->r24 = ctx->r2 | ctx->r5;
    // 0x80801A28: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80801A2C: andi        $t0, $t9, 0x10
    ctx->r8 = ctx->r25 & 0X10;
    // 0x80801A30: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x80801A34: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80801A38: b           L_80801A48
    // 0x80801A3C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
        goto L_80801A48;
    // 0x80801A3C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80801A40:
    // 0x80801A40: b           L_80801A4C
    // 0x80801A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801A4C;
    // 0x80801A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801A48:
    // 0x80801A48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801A4C:
    // 0x80801A4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801A54: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80801A58: jr          $ra
    // 0x80801A5C: nop

    return;
    // 0x80801A5C: nop

;}
RECOMP_FUNC void func_800F4524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4524: jr          $ra
    // 0x800F4528: sw          $a1, 0x180($a0)
    MEM_W(0X180, ctx->r4) = ctx->r5;
    return;
    // 0x800F4528: sw          $a1, 0x180($a0)
    MEM_W(0X180, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_800BA660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA660: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800BA664: sw          $a1, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r5;
    // 0x800BA668: jr          $ra
    // 0x800BA66C: sh          $a2, 0x98($a0)
    MEM_H(0X98, ctx->r4) = ctx->r6;
    return;
    // 0x800BA66C: sh          $a2, 0x98($a0)
    MEM_H(0X98, ctx->r4) = ctx->r6;
;}
RECOMP_FUNC void func_80806C08_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806C08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80806C0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80806C10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80806C14: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80806C18: jal         0x80100094
    // 0x80806C1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806C1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806C20: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80806C24: jal         0x80802248
    // 0x80806C28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80806C28: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80806C2C: lbu         $t6, 0x4($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X4);
    // 0x80806C30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80806C34: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x80806C38: beq         $t6, $zero, L_80806C54
    if (ctx->r14 == 0) {
        // 0x80806C3C: addiu       $a1, $zero, 0x63
        ctx->r5 = ADD32(0, 0X63);
            goto L_80806C54;
    }
    // 0x80806C3C: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    // 0x80806C40: sb          $t7, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r15;
    // 0x80806C44: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9BF4) << 16);
    // 0x80806C48: lwc1        $f4, -0x640C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9BF4));
    // 0x80806C4C: b           L_80806C90
    // 0x80806C50: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
        goto L_80806C90;
    // 0x80806C50: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
L_80806C54:
    // 0x80806C54: jal         0x800F7B9C
    // 0x80806C58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F7B9C(rdram, ctx);
        goto after_2;
    // 0x80806C58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x80806C5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806C60: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    // 0x80806C64: jal         0x800F7C58
    // 0x80806C68: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800F7C58(rdram, ctx);
        goto after_3;
    // 0x80806C68: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x80806C6C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80806C70: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80806C74: jal         0x80802878
    // 0x80806C78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80806C78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80806C7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80806C80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80806C84: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x80806C88: sb          $t8, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r24;
    // 0x80806C8C: swc1        $f6, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f6.u32l;
L_80806C90:
    // 0x80806C90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80806C94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80806C98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80806C9C: jr          $ra
    // 0x80806CA0: nop

    return;
    // 0x80806CA0: nop

;}
RECOMP_FUNC void func_80800594_chskeletonexplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800594: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800598: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080059C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808005A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005A4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808005A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005AC: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x808005B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005B4: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x808005B8: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x808005BC: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    // 0x808005C0: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
    // 0x808005C4: jr          $ra
    // 0x808005C8: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x808005C8: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_800B3B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3B08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B3B0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B3B10: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B3B14: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B3B18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B3B1C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800B3B20: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800B3B24: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x800B3B28: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800B3B2C: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x800B3B30: beq         $t6, $zero, L_800B3B60
    if (ctx->r14 == 0) {
        // 0x800B3B34: addu        $s1, $a1, $a2
        ctx->r17 = ADD32(ctx->r5, ctx->r6);
            goto L_800B3B60;
    }
    // 0x800B3B34: addu        $s1, $a1, $a2
    ctx->r17 = ADD32(ctx->r5, ctx->r6);
    // 0x800B3B38: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
L_800B3B3C:
    // 0x800B3B3C: slt         $at, $a1, $s1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800B3B40: beql        $at, $zero, L_800B3B64
    if (ctx->r1 == 0) {
        // 0x800B3B44: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B3B64;
    }
    goto skip_0;
    // 0x800B3B44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x800B3B48: jal         0x800B39D0
    // 0x800B3B4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800B39D0(rdram, ctx);
        goto after_0;
    // 0x800B3B4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x800B3B50: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800B3B54: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3B58: bnel        $t9, $zero, L_800B3B3C
    if (ctx->r25 != 0) {
        // 0x800B3B5C: lh          $a1, 0x0($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X0);
            goto L_800B3B3C;
    }
    goto skip_1;
    // 0x800B3B5C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    skip_1:
L_800B3B60:
    // 0x800B3B60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800B3B64:
    // 0x800B3B64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B3B68: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3B6C: jal         0x800B3A40
    // 0x800B3B70: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_800B3A40(rdram, ctx);
        goto after_1;
    // 0x800B3B70: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800B3B74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B3B78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B3B7C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3B80: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B3B84: jr          $ra
    // 0x800B3B88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B3B88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void chbanjocurrent_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(756, 0X818) << 16);
    // 0x8080050C: jr          $ra
    // 0x80800510: addiu       $v0, $v0, 0x818
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(756, 0X818));
    return;
    // 0x80800510: addiu       $v0, $v0, 0x818
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(756, 0X818));
;}
RECOMP_FUNC void func_80801110_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801110: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801114: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801118: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080111C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801120: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801124: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80801128: jal         0x80100094
    // 0x8080112C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080112C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801130: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801134: addiu       $at, $zero, 0x1287
    ctx->r1 = ADD32(0, 0X1287);
    // 0x80801138: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080113C: beq         $a1, $at, L_80801158
    if (ctx->r5 == ctx->r1) {
        // 0x80801140: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801158;
    }
    // 0x80801140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801144: addiu       $at, $zero, 0x12AA
    ctx->r1 = ADD32(0, 0X12AA);
    // 0x80801148: beq         $a1, $at, L_808011A0
    if (ctx->r5 == ctx->r1) {
        // 0x8080114C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808011A0;
    }
    // 0x8080114C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801150: b           L_808011EC
    // 0x80801154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808011EC;
    // 0x80801154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801158:
    // 0x80801158: jal         0x80102424
    // 0x8080115C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080115C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_1:
    // 0x80801160: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801164: addiu       $t6, $zero, 0x62
    ctx->r14 = ADD32(0, 0X62);
    // 0x80801168: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080116C: addiu       $a1, $zero, 0x12B4
    ctx->r5 = ADD32(0, 0X12B4);
    // 0x80801170: addiu       $a2, $zero, 0x144
    ctx->r6 = ADD32(0, 0X144);
    // 0x80801174: jal         0x8008A208
    // 0x80801178: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80801178: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x8080117C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801180: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x80801184: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80801188: jal         0x80801D40
    // 0x8080118C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80801D40_chaliendad(rdram, ctx);
        goto after_3;
    // 0x8080118C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80801190: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80801194: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801198: b           L_8080120C
    // 0x8080119C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_8080120C;
    // 0x8080119C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808011A0:
    // 0x808011A0: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    // 0x808011A4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x808011A8: jal         0x80801D40
    // 0x808011AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80801D40_chaliendad(rdram, ctx);
        goto after_4;
    // 0x808011AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x808011B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011B4: jal         0x80102424
    // 0x808011B8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x808011B8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_5:
    // 0x808011BC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1364, 0X25D8) << 16);
    // 0x808011C0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1364, 0X25E4) << 16);
    // 0x808011C4: addiu       $a0, $a0, 0x25E4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1364, 0X25E4));
    // 0x808011C8: addiu       $v0, $v0, 0x25D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1364, 0X25D8));
    // 0x808011CC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_808011D0:
    // 0x808011D0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808011D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808011D8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808011DC: bne         $v0, $a0, L_808011D0
    if (ctx->r2 != ctx->r4) {
        // 0x808011E0: swc1        $f6, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
            goto L_808011D0;
    }
    // 0x808011E0: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x808011E4: b           L_80801210
    // 0x808011E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801210;
    // 0x808011E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808011EC:
    // 0x808011EC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1364, 0X25C0) << 16);
    // 0x808011F0: addiu       $a2, $a2, 0x25C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1364, 0X25C0));
    // 0x808011F4: jal         0x8008A1F8
    // 0x808011F8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x808011F8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x808011FC: beq         $v0, $zero, L_8080120C
    if (ctx->r2 == 0) {
        // 0x80801200: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080120C;
    }
    // 0x80801200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801204: jal         0x80102424
    // 0x80801208: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80801208: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_7:
L_8080120C:
    // 0x8080120C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801210:
    // 0x80801210: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801214: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801218: jr          $ra
    // 0x8080121C: nop

    return;
    // 0x8080121C: nop

;}
RECOMP_FUNC void func_80803420_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803420: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803424: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80803428: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8080342C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803430: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80803434: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80803438: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080343C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80803440: jal         0x80100094
    // 0x80803444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80803448: lw          $t6, 0x2C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X2C);
    // 0x8080344C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80803450: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80803454: blez        $t6, L_80803494
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80803458: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803494;
    }
    // 0x80803458: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8080345C:
    // 0x8080345C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803460: jal         0x80087CF8
    // 0x80803464: lbu         $a2, 0x1($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X1);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80803464: lbu         $a2, 0x1($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X1);
    after_1:
    // 0x80803468: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080346C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803470: lb          $a2, 0x3($s1)
    ctx->r6 = MEM_B(ctx->r17, 0X3);
    // 0x80803474: jal         0x80803604
    // 0x80803478: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80803604_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80803478: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8080347C: lw          $t7, 0x2C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X2C);
    // 0x80803480: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80803484: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x80803488: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8080348C: bnel        $at, $zero, L_8080345C
    if (ctx->r1 != 0) {
        // 0x80803490: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080345C;
    }
    goto skip_0;
    // 0x80803490: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_80803494:
    // 0x80803494: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803498: jal         0x80087DE0
    // 0x8080349C: lw          $a1, 0x30($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X30);
    _gcnewoption_entrypoint_41(rdram, ctx);
        goto after_3;
    // 0x8080349C: lw          $a1, 0x30($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X30);
    after_3:
    // 0x808034A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808034A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808034A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808034AC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808034B0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808034B4: jr          $ra
    // 0x808034B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808034B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80017EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017EC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80017EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017EC8: jal         0x80017810
    // 0x80017ECC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80017810(rdram, ctx);
        goto after_0;
    // 0x80017ECC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80017ED0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80017ED4: beq         $v0, $zero, L_80017FB0
    if (ctx->r2 == 0) {
        // 0x80017ED8: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80017FB0;
    }
    // 0x80017ED8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80017EDC: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80017EE0: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80017EE4: addiu       $t7, $t7, -0x5148
    ctx->r15 = ADD32(ctx->r15, -0X5148);
    // 0x80017EE8: beq         $t6, $zero, L_80017FB0
    if (ctx->r14 == 0) {
        // 0x80017EEC: sll         $a1, $a0, 2
        ctx->r5 = S32(ctx->r4 << 2);
            goto L_80017FB0;
    }
    // 0x80017EEC: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x80017EF0: addu        $a2, $a1, $t7
    ctx->r6 = ADD32(ctx->r5, ctx->r15);
    // 0x80017EF4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80017EF8: beql        $t8, $zero, L_80017FB4
    if (ctx->r24 == 0) {
        // 0x80017EFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80017FB4;
    }
    goto skip_0;
    // 0x80017EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80017F00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80017F04: jal         0x80017778
    // 0x80017F08: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80017778(rdram, ctx);
        goto after_1;
    // 0x80017F08: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80017F0C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80017F10: bne         $v0, $zero, L_80017FB0
    if (ctx->r2 != 0) {
        // 0x80017F14: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80017FB0;
    }
    // 0x80017F14: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80017F18: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80017F1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80017F20: jal         0x800260B0
    // 0x80017F24: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800260B0(rdram, ctx);
        goto after_2;
    // 0x80017F24: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80017F28: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80017F2C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80017F30: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80017F34: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80017F38: lw          $v1, -0x5160($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5160);
    // 0x80017F3C: bnel        $v0, $v1, L_80017F50
    if (ctx->r2 != ctx->r3) {
        // 0x80017F40: lw          $a1, 0x0($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X0);
            goto L_80017F50;
    }
    goto skip_1;
    // 0x80017F40: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x80017F44: b           L_80017FB0
    // 0x80017F48: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_80017FB0;
    // 0x80017F48: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80017F4C: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
L_80017F50:
    // 0x80017F50: addu        $a0, $a1, $v0
    ctx->r4 = ADD32(ctx->r5, ctx->r2);
    // 0x80017F54: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017F58: beq         $at, $zero, L_80017F78
    if (ctx->r1 == 0) {
        // 0x80017F5C: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80017F78;
    }
    // 0x80017F5C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80017F60: beq         $at, $zero, L_80017F70
    if (ctx->r1 == 0) {
        // 0x80017F64: nop
    
            goto L_80017F70;
    }
    // 0x80017F64: nop

    // 0x80017F68: b           L_80017FA8
    // 0x80017F6C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_80017FA8;
    // 0x80017F6C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_80017F70:
    // 0x80017F70: b           L_80017FA8
    // 0x80017F74: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
        goto L_80017FA8;
    // 0x80017F74: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_80017F78:
    // 0x80017F78: subu        $a0, $v0, $a1
    ctx->r4 = SUB32(ctx->r2, ctx->r5);
    // 0x80017F7C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80017F80: beq         $at, $zero, L_80017FA4
    if (ctx->r1 == 0) {
        // 0x80017F84: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80017FA4;
    }
    // 0x80017F84: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80017F88: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017F8C: beq         $at, $zero, L_80017F9C
    if (ctx->r1 == 0) {
        // 0x80017F90: nop
    
            goto L_80017F9C;
    }
    // 0x80017F90: nop

    // 0x80017F94: b           L_80017FA8
    // 0x80017F98: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_80017FA8;
    // 0x80017F98: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_80017F9C:
    // 0x80017F9C: b           L_80017FA8
    // 0x80017FA0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
        goto L_80017FA8;
    // 0x80017FA0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_80017FA4:
    // 0x80017FA4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80017FA8:
    // 0x80017FA8: jal         0x80026330
    // 0x80017FAC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80026330(rdram, ctx);
        goto after_3;
    // 0x80017FAC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
L_80017FB0:
    // 0x80017FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80017FB4:
    // 0x80017FB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80017FB8: jr          $ra
    // 0x80017FBC: nop

    return;
    // 0x80017FBC: nop

;}
RECOMP_FUNC void badata_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800ECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800ED0: jal         0x80800000
    // 0x80800ED4: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800ED4: nop

    after_0:
    // 0x80800ED8: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80800EDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EE0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X2258) << 16);
    // 0x80800EE4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800EE8: lh          $v0, 0x2258($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X2258));
    // 0x80800EEC: jr          $ra
    // 0x80800EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800A7584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7584: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7588: addiu       $v0, $v0, 0x7630
    ctx->r2 = ADD32(ctx->r2, 0X7630);
    // 0x800A758C: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x800A7590: sb          $t6, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = ctx->r14;
    // 0x800A7594: jr          $ra
    // 0x800A7598: sb          $a1, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r5;
    return;
    // 0x800A7598: sb          $a1, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void bsclaw_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800128: jal         0x8008CABC
    // 0x8080012C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080012C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800130: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800134: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80800138: jal         0x8008B2B4
    // 0x8080013C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_1;
    // 0x8080013C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800140: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800144: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800148: jal         0x80085300
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_2;
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800150: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800154: nop

    // 0x80800158: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8080015C: nop

    // 0x80800160: bc1tl       L_80800184
    if (c1cs) {
        // 0x80800164: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800184;
    }
    goto skip_0;
    // 0x80800164: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80800168: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080016C: jal         0x80091A58
    // 0x80800170: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_3;
    // 0x80800170: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x80800174: beq         $v0, $zero, L_80800180
    if (ctx->r2 == 0) {
        // 0x80800178: addiu       $t6, $zero, 0x189
        ctx->r14 = ADD32(0, 0X189);
            goto L_80800180;
    }
    // 0x80800178: addiu       $t6, $zero, 0x189
    ctx->r14 = ADD32(0, 0X189);
    // 0x8080017C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
L_80800180:
    // 0x80800180: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800184:
    // 0x80800184: jal         0x800852F0
    // 0x80800188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_4;
    // 0x80800188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8080018C: lui         $a1, 0x3F03
    ctx->r5 = S32(0X3F03 << 16);
    // 0x80800190: ori         $a1, $a1, 0x4D6A
    ctx->r5 = ctx->r5 | 0X4D6A;
    // 0x80800194: jal         0x8008B348
    // 0x80800198: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x80800198: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x8080019C: beql        $v0, $zero, L_808001C0
    if (ctx->r2 == 0) {
        // 0x808001A0: lui         $a1, 0x3F27
        ctx->r5 = S32(0X3F27 << 16);
            goto L_808001C0;
    }
    goto skip_1;
    // 0x808001A0: lui         $a1, 0x3F27
    ctx->r5 = S32(0X3F27 << 16);
    skip_1:
    // 0x808001A4: jal         0x8009C984
    // 0x808001A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    yaw_get(rdram, ctx);
        goto after_6;
    // 0x808001A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x808001AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001B4: jal         0x8009BA68
    // 0x808001B8: lui         $a2, 0x43B4
    ctx->r6 = S32(0X43B4 << 16);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x808001B8: lui         $a2, 0x43B4
    ctx->r6 = S32(0X43B4 << 16);
    after_7:
    // 0x808001BC: lui         $a1, 0x3F27
    ctx->r5 = S32(0X3F27 << 16);
L_808001C0:
    // 0x808001C0: ori         $a1, $a1, 0x65FE
    ctx->r5 = ctx->r5 | 0X65FE;
    // 0x808001C4: jal         0x8008B348
    // 0x808001C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_8;
    // 0x808001C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x808001CC: beql        $v0, $zero, L_808001E4
    if (ctx->r2 == 0) {
        // 0x808001D0: lui         $a1, 0x3E18
        ctx->r5 = S32(0X3E18 << 16);
            goto L_808001E4;
    }
    goto skip_2;
    // 0x808001D0: lui         $a1, 0x3E18
    ctx->r5 = S32(0X3E18 << 16);
    skip_2:
    // 0x808001D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001D8: jal         0x8009B9B0
    // 0x808001DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_9;
    // 0x808001DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_9:
    // 0x808001E0: lui         $a1, 0x3E18
    ctx->r5 = S32(0X3E18 << 16);
L_808001E4:
    // 0x808001E4: ori         $a1, $a1, 0x5F07
    ctx->r5 = ctx->r5 | 0X5F07;
    // 0x808001E8: jal         0x8008B348
    // 0x808001EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_10;
    // 0x808001EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x808001F0: bne         $v0, $zero, L_808002B4
    if (ctx->r2 != 0) {
        // 0x808001F4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(140, 0X3E4) << 16);
            goto L_808002B4;
    }
    // 0x808001F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(140, 0X3E4) << 16);
    // 0x808001F8: lwc1        $f6, 0x3E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(140, 0X3E4));
    // 0x808001FC: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800200: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(140, 0X3E8) << 16);
    // 0x80800204: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800208: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8080020C: lui         $a1, 0x3EA8
    ctx->r5 = S32(0X3EA8 << 16);
    // 0x80800210: bc1f        L_8080022C
    if (!c1cs) {
        // 0x80800214: nop
    
            goto L_8080022C;
    }
    // 0x80800214: nop

    // 0x80800218: lwc1        $f8, 0x3E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(140, 0X3E8));
    // 0x8080021C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800220: nop

    // 0x80800224: bc1tl       L_808002B8
    if (c1cs) {
        // 0x80800228: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808002B8;
    }
    goto skip_3;
    // 0x80800228: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_3:
L_8080022C:
    // 0x8080022C: jal         0x8008B348
    // 0x80800230: ori         $a1, $a1, 0x5879
    ctx->r5 = ctx->r5 | 0X5879;
    anctrl_isAt(rdram, ctx);
        goto after_11;
    // 0x80800230: ori         $a1, $a1, 0x5879
    ctx->r5 = ctx->r5 | 0X5879;
    after_11:
    // 0x80800234: bne         $v0, $zero, L_808002B4
    if (ctx->r2 != 0) {
        // 0x80800238: lwc1        $f0, 0x1C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_808002B4;
    }
    // 0x80800238: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8080023C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(140, 0X3EC) << 16);
    // 0x80800240: lwc1        $f10, 0x3EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(140, 0X3EC));
    // 0x80800244: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(140, 0X3F0) << 16);
    // 0x80800248: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080024C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800250: lui         $a1, 0x3F14
    ctx->r5 = S32(0X3F14 << 16);
    // 0x80800254: bc1f        L_80800270
    if (!c1cs) {
        // 0x80800258: nop
    
            goto L_80800270;
    }
    // 0x80800258: nop

    // 0x8080025C: lwc1        $f16, 0x3F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(140, 0X3F0));
    // 0x80800260: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800264: nop

    // 0x80800268: bc1tl       L_808002B8
    if (c1cs) {
        // 0x8080026C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808002B8;
    }
    goto skip_4;
    // 0x8080026C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_4:
L_80800270:
    // 0x80800270: jal         0x8008B348
    // 0x80800274: ori         $a1, $a1, 0x2C3D
    ctx->r5 = ctx->r5 | 0X2C3D;
    anctrl_isAt(rdram, ctx);
        goto after_12;
    // 0x80800274: ori         $a1, $a1, 0x2C3D
    ctx->r5 = ctx->r5 | 0X2C3D;
    after_12:
    // 0x80800278: bne         $v0, $zero, L_808002B4
    if (ctx->r2 != 0) {
        // 0x8080027C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(140, 0X3F4) << 16);
            goto L_808002B4;
    }
    // 0x8080027C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(140, 0X3F4) << 16);
    // 0x80800280: lwc1        $f18, 0x3F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(140, 0X3F4));
    // 0x80800284: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800288: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(140, 0X3F8) << 16);
    // 0x8080028C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800290: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800294: nop

    // 0x80800298: bc1f        L_808002C8
    if (!c1cs) {
        // 0x8080029C: nop
    
            goto L_808002C8;
    }
    // 0x8080029C: nop

    // 0x808002A0: lwc1        $f6, 0x3F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(140, 0X3F8));
    // 0x808002A4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808002A8: nop

    // 0x808002AC: bc1f        L_808002C8
    if (!c1cs) {
        // 0x808002B0: nop
    
            goto L_808002C8;
    }
    // 0x808002B0: nop

L_808002B4:
    // 0x808002B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_808002B8:
    // 0x808002B8: jal         0x80095760
    // 0x808002BC: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    baflag_set(rdram, ctx);
        goto after_13;
    // 0x808002BC: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_13:
    // 0x808002C0: b           L_808002D4
    // 0x808002C4: lui         $a1, 0x3F14
    ctx->r5 = S32(0X3F14 << 16);
        goto L_808002D4;
    // 0x808002C4: lui         $a1, 0x3F14
    ctx->r5 = S32(0X3F14 << 16);
L_808002C8:
    // 0x808002C8: jal         0x80095774
    // 0x808002CC: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    baflag_clear(rdram, ctx);
        goto after_14;
    // 0x808002CC: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_14:
    // 0x808002D0: lui         $a1, 0x3F14
    ctx->r5 = S32(0X3F14 << 16);
L_808002D4:
    // 0x808002D4: ori         $a1, $a1, 0x2C3D
    ctx->r5 = ctx->r5 | 0X2C3D;
    // 0x808002D8: jal         0x8008B348
    // 0x808002DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_15;
    // 0x808002DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x808002E0: beql        $v0, $zero, L_808002F8
    if (ctx->r2 == 0) {
        // 0x808002E4: lui         $a1, 0x3DF3
        ctx->r5 = S32(0X3DF3 << 16);
            goto L_808002F8;
    }
    goto skip_5;
    // 0x808002E4: lui         $a1, 0x3DF3
    ctx->r5 = S32(0X3DF3 << 16);
    skip_5:
    // 0x808002E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808002EC: jal         0x8009B9B0
    // 0x808002F0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x808002F0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_16:
    // 0x808002F4: lui         $a1, 0x3DF3
    ctx->r5 = S32(0X3DF3 << 16);
L_808002F8:
    // 0x808002F8: ori         $a1, $a1, 0x4D6A
    ctx->r5 = ctx->r5 | 0X4D6A;
    // 0x808002FC: jal         0x8008B348
    // 0x80800300: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_17;
    // 0x80800300: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_17:
    // 0x80800304: beq         $v0, $zero, L_8080031C
    if (ctx->r2 == 0) {
        // 0x80800308: lui         $a2, 0x3F90
        ctx->r6 = S32(0X3F90 << 16);
            goto L_8080031C;
    }
    // 0x80800308: lui         $a2, 0x3F90
    ctx->r6 = S32(0X3F90 << 16);
    // 0x8080030C: ori         $a2, $a2, 0xA3D7
    ctx->r6 = ctx->r6 | 0XA3D7;
    // 0x80800310: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800314: jal         0x8009DE38
    // 0x80800318: addiu       $a1, $zero, 0x442C
    ctx->r5 = ADD32(0, 0X442C);
    func_8009DE38(rdram, ctx);
        goto after_18;
    // 0x80800318: addiu       $a1, $zero, 0x442C
    ctx->r5 = ADD32(0, 0X442C);
    after_18:
L_8080031C:
    // 0x8080031C: lui         $a1, 0x3E93
    ctx->r5 = S32(0X3E93 << 16);
    // 0x80800320: ori         $a1, $a1, 0xDD98
    ctx->r5 = ctx->r5 | 0XDD98;
    // 0x80800324: jal         0x8008B348
    // 0x80800328: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_19;
    // 0x80800328: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_19:
    // 0x8080032C: beq         $v0, $zero, L_80800344
    if (ctx->r2 == 0) {
        // 0x80800330: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800344;
    }
    // 0x80800330: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800334: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x80800338: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080033C: jal         0x8009DE38
    // 0x80800340: addiu       $a1, $zero, 0x442C
    ctx->r5 = ADD32(0, 0X442C);
    func_8009DE38(rdram, ctx);
        goto after_20;
    // 0x80800340: addiu       $a1, $zero, 0x442C
    ctx->r5 = ADD32(0, 0X442C);
    after_20:
L_80800344:
    // 0x80800344: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800348: jal         0x8008B348
    // 0x8080034C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    anctrl_isAt(rdram, ctx);
        goto after_21;
    // 0x8080034C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_21:
    // 0x80800350: beq         $v0, $zero, L_80800368
    if (ctx->r2 == 0) {
        // 0x80800354: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800368;
    }
    // 0x80800354: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800358: lui         $a2, 0x3FA8
    ctx->r6 = S32(0X3FA8 << 16);
    // 0x8080035C: ori         $a2, $a2, 0xF5C3
    ctx->r6 = ctx->r6 | 0XF5C3;
    // 0x80800360: jal         0x8009DE38
    // 0x80800364: addiu       $a1, $zero, 0x442C
    ctx->r5 = ADD32(0, 0X442C);
    func_8009DE38(rdram, ctx);
        goto after_22;
    // 0x80800364: addiu       $a1, $zero, 0x442C
    ctx->r5 = ADD32(0, 0X442C);
    after_22:
L_80800368:
    // 0x80800368: jal         0x8008B324
    // 0x8080036C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isStopped(rdram, ctx);
        goto after_23;
    // 0x8080036C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_23:
    // 0x80800370: beq         $v0, $zero, L_8080037C
    if (ctx->r2 == 0) {
        // 0x80800374: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8080037C;
    }
    // 0x80800374: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800378: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_8080037C:
    // 0x8080037C: jal         0x8008E35C
    // 0x80800380: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    player_inWater(rdram, ctx);
        goto after_24;
    // 0x80800380: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_24:
    // 0x80800384: beq         $v0, $zero, L_80800394
    if (ctx->r2 == 0) {
        // 0x80800388: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_80800394;
    }
    // 0x80800388: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8080038C: addiu       $t8, $zero, 0x4C
    ctx->r24 = ADD32(0, 0X4C);
    // 0x80800390: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_80800394:
    // 0x80800394: jal         0x80091A58
    // 0x80800398: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    bakey_pressed(rdram, ctx);
        goto after_25;
    // 0x80800398: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_25:
    // 0x8080039C: beql        $v0, $zero, L_808003B4
    if (ctx->r2 == 0) {
        // 0x808003A0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808003B4;
    }
    goto skip_6;
    // 0x808003A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_6:
    // 0x808003A4: jal         0x8009FE84
    // 0x808003A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    bs_getTypeOfJump(rdram, ctx);
        goto after_26;
    // 0x808003A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_26:
    // 0x808003AC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808003B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_808003B4:
    // 0x808003B4: jal         0x8009E5C8
    // 0x808003B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_27;
    // 0x808003B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_27:
    // 0x808003BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003C4: jr          $ra
    // 0x808003C8: nop

    return;
    // 0x808003C8: nop

;}
RECOMP_FUNC void func_80109704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109704: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80109708: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8010970C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80109710: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80109714: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80109718: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010971C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80109720: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80109724: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80109728: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8010972C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80109730: jal         0x80109748
    // 0x80109734: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    func_80109748(rdram, ctx);
        goto after_0;
    // 0x80109734: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_0:
    // 0x80109738: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8010973C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80109740: jr          $ra
    // 0x80109744: nop

    return;
    // 0x80109744: nop

;}
RECOMP_FUNC void func_80800964_chgoldfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800964: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800968: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080096C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800970: jal         0x800BED50
    // 0x80800974: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800BED50(rdram, ctx);
        goto after_0;
    // 0x80800974: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800978: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8080097C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800980: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80800984: lui         $a0, 0x7FFB
    ctx->r4 = S32(0X7FFB << 16);
    // 0x80800988: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8080098C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800990: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800994: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800998: ori         $a0, $a0, 0x5C09
    ctx->r4 = ctx->r4 | 0X5C09;
    // 0x8080099C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808009A0: jal         0x800C4140
    // 0x808009A4: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    func_800C4140(rdram, ctx);
        goto after_1;
    // 0x808009A4: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x808009A8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808009AC: jal         0x80088AE8
    // 0x808009B0: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    _fxsplash_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808009B0: lui         $a1, 0x420C
    ctx->r5 = S32(0X420C << 16);
    after_2:
    // 0x808009B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808009B8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808009BC: jal         0x800889A0
    // 0x808009C0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    _fxripple_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808009C0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x808009C4: addiu       $t6, $zero, 0x15E
    ctx->r14 = ADD32(0, 0X15E);
    // 0x808009C8: addiu       $t7, $zero, 0x1F4
    ctx->r15 = ADD32(0, 0X1F4);
    // 0x808009CC: addiu       $t8, $zero, 0x15E
    ctx->r24 = ADD32(0, 0X15E);
    // 0x808009D0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x808009D4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808009D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E0: addiu       $a1, $zero, -0x15E
    ctx->r5 = ADD32(0, -0X15E);
    // 0x808009E4: addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // 0x808009E8: jal         0x800BA930
    // 0x808009EC: addiu       $a3, $zero, -0x15E
    ctx->r7 = ADD32(0, -0X15E);
    func_800BA930(rdram, ctx);
        goto after_4;
    // 0x808009EC: addiu       $a3, $zero, -0x15E
    ctx->r7 = ADD32(0, -0X15E);
    after_4:
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009F4: jal         0x800BA22C
    // 0x808009F8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800BA22C(rdram, ctx);
        goto after_5;
    // 0x808009F8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_5:
    // 0x808009FC: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x80800A00: addiu       $t0, $zero, 0x320
    ctx->r8 = ADD32(0, 0X320);
    // 0x80800A04: addiu       $t1, $zero, 0x96
    ctx->r9 = ADD32(0, 0X96);
    // 0x80800A08: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80800A0C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800A10: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A18: addiu       $a1, $zero, -0x96
    ctx->r5 = ADD32(0, -0X96);
    // 0x80800A1C: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x80800A20: jal         0x800BA930
    // 0x80800A24: addiu       $a3, $zero, -0x96
    ctx->r7 = ADD32(0, -0X96);
    func_800BA930(rdram, ctx);
        goto after_6;
    // 0x80800A24: addiu       $a3, $zero, -0x96
    ctx->r7 = ADD32(0, -0X96);
    after_6:
    // 0x80800A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A2C: jal         0x800BA22C
    // 0x80800A30: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x80800A30: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_7:
    // 0x80800A34: jal         0x800889D8
    // 0x80800A38: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    _fxsplash25d_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80800A38: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_8:
    // 0x80800A3C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800A40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800A44: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800A48: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800A4C: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80800A50: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800A54: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800A58: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800A5C: jal         0x800889D0
    // 0x80800A60: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    _fxairbub_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80800A60: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x80800A64: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x80800A68: addiu       $t3, $zero, -0x96
    ctx->r11 = ADD32(0, -0X96);
    // 0x80800A6C: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x80800A70: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A74: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80800A78: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800A7C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800A80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A84: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x80800A88: addiu       $a2, $zero, -0xFA
    ctx->r6 = ADD32(0, -0XFA);
    // 0x80800A8C: jal         0x800BA930
    // 0x80800A90: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    func_800BA930(rdram, ctx);
        goto after_10;
    // 0x80800A90: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    after_10:
    // 0x80800A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A98: jal         0x800BA22C
    // 0x80800A9C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800BA22C(rdram, ctx);
        goto after_11;
    // 0x80800A9C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_11:
    // 0x80800AA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AA4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800AA8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800AAC: jr          $ra
    // 0x80800AB0: nop

    return;
    // 0x80800AB0: nop

;}
RECOMP_FUNC void func_8008CA4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CA4C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8008CA50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008CA54: lw          $t6, 0x3C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X3C);
    // 0x8008CA58: beq         $t6, $zero, L_8008CA6C
    if (ctx->r14 == 0) {
        // 0x8008CA5C: nop
    
            goto L_8008CA6C;
    }
    // 0x8008CA5C: nop

    // 0x8008CA60: bne         $a1, $at, L_8008CA6C
    if (ctx->r5 != ctx->r1) {
        // 0x8008CA64: nop
    
            goto L_8008CA6C;
    }
    // 0x8008CA64: nop

    // 0x8008CA68: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_8008CA6C:
    // 0x8008CA6C: jr          $ra
    // 0x8008CA70: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    return;
    // 0x8008CA70: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_800BFAD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFAD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BFAD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BFAD8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BFADC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800BFAE0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800BFAE4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800BFAE8: jal         0x800BFC34
    // 0x800BFAEC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800BFC34(rdram, ctx);
        goto after_0;
    // 0x800BFAEC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x800BFAF0: jal         0x800D2F20
    // 0x800BFAF4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800D2F20(rdram, ctx);
        goto after_1;
    // 0x800BFAF4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    tooie_model_draw_distance(rdram, ctx);
    // 0x800BFAF8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800BFAFC: jal         0x800DF428
    // 0x800BFB00: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800DF428(rdram, ctx);
        goto after_2;
    // 0x800BFB00: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_2:
    // 0x800BFB04: jal         0x800DF470
    // 0x800BFB08: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF470(rdram, ctx);
        goto after_3;
    // 0x800BFB08: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800BFB0C: jal         0x800DF830
    // 0x800BFB10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_4;
    // 0x800BFB10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800BFB14: jal         0x800DF3E0
    // 0x800BFB18: nop

    func_800DF3E0(rdram, ctx);
        goto after_5;
    // 0x800BFB18: nop

    after_5:
    // 0x800BFB1C: jal         0x800D731C
    // 0x800BFB20: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800D731C(rdram, ctx);
        goto after_6;
    // 0x800BFB20: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x800BFB24: jal         0x800DF7E8
    // 0x800BFB28: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    func_800DF7E8(rdram, ctx);
        goto after_7;
    // 0x800BFB28: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_7:
    // 0x800BFB2C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BFB30: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800BFB34: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800BFB38: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800BFB3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BFB40: jal         0x800DE448
    // 0x800BFB44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800DE448(rdram, ctx);
        goto after_8;
    // 0x800BFB44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_8:
    // 0x800BFB48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BFB4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BFB50: jr          $ra
    // 0x800BFB54: nop

    return;
    // 0x800BFB54: nop

;}
RECOMP_FUNC void _bsbflap_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082918: syscall     20
    recomp_syscall_handler(rdram, ctx, 0x80082918);
    return;
    // 0x8008291C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void gcnewoption_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800080: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800084: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800088: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080008C: lbu         $t6, 0x1C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1C);
    // 0x80800090: lw          $a1, 0x20($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X20);
    // 0x80800094: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800098: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x8080009C: beq         $a1, $zero, L_808000AC
    if (ctx->r5 == 0) {
        // 0x808000A0: sb          $t7, 0x1C($a0)
        MEM_B(0X1C, ctx->r4) = ctx->r15;
            goto L_808000AC;
    }
    // 0x808000A0: sb          $t7, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r15;
    // 0x808000A4: lbu         $t8, 0x24($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X24);
    // 0x808000A8: sb          $t8, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r24;
L_808000AC:
    // 0x808000AC: lhu         $t9, 0x0($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X0);
    // 0x808000B0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x808000B4: sltiu       $at, $t9, 0xE
    ctx->r1 = ctx->r25 < 0XE ? 1 : 0;
    // 0x808000B8: beq         $at, $zero, L_80800720
    if (ctx->r1 == 0) {
        // 0x808000BC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800720;
    }
    // 0x808000BC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808000C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2F70) << 16);
    // 0x808000C4: addu        $at, $at, $t9
    gpr jr_addend_808000CC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808000C8: lw          $t9, 0x2F70($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2F70));
    // 0x808000CC: jr          $t9
    // 0x808000D0: nop

    switch (jr_addend_808000CC >> 2) {
        case 0: goto L_808000D4; break;
        case 1: goto L_808000DC; break;
        case 2: goto L_80800110; break;
        case 3: goto L_80800120; break;
        case 4: goto L_80800198; break;
        case 5: goto L_80800218; break;
        case 6: goto L_80800578; break;
        case 7: goto L_808005A0; break;
        case 8: goto L_808005D4; break;
        case 9: goto L_80800684; break;
        case 10: goto L_808006CC; break;
        case 11: goto L_808005FC; break;
        case 12: goto L_80800618; break;
        case 13: goto L_8080067C; break;
        default: switch_error(__func__, 0x808000CC, 0x80802F70);
    }
    // 0x808000D0: nop

L_808000D4:
    // 0x808000D4: b           L_80800720
    // 0x808000D8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80800720;
    // 0x808000D8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_808000DC:
    // 0x808000DC: jal         0x80800D28
    // 0x808000E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800D28_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x808000E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x808000E4: lw          $t9, 0x244($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X244);
    // 0x808000E8: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    // 0x808000EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808000F0: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    // 0x808000F4: jalr        $t9
    // 0x808000F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x808000F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x808000FC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80800100: sh          $t0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r8;
    // 0x80800104: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    // 0x80800108: b           L_80800720
    // 0x8080010C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80800720;
    // 0x8080010C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80800110:
    // 0x80800110: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80800114: sh          $s0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r16;
    // 0x80800118: b           L_80800720
    // 0x8080011C: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
        goto L_80800720;
    // 0x8080011C: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
L_80800120:
    // 0x80800120: jal         0x80801E68
    // 0x80800124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801E68_gcnewoption(rdram, ctx);
        goto after_2;
    // 0x80800124: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800128: beql        $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x8080012C: addiu       $s0, $zero, 0x3
        ctx->r16 = ADD32(0, 0X3);
            goto L_80800188;
    }
    goto skip_0;
    // 0x8080012C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    skip_0:
    // 0x80800130: lbu         $t1, 0x1C($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X1C);
    // 0x80800134: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80800138: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8080013C: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x80800140: bne         $s0, $t2, L_80800154
    if (ctx->r16 != ctx->r10) {
        // 0x80800144: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80800154;
    }
    // 0x80800144: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800148: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8080014C: b           L_80800184
    // 0x80800150: sh          $t3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r11;
        goto L_80800184;
    // 0x80800150: sh          $t3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r11;
L_80800154:
    // 0x80800154: lw          $t9, 0x244($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X244);
    // 0x80800158: sh          $t4, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r12;
    // 0x8080015C: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    // 0x80800160: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    // 0x80800164: jalr        $t9
    // 0x80800168: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80800168: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_3:
    // 0x8080016C: lw          $t9, 0x244($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X244);
    // 0x80800170: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    // 0x80800174: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800178: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    // 0x8080017C: jalr        $t9
    // 0x80800180: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80800180: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_4:
L_80800184:
    // 0x80800184: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80800188:
    // 0x80800188: jal         0x808019D0
    // 0x8080018C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808019D0_gcnewoption(rdram, ctx);
        goto after_5;
    // 0x8080018C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80800190: b           L_80800720
    // 0x80800194: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
        goto L_80800720;
    // 0x80800194: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
L_80800198:
    // 0x80800198: lh          $t5, 0x2($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2);
    // 0x8080019C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808001A0: blez        $t5, L_808001E8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x808001A4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808001E8;
    }
    // 0x808001A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808001A8:
    // 0x808001A8: jal         0x80800000
    // 0x808001AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_6;
    // 0x808001AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x808001B0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808001B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001B8: jal         0x808027DC
    // 0x808001BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_808027DC_gcnewoption(rdram, ctx);
        goto after_7;
    // 0x808001BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x808001C0: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x808001C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x808001C8: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x808001CC: jal         0x80087B00
    // 0x808001D0: lw          $a0, 0x3C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X3C);
    _gczoombox_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x808001D0: lw          $a0, 0x3C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X3C);
    after_8:
    // 0x808001D4: lh          $t0, 0x2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X2);
    // 0x808001D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808001DC: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x808001E0: bnel        $at, $zero, L_808001A8
    if (ctx->r1 != 0) {
        // 0x808001E4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808001A8;
    }
    goto skip_1;
    // 0x808001E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
L_808001E8:
    // 0x808001E8: jal         0x80801B5C
    // 0x808001EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801B5C_gcnewoption(rdram, ctx);
        goto after_9;
    // 0x808001EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x808001F0: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    // 0x808001F4: beq         $a1, $zero, L_80800204
    if (ctx->r5 == 0) {
        // 0x808001F8: nop
    
            goto L_80800204;
    }
    // 0x808001F8: nop

    // 0x808001FC: jal         0x80087B00
    // 0x80800200: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _gczoombox_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x80800200: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_10:
L_80800204:
    // 0x80800204: jal         0x80802998
    // 0x80800208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802998_gcnewoption(rdram, ctx);
        goto after_11;
    // 0x80800208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8080020C: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    // 0x80800210: b           L_80800720
    // 0x80800214: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80800720;
    // 0x80800214: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80800218:
    // 0x80800218: jal         0x808019D0
    // 0x8080021C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808019D0_gcnewoption(rdram, ctx);
        goto after_12;
    // 0x8080021C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80800220: jal         0x80802998
    // 0x80800224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802998_gcnewoption(rdram, ctx);
        goto after_13;
    // 0x80800224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80800228: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080022C: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80800230: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80800234: nop

    // 0x80800238: bc1fl       L_8080054C
    if (!c1cs) {
        // 0x8080023C: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8080054C;
    }
    goto skip_2;
    // 0x8080023C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_2:
    // 0x80800240: lb          $v0, 0x250($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X250);
    // 0x80800244: bltz        $v0, L_80800548
    if (SIGNED(ctx->r2) < 0) {
        // 0x80800248: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800548;
    }
    // 0x80800248: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080024C: jal         0x80015E80
    // 0x80800250: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80015E80(rdram, ctx);
        goto after_14;
    // 0x80800250: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_14:
    // 0x80800254: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80800258: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8080025C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80800260: bne         $v1, $t1, L_808002BC
    if (ctx->r3 != ctx->r9) {
        // 0x80800264: nop
    
            goto L_808002BC;
    }
    // 0x80800264: nop

    // 0x80800268: lbu         $v0, 0x1C($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1C);
    // 0x8080026C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800270: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800274: andi        $t2, $v0, 0x7
    ctx->r10 = ctx->r2 & 0X7;
    // 0x80800278: bne         $t2, $at, L_808002A8
    if (ctx->r10 != ctx->r1) {
        // 0x8080027C: ori         $t4, $v0, 0x20
        ctx->r12 = ctx->r2 | 0X20;
            goto L_808002A8;
    }
    // 0x8080027C: ori         $t4, $v0, 0x20
    ctx->r12 = ctx->r2 | 0X20;
    // 0x80800280: lw          $v0, 0x244($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X244);
    // 0x80800284: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800288: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8080028C: beql        $v0, $zero, L_80800398
    if (ctx->r2 == 0) {
        // 0x80800290: lh          $t2, 0x0($s1)
        ctx->r10 = MEM_H(ctx->r17, 0X0);
            goto L_80800398;
    }
    goto skip_3;
    // 0x80800290: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    skip_3:
    // 0x80800294: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    // 0x80800298: jalr        $v0
    // 0x8080029C: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_15;
    // 0x8080029C: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    after_15:
    // 0x808002A0: b           L_80800398
    // 0x808002A4: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
        goto L_80800398;
    // 0x808002A4: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
L_808002A8:
    // 0x808002A8: jal         0x80802A9C
    // 0x808002AC: sb          $t4, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r12;
    func_80802A9C_gcnewoption(rdram, ctx);
        goto after_16;
    // 0x808002AC: sb          $t4, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r12;
    after_16:
    // 0x808002B0: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x808002B4: b           L_80800394
    // 0x808002B8: sh          $t9, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r25;
        goto L_80800394;
    // 0x808002B8: sh          $t9, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r25;
L_808002BC:
    // 0x808002BC: bnel        $v1, $t5, L_80800398
    if (ctx->r3 != ctx->r13) {
        // 0x808002C0: lh          $t2, 0x0($s1)
        ctx->r10 = MEM_H(ctx->r17, 0X0);
            goto L_80800398;
    }
    goto skip_4;
    // 0x808002C0: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    skip_4:
    // 0x808002C4: lbu         $v0, 0x1C($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1C);
    // 0x808002C8: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x808002CC: beql        $t6, $zero, L_808002F0
    if (ctx->r14 == 0) {
        // 0x808002D0: lh          $a2, 0x6($s1)
        ctx->r6 = MEM_H(ctx->r17, 0X6);
            goto L_808002F0;
    }
    goto skip_5;
    // 0x808002D0: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    skip_5:
    // 0x808002D4: beq         $t6, $v1, L_80800340
    if (ctx->r14 == ctx->r3) {
        // 0x808002D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800340;
    }
    // 0x808002D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002DC: beql        $t6, $at, L_8080036C
    if (ctx->r14 == ctx->r1) {
        // 0x808002E0: lw          $v0, 0x244($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X244);
            goto L_8080036C;
    }
    goto skip_6;
    // 0x808002E0: lw          $v0, 0x244($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X244);
    skip_6:
    // 0x808002E4: b           L_80800388
    // 0x808002E8: nop

        goto L_80800388;
    // 0x808002E8: nop

    // 0x808002EC: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
L_808002F0:
    // 0x808002F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808002F4: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x808002F8: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x808002FC: lh          $t0, 0xB0($t8)
    ctx->r8 = MEM_H(ctx->r24, 0XB0);
    // 0x80800300: bne         $t0, $at, L_8080032C
    if (ctx->r8 != ctx->r1) {
        // 0x80800304: nop
    
            goto L_8080032C;
    }
    // 0x80800304: nop

    // 0x80800308: lw          $v0, 0x244($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X244);
    // 0x8080030C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800310: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800314: beq         $v0, $zero, L_80800388
    if (ctx->r2 == 0) {
        // 0x80800318: nop
    
            goto L_80800388;
    }
    // 0x80800318: nop

    // 0x8080031C: jalr        $v0
    // 0x80800320: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_17;
    // 0x80800320: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    after_17:
    // 0x80800324: b           L_8080077C
    // 0x80800328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080077C;
    // 0x80800328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080032C:
    // 0x8080032C: jal         0x80802A9C
    // 0x80800330: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802A9C_gcnewoption(rdram, ctx);
        goto after_18;
    // 0x80800330: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80800334: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80800338: b           L_80800388
    // 0x8080033C: sh          $t1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r9;
        goto L_80800388;
    // 0x8080033C: sh          $t1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r9;
L_80800340:
    // 0x80800340: lw          $v0, 0x244($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X244);
    // 0x80800344: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800348: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080034C: beq         $v0, $zero, L_80800388
    if (ctx->r2 == 0) {
        // 0x80800350: nop
    
            goto L_80800388;
    }
    // 0x80800350: nop

    // 0x80800354: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    // 0x80800358: jalr        $v0
    // 0x8080035C: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_19;
    // 0x8080035C: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    after_19:
    // 0x80800360: b           L_80800388
    // 0x80800364: nop

        goto L_80800388;
    // 0x80800364: nop

    // 0x80800368: lw          $v0, 0x244($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X244);
L_8080036C:
    // 0x8080036C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800370: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80800374: beq         $v0, $zero, L_80800388
    if (ctx->r2 == 0) {
        // 0x80800378: nop
    
            goto L_80800388;
    }
    // 0x80800378: nop

    // 0x8080037C: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    // 0x80800380: jalr        $v0
    // 0x80800384: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_20;
    // 0x80800384: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    after_20:
L_80800388:
    // 0x80800388: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FA8) << 16);
    // 0x8080038C: lwc1        $f4, 0x2FA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FA8));
    // 0x80800390: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
L_80800394:
    // 0x80800394: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
L_80800398:
    // 0x80800398: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080039C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x808003A0: beql        $t2, $at, L_808003B4
    if (ctx->r10 == ctx->r1) {
        // 0x808003A4: lw          $v0, 0x1C($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X1C);
            goto L_808003B4;
    }
    goto skip_7;
    // 0x808003A4: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    skip_7:
    // 0x808003A8: b           L_80800720
    // 0x808003AC: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
        goto L_80800720;
    // 0x808003AC: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    // 0x808003B0: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
L_808003B4:
    // 0x808003B4: srl         $t3, $v0, 31
    ctx->r11 = S32(U32(ctx->r2) >> 31);
    // 0x808003B8: bne         $t3, $zero, L_80800444
    if (ctx->r11 != 0) {
        // 0x808003BC: sll         $t9, $v0, 4
        ctx->r25 = S32(ctx->r2 << 4);
            goto L_80800444;
    }
    // 0x808003BC: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x808003C0: bltzl       $t9, L_80800448
    if (SIGNED(ctx->r25) < 0) {
        // 0x808003C4: lbu         $t5, 0x1C($s1)
        ctx->r13 = MEM_BU(ctx->r17, 0X1C);
            goto L_80800448;
    }
    goto skip_8;
    // 0x808003C4: lbu         $t5, 0x1C($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X1C);
    skip_8:
    // 0x808003C8: lb          $a0, 0x250($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X250);
    // 0x808003CC: bltzl       $a0, L_80800448
    if (SIGNED(ctx->r4) < 0) {
        // 0x808003D0: lbu         $t5, 0x1C($s1)
        ctx->r13 = MEM_BU(ctx->r17, 0X1C);
            goto L_80800448;
    }
    goto skip_9;
    // 0x808003D0: lbu         $t5, 0x1C($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X1C);
    skip_9:
    // 0x808003D4: jal         0x80016068
    // 0x808003D8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80016068(rdram, ctx);
        goto after_21;
    // 0x808003D8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_21:
    // 0x808003DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FAC) << 16);
    // 0x808003E0: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808003E4: lwc1        $f6, 0x2FAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FAC));
    // 0x808003E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FB4) << 16);
    // 0x808003EC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808003F0: nop

    // 0x808003F4: bc1f        L_80800418
    if (!c1cs) {
        // 0x808003F8: nop
    
            goto L_80800418;
    }
    // 0x808003F8: nop

    // 0x808003FC: jal         0x80801114
    // 0x80800400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801114_gcnewoption(rdram, ctx);
        goto after_22;
    // 0x80800400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x80800404: beq         $v0, $zero, L_80800444
    if (ctx->r2 == 0) {
        // 0x80800408: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2590, 0X2FB0) << 16);
            goto L_80800444;
    }
    // 0x80800408: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FB0) << 16);
    // 0x8080040C: lwc1        $f8, 0x2FB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FB0));
    // 0x80800410: b           L_80800444
    // 0x80800414: swc1        $f8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f8.u32l;
        goto L_80800444;
    // 0x80800414: swc1        $f8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f8.u32l;
L_80800418:
    // 0x80800418: lwc1        $f10, 0x2FB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FB4));
    // 0x8080041C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800420: nop

    // 0x80800424: bc1fl       L_80800448
    if (!c1cs) {
        // 0x80800428: lbu         $t5, 0x1C($s1)
        ctx->r13 = MEM_BU(ctx->r17, 0X1C);
            goto L_80800448;
    }
    goto skip_10;
    // 0x80800428: lbu         $t5, 0x1C($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X1C);
    skip_10:
    // 0x8080042C: jal         0x80801190
    // 0x80800430: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801190_gcnewoption(rdram, ctx);
        goto after_23;
    // 0x80800430: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x80800434: beq         $v0, $zero, L_80800444
    if (ctx->r2 == 0) {
        // 0x80800438: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2590, 0X2FB8) << 16);
            goto L_80800444;
    }
    // 0x80800438: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FB8) << 16);
    // 0x8080043C: lwc1        $f16, 0x2FB8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FB8));
    // 0x80800440: swc1        $f16, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f16.u32l;
L_80800444:
    // 0x80800444: lbu         $t5, 0x1C($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X1C);
L_80800448:
    // 0x80800448: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080044C: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x80800450: bnel        $t6, $at, L_80800570
    if (ctx->r14 != ctx->r1) {
        // 0x80800454: lw          $a1, 0x20($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X20);
            goto L_80800570;
    }
    goto skip_11;
    // 0x80800454: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    skip_11:
    // 0x80800458: lw          $t7, 0x1C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1C);
    // 0x8080045C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800460: sll         $t0, $t7, 4
    ctx->r8 = S32(ctx->r15 << 4);
    // 0x80800464: bgezl       $t0, L_80800570
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800468: lw          $a1, 0x20($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X20);
            goto L_80800570;
    }
    goto skip_12;
    // 0x80800468: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    skip_12:
    // 0x8080046C: jal         0x80016068
    // 0x80800470: lb          $a0, 0x250($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X250);
    func_80016068(rdram, ctx);
        goto after_24;
    // 0x80800470: lb          $a0, 0x250($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X250);
    after_24:
    // 0x80800474: lw          $t1, 0x1C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1C);
    // 0x80800478: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080047C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FC0) << 16);
    // 0x80800480: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x80800484: bgez        $t3, L_808004BC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800488: nop
    
            goto L_808004BC;
    }
    // 0x80800488: nop

    // 0x8080048C: jal         0x800F2100
    // 0x80800490: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    mlAbsF(rdram, ctx);
        goto after_25;
    // 0x80800490: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    after_25:
    // 0x80800494: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FBC) << 16);
    // 0x80800498: lwc1        $f18, 0x2FBC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FBC));
    // 0x8080049C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808004A0: nop

    // 0x808004A4: bc1fl       L_80800570
    if (!c1cs) {
        // 0x808004A8: lw          $a1, 0x20($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X20);
            goto L_80800570;
    }
    goto skip_13;
    // 0x808004A8: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    skip_13:
    // 0x808004AC: lbu         $t4, 0x1C($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X1C);
    // 0x808004B0: andi        $t9, $t4, 0xFFBF
    ctx->r25 = ctx->r12 & 0XFFBF;
    // 0x808004B4: b           L_8080056C
    // 0x808004B8: sb          $t9, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r25;
        goto L_8080056C;
    // 0x808004B8: sb          $t9, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r25;
L_808004BC:
    // 0x808004BC: lwc1        $f4, 0x2FC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FC0));
    // 0x808004C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X2FC4) << 16);
    // 0x808004C4: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x808004C8: nop

    // 0x808004CC: bc1f        L_80800504
    if (!c1cs) {
        // 0x808004D0: nop
    
            goto L_80800504;
    }
    // 0x808004D0: nop

    // 0x808004D4: lw          $v0, 0x244($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X244);
    // 0x808004D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808004DC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x808004E0: beql        $v0, $zero, L_808004F8
    if (ctx->r2 == 0) {
        // 0x808004E4: lbu         $t6, 0x1C($s1)
        ctx->r14 = MEM_BU(ctx->r17, 0X1C);
            goto L_808004F8;
    }
    goto skip_14;
    // 0x808004E4: lbu         $t6, 0x1C($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X1C);
    skip_14:
    // 0x808004E8: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    // 0x808004EC: jalr        $v0
    // 0x808004F0: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_26;
    // 0x808004F0: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    after_26:
    // 0x808004F4: lbu         $t6, 0x1C($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X1C);
L_808004F8:
    // 0x808004F8: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x808004FC: b           L_8080056C
    // 0x80800500: sb          $t7, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r15;
        goto L_8080056C;
    // 0x80800500: sb          $t7, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r15;
L_80800504:
    // 0x80800504: lwc1        $f6, 0x2FC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X2FC4));
    // 0x80800508: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x8080050C: nop

    // 0x80800510: bc1fl       L_80800570
    if (!c1cs) {
        // 0x80800514: lw          $a1, 0x20($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X20);
            goto L_80800570;
    }
    goto skip_15;
    // 0x80800514: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    skip_15:
    // 0x80800518: lw          $v0, 0x244($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X244);
    // 0x8080051C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800520: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80800524: beql        $v0, $zero, L_8080053C
    if (ctx->r2 == 0) {
        // 0x80800528: lbu         $t0, 0x1C($s1)
        ctx->r8 = MEM_BU(ctx->r17, 0X1C);
            goto L_8080053C;
    }
    goto skip_16;
    // 0x80800528: lbu         $t0, 0x1C($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1C);
    skip_16:
    // 0x8080052C: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    // 0x80800530: jalr        $v0
    // 0x80800534: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_27;
    // 0x80800534: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    after_27:
    // 0x80800538: lbu         $t0, 0x1C($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1C);
L_8080053C:
    // 0x8080053C: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x80800540: b           L_8080056C
    // 0x80800544: sb          $t1, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r9;
        goto L_8080056C;
    // 0x80800544: sb          $t1, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r9;
L_80800548:
    // 0x80800548: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8080054C:
    // 0x8080054C: nop

    // 0x80800550: bc1fl       L_80800570
    if (!c1cs) {
        // 0x80800554: lw          $a1, 0x20($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X20);
            goto L_80800570;
    }
    goto skip_17;
    // 0x80800554: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    skip_17:
    // 0x80800558: jal         0x800D8FF8
    // 0x8080055C: nop

    func_800D8FF8(rdram, ctx);
        goto after_28;
    // 0x8080055C: nop

    after_28:
    // 0x80800560: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80800564: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800568: swc1        $f10, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f10.u32l;
L_8080056C:
    // 0x8080056C: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
L_80800570:
    // 0x80800570: b           L_80800720
    // 0x80800574: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80800720;
    // 0x80800574: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80800578:
    // 0x80800578: jal         0x808019D0
    // 0x8080057C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808019D0_gcnewoption(rdram, ctx);
        goto after_29;
    // 0x8080057C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
    // 0x80800580: jal         0x808020C4
    // 0x80800584: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808020C4_gcnewoption(rdram, ctx);
        goto after_30;
    // 0x80800584: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_30:
    // 0x80800588: beq         $v0, $zero, L_80800598
    if (ctx->r2 == 0) {
        // 0x8080058C: addiu       $s0, $zero, 0x3
        ctx->r16 = ADD32(0, 0X3);
            goto L_80800598;
    }
    // 0x8080058C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80800590: addiu       $t2, $zero, 0xB
    ctx->r10 = ADD32(0, 0XB);
    // 0x80800594: sh          $t2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r10;
L_80800598:
    // 0x80800598: b           L_80800720
    // 0x8080059C: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
        goto L_80800720;
    // 0x8080059C: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
L_808005A0:
    // 0x808005A0: jal         0x808019D0
    // 0x808005A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808019D0_gcnewoption(rdram, ctx);
        goto after_31;
    // 0x808005A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_31:
    // 0x808005A8: jal         0x808022E0
    // 0x808005AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808022E0_gcnewoption(rdram, ctx);
        goto after_32;
    // 0x808005AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_32:
    // 0x808005B0: beql        $v0, $zero, L_808005CC
    if (ctx->r2 == 0) {
        // 0x808005B4: lw          $a1, 0x20($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X20);
            goto L_808005CC;
    }
    goto skip_18;
    // 0x808005B4: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    skip_18:
    // 0x808005B8: jal         0x80802A9C
    // 0x808005BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802A9C_gcnewoption(rdram, ctx);
        goto after_33;
    // 0x808005BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_33:
    // 0x808005C0: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x808005C4: sh          $t3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r11;
    // 0x808005C8: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
L_808005CC:
    // 0x808005CC: b           L_80800720
    // 0x808005D0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80800720;
    // 0x808005D0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_808005D4:
    // 0x808005D4: jal         0x808019D0
    // 0x808005D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808019D0_gcnewoption(rdram, ctx);
        goto after_34;
    // 0x808005D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_34:
    // 0x808005DC: jal         0x80802674
    // 0x808005E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802674_gcnewoption(rdram, ctx);
        goto after_35;
    // 0x808005E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_35:
    // 0x808005E4: beq         $v0, $zero, L_808005F4
    if (ctx->r2 == 0) {
        // 0x808005E8: addiu       $s0, $zero, 0x3
        ctx->r16 = ADD32(0, 0X3);
            goto L_808005F4;
    }
    // 0x808005E8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x808005EC: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x808005F0: sh          $t4, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r12;
L_808005F4:
    // 0x808005F4: b           L_80800720
    // 0x808005F8: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
        goto L_80800720;
    // 0x808005F8: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
L_808005FC:
    // 0x808005FC: jal         0x8080103C
    // 0x80800600: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8080103C_gcnewoption(rdram, ctx);
        goto after_36;
    // 0x80800600: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_36:
    // 0x80800604: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80800608: sh          $t9, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r25;
    // 0x8080060C: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    // 0x80800610: b           L_80800720
    // 0x80800614: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80800720;
    // 0x80800614: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80800618:
    // 0x80800618: lw          $v0, 0x244($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X244);
    // 0x8080061C: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    // 0x80800620: sh          $t5, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r13;
    // 0x80800624: beq         $v0, $zero, L_80800674
    if (ctx->r2 == 0) {
        // 0x80800628: addiu       $s0, $zero, 0x3
        ctx->r16 = ADD32(0, 0X3);
            goto L_80800674;
    }
    // 0x80800628: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8080062C: lw          $t6, 0x1C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C);
    // 0x80800630: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800634: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800638: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8080063C: bgezl       $t8, L_80800664
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800640: lw          $a0, 0x24C($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X24C);
            goto L_80800664;
    }
    goto skip_19;
    // 0x80800640: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    skip_19:
    // 0x80800644: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    // 0x80800648: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080064C: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    // 0x80800650: jalr        $v0
    // 0x80800654: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_37;
    // 0x80800654: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_37:
    // 0x80800658: b           L_8080077C
    // 0x8080065C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080077C;
    // 0x8080065C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800660: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
L_80800664:
    // 0x80800664: jalr        $v0
    // 0x80800668: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_38;
    // 0x80800668: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    after_38:
    // 0x8080066C: b           L_8080077C
    // 0x80800670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080077C;
    // 0x80800670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800674:
    // 0x80800674: b           L_80800720
    // 0x80800678: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
        goto L_80800720;
    // 0x80800678: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
L_8080067C:
    // 0x8080067C: b           L_80800720
    // 0x80800680: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80800720;
    // 0x80800680: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80800684:
    // 0x80800684: jal         0x808019D0
    // 0x80800688: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808019D0_gcnewoption(rdram, ctx);
        goto after_39;
    // 0x80800688: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_39:
    // 0x8080068C: jal         0x8080241C
    // 0x80800690: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8080241C_gcnewoption(rdram, ctx);
        goto after_40;
    // 0x80800690: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_40:
    // 0x80800694: beql        $v0, $zero, L_808006C4
    if (ctx->r2 == 0) {
        // 0x80800698: lw          $a1, 0x20($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X20);
            goto L_808006C4;
    }
    goto skip_20;
    // 0x80800698: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    skip_20:
    // 0x8080069C: lw          $v0, 0x244($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X244);
    // 0x808006A0: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x808006A4: sh          $t0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r8;
    // 0x808006A8: beq         $v0, $zero, L_808006C0
    if (ctx->r2 == 0) {
        // 0x808006AC: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_808006C0;
    }
    // 0x808006AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808006B0: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    // 0x808006B4: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    // 0x808006B8: jalr        $v0
    // 0x808006BC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_41;
    // 0x808006BC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_41:
L_808006C0:
    // 0x808006C0: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
L_808006C4:
    // 0x808006C4: b           L_80800720
    // 0x808006C8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80800720;
    // 0x808006C8: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_808006CC:
    // 0x808006CC: jal         0x808019D0
    // 0x808006D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808019D0_gcnewoption(rdram, ctx);
        goto after_42;
    // 0x808006D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_42:
    // 0x808006D4: jal         0x80802534
    // 0x808006D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80802534_gcnewoption(rdram, ctx);
        goto after_43;
    // 0x808006D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_43:
    // 0x808006DC: beq         $v0, $zero, L_80800714
    if (ctx->r2 == 0) {
        // 0x808006E0: addiu       $t1, $zero, 0x5
        ctx->r9 = ADD32(0, 0X5);
            goto L_80800714;
    }
    // 0x808006E0: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x808006E4: sh          $t1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r9;
    // 0x808006E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006EC: jal         0x80802B24
    // 0x808006F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802B24_gcnewoption(rdram, ctx);
        goto after_44;
    // 0x808006F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_44:
    // 0x808006F4: lw          $v0, 0x244($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X244);
    // 0x808006F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808006FC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80800700: beql        $v0, $zero, L_80800718
    if (ctx->r2 == 0) {
        // 0x80800704: lw          $a1, 0x20($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X20);
            goto L_80800718;
    }
    goto skip_21;
    // 0x80800704: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    skip_21:
    // 0x80800708: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    // 0x8080070C: jalr        $v0
    // 0x80800710: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_45;
    // 0x80800710: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    after_45:
L_80800714:
    // 0x80800714: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
L_80800718:
    // 0x80800718: b           L_80800720
    // 0x8080071C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80800720;
    // 0x8080071C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80800720:
    // 0x80800720: beql        $a1, $zero, L_8080077C
    if (ctx->r5 == 0) {
        // 0x80800724: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080077C;
    }
    goto skip_22;
    // 0x80800724: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_22:
    // 0x80800728: lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X0);
    // 0x8080072C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800730: lbu         $t2, 0x67($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X67);
    // 0x80800734: beq         $s0, $v0, L_8080074C
    if (ctx->r16 == ctx->r2) {
        // 0x80800738: nop
    
            goto L_8080074C;
    }
    // 0x80800738: nop

    // 0x8080073C: beq         $v0, $at, L_8080074C
    if (ctx->r2 == ctx->r1) {
        // 0x80800740: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8080074C;
    }
    // 0x80800740: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800744: bnel        $v0, $at, L_8080077C
    if (ctx->r2 != ctx->r1) {
        // 0x80800748: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080077C;
    }
    goto skip_23;
    // 0x80800748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_23:
L_8080074C:
    // 0x8080074C: beql        $s0, $t2, L_8080077C
    if (ctx->r16 == ctx->r10) {
        // 0x80800750: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080077C;
    }
    goto skip_24;
    // 0x80800750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_24:
    // 0x80800754: lbu         $t3, 0x24($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X24);
    // 0x80800758: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080075C: bnel        $s0, $t3, L_8080077C
    if (ctx->r16 != ctx->r11) {
        // 0x80800760: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080077C;
    }
    goto skip_25;
    // 0x80800760: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_25:
    // 0x80800764: lw          $t9, 0x244($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X244);
    // 0x80800768: lw          $a0, 0x24C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24C);
    // 0x8080076C: lh          $a2, 0x6($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X6);
    // 0x80800770: jalr        $t9
    // 0x80800774: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_46;
    // 0x80800774: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_46:
    // 0x80800778: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080077C:
    // 0x8080077C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800780: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800784: jr          $ra
    // 0x80800788: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800788: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8080000C_chfactorygoblin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x8008A0F8
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sucoaster_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: jal         0x8010A3E8
    // 0x80800028: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_8010A3E8(rdram, ctx);
        goto after_1;
    // 0x80800028: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
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
RECOMP_FUNC void _badeathmatch_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085520: syscall     165
    recomp_syscall_handler(rdram, ctx, 0x80085520);
    return;
    // 0x80085524: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chcoderoombits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1172, 0X1170) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1170
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1172, 0X1170));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1170
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1172, 0X1170));
;}
RECOMP_FUNC void _chtemplebrokendoorpiece_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086FD0: syscall     489
    recomp_syscall_handler(rdram, ctx, 0x80086FD0);
    return;
    // 0x80086FD4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800BDC_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BDC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800BE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800BE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800BEC: jal         0x8008CABC
    // 0x80800BF0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800BF0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80800BF4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800BF8: jal         0x8080032C
    // 0x80800BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080032C_bsvan(rdram, ctx);
        goto after_1;
    // 0x80800BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800C00: jal         0x80800000
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsvan(rdram, ctx);
        goto after_2;
    // 0x80800C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C0C: jal         0x8009BB24
    // 0x80800C10: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_3;
    // 0x80800C10: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80800C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C18: jal         0x80091A30
    // 0x80800C1C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_4;
    // 0x80800C1C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x80800C20: beq         $v0, $zero, L_80800C48
    if (ctx->r2 == 0) {
        // 0x80800C24: lwc1        $f6, 0x28($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800C48;
    }
    // 0x80800C24: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800C28: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800C2C: nop

    // 0x80800C30: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800C34: nop

    // 0x80800C38: bc1fl       L_80800C4C
    if (!c1cs) {
        // 0x80800C3C: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_80800C4C;
    }
    goto skip_0;
    // 0x80800C3C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_0:
    // 0x80800C40: jal         0x8009BC6C
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_5;
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80800C48:
    // 0x80800C48: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
L_80800C4C:
    // 0x80800C4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C54: beq         $v0, $zero, L_80800C84
    if (ctx->r2 == 0) {
        // 0x80800C58: nop
    
            goto L_80800C84;
    }
    // 0x80800C58: nop

    // 0x80800C5C: beq         $v0, $at, L_80800CDC
    if (ctx->r2 == ctx->r1) {
        // 0x80800C60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CDC;
    }
    // 0x80800C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C68: beq         $v0, $at, L_80800D04
    if (ctx->r2 == ctx->r1) {
        // 0x80800C6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D04;
    }
    // 0x80800C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C70: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800C74: beq         $v0, $at, L_80800D40
    if (ctx->r2 == ctx->r1) {
        // 0x80800C78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D40;
    }
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C7C: b           L_80800DA8
    // 0x80800C80: nop

        goto L_80800DA8;
    // 0x80800C80: nop

L_80800C84:
    // 0x80800C84: jal         0x8008DF8C
    // 0x80800C88: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_6;
    // 0x80800C88: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_6:
    // 0x80800C8C: beq         $v0, $zero, L_80800CB0
    if (ctx->r2 == 0) {
        // 0x80800C90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CB0;
    }
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C94: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800C98: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800C9C: jal         0x8008CF1C
    // 0x80800CA0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_7;
    // 0x80800CA0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_7:
    // 0x80800CA4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800CA8: b           L_80800DA8
    // 0x80800CAC: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80800DA8;
    // 0x80800CAC: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800CB0:
    // 0x80800CB0: jal         0x8008B324
    // 0x80800CB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_8;
    // 0x80800CB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x80800CB8: beq         $v0, $zero, L_80800DA8
    if (ctx->r2 == 0) {
        // 0x80800CBC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DA8;
    }
    // 0x80800CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CC0: lui         $a1, 0x3F30
    ctx->r5 = S32(0X3F30 << 16);
    // 0x80800CC4: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x80800CC8: jal         0x8008CF1C
    // 0x80800CCC: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_9;
    // 0x80800CCC: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_9:
    // 0x80800CD0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800CD4: b           L_80800DA8
    // 0x80800CD8: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_80800DA8;
    // 0x80800CD8: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80800CDC:
    // 0x80800CDC: jal         0x8008DF8C
    // 0x80800CE0: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_10;
    // 0x80800CE0: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_10:
    // 0x80800CE4: beq         $v0, $zero, L_80800DA8
    if (ctx->r2 == 0) {
        // 0x80800CE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DA8;
    }
    // 0x80800CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CEC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800CF0: jal         0x8008CF1C
    // 0x80800CF4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_11;
    // 0x80800CF4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_11:
    // 0x80800CF8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80800CFC: b           L_80800DA8
    // 0x80800D00: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
        goto L_80800DA8;
    // 0x80800D00: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_80800D04:
    // 0x80800D04: jal         0x8009D3A8
    // 0x80800D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_12;
    // 0x80800D08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800D0C: jal         0x8008E078
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_13;
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800D14: beq         $v0, $zero, L_80800DA8
    if (ctx->r2 == 0) {
        // 0x80800D18: nop
    
            goto L_80800DA8;
    }
    // 0x80800D18: nop

    // 0x80800D1C: jal         0x800A2EAC
    // 0x80800D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2EAC(rdram, ctx);
        goto after_14;
    // 0x80800D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D28: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800D2C: jal         0x8008CF1C
    // 0x80800D30: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_15;
    // 0x80800D30: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_15:
    // 0x80800D34: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80800D38: b           L_80800DA8
    // 0x80800D3C: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
        goto L_80800DA8;
    // 0x80800D3C: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
L_80800D40:
    // 0x80800D40: jal         0x8009D2D8
    // 0x80800D44: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_16;
    // 0x80800D44: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_16:
    // 0x80800D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D4C: jal         0x8009D3A8
    // 0x80800D50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_17;
    // 0x80800D50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800D54: jal         0x8009BB5C
    // 0x80800D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_18;
    // 0x80800D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800D5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800D60: addiu       $t0, $zero, 0x116
    ctx->r8 = ADD32(0, 0X116);
    // 0x80800D64: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800D68: nop

    // 0x80800D6C: bc1f        L_80800D7C
    if (!c1cs) {
        // 0x80800D70: nop
    
            goto L_80800D7C;
    }
    // 0x80800D70: nop

    // 0x80800D74: b           L_80800D90
    // 0x80800D78: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
        goto L_80800D90;
    // 0x80800D78: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_80800D7C:
    // 0x80800D7C: jal         0x8008B324
    // 0x80800D80: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_19;
    // 0x80800D80: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_19:
    // 0x80800D84: beq         $v0, $zero, L_80800D90
    if (ctx->r2 == 0) {
        // 0x80800D88: addiu       $t1, $zero, 0x11A
        ctx->r9 = ADD32(0, 0X11A);
            goto L_80800D90;
    }
    // 0x80800D88: addiu       $t1, $zero, 0x11A
    ctx->r9 = ADD32(0, 0X11A);
    // 0x80800D8C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_80800D90:
    // 0x80800D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D94: jal         0x80091A58
    // 0x80800D98: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_20;
    // 0x80800D98: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_20:
    // 0x80800D9C: beq         $v0, $zero, L_80800DA8
    if (ctx->r2 == 0) {
        // 0x80800DA0: addiu       $t2, $zero, 0x115
        ctx->r10 = ADD32(0, 0X115);
            goto L_80800DA8;
    }
    // 0x80800DA0: addiu       $t2, $zero, 0x115
    ctx->r10 = ADD32(0, 0X115);
    // 0x80800DA4: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80800DA8:
    // 0x80800DA8: jal         0x8009BB50
    // 0x80800DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_21;
    // 0x80800DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800DB0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800DB4: nop

    // 0x80800DB8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800DBC: nop

    // 0x80800DC0: bc1f        L_80800DDC
    if (!c1cs) {
        // 0x80800DC4: nop
    
            goto L_80800DDC;
    }
    // 0x80800DC4: nop

    // 0x80800DC8: jal         0x8008E35C
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_22;
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800DD0: beq         $v0, $zero, L_80800DDC
    if (ctx->r2 == 0) {
        // 0x80800DD4: addiu       $t3, $zero, 0x11D
        ctx->r11 = ADD32(0, 0X11D);
            goto L_80800DDC;
    }
    // 0x80800DD4: addiu       $t3, $zero, 0x11D
    ctx->r11 = ADD32(0, 0X11D);
    // 0x80800DD8: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80800DDC:
    // 0x80800DDC: jal         0x808000BC
    // 0x80800DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000BC_bsvan(rdram, ctx);
        goto after_23;
    // 0x80800DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800DE4: jal         0x808003BC
    // 0x80800DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsvan_entrypoint_3(rdram, ctx);
        goto after_24;
    // 0x80800DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DF0: jal         0x8009E5C8
    // 0x80800DF4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_25;
    // 0x80800DF4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_25:
    // 0x80800DF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800E04: jr          $ra
    // 0x80800E08: nop

    return;
    // 0x80800E08: nop

;}
