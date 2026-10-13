#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _ncpoddialog_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895F0: syscall     784
    recomp_syscall_handler(rdram, ctx, 0x800895F0);
    return;
    // 0x800895F4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800000_bskazdie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800008: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080000C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800010: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800014: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800018: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x80800024: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800028: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8080002C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800030: bc1f        L_8080006C
    if (!c1cs) {
        // 0x80800034: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_8080006C;
    }
    // 0x80800034: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800038: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8080003C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80800040: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800044: nop

    // 0x80800048: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_8080004C:
    // 0x8080004C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800050: jal         0x800849F0
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800058: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x8080005C: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x80800060: nop

    // 0x80800064: bc1tl       L_8080004C
    if (c1cs) {
        // 0x80800068: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_8080004C;
    }
    goto skip_0;
    // 0x80800068: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_0:
L_8080006C:
    // 0x8080006C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800070: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800074: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800078: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8080007C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800080: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800084: jr          $ra
    // 0x80800088: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800088: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8008B4F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B4F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B4F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B4FC: jal         0x8008C0B8
    // 0x8008B500: nop

    func_8008C0B8(rdram, ctx);
        goto after_0;
    // 0x8008B500: nop

    after_0:
    // 0x8008B504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B50C: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8008B510: jr          $ra
    // 0x8008B514: nop

    return;
    // 0x8008B514: nop

;}
RECOMP_FUNC void chdoubloon_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800040: jal         0x80101870
    // 0x80800044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080004C: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80800050: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800054: bgezl       $t8, L_80800068
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800058: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800068;
    }
    goto skip_0;
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080005C: jal         0x80103110
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800068:
    // 0x80800068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080006C: jr          $ra
    // 0x80800070: nop

    return;
    // 0x80800070: nop

;}
RECOMP_FUNC void _chanim_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859C0: syscall     184
    recomp_syscall_handler(rdram, ctx, 0x800859C0);
    return;
    // 0x800859C4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80807208_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807208: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080720C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80807210: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807214: jal         0x80807BB8
    // 0x80807218: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80807218: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080721C: jal         0x800827D8
    // 0x80807220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsbabykaz_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80807220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80807224: jal         0x800827B8
    // 0x80807228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsbabykaz_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80807228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080722C: jal         0x800844B8
    // 0x80807230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80807230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80807234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807238: jal         0x80091E48
    // 0x8080723C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80091E48(rdram, ctx);
        goto after_4;
    // 0x8080723C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_4:
    // 0x80807240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80807248: jal         0x80085338
    // 0x8080724C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _batimer_set(rdram, ctx);
        goto after_5;
    // 0x8080724C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_5:
    // 0x80807250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80807254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807258: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080725C: jr          $ra
    // 0x80807260: nop

    return;
    // 0x80807260: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D10: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083D10);
    return;
    // 0x80083D14: addi        $t0, $zero, 0x98
    ctx->r8 = ADD32(0, 0X98);
;}
RECOMP_FUNC void func_800C6744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6744: jr          $ra
    // 0x800C6748: lw          $v0, 0x7C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X7C);
    return;
    // 0x800C6748: lw          $v0, 0x7C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X7C);
;}
RECOMP_FUNC void func_80803698_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803698: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080369C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808036A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808036A4: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x808036A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808036AC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808036B0: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x808036B4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808036B8: jal         0x80089F20
    // 0x808036BC: lui         $a3, 0x4282
    ctx->r7 = S32(0X4282 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808036BC: lui         $a3, 0x4282
    ctx->r7 = S32(0X4282 << 16);
    after_0:
    // 0x808036C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808036C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808036C8: jr          $ra
    // 0x808036CC: nop

    return;
    // 0x808036CC: nop

;}
RECOMP_FUNC void func_808007F4_chboggyboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800800: jal         0x80100094
    // 0x80800804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800808: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080080C: jal         0x8008A058
    // 0x80800810: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    _subaddiefx_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800810: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    after_1:
    // 0x80800814: jal         0x80800AD0
    // 0x80800818: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800AD0_chboggyboy(rdram, ctx);
        goto after_2;
    // 0x80800818: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080081C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800824: jr          $ra
    // 0x80800828: nop

    return;
    // 0x80800828: nop

;}
RECOMP_FUNC void func_80800220_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800220: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800224: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800228: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080022C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800230: jal         0x80100094
    // 0x80800234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800238: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x8080023C: jal         0x800DA298
    // 0x80800240: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800240: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800244: beql        $v0, $zero, L_80800258
    if (ctx->r2 == 0) {
        // 0x80800248: lhu         $t6, 0x72($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X72);
            goto L_80800258;
    }
    goto skip_0;
    // 0x80800248: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x8080024C: jal         0x80801CDC
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CDC_chdinoboss(rdram, ctx);
        goto after_2;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800254: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_80800258:
    // 0x80800258: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080025C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800260: sltiu       $at, $t8, 0x1A
    ctx->r1 = ctx->r24 < 0X1A ? 1 : 0;
    // 0x80800264: beq         $at, $zero, L_80800BE8
    if (ctx->r1 == 0) {
        // 0x80800268: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800BE8;
    }
    // 0x80800268: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080026C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1060, 0X28E0) << 16);
    // 0x80800270: addu        $at, $at, $t8
    gpr jr_addend_80800278 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800274: lw          $t8, 0x28E0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1060, 0X28E0));
    // 0x80800278: jr          $t8
    // 0x8080027C: nop

    switch (jr_addend_80800278 >> 2) {
        case 0: goto L_80800280; break;
        case 1: goto L_80800380; break;
        case 2: goto L_80800380; break;
        case 3: goto L_808003A4; break;
        case 4: goto L_808003D8; break;
        case 5: goto L_80800400; break;
        case 6: goto L_80800478; break;
        case 7: goto L_808004AC; break;
        case 8: goto L_80800540; break;
        case 9: goto L_80800590; break;
        case 10: goto L_80800634; break;
        case 11: goto L_80800668; break;
        case 12: goto L_8080070C; break;
        case 13: goto L_8080079C; break;
        case 14: goto L_808007E4; break;
        case 15: goto L_80800884; break;
        case 16: goto L_80800944; break;
        case 17: goto L_808009AC; break;
        case 18: goto L_808009FC; break;
        case 19: goto L_80800AB4; break;
        case 20: goto L_80800AF8; break;
        case 21: goto L_80800B10; break;
        case 22: goto L_80800B70; break;
        case 23: goto L_80800BAC; break;
        case 24: goto L_80800BC4; break;
        case 25: goto L_80800BE0; break;
        default: switch_error(__func__, 0x80800278, 0x808028E0);
    }
    // 0x8080027C: nop

L_80800280:
    // 0x80800280: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80800284: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800288: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080028C: jal         0x8008A0E0
    // 0x80800290: addiu       $a2, $a2, 0x110
    ctx->r6 = ADD32(ctx->r6, 0X110);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800290: addiu       $a2, $a2, 0x110
    ctx->r6 = ADD32(ctx->r6, 0X110);
    after_3:
    // 0x80800294: jal         0x800EFD24
    // 0x80800298: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    func_800EFD24(rdram, ctx);
        goto after_4;
    // 0x80800298: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_4:
    // 0x8080029C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808002A0: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x808002A4: addiu       $a1, $zero, 0x6D6
    ctx->r5 = ADD32(0, 0X6D6);
    // 0x808002A8: jal         0x8010C9B0
    // 0x808002AC: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    func_8010C9B0(rdram, ctx);
        goto after_5;
    // 0x808002AC: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x808002B0: beq         $v0, $zero, L_80800370
    if (ctx->r2 == 0) {
        // 0x808002B4: nop
    
            goto L_80800370;
    }
    // 0x808002B4: nop

    // 0x808002B8: jal         0x800F54E4
    // 0x808002BC: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x808002BC: nop

    after_6:
    // 0x808002C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002C4: jal         0x800F64A4
    // 0x808002C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F64A4(rdram, ctx);
        goto after_7;
    // 0x808002C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808002CC: beq         $v0, $zero, L_80800370
    if (ctx->r2 == 0) {
        // 0x808002D0: nop
    
            goto L_80800370;
    }
    // 0x808002D0: nop

    // 0x808002D4: jal         0x8010D254
    // 0x808002D8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    func_8010D254(rdram, ctx);
        goto after_8;
    // 0x808002D8: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_8:
    // 0x808002DC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808002E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002E4: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x808002E8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808002EC: nop

    // 0x808002F0: bc1f        L_80800370
    if (!c1cs) {
        // 0x808002F4: nop
    
            goto L_80800370;
    }
    // 0x808002F4: nop

    // 0x808002F8: jal         0x800DA298
    // 0x808002FC: addiu       $a0, $zero, 0x172
    ctx->r4 = ADD32(0, 0X172);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808002FC: addiu       $a0, $zero, 0x172
    ctx->r4 = ADD32(0, 0X172);
    after_9:
    // 0x80800300: beq         $v0, $zero, L_80800348
    if (ctx->r2 == 0) {
        // 0x80800304: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800348;
    }
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80800310: jal         0x8080248C
    // 0x80800314: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_8080248C_chdinoboss(rdram, ctx);
        goto after_10;
    // 0x80800314: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_10:
    // 0x80800318: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080031C: addiu       $t9, $zero, 0x57
    ctx->r25 = ADD32(0, 0X57);
    // 0x80800320: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800324: addiu       $a1, $zero, 0x1801
    ctx->r5 = ADD32(0, 0X1801);
    // 0x80800328: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8080032C: jal         0x8008A208
    // 0x80800330: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80800330: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_11:
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: jal         0x80800F70
    // 0x8080033C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_12;
    // 0x8080033C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x80800340: b           L_80800364
    // 0x80800344: addiu       $a0, $zero, 0x461
    ctx->r4 = ADD32(0, 0X461);
        goto L_80800364;
    // 0x80800344: addiu       $a0, $zero, 0x461
    ctx->r4 = ADD32(0, 0X461);
L_80800348:
    // 0x80800348: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8080034C: jal         0x8080248C
    // 0x80800350: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_8080248C_chdinoboss(rdram, ctx);
        goto after_13;
    // 0x80800350: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_13:
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: jal         0x80800F70
    // 0x8080035C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_14;
    // 0x8080035C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x80800360: addiu       $a0, $zero, 0x461
    ctx->r4 = ADD32(0, 0X461);
L_80800364:
    // 0x80800364: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800368: jal         0x80101180
    // 0x8080036C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_15;
    // 0x8080036C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
L_80800370:
    // 0x80800370: jal         0x808016C0
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016C0_chdinoboss(rdram, ctx);
        goto after_16;
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800378: b           L_80800BE8
    // 0x8080037C: nop

        goto L_80800BE8;
    // 0x8080037C: nop

L_80800380:
    // 0x80800380: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80800384: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800388: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080038C: jal         0x8008A0E0
    // 0x80800390: addiu       $a2, $a2, 0x110
    ctx->r6 = ADD32(ctx->r6, 0X110);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_17;
    // 0x80800390: addiu       $a2, $a2, 0x110
    ctx->r6 = ADD32(ctx->r6, 0X110);
    after_17:
    // 0x80800394: jal         0x808016C0
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016C0_chdinoboss(rdram, ctx);
        goto after_18;
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8080039C: b           L_80800BE8
    // 0x808003A0: nop

        goto L_80800BE8;
    // 0x808003A0: nop

L_808003A4:
    // 0x808003A4: jal         0x808016C0
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016C0_chdinoboss(rdram, ctx);
        goto after_19;
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808003AC: jal         0x800D9078
    // 0x808003B0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_20;
    // 0x808003B0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_20:
    // 0x808003B4: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x808003B8: nop
    
            goto L_80800BE8;
    }
    // 0x808003B8: nop

    // 0x808003BC: jal         0x800FDC28
    // 0x808003C0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800FDC28(rdram, ctx);
        goto after_21;
    // 0x808003C0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_21:
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C8: jal         0x80800F70
    // 0x808003CC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_22;
    // 0x808003CC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_22:
    // 0x808003D0: b           L_80800BE8
    // 0x808003D4: nop

        goto L_80800BE8;
    // 0x808003D4: nop

L_808003D8:
    // 0x808003D8: jal         0x808017A0
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017A0_chdinoboss(rdram, ctx);
        goto after_23;
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808003E0: jal         0x80101DDC
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_24;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808003E8: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x808003EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BE8;
    }
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F0: jal         0x80800F70
    // 0x808003F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_25;
    // 0x808003F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_25:
    // 0x808003F8: b           L_80800BE8
    // 0x808003FC: nop

        goto L_80800BE8;
    // 0x808003FC: nop

L_80800400:
    // 0x80800400: jal         0x800DA298
    // 0x80800404: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA298(rdram, ctx);
        goto after_26;
    // 0x80800404: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_26:
    // 0x80800408: bnel        $v0, $zero, L_80800448
    if (ctx->r2 != 0) {
        // 0x8080040C: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800448;
    }
    goto skip_1;
    // 0x8080040C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_1:
    // 0x80800410: jal         0x80802500
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802500_chdinoboss(rdram, ctx);
        goto after_27;
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080041C: jal         0x80800F70
    // 0x80800420: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_28;
    // 0x80800420: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_28:
    // 0x80800424: jal         0x80801C28
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C28_chdinoboss(rdram, ctx);
        goto after_29;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8080042C: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80800430: addiu       $a0, $zero, 0x172
    ctx->r4 = ADD32(0, 0X172);
    // 0x80800434: jal         0x800DA544
    // 0x80800438: sw          $v0, 0x120($t0)
    MEM_W(0X120, ctx->r8) = ctx->r2;
    func_800DA544(rdram, ctx);
        goto after_30;
    // 0x80800438: sw          $v0, 0x120($t0)
    MEM_W(0X120, ctx->r8) = ctx->r2;
    after_30:
    // 0x8080043C: jal         0x80088178
    // 0x80800440: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_31;
    // 0x80800440: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_31:
    // 0x80800444: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800448:
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080044C: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80800450: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80800454: jal         0x80801660
    // 0x80800458: nop

    func_80801660_chdinoboss(rdram, ctx);
        goto after_32;
    // 0x80800458: nop

    after_32:
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: jal         0x80801D08
    // 0x80800464: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801D08_chdinoboss(rdram, ctx);
        goto after_33;
    // 0x80800464: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_33:
    // 0x80800468: jal         0x808017D0
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017D0_chdinoboss(rdram, ctx);
        goto after_34;
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800470: b           L_80800BE8
    // 0x80800474: nop

        goto L_80800BE8;
    // 0x80800474: nop

L_80800478:
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080047C: jal         0x80801D08
    // 0x80800480: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801D08_chdinoboss(rdram, ctx);
        goto after_35;
    // 0x80800480: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_35:
    // 0x80800484: jal         0x808017D0
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017D0_chdinoboss(rdram, ctx);
        goto after_36;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x8080048C: jal         0x800D9078
    // 0x80800490: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_37;
    // 0x80800490: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_37:
    // 0x80800494: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x80800498: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BE8;
    }
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080049C: jal         0x80800F70
    // 0x808004A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_38;
    // 0x808004A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_38:
    // 0x808004A4: b           L_80800BE8
    // 0x808004A8: nop

        goto L_80800BE8;
    // 0x808004A8: nop

L_808004AC:
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B0: jal         0x80801D08
    // 0x808004B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801D08_chdinoboss(rdram, ctx);
        goto after_39;
    // 0x808004B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_39:
    // 0x808004B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2A34) << 16);
    // 0x808004BC: lui         $a3, 0x3F26
    ctx->r7 = S32(0X3F26 << 16);
    // 0x808004C0: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x808004C4: addiu       $a2, $a2, 0x2A34
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2A34));
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004CC: jal         0x80089D20
    // 0x808004D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_40;
    // 0x808004D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_40:
    // 0x808004D4: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808004D8: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808004DC: jal         0x80101E14
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_41;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x808004E4: beq         $v0, $zero, L_808004F4
    if (ctx->r2 == 0) {
        // 0x808004E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004F4;
    }
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: jal         0x80108B04
    // 0x808004F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_42;
    // 0x808004F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_42:
L_808004F4:
    // 0x808004F4: jal         0x80101DDC
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_43;
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x808004FC: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x80800500: lw          $t1, 0x84($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X84);
            goto L_80800BE8;
    }
    // 0x80800500: lw          $t1, 0x84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X84);
    // 0x80800504: lw          $t2, 0x120($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X120);
    // 0x80800508: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800510: blez        $t2, L_80800530
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80800514: nop
    
            goto L_80800530;
    }
    // 0x80800514: nop

    // 0x80800518: jal         0x80800F70
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_44;
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x80800520: jal         0x80801C84
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C84_chdinoboss(rdram, ctx);
        goto after_45;
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80800528: b           L_80800BE8
    // 0x8080052C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80800BE8;
    // 0x8080052C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800530:
    // 0x80800530: jal         0x80800F70
    // 0x80800534: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_46;
    // 0x80800534: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_46:
    // 0x80800538: b           L_80800BE8
    // 0x8080053C: nop

        goto L_80800BE8;
    // 0x8080053C: nop

L_80800540:
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: jal         0x80801D08
    // 0x80800548: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801D08_chdinoboss(rdram, ctx);
        goto after_47;
    // 0x80800548: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_47:
    // 0x8080054C: jal         0x808017D0
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017D0_chdinoboss(rdram, ctx);
        goto after_48;
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x80800554: addiu       $a0, $zero, 0x398
    ctx->r4 = ADD32(0, 0X398);
    // 0x80800558: jal         0x80089C30
    // 0x8080055C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_49;
    // 0x8080055C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_49:
    // 0x80800560: bne         $v0, $zero, L_80800BE8
    if (ctx->r2 != 0) {
        // 0x80800564: nop
    
            goto L_80800BE8;
    }
    // 0x80800564: nop

    // 0x80800568: jal         0x800D9078
    // 0x8080056C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_50;
    // 0x8080056C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_50:
    // 0x80800570: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x80800574: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BE8;
    }
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: jal         0x80800F70
    // 0x8080057C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_51;
    // 0x8080057C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_51:
    // 0x80800580: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80800584: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800588: b           L_80800BE8
    // 0x8080058C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80800BE8;
    // 0x8080058C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80800590:
    // 0x80800590: jal         0x800D8FF8
    // 0x80800594: nop

    func_800D8FF8(rdram, ctx);
        goto after_52;
    // 0x80800594: nop

    after_52:
    // 0x80800598: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8080059C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808005A0: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x808005A4: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808005A8: lwc1        $f16, 0x130($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X130);
    // 0x808005AC: jal         0x800136E4
    // 0x808005B0: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_53;
    // 0x808005B0: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    after_53:
    // 0x808005B4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808005B8: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x808005C4: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x808005C8: jal         0x80801660
    // 0x808005CC: swc1        $f0, 0x130($t4)
    MEM_W(0X130, ctx->r12) = ctx->f0.u32l;
    func_80801660_chdinoboss(rdram, ctx);
        goto after_54;
    // 0x808005CC: swc1        $f0, 0x130($t4)
    MEM_W(0X130, ctx->r12) = ctx->f0.u32l;
    after_54:
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D4: jal         0x80801D08
    // 0x808005D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801D08_chdinoboss(rdram, ctx);
        goto after_55;
    // 0x808005D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_55:
    // 0x808005DC: jal         0x80801800
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801800_chdinoboss(rdram, ctx);
        goto after_56;
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x808005E4: jal         0x800D9078
    // 0x808005E8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_57;
    // 0x808005E8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_57:
    // 0x808005EC: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x808005F0: lw          $t5, 0x84($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X84);
            goto L_80800BE8;
    }
    // 0x808005F0: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x808005F4: lh          $t6, 0x11E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X11E);
    // 0x808005F8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: bne         $t6, $zero, L_80800624
    if (ctx->r14 != 0) {
        // 0x80800604: nop
    
            goto L_80800624;
    }
    // 0x80800604: nop

    // 0x80800608: jal         0x80800F70
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_58;
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x80800610: jal         0x80801C28
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C28_chdinoboss(rdram, ctx);
        goto after_59;
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x80800618: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x8080061C: b           L_80800BE8
    // 0x80800620: sw          $v0, 0x120($t7)
    MEM_W(0X120, ctx->r15) = ctx->r2;
        goto L_80800BE8;
    // 0x80800620: sw          $v0, 0x120($t7)
    MEM_W(0X120, ctx->r15) = ctx->r2;
L_80800624:
    // 0x80800624: jal         0x80800F70
    // 0x80800628: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_60;
    // 0x80800628: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_60:
    // 0x8080062C: b           L_80800BE8
    // 0x80800630: nop

        goto L_80800BE8;
    // 0x80800630: nop

L_80800634:
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800638: jal         0x80801D08
    // 0x8080063C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801D08_chdinoboss(rdram, ctx);
        goto after_61;
    // 0x8080063C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_61:
    // 0x80800640: jal         0x808017D0
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017D0_chdinoboss(rdram, ctx);
        goto after_62;
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_62:
    // 0x80800648: jal         0x800D9078
    // 0x8080064C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_63;
    // 0x8080064C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_63:
    // 0x80800650: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x80800654: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BE8;
    }
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800658: jal         0x80800F70
    // 0x8080065C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_64;
    // 0x8080065C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_64:
    // 0x80800660: b           L_80800BE8
    // 0x80800664: nop

        goto L_80800BE8;
    // 0x80800664: nop

L_80800668:
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: jal         0x80801D08
    // 0x80800670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801D08_chdinoboss(rdram, ctx);
        goto after_65;
    // 0x80800670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_65:
    // 0x80800674: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2A34) << 16);
    // 0x80800678: lui         $a3, 0x3F26
    ctx->r7 = S32(0X3F26 << 16);
    // 0x8080067C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800680: addiu       $a2, $a2, 0x2A34
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2A34));
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800688: jal         0x80089D20
    // 0x8080068C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_66;
    // 0x8080068C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_66:
    // 0x80800690: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800694: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800698: jal         0x80101E14
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_67;
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_67:
    // 0x808006A0: beq         $v0, $zero, L_808006B0
    if (ctx->r2 == 0) {
        // 0x808006A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006B0;
    }
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A8: jal         0x80108B04
    // 0x808006AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_68;
    // 0x808006AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_68:
L_808006B0:
    // 0x808006B0: jal         0x80101DDC
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_69;
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_69:
    // 0x808006B8: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x808006BC: lw          $t8, 0x84($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X84);
            goto L_80800BE8;
    }
    // 0x808006BC: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x808006C0: lw          $t9, 0x120($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X120);
    // 0x808006C4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006CC: blez        $t9, L_808006FC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x808006D0: nop
    
            goto L_808006FC;
    }
    // 0x808006D0: nop

    // 0x808006D4: jal         0x80800F70
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_70;
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_70:
    // 0x808006DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808006E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808006E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808006EC: jal         0x800DC178
    // 0x808006F0: nop

    func_800DC178(rdram, ctx);
        goto after_71;
    // 0x808006F0: nop

    after_71:
    // 0x808006F4: b           L_80800BE8
    // 0x808006F8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80800BE8;
    // 0x808006F8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_808006FC:
    // 0x808006FC: jal         0x80800F70
    // 0x80800700: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_72;
    // 0x80800700: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_72:
    // 0x80800704: b           L_80800BE8
    // 0x80800708: nop

        goto L_80800BE8;
    // 0x80800708: nop

L_8080070C:
    // 0x8080070C: jal         0x800D9078
    // 0x80800710: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_73;
    // 0x80800710: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_73:
    // 0x80800714: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800718: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8080071C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800720: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800724: lui         $a3, 0xC28C
    ctx->r7 = S32(0XC28C << 16);
    // 0x80800728: jal         0x800F10B4
    // 0x8080072C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_74;
    // 0x8080072C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_74:
    // 0x80800730: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800734: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80800738: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080073C: lui         $a3, 0x45CB
    ctx->r7 = S32(0X45CB << 16);
    // 0x80800740: ori         $a3, $a3, 0x2000
    ctx->r7 = ctx->r7 | 0X2000;
    // 0x80800744: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800748: jal         0x800F10B4
    // 0x8080074C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_75;
    // 0x8080074C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_75:
    // 0x80800750: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800758: jal         0x80801660
    // 0x8080075C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_80801660_chdinoboss(rdram, ctx);
        goto after_76;
    // 0x8080075C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_76:
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800764: jal         0x80801D08
    // 0x80800768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801D08_chdinoboss(rdram, ctx);
        goto after_77;
    // 0x80800768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_77:
    // 0x8080076C: jal         0x808017D0
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017D0_chdinoboss(rdram, ctx);
        goto after_78;
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_78:
    // 0x80800774: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080077C: beq         $t0, $zero, L_80800BE8
    if (ctx->r8 == 0) {
        // 0x80800780: nop
    
            goto L_80800BE8;
    }
    // 0x80800780: nop

    // 0x80800784: jal         0x80800F70
    // 0x80800788: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_79;
    // 0x80800788: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_79:
    // 0x8080078C: jal         0x800DA544
    // 0x80800790: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_80;
    // 0x80800790: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_80:
    // 0x80800794: b           L_80800BE8
    // 0x80800798: nop

        goto L_80800BE8;
    // 0x80800798: nop

L_8080079C:
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A0: jal         0x80801D08
    // 0x808007A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801D08_chdinoboss(rdram, ctx);
        goto after_81;
    // 0x808007A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_81:
    // 0x808007A8: addiu       $a0, $zero, 0x399
    ctx->r4 = ADD32(0, 0X399);
    // 0x808007AC: jal         0x80089C30
    // 0x808007B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_82;
    // 0x808007B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_82:
    // 0x808007B4: bne         $v0, $zero, L_80800BE8
    if (ctx->r2 != 0) {
        // 0x808007B8: nop
    
            goto L_80800BE8;
    }
    // 0x808007B8: nop

    // 0x808007BC: jal         0x800D90A4
    // 0x808007C0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_83;
    // 0x808007C0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_83:
    // 0x808007C4: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x808007C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BE8;
    }
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007CC: jal         0x80800F70
    // 0x808007D0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_84;
    // 0x808007D0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_84:
    // 0x808007D4: jal         0x800DA524
    // 0x808007D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA524(rdram, ctx);
        goto after_85;
    // 0x808007D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_85:
    // 0x808007DC: b           L_80800BE8
    // 0x808007E0: nop

        goto L_80800BE8;
    // 0x808007E0: nop

L_808007E4:
    // 0x808007E4: jal         0x800D9078
    // 0x808007E8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_86;
    // 0x808007E8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_86:
    // 0x808007EC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808007F0: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x808007F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007F8: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x808007FC: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800800: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800804: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800808: jal         0x800F10B4
    // 0x8080080C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_87;
    // 0x8080080C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_87:
    // 0x80800810: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800814: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1060, 0X2948) << 16);
    // 0x80800818: lwc1        $f8, 0x2948($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1060, 0X2948));
    // 0x8080081C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80800820: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800824: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800828: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x8080082C: jal         0x800F10B4
    // 0x80800830: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_88;
    // 0x80800830: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_88:
    // 0x80800834: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080083C: jal         0x80801660
    // 0x80800840: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_80801660_chdinoboss(rdram, ctx);
        goto after_89;
    // 0x80800840: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_89:
    // 0x80800844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800848: jal         0x80801D08
    // 0x8080084C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801D08_chdinoboss(rdram, ctx);
        goto after_90;
    // 0x8080084C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_90:
    // 0x80800850: jal         0x808017D0
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017D0_chdinoboss(rdram, ctx);
        goto after_91;
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_91:
    // 0x80800858: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800860: beq         $t1, $zero, L_80800BE8
    if (ctx->r9 == 0) {
        // 0x80800864: nop
    
            goto L_80800BE8;
    }
    // 0x80800864: nop

    // 0x80800868: jal         0x80800F70
    // 0x8080086C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_92;
    // 0x8080086C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_92:
    // 0x80800870: jal         0x80801C28
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C28_chdinoboss(rdram, ctx);
        goto after_93;
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_93:
    // 0x80800878: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8080087C: b           L_80800BE8
    // 0x80800880: sw          $v0, 0x120($t2)
    MEM_W(0X120, ctx->r10) = ctx->r2;
        goto L_80800BE8;
    // 0x80800880: sw          $v0, 0x120($t2)
    MEM_W(0X120, ctx->r10) = ctx->r2;
L_80800884:
    // 0x80800884: jal         0x800D8FF8
    // 0x80800888: nop

    func_800D8FF8(rdram, ctx);
        goto after_94;
    // 0x80800888: nop

    after_94:
    // 0x8080088C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800890: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800894: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x80800898: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8080089C: lwc1        $f12, 0x130($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X130);
    // 0x808008A0: lwc1        $f14, 0x124($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X124);
    // 0x808008A4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808008A8: jal         0x800F1F38
    // 0x808008AC: nop

    func_800F1F38(rdram, ctx);
        goto after_95;
    // 0x808008AC: nop

    after_95:
    // 0x808008B0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808008B4: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008BC: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x808008C0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x808008C4: jal         0x80801660
    // 0x808008C8: swc1        $f0, 0x130($t3)
    MEM_W(0X130, ctx->r11) = ctx->f0.u32l;
    func_80801660_chdinoboss(rdram, ctx);
        goto after_96;
    // 0x808008C8: swc1        $f0, 0x130($t3)
    MEM_W(0X130, ctx->r11) = ctx->f0.u32l;
    after_96:
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D0: jal         0x80801D08
    // 0x808008D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801D08_chdinoboss(rdram, ctx);
        goto after_97;
    // 0x808008D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_97:
    // 0x808008D8: jal         0x80801830
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801830_chdinoboss(rdram, ctx);
        goto after_98;
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_98:
    // 0x808008E0: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x808008E4: lwc1        $f12, 0x130($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X130);
    // 0x808008E8: jal         0x800F2094
    // 0x808008EC: lwc1        $f14, 0x124($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X124);
    func_800F2094(rdram, ctx);
        goto after_99;
    // 0x808008EC: lwc1        $f14, 0x124($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X124);
    after_99:
    // 0x808008F0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808008F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008FC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800900: nop

    // 0x80800904: bc1f        L_80800BE8
    if (!c1cs) {
        // 0x80800908: nop
    
            goto L_80800BE8;
    }
    // 0x80800908: nop

    // 0x8080090C: jal         0x80102CF4
    // 0x80800910: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102CF4(rdram, ctx);
        goto after_100;
    // 0x80800910: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_100:
    // 0x80800914: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x80800918: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BE8;
    }
    // 0x80800918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080091C: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800920: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80800924: jal         0x80800F70
    // 0x80800928: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_101;
    // 0x80800928: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    after_101:
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800930: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800934: jal         0x8080248C
    // 0x80800938: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_8080248C_chdinoboss(rdram, ctx);
        goto after_102;
    // 0x80800938: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_102:
    // 0x8080093C: b           L_80800BE8
    // 0x80800940: nop

        goto L_80800BE8;
    // 0x80800940: nop

L_80800944:
    // 0x80800944: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2A2C) << 16);
    // 0x80800948: lui         $a3, 0x3EB3
    ctx->r7 = S32(0X3EB3 << 16);
    // 0x8080094C: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800950: addiu       $a2, $a2, 0x2A2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2A2C));
    // 0x80800954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800958: jal         0x80089D20
    // 0x8080095C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_103;
    // 0x8080095C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_103:
    // 0x80800960: beq         $v0, $zero, L_8080098C
    if (ctx->r2 == 0) {
        // 0x80800964: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080098C;
    }
    // 0x80800964: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800968: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x8080096C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800970: jal         0x800E15CC
    // 0x80800974: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_104;
    // 0x80800974: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_104:
    // 0x80800978: lui         $a2, 0x3EE6
    ctx->r6 = S32(0X3EE6 << 16);
    // 0x8080097C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800980: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800984: jal         0x80018820
    // 0x80800988: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80018820(rdram, ctx);
        goto after_105;
    // 0x80800988: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_105:
L_8080098C:
    // 0x8080098C: jal         0x80101DDC
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_106;
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_106:
    // 0x80800994: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x80800998: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BE8;
    }
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080099C: jal         0x80800F70
    // 0x808009A0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_107;
    // 0x808009A0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_107:
    // 0x808009A4: b           L_80800BE8
    // 0x808009A8: nop

        goto L_80800BE8;
    // 0x808009A8: nop

L_808009AC:
    // 0x808009AC: jal         0x800D9078
    // 0x808009B0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_108;
    // 0x808009B0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_108:
    // 0x808009B4: beq         $v0, $zero, L_808009EC
    if (ctx->r2 == 0) {
        // 0x808009B8: nop
    
            goto L_808009EC;
    }
    // 0x808009B8: nop

    // 0x808009BC: jal         0x800D395C
    // 0x808009C0: nop

    func_800D395C(rdram, ctx);
        goto after_109;
    // 0x808009C0: nop

    after_109:
    // 0x808009C4: beq         $v0, $zero, L_808009E4
    if (ctx->r2 == 0) {
        // 0x808009C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009E4;
    }
    // 0x808009C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009CC: jal         0x80802500
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802500_chdinoboss(rdram, ctx);
        goto after_110;
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_110:
    // 0x808009D4: jal         0x80088180
    // 0x808009D8: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_111;
    // 0x808009D8: nop

    after_111:
    // 0x808009DC: b           L_808009EC
    // 0x808009E0: nop

        goto L_808009EC;
    // 0x808009E0: nop

L_808009E4:
    // 0x808009E4: jal         0x80800F70
    // 0x808009E8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_112;
    // 0x808009E8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_112:
L_808009EC:
    // 0x808009EC: jal         0x80801860
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801860_chdinoboss(rdram, ctx);
        goto after_113;
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_113:
    // 0x808009F4: b           L_80800BE8
    // 0x808009F8: nop

        goto L_80800BE8;
    // 0x808009F8: nop

L_808009FC:
    // 0x808009FC: jal         0x80801860
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801860_chdinoboss(rdram, ctx);
        goto after_114;
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_114:
    // 0x80800A04: jal         0x800C9510
    // 0x80800A08: nop

    func_800C9510(rdram, ctx);
        goto after_115;
    // 0x80800A08: nop

    after_115:
    // 0x80800A0C: bne         $v0, $zero, L_80800BE8
    if (ctx->r2 != 0) {
        // 0x80800A10: lui         $v0, 0x8080
        ctx->r2 = S32(RELOC_HI16(1060, 0X2A68) << 16);
            goto L_80800BE8;
    }
    // 0x80800A10: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1060, 0X2A68) << 16);
    // 0x80800A14: addiu       $v0, $v0, 0x2A68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1060, 0X2A68));
    // 0x80800A18: lhu         $t4, 0xAE($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0XAE);
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A20: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80800A24: ori         $t5, $t4, 0x200
    ctx->r13 = ctx->r12 | 0X200;
    // 0x80800A28: jal         0x80800F70
    // 0x80800A2C: sh          $t5, 0xAE($v0)
    MEM_H(0XAE, ctx->r2) = ctx->r13;
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_116;
    // 0x80800A2C: sh          $t5, 0xAE($v0)
    MEM_H(0XAE, ctx->r2) = ctx->r13;
    after_116:
    // 0x80800A30: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1060, 0X2A68) << 16);
    // 0x80800A34: addiu       $v0, $v0, 0x2A68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1060, 0X2A68));
    // 0x80800A38: lhu         $t6, 0xAE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XAE);
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A40: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80800A44: andi        $t7, $t6, 0xFDFF
    ctx->r15 = ctx->r14 & 0XFDFF;
    // 0x80800A48: sh          $t7, 0xAE($v0)
    MEM_H(0XAE, ctx->r2) = ctx->r15;
    // 0x80800A4C: jal         0x8080248C
    // 0x80800A50: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8080248C_chdinoboss(rdram, ctx);
        goto after_117;
    // 0x80800A50: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_117:
    // 0x80800A54: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800A58: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800A5C: addiu       $t8, $zero, 0x57
    ctx->r24 = ADD32(0, 0X57);
    // 0x80800A60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800A64: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800A68: addiu       $a1, $zero, 0x17B6
    ctx->r5 = ADD32(0, 0X17B6);
    // 0x80800A6C: jal         0x8008A208
    // 0x80800A70: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_118;
    // 0x80800A70: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_118:
    // 0x80800A74: jal         0x800EFD24
    // 0x80800A78: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800EFD24(rdram, ctx);
        goto after_119;
    // 0x80800A78: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_119:
    // 0x80800A7C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1060, 0X2A20) << 16);
    // 0x80800A80: addiu       $a0, $a0, 0x2A20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1060, 0X2A20));
    // 0x80800A84: jal         0x800F1DF4
    // 0x80800A88: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F1DF4(rdram, ctx);
        goto after_120;
    // 0x80800A88: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_120:
    // 0x80800A8C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1060, 0X2A20) << 16);
    // 0x80800A90: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800A94: jal         0x800907C0
    // 0x80800A98: addiu       $a0, $a0, 0x2A20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1060, 0X2A20));
    func_800907C0(rdram, ctx);
        goto after_121;
    // 0x80800A98: addiu       $a0, $a0, 0x2A20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1060, 0X2A20));
    after_121:
    // 0x80800A9C: jal         0x800906DC
    // 0x80800AA0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800906DC(rdram, ctx);
        goto after_122;
    // 0x80800AA0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_122:
    // 0x80800AA4: jal         0x800C964C
    // 0x80800AA8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C964C(rdram, ctx);
        goto after_123;
    // 0x80800AA8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_123:
    // 0x80800AAC: b           L_80800BE8
    // 0x80800AB0: nop

        goto L_80800BE8;
    // 0x80800AB0: nop

L_80800AB4:
    // 0x80800AB4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2BD0) << 16);
    // 0x80800AB8: addiu       $a2, $a2, 0x2BD0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2BD0));
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC0: jal         0x8008A1E8
    // 0x80800AC4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_124;
    // 0x80800AC4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_124:
    // 0x80800AC8: beq         $v0, $zero, L_80800AE0
    if (ctx->r2 == 0) {
        // 0x80800ACC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800AE0;
    }
    // 0x80800ACC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800AD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800AD4: addiu       $a2, $zero, 0x27
    ctx->r6 = ADD32(0, 0X27);
    // 0x80800AD8: jal         0x80085708
    // 0x80800ADC: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    _capod_entrypoint_13(rdram, ctx);
        goto after_125;
    // 0x80800ADC: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_125:
L_80800AE0:
    // 0x80800AE0: jal         0x808018D0
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018D0_chdinoboss(rdram, ctx);
        goto after_126;
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_126:
    // 0x80800AE8: jal         0x80802540
    // 0x80800AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802540_chdinoboss(rdram, ctx);
        goto after_127;
    // 0x80800AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_127:
    // 0x80800AF0: b           L_80800BE8
    // 0x80800AF4: nop

        goto L_80800BE8;
    // 0x80800AF4: nop

L_80800AF8:
    // 0x80800AF8: jal         0x808018D0
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018D0_chdinoboss(rdram, ctx);
        goto after_128;
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_128:
    // 0x80800B00: jal         0x80802540
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802540_chdinoboss(rdram, ctx);
        goto after_129;
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_129:
    // 0x80800B08: b           L_80800BE8
    // 0x80800B0C: nop

        goto L_80800BE8;
    // 0x80800B0C: nop

L_80800B10:
    // 0x80800B10: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2A58) << 16);
    // 0x80800B14: lui         $a3, 0x3EE6
    ctx->r7 = S32(0X3EE6 << 16);
    // 0x80800B18: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800B1C: addiu       $a2, $a2, 0x2A58
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2A58));
    // 0x80800B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B24: jal         0x80089D20
    // 0x80800B28: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_130;
    // 0x80800B28: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_130:
    // 0x80800B2C: jal         0x80101DDC
    // 0x80800B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_131;
    // 0x80800B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_131:
    // 0x80800B34: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x80800B38: lw          $t9, 0x84($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X84);
            goto L_80800BE8;
    }
    // 0x80800B38: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x80800B3C: lh          $t0, 0x11E($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X11E);
    // 0x80800B40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800B44: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80800B48: bne         $t0, $at, L_80800B60
    if (ctx->r8 != ctx->r1) {
        // 0x80800B4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B60;
    }
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B50: jal         0x80800F70
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_132;
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_132:
    // 0x80800B58: b           L_80800BE8
    // 0x80800B5C: nop

        goto L_80800BE8;
    // 0x80800B5C: nop

L_80800B60:
    // 0x80800B60: jal         0x80800F70
    // 0x80800B64: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_133;
    // 0x80800B64: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_133:
    // 0x80800B68: b           L_80800BE8
    // 0x80800B6C: nop

        goto L_80800BE8;
    // 0x80800B6C: nop

L_80800B70:
    // 0x80800B70: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2A58) << 16);
    // 0x80800B74: lui         $a3, 0x3EE6
    ctx->r7 = S32(0X3EE6 << 16);
    // 0x80800B78: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800B7C: addiu       $a2, $a2, 0x2A58
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2A58));
    // 0x80800B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B84: jal         0x80089D20
    // 0x80800B88: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_134;
    // 0x80800B88: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_134:
    // 0x80800B8C: jal         0x80101DDC
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_135;
    // 0x80800B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_135:
    // 0x80800B94: beq         $v0, $zero, L_80800BE8
    if (ctx->r2 == 0) {
        // 0x80800B98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BE8;
    }
    // 0x80800B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B9C: jal         0x80800F70
    // 0x80800BA0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80800F70_chdinoboss(rdram, ctx);
        goto after_136;
    // 0x80800BA0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_136:
    // 0x80800BA4: b           L_80800BE8
    // 0x80800BA8: nop

        goto L_80800BE8;
    // 0x80800BA8: nop

L_80800BAC:
    // 0x80800BAC: jal         0x80802540
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802540_chdinoboss(rdram, ctx);
        goto after_137;
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_137:
    // 0x80800BB4: jal         0x808016C0
    // 0x80800BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016C0_chdinoboss(rdram, ctx);
        goto after_138;
    // 0x80800BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_138:
    // 0x80800BBC: b           L_80800BE8
    // 0x80800BC0: nop

        goto L_80800BE8;
    // 0x80800BC0: nop

L_80800BC4:
    // 0x80800BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC8: jal         0x80801D08
    // 0x80800BCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801D08_chdinoboss(rdram, ctx);
        goto after_139;
    // 0x80800BCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_139:
    // 0x80800BD0: jal         0x808017D0
    // 0x80800BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017D0_chdinoboss(rdram, ctx);
        goto after_140;
    // 0x80800BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_140:
    // 0x80800BD8: b           L_80800BE8
    // 0x80800BDC: nop

        goto L_80800BE8;
    // 0x80800BDC: nop

L_80800BE0:
    // 0x80800BE0: jal         0x808016C0
    // 0x80800BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016C0_chdinoboss(rdram, ctx);
        goto after_141;
    // 0x80800BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_141:
L_80800BE8:
    // 0x80800BE8: jal         0x80801DC8
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801DC8_chdinoboss(rdram, ctx);
        goto after_142;
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_142:
    // 0x80800BF0: jal         0x801022E4
    // 0x80800BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_143;
    // 0x80800BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_143:
    // 0x80800BF8: addiu       $at, $zero, 0x163
    ctx->r1 = ADD32(0, 0X163);
    // 0x80800BFC: beq         $v0, $at, L_80800C14
    if (ctx->r2 == ctx->r1) {
        // 0x80800C00: addiu       $at, $zero, 0x1C1
        ctx->r1 = ADD32(0, 0X1C1);
            goto L_80800C14;
    }
    // 0x80800C00: addiu       $at, $zero, 0x1C1
    ctx->r1 = ADD32(0, 0X1C1);
    // 0x80800C04: beq         $v0, $at, L_80800C14
    if (ctx->r2 == ctx->r1) {
        // 0x80800C08: addiu       $at, $zero, 0x1F7
        ctx->r1 = ADD32(0, 0X1F7);
            goto L_80800C14;
    }
    // 0x80800C08: addiu       $at, $zero, 0x1F7
    ctx->r1 = ADD32(0, 0X1F7);
    // 0x80800C0C: bnel        $v0, $at, L_80800C24
    if (ctx->r2 != ctx->r1) {
        // 0x80800C10: addiu       $s0, $sp, 0x34
        ctx->r16 = ADD32(ctx->r29, 0X34);
            goto L_80800C24;
    }
    goto skip_2;
    // 0x80800C10: addiu       $s0, $sp, 0x34
    ctx->r16 = ADD32(ctx->r29, 0X34);
    skip_2:
L_80800C14:
    // 0x80800C14: jal         0x800D395C
    // 0x80800C18: nop

    func_800D395C(rdram, ctx);
        goto after_144;
    // 0x80800C18: nop

    after_144:
    // 0x80800C1C: beq         $v0, $zero, L_80800C3C
    if (ctx->r2 == 0) {
        // 0x80800C20: addiu       $s0, $sp, 0x34
        ctx->r16 = ADD32(ctx->r29, 0X34);
            goto L_80800C3C;
    }
    // 0x80800C20: addiu       $s0, $sp, 0x34
    ctx->r16 = ADD32(ctx->r29, 0X34);
L_80800C24:
    // 0x80800C24: jal         0x800EFD24
    // 0x80800C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFD24(rdram, ctx);
        goto after_145;
    // 0x80800C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_145:
    // 0x80800C2C: lui         $a1, 0x4A3A
    ctx->r5 = S32(0X4A3A << 16);
    // 0x80800C30: ori         $a1, $a1, 0xEB90
    ctx->r5 = ctx->r5 | 0XEB90;
    // 0x80800C34: jal         0x8008A0B8
    // 0x80800C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiemulti_entrypoint_6(rdram, ctx);
        goto after_146;
    // 0x80800C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_146:
L_80800C3C:
    // 0x80800C3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800C40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C44: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80800C48: jr          $ra
    // 0x80800C4C: nop

    return;
    // 0x80800C4C: nop

;}
RECOMP_FUNC void func_80092E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092E2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092E34: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80092E38: jal         0x800921E0
    // 0x80092E3C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800921E0(rdram, ctx);
        goto after_0;
    // 0x80092E3C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x80092E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092E48: jr          $ra
    // 0x80092E4C: nop

    return;
    // 0x80092E4C: nop

;}
RECOMP_FUNC void func_800148C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800148C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800148C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800148CC: jal         0x80012F00
    // 0x800148D0: nop

    func_80012F00(rdram, ctx);
        goto after_0;
    // 0x800148D0: nop

    after_0:
    // 0x800148D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800148D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800148DC: jal         0x8002EAD0
    // 0x800148E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800148E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800148E4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800148E8: addiu       $a0, $a0, -0x7B74
    ctx->r4 = ADD32(ctx->r4, -0X7B74);
    // 0x800148EC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800148F0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800148F4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800148F8: bne         $v1, $at, L_80014954
    if (ctx->r3 != ctx->r1) {
        // 0x800148FC: addiu       $v0, $v0, -0x70FC
        ctx->r2 = ADD32(ctx->r2, -0X70FC);
            goto L_80014954;
    }
    // 0x800148FC: addiu       $v0, $v0, -0x70FC
    ctx->r2 = ADD32(ctx->r2, -0X70FC);
    // 0x80014900: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80014904: addiu       $t6, $t6, -0x7100
    ctx->r14 = ADD32(ctx->r14, -0X7100);
    // 0x80014908: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001490C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80014910: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014914: beq         $t7, $t8, L_80014954
    if (ctx->r15 == ctx->r24) {
        // 0x80014918: nop
    
            goto L_80014954;
    }
    // 0x80014918: nop

    // 0x8001491C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80014920: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80014924: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80014928: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001492C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80014930: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80014934: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80014938: lw          $a0, -0x7150($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7150);
    // 0x8001493C: mfhi        $t3
    ctx->r11 = hi;
    // 0x80014940: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80014944: jal         0x80013E34
    // 0x80014948: nop

    func_80013E34(rdram, ctx);
        goto after_2;
    // 0x80014948: nop

    after_2:
    // 0x8001494C: b           L_800149B0
    // 0x80014950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800149B0;
    // 0x80014950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80014954:
    // 0x80014954: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014958: andi        $t4, $v1, 0x8
    ctx->r12 = ctx->r3 & 0X8;
    // 0x8001495C: beq         $t4, $zero, L_800149AC
    if (ctx->r12 == 0) {
        // 0x80014960: addiu       $v0, $v0, -0x70FC
        ctx->r2 = ADD32(ctx->r2, -0X70FC);
            goto L_800149AC;
    }
    // 0x80014960: addiu       $v0, $v0, -0x70FC
    ctx->r2 = ADD32(ctx->r2, -0X70FC);
    // 0x80014964: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80014968: addiu       $t5, $t5, -0x7100
    ctx->r13 = ADD32(ctx->r13, -0X7100);
    // 0x8001496C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80014970: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80014974: beql        $t6, $t7, L_800149B0
    if (ctx->r14 == ctx->r15) {
        // 0x80014978: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800149B0;
    }
    goto skip_0;
    // 0x80014978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001497C: jal         0x8002F760
    // 0x80014980: nop

    osSpTaskYield_recomp(rdram, ctx);
        goto after_3;
    // 0x80014980: nop

    after_3:
    // 0x80014984: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014988: addiu       $a0, $a0, -0x7B74
    ctx->r4 = ADD32(ctx->r4, -0X7B74);
    // 0x8001498C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80014990: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014994: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80014998: sw          $t8, -0x7B70($at)
    MEM_W(-0X7B70, ctx->r1) = ctx->r24;
    // 0x8001499C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800149A0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800149A4: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x800149A8: sw          $t0, -0x70EC($at)
    MEM_W(-0X70EC, ctx->r1) = ctx->r8;
L_800149AC:
    // 0x800149AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800149B0:
    // 0x800149B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800149B4: jr          $ra
    // 0x800149B8: nop

    return;
    // 0x800149B8: nop

;}
RECOMP_FUNC void func_808000F0_chfactorytoxiccloud(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000F8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808000FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800100: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800104: lw          $v0, 0x70($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X70);
    // 0x80800108: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8080010C: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x80800110: srl         $t7, $a2, 26
    ctx->r15 = S32(U32(ctx->r6) >> 26);
    // 0x80800114: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x80800118: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8080011C: jal         0x800CC338
    // 0x80800120: addiu       $a2, $t7, -0x1
    ctx->r6 = ADD32(ctx->r15, -0X1);
    func_800CC338(rdram, ctx);
        goto after_0;
    // 0x80800120: addiu       $a2, $t7, -0x1
    ctx->r6 = ADD32(ctx->r15, -0X1);
    after_0:
    // 0x80800124: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800128: bne         $v0, $at, L_80800138
    if (ctx->r2 != ctx->r1) {
        // 0x8080012C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800138;
    }
    // 0x8080012C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800130: b           L_808001A8
    // 0x80800134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001A8;
    // 0x80800134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800138:
    // 0x80800138: jal         0x80800BF8
    // 0x8080013C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80800BF8_chfactorytoxiccloud(rdram, ctx);
        goto after_1;
    // 0x8080013C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800140: bne         $v0, $zero, L_80800150
    if (ctx->r2 != 0) {
        // 0x80800144: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_80800150;
    }
    // 0x80800144: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800148: b           L_808001A8
    // 0x8080014C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001A8;
    // 0x8080014C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800150:
    // 0x80800150: lhu         $v0, 0x72($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X72);
    // 0x80800154: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800158: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x8080015C: bne         $t9, $at, L_8080016C
    if (ctx->r25 != ctx->r1) {
        // 0x80800160: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8080016C;
    }
    // 0x80800160: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80800164: b           L_808001A8
    // 0x80800168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001A8;
    // 0x80800168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080016C:
    // 0x8080016C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800170: bne         $v0, $at, L_80800180
    if (ctx->r2 != ctx->r1) {
        // 0x80800174: nop
    
            goto L_80800180;
    }
    // 0x80800174: nop

    // 0x80800178: b           L_808001A8
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001A8;
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800180:
    // 0x80800180: jal         0x800F54E4
    // 0x80800184: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800184: nop

    after_2:
    // 0x80800188: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080018C: jal         0x800F64A4
    // 0x80800190: addiu       $a1, $zero, 0x1601
    ctx->r5 = ADD32(0, 0X1601);
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x80800190: addiu       $a1, $zero, 0x1601
    ctx->r5 = ADD32(0, 0X1601);
    after_3:
    // 0x80800194: bnel        $v0, $zero, L_808001A8
    if (ctx->r2 != 0) {
        // 0x80800198: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808001A8;
    }
    goto skip_0;
    // 0x80800198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080019C: b           L_808001A8
    // 0x808001A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001A8;
    // 0x808001A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001A8:
    // 0x808001A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B0: jr          $ra
    // 0x808001B4: nop

    return;
    // 0x808001B4: nop

;}
RECOMP_FUNC void func_8080227C_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080227C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802284: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x80802288: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080228C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802290: beql        $t6, $zero, L_808022AC
    if (ctx->r14 == 0) {
        // 0x80802294: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808022AC;
    }
    goto skip_0;
    // 0x80802294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802298: jal         0x800856B8
    // 0x8080229C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080229C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808022A0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808022A4: sw          $zero, 0x34($a1)
    MEM_W(0X34, ctx->r5) = 0;
    // 0x808022A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808022AC:
    // 0x808022AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808022B0: jr          $ra
    // 0x808022B4: nop

    return;
    // 0x808022B4: nop

;}
RECOMP_FUNC void func_800F9AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9AFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F9B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9B04: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800F9B08: jal         0x800F93C4
    // 0x800F9B0C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F93C4(rdram, ctx);
        goto after_0;
    // 0x800F9B0C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800F9B10: jal         0x800F929C
    // 0x800F9B14: nop

    func_800F929C(rdram, ctx);
        goto after_1;
    // 0x800F9B14: nop

    after_1:
    // 0x800F9B18: jal         0x800878A0
    // 0x800F9B1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _plsu_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x800F9B1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800F9B20: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800F9B24: jal         0x800F8128
    // 0x800F9B28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F8128(rdram, ctx);
        goto after_3;
    // 0x800F9B28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800F9B2C: jal         0x800F8EBC
    // 0x800F9B30: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F8EBC(rdram, ctx);
        goto after_4;
    // 0x800F9B30: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x800F9B34: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F9B38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800F9B3C: jal         0x800F8268
    // 0x800F9B40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F8268(rdram, ctx);
        goto after_5;
    // 0x800F9B40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800F9B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F9B48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F9B4C: jr          $ra
    // 0x800F9B50: nop

    return;
    // 0x800F9B50: nop

;}
RECOMP_FUNC void func_80800300_chboggykidshome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800300: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800308: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080030C: jal         0x801022E4
    // 0x80800310: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x80800310: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800314: addiu       $at, $zero, 0x246
    ctx->r1 = ADD32(0, 0X246);
    // 0x80800318: bne         $v0, $at, L_808003AC
    if (ctx->r2 != ctx->r1) {
        // 0x8080031C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003AC;
    }
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800320: jal         0x80101E14
    // 0x80800324: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x80800324: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800328: beq         $v0, $zero, L_80800360
    if (ctx->r2 == 0) {
        // 0x8080032C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800360;
    }
    // 0x8080032C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800330: jal         0x800DC128
    // 0x80800334: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80800334: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80800338: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8080033C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1396, 0X5A0) << 16);
    // 0x80800340: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80800344: jal         0x800C4B7C
    // 0x80800348: lh          $a0, 0x5A0($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1396, 0X5A0));
    func_800C4B7C(rdram, ctx);
        goto after_3;
    // 0x80800348: lh          $a0, 0x5A0($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1396, 0X5A0));
    after_3:
    // 0x8080034C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1396, 0X5BC) << 16);
    // 0x80800350: addiu       $a2, $a2, 0x5BC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1396, 0X5BC));
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: jal         0x80089D18
    // 0x8080035C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x8080035C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
L_80800360:
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x80101E14
    // 0x80800368: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_5;
    // 0x80800368: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_5:
    // 0x8080036C: beq         $v0, $zero, L_80800384
    if (ctx->r2 == 0) {
        // 0x80800370: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800384;
    }
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1396, 0X5CC) << 16);
    // 0x80800378: addiu       $a2, $a2, 0x5CC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1396, 0X5CC));
    // 0x8080037C: jal         0x80089D18
    // 0x80800380: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800380: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_6:
L_80800384:
    // 0x80800384: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1396, 0X5AC) << 16);
    // 0x80800388: addiu       $a1, $a1, 0x5AC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1396, 0X5AC));
    // 0x8080038C: jal         0x80101E4C
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_7;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800394: beq         $v0, $zero, L_808003AC
    if (ctx->r2 == 0) {
        // 0x80800398: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003AC;
    }
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1396, 0X5E8) << 16);
    // 0x808003A0: addiu       $a2, $a2, 0x5E8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1396, 0X5E8));
    // 0x808003A4: jal         0x80089D18
    // 0x808003A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x808003A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
L_808003AC:
    // 0x808003AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003B8: jr          $ra
    // 0x808003BC: nop

    return;
    // 0x808003BC: nop

;}
RECOMP_FUNC void func_8010BDB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010BDB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8010BDB4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8010BDB8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8010BDBC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8010BDC0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8010BDC4: addiu       $s5, $a0, 0x4
    ctx->r21 = ADD32(ctx->r4, 0X4);
    // 0x8010BDC8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8010BDCC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8010BDD0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8010BDD4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8010BDD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010BDDC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8010BDE0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8010BDE4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8010BDE8: jal         0x800BE3F8
    // 0x8010BDEC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800BE3F8(rdram, ctx);
        goto after_0;
    // 0x8010BDEC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x8010BDF0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8010BDF4: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8010BDF8: beq         $t6, $zero, L_8010BF20
    if (ctx->r14 == 0) {
        // 0x8010BDFC: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_8010BF20;
    }
    // 0x8010BDFC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_8010BE00:
    // 0x8010BE00: jal         0x800E9E88
    // 0x8010BE04: nop

    func_800E9E88(rdram, ctx);
        goto after_1;
    // 0x8010BE04: nop

    after_1:
    // 0x8010BE08: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010BE0C: jal         0x800E9EB4
    // 0x8010BE10: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_2;
    // 0x8010BE10: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_2:
    // 0x8010BE14: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8010BE18: beq         $at, $zero, L_8010BF10
    if (ctx->r1 == 0) {
        // 0x8010BE1C: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_8010BF10;
    }
    // 0x8010BE1C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8010BE20: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
L_8010BE24:
    // 0x8010BE24: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8010BE28: beql        $t8, $zero, L_8010BF04
    if (ctx->r24 == 0) {
        // 0x8010BE2C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8010BF04;
    }
    goto skip_0;
    // 0x8010BE2C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x8010BE30: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8010BE34: lhu         $t9, 0x18($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X18);
    // 0x8010BE38: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8010BE3C: beql        $t0, $zero, L_8010BF04
    if (ctx->r8 == 0) {
        // 0x8010BE40: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8010BF04;
    }
    goto skip_1;
    // 0x8010BE40: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_1:
    // 0x8010BE44: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x8010BE48: beql        $s1, $t1, L_8010BF04
    if (ctx->r17 == ctx->r9) {
        // 0x8010BE4C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8010BF04;
    }
    goto skip_2;
    // 0x8010BE4C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_2:
    // 0x8010BE50: jal         0x80106790
    // 0x8010BE54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x8010BE54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8010BE58: lhu         $t2, 0x70($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X70);
    // 0x8010BE5C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8010BE60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8010BE64: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8010BE68: beq         $t3, $zero, L_8010BF00
    if (ctx->r11 == 0) {
        // 0x8010BE6C: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_8010BF00;
    }
    // 0x8010BE6C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8010BE70: jal         0x8010BCC8
    // 0x8010BE74: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_8010BCC8(rdram, ctx);
        goto after_4;
    // 0x8010BE74: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x8010BE78: beql        $v0, $zero, L_8010BF04
    if (ctx->r2 == 0) {
        // 0x8010BE7C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8010BF04;
    }
    goto skip_3;
    // 0x8010BE7C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_3:
    // 0x8010BE80: lbu         $t4, 0x74($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X74);
    // 0x8010BE84: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8010BE88: beql        $t5, $zero, L_8010BEC0
    if (ctx->r13 == 0) {
        // 0x8010BE8C: lbu         $t8, 0x74($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0X74);
            goto L_8010BEC0;
    }
    goto skip_4;
    // 0x8010BE8C: lbu         $t8, 0x74($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X74);
    skip_4:
    // 0x8010BE90: lbu         $t6, 0x74($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X74);
    // 0x8010BE94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8010BE98: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8010BE9C: bnel        $t7, $zero, L_8010BEC0
    if (ctx->r15 != 0) {
        // 0x8010BEA0: lbu         $t8, 0x74($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0X74);
            goto L_8010BEC0;
    }
    goto skip_5;
    // 0x8010BEA0: lbu         $t8, 0x74($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X74);
    skip_5:
    // 0x8010BEA4: jal         0x80102F74
    // 0x8010BEA8: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    func_80102F74(rdram, ctx);
        goto after_5;
    // 0x8010BEA8: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    after_5:
    // 0x8010BEAC: beq         $v0, $zero, L_8010BEBC
    if (ctx->r2 == 0) {
        // 0x8010BEB0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8010BEBC;
    }
    // 0x8010BEB0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8010BEB4: jal         0x800860D0
    // 0x8010BEB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _chflamer_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x8010BEB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
L_8010BEBC:
    // 0x8010BEBC: lbu         $t8, 0x74($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X74);
L_8010BEC0:
    // 0x8010BEC0: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8010BEC4: bne         $t9, $zero, L_8010BEF8
    if (ctx->r25 != 0) {
        // 0x8010BEC8: nop
    
            goto L_8010BEF8;
    }
    // 0x8010BEC8: nop

    // 0x8010BECC: lbu         $t0, 0x74($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X74);
    // 0x8010BED0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010BED4: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8010BED8: beq         $t1, $zero, L_8010BEF8
    if (ctx->r9 == 0) {
        // 0x8010BEDC: nop
    
            goto L_8010BEF8;
    }
    // 0x8010BEDC: nop

    // 0x8010BEE0: jal         0x80102F74
    // 0x8010BEE4: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    func_80102F74(rdram, ctx);
        goto after_7;
    // 0x8010BEE4: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    after_7:
    // 0x8010BEE8: beq         $v0, $zero, L_8010BEF8
    if (ctx->r2 == 0) {
        // 0x8010BEEC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8010BEF8;
    }
    // 0x8010BEEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010BEF0: jal         0x800860D0
    // 0x8010BEF4: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    _chflamer_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x8010BEF4: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    after_8:
L_8010BEF8:
    // 0x8010BEF8: b           L_8010BF24
    // 0x8010BEFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010BF24;
    // 0x8010BEFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010BF00:
    // 0x8010BF00: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_8010BF04:
    // 0x8010BF04: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x8010BF08: bnel        $at, $zero, L_8010BE24
    if (ctx->r1 != 0) {
        // 0x8010BF0C: lw          $t7, 0x8($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X8);
            goto L_8010BE24;
    }
    goto skip_6;
    // 0x8010BF0C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    skip_6:
L_8010BF10:
    // 0x8010BF10: lw          $a0, 0x4($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X4);
    // 0x8010BF14: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8010BF18: bne         $a0, $zero, L_8010BE00
    if (ctx->r4 != 0) {
        // 0x8010BF1C: nop
    
            goto L_8010BE00;
    }
    // 0x8010BF1C: nop

L_8010BF20:
    // 0x8010BF20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010BF24:
    // 0x8010BF24: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8010BF28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010BF2C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8010BF30: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8010BF34: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8010BF38: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8010BF3C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8010BF40: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8010BF44: jr          $ra
    // 0x8010BF48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8010BF48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808005B8_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005C0: jal         0x800A587C
    // 0x808005C4: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x808005C4: nop

    after_0:
    // 0x808005C8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808005CC: beq         $v0, $at, L_808005EC
    if (ctx->r2 == ctx->r1) {
        // 0x808005D0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_808005EC;
    }
    // 0x808005D0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808005D4: beq         $v0, $at, L_808005FC
    if (ctx->r2 == ctx->r1) {
        // 0x808005D8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_808005FC;
    }
    // 0x808005D8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808005DC: beq         $v0, $at, L_8080060C
    if (ctx->r2 == ctx->r1) {
        // 0x808005E0: nop
    
            goto L_8080060C;
    }
    // 0x808005E0: nop

    // 0x808005E4: b           L_8080061C
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080061C;
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005EC:
    // 0x808005EC: jal         0x800A586C
    // 0x808005F0: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x808005F0: nop

    after_1:
    // 0x808005F4: b           L_8080061C
    // 0x808005F8: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
        goto L_8080061C;
    // 0x808005F8: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
L_808005FC:
    // 0x808005FC: jal         0x800A586C
    // 0x80800600: nop

    func_800A586C(rdram, ctx);
        goto after_2;
    // 0x80800600: nop

    after_2:
    // 0x80800604: b           L_8080061C
    // 0x80800608: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
        goto L_8080061C;
    // 0x80800608: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_8080060C:
    // 0x8080060C: jal         0x800A586C
    // 0x80800610: nop

    func_800A586C(rdram, ctx);
        goto after_3;
    // 0x80800610: nop

    after_3:
    // 0x80800614: b           L_8080061C
    // 0x80800618: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
        goto L_8080061C;
    // 0x80800618: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
L_8080061C:
    // 0x8080061C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800620: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800624: jr          $ra
    // 0x80800628: nop

    return;
    // 0x80800628: nop

;}
RECOMP_FUNC void subaddierouteDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800528: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080052C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800530: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800534: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800538: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8080053C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800540: jal         0x8001BCF8
    // 0x80800544: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    rare_memset(rdram, ctx);
        goto after_0;
    // 0x80800544: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x80800548: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080054C: jal         0x80800564
    // 0x80800550: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80800564_subaddierouteDll(rdram, ctx);
        goto after_1;
    // 0x80800550: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080055C: jr          $ra
    // 0x80800560: nop

    return;
    // 0x80800560: nop

;}
RECOMP_FUNC void func_80800368_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080036C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800370: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800374: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800378: jal         0x80100094
    // 0x8080037C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080037C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800380: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800384: jal         0x800DF744
    // 0x80800388: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800388: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x8080038C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800390: jal         0x80101870
    // 0x80800394: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_2;
    // 0x80800394: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080039C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
RECOMP_FUNC void chfactorytoxicpools_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1156, 0X940) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x940
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1156, 0X940));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x940
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1156, 0X940));
;}
RECOMP_FUNC void chfiregen_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BFC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X17BC) << 16);
    // 0x80800C00: jr          $ra
    // 0x80800C04: addiu       $v0, $v0, 0x17BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X17BC));
    return;
    // 0x80800C04: addiu       $v0, $v0, 0x17BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X17BC));
;}
RECOMP_FUNC void func_800C67D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C67D0: jr          $ra
    // 0x800C67D4: lbu         $v0, 0x9C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9C);
    return;
    // 0x800C67D4: lbu         $v0, 0x9C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9C);
;}
RECOMP_FUNC void gccubeDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808008F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808008F8: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x808008FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800900: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800904: blez        $t6, L_80800938
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800908: nop
    
            goto L_80800938;
    }
    // 0x80800908: nop

    // 0x8080090C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
L_80800910:
    // 0x80800910: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    // 0x80800914: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800918: jal         0x80088B90
    // 0x8080091C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    _gspropsDll_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080091C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80800920: lw          $t9, 0x24($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X24);
    // 0x80800924: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800928: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8080092C: bnel        $at, $zero, L_80800910
    if (ctx->r1 != 0) {
        // 0x80800930: lw          $t7, 0x0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X0);
            goto L_80800910;
    }
    goto skip_0;
    // 0x80800930: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x80800934: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800938:
    // 0x80800938: jal         0x800CBA20
    // 0x8080093C: nop

    func_800CBA20(rdram, ctx);
        goto after_1;
    // 0x8080093C: nop

    after_1:
    // 0x80800940: lw          $t0, 0x24($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X24);
    // 0x80800944: blez        $t0, L_80800974
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80800948: nop
    
            goto L_80800974;
    }
    // 0x80800948: nop

    // 0x8080094C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
L_80800950:
    // 0x80800950: sll         $t2, $s0, 3
    ctx->r10 = S32(ctx->r16 << 3);
    // 0x80800954: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800958: jal         0x80088B90
    // 0x8080095C: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    _gspropsDll_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080095C: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_2:
    // 0x80800960: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x80800964: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800968: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8080096C: bnel        $at, $zero, L_80800950
    if (ctx->r1 != 0) {
        // 0x80800970: lw          $t1, 0x0($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X0);
            goto L_80800950;
    }
    goto skip_1;
    // 0x80800970: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    skip_1:
L_80800974:
    // 0x80800974: jal         0x800CB9FC
    // 0x80800978: nop

    func_800CB9FC(rdram, ctx);
        goto after_3;
    // 0x80800978: nop

    after_3:
    // 0x8080097C: jal         0x800CBA44
    // 0x80800980: nop

    func_800CBA44(rdram, ctx);
        goto after_4;
    // 0x80800980: nop

    after_4:
    // 0x80800984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800988: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080098C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800990: jr          $ra
    // 0x80800994: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800994: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _gcmapsects_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F48: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F48);
    return;
    // 0x80087F4C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80110FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110FCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80110FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110FD4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80110FD8: jal         0x8001BAFC
    // 0x80110FDC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    defrag(rdram, ctx);
        goto after_0;
    // 0x80110FDC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80110FE0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80110FE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80110FE8: beql        $t6, $v0, L_80111000
    if (ctx->r14 == ctx->r2) {
        // 0x80110FEC: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80111000;
    }
    goto skip_0;
    // 0x80110FEC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80110FF0: jal         0x80110280
    // 0x80110FF4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80110280(rdram, ctx);
        goto after_1;
    // 0x80110FF4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80110FF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80110FFC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80111000:
    // 0x80111000: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80111004: sw          $t7, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r15;
    // 0x80111008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011100C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80111010: jr          $ra
    // 0x80111014: nop

    return;
    // 0x80111014: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800624: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800628: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(128, 0XF98) << 16);
    // 0x8080062C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800630: jr          $ra
    // 0x80800634: lw          $v0, 0xF98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(128, 0XF98));
    return;
    // 0x80800634: lw          $v0, 0xF98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(128, 0XF98));
;}
RECOMP_FUNC void ncbaledge_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800098: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080009C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A4: jal         0x80800020
    // 0x808000A8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_80800020_ncbaledge(rdram, ctx);
        goto after_0;
    // 0x808000A8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_0:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: jal         0x801107F0
    // 0x808000B4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x808000B4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x808000B8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808000BC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808000C0: jal         0x800EFB24
    // 0x808000C4: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x808000C4: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_2:
    // 0x808000C8: jal         0x800EEF94
    // 0x808000CC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_800EEF94(rdram, ctx);
        goto after_3;
    // 0x808000CC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_3:
    // 0x808000D0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808000D4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808000D8: jal         0x800F1A88
    // 0x808000DC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F1A88(rdram, ctx);
        goto after_4;
    // 0x808000DC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x80115358
    // 0x808000E8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80115358(rdram, ctx);
        goto after_5;
    // 0x808000E8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x808000EC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: jal         0x80115750
    // 0x808000F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80115750(rdram, ctx);
        goto after_6;
    // 0x808000F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x808000FC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800104: jal         0x80112C3C
    // 0x80800108: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80112C3C(rdram, ctx);
        goto after_7;
    // 0x80800108: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x8080010C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800110: jal         0x801112B0
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801112B0(rdram, ctx);
        goto after_8;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800118: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080011C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800120: jal         0x800F1DCC
    // 0x80800124: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_9;
    // 0x80800124: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_9:
    // 0x80800128: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8080012C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800138: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8080013C: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80800140: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800144: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800148: jal         0x80112D08
    // 0x8080014C: nop

    func_80112D08(rdram, ctx);
        goto after_10;
    // 0x8080014C: nop

    after_10:
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: jal         0x80112C3C
    // 0x80800158: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80112C3C(rdram, ctx);
        goto after_11;
    // 0x80800158: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x8080015C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800160: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800164: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800168: jal         0x800EEBF0
    // 0x8080016C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_800EEBF0(rdram, ctx);
        goto after_12;
    // 0x8080016C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_12:
    // 0x80800170: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800174: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80800178: jal         0x800EE780
    // 0x8080017C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_800EE780(rdram, ctx);
        goto after_13;
    // 0x8080017C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_13:
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x80111CC8
    // 0x80800188: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80111CC8(rdram, ctx);
        goto after_14;
    // 0x80800188: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_14:
    // 0x8080018C: beql        $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x80800190: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001D0;
    }
    goto skip_0;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800194: jal         0x801138A0
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138A0(rdram, ctx);
        goto after_15;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080019C: bne         $v0, $zero, L_808001B4
    if (ctx->r2 != 0) {
        // 0x808001A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B4;
    }
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x80115580
    // 0x808001A8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_80115580(rdram, ctx);
        goto after_16;
    // 0x808001A8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_16:
    // 0x808001AC: beql        $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x808001B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001D0;
    }
    goto skip_1;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_808001B4:
    // 0x808001B4: jal         0x801138F4
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_17;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808001BC: beql        $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x808001C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001D0;
    }
    goto skip_2;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808001C4: jal         0x80110F44
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110F44(rdram, ctx);
        goto after_18;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001D0:
    // 0x808001D0: jal         0x80800000
    // 0x808001D4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_80800000_ncbaledge(rdram, ctx);
        goto after_19;
    // 0x808001D4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_19:
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808001E0: jal         0x80110A68
    // 0x808001E4: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_80110A68(rdram, ctx);
        goto after_20;
    // 0x808001E4: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_20:
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: jal         0x80110790
    // 0x808001F0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80110790(rdram, ctx);
        goto after_21;
    // 0x808001F0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_21:
    // 0x808001F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001FC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80800200: jr          $ra
    // 0x80800204: nop

    return;
    // 0x80800204: nop

    // 0x80800208: nop

    // 0x8080020C: nop

;}
RECOMP_FUNC void func_80800000_chlavatraindoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800010: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1864, 0XE0) << 16);
    // 0x80800014: lwc1        $f6, 0xE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1864, 0XE0));
    // 0x80800018: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080001C: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80800020: addiu       $t7, $zero, 0x1D0
    ctx->r15 = ADD32(0, 0X1D0);
    // 0x80800024: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800028: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8080002C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800030: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800034: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800038: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8080003C: jal         0x80086898
    // 0x80800040: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800040: nop

    after_0:
    // 0x80800044: beq         $v0, $zero, L_808000BC
    if (ctx->r2 == 0) {
        // 0x80800048: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000BC;
    }
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800050: jal         0x800868E0
    // 0x80800054: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    _chdoormake_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80800054: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    after_1:
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: jal         0x800868C0
    // 0x80800060: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800060: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80800064: lhu         $t8, 0x76($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X76);
    // 0x80800068: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8080006C: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x80800070: bne         $t9, $at, L_80800080
    if (ctx->r25 != ctx->r1) {
        // 0x80800074: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1864, 0XE4) << 16);
            goto L_80800080;
    }
    // 0x80800074: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1864, 0XE4) << 16);
    // 0x80800078: b           L_8080008C
    // 0x8080007C: lwc1        $f0, 0xE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1864, 0XE4));
        goto L_8080008C;
    // 0x8080007C: lwc1        $f0, 0xE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1864, 0XE4));
L_80800080:
    // 0x80800080: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80800084: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800088: nop

L_8080008C:
    // 0x8080008C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800090: jal         0x800868B0
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800098: lhu         $t0, 0x76($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X76);
    // 0x8080009C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x808000A8: bne         $t1, $at, L_808000BC
    if (ctx->r9 != ctx->r1) {
        // 0x808000AC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808000BC;
    }
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x808000B4: jal         0x800868C8
    // 0x808000B8: addiu       $a3, $zero, 0x910
    ctx->r7 = ADD32(0, 0X910);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x808000B8: addiu       $a3, $zero, 0x910
    ctx->r7 = ADD32(0, 0X910);
    after_4:
L_808000BC:
    // 0x808000BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void func_80801358_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801358: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080135C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801360: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801364: jal         0x80800AEC
    // 0x80801368: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_80800AEC_bssub(rdram, ctx);
        goto after_0;
    // 0x80801368: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x8080136C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801370: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x80801374: jal         0x800914FC
    // 0x80801378: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800914FC(rdram, ctx);
        goto after_1;
    // 0x80801378: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8080137C: jal         0x80085158
    // 0x80801380: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _baspin_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801380: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80801384: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801388: bne         $v0, $at, L_80801394
    if (ctx->r2 != ctx->r1) {
        // 0x8080138C: addiu       $t6, $zero, 0x131
        ctx->r14 = ADD32(0, 0X131);
            goto L_80801394;
    }
    // 0x8080138C: addiu       $t6, $zero, 0x131
    ctx->r14 = ADD32(0, 0X131);
    // 0x80801390: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80801394:
    // 0x80801394: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801398: jal         0x8009E5C8
    // 0x8080139C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x8080139C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808013A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808013A8: jr          $ra
    // 0x808013AC: nop

    return;
    // 0x808013AC: nop

;}
RECOMP_FUNC void baeggcursor_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808003A8: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x808003AC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x808003B0: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    // 0x808003B4: lw          $t7, 0x68($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X68);
    // 0x808003B8: jr          $ra
    // 0x808003BC: swc1        $f14, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f14.u32l;
    return;
    // 0x808003BC: swc1        $f14, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80020B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020B90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020B98: jal         0x80020AD0
    // 0x80020B9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80020AD0(rdram, ctx);
        goto after_0;
    // 0x80020B9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80020BA0: b           L_80020BA8
    // 0x80020BA4: nop

        goto L_80020BA8;
    // 0x80020BA4: nop

L_80020BA8:
    // 0x80020BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020BAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020BB0: jr          $ra
    // 0x80020BB4: nop

    return;
    // 0x80020BB4: nop

;}
RECOMP_FUNC void _bswalk_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084200: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084200);
    return;
    // 0x80084204: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chnicecavemen_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1096, 0X1AA4) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1AA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1096, 0X1AA4));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1AA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1096, 0X1AA4));
;}
RECOMP_FUNC void func_80800AD8_subaddiestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800AE4: jal         0x80800260
    // 0x80800AE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800260_subaddiestore(rdram, ctx);
        goto after_0;
    // 0x80800AE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800AEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800AF0: beq         $v0, $at, L_80800B00
    if (ctx->r2 == ctx->r1) {
        // 0x80800AF4: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B00;
    }
    // 0x80800AF4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AF8: b           L_80800B14
    // 0x80800AFC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80800B14;
    // 0x80800AFC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80800B00:
    // 0x80800B00: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800B04: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x80800B08: lw          $t7, 0x6C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X6C);
    // 0x80800B0C: srl         $t8, $t7, 21
    ctx->r24 = S32(U32(ctx->r15) >> 21);
    // 0x80800B10: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
L_80800B14:
    // 0x80800B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B1C: jr          $ra
    // 0x80800B20: nop

    return;
    // 0x80800B20: nop

;}
RECOMP_FUNC void func_8008E454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E454: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008E458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E45C: jal         0x800DB9B0
    // 0x8008E460: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x8008E460: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008E464: beql        $v0, $zero, L_8008E49C
    if (ctx->r2 == 0) {
        // 0x8008E468: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8008E49C;
    }
    goto skip_0;
    // 0x8008E468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8008E46C: jal         0x800BFAA4
    // 0x8008E470: nop

    func_800BFAA4(rdram, ctx);
        goto after_1;
    // 0x8008E470: nop

    after_1:
    // 0x8008E474: beq         $v0, $zero, L_8008E498
    if (ctx->r2 == 0) {
        // 0x8008E478: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8008E498;
    }
    // 0x8008E478: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008E47C: jal         0x8009C128
    // 0x8008E480: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_2;
    // 0x8008E480: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x8008E484: jal         0x80087F20
    // 0x8008E488: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    _gcmapsects_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x8008E488: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x8008E48C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8008E490: b           L_8008E49C
    // 0x8008E494: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
        goto L_8008E49C;
    // 0x8008E494: sltu        $v0, $zero, $t6
    ctx->r2 = 0 < ctx->r14 ? 1 : 0;
L_8008E498:
    // 0x8008E498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008E49C:
    // 0x8008E49C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E4A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008E4A4: jr          $ra
    // 0x8008E4A8: nop

    return;
    // 0x8008E4A8: nop

    // 0x8008E4AC: nop

;}
RECOMP_FUNC void _bamovespline_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E90: syscall     140
    recomp_syscall_handler(rdram, ctx, 0x80084E90);
    return;
    // 0x80084E94: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080000C_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080001C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800020: jal         0x80088278
    // 0x80800024: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800024: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80800028: beq         $v0, $zero, L_80800040
    if (ctx->r2 == 0) {
        // 0x8080002C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800040;
    }
    // 0x8080002C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800030: jal         0x80088C00
    // 0x80800034: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800034: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_1:
    // 0x80800038: b           L_8080005C
    // 0x8080003C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
        goto L_8080005C;
    // 0x8080003C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_80800040:
    // 0x80800040: lui         $a1, 0x44CE
    ctx->r5 = S32(0X44CE << 16);
    // 0x80800044: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x80800048: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080004C: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80800050: jal         0x800EFA4C
    // 0x80800054: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80800054: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_2:
    // 0x80800058: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8080005C:
    // 0x8080005C: jal         0x80088278
    // 0x80800060: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800060: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800064: beq         $v0, $zero, L_8080007C
    if (ctx->r2 == 0) {
        // 0x80800068: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080007C;
    }
    // 0x80800068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080006C: jal         0x80088C00
    // 0x80800070: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800070: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_4:
    // 0x80800074: b           L_80800098
    // 0x80800078: nop

        goto L_80800098;
    // 0x80800078: nop

L_8080007C:
    // 0x8080007C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800080: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800084: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x80800088: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080008C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800090: jal         0x800EFA4C
    // 0x80800094: nop

    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x80800094: nop

    after_5:
L_80800098:
    // 0x80800098: jal         0x80088848
    // 0x8080009C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_6;
    // 0x8080009C: nop

    after_6:
    // 0x808000A0: bnel        $v0, $zero, L_808000B8
    if (ctx->r2 != 0) {
        // 0x808000A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000B8;
    }
    goto skip_0;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808000A8: jal         0x800A9C98
    // 0x808000AC: nop

    func_800A9C98(rdram, ctx);
        goto after_7;
    // 0x808000AC: nop

    after_7:
    // 0x808000B0: beq         $v0, $zero, L_808000C8
    if (ctx->r2 == 0) {
        // 0x808000B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000C8;
    }
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000B8:
    // 0x808000B8: jal         0x80800220
    // 0x808000BC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_8;
    // 0x808000BC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_8:
    // 0x808000C0: b           L_8080018C
    // 0x808000C4: nop

        goto L_8080018C;
    // 0x808000C4: nop

L_808000C8:
    // 0x808000C8: jal         0x8008A700
    // 0x808000CC: nop

    _sujiggy_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x808000CC: nop

    after_9:
    // 0x808000D0: beq         $v0, $zero, L_80800154
    if (ctx->r2 == 0) {
        // 0x808000D4: nop
    
            goto L_80800154;
    }
    // 0x808000D4: nop

    // 0x808000D8: jal         0x8008A708
    // 0x808000DC: nop

    _sujiggy_entrypoint_14(rdram, ctx);
        goto after_10;
    // 0x808000DC: nop

    after_10:
    // 0x808000E0: beq         $v0, $zero, L_80800114
    if (ctx->r2 == 0) {
        // 0x808000E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800114;
    }
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000EC: beq         $v0, $at, L_80800124
    if (ctx->r2 == ctx->r1) {
        // 0x808000F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800124;
    }
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000F8: beq         $v0, $at, L_80800134
    if (ctx->r2 == ctx->r1) {
        // 0x808000FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800134;
    }
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800104: beq         $v0, $at, L_80800144
    if (ctx->r2 == ctx->r1) {
        // 0x80800108: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800144;
    }
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: b           L_8080018C
    // 0x80800110: nop

        goto L_8080018C;
    // 0x80800110: nop

L_80800114:
    // 0x80800114: jal         0x808001D0
    // 0x80800118: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808001D0_chmasterjiggy(rdram, ctx);
        goto after_11;
    // 0x80800118: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x8080011C: b           L_8080018C
    // 0x80800120: nop

        goto L_8080018C;
    // 0x80800120: nop

L_80800124:
    // 0x80800124: jal         0x80800220
    // 0x80800128: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_12;
    // 0x80800128: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_12:
    // 0x8080012C: b           L_8080018C
    // 0x80800130: nop

        goto L_8080018C;
    // 0x80800130: nop

L_80800134:
    // 0x80800134: jal         0x808001D0
    // 0x80800138: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808001D0_chmasterjiggy(rdram, ctx);
        goto after_13;
    // 0x80800138: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_13:
    // 0x8080013C: b           L_8080018C
    // 0x80800140: nop

        goto L_8080018C;
    // 0x80800140: nop

L_80800144:
    // 0x80800144: jal         0x80800220
    // 0x80800148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_14;
    // 0x80800148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x8080014C: b           L_8080018C
    // 0x80800150: nop

        goto L_8080018C;
    // 0x80800150: nop

L_80800154:
    // 0x80800154: jal         0x800DA298
    // 0x80800158: addiu       $a0, $zero, 0x35B
    ctx->r4 = ADD32(0, 0X35B);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x80800158: addiu       $a0, $zero, 0x35B
    ctx->r4 = ADD32(0, 0X35B);
    after_15:
    // 0x8080015C: bne         $v0, $zero, L_80800174
    if (ctx->r2 != 0) {
        // 0x80800160: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800174;
    }
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800164: jal         0x80800220
    // 0x80800168: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_16;
    // 0x80800168: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_16:
    // 0x8080016C: b           L_8080018C
    // 0x80800170: nop

        goto L_8080018C;
    // 0x80800170: nop

L_80800174:
    // 0x80800174: jal         0x8008A720
    // 0x80800178: nop

    _sujiggy_entrypoint_17(rdram, ctx);
        goto after_17;
    // 0x80800178: nop

    after_17:
    // 0x8080017C: bne         $v0, $zero, L_8080018C
    if (ctx->r2 != 0) {
        // 0x80800180: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080018C;
    }
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x80800220
    // 0x80800188: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_18;
    // 0x80800188: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_18:
L_8080018C:
    // 0x8080018C: jal         0x800FE734
    // 0x80800190: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FE734(rdram, ctx);
        goto after_19;
    // 0x80800190: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
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
RECOMP_FUNC void sumumbofx_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801074: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801078: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080107C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801080: lw          $v0, 0x60($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X60);
    // 0x80801084: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801088: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080108C: srl         $t6, $v0, 25
    ctx->r14 = S32(U32(ctx->r2) >> 25);
    // 0x80801090: beq         $t6, $at, L_808010EC
    if (ctx->r14 == ctx->r1) {
        // 0x80801094: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808010EC;
    }
    // 0x80801094: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801098: bnel        $t6, $at, L_8080112C
    if (ctx->r14 != ctx->r1) {
        // 0x8080109C: lbu         $t0, 0x61($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X61);
            goto L_8080112C;
    }
    goto skip_0;
    // 0x8080109C: lbu         $t0, 0x61($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X61);
    skip_0:
    // 0x808010A0: jal         0x808013B4
    // 0x808010A4: nop

    sumumbofx_entrypoint_26(rdram, ctx);
        goto after_0;
    // 0x808010A4: nop

    after_0:
    // 0x808010A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808010AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808010B0: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808010B4: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x808010B8: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808010BC: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    // 0x808010C0: nop

    // 0x808010C4: bc1tl       L_808010D4
    if (c1cs) {
        // 0x808010C8: lbu         $t0, 0x60($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X60);
            goto L_808010D4;
    }
    goto skip_1;
    // 0x808010C8: lbu         $t0, 0x60($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X60);
    skip_1:
    // 0x808010CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808010D0: lbu         $t0, 0x60($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X60);
L_808010D4:
    // 0x808010D4: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x808010D8: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x808010DC: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x808010E0: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x808010E4: b           L_80801128
    // 0x808010E8: sb          $t2, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r10;
        goto L_80801128;
    // 0x808010E8: sb          $t2, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r10;
L_808010EC:
    // 0x808010EC: jal         0x808013B4
    // 0x808010F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sumumbofx_entrypoint_26(rdram, ctx);
        goto after_1;
    // 0x808010F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808010F4: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808010F8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x808010FC: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80801100: nop

    // 0x80801104: bc1tl       L_80801114
    if (c1cs) {
        // 0x80801108: lbu         $t6, 0x60($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X60);
            goto L_80801114;
    }
    goto skip_2;
    // 0x80801108: lbu         $t6, 0x60($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X60);
    skip_2:
    // 0x8080110C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80801110: lbu         $t6, 0x60($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X60);
L_80801114:
    // 0x80801114: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x80801118: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8080111C: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80801120: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80801124: sb          $t8, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r24;
L_80801128:
    // 0x80801128: lbu         $t0, 0x61($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X61);
L_8080112C:
    // 0x8080112C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X14BC) << 16);
    // 0x80801130: beql        $t0, $zero, L_80801230
    if (ctx->r8 == 0) {
        // 0x80801134: sb          $zero, 0x61($s0)
        MEM_B(0X61, ctx->r16) = 0;
            goto L_80801230;
    }
    goto skip_3;
    // 0x80801134: sb          $zero, 0x61($s0)
    MEM_B(0X61, ctx->r16) = 0;
    skip_3:
    // 0x80801138: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8080113C: lwc1        $f10, 0x14BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X14BC));
    // 0x80801140: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80801144: nop

    // 0x80801148: bc1fl       L_80801230
    if (!c1cs) {
        // 0x8080114C: sb          $zero, 0x61($s0)
        MEM_B(0X61, ctx->r16) = 0;
            goto L_80801230;
    }
    goto skip_4;
    // 0x8080114C: sb          $zero, 0x61($s0)
    MEM_B(0X61, ctx->r16) = 0;
    skip_4:
    // 0x80801150: lbu         $t9, 0x62($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X62);
    // 0x80801154: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801158: bnel        $t9, $at, L_80801230
    if (ctx->r25 != ctx->r1) {
        // 0x8080115C: sb          $zero, 0x61($s0)
        MEM_B(0X61, ctx->r16) = 0;
            goto L_80801230;
    }
    goto skip_5;
    // 0x8080115C: sb          $zero, 0x61($s0)
    MEM_B(0X61, ctx->r16) = 0;
    skip_5:
    // 0x80801160: lbu         $t1, 0x63($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X63);
    // 0x80801164: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801168: beql        $t1, $zero, L_808011FC
    if (ctx->r9 == 0) {
        // 0x8080116C: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_808011FC;
    }
    goto skip_6;
    // 0x8080116C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_6:
    // 0x80801170: jal         0x800F54E4
    // 0x80801174: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80801174: nop

    after_2:
    // 0x80801178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080117C: jal         0x800F5A00
    // 0x80801180: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x80801180: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x80801184: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80801188: jal         0x800EEB40
    // 0x8080118C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EEB40(rdram, ctx);
        goto after_4;
    // 0x8080118C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x80801190: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80801194: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801198: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080119C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x808011A0: nop

    // 0x808011A4: bc1fl       L_808011BC
    if (!c1cs) {
        // 0x808011A8: lwc1        $f2, 0x38($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
            goto L_808011BC;
    }
    goto skip_7;
    // 0x808011A8: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    skip_7:
    // 0x808011AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808011B0: b           L_808011F0
    // 0x808011B4: nop

        goto L_808011F0;
    // 0x808011B4: nop

    // 0x808011B8: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
L_808011BC:
    // 0x808011BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808011C0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808011C4: nop

    // 0x808011C8: bc1fl       L_808011E0
    if (!c1cs) {
        // 0x808011CC: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_808011E0;
    }
    goto skip_8;
    // 0x808011CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_8:
    // 0x808011D0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808011D4: b           L_808011F0
    // 0x808011D8: nop

        goto L_808011F0;
    // 0x808011D8: nop

    // 0x808011DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_808011E0:
    // 0x808011E0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808011E4: jal         0x800F10B4
    // 0x808011E8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x808011E8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x808011EC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_808011F0:
    // 0x808011F0: b           L_80801200
    // 0x808011F4: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
        goto L_80801200;
    // 0x808011F4: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808011F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_808011FC:
    // 0x808011FC: nop

L_80801200:
    // 0x80801200: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X14C0) << 16);
    // 0x80801204: lwc1        $f18, 0x14C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X14C0));
    // 0x80801208: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x8080120C: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x80801210: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80801214: nop

    // 0x80801218: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8080121C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80801220: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80801224: jal         0x800FCAE0
    // 0x80801228: nop

    func_800FCAE0(rdram, ctx);
        goto after_6;
    // 0x80801228: nop

    after_6:
    // 0x8080122C: sb          $zero, 0x61($s0)
    MEM_B(0X61, ctx->r16) = 0;
L_80801230:
    // 0x80801230: jal         0x800D9078
    // 0x80801234: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_800D9078(rdram, ctx);
        goto after_7;
    // 0x80801234: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_7:
    // 0x80801238: lbu         $v1, 0x60($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X60);
    // 0x8080123C: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
    // 0x80801240: beql        $t3, $zero, L_80801268
    if (ctx->r11 == 0) {
        // 0x80801244: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801268;
    }
    goto skip_9;
    // 0x80801244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x80801248: lh          $t6, 0x5E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X5E);
    // 0x8080124C: andi        $t4, $v1, 0xFFFE
    ctx->r12 = ctx->r3 & 0XFFFE;
    // 0x80801250: sb          $t4, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r12;
    // 0x80801254: beql        $t6, $zero, L_80801268
    if (ctx->r14 == 0) {
        // 0x80801258: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801268;
    }
    goto skip_10;
    // 0x80801258: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_10:
    // 0x8080125C: jal         0x80800F8C
    // 0x80801260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F8C_sumumbofx(rdram, ctx);
        goto after_8;
    // 0x80801260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801264: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801268:
    // 0x80801268: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080126C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80801270: jr          $ra
    // 0x80801274: nop

    return;
    // 0x80801274: nop

;}
RECOMP_FUNC void func_8080003C_chspiralgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800040: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800044: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800048: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080004C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800050: beq         $a1, $at, L_8080006C
    if (ctx->r5 == ctx->r1) {
        // 0x80800054: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_8080006C;
    }
    // 0x80800054: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800058: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x8080005C: beq         $a1, $at, L_80800104
    if (ctx->r5 == ctx->r1) {
        // 0x80800060: nop
    
            goto L_80800104;
    }
    // 0x80800060: nop

    // 0x80800064: b           L_80800160
    // 0x80800068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800160;
    // 0x80800068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080006C:
    // 0x8080006C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80800070: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80800074: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800078: jal         0x800EE7F8
    // 0x8080007C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080007C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x80800080: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800084: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800088: jal         0x800EF1B8
    // 0x8080008C: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x8080008C: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_1:
    // 0x80800090: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800094: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800098: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808000A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808000A8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x808000AC: jal         0x80086670
    // 0x808000B0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000B0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x808000B4: addiu       $a0, $zero, 0x51A
    ctx->r4 = ADD32(0, 0X51A);
    // 0x808000B8: jal         0x80089C30
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808000C0: beq         $v0, $zero, L_808000D0
    if (ctx->r2 == 0) {
        // 0x808000C4: addiu       $a2, $zero, 0x1A
        ctx->r6 = ADD32(0, 0X1A);
            goto L_808000D0;
    }
    // 0x808000C4: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x808000C8: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x808000CC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_808000D0:
    // 0x808000D0: beql        $v0, $zero, L_808000E8
    if (ctx->r2 == 0) {
        // 0x808000D4: lw          $a1, 0x0($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X0);
            goto L_808000E8;
    }
    goto skip_0;
    // 0x808000D4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x808000D8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808000DC: b           L_808000EC
    // 0x808000E0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
        goto L_808000EC;
    // 0x808000E0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808000E4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
L_808000E8:
    // 0x808000E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_808000EC:
    // 0x808000EC: jal         0x80085708
    // 0x808000F0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x808000F0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x808000F4: jal         0x800DA544
    // 0x808000F8: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x808000F8: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    after_5:
    // 0x808000FC: b           L_80800160
    // 0x80800100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800160;
    // 0x80800100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800104:
    // 0x80800104: jal         0x80101080
    // 0x80800108: nop

    func_80101080(rdram, ctx);
        goto after_6;
    // 0x80800108: nop

    after_6:
    // 0x8080010C: jal         0x80106790
    // 0x80800110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_7;
    // 0x80800110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80800114: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1520, 0X1C8) << 16);
    // 0x80800118: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8080011C: addiu       $a2, $a2, 0x1C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1520, 0X1C8));
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800124: jal         0x80089D18
    // 0x80800128: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800128: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x8080012C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800130: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    // 0x80800134: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    // 0x80800138: jal         0x80086688
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_9;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: jal         0x800866C8
    // 0x80800148: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _chexploder_entrypoint_14(rdram, ctx);
        goto after_10;
    // 0x80800148: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x8080014C: b           L_80800160
    // 0x80800150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800160;
    // 0x80800150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800154: b           L_80800160
    // 0x80800158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800160;
    // 0x80800158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080015C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800160:
    // 0x80800160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800164: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800168: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080016C: jr          $ra
    // 0x80800170: nop

    return;
    // 0x80800170: nop

    // 0x80800174: nop

    // 0x80800178: nop

    // 0x8080017C: nop

;}
RECOMP_FUNC void func_800F4B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4B8C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4B90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4B94: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4B9C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4BA0: jal         0x800F3930
    // 0x800F4BA4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F3930(rdram, ctx);
        goto after_0;
    // 0x800F4BA4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4BAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4BB0: jr          $ra
    // 0x800F4BB4: nop

    return;
    // 0x800F4BB4: nop

;}
RECOMP_FUNC void func_80099840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80099844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80099848: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009984C: jal         0x800A1718
    // 0x80099850: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A1718(rdram, ctx);
        goto after_0;
    // 0x80099850: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80099854: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80099858: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8009985C: sltiu       $a0, $v1, 0x1
    ctx->r4 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80099860: beq         $a0, $zero, L_8009986C
    if (ctx->r4 == 0) {
        // 0x80099864: nop
    
            goto L_8009986C;
    }
    // 0x80099864: nop

    // 0x80099868: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
L_8009986C:
    // 0x8009986C: beq         $a0, $zero, L_80099884
    if (ctx->r4 == 0) {
        // 0x80099870: nop
    
            goto L_80099884;
    }
    // 0x80099870: nop

    // 0x80099874: jal         0x80084710
    // 0x80099878: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _badata_entrypoint_26(rdram, ctx);
        goto after_1;
    // 0x80099878: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8009987C: b           L_80099890
    // 0x80099880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80099890;
    // 0x80099880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80099884:
    // 0x80099884: jal         0x800846E0
    // 0x80099888: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _badata_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80099888: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x8009988C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80099890:
    // 0x80099890: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80099894: jr          $ra
    // 0x80099898: nop

    return;
    // 0x80099898: nop

;}
RECOMP_FUNC void func_800DC580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC580: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DC584: addiu       $v0, $v0, -0x36B8
    ctx->r2 = ADD32(ctx->r2, -0X36B8);
    // 0x800DC588: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DC58C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800DC590: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800DC594: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800DC598: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DC59C: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800DC5A0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800DC5A4: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x800DC5A8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DC5AC: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800DC5B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800DC5B4: jr          $ra
    // 0x800DC5B8: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800DC5B8: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_800A0FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0FF0: lw          $t7, 0x150($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X150);
    // 0x800A0FF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A0FF8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800A0FFC: sb          $t6, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r14;
    // 0x800A1000: lw          $t8, 0x150($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X150);
    // 0x800A1004: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A1008: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800A100C: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x800A1010: lw          $t9, 0x150($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X150);
    // 0x800A1014: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A1018: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800A101C: sb          $zero, 0x1($t9)
    MEM_B(0X1, ctx->r25) = 0;
    // 0x800A1020: lw          $t0, 0x150($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X150);
    // 0x800A1024: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A1028: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x800A102C: lw          $t1, 0x150($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X150);
    // 0x800A1030: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
    // 0x800A1034: lw          $t2, 0x150($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X150);
    // 0x800A1038: jr          $ra
    // 0x800A103C: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    return;
    // 0x800A103C: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
;}
RECOMP_FUNC void chswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(696, 0XDB0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xDB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(696, 0XDB0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xDB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(696, 0XDB0));
;}
RECOMP_FUNC void strlen_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032AB0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80032AB4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80032AB8: beq         $t6, $zero, L_80032AD0
    if (ctx->r14 == 0) {
        // 0x80032ABC: nop
    
            goto L_80032AD0;
    }
    // 0x80032ABC: nop

    // 0x80032AC0: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
L_80032AC4:
    // 0x80032AC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80032AC8: bnel        $t7, $zero, L_80032AC4
    if (ctx->r15 != 0) {
        // 0x80032ACC: lbu         $t7, 0x1($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X1);
            goto L_80032AC4;
    }
    goto skip_0;
    // 0x80032ACC: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    skip_0:
L_80032AD0:
    // 0x80032AD0: jr          $ra
    // 0x80032AD4: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    return;
    // 0x80032AD4: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
;}
RECOMP_FUNC void func_800F13C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F13C4: div.s       $f2, $f12, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800F13C8: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800F13CC: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800F13D0: nop

    // 0x800F13D4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800F13D8: nop

    // 0x800F13DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F13E0: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x800F13E4: mul.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800F13E8: jr          $ra
    // 0x800F13EC: nop

    return;
    // 0x800F13EC: nop

;}
RECOMP_FUNC void ncbadolly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080018C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800190: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800194: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800198: jal         0x800A5800
    // 0x8080019C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800A5800(rdram, ctx);
        goto after_0;
    // 0x8080019C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808001A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808001A4: jal         0x80085668
    // 0x808001A8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_1;
    // 0x808001A8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808001AC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808001B0: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x808001B4: sb          $t6, 0x20($t7)
    MEM_B(0X20, ctx->r15) = ctx->r14;
    // 0x808001B8: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x808001BC: jal         0x800855A0
    // 0x808001C0: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    _cadbfunc_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808001C0: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_2:
    // 0x808001C4: jal         0x80085580
    // 0x808001C8: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808001C8: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_3:
    // 0x808001CC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808001D0: jal         0x800855B0
    // 0x808001D4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _cadbfunc_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x808001D4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808001E0: jal         0x80111B8C
    // 0x808001E4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_80111B8C(rdram, ctx);
        goto after_5;
    // 0x808001E4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x808001E8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808001EC: jal         0x800855C0
    // 0x808001F0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _cadbfunc_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808001F0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x808001F4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808001F8: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
    // 0x808001FC: swc1        $f4, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f4.u32l;
    // 0x80800200: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x80800204: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800208: swc1        $f6, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->f6.u32l;
    // 0x8080020C: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80800210: jal         0x80085610
    // 0x80800214: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    _cadbfunc_entrypoint_18(rdram, ctx);
        goto after_7;
    // 0x80800214: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_7:
    // 0x80800218: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x8080021C: jal         0x80085620
    // 0x80800220: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    _cadbfunc_entrypoint_20(rdram, ctx);
        goto after_8;
    // 0x80800220: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_8:
    // 0x80800224: lw          $t0, 0x1C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1C);
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x80800230: sb          $zero, 0x21($t0)
    MEM_B(0X21, ctx->r8) = 0;
    // 0x80800234: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80800238: jal         0x80112570
    // 0x8080023C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_80112570(rdram, ctx);
        goto after_9;
    // 0x8080023C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_9:
    // 0x80800240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800244: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800248: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080024C: jr          $ra
    // 0x80800250: nop

    return;
    // 0x80800250: nop

    // 0x80800254: nop

    // 0x80800258: nop

    // 0x8080025C: nop

;}
RECOMP_FUNC void func_800F371C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F371C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800F3720: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800F3724: xor         $v0, $t6, $t7
    ctx->r2 = ctx->r14 ^ ctx->r15;
    // 0x800F3728: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F372C: beq         $v0, $zero, L_800F3774
    if (ctx->r2 == 0) {
        // 0x800F3730: nop
    
            goto L_800F3774;
    }
    // 0x800F3730: nop

    // 0x800F3734: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x800F3738: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800F373C: xor         $v0, $t8, $t9
    ctx->r2 = ctx->r24 ^ ctx->r25;
    // 0x800F3740: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F3744: beq         $v0, $zero, L_800F3774
    if (ctx->r2 == 0) {
        // 0x800F3748: nop
    
            goto L_800F3774;
    }
    // 0x800F3748: nop

    // 0x800F374C: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800F3750: lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X8);
    // 0x800F3754: xor         $v0, $t0, $t1
    ctx->r2 = ctx->r8 ^ ctx->r9;
    // 0x800F3758: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F375C: beq         $v0, $zero, L_800F3774
    if (ctx->r2 == 0) {
        // 0x800F3760: nop
    
            goto L_800F3774;
    }
    // 0x800F3760: nop

    // 0x800F3764: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x800F3768: lw          $t3, 0xC($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XC);
    // 0x800F376C: xor         $v0, $t2, $t3
    ctx->r2 = ctx->r10 ^ ctx->r11;
    // 0x800F3770: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800F3774:
    // 0x800F3774: jr          $ra
    // 0x800F3778: nop

    return;
    // 0x800F3778: nop

;}
