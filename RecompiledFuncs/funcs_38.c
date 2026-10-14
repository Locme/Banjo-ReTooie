#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801BD4_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801BD8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801BDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801BE0: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x80801BE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801BE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801BEC: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80801BF0: jal         0x8008A4B0
    // 0x80801BF4: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80801BF4: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    after_0:
    // 0x80801BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BFC: jal         0x80102424
    // 0x80801C00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80801C00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80801C04: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801C08: addiu       $t9, $zero, 0x62
    ctx->r25 = ADD32(0, 0X62);
    // 0x80801C0C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801C10: addiu       $a1, $zero, 0x12B3
    ctx->r5 = ADD32(0, 0X12B3);
    // 0x80801C14: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80801C18: jal         0x8008A208
    // 0x80801C1C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80801C1C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80801C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C24: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80801C28: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80801C2C: jal         0x80801D40
    // 0x80801C30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80801D40_chaliendad(rdram, ctx);
        goto after_3;
    // 0x80801C30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80801C34: addiu       $a0, $zero, 0x45B
    ctx->r4 = ADD32(0, 0X45B);
    // 0x80801C38: jal         0x80089C30
    // 0x80801C3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80801C3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80801C40: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
    // 0x80801C44: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x80801C48: sb          $t1, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r9;
    // 0x80801C4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801C50: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801C54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801C58: jr          $ra
    // 0x80801C5C: nop

    return;
    // 0x80801C5C: nop

;}
RECOMP_FUNC void func_800D22C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D22C8: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D22CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D22D0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800D22D4: lw          $t7, -0x4BA0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4BA0);
    // 0x800D22D8: jr          $ra
    // 0x800D22DC: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    return;
    // 0x800D22DC: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
;}
RECOMP_FUNC void _gcdialogexec_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E60: syscall     658
    recomp_syscall_handler(rdram, ctx, 0x80087E60);
    return;
    // 0x80087E64: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80801B80_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B88: jal         0x80800188
    // 0x80801B8C: nop

    func_80800188_bsbfly(rdram, ctx);
        goto after_0;
    // 0x80801B8C: nop

    after_0:
    // 0x80801B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801B94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801B98: jr          $ra
    // 0x80801B9C: nop

    return;
    // 0x80801B9C: nop

;}
RECOMP_FUNC void gczoomboxdata_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808002C0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x808002C4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2686, 0XAA8) << 16);
    // 0x808002C8: addiu       $t7, $t7, 0xAA8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2686, 0XAA8));
    // 0x808002CC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808002D0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x808002D4: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x808002D8: sll         $v1, $a1, 3
    ctx->r3 = S32(ctx->r5 << 3);
    // 0x808002DC: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x808002E0: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x808002E4: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x808002E8: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x808002EC: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x808002F0: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x808002F4: sh          $t3, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r11;
    // 0x808002F8: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x808002FC: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80800300: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80800304: lwc1        $f4, 0x4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80800308: jr          $ra
    // 0x8080030C: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    return;
    // 0x8080030C: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80800BFC_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BFC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80800C00: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80800C04: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80800C08: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x80800C0C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80800C10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C14: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80800C18: andi        $t8, $v1, 0xFFFC
    ctx->r24 = ctx->r3 & 0XFFFC;
    // 0x80800C1C: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x80800C20: lh          $t9, 0x2($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X2);
    // 0x80800C24: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80800C28: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80800C2C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80800C30: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80800C34: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80800C38: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800C3C: addu        $t0, $t9, $t6
    ctx->r8 = ADD32(ctx->r25, ctx->r14);
    // 0x80800C40: lbu         $t6, 0x9B($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X9B);
    // 0x80800C44: lbu         $t9, 0x3($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X3);
    // 0x80800C48: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80800C4C: lui         $t3, 0xF800
    ctx->r11 = S32(0XF800 << 16);
    // 0x80800C50: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800C54: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80800C58: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80800C5C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80800C60: lbu         $t9, 0x2($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2);
    // 0x80800C64: andi        $t7, $t0, 0xFFFC
    ctx->r15 = ctx->r8 & 0XFFFC;
    // 0x80800C68: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
    // 0x80800C6C: sra         $t6, $t9, 2
    ctx->r14 = S32(SIGNED(ctx->r25) >> 2);
    // 0x80800C70: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x80800C74: lui         $t5, 0xE400
    ctx->r13 = S32(0XE400 << 16);
    // 0x80800C78: mflo        $t1
    ctx->r9 = lo;
    // 0x80800C7C: sra         $t7, $t1, 8
    ctx->r15 = S32(SIGNED(ctx->r9) >> 8);
    // 0x80800C80: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x80800C84: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80800C88: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80800C8C: sra         $t7, $t9, 2
    ctx->r15 = S32(SIGNED(ctx->r25) >> 2);
    // 0x80800C90: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x80800C94: lbu         $t7, 0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1);
    // 0x80800C98: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80800C9C: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x80800CA0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80800CA4: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x80800CA8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80800CAC: sra         $t6, $t1, 2
    ctx->r14 = S32(SIGNED(ctx->r9) >> 2);
    // 0x80800CB0: sra         $t9, $t1, 1
    ctx->r25 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80800CB4: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80800CB8: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x80800CBC: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80800CC0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80800CC4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80800CC8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80800CCC: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80800CD0: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80800CD4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80800CD8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80800CDC: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80800CE0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80800CE4: or          $t7, $t6, $t5
    ctx->r15 = ctx->r14 | ctx->r13;
    // 0x80800CE8: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80800CEC: addiu       $t8, $v1, -0x8
    ctx->r24 = ADD32(ctx->r3, -0X8);
    // 0x80800CF0: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80800CF4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80800CF8: addiu       $t6, $t0, -0x8
    ctx->r14 = ADD32(ctx->r8, -0X8);
    // 0x80800CFC: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80800D00: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80800D04: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80800D08: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80800D0C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80800D10: lui         $t9, 0xE100
    ctx->r25 = S32(0XE100 << 16);
    // 0x80800D14: lui         $t7, 0xF100
    ctx->r15 = S32(0XF100 << 16);
    // 0x80800D18: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80800D1C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80800D20: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800D24: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80800D28: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80800D2C: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x80800D30: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80800D34: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80800D38: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80800D3C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80800D40: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80800D44: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80800D48: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80800D4C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80800D50: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800D54: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80800D58: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80800D5C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80800D60: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80800D64: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80800D68: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x80800D6C: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80800D70: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x80800D74: sll         $t6, $t7, 24
    ctx->r14 = S32(ctx->r15 << 24);
    // 0x80800D78: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80800D7C: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x80800D80: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80800D84: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80800D88: andi        $t9, $t1, 0xFF
    ctx->r25 = ctx->r9 & 0XFF;
    // 0x80800D8C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80800D90: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80800D94: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80800D98: addiu       $t7, $v1, 0x4
    ctx->r15 = ADD32(ctx->r3, 0X4);
    // 0x80800D9C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80800DA0: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80800DA4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80800DA8: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80800DAC: addiu       $t7, $t0, 0x4
    ctx->r15 = ADD32(ctx->r8, 0X4);
    // 0x80800DB0: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80800DB4: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80800DB8: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80800DBC: addiu       $t7, $v1, -0x4
    ctx->r15 = ADD32(ctx->r3, -0X4);
    // 0x80800DC0: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80800DC4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80800DC8: addiu       $t8, $t0, -0x4
    ctx->r24 = ADD32(ctx->r8, -0X4);
    // 0x80800DCC: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80800DD0: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80800DD4: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80800DD8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80800DDC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80800DE0: lui         $t9, 0xE100
    ctx->r25 = S32(0XE100 << 16);
    // 0x80800DE4: lui         $t6, 0xF100
    ctx->r14 = S32(0XF100 << 16);
    // 0x80800DE8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80800DEC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80800DF0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800DF4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80800DF8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80800DFC: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x80800E00: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80800E04: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80800E08: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80800E0C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80800E10: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80800E14: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80800E18: jr          $ra
    // 0x80800E1C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80800E1C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800D56C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D56C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D56C8: beq         $a0, $zero, L_800D57F0
    if (ctx->r4 == 0) {
        // 0x800D56CC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D57F0;
    }
    // 0x800D56CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D56D0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800D56D4: addiu       $t1, $t1, -0x481C
    ctx->r9 = ADD32(ctx->r9, -0X481C);
    // 0x800D56D8: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x800D56DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D56E0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D56E4: blez        $v0, L_800D5720
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D56E8: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_800D5720;
    }
    // 0x800D56E8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800D56EC: lw          $t6, 0x7AD0($t6)
    if (tooie_more_memory()) ctx->r14 = MEM_W(ctx->r14, 0X7AD0); else ctx->r14 = MEM_W(ctx->r14, -0X4BB0);
    // 0x800D56F0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D56F4: addiu       $a1, $a1, 0x7AD0
    if (tooie_more_memory()) ctx->r5 = ADD32(ctx->r5, 0X7AD0); else ctx->r5 = ADD32(ctx->r5, -0X4BB0);
    // 0x800D56F8: beq         $a0, $t6, L_800D5720
    if (ctx->r4 == ctx->r14) {
        // 0x800D56FC: nop
    
            goto L_800D5720;
    }
    // 0x800D56FC: nop

    // 0x800D5700: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D5704:
    // 0x800D5704: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D5708: beq         $at, $zero, L_800D5720
    if (ctx->r1 == 0) {
        // 0x800D570C: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800D5720;
    }
    // 0x800D570C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800D5710: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800D5714: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800D5718: bnel        $a0, $t9, L_800D5704
    if (ctx->r4 != ctx->r25) {
        // 0x800D571C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D5704;
    }
    goto skip_0;
    // 0x800D571C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_800D5720:
    // 0x800D5720: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5724: bne         $v1, $v0, L_800D5734
    if (ctx->r3 != ctx->r2) {
        // 0x800D5728: addiu       $a1, $a1, 0x7AD0
        if (tooie_more_memory()) ctx->r5 = ADD32(ctx->r5, 0X7AD0); else ctx->r5 = ADD32(ctx->r5, -0X4BB0);
            goto L_800D5734;
    }
    // 0x800D5728: addiu       $a1, $a1, 0x7AD0
    if (tooie_more_memory()) ctx->r5 = ADD32(ctx->r5, 0X7AD0); else ctx->r5 = ADD32(ctx->r5, -0X4BB0);
    // 0x800D572C: b           L_800D57F4
    // 0x800D5730: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800D57F4;
    // 0x800D5730: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800D5734:
    // 0x800D5734: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5738: addiu       $t2, $t2, 0x79E0
    if (tooie_more_memory()) ctx->r10 = ADD32(ctx->r10, 0X79E0); else ctx->r10 = ADD32(ctx->r10, -0X49A8);
    // 0x800D573C: sb          $v1, -0x481B($at)
    MEM_B(-0X481B, ctx->r1) = ctx->r3;
    // 0x800D5740: addu        $a3, $v1, $t2
    ctx->r7 = ADD32(ctx->r3, ctx->r10);
    // 0x800D5744: lbu         $a2, 0x0($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X0);
    // 0x800D5748: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D574C: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800D5750: bne         $a2, $at, L_800D57E0
    if (ctx->r6 != ctx->r1) {
        // 0x800D5754: addu        $t4, $a1, $t3
        ctx->r12 = ADD32(ctx->r5, ctx->r11);
            goto L_800D57E0;
    }
    // 0x800D5754: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x800D5758: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800D575C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800D5760: jal         0x8001B084
    // 0x800D5764: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    heap_free(rdram, ctx);
        goto after_0;
    // 0x800D5764: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D5768: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800D576C: addiu       $t1, $t1, -0x481C
    ctx->r9 = ADD32(ctx->r9, -0X481C);
    // 0x800D5770: lbu         $a2, 0x0($t1)
    ctx->r6 = MEM_BU(ctx->r9, 0X0);
    // 0x800D5774: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5778: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D577C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800D5780: andi        $t5, $a2, 0xFF
    ctx->r13 = ctx->r6 & 0XFF;
    // 0x800D5784: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    // 0x800D5788: addiu       $a1, $a1, 0x7AD0
    if (tooie_more_memory()) ctx->r5 = ADD32(ctx->r5, 0X7AD0); else ctx->r5 = ADD32(ctx->r5, -0X4BB0);
    // 0x800D578C: sb          $t5, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r13;
    // 0x800D5790: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800D5794: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800D5798: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800D579C: lbu         $t6, 0x79E0($t6)
    if (tooie_more_memory()) ctx->r14 = MEM_BU(ctx->r14, 0X79E0); else ctx->r14 = MEM_BU(ctx->r14, -0X49A8);
    // 0x800D57A0: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800D57A4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800D57A8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800D57AC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800D57B0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800D57B4: addiu       $t0, $t0, 0x7800
    if (tooie_more_memory()) ctx->r8 = ADD32(ctx->r8, 0X7800); else ctx->r8 = ADD32(ctx->r8, -0X4920);
    // 0x800D57B8: sll         $t3, $a0, 1
    ctx->r11 = S32(ctx->r4 << 1);
    // 0x800D57BC: sb          $t6, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r14;
    // 0x800D57C0: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x800D57C4: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800D57C8: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800D57CC: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800D57D0: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x800D57D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D57D8: b           L_800D57F4
    // 0x800D57DC: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
        goto L_800D57F4;
    // 0x800D57DC: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
L_800D57E0:
    // 0x800D57E0: addiu       $t8, $a2, -0x1
    ctx->r24 = ADD32(ctx->r6, -0X1);
    // 0x800D57E4: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
    // 0x800D57E8: b           L_800D57F4
    // 0x800D57EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D57F4;
    // 0x800D57EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D57F0:
    // 0x800D57F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800D57F4:
    // 0x800D57F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D57F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D57FC: jr          $ra
    // 0x800D5800: nop

    return;
    // 0x800D5800: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001AC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808001B0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x808001B4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x808001B8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3354, 0X8E8) << 16);
    // 0x808001BC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808001C0: jr          $ra
    // 0x808001C4: lbu         $v0, 0x8E8($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(3354, 0X8E8));
    return;
    // 0x808001C4: lbu         $v0, 0x8E8($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(3354, 0X8E8));
;}
RECOMP_FUNC void func_80800000_dbmorph(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X0);
    // 0x80800004: addiu       $v1, $a0, 0x4
    ctx->r3 = ADD32(ctx->r4, 0X4);
    // 0x80800008: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080000C: blezl       $a2, L_80800040
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80800010: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800040;
    }
    goto skip_0;
    // 0x80800010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80800014:
    // 0x80800014: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x80800018: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080001C: bnel        $a1, $t6, L_80800030
    if (ctx->r5 != ctx->r14) {
        // 0x80800020: lw          $t7, 0x8($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X8);
            goto L_80800030;
    }
    goto skip_1;
    // 0x80800020: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    skip_1:
    // 0x80800024: jr          $ra
    // 0x80800028: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800028: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080002C: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
L_80800030:
    // 0x80800030: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800034: bne         $at, $zero, L_80800014
    if (ctx->r1 != 0) {
        // 0x80800038: addu        $v1, $v1, $t7
        ctx->r3 = ADD32(ctx->r3, ctx->r15);
            goto L_80800014;
    }
    // 0x80800038: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x8080003C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800040:
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void func_800D1338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1338: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D133C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D1340: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800D1344: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D1348: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D134C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D1350: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D1354: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D1358: jal         0x800D0820
    // 0x800D135C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D0820(rdram, ctx);
        goto after_0;
    // 0x800D135C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800D1360: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D1364: jal         0x800D0894
    // 0x800D1368: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D0894(rdram, ctx);
        goto after_1;
    // 0x800D1368: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800D136C: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D1370: bne         $at, $zero, L_800D13C8
    if (ctx->r1 != 0) {
        // 0x800D1374: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_800D13C8;
    }
    // 0x800D1374: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x800D1378: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D137C: addiu       $t7, $t7, -0x54C0
    ctx->r15 = ADD32(ctx->r15, -0X54C0);
    // 0x800D1380: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x800D1384: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800D1388: lbu         $t8, -0x2($s1)
    ctx->r24 = MEM_BU(ctx->r17, -0X2);
L_800D138C:
    // 0x800D138C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D1390: bnel        $s3, $t8, L_800D13B0
    if (ctx->r19 != ctx->r24) {
        // 0x800D1394: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800D13B0;
    }
    goto skip_0;
    // 0x800D1394: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800D1398: jal         0x800D0B68
    // 0x800D139C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x800D139C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800D13A0: beql        $v0, $zero, L_800D13B0
    if (ctx->r2 == 0) {
        // 0x800D13A4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800D13B0;
    }
    goto skip_1;
    // 0x800D13A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x800D13A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D13AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800D13B0:
    // 0x800D13B0: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x800D13B4: jal         0x800D0894
    // 0x800D13B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D0894(rdram, ctx);
        goto after_3;
    // 0x800D13B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800D13BC: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D13C0: beql        $at, $zero, L_800D138C
    if (ctx->r1 == 0) {
        // 0x800D13C4: lbu         $t8, -0x2($s1)
        ctx->r24 = MEM_BU(ctx->r17, -0X2);
            goto L_800D138C;
    }
    goto skip_2;
    // 0x800D13C4: lbu         $t8, -0x2($s1)
    ctx->r24 = MEM_BU(ctx->r17, -0X2);
    skip_2:
L_800D13C8:
    // 0x800D13C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D13CC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800D13D0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D13D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D13D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D13DC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D13E0: jr          $ra
    // 0x800D13E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D13E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8010C788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C788: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010C78C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010C790: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8010C794: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8010C798: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8010C79C: jal         0x800F54E4
    // 0x8010C7A0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8010C7A0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010C7A4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8010C7A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010C7AC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010C7B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8010C7B4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010C7B8: jal         0x800F8B88
    // 0x8010C7BC: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    func_800F8B88(rdram, ctx);
        goto after_1;
    // 0x8010C7BC: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8010C7C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8010C7C4: bnel        $v0, $at, L_8010C7F8
    if (ctx->r2 != ctx->r1) {
        // 0x8010C7C8: lwc1        $f16, 0x34($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
            goto L_8010C7F8;
    }
    goto skip_0;
    // 0x8010C7C8: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8010C7CC: jal         0x800878A0
    // 0x8010C7D0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8010C7D0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
    // 0x8010C7D4: bltz        $v0, L_8010C7F4
    if (SIGNED(ctx->r2) < 0) {
        // 0x8010C7D8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010C7F4;
    }
    // 0x8010C7D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010C7DC: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010C7E0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8010C7E4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8010C7E8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8010C7EC: jal         0x800F4EC8
    // 0x8010C7F0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F4EC8(rdram, ctx);
        goto after_3;
    // 0x8010C7F0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
L_8010C7F4:
    // 0x8010C7F4: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
L_8010C7F8:
    // 0x8010C7F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8010C7FC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8010C800: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8010C804: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8010C808: jal         0x800F4EC8
    // 0x8010C80C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F4EC8(rdram, ctx);
        goto after_4;
    // 0x8010C80C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8010C810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010C814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010C818: jr          $ra
    // 0x8010C81C: nop

    return;
    // 0x8010C81C: nop

;}
RECOMP_FUNC void _gcstatusDll_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088370: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088370);
    return;
    // 0x80088374: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _chfriesstand_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085DB8: syscall     240
    recomp_syscall_handler(rdram, ctx, 0x80085DB8);
    return;
    // 0x80085DBC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080714C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080714C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80807150: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80807154: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80807158: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8080715C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80807160: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80807164: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80807168: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x8080716C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80807170: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80807174: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80807178: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8080717C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80807180: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80807184: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x80807188: jal         0x80100094
    // 0x8080718C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080718C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807190: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x80807194: lw          $v1, 0x6C($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X6C);
    // 0x80807198: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080719C: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x808071A0: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x808071A4: beq         $t6, $zero, L_808071E8
    if (ctx->r14 == 0) {
        // 0x808071A8: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_808071E8;
    }
    // 0x808071A8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x808071AC: addiu       $s4, $sp, 0x60
    ctx->r20 = ADD32(ctx->r29, 0X60);
L_808071B0:
    // 0x808071B0: jalr        $s1
    // 0x808071B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r17)(rdram, ctx);
        goto after_1;
    // 0x808071B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808071B8: addiu       $s2, $s0, 0x1
    ctx->r18 = ADD32(ctx->r16, 0X1);
    // 0x808071BC: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x808071C0: sw          $s2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r18;
    // 0x808071C4: lw          $v1, 0x6C($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X6C);
    // 0x808071C8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x808071CC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x808071D0: andi        $t7, $v1, 0x1FF
    ctx->r15 = ctx->r3 & 0X1FF;
    // 0x808071D4: sltu        $at, $s2, $t7
    ctx->r1 = ctx->r18 < ctx->r15 ? 1 : 0;
    // 0x808071D8: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x808071DC: bne         $at, $zero, L_808071B0
    if (ctx->r1 != 0) {
        // 0x808071E0: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_808071B0;
    }
    // 0x808071E0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x808071E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_808071E8:
    // 0x808071E8: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x808071EC: bnel        $t8, $zero, L_80807214
    if (ctx->r24 != 0) {
        // 0x808071F0: addiu       $a0, $sp, 0x70
        ctx->r4 = ADD32(ctx->r29, 0X70);
            goto L_80807214;
    }
    goto skip_0;
    // 0x808071F0: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    skip_0:
    // 0x808071F4: jal         0x800AA194
    // 0x808071F8: nop

    func_800AA194(rdram, ctx);
        goto after_2;
    // 0x808071F8: nop

    after_2:
    // 0x808071FC: bnel        $v0, $zero, L_8080722C
    if (ctx->r2 != 0) {
        // 0x80807200: lw          $a2, 0x6C($s6)
        ctx->r6 = MEM_W(ctx->r22, 0X6C);
            goto L_8080722C;
    }
    goto skip_1;
    // 0x80807200: lw          $a2, 0x6C($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X6C);
    skip_1:
    // 0x80807204: lw          $v1, 0x6C($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X6C);
    // 0x80807208: andi        $t9, $v1, 0x1FF
    ctx->r25 = ctx->r3 & 0X1FF;
    // 0x8080720C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x80807210: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
L_80807214:
    // 0x80807214: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80807218: jal         0x80089968
    // 0x8080721C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    _sumultiscore_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x8080721C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    after_3:
    // 0x80807220: b           L_80807244
    // 0x80807224: lw          $t1, 0x6C($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X6C);
        goto L_80807244;
    // 0x80807224: lw          $t1, 0x6C($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X6C);
    // 0x80807228: lw          $a2, 0x6C($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X6C);
L_8080722C:
    // 0x8080722C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80807230: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80807234: andi        $t0, $a2, 0x1FF
    ctx->r8 = ctx->r6 & 0X1FF;
    // 0x80807238: jal         0x80089970
    // 0x8080723C: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    _sumultiscore_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x8080723C: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_4:
    // 0x80807240: lw          $t1, 0x6C($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X6C);
L_80807244:
    // 0x80807244: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // 0x80807248: addiu       $s4, $sp, 0x60
    ctx->r20 = ADD32(ctx->r29, 0X60);
    // 0x8080724C: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x80807250: beq         $t2, $zero, L_80807364
    if (ctx->r10 == 0) {
        // 0x80807254: sll         $t3, $s7, 2
        ctx->r11 = S32(ctx->r23 << 2);
            goto L_80807364;
    }
    // 0x80807254: sll         $t3, $s7, 2
    ctx->r11 = S32(ctx->r23 << 2);
    // 0x80807258: lui         $t4, 0x8081
    ctx->r12 = S32(RELOC_HI16(804, 0X8560) << 16);
    // 0x8080725C: addiu       $t4, $t4, -0x7AA0
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(804, 0X8560));
    // 0x80807260: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80807264: lui         $s1, 0x8081
    ctx->r17 = S32(RELOC_HI16(804, 0X8560) << 16);
    // 0x80807268: addiu       $s1, $s1, -0x7AA0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(804, 0X8560));
    // 0x8080726C: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x80807270: lw          $s5, 0x80($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X80);
    // 0x80807274: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80807278: lw          $s7, 0x98($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X98);
L_8080727C:
    // 0x8080727C: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80807280: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80807284: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80807288: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8080728C: blez        $s0, L_808072AC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80807290: sw          $v0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r2;
            goto L_808072AC;
    }
    // 0x80807290: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80807294: lw          $t7, -0x4($s3)
    ctx->r15 = MEM_W(ctx->r19, -0X4);
    // 0x80807298: bnel        $v0, $t7, L_808072B0
    if (ctx->r2 != ctx->r15) {
        // 0x8080729C: subu        $t0, $t9, $s0
        ctx->r8 = SUB32(ctx->r25, ctx->r16);
            goto L_808072B0;
    }
    goto skip_2;
    // 0x8080729C: subu        $t0, $t9, $s0
    ctx->r8 = SUB32(ctx->r25, ctx->r16);
    skip_2:
    // 0x808072A0: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x808072A4: b           L_808072B4
    // 0x808072A8: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
        goto L_808072B4;
    // 0x808072A8: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
L_808072AC:
    // 0x808072AC: subu        $t0, $t9, $s0
    ctx->r8 = SUB32(ctx->r25, ctx->r16);
L_808072B0:
    // 0x808072B0: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_808072B4:
    // 0x808072B4: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x808072B8: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x808072BC: bne         $v0, $t1, L_808072C8
    if (ctx->r2 != ctx->r9) {
        // 0x808072C0: addiu       $t2, $s0, 0x1
        ctx->r10 = ADD32(ctx->r16, 0X1);
            goto L_808072C8;
    }
    // 0x808072C0: addiu       $t2, $s0, 0x1
    ctx->r10 = ADD32(ctx->r16, 0X1);
    // 0x808072C4: sh          $t2, 0x24($t3)
    MEM_H(0X24, ctx->r11) = ctx->r10;
L_808072C8:
    // 0x808072C8: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x808072CC: addiu       $s2, $s0, 0x1
    ctx->r18 = ADD32(ctx->r16, 0X1);
    // 0x808072D0: beql        $t4, $zero, L_808072FC
    if (ctx->r12 == 0) {
        // 0x808072D4: lw          $t8, 0x4C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X4C);
            goto L_808072FC;
    }
    goto skip_3;
    // 0x808072D4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    skip_3:
    // 0x808072D8: lw          $t5, 0x64($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X64);
    // 0x808072DC: sll         $t7, $t5, 12
    ctx->r15 = S32(ctx->r13 << 12);
    // 0x808072E0: bltzl       $t7, L_808072FC
    if (SIGNED(ctx->r15) < 0) {
        // 0x808072E4: lw          $t8, 0x4C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X4C);
            goto L_808072FC;
    }
    goto skip_4;
    // 0x808072E4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    skip_4:
    // 0x808072E8: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x808072EC: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x808072F0: jal         0x800AA220
    // 0x808072F4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_800AA220(rdram, ctx);
        goto after_5;
    // 0x808072F4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_5:
    // 0x808072F8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_808072FC:
    // 0x808072FC: addiu       $a1, $zero, 0x18F3
    ctx->r5 = ADD32(0, 0X18F3);
    // 0x80807300: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80807304: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80807308: lw          $a2, 0x94($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X94);
    // 0x8080730C: bne         $fp, $t9, L_8080731C
    if (ctx->r30 != ctx->r25) {
        // 0x80807310: nop
    
            goto L_8080731C;
    }
    // 0x80807310: nop

    // 0x80807314: b           L_8080731C
    // 0x80807318: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
        goto L_8080731C;
    // 0x80807318: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
L_8080731C:
    // 0x8080731C: lw          $a0, 0x10($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X10);
    // 0x80807320: jal         0x80803E94
    // 0x80807324: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80803E94_chgameselect(rdram, ctx);
        goto after_6;
    // 0x80807324: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_6:
    // 0x80807328: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8080732C: jal         0x80087B20
    // 0x80807330: lw          $a1, 0x10($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X10);
    _gczoombox_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x80807330: lw          $a1, 0x10($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X10);
    after_7:
    // 0x80807334: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(804, 0X84FC) << 16);
    // 0x80807338: addiu       $a1, $a1, -0x7B04
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(804, 0X84FC));
    // 0x8080733C: jal         0x80087BB8
    // 0x80807340: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    _gczoombox_entrypoint_27(rdram, ctx);
        goto after_8;
    // 0x80807340: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    after_8:
    // 0x80807344: lw          $t0, 0x6C($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X6C);
    // 0x80807348: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8080734C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80807350: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x80807354: sltu        $at, $s2, $t1
    ctx->r1 = ctx->r18 < ctx->r9 ? 1 : 0;
    // 0x80807358: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8080735C: bne         $at, $zero, L_8080727C
    if (ctx->r1 != 0) {
        // 0x80807360: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8080727C;
    }
    // 0x80807360: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_80807364:
    // 0x80807364: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x80807368: beql        $t2, $zero, L_80807380
    if (ctx->r10 == 0) {
        // 0x8080736C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80807380;
    }
    goto skip_5;
    // 0x8080736C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_5:
    // 0x80807370: lbu         $t4, 0x65($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X65);
    // 0x80807374: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x80807378: sb          $t5, 0x65($s6)
    MEM_B(0X65, ctx->r22) = ctx->r13;
    // 0x8080737C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80807380:
    // 0x80807380: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80807384: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80807388: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080738C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80807390: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80807394: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80807398: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8080739C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x808073A0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x808073A4: jr          $ra
    // 0x808073A8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x808073A8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8080185C_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080185C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801860: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801864: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801868: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080186C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801870: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801874: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80801878: jal         0x80100094
    // 0x8080187C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080187C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801880: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80801884: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801888: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8080188C: slti        $at, $a2, 0xE
    ctx->r1 = SIGNED(ctx->r6) < 0XE ? 1 : 0;
    // 0x80801890: bne         $at, $zero, L_808018B8
    if (ctx->r1 != 0) {
        // 0x80801894: addiu       $t6, $a2, -0x2E
        ctx->r14 = ADD32(ctx->r6, -0X2E);
            goto L_808018B8;
    }
    // 0x80801894: addiu       $t6, $a2, -0x2E
    ctx->r14 = ADD32(ctx->r6, -0X2E);
    // 0x80801898: sltiu       $at, $t6, 0x2C
    ctx->r1 = ctx->r14 < 0X2C ? 1 : 0;
    // 0x8080189C: beq         $at, $zero, L_808018D0
    if (ctx->r1 == 0) {
        // 0x808018A0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808018D0;
    }
    // 0x808018A0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808018A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3F6C) << 16);
    // 0x808018A8: addu        $at, $at, $t6
    gpr jr_addend_808018B0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808018AC: lw          $t6, 0x3F6C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3F6C));
    // 0x808018B0: jr          $t6
    // 0x808018B4: nop

    switch (jr_addend_808018B0 >> 2) {
        case 0: goto L_80801918; break;
        case 1: goto L_80801BA8; break;
        case 2: goto L_80801B0C; break;
        case 3: goto L_808018D0; break;
        case 4: goto L_808018D0; break;
        case 5: goto L_808018D0; break;
        case 6: goto L_808018D0; break;
        case 7: goto L_808018D0; break;
        case 8: goto L_808018D0; break;
        case 9: goto L_808018D0; break;
        case 10: goto L_808018D0; break;
        case 11: goto L_808018D0; break;
        case 12: goto L_808018D0; break;
        case 13: goto L_808018D0; break;
        case 14: goto L_808018D0; break;
        case 15: goto L_80801E14; break;
        case 16: goto L_808018D0; break;
        case 17: goto L_808018D0; break;
        case 18: goto L_808018D0; break;
        case 19: goto L_808018D0; break;
        case 20: goto L_808018D0; break;
        case 21: goto L_808018D0; break;
        case 22: goto L_808018D0; break;
        case 23: goto L_808018D0; break;
        case 24: goto L_808018D0; break;
        case 25: goto L_808018D0; break;
        case 26: goto L_808018D0; break;
        case 27: goto L_808018D0; break;
        case 28: goto L_808018D0; break;
        case 29: goto L_808018D0; break;
        case 30: goto L_808018D0; break;
        case 31: goto L_808018D0; break;
        case 32: goto L_808018D0; break;
        case 33: goto L_808018D0; break;
        case 34: goto L_808018D0; break;
        case 35: goto L_808018D0; break;
        case 36: goto L_808018D8; break;
        case 37: goto L_808018D0; break;
        case 38: goto L_808018D0; break;
        case 39: goto L_808018D0; break;
        case 40: goto L_80801C24; break;
        case 41: goto L_808018D0; break;
        case 42: goto L_808018D0; break;
        case 43: goto L_80801DB4; break;
        default: switch_error(__func__, 0x808018B0, 0x80803F6C);
    }
    // 0x808018B4: nop

L_808018B8:
    // 0x808018B8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808018BC: beq         $a2, $at, L_80801C7C
    if (ctx->r6 == ctx->r1) {
        // 0x808018C0: addiu       $t3, $v1, -0x64
        ctx->r11 = ADD32(ctx->r3, -0X64);
            goto L_80801C7C;
    }
    // 0x808018C0: addiu       $t3, $v1, -0x64
    ctx->r11 = ADD32(ctx->r3, -0X64);
    // 0x808018C4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x808018C8: beq         $a2, $at, L_80801E28
    if (ctx->r6 == ctx->r1) {
        // 0x808018CC: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_80801E28;
    }
    // 0x808018CC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
L_808018D0:
    // 0x808018D0: b           L_80801E88
    // 0x808018D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801E88;
    // 0x808018D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808018D8:
    // 0x808018D8: lbu         $t7, 0x24($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X24);
    // 0x808018DC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808018E0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1692, 0X4608) << 16);
    // 0x808018E4: bne         $t7, $zero, L_80801904
    if (ctx->r15 != 0) {
        // 0x808018E8: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_80801904;
    }
    // 0x808018E8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x808018EC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1692, 0X45F8) << 16);
    // 0x808018F0: addiu       $a0, $a0, 0x45F8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1692, 0X45F8));
    // 0x808018F4: jal         0x80088090
    // 0x808018F8: lw          $a1, 0x38($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808018F8: lw          $a1, 0x38($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X38);
    after_1:
    // 0x808018FC: b           L_80801E88
    // 0x80801900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801E88;
    // 0x80801900: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801904:
    // 0x80801904: addiu       $a0, $a0, 0x4608
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1692, 0X4608));
    // 0x80801908: jal         0x80088090
    // 0x8080190C: lw          $a1, 0x38($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080190C: lw          $a1, 0x38($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X38);
    after_2:
    // 0x80801910: b           L_80801E88
    // 0x80801914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801E88;
    // 0x80801914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801918:
    // 0x80801918: lh          $v1, 0x30($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X30);
    // 0x8080191C: slti        $at, $v1, 0x10E7
    ctx->r1 = SIGNED(ctx->r3) < 0X10E7 ? 1 : 0;
    // 0x80801920: bne         $at, $zero, L_8080193C
    if (ctx->r1 != 0) {
        // 0x80801924: addiu       $t0, $v1, -0x10C5
        ctx->r8 = ADD32(ctx->r3, -0X10C5);
            goto L_8080193C;
    }
    // 0x80801924: addiu       $t0, $v1, -0x10C5
    ctx->r8 = ADD32(ctx->r3, -0X10C5);
    // 0x80801928: addiu       $at, $zero, 0x1102
    ctx->r1 = ADD32(0, 0X1102);
    // 0x8080192C: beql        $v1, $at, L_80801994
    if (ctx->r3 == ctx->r1) {
        // 0x80801930: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80801994;
    }
    goto skip_0;
    // 0x80801930: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801934: b           L_80801988
    // 0x80801938: nop

        goto L_80801988;
    // 0x80801938: nop

L_8080193C:
    // 0x8080193C: slti        $at, $v1, 0xCEC
    ctx->r1 = SIGNED(ctx->r3) < 0XCEC ? 1 : 0;
    // 0x80801940: bne         $at, $zero, L_80801964
    if (ctx->r1 != 0) {
        // 0x80801944: sltiu       $at, $t0, 0x22
        ctx->r1 = ctx->r8 < 0X22 ? 1 : 0;
            goto L_80801964;
    }
    // 0x80801944: sltiu       $at, $t0, 0x22
    ctx->r1 = ctx->r8 < 0X22 ? 1 : 0;
    // 0x80801948: beq         $at, $zero, L_80801988
    if (ctx->r1 == 0) {
        // 0x8080194C: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80801988;
    }
    // 0x8080194C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80801950: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X401C) << 16);
    // 0x80801954: addu        $at, $at, $t0
    gpr jr_addend_8080195C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80801958: lw          $t0, 0x401C($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X401C));
    // 0x8080195C: jr          $t0
    // 0x80801960: nop

    switch (jr_addend_8080195C >> 2) {
        case 0: goto L_80801990; break;
        case 1: goto L_80801988; break;
        case 2: goto L_80801988; break;
        case 3: goto L_80801990; break;
        case 4: goto L_80801990; break;
        case 5: goto L_80801988; break;
        case 6: goto L_80801988; break;
        case 7: goto L_80801988; break;
        case 8: goto L_80801988; break;
        case 9: goto L_80801988; break;
        case 10: goto L_80801988; break;
        case 11: goto L_80801988; break;
        case 12: goto L_80801988; break;
        case 13: goto L_80801988; break;
        case 14: goto L_80801988; break;
        case 15: goto L_80801988; break;
        case 16: goto L_80801988; break;
        case 17: goto L_80801988; break;
        case 18: goto L_80801988; break;
        case 19: goto L_80801988; break;
        case 20: goto L_80801988; break;
        case 21: goto L_80801988; break;
        case 22: goto L_80801988; break;
        case 23: goto L_80801988; break;
        case 24: goto L_80801988; break;
        case 25: goto L_80801988; break;
        case 26: goto L_80801988; break;
        case 27: goto L_80801988; break;
        case 28: goto L_80801988; break;
        case 29: goto L_80801978; break;
        case 30: goto L_80801978; break;
        case 31: goto L_80801978; break;
        case 32: goto L_80801990; break;
        case 33: goto L_80801990; break;
        default: switch_error(__func__, 0x8080195C, 0x8080401C);
    }
    // 0x80801960: nop

L_80801964:
    // 0x80801964: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80801968: beql        $v1, $at, L_80801994
    if (ctx->r3 == ctx->r1) {
        // 0x8080196C: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80801994;
    }
    goto skip_1;
    // 0x8080196C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80801970: b           L_80801988
    // 0x80801974: nop

        goto L_80801988;
    // 0x80801974: nop

L_80801978:
    // 0x80801978: jal         0x800D395C
    // 0x8080197C: nop

    func_800D395C(rdram, ctx);
        goto after_3;
    // 0x8080197C: nop

    after_3:
    // 0x80801980: bnel        $v0, $zero, L_80801994
    if (ctx->r2 != 0) {
        // 0x80801984: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80801994;
    }
    goto skip_2;
    // 0x80801984: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_2:
L_80801988:
    // 0x80801988: jal         0x808004B0
    // 0x8080198C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808004B0_chflysaucer(rdram, ctx);
        goto after_4;
    // 0x8080198C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
L_80801990:
    // 0x80801990: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80801994:
    // 0x80801994: lh          $v1, 0x30($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X30);
    // 0x80801998: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080199C: lbu         $t2, 0x26($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X26);
    // 0x808019A0: addiu       $t3, $v1, -0x10C8
    ctx->r11 = ADD32(ctx->r3, -0X10C8);
    // 0x808019A4: bne         $t2, $at, L_80801A54
    if (ctx->r10 != ctx->r1) {
        // 0x808019A8: slti        $at, $v1, 0xCEC
        ctx->r1 = SIGNED(ctx->r3) < 0XCEC ? 1 : 0;
            goto L_80801A54;
    }
    // 0x808019A8: slti        $at, $v1, 0xCEC
    ctx->r1 = SIGNED(ctx->r3) < 0XCEC ? 1 : 0;
    // 0x808019AC: bne         $at, $zero, L_808019D0
    if (ctx->r1 != 0) {
        // 0x808019B0: sltiu       $at, $t3, 0x1F
        ctx->r1 = ctx->r11 < 0X1F ? 1 : 0;
            goto L_808019D0;
    }
    // 0x808019B0: sltiu       $at, $t3, 0x1F
    ctx->r1 = ctx->r11 < 0X1F ? 1 : 0;
    // 0x808019B4: beq         $at, $zero, L_80801A38
    if (ctx->r1 == 0) {
        // 0x808019B8: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80801A38;
    }
    // 0x808019B8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x808019BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X40A4) << 16);
    // 0x808019C0: addu        $at, $at, $t3
    gpr jr_addend_808019C8 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x808019C4: lw          $t3, 0x40A4($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X40A4));
    // 0x808019C8: jr          $t3
    // 0x808019CC: nop

    switch (jr_addend_808019C8 >> 2) {
        case 0: goto L_80801AF8; break;
        case 1: goto L_80801AF8; break;
        case 2: goto L_80801A38; break;
        case 3: goto L_80801A38; break;
        case 4: goto L_80801A38; break;
        case 5: goto L_80801A38; break;
        case 6: goto L_80801A38; break;
        case 7: goto L_80801A38; break;
        case 8: goto L_80801A38; break;
        case 9: goto L_80801A38; break;
        case 10: goto L_80801A38; break;
        case 11: goto L_80801A38; break;
        case 12: goto L_80801A38; break;
        case 13: goto L_80801A38; break;
        case 14: goto L_80801A38; break;
        case 15: goto L_80801A38; break;
        case 16: goto L_80801A38; break;
        case 17: goto L_80801A38; break;
        case 18: goto L_80801A38; break;
        case 19: goto L_80801A38; break;
        case 20: goto L_80801A38; break;
        case 21: goto L_80801A38; break;
        case 22: goto L_80801A38; break;
        case 23: goto L_80801A38; break;
        case 24: goto L_80801A38; break;
        case 25: goto L_80801A38; break;
        case 26: goto L_80801A14; break;
        case 27: goto L_80801A14; break;
        case 28: goto L_80801A14; break;
        case 29: goto L_80801AF8; break;
        case 30: goto L_80801AF8; break;
        default: switch_error(__func__, 0x808019C8, 0x808040A4);
    }
    // 0x808019CC: nop

L_808019D0:
    // 0x808019D0: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x808019D4: bne         $v1, $at, L_80801A38
    if (ctx->r3 != ctx->r1) {
        // 0x808019D8: lh          $t4, 0x32($sp)
        ctx->r12 = MEM_H(ctx->r29, 0X32);
            goto L_80801A38;
    }
    // 0x808019D8: lh          $t4, 0x32($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X32);
    // 0x808019DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808019E0: bne         $t4, $at, L_80801A04
    if (ctx->r12 != ctx->r1) {
        // 0x808019E4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801A04;
    }
    // 0x808019E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808019E8: jal         0x8080003C
    // 0x808019EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080003C_chflysaucer(rdram, ctx);
        goto after_5;
    // 0x808019EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808019F0: addiu       $a0, $zero, 0x124
    ctx->r4 = ADD32(0, 0X124);
    // 0x808019F4: jal         0x80087A58
    // 0x808019F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808019F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x808019FC: b           L_80801AFC
    // 0x80801A00: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_80801AFC;
    // 0x80801A00: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_80801A04:
    // 0x80801A04: jal         0x80088180
    // 0x80801A08: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x80801A08: nop

    after_7:
    // 0x80801A0C: b           L_80801AFC
    // 0x80801A10: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_80801AFC;
    // 0x80801A10: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_80801A14:
    // 0x80801A14: jal         0x800D395C
    // 0x80801A18: nop

    func_800D395C(rdram, ctx);
        goto after_8;
    // 0x80801A18: nop

    after_8:
    // 0x80801A1C: beq         $v0, $zero, L_80801A38
    if (ctx->r2 == 0) {
        // 0x80801A20: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801A38;
    }
    // 0x80801A20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801A24: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80801A28: jal         0x8080105C
    // 0x80801A2C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_9;
    // 0x80801A2C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_9:
    // 0x80801A30: b           L_80801AFC
    // 0x80801A34: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_80801AFC;
    // 0x80801A34: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_80801A38:
    // 0x80801A38: jal         0x808005FC
    // 0x80801A3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808005FC_chflysaucer(rdram, ctx);
        goto after_10;
    // 0x80801A3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x80801A40: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801A44: jal         0x808012A4
    // 0x80801A48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_11;
    // 0x80801A48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80801A4C: b           L_80801AFC
    // 0x80801A50: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_80801AFC;
    // 0x80801A50: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_80801A54:
    // 0x80801A54: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80801A58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801A5C: lh          $v1, 0x30($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X30);
    // 0x80801A60: lhu         $t5, 0x72($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X72);
    // 0x80801A64: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x80801A68: bne         $t6, $at, L_80801AF8
    if (ctx->r14 != ctx->r1) {
        // 0x80801A6C: addiu       $at, $zero, 0x10C5
        ctx->r1 = ADD32(0, 0X10C5);
            goto L_80801AF8;
    }
    // 0x80801A6C: addiu       $at, $zero, 0x10C5
    ctx->r1 = ADD32(0, 0X10C5);
    // 0x80801A70: beq         $v1, $at, L_80801AA4
    if (ctx->r3 == ctx->r1) {
        // 0x80801A74: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_80801AA4;
    }
    // 0x80801A74: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80801A78: addiu       $at, $zero, 0x10E1
    ctx->r1 = ADD32(0, 0X10E1);
    // 0x80801A7C: beq         $v1, $at, L_80801AF0
    if (ctx->r3 == ctx->r1) {
        // 0x80801A80: addiu       $at, $zero, 0x1102
        ctx->r1 = ADD32(0, 0X1102);
            goto L_80801AF0;
    }
    // 0x80801A80: addiu       $at, $zero, 0x1102
    ctx->r1 = ADD32(0, 0X1102);
    // 0x80801A84: beq         $v1, $at, L_80801AA4
    if (ctx->r3 == ctx->r1) {
        // 0x80801A88: addiu       $at, $zero, 0x1103
        ctx->r1 = ADD32(0, 0X1103);
            goto L_80801AA4;
    }
    // 0x80801A88: addiu       $at, $zero, 0x1103
    ctx->r1 = ADD32(0, 0X1103);
    // 0x80801A8C: beq         $v1, $at, L_80801AE0
    if (ctx->r3 == ctx->r1) {
        // 0x80801A90: addiu       $at, $zero, 0x1104
        ctx->r1 = ADD32(0, 0X1104);
            goto L_80801AE0;
    }
    // 0x80801A90: addiu       $at, $zero, 0x1104
    ctx->r1 = ADD32(0, 0X1104);
    // 0x80801A94: beq         $v1, $at, L_80801AE0
    if (ctx->r3 == ctx->r1) {
        // 0x80801A98: nop
    
            goto L_80801AE0;
    }
    // 0x80801A98: nop

    // 0x80801A9C: b           L_80801AFC
    // 0x80801AA0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_80801AFC;
    // 0x80801AA0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_80801AA4:
    // 0x80801AA4: jal         0x800D0A9C
    // 0x80801AA8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_12;
    // 0x80801AA8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x80801AAC: bne         $v0, $zero, L_80801ACC
    if (ctx->r2 != 0) {
        // 0x80801AB0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801ACC;
    }
    // 0x80801AB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801AB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801AB8: addiu       $a1, $zero, 0x1103
    ctx->r5 = ADD32(0, 0X1103);
    // 0x80801ABC: jal         0x8080105C
    // 0x80801AC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_13;
    // 0x80801AC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80801AC4: b           L_80801AD8
    // 0x80801AC8: nop

        goto L_80801AD8;
    // 0x80801AC8: nop

L_80801ACC:
    // 0x80801ACC: addiu       $a1, $zero, 0x1104
    ctx->r5 = ADD32(0, 0X1104);
    // 0x80801AD0: jal         0x8080105C
    // 0x80801AD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_14;
    // 0x80801AD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
L_80801AD8:
    // 0x80801AD8: b           L_80801AFC
    // 0x80801ADC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_80801AFC;
    // 0x80801ADC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_80801AE0:
    // 0x80801AE0: jal         0x808004F0
    // 0x80801AE4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808004F0_chflysaucer(rdram, ctx);
        goto after_15;
    // 0x80801AE4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_15:
    // 0x80801AE8: b           L_80801AFC
    // 0x80801AEC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_80801AFC;
    // 0x80801AEC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_80801AF0:
    // 0x80801AF0: jal         0x808004F0
    // 0x80801AF4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808004F0_chflysaucer(rdram, ctx);
        goto after_16;
    // 0x80801AF4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_16:
L_80801AF8:
    // 0x80801AF8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_80801AFC:
    // 0x80801AFC: lbu         $t7, 0x74($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X74);
    // 0x80801B00: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x80801B04: b           L_80801E84
    // 0x80801B08: sb          $t8, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r24;
        goto L_80801E84;
    // 0x80801B08: sb          $t8, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r24;
L_80801B0C:
    // 0x80801B0C: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80801B10: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x80801B14: addiu       $at, $zero, 0x10C5
    ctx->r1 = ADD32(0, 0X10C5);
    // 0x80801B18: beq         $v1, $at, L_80801B50
    if (ctx->r3 == ctx->r1) {
        // 0x80801B1C: addiu       $at, $zero, 0x10E2
        ctx->r1 = ADD32(0, 0X10E2);
            goto L_80801B50;
    }
    // 0x80801B1C: addiu       $at, $zero, 0x10E2
    ctx->r1 = ADD32(0, 0X10E2);
    // 0x80801B20: beq         $v1, $at, L_80801B98
    if (ctx->r3 == ctx->r1) {
        // 0x80801B24: addiu       $at, $zero, 0x10E3
        ctx->r1 = ADD32(0, 0X10E3);
            goto L_80801B98;
    }
    // 0x80801B24: addiu       $at, $zero, 0x10E3
    ctx->r1 = ADD32(0, 0X10E3);
    // 0x80801B28: beq         $v1, $at, L_80801B98
    if (ctx->r3 == ctx->r1) {
        // 0x80801B2C: addiu       $at, $zero, 0x10E4
        ctx->r1 = ADD32(0, 0X10E4);
            goto L_80801B98;
    }
    // 0x80801B2C: addiu       $at, $zero, 0x10E4
    ctx->r1 = ADD32(0, 0X10E4);
    // 0x80801B30: beq         $v1, $at, L_80801B88
    if (ctx->r3 == ctx->r1) {
        // 0x80801B34: addiu       $at, $zero, 0x1103
        ctx->r1 = ADD32(0, 0X1103);
            goto L_80801B88;
    }
    // 0x80801B34: addiu       $at, $zero, 0x1103
    ctx->r1 = ADD32(0, 0X1103);
    // 0x80801B38: beq         $v1, $at, L_80801B50
    if (ctx->r3 == ctx->r1) {
        // 0x80801B3C: addiu       $at, $zero, 0x1104
        ctx->r1 = ADD32(0, 0X1104);
            goto L_80801B50;
    }
    // 0x80801B3C: addiu       $at, $zero, 0x1104
    ctx->r1 = ADD32(0, 0X1104);
    // 0x80801B40: beq         $v1, $at, L_80801B80
    if (ctx->r3 == ctx->r1) {
        // 0x80801B44: nop
    
            goto L_80801B80;
    }
    // 0x80801B44: nop

    // 0x80801B48: b           L_80801E88
    // 0x80801B4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801E88;
    // 0x80801B4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B50:
    // 0x80801B50: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x80801B54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801B58: beq         $v1, $zero, L_80801B70
    if (ctx->r3 == 0) {
        // 0x80801B5C: nop
    
            goto L_80801B70;
    }
    // 0x80801B5C: nop

    // 0x80801B60: beq         $v1, $at, L_80801B78
    if (ctx->r3 == ctx->r1) {
        // 0x80801B64: nop
    
            goto L_80801B78;
    }
    // 0x80801B64: nop

    // 0x80801B68: b           L_80801E88
    // 0x80801B6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801E88;
    // 0x80801B6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B70:
    // 0x80801B70: b           L_80801E88
    // 0x80801B74: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
        goto L_80801E88;
    // 0x80801B74: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
L_80801B78:
    // 0x80801B78: b           L_80801E88
    // 0x80801B7C: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
        goto L_80801E88;
    // 0x80801B7C: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
L_80801B80:
    // 0x80801B80: b           L_80801E88
    // 0x80801B84: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
        goto L_80801E88;
    // 0x80801B84: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
L_80801B88:
    // 0x80801B88: jal         0x800D211C
    // 0x80801B8C: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800D211C(rdram, ctx);
        goto after_17;
    // 0x80801B8C: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_17:
    // 0x80801B90: b           L_80801E8C
    // 0x80801B94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801E8C;
    // 0x80801B94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801B98:
    // 0x80801B98: jal         0x800D211C
    // 0x80801B9C: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800D211C(rdram, ctx);
        goto after_18;
    // 0x80801B9C: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_18:
    // 0x80801BA0: b           L_80801E8C
    // 0x80801BA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801E8C;
    // 0x80801BA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801BA8:
    // 0x80801BA8: lh          $v1, 0x30($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X30);
    // 0x80801BAC: addiu       $at, $zero, 0x10C8
    ctx->r1 = ADD32(0, 0X10C8);
    // 0x80801BB0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80801BB4: beq         $v1, $at, L_80801BDC
    if (ctx->r3 == ctx->r1) {
        // 0x80801BB8: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_80801BDC;
    }
    // 0x80801BB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80801BBC: addiu       $at, $zero, 0x10C9
    ctx->r1 = ADD32(0, 0X10C9);
    // 0x80801BC0: beq         $v1, $at, L_80801BFC
    if (ctx->r3 == ctx->r1) {
        // 0x80801BC4: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80801BFC;
    }
    // 0x80801BC4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80801BC8: addiu       $at, $zero, 0x10E5
    ctx->r1 = ADD32(0, 0X10E5);
    // 0x80801BCC: beq         $v1, $at, L_80801BFC
    if (ctx->r3 == ctx->r1) {
        // 0x80801BD0: addiu       $at, $zero, 0x10E6
        ctx->r1 = ADD32(0, 0X10E6);
            goto L_80801BFC;
    }
    // 0x80801BD0: addiu       $at, $zero, 0x10E6
    ctx->r1 = ADD32(0, 0X10E6);
    // 0x80801BD4: bnel        $v1, $at, L_80801E88
    if (ctx->r3 != ctx->r1) {
        // 0x80801BD8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801E88;
    }
    goto skip_3;
    // 0x80801BD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
L_80801BDC:
    // 0x80801BDC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80801BE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801BE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801BE8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801BEC: jal         0x800D1000
    // 0x80801BF0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800D1000(rdram, ctx);
        goto after_19;
    // 0x80801BF0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_19:
    // 0x80801BF4: b           L_80801E88
    // 0x80801BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801E88;
    // 0x80801BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801BFC:
    // 0x80801BFC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80801C00: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1692, 0X4618) << 16);
    // 0x80801C04: addiu       $a2, $a2, 0x4618
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1692, 0X4618));
    // 0x80801C08: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80801C0C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80801C10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801C14: jal         0x800D1000
    // 0x80801C18: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800D1000(rdram, ctx);
        goto after_20;
    // 0x80801C18: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_20:
    // 0x80801C1C: b           L_80801E88
    // 0x80801C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801E88;
    // 0x80801C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801C24:
    // 0x80801C24: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80801C28: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80801C2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801C30: beq         $v1, $at, L_80801C60
    if (ctx->r3 == ctx->r1) {
        // 0x80801C34: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_80801C60;
    }
    // 0x80801C34: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x80801C38: beq         $v1, $at, L_80801C60
    if (ctx->r3 == ctx->r1) {
        // 0x80801C3C: addiu       $at, $zero, 0x66
        ctx->r1 = ADD32(0, 0X66);
            goto L_80801C60;
    }
    // 0x80801C3C: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80801C40: beq         $v1, $at, L_80801C60
    if (ctx->r3 == ctx->r1) {
        // 0x80801C44: addiu       $at, $zero, 0x68
        ctx->r1 = ADD32(0, 0X68);
            goto L_80801C60;
    }
    // 0x80801C44: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80801C48: beq         $v1, $at, L_80801C60
    if (ctx->r3 == ctx->r1) {
        // 0x80801C4C: addiu       $at, $zero, 0x6A
        ctx->r1 = ADD32(0, 0X6A);
            goto L_80801C60;
    }
    // 0x80801C4C: addiu       $at, $zero, 0x6A
    ctx->r1 = ADD32(0, 0X6A);
    // 0x80801C50: beq         $v1, $at, L_80801C60
    if (ctx->r3 == ctx->r1) {
        // 0x80801C54: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_80801C60;
    }
    // 0x80801C54: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x80801C58: bnel        $v1, $at, L_80801E88
    if (ctx->r3 != ctx->r1) {
        // 0x80801C5C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801E88;
    }
    goto skip_4;
    // 0x80801C5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
L_80801C60:
    // 0x80801C60: jal         0x808009DC
    // 0x80801C64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808009DC_chflysaucer(rdram, ctx);
        goto after_21;
    // 0x80801C64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x80801C68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801C6C: jal         0x808012A4
    // 0x80801C70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_22;
    // 0x80801C70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80801C74: b           L_80801E88
    // 0x80801C78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801E88;
    // 0x80801C78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801C7C:
    // 0x80801C7C: slti        $at, $v1, 0x1C
    ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
    // 0x80801C80: bne         $at, $zero, L_80801CA4
    if (ctx->r1 != 0) {
        // 0x80801C84: sltiu       $at, $t3, 0xF
        ctx->r1 = ctx->r11 < 0XF ? 1 : 0;
            goto L_80801CA4;
    }
    // 0x80801C84: sltiu       $at, $t3, 0xF
    ctx->r1 = ctx->r11 < 0XF ? 1 : 0;
    // 0x80801C88: beq         $at, $zero, L_80801DAC
    if (ctx->r1 == 0) {
        // 0x80801C8C: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80801DAC;
    }
    // 0x80801C8C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80801C90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4120) << 16);
    // 0x80801C94: addu        $at, $at, $t3
    gpr jr_addend_80801C9C = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80801C98: lw          $t3, 0x4120($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4120));
    // 0x80801C9C: jr          $t3
    // 0x80801CA0: nop

    switch (jr_addend_80801C9C >> 2) {
        case 0: goto L_80801CB8; break;
        case 1: goto L_80801DAC; break;
        case 2: goto L_80801DAC; break;
        case 3: goto L_80801DAC; break;
        case 4: goto L_80801DAC; break;
        case 5: goto L_80801DAC; break;
        case 6: goto L_80801CB8; break;
        case 7: goto L_80801DAC; break;
        case 8: goto L_80801DAC; break;
        case 9: goto L_80801DAC; break;
        case 10: goto L_80801CB8; break;
        case 11: goto L_80801DAC; break;
        case 12: goto L_80801CCC; break;
        case 13: goto L_80801DAC; break;
        case 14: goto L_80801D38; break;
        default: switch_error(__func__, 0x80801C9C, 0x80804120);
    }
    // 0x80801CA0: nop

L_80801CA4:
    // 0x80801CA4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80801CA8: beq         $v1, $at, L_80801CB8
    if (ctx->r3 == ctx->r1) {
        // 0x80801CAC: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_80801CB8;
    }
    // 0x80801CAC: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80801CB0: bne         $v1, $at, L_80801DAC
    if (ctx->r3 != ctx->r1) {
        // 0x80801CB4: nop
    
            goto L_80801DAC;
    }
    // 0x80801CB4: nop

L_80801CB8:
    // 0x80801CB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801CBC: jal         0x80108BD4
    // 0x80801CC0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80108BD4(rdram, ctx);
        goto after_23;
    // 0x80801CC0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_23:
    // 0x80801CC4: b           L_80801E88
    // 0x80801CC8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801E88;
    // 0x80801CC8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801CCC:
    // 0x80801CCC: lbu         $v1, 0x25($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X25);
    // 0x80801CD0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80801CD4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80801CD8: beq         $v1, $at, L_80801CFC
    if (ctx->r3 == ctx->r1) {
        // 0x80801CDC: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80801CFC;
    }
    // 0x80801CDC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80801CE0: bne         $v1, $at, L_80801DAC
    if (ctx->r3 != ctx->r1) {
        // 0x80801CE4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801DAC;
    }
    // 0x80801CE4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801CE8: addiu       $a1, $zero, 0x10E6
    ctx->r5 = ADD32(0, 0X10E6);
    // 0x80801CEC: jal         0x8080105C
    // 0x80801CF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_24;
    // 0x80801CF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_24:
    // 0x80801CF4: b           L_80801E88
    // 0x80801CF8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801E88;
    // 0x80801CF8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80801CFC:
    // 0x80801CFC: jal         0x800D0A9C
    // 0x80801D00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_25;
    // 0x80801D00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x80801D04: beq         $v0, $zero, L_80801D24
    if (ctx->r2 == 0) {
        // 0x80801D08: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801D24;
    }
    // 0x80801D08: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801D0C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801D10: addiu       $a1, $zero, 0x10E8
    ctx->r5 = ADD32(0, 0X10E8);
    // 0x80801D14: jal         0x8080105C
    // 0x80801D18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_26;
    // 0x80801D18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_26:
    // 0x80801D1C: b           L_80801E88
    // 0x80801D20: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801E88;
    // 0x80801D20: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80801D24:
    // 0x80801D24: addiu       $a1, $zero, 0x10E7
    ctx->r5 = ADD32(0, 0X10E7);
    // 0x80801D28: jal         0x8080105C
    // 0x80801D2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_27;
    // 0x80801D2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_27:
    // 0x80801D30: b           L_80801E88
    // 0x80801D34: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801E88;
    // 0x80801D34: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80801D38:
    // 0x80801D38: lbu         $v1, 0x25($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X25);
    // 0x80801D3C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80801D40: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80801D44: beq         $v1, $at, L_80801D5C
    if (ctx->r3 == ctx->r1) {
        // 0x80801D48: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80801D5C;
    }
    // 0x80801D48: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80801D4C: beq         $v1, $at, L_80801D98
    if (ctx->r3 == ctx->r1) {
        // 0x80801D50: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801D98;
    }
    // 0x80801D50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801D54: b           L_80801E88
    // 0x80801D58: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801E88;
    // 0x80801D58: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801D5C:
    // 0x80801D5C: jal         0x800D0A9C
    // 0x80801D60: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_28;
    // 0x80801D60: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_28:
    // 0x80801D64: beq         $v0, $zero, L_80801D84
    if (ctx->r2 == 0) {
        // 0x80801D68: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801D84;
    }
    // 0x80801D68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801D6C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801D70: addiu       $a1, $zero, 0x10E8
    ctx->r5 = ADD32(0, 0X10E8);
    // 0x80801D74: jal         0x8080105C
    // 0x80801D78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_29;
    // 0x80801D78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_29:
    // 0x80801D7C: b           L_80801E88
    // 0x80801D80: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801E88;
    // 0x80801D80: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80801D84:
    // 0x80801D84: addiu       $a1, $zero, 0x10E7
    ctx->r5 = ADD32(0, 0X10E7);
    // 0x80801D88: jal         0x8080105C
    // 0x80801D8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_30;
    // 0x80801D8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_30:
    // 0x80801D90: b           L_80801E88
    // 0x80801D94: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801E88;
    // 0x80801D94: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80801D98:
    // 0x80801D98: addiu       $a1, $zero, 0x10E8
    ctx->r5 = ADD32(0, 0X10E8);
    // 0x80801D9C: jal         0x8080105C
    // 0x80801DA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_31;
    // 0x80801DA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_31:
    // 0x80801DA4: b           L_80801E88
    // 0x80801DA8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801E88;
    // 0x80801DA8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80801DAC:
    // 0x80801DAC: b           L_80801E88
    // 0x80801DB0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801E88;
    // 0x80801DB0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801DB4:
    // 0x80801DB4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80801DB8: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80801DBC: beq         $v1, $at, L_80801DE4
    if (ctx->r3 == ctx->r1) {
        // 0x80801DC0: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_80801DE4;
    }
    // 0x80801DC0: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80801DC4: beq         $v1, $at, L_80801DE4
    if (ctx->r3 == ctx->r1) {
        // 0x80801DC8: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_80801DE4;
    }
    // 0x80801DC8: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80801DCC: beq         $v1, $at, L_80801DE4
    if (ctx->r3 == ctx->r1) {
        // 0x80801DD0: addiu       $at, $zero, 0x6A
        ctx->r1 = ADD32(0, 0X6A);
            goto L_80801DE4;
    }
    // 0x80801DD0: addiu       $at, $zero, 0x6A
    ctx->r1 = ADD32(0, 0X6A);
    // 0x80801DD4: beq         $v1, $at, L_80801DE4
    if (ctx->r3 == ctx->r1) {
        // 0x80801DD8: addiu       $at, $zero, 0x6E
        ctx->r1 = ADD32(0, 0X6E);
            goto L_80801DE4;
    }
    // 0x80801DD8: addiu       $at, $zero, 0x6E
    ctx->r1 = ADD32(0, 0X6E);
    // 0x80801DDC: bne         $v1, $at, L_80801E0C
    if (ctx->r3 != ctx->r1) {
        // 0x80801DE0: nop
    
            goto L_80801E0C;
    }
    // 0x80801DE0: nop

L_80801DE4:
    // 0x80801DE4: jal         0x80085710
    // 0x80801DE8: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_32;
    // 0x80801DE8: nop

    after_32:
    // 0x80801DEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801DF0: jal         0x808012A4
    // 0x80801DF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_33;
    // 0x80801DF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_33:
    // 0x80801DF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801DFC: jal         0x808009DC
    // 0x80801E00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808009DC_chflysaucer(rdram, ctx);
        goto after_34;
    // 0x80801E00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_34:
    // 0x80801E04: b           L_80801E88
    // 0x80801E08: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80801E88;
    // 0x80801E08: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80801E0C:
    // 0x80801E0C: b           L_80801E88
    // 0x80801E10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80801E88;
    // 0x80801E10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801E14:
    // 0x80801E14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801E18: jal         0x808001B4
    // 0x80801E1C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_808001B4_chflysaucer(rdram, ctx);
        goto after_35;
    // 0x80801E1C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_35:
    // 0x80801E20: b           L_80801E88
    // 0x80801E24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801E88;
    // 0x80801E24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801E28:
    // 0x80801E28: sra         $t4, $v1, 16
    ctx->r12 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80801E2C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80801E30: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80801E34: beq         $t5, $at, L_80801E68
    if (ctx->r13 == ctx->r1) {
        // 0x80801E38: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_80801E68;
    }
    // 0x80801E38: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80801E3C: bnel        $t5, $at, L_80801E88
    if (ctx->r13 != ctx->r1) {
        // 0x80801E40: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801E88;
    }
    goto skip_5;
    // 0x80801E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_5:
    // 0x80801E44: jal         0x80101080
    // 0x80801E48: nop

    func_80101080(rdram, ctx);
        goto after_36;
    // 0x80801E48: nop

    after_36:
    // 0x80801E4C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801E50: addiu       $a1, $zero, 0x72
    ctx->r5 = ADD32(0, 0X72);
    // 0x80801E54: addiu       $a2, $zero, 0x418
    ctx->r6 = ADD32(0, 0X418);
    // 0x80801E58: jal         0x80800424
    // 0x80801E5C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80800424_chflysaucer(rdram, ctx);
        goto after_37;
    // 0x80801E5C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_37:
    // 0x80801E60: b           L_80801E88
    // 0x80801E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801E88;
    // 0x80801E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801E68:
    // 0x80801E68: jal         0x80101080
    // 0x80801E6C: nop

    func_80101080(rdram, ctx);
        goto after_38;
    // 0x80801E6C: nop

    after_38:
    // 0x80801E70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801E74: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x80801E78: addiu       $a2, $zero, 0x418
    ctx->r6 = ADD32(0, 0X418);
    // 0x80801E7C: jal         0x80800424
    // 0x80801E80: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80800424_chflysaucer(rdram, ctx);
        goto after_39;
    // 0x80801E80: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_39:
L_80801E84:
    // 0x80801E84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801E88:
    // 0x80801E88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801E8C:
    // 0x80801E8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801E90: jr          $ra
    // 0x80801E94: nop

    return;
    // 0x80801E94: nop

;}
RECOMP_FUNC void func_8080115C_chglowbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080115C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801160: addiu       $at, $zero, 0x4D
    ctx->r1 = ADD32(0, 0X4D);
    // 0x80801164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801168: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080116C: bne         $a1, $at, L_80801184
    if (ctx->r5 != ctx->r1) {
        // 0x80801170: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801184;
    }
    // 0x80801170: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801174: jal         0x800FFA88
    // 0x80801178: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_0;
    // 0x80801178: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8080117C: b           L_80801188
    // 0x80801180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801188;
    // 0x80801180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801184:
    // 0x80801184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801188:
    // 0x80801188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080118C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801190: jr          $ra
    // 0x80801194: nop

    return;
    // 0x80801194: nop

;}
RECOMP_FUNC void func_8080044C_chstarspinnerctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080044C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800454: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800458: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x8080045C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800460: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800464: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800468: bgez        $t8, L_80800478
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080046C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800478;
    }
    // 0x8080046C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800470: b           L_80800478
    // 0x80800474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800478;
    // 0x80800474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800478:
    // 0x80800478: jal         0x800DF744
    // 0x8080047C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x8080047C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800480: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800484: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080048C: lw          $t9, 0x64($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X64);
    // 0x80800490: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x80800494: bgez        $t1, L_808004A4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800498: nop
    
            goto L_808004A4;
    }
    // 0x80800498: nop

    // 0x8080049C: b           L_808004A4
    // 0x808004A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_808004A4;
    // 0x808004A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808004A4:
    // 0x808004A4: jal         0x800DF744
    // 0x808004A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x808004A8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x808004AC: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x808004B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004B4: jal         0x80101808
    // 0x808004B8: addiu       $a1, $a1, 0x15D0
    ctx->r5 = ADD32(ctx->r5, 0X15D0);
    func_80101808(rdram, ctx);
        goto after_2;
    // 0x808004B8: addiu       $a1, $a1, 0x15D0
    ctx->r5 = ADD32(ctx->r5, 0X15D0);
    after_2:
    // 0x808004BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004C4: jr          $ra
    // 0x808004C8: nop

    return;
    // 0x808004C8: nop

;}
RECOMP_FUNC void heap_update_empty_block(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A6EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A6F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A6F4: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8001A6F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A6FC: lbu         $t6, 0xF($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF);
    // 0x8001A700: srl         $t7, $t6, 6
    ctx->r15 = S32(U32(ctx->r14) >> 6);
    // 0x8001A704: bnel        $t7, $zero, L_8001A73C
    if (ctx->r15 != 0) {
        // 0x8001A708: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8001A73C;
    }
    goto skip_0;
    // 0x8001A708: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8001A70C: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x8001A710: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x8001A714: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8001A718: sw          $t8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r24;
    // 0x8001A71C: lw          $t1, 0x10($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X10);
    // 0x8001A720: lw          $t0, 0x14($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X14);
    // 0x8001A724: sw          $t0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r8;
    // 0x8001A728: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x8001A72C: sw          $a0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r4;
    // 0x8001A730: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x8001A734: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8001A738: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_8001A73C:
    // 0x8001A73C: lbu         $t4, 0xF($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XF);
    // 0x8001A740: srl         $t5, $t4, 6
    ctx->r13 = S32(U32(ctx->r12) >> 6);
    // 0x8001A744: bne         $t5, $zero, L_8001A780
    if (ctx->r13 != 0) {
        // 0x8001A748: nop
    
            goto L_8001A780;
    }
    // 0x8001A748: nop

    // 0x8001A74C: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x8001A750: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x8001A754: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001A758: sw          $t6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r14;
    // 0x8001A75C: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
    // 0x8001A760: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x8001A764: sw          $t8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r24;
    // 0x8001A768: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x8001A76C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8001A770: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8001A774: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8001A778: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8001A77C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
L_8001A780:
    // 0x8001A780: beq         $a1, $zero, L_8001A798
    if (ctx->r5 == 0) {
        // 0x8001A784: nop
    
            goto L_8001A798;
    }
    // 0x8001A784: nop

    // 0x8001A788: jal         0x8001AF14
    // 0x8001A78C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    heap_merge_free_block(rdram, ctx);
        goto after_0;
    // 0x8001A78C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8001A790: b           L_8001A7A4
    // 0x8001A794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001A7A4;
    // 0x8001A794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001A798:
    // 0x8001A798: jal         0x8001AF14
    // 0x8001A79C: nop

    heap_merge_free_block(rdram, ctx);
        goto after_1;
    // 0x8001A79C: nop

    after_1:
    // 0x8001A7A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001A7A4:
    // 0x8001A7A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A7A8: jr          $ra
    // 0x8001A7AC: nop

    return;
    // 0x8001A7AC: nop

;}
RECOMP_FUNC void func_808000F0_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000FC: jal         0x8009EAE8
    // 0x80800100: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8009EAE8(rdram, ctx);
        goto after_0;
    // 0x80800100: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800104: jal         0x8080008C
    // 0x80800108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080008C_bsride(rdram, ctx);
        goto after_1;
    // 0x80800108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080010C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800114: jr          $ra
    // 0x80800118: nop

    return;
    // 0x80800118: nop

;}
RECOMP_FUNC void bsrest_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005C4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808005C8: jal         0x80084698
    // 0x808005CC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    _badata_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808005CC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x808005D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808005D8: jal         0x8080020C
    // 0x808005DC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    static_344_8080020C(rdram, ctx);
        goto after_1;
    // 0x808005DC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808005E0: jal         0x80800080
    // 0x808005E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    static_344_80800080(rdram, ctx);
        goto after_2;
    // 0x808005E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808005E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005F0: jr          $ra
    // 0x808005F4: nop

    return;
    // 0x808005F4: nop

;}
RECOMP_FUNC void chjadestatue_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2180, 0X310) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x310
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2180, 0X310));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x310
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2180, 0X310));
;}
RECOMP_FUNC void _gccubesearch_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800882F0: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x800882F0);
    return;
    // 0x800882F4: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_80801B04_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B04: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801B08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801B10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801B14: jal         0x80100094
    // 0x80801B18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801B18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801B1C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80801B20: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801B24: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801B28: jal         0x80102D78
    // 0x80801B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x80801B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801B30: jal         0x800D8FF8
    // 0x80801B34: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80801B34: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x80801B38: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80801B3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801B40: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80801B44: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801B48: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801B4C: lwc1        $f14, 0x40($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X40);
    // 0x80801B50: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80801B54: jal         0x800F15F8
    // 0x80801B58: nop

    func_800F15F8(rdram, ctx);
        goto after_3;
    // 0x80801B58: nop

    after_3:
    // 0x80801B5C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80801B60: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80801B64: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B6C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x80801B70: jal         0x80102BF8
    // 0x80801B74: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    func_80102BF8(rdram, ctx);
        goto after_4;
    // 0x80801B74: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    after_4:
    // 0x80801B78: jal         0x80101F24
    // 0x80801B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_5;
    // 0x80801B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801B80: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(832, 0X2F68) << 16);
    // 0x80801B84: addiu       $a1, $a1, 0x2F68
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(832, 0X2F68));
    // 0x80801B88: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801B8C: jal         0x800F3780
    // 0x80801B90: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_800F3780(rdram, ctx);
        goto after_6;
    // 0x80801B90: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_6:
    // 0x80801B94: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B9C: jal         0x8010C3A8
    // 0x80801BA0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8010C3A8(rdram, ctx);
        goto after_7;
    // 0x80801BA0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
    // 0x80801BA4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801BA8: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x80801BAC: jal         0x800F0064
    // 0x80801BB0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800F0064(rdram, ctx);
        goto after_8;
    // 0x80801BB0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80801BB4: beql        $v0, $zero, L_80801C6C
    if (ctx->r2 == 0) {
        // 0x80801BB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801C6C;
    }
    goto skip_0;
    // 0x80801BB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801BBC: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80801BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BC4: lbu         $t7, 0x497($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X497);
    // 0x80801BC8: beql        $t7, $zero, L_80801C10
    if (ctx->r15 == 0) {
        // 0x80801BCC: lbu         $t9, 0x493($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X493);
            goto L_80801C10;
    }
    goto skip_1;
    // 0x80801BCC: lbu         $t9, 0x493($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X493);
    skip_1:
    // 0x80801BD0: jal         0x80800F84
    // 0x80801BD4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800F84_chinflatableboss(rdram, ctx);
        goto after_9;
    // 0x80801BD4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_9:
    // 0x80801BD8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801BDC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801BE0: jal         0x800EE7F8
    // 0x80801BE4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80801BE4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_10:
    // 0x80801BE8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801BEC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801BF0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80801BF4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80801BF8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801BFC: jal         0x800DC178
    // 0x80801C00: sb          $zero, 0x497($t8)
    MEM_B(0X497, ctx->r24) = 0;
    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80801C00: sb          $zero, 0x497($t8)
    MEM_B(0X497, ctx->r24) = 0;
    after_11:
    // 0x80801C04: b           L_80801C50
    // 0x80801C08: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80801C50;
    // 0x80801C08: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80801C0C: lbu         $t9, 0x493($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X493);
L_80801C10:
    // 0x80801C10: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80801C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C18: bne         $t9, $zero, L_80801C48
    if (ctx->r25 != 0) {
        // 0x80801C1C: nop
    
            goto L_80801C48;
    }
    // 0x80801C1C: nop

    // 0x80801C20: jal         0x80800F84
    // 0x80801C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F84_chinflatableboss(rdram, ctx);
        goto after_12;
    // 0x80801C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801C28: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80801C2C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801C30: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80801C34: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801C38: jal         0x800DC178
    // 0x80801C3C: nop

    func_800DC178(rdram, ctx);
        goto after_13;
    // 0x80801C3C: nop

    after_13:
    // 0x80801C40: b           L_80801C50
    // 0x80801C44: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80801C50;
    // 0x80801C44: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80801C48:
    // 0x80801C48: jal         0x80800F84
    // 0x80801C4C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800F84_chinflatableboss(rdram, ctx);
        goto after_14;
    // 0x80801C4C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_14:
L_80801C50:
    // 0x80801C50: jal         0x80104248
    // 0x80801C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_15;
    // 0x80801C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80801C58: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80801C5C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801C60: jal         0x8008B1C8
    // 0x80801C64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_16;
    // 0x80801C64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_16:
    // 0x80801C68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801C6C:
    // 0x80801C6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801C70: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801C74: jr          $ra
    // 0x80801C78: nop

    return;
    // 0x80801C78: nop

;}
RECOMP_FUNC void func_80801634_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801634: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080163C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801640: jal         0x800839E8
    // 0x80801644: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80801644: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80801648: beq         $v0, $zero, L_80801654
    if (ctx->r2 == 0) {
        // 0x8080164C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80801654;
    }
    // 0x8080164C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801650: addiu       $a1, $zero, 0x165
    ctx->r5 = ADD32(0, 0X165);
L_80801654:
    // 0x80801654: jal         0x8009E5C8
    // 0x80801658: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x80801658: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080165C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801660: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801664: jr          $ra
    // 0x80801668: nop

    return;
    // 0x80801668: nop

;}
RECOMP_FUNC void _bsmum_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083848: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083848);
    return;
    // 0x8008384C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void chfirefx_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080009C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x808000A0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000A4: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x808000A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000AC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808000B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808000B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000B8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808000BC: addiu       $a2, $t6, 0x20
    ctx->r6 = ADD32(ctx->r14, 0X20);
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000C4: jal         0x80100074
    // 0x808000C8: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x808000C8: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x808000CC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808000D0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808000D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000D8: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808000DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808000E0: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x808000E4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808000E8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808000EC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808000F0: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x808000F4: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x808000F8: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x808000FC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80800100: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80800104: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800108: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x8080010C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80800110: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x80800114: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x80800118: andi        $t5, $v1, 0x8
    ctx->r13 = ctx->r3 & 0X8;
    // 0x8080011C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80800120: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
    // 0x80800124: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x80800128: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8080012C: beq         $t2, $zero, L_8080017C
    if (ctx->r10 == 0) {
        // 0x80800130: sh          $t0, 0x12($v0)
        MEM_H(0X12, ctx->r2) = ctx->r8;
            goto L_8080017C;
    }
    // 0x80800130: sh          $t0, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r8;
    // 0x80800134: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800138: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080013C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800140: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800144: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80800148: nop

    // 0x8080014C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800150: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80800154: nop

    // 0x80800158: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8080015C: bne         $t2, $zero, L_80800174
    if (ctx->r10 != 0) {
        // 0x80800160: nop
    
            goto L_80800174;
    }
    // 0x80800160: nop

    // 0x80800164: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80800168: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080016C: b           L_8080018C
    // 0x80800170: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8080018C;
    // 0x80800170: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80800174:
    // 0x80800174: b           L_8080018C
    // 0x80800178: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8080018C;
    // 0x80800178: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_8080017C:
    // 0x8080017C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80800180: nop

    // 0x80800184: bltz        $t2, L_80800174
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800188: nop
    
            goto L_80800174;
    }
    // 0x80800188: nop

L_8080018C:
    // 0x8080018C: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
    // 0x80800190: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1104, 0X11D0) << 16);
    // 0x80800194: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80800198: lwc1        $f16, 0x11D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1104, 0X11D0));
    // 0x8080019C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808001A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808001A4: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x808001A8: andi        $t7, $v1, 0x10
    ctx->r15 = ctx->r3 & 0X10;
    // 0x808001AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808001B0: addiu       $a0, $zero, 0x289
    ctx->r4 = ADD32(0, 0X289);
    // 0x808001B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001B8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x808001BC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x808001C0: nop

    // 0x808001C4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x808001C8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x808001CC: nop

    // 0x808001D0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x808001D4: beql        $t4, $zero, L_80800224
    if (ctx->r12 == 0) {
        // 0x808001D8: mfc1        $t4, $f4
        ctx->r12 = (int32_t)ctx->f4.u32l;
            goto L_80800224;
    }
    goto skip_0;
    // 0x808001D8: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x808001DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001E0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808001E4: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x808001E8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x808001EC: nop

    // 0x808001F0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x808001F4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x808001F8: nop

    // 0x808001FC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80800200: bne         $t4, $zero, L_80800218
    if (ctx->r12 != 0) {
        // 0x80800204: nop
    
            goto L_80800218;
    }
    // 0x80800204: nop

    // 0x80800208: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8080020C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800210: b           L_80800230
    // 0x80800214: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_80800230;
    // 0x80800214: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80800218:
    // 0x80800218: b           L_80800230
    // 0x8080021C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_80800230;
    // 0x8080021C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80800220: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
L_80800224:
    // 0x80800224: nop

    // 0x80800228: bltz        $t4, L_80800218
    if (SIGNED(ctx->r12) < 0) {
        // 0x8080022C: nop
    
            goto L_80800218;
    }
    // 0x8080022C: nop

L_80800230:
    // 0x80800230: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80800234: beq         $t5, $zero, L_8080025C
    if (ctx->r13 == 0) {
        // 0x80800238: sh          $t4, 0x16($v0)
        MEM_H(0X16, ctx->r2) = ctx->r12;
            goto L_8080025C;
    }
    // 0x80800238: sh          $t4, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r12;
    // 0x8080023C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800240: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800244: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800248: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8080024C: nop

    // 0x80800250: bc1f        L_8080025C
    if (!c1cs) {
        // 0x80800254: nop
    
            goto L_8080025C;
    }
    // 0x80800254: nop

    // 0x80800258: sh          $t6, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r14;
L_8080025C:
    // 0x8080025C: beq         $t7, $zero, L_80800268
    if (ctx->r15 == 0) {
        // 0x80800260: nop
    
            goto L_80800268;
    }
    // 0x80800260: nop

    // 0x80800264: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
L_80800268:
    // 0x80800268: jal         0x80089C30
    // 0x8080026C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080026C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800270: beq         $v0, $zero, L_80800280
    if (ctx->r2 == 0) {
        // 0x80800274: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_80800280;
    }
    // 0x80800274: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800278: b           L_80800284
    // 0x8080027C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
        goto L_80800284;
    // 0x8080027C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
L_80800280:
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800284:
    // 0x80800284: jal         0x8008A028
    // 0x80800288: addiu       $a0, $a2, 0x18
    ctx->r4 = ADD32(ctx->r6, 0X18);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800288: addiu       $a0, $a2, 0x18
    ctx->r4 = ADD32(ctx->r6, 0X18);
    after_2:
    // 0x8080028C: jal         0x800EA05C
    // 0x80800290: nop

    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x80800290: nop

    after_3:
    // 0x80800294: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800298: xori        $t9, $v0, 0xED
    ctx->r25 = ctx->r2 ^ 0XED;
    // 0x8080029C: sltiu       $t0, $t9, 0x1
    ctx->r8 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x808002A0: lbu         $t3, 0x65($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X65);
    // 0x808002A4: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x808002A8: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x808002AC: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x808002B0: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808002B4: sb          $t5, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r13;
    // 0x808002B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002C0: jr          $ra
    // 0x808002C4: nop

    return;
    // 0x808002C4: nop

;}
RECOMP_FUNC void func_800E8A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8A20: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8A24: lw          $a0, -0x2A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A00);
    // 0x800E8A28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8A30: beql        $a0, $zero, L_800E8A4C
    if (ctx->r4 == 0) {
        // 0x800E8A34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E8A4C;
    }
    goto skip_0;
    // 0x800E8A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E8A38: jal         0x800B32E4
    // 0x800E8A3C: nop

    freelist_defrag(rdram, ctx);
        goto after_0;
    // 0x800E8A3C: nop

    after_0:
    // 0x800E8A40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E8A44: sw          $v0, -0x2A00($at)
    MEM_W(-0X2A00, ctx->r1) = ctx->r2;
    // 0x800E8A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E8A4C:
    // 0x800E8A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8A50: jr          $ra
    // 0x800E8A54: nop

    return;
    // 0x800E8A54: nop

    // 0x800E8A58: nop

    // 0x800E8A5C: nop

;}
RECOMP_FUNC void bskazstilt_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080112C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801130: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(292, 0X1260) << 16);
    // 0x80801134: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801138: jr          $ra
    // 0x8080113C: lw          $v0, 0x1260($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1260));
    return;
    // 0x8080113C: lw          $v0, 0x1260($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1260));
;}
RECOMP_FUNC void func_80800B4C_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B4C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800B50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B54: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800B58: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80800B5C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800B60: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800B64: bgezl       $t8, L_80800BF0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800B68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BF0;
    }
    goto skip_0;
    // 0x80800B68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800B6C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80800B70: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80800B74: jal         0x800DBEFC
    // 0x80800B78: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_0;
    // 0x80800B78: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    after_0:
    // 0x80800B7C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800B80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800B84: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800B88: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800B8C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800B90: jal         0x800B53A4
    // 0x80800B94: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x80800B94: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800B98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1500) << 16);
    // 0x80800B9C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800BA0: jal         0x800DC298
    // 0x80800BA4: lwc1        $f12, 0x1500($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1500));
    func_800DC298(rdram, ctx);
        goto after_2;
    // 0x80800BA4: lwc1        $f12, 0x1500($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1500));
    after_2:
    // 0x80800BA8: beq         $v0, $zero, L_80800BB8
    if (ctx->r2 == 0) {
        // 0x80800BAC: addiu       $a1, $zero, 0x9CA
        ctx->r5 = ADD32(0, 0X9CA);
            goto L_80800BB8;
    }
    // 0x80800BAC: addiu       $a1, $zero, 0x9CA
    ctx->r5 = ADD32(0, 0X9CA);
    // 0x80800BB0: b           L_80800BB8
    // 0x80800BB4: addiu       $a1, $zero, 0x9DC
    ctx->r5 = ADD32(0, 0X9DC);
        goto L_80800BB8;
    // 0x80800BB4: addiu       $a1, $zero, 0x9DC
    ctx->r5 = ADD32(0, 0X9DC);
L_80800BB8:
    // 0x80800BB8: jal         0x800BA3FC
    // 0x80800BBC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800BA3FC(rdram, ctx);
        goto after_3;
    // 0x80800BBC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80800BC0: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1588, 0X1784) << 16);
    // 0x80800BC4: addiu       $t0, $t0, 0x1784
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1588, 0X1784));
    // 0x80800BC8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800BCC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800BD0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800BD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800BD8: jal         0x800BABB8
    // 0x80800BDC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80800BDC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80800BE0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800BE4: jal         0x800BA22C
    // 0x80800BE8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800BA22C(rdram, ctx);
        goto after_5;
    // 0x80800BE8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_5:
    // 0x80800BEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BF0:
    // 0x80800BF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800BF4: jr          $ra
    // 0x80800BF8: nop

    return;
    // 0x80800BF8: nop

;}
RECOMP_FUNC void plcamera_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: jal         0x800F53E4
    // 0x80800048: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F53E4(rdram, ctx);
        goto after_0;
    // 0x80800048: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080004C: bne         $v0, $zero, L_8080005C
    if (ctx->r2 != 0) {
        // 0x80800050: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080005C;
    }
    // 0x80800050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800054: b           L_808000B8
    // 0x80800058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000B8;
    // 0x80800058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080005C:
    // 0x8080005C: jal         0x800A3404
    // 0x80800060: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800A3404(rdram, ctx);
        goto after_1;
    // 0x80800060: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800064: beq         $v0, $zero, L_8080009C
    if (ctx->r2 == 0) {
        // 0x80800068: nop
    
            goto L_8080009C;
    }
    // 0x80800068: nop

    // 0x8080006C: jal         0x800F693C
    // 0x80800070: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F693C(rdram, ctx);
        goto after_2;
    // 0x80800070: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800074: beq         $v0, $zero, L_8080009C
    if (ctx->r2 == 0) {
        // 0x80800078: nop
    
            goto L_8080009C;
    }
    // 0x80800078: nop

    // 0x8080007C: jal         0x800EA068
    // 0x80800080: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800EA068(rdram, ctx);
        goto after_3;
    // 0x80800080: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_3:
    // 0x80800084: beq         $v0, $zero, L_8080009C
    if (ctx->r2 == 0) {
        // 0x80800088: nop
    
            goto L_8080009C;
    }
    // 0x80800088: nop

    // 0x8080008C: jal         0x80084298
    // 0x80800090: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _bsfirstp_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800090: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x80800094: b           L_808000B8
    // 0x80800098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000B8;
    // 0x80800098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080009C:
    // 0x8080009C: jal         0x800A3404
    // 0x808000A0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800A3404(rdram, ctx);
        goto after_5;
    // 0x808000A0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_5:
    // 0x808000A4: beql        $v0, $zero, L_808000B8
    if (ctx->r2 == 0) {
        // 0x808000A8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000B8;
    }
    goto skip_0;
    // 0x808000A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808000AC: b           L_808000B8
    // 0x808000B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000B8;
    // 0x808000B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808000B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000B8:
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C0: jr          $ra
    // 0x808000C4: nop

    return;
    // 0x808000C4: nop

;}
RECOMP_FUNC void func_800F254C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F254C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F2550: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F2554: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800F2558: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F255C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F2560: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800F2564: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800F2568: jal         0x800EF2A0
    // 0x800F256C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_0;
    // 0x800F256C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800F2570: jal         0x800137F4
    // 0x800F2574: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    func_800137F4(rdram, ctx);
        goto after_1;
    // 0x800F2574: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800F2578: jal         0x80013788
    // 0x800F257C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_80013788(rdram, ctx);
        goto after_2;
    // 0x800F257C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800F2580: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800F2584: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F2588: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F258C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F2590: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F2594: mul.s       $f6, $f14, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800F2598: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F259C: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800F25A0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800F25A4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800F25A8: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F25AC: mul.s       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800F25B0: nop

    // 0x800F25B4: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800F25B8: nop

    // 0x800F25BC: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800F25C0: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800F25C4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800F25C8: jal         0x800F274C
    // 0x800F25CC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_800F274C(rdram, ctx);
        goto after_3;
    // 0x800F25CC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x800F25D0: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F25D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F25D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800F25DC: mul.s       $f0, $f16, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800F25E0: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800F25E4: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F25E8: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F25EC: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800F25F0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800F25F4: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800F25F8: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x800F25FC: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F2600: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800F2604: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800F2608: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
    // 0x800F260C: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800F2610: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F2614: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800F2618: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800F261C: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    // 0x800F2620: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F2624: mul.s       $f0, $f14, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800F2628: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800F262C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800F2630: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800F2634: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x800F2638: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F263C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F2640: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F2644: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800F2648: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800F264C: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x800F2650: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800F2654: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800F2658: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800F265C: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800F2660: swc1        $f8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f8.u32l;
    // 0x800F2664: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F2668: mul.s       $f0, $f18, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800F266C: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800F2670: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800F2674: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800F2678: swc1        $f8, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f8.u32l;
    // 0x800F267C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F2680: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800F2684: sub.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x800F2688: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
    // 0x800F268C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800F2690: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800F2694: add.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x800F2698: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x800F269C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F26A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800F26A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F26A8: jr          $ra
    // 0x800F26AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800F26AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808005DC_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005E0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808005E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808005E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005EC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808005F0: beq         $a1, $zero, L_80800620
    if (ctx->r5 == 0) {
        // 0x808005F4: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80800620;
    }
    // 0x808005F4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808005F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005FC: beq         $a1, $at, L_80800630
    if (ctx->r5 == ctx->r1) {
        // 0x80800600: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800630;
    }
    // 0x80800600: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800604: beq         $a1, $at, L_808006FC
    if (ctx->r5 == ctx->r1) {
        // 0x80800608: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808006FC;
    }
    // 0x80800608: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080060C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800610: beq         $a1, $at, L_80800718
    if (ctx->r5 == ctx->r1) {
        // 0x80800614: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800718;
    }
    // 0x80800614: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800618: b           L_8080072C
    // 0x8080061C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
        goto L_8080072C;
    // 0x8080061C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_80800620:
    // 0x80800620: jal         0x8009BC6C
    // 0x80800624: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x80800624: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80800628: b           L_8080072C
    // 0x8080062C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
        goto L_8080072C;
    // 0x8080062C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_80800630:
    // 0x80800630: jal         0x8008CABC
    // 0x80800634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x80800634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800638: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080063C: sw          $zero, 0x160($s1)
    MEM_W(0X160, ctx->r17) = 0;
    // 0x80800640: jal         0x8008AF24
    // 0x80800644: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80800644: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080064C: jal         0x8008AED4
    // 0x80800650: addiu       $a1, $zero, 0x294
    ctx->r5 = ADD32(0, 0X294);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800650: addiu       $a1, $zero, 0x294
    ctx->r5 = ADD32(0, 0X294);
    after_3:
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800658: jal         0x8008B1BC
    // 0x8080065C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x8080065C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x80800660: lui         $a1, 0x3E09
    ctx->r5 = S32(0X3E09 << 16);
    // 0x80800664: ori         $a1, $a1, 0x374C
    ctx->r5 = ctx->r5 | 0X374C;
    // 0x80800668: jal         0x8008B1C8
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_5;
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800670: lui         $a1, 0x3E0F
    ctx->r5 = S32(0X3E0F << 16);
    // 0x80800674: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    // 0x80800678: jal         0x8008B24C
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800680: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800684: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: jal         0x8008B1D4
    // 0x80800690: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_7;
    // 0x80800690: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800698: jal         0x8008B134
    // 0x8080069C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x8080069C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808006A0: jal         0x8008B064
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808006A8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808006AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808006B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808006BC: jal         0x8009FFD8
    // 0x808006C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x808006C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x808006C4: lui         $a1, 0x4418
    ctx->r5 = S32(0X4418 << 16);
    // 0x808006C8: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808006CC: jal         0x8009BA58
    // 0x808006D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_11;
    // 0x808006D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x808006D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006D8: jal         0x8009BCB4
    // 0x808006DC: lui         $a1, 0xC47A
    ctx->r5 = S32(0XC47A << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_12;
    // 0x808006DC: lui         $a1, 0xC47A
    ctx->r5 = S32(0XC47A << 16);
    after_12:
    // 0x808006E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006E4: addiu       $a1, $zero, 0x589
    ctx->r5 = ADD32(0, 0X589);
    // 0x808006E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808006EC: jal         0x8009DF18
    // 0x808006F0: addiu       $a3, $zero, 0x3A98
    ctx->r7 = ADD32(0, 0X3A98);
    func_8009DF18(rdram, ctx);
        goto after_13;
    // 0x808006F0: addiu       $a3, $zero, 0x3A98
    ctx->r7 = ADD32(0, 0X3A98);
    after_13:
    // 0x808006F4: b           L_8080072C
    // 0x808006F8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
        goto L_8080072C;
    // 0x808006F8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_808006FC:
    // 0x808006FC: lui         $a1, 0x3F4F
    ctx->r5 = S32(0X3F4F << 16);
    // 0x80800700: lui         $a2, 0x404C
    ctx->r6 = S32(0X404C << 16);
    // 0x80800704: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800708: jal         0x8008CF1C
    // 0x8080070C: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_14;
    // 0x8080070C: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    after_14:
    // 0x80800710: b           L_8080072C
    // 0x80800714: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
        goto L_8080072C;
    // 0x80800714: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_80800718:
    // 0x80800718: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8080071C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800720: jal         0x8008CF1C
    // 0x80800724: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_15;
    // 0x80800724: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_15:
    // 0x80800728: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_8080072C:
    // 0x8080072C: sb          $t8, 0x15C($s1)
    MEM_B(0X15C, ctx->r17) = ctx->r24;
    // 0x80800730: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800734: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800738: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080073C: jr          $ra
    // 0x80800740: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800740: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void badrone_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x80800188: jr          $ra
    // 0x8080018C: sb          $a1, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r5;
    return;
    // 0x8080018C: sb          $a1, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80800A14_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A20: addiu       $a0, $zero, 0x42D
    ctx->r4 = ADD32(0, 0X42D);
    // 0x80800A24: jal         0x800DA564
    // 0x80800A28: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800A28: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80800A2C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800A30: jal         0x80800A04
    // 0x80800A34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800A04_chfactoryworkerdirty(rdram, ctx);
        goto after_1;
    // 0x80800A34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800A38: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A40: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80800A44: xor         $v0, $t6, $t7
    ctx->r2 = ctx->r14 ^ ctx->r15;
    // 0x80800A48: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800A4C: jr          $ra
    // 0x80800A50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800A50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80097524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097524: lw          $t6, 0x98($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X98);
    // 0x80097528: jr          $ra
    // 0x8009752C: lbu         $v0, 0x25($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X25);
    return;
    // 0x8009752C: lbu         $v0, 0x25($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X25);
;}
RECOMP_FUNC void func_800D3DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3DAC: jal         0x800F54F0
    // 0x800D3DB0: nop

    func_800F54F0(rdram, ctx);
        goto after_0;
    // 0x800D3DB0: nop

    after_0:
    // 0x800D3DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3DBC: jr          $ra
    // 0x800D3DC0: nop

    return;
    // 0x800D3DC0: nop

    // 0x800D3DC4: nop

    // 0x800D3DC8: nop

    // 0x800D3DCC: nop

;}
RECOMP_FUNC void chdodgemcontrol_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802070: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1752, 0X4EDC) << 16);
    // 0x80802074: jr          $ra
    // 0x80802078: addiu       $v0, $v0, 0x4EDC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1752, 0X4EDC));
    return;
    // 0x80802078: addiu       $v0, $v0, 0x4EDC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1752, 0X4EDC));
;}
RECOMP_FUNC void func_800BA7C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA7C4: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800BA7C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BA7CC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BA7D0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800BA7D4: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800BA7D8: nop

    // 0x800BA7DC: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800BA7E0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BA7E4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800BA7E8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800BA7EC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800BA7F0: sh          $t7, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r15;
    // 0x800BA7F4: jr          $ra
    // 0x800BA7F8: sh          $t9, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r25;
    return;
    // 0x800BA7F8: sh          $t9, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_8080436C_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080436C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804374: jal         0x801018A4
    // 0x80804378: nop

    func_801018A4(rdram, ctx);
        goto after_0;
    // 0x80804378: nop

    after_0:
    // 0x8080437C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804384: jr          $ra
    // 0x80804388: nop

    return;
    // 0x80804388: nop

;}
RECOMP_FUNC void func_80800024_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080002C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800030: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800034: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800038: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x8080003C: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x80800040: jal         0x80105010
    // 0x80800044: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    func_80105010(rdram, ctx);
        goto after_0;
    // 0x80800044: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_808000C8_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D0: jal         0x80800040
    // 0x808000D4: nop

    func_80800040_chcollballcontrol(rdram, ctx);
        goto after_0;
    // 0x808000D4: nop

    after_0:
    // 0x808000D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4B14) << 16);
    // 0x808000DC: lwc1        $f4, 0x4B14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4B14));
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E8: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void func_80800054_chmumboskullfakearchpanellava(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080005C: jal         0x80800000
    // 0x80800060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_chmumboskullfakearchpanellava(rdram, ctx);
        goto after_0;
    // 0x80800060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800064: jal         0x800DA298
    // 0x80800068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080006C: beql        $v0, $zero, L_80800080
    if (ctx->r2 == 0) {
        // 0x80800070: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800080;
    }
    goto skip_0;
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800074: jal         0x800FFAB0
    // 0x80800078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800080:
    // 0x80800080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void func_808005F0_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(892, 0XF08) << 16);
    // 0x808005FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800600: jal         0x800DC298
    // 0x80800604: lwc1        $f12, 0xF08($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(892, 0XF08));
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x80800604: lwc1        $f12, 0xF08($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(892, 0XF08));
    after_0:
    // 0x80800608: beq         $v0, $zero, L_80800628
    if (ctx->r2 == 0) {
        // 0x8080060C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800628;
    }
    // 0x8080060C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800610: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0XFB0) << 16);
    // 0x80800614: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800618: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080061C: addiu       $a2, $a2, 0xFB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0XFB0));
    // 0x80800620: jal         0x80089D20
    // 0x80800624: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800624: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    after_1:
L_80800628:
    // 0x80800628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080062C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800630: jr          $ra
    // 0x80800634: nop

    return;
    // 0x80800634: nop

;}
RECOMP_FUNC void func_8001D96C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D96C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D974: jal         0x8001D800
    // 0x8001D978: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_8001D800(rdram, ctx);
        goto after_0;
    // 0x8001D978: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x8001D97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D984: jr          $ra
    // 0x8001D988: nop

    return;
    // 0x8001D988: nop

;}
RECOMP_FUNC void _gcgame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A40: syscall     651
    recomp_syscall_handler(rdram, ctx, 0x80087A40);
    return;
    // 0x80087A44: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void gcmapsects_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080224C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80802250: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80802254: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80802258: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8080225C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80802260: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80802264: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80802268: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8080226C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80802270: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80802274: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80802278: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8080227C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80802280: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x80802284: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80802288: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8080228C: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x80802290: bne         $t6, $zero, L_808022A0
    if (ctx->r14 != 0) {
        // 0x80802294: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_808022A0;
    }
    // 0x80802294: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80802298: b           L_8080240C
    // 0x8080229C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080240C;
    // 0x8080229C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808022A0:
    // 0x808022A0: jal         0x800BEB58
    // 0x808022A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEB58(rdram, ctx);
        goto after_0;
    // 0x808022A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808022A8: lbu         $t7, 0x77($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X77);
    // 0x808022AC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x808022B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808022B4: blez        $t7, L_80802408
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808022B8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80802408;
    }
    // 0x808022B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808022BC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808022C0: lw          $s5, 0x70($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X70);
    // 0x808022C4: lw          $t8, 0x68($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X68);
L_808022C8:
    // 0x808022C8: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x808022CC: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x808022D0: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x808022D4: bgezl       $t1, L_808023F4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808022D8: lbu         $t2, 0x77($s2)
        ctx->r10 = MEM_BU(ctx->r18, 0X77);
            goto L_808023F4;
    }
    goto skip_0;
    // 0x808022D8: lbu         $t2, 0x77($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X77);
    skip_0:
    // 0x808022DC: jal         0x800D674C
    // 0x808022E0: lhu         $a0, 0x40($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X40);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x808022E0: lhu         $a0, 0x40($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X40);
    after_1:
    // 0x808022E4: beq         $v0, $zero, L_808023F0
    if (ctx->r2 == 0) {
        // 0x808022E8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_808023F0;
    }
    // 0x808022E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808022EC: lw          $t2, 0x68($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X68);
    // 0x808022F0: andi        $s3, $s5, 0x1F00
    ctx->r19 = ctx->r21 & 0X1F00;
    // 0x808022F4: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x808022F8: jal         0x800D62E4
    // 0x808022FC: lhu         $a0, 0x40($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X40);
    func_800D62E4(rdram, ctx);
        goto after_2;
    // 0x808022FC: lhu         $a0, 0x40($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X40);
    after_2:
    // 0x80802300: addiu       $at, $zero, 0x1F00
    ctx->r1 = ADD32(0, 0X1F00);
    // 0x80802304: bne         $s3, $at, L_80802314
    if (ctx->r19 != ctx->r1) {
        // 0x80802308: nop
    
            goto L_80802314;
    }
    // 0x80802308: nop

    // 0x8080230C: b           L_8080235C
    // 0x80802310: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
        goto L_8080235C;
    // 0x80802310: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80802314:
    // 0x80802314: jal         0x800B2720
    // 0x80802318: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B2720(rdram, ctx);
        goto after_3;
    // 0x80802318: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8080231C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80802320: jal         0x800B2840
    // 0x80802324: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B2840(rdram, ctx);
        goto after_4;
    // 0x80802324: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80802328: lw          $t4, 0x68($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X68);
    // 0x8080232C: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80802330: sw          $s5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r21;
    // 0x80802334: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x80802338: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x8080233C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80802340: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80802344: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802348: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080234C: addu        $a2, $t4, $s0
    ctx->r6 = ADD32(ctx->r12, ctx->r16);
    // 0x80802350: jal         0x800AB868
    // 0x80802354: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    func_800AB868(rdram, ctx);
        goto after_5;
    // 0x80802354: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_5:
    // 0x80802358: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_8080235C:
    // 0x8080235C: beql        $s4, $zero, L_80802378
    if (ctx->r20 == 0) {
        // 0x80802360: lw          $t6, 0x68($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X68);
            goto L_80802378;
    }
    goto skip_1;
    // 0x80802360: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
    skip_1:
    // 0x80802364: jal         0x800BEB58
    // 0x80802368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800BEB58(rdram, ctx);
        goto after_6;
    // 0x80802368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8080236C: b           L_8080240C
    // 0x80802370: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
        goto L_8080240C;
    // 0x80802370: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80802374: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
L_80802378:
    // 0x80802378: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8080237C: lhu         $v0, 0x42($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X42);
    // 0x80802380: beql        $v0, $zero, L_808023F4
    if (ctx->r2 == 0) {
        // 0x80802384: lbu         $t2, 0x77($s2)
        ctx->r10 = MEM_BU(ctx->r18, 0X77);
            goto L_808023F4;
    }
    goto skip_2;
    // 0x80802384: lbu         $t2, 0x77($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X77);
    skip_2:
    // 0x80802388: jal         0x800D674C
    // 0x8080238C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D674C(rdram, ctx);
        goto after_7;
    // 0x8080238C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80802390: lw          $t8, 0x68($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X68);
    // 0x80802394: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80802398: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8080239C: jal         0x800D62E4
    // 0x808023A0: lhu         $a0, 0x42($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X42);
    func_800D62E4(rdram, ctx);
        goto after_8;
    // 0x808023A0: lhu         $a0, 0x42($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X42);
    after_8:
    // 0x808023A4: jal         0x800B2720
    // 0x808023A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B2720(rdram, ctx);
        goto after_9;
    // 0x808023A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x808023AC: beq         $v0, $zero, L_808023F0
    if (ctx->r2 == 0) {
        // 0x808023B0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_808023F0;
    }
    // 0x808023B0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808023B4: jal         0x800B2840
    // 0x808023B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B2840(rdram, ctx);
        goto after_10;
    // 0x808023B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x808023BC: lw          $t0, 0x68($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X68);
    // 0x808023C0: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x808023C4: sw          $s5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r21;
    // 0x808023C8: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x808023CC: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x808023D0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x808023D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808023D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808023DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808023E0: addu        $a2, $t0, $s0
    ctx->r6 = ADD32(ctx->r8, ctx->r16);
    // 0x808023E4: jal         0x800AB868
    // 0x808023E8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    func_800AB868(rdram, ctx);
        goto after_11;
    // 0x808023E8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_11:
    // 0x808023EC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_808023F0:
    // 0x808023F0: lbu         $t2, 0x77($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X77);
L_808023F4:
    // 0x808023F4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x808023F8: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x808023FC: slt         $at, $s6, $t2
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80802400: bnel        $at, $zero, L_808022C8
    if (ctx->r1 != 0) {
        // 0x80802404: lw          $t8, 0x68($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X68);
            goto L_808022C8;
    }
    goto skip_3;
    // 0x80802404: lw          $t8, 0x68($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X68);
    skip_3:
L_80802408:
    // 0x80802408: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_8080240C:
    // 0x8080240C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80802410: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80802414: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80802418: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8080241C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80802420: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80802424: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80802428: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8080242C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80802430: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80802434: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80802438: jr          $ra
    // 0x8080243C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8080243C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _chbilldrillplate_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862F8: syscall     304
    recomp_syscall_handler(rdram, ctx, 0x800862F8);
    return;
    // 0x800862FC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808009E4_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808009E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009F4: jal         0x80800100
    // 0x808009F8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_80800100_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x808009F8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A00: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x80800A04: jal         0x800A2CE8
    // 0x80800A08: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_1;
    // 0x80800A08: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80800A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A10: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x80800A14: jal         0x800A2CE8
    // 0x80800A18: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_2;
    // 0x80800A18: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80800A1C: lui         $a1, 0x3F02
    ctx->r5 = S32(0X3F02 << 16);
    // 0x80800A20: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x80800A24: jal         0x8008CB10
    // 0x80800A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_3;
    // 0x80800A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800A2C: beq         $v0, $zero, L_80800A6C
    if (ctx->r2 == 0) {
        // 0x80800A30: nop
    
            goto L_80800A6C;
    }
    // 0x80800A30: nop

    // 0x80800A34: jal         0x800DC0C0
    // 0x80800A38: nop

    func_800DC0C0(rdram, ctx);
        goto after_4;
    // 0x80800A38: nop

    after_4:
    // 0x80800A3C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A48: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800A4C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800A50: addiu       $a1, $zero, 0x58B
    ctx->r5 = ADD32(0, 0X58B);
    // 0x80800A54: bc1f        L_80800A64
    if (!c1cs) {
        // 0x80800A58: nop
    
            goto L_80800A64;
    }
    // 0x80800A58: nop

    // 0x80800A5C: b           L_80800A64
    // 0x80800A60: addiu       $a1, $zero, 0x58A
    ctx->r5 = ADD32(0, 0X58A);
        goto L_80800A64;
    // 0x80800A60: addiu       $a1, $zero, 0x58A
    ctx->r5 = ADD32(0, 0X58A);
L_80800A64:
    // 0x80800A64: jal         0x8009DF18
    // 0x80800A68: addiu       $a3, $zero, 0x1388
    ctx->r7 = ADD32(0, 0X1388);
    func_8009DF18(rdram, ctx);
        goto after_5;
    // 0x80800A68: addiu       $a3, $zero, 0x1388
    ctx->r7 = ADD32(0, 0X1388);
    after_5:
L_80800A6C:
    // 0x80800A6C: jal         0x8009EF10
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_6;
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800A74: bne         $v0, $zero, L_80800A90
    if (ctx->r2 != 0) {
        // 0x80800A78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A90;
    }
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A7C: jal         0x8009BCD4
    // 0x80800A80: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_7;
    // 0x80800A80: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_7:
    // 0x80800A84: beq         $v0, $zero, L_80800A90
    if (ctx->r2 == 0) {
        // 0x80800A88: addiu       $t6, $zero, 0x16C
        ctx->r14 = ADD32(0, 0X16C);
            goto L_80800A90;
    }
    // 0x80800A88: addiu       $t6, $zero, 0x16C
    ctx->r14 = ADD32(0, 0X16C);
    // 0x80800A8C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800A90:
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A94: jal         0x80800000
    // 0x80800A98: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80800000_bsbanshack(rdram, ctx);
        goto after_8;
    // 0x80800A98: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA0: jal         0x8009E5C8
    // 0x80800AA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_9;
    // 0x80800AA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80800AA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800AB4: jr          $ra
    // 0x80800AB8: nop

    return;
    // 0x80800AB8: nop

;}
RECOMP_FUNC void func_808002B4_fxstep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2830, 0XAA0) << 16);
    // 0x808002B8: lh          $t6, 0xAA0($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(2830, 0XAA0));
    // 0x808002BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002C0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808002C4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x808002C8: beq         $t6, $zero, L_80800330
    if (ctx->r14 == 0) {
        // 0x808002CC: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80800330;
    }
    // 0x808002CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002D0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2830, 0XAA0) << 16);
    // 0x808002D4: addiu       $v0, $t7, 0xAA0
    ctx->r2 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2830, 0XAA0));
    // 0x808002D8: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
L_808002DC:
    // 0x808002DC: bnel        $a3, $v1, L_80800324
    if (ctx->r7 != ctx->r3) {
        // 0x808002E0: lh          $v1, 0x10($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X10);
            goto L_80800324;
    }
    goto skip_0;
    // 0x808002E0: lh          $v1, 0x10($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X10);
    skip_0:
    // 0x808002E4: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x808002E8: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808002EC: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x808002F0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x808002F4: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x808002F8: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x808002FC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800300: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800304: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80800308: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080030C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80800310: jal         0x80800078
    // 0x80800314: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80800078_fxstep(rdram, ctx);
        goto after_0;
    // 0x80800314: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x80800318: b           L_80800334
    // 0x8080031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800334;
    // 0x8080031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800320: lh          $v1, 0x10($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X10);
L_80800324:
    // 0x80800324: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80800328: bne         $v1, $zero, L_808002DC
    if (ctx->r3 != 0) {
        // 0x8080032C: nop
    
            goto L_808002DC;
    }
    // 0x8080032C: nop

L_80800330:
    // 0x80800330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800334:
    // 0x80800334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800338: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080033C: jr          $ra
    // 0x80800340: nop

    return;
    // 0x80800340: nop

;}
RECOMP_FUNC void scinfobar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800230: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800234: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800238: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080023C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800240: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800244: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800248: jal         0x8001ACCC
    // 0x8080024C: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080024C: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_0:
    // 0x80800250: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80800254: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x80800258: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x8080025C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800260: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80800264: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x80800268: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x8080026C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800270: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800274: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x80800278: sb          $zero, 0xA($v0)
    MEM_B(0XA, ctx->r2) = 0;
    // 0x8080027C: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x80800280: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x80800284: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800288: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080028C: jal         0x808003E8
    // 0x80800290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scinfobar_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x80800530
    // 0x8080029C: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    scinfobar_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x8080029C: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    after_2:
    // 0x808002A0: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x808002A4: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x808002A8: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x808002AC: jal         0x808000B0
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B0_scinfobar(rdram, ctx);
        goto after_3;
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: jal         0x80800000
    // 0x808002BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800000_scinfobar(rdram, ctx);
        goto after_4;
    // 0x808002BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808002C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002C4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808002C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002CC: jr          $ra
    // 0x808002D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808002D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
