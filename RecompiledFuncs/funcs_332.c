#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void basub_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void func_80800220_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800220: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800228: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080022C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800230: jal         0x80102424
    // 0x80800234: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800234: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800238: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8080023C: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80800240: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80800244: beq         $at, $zero, L_80800360
    if (ctx->r1 == 0) {
        // 0x80800248: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800360;
    }
    // 0x80800248: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080024C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(768, 0X1530) << 16);
    // 0x80800250: addu        $at, $at, $t7
    gpr jr_addend_80800258 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800254: lw          $t7, 0x1530($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(768, 0X1530));
    // 0x80800258: jr          $t7
    // 0x8080025C: nop

    switch (jr_addend_80800258 >> 2) {
        case 0: goto L_80800260; break;
        case 1: goto L_808002B0; break;
        case 2: goto L_808002F4; break;
        case 3: goto L_80800328; break;
        case 4: goto L_80800360; break;
        case 5: goto L_80800360; break;
        case 6: goto L_80800360; break;
        case 7: goto L_80800350; break;
        default: switch_error(__func__, 0x80800258, 0x80801530);
    }
    // 0x8080025C: nop

L_80800260:
    // 0x80800260: jal         0x8008F8B0
    // 0x80800264: nop

    func_8008F8B0(rdram, ctx);
        goto after_1;
    // 0x80800264: nop

    after_1:
    // 0x80800268: jal         0x8008F8D8
    // 0x8080026C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_2;
    // 0x8080026C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800270: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800274: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80800278: jal         0x8008F904
    // 0x8080027C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8008F904(rdram, ctx);
        goto after_3;
    // 0x8080027C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80800280: jal         0x8008F938
    // 0x80800284: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F938(rdram, ctx);
        goto after_4;
    // 0x80800284: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80800288: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080028C: jal         0x8008F990
    // 0x80800290: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    func_8008F990(rdram, ctx);
        goto after_5;
    // 0x80800290: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_5:
    // 0x80800294: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080029C: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x808002A0: jal         0x80085708
    // 0x808002A4: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    _capod_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x808002A4: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_6:
    // 0x808002A8: b           L_80800364
    // 0x808002AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800364;
    // 0x808002AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002B0:
    // 0x808002B0: jal         0x800C0658
    // 0x808002B4: nop

    func_800C0658(rdram, ctx);
        goto after_7;
    // 0x808002B4: nop

    after_7:
    // 0x808002B8: jal         0x8008F8B0
    // 0x808002BC: nop

    func_8008F8B0(rdram, ctx);
        goto after_8;
    // 0x808002BC: nop

    after_8:
    // 0x808002C0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x808002C4: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x808002C8: jal         0x8008F904
    // 0x808002CC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8008F904(rdram, ctx);
        goto after_9;
    // 0x808002CC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x808002D0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808002D4: jal         0x8008F9F8
    // 0x808002D8: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_8008F9F8(rdram, ctx);
        goto after_10;
    // 0x808002D8: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_10:
    // 0x808002DC: jal         0x8008F938
    // 0x808002E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8008F938(rdram, ctx);
        goto after_11;
    // 0x808002E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x808002E4: jal         0x80090658
    // 0x808002E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090658(rdram, ctx);
        goto after_12;
    // 0x808002E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x808002EC: b           L_80800364
    // 0x808002F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800364;
    // 0x808002F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002F4:
    // 0x808002F4: jal         0x800BEC10
    // 0x808002F8: nop

    func_800BEC10(rdram, ctx);
        goto after_13;
    // 0x808002F8: nop

    after_13:
    // 0x808002FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800300: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800304: jal         0x800DBEFC
    // 0x80800308: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800DBEFC(rdram, ctx);
        goto after_14;
    // 0x80800308: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_14:
    // 0x8080030C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800310: jal         0x80090734
    // 0x80800314: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80090734(rdram, ctx);
        goto after_15;
    // 0x80800314: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_15:
    // 0x80800318: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080031C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800320: b           L_80800360
    // 0x80800324: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800360;
    // 0x80800324: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800328:
    // 0x80800328: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(768, 0X17F0) << 16);
    // 0x8080032C: addiu       $a1, $a1, 0x17F0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(768, 0X17F0));
    // 0x80800330: addiu       $a0, $zero, 0x4B1
    ctx->r4 = ADD32(0, 0X4B1);
    // 0x80800334: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800338: jal         0x80108A30
    // 0x8080033C: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    func_80108A30(rdram, ctx);
        goto after_16;
    // 0x8080033C: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_16:
    // 0x80800340: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800344: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800348: b           L_80800360
    // 0x8080034C: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
        goto L_80800360;
    // 0x8080034C: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
L_80800350:
    // 0x80800350: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800354: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800358: jal         0x80101EE4
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101EE4(rdram, ctx);
        goto after_17;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_80800360:
    // 0x80800360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800364:
    // 0x80800364: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800368: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080036C: jr          $ra
    // 0x80800370: nop

    return;
    // 0x80800370: nop

;}
RECOMP_FUNC void _bskaztorpedo_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083798: syscall     72
    recomp_syscall_handler(rdram, ctx, 0x80083798);
    return;
    // 0x8008379C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bainvisible_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854C8: syscall     164
    recomp_syscall_handler(rdram, ctx, 0x800854C8);
    return;
    // 0x800854CC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _suflamefx_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089940: syscall     798
    recomp_syscall_handler(rdram, ctx, 0x80089940);
    return;
    // 0x80089944: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808015EC_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808015F0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808015F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808015F8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808015FC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80801600: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80801604: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801608: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080160C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801610: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801614: jal         0x80100094
    // 0x80801618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080161C: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80801620: jal         0x80088368
    // 0x80801624: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80801624: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_1:
    // 0x80801628: blez        $v0, L_80801730
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080162C: addiu       $s5, $zero, 0x3
        ctx->r21 = ADD32(0, 0X3);
            goto L_80801730;
    }
    // 0x8080162C: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x80801630: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x80801634: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80801638:
    // 0x80801638: jal         0x800F53D0
    // 0x8080163C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F53D0(rdram, ctx);
        goto after_2;
    // 0x8080163C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80801640: sll         $t6, $s1, 3
    ctx->r14 = S32(ctx->r17 << 3);
    // 0x80801644: addu        $s0, $s6, $t6
    ctx->r16 = ADD32(ctx->r22, ctx->r14);
    // 0x80801648: lw          $v1, 0x530($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X530);
    // 0x8080164C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801650: beq         $v1, $s3, L_80801670
    if (ctx->r3 == ctx->r19) {
        // 0x80801654: nop
    
            goto L_80801670;
    }
    // 0x80801654: nop

    // 0x80801658: beq         $v1, $s4, L_8080169C
    if (ctx->r3 == ctx->r20) {
        // 0x8080165C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8080169C;
    }
    // 0x8080165C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801660: beq         $v1, $s5, L_808016F8
    if (ctx->r3 == ctx->r21) {
        // 0x80801664: nop
    
            goto L_808016F8;
    }
    // 0x80801664: nop

    // 0x80801668: b           L_8080171C
    // 0x8080166C: nop

        goto L_8080171C;
    // 0x8080166C: nop

L_80801670:
    // 0x80801670: jal         0x800A4C68
    // 0x80801674: nop

    func_800A4C68(rdram, ctx);
        goto after_3;
    // 0x80801674: nop

    after_3:
    // 0x80801678: jal         0x800C96CC
    // 0x8080167C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C96CC(rdram, ctx);
        goto after_4;
    // 0x8080167C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80801680: beq         $v0, $zero, L_8080171C
    if (ctx->r2 == 0) {
        // 0x80801684: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080171C;
    }
    // 0x80801684: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801688: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080168C: jal         0x808013DC
    // 0x80801690: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_808013DC_chfpsgame(rdram, ctx);
        goto after_5;
    // 0x80801690: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_5:
    // 0x80801694: b           L_8080171C
    // 0x80801698: nop

        goto L_8080171C;
    // 0x80801698: nop

L_8080169C:
    // 0x8080169C: jal         0x80800074
    // 0x808016A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80800074_chfpsgame(rdram, ctx);
        goto after_6;
    // 0x808016A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x808016A4: bne         $v0, $zero, L_8080171C
    if (ctx->r2 != 0) {
        // 0x808016A8: nop
    
            goto L_8080171C;
    }
    // 0x808016A8: nop

    // 0x808016AC: jal         0x800D8FF8
    // 0x808016B0: nop

    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x808016B0: nop

    after_7:
    // 0x808016B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808016B8: jal         0x800F1574
    // 0x808016BC: addiu       $a0, $s0, 0x534
    ctx->r4 = ADD32(ctx->r16, 0X534);
    func_800F1574(rdram, ctx);
        goto after_8;
    // 0x808016BC: addiu       $a0, $s0, 0x534
    ctx->r4 = ADD32(ctx->r16, 0X534);
    after_8:
    // 0x808016C0: bnel        $v0, $zero, L_808016E4
    if (ctx->r2 != 0) {
        // 0x808016C4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808016E4;
    }
    goto skip_0;
    // 0x808016C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x808016C8: jal         0x800F54F0
    // 0x808016CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F54F0(rdram, ctx);
        goto after_9;
    // 0x808016CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x808016D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808016D4: jal         0x80016BBC
    // 0x808016D8: ori         $a1, $zero, 0xD000
    ctx->r5 = 0 | 0XD000;
    func_80016BBC(rdram, ctx);
        goto after_10;
    // 0x808016D8: ori         $a1, $zero, 0xD000
    ctx->r5 = 0 | 0XD000;
    after_10:
    // 0x808016DC: beq         $v0, $zero, L_8080171C
    if (ctx->r2 == 0) {
        // 0x808016E0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080171C;
    }
    // 0x808016E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808016E4:
    // 0x808016E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808016E8: jal         0x808013DC
    // 0x808016EC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_808013DC_chfpsgame(rdram, ctx);
        goto after_11;
    // 0x808016EC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_11:
    // 0x808016F0: b           L_8080171C
    // 0x808016F4: nop

        goto L_8080171C;
    // 0x808016F4: nop

L_808016F8:
    // 0x808016F8: jal         0x800A4C68
    // 0x808016FC: nop

    func_800A4C68(rdram, ctx);
        goto after_12;
    // 0x808016FC: nop

    after_12:
    // 0x80801700: jal         0x800C9714
    // 0x80801704: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C9714(rdram, ctx);
        goto after_13;
    // 0x80801704: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x80801708: beq         $v0, $zero, L_8080171C
    if (ctx->r2 == 0) {
        // 0x8080170C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080171C;
    }
    // 0x8080170C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801710: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801714: jal         0x808013DC
    // 0x80801718: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808013DC_chfpsgame(rdram, ctx);
        goto after_14;
    // 0x80801718: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
L_8080171C:
    // 0x8080171C: jal         0x80088368
    // 0x80801720: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x80801720: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_15:
    // 0x80801724: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801728: bne         $at, $zero, L_80801638
    if (ctx->r1 != 0) {
        // 0x8080172C: nop
    
            goto L_80801638;
    }
    // 0x8080172C: nop

L_80801730:
    // 0x80801730: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80801734: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801738: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080173C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801740: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801744: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801748: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8080174C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80801750: jr          $ra
    // 0x80801754: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801754: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80806148_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080614C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806150: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80806154: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80806158: jal         0x800EE7F8
    // 0x8080615C: addiu       $a1, $v0, 0x1B8
    ctx->r5 = ADD32(ctx->r2, 0X1B8);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080615C: addiu       $a1, $v0, 0x1B8
    ctx->r5 = ADD32(ctx->r2, 0X1B8);
    after_0:
    // 0x80806160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806168: jr          $ra
    // 0x8080616C: nop

    return;
    // 0x8080616C: nop

;}
RECOMP_FUNC void glidmake_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800254: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800258: jal         0x800D674C
    // 0x8080025C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x8080025C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80800260: jal         0x800B274C
    // 0x80800264: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B274C(rdram, ctx);
        goto after_1;
    // 0x80800264: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800268: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080026C: jal         0x800879D0
    // 0x80800270: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _dbid_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800270: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800274: beq         $v0, $zero, L_80800284
    if (ctx->r2 == 0) {
        // 0x80800278: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800284;
    }
    // 0x80800278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080027C: b           L_80800288
    // 0x80800280: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
        goto L_80800288;
    // 0x80800280: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
L_80800284:
    // 0x80800284: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800288:
    // 0x80800288: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080028C: jr          $ra
    // 0x80800290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bskazstilt_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083680: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083680);
    return;
    // 0x80083684: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800690_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800690: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800698: jal         0x8008CABC
    // 0x8080069C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080069C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808006A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808006A4: jal         0x8080040C
    // 0x808006A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8080040C_bsbanswim(rdram, ctx);
        goto after_1;
    // 0x808006A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808006AC: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808006B0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808006B4: jal         0x8008B1BC
    // 0x808006B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x808006B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808006BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006C4: jr          $ra
    // 0x808006C8: nop

    return;
    // 0x808006C8: nop

;}
RECOMP_FUNC void _ncbafly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800892D0: syscall     771
    recomp_syscall_handler(rdram, ctx, 0x800892D0);
    return;
    // 0x800892D4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80809A10_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80809A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80809A18: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80809A1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80809A20: lwc1        $f0, 0x230($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X230);
    // 0x80809A24: lwc1        $f6, 0x168($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X168);
    // 0x80809A28: lw          $t6, 0x170($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X170);
    // 0x80809A2C: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80809A30: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80809A34: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80809A38: beql        $t6, $zero, L_80809A5C
    if (ctx->r14 == 0) {
        // 0x80809A3C: lwc1        $f2, 0x240($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X240);
            goto L_80809A5C;
    }
    goto skip_0;
    // 0x80809A3C: lwc1        $f2, 0x240($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X240);
    skip_0:
    // 0x80809A40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80809A44: lwc1        $f10, 0x16C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x80809A48: lwc1        $f18, 0x238($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X238);
    // 0x80809A4C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80809A50: b           L_80809A5C
    // 0x80809A54: div.s       $f2, $f18, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
        goto L_80809A5C;
    // 0x80809A54: div.s       $f2, $f18, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80809A58: lwc1        $f2, 0x240($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X240);
L_80809A5C:
    // 0x80809A5C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80809A60: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80809A64: jal         0x80809AF8
    // 0x80809A68: nop

    func_80809AF8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80809A68: nop

    after_0:
    // 0x80809A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80809A70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80809A74: jr          $ra
    // 0x80809A78: nop

    return;
    // 0x80809A78: nop

;}
RECOMP_FUNC void func_800C39D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C39D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C39D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C39D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C39DC: jal         0x800C13C4
    // 0x800C39E0: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    func_800C13C4(rdram, ctx);
        goto after_0;
    // 0x800C39E0: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_0:
    // 0x800C39E4: beq         $v0, $zero, L_800C39F4
    if (ctx->r2 == 0) {
        // 0x800C39E8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800C39F4;
    }
    // 0x800C39E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C39EC: b           L_800C3A30
    // 0x800C39F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C3A30;
    // 0x800C39F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C39F4:
    // 0x800C39F4: lbu         $t6, 0x63($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X63);
    // 0x800C39F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C39FC: beql        $t6, $zero, L_800C3A28
    if (ctx->r14 == 0) {
        // 0x800C3A00: lh          $v1, 0x5A($a0)
        ctx->r3 = MEM_H(ctx->r4, 0X5A);
            goto L_800C3A28;
    }
    goto skip_0;
    // 0x800C3A00: lh          $v1, 0x5A($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X5A);
    skip_0:
    // 0x800C3A04: jal         0x800C13C4
    // 0x800C3A08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800C13C4(rdram, ctx);
        goto after_1;
    // 0x800C3A08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x800C3A0C: beq         $v0, $zero, L_800C3A24
    if (ctx->r2 == 0) {
        // 0x800C3A10: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800C3A24;
    }
    // 0x800C3A10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C3A14: jal         0x800C19E4
    // 0x800C3A18: lh          $a1, 0x5A($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X5A);
    func_800C19E4(rdram, ctx);
        goto after_2;
    // 0x800C3A18: lh          $a1, 0x5A($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X5A);
    after_2:
    // 0x800C3A1C: b           L_800C3A28
    // 0x800C3A20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800C3A28;
    // 0x800C3A20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800C3A24:
    // 0x800C3A24: lh          $v1, 0x5A($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X5A);
L_800C3A28:
    // 0x800C3A28: slti        $v0, $v1, 0x65
    ctx->r2 = SIGNED(ctx->r3) < 0X65 ? 1 : 0;
    // 0x800C3A2C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_800C3A30:
    // 0x800C3A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3A38: jr          $ra
    // 0x800C3A3C: nop

    return;
    // 0x800C3A3C: nop

;}
RECOMP_FUNC void func_8080451C_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080451C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80804520: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80804524: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804528: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080452C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804530: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x80804534: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80804538: addiu       $a1, $zero, 0x1A1
    ctx->r5 = ADD32(0, 0X1A1);
    // 0x8080453C: jal         0x80089C20
    // 0x80804540: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80804540: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_0:
    // 0x80804544: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80804548: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x8080454C: bne         $v0, $zero, L_80804590
    if (ctx->r2 != 0) {
        // 0x80804550: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80804590;
    }
    // 0x80804550: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80804554: addiu       $a1, $zero, 0x1A2
    ctx->r5 = ADD32(0, 0X1A2);
    // 0x80804558: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8080455C: jal         0x80089C20
    // 0x80804560: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80804560: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80804564: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80804568: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x8080456C: bne         $v0, $zero, L_80804684
    if (ctx->r2 != 0) {
        // 0x80804570: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80804684;
    }
    // 0x80804570: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80804574: addiu       $a1, $zero, 0x1A3
    ctx->r5 = ADD32(0, 0X1A3);
    // 0x80804578: jal         0x80089C20
    // 0x8080457C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080457C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_2:
    // 0x80804580: bne         $v0, $zero, L_80804684
    if (ctx->r2 != 0) {
        // 0x80804584: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80804684;
    }
    // 0x80804584: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80804588: b           L_80804858
    // 0x8080458C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80804858;
    // 0x8080458C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80804590:
    // 0x80804590: lhu         $t6, 0x72($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X72);
    // 0x80804594: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804598: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x8080459C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808045A0: bne         $t7, $at, L_808045BC
    if (ctx->r15 != ctx->r1) {
        // 0x808045A4: addiu       $a2, $s0, 0x4
        ctx->r6 = ADD32(ctx->r16, 0X4);
            goto L_808045BC;
    }
    // 0x808045A4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808045A8: jal         0x800F0064
    // 0x808045AC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800F0064(rdram, ctx);
        goto after_3;
    // 0x808045AC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_3:
    // 0x808045B0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808045B4: beq         $v0, $zero, L_808045E0
    if (ctx->r2 == 0) {
        // 0x808045B8: addiu       $a3, $sp, 0x40
        ctx->r7 = ADD32(ctx->r29, 0X40);
            goto L_808045E0;
    }
    // 0x808045B8: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
L_808045BC:
    // 0x808045BC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808045C0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808045C4: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x808045C8: beq         $t8, $at, L_808045E0
    if (ctx->r24 == ctx->r1) {
        // 0x808045CC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808045E0;
    }
    // 0x808045CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808045D0: beq         $t8, $at, L_808045E0
    if (ctx->r24 == ctx->r1) {
        // 0x808045D4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808045E0;
    }
    // 0x808045D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808045D8: bnel        $t8, $at, L_80804688
    if (ctx->r24 != ctx->r1) {
        // 0x808045DC: lhu         $t1, 0x72($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X72);
            goto L_80804688;
    }
    goto skip_0;
    // 0x808045DC: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    skip_0:
L_808045E0:
    // 0x808045E0: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808045E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808045E8: addiu       $a1, $zero, 0x1A1
    ctx->r5 = ADD32(0, 0X1A1);
    // 0x808045EC: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x808045F0: beq         $t9, $at, L_80804620
    if (ctx->r25 == ctx->r1) {
        // 0x808045F4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80804620;
    }
    // 0x808045F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808045F8: beq         $t9, $at, L_80804630
    if (ctx->r25 == ctx->r1) {
        // 0x808045FC: addiu       $a1, $zero, 0x1A1
        ctx->r5 = ADD32(0, 0X1A1);
            goto L_80804630;
    }
    // 0x808045FC: addiu       $a1, $zero, 0x1A1
    ctx->r5 = ADD32(0, 0X1A1);
    // 0x80804600: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80804604: beq         $t9, $at, L_80804650
    if (ctx->r25 == ctx->r1) {
        // 0x80804608: addiu       $a1, $zero, 0x1A1
        ctx->r5 = ADD32(0, 0X1A1);
            goto L_80804650;
    }
    // 0x80804608: addiu       $a1, $zero, 0x1A1
    ctx->r5 = ADD32(0, 0X1A1);
    // 0x8080460C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80804610: beq         $t9, $at, L_80804640
    if (ctx->r25 == ctx->r1) {
        // 0x80804614: addiu       $a1, $zero, 0x1A1
        ctx->r5 = ADD32(0, 0X1A1);
            goto L_80804640;
    }
    // 0x80804614: addiu       $a1, $zero, 0x1A1
    ctx->r5 = ADD32(0, 0X1A1);
    // 0x80804618: b           L_8080465C
    // 0x8080461C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
        goto L_8080465C;
    // 0x8080461C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
L_80804620:
    // 0x80804620: jal         0x80089C20
    // 0x80804624: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80804624: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x80804628: b           L_8080465C
    // 0x8080462C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8080465C;
    // 0x8080462C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80804630:
    // 0x80804630: jal         0x80089C20
    // 0x80804634: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80804634: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x80804638: b           L_8080465C
    // 0x8080463C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8080465C;
    // 0x8080463C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80804640:
    // 0x80804640: jal         0x80089C20
    // 0x80804644: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80804644: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_6:
    // 0x80804648: b           L_8080465C
    // 0x8080464C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8080465C;
    // 0x8080464C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80804650:
    // 0x80804650: jal         0x80089C20
    // 0x80804654: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80804654: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x80804658: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080465C:
    // 0x8080465C: beql        $v1, $zero, L_80804688
    if (ctx->r3 == 0) {
        // 0x80804660: lhu         $t1, 0x72($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X72);
            goto L_80804688;
    }
    goto skip_1;
    // 0x80804660: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x80804664: lhu         $v0, 0x72($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X72);
    // 0x80804668: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080466C: srl         $t0, $v0, 10
    ctx->r8 = S32(U32(ctx->r2) >> 10);
    // 0x80804670: beq         $t0, $at, L_80804680
    if (ctx->r8 == ctx->r1) {
        // 0x80804674: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80804680;
    }
    // 0x80804674: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80804678: bnel        $t0, $at, L_80804688
    if (ctx->r8 != ctx->r1) {
        // 0x8080467C: lhu         $t1, 0x72($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X72);
            goto L_80804688;
    }
    goto skip_2;
    // 0x8080467C: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    skip_2:
L_80804680:
    // 0x80804680: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_80804684:
    // 0x80804684: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
L_80804688:
    // 0x80804688: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080468C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80804690: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80804694: bne         $t2, $at, L_80804848
    if (ctx->r10 != ctx->r1) {
        // 0x80804698: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80804848;
    }
    // 0x80804698: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8080469C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x808046A0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x808046A4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808046A8: jal         0x80102D78
    // 0x808046AC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80102D78(rdram, ctx);
        goto after_8;
    // 0x808046AC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_8:
    // 0x808046B0: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808046B4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808046B8: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808046BC: jal         0x800136E4
    // 0x808046C0: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_800136E4(rdram, ctx);
        goto after_9;
    // 0x808046C0: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x808046C4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808046C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808046CC: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808046D0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808046D4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808046D8: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x808046DC: bc1fl       L_8080470C
    if (!c1cs) {
        // 0x808046E0: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8080470C;
    }
    goto skip_3;
    // 0x808046E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_3:
    // 0x808046E4: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x808046E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808046EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4C40) << 16);
    // 0x808046F0: lwc1        $f18, 0x4C40($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4C40));
    // 0x808046F4: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808046F8: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808046FC: mul.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80804700: b           L_8080476C
    // 0x80804704: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
        goto L_8080476C;
    // 0x80804704: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80804708: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8080470C:
    // 0x8080470C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80804710: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80804714: nop

    // 0x80804718: bc1fl       L_80804748
    if (!c1cs) {
        // 0x8080471C: lwc1        $f0, 0x50($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
            goto L_80804748;
    }
    goto skip_4;
    // 0x8080471C: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    skip_4:
    // 0x80804720: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80804724: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80804728: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4C44) << 16);
    // 0x8080472C: lwc1        $f16, 0x4C44($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4C44));
    // 0x80804730: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80804734: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80804738: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8080473C: b           L_8080476C
    // 0x80804740: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
        goto L_8080476C;
    // 0x80804740: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80804744: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
L_80804748:
    // 0x80804748: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080474C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4C48) << 16);
    // 0x80804750: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80804754: nop

    // 0x80804758: bc1fl       L_80804770
    if (!c1cs) {
        // 0x8080475C: lui         $at, 0x41C8
        ctx->r1 = S32(0X41C8 << 16);
            goto L_80804770;
    }
    goto skip_5;
    // 0x8080475C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    skip_5:
    // 0x80804760: lwc1        $f4, 0x4C48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4C48));
    // 0x80804764: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80804768: nop

L_8080476C:
    // 0x8080476C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
L_80804770:
    // 0x80804770: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80804774: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80804778: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080477C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80804780: nop

    // 0x80804784: bc1fl       L_80804794
    if (!c1cs) {
        // 0x80804788: c.lt.s      $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
            goto L_80804794;
    }
    goto skip_6;
    // 0x80804788: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    skip_6:
    // 0x8080478C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80804790: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
L_80804794:
    // 0x80804794: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x80804798: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8080479C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808047A0: bc1fl       L_8080481C
    if (!c1cs) {
        // 0x808047A4: lwc1        $f12, 0x38($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
            goto L_8080481C;
    }
    goto skip_7;
    // 0x808047A4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    skip_7:
    // 0x808047A8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x808047AC: jal         0x80102D78
    // 0x808047B0: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    func_80102D78(rdram, ctx);
        goto after_10;
    // 0x808047B0: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_10:
    // 0x808047B4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808047B8: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x808047BC: jal         0x80102CF4
    // 0x808047C0: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_80102CF4(rdram, ctx);
        goto after_11;
    // 0x808047C0: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_11:
    // 0x808047C4: bne         $v0, $zero, L_80804818
    if (ctx->r2 != 0) {
        // 0x808047C8: lwc1        $f2, 0x34($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80804818;
    }
    // 0x808047C8: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808047CC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808047D0: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x808047D4: jal         0x80102CF4
    // 0x808047D8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_80102CF4(rdram, ctx);
        goto after_12;
    // 0x808047D8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_12:
    // 0x808047DC: beq         $v0, $zero, L_80804818
    if (ctx->r2 == 0) {
        // 0x808047E0: lwc1        $f2, 0x34($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80804818;
    }
    // 0x808047E0: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808047E4: jal         0x800DC0C0
    // 0x808047E8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_13;
    // 0x808047E8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_13:
    // 0x808047EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4C4C) << 16);
    // 0x808047F0: lwc1        $f8, 0x4C4C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4C4C));
    // 0x808047F4: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808047F8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808047FC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80804800: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80804804: bc1fl       L_8080481C
    if (!c1cs) {
        // 0x80804808: lwc1        $f12, 0x38($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
            goto L_8080481C;
    }
    goto skip_8;
    // 0x80804808: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    skip_8:
    // 0x8080480C: jal         0x8080324C
    // 0x80804810: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_14;
    // 0x80804810: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_14:
    // 0x80804814: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
L_80804818:
    // 0x80804818: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
L_8080481C:
    // 0x8080481C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80804820: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80804824: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80804828: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x8080482C: jal         0x800EFCD8
    // 0x80804830: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EFCD8(rdram, ctx);
        goto after_15;
    // 0x80804830: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_15:
    // 0x80804834: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80804838: jal         0x800EF04C
    // 0x8080483C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EF04C(rdram, ctx);
        goto after_16;
    // 0x8080483C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x80804840: b           L_80804858
    // 0x80804844: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80804858;
    // 0x80804844: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80804848:
    // 0x80804848: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x8080484C: jal         0x800EE7F8
    // 0x80804850: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x80804850: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_17:
    // 0x80804854: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80804858:
    // 0x80804858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080485C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804860: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80804864: jr          $ra
    // 0x80804868: nop

    return;
    // 0x80804868: nop

;}
RECOMP_FUNC void func_80013E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013E34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80013E38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80013E3C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80013E40: addiu       $s0, $s0, -0xC50
    ctx->r16 = ADD32(ctx->r16, -0XC50);
    // 0x80013E44: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80013E48: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80013E4C: addiu       $v0, $v0, -0x6FB0
    ctx->r2 = ADD32(ctx->r2, -0X6FB0);
    // 0x80013E50: addiu       $t6, $t6, -0x6EE0
    ctx->r14 = ADD32(ctx->r14, -0X6EE0);
    // 0x80013E54: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x80013E58: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80013E5C: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x80013E60: addiu       $t8, $t8, 0x7880
    ctx->r24 = ADD32(ctx->r24, 0X7880);
    // 0x80013E64: addiu       $t9, $t9, 0x2010
    ctx->r25 = ADD32(ctx->r25, 0X2010);
    // 0x80013E68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80013E6C: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80013E70: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x80013E74: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x80013E78: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
    // 0x80013E7C: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80013E80: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80013E84: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x80013E88: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x80013E8C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80013E90: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80013E94: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80013E98: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80013E9C: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x80013EA0: sll         $a1, $t4, 3
    ctx->r5 = S32(ctx->r12 << 3);
    // 0x80013EA4: jal         0x8002E660
    // 0x80013EA8: sw          $a1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r5;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80013EA8: sw          $a1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r5;
    after_0:
    // 0x80013EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80013EB0: jal         0x8002E660
    // 0x80013EB4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x80013EB4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x80013EB8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80013EBC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80013EC4: jal         0x8002F08C
    // 0x80013EC8: sw          $a2, -0x7B88($at)
    MEM_W(-0X7B88, ctx->r1) = ctx->r6;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_2;
    // 0x80013EC8: sw          $a2, -0x7B88($at)
    MEM_W(-0X7B88, ctx->r1) = ctx->r6;
    after_2:
    // 0x80013ECC: jal         0x8002F1F4
    // 0x80013ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_3;
    // 0x80013ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80013ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80013ED8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80013EDC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013EE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80013EE4: sw          $t6, -0x7B74($at)
    MEM_W(-0X7B74, ctx->r1) = ctx->r14;
    // 0x80013EE8: jr          $ra
    // 0x80013EEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80013EEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808000FC_bskazcrouch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800100: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: lui         $a1, 0x3ED1
    ctx->r5 = S32(0X3ED1 << 16);
    // 0x8080010C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800110: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    // 0x80800114: jal         0x800A2CE8
    // 0x80800118: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_0;
    // 0x80800118: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8080011C: lui         $a1, 0x3F68
    ctx->r5 = S32(0X3F68 << 16);
    // 0x80800120: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x80800124: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800128: jal         0x800A2CE8
    // 0x8080012C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_1;
    // 0x8080012C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void bskazjump_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A28: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A2C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(256, 0XC60) << 16);
    // 0x80800A30: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A34: jr          $ra
    // 0x80800A38: lw          $v0, 0xC60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(256, 0XC60));
    return;
    // 0x80800A38: lw          $v0, 0xC60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(256, 0XC60));
;}
RECOMP_FUNC void func_800902E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800902E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800902E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800902EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800902F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800902F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800902F8: jal         0x800F54E4
    // 0x800902FC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800902FC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090300: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80090304: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090308: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8009030C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80090310: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80090314: jal         0x800F7200
    // 0x80090318: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800F7200(rdram, ctx);
        goto after_1;
    // 0x80090318: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8009031C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80090320: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80090324: jr          $ra
    // 0x80090328: nop

    return;
    // 0x80090328: nop

;}
RECOMP_FUNC void func_80800358_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800358: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080035C: jr          $ra
    // 0x80800360: swc1        $f12, 0x1F0($a0)
    MEM_W(0X1F0, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x80800360: swc1        $f12, 0x1F0($a0)
    MEM_W(0X1F0, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800F11E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F11E4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800F11E8: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F11EC: sub.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800F11F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800F11F4: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F11F8: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x800F11FC: lwc1        $f16, 0x10($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F1200: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800F1204: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800F1208: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800F120C: jr          $ra
    // 0x800F1210: add.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f18.fl;
    return;
    // 0x800F1210: add.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f18.fl;
;}
RECOMP_FUNC void _bsclimb_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F30: syscall     34
    recomp_syscall_handler(rdram, ctx, 0x80082F30);
    return;
    // 0x80082F34: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void idtwinkle_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x80800188: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8080018C: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x80800190: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80800194: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80800198: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8080019C: beq         $at, $zero, L_8080046C
    if (ctx->r1 == 0) {
        // 0x808001A0: sw          $a0, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r4;
            goto L_8080046C;
    }
    // 0x808001A0: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x808001A4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x808001A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808001AC:
    // 0x808001AC: lh          $a2, 0x28($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X28);
    // 0x808001B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808001B4: blez        $a2, L_80800200
    if (SIGNED(ctx->r6) <= 0) {
        // 0x808001B8: nop
    
            goto L_80800200;
    }
    // 0x808001B8: nop

    // 0x808001BC: lh          $a3, 0x0($a1)
    ctx->r7 = MEM_H(ctx->r5, 0X0);
    // 0x808001C0: lw          $t0, 0x2C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X2C);
L_808001C4:
    // 0x808001C4: lh          $t7, 0x8($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X8);
    // 0x808001C8: bnel        $a3, $t7, L_808001F4
    if (ctx->r7 != ctx->r15) {
        // 0x808001CC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_808001F4;
    }
    goto skip_0;
    // 0x808001CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x808001D0: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x808001D4: lh          $t9, 0xA($t0)
    ctx->r25 = MEM_H(ctx->r8, 0XA);
    // 0x808001D8: bnel        $t8, $t9, L_808001F4
    if (ctx->r24 != ctx->r25) {
        // 0x808001DC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_808001F4;
    }
    goto skip_1;
    // 0x808001DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x808001E0: lh          $t2, 0x4($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X4);
    // 0x808001E4: lh          $t3, 0xC($t0)
    ctx->r11 = MEM_H(ctx->r8, 0XC);
    // 0x808001E8: beq         $t2, $t3, L_80800200
    if (ctx->r10 == ctx->r11) {
        // 0x808001EC: nop
    
            goto L_80800200;
    }
    // 0x808001EC: nop

    // 0x808001F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_808001F4:
    // 0x808001F4: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808001F8: bne         $at, $zero, L_808001C4
    if (ctx->r1 != 0) {
        // 0x808001FC: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_808001C4;
    }
    // 0x808001FC: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_80800200:
    // 0x80800200: beql        $v1, $a2, L_80800460
    if (ctx->r3 == ctx->r6) {
        // 0x80800204: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_80800460;
    }
    goto skip_2;
    // 0x80800204: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    skip_2:
    // 0x80800208: lbu         $a2, 0xC($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0XC);
    // 0x8080020C: lw          $t4, 0x2C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X2C);
    // 0x80800210: sll         $t5, $v1, 4
    ctx->r13 = S32(ctx->r3 << 4);
    // 0x80800214: subu        $t7, $t1, $a2
    ctx->r15 = SUB32(ctx->r9, ctx->r6);
    // 0x80800218: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8080021C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80800220: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80800224: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800228: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x8080022C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800230: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800234: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800238: bgezl       $a2, L_80800250
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8080023C: add.s       $f4, $f8, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
            goto L_80800250;
    }
    goto skip_3;
    // 0x8080023C: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    skip_3:
    // 0x80800240: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800244: nop

    // 0x80800248: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8080024C: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
L_80800250:
    // 0x80800250: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800254: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800258: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8080025C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800260: nop

    // 0x80800264: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800268: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8080026C: nop

    // 0x80800270: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800274: beql        $t9, $zero, L_808002C4
    if (ctx->r25 == 0) {
        // 0x80800278: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_808002C4;
    }
    goto skip_4;
    // 0x80800278: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_4:
    // 0x8080027C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800280: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800284: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800288: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8080028C: nop

    // 0x80800290: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800294: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800298: nop

    // 0x8080029C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x808002A0: bne         $t9, $zero, L_808002B8
    if (ctx->r25 != 0) {
        // 0x808002A4: nop
    
            goto L_808002B8;
    }
    // 0x808002A4: nop

    // 0x808002A8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x808002AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808002B0: b           L_808002D0
    // 0x808002B4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_808002D0;
    // 0x808002B4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_808002B8:
    // 0x808002B8: b           L_808002D0
    // 0x808002BC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_808002D0;
    // 0x808002BC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808002C0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_808002C4:
    // 0x808002C4: nop

    // 0x808002C8: bltz        $t9, L_808002B8
    if (SIGNED(ctx->r25) < 0) {
        // 0x808002CC: nop
    
            goto L_808002B8;
    }
    // 0x808002CC: nop

L_808002D0:
    // 0x808002D0: sb          $t9, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r25;
    // 0x808002D4: lbu         $a3, 0xD($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0XD);
    // 0x808002D8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x808002DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808002E0: subu        $t2, $t1, $a3
    ctx->r10 = SUB32(ctx->r9, ctx->r7);
    // 0x808002E4: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x808002E8: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x808002EC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808002F0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808002F4: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808002F8: bgezl       $a3, L_80800310
    if (SIGNED(ctx->r7) >= 0) {
        // 0x808002FC: add.s       $f10, $f8, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
            goto L_80800310;
    }
    goto skip_5;
    // 0x808002FC: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    skip_5:
    // 0x80800300: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800304: nop

    // 0x80800308: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080030C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
L_80800310:
    // 0x80800310: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800314: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800318: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8080031C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80800320: nop

    // 0x80800324: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800328: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8080032C: nop

    // 0x80800330: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80800334: beql        $t4, $zero, L_80800384
    if (ctx->r12 == 0) {
        // 0x80800338: mfc1        $t4, $f18
        ctx->r12 = (int32_t)ctx->f18.u32l;
            goto L_80800384;
    }
    goto skip_6;
    // 0x80800338: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    skip_6:
    // 0x8080033C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800340: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800344: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80800348: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8080034C: nop

    // 0x80800350: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80800354: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80800358: nop

    // 0x8080035C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80800360: bne         $t4, $zero, L_80800378
    if (ctx->r12 != 0) {
        // 0x80800364: nop
    
            goto L_80800378;
    }
    // 0x80800364: nop

    // 0x80800368: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8080036C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800370: b           L_80800390
    // 0x80800374: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_80800390;
    // 0x80800374: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80800378:
    // 0x80800378: b           L_80800390
    // 0x8080037C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_80800390;
    // 0x8080037C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80800380: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
L_80800384:
    // 0x80800384: nop

    // 0x80800388: bltz        $t4, L_80800378
    if (SIGNED(ctx->r12) < 0) {
        // 0x8080038C: nop
    
            goto L_80800378;
    }
    // 0x8080038C: nop

L_80800390:
    // 0x80800390: sb          $t4, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r12;
    // 0x80800394: lbu         $t0, 0xE($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XE);
    // 0x80800398: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8080039C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808003A0: subu        $t5, $t1, $t0
    ctx->r13 = SUB32(ctx->r9, ctx->r8);
    // 0x808003A4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x808003A8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x808003AC: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808003B0: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808003B4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808003B8: bgezl       $t0, L_808003D0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808003BC: add.s       $f16, $f8, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
            goto L_808003D0;
    }
    goto skip_7;
    // 0x808003BC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    skip_7:
    // 0x808003C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808003C4: nop

    // 0x808003C8: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x808003CC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
L_808003D0:
    // 0x808003D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808003D4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808003D8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x808003DC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808003E0: nop

    // 0x808003E4: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x808003E8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808003EC: nop

    // 0x808003F0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x808003F4: beql        $t7, $zero, L_80800444
    if (ctx->r15 == 0) {
        // 0x808003F8: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_80800444;
    }
    goto skip_8;
    // 0x808003F8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_8:
    // 0x808003FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800400: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800404: sub.s       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80800408: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8080040C: nop

    // 0x80800410: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800414: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800418: nop

    // 0x8080041C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800420: bne         $t7, $zero, L_80800438
    if (ctx->r15 != 0) {
        // 0x80800424: nop
    
            goto L_80800438;
    }
    // 0x80800424: nop

    // 0x80800428: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8080042C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800430: b           L_80800450
    // 0x80800434: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80800450;
    // 0x80800434: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80800438:
    // 0x80800438: b           L_80800450
    // 0x8080043C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80800450;
    // 0x8080043C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800440: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_80800444:
    // 0x80800444: nop

    // 0x80800448: bltz        $t7, L_80800438
    if (SIGNED(ctx->r15) < 0) {
        // 0x8080044C: nop
    
            goto L_80800438;
    }
    // 0x8080044C: nop

L_80800450:
    // 0x80800450: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800454: sb          $t7, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r15;
    // 0x80800458: nop

    // 0x8080045C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
L_80800460:
    // 0x80800460: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80800464: bne         $at, $zero, L_808001AC
    if (ctx->r1 != 0) {
        // 0x80800468: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_808001AC;
    }
    // 0x80800468: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_8080046C:
    // 0x8080046C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80800470: jr          $ra
    // 0x80800474: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80800474: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800BFC94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFC94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BFC98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BFC9C: jal         0x800D674C
    // 0x800BFCA0: nop

    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x800BFCA0: nop

    after_0:
    // 0x800BFCA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BFCA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BFCAC: jr          $ra
    // 0x800BFCB0: nop

    return;
    // 0x800BFCB0: nop

;}
RECOMP_FUNC void _gcegg_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883D0: syscall     680
    recomp_syscall_handler(rdram, ctx, 0x800883D0);
    return;
    // 0x800883D4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800E3BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3BAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3BB0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E3BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3BB8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3BBC: jal         0x800CA5B8
    // 0x800E3BC0: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA5B8(rdram, ctx);
        goto after_0;
    // 0x800E3BC0: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3BC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3BCC: jr          $ra
    // 0x800E3BD0: nop

    return;
    // 0x800E3BD0: nop

;}
RECOMP_FUNC void gcgoto_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080044C: sll         $t6, $a1, 8
    ctx->r14 = S32(ctx->r5 << 8);
    // 0x80800450: jal         0x808003D0
    // 0x80800454: addu        $a1, $t6, $a2
    ctx->r5 = ADD32(ctx->r14, ctx->r6);
    func_808003D0_gcgoto(rdram, ctx);
        goto after_0;
    // 0x80800454: addu        $a1, $t6, $a2
    ctx->r5 = ADD32(ctx->r14, ctx->r6);
    after_0:
    // 0x80800458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080045C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800460: jr          $ra
    // 0x80800464: nop

    return;
    // 0x80800464: nop

;}
RECOMP_FUNC void bamotor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080000C: jal         0x800918F8
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    bakey_getControllerIndex(rdram, ctx);
        goto after_0;
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800014: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800018: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080001C: jal         0x80018820
    // 0x80800020: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_80018820(rdram, ctx);
        goto after_1;
    // 0x80800020: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void func_80800240_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800240: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800244: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800248: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080024C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800250: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80800254: addiu       $s0, $a1, -0x1
    ctx->r16 = ADD32(ctx->r5, -0X1);
    // 0x80800258: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080025C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80800260: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80800264: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800268: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8080026C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800270: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800274: jal         0x80100094
    // 0x80800278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080027C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1564, 0X3CE8) << 16);
    // 0x80800280: addiu       $t6, $t6, 0x3CE8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1564, 0X3CE8));
    // 0x80800284: sll         $s6, $s0, 2
    ctx->r22 = S32(ctx->r16 << 2);
    // 0x80800288: addu        $s7, $s6, $t6
    ctx->r23 = ADD32(ctx->r22, ctx->r14);
    // 0x8080028C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800290: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    // 0x80800294: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800298: jal         0x80089EB0
    // 0x8080029C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _susplinet_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x8080029C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x808002A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002A8: jal         0x80100074
    // 0x808002AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80100074(rdram, ctx);
        goto after_2;
    // 0x808002AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x808002B0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808002B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002B8: lw          $a1, 0x0($s7)
    ctx->r5 = MEM_W(ctx->r23, 0X0);
    // 0x808002BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808002C0: jal         0x80089EB8
    // 0x808002C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _susplinet_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x808002C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x808002C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808002CC: addiu       $s1, $sp, 0x6C
    ctx->r17 = ADD32(ctx->r29, 0X6C);
L_808002D0:
    // 0x808002D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808002D4: jal         0x80089E90
    // 0x808002D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _susplinet_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x808002D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x808002DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808002E0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808002E4: blez        $s0, L_808002D0
    if (SIGNED(ctx->r16) <= 0) {
        // 0x808002E8: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_808002D0;
    }
    // 0x808002E8: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x808002EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808002F0: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
L_808002F4:
    // 0x808002F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808002F8: jal         0x80089E98
    // 0x808002FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _susplinet_entrypoint_15(rdram, ctx);
        goto after_5;
    // 0x808002FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800300: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800304: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800308: blez        $s0, L_808002F4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8080030C: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_808002F4;
    }
    // 0x8080030C: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x80800310: jal         0x80089E80
    // 0x80800314: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    _susplinet_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x80800314: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x80800318: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8080031C: jal         0x80089E88
    // 0x80800320: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    _susplinet_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x80800320: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_7:
    // 0x80800324: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x80800328: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8080032C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800330: blez        $t7, L_80800420
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80800334: lui         $t8, 0x8080
        ctx->r24 = S32(RELOC_HI16(1564, 0X3CD8) << 16);
            goto L_80800420;
    }
    // 0x80800334: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1564, 0X3CD8) << 16);
    // 0x80800338: addiu       $t8, $t8, 0x3CD8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1564, 0X3CD8));
    // 0x8080033C: addu        $s2, $s6, $t8
    ctx->r18 = ADD32(ctx->r22, ctx->r24);
    // 0x80800340: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80800344: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80800348:
    // 0x80800348: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8080034C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80800350: jal         0x800EE7F8
    // 0x80800354: addu        $a1, $t9, $s1
    ctx->r5 = ADD32(ctx->r25, ctx->r17);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80800354: addu        $a1, $t9, $s1
    ctx->r5 = ADD32(ctx->r25, ctx->r17);
    after_8:
    // 0x80800358: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8080035C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800360: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800364: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80800368: lh          $t2, 0x10($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X10);
    // 0x8080036C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800370: sh          $t2, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r10;
    // 0x80800374: sh          $s6, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r22;
    // 0x80800378: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8080037C: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x80800380: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x80800384: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80800388: swc1        $f4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f4.u32l;
    // 0x8080038C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80800390: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80800394: lh          $t8, 0x12($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X12);
    // 0x80800398: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8080039C: beq         $t9, $zero, L_808003AC
    if (ctx->r25 == 0) {
        // 0x808003A0: nop
    
            goto L_808003AC;
    }
    // 0x808003A0: nop

    // 0x808003A4: b           L_808003AC
    // 0x808003A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_808003AC;
    // 0x808003A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_808003AC:
    // 0x808003AC: jal         0x80089E20
    // 0x808003B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _susplinet_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x808003B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_9:
    // 0x808003B4: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x808003B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808003BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003C0: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x808003C4: lh          $t2, 0x12($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X12);
    // 0x808003C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808003CC: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x808003D0: beq         $t3, $zero, L_808003E0
    if (ctx->r11 == 0) {
        // 0x808003D4: nop
    
            goto L_808003E0;
    }
    // 0x808003D4: nop

    // 0x808003D8: b           L_808003E0
    // 0x808003DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_808003E0;
    // 0x808003DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_808003E0:
    // 0x808003E0: jal         0x80089E20
    // 0x808003E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _susplinet_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x808003E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_10:
    // 0x808003E8: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x808003EC: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x808003F0: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x808003F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808003F8: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x808003FC: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x80800400: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x80800404: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    // 0x80800408: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x8080040C: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80800410: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x80800414: bne         $at, $zero, L_80800348
    if (ctx->r1 != 0) {
        // 0x80800418: sw          $t5, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r13;
            goto L_80800348;
    }
    // 0x80800418: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x8080041C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800420:
    // 0x80800420: addiu       $s1, $sp, 0x6C
    ctx->r17 = ADD32(ctx->r29, 0X6C);
L_80800424:
    // 0x80800424: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800428: jal         0x80089E90
    // 0x8080042C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _susplinet_entrypoint_14(rdram, ctx);
        goto after_11;
    // 0x8080042C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x80800430: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800434: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800438: blez        $s0, L_80800424
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8080043C: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_80800424;
    }
    // 0x8080043C: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x80800440: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800444: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
    // 0x80800448: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8080044C:
    // 0x8080044C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800450: jal         0x80089E98
    // 0x80800454: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _susplinet_entrypoint_15(rdram, ctx);
        goto after_12;
    // 0x80800454: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x80800458: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080045C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800460: bne         $s0, $s2, L_8080044C
    if (ctx->r16 != ctx->r18) {
        // 0x80800464: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_8080044C;
    }
    // 0x80800464: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x80800468: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x8080046C: jal         0x800F0EF0
    // 0x80800470: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    func_800F0EF0(rdram, ctx);
        goto after_13;
    // 0x80800470: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    after_13:
    // 0x80800474: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80800478: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8080047C: sb          $zero, 0xFC($v0)
    MEM_B(0XFC, ctx->r2) = 0;
    // 0x80800480: sb          $t7, 0xFB($v0)
    MEM_B(0XFB, ctx->r2) = ctx->r15;
    // 0x80800484: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800488: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8080048C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80800490: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800494: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800498: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080049C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808004A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808004A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808004A8: jr          $ra
    // 0x808004AC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808004AC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void _bsrest_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839A0: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x800839A0);
    return;
    // 0x800839A4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _ncpod_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089500: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089500);
    return;
    // 0x80089504: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800CA5B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA5B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA5BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA5C0: jal         0x800EE7F8
    // 0x800CA5C4: nop

    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800CA5C4: nop

    after_0:
    // 0x800CA5C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA5CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA5D0: jr          $ra
    // 0x800CA5D4: nop

    return;
    // 0x800CA5D4: nop

;}
RECOMP_FUNC void func_8080079C_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080079C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007AC: jal         0x80100094
    // 0x808007B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007B4: jal         0x800D8FF8
    // 0x808007B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808007B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808007BC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808007C0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808007C4: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x808007C8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808007CC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x808007D0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x808007D4: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x808007D8: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808007DC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808007E0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808007E4: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x808007E8: beq         $at, $zero, L_808008F4
    if (ctx->r1 == 0) {
        // 0x808007EC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808008F4;
    }
    // 0x808007EC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808007F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4E98) << 16);
    // 0x808007F4: addu        $at, $at, $t8
    gpr jr_addend_808007FC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808007F8: lw          $t8, 0x4E98($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4E98));
    // 0x808007FC: jr          $t8
    // 0x80800800: nop

    switch (jr_addend_808007FC >> 2) {
        case 0: goto L_80800804; break;
        case 1: goto L_808008F4; break;
        case 2: goto L_80800814; break;
        case 3: goto L_8080083C; break;
        case 4: goto L_808008F4; break;
        case 5: goto L_80800824; break;
        case 6: goto L_80800898; break;
        case 7: goto L_808008A8; break;
        default: switch_error(__func__, 0x808007FC, 0x80804E98);
    }
    // 0x80800800: nop

L_80800804:
    // 0x80800804: jal         0x80800144
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800144_chstoneballcontrol(rdram, ctx);
        goto after_2;
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080080C: b           L_808008F8
    // 0x80800810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008F8;
    // 0x80800810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800814:
    // 0x80800814: jal         0x80089B20
    // 0x80800818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sukickball_entrypoint_17(rdram, ctx);
        goto after_3;
    // 0x80800818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080081C: b           L_808008F8
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008F8;
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800824:
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800828: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080082C: jal         0x80089B30
    // 0x80800830: lbu         $a2, 0x3A($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X3A);
    _sukickball_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800830: lbu         $a2, 0x3A($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X3A);
    after_4:
    // 0x80800834: b           L_808008F8
    // 0x80800838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008F8;
    // 0x80800838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080083C:
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800844: jal         0x80089B30
    // 0x80800848: lbu         $a2, 0x3A($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X3A);
    _sukickball_entrypoint_19(rdram, ctx);
        goto after_5;
    // 0x80800848: lbu         $a2, 0x3A($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X3A);
    after_5:
    // 0x8080084C: jal         0x8080145C
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080145C_chstoneballcontrol(rdram, ctx);
        goto after_6;
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800854: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800858: jal         0x800CEB54
    // 0x8080085C: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    func_800CEB54(rdram, ctx);
        goto after_7;
    // 0x8080085C: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    after_7:
    // 0x80800860: beq         $v0, $zero, L_80800878
    if (ctx->r2 == 0) {
        // 0x80800864: nop
    
            goto L_80800878;
    }
    // 0x80800864: nop

    // 0x80800868: jal         0x800FDC28
    // 0x8080086C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FDC28(rdram, ctx);
        goto after_8;
    // 0x8080086C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_8:
    // 0x80800870: b           L_808008F8
    // 0x80800874: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008F8;
    // 0x80800874: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800878:
    // 0x80800878: jal         0x800CEAD0
    // 0x8080087C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_9;
    // 0x8080087C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80800880: beql        $v0, $zero, L_808008F8
    if (ctx->r2 == 0) {
        // 0x80800884: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808008F8;
    }
    goto skip_0;
    // 0x80800884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800888: jal         0x80800908
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800908_chstoneballcontrol(rdram, ctx);
        goto after_10;
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800890: b           L_808008F8
    // 0x80800894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008F8;
    // 0x80800894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800898:
    // 0x80800898: jal         0x8080145C
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080145C_chstoneballcontrol(rdram, ctx);
        goto after_11;
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808008A0: b           L_808008F8
    // 0x808008A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008F8;
    // 0x808008A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008A8:
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808008B0: jal         0x80089B30
    // 0x808008B4: lbu         $a2, 0x3A($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X3A);
    _sukickball_entrypoint_19(rdram, ctx);
        goto after_12;
    // 0x808008B4: lbu         $a2, 0x3A($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X3A);
    after_12:
    // 0x808008B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808008BC: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808008C0: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    // 0x808008C4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808008C8: nop

    // 0x808008CC: bc1f        L_808008EC
    if (!c1cs) {
        // 0x808008D0: nop
    
            goto L_808008EC;
    }
    // 0x808008D0: nop

    // 0x808008D4: jal         0x800D8FF8
    // 0x808008D8: nop

    func_800D8FF8(rdram, ctx);
        goto after_13;
    // 0x808008D8: nop

    after_13:
    // 0x808008DC: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808008E0: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808008E4: b           L_808008F4
    // 0x808008E8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808008F4;
    // 0x808008E8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808008EC:
    // 0x808008EC: jal         0x80087A58
    // 0x808008F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x808008F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
L_808008F4:
    // 0x808008F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008F8:
    // 0x808008F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800900: jr          $ra
    // 0x80800904: nop

    return;
    // 0x80800904: nop

;}
RECOMP_FUNC void func_808013BC_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808013C0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808013C4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808013C8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808013CC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808013D0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808013D4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x808013D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808013DC: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x808013E0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808013E4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808013E8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808013EC: bc1f        L_80801428
    if (!c1cs) {
        // 0x808013F0: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_80801428;
    }
    // 0x808013F0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808013F4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808013F8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x808013FC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80801400: nop

    // 0x80801404: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_80801408:
    // 0x80801408: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8080140C: jal         0x800849F0
    // 0x80801410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80801410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801414: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x80801418: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x8080141C: nop

    // 0x80801420: bc1tl       L_80801408
    if (c1cs) {
        // 0x80801424: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_80801408;
    }
    goto skip_0;
    // 0x80801424: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_0:
L_80801428:
    // 0x80801428: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8080142C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801430: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80801434: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80801438: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8080143C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80801440: jr          $ra
    // 0x80801444: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80801444: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void bsjump_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C50: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800C54: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800C58: jal         0x8008CABC
    // 0x80800C5C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800C5C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800C60: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800C64: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800C68: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80800C6C: jal         0x8009E710
    // 0x80800C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_1;
    // 0x80800C70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800C74: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80800C78: bne         $v0, $at, L_80800C84
    if (ctx->r2 != ctx->r1) {
        // 0x80800C7C: nop
    
            goto L_80800C84;
    }
    // 0x80800C7C: nop

    // 0x80800C80: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_80800C84:
    // 0x80800C84: jal         0x8008AF24
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C90: jal         0x8008B1A0
    // 0x80800C94: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_3;
    // 0x80800C94: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C9C: jal         0x8008AED4
    // 0x80800CA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x80800CA0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x80800CA4: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800CA8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800CAC: jal         0x8008B1C8
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_5;
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800CB4: lui         $a1, 0x3FF3
    ctx->r5 = S32(0X3FF3 << 16);
    // 0x80800CB8: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800CBC: jal         0x8008B1BC
    // 0x80800CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x80800CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800CC4: lui         $a1, 0x3F2A
    ctx->r5 = S32(0X3F2A << 16);
    // 0x80800CC8: ori         $a1, $a1, 0xACDA
    ctx->r5 = ctx->r5 | 0XACDA;
    // 0x80800CCC: jal         0x8008B24C
    // 0x80800CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_7;
    // 0x80800CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CD8: jal         0x8008B134
    // 0x80800CDC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x80800CDC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80800CE0: jal         0x8008B064
    // 0x80800CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x80800CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800CE8: jal         0x8009F308
    // 0x80800CEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009F308(rdram, ctx);
        goto after_10;
    // 0x80800CEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80800CF0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800CF4: jal         0x8009C914
    // 0x80800CF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_11;
    // 0x80800CF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80800CFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D00: jal         0x8008CA4C
    // 0x80800D04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_12;
    // 0x80800D04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800D08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D0C: jal         0x8009C908
    // 0x80800D10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    yaw_setUpdateType(rdram, ctx);
        goto after_13;
    // 0x80800D10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800D14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D18: jal         0x8009D2D8
    // 0x80800D1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_14;
    // 0x80800D1C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x80800D20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D24: jal         0x8009B800
    // 0x80800D28: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baphysics_set_type(rdram, ctx);
        goto after_15;
    // 0x80800D28: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_15:
    // 0x80800D2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D30: jal         0x8009B9B0
    // 0x80800D34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x80800D34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_16:
    // 0x80800D38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D3C: jal         0x8009BA9C
    // 0x80800D40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_17;
    // 0x80800D40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800D44: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80800D48: jal         0x8008E944
    // 0x80800D4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008E944(rdram, ctx);
        goto after_18;
    // 0x80800D4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80800D50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800D58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800D5C: jr          $ra
    // 0x80800D60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800D60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mlMtxRotPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018F50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80018F54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80018F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018F5C: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x80018F60: nop

    // 0x80018F64: bc1tl       L_80018FDC
    if (c1cs) {
        // 0x80018F68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80018FDC;
    }
    goto skip_0;
    // 0x80018F68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80018F6C: jal         0x800137F4
    // 0x80018F70: nop

    func_800137F4(rdram, ctx);
        goto after_0;
    // 0x80018F70: nop

    after_0:
    // 0x80018F74: jal         0x80013788
    // 0x80018F78: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80013788(rdram, ctx);
        goto after_1;
    // 0x80018F78: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80018F7C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80018F80: lw          $a1, -0x4350($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4350);
    // 0x80018F84: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80018F88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018F8C: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80018F90: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x80018F94: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80018F98:
    // 0x80018F98: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80018F9C: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80018FA0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80018FA4: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80018FA8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80018FAC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80018FB0: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80018FB4: nop

    // 0x80018FB8: mul.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80018FBC: nop

    // 0x80018FC0: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80018FC4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80018FC8: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80018FCC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80018FD0: bne         $a0, $a1, L_80018F98
    if (ctx->r4 != ctx->r5) {
        // 0x80018FD4: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_80018F98;
    }
    // 0x80018FD4: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80018FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018FDC:
    // 0x80018FDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80018FE0: jr          $ra
    // 0x80018FE4: nop

    return;
    // 0x80018FE4: nop

;}
RECOMP_FUNC void func_80098898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098898: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009889C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800988A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800988A4: jal         0x800EA05C
    // 0x800988A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x800988A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800988AC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800988B0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800988B4: jal         0x800BED18
    // 0x800988B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800BED18(rdram, ctx);
        goto after_1;
    // 0x800988B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800988BC: lw          $a0, 0xBC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XBC);
    // 0x800988C0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800988C4: jal         0x800EE84C
    // 0x800988C8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE84C(rdram, ctx);
        goto after_2;
    // 0x800988C8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_2:
    // 0x800988CC: lw          $a0, 0xBC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XBC);
    // 0x800988D0: jal         0x800EE84C
    // 0x800988D4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800EE84C(rdram, ctx);
        goto after_3;
    // 0x800988D4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x800988D8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800988DC: addiu       $v1, $v0, 0x7EC0
    ctx->r3 = ADD32(ctx->r2, 0X7EC0);
    // 0x800988E0: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800988E4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800988E8: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800988EC: beql        $t6, $zero, L_8009891C
    if (ctx->r14 == 0) {
        // 0x800988F0: lh          $t8, 0x2($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X2);
            goto L_8009891C;
    }
    goto skip_0;
    // 0x800988F0: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    skip_0:
    // 0x800988F4: lh          $t7, 0x7EC0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7EC0);
    // 0x800988F8: beql        $a2, $t7, L_8009891C
    if (ctx->r6 == ctx->r15) {
        // 0x800988FC: lh          $t8, 0x2($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X2);
            goto L_8009891C;
    }
    goto skip_1;
    // 0x800988FC: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    skip_1:
    // 0x80098900: lh          $v0, 0xE($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XE);
L_80098904:
    // 0x80098904: addiu       $v1, $v1, 0xE
    ctx->r3 = ADD32(ctx->r3, 0XE);
    // 0x80098908: beql        $v0, $zero, L_8009891C
    if (ctx->r2 == 0) {
        // 0x8009890C: lh          $t8, 0x2($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X2);
            goto L_8009891C;
    }
    goto skip_2;
    // 0x8009890C: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    skip_2:
    // 0x80098910: bnel        $a2, $v0, L_80098904
    if (ctx->r6 != ctx->r2) {
        // 0x80098914: lh          $v0, 0xE($v1)
        ctx->r2 = MEM_H(ctx->r3, 0XE);
            goto L_80098904;
    }
    goto skip_3;
    // 0x80098914: lh          $v0, 0xE($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XE);
    skip_3:
    // 0x80098918: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
L_8009891C:
    // 0x8009891C: lw          $v0, 0xBC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XBC);
    // 0x80098920: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80098924: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80098928: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009892C: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80098930: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x80098934: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x80098938: lw          $v0, 0xBC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XBC);
    // 0x8009893C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80098940: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80098944: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80098948: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8009894C: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x80098950: lh          $t0, 0x6($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X6);
    // 0x80098954: lw          $v0, 0xBC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XBC);
    // 0x80098958: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8009895C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80098960: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80098964: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80098968: swc1        $f16, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f16.u32l;
    // 0x8009896C: lh          $t1, 0x8($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X8);
    // 0x80098970: lw          $v0, 0xBC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XBC);
    // 0x80098974: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80098978: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8009897C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80098980: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80098984: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80098988: lh          $t2, 0xA($v1)
    ctx->r10 = MEM_H(ctx->r3, 0XA);
    // 0x8009898C: lw          $v0, 0xBC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XBC);
    // 0x80098990: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80098994: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80098998: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009899C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800989A0: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x800989A4: lh          $t3, 0xC($v1)
    ctx->r11 = MEM_H(ctx->r3, 0XC);
    // 0x800989A8: lw          $v0, 0xBC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XBC);
    // 0x800989AC: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800989B0: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800989B4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800989B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800989BC: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x800989C0: lw          $t4, 0xBC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XBC);
    // 0x800989C4: sb          $zero, 0x18($t4)
    MEM_B(0X18, ctx->r12) = 0;
    // 0x800989C8: lw          $t5, 0xBC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XBC);
    // 0x800989CC: sb          $zero, 0x19($t5)
    MEM_B(0X19, ctx->r13) = 0;
    // 0x800989D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800989D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800989D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800989DC: jr          $ra
    // 0x800989E0: nop

    return;
    // 0x800989E0: nop

;}
RECOMP_FUNC void _gspropctrl_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BF0: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088BF0);
    return;
    // 0x80088BF4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _sujiggy_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6F8: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A6F8);
    return;
    // 0x8008A6FC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _gsmaker_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825D8: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x800825D8);
    return;
    // 0x800825DC: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void idworldmake_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080090C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800910: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800918: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8080091C: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    // 0x80800920: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800924: jal         0x800B296C
    // 0x80800928: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    vector_end(rdram, ctx);
        goto after_0;
    // 0x80800928: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080092C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800930: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    // 0x80800934: jal         0x800B28C4
    // 0x80800938: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x80800938: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080093C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800940: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800944: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800948: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8080094C: beq         $at, $zero, L_80800974
    if (ctx->r1 == 0) {
        // 0x80800950: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800974;
    }
    // 0x80800950: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800954: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80800958:
    // 0x80800958: bnel        $a2, $t6, L_80800968
    if (ctx->r6 != ctx->r14) {
        // 0x8080095C: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_80800968;
    }
    goto skip_0;
    // 0x8080095C: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_0:
    // 0x80800960: sb          $a3, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r7;
    // 0x80800964: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
L_80800968:
    // 0x80800968: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8080096C: bnel        $at, $zero, L_80800958
    if (ctx->r1 != 0) {
        // 0x80800970: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80800958;
    }
    goto skip_1;
    // 0x80800970: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
L_80800974:
    // 0x80800974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800978: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080097C: jr          $ra
    // 0x80800980: nop

    return;
    // 0x80800980: nop

;}
RECOMP_FUNC void func_808002B8_chfactorydrums(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002C4: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808002C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002CC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808002D0: bgez        $t8, L_8080032C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808002D4: nop
    
            goto L_8080032C;
    }
    // 0x808002D4: nop

    // 0x808002D8: jal         0x8001210C
    // 0x808002DC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x808002DC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x808002E0: beql        $v0, $zero, L_80800398
    if (ctx->r2 == 0) {
        // 0x808002E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800398;
    }
    goto skip_0;
    // 0x808002E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808002E8: lhu         $t9, 0x76($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X76);
    // 0x808002EC: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808002F0: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x808002F4: beql        $t0, $at, L_80800398
    if (ctx->r8 == ctx->r1) {
        // 0x808002F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800398;
    }
    goto skip_1;
    // 0x808002F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808002FC: jal         0x80800000
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chfactorydrums(rdram, ctx);
        goto after_1;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800304: beq         $v0, $zero, L_80800394
    if (ctx->r2 == 0) {
        // 0x80800308: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800394;
    }
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: jal         0x80089BD8
    // 0x80800310: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800310: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800314: beq         $v0, $zero, L_80800394
    if (ctx->r2 == 0) {
        // 0x80800318: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800394;
    }
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080031C: jal         0x80102424
    // 0x80800320: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800320: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x80800324: b           L_80800398
    // 0x80800328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800398;
    // 0x80800328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080032C:
    // 0x8080032C: jal         0x800D90A4
    // 0x80800330: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_4;
    // 0x80800330: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_4:
    // 0x80800334: beql        $v0, $zero, L_80800398
    if (ctx->r2 == 0) {
        // 0x80800338: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800398;
    }
    goto skip_2;
    // 0x80800338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8080033C: jal         0x8001210C
    // 0x80800340: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_5;
    // 0x80800340: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_5:
    // 0x80800344: beql        $v0, $zero, L_80800398
    if (ctx->r2 == 0) {
        // 0x80800348: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800398;
    }
    goto skip_3;
    // 0x80800348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8080034C: lhu         $t1, 0x76($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X76);
    // 0x80800350: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800354: srl         $t2, $t1, 7
    ctx->r10 = S32(U32(ctx->r9) >> 7);
    // 0x80800358: beql        $t2, $at, L_8080037C
    if (ctx->r10 == ctx->r1) {
        // 0x8080035C: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8080037C;
    }
    goto skip_4;
    // 0x8080035C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_4:
    // 0x80800360: jal         0x80800000
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chfactorydrums(rdram, ctx);
        goto after_6;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800368: beq         $v0, $zero, L_80800378
    if (ctx->r2 == 0) {
        // 0x8080036C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800378;
    }
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800370: jal         0x80102424
    // 0x80800374: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800374: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
L_80800378:
    // 0x80800378: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_8080037C:
    // 0x8080037C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800380: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800384: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800388: jal         0x800DC178
    // 0x8080038C: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x8080038C: nop

    after_8:
    // 0x80800390: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800394:
    // 0x80800394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800398:
    // 0x80800398: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080039C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
RECOMP_FUNC void _bsdronesuckunder_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083168: syscall     47
    recomp_syscall_handler(rdram, ctx, 0x80083168);
    return;
    // 0x8008316C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800D4298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D429C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D42A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D42A4: jal         0x800D41D8
    // 0x800D42A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D41D8(rdram, ctx);
        goto after_0;
    // 0x800D42A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D42AC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800D42B0: beq         $v0, $at, L_800D42CC
    if (ctx->r2 == ctx->r1) {
        // 0x800D42B4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D42CC;
    }
    // 0x800D42B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D42B8: jal         0x800C6E38
    // 0x800D42BC: nop

    func_800C6E38(rdram, ctx);
        goto after_1;
    // 0x800D42BC: nop

    after_1:
    // 0x800D42C0: bnel        $v0, $zero, L_800D42D0
    if (ctx->r2 != 0) {
        // 0x800D42C4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800D42D0;
    }
    goto skip_0;
    // 0x800D42C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x800D42C8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800D42CC:
    // 0x800D42CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_800D42D0:
    // 0x800D42D0: jal         0x800D192C
    // 0x800D42D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800D192C(rdram, ctx);
        goto after_2;
    // 0x800D42D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800D42D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D42DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D42E0: jr          $ra
    // 0x800D42E4: nop

    return;
    // 0x800D42E4: nop

;}
RECOMP_FUNC void func_800CEF7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEF7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CEF80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEF84: jal         0x800CEF00
    // 0x800CEF88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEF00(rdram, ctx);
        goto after_0;
    // 0x800CEF88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800CEF8C: jal         0x800CF6D0
    // 0x800CEF90: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_800CF6D0(rdram, ctx);
        goto after_1;
    // 0x800CEF90: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800CEF94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CEF98: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CEF9C: jal         0x800CE8D8
    // 0x800CEFA0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800CE8D8(rdram, ctx);
        goto after_2;
    // 0x800CEFA0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x800CEFA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CEFA8: lwc1        $f0, -0x4E90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4E90);
    // 0x800CEFAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CEFB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CEFB4: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x800CEFB8: nop

    // 0x800CEFBC: bc1t        L_800CEFD0
    if (c1cs) {
        // 0x800CEFC0: nop
    
            goto L_800CEFD0;
    }
    // 0x800CEFC0: nop

    // 0x800CEFC4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800CEFC8: jal         0x800CE980
    // 0x800CEFCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CE980(rdram, ctx);
        goto after_3;
    // 0x800CEFCC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_800CEFD0:
    // 0x800CEFD0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CEFD4: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x800CEFD8: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x800CEFDC: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x800CEFE0: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x800CEFE4: sh          $t9, -0x4E9A($at)
    MEM_H(-0X4E9A, ctx->r1) = ctx->r25;
    // 0x800CEFE8: sh          $t8, -0x4E9C($at)
    MEM_H(-0X4E9C, ctx->r1) = ctx->r24;
    // 0x800CEFEC: sh          $t7, -0x4E9E($at)
    MEM_H(-0X4E9E, ctx->r1) = ctx->r15;
    // 0x800CEFF0: sh          $t6, -0x4EA0($at)
    MEM_H(-0X4EA0, ctx->r1) = ctx->r14;
    // 0x800CEFF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CEFF8: sh          $zero, -0x4E98($at)
    MEM_H(-0X4E98, ctx->r1) = 0;
    // 0x800CEFFC: jal         0x800CEA84
    // 0x800CF000: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CEA84(rdram, ctx);
        goto after_4;
    // 0x800CF000: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800CF004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF008: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CF00C: sh          $v0, -0x4E96($at)
    MEM_H(-0X4E96, ctx->r1) = ctx->r2;
    // 0x800CF010: sb          $zero, -0x4E94($at)
    MEM_B(-0X4E94, ctx->r1) = 0;
    // 0x800CF014: jr          $ra
    // 0x800CF018: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800CF018: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80801C3C_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801C40: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2658, 0X215C) << 16);
    // 0x80801C44: lb          $t6, 0x215C($t6)
    ctx->r14 = MEM_B(ctx->r14, (int16_t)RELOC_LO16(2658, 0X215C));
    // 0x80801C48: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80801C4C: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80801C50: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80801C54: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801C58: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801C5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801C60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801C64: beq         $s3, $t6, L_80801CAC
    if (ctx->r19 == ctx->r14) {
        // 0x80801C68: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80801CAC;
    }
    // 0x80801C68: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801C6C: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2658, 0X215C) << 16);
    // 0x80801C70: addiu       $s0, $s0, 0x215C
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2658, 0X215C));
L_80801C74:
    // 0x80801C74: beq         $s1, $zero, L_80801C88
    if (ctx->r17 == 0) {
        // 0x80801C78: nop
    
            goto L_80801C88;
    }
    // 0x80801C78: nop

    // 0x80801C7C: lb          $t7, 0x0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X0);
    // 0x80801C80: bnel        $s1, $t7, L_80801CA0
    if (ctx->r17 != ctx->r15) {
        // 0x80801C84: lb          $t8, 0x2($s0)
        ctx->r24 = MEM_B(ctx->r16, 0X2);
            goto L_80801CA0;
    }
    goto skip_0;
    // 0x80801C84: lb          $t8, 0x2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X2);
    skip_0:
L_80801C88:
    // 0x80801C88: jal         0x800C6E38
    // 0x80801C8C: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x80801C8C: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    after_0:
    // 0x80801C90: beql        $v0, $zero, L_80801CA0
    if (ctx->r2 == 0) {
        // 0x80801C94: lb          $t8, 0x2($s0)
        ctx->r24 = MEM_B(ctx->r16, 0X2);
            goto L_80801CA0;
    }
    goto skip_1;
    // 0x80801C94: lb          $t8, 0x2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X2);
    skip_1:
    // 0x80801C98: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80801C9C: lb          $t8, 0x2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X2);
L_80801CA0:
    // 0x80801CA0: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80801CA4: bne         $s3, $t8, L_80801C74
    if (ctx->r19 != ctx->r24) {
        // 0x80801CA8: nop
    
            goto L_80801C74;
    }
    // 0x80801CA8: nop

L_80801CAC:
    // 0x80801CAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801CB0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80801CB4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CB8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801CBC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801CC0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801CC4: jr          $ra
    // 0x80801CC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801CC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080021C_sulights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080021C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800220: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800224: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800228: jal         0x800DC0C0
    // 0x8080022C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x8080022C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800230: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800234: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800238: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080023C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800240: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800244: nop

    // 0x80800248: bc1fl       L_80800264
    if (!c1cs) {
        // 0x8080024C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80800264;
    }
    goto skip_0;
    // 0x8080024C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80800250: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800254: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800258: b           L_8080026C
    // 0x8080025C: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
        goto L_8080026C;
    // 0x8080025C: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80800260: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80800264:
    // 0x80800264: nop

    // 0x80800268: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
L_8080026C:
    // 0x8080026C: jal         0x800C8900
    // 0x80800270: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_800C8900(rdram, ctx);
        goto after_1;
    // 0x80800270: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800274: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800278: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x8080027C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80800280: addiu       $t0, $sp, 0x4C
    ctx->r8 = ADD32(ctx->r29, 0X4C);
L_80800284:
    // 0x80800284: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x80800288: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080028C: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800290: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80800294: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80800298: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080029C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x808002A0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x808002A4: nop

    // 0x808002A8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808002AC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808002B0: nop

    // 0x808002B4: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808002B8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x808002BC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808002C0: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x808002C4: nop

    // 0x808002C8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x808002CC: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x808002D0: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    // 0x808002D4: addu        $a3, $a1, $a2
    ctx->r7 = ADD32(ctx->r5, ctx->r6);
    // 0x808002D8: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x808002DC: beq         $at, $zero, L_808002F4
    if (ctx->r1 == 0) {
        // 0x808002E0: nop
    
            goto L_808002F4;
    }
    // 0x808002E0: nop

    // 0x808002E4: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x808002E8: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x808002EC: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    // 0x808002F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_808002F4:
    // 0x808002F4: subu        $a3, $a2, $a1
    ctx->r7 = SUB32(ctx->r6, ctx->r5);
    // 0x808002F8: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x808002FC: beql        $at, $zero, L_8080030C
    if (ctx->r1 == 0) {
        // 0x80800300: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8080030C;
    }
    goto skip_1;
    // 0x80800300: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_1:
    // 0x80800304: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80800308: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8080030C:
    // 0x8080030C: bne         $v0, $t0, L_80800284
    if (ctx->r2 != ctx->r8) {
        // 0x80800310: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80800284;
    }
    // 0x80800310: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800314: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80800318: jal         0x800C8E84
    // 0x8080031C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800C8E84(rdram, ctx);
        goto after_2;
    // 0x8080031C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x80800320: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800324: nop

    // 0x80800328: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x8080032C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800330: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800334: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800338: jr          $ra
    // 0x8080033C: nop

    return;
    // 0x8080033C: nop

;}
RECOMP_FUNC void func_808015D8_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808015DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808015E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808015E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808015E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808015EC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808015F0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808015F4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808015F8: jal         0x800EFB24
    // 0x808015FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x808015FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x80801600: jal         0x800EF2A0
    // 0x80801604: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800EF2A0(rdram, ctx);
        goto after_1;
    // 0x80801604: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80801608: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080160C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801610: jal         0x800EE780
    // 0x80801614: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_800EE780(rdram, ctx);
        goto after_2;
    // 0x80801614: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801618: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080161C: jal         0x800EF334
    // 0x80801620: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x80801620: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_3:
    // 0x80801624: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801628: jal         0x800EEAD4
    // 0x8080162C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800EEAD4(rdram, ctx);
        goto after_4;
    // 0x8080162C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80801630: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801634: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801638: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080163C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801640: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80801644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080164C: jr          $ra
    // 0x80801650: nop

    return;
    // 0x80801650: nop

;}
RECOMP_FUNC void _chpowerhut_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086040: syscall     274
    recomp_syscall_handler(rdram, ctx, 0x80086040);
    return;
    // 0x80086044: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801218_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080121C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801220: jal         0x80800130
    // 0x80801224: nop

    func_80800130_bsstatue(rdram, ctx);
        goto after_0;
    // 0x80801224: nop

    after_0:
    // 0x80801228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080122C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801230: jr          $ra
    // 0x80801234: nop

    return;
    // 0x80801234: nop

;}
RECOMP_FUNC void func_80802A50_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802A50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802A54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802A58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802A5C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80802A60: jal         0x80100094
    // 0x80802A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802A68: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80802A6C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802A70: jal         0x80106790
    // 0x80802A74: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80802A74: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    after_1:
    // 0x80802A78: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    // 0x80802A7C: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80802A80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802A84: beql        $a1, $at, L_80802AE8
    if (ctx->r5 == ctx->r1) {
        // 0x80802A88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802AE8;
    }
    goto skip_0;
    // 0x80802A88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802A8C: jal         0x80089AC8
    // 0x80802A90: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80802A90: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80802A94: beq         $v0, $zero, L_80802AC4
    if (ctx->r2 == 0) {
        // 0x80802A98: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80802AC4;
    }
    // 0x80802A98: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80802A9C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80802AA0: lbu         $a0, 0x20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20);
    // 0x80802AA4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80802AA8: jal         0x800F4F98
    // 0x80802AAC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F4F98(rdram, ctx);
        goto after_3;
    // 0x80802AAC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80802AB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802AB4: jal         0x80089AF0
    // 0x80802AB8: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80802AB8: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    after_4:
    // 0x80802ABC: b           L_80802AD4
    // 0x80802AC0: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
        goto L_80802AD4;
    // 0x80802AC0: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
L_80802AC4:
    // 0x80802AC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80802AC8: jal         0x80089AF0
    // 0x80802ACC: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80802ACC: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    after_5:
    // 0x80802AD0: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
L_80802AD4:
    // 0x80802AD4: sb          $t8, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r24;
    // 0x80802AD8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BE4) << 16);
    // 0x80802ADC: lwc1        $f4, 0x4BE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BE4));
    // 0x80802AE0: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80802AE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802AE8:
    // 0x80802AE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802AEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802AF0: jr          $ra
    // 0x80802AF4: nop

    return;
    // 0x80802AF4: nop

;}
