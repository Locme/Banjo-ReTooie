#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void sucoaster_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080157C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801580: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801584: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801588: jal         0x80100094
    // 0x8080158C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080158C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801590: lb          $t7, 0x19($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X19);
    // 0x80801594: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801598: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080159C: bltzl       $t7, L_808015C0
    if (SIGNED(ctx->r15) < 0) {
        // 0x808015A0: lh          $t9, 0x10($a1)
        ctx->r25 = MEM_H(ctx->r5, 0X10);
            goto L_808015C0;
    }
    goto skip_0;
    // 0x808015A0: lh          $t9, 0x10($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X10);
    skip_0:
    // 0x808015A4: jal         0x80089F78
    // 0x808015A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808015A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808015AC: bne         $v0, $zero, L_808015BC
    if (ctx->r2 != 0) {
        // 0x808015B0: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_808015BC;
    }
    // 0x808015B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808015B4: b           L_808015E8
    // 0x808015B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808015E8;
    // 0x808015B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808015BC:
    // 0x808015BC: lh          $t9, 0x10($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X10);
L_808015C0:
    // 0x808015C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808015C4: addiu       $t0, $zero, 0x102
    ctx->r8 = ADD32(0, 0X102);
    // 0x808015C8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x808015CC: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x808015D0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808015D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808015D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808015DC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808015E0: jal         0x80089F90
    // 0x808015E4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x808015E4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
L_808015E8:
    // 0x808015E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808015EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808015F0: jr          $ra
    // 0x808015F4: nop

    return;
    // 0x808015F4: nop

;}
RECOMP_FUNC void func_800C38E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C38E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C38E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C38EC: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C38F0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C38F4: bne         $t6, $zero, L_800C3904
    if (ctx->r14 != 0) {
        // 0x800C38F8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C3904;
    }
    // 0x800C38F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C38FC: b           L_800C3910
    // 0x800C3900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C3910;
    // 0x800C3900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C3904:
    // 0x800C3904: jal         0x800C1414
    // 0x800C3908: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3908: nop

    after_0:
    // 0x800C390C: lh          $v0, 0x58($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X58);
L_800C3910:
    // 0x800C3910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3918: jr          $ra
    // 0x800C391C: nop

    return;
    // 0x800C391C: nop

;}
RECOMP_FUNC void func_8080000C_chwitchyshockpadswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800018: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800024: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80800028: addiu       $a1, $zero, 0x4E8
    ctx->r5 = ADD32(0, 0X4E8);
    // 0x8080002C: jal         0x8008A0C8
    // 0x80800030: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800030: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_0:
    // 0x80800034: bne         $v0, $zero, L_8080004C
    if (ctx->r2 != 0) {
        // 0x80800038: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_8080004C;
    }
    // 0x80800038: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080003C: jal         0x800FFAB0
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800044: b           L_80800084
    // 0x80800048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800084;
    // 0x80800048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080004C:
    // 0x8080004C: jal         0x800EE7F8
    // 0x80800050: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800050: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80800054: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: addiu       $a1, $zero, 0x365
    ctx->r5 = ADD32(0, 0X365);
    // 0x80800060: jal         0x80085808
    // 0x80800064: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800064: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x80800068: beq         $v0, $zero, L_80800078
    if (ctx->r2 == 0) {
        // 0x8080006C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800078;
    }
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: jal         0x80108B04
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_4;
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80800078:
    // 0x80800078: jal         0x80085818
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800080: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800084:
    // 0x80800084: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800088: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void chcaptainblubber_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2228, 0X176C) << 16);
    // 0x808014EC: jr          $ra
    // 0x808014F0: addiu       $v0, $v0, 0x176C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2228, 0X176C));
    return;
    // 0x808014F0: addiu       $v0, $v0, 0x176C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2228, 0X176C));
    // 0x808014F4: nop

    // 0x808014F8: nop

    // 0x808014FC: nop

;}
RECOMP_FUNC void subaddieDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8080000C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80800010: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80800014: bnel        $t8, $zero, L_80800050
    if (ctx->r24 != 0) {
        // 0x80800018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800050;
    }
    goto skip_0;
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080001C: jal         0x8010A698
    // 0x80800020: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8010A698(rdram, ctx);
        goto after_0;
    // 0x80800020: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800024: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800028: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080002C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80800030: lbu         $t0, 0x13($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X13);
    // 0x80800034: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80800038: jal         0x80103014
    // 0x8080003C: sb          $t1, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r9;
    func_80103014(rdram, ctx);
        goto after_1;
    // 0x8080003C: sb          $t1, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r9;
    after_1:
    // 0x80800040: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800044: jal         0x8010A654
    // 0x80800048: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8010A654(rdram, ctx);
        goto after_2;
    // 0x80800048: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800050:
    // 0x80800050: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void func_80800324_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080032C: jal         0x80800144
    // 0x80800330: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800144_chnests(rdram, ctx);
        goto after_0;
    // 0x80800330: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800334: jal         0x808002E0
    // 0x80800338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808002E0_chnests(rdram, ctx);
        goto after_1;
    // 0x80800338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080033C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800344: jr          $ra
    // 0x80800348: nop

    return;
    // 0x80800348: nop

;}
RECOMP_FUNC void _chquizremotectrl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DB0: syscall     454
    recomp_syscall_handler(rdram, ctx, 0x80086DB0);
    return;
    // 0x80086DB4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808024C8_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808024C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808024CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808024D0: jal         0x800E4208
    // 0x808024D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800E4208(rdram, ctx);
        goto after_0;
    // 0x808024D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808024D8: jal         0x800E44FC
    // 0x808024DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800E44FC(rdram, ctx);
        goto after_1;
    // 0x808024DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808024E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808024E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808024E8: jr          $ra
    // 0x808024EC: nop

    return;
    // 0x808024EC: nop

;}
RECOMP_FUNC void idlight_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800240: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800244: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800248: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8080024C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80800250: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80800254: jr          $ra
    // 0x80800258: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80800258: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void _chfactorylinkgrill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087550: syscall     587
    recomp_syscall_handler(rdram, ctx, 0x80087550);
    return;
    // 0x80087554: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A13A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A13A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A13A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A13A8: jr          $ra
    // 0x800A13AC: sb          $t6, 0x7090($at)
    MEM_B(0X7090, ctx->r1) = ctx->r14;
    return;
    // 0x800A13AC: sb          $t6, 0x7090($at)
    MEM_B(0X7090, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_800C7900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7900: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800C7904: addiu       $v1, $v1, 0x760C
    ctx->r3 = ADD32(ctx->r3, 0X760C);
    // 0x800C7908: lb          $t6, 0x1($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1);
    // 0x800C790C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C7910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7914: bnel        $t6, $zero, L_800C7968
    if (ctx->r14 != 0) {
        // 0x800C7918: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C7968;
    }
    goto skip_0;
    // 0x800C7918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C791C: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x800C7920: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x800C7924: bnel        $at, $zero, L_800C7968
    if (ctx->r1 != 0) {
        // 0x800C7928: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C7968;
    }
    goto skip_1;
    // 0x800C7928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800C792C: jal         0x8001210C
    // 0x800C7930: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x800C7930: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x800C7934: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800C7938: beq         $v0, $zero, L_800C7964
    if (ctx->r2 == 0) {
        // 0x800C793C: addiu       $v1, $v1, 0x760C
        ctx->r3 = ADD32(ctx->r3, 0X760C);
            goto L_800C7964;
    }
    // 0x800C793C: addiu       $v1, $v1, 0x760C
    ctx->r3 = ADD32(ctx->r3, 0X760C);
    // 0x800C7940: jal         0x800C75A0
    // 0x800C7944: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    func_800C75A0(rdram, ctx);
        goto after_1;
    // 0x800C7944: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    after_1:
    // 0x800C7948: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C794C: jal         0x800FCCD4
    // 0x800C7950: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800FCCD4(rdram, ctx);
        goto after_2;
    // 0x800C7950: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800C7954: bne         $v0, $zero, L_800C7964
    if (ctx->r2 != 0) {
        // 0x800C7958: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800C7964;
    }
    // 0x800C7958: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C795C: jal         0x800C7618
    // 0x800C7960: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800C7618(rdram, ctx);
        goto after_3;
    // 0x800C7960: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
L_800C7964:
    // 0x800C7964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C7968:
    // 0x800C7968: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C796C: jr          $ra
    // 0x800C7970: nop

    return;
    // 0x800C7970: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082CD8: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082CD8);
    return;
    // 0x80082CDC: addi        $t0, $zero, 0x8C
    ctx->r8 = ADD32(0, 0X8C);
;}
RECOMP_FUNC void func_80800BE8_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BF0: jal         0x800839B8
    // 0x80800BF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800BF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BF8: jal         0x808002E4
    // 0x80800BFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808002E4_bsbeefly(rdram, ctx);
        goto after_1;
    // 0x80800BFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800C00: jal         0x80082830
    // 0x80800C04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsbee_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800C04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C10: jr          $ra
    // 0x80800C14: nop

    return;
    // 0x80800C14: nop

;}
RECOMP_FUNC void func_800C8594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8594: lbu         $t6, 0x15($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15);
    // 0x800C8598: jr          $ra
    // 0x800C859C: and         $v0, $t6, $a1
    ctx->r2 = ctx->r14 & ctx->r5;
    return;
    // 0x800C859C: and         $v0, $t6, $a1
    ctx->r2 = ctx->r14 & ctx->r5;
;}
RECOMP_FUNC void func_800CE928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE92C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE930: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800CE934: jal         0x800CE3E0
    // 0x800CE938: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CE938: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800CE93C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800CE940: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x800CE944: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800CE948: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x800CE94C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CE954: jr          $ra
    // 0x800CE958: nop

    return;
    // 0x800CE958: nop

;}
RECOMP_FUNC void func_8009FC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FC34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009FC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009FC3C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8009FC40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009FC44: jal         0x8009C128
    // 0x8009FC48: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8009FC48: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8009FC4C: jal         0x800964DC
    // 0x8009FC50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800964DC(rdram, ctx);
        goto after_1;
    // 0x8009FC50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8009FC54: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8009FC58: jal         0x800966E0
    // 0x8009FC5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800966E0(rdram, ctx);
        goto after_2;
    // 0x8009FC5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8009FC60: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8009FC64: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8009FC68: jal         0x800889A8
    // 0x8009FC6C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _fxripple_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8009FC6C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x8009FC70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009FC74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009FC78: jr          $ra
    // 0x8009FC7C: nop

    return;
    // 0x8009FC7C: nop

;}
RECOMP_FUNC void func_808000FC_susplinet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: bgez        $a1, L_8080010C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80800100: sra         $t6, $a1, 3
        ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8080010C;
    }
    // 0x80800100: sra         $t6, $a1, 3
    ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
    // 0x80800104: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x80800108: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8080010C:
    // 0x8080010C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80800110: lbu         $t8, 0x50($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X50);
    // 0x80800114: andi        $t9, $a1, 0x7
    ctx->r25 = ctx->r5 & 0X7;
    // 0x80800118: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8080011C: sllv        $t1, $t0, $t9
    ctx->r9 = S32(ctx->r8 << (ctx->r25 & 31));
    // 0x80800120: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x80800124: beq         $t2, $zero, L_80800134
    if (ctx->r10 == 0) {
        // 0x80800128: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800134;
    }
    // 0x80800128: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8080012C: jr          $ra
    // 0x80800130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800134:
    // 0x80800134: jr          $ra
    // 0x80800138: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800138: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _bswalk_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084240: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084240);
    return;
    // 0x80084244: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void chvolcanobits_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E14: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800E18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800E1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800E20: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800E24: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800E28: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800E2C: jal         0x80106790
    // 0x80800E30: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800E30: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x80800E34: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E38: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800E3C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80800E40: addu        $t0, $t7, $s0
    ctx->r8 = ADD32(ctx->r15, ctx->r16);
    // 0x80800E44: sltu        $at, $s0, $t0
    ctx->r1 = ctx->r16 < ctx->r8 ? 1 : 0;
    // 0x80800E48: beq         $at, $zero, L_80800EDC
    if (ctx->r1 == 0) {
        // 0x80800E4C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800EDC;
    }
L_80800E4C:
    // 0x80800E4C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800E58: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800E5C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800E60: beq         $v1, $a3, L_80800EA0
    if (ctx->r3 == ctx->r7) {
        // 0x80800E64: lh          $t8, 0x0($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X0);
            goto L_80800EA0;
    }
    // 0x80800E64: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
L_80800E68:
    // 0x80800E68: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80800E6C: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80800E70: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800E74: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800E78: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80800E7C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80800E80: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80800E84: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800E88: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800E8C: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80800E90: nop

    // 0x80800E94: sh          $t1, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r9;
    // 0x80800E98: bne         $v1, $a3, L_80800E68
    if (ctx->r3 != ctx->r7) {
        // 0x80800E9C: lh          $t8, 0x0($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X0);
            goto L_80800E68;
    }
    // 0x80800E9C: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
L_80800EA0:
    // 0x80800EA0: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80800EA4: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80800EA8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80800EAC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800EB0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80800EB4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80800EB8: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800EBC: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800EC0: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80800EC4: nop

    // 0x80800EC8: sh          $t1, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r9;
    // 0x80800ECC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800ED0: sltu        $at, $s0, $t0
    ctx->r1 = ctx->r16 < ctx->r8 ? 1 : 0;
    // 0x80800ED4: bne         $at, $zero, L_80800E4C
    if (ctx->r1 != 0) {
        // 0x80800ED8: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80800E4C;
    }
    // 0x80800ED8: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_80800EDC:
    // 0x80800EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EE0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800EE4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800EE8: jr          $ra
    // 0x80800EEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800EEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80801CE8_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801CF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801CF4: jal         0x80100094
    // 0x80801CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801CFC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2B20) << 16);
    // 0x80801D00: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801D04: addiu       $a2, $a2, 0x2B20
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2B20));
    // 0x80801D08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801D0C: addiu       $a1, $v0, 0x24
    ctx->r5 = ADD32(ctx->r2, 0X24);
    // 0x80801D10: jal         0x80089D20
    // 0x80801D14: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801D14: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_1:
    // 0x80801D18: bne         $v0, $zero, L_80801D40
    if (ctx->r2 != 0) {
        // 0x80801D1C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801D40;
    }
    // 0x80801D1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801D20: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D24: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2B20) << 16);
    // 0x80801D28: addiu       $a2, $a2, 0x2B20
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2B20));
    // 0x80801D2C: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80801D30: jal         0x80089D20
    // 0x80801D34: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801D34: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_2:
    // 0x80801D38: beql        $v0, $zero, L_80801D74
    if (ctx->r2 == 0) {
        // 0x80801D3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801D74;
    }
    goto skip_0;
    // 0x80801D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80801D40:
    // 0x80801D40: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80801D44: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80801D48: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801D4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801D50: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x80801D54: jal         0x800E1610
    // 0x80801D58: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    func_800E1610(rdram, ctx);
        goto after_3;
    // 0x80801D58: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    after_3:
    // 0x80801D5C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80801D60: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801D64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801D68: jal         0x80018820
    // 0x80801D6C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80018820(rdram, ctx);
        goto after_4;
    // 0x80801D6C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_4:
    // 0x80801D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801D74:
    // 0x80801D74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D78: jr          $ra
    // 0x80801D7C: nop

    return;
    // 0x80801D7C: nop

;}
RECOMP_FUNC void func_808002A0_bskazspring(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002AC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808002B0: lbu         $v0, 0x15C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X15C);
    // 0x808002B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002BC: beq         $v0, $at, L_808002E0
    if (ctx->r2 == ctx->r1) {
        // 0x808002C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002E0;
    }
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002C8: beq         $v0, $at, L_80800330
    if (ctx->r2 == ctx->r1) {
        // 0x808002CC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800330;
    }
    // 0x808002CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808002D0: beq         $v0, $at, L_80800358
    if (ctx->r2 == ctx->r1) {
        // 0x808002D4: nop
    
            goto L_80800358;
    }
    // 0x808002D4: nop

    // 0x808002D8: b           L_80800390
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800390;
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002E0:
    // 0x808002E0: lui         $a1, 0x3E61
    ctx->r5 = S32(0X3E61 << 16);
    // 0x808002E4: jal         0x8008CB10
    // 0x808002E8: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x808002E8: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    after_0:
    // 0x808002EC: beq         $v0, $zero, L_80800308
    if (ctx->r2 == 0) {
        // 0x808002F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800308;
    }
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: lui         $a2, 0x3F0E
    ctx->r6 = S32(0X3F0E << 16);
    // 0x808002F8: ori         $a2, $a2, 0xD917
    ctx->r6 = ctx->r6 | 0XD917;
    // 0x808002FC: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x80800300: jal         0x8009DF94
    // 0x80800304: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF94(rdram, ctx);
        goto after_1;
    // 0x80800304: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_1:
L_80800308:
    // 0x80800308: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x8080030C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800310: jal         0x8008CB10
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800318: beq         $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x8080031C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080038C;
    }
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800320: jal         0x80800064
    // 0x80800324: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800064_bskazspring(rdram, ctx);
        goto after_3;
    // 0x80800324: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800328: b           L_80800390
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800390;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800330:
    // 0x80800330: jal         0x80800000
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazspring(rdram, ctx);
        goto after_4;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800338: jal         0x8008CAEC
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_5;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800340: beq         $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x80800344: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080038C;
    }
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: jal         0x80800064
    // 0x8080034C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800064_bskazspring(rdram, ctx);
        goto after_6;
    // 0x8080034C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800350: b           L_80800390
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800390;
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800358:
    // 0x80800358: jal         0x80800000
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazspring(rdram, ctx);
        goto after_7;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x80091A30
    // 0x80800368: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_8;
    // 0x80800368: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x8080036C: beq         $v0, $zero, L_80800378
    if (ctx->r2 == 0) {
        // 0x80800370: addiu       $t6, $zero, 0xDF
        ctx->r14 = ADD32(0, 0XDF);
            goto L_80800378;
    }
    // 0x80800370: addiu       $t6, $zero, 0xDF
    ctx->r14 = ADD32(0, 0XDF);
    // 0x80800374: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800378:
    // 0x80800378: jal         0x8008E078
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_9;
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800380: beq         $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x80800384: addiu       $t7, $zero, 0xDF
        ctx->r15 = ADD32(0, 0XDF);
            goto L_8080038C;
    }
    // 0x80800384: addiu       $t7, $zero, 0xDF
    ctx->r15 = ADD32(0, 0XDF);
    // 0x80800388: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8080038C:
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800390:
    // 0x80800390: jal         0x80091A58
    // 0x80800394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_10;
    // 0x80800394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800398: beq         $v0, $zero, L_808003A4
    if (ctx->r2 == 0) {
        // 0x8080039C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_808003A4;
    }
    // 0x8080039C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808003A0: sw          $t8, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r24;
L_808003A4:
    // 0x808003A4: lw          $t9, 0x160($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X160);
    // 0x808003A8: beql        $t9, $zero, L_808003E8
    if (ctx->r25 == 0) {
        // 0x808003AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003E8;
    }
    goto skip_0;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808003B0: jal         0x8009BB50
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_11;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808003B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808003BC: nop

    // 0x808003C0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808003C4: nop

    // 0x808003C8: bc1fl       L_808003E8
    if (!c1cs) {
        // 0x808003CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003E8;
    }
    goto skip_1;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808003D0: jal         0x80097E74
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097E74(rdram, ctx);
        goto after_12;
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808003D8: beq         $v0, $zero, L_808003E4
    if (ctx->r2 == 0) {
        // 0x808003DC: addiu       $t0, $zero, 0xBE
        ctx->r8 = ADD32(0, 0XBE);
            goto L_808003E4;
    }
    // 0x808003DC: addiu       $t0, $zero, 0xBE
    ctx->r8 = ADD32(0, 0XBE);
    // 0x808003E0: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_808003E4:
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003E8:
    // 0x808003E8: jal         0x8009E5C8
    // 0x808003EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x808003EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x808003F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003FC: jr          $ra
    // 0x80800400: nop

    return;
    // 0x80800400: nop

;}
RECOMP_FUNC void boot_inflate_codes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800012B0: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x800012B4: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800012B8: mfc1        $s4, $f17
    ctx->r20 = (int32_t)ctx->f_odd[(17 - 1) * 2];
    // 0x800012BC: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x800012C0: addiu       $s0, $s0, 0x4300
    ctx->r16 = ADD32(ctx->r16, 0X4300);
    // 0x800012C4: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x800012C8: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x800012CC: lhu         $t2, 0x0($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X0);
    // 0x800012D0: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x800012D4: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x800012D8: lhu         $t0, 0x0($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X0);
L_800012DC:
    // 0x800012DC: slt         $at, $fp, $a2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r6) ? 1 : 0;
L_800012E0:
    // 0x800012E0: beq         $at, $zero, L_80001308
    if (ctx->r1 == 0) {
        // 0x800012E4: and         $s5, $gp, $t2
        ctx->r21 = ctx->r28 & ctx->r10;
            goto L_80001308;
    }
    // 0x800012E4: and         $s5, $gp, $t2
    ctx->r21 = ctx->r28 & ctx->r10;
L_800012E8:
    // 0x800012E8: lbu         $s5, 0x0($s7)
    ctx->r21 = MEM_BU(ctx->r23, 0X0);
    // 0x800012EC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800012F0: sllv        $s5, $s5, $fp
    ctx->r21 = S32(ctx->r21 << (ctx->r30 & 31));
    // 0x800012F4: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x800012F8: slt         $at, $fp, $a2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800012FC: bne         $at, $zero, L_800012E8
    if (ctx->r1 != 0) {
        // 0x80001300: or          $gp, $gp, $s5
        ctx->r28 = ctx->r28 | ctx->r21;
            goto L_800012E8;
    }
    // 0x80001300: or          $gp, $gp, $s5
    ctx->r28 = ctx->r28 | ctx->r21;
    // 0x80001304: and         $s5, $gp, $t2
    ctx->r21 = ctx->r28 & ctx->r10;
L_80001308:
    // 0x80001308: sll         $s5, $s5, 2
    ctx->r21 = S32(ctx->r21 << 2);
    // 0x8000130C: addu        $s5, $s5, $a0
    ctx->r21 = ADD32(ctx->r21, ctx->r4);
    // 0x80001310: lbu         $s1, 0x0($s5)
    ctx->r17 = MEM_BU(ctx->r21, 0X0);
    // 0x80001314: slti        $at, $s1, 0x11
    ctx->r1 = SIGNED(ctx->r17) < 0X11 ? 1 : 0;
    // 0x80001318: bne         $at, $zero, L_80001388
    if (ctx->r1 != 0) {
        // 0x8000131C: addiu       $t9, $zero, 0x63
        ctx->r25 = ADD32(0, 0X63);
            goto L_80001388;
    }
    // 0x8000131C: addiu       $t9, $zero, 0x63
    ctx->r25 = ADD32(0, 0X63);
    // 0x80001320: lbu         $t7, 0x1($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X1);
L_80001324:
    // 0x80001324: beq         $s1, $t9, L_80001588
    if (ctx->r17 == ctx->r25) {
        // 0x80001328: addiu       $s1, $s1, -0x10
        ctx->r17 = ADD32(ctx->r17, -0X10);
            goto L_80001588;
    }
    // 0x80001328: addiu       $s1, $s1, -0x10
    ctx->r17 = ADD32(ctx->r17, -0X10);
    // 0x8000132C: subu        $fp, $fp, $t7
    ctx->r30 = SUB32(ctx->r30, ctx->r15);
    // 0x80001330: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80001334: beq         $at, $zero, L_80001358
    if (ctx->r1 == 0) {
        // 0x80001338: srlv        $gp, $gp, $t7
        ctx->r28 = S32(U32(ctx->r28) >> (ctx->r15 & 31));
            goto L_80001358;
    }
    // 0x80001338: srlv        $gp, $gp, $t7
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r15 & 31));
L_8000133C:
    // 0x8000133C: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    // 0x80001340: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80001344: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x80001348: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8000134C: slt         $t7, $fp, $s1
    ctx->r15 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80001350: bne         $t7, $zero, L_8000133C
    if (ctx->r15 != 0) {
        // 0x80001354: or          $gp, $gp, $at
        ctx->r28 = ctx->r28 | ctx->r1;
            goto L_8000133C;
    }
    // 0x80001354: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
L_80001358:
    // 0x80001358: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x8000135C: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x80001360: lhu         $t7, 0x0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X0);
    // 0x80001364: lhu         $t8, 0x2($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X2);
    // 0x80001368: and         $t7, $t7, $gp
    ctx->r15 = ctx->r15 & ctx->r28;
    // 0x8000136C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80001370: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80001374: addu        $s5, $s6, $t7
    ctx->r21 = ADD32(ctx->r22, ctx->r15);
    // 0x80001378: lbu         $s1, 0x0($s5)
    ctx->r17 = MEM_BU(ctx->r21, 0X0);
    // 0x8000137C: slti        $at, $s1, 0x11
    ctx->r1 = SIGNED(ctx->r17) < 0X11 ? 1 : 0;
    // 0x80001380: beql        $at, $zero, L_80001324
    if (ctx->r1 == 0) {
        // 0x80001384: lbu         $t7, 0x1($s5)
        ctx->r15 = MEM_BU(ctx->r21, 0X1);
            goto L_80001324;
    }
    goto skip_0;
    // 0x80001384: lbu         $t7, 0x1($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X1);
    skip_0:
L_80001388:
    // 0x80001388: lbu         $t7, 0x1($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X1);
    // 0x8000138C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80001390: srlv        $gp, $gp, $t7
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r15 & 31));
    // 0x80001394: bne         $s1, $at, L_800013D4
    if (ctx->r17 != ctx->r1) {
        // 0x80001398: subu        $fp, $fp, $t7
        ctx->r30 = SUB32(ctx->r30, ctx->r15);
            goto L_800013D4;
    }
    // 0x80001398: subu        $fp, $fp, $t7
    ctx->r30 = SUB32(ctx->r30, ctx->r15);
    // 0x8000139C: lhu         $t7, 0x2($s5)
    ctx->r15 = MEM_HU(ctx->r21, 0X2);
    // 0x800013A0: addu        $t8, $t3, $s4
    ctx->r24 = ADD32(ctx->r11, ctx->r20);
    // 0x800013A4: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800013A8: lw          $t8, 0xA84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA84);
    // 0x800013AC: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x800013B0: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800013B4: sw          $t8, 0xA84($sp)
    MEM_W(0XA84, ctx->r29) = ctx->r24;
    // 0x800013B8: andi        $t8, $t8, 0x17
    ctx->r24 = ctx->r24 & 0X17;
    // 0x800013BC: sllv        $t9, $t9, $t8
    ctx->r25 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x800013C0: lw          $t8, 0xA88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA88);
    // 0x800013C4: xor         $t8, $t8, $t9
    ctx->r24 = ctx->r24 ^ ctx->r25;
    // 0x800013C8: sw          $t8, 0xA88($sp)
    MEM_W(0XA88, ctx->r29) = ctx->r24;
    // 0x800013CC: j           L_800012DC
    // 0x800013D0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_800012DC;
    // 0x800013D0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800013D4:
    // 0x800013D4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800013D8: beq         $s1, $at, L_8000157C
    if (ctx->r17 == ctx->r1) {
        // 0x800013DC: slt         $at, $fp, $s1
        ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
            goto L_8000157C;
    }
    // 0x800013DC: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800013E0: beq         $at, $zero, L_80001404
    if (ctx->r1 == 0) {
        // 0x800013E4: sll         $t7, $s1, 1
        ctx->r15 = S32(ctx->r17 << 1);
            goto L_80001404;
    }
    // 0x800013E4: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
L_800013E8:
    // 0x800013E8: lbu         $t9, 0x0($s7)
    ctx->r25 = MEM_BU(ctx->r23, 0X0);
    // 0x800013EC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800013F0: sllv        $t9, $t9, $fp
    ctx->r25 = S32(ctx->r25 << (ctx->r30 & 31));
    // 0x800013F4: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x800013F8: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800013FC: bne         $at, $zero, L_800013E8
    if (ctx->r1 != 0) {
        // 0x80001400: or          $gp, $gp, $t9
        ctx->r28 = ctx->r28 | ctx->r25;
            goto L_800013E8;
    }
    // 0x80001400: or          $gp, $gp, $t9
    ctx->r28 = ctx->r28 | ctx->r25;
L_80001404:
    // 0x80001404: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x80001408: lhu         $t7, 0x0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X0);
    // 0x8000140C: lhu         $t8, 0x2($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X2);
    // 0x80001410: and         $t7, $t7, $gp
    ctx->r15 = ctx->r15 & ctx->r28;
    // 0x80001414: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x80001418: subu        $fp, $fp, $s1
    ctx->r30 = SUB32(ctx->r30, ctx->r17);
    // 0x8000141C: slt         $at, $fp, $a3
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80001420: beq         $at, $zero, L_80001444
    if (ctx->r1 == 0) {
        // 0x80001424: srlv        $gp, $gp, $s1
        ctx->r28 = S32(U32(ctx->r28) >> (ctx->r17 & 31));
            goto L_80001444;
    }
    // 0x80001424: srlv        $gp, $gp, $s1
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r17 & 31));
L_80001428:
    // 0x80001428: lbu         $t7, 0x0($s7)
    ctx->r15 = MEM_BU(ctx->r23, 0X0);
    // 0x8000142C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80001430: sllv        $t7, $t7, $fp
    ctx->r15 = S32(ctx->r15 << (ctx->r30 & 31));
    // 0x80001434: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x80001438: slt         $at, $fp, $a3
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8000143C: bne         $at, $zero, L_80001428
    if (ctx->r1 != 0) {
        // 0x80001440: or          $gp, $gp, $t7
        ctx->r28 = ctx->r28 | ctx->r15;
            goto L_80001428;
    }
    // 0x80001440: or          $gp, $gp, $t7
    ctx->r28 = ctx->r28 | ctx->r15;
L_80001444:
    // 0x80001444: and         $t7, $gp, $t0
    ctx->r15 = ctx->r28 & ctx->r8;
    // 0x80001448: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000144C: addu        $s5, $a1, $t7
    ctx->r21 = ADD32(ctx->r5, ctx->r15);
    // 0x80001450: lbu         $s1, 0x0($s5)
    ctx->r17 = MEM_BU(ctx->r21, 0X0);
    // 0x80001454: slti        $at, $s1, 0x11
    ctx->r1 = SIGNED(ctx->r17) < 0X11 ? 1 : 0;
    // 0x80001458: bne         $at, $zero, L_800014D0
    if (ctx->r1 != 0) {
        // 0x8000145C: addiu       $t7, $zero, 0x63
        ctx->r15 = ADD32(0, 0X63);
            goto L_800014D0;
    }
    // 0x8000145C: addiu       $t7, $zero, 0x63
    ctx->r15 = ADD32(0, 0X63);
L_80001460:
    // 0x80001460: beq         $s1, $t7, L_80001588
    if (ctx->r17 == ctx->r15) {
        // 0x80001464: lbu         $t7, 0x1($s5)
        ctx->r15 = MEM_BU(ctx->r21, 0X1);
            goto L_80001588;
    }
    // 0x80001464: lbu         $t7, 0x1($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X1);
    // 0x80001468: addiu       $s1, $s1, -0x10
    ctx->r17 = ADD32(ctx->r17, -0X10);
    // 0x8000146C: srlv        $gp, $gp, $t7
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r15 & 31));
    // 0x80001470: subu        $fp, $fp, $t7
    ctx->r30 = SUB32(ctx->r30, ctx->r15);
    // 0x80001474: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80001478: beq         $at, $zero, L_800014A0
    if (ctx->r1 == 0) {
        // 0x8000147C: nop
    
            goto L_800014A0;
    }
    // 0x8000147C: nop

    // 0x80001480: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_80001484:
    // 0x80001484: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80001488: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8000148C: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x80001490: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x80001494: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80001498: bnel        $at, $zero, L_80001484
    if (ctx->r1 != 0) {
        // 0x8000149C: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_80001484;
    }
    goto skip_1;
    // 0x8000149C: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_1:
L_800014A0:
    // 0x800014A0: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x800014A4: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x800014A8: lhu         $t7, 0x0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X0);
    // 0x800014AC: lhu         $t8, 0x2($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X2);
    // 0x800014B0: and         $t7, $t7, $gp
    ctx->r15 = ctx->r15 & ctx->r28;
    // 0x800014B4: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800014B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800014BC: addu        $s5, $s6, $t7
    ctx->r21 = ADD32(ctx->r22, ctx->r15);
    // 0x800014C0: lbu         $s1, 0x0($s5)
    ctx->r17 = MEM_BU(ctx->r21, 0X0);
    // 0x800014C4: slti        $at, $s1, 0x11
    ctx->r1 = SIGNED(ctx->r17) < 0X11 ? 1 : 0;
    // 0x800014C8: beq         $at, $zero, L_80001460
    if (ctx->r1 == 0) {
        // 0x800014CC: addiu       $t7, $zero, 0x63
        ctx->r15 = ADD32(0, 0X63);
            goto L_80001460;
    }
    // 0x800014CC: addiu       $t7, $zero, 0x63
    ctx->r15 = ADD32(0, 0X63);
L_800014D0:
    // 0x800014D0: lbu         $t7, 0x1($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X1);
    // 0x800014D4: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
    // 0x800014D8: subu        $fp, $fp, $t7
    ctx->r30 = SUB32(ctx->r30, ctx->r15);
    // 0x800014DC: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800014E0: beq         $at, $zero, L_80001504
    if (ctx->r1 == 0) {
        // 0x800014E4: srlv        $gp, $gp, $t7
        ctx->r28 = S32(U32(ctx->r28) >> (ctx->r15 & 31));
            goto L_80001504;
    }
    // 0x800014E4: srlv        $gp, $gp, $t7
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r15 & 31));
L_800014E8:
    // 0x800014E8: lbu         $t7, 0x0($s7)
    ctx->r15 = MEM_BU(ctx->r23, 0X0);
    // 0x800014EC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800014F0: sllv        $t7, $t7, $fp
    ctx->r15 = S32(ctx->r15 << (ctx->r30 & 31));
    // 0x800014F4: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x800014F8: slt         $at, $fp, $s1
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800014FC: bne         $at, $zero, L_800014E8
    if (ctx->r1 != 0) {
        // 0x80001500: or          $gp, $gp, $t7
        ctx->r28 = ctx->r28 | ctx->r15;
            goto L_800014E8;
    }
    // 0x80001500: or          $gp, $gp, $t7
    ctx->r28 = ctx->r28 | ctx->r15;
L_80001504:
    // 0x80001504: addu        $t7, $t8, $s0
    ctx->r15 = ADD32(ctx->r24, ctx->r16);
    // 0x80001508: lhu         $t7, 0x0($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X0);
    // 0x8000150C: lhu         $t8, 0x2($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X2);
    // 0x80001510: and         $t7, $t7, $gp
    ctx->r15 = ctx->r15 & ctx->r28;
    // 0x80001514: subu        $s3, $s4, $t7
    ctx->r19 = SUB32(ctx->r20, ctx->r15);
    // 0x80001518: subu        $s3, $s3, $t8
    ctx->r19 = SUB32(ctx->r19, ctx->r24);
    // 0x8000151C: srlv        $gp, $gp, $s1
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r17 & 31));
    // 0x80001520: subu        $fp, $fp, $s1
    ctx->r30 = SUB32(ctx->r30, ctx->r17);
    // 0x80001524: addu        $t7, $s4, $s2
    ctx->r15 = ADD32(ctx->r20, ctx->r18);
    // 0x80001528: slt         $at, $t7, $t5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000152C: beq         $at, $zero, L_80001588
    if (ctx->r1 == 0) {
        // 0x80001530: addu        $t8, $t3, $s3
        ctx->r24 = ADD32(ctx->r11, ctx->r19);
            goto L_80001588;
    }
    // 0x80001530: addu        $t8, $t3, $s3
    ctx->r24 = ADD32(ctx->r11, ctx->r19);
    // 0x80001534: addu        $t9, $t3, $s4
    ctx->r25 = ADD32(ctx->r11, ctx->r20);
    // 0x80001538: addu        $s4, $s4, $s2
    ctx->r20 = ADD32(ctx->r20, ctx->r18);
    // 0x8000153C: lw          $v0, 0xA84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA84);
    // 0x80001540: lw          $v1, 0xA88($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA88);
L_80001544:
    // 0x80001544: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x80001548: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x8000154C: sb          $t7, -0x1($t9)
    MEM_B(-0X1, ctx->r25) = ctx->r15;
    // 0x80001550: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80001554: andi        $at, $v0, 0x17
    ctx->r1 = ctx->r2 & 0X17;
    // 0x80001558: sllv        $t7, $t7, $at
    ctx->r15 = S32(ctx->r15 << (ctx->r1 & 31));
    // 0x8000155C: xor         $v1, $v1, $t7
    ctx->r3 = ctx->r3 ^ ctx->r15;
    // 0x80001560: addu        $at, $t3, $s4
    ctx->r1 = ADD32(ctx->r11, ctx->r20);
    // 0x80001564: bne         $t9, $at, L_80001544
    if (ctx->r25 != ctx->r1) {
        // 0x80001568: addiu       $t8, $t8, 0x1
        ctx->r24 = ADD32(ctx->r24, 0X1);
            goto L_80001544;
    }
    // 0x80001568: addiu       $t8, $t8, 0x1
    ctx->r24 = ADD32(ctx->r24, 0X1);
    // 0x8000156C: sw          $v0, 0xA84($sp)
    MEM_W(0XA84, ctx->r29) = ctx->r2;
    // 0x80001570: sw          $v1, 0xA88($sp)
    MEM_W(0XA88, ctx->r29) = ctx->r3;
    // 0x80001574: j           L_800012E0
    // 0x80001578: slt         $at, $fp, $a2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r6) ? 1 : 0;
        goto L_800012E0;
    // 0x80001578: slt         $at, $fp, $a2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r6) ? 1 : 0;
L_8000157C:
    // 0x8000157C: mtc1        $s4, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r20;
    // 0x80001580: jr          $ra
    // 0x80001584: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    return;
    // 0x80001584: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_80001588:
    // 0x80001588: jr          $ra
    // 0x8000158C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8000158C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void heap_bytes_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B3C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001B3C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B3C8: jal         0x8001AAD8
    // 0x8001B3CC: nop

    heap_bytes_used(rdram, ctx);
        goto after_0;
    // 0x8001B3CC: nop

    after_0:
    // 0x8001B3D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B3D4: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001B3D8: lw          $t6, -0x4100($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4100);
    // 0x8001B3DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001B3E0: jr          $ra
    // 0x8001B3E4: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
    return;
    // 0x8001B3E4: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
;}
RECOMP_FUNC void func_80800310_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800318: jal         0x800897C8
    // 0x8080031C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x8080031C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800328: jr          $ra
    // 0x8080032C: nop

    return;
    // 0x8080032C: nop

;}
RECOMP_FUNC void func_800EBCD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBCD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EBCD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EBCD8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800EBCDC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800EBCE0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800EBCE4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800EBCE8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800EBCEC: lhu         $t7, 0xA($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XA);
    // 0x800EBCF0: jal         0x800E9AC0
    // 0x800EBCF4: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
    func_800E9AC0(rdram, ctx);
        goto after_0;
    // 0x800EBCF4: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
    after_0:
    // 0x800EBCF8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800EBCFC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800EBD00: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800EBD04: jal         0x800EBC0C
    // 0x800EBD08: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800EBC0C(rdram, ctx);
        goto after_1;
    // 0x800EBD08: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_1:
    // 0x800EBD0C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800EBD10: lhu         $t8, 0x1E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1E);
    // 0x800EBD14: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800EBD18: sh          $t8, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r24;
    // 0x800EBD1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EBD20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800EBD24: jr          $ra
    // 0x800EBD28: nop

    return;
    // 0x800EBD28: nop

;}
RECOMP_FUNC void chinflatableboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(832, 0X2E50) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2E50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(832, 0X2E50));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2E50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(832, 0X2E50));
;}
RECOMP_FUNC void _chpotogoldbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875E8: syscall     594
    recomp_syscall_handler(rdram, ctx, 0x800875E8);
    return;
    // 0x800875EC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080088C_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080088C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800894: jal         0x80800114
    // 0x80800898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800114_bstntswim(rdram, ctx);
        goto after_0;
    // 0x80800898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080089C: jal         0x800839C8
    // 0x808008A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x808008A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808008A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008AC: jr          $ra
    // 0x808008B0: nop

    return;
    // 0x808008B0: nop

;}
RECOMP_FUNC void chfactorysparkroom_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E88: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2372, 0X1108) << 16);
    // 0x80800E8C: jr          $ra
    // 0x80800E90: addiu       $v0, $v0, 0x1108
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2372, 0X1108));
    return;
    // 0x80800E90: addiu       $v0, $v0, 0x1108
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2372, 0X1108));
;}
RECOMP_FUNC void _chfootwear_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087778: syscall     620
    recomp_syscall_handler(rdram, ctx, 0x80087778);
    return;
    // 0x8008777C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80801E18_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E18: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80801E1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801E20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801E24: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80801E28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801E2C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801E30: beql        $t6, $zero, L_80801EB4
    if (ctx->r14 == 0) {
        // 0x80801E34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801EB4;
    }
    goto skip_0;
    // 0x80801E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801E38: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801E3C: jal         0x800F0F9C
    // 0x80801E40: lwc1        $f12, 0x34($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X34);
    func_800F0F9C(rdram, ctx);
        goto after_0;
    // 0x80801E40: lwc1        $f12, 0x34($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x80801E44: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(924, 0X2338) << 16);
    // 0x80801E48: addiu       $a1, $a1, 0x2338
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X2338));
    // 0x80801E4C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801E50: jal         0x800F3780
    // 0x80801E54: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_1;
    // 0x80801E54: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x80801E58: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80801E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E60: jal         0x80103DFC
    // 0x80801E64: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80103DFC(rdram, ctx);
        goto after_2;
    // 0x80801E64: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x80801E68: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(924, 0X2320) << 16);
    // 0x80801E6C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(924, 0X232C) << 16);
    // 0x80801E70: addiu       $a2, $a2, 0x232C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(924, 0X232C));
    // 0x80801E74: addiu       $a1, $a1, 0x2320
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X2320));
    // 0x80801E78: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80801E7C: jal         0x800F3214
    // 0x80801E80: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_800F3214(rdram, ctx);
        goto after_3;
    // 0x80801E80: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80801E84: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80801E88: jal         0x800C8CB8
    // 0x80801E8C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800C8CB8(rdram, ctx);
        goto after_4;
    // 0x80801E8C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x80801E90: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80801E94: jal         0x800C8E84
    // 0x80801E98: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800C8E84(rdram, ctx);
        goto after_5;
    // 0x80801E98: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x80801E9C: jal         0x800D8FF8
    // 0x80801EA0: nop

    func_800D8FF8(rdram, ctx);
        goto after_6;
    // 0x80801EA0: nop

    after_6:
    // 0x80801EA4: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80801EA8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80801EAC: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x80801EB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801EB4:
    // 0x80801EB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801EB8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801EBC: jr          $ra
    // 0x80801EC0: nop

    return;
    // 0x80801EC0: nop

;}
RECOMP_FUNC void func_800C5190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5190: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5194: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C5198: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C519C: jr          $ra
    // 0x800C51A0: lwc1        $f0, -0x55FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X55FC);
    return;
    // 0x800C51A0: lwc1        $f0, -0x55FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X55FC);
;}
RECOMP_FUNC void _bsfirstp_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800842D0: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800842D0);
    return;
    // 0x800842D4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800C1430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1430: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800C1434: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C1438: addiu       $t8, $t8, -0x74F0
    ctx->r24 = ADD32(ctx->r24, -0X74F0);
    // 0x800C143C: addiu       $t7, $t6, -0x8
    ctx->r15 = ADD32(ctx->r14, -0X8);
    // 0x800C1440: jr          $ra
    // 0x800C1444: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x800C1444: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
;}
RECOMP_FUNC void func_8010B8A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B8A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010B8A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B8AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8010B8B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8010B8B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8010B8B8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8010B8BC: jal         0x800D8FF8
    // 0x8010B8C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8010B8C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010B8C4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8010B8C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8010B8CC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8010B8D0: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x8010B8D4: lwc1        $f4, 0x2C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x8010B8D8: addiu       $a1, $a3, 0x28
    ctx->r5 = ADD32(ctx->r7, 0X28);
    // 0x8010B8DC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010B8E0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010B8E4: jal         0x800EFA20
    // 0x8010B8E8: swc1        $f10, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f10.u32l;
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x8010B8E8: swc1        $f10, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f10.u32l;
    after_1:
    // 0x8010B8EC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8010B8F0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8010B8F4: jal         0x800EF04C
    // 0x8010B8F8: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x8010B8F8: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    after_2:
    // 0x8010B8FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B900: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010B904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010B908: jr          $ra
    // 0x8010B90C: nop

    return;
    // 0x8010B90C: nop

;}
RECOMP_FUNC void _subaddielink_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A020: syscall     823
    recomp_syscall_handler(rdram, ctx, 0x8008A020);
    return;
    // 0x8008A024: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _ncpoddialog_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895F8: syscall     784
    recomp_syscall_handler(rdram, ctx, 0x800895F8);
    return;
    // 0x800895FC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chdoubloon_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800078: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8080007C: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80800080: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800084: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80800088: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x8080008C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80800090: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80800094: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80800098: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8080009C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808000A0: jal         0x800D8FF8
    // 0x808000A4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808000A4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x808000A8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808000AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000B0: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808000B4: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x808000B8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808000BC: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
    // 0x808000C0: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808000C4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808000C8: bgez        $t8, L_808001A4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808000CC: swc1        $f10, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
            goto L_808001A4;
    }
    // 0x808000CC: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x808000D0: jal         0x800E3980
    // 0x808000D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E3980(rdram, ctx);
        goto after_1;
    // 0x808000D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808000D8: addiu       $s3, $s0, 0x4
    ctx->r19 = ADD32(ctx->r16, 0X4);
    // 0x808000DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808000E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808000E4: jal         0x800F18FC
    // 0x808000E8: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    func_800F18FC(rdram, ctx);
        goto after_2;
    // 0x808000E8: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_2:
    // 0x808000EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2256, 0X280) << 16);
    // 0x808000F0: lwc1        $f28, 0x280($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2256, 0X280));
    // 0x808000F4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808000F8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808000FC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800100: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800104: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800108: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8080010C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800110: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x80800114: addiu       $s0, $sp, 0x74
    ctx->r16 = ADD32(ctx->r29, 0X74);
L_80800118:
    // 0x80800118: jal         0x800DC0C0
    // 0x8080011C: nop

    func_800DC0C0(rdram, ctx);
        goto after_3;
    // 0x8080011C: nop

    after_3:
    // 0x80800120: c.lt.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl < ctx->f28.fl;
    // 0x80800124: nop

    // 0x80800128: bc1fl       L_8080019C
    if (!c1cs) {
        // 0x8080012C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080019C;
    }
    goto skip_0;
    // 0x8080012C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80800130: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800134: jal         0x800DC178
    // 0x80800138: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800138: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_4:
    // 0x8080013C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800140: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800144: jal         0x800DC178
    // 0x80800148: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800148: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_5:
    // 0x8080014C: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800150: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80800154: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800158: add.s       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: add.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800164: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800168: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8080016C: jal         0x800EEC30
    // 0x80800170: nop

    func_800EEC30(rdram, ctx);
        goto after_6;
    // 0x80800170: nop

    after_6:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x800EF04C
    // 0x8080017C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x8080017C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x80800180: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    // 0x8080018C: add.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x80800190: jal         0x80088AB0
    // 0x80800194: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    _fxtwinkle_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800194: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x80800198: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8080019C:
    // 0x8080019C: bne         $s1, $s2, L_80800118
    if (ctx->r17 != ctx->r18) {
        // 0x808001A0: nop
    
            goto L_80800118;
    }
    // 0x808001A0: nop

L_808001A4:
    // 0x808001A4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x808001A8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808001AC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808001B0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x808001B4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x808001B8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x808001BC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x808001C0: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x808001C4: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x808001C8: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x808001CC: jr          $ra
    // 0x808001D0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x808001D0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void chgoldsnakehead_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(724, 0X550) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x550
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(724, 0X550));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x550
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(724, 0X550));
;}
RECOMP_FUNC void func_80804450_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804450: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80804454: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804458: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080445C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804460: jal         0x80100094
    // 0x80804464: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804464: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804468: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080446C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80804470: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x80804474: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80804478: jal         0x800D91EC
    // 0x8080447C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_800D91EC(rdram, ctx);
        goto after_1;
    // 0x8080447C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80804480: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80804484: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80804488: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8080448C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80804490: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80804494: jal         0x80804644
    // 0x80804498: lwc1        $f12, 0x10($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X10);
    func_80804644_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80804498: lwc1        $f12, 0x10($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X10);
    after_2:
    // 0x8080449C: beq         $v0, $zero, L_808044C8
    if (ctx->r2 == 0) {
        // 0x808044A0: lui         $a2, 0x8081
        ctx->r6 = S32(RELOC_HI16(1480, 0X9F44) << 16);
            goto L_808044C8;
    }
    // 0x808044A0: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F44) << 16);
    // 0x808044A4: addiu       $a2, $a2, -0x60BC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F44));
    // 0x808044A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808044AC: jal         0x80089D18
    // 0x808044B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808044B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808044B4: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F3C) << 16);
    // 0x808044B8: addiu       $a2, $a2, -0x60C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F3C));
    // 0x808044BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808044C0: jal         0x808043D8
    // 0x808044C4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_808043D8_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x808044C4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
L_808044C8:
    // 0x808044C8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808044CC: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x808044D0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808044D4: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808044D8: jal         0x80804644
    // 0x808044DC: lwc1        $f12, 0x10($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X10);
    func_80804644_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x808044DC: lwc1        $f12, 0x10($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X10);
    after_5:
    // 0x808044E0: beq         $v0, $zero, L_8080450C
    if (ctx->r2 == 0) {
        // 0x808044E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080450C;
    }
    // 0x808044E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808044E8: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F44) << 16);
    // 0x808044EC: addiu       $a2, $a2, -0x60BC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F44));
    // 0x808044F0: jal         0x80089D18
    // 0x808044F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808044F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x808044F8: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F3C) << 16);
    // 0x808044FC: addiu       $a2, $a2, -0x60C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F3C));
    // 0x80804500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804504: jal         0x808043D8
    // 0x80804508: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_808043D8_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x80804508: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_7:
L_8080450C:
    // 0x8080450C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80804510: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80804514: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80804518: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080451C: jal         0x80804644
    // 0x80804520: lwc1        $f12, 0x10($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X10);
    func_80804644_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x80804520: lwc1        $f12, 0x10($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X10);
    after_8:
    // 0x80804524: beq         $v0, $zero, L_80804550
    if (ctx->r2 == 0) {
        // 0x80804528: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804550;
    }
    // 0x80804528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080452C: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F74) << 16);
    // 0x80804530: addiu       $a2, $a2, -0x608C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F74));
    // 0x80804534: jal         0x80089D18
    // 0x80804538: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80804538: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x8080453C: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F3C) << 16);
    // 0x80804540: addiu       $a2, $a2, -0x60C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F3C));
    // 0x80804544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804548: jal         0x808043D8
    // 0x8080454C: lui         $a1, 0x3FA0
    ctx->r5 = S32(0X3FA0 << 16);
    func_808043D8_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x8080454C: lui         $a1, 0x3FA0
    ctx->r5 = S32(0X3FA0 << 16);
    after_10:
L_80804550:
    // 0x80804550: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80804554: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80804558: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8080455C: jal         0x80804644
    // 0x80804560: lwc1        $f12, 0x10($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X10);
    func_80804644_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x80804560: lwc1        $f12, 0x10($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X10);
    after_11:
    // 0x80804564: beq         $v0, $zero, L_80804590
    if (ctx->r2 == 0) {
        // 0x80804568: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804590;
    }
    // 0x80804568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080456C: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F44) << 16);
    // 0x80804570: addiu       $a2, $a2, -0x60BC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F44));
    // 0x80804574: jal         0x80089D18
    // 0x80804578: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80804578: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_12:
    // 0x8080457C: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F3C) << 16);
    // 0x80804580: addiu       $a2, $a2, -0x60C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F3C));
    // 0x80804584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804588: jal         0x808043D8
    // 0x8080458C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_808043D8_chdiggerboss(rdram, ctx);
        goto after_13;
    // 0x8080458C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_13:
L_80804590:
    // 0x80804590: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80804594: lui         $a2, 0x4019
    ctx->r6 = S32(0X4019 << 16);
    // 0x80804598: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080459C: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808045A0: jal         0x80804644
    // 0x808045A4: lwc1        $f12, 0x10($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X10);
    func_80804644_chdiggerboss(rdram, ctx);
        goto after_14;
    // 0x808045A4: lwc1        $f12, 0x10($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X10);
    after_14:
    // 0x808045A8: beq         $v0, $zero, L_808045D4
    if (ctx->r2 == 0) {
        // 0x808045AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808045D4;
    }
    // 0x808045AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808045B0: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F5C) << 16);
    // 0x808045B4: addiu       $a2, $a2, -0x60A4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F5C));
    // 0x808045B8: jal         0x80089D18
    // 0x808045BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x808045BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_15:
    // 0x808045C0: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F40) << 16);
    // 0x808045C4: addiu       $a2, $a2, -0x60C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F40));
    // 0x808045C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808045CC: jal         0x808043D8
    // 0x808045D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_808043D8_chdiggerboss(rdram, ctx);
        goto after_16;
    // 0x808045D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_16:
L_808045D4:
    // 0x808045D4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x808045D8: lui         $a2, 0x4059
    ctx->r6 = S32(0X4059 << 16);
    // 0x808045DC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808045E0: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808045E4: jal         0x80804644
    // 0x808045E8: lwc1        $f12, 0x10($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X10);
    func_80804644_chdiggerboss(rdram, ctx);
        goto after_17;
    // 0x808045E8: lwc1        $f12, 0x10($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X10);
    after_17:
    // 0x808045EC: beq         $v0, $zero, L_80804618
    if (ctx->r2 == 0) {
        // 0x808045F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804618;
    }
    // 0x808045F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808045F4: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F88) << 16);
    // 0x808045F8: addiu       $a2, $a2, -0x6078
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F88));
    // 0x808045FC: jal         0x80089D18
    // 0x80804600: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x80804600: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_18:
    // 0x80804604: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F3C) << 16);
    // 0x80804608: addiu       $a2, $a2, -0x60C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F3C));
    // 0x8080460C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804610: jal         0x808043D8
    // 0x80804614: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    func_808043D8_chdiggerboss(rdram, ctx);
        goto after_19;
    // 0x80804614: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_19:
L_80804618:
    // 0x80804618: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8080461C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804620: beql        $t2, $zero, L_80804634
    if (ctx->r10 == 0) {
        // 0x80804624: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80804634;
    }
    goto skip_0;
    // 0x80804624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80804628: jal         0x808041E4
    // 0x8080462C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808041E4_chdiggerboss(rdram, ctx);
        goto after_20;
    // 0x8080462C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80804630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804634:
    // 0x80804634: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804638: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080463C: jr          $ra
    // 0x80804640: nop

    return;
    // 0x80804640: nop

;}
RECOMP_FUNC void func_808002F4_chglowbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808002F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002FC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800300: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800304: jal         0x80100094
    // 0x80800308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080030C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: jal         0x80100094
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080031C: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80800320: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800328: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x8080032C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800330: bgez        $t8, L_80800348
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800334: addiu       $a2, $zero, 0xB
        ctx->r6 = ADD32(0, 0XB);
            goto L_80800348;
    }
    // 0x80800334: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80800338: jal         0x80089F40
    // 0x8080033C: lbu         $a1, 0x17($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X17);
    _subaddiesect_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080033C: lbu         $a1, 0x17($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X17);
    after_2:
    // 0x80800340: beql        $v0, $zero, L_80800870
    if (ctx->r2 == 0) {
        // 0x80800344: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800870;
    }
    goto skip_0;
    // 0x80800344: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_80800348:
    // 0x80800348: jal         0x800D8FF8
    // 0x8080034C: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x8080034C: nop

    after_3:
    // 0x80800350: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x80800354: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
    // 0x80800358: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X1370) << 16);
    // 0x8080035C: sll         $t2, $t0, 19
    ctx->r10 = S32(ctx->r8 << 19);
    // 0x80800360: bgez        $t2, L_80800400
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800364: nop
    
            goto L_80800400;
    }
    // 0x80800364: nop

    // 0x80800368: jal         0x800DC298
    // 0x8080036C: lwc1        $f12, 0x1370($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X1370));
    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x8080036C: lwc1        $f12, 0x1370($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X1370));
    after_4:
    // 0x80800370: beq         $v0, $zero, L_80800400
    if (ctx->r2 == 0) {
        // 0x80800374: lui         $at, 0xC1F0
        ctx->r1 = S32(0XC1F0 << 16);
            goto L_80800400;
    }
    // 0x80800374: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80800378: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080037C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800380: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800384: jal         0x800DC178
    // 0x80800388: nop

    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800388: nop

    after_5:
    // 0x8080038C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800390: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800394: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80800398: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080039C: jal         0x800DC178
    // 0x808003A0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808003A0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x808003A4: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x808003A8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808003AC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808003B0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003B4: jal         0x800DC178
    // 0x808003B8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x808003B8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x808003BC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808003C0: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808003C4: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808003C8: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808003CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808003D0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808003D4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x808003D8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808003DC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808003E0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808003E4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808003E8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808003EC: jal         0x800EFA4C
    // 0x808003F0: nop

    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x808003F0: nop

    after_8:
    // 0x808003F4: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x808003F8: jal         0x80088AB0
    // 0x808003FC: addiu       $a1, $zero, 0x9E4
    ctx->r5 = ADD32(0, 0X9E4);
    _fxtwinkle_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808003FC: addiu       $a1, $zero, 0x9E4
    ctx->r5 = ADD32(0, 0X9E4);
    after_9:
L_80800400:
    // 0x80800400: jal         0x8010D254
    // 0x80800404: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_8010D254(rdram, ctx);
        goto after_10;
    // 0x80800404: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_10:
    // 0x80800408: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080040C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800410: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80800414: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x80800418: beq         $t3, $at, L_80800850
    if (ctx->r11 == ctx->r1) {
        // 0x8080041C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800850;
    }
    // 0x8080041C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800420: beq         $t3, $at, L_80800438
    if (ctx->r11 == ctx->r1) {
        // 0x80800424: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80800438;
    }
    // 0x80800424: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800428: beq         $t3, $at, L_80800718
    if (ctx->r11 == ctx->r1) {
        // 0x8080042C: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800718;
    }
    // 0x8080042C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800430: b           L_80800870
    // 0x80800434: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800870;
    // 0x80800434: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800438:
    // 0x80800438: jal         0x80089F78
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_11;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800440: beql        $v0, $zero, L_80800520
    if (ctx->r2 == 0) {
        // 0x80800444: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_80800520;
    }
    goto skip_1;
    // 0x80800444: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    skip_1:
    // 0x80800448: jal         0x80090128
    // 0x8080044C: nop

    func_80090128(rdram, ctx);
        goto after_12;
    // 0x8080044C: nop

    after_12:
    // 0x80800450: beql        $v0, $zero, L_808004B4
    if (ctx->r2 == 0) {
        // 0x80800454: lw          $t4, 0x74($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X74);
            goto L_808004B4;
    }
    goto skip_2;
    // 0x80800454: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    skip_2:
    // 0x80800458: jal         0x8010C500
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_13;
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800460: bne         $v0, $zero, L_80800484
    if (ctx->r2 != 0) {
        // 0x80800464: nop
    
            goto L_80800484;
    }
    // 0x80800464: nop

    // 0x80800468: jal         0x8010C710
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C710(rdram, ctx);
        goto after_14;
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800470: lui         $at, 0x9
    ctx->r1 = S32(0X9 << 16);
    // 0x80800474: ori         $at, $at, 0xC400
    ctx->r1 = ctx->r1 | 0XC400;
    // 0x80800478: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8080047C: beql        $at, $zero, L_808004B4
    if (ctx->r1 == 0) {
        // 0x80800480: lw          $t4, 0x74($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X74);
            goto L_808004B4;
    }
    goto skip_3;
    // 0x80800480: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    skip_3:
L_80800484:
    // 0x80800484: jal         0x800F54E4
    // 0x80800488: nop

    func_800F54E4(rdram, ctx);
        goto after_15;
    // 0x80800488: nop

    after_15:
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800490: jal         0x8010CD50
    // 0x80800494: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010CD50(rdram, ctx);
        goto after_16;
    // 0x80800494: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
    // 0x80800498: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080049C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004A0: nop

    // 0x808004A4: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x808004A8: b           L_808004E4
    // 0x808004AC: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
        goto L_808004E4;
    // 0x808004AC: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x808004B0: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
L_808004B4:
    // 0x808004B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X1374) << 16);
    // 0x808004B8: lwc1        $f16, 0x1374($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X1374));
    // 0x808004BC: lhu         $a2, 0x14($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X14);
    // 0x808004C0: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x808004C4: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x808004C8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x808004CC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D4: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x808004D8: addiu       $a3, $zero, 0x3F
    ctx->r7 = ADD32(0, 0X3F);
    // 0x808004DC: jal         0x80089F88
    // 0x808004E0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_17;
    // 0x808004E0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_17:
L_808004E4:
    // 0x808004E4: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x808004E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808004EC: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x808004F0: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x808004F4: addiu       $t7, $zero, 0x4803
    ctx->r15 = ADD32(0, 0X4803);
    // 0x808004F8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800500: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80800504: jal         0x80089F90
    // 0x80800508: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_18;
    // 0x80800508: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_18:
    // 0x8080050C: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80800510: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80800514: lhu         $t9, 0x6($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X6);
    // 0x80800518: sh          $t9, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r25;
    // 0x8080051C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_80800520:
    // 0x80800520: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800524: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x80800528: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080052C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800530: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x80800534: lhu         $a2, 0x14($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X14);
    // 0x80800538: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800540: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80800544: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800548: jal         0x80089F80
    // 0x8080054C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_19;
    // 0x8080054C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_19:
    // 0x80800550: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800554: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80800558: jal         0x8010CB84
    // 0x8080055C: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    func_8010CB84(rdram, ctx);
        goto after_20;
    // 0x8080055C: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    after_20:
    // 0x80800560: beq         $v0, $zero, L_80800578
    if (ctx->r2 == 0) {
        // 0x80800564: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80800578;
    }
    // 0x80800564: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800568: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080056C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80800570: b           L_80800584
    // 0x80800574: swc1        $f8, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f8.u32l;
        goto L_80800584;
    // 0x80800574: swc1        $f8, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f8.u32l;
L_80800578:
    // 0x80800578: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080057C: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80800580: swc1        $f10, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f10.u32l;
L_80800584:
    // 0x80800584: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800588: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080058C: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80800590: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80800594: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800598: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080059C: lwc1        $f14, 0x10($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X10);
    // 0x808005A0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808005A4: jal         0x800F15F8
    // 0x808005A8: nop

    func_800F15F8(rdram, ctx);
        goto after_21;
    // 0x808005A8: nop

    after_21:
    // 0x808005AC: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(1628, 0X14B4) << 16);
    // 0x808005B0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808005B4: addiu       $t5, $t5, 0x14B4
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(1628, 0X14B4));
    // 0x808005B8: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: sw          $at, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r1;
    // 0x808005C4: lw          $a2, 0x4($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X4);
    // 0x808005C8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x808005CC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808005D0: lw          $a3, 0x8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X8);
    // 0x808005D4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808005D8: jal         0x801026CC
    // 0x808005DC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    func_801026CC(rdram, ctx);
        goto after_22;
    // 0x808005DC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_22:
    // 0x808005E0: jal         0x80101F24
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_23;
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808005E8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1628, 0X13B0) << 16);
    // 0x808005EC: addiu       $a1, $a1, 0x13B0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1628, 0X13B0));
    // 0x808005F0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808005F4: jal         0x800F3780
    // 0x808005F8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_24;
    // 0x808005F8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_24:
    // 0x808005FC: lui         $a1, 0x30
    ctx->r5 = S32(0X30 << 16);
    // 0x80800600: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800604: ori         $a1, $a1, 0x5425
    ctx->r5 = ctx->r5 | 0X5425;
    // 0x80800608: jal         0x8010C3A8
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C3A8(rdram, ctx);
        goto after_25;
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800610: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80800614: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800618: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8080061C: beql        $t9, $zero, L_8080065C
    if (ctx->r25 == 0) {
        // 0x80800620: lw          $t1, 0x74($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X74);
            goto L_8080065C;
    }
    goto skip_4;
    // 0x80800620: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    skip_4:
    // 0x80800624: jal         0x800EE7F8
    // 0x80800628: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_26;
    // 0x80800628: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_26:
    // 0x8080062C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800630: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800634: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800638: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x8080063C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800640: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800644: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x80800648: jal         0x800C8CB8
    // 0x8080064C: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_27;
    // 0x8080064C: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    after_27:
    // 0x80800650: jal         0x80800000
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chglowbo(rdram, ctx);
        goto after_28;
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800658: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
L_8080065C:
    // 0x8080065C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800660: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X1378) << 16);
    // 0x80800664: lwc1        $f18, 0xC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80800668: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x8080066C: nop

    // 0x80800670: bc1f        L_808006C0
    if (!c1cs) {
        // 0x80800674: nop
    
            goto L_808006C0;
    }
    // 0x80800674: nop

    // 0x80800678: jal         0x800DC298
    // 0x8080067C: lwc1        $f12, 0x1378($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X1378));
    func_800DC298(rdram, ctx);
        goto after_29;
    // 0x8080067C: lwc1        $f12, 0x1378($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X1378));
    after_29:
    // 0x80800680: beq         $v0, $zero, L_808006C0
    if (ctx->r2 == 0) {
        // 0x80800684: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_808006C0;
    }
    // 0x80800684: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800688: jal         0x8010CAC0
    // 0x8080068C: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    func_8010CAC0(rdram, ctx);
        goto after_30;
    // 0x8080068C: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    after_30:
    // 0x80800690: beq         $v0, $zero, L_808006C0
    if (ctx->r2 == 0) {
        // 0x80800694: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_808006C0;
    }
    // 0x80800694: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800698: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080069C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x808006A0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1628, 0X1420) << 16);
    // 0x808006A4: addiu       $a2, $a2, 0x1420
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1628, 0X1420));
    // 0x808006A8: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
    // 0x808006AC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808006B0: jal         0x80089D18
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_31;
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x808006B8: b           L_808006D8
    // 0x808006BC: nop

        goto L_808006D8;
    // 0x808006BC: nop

L_808006C0:
    // 0x808006C0: jal         0x800D8FF8
    // 0x808006C4: nop

    func_800D8FF8(rdram, ctx);
        goto after_32;
    // 0x808006C4: nop

    after_32:
    // 0x808006C8: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x808006CC: lwc1        $f6, 0xC($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XC);
    // 0x808006D0: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x808006D4: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
L_808006D8:
    // 0x808006D8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1628, 0X1430) << 16);
    // 0x808006DC: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x808006E0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808006E4: addiu       $a2, $a2, 0x1430
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1628, 0X1430));
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006EC: jal         0x80089D20
    // 0x808006F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_33;
    // 0x808006F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_33:
    // 0x808006F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1628, 0X143C) << 16);
    // 0x808006F8: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x808006FC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800700: addiu       $a2, $a2, 0x143C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1628, 0X143C));
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800708: jal         0x80089D20
    // 0x8080070C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_34;
    // 0x8080070C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_34:
    // 0x80800710: b           L_80800870
    // 0x80800714: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800870;
    // 0x80800714: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800718:
    // 0x80800718: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x8080071C: jal         0x800EE7F8
    // 0x80800720: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_35;
    // 0x80800720: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_35:
    // 0x80800724: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800728: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080072C: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800730: lhu         $t4, 0x76($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X76);
    // 0x80800734: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800738: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8080073C: srl         $t6, $t4, 7
    ctx->r14 = S32(U32(ctx->r12) >> 7);
    // 0x80800740: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800744: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800748: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080074C: bgez        $t6, L_80800760
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800750: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800760;
    }
    // 0x80800750: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800754: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800758: nop

    // 0x8080075C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80800760:
    // 0x80800760: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800764: jal         0x800EF1B8
    // 0x80800768: nop

    func_800EF1B8(rdram, ctx);
        goto after_36;
    // 0x80800768: nop

    after_36:
    // 0x8080076C: jal         0x80101F24
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_37;
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800774: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1628, 0X13B0) << 16);
    // 0x80800778: addiu       $a1, $a1, 0x13B0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1628, 0X13B0));
    // 0x8080077C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800780: jal         0x800F3780
    // 0x80800784: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_38;
    // 0x80800784: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_38:
    // 0x80800788: jal         0x800D8FF8
    // 0x8080078C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_39;
    // 0x8080078C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_39:
    // 0x80800790: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800794: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800798: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8080079C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808007A0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808007A4: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x808007A8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808007AC: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x808007B0: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x808007B4: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x808007B8: beql        $t5, $zero, L_808007FC
    if (ctx->r13 == 0) {
        // 0x808007BC: lui         $a1, 0x3E99
        ctx->r5 = S32(0X3E99 << 16);
            goto L_808007FC;
    }
    goto skip_5;
    // 0x808007BC: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    skip_5:
    // 0x808007C0: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808007C4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808007C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007CC: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x808007D0: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808007D4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x808007D8: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808007DC: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x808007E0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808007E4: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x808007E8: jal         0x800C8CB8
    // 0x808007EC: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_40;
    // 0x808007EC: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_40:
    // 0x808007F0: jal         0x80800000
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chglowbo(rdram, ctx);
        goto after_41;
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x808007F8: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
L_808007FC:
    // 0x808007FC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800800: jal         0x80101E14
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_42;
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80800808: beq         $v0, $zero, L_80800820
    if (ctx->r2 == 0) {
        // 0x8080080C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800820;
    }
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800810: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1628, 0X1430) << 16);
    // 0x80800814: addiu       $a2, $a2, 0x1430
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1628, 0X1430));
    // 0x80800818: jal         0x80089D18
    // 0x8080081C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_43;
    // 0x8080081C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_43:
L_80800820:
    // 0x80800820: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800824: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800828: jal         0x80101E14
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_44;
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x80800830: beq         $v0, $zero, L_8080086C
    if (ctx->r2 == 0) {
        // 0x80800834: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080086C;
    }
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800838: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1628, 0X143C) << 16);
    // 0x8080083C: addiu       $a2, $a2, 0x143C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1628, 0X143C));
    // 0x80800840: jal         0x80089D18
    // 0x80800844: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_45;
    // 0x80800844: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_45:
    // 0x80800848: b           L_80800870
    // 0x8080084C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800870;
    // 0x8080084C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800850:
    // 0x80800850: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x80800854: beq         $a0, $zero, L_80800864
    if (ctx->r4 == 0) {
        // 0x80800858: nop
    
            goto L_80800864;
    }
    // 0x80800858: nop

    // 0x8080085C: jal         0x800C8B84
    // 0x80800860: nop

    func_800C8B84(rdram, ctx);
        goto after_46;
    // 0x80800860: nop

    after_46:
L_80800864:
    // 0x80800864: jal         0x800FFAB0
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_47;
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
L_8080086C:
    // 0x8080086C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800870:
    // 0x80800870: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800874: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80800878: jr          $ra
    // 0x8080087C: nop

    return;
    // 0x8080087C: nop

;}
RECOMP_FUNC void func_8080034C_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080034C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800350: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800354: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800358: jal         0x80089CA0
    // 0x8080035C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080035C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x80103110
    // 0x80800368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800370: jal         0x8008A4B0
    // 0x80800374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800378: jal         0x8010A590
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_3;
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800380: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800388: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x8080038C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800390: jal         0x80101FDC
    // 0x80800394: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800394: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_4:
    // 0x80800398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080039C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003A4: jr          $ra
    // 0x808003A8: nop

    return;
    // 0x808003A8: nop

;}
RECOMP_FUNC void func_80800688_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080068C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800690: jal         0x80800270
    // 0x80800694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800270_bsswim(rdram, ctx);
        goto after_0;
    // 0x80800694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800698: jal         0x800A4E30
    // 0x8080069C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4E30(rdram, ctx);
        goto after_1;
    // 0x8080069C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808006A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006A8: jr          $ra
    // 0x808006AC: nop

    return;
    // 0x808006AC: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083CD8: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083CD8);
    return;
    // 0x80083CDC: addi        $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
;}
RECOMP_FUNC void func_8080015C_gcdialogcamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800164: jal         0x80106790
    // 0x80800168: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800168: nop

    after_0:
    // 0x8080016C: lhu         $t6, 0x68($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X68);
    // 0x80800170: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800174: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800178: bgez        $t6, L_8080018C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080017C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080018C;
    }
    // 0x8080017C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800180: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800184: nop

    // 0x80800188: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8080018C:
    // 0x8080018C: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80800190: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800194: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800198: mul.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8080019C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001A0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x808001A4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808001A8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x808001AC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x808001B0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808001B4: jal         0x800856E8
    // 0x808001B8: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    _capod_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808001B8: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void gclightsDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800488: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080048C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800490: jal         0x800C911C
    // 0x80800494: nop

    func_800C911C(rdram, ctx);
        goto after_0;
    // 0x80800494: nop

    after_0:
    // 0x80800498: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080049C: jal         0x800B28C4
    // 0x808004A0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x808004A0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_1:
    // 0x808004A4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808004A8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x808004AC: jal         0x800B296C
    // 0x808004B0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    vector_end(rdram, ctx);
        goto after_2;
    // 0x808004B0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x808004B4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x808004B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004BC: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x808004C0: beq         $at, $zero, L_808004E8
    if (ctx->r1 == 0) {
        // 0x808004C4: nop
    
            goto L_808004E8;
    }
    // 0x808004C4: nop

    // 0x808004C8: lbu         $t7, 0x14($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X14);
L_808004CC:
    // 0x808004CC: bnel        $t7, $zero, L_808004DC
    if (ctx->r15 != 0) {
        // 0x808004D0: addiu       $v1, $v1, 0x1C
        ctx->r3 = ADD32(ctx->r3, 0X1C);
            goto L_808004DC;
    }
    goto skip_0;
    // 0x808004D0: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    skip_0:
    // 0x808004D4: sb          $zero, 0x15($v1)
    MEM_B(0X15, ctx->r3) = 0;
    // 0x808004D8: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
L_808004DC:
    // 0x808004DC: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x808004E0: bnel        $at, $zero, L_808004CC
    if (ctx->r1 != 0) {
        // 0x808004E4: lbu         $t7, 0x14($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X14);
            goto L_808004CC;
    }
    goto skip_1;
    // 0x808004E4: lbu         $t7, 0x14($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X14);
    skip_1:
L_808004E8:
    // 0x808004E8: jal         0x800C8A98
    // 0x808004EC: nop

    func_800C8A98(rdram, ctx);
        goto after_3;
    // 0x808004EC: nop

    after_3:
    // 0x808004F0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808004F4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808004F8: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x808004FC: jal         0x800B28CC
    // 0x80800500: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    vector_at(rdram, ctx);
        goto after_4;
    // 0x80800500: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_4:
    // 0x80800504: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800508: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x8080050C: sb          $t9, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r25;
    // 0x80800510: sb          $t0, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r8;
    // 0x80800514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800518: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8080051C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800520: jr          $ra
    // 0x80800524: nop

    return;
    // 0x80800524: nop

;}
RECOMP_FUNC void subaddierouteDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800574: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080057C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800580: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800584: lhu         $t7, 0x12($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X12);
    // 0x80800588: srl         $t8, $t7, 1
    ctx->r24 = S32(U32(ctx->r15) >> 1);
    // 0x8080058C: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x80800590: jal         0x8001210C
    // 0x80800594: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80800594: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80800598: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8080059C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005A4: xor         $v0, $v0, $t0
    ctx->r2 = ctx->r2 ^ ctx->r8;
    // 0x808005A8: jr          $ra
    // 0x808005AC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x808005AC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void _chfantasytrashcanbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087600: syscall     596
    recomp_syscall_handler(rdram, ctx, 0x80087600);
    return;
    // 0x80087604: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800F6AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6AA4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6AAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6AB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6AB4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6AB8: jal         0x8009E6F8
    // 0x800F6ABC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x800F6ABC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F6AC0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F6AC4: xori        $t7, $v0, 0x1B
    ctx->r15 = ctx->r2 ^ 0X1B;
    // 0x800F6AC8: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F6ACC: bne         $v0, $zero, L_800F6B2C
    if (ctx->r2 != 0) {
        // 0x800F6AD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F6B2C;
    }
    // 0x800F6AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6AD4: xori        $v0, $v1, 0x1C
    ctx->r2 = ctx->r3 ^ 0X1C;
    // 0x800F6AD8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F6ADC: bne         $v0, $zero, L_800F6B2C
    if (ctx->r2 != 0) {
        // 0x800F6AE0: nop
    
            goto L_800F6B2C;
    }
    // 0x800F6AE0: nop

    // 0x800F6AE4: xori        $v0, $v1, 0x1D
    ctx->r2 = ctx->r3 ^ 0X1D;
    // 0x800F6AE8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F6AEC: bne         $v0, $zero, L_800F6B2C
    if (ctx->r2 != 0) {
        // 0x800F6AF0: nop
    
            goto L_800F6B2C;
    }
    // 0x800F6AF0: nop

    // 0x800F6AF4: xori        $v0, $v1, 0x1E
    ctx->r2 = ctx->r3 ^ 0X1E;
    // 0x800F6AF8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F6AFC: bne         $v0, $zero, L_800F6B2C
    if (ctx->r2 != 0) {
        // 0x800F6B00: nop
    
            goto L_800F6B2C;
    }
    // 0x800F6B00: nop

    // 0x800F6B04: xori        $v0, $v1, 0x1A
    ctx->r2 = ctx->r3 ^ 0X1A;
    // 0x800F6B08: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F6B0C: bne         $v0, $zero, L_800F6B2C
    if (ctx->r2 != 0) {
        // 0x800F6B10: nop
    
            goto L_800F6B2C;
    }
    // 0x800F6B10: nop

    // 0x800F6B14: xori        $v0, $v1, 0xA4
    ctx->r2 = ctx->r3 ^ 0XA4;
    // 0x800F6B18: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800F6B1C: bne         $v0, $zero, L_800F6B2C
    if (ctx->r2 != 0) {
        // 0x800F6B20: nop
    
            goto L_800F6B2C;
    }
    // 0x800F6B20: nop

    // 0x800F6B24: xori        $v0, $v1, 0xA5
    ctx->r2 = ctx->r3 ^ 0XA5;
    // 0x800F6B28: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800F6B2C:
    // 0x800F6B2C: jr          $ra
    // 0x800F6B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F6B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
