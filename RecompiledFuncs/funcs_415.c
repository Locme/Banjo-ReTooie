#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800260_chgruntyfireball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800264: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800268: sw          $s7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r23;
    // 0x8080026C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80800270: sw          $s6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r22;
    // 0x80800274: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x80800278: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x8080027C: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80800280: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80800284: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80800288: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8080028C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800290: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800294: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800298: jal         0x8010A570
    // 0x8080029C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_8010A570(rdram, ctx);
        goto after_0;
    // 0x8080029C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x808002A0: addiu       $s4, $s7, 0x4
    ctx->r20 = ADD32(ctx->r23, 0X4);
    // 0x808002A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1488, 0X514) << 16);
    // 0x808002A8: addiu       $a2, $a2, 0x514
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1488, 0X514));
    // 0x808002AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808002B0: jal         0x80089D18
    // 0x808002B4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808002B4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x808002B8: addiu       $s6, $sp, 0x7C
    ctx->r22 = ADD32(ctx->r29, 0X7C);
    // 0x808002BC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808002C0: jal         0x800EE7F8
    // 0x808002C4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808002C4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x808002C8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x808002CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002D0: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x808002D4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x808002D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808002DC: jal         0x800B53A4
    // 0x808002E0: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    func_800B53A4(rdram, ctx);
        goto after_3;
    // 0x808002E0: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x808002E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002E8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808002EC: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x808002F0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808002F4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808002F8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808002FC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800300: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1488, 0X524) << 16);
    // 0x80800304: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800308: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8080030C: addiu       $s2, $s2, 0x524
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1488, 0X524));
    // 0x80800310: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800314: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x80800318: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x8080031C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_80800320:
    // 0x80800320: jal         0x800DC178
    // 0x80800324: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800324: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_4:
    // 0x80800328: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x8080032C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800334: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800338: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x8080033C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800340: jal         0x800EEB9C
    // 0x80800344: nop

    func_800EEB9C(rdram, ctx);
        goto after_5;
    // 0x80800344: nop

    after_5:
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080034C: jal         0x800EF04C
    // 0x80800350: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x80800350: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x80800354: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800358: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080035C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800360: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800364: jal         0x800BABB8
    // 0x80800368: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80800368: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_7:
    // 0x8080036C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800370: bnel        $s1, $s3, L_80800320
    if (ctx->r17 != ctx->r19) {
        // 0x80800374: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_80800320;
    }
    goto skip_0;
    // 0x80800374: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_0:
    // 0x80800378: lw          $a0, 0x24($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X24);
    // 0x8080037C: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80800380: beq         $a0, $zero, L_80800394
    if (ctx->r4 == 0) {
        // 0x80800384: nop
    
            goto L_80800394;
    }
    // 0x80800384: nop

    // 0x80800388: jal         0x800863E8
    // 0x8080038C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x8080038C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x80800390: sw          $v0, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->r2;
L_80800394:
    // 0x80800394: jal         0x800FFAB0
    // 0x80800398: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x80800398: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_9:
    // 0x8080039C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x808003A0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808003A4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808003A8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808003AC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808003B0: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x808003B4: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x808003B8: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x808003BC: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x808003C0: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x808003C4: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x808003C8: lw          $s6, 0x54($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X54);
    // 0x808003CC: lw          $s7, 0x58($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X58);
    // 0x808003D0: jr          $ra
    // 0x808003D4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x808003D4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800F4BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4BE4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4BEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4BF4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4BF8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F4BFC: jal         0x8009E674
    // 0x800F4C00: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x800F4C00: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    after_0:
    // 0x800F4C04: beq         $v0, $zero, L_800F4C14
    if (ctx->r2 == 0) {
        // 0x800F4C08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F4C14;
    }
    // 0x800F4C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4C0C: b           L_800F4C18
    // 0x800F4C10: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800F4C18;
    // 0x800F4C10: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800F4C14:
    // 0x800F4C14: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800F4C18:
    // 0x800F4C18: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800F4C1C: jr          $ra
    // 0x800F4C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F4C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8080100C_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080100C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801014: jal         0x80800F1C
    // 0x80801018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800F1C_bswasher(rdram, ctx);
        goto after_0;
    // 0x80801018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080101C: jal         0x808000F0
    // 0x80801020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000F0_bswasher(rdram, ctx);
        goto after_1;
    // 0x80801020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080102C: jr          $ra
    // 0x80801030: nop

    return;
    // 0x80801030: nop

;}
RECOMP_FUNC void chboggyfish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2076, 0X220) << 16);
    // 0x808001FC: jr          $ra
    // 0x80800200: addiu       $v0, $v0, 0x220
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2076, 0X220));
    return;
    // 0x80800200: addiu       $v0, $v0, 0x220
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2076, 0X220));
    // 0x80800204: nop

    // 0x80800208: nop

    // 0x8080020C: nop

;}
RECOMP_FUNC void bafly_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080078C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800790: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800794: lw          $t6, 0x8C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8C);
    // 0x80800798: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080079C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808007A0: lbu         $t7, 0xE($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XE);
    // 0x808007A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808007A8: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x808007AC: beq         $t7, $zero, L_808007BC
    if (ctx->r15 == 0) {
        // 0x808007B0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_808007BC;
    }
    // 0x808007B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808007B4: b           L_808007C8
    // 0x808007B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808007C8;
    // 0x808007B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007BC:
    // 0x808007BC: jal         0x8008A690
    // 0x808007C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    _suinv_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808007C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x808007C4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_808007C8:
    // 0x808007C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007D0: jr          $ra
    // 0x808007D4: nop

    return;
    // 0x808007D4: nop

;}
RECOMP_FUNC void _bswasher_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800843E0: syscall     109
    recomp_syscall_handler(rdram, ctx, 0x800843E0);
    return;
    // 0x800843E4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8080022C_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080022C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800230: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800234: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080023C: jal         0x800F3E84
    // 0x80800240: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F3E84(rdram, ctx);
        goto after_0;
    // 0x80800240: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800244: jal         0x8009BFCC
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFCC(rdram, ctx);
        goto after_1;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080024C: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: jal         0x8009C990
    // 0x80800258: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    yaw_getIdeal(rdram, ctx);
        goto after_2;
    // 0x80800258: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8080025C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800260: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800268: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8080026C: jal         0x8009C53C
    // 0x80800270: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    baroll_get(rdram, ctx);
        goto after_3;
    // 0x80800270: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80800274: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x800A4CA8
    // 0x80800280: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    func_800A4CA8(rdram, ctx);
        goto after_4;
    // 0x80800280: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80800284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800288: jal         0x80089400
    // 0x8080028C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _ncba1p_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x8080028C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x80800290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800294: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800298: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080029C: jr          $ra
    // 0x808002A0: nop

    return;
    // 0x808002A0: nop

;}
RECOMP_FUNC void fxegg_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800208: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080020C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800210: jal         0x800B5BE4
    // 0x80800214: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800214: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_0:
    // 0x80800218: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080021C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800220: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800224: jal         0x808001CC
    // 0x80800228: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_808001CC_fxegg(rdram, ctx);
        goto after_1;
    // 0x80800228: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8080022C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800230: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800234: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800238: jr          $ra
    // 0x8080023C: nop

    return;
    // 0x8080023C: nop

;}
RECOMP_FUNC void _gsworldDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B78: syscall     726
    recomp_syscall_handler(rdram, ctx, 0x80088B78);
    return;
    // 0x80088B7C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808002DC_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002E4: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x808002E8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808002EC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x808002F0: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808002F4: bgez        $t8, L_80800340
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808002F8: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_80800340;
    }
    // 0x808002F8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808002FC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800300: jal         0x8008A0E0
    // 0x80800304: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800304: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800308: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1776, 0X178C) << 16);
    // 0x8080030C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1776, 0X1858) << 16);
    // 0x80800310: addiu       $a3, $a3, 0x1858
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1776, 0X1858));
    // 0x80800314: addiu       $a2, $a2, 0x178C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1776, 0X178C));
    // 0x80800318: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080031C: jal         0x80089D28
    // 0x80800320: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800320: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800324: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1776, 0X179C) << 16);
    // 0x80800328: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1776, 0X1864) << 16);
    // 0x8080032C: addiu       $a3, $a3, 0x1864
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1776, 0X1864));
    // 0x80800330: addiu       $a2, $a2, 0x179C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1776, 0X179C));
    // 0x80800334: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800338: jal         0x80089D28
    // 0x8080033C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x8080033C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
L_80800340:
    // 0x80800340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800344: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800348: jr          $ra
    // 0x8080034C: nop

    return;
    // 0x8080034C: nop

;}
RECOMP_FUNC void func_801098D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801098D0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801098D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801098D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801098DC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x801098E0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x801098E4: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    // 0x801098E8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x801098EC: beql        $v0, $zero, L_80109968
    if (ctx->r2 == 0) {
        // 0x801098F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80109968;
    }
    goto skip_0;
    // 0x801098F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x801098F4: jalr        $v0
    // 0x801098F8: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x801098F8: nop

    after_0:
    // 0x801098FC: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80109900: beql        $t6, $zero, L_80109968
    if (ctx->r14 == 0) {
        // 0x80109904: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80109968;
    }
    goto skip_1;
    // 0x80109904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80109908: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    // 0x8010990C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80109910: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80109914: sll         $t8, $t7, 27
    ctx->r24 = S32(ctx->r15 << 27);
    // 0x80109918: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x8010991C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80109920: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80109924: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80109928: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x8010992C: jalr        $t9
    // 0x80109930: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80109930: nop

    after_1:
    // 0x80109934: beq         $v0, $zero, L_8010995C
    if (ctx->r2 == 0) {
        // 0x80109938: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_8010995C;
    }
    // 0x80109938: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8010993C: lbu         $t3, 0x19($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X19);
    // 0x80109940: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80109944: andi        $t2, $t1, 0x1E
    ctx->r10 = ctx->r9 & 0X1E;
    // 0x80109948: andi        $t4, $t3, 0xFFE1
    ctx->r12 = ctx->r11 & 0XFFE1;
    // 0x8010994C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80109950: sb          $t5, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r13;
    // 0x80109954: b           L_801099BC
    // 0x80109958: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801099BC;
    // 0x80109958: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010995C:
    // 0x8010995C: b           L_801099BC
    // 0x80109960: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801099BC;
    // 0x80109960: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80109964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80109968:
    // 0x80109968: jal         0x800EC75C
    // 0x8010996C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EC75C(rdram, ctx);
        goto after_2;
    // 0x8010996C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x80109970: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80109974: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
    // 0x80109978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010997C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80109980: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80109984: jal         0x800EF3DC
    // 0x80109988: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    func_800EF3DC(rdram, ctx);
        goto after_3;
    // 0x80109988: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8010998C: jal         0x800EEFD4
    // 0x80109990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEFD4(rdram, ctx);
        goto after_4;
    // 0x80109990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80109994: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80109998: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010999C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801099A0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x801099A4: nop

    // 0x801099A8: bc1f        L_801099B8
    if (!c1cs) {
        // 0x801099AC: nop
    
            goto L_801099B8;
    }
    // 0x801099AC: nop

    // 0x801099B0: b           L_801099B8
    // 0x801099B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801099B8;
    // 0x801099B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801099B8:
    // 0x801099B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_801099BC:
    // 0x801099BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801099C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801099C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x801099C8: jr          $ra
    // 0x801099CC: nop

    return;
    // 0x801099CC: nop

;}
RECOMP_FUNC void surestart_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800EA05C
    // 0x8080000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800014: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800018: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(3362, 0XD0) << 16);
    // 0x8080001C: bne         $a2, $at, L_80800034
    if (ctx->r6 != ctx->r1) {
        // 0x80800020: addiu       $v1, $v1, 0xD0
        ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(3362, 0XD0));
            goto L_80800034;
    }
    // 0x80800020: addiu       $v1, $v1, 0xD0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(3362, 0XD0));
    // 0x80800024: jal         0x8009EBD0
    // 0x80800028: nop

    func_8009EBD0(rdram, ctx);
        goto after_1;
    // 0x80800028: nop

    after_1:
    // 0x8080002C: b           L_808000C4
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000C4;
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800034:
    // 0x80800034: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3362, 0X148) << 16);
    // 0x80800038: addiu       $a1, $a1, 0x148
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3362, 0X148));
    // 0x8080003C: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
L_80800040:
    // 0x80800040: bnel        $a2, $t6, L_808000B8
    if (ctx->r6 != ctx->r14) {
        // 0x80800044: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_808000B8;
    }
    goto skip_0;
    // 0x80800044: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    skip_0:
    // 0x80800048: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x8080004C: beql        $a0, $zero, L_8080005C
    if (ctx->r4 == 0) {
        // 0x80800050: addiu       $at, $zero, 0x13E
        ctx->r1 = ADD32(0, 0X13E);
            goto L_8080005C;
    }
    goto skip_1;
    // 0x80800050: addiu       $at, $zero, 0x13E
    ctx->r1 = ADD32(0, 0X13E);
    skip_1:
    // 0x80800054: bne         $v0, $a0, L_808000B4
    if (ctx->r2 != ctx->r4) {
        // 0x80800058: addiu       $at, $zero, 0x13E
        ctx->r1 = ADD32(0, 0X13E);
            goto L_808000B4;
    }
    // 0x80800058: addiu       $at, $zero, 0x13E
    ctx->r1 = ADD32(0, 0X13E);
L_8080005C:
    // 0x8080005C: lh          $a3, 0x0($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X0);
    // 0x80800060: beq         $a0, $at, L_80800070
    if (ctx->r4 == ctx->r1) {
        // 0x80800064: lbu         $a2, 0x5($v1)
        ctx->r6 = MEM_BU(ctx->r3, 0X5);
            goto L_80800070;
    }
    // 0x80800064: lbu         $a2, 0x5($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X5);
    // 0x80800068: addiu       $at, $zero, 0x13F
    ctx->r1 = ADD32(0, 0X13F);
    // 0x8080006C: bne         $a0, $at, L_80800090
    if (ctx->r4 != ctx->r1) {
        // 0x80800070: addiu       $a0, $zero, 0x40A
        ctx->r4 = ADD32(0, 0X40A);
            goto L_80800090;
    }
L_80800070:
    // 0x80800070: addiu       $a0, $zero, 0x40A
    ctx->r4 = ADD32(0, 0X40A);
    // 0x80800074: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800078: jal         0x800DA298
    // 0x8080007C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080007C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x80800080: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: bne         $v0, $zero, L_80800090
    if (ctx->r2 != 0) {
        // 0x80800088: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_80800090;
    }
    // 0x80800088: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8080008C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
L_80800090:
    // 0x80800090: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x80800094: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x80800098: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8080009C: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x808000A0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x808000A4: jal         0x8009EB24
    // 0x808000A8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_8009EB24(rdram, ctx);
        goto after_3;
    // 0x808000A8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_3:
    // 0x808000AC: b           L_808000C4
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000C4;
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000B4:
    // 0x808000B4: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
L_808000B8:
    // 0x808000B8: bnel        $v1, $a1, L_80800040
    if (ctx->r3 != ctx->r5) {
        // 0x808000BC: lbu         $t6, 0x4($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X4);
            goto L_80800040;
    }
    goto skip_2;
    // 0x808000BC: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    skip_2:
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000C4:
    // 0x808000C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void func_80800250_chchompaslunch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800250: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800254: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800258: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080025C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800260: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800264: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800268: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080026C: lbu         $t6, 0x5F($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5F);
    // 0x80800270: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800274: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    // 0x80800278: bne         $t6, $zero, L_80800290
    if (ctx->r14 != 0) {
        // 0x8080027C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800290;
    }
    // 0x8080027C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800280: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1548, 0X498) << 16);
    // 0x80800284: jal         0x800C4350
    // 0x80800288: addiu       $a2, $a2, 0x498
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1548, 0X498));
    func_800C4350(rdram, ctx);
        goto after_0;
    // 0x80800288: addiu       $a2, $a2, 0x498
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1548, 0X498));
    after_0:
    // 0x8080028C: sb          $v0, 0x5F($s4)
    MEM_B(0X5F, ctx->r20) = ctx->r2;
L_80800290:
    // 0x80800290: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1548, 0X468) << 16);
    // 0x80800294: addiu       $s1, $s1, 0x468
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1548, 0X468));
    // 0x80800298: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080029C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808002A0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_808002A4:
    // 0x808002A4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808002A8: jal         0x80101E14
    // 0x808002AC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x808002AC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x808002B0: beq         $v0, $zero, L_80800328
    if (ctx->r2 == 0) {
        // 0x808002B4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800328;
    }
    // 0x808002B4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808002B8: sll         $s1, $s0, 1
    ctx->r17 = S32(ctx->r16 << 1);
    // 0x808002BC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1548, 0X488) << 16);
    // 0x808002C0: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x808002C4: lh          $a1, 0x488($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1548, 0X488));
    // 0x808002C8: jal         0x800C301C
    // 0x808002CC: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    func_800C301C(rdram, ctx);
        goto after_2;
    // 0x808002CC: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    after_2:
    // 0x808002D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1548, 0X3B0) << 16);
    // 0x808002D4: lwc1        $f12, 0x3B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1548, 0X3B0));
    // 0x808002D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1548, 0X3B4) << 16);
    // 0x808002DC: jal         0x800DC178
    // 0x808002E0: lwc1        $f14, 0x3B4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1548, 0X3B4));
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808002E0: lwc1        $f14, 0x3B4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1548, 0X3B4));
    after_3:
    // 0x808002E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1548, 0X478) << 16);
    // 0x808002E8: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x808002EC: lwc1        $f4, 0x478($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1548, 0X478));
    // 0x808002F0: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    // 0x808002F4: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808002F8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808002FC: jal         0x800C31DC
    // 0x80800300: nop

    func_800C31DC(rdram, ctx);
        goto after_4;
    // 0x80800300: nop

    after_4:
    // 0x80800304: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1548, 0X490) << 16);
    // 0x80800308: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x8080030C: lh          $a1, 0x490($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1548, 0X490));
    // 0x80800310: jal         0x800C3058
    // 0x80800314: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    func_800C3058(rdram, ctx);
        goto after_5;
    // 0x80800314: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    after_5:
    // 0x80800318: jal         0x800C3BDC
    // 0x8080031C: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    func_800C3BDC(rdram, ctx);
        goto after_6;
    // 0x8080031C: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    after_6:
    // 0x80800320: b           L_80800338
    // 0x80800324: lw          $t7, 0x6C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X6C);
        goto L_80800338;
    // 0x80800324: lw          $t7, 0x6C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X6C);
L_80800328:
    // 0x80800328: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080032C: bne         $s0, $s3, L_808002A4
    if (ctx->r16 != ctx->r19) {
        // 0x80800330: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_808002A4;
    }
    // 0x80800330: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800334: lw          $t7, 0x6C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X6C);
L_80800338:
    // 0x80800338: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080033C: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    // 0x80800340: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80800344: bne         $t8, $zero, L_8080035C
    if (ctx->r24 != 0) {
        // 0x80800348: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1548, 0X44C) << 16);
            goto L_8080035C;
    }
    // 0x80800348: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1548, 0X44C) << 16);
    // 0x8080034C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1548, 0X458) << 16);
    // 0x80800350: addiu       $a3, $a3, 0x458
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1548, 0X458));
    // 0x80800354: jal         0x80089D28
    // 0x80800358: addiu       $a2, $a2, 0x44C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1548, 0X44C));
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800358: addiu       $a2, $a2, 0x44C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1548, 0X44C));
    after_7:
L_8080035C:
    // 0x8080035C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800360: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800364: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800368: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080036C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800370: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800374: jr          $ra
    // 0x80800378: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800378: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800EBFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBFF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EBFF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EBFFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EC000: jal         0x800BDB9C
    // 0x800EC004: lh          $a0, 0x1C($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1C);
    func_800BDB9C(rdram, ctx);
        goto after_0;
    // 0x800EC004: lh          $a0, 0x1C($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X1C);
    after_0:
    // 0x800EC008: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800EC00C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800EC010: jal         0x800E9AC0
    // 0x800EC014: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    func_800E9AC0(rdram, ctx);
        goto after_1;
    // 0x800EC014: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x800EC018: jal         0x800EBE24
    // 0x800EC01C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800EBE24(rdram, ctx);
        goto after_2;
    // 0x800EC01C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800EC020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EC024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EC028: jr          $ra
    // 0x800EC02C: nop

    return;
    // 0x800EC02C: nop

;}
RECOMP_FUNC void _bsdronejump_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083100: syscall     44
    recomp_syscall_handler(rdram, ctx, 0x80083100);
    return;
    // 0x80083104: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808002CC_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002D0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808002D4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808002D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002DC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808002E0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808002E4: jal         0x800EE7F8
    // 0x808002E8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808002E8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002EC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808002F0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808002F4: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    // 0x808002F8: jal         0x800EF1B8
    // 0x808002FC: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808002FC: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    after_1:
    // 0x80800300: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800304: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800308: jal         0x80086670
    // 0x8080030C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080030C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_2:
    // 0x80800310: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1052, 0X7D0) << 16);
    // 0x80800314: addiu       $t7, $t7, 0x7D0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1052, 0X7D0));
    // 0x80800318: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8080031C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800320: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800324: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800328: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8080032C: jal         0x800BBCB8
    // 0x80800330: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x80800330: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_3:
    // 0x80800334: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1052, 0X9B4) << 16);
    // 0x80800338: addiu       $a2, $a2, 0x9B4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1052, 0X9B4));
    // 0x8080033C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800340: jal         0x80089D18
    // 0x80800344: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800344: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800348: jal         0x800DA544
    // 0x8080034C: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x8080034C: addiu       $a0, $zero, 0xCE
    ctx->r4 = ADD32(0, 0XCE);
    after_5:
    // 0x80800350: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800354: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800358: jr          $ra
    // 0x8080035C: nop

    return;
    // 0x8080035C: nop

;}
RECOMP_FUNC void func_800DFCC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFCC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DFCC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DFCC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DFCCC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800DFCD0: jal         0x8001B754
    // 0x800DFCD4: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B754(rdram, ctx);
        goto after_0;
    // 0x800DFCD4: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x800DFCD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DFCDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DFCE0: jr          $ra
    // 0x800DFCE4: nop

    return;
    // 0x800DFCE4: nop

;}
RECOMP_FUNC void func_808003C8_chpufferfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808003D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003D8: beq         $a1, $v0, L_808004A8
    if (ctx->r5 == ctx->r2) {
        // 0x808003DC: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_808004A8;
    }
    // 0x808003DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003E0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x808003E4: beq         $a1, $v1, L_808004E8
    if (ctx->r5 == ctx->r3) {
        // 0x808003E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E8;
    }
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003EC: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x808003F0: beq         $a1, $at, L_80800414
    if (ctx->r5 == ctx->r1) {
        // 0x808003F4: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80800414;
    }
    // 0x808003F4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808003F8: beq         $a1, $at, L_8080045C
    if (ctx->r5 == ctx->r1) {
        // 0x808003FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080045C;
    }
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800400: addiu       $at, $zero, 0x8F
    ctx->r1 = ADD32(0, 0X8F);
    // 0x80800404: beq         $a1, $at, L_8080046C
    if (ctx->r5 == ctx->r1) {
        // 0x80800408: nop
    
            goto L_8080046C;
    }
    // 0x80800408: nop

    // 0x8080040C: b           L_80800504
    // 0x80800410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800504;
    // 0x80800410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800414:
    // 0x80800414: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x80800418: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x8080041C: srl         $t6, $a1, 26
    ctx->r14 = S32(U32(ctx->r5) >> 26);
    // 0x80800420: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x80800424: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80800428: jal         0x800CC63C
    // 0x8080042C: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_0;
    // 0x8080042C: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    after_0:
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800434: jal         0x80102D78
    // 0x80800438: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x80800438: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8080043C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800440: jal         0x80102924
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102924(rdram, ctx);
        goto after_2;
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080044C: jal         0x80800274
    // 0x80800450: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800274_chpufferfish(rdram, ctx);
        goto after_3;
    // 0x80800450: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800454: b           L_80800504
    // 0x80800458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800504;
    // 0x80800458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080045C:
    // 0x8080045C: jal         0x80800274
    // 0x80800460: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800274_chpufferfish(rdram, ctx);
        goto after_4;
    // 0x80800460: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800464: b           L_80800504
    // 0x80800468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800504;
    // 0x80800468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080046C:
    // 0x8080046C: beq         $a2, $v0, L_8080048C
    if (ctx->r6 == ctx->r2) {
        // 0x80800470: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080048C;
    }
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800474: beq         $a2, $v1, L_808004A0
    if (ctx->r6 == ctx->r3) {
        // 0x80800478: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808004A0;
    }
    // 0x80800478: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080047C: beq         $a2, $at, L_808004A0
    if (ctx->r6 == ctx->r1) {
        // 0x80800480: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808004A0;
    }
    // 0x80800480: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800484: bne         $a2, $at, L_808004A0
    if (ctx->r6 != ctx->r1) {
        // 0x80800488: nop
    
            goto L_808004A0;
    }
    // 0x80800488: nop

L_8080048C:
    // 0x8080048C: jal         0x80800274
    // 0x80800490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800274_chpufferfish(rdram, ctx);
        goto after_5;
    // 0x80800490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: jal         0x8080086C
    // 0x8080049C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080086C_chpufferfish(rdram, ctx);
        goto after_6;
    // 0x8080049C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
L_808004A0:
    // 0x808004A0: b           L_80800504
    // 0x808004A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800504;
    // 0x808004A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004A8:
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004AC: jal         0x80800274
    // 0x808004B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800274_chpufferfish(rdram, ctx);
        goto after_7;
    // 0x808004B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808004B4: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x808004B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808004C4: beql        $v0, $t8, L_808004D8
    if (ctx->r2 == ctx->r24) {
        // 0x808004C8: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_808004D8;
    }
    goto skip_0;
    // 0x808004C8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_0:
    // 0x808004CC: jal         0x8080086C
    // 0x808004D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080086C_chpufferfish(rdram, ctx);
        goto after_8;
    // 0x808004D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x808004D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_808004D8:
    // 0x808004D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808004E0: b           L_80800504
    // 0x808004E4: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
        goto L_80800504;
    // 0x808004E4: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
L_808004E8:
    // 0x808004E8: jal         0x80800274
    // 0x808004EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800274_chpufferfish(rdram, ctx);
        goto after_9;
    // 0x808004EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F4: jal         0x80107070
    // 0x808004F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80107070(rdram, ctx);
        goto after_10;
    // 0x808004F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808004FC: b           L_80800504
    // 0x80800500: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800504;
    // 0x80800500: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800504:
    // 0x80800504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800508: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080050C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800510: jr          $ra
    // 0x80800514: nop

    return;
    // 0x80800514: nop

;}
RECOMP_FUNC void func_8009BCD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BCD4: lw          $v1, 0xC8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BCD8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009BCDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009BCE0: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8009BCE4: lwc1        $f2, 0x10($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8009BCE8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8009BCEC: nop

    // 0x8009BCF0: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8009BCF4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8009BCF8: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8009BCFC: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x8009BD00: nop

    // 0x8009BD04: bc1f        L_8009BD10
    if (!c1cs) {
        // 0x8009BD08: nop
    
            goto L_8009BD10;
    }
    // 0x8009BD08: nop

    // 0x8009BD0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009BD10:
    // 0x8009BD10: jr          $ra
    // 0x8009BD14: nop

    return;
    // 0x8009BD14: nop

;}
RECOMP_FUNC void func_808008B4_idbounce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008BC: jal         0x800F54E4
    // 0x808008C0: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808008C0: nop

    after_0:
    // 0x808008C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808008C8: jal         0x800F6C5C
    // 0x808008CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_1;
    // 0x808008CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808008D0: bne         $v0, $zero, L_808008E0
    if (ctx->r2 != 0) {
        // 0x808008D4: nop
    
            goto L_808008E0;
    }
    // 0x808008D4: nop

    // 0x808008D8: b           L_808008FC
    // 0x808008DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008FC;
    // 0x808008DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008E0:
    // 0x808008E0: jal         0x800F55FC
    // 0x808008E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F55FC(rdram, ctx);
        goto after_2;
    // 0x808008E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808008E8: andi        $t6, $v0, 0x8000
    ctx->r14 = ctx->r2 & 0X8000;
    // 0x808008EC: bne         $t6, $zero, L_808008FC
    if (ctx->r14 != 0) {
        // 0x808008F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808008FC;
    }
    // 0x808008F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808008F4: b           L_808008FC
    // 0x808008F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008FC;
    // 0x808008F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008FC:
    // 0x808008FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800904: jr          $ra
    // 0x80800908: nop

    return;
    // 0x80800908: nop

;}
RECOMP_FUNC void bswasher_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808011A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(443, 0X1E60) << 16);
    // 0x808011A8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808011AC: jr          $ra
    // 0x808011B0: lw          $v0, 0x1E60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E60));
    return;
    // 0x808011B0: lw          $v0, 0x1E60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1E60));
;}
RECOMP_FUNC void _sumumbofx_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898A0: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x800898A0);
    return;
    // 0x800898A4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void sumultiscore_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E98: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80800E9C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80800EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EA4: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80800EA8: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80800EAC: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x80800EB0: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80800EB4: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80800EB8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800EBC: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80800EC0: sll         $t0, $v0, 5
    ctx->r8 = S32(ctx->r2 << 5);
    // 0x80800EC4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80800EC8: lh          $t2, 0x48($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X48);
    // 0x80800ECC: jal         0x80800F18
    // 0x80800ED0: addu        $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
    sumultiscore_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800ED0: addu        $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
    after_0:
    // 0x80800ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800ED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EDC: jr          $ra
    // 0x80800EE0: nop

    return;
    // 0x80800EE0: nop

;}
RECOMP_FUNC void cosectionstor_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080009C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808000A4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x808000A8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x808000AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000B0: addiu       $s1, $s1, 0x75C0
    ctx->r17 = ADD32(ctx->r17, 0X75C0);
    // 0x808000B4: addiu       $s0, $s0, 0x7198
    ctx->r16 = ADD32(ctx->r16, 0X7198);
    // 0x808000B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_808000BC:
    // 0x808000BC: beql        $a0, $zero, L_808000D4
    if (ctx->r4 == 0) {
        // 0x808000C0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808000D4;
    }
    goto skip_0;
    // 0x808000C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x808000C4: jal         0x8001BAFC
    // 0x808000C8: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x808000C8: nop

    after_0:
    // 0x808000CC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x808000D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_808000D4:
    // 0x808000D4: bnel        $s0, $s1, L_808000BC
    if (ctx->r16 != ctx->r17) {
        // 0x808000D8: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_808000BC;
    }
    goto skip_1;
    // 0x808000D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000E8: jr          $ra
    // 0x808000EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808000EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808000C4_chhotwatersteam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808000C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808000CC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808000D0: jr          $ra
    // 0x808000D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808000D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8080040C_chcablespark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080040C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800410: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800414: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800418: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8080041C: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800420: lbu         $t3, 0x65($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X65);
    // 0x80800424: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800428: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x8080042C: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80800430: xori        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 ^ 0X1;
    // 0x80800434: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80800438: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x8080043C: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x80800440: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800444: sb          $t5, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r13;
    // 0x80800448: jal         0x800DF830
    // 0x8080044C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_0;
    // 0x8080044C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800450: jal         0x80800828
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800828_chcablespark(rdram, ctx);
        goto after_1;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800458: beq         $v0, $zero, L_80800468
    if (ctx->r2 == 0) {
        // 0x8080045C: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800468;
    }
    // 0x8080045C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800460: b           L_80800468
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800468;
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800468:
    // 0x80800468: jal         0x800DF744
    // 0x8080046C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x8080046C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x80800470: jal         0x800D674C
    // 0x80800474: addiu       $a0, $zero, 0x6BC
    ctx->r4 = ADD32(0, 0X6BC);
    func_800D674C(rdram, ctx);
        goto after_3;
    // 0x80800474: addiu       $a0, $zero, 0x6BC
    ctx->r4 = ADD32(0, 0X6BC);
    after_3:
    // 0x80800478: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080047C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800480: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800484: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80800488: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x8080048C: jal         0x800DE448
    // 0x80800490: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_4;
    // 0x80800490: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80800494: jal         0x800DF350
    // 0x80800498: nop

    func_800DF350(rdram, ctx);
        goto after_5;
    // 0x80800498: nop

    after_5:
    // 0x8080049C: lbu         $t9, 0x7E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7E);
    // 0x808004A0: lhu         $t3, 0x72($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X72);
    // 0x808004A4: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x808004A8: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x808004AC: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x808004B0: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808004B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808004B8: srl         $t2, $t3, 10
    ctx->r10 = S32(U32(ctx->r11) >> 10);
    // 0x808004BC: bne         $t2, $at, L_8080057C
    if (ctx->r10 != ctx->r1) {
        // 0x808004C0: sb          $t1, 0x7E($s0)
        MEM_B(0X7E, ctx->r16) = ctx->r9;
            goto L_8080057C;
    }
    // 0x808004C0: sb          $t1, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r9;
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C8: jal         0x80800590
    // 0x808004CC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80800590_chcablespark(rdram, ctx);
        goto after_6;
    // 0x808004CC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x808004D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004D4: jal         0x800DC128
    // 0x808004D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_7;
    // 0x808004D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x808004DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808004E0: jal         0x800DF744
    // 0x808004E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DF744(rdram, ctx);
        goto after_8;
    // 0x808004E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x808004E8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x808004EC: addiu       $a0, $a0, 0x15D0
    ctx->r4 = ADD32(ctx->r4, 0X15D0);
    // 0x808004F0: jal         0x800DF47C
    // 0x808004F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_9;
    // 0x808004F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x808004F8: jal         0x8010347C
    // 0x808004FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_10;
    // 0x808004FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x80800500: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800504: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80800508: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080050C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800510: jal         0x800DE448
    // 0x80800514: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_11;
    // 0x80800514: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80800518: jal         0x800E88E4
    // 0x8080051C: lbu         $a0, 0x18($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X18);
    func_800E88E4(rdram, ctx);
        goto after_12;
    // 0x8080051C: lbu         $a0, 0x18($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X18);
    after_12:
    // 0x80800520: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800524: bnel        $v0, $at, L_80800580
    if (ctx->r2 != ctx->r1) {
        // 0x80800528: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800580;
    }
    goto skip_0;
    // 0x80800528: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080052C: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x80800530: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x80800534: bgezl       $t6, L_80800580
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800538: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800580;
    }
    goto skip_1;
    // 0x80800538: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8080053C: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x80800540: sll         $t8, $t7, 19
    ctx->r24 = S32(ctx->r15 << 19);
    // 0x80800544: bgezl       $t8, L_80800580
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800548: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800580;
    }
    goto skip_2;
    // 0x80800548: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8080054C: jal         0x800E3A58
    // 0x80800550: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800E3A58(rdram, ctx);
        goto after_13;
    // 0x80800550: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_13:
    // 0x80800554: jal         0x800DF830
    // 0x80800558: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF830(rdram, ctx);
        goto after_14;
    // 0x80800558: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x8080055C: jal         0x800D674C
    // 0x80800560: addiu       $a0, $zero, 0x6BB
    ctx->r4 = ADD32(0, 0X6BB);
    func_800D674C(rdram, ctx);
        goto after_15;
    // 0x80800560: addiu       $a0, $zero, 0x6BB
    ctx->r4 = ADD32(0, 0X6BB);
    after_15:
    // 0x80800564: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800568: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8080056C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800570: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800574: jal         0x800DE448
    // 0x80800578: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_16;
    // 0x80800578: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_16:
L_8080057C:
    // 0x8080057C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800580:
    // 0x80800580: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800584: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800588: jr          $ra
    // 0x8080058C: nop

    return;
    // 0x8080058C: nop

;}
RECOMP_FUNC void func_808003E0_chgoldsnakehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003E8: addiu       $t6, $zero, 0x41
    ctx->r14 = ADD32(0, 0X41);
    // 0x808003EC: addiu       $t7, $zero, 0x18B
    ctx->r15 = ADD32(0, 0X18B);
    // 0x808003F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808003F4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808003F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800400: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800404: jal         0x80086898
    // 0x80800408: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800408: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_0:
    // 0x8080040C: beq         $v0, $zero, L_80800430
    if (ctx->r2 == 0) {
        // 0x80800410: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800430;
    }
    // 0x80800410: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800414: jal         0x800868C0
    // 0x80800418: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800418: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x8080041C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800420: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800424: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800428: jal         0x800868C8
    // 0x8080042C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x8080042C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
L_80800430:
    // 0x80800430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800438: jr          $ra
    // 0x8080043C: nop

    return;
    // 0x8080043C: nop

;}
RECOMP_FUNC void gcegg_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80800148: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8080014C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80800150: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2678, 0X209) << 16);
    // 0x80800154: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800158: jr          $ra
    // 0x8080015C: lbu         $v0, 0x209($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(2678, 0X209));
    return;
    // 0x8080015C: lbu         $v0, 0x209($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(2678, 0X209));
;}
RECOMP_FUNC void _capod_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085738: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x80085738);
    return;
    // 0x8008573C: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_80081A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081A90: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x80081A94: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80081A98: addu        $v1, $a0, $t7
    ctx->r3 = ADD32(ctx->r4, ctx->r15);
    // 0x80081A9C: jr          $ra
    // 0x80081AA0: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    return;
    // 0x80081AA0: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
;}
RECOMP_FUNC void bsbreegullbash_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080022C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800230: jal         0x8009E474
    // 0x80800234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E474(rdram, ctx);
        goto after_0;
    // 0x80800234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800238: jal         0x808001D4
    // 0x8080023C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808001D4_bsbreegullbash(rdram, ctx);
        goto after_1;
    // 0x8080023C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800240: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800244: jal         0x80095774
    // 0x80800248: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    baflag_clear(rdram, ctx);
        goto after_2;
    // 0x80800248: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_2:
    // 0x8080024C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800254: jr          $ra
    // 0x80800258: nop

    return;
    // 0x80800258: nop

;}
RECOMP_FUNC void func_80800000_chmineentrygrille(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800008: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080000C: beq         $a1, $at, L_80800028
    if (ctx->r5 == ctx->r1) {
        // 0x80800010: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800028;
    }
    // 0x80800010: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800014: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800018: beq         $a1, $at, L_80800044
    if (ctx->r5 == ctx->r1) {
        // 0x8080001C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800044;
    }
    // 0x8080001C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800020: b           L_808000B4
    // 0x80800024: nop

        goto L_808000B4;
    // 0x80800024: nop

L_80800028:
    // 0x80800028: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x8080002C: jal         0x80086670
    // 0x80800030: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800030: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x80800034: jal         0x800DA544
    // 0x80800038: addiu       $a0, $zero, 0x393
    ctx->r4 = ADD32(0, 0X393);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800038: addiu       $a0, $zero, 0x393
    ctx->r4 = ADD32(0, 0X393);
    after_1:
    // 0x8080003C: b           L_808000B4
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000B4;
    // 0x80800040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800044:
    // 0x80800044: jal         0x80101080
    // 0x80800048: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_2;
    // 0x80800048: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_2:
    // 0x8080004C: jal         0x80106790
    // 0x80800050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80800050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800054: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800058: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080005C: jal         0x800866C0
    // 0x80800060: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _chexploder_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800060: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x80800064: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800068: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080006C: jal         0x800866D0
    // 0x80800070: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _chexploder_entrypoint_15(rdram, ctx);
        goto after_5;
    // 0x80800070: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x80800074: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800078: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1996, 0X140) << 16);
    // 0x8080007C: addiu       $t6, $t6, 0x140
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1996, 0X140));
    // 0x80800080: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80800084: lw          $a3, 0x38($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X38);
    // 0x80800088: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080008C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800090: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800094: jal         0x800BABB8
    // 0x80800098: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x80800098: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8080009C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1996, 0X180) << 16);
    // 0x808000A0: addiu       $a1, $a1, 0x180
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1996, 0X180));
    // 0x808000A4: jal         0x800C4AF0
    // 0x808000A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800C4AF0(rdram, ctx);
        goto after_7;
    // 0x808000A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x808000AC: b           L_808000B4
    // 0x808000B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000B4;
    // 0x808000B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000B4:
    // 0x808000B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void func_800FAB50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAB50: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800FAB54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FAB58: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
    // 0x800FAB5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FAB60: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800FAB64: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800FAB68: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800FAB6C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800FAB70: jal         0x800EE7F8
    // 0x800FAB74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800FAB74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800FAB78: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800FAB7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800FAB80: jal         0x800EFB24
    // 0x800FAB84: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x800FAB84: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800FAB88: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800FAB8C: jal         0x800EF368
    // 0x800FAB90: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_800EF368(rdram, ctx);
        goto after_2;
    // 0x800FAB90: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x800FAB94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FAB98: jal         0x800EF04C
    // 0x800FAB9C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x800FAB9C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x800FABA0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800FABA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800FABA8: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800FABAC: jal         0x800C6A7C
    // 0x800FABB0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    func_800C6A7C(rdram, ctx);
        goto after_4;
    // 0x800FABB0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x800FABB4: bne         $v0, $zero, L_800FABC4
    if (ctx->r2 != 0) {
        // 0x800FABB8: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_800FABC4;
    }
    // 0x800FABB8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800FABBC: b           L_800FABE0
    // 0x800FABC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FABE0;
    // 0x800FABC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FABC4:
    // 0x800FABC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FABC8: jal         0x800EF3DC
    // 0x800FABCC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EF3DC(rdram, ctx);
        goto after_5;
    // 0x800FABCC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x800FABD0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800FABD4: jal         0x800EE7F8
    // 0x800FABD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x800FABD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800FABDC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_800FABE0:
    // 0x800FABE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FABE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FABE8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800FABEC: jr          $ra
    // 0x800FABF0: nop

    return;
    // 0x800FABF0: nop

;}
RECOMP_FUNC void func_800BD0BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD0BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BD0C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD0C4: jal         0x8001BAFC
    // 0x800BD0C8: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800BD0C8: nop

    after_0:
    // 0x800BD0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BD0D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BD0D4: jr          $ra
    // 0x800BD0D8: nop

    return;
    // 0x800BD0D8: nop

;}
RECOMP_FUNC void func_808018DC_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018E4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808018E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808018EC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808018F0: beq         $t6, $at, L_80801908
    if (ctx->r14 == ctx->r1) {
        // 0x808018F4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801908;
    }
    // 0x808018F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808018F8: beql        $t6, $at, L_80801930
    if (ctx->r14 == ctx->r1) {
        // 0x808018FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801930;
    }
    goto skip_0;
    // 0x808018FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801900: b           L_80801930
    // 0x80801904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801930;
    // 0x80801904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801908:
    // 0x80801908: jal         0x80101DDC
    // 0x8080190C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101DDC(rdram, ctx);
        goto after_0;
    // 0x8080190C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801910: beq         $v0, $zero, L_8080192C
    if (ctx->r2 == 0) {
        // 0x80801914: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080192C;
    }
    // 0x80801914: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801918: jal         0x80102424
    // 0x8080191C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080191C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80801920: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801924: jal         0x80103110
    // 0x80801928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x80801928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8080192C:
    // 0x8080192C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801930:
    // 0x80801930: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801934: jr          $ra
    // 0x80801938: nop

    return;
    // 0x80801938: nop

;}
RECOMP_FUNC void bsbabykaz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808004A8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(68, 0X1730) << 16);
    // 0x808004AC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808004B0: jr          $ra
    // 0x808004B4: lw          $v0, 0x1730($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1730));
    return;
    // 0x808004B4: lw          $v0, 0x1730($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1730));
;}
RECOMP_FUNC void func_80803368_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803368: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080336C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80803370: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80803374: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803378: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080337C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803380: jal         0x80089C78
    // 0x80803384: addiu       $a0, $zero, 0x52B
    ctx->r4 = ADD32(0, 0X52B);
    _subaddiefind_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80803384: addiu       $a0, $zero, 0x52B
    ctx->r4 = ADD32(0, 0X52B);
    after_0:
    // 0x80803388: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8080338C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80803390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803394: beql        $t6, $zero, L_808033B0
    if (ctx->r14 == 0) {
        // 0x80803398: lbu         $t0, 0x65($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X65);
            goto L_808033B0;
    }
    goto skip_0;
    // 0x80803398: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
    skip_0:
    // 0x8080339C: lbu         $t8, 0x65($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X65);
    // 0x808033A0: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x808033A4: b           L_808033B8
    // 0x808033A8: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
        goto L_808033B8;
    // 0x808033A8: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
    // 0x808033AC: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
L_808033B0:
    // 0x808033B0: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x808033B4: sb          $t1, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r9;
L_808033B8:
    // 0x808033B8: jal         0x80102424
    // 0x808033BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x808033BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808033C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808033C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808033C8: jal         0x8008A0E0
    // 0x808033CC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808033CC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x808033D0: bne         $v0, $zero, L_8080340C
    if (ctx->r2 != 0) {
        // 0x808033D4: nop
    
            goto L_8080340C;
    }
    // 0x808033D4: nop

    // 0x808033D8: jal         0x80103EF4
    // 0x808033DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_3;
    // 0x808033DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808033E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808033E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808033E8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808033EC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808033F0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808033F4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x808033F8: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x808033FC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80803400: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80803404: jal         0x800EFA4C
    // 0x80803408: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80803408: nop

    after_4:
L_8080340C:
    // 0x8080340C: jal         0x800C8A98
    // 0x80803410: nop

    func_800C8A98(rdram, ctx);
        goto after_5;
    // 0x80803410: nop

    after_5:
    // 0x80803414: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80803418: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080341C: jal         0x800C8F64
    // 0x80803420: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_800C8F64(rdram, ctx);
        goto after_6;
    // 0x80803420: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_6:
    // 0x80803424: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2484, 0X7474) << 16);
    // 0x80803428: addiu       $a1, $a1, 0x7474
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2484, 0X7474));
    // 0x8080342C: jal         0x800C8E84
    // 0x80803430: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    func_800C8E84(rdram, ctx);
        goto after_7;
    // 0x80803430: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_7:
    // 0x80803434: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2484, 0X746C) << 16);
    // 0x80803438: addiu       $a1, $a1, 0x746C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2484, 0X746C));
    // 0x8080343C: jal         0x800C8D4C
    // 0x80803440: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    func_800C8D4C(rdram, ctx);
        goto after_8;
    // 0x80803440: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_8:
    // 0x80803444: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80803448: jal         0x800C8CB8
    // 0x8080344C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800C8CB8(rdram, ctx);
        goto after_9;
    // 0x8080344C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_9:
    // 0x80803450: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80803454: jal         0x800C8FE0
    // 0x80803458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_10;
    // 0x80803458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8080345C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803460: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803464: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80803468: jr          $ra
    // 0x8080346C: nop

    return;
    // 0x8080346C: nop

;}
RECOMP_FUNC void _bskazfly_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083398: syscall     57
    recomp_syscall_handler(rdram, ctx, 0x80083398);
    return;
    // 0x8008339C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8080016C_gclevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800174: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800178: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080017C: beq         $a0, $a1, L_808001EC
    if (ctx->r4 == ctx->r5) {
        // 0x80800180: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_808001EC;
    }
    // 0x80800180: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800184: jal         0x8009E958
    // 0x80800188: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8009E958(rdram, ctx);
        goto after_0;
    // 0x80800188: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080018C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800190: beq         $v0, $at, L_808001A8
    if (ctx->r2 == ctx->r1) {
        // 0x80800194: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_808001A8;
    }
    // 0x80800194: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800198: jal         0x800D395C
    // 0x8080019C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D395C(rdram, ctx);
        goto after_1;
    // 0x8080019C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x808001A0: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001A4: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_808001EC;
    }
    // 0x808001A4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_808001A8:
    // 0x808001A8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x808001AC: beq         $a1, $v0, L_80800228
    if (ctx->r5 == ctx->r2) {
        // 0x808001B0: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_80800228;
    }
    // 0x808001B0: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x808001B4: beq         $a1, $at, L_808001D8
    if (ctx->r5 == ctx->r1) {
        // 0x808001B8: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_808001D8;
    }
    // 0x808001B8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x808001BC: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x808001C0: bne         $a1, $at, L_808001E0
    if (ctx->r5 != ctx->r1) {
        // 0x808001C4: addiu       $t7, $zero, 0x142
        ctx->r15 = ADD32(0, 0X142);
            goto L_808001E0;
    }
    // 0x808001C4: addiu       $t7, $zero, 0x142
    ctx->r15 = ADD32(0, 0X142);
    // 0x808001C8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x808001CC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x808001D0: b           L_808001E0
    // 0x808001D4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_808001E0;
    // 0x808001D4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808001D8:
    // 0x808001D8: beql        $t9, $v0, L_8080022C
    if (ctx->r25 == ctx->r2) {
        // 0x808001DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080022C;
    }
    goto skip_0;
    // 0x808001DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_808001E0:
    // 0x808001E0: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    // 0x808001E4: jal         0x8009EB8C
    // 0x808001E8: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    func_8009EB8C(rdram, ctx);
        goto after_2;
    // 0x808001E8: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    after_2:
L_808001EC:
    // 0x808001EC: jal         0x8009EC7C
    // 0x808001F0: nop

    func_8009EC7C(rdram, ctx);
        goto after_3;
    // 0x808001F0: nop

    after_3:
    // 0x808001F4: bne         $v0, $zero, L_80800228
    if (ctx->r2 != 0) {
        // 0x808001F8: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_80800228;
    }
    // 0x808001F8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808001FC: addiu       $at, $zero, 0x194
    ctx->r1 = ADD32(0, 0X194);
    // 0x80800200: bne         $t0, $at, L_8080021C
    if (ctx->r8 != ctx->r1) {
        // 0x80800204: lh          $a0, 0x22($sp)
        ctx->r4 = MEM_H(ctx->r29, 0X22);
            goto L_8080021C;
    }
    // 0x80800204: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    // 0x80800208: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8080020C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80800210: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    // 0x80800214: b           L_80800220
    // 0x80800218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800220;
    // 0x80800218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080021C:
    // 0x8080021C: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
L_80800220:
    // 0x80800220: jal         0x8009EB8C
    // 0x80800224: nop

    func_8009EB8C(rdram, ctx);
        goto after_4;
    // 0x80800224: nop

    after_4:
L_80800228:
    // 0x80800228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080022C:
    // 0x8080022C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800230: jr          $ra
    // 0x80800234: nop

    return;
    // 0x80800234: nop

;}
RECOMP_FUNC void func_8080076C_sucoasterplayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080076C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800774: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800778: lw          $a0, 0x18($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X18);
    // 0x8080077C: srl         $t6, $a0, 28
    ctx->r14 = S32(U32(ctx->r4) >> 28);
    // 0x80800780: jal         0x8008A240
    // 0x80800784: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800784: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80800788: lhu         $t7, 0x4A($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4A);
    // 0x8080078C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800790: beql        $t7, $zero, L_808007D0
    if (ctx->r15 == 0) {
        // 0x80800794: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808007D0;
    }
    goto skip_0;
    // 0x80800794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800798: lw          $a0, 0x64($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X64);
    // 0x8080079C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007A0: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x808007A4: jal         0x80016B30
    // 0x808007A8: srl         $a0, $t9, 30
    ctx->r4 = S32(U32(ctx->r25) >> 30);
    func_80016B30(rdram, ctx);
        goto after_1;
    // 0x808007A8: srl         $a0, $t9, 30
    ctx->r4 = S32(U32(ctx->r25) >> 30);
    after_1:
    // 0x808007AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007B0: bne         $v0, $at, L_808007CC
    if (ctx->r2 != ctx->r1) {
        // 0x808007B4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808007CC;
    }
    // 0x808007B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007B8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x808007BC: jal         0x8008A140
    // 0x808007C0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808007C0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_2:
    // 0x808007C4: b           L_808007D4
    // 0x808007C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007D4;
    // 0x808007C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007CC:
    // 0x808007CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808007D0:
    // 0x808007D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007D4:
    // 0x808007D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007D8: jr          $ra
    // 0x808007DC: nop

    return;
    // 0x808007DC: nop

;}
RECOMP_FUNC void func_80114DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114DD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114DE0: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80114DE4: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80114DE8: bnel        $t6, $zero, L_80114E24
    if (ctx->r14 != 0) {
        // 0x80114DEC: lh          $t8, 0x6($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X6);
            goto L_80114E24;
    }
    goto skip_0;
    // 0x80114DEC: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    skip_0:
    // 0x80114DF0: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80114DF4: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    // 0x80114DF8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80114DFC: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x80114E00: bnel        $at, $zero, L_80114E1C
    if (ctx->r1 != 0) {
        // 0x80114E04: sh          $zero, 0x0($v0)
        MEM_H(0X0, ctx->r2) = 0;
            goto L_80114E1C;
    }
    goto skip_1;
    // 0x80114E04: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    skip_1:
    // 0x80114E08: jal         0x80112E50
    // 0x80114E0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80112E50(rdram, ctx);
        goto after_0;
    // 0x80114E0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80114E10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80114E14: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80114E18: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_80114E1C:
    // 0x80114E1C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80114E20: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
L_80114E24:
    // 0x80114E24: bnel        $t8, $zero, L_80114E60
    if (ctx->r24 != 0) {
        // 0x80114E28: sh          $zero, 0x6($v0)
        MEM_H(0X6, ctx->r2) = 0;
            goto L_80114E60;
    }
    goto skip_2;
    // 0x80114E28: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    skip_2:
    // 0x80114E2C: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x80114E30: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80114E34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80114E38: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80114E3C: bnel        $at, $zero, L_80114E58
    if (ctx->r1 != 0) {
        // 0x80114E40: sh          $zero, 0x2($v0)
        MEM_H(0X2, ctx->r2) = 0;
            goto L_80114E58;
    }
    goto skip_3;
    // 0x80114E40: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    skip_3:
    // 0x80114E44: jal         0x80112E50
    // 0x80114E48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80112E50(rdram, ctx);
        goto after_1;
    // 0x80114E48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80114E4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80114E50: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80114E54: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
L_80114E58:
    // 0x80114E58: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80114E5C: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
L_80114E60:
    // 0x80114E60: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80114E64: lh          $t0, 0x6($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X6);
    // 0x80114E68: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
    // 0x80114E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80114E74: jr          $ra
    // 0x80114E78: nop

    return;
    // 0x80114E78: nop

    // 0x80114E7C: nop

;}
RECOMP_FUNC void _chhumba_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086BF0: syscall     429
    recomp_syscall_handler(rdram, ctx, 0x80086BF0);
    return;
    // 0x80086BF4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F6D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6D50: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6D54: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6D58: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6D5C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F6D60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F6D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6D68: jal         0x8008E124
    // 0x800F6D6C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8008E124(rdram, ctx);
        goto after_0;
    // 0x800F6D6C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6D70: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F6D74: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800F6D78: beq         $t7, $zero, L_800F6D90
    if (ctx->r15 == 0) {
        // 0x800F6D7C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F6D90;
    }
    // 0x800F6D7C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6D80: jal         0x8009E674
    // 0x800F6D84: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8009E674(rdram, ctx);
        goto after_1;
    // 0x800F6D84: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x800F6D88: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F6D8C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800F6D90:
    // 0x800F6D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6D94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F6D98: jr          $ra
    // 0x800F6D9C: nop

    return;
    // 0x800F6D9C: nop

;}
RECOMP_FUNC void baduo_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800180: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800184: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800188: lw          $t6, 0x58($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X58);
    // 0x8080018C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800190: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800194: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    // 0x80800198: lw          $t7, 0x58($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X58);
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x808001A4: beq         $v0, $at, L_808001D0
    if (ctx->r2 == ctx->r1) {
        // 0x808001A8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001D0;
    }
    // 0x808001A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001AC: beq         $v0, $at, L_808001F0
    if (ctx->r2 == ctx->r1) {
        // 0x808001B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F0;
    }
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001B8: beq         $v0, $at, L_8080020C
    if (ctx->r2 == ctx->r1) {
        // 0x808001BC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080020C;
    }
    // 0x808001BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808001C0: beq         $v0, $at, L_80800258
    if (ctx->r2 == ctx->r1) {
        // 0x808001C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800258;
    }
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: b           L_80800278
    // 0x808001CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800278;
    // 0x808001CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001D0:
    // 0x808001D0: jal         0x808002C8
    // 0x808001D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    baduo_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808001D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001E0: jal         0x8009ADF0
    // 0x808001E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009ADF0(rdram, ctx);
        goto after_1;
    // 0x808001E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808001E8: b           L_80800278
    // 0x808001EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800278;
    // 0x808001EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001F0:
    // 0x808001F0: jal         0x808002BC
    // 0x808001F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    baduo_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808001F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: jal         0x808002C8
    // 0x80800200: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    baduo_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800200: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800204: b           L_80800278
    // 0x80800208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800278;
    // 0x80800208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080020C:
    // 0x8080020C: jal         0x8008DAA8
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DAA8(rdram, ctx);
        goto after_4;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800214: beq         $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x80800218: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800234;
    }
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800224: jal         0x800A38F0
    // 0x80800228: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_5;
    // 0x80800228: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8080022C: b           L_80800244
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800244;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800234:
    // 0x80800234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800238: jal         0x800A38F0
    // 0x8080023C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_6;
    // 0x8080023C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800244:
    // 0x80800244: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800248: jal         0x8009ADF0
    // 0x8080024C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_7;
    // 0x8080024C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80800250: b           L_80800278
    // 0x80800254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800278;
    // 0x80800254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800258:
    // 0x80800258: jal         0x80085008
    // 0x8080025C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bashoes_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x8080025C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800260: jal         0x800F54E4
    // 0x80800264: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x80800264: nop

    after_9:
    // 0x80800268: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080026C: jal         0x800F82D4
    // 0x80800270: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_10;
    // 0x80800270: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800278:
    // 0x80800278: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080027C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800280: jr          $ra
    // 0x80800284: nop

    return;
    // 0x80800284: nop

;}
RECOMP_FUNC void _bsmumswim_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083918: syscall     81
    recomp_syscall_handler(rdram, ctx, 0x80083918);
    return;
    // 0x8008391C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_8008AB84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AB84: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008AB88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008AB8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008AB90: jal         0x8008AEDC
    // 0x8008AB94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8008AEDC(rdram, ctx);
        goto after_0;
    // 0x8008AB94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8008AB98: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8008AB9C: jal         0x8008AA0C
    // 0x8008ABA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AA0C(rdram, ctx);
        goto after_1;
    // 0x8008ABA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8008ABA4: jal         0x8008C0C8
    // 0x8008ABA8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_8008C0C8(rdram, ctx);
        goto after_2;
    // 0x8008ABA8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x8008ABAC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8008ABB0: jal         0x8008A990
    // 0x8008ABB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008A990(rdram, ctx);
        goto after_3;
    // 0x8008ABB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8008ABB8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8008ABBC: jal         0x8008B2AC
    // 0x8008ABC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B2AC(rdram, ctx);
        goto after_4;
    // 0x8008ABC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8008ABC4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8008ABC8: lb          $t7, 0x1B($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1B);
    // 0x8008ABCC: div.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8008ABD0: bltz        $t7, L_8008ABDC
    if (SIGNED(ctx->r15) < 0) {
        // 0x8008ABD4: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_8008ABDC;
    }
    // 0x8008ABD4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8008ABD8: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_8008ABDC:
    // 0x8008ABDC: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8008ABE0: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8008ABE4: add.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8008ABE8: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
    // 0x8008ABEC: nop

    // 0x8008ABF0: bc1fl       L_8008AC30
    if (!c1cs) {
        // 0x8008ABF4: mfc1        $a1, $f14
        ctx->r5 = (int32_t)ctx->f14.u32l;
            goto L_8008AC30;
    }
    goto skip_0;
    // 0x8008ABF4: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    skip_0:
    // 0x8008ABF8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8008ABFC: sub.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8008AC00: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8008AC04: div.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8008AC08: trunc.w.s   $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8008AC0C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8008AC10: nop

    // 0x8008AC14: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8008AC18: nop

    // 0x8008AC1C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8008AC20: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8008AC24: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8008AC28: add.s       $f14, $f0, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8008AC2C: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
L_8008AC30:
    // 0x8008AC30: jal         0x8008C1C0
    // 0x8008AC34: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_8008C1C0(rdram, ctx);
        goto after_5;
    // 0x8008AC34: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x8008AC38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AC3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008AC40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8008AC44: jr          $ra
    // 0x8008AC48: nop

    return;
    // 0x8008AC48: nop

;}
RECOMP_FUNC void bsmumcast_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800238: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080023C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800240: jal         0x8009E6EC
    // 0x80800244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800248: slti        $at, $v0, 0x26
    ctx->r1 = SIGNED(ctx->r2) < 0X26 ? 1 : 0;
    // 0x8080024C: bne         $at, $zero, L_80800268
    if (ctx->r1 != 0) {
        // 0x80800250: addiu       $t6, $v0, -0x15
        ctx->r14 = ADD32(ctx->r2, -0X15);
            goto L_80800268;
    }
    // 0x80800250: addiu       $t6, $v0, -0x15
    ctx->r14 = ADD32(ctx->r2, -0X15);
    // 0x80800254: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80800258: beql        $v0, $at, L_80800294
    if (ctx->r2 == ctx->r1) {
        // 0x8080025C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800294;
    }
    goto skip_0;
    // 0x8080025C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800260: b           L_80800288
    // 0x80800264: nop

        goto L_80800288;
    // 0x80800264: nop

L_80800268:
    // 0x80800268: sltiu       $at, $t6, 0x11
    ctx->r1 = ctx->r14 < 0X11 ? 1 : 0;
    // 0x8080026C: beq         $at, $zero, L_80800288
    if (ctx->r1 == 0) {
        // 0x80800270: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800288;
    }
    // 0x80800270: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800274: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(316, 0X444) << 16);
    // 0x80800278: addu        $at, $at, $t6
    gpr jr_addend_80800280 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080027C: lw          $t6, 0x444($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(316, 0X444));
    // 0x80800280: jr          $t6
    // 0x80800284: nop

    switch (jr_addend_80800280 >> 2) {
        case 0: goto L_80800290; break;
        case 1: goto L_80800288; break;
        case 2: goto L_80800288; break;
        case 3: goto L_80800288; break;
        case 4: goto L_80800288; break;
        case 5: goto L_80800288; break;
        case 6: goto L_80800288; break;
        case 7: goto L_80800290; break;
        case 8: goto L_80800290; break;
        case 9: goto L_80800290; break;
        case 10: goto L_80800288; break;
        case 11: goto L_80800288; break;
        case 12: goto L_80800288; break;
        case 13: goto L_80800288; break;
        case 14: goto L_80800288; break;
        case 15: goto L_80800288; break;
        case 16: goto L_80800290; break;
        default: switch_error(__func__, 0x80800280, 0x80800444);
    }
    // 0x80800284: nop

L_80800288:
    // 0x80800288: jal         0x80099B94
    // 0x8080028C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80099B94(rdram, ctx);
        goto after_1;
    // 0x8080028C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80800290:
    // 0x80800290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800294:
    // 0x80800294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800298: jr          $ra
    // 0x8080029C: nop

    return;
    // 0x8080029C: nop

;}
RECOMP_FUNC void func_800EE010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EE014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EE018: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x800EE01C: lui         $a3, 0x3F66
    ctx->r7 = S32(0X3F66 << 16);
    // 0x800EE020: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x800EE024: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x800EE028: jal         0x800EE040
    // 0x800EE02C: addiu       $a1, $zero, 0x3EC
    ctx->r5 = ADD32(0, 0X3EC);
    func_800EE040(rdram, ctx);
        goto after_0;
    // 0x800EE02C: addiu       $a1, $zero, 0x3EC
    ctx->r5 = ADD32(0, 0X3EC);
    after_0:
    // 0x800EE030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EE034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EE038: jr          $ra
    // 0x800EE03C: nop

    return;
    // 0x800EE03C: nop

;}
RECOMP_FUNC void _chfactorygoblin_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086250: syscall     294
    recomp_syscall_handler(rdram, ctx, 0x80086250);
    return;
    // 0x80086254: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chamazongoldhordeofficial_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1860, 0X1240) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1240
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1860, 0X1240));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1240
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1860, 0X1240));
;}
