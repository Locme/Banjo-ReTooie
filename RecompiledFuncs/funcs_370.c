#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void glcutDll_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800608: jal         0x800DB9B0
    // 0x8080060C: nop

    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x8080060C: nop

    after_0:
    // 0x80800610: bne         $v0, $zero, L_80800620
    if (ctx->r2 != 0) {
        // 0x80800614: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800620;
    }
    // 0x80800614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800618: b           L_80800654
    // 0x8080061C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800654;
    // 0x8080061C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800620:
    // 0x80800620: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800624: lh          $v0, 0x75EC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X75EC);
    // 0x80800628: addiu       $at, $zero, 0x8C
    ctx->r1 = ADD32(0, 0X8C);
    // 0x8080062C: bnel        $v0, $at, L_80800640
    if (ctx->r2 != ctx->r1) {
        // 0x80800630: addiu       $at, $zero, 0x8A
        ctx->r1 = ADD32(0, 0X8A);
            goto L_80800640;
    }
    goto skip_0;
    // 0x80800630: addiu       $at, $zero, 0x8A
    ctx->r1 = ADD32(0, 0X8A);
    skip_0:
    // 0x80800634: b           L_80800654
    // 0x80800638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800654;
    // 0x80800638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080063C: addiu       $at, $zero, 0x8A
    ctx->r1 = ADD32(0, 0X8A);
L_80800640:
    // 0x80800640: bnel        $v0, $at, L_80800654
    if (ctx->r2 != ctx->r1) {
        // 0x80800644: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800654;
    }
    goto skip_1;
    // 0x80800644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80800648: b           L_80800654
    // 0x8080064C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800654;
    // 0x8080064C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800654:
    // 0x80800654: jr          $ra
    // 0x80800658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _gczoombox_entrypoint_43(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C38: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087C38);
    return;
    // 0x80087C3C: addi        $t0, $zero, 0xAC
    ctx->r8 = ADD32(0, 0XAC);
;}
RECOMP_FUNC void func_80801458_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801458: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080145C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801460: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801464: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801468: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080146C: jal         0x80100094
    // 0x80801470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801474: jal         0x8008A040
    // 0x80801478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080147C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801480: jal         0x8010CD28
    // 0x80801484: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010CD28(rdram, ctx);
        goto after_2;
    // 0x80801484: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80801488: jal         0x8010105C
    // 0x8080148C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8010105C(rdram, ctx);
        goto after_3;
    // 0x8080148C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80801490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801494: addiu       $a1, $zero, 0x97
    ctx->r5 = ADD32(0, 0X97);
    // 0x80801498: jal         0x8010108C
    // 0x8080149C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_4;
    // 0x8080149C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808014A0: bgtz        $v0, L_808014F4
    if (SIGNED(ctx->r2) > 0) {
        // 0x808014A4: addiu       $a0, $s1, 0x18
        ctx->r4 = ADD32(ctx->r17, 0X18);
            goto L_808014F4;
    }
    // 0x808014A4: addiu       $a0, $s1, 0x18
    ctx->r4 = ADD32(ctx->r17, 0X18);
    // 0x808014A8: addiu       $a0, $s1, 0x18
    ctx->r4 = ADD32(ctx->r17, 0X18);
    // 0x808014AC: jal         0x800EE7F8
    // 0x808014B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808014B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x808014B4: lhu         $t6, 0x6A($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6A);
    // 0x808014B8: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808014BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808014C0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x808014C4: bgez        $t6, L_808014D8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808014C8: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_808014D8;
    }
    // 0x808014C8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808014CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808014D0: nop

    // 0x808014D4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_808014D8:
    // 0x808014D8: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808014DC: lwc1        $f18, 0x2C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x808014E0: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x808014E4: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808014E8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x808014EC: b           L_80801514
    // 0x808014F0: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
        goto L_80801514;
    // 0x808014F0: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
L_808014F4:
    // 0x808014F4: jal         0x80101038
    // 0x808014F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80101038(rdram, ctx);
        goto after_6;
    // 0x808014F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_6:
    // 0x808014FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801500: jal         0x800EF334
    // 0x80801504: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_800EF334(rdram, ctx);
        goto after_7;
    // 0x80801504: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_7:
    // 0x80801508: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080150C: jal         0x800EF04C
    // 0x80801510: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x80801510: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
L_80801514:
    // 0x80801514: jal         0x80101068
    // 0x80801518: nop

    func_80101068(rdram, ctx);
        goto after_9;
    // 0x80801518: nop

    after_9:
    // 0x8080151C: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    // 0x80801520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801524: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801528: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080152C: jr          $ra
    // 0x80801530: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801530: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _suautobaddies_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FC8: syscall     820
    recomp_syscall_handler(rdram, ctx, 0x80089FC8);
    return;
    // 0x80089FCC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _anseq_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082620: syscall     3
    recomp_syscall_handler(rdram, ctx, 0x80082620);
    return;
    // 0x80082624: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080019C_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080019C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001A4: lbu         $t6, 0x15D($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15D);
    // 0x808001A8: beq         $t6, $zero, L_808001C0
    if (ctx->r14 == 0) {
        // 0x808001AC: nop
    
            goto L_808001C0;
    }
    // 0x808001AC: nop

    // 0x808001B0: jal         0x80800000
    // 0x808001B4: nop

    func_80800000_bsbansnooze(rdram, ctx);
        goto after_0;
    // 0x808001B4: nop

    after_0:
    // 0x808001B8: b           L_808001F0
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001F0;
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001C0:
    // 0x808001C0: jal         0x80084508
    // 0x808001C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babackpack_get_state(rdram, ctx);
        goto after_1;
    // 0x808001C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808001C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001CC: beq         $v0, $at, L_808001EC
    if (ctx->r2 == ctx->r1) {
        // 0x808001D0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808001EC;
    }
    // 0x808001D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001D8: jal         0x800A0CD0
    // 0x808001DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A0CD0(rdram, ctx);
        goto after_2;
    // 0x808001DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x808001E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001E4: jal         0x80084538
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_3;
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808001EC:
    // 0x808001EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001F0:
    // 0x808001F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

;}
RECOMP_FUNC void func_80800050_chweather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080005C: jal         0x8010D254
    // 0x80800060: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80800060: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800064: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(732, 0X404) << 16);
    // 0x80800068: lwc1        $f4, 0x404($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(732, 0X404));
    // 0x8080006C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800078: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080007C: nop

    // 0x80800080: bc1f        L_8080008C
    if (!c1cs) {
        // 0x80800084: nop
    
            goto L_8080008C;
    }
    // 0x80800084: nop

    // 0x80800088: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080008C:
    // 0x8080008C: jr          $ra
    // 0x80800090: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800090: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808005E0_chhellterskelter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808005E4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808005E8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808005EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005F0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808005F4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808005F8: jal         0x800EE7F8
    // 0x808005FC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808005FC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800600: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800604: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800608: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080060C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800610: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800614: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800618: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080061C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800620: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80800624: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80800628: lwc1        $f10, 0x48($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X48);
    // 0x8080062C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800630: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800634: jal         0x800EF1B8
    // 0x80800638: nop

    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800638: nop

    after_1:
    // 0x8080063C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(964, 0X938) << 16);
    // 0x80800640: addiu       $t7, $t7, 0x938
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(964, 0X938));
    // 0x80800644: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800648: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080064C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800650: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80800654: jal         0x800BABB8
    // 0x80800658: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800658: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8080065C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(964, 0X974) << 16);
    // 0x80800660: addiu       $a2, $a2, 0x974
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(964, 0X974));
    // 0x80800664: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800668: jal         0x80089D18
    // 0x8080066C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8080066C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800674: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800678: jr          $ra
    // 0x8080067C: nop

    return;
    // 0x8080067C: nop

;}
RECOMP_FUNC void func_80800F6C_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F6C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800F70: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800F74: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80800F78: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800F7C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80800F80: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800F84: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800F88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800F8C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800F90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800F94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800F98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F9C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80800FA0: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x80800FA4: beq         $a2, $zero, L_808012FC
    if (ctx->r6 == 0) {
        // 0x80800FA8: or          $t6, $a2, $zero
        ctx->r14 = ctx->r6 | 0;
            goto L_808012FC;
    }
    // 0x80800FA8: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
    // 0x80800FAC: beq         $a1, $zero, L_808012FC
    if (ctx->r5 == 0) {
        // 0x80800FB0: or          $t7, $a1, $zero
        ctx->r15 = ctx->r5 | 0;
            goto L_808012FC;
    }
    // 0x80800FB0: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x80800FB4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80800FB8: or          $t8, $a2, $zero
    ctx->r24 = ctx->r6 | 0;
    // 0x80800FBC: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x80800FC0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80800FC4: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80800FC8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80800FCC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800FD0: addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // 0x80800FD4: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80800FD8: beql        $at, $zero, L_808011B8
    if (ctx->r1 == 0) {
        // 0x80800FDC: sltu        $at, $v1, $v0
        ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
            goto L_808011B8;
    }
    goto skip_0;
    // 0x80800FDC: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    skip_0:
L_80800FE0:
    // 0x80800FE0: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80800FE4: addiu       $s5, $t2, 0x1C
    ctx->r21 = ADD32(ctx->r10, 0X1C);
    // 0x80800FE8: sltu        $at, $s5, $v0
    ctx->r1 = ctx->r21 < ctx->r2 ? 1 : 0;
    // 0x80800FEC: beq         $at, $zero, L_808011A0
    if (ctx->r1 == 0) {
        // 0x80800FF0: sw          $s5, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r21;
            goto L_808011A0;
    }
    // 0x80800FF0: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80800FF4: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
L_80800FF8:
    // 0x80800FF8: lw          $t4, 0x14($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X14);
    // 0x80800FFC: lw          $t6, 0x14($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X14);
    // 0x80801000: bnel        $t4, $t6, L_80801174
    if (ctx->r12 != ctx->r14) {
        // 0x80801004: lw          $t0, 0x74($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X74);
            goto L_80801174;
    }
    goto skip_1;
    // 0x80801004: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    skip_1:
    // 0x80801008: lh          $t7, 0x1A($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X1A);
    // 0x8080100C: beql        $t7, $zero, L_80801174
    if (ctx->r15 == 0) {
        // 0x80801010: lw          $t0, 0x74($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X74);
            goto L_80801174;
    }
    goto skip_2;
    // 0x80801010: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    skip_2:
    // 0x80801014: lh          $t8, 0x1A($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X1A);
    // 0x80801018: beql        $t8, $zero, L_80801174
    if (ctx->r24 == 0) {
        // 0x8080101C: lw          $t0, 0x74($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X74);
            goto L_80801174;
    }
    goto skip_3;
    // 0x8080101C: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    skip_3:
    // 0x80801020: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80801024: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80801028: jal         0x80800654
    // 0x8080102C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    func_80800654_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x8080102C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    after_0:
    // 0x80801030: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80801034: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80801038: jal         0x80800630
    // 0x8080103C: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    func_80800630_gcboundDll(rdram, ctx);
        goto after_1;
    // 0x8080103C: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_1:
    // 0x80801040: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80801044: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80801048: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x8080104C: beql        $at, $zero, L_80801174
    if (ctx->r1 == 0) {
        // 0x80801050: lw          $t0, 0x74($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X74);
            goto L_80801174;
    }
    goto skip_4;
    // 0x80801050: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    skip_4:
    // 0x80801054: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
L_80801058:
    // 0x80801058: jal         0x80800654
    // 0x8080105C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80800654_gcboundDll(rdram, ctx);
        goto after_2;
    // 0x8080105C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_2:
    // 0x80801060: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80801064: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80801068: jal         0x80800630
    // 0x8080106C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80800630_gcboundDll(rdram, ctx);
        goto after_3;
    // 0x8080106C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x80801070: sltu        $at, $v0, $s3
    ctx->r1 = ctx->r2 < ctx->r19 ? 1 : 0;
    // 0x80801074: beq         $at, $zero, L_80801154
    if (ctx->r1 == 0) {
        // 0x80801078: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_80801154;
    }
    // 0x80801078: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8080107C: beql        $s7, $zero, L_80801158
    if (ctx->r23 == 0) {
        // 0x80801080: lw          $t5, 0x58($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X58);
            goto L_80801158;
    }
    goto skip_5;
    // 0x80801080: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    skip_5:
    // 0x80801084: lh          $t0, 0xC($s6)
    ctx->r8 = MEM_H(ctx->r22, 0XC);
L_80801088:
    // 0x80801088: lh          $t1, 0xC($s4)
    ctx->r9 = MEM_H(ctx->r20, 0XC);
    // 0x8080108C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80801090: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80801094: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80801098: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8080109C: nop

    // 0x808010A0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808010A4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808010A8: jal         0x800F0064
    // 0x808010AC: nop

    func_800F0064(rdram, ctx);
        goto after_4;
    // 0x808010AC: nop

    after_4:
    // 0x808010B0: beql        $v0, $zero, L_80801140
    if (ctx->r2 == 0) {
        // 0x808010B4: addiu       $s4, $s4, 0x18
        ctx->r20 = ADD32(ctx->r20, 0X18);
            goto L_80801140;
    }
    goto skip_6;
    // 0x808010B4: addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
    skip_6:
    // 0x808010B8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x808010BC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808010C0: addiu       $s2, $fp, 0xE0
    ctx->r18 = ADD32(ctx->r30, 0XE0);
    // 0x808010C4: jal         0x80800630
    // 0x808010C8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    func_80800630_gcboundDll(rdram, ctx);
        goto after_5;
    // 0x808010C8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    after_5:
    // 0x808010CC: sltu        $at, $v0, $s3
    ctx->r1 = ctx->r2 < ctx->r19 ? 1 : 0;
    // 0x808010D0: beq         $at, $zero, L_8080110C
    if (ctx->r1 == 0) {
        // 0x808010D4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8080110C;
    }
    // 0x808010D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808010D8: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x808010DC: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x808010E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808010E4:
    // 0x808010E4: jal         0x800B3CDC
    // 0x808010E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800B3CDC(rdram, ctx);
        goto after_6;
    // 0x808010E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x808010EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808010F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808010F4: jal         0x8001BBA0
    // 0x808010F8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    rare_memcpy(rdram, ctx);
        goto after_7;
    // 0x808010F8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_7:
    // 0x808010FC: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80801100: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80801104: bnel        $at, $zero, L_808010E4
    if (ctx->r1 != 0) {
        // 0x80801108: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808010E4;
    }
    goto skip_7;
    // 0x80801108: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_7:
L_8080110C:
    // 0x8080110C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801110: jal         0x800B422C
    // 0x80801114: addiu       $a1, $s5, 0x18
    ctx->r5 = ADD32(ctx->r21, 0X18);
    func_800B422C(rdram, ctx);
        goto after_8;
    // 0x80801114: addiu       $a1, $s5, 0x18
    ctx->r5 = ADD32(ctx->r21, 0X18);
    after_8:
    // 0x80801118: sb          $zero, 0x3($s5)
    MEM_B(0X3, ctx->r21) = 0;
    // 0x8080111C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80801120: andi        $t3, $zero, 0xFF
    ctx->r11 = 0 & 0XFF;
    // 0x80801124: srl         $t4, $v0, 9
    ctx->r12 = S32(U32(ctx->r2) >> 9);
    // 0x80801128: xor         $t6, $t3, $t4
    ctx->r14 = ctx->r11 ^ ctx->r12;
    // 0x8080112C: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x80801130: xor         $t8, $t7, $v0
    ctx->r24 = ctx->r15 ^ ctx->r2;
    // 0x80801134: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x80801138: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x8080113C: addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
L_80801140:
    // 0x80801140: sltu        $at, $s4, $s3
    ctx->r1 = ctx->r20 < ctx->r19 ? 1 : 0;
    // 0x80801144: beql        $at, $zero, L_80801158
    if (ctx->r1 == 0) {
        // 0x80801148: lw          $t5, 0x58($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X58);
            goto L_80801158;
    }
    goto skip_8;
    // 0x80801148: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    skip_8:
    // 0x8080114C: bnel        $s7, $zero, L_80801088
    if (ctx->r23 != 0) {
        // 0x80801150: lh          $t0, 0xC($s6)
        ctx->r8 = MEM_H(ctx->r22, 0XC);
            goto L_80801088;
    }
    goto skip_9;
    // 0x80801150: lh          $t0, 0xC($s6)
    ctx->r8 = MEM_H(ctx->r22, 0XC);
    skip_9:
L_80801154:
    // 0x80801154: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
L_80801158:
    // 0x80801158: addiu       $s6, $s6, 0x18
    ctx->r22 = ADD32(ctx->r22, 0X18);
    // 0x8080115C: sltu        $at, $s6, $t5
    ctx->r1 = ctx->r22 < ctx->r13 ? 1 : 0;
    // 0x80801160: beql        $at, $zero, L_80801174
    if (ctx->r1 == 0) {
        // 0x80801164: lw          $t0, 0x74($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X74);
            goto L_80801174;
    }
    goto skip_10;
    // 0x80801164: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    skip_10:
    // 0x80801168: bnel        $s7, $zero, L_80801058
    if (ctx->r23 != 0) {
        // 0x8080116C: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_80801058;
    }
    goto skip_11;
    // 0x8080116C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    skip_11:
    // 0x80801170: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
L_80801174:
    // 0x80801174: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80801178: addiu       $s5, $s5, 0x1C
    ctx->r21 = ADD32(ctx->r21, 0X1C);
    // 0x8080117C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80801180: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x80801184: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80801188: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8080118C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80801190: addu        $v0, $t2, $v1
    ctx->r2 = ADD32(ctx->r10, ctx->r3);
    // 0x80801194: sltu        $at, $s5, $v0
    ctx->r1 = ctx->r21 < ctx->r2 ? 1 : 0;
    // 0x80801198: bnel        $at, $zero, L_80800FF8
    if (ctx->r1 != 0) {
        // 0x8080119C: lw          $t5, 0x6C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X6C);
            goto L_80800FF8;
    }
    goto skip_12;
    // 0x8080119C: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    skip_12:
L_808011A0:
    // 0x808011A0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x808011A4: sltu        $at, $t3, $v0
    ctx->r1 = ctx->r11 < ctx->r2 ? 1 : 0;
    // 0x808011A8: bne         $at, $zero, L_80800FE0
    if (ctx->r1 != 0) {
        // 0x808011AC: sw          $t3, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r11;
            goto L_80800FE0;
    }
    // 0x808011AC: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x808011B0: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x808011B4: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
L_808011B8:
    // 0x808011B8: beql        $at, $zero, L_80801264
    if (ctx->r1 == 0) {
        // 0x808011BC: sltu        $at, $v1, $v0
        ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
            goto L_80801264;
    }
    goto skip_13;
    // 0x808011BC: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    skip_13:
L_808011C0:
    // 0x808011C0: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x808011C4: lh          $t6, 0x1A($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X1A);
    // 0x808011C8: bnel        $t6, $zero, L_8080124C
    if (ctx->r14 != 0) {
        // 0x808011CC: lw          $t2, 0x6C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X6C);
            goto L_8080124C;
    }
    goto skip_14;
    // 0x808011CC: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    skip_14:
    // 0x808011D0: addiu       $t7, $t4, 0x1C
    ctx->r15 = ADD32(ctx->r12, 0X1C);
    // 0x808011D4: sltu        $at, $t7, $v0
    ctx->r1 = ctx->r15 < ctx->r2 ? 1 : 0;
    // 0x808011D8: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x808011DC: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x808011E0: beq         $at, $zero, L_80801248
    if (ctx->r1 == 0) {
        // 0x808011E4: or          $s5, $t7, $zero
        ctx->r21 = ctx->r15 | 0;
            goto L_80801248;
    }
    // 0x808011E4: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
    // 0x808011E8: lh          $t8, 0x1A($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X1A);
L_808011EC:
    // 0x808011EC: beql        $t8, $zero, L_80801234
    if (ctx->r24 == 0) {
        // 0x808011F0: addiu       $s5, $s5, 0x1C
        ctx->r21 = ADD32(ctx->r21, 0X1C);
            goto L_80801234;
    }
    goto skip_15;
    // 0x808011F0: addiu       $s5, $s5, 0x1C
    ctx->r21 = ADD32(ctx->r21, 0X1C);
    skip_15:
    // 0x808011F4: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x808011F8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808011FC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80801200: jal         0x8001BBA0
    // 0x80801204: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    rare_memcpy(rdram, ctx);
        goto after_9;
    // 0x80801204: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    after_9:
    // 0x80801208: jal         0x800B4290
    // 0x8080120C: addiu       $a0, $s5, 0x18
    ctx->r4 = ADD32(ctx->r21, 0X18);
    func_800B4290(rdram, ctx);
        goto after_10;
    // 0x8080120C: addiu       $a0, $s5, 0x18
    ctx->r4 = ADD32(ctx->r21, 0X18);
    after_10:
    // 0x80801210: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80801214: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80801218: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8080121C: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x80801220: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80801224: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80801228: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8080122C: addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // 0x80801230: addiu       $s5, $s5, 0x1C
    ctx->r21 = ADD32(ctx->r21, 0X1C);
L_80801234:
    // 0x80801234: sltu        $at, $s5, $v0
    ctx->r1 = ctx->r21 < ctx->r2 ? 1 : 0;
    // 0x80801238: beql        $at, $zero, L_8080124C
    if (ctx->r1 == 0) {
        // 0x8080123C: lw          $t2, 0x6C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X6C);
            goto L_8080124C;
    }
    goto skip_16;
    // 0x8080123C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    skip_16:
    // 0x80801240: bnel        $s7, $zero, L_808011EC
    if (ctx->r23 != 0) {
        // 0x80801244: lh          $t8, 0x1A($s5)
        ctx->r24 = MEM_H(ctx->r21, 0X1A);
            goto L_808011EC;
    }
    goto skip_17;
    // 0x80801244: lh          $t8, 0x1A($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X1A);
    skip_17:
L_80801248:
    // 0x80801248: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
L_8080124C:
    // 0x8080124C: addiu       $t3, $t2, 0x1C
    ctx->r11 = ADD32(ctx->r10, 0X1C);
    // 0x80801250: sltu        $at, $t3, $v0
    ctx->r1 = ctx->r11 < ctx->r2 ? 1 : 0;
    // 0x80801254: bne         $at, $zero, L_808011C0
    if (ctx->r1 != 0) {
        // 0x80801258: sw          $t3, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r11;
            goto L_808011C0;
    }
    // 0x80801258: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x8080125C: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x80801260: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
L_80801264:
    // 0x80801264: beql        $at, $zero, L_808012A0
    if (ctx->r1 == 0) {
        // 0x80801268: lw          $t9, 0x6C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X6C);
            goto L_808012A0;
    }
    goto skip_18;
    // 0x80801268: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    skip_18:
    // 0x8080126C: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80801270: lh          $t4, 0x1A($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X1A);
    // 0x80801274: beql        $t4, $zero, L_808012A0
    if (ctx->r12 == 0) {
        // 0x80801278: lw          $t9, 0x6C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X6C);
            goto L_808012A0;
    }
    goto skip_19;
    // 0x80801278: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    skip_19:
    // 0x8080127C: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
L_80801280:
    // 0x80801280: addiu       $t8, $t7, 0x1C
    ctx->r24 = ADD32(ctx->r15, 0X1C);
    // 0x80801284: sltu        $at, $t8, $v0
    ctx->r1 = ctx->r24 < ctx->r2 ? 1 : 0;
    // 0x80801288: beq         $at, $zero, L_8080129C
    if (ctx->r1 == 0) {
        // 0x8080128C: sw          $t8, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r24;
            goto L_8080129C;
    }
    // 0x8080128C: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x80801290: lh          $t5, 0x1A($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X1A);
    // 0x80801294: bnel        $t5, $zero, L_80801280
    if (ctx->r13 != 0) {
        // 0x80801298: lw          $t7, 0x6C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X6C);
            goto L_80801280;
    }
    goto skip_20;
    // 0x80801298: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    skip_20:
L_8080129C:
    // 0x8080129C: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
L_808012A0:
    // 0x808012A0: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // 0x808012A4: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x808012A8: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x808012AC: div         $zero, $t0, $v0
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r2)));
    // 0x808012B0: mflo        $t1
    ctx->r9 = lo;
    // 0x808012B4: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x808012B8: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x808012BC: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808012C0: bne         $v0, $zero, L_808012CC
    if (ctx->r2 != 0) {
        // 0x808012C4: nop
    
            goto L_808012CC;
    }
    // 0x808012C4: nop

    // 0x808012C8: break       7
    do_break(2155877064);
L_808012CC:
    // 0x808012CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808012D0: bne         $v0, $at, L_808012E4
    if (ctx->r2 != ctx->r1) {
        // 0x808012D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_808012E4;
    }
    // 0x808012D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808012D8: bne         $t0, $at, L_808012E4
    if (ctx->r8 != ctx->r1) {
        // 0x808012DC: nop
    
            goto L_808012E4;
    }
    // 0x808012DC: nop

    // 0x808012E0: break       6
    do_break(2155877088);
L_808012E4:
    // 0x808012E4: mflo        $a1
    ctx->r5 = lo;
    // 0x808012E8: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x808012EC: jal         0x8001B208
    // 0x808012F0: nop

    heap_realloc(rdram, ctx);
        goto after_11;
    // 0x808012F0: nop

    after_11:
    // 0x808012F4: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x808012F8: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
L_808012FC:
    // 0x808012FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80801300: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801304: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801308: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080130C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801310: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801314: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80801318: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8080131C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80801320: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80801324: jr          $ra
    // 0x80801328: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80801328: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void _idwibble_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E70: syscall     745
    recomp_syscall_handler(rdram, ctx, 0x80088E70);
    return;
    // 0x80088E74: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chboilerboss_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D80: syscall     238
    recomp_syscall_handler(rdram, ctx, 0x80085D80);
    return;
    // 0x80085D84: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800EA334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA334: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA338: jr          $ra
    // 0x800EA33C: sh          $a0, 0x2DCA($at)
    MEM_H(0X2DCA, ctx->r1) = ctx->r4;
    return;
    // 0x800EA33C: sh          $a0, 0x2DCA($at)
    MEM_H(0X2DCA, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_80800CD4_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800CE0: jal         0x800DF3E0
    // 0x80800CE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DF3E0(rdram, ctx);
        goto after_0;
    // 0x80800CE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800CE8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800CEC: addiu       $at, $zero, 0x1C6
    ctx->r1 = ADD32(0, 0X1C6);
    // 0x80800CF0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800CF4: lw          $v0, 0x6C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X6C);
    // 0x80800CF8: sll         $t7, $v0, 11
    ctx->r15 = S32(ctx->r2 << 11);
    // 0x80800CFC: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800D00: beq         $t8, $at, L_80800D18
    if (ctx->r24 == ctx->r1) {
        // 0x80800D04: addiu       $at, $zero, 0x1C7
        ctx->r1 = ADD32(0, 0X1C7);
            goto L_80800D18;
    }
    // 0x80800D04: addiu       $at, $zero, 0x1C7
    ctx->r1 = ADD32(0, 0X1C7);
    // 0x80800D08: beq         $t8, $at, L_80800D34
    if (ctx->r24 == ctx->r1) {
        // 0x80800D0C: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_80800D34;
    }
    // 0x80800D0C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800D10: b           L_80800D80
    // 0x80800D14: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
        goto L_80800D80;
    // 0x80800D14: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_80800D18:
    // 0x80800D18: jal         0x800DF744
    // 0x80800D1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800D1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800D20: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800D24: jal         0x800DF744
    // 0x80800D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80800D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800D2C: b           L_80800D8C
    // 0x80800D30: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
        goto L_80800D8C;
    // 0x80800D30: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_80800D34:
    // 0x80800D34: jal         0x800DF744
    // 0x80800D38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800D38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800D3C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80800D40: jal         0x800DF744
    // 0x80800D44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x80800D44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800D48: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800D4C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800D50: lbu         $a1, 0x79($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X79);
    // 0x80800D54: srl         $t0, $a1, 4
    ctx->r8 = S32(U32(ctx->r5) >> 4);
    // 0x80800D58: jal         0x800DF744
    // 0x80800D5C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x80800D5C: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_5:
    // 0x80800D60: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80800D64: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80800D68: lw          $a1, 0x6C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X6C);
    // 0x80800D6C: andi        $t2, $a1, 0x1FF
    ctx->r10 = ctx->r5 & 0X1FF;
    // 0x80800D70: jal         0x800DF744
    // 0x80800D74: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_800DF744(rdram, ctx);
        goto after_6;
    // 0x80800D74: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_6:
    // 0x80800D78: b           L_80800D8C
    // 0x80800D7C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
        goto L_80800D8C;
    // 0x80800D7C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_80800D80:
    // 0x80800D80: jal         0x800DF744
    // 0x80800D84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_7;
    // 0x80800D84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800D88: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_80800D8C:
    // 0x80800D8C: lw          $a0, 0x3C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X3C);
    // 0x80800D90: beql        $a0, $zero, L_80800DE8
    if (ctx->r4 == 0) {
        // 0x80800D94: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800DE8;
    }
    goto skip_0;
    // 0x80800D94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800D98: jal         0x80106790
    // 0x80800D9C: nop

    func_80106790(rdram, ctx);
        goto after_8;
    // 0x80800D9C: nop

    after_8:
    // 0x80800DA0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X1914) << 16);
    // 0x80800DA4: lwc1        $f6, 0x1914($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X1914));
    // 0x80800DA8: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80800DAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(748, 0X1918) << 16);
    // 0x80800DB0: lwc1        $f10, 0x1918($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X1918));
    // 0x80800DB4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800DB8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800DBC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800DC0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80800DC4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800DC8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800DCC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800DD0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800DD4: nop

    // 0x80800DD8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800DDC: jal         0x800DF5D8
    // 0x80800DE0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_800DF5D8(rdram, ctx);
        goto after_9;
    // 0x80800DE0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_9:
    // 0x80800DE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800DE8:
    // 0x80800DE8: jal         0x80101870
    // 0x80800DEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_10;
    // 0x80800DEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_10:
    // 0x80800DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DF8: jr          $ra
    // 0x80800DFC: nop

    return;
    // 0x80800DFC: nop

;}
RECOMP_FUNC void gcnewpause_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000E0: jal         0x80800534
    // 0x808000E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800534_gcnewpause(rdram, ctx);
        goto after_0;
    // 0x808000E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x808000E8: jal         0x8001B084
    // 0x808000EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    heap_free(rdram, ctx);
        goto after_1;
    // 0x808000EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void chanim_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800128: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080012C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800130: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800134: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800138: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080013C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800140: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800144: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800148: addiu       $a2, $a2, 0x5980
    ctx->r6 = ADD32(ctx->r6, 0X5980);
    // 0x8080014C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800150: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800154: jal         0x80082630
    // 0x80800158: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800158: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8080015C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800160: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800164: jr          $ra
    // 0x80800168: nop

    return;
    // 0x80800168: nop

;}
RECOMP_FUNC void _chfactorystationdoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875D0: syscall     593
    recomp_syscall_handler(rdram, ctx, 0x800875D0);
    return;
    // 0x800875D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80099A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099A40: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x80099A44: jr          $ra
    // 0x80099A48: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
    return;
    // 0x80099A48: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
;}
RECOMP_FUNC void func_80800E30_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800E3C: jal         0x80091A58
    // 0x80800E40: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80800E40: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80800E44: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800E48: beq         $t6, $zero, L_80800E94
    if (ctx->r14 == 0) {
        // 0x80800E4C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800E94;
    }
    // 0x80800E4C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800E50: jal         0x80800C10
    // 0x80800E54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bafpctrl_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800E54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800E58: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800E5C: beq         $t7, $zero, L_80800E94
    if (ctx->r15 == 0) {
        // 0x80800E60: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80800E94;
    }
    // 0x80800E60: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80800E64: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800E68: jal         0x800F6774
    // 0x80800E6C: lw          $a0, 0x184($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X184);
    func_800F6774(rdram, ctx);
        goto after_2;
    // 0x80800E6C: lw          $a0, 0x184($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X184);
    after_2:
    // 0x80800E70: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800E74: beq         $t9, $zero, L_80800E94
    if (ctx->r25 == 0) {
        // 0x80800E78: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80800E94;
    }
    // 0x80800E78: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80800E7C: jal         0x800A4CA8
    // 0x80800E80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4CA8(rdram, ctx);
        goto after_3;
    // 0x80800E80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800E84: jal         0x80089418
    // 0x80800E88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncba1p_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800E88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800E8C: xori        $t0, $v0, 0x3
    ctx->r8 = ctx->r2 ^ 0X3;
    // 0x80800E90: sltu        $v0, $zero, $t0
    ctx->r2 = 0 < ctx->r8 ? 1 : 0;
L_80800E94:
    // 0x80800E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E9C: jr          $ra
    // 0x80800EA0: nop

    return;
    // 0x80800EA0: nop

;}
RECOMP_FUNC void func_8080189C_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080189C: lui         $at, 0x4332
    ctx->r1 = S32(0X4332 << 16);
    // 0x808018A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808018A4: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x808018A8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808018AC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808018B0: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x808018B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808018B8: addiu       $v1, $a0, 0x4
    ctx->r3 = ADD32(ctx->r4, 0X4);
    // 0x808018BC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x808018C0: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x808018C4: nop

    // 0x808018C8: bc1fl       L_808018E8
    if (!c1cs) {
        // 0x808018CC: add.s       $f10, $f0, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_808018E8;
    }
    goto skip_0;
    // 0x808018CC: add.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
    skip_0:
    // 0x808018D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808018D4: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x808018D8: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x808018DC: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x808018E0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808018E4: add.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
L_808018E8:
    // 0x808018E8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808018EC: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x808018F0: nop

    // 0x808018F4: bc1f        L_8080190C
    if (!c1cs) {
        // 0x808018F8: nop
    
            goto L_8080190C;
    }
    // 0x808018F8: nop

    // 0x808018FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801900: nop

    // 0x80801904: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80801908: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
L_8080190C:
    // 0x8080190C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3094, 0X2A0C) << 16);
    // 0x80801910: lwc1        $f0, 0x2A0C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3094, 0X2A0C));
L_80801914:
    // 0x80801914: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80801918: subu        $a1, $a2, $v0
    ctx->r5 = SUB32(ctx->r6, ctx->r2);
    // 0x8080191C: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80801920: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801924: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80801928: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8080192C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80801930: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x80801934: addiu       $t8, $v0, 0x2
    ctx->r24 = ADD32(ctx->r2, 0X2);
    // 0x80801938: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8080193C: addiu       $t9, $a1, -0x2
    ctx->r25 = ADD32(ctx->r5, -0X2);
    // 0x80801940: addiu       $t0, $v0, 0x3
    ctx->r8 = ADD32(ctx->r2, 0X3);
    // 0x80801944: addiu       $t1, $a1, -0x3
    ctx->r9 = ADD32(ctx->r5, -0X3);
    // 0x80801948: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080194C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80801950: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801954: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80801958: nop

    // 0x8080195C: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80801960: nop

    // 0x80801964: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80801968: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8080196C: nop

    // 0x80801970: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801974: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80801978: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8080197C: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80801980: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x80801984: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80801988: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8080198C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801990: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80801994: nop

    // 0x80801998: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8080199C: nop

    // 0x808019A0: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808019A4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x808019A8: nop

    // 0x808019AC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808019B0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x808019B4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808019B8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808019BC: swc1        $f18, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f18.u32l;
    // 0x808019C0: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x808019C4: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808019C8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808019CC: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x808019D0: nop

    // 0x808019D4: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808019D8: nop

    // 0x808019DC: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808019E0: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x808019E4: nop

    // 0x808019E8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808019EC: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x808019F0: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x808019F4: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808019F8: swc1        $f6, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f6.u32l;
    // 0x808019FC: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80801A00: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80801A04: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801A08: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80801A0C: nop

    // 0x80801A10: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80801A14: nop

    // 0x80801A18: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801A1C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80801A20: bne         $v0, $a2, L_80801914
    if (ctx->r2 != ctx->r6) {
        // 0x80801A24: swc1        $f18, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
            goto L_80801914;
    }
    // 0x80801A24: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x80801A28: jr          $ra
    // 0x80801A2C: nop

    return;
    // 0x80801A2C: nop

;}
RECOMP_FUNC void func_80800188_chpotogoldbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080018C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800190: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800194: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800198: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080019C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808001A0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808001A4: sltiu       $at, $t8, 0xB
    ctx->r1 = ctx->r24 < 0XB ? 1 : 0;
    // 0x808001A8: beq         $at, $zero, L_8080055C
    if (ctx->r1 == 0) {
        // 0x808001AC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8080055C;
    }
    // 0x808001AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808001B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2344, 0X8E0) << 16);
    // 0x808001B4: addu        $at, $at, $t8
    gpr jr_addend_808001BC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808001B8: lw          $t8, 0x8E0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2344, 0X8E0));
    // 0x808001BC: jr          $t8
    // 0x808001C0: nop

    switch (jr_addend_808001BC >> 2) {
        case 0: goto L_808001C4; break;
        case 1: goto L_808001D8; break;
        case 2: goto L_80800248; break;
        case 3: goto L_808002A8; break;
        case 4: goto L_808002BC; break;
        case 5: goto L_8080032C; break;
        case 6: goto L_8080055C; break;
        case 7: goto L_80800388; break;
        case 8: goto L_808003D8; break;
        case 9: goto L_80800440; break;
        case 10: goto L_8080049C; break;
        default: switch_error(__func__, 0x808001BC, 0x808008E0);
    }
    // 0x808001C0: nop

L_808001C4:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: jal         0x80103110
    // 0x808001CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x808001CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001D0: b           L_80800560
    // 0x808001D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800560;
    // 0x808001D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_808001D8:
    // 0x808001D8: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001E4: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x808001E8: bltzl       $t1, L_8080020C
    if (SIGNED(ctx->r9) < 0) {
        // 0x808001EC: addiu       $t5, $s0, 0x4
        ctx->r13 = ADD32(ctx->r16, 0X4);
            goto L_8080020C;
    }
    goto skip_0;
    // 0x808001EC: addiu       $t5, $s0, 0x4
    ctx->r13 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x808001F0: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x808001F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2344, 0X978) << 16);
    // 0x808001F8: addiu       $a2, $a2, 0x978
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2344, 0X978));
    // 0x808001FC: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x80800200: jal         0x80089D18
    // 0x80800204: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800204: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
    after_1:
    // 0x80800208: addiu       $t5, $s0, 0x4
    ctx->r13 = ADD32(ctx->r16, 0X4);
L_8080020C:
    // 0x8080020C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80800210: jal         0x800D90A4
    // 0x80800214: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_800D90A4(rdram, ctx);
        goto after_2;
    // 0x80800214: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_2:
    // 0x80800218: beq         $v0, $zero, L_80800228
    if (ctx->r2 == 0) {
        // 0x8080021C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800228;
    }
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800220: jal         0x80101FDC
    // 0x80800224: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800224: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
L_80800228:
    // 0x80800228: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2344, 0X968) << 16);
    // 0x8080022C: addiu       $a3, $a3, 0x968
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2344, 0X968));
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800234: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800238: jal         0x80089D50
    // 0x8080023C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x8080023C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80800240: b           L_80800560
    // 0x80800244: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800560;
    // 0x80800244: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800248:
    // 0x80800248: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080024C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2344, 0X968) << 16);
    // 0x80800250: addiu       $a3, $a3, 0x968
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2344, 0X968));
    // 0x80800254: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: jal         0x80089D50
    // 0x80800260: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800260: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80800264: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x80800268: jal         0x800D91EC
    // 0x8080026C: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    func_800D91EC(rdram, ctx);
        goto after_6;
    // 0x8080026C: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    after_6:
    // 0x80800270: beql        $v0, $zero, L_80800560
    if (ctx->r2 == 0) {
        // 0x80800274: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800560;
    }
    goto skip_1;
    // 0x80800274: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_1:
    // 0x80800278: jal         0x80089D40
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800280: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2344, 0X978) << 16);
    // 0x80800284: addiu       $a2, $a2, 0x978
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2344, 0X978));
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: jal         0x80089D18
    // 0x80800290: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800290: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x80101FDC
    // 0x8080029C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x8080029C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x808002A0: b           L_80800560
    // 0x808002A4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800560;
    // 0x808002A4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_808002A8:
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: jal         0x80103110
    // 0x808002B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_10;
    // 0x808002B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808002B4: b           L_80800560
    // 0x808002B8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800560;
    // 0x808002B8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_808002BC:
    // 0x808002BC: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808002C8: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x808002CC: bltzl       $t8, L_808002F0
    if (SIGNED(ctx->r24) < 0) {
        // 0x808002D0: addiu       $t2, $s0, 0x4
        ctx->r10 = ADD32(ctx->r16, 0X4);
            goto L_808002F0;
    }
    goto skip_2;
    // 0x808002D0: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    skip_2:
    // 0x808002D4: lbu         $t0, 0x74($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X74);
    // 0x808002D8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2344, 0X978) << 16);
    // 0x808002DC: addiu       $a2, $a2, 0x978
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2344, 0X978));
    // 0x808002E0: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x808002E4: jal         0x80089D18
    // 0x808002E8: sb          $t1, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r9;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x808002E8: sb          $t1, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r9;
    after_11:
    // 0x808002EC: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
L_808002F0:
    // 0x808002F0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x808002F4: jal         0x800D90A4
    // 0x808002F8: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_800D90A4(rdram, ctx);
        goto after_12;
    // 0x808002F8: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_12:
    // 0x808002FC: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x80800300: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080030C;
    }
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: jal         0x80101FDC
    // 0x80800308: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x80800308: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_13:
L_8080030C:
    // 0x8080030C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2344, 0X968) << 16);
    // 0x80800310: addiu       $a3, $a3, 0x968
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2344, 0X968));
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080031C: jal         0x80089D50
    // 0x80800320: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x80800320: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x80800324: b           L_80800560
    // 0x80800328: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800560;
    // 0x80800328: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8080032C:
    // 0x8080032C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800330: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2344, 0X968) << 16);
    // 0x80800334: addiu       $a3, $a3, 0x968
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2344, 0X968));
    // 0x80800338: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: jal         0x80089D50
    // 0x80800344: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x80800344: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x80800348: jal         0x800D90A4
    // 0x8080034C: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    func_800D90A4(rdram, ctx);
        goto after_16;
    // 0x8080034C: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    after_16:
    // 0x80800350: beql        $v0, $zero, L_80800560
    if (ctx->r2 == 0) {
        // 0x80800354: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800560;
    }
    goto skip_3;
    // 0x80800354: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_3:
    // 0x80800358: jal         0x80089D40
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_17;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800360: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2344, 0X978) << 16);
    // 0x80800364: addiu       $a2, $a2, 0x978
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2344, 0X978));
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: jal         0x80089D18
    // 0x80800370: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x80800370: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_18:
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800378: jal         0x80101FDC
    // 0x8080037C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_19;
    // 0x8080037C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80800380: b           L_80800560
    // 0x80800384: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800560;
    // 0x80800384: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800388:
    // 0x80800388: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800394: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x80800398: bltz        $t5, L_808003B8
    if (SIGNED(ctx->r13) < 0) {
        // 0x8080039C: nop
    
            goto L_808003B8;
    }
    // 0x8080039C: nop

    // 0x808003A0: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x808003A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2344, 0X978) << 16);
    // 0x808003A8: addiu       $a2, $a2, 0x978
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2344, 0X978));
    // 0x808003AC: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x808003B0: jal         0x80089D18
    // 0x808003B4: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_20;
    // 0x808003B4: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    after_20:
L_808003B8:
    // 0x808003B8: jal         0x800D90A4
    // 0x808003BC: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_800D90A4(rdram, ctx);
        goto after_21;
    // 0x808003BC: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_21:
    // 0x808003C0: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x808003C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080055C;
    }
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C8: jal         0x80101FDC
    // 0x808003CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80101FDC(rdram, ctx);
        goto after_22;
    // 0x808003CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_22:
    // 0x808003D0: b           L_80800560
    // 0x808003D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800560;
    // 0x808003D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_808003D8:
    // 0x808003D8: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x808003DC: jal         0x800D91EC
    // 0x808003E0: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    func_800D91EC(rdram, ctx);
        goto after_23;
    // 0x808003E0: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    after_23:
    // 0x808003E4: beq         $v0, $zero, L_80800420
    if (ctx->r2 == 0) {
        // 0x808003E8: nop
    
            goto L_80800420;
    }
    // 0x808003E8: nop

    // 0x808003EC: jal         0x80089D40
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_24;
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808003F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2344, 0X978) << 16);
    // 0x808003F8: addiu       $a2, $a2, 0x978
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2344, 0X978));
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800400: jal         0x80089D18
    // 0x80800404: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_25;
    // 0x80800404: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_25:
    // 0x80800408: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800410: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800414: andi        $t0, $t9, 0xFFBF
    ctx->r8 = ctx->r25 & 0XFFBF;
    // 0x80800418: jal         0x80101FDC
    // 0x8080041C: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
    func_80101FDC(rdram, ctx);
        goto after_26;
    // 0x8080041C: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
    after_26:
L_80800420:
    // 0x80800420: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2344, 0X968) << 16);
    // 0x80800424: addiu       $a3, $a3, 0x968
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2344, 0X968));
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800430: jal         0x80089D50
    // 0x80800434: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_27;
    // 0x80800434: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_27:
    // 0x80800438: b           L_80800560
    // 0x8080043C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800560;
    // 0x8080043C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800440:
    // 0x80800440: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080044C: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x80800450: bltz        $t3, L_80800470
    if (SIGNED(ctx->r11) < 0) {
        // 0x80800454: nop
    
            goto L_80800470;
    }
    // 0x80800454: nop

    // 0x80800458: lbu         $t5, 0x74($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X74);
    // 0x8080045C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2344, 0X978) << 16);
    // 0x80800460: addiu       $a2, $a2, 0x978
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2344, 0X978));
    // 0x80800464: ori         $t6, $t5, 0x40
    ctx->r14 = ctx->r13 | 0X40;
    // 0x80800468: jal         0x80089D18
    // 0x8080046C: sb          $t6, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r14;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_28;
    // 0x8080046C: sb          $t6, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r14;
    after_28:
L_80800470:
    // 0x80800470: jal         0x800D90A4
    // 0x80800474: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_800D90A4(rdram, ctx);
        goto after_29;
    // 0x80800474: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_29:
    // 0x80800478: beq         $v0, $zero, L_8080055C
    if (ctx->r2 == 0) {
        // 0x8080047C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8080055C;
    }
    // 0x8080047C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800480: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800488: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8080048C: jal         0x80101FDC
    // 0x80800490: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    func_80101FDC(rdram, ctx);
        goto after_30;
    // 0x80800490: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    after_30:
    // 0x80800494: b           L_80800560
    // 0x80800498: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800560;
    // 0x80800498: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8080049C:
    // 0x8080049C: jal         0x800D90A4
    // 0x808004A0: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    func_800D90A4(rdram, ctx);
        goto after_31;
    // 0x808004A0: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    after_31:
    // 0x808004A4: beql        $v0, $zero, L_808004B8
    if (ctx->r2 == 0) {
        // 0x808004A8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_808004B8;
    }
    goto skip_4;
    // 0x808004A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_4:
    // 0x808004AC: jal         0x800FFA88
    // 0x808004B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_32;
    // 0x808004B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_32:
    // 0x808004B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_808004B8:
    // 0x808004B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808004BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004C0: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808004C4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808004C8: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x808004CC: jal         0x800F10B4
    // 0x808004D0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_33;
    // 0x808004D0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_33:
    // 0x808004D4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808004D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808004DC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x808004E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808004E4: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x808004E8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x808004EC: nop

    // 0x808004F0: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x808004F4: beql        $t8, $zero, L_80800544
    if (ctx->r24 == 0) {
        // 0x808004F8: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_80800544;
    }
    goto skip_5;
    // 0x808004F8: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_5:
    // 0x808004FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800500: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800504: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80800508: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8080050C: nop

    // 0x80800510: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800514: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800518: nop

    // 0x8080051C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80800520: bne         $t8, $zero, L_80800538
    if (ctx->r24 != 0) {
        // 0x80800524: nop
    
            goto L_80800538;
    }
    // 0x80800524: nop

    // 0x80800528: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8080052C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800530: b           L_80800550
    // 0x80800534: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80800550;
    // 0x80800534: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80800538:
    // 0x80800538: b           L_80800550
    // 0x8080053C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80800550;
    // 0x8080053C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80800540: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_80800544:
    // 0x80800544: nop

    // 0x80800548: bltz        $t8, L_80800538
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080054C: nop
    
            goto L_80800538;
    }
    // 0x8080054C: nop

L_80800550:
    // 0x80800550: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800554: sb          $t8, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r24;
    // 0x80800558: nop

L_8080055C:
    // 0x8080055C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800560:
    // 0x80800560: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800564: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800568: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080056C: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x80800570: addiu       $t9, $s0, 0x4
    ctx->r25 = ADD32(ctx->r16, 0X4);
    // 0x80800574: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800578: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8080057C: jal         0x800F12D4
    // 0x80800580: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F12D4(rdram, ctx);
        goto after_34;
    // 0x80800580: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_34:
    // 0x80800584: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800588: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080058C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800590: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800594: jal         0x800EFE50
    // 0x80800598: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EFE50(rdram, ctx);
        goto after_35;
    // 0x80800598: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_35:
    // 0x8080059C: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808005A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808005A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2344, 0X90C) << 16);
    // 0x808005A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808005AC: c.eq.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl == ctx->f12.fl;
    // 0x808005B0: nop

    // 0x808005B4: bc1tl       L_80800608
    if (c1cs) {
        // 0x808005B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800608;
    }
    goto skip_6;
    // 0x808005B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x808005BC: lwc1        $f14, 0x90C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2344, 0X90C));
    // 0x808005C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005C8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808005CC: jal         0x800F10B4
    // 0x808005D0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_36;
    // 0x808005D0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_36:
    // 0x808005D4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808005D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808005DC: nop

    // 0x808005E0: mul.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808005E4: jal         0x80013970
    // 0x808005E8: nop

    func_80013970(rdram, ctx);
        goto after_37;
    // 0x808005E8: nop

    after_37:
    // 0x808005EC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808005F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005F4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808005F8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808005FC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800600: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80800604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800608:
    // 0x80800608: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080060C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800610: jr          $ra
    // 0x80800614: nop

    return;
    // 0x80800614: nop

;}
RECOMP_FUNC void _subaddieaudioquick_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D20: syscall     809
    recomp_syscall_handler(rdram, ctx, 0x80089D20);
    return;
    // 0x80089D24: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800BA8_chmole_training(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA8: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80800BAC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800BB0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800BB4: nop

    // 0x80800BB8: addiu       $t8, $t7, -0xA
    ctx->r24 = ADD32(ctx->r15, -0XA);
    // 0x80800BBC: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x80800BC0: beq         $at, $zero, L_80800C10
    if (ctx->r1 == 0) {
        // 0x80800BC4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800C10;
    }
    // 0x80800BC4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800BC8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1604, 0XDE0) << 16);
    // 0x80800BCC: addu        $at, $at, $t8
    gpr jr_addend_80800BD4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800BD0: lw          $t8, 0xDE0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1604, 0XDE0));
    // 0x80800BD4: jr          $t8
    // 0x80800BD8: nop

    switch (jr_addend_80800BD4 >> 2) {
        case 0: goto L_80800BDC; break;
        case 1: goto L_80800BDC; break;
        case 2: goto L_80800BDC; break;
        case 3: goto L_80800BDC; break;
        case 4: goto L_80800BDC; break;
        case 5: goto L_80800BDC; break;
        case 6: goto L_80800BDC; break;
        case 7: goto L_80800BDC; break;
        case 8: goto L_80800BDC; break;
        case 9: goto L_80800BDC; break;
        case 10: goto L_80800BDC; break;
        case 11: goto L_80800BDC; break;
        case 12: goto L_80800BDC; break;
        case 13: goto L_80800BDC; break;
        case 14: goto L_80800BDC; break;
        case 15: goto L_80800BDC; break;
        case 16: goto L_80800BDC; break;
        default: switch_error(__func__, 0x80800BD4, 0x80800DE0);
    }
    // 0x80800BD8: nop

L_80800BDC:
    // 0x80800BDC: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800BE0: lbu         $t1, 0x72($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X72);
    // 0x80800BE4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800BE8: andi        $t2, $t1, 0xFF03
    ctx->r10 = ctx->r9 & 0XFF03;
    // 0x80800BEC: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x80800BF0: sb          $t3, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r11;
    // 0x80800BF4: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80800BF8: nop

    // 0x80800BFC: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80800C00: nop

    // 0x80800C04: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800C08: jr          $ra
    // 0x80800C0C: swc1        $f18, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x80800C0C: swc1        $f18, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f18.u32l;
L_80800C10:
    // 0x80800C10: lbu         $t4, 0x72($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X72);
    // 0x80800C14: andi        $t5, $t4, 0xFF03
    ctx->r13 = ctx->r12 & 0XFF03;
    // 0x80800C18: ori         $t6, $t5, 0x2C
    ctx->r14 = ctx->r13 | 0X2C;
    // 0x80800C1C: sb          $t6, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r14;
    // 0x80800C20: jr          $ra
    // 0x80800C24: nop

    return;
    // 0x80800C24: nop

;}
RECOMP_FUNC void _bsdronebubbled_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083078: syscall     40
    recomp_syscall_handler(rdram, ctx, 0x80083078);
    return;
    // 0x8008307C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800A00_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A08: jal         0x8080064C
    // 0x80800A0C: nop

    bstrexlarge_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800A0C: nop

    after_0:
    // 0x80800A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A18: jr          $ra
    // 0x80800A1C: nop

    return;
    // 0x80800A1C: nop

;}
RECOMP_FUNC void func_80800070_chgruntylairexttowerwindow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800074: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800078: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080007C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800080: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1964, 0XD0) << 16);
    // 0x80800084: addiu       $t7, $t7, 0xD0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1964, 0XD0));
    // 0x80800088: lw          $a3, 0x38($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X38);
    // 0x8080008C: addiu       $a1, $t6, 0x4
    ctx->r5 = ADD32(ctx->r14, 0X4);
    // 0x80800090: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800094: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800098: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080009C: jal         0x800BABB8
    // 0x808000A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x808000A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808000A4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1964, 0X13C) << 16);
    // 0x808000A8: addiu       $a1, $a1, 0x13C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1964, 0X13C));
    // 0x808000AC: jal         0x800C4AF0
    // 0x808000B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800C4AF0(rdram, ctx);
        goto after_1;
    // 0x808000B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808000B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void idworld_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080013C: jal         0x80800000
    // 0x80800140: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_idworld(rdram, ctx);
        goto after_0;
    // 0x80800140: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800144: beq         $v0, $zero, L_80800154
    if (ctx->r2 == 0) {
        // 0x80800148: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800154;
    }
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080014C: b           L_80800158
    // 0x80800150: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
        goto L_80800158;
    // 0x80800150: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
L_80800154:
    // 0x80800154: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800158:
    // 0x80800158: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080015C: jr          $ra
    // 0x80800160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808070C0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808070C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808070C4: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x808070C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808070CC: bne         $a1, $at, L_80807134
    if (ctx->r5 != ctx->r1) {
        // 0x808070D0: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80807134;
    }
    // 0x808070D0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808070D4: jal         0x80100094
    // 0x808070D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808070D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808070DC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808070E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808070E4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x808070E8: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x808070EC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x808070F0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x808070F4: jal         0x80087B70
    // 0x808070F8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    _gczoombox_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x808070F8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    after_1:
    // 0x808070FC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80807100: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80807104: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x80807108: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8080710C: jal         0x80087B60
    // 0x80807110: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _gczoombox_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x80807110: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80807114: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80807118: jal         0x80087B28
    // 0x8080711C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _gczoombox_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x8080711C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_3:
    // 0x80807120: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80807124: jal         0x80087B38
    // 0x80807128: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    _gczoombox_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80807128: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_4:
    // 0x8080712C: b           L_8080713C
    // 0x80807130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080713C;
    // 0x80807130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80807134:
    // 0x80807134: b           L_8080713C
    // 0x80807138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080713C;
    // 0x80807138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080713C:
    // 0x8080713C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807140: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80807144: jr          $ra
    // 0x80807148: nop

    return;
    // 0x80807148: nop

;}
RECOMP_FUNC void func_80090270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090278: jal         0x800F54E4
    // 0x8009027C: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8009027C: nop

    after_0:
    // 0x80090280: jal         0x800F6CC8
    // 0x80090284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6CC8(rdram, ctx);
        goto after_1;
    // 0x80090284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80090288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009028C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090290: jr          $ra
    // 0x80090294: nop

    return;
    // 0x80090294: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802B38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80802B3C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80802B40: jal         0x80802458
    // 0x80802B44: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80802458_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80802B44: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80802B48: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80802B4C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80802B50: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x80802B54: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80802B58: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80802B5C: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x80802B60: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80802B64: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80802B68: jal         0x800D3948
    // 0x80802B6C: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    func_800D3948(rdram, ctx);
        goto after_1;
    // 0x80802B6C: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    after_1:
    // 0x80802B70: bne         $v0, $zero, L_80802B8C
    if (ctx->r2 != 0) {
        // 0x80802B74: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80802B8C;
    }
    // 0x80802B74: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80802B78: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA458) << 16);
    // 0x80802B7C: lwc1        $f16, -0x5BA8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA458));
    // 0x80802B80: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80802B84: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80802B88: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80802B8C:
    // 0x80802B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802B90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802B94: jr          $ra
    // 0x80802B98: nop

    return;
    // 0x80802B98: nop

;}
RECOMP_FUNC void func_80800CC4_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CC8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CD0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800CD4: jal         0x800DC298
    // 0x80800CD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x80800CD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800CDC: beq         $v0, $zero, L_80800CEC
    if (ctx->r2 == 0) {
        // 0x80800CE0: addiu       $a0, $zero, 0x518
        ctx->r4 = ADD32(0, 0X518);
            goto L_80800CEC;
    }
    // 0x80800CE0: addiu       $a0, $zero, 0x518
    ctx->r4 = ADD32(0, 0X518);
    // 0x80800CE4: b           L_80800CEC
    // 0x80800CE8: addiu       $a0, $zero, 0x517
    ctx->r4 = ADD32(0, 0X517);
        goto L_80800CEC;
    // 0x80800CE8: addiu       $a0, $zero, 0x517
    ctx->r4 = ADD32(0, 0X517);
L_80800CEC:
    // 0x80800CEC: jal         0x800C4B7C
    // 0x80800CF0: nop

    func_800C4B7C(rdram, ctx);
        goto after_1;
    // 0x80800CF0: nop

    after_1:
    // 0x80800CF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800CF8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1516, 0X1064) << 16);
    // 0x80800CFC: addiu       $a2, $a2, 0x1064
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1516, 0X1064));
    // 0x80800D00: jal         0x80089D18
    // 0x80800D04: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800D04: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x80800D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D10: jr          $ra
    // 0x80800D14: nop

    return;
    // 0x80800D14: nop

;}
RECOMP_FUNC void chgobihailfire_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1208, 0X788) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x788
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1208, 0X788));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x788
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1208, 0X788));
;}
RECOMP_FUNC void func_80800B74_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800B80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800B84: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800B88: jal         0x800DA298
    // 0x80800B8C: addiu       $a0, $zero, 0x67E
    ctx->r4 = ADD32(0, 0X67E);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800B8C: addiu       $a0, $zero, 0x67E
    ctx->r4 = ADD32(0, 0X67E);
    after_0:
    // 0x80800B90: bne         $v0, $zero, L_80800BAC
    if (ctx->r2 != 0) {
        // 0x80800B94: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800BAC;
    }
    // 0x80800B94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B9C: jal         0x80101FDC
    // 0x80800BA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800BA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800BA4: b           L_80800BC4
    // 0x80800BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800BC4;
    // 0x80800BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BAC:
    // 0x80800BAC: jal         0x80101FDC
    // 0x80800BB0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800BB0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800BB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BB8: jal         0x8008A4B0
    // 0x80800BBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800BBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BC4:
    // 0x80800BC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BC8: jr          $ra
    // 0x80800BCC: nop

    return;
    // 0x80800BCC: nop

;}
RECOMP_FUNC void func_800BF4DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF4DC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BF4E0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BF4E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BF4E8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BF4EC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BF4F0: addiu       $t7, $t7, -0x7A50
    ctx->r15 = ADD32(ctx->r15, -0X7A50);
    // 0x800BF4F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BF4F8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800BF4FC: lbu         $t8, 0x2B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2B);
    // 0x800BF500: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BF504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF508: beql        $a1, $t8, L_800BF534
    if (ctx->r5 == ctx->r24) {
        // 0x800BF50C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BF534;
    }
    goto skip_0;
    // 0x800BF50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800BF510: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800BF514: beql        $a0, $zero, L_800BF534
    if (ctx->r4 == 0) {
        // 0x800BF518: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BF534;
    }
    goto skip_1;
    // 0x800BF518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800BF51C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BF520: jal         0x80088F48
    // 0x800BF524: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _idworldmake_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800BF524: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800BF528: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF52C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800BF530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BF534:
    // 0x800BF534: sb          $a1, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r5;
    // 0x800BF538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BF53C: jr          $ra
    // 0x800BF540: nop

    return;
    // 0x800BF540: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800C58: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800C5C: jal         0x8008E430
    // 0x80800C60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8008E430(rdram, ctx);
        goto after_0;
    // 0x80800C60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800C64: beq         $v0, $zero, L_80800C84
    if (ctx->r2 == 0) {
        // 0x80800C68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C84;
    }
    // 0x80800C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C6C: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80800C70: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800C74: jal         0x8008CB3C
    // 0x80800C78: addiu       $a1, $zero, 0x29B
    ctx->r5 = ADD32(0, 0X29B);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800C78: addiu       $a1, $zero, 0x29B
    ctx->r5 = ADD32(0, 0X29B);
    after_1:
    // 0x80800C7C: b           L_80800CC4
    // 0x80800C80: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
        goto L_80800CC4;
    // 0x80800C80: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
L_80800C84:
    // 0x80800C84: jal         0x8008E40C
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E40C(rdram, ctx);
        goto after_2;
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800C8C: beq         $v0, $zero, L_80800CB0
    if (ctx->r2 == 0) {
        // 0x80800C90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CB0;
    }
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C94: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80800C98: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA0: jal         0x8008CB3C
    // 0x80800CA4: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_3;
    // 0x80800CA4: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    after_3:
    // 0x80800CA8: b           L_80800CC4
    // 0x80800CAC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
        goto L_80800CC4;
    // 0x80800CAC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
L_80800CB0:
    // 0x80800CB0: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80800CB4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800CB8: jal         0x8008CB3C
    // 0x80800CBC: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_4;
    // 0x80800CBC: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_4:
    // 0x80800CC0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
L_80800CC4:
    // 0x80800CC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800CD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800CD4: jal         0x8009FFD8
    // 0x80800CD8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_5;
    // 0x80800CD8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80800CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE0: jal         0x8009B9B0
    // 0x80800CE4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x80800CE4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800CE8: jal         0x80800538
    // 0x80800CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800538_bsbtrot(rdram, ctx);
        goto after_7;
    // 0x80800CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800CF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800CF4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800CF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CFC: jr          $ra
    // 0x80800D00: nop

    return;
    // 0x80800D00: nop

;}
RECOMP_FUNC void _bsstatue_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083BD8: syscall     91
    recomp_syscall_handler(rdram, ctx, 0x80083BD8);
    return;
    // 0x80083BDC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800A9CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9CD0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9CD4: jr          $ra
    // 0x800A9CD8: lbu         $v0, 0x7760($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7760);
    return;
    // 0x800A9CD8: lbu         $v0, 0x7760($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7760);
;}
RECOMP_FUNC void func_8080106C_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080106C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801070: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801074: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801078: jal         0x800D8FF8
    // 0x8080107C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8080107C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801080: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801084: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801088: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x8080108C: jal         0x800EFA20
    // 0x80801090: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x80801090: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80801094: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80801098: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080109C: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808010A0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808010A4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808010A8: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x808010AC: beq         $at, $zero, L_80801574
    if (ctx->r1 == 0) {
        // 0x808010B0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80801574;
    }
    // 0x808010B0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808010B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1720) << 16);
    // 0x808010B8: addu        $at, $at, $t8
    gpr jr_addend_808010C0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808010BC: lw          $t8, 0x1720($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1720));
    // 0x808010C0: jr          $t8
    // 0x808010C4: nop

    switch (jr_addend_808010C0 >> 2) {
        case 0: goto L_808010C8; break;
        case 1: goto L_80801198; break;
        case 2: goto L_808012B4; break;
        case 3: goto L_80801458; break;
        case 4: goto L_808014F0; break;
        default: switch_error(__func__, 0x808010C0, 0x80801720);
    }
    // 0x808010C4: nop

L_808010C8:
    // 0x808010C8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808010CC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x808010D0: jal         0x800EF04C
    // 0x808010D4: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x808010D4: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x808010D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1734) << 16);
    // 0x808010DC: lwc1        $f0, 0x1734($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1734));
    // 0x808010E0: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808010E4: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808010E8: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808010EC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808010F0: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808010F4: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808010F8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808010FC: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80801100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801104: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80801108: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x8080110C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801110: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x80801114: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801118: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8080111C: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x80801120: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80801124: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80801128: nop

    // 0x8080112C: bc1fl       L_80801144
    if (!c1cs) {
        // 0x80801130: lui         $at, 0x43C8
        ctx->r1 = S32(0X43C8 << 16);
            goto L_80801144;
    }
    goto skip_0;
    // 0x80801130: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    skip_0:
    // 0x80801134: jal         0x80800EE4
    // 0x80801138: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    func_80800EE4_chtoothyfish(rdram, ctx);
        goto after_3;
    // 0x80801138: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x8080113C: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80801140: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
L_80801144:
    // 0x80801144: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801148: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080114C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801150: mul.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80801154: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80801158: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080115C: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80801160: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1738) << 16);
    // 0x80801164: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80801168: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8080116C: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x80801170: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x80801174: jal         0x800DC298
    // 0x80801178: lwc1        $f12, 0x1738($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1738));
    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x80801178: lwc1        $f12, 0x1738($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1738));
    after_4:
    // 0x8080117C: beq         $v0, $zero, L_80801574
    if (ctx->r2 == 0) {
        // 0x80801180: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80801574;
    }
    // 0x80801180: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801184: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80801188: jal         0x80800F6C
    // 0x8080118C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80800F6C_chtoothyfish(rdram, ctx);
        goto after_5;
    // 0x8080118C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x80801190: b           L_80801578
    // 0x80801194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801578;
    // 0x80801194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801198:
    // 0x80801198: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080119C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x808011A0: jal         0x800EF04C
    // 0x808011A4: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x808011A4: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    after_6:
    // 0x808011A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X173C) << 16);
    // 0x808011AC: lwc1        $f0, 0x173C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X173C));
    // 0x808011B0: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808011B4: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808011B8: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808011BC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808011C0: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808011C4: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x808011C8: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808011CC: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808011D0: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808011D4: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x808011D8: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x808011DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808011E0: addiu       $a3, $s0, 0x1C
    ctx->r7 = ADD32(ctx->r16, 0X1C);
    // 0x808011E4: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x808011E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808011EC: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x808011F0: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x808011F4: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x808011F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808011FC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80801200: jal         0x80089830
    // 0x80801204: nop

    _subaddie3d_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80801204: nop

    after_7:
    // 0x80801208: beq         $v0, $zero, L_80801260
    if (ctx->r2 == 0) {
        // 0x8080120C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801260;
    }
    // 0x8080120C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801210: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80801214: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801218: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080121C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801220: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801224: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80801228: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080122C: add.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80801230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801234: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80801238: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8080123C: nop

    // 0x80801240: bc1f        L_80801250
    if (!c1cs) {
        // 0x80801244: nop
    
            goto L_80801250;
    }
    // 0x80801244: nop

    // 0x80801248: b           L_8080128C
    // 0x8080124C: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
        goto L_8080128C;
    // 0x8080124C: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_80801250:
    // 0x80801250: jal         0x80800EE4
    // 0x80801254: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800EE4_chtoothyfish(rdram, ctx);
        goto after_8;
    // 0x80801254: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x80801258: b           L_8080128C
    // 0x8080125C: nop

        goto L_8080128C;
    // 0x8080125C: nop

L_80801260:
    // 0x80801260: jal         0x80102D4C
    // 0x80801264: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102D4C(rdram, ctx);
        goto after_9;
    // 0x80801264: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_9:
    // 0x80801268: beq         $v0, $zero, L_80801284
    if (ctx->r2 == 0) {
        // 0x8080126C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801284;
    }
    // 0x8080126C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801274: jal         0x80800EE4
    // 0x80801278: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800EE4_chtoothyfish(rdram, ctx);
        goto after_10;
    // 0x80801278: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x8080127C: b           L_8080128C
    // 0x80801280: nop

        goto L_8080128C;
    // 0x80801280: nop

L_80801284:
    // 0x80801284: jal         0x80102B6C
    // 0x80801288: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102B6C(rdram, ctx);
        goto after_11;
    // 0x80801288: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_11:
L_8080128C:
    // 0x8080128C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1740) << 16);
    // 0x80801290: jal         0x800DC298
    // 0x80801294: lwc1        $f12, 0x1740($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1740));
    func_800DC298(rdram, ctx);
        goto after_12;
    // 0x80801294: lwc1        $f12, 0x1740($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1740));
    after_12:
    // 0x80801298: beq         $v0, $zero, L_80801574
    if (ctx->r2 == 0) {
        // 0x8080129C: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80801574;
    }
    // 0x8080129C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808012A0: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x808012A4: jal         0x80800F6C
    // 0x808012A8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80800F6C_chtoothyfish(rdram, ctx);
        goto after_13;
    // 0x808012A8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_13:
    // 0x808012AC: b           L_80801578
    // 0x808012B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801578;
    // 0x808012B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808012B4:
    // 0x808012B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1744) << 16);
    // 0x808012B8: lwc1        $f0, 0x1744($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1744));
    // 0x808012BC: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808012C0: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808012C4: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808012C8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808012CC: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808012D0: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x808012D4: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808012D8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808012DC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808012E0: mul.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x808012E4: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x808012E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808012EC: addiu       $a3, $s0, 0x1C
    ctx->r7 = ADD32(ctx->r16, 0X1C);
    // 0x808012F0: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
    // 0x808012F4: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808012F8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x808012FC: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80801300: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80801304: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80801308: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080130C: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801310: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x80801314: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x80801318: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8080131C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80801320: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80801324: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80801328: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8080132C: jal         0x80089830
    // 0x80801330: nop

    _subaddie3d_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x80801330: nop

    after_14:
    // 0x80801334: beq         $v0, $zero, L_8080138C
    if (ctx->r2 == 0) {
        // 0x80801338: lwc1        $f6, 0x38($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
            goto L_8080138C;
    }
    // 0x80801338: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080133C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80801340: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801344: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801348: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080134C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801350: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80801354: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80801358: add.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8080135C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801360: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80801364: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80801368: nop

    // 0x8080136C: bc1f        L_8080137C
    if (!c1cs) {
        // 0x80801370: nop
    
            goto L_8080137C;
    }
    // 0x80801370: nop

    // 0x80801374: b           L_80801398
    // 0x80801378: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
        goto L_80801398;
    // 0x80801378: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_8080137C:
    // 0x8080137C: jal         0x80800EE4
    // 0x80801380: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800EE4_chtoothyfish(rdram, ctx);
        goto after_15;
    // 0x80801380: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_15:
    // 0x80801384: b           L_8080139C
    // 0x80801388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080139C;
    // 0x80801388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080138C:
    // 0x8080138C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801390: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801394: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_80801398:
    // 0x80801398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080139C:
    // 0x8080139C: jal         0x80102D4C
    // 0x808013A0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_80102D4C(rdram, ctx);
        goto after_16;
    // 0x808013A0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_16:
    // 0x808013A4: bne         $v0, $zero, L_808013B4
    if (ctx->r2 != 0) {
        // 0x808013A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808013B4;
    }
    // 0x808013A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013AC: jal         0x80102B6C
    // 0x808013B0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_80102B6C(rdram, ctx);
        goto after_17;
    // 0x808013B0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_17:
L_808013B4:
    // 0x808013B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013B8: jal         0x80102CF4
    // 0x808013BC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_80102CF4(rdram, ctx);
        goto after_18;
    // 0x808013BC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_18:
    // 0x808013C0: bne         $v0, $zero, L_808013D0
    if (ctx->r2 != 0) {
        // 0x808013C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808013D0;
    }
    // 0x808013C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013C8: jal         0x80102B2C
    // 0x808013CC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_80102B2C(rdram, ctx);
        goto after_19;
    // 0x808013CC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_19:
L_808013D0:
    // 0x808013D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1748) << 16);
    // 0x808013D4: jal         0x800DC298
    // 0x808013D8: lwc1        $f12, 0x1748($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1748));
    func_800DC298(rdram, ctx);
        goto after_20;
    // 0x808013D8: lwc1        $f12, 0x1748($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1748));
    after_20:
    // 0x808013DC: beq         $v0, $zero, L_808013FC
    if (ctx->r2 == 0) {
        // 0x808013E0: lui         $at, 0x430C
        ctx->r1 = S32(0X430C << 16);
            goto L_808013FC;
    }
    // 0x808013E0: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x808013E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808013E8: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x808013EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808013F0: jal         0x800DC178
    // 0x808013F4: nop

    func_800DC178(rdram, ctx);
        goto after_21;
    // 0x808013F4: nop

    after_21:
    // 0x808013F8: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
L_808013FC:
    // 0x808013FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X174C) << 16);
    // 0x80801400: jal         0x800DC298
    // 0x80801404: lwc1        $f12, 0x174C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X174C));
    func_800DC298(rdram, ctx);
        goto after_22;
    // 0x80801404: lwc1        $f12, 0x174C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X174C));
    after_22:
    // 0x80801408: beq         $v0, $zero, L_80801430
    if (ctx->r2 == 0) {
        // 0x8080140C: lui         $at, 0xC2B4
        ctx->r1 = S32(0XC2B4 << 16);
            goto L_80801430;
    }
    // 0x8080140C: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80801410: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801414: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801418: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080141C: jal         0x800DC178
    // 0x80801420: nop

    func_800DC178(rdram, ctx);
        goto after_23;
    // 0x80801420: nop

    after_23:
    // 0x80801424: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801428: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8080142C: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
L_80801430:
    // 0x80801430: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1750) << 16);
    // 0x80801434: jal         0x800DC298
    // 0x80801438: lwc1        $f12, 0x1750($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1750));
    func_800DC298(rdram, ctx);
        goto after_24;
    // 0x80801438: lwc1        $f12, 0x1750($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1750));
    after_24:
    // 0x8080143C: beq         $v0, $zero, L_80801574
    if (ctx->r2 == 0) {
        // 0x80801440: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80801574;
    }
    // 0x80801440: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801444: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80801448: jal         0x80800F6C
    // 0x8080144C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80800F6C_chtoothyfish(rdram, ctx);
        goto after_25;
    // 0x8080144C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_25:
    // 0x80801450: b           L_80801578
    // 0x80801454: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801578;
    // 0x80801454: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801458:
    // 0x80801458: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080145C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801460: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801464: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80801468: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080146C: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80801470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801474: add.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80801478: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8080147C: nop

    // 0x80801480: bc1fl       L_808014A0
    if (!c1cs) {
        // 0x80801484: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_808014A0;
    }
    goto skip_1;
    // 0x80801484: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_1:
    // 0x80801488: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080148C: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80801490: add.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80801494: b           L_808014BC
    // 0x80801498: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_808014BC;
    // 0x80801498: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8080149C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_808014A0:
    // 0x808014A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808014A4: bc1f        L_808014BC
    if (!c1cs) {
        // 0x808014A8: nop
    
            goto L_808014BC;
    }
    // 0x808014A8: nop

    // 0x808014AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808014B0: nop

    // 0x808014B4: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808014B8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_808014BC:
    // 0x808014BC: jal         0x80102D4C
    // 0x808014C0: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102D4C(rdram, ctx);
        goto after_26;
    // 0x808014C0: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_26:
    // 0x808014C4: bne         $v0, $zero, L_808014E0
    if (ctx->r2 != 0) {
        // 0x808014C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808014E0;
    }
    // 0x808014C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014D0: jal         0x80102B6C
    // 0x808014D4: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102B6C(rdram, ctx);
        goto after_27;
    // 0x808014D4: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_27:
    // 0x808014D8: b           L_80801578
    // 0x808014DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801578;
    // 0x808014DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808014E0:
    // 0x808014E0: jal         0x80800EE4
    // 0x808014E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800EE4_chtoothyfish(rdram, ctx);
        goto after_28;
    // 0x808014E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_28:
    // 0x808014E8: b           L_80801578
    // 0x808014EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801578;
    // 0x808014EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808014F0:
    // 0x808014F0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808014F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808014F8: lwc1        $f12, 0x38($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808014FC: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80801500: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801504: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80801508: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080150C: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x80801510: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80801514: nop

    // 0x80801518: bc1fl       L_80801538
    if (!c1cs) {
        // 0x8080151C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80801538;
    }
    goto skip_2;
    // 0x8080151C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_2:
    // 0x80801520: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80801524: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80801528: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8080152C: b           L_80801574
    // 0x80801530: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
        goto L_80801574;
    // 0x80801530: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80801534: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80801538:
    // 0x80801538: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080153C: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80801540: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x80801544: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80801548: nop

    // 0x8080154C: bc1fl       L_8080156C
    if (!c1cs) {
        // 0x80801550: lbu         $t9, 0x7E($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X7E);
            goto L_8080156C;
    }
    goto skip_3;
    // 0x80801550: lbu         $t9, 0x7E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7E);
    skip_3:
    // 0x80801554: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801558: nop

    // 0x8080155C: add.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80801560: b           L_80801574
    // 0x80801564: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
        goto L_80801574;
    // 0x80801564: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80801568: lbu         $t9, 0x7E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7E);
L_8080156C:
    // 0x8080156C: andi        $t0, $t9, 0xFFBF
    ctx->r8 = ctx->r25 & 0XFFBF;
    // 0x80801570: sb          $t0, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r8;
L_80801574:
    // 0x80801574: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801578:
    // 0x80801578: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080157C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801580: jr          $ra
    // 0x80801584: nop

    return;
    // 0x80801584: nop

;}
RECOMP_FUNC void _bsbanshack_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082720: syscall     8
    recomp_syscall_handler(rdram, ctx, 0x80082720);
    return;
    // 0x80082724: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808001E8_chhotfloorsmoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808001EC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808001F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001F4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808001F8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808001FC: jal         0x800E3E8C
    // 0x80800200: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    func_800E3E8C(rdram, ctx);
        goto after_0;
    // 0x80800200: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_0:
    // 0x80800204: beq         $v0, $zero, L_80800288
    if (ctx->r2 == 0) {
        // 0x80800208: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_80800288;
    }
    // 0x80800208: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080020C: jal         0x800EE7F8
    // 0x80800210: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800210: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x80800214: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800218: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080021C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800220: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800224: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80800228: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8080022C: jal         0x800EE7F8
    // 0x80800230: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800230: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800234: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800238: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080023C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800240: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80800244: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800248: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8080024C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(928, 0X318) << 16);
    // 0x80800250: addiu       $v0, $v0, 0x318
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(928, 0X318));
    // 0x80800254: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800258: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8080025C: lw          $t7, 0x6C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X6C);
    // 0x80800260: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800264: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800268: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x8080026C: bne         $t8, $at, L_80800280
    if (ctx->r24 != ctx->r1) {
        // 0x80800270: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_80800280;
    }
    // 0x80800270: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800274: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(928, 0X350) << 16);
    // 0x80800278: b           L_80800280
    // 0x8080027C: addiu       $v0, $v0, 0x350
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(928, 0X350));
        goto L_80800280;
    // 0x8080027C: addiu       $v0, $v0, 0x350
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(928, 0X350));
L_80800280:
    // 0x80800280: jal         0x800BABB8
    // 0x80800284: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x80800284: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
L_80800288:
    // 0x80800288: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8080028C: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x80800290: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x80800294: bgezl       $t2, L_808002C0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800298: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002C0;
    }
    goto skip_0;
    // 0x80800298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080029C: jal         0x800DA298
    // 0x808002A0: addiu       $a0, $zero, 0x66F
    ctx->r4 = ADD32(0, 0X66F);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808002A0: addiu       $a0, $zero, 0x66F
    ctx->r4 = ADD32(0, 0X66F);
    after_4:
    // 0x808002A4: bne         $v0, $zero, L_808002BC
    if (ctx->r2 != 0) {
        // 0x808002A8: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_808002BC;
    }
    // 0x808002A8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808002AC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(928, 0X388) << 16);
    // 0x808002B0: addiu       $a2, $a2, 0x388
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(928, 0X388));
    // 0x808002B4: jal         0x80089D18
    // 0x808002B8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808002B8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_5:
L_808002BC:
    // 0x808002BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002C0:
    // 0x808002C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808002C4: jr          $ra
    // 0x808002C8: nop

    return;
    // 0x808002C8: nop

    // 0x808002CC: nop

;}
RECOMP_FUNC void func_8080111C_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080111C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801120: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X371C) << 16);
    // 0x80801124: lwc1        $f4, 0x371C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X371C));
    // 0x80801128: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080112C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801130: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801134: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080113C: jal         0x80100094
    // 0x80801140: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801140: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80801144: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801148: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080114C: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801150: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801158: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080115C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801160: jal         0x80105A9C
    // 0x80801164: nop

    func_80105A9C(rdram, ctx);
        goto after_1;
    // 0x80801164: nop

    after_1:
    // 0x80801168: jal         0x80105834
    // 0x8080116C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_2;
    // 0x8080116C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801170: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801174: jal         0x800F1DCC
    // 0x80801178: lwc1        $f14, 0xD4($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XD4);
    func_800F1DCC(rdram, ctx);
        goto after_3;
    // 0x80801178: lwc1        $f14, 0xD4($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XD4);
    after_3:
    // 0x8080117C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801180: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801184: lwc1        $f4, 0xD8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x80801188: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3720) << 16);
    // 0x8080118C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801190: lwc1        $f8, 0x3720($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3720));
    // 0x80801194: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801198: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x8080119C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808011A0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x808011A4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808011A8: swc1        $f10, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f10.u32l;
    // 0x808011AC: lwc1        $f16, 0xD8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x808011B0: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808011B4: jal         0x800F10B4
    // 0x808011B8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808011B8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x808011BC: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x808011C0: lbu         $t6, 0xFD($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XFD);
    // 0x808011C4: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808011C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808011CC: bne         $t6, $zero, L_808011E4
    if (ctx->r14 != 0) {
        // 0x808011D0: swc1        $f18, 0xD4($s1)
        MEM_W(0XD4, ctx->r17) = ctx->f18.u32l;
            goto L_808011E4;
    }
    // 0x808011D0: swc1        $f18, 0xD4($s1)
    MEM_W(0XD4, ctx->r17) = ctx->f18.u32l;
    // 0x808011D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808011D8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808011DC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x808011E0: sb          $t7, 0xFD($s1)
    MEM_B(0XFD, ctx->r17) = ctx->r15;
L_808011E4:
    // 0x808011E4: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808011E8: jal         0x800F1DCC
    // 0x808011EC: lwc1        $f14, 0x44($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X44);
    func_800F1DCC(rdram, ctx);
        goto after_5;
    // 0x808011EC: lwc1        $f14, 0x44($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X44);
    after_5:
    // 0x808011F0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808011F4: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808011F8: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808011FC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80801200: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801204: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80801208: jal         0x800F1DCC
    // 0x8080120C: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_6;
    // 0x8080120C: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    after_6:
    // 0x80801210: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801214: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080121C: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801220: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80801224: jal         0x80801044
    // 0x80801228: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    func_80801044_chclockworkmouse(rdram, ctx);
        goto after_7;
    // 0x80801228: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    after_7:
    // 0x8080122C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801230: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801234: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801238: jr          $ra
    // 0x8080123C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080123C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gcskyDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004E4: jal         0x800EA05C
    // 0x808004E8: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808004E8: nop

    after_0:
    // 0x808004EC: jal         0x80800000
    // 0x808004F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800000_gcskyDll(rdram, ctx);
        goto after_1;
    // 0x808004F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808004F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004F8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x808004FC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800500: jr          $ra
    // 0x80800504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800508: nop

    // 0x8080050C: nop

;}
RECOMP_FUNC void func_80800898_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800898: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080089C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808008A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808008A8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808008AC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808008B0: jal         0x800D674C
    // 0x808008B4: addiu       $a0, $zero, 0x85C
    ctx->r4 = ADD32(0, 0X85C);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x808008B4: addiu       $a0, $zero, 0x85C
    ctx->r4 = ADD32(0, 0X85C);
    after_0:
    // 0x808008B8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808008BC: jal         0x80101970
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101970(rdram, ctx);
        goto after_1;
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C8: jal         0x80106A98
    // 0x808008CC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80106A98(rdram, ctx);
        goto after_2;
    // 0x808008CC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x808008D0: jal         0x800DF830
    // 0x808008D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_3;
    // 0x808008D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x808008D8: jal         0x80089C90
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808008E0: jal         0x800DF410
    // 0x808008E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF410(rdram, ctx);
        goto after_5;
    // 0x808008E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808008E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808008EC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808008F0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x808008F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808008F8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808008FC: jal         0x800EFA4C
    // 0x80800900: nop

    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x80800900: nop

    after_6:
    // 0x80800904: jal         0x801018D8
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801018D8(rdram, ctx);
        goto after_7;
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080090C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800910: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800914: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800918: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080091C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800920: jal         0x800DE448
    // 0x80800924: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800DE448(rdram, ctx);
        goto after_8;
    // 0x80800924: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_8:
    // 0x80800928: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080092C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800930: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800934: jr          $ra
    // 0x80800938: nop

    return;
    // 0x80800938: nop

;}
RECOMP_FUNC void bsswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A10: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A14: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(384, 0XBB4) << 16);
    // 0x80800A18: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A1C: jr          $ra
    // 0x80800A20: lw          $v0, 0xBB4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(384, 0XBB4));
    return;
    // 0x80800A20: lw          $v0, 0xBB4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(384, 0XBB4));
;}
RECOMP_FUNC void chnests_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F44: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X1230) << 16);
    // 0x80800F48: jr          $ra
    // 0x80800F4C: addiu       $v0, $v0, 0x1230
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1230));
    return;
    // 0x80800F4C: addiu       $v0, $v0, 0x1230
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1230));
;}
RECOMP_FUNC void _sumole_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A10: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A10);
    return;
    // 0x80089A14: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _fxdlsmoke_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088970: syscall     712
    recomp_syscall_handler(rdram, ctx, 0x80088970);
    return;
    // 0x80088974: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808000A0_charea51gate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000A4: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x808000A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000AC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808000B0: beq         $a1, $at, L_808000E0
    if (ctx->r5 == ctx->r1) {
        // 0x808000B4: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_808000E0;
    }
    // 0x808000B4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808000B8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808000BC: beq         $a1, $at, L_80800180
    if (ctx->r5 == ctx->r1) {
        // 0x808000C0: lw          $t4, 0x48($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X48);
            goto L_80800180;
    }
    // 0x808000C0: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x808000C4: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x808000C8: beq         $a1, $at, L_8080019C
    if (ctx->r5 == ctx->r1) {
        // 0x808000CC: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_8080019C;
    }
    // 0x808000CC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000D0: beq         $a1, $at, L_808001AC
    if (ctx->r5 == ctx->r1) {
        // 0x808000D4: nop
    
            goto L_808001AC;
    }
    // 0x808000D4: nop

    // 0x808000D8: b           L_80800218
    // 0x808000DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800218;
    // 0x808000DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000E0:
    // 0x808000E0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808000E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808000E8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x808000EC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808000F0: jal         0x800EC398
    // 0x808000F4: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    func_800EC398(rdram, ctx);
        goto after_0;
    // 0x808000F4: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000F8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x808000FC: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x80800100: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x80800104: bnel        $t8, $zero, L_80800164
    if (ctx->r24 != 0) {
        // 0x80800108: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_80800164;
    }
    goto skip_0;
    // 0x80800108: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8080010C: lhu         $a0, 0x1A($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0X1A);
    // 0x80800110: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800114: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80800118: srl         $t9, $a0, 5
    ctx->r25 = S32(U32(ctx->r4) >> 5);
    // 0x8080011C: jal         0x800F64A4
    // 0x80800120: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x80800120: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x80800124: bne         $v0, $zero, L_80800150
    if (ctx->r2 != 0) {
        // 0x80800128: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_80800150;
    }
    // 0x80800128: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8080012C: lhu         $a0, 0x1A($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0X1A);
    // 0x80800130: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80800134: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800138: srl         $t0, $a0, 5
    ctx->r8 = S32(U32(ctx->r4) >> 5);
    // 0x8080013C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80800140: jal         0x800F79DC
    // 0x80800144: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    func_800F79DC(rdram, ctx);
        goto after_2;
    // 0x80800144: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    after_2:
    // 0x80800148: b           L_80800164
    // 0x8080014C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
        goto L_80800164;
    // 0x8080014C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_80800150:
    // 0x80800150: jal         0x8001210C
    // 0x80800154: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001210C(rdram, ctx);
        goto after_3;
    // 0x80800154: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x80800158: sltiu       $t2, $v0, 0x1
    ctx->r10 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8080015C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80800160: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_80800164:
    // 0x80800164: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800168: beq         $t3, $zero, L_80800178
    if (ctx->r11 == 0) {
        // 0x8080016C: nop
    
            goto L_80800178;
    }
    // 0x8080016C: nop

    // 0x80800170: jal         0x800862B8
    // 0x80800174: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _chelectricfence_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800174: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
L_80800178:
    // 0x80800178: b           L_80800218
    // 0x8080017C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800218;
    // 0x8080017C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800180:
    // 0x80800180: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x80800184: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800188: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8080018C: jal         0x80086678
    // 0x80800190: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _chexploder_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800190: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_5:
    // 0x80800194: b           L_80800218
    // 0x80800198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800218;
    // 0x80800198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080019C:
    // 0x8080019C: jal         0x80800228
    // 0x808001A0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80800228_charea51gate(rdram, ctx);
        goto after_6;
    // 0x808001A0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_6:
    // 0x808001A4: b           L_80800218
    // 0x808001A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800218;
    // 0x808001A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001AC:
    // 0x808001AC: jal         0x800F54E4
    // 0x808001B0: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x808001B0: nop

    after_7:
    // 0x808001B4: jal         0x800F6438
    // 0x808001B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_8;
    // 0x808001B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x808001BC: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
    // 0x808001C0: beq         $a0, $zero, L_808001E0
    if (ctx->r4 == 0) {
        // 0x808001C4: nop
    
            goto L_808001E0;
    }
    // 0x808001C4: nop

    // 0x808001C8: jal         0x800F54E4
    // 0x808001CC: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x808001CC: nop

    after_9:
    // 0x808001D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001D4: jal         0x800F64A4
    // 0x808001D8: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    func_800F64A4(rdram, ctx);
        goto after_10;
    // 0x808001D8: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    after_10:
    // 0x808001DC: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
L_808001E0:
    // 0x808001E0: beq         $a0, $zero, L_808001FC
    if (ctx->r4 == 0) {
        // 0x808001E4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808001FC;
    }
    // 0x808001E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001E8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808001EC: jal         0x80109EF4
    // 0x808001F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109EF4(rdram, ctx);
        goto after_11;
    // 0x808001F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808001F4: b           L_80800218
    // 0x808001F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800218;
    // 0x808001F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001FC:
    // 0x808001FC: jal         0x80109F08
    // 0x80800200: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80109F08(rdram, ctx);
        goto after_12;
    // 0x80800200: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_12:
    // 0x80800204: b           L_80800218
    // 0x80800208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800218;
    // 0x80800208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080020C: b           L_80800218
    // 0x80800210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800218;
    // 0x80800210: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800218:
    // 0x80800218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080021C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void func_80800914_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800914: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800918: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080091C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800920: lw          $a2, 0x18($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X18);
    // 0x80800924: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800928: bnel        $a2, $zero, L_80800954
    if (ctx->r6 != 0) {
        // 0x8080092C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800954;
    }
    goto skip_0;
    // 0x8080092C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x80800930: jal         0x800C8A98
    // 0x80800934: nop

    func_800C8A98(rdram, ctx);
        goto after_0;
    // 0x80800934: nop

    after_0:
    // 0x80800938: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8080093C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800940: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80800944: jal         0x800C8E54
    // 0x80800948: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    func_800C8E54(rdram, ctx);
        goto after_1;
    // 0x80800948: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_1:
    // 0x8080094C: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    // 0x80800950: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80800954:
    // 0x80800954: jal         0x800C8CB8
    // 0x80800958: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_2;
    // 0x80800958: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x8080095C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1264, 0X10E0) << 16);
    // 0x80800960: lwc1        $f12, 0x10E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1264, 0X10E0));
    // 0x80800964: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800968: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080096C: jal         0x800DC178
    // 0x80800970: nop

    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800970: nop

    after_3:
    // 0x80800974: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1264, 0X1100) << 16);
    // 0x80800978: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080097C: addiu       $a1, $a1, 0x1100
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1264, 0X1100));
    // 0x80800980: jal         0x800F2F60
    // 0x80800984: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800F2F60(rdram, ctx);
        goto after_4;
    // 0x80800984: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80800988: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x8080098C: jal         0x800C8E84
    // 0x80800990: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800C8E84(rdram, ctx);
        goto after_5;
    // 0x80800990: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80800994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800998: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080099C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808009A0: jr          $ra
    // 0x808009A4: nop

    return;
    // 0x808009A4: nop

;}
RECOMP_FUNC void baanim_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C764: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008C768: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008C76C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008C770: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008C774: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008C778: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008C77C: jal         0x8008AD80
    // 0x8008C780: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    func_8008AD80(rdram, ctx);
        goto after_0;
    // 0x8008C780: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    after_0:
    // 0x8008C784: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8008C788: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008C78C: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x8008C790: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8008C794: jal         0x8008B1A0
    // 0x8008C798: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_1;
    // 0x8008C798: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_1:
    // 0x8008C79C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8008C7A0: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8008C7A4: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8008C7A8: jal         0x8008B304
    // 0x8008C7AC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_8008B304(rdram, ctx);
        goto after_2;
    // 0x8008C7AC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_2:
    // 0x8008C7B0: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8008C7B4: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8008C7B8: addiu       $a1, $a1, -0x3B24
    ctx->r5 = ADD32(ctx->r5, -0X3B24);
    // 0x8008C7BC: jal         0x8008AEE4
    // 0x8008C7C0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    func_8008AEE4(rdram, ctx);
        goto after_3;
    // 0x8008C7C0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_3:
    // 0x8008C7C4: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x8008C7C8: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    // 0x8008C7CC: jal         0x8008AF04
    // 0x8008C7D0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    func_8008AF04(rdram, ctx);
        goto after_4;
    // 0x8008C7D0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_4:
    // 0x8008C7D4: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8008C7D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C7DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008C7E0: jal         0x8008CA4C
    // 0x8008C7E4: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
    func_8008CA4C(rdram, ctx);
        goto after_5;
    // 0x8008C7E4: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
    after_5:
    // 0x8008C7E8: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x8008C7EC: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x8008C7F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C7F4: jal         0x8008C9BC
    // 0x8008C7F8: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_6;
    // 0x8008C7F8: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_6:
    // 0x8008C7FC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8008C800: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008C804: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x8008C808: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8008C80C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C810: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8008C814: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x8008C818: jal         0x8008C9F0
    // 0x8008C81C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_7;
    // 0x8008C81C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x8008C820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C824: jal         0x8008C9E4
    // 0x8008C828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008C9E4(rdram, ctx);
        goto after_8;
    // 0x8008C828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8008C82C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C830: jal         0x8008C984
    // 0x8008C834: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8008C984(rdram, ctx);
        goto after_9;
    // 0x8008C834: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x8008C838: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x8008C83C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008C840: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008C844: sb          $zero, 0x38($t4)
    MEM_B(0X38, ctx->r12) = 0;
    // 0x8008C848: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x8008C84C: swc1        $f6, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f6.u32l;
    // 0x8008C850: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008C854: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008C858: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008C85C: jr          $ra
    // 0x8008C860: nop

    return;
    // 0x8008C860: nop

;}
RECOMP_FUNC void _chfireimp_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800865C8: syscall     343
    recomp_syscall_handler(rdram, ctx, 0x800865C8);
    return;
    // 0x800865CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
