#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800C64_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800C70: jal         0x80800000
    // 0x80800C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_bsstatue(rdram, ctx);
        goto after_0;
    // 0x80800C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800C78: jal         0x800839B8
    // 0x80800C7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80800C7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800C80: jal         0x80800130
    // 0x80800C84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800130_bsstatue(rdram, ctx);
        goto after_2;
    // 0x80800C84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C90: jr          $ra
    // 0x80800C94: nop

    return;
    // 0x80800C94: nop

;}
RECOMP_FUNC void func_8080009C_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A4: jal         0x80100094
    // 0x808000A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000AC: lbu         $t6, 0x24($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X24);
    // 0x808000B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000B4: beql        $t6, $zero, L_808000D0
    if (ctx->r14 == 0) {
        // 0x808000B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000D0;
    }
    goto skip_0;
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000BC: jal         0x800856B8
    // 0x808000C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _capod_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808000C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808000C4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C8: sb          $zero, 0x24($v1)
    MEM_B(0X24, ctx->r3) = 0;
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000D0:
    // 0x808000D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void func_808004E8_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004EC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808004F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808004F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800500: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800508: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080050C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80800510: jal         0x80087D08
    // 0x80800514: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _gcnewoption_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800514: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800518: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1200, 0XBB8) << 16);
    // 0x8080051C: lwc1        $f6, 0xBB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1200, 0XBB8));
    // 0x80800520: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800524: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800528: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080052C: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x80800530: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80800534: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80800538: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8080053C: jal         0x80087DD8
    // 0x80800540: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_1;
    // 0x80800540: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800544: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800548: jal         0x80087D98
    // 0x8080054C: addiu       $a1, $zero, 0xA3
    ctx->r5 = ADD32(0, 0XA3);
    _gcnewoption_entrypoint_32(rdram, ctx);
        goto after_2;
    // 0x8080054C: addiu       $a1, $zero, 0xA3
    ctx->r5 = ADD32(0, 0XA3);
    after_2:
    // 0x80800550: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800554: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800558: jr          $ra
    // 0x8080055C: nop

    return;
    // 0x8080055C: nop

;}
RECOMP_FUNC void func_8009CA70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CA70: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8009CA74: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8009CA78: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009CA7C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8009CA80: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8009CA84: lw          $t7, 0x7F34($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7F34);
    // 0x8009CA88: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8009CA8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009CA90: and         $t8, $t7, $a2
    ctx->r24 = ctx->r15 & ctx->r6;
    // 0x8009CA94: beq         $t8, $zero, L_8009CAA4
    if (ctx->r24 == 0) {
        // 0x8009CA98: nop
    
            goto L_8009CAA4;
    }
    // 0x8009CA98: nop

    // 0x8009CA9C: jr          $ra
    // 0x8009CAA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8009CAA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009CAA4:
    // 0x8009CAA4: jr          $ra
    // 0x8009CAA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8009CAA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void bsbtrot_entrypoint_45(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808027EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808027F0: jal         0x80800538
    // 0x808027F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800538_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x808027F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808027F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808027FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802800: jal         0x808025D8
    // 0x80802804: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    func_808025D8_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80802804: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80802808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080280C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802810: jr          $ra
    // 0x80802814: nop

    return;
    // 0x80802814: nop

;}
RECOMP_FUNC void bscrouch_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800688: jr          $ra
    // 0x8080068C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080068C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80110DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110DC8: jal         0x8011546C
    // 0x80110DCC: nop

    func_8011546C(rdram, ctx);
        goto after_0;
    // 0x80110DCC: nop

    after_0:
    // 0x80110DD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110DD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110DD8: jr          $ra
    // 0x80110DDC: nop

    return;
    // 0x80110DDC: nop

;}
RECOMP_FUNC void func_80800560_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800560: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800564: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800568: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080056C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800570: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800574: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800578: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1200, 0XBC0) << 16);
    // 0x8080057C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800580: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800584: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800588: addiu       $s2, $s2, 0xBC0
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1200, 0XBC0));
    // 0x8080058C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800590: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
L_80800594:
    // 0x80800594: jal         0x800EA05C
    // 0x80800598: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800598: nop

    after_0:
    // 0x8080059C: lh          $t6, 0x0($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X0);
    // 0x808005A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808005A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808005A8: beq         $v0, $t6, L_808005DC
    if (ctx->r2 == ctx->r14) {
        // 0x808005AC: addiu       $a2, $s1, 0xA
        ctx->r6 = ADD32(ctx->r17, 0XA);
            goto L_808005DC;
    }
    // 0x808005AC: addiu       $a2, $s1, 0xA
    ctx->r6 = ADD32(ctx->r17, 0XA);
    // 0x808005B0: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x808005B4: jal         0x80087CF8
    // 0x808005B8: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x808005B8: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    after_1:
    // 0x808005BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808005C0: jal         0x80087D40
    // 0x808005C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_21(rdram, ctx);
        goto after_2;
    // 0x808005C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808005C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808005CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808005D0: jal         0x80087D90
    // 0x808005D4: lbu         $a2, 0x7($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X7);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_3;
    // 0x808005D4: lbu         $a2, 0x7($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X7);
    after_3:
    // 0x808005D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808005DC:
    // 0x808005DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808005E0: bne         $s1, $s4, L_80800594
    if (ctx->r17 != ctx->r20) {
        // 0x808005E4: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_80800594;
    }
    // 0x808005E4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x808005E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808005EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808005F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808005F8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808005FC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800600: jr          $ra
    // 0x80800604: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800604: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800A5630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5638: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A563C: jal         0x80085568
    // 0x800A5640: addiu       $a0, $a0, -0x6AC0
    ctx->r4 = ADD32(ctx->r4, -0X6AC0);
    _cadbmgrDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800A5640: addiu       $a0, $a0, -0x6AC0
    ctx->r4 = ADD32(ctx->r4, -0X6AC0);
    after_0:
    // 0x800A5644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A564C: jr          $ra
    // 0x800A5650: nop

    return;
    // 0x800A5650: nop

;}
RECOMP_FUNC void func_808013C0_chdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013C0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808013C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808013C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808013CC: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x808013D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808013D4: jal         0x80100094
    // 0x808013D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808013D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808013DC: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x808013E0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x808013E4: jal         0x800F5A00
    // 0x808013E8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x808013E8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_1:
    // 0x808013EC: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x808013F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808013F4: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808013F8: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x808013FC: srl         $t7, $t6, 26
    ctx->r15 = S32(U32(ctx->r14) >> 26);
    // 0x80801400: bnel        $t7, $at, L_8080141C
    if (ctx->r15 != ctx->r1) {
        // 0x80801404: lwc1        $f0, 0x8($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
            goto L_8080141C;
    }
    goto skip_0;
    // 0x80801404: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x80801408: lh          $t8, 0x12($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X12);
    // 0x8080140C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80801410: b           L_8080141C
    // 0x80801414: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
        goto L_8080141C;
    // 0x80801414: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801418: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
L_8080141C:
    // 0x8080141C: jal         0x800F2100
    // 0x80801420: sub.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x80801420: sub.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f0.fl;
    after_2:
    // 0x80801424: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801428: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080142C: nop

    // 0x80801430: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80801434: nop

    // 0x80801438: bc1f        L_80801448
    if (!c1cs) {
        // 0x8080143C: nop
    
            goto L_80801448;
    }
    // 0x8080143C: nop

    // 0x80801440: b           L_808014FC
    // 0x80801444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808014FC;
    // 0x80801444: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801448:
    // 0x80801448: jal         0x800137AC
    // 0x8080144C: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    func_800137AC(rdram, ctx);
        goto after_3;
    // 0x8080144C: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    after_3:
    // 0x80801450: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801454: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801458: nop

    // 0x8080145C: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80801460: jal         0x800137C4
    // 0x80801464: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    func_800137C4(rdram, ctx);
        goto after_4;
    // 0x80801464: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x80801468: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080146C: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80801470: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801474: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801478: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x8080147C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80801480: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801484: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x80801488: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8080148C: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80801490: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x80801494: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80801498: add.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8080149C: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x808014A0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808014A4: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x808014A8: jal         0x800F5F24
    // 0x808014AC: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    func_800F5F24(rdram, ctx);
        goto after_5;
    // 0x808014AC: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x808014B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808014B4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808014B8: jal         0x800EEB9C
    // 0x808014BC: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_6;
    // 0x808014BC: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_6:
    // 0x808014C0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808014C4: jal         0x800EF04C
    // 0x808014C8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x808014C8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_7:
    // 0x808014CC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808014D0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808014D4: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x808014D8: jal         0x800F0AA4
    // 0x808014DC: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_800F0AA4(rdram, ctx);
        goto after_8;
    // 0x808014DC: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_8:
    // 0x808014E0: bne         $v0, $zero, L_808014F0
    if (ctx->r2 != 0) {
        // 0x808014E4: nop
    
            goto L_808014F0;
    }
    // 0x808014E4: nop

    // 0x808014E8: b           L_808014FC
    // 0x808014EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808014FC;
    // 0x808014EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808014F0:
    // 0x808014F0: jal         0x808009F4
    // 0x808014F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009F4_chdoor(rdram, ctx);
        goto after_9;
    // 0x808014F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808014F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808014FC:
    // 0x808014FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801500: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801504: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80801508: jr          $ra
    // 0x8080150C: nop

    return;
    // 0x8080150C: nop

;}
RECOMP_FUNC void func_800C7BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7BCC: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x800C7BD0: addiu       $a2, $a0, 0x14
    ctx->r6 = ADD32(ctx->r4, 0X14);
    // 0x800C7BD4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800C7BD8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800C7BDC: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800C7BE0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C7BE4: addu        $t0, $t6, $a0
    ctx->r8 = ADD32(ctx->r14, ctx->r4);
    // 0x800C7BE8: addiu       $t1, $t0, 0x14
    ctx->r9 = ADD32(ctx->r8, 0X14);
    // 0x800C7BEC: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800C7BF0: beq         $a0, $t0, L_800C7E14
    if (ctx->r4 == ctx->r8) {
        // 0x800C7BF4: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800C7E14;
    }
    // 0x800C7BF4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800C7BF8: subu        $t0, $t1, $a2
    ctx->r8 = SUB32(ctx->r9, ctx->r6);
    // 0x800C7BFC: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x800C7C00: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x800C7C04: mfhi        $t7
    ctx->r15 = hi;
    // 0x800C7C08: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    // 0x800C7C0C: beql        $t7, $zero, L_800C7C8C
    if (ctx->r15 == 0) {
        // 0x800C7C10: lwc1        $f0, 0x0($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
            goto L_800C7C8C;
    }
    goto skip_0;
    // 0x800C7C10: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x800C7C14: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
L_800C7C18:
    // 0x800C7C18: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C7C1C: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x800C7C20: nop

    // 0x800C7C24: bc1fl       L_800C7C78
    if (!c1cs) {
        // 0x800C7C28: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_800C7C78;
    }
    goto skip_1;
    // 0x800C7C28: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    skip_1:
    // 0x800C7C2C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800C7C30: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800C7C34: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800C7C38: nop

    // 0x800C7C3C: bc1fl       L_800C7C78
    if (!c1cs) {
        // 0x800C7C40: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_800C7C78;
    }
    goto skip_2;
    // 0x800C7C40: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    skip_2:
    // 0x800C7C44: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800C7C48: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800C7C4C: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800C7C50: nop

    // 0x800C7C54: bc1f        L_800C7C74
    if (!c1cs) {
        // 0x800C7C58: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_800C7C74;
    }
    // 0x800C7C58: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800C7C5C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800C7C60: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800C7C64: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C7C68: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C7C6C: jr          $ra
    // 0x800C7C70: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    return;
    // 0x800C7C70: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
L_800C7C74:
    // 0x800C7C74: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
L_800C7C78:
    // 0x800C7C78: bne         $a0, $v1, L_800C7C18
    if (ctx->r4 != ctx->r3) {
        // 0x800C7C7C: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_800C7C18;
    }
    // 0x800C7C7C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800C7C80: beql        $v1, $t1, L_800C7E18
    if (ctx->r3 == ctx->r9) {
        // 0x800C7C84: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_800C7E18;
    }
    goto skip_3;
    // 0x800C7C84: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_3:
    // 0x800C7C88: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
L_800C7C8C:
    // 0x800C7C8C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C7C90: c.eq.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl == ctx->f0.fl;
    // 0x800C7C94: nop

    // 0x800C7C98: bc1fl       L_800C7CEC
    if (!c1cs) {
        // 0x800C7C9C: lwc1        $f6, 0xC($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
            goto L_800C7CEC;
    }
    goto skip_4;
    // 0x800C7C9C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    skip_4:
    // 0x800C7CA0: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800C7CA4: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800C7CA8: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800C7CAC: nop

    // 0x800C7CB0: bc1fl       L_800C7CEC
    if (!c1cs) {
        // 0x800C7CB4: lwc1        $f6, 0xC($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
            goto L_800C7CEC;
    }
    goto skip_5;
    // 0x800C7CB4: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    skip_5:
    // 0x800C7CB8: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800C7CBC: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800C7CC0: c.eq.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl == ctx->f4.fl;
    // 0x800C7CC4: nop

    // 0x800C7CC8: bc1f        L_800C7CE8
    if (!c1cs) {
        // 0x800C7CCC: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800C7CE8;
    }
    // 0x800C7CCC: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800C7CD0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800C7CD4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800C7CD8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C7CDC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C7CE0: jr          $ra
    // 0x800C7CE4: div.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    return;
    // 0x800C7CE4: div.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
L_800C7CE8:
    // 0x800C7CE8: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
L_800C7CEC:
    // 0x800C7CEC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800C7CF0: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x800C7CF4: nop

    // 0x800C7CF8: bc1fl       L_800C7D4C
    if (!c1cs) {
        // 0x800C7CFC: lwc1        $f16, 0x18($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X18);
            goto L_800C7D4C;
    }
    goto skip_6;
    // 0x800C7CFC: lwc1        $f16, 0x18($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X18);
    skip_6:
    // 0x800C7D00: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800C7D04: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800C7D08: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x800C7D0C: nop

    // 0x800C7D10: bc1fl       L_800C7D4C
    if (!c1cs) {
        // 0x800C7D14: lwc1        $f16, 0x18($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X18);
            goto L_800C7D4C;
    }
    goto skip_7;
    // 0x800C7D14: lwc1        $f16, 0x18($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X18);
    skip_7:
    // 0x800C7D18: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800C7D1C: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800C7D20: c.eq.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl == ctx->f10.fl;
    // 0x800C7D24: nop

    // 0x800C7D28: bc1f        L_800C7D48
    if (!c1cs) {
        // 0x800C7D2C: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800C7D48;
    }
    // 0x800C7D2C: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800C7D30: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800C7D34: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800C7D38: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C7D3C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C7D40: jr          $ra
    // 0x800C7D44: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    return;
    // 0x800C7D44: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
L_800C7D48:
    // 0x800C7D48: lwc1        $f16, 0x18($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X18);
L_800C7D4C:
    // 0x800C7D4C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800C7D50: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x800C7D54: nop

    // 0x800C7D58: bc1fl       L_800C7DAC
    if (!c1cs) {
        // 0x800C7D5C: lwc1        $f4, 0x24($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
            goto L_800C7DAC;
    }
    goto skip_8;
    // 0x800C7D5C: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
    skip_8:
    // 0x800C7D60: lwc1        $f10, 0x1C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800C7D64: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800C7D68: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x800C7D6C: nop

    // 0x800C7D70: bc1fl       L_800C7DAC
    if (!c1cs) {
        // 0x800C7D74: lwc1        $f4, 0x24($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
            goto L_800C7DAC;
    }
    goto skip_9;
    // 0x800C7D74: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
    skip_9:
    // 0x800C7D78: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x800C7D7C: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800C7D80: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800C7D84: nop

    // 0x800C7D88: bc1f        L_800C7DA8
    if (!c1cs) {
        // 0x800C7D8C: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_800C7DA8;
    }
    // 0x800C7D8C: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x800C7D90: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800C7D94: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800C7D98: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C7D9C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C7DA0: jr          $ra
    // 0x800C7DA4: div.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    return;
    // 0x800C7DA4: div.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
L_800C7DA8:
    // 0x800C7DA8: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
L_800C7DAC:
    // 0x800C7DAC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800C7DB0: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x800C7DB4: nop

    // 0x800C7DB8: bc1fl       L_800C7E0C
    if (!c1cs) {
        // 0x800C7DBC: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_800C7E0C;
    }
    goto skip_10;
    // 0x800C7DBC: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_10:
    // 0x800C7DC0: lwc1        $f6, 0x28($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X28);
    // 0x800C7DC4: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800C7DC8: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800C7DCC: nop

    // 0x800C7DD0: bc1fl       L_800C7E0C
    if (!c1cs) {
        // 0x800C7DD4: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_800C7E0C;
    }
    goto skip_11;
    // 0x800C7DD4: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_11:
    // 0x800C7DD8: lwc1        $f10, 0x2C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x800C7DDC: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800C7DE0: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800C7DE4: nop

    // 0x800C7DE8: bc1f        L_800C7E08
    if (!c1cs) {
        // 0x800C7DEC: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_800C7E08;
    }
    // 0x800C7DEC: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800C7DF0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800C7DF4: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800C7DF8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C7DFC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C7E00: jr          $ra
    // 0x800C7E04: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    return;
    // 0x800C7E04: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
L_800C7E08:
    // 0x800C7E08: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
L_800C7E0C:
    // 0x800C7E0C: bne         $v1, $a3, L_800C7C8C
    if (ctx->r3 != ctx->r7) {
        // 0x800C7E10: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_800C7C8C;
    }
    // 0x800C7E10: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_800C7E14:
    // 0x800C7E14: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_800C7E18:
    // 0x800C7E18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800C7E1C: nop

    // 0x800C7E20: jr          $ra
    // 0x800C7E24: nop

    return;
    // 0x800C7E24: nop

;}
RECOMP_FUNC void func_80806BA0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806BA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80806BA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80806BA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80806BAC: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x80806BB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80806BB4: lbu         $a1, 0x218($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X218);
    // 0x80806BB8: jal         0x80809540
    // 0x80806BBC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80809540_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80806BBC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80806BC0: beq         $v0, $zero, L_80806BE0
    if (ctx->r2 == 0) {
        // 0x80806BC4: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80806BE0;
    }
    // 0x80806BC4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80806BC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80806BCC: beql        $v0, $a0, L_80806C08
    if (ctx->r2 == ctx->r4) {
        // 0x80806BD0: lbu         $t7, 0x218($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X218);
            goto L_80806C08;
    }
    goto skip_0;
    // 0x80806BD0: lbu         $t7, 0x218($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X218);
    skip_0:
    // 0x80806BD4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80806BD8: beql        $v0, $a0, L_80806C28
    if (ctx->r2 == ctx->r4) {
        // 0x80806BDC: lbu         $t8, 0x218($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X218);
            goto L_80806C28;
    }
    goto skip_1;
    // 0x80806BDC: lbu         $t8, 0x218($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X218);
    skip_1:
L_80806BE0:
    // 0x80806BE0: lbu         $t6, 0x218($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X218);
    // 0x80806BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806BE8: beql        $t6, $zero, L_80806C48
    if (ctx->r14 == 0) {
        // 0x80806BEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80806C48;
    }
    goto skip_2;
    // 0x80806BEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80806BF0: jal         0x80808D80
    // 0x80806BF4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80808D80_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80806BF4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80806BF8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80806BFC: b           L_80806C44
    // 0x80806C00: sb          $zero, 0x218($v1)
    MEM_B(0X218, ctx->r3) = 0;
        goto L_80806C44;
    // 0x80806C00: sb          $zero, 0x218($v1)
    MEM_B(0X218, ctx->r3) = 0;
    // 0x80806C04: lbu         $t7, 0x218($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X218);
L_80806C08:
    // 0x80806C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80806C0C: beq         $a0, $t7, L_80806C3C
    if (ctx->r4 == ctx->r15) {
        // 0x80806C10: nop
    
            goto L_80806C3C;
    }
    // 0x80806C10: nop

    // 0x80806C14: jal         0x80809684
    // 0x80806C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809684_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80806C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80806C1C: b           L_80806C3C
    // 0x80806C20: nop

        goto L_80806C3C;
    // 0x80806C20: nop

    // 0x80806C24: lbu         $t8, 0x218($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X218);
L_80806C28:
    // 0x80806C28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80806C2C: beq         $a0, $t8, L_80806C3C
    if (ctx->r4 == ctx->r24) {
        // 0x80806C30: nop
    
            goto L_80806C3C;
    }
    // 0x80806C30: nop

    // 0x80806C34: jal         0x80809684
    // 0x80806C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809684_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80806C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80806C3C:
    // 0x80806C3C: jal         0x80809740
    // 0x80806C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809740_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80806C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80806C44:
    // 0x80806C44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806C48:
    // 0x80806C48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80806C4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80806C50: jr          $ra
    // 0x80806C54: nop

    return;
    // 0x80806C54: nop

;}
RECOMP_FUNC void cadbmgrDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080000C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800014: addiu       $a0, $t6, 0x40
    ctx->r4 = ADD32(ctx->r14, 0X40);
    // 0x80800018: jal         0x8001ACCC
    // 0x8080001C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800020: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800028: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8080002C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80800030: addiu       $v0, $zero, 0x24
    ctx->r2 = ADD32(0, 0X24);
L_80800034:
    // 0x80800034: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80800038: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8080003C: sh          $zero, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = 0;
    // 0x80800040: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80800044: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80800048: sw          $zero, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = 0;
    // 0x8080004C: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80800050: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x80800054: sh          $zero, 0x20($t2)
    MEM_H(0X20, ctx->r10) = 0;
    // 0x80800058: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8080005C: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x80800060: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x80800064: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80800068: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x8080006C: sh          $zero, 0x22($t6)
    MEM_H(0X22, ctx->r14) = 0;
    // 0x80800070: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80800074: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80800078: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8080007C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80800080: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x80800084: sh          $zero, 0x24($t0)
    MEM_H(0X24, ctx->r8) = 0;
    // 0x80800088: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8080008C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80800090: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x80800094: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80800098: bne         $v1, $v0, L_80800034
    if (ctx->r3 != ctx->r2) {
        // 0x8080009C: sw          $zero, 0x8($t2)
        MEM_W(0X8, ctx->r10) = 0;
            goto L_80800034;
    }
    // 0x8080009C: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x808000A0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x808000A8: jal         0x800A56A4
    // 0x808000AC: sw          $t3, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->r11;
    func_800A56A4(rdram, ctx);
        goto after_1;
    // 0x808000AC: sw          $t3, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->r11;
    after_1:
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829D8: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x800829D8);
    return;
    // 0x800829DC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _gspropctrl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BB0: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088BB0);
    return;
    // 0x80088BB4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void freelist_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B324C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3250: jal         0x8001B084
    // 0x800B3254: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800B3254: nop

    after_0:
    // 0x800B3258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B325C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B3260: jr          $ra
    // 0x800B3264: nop

    return;
    // 0x800B3264: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014C4: beql        $a1, $zero, L_808014E0
    if (ctx->r5 == 0) {
        // 0x808014C8: lbu         $t9, 0x1D($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X1D);
            goto L_808014E0;
    }
    goto skip_0;
    // 0x808014C8: lbu         $t9, 0x1D($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1D);
    skip_0:
    // 0x808014CC: lbu         $t6, 0x1D($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1D);
    // 0x808014D0: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x808014D4: jr          $ra
    // 0x808014D8: sb          $t7, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r15;
    return;
    // 0x808014D8: sb          $t7, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r15;
    // 0x808014DC: lbu         $t9, 0x1D($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1D);
L_808014E0:
    // 0x808014E0: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x808014E4: sb          $t0, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r8;
    // 0x808014E8: jr          $ra
    // 0x808014EC: nop

    return;
    // 0x808014EC: nop

;}
RECOMP_FUNC void _bsrest_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839E0: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x800839E0);
    return;
    // 0x800839E4: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void chphlegm_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1064, 0XBE8) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0xBE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1064, 0XBE8));
    return;
    // 0x80800020: addiu       $v0, $v0, 0xBE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1064, 0XBE8));
;}
RECOMP_FUNC void func_80013ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013ABC: lui         $at, 0x4880
    ctx->r1 = S32(0X4880 << 16);
    // 0x80013AC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80013AC4: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80013AC8: addiu       $t8, $t8, -0x3360
    ctx->r24 = ADD32(ctx->r24, -0X3360);
    // 0x80013ACC: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80013AD0: trunc.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80013AD4: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x80013AD8: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80013ADC: addiu       $t9, $t9, -0x2C60
    ctx->r25 = ADD32(ctx->r25, -0X2C60);
    // 0x80013AE0: bgtzl       $v0, L_80013AF8
    if (SIGNED(ctx->r2) > 0) {
        // 0x80013AE4: srl         $t1, $v0, 12
        ctx->r9 = S32(U32(ctx->r2) >> 12);
            goto L_80013AF8;
    }
    goto skip_0;
    // 0x80013AE4: srl         $t1, $v0, 12
    ctx->r9 = S32(U32(ctx->r2) >> 12);
    skip_0:
    // 0x80013AE8: abs.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = fabsf(ctx->f12.fl);
    // 0x80013AEC: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x80013AF0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80013AF4: srl         $t1, $v0, 12
    ctx->r9 = S32(U32(ctx->r2) >> 12);
L_80013AF8:
    // 0x80013AF8: addu        $t0, $t1, $t8
    ctx->r8 = ADD32(ctx->r9, ctx->r24);
    // 0x80013AFC: lb          $v1, 0x0($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X0);
    // 0x80013B00: bgezl       $v1, L_80013B18
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80013B04: addu        $t0, $v1, $t8
        ctx->r8 = ADD32(ctx->r3, ctx->r24);
            goto L_80013B18;
    }
    goto skip_1;
    // 0x80013B04: addu        $t0, $v1, $t8
    ctx->r8 = ADD32(ctx->r3, ctx->r24);
    skip_1:
    // 0x80013B08: srl         $t1, $v0, 6
    ctx->r9 = S32(U32(ctx->r2) >> 6);
    // 0x80013B0C: addu        $t0, $t1, $t8
    ctx->r8 = ADD32(ctx->r9, ctx->r24);
    // 0x80013B10: lb          $v1, -0xF7F($t0)
    ctx->r3 = MEM_B(ctx->r8, -0XF7F);
    // 0x80013B14: addu        $t0, $v1, $t8
    ctx->r8 = ADD32(ctx->r3, ctx->r24);
L_80013B18:
    // 0x80013B18: lw          $a0, 0x84($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X84);
    // 0x80013B1C: lw          $a2, 0x8C($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8C);
    // 0x80013B20: lw          $a1, 0x88($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X88);
    // 0x80013B24: subu        $t1, $v0, $a0
    ctx->r9 = SUB32(ctx->r2, ctx->r4);
    // 0x80013B28: srlv        $t1, $t1, $a2
    ctx->r9 = S32(U32(ctx->r9) >> (ctx->r6 & 31));
    // 0x80013B2C: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x80013B30: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80013B34: addu        $t0, $t1, $t8
    ctx->r8 = ADD32(ctx->r9, ctx->r24);
    // 0x80013B38: lh          $v1, 0xF4($t0)
    ctx->r3 = MEM_H(ctx->r8, 0XF4);
    // 0x80013B3C: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x80013B40: addu        $t0, $t1, $t9
    ctx->r8 = ADD32(ctx->r9, ctx->r25);
    // 0x80013B44: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80013B48: lwc1        $f2, 0x4($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80013B4C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80013B50: sub.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80013B54: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80013B58: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80013B5C: div.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80013B60: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80013B64: mul.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80013B68: jr          $ra
    // 0x80013B6C: nop

    return;
    // 0x80013B6C: nop

;}
RECOMP_FUNC void func_8009D89C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D89C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009D8A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D8A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009D8A8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8009D8AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009D8B0: jal         0x8009C128
    // 0x8009D8B4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8009D8B4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8009D8B8: lw          $t6, 0x104($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X104);
    // 0x8009D8BC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8009D8C0: jal         0x800C35E8
    // 0x8009D8C4: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    func_800C35E8(rdram, ctx);
        goto after_1;
    // 0x8009D8C4: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    after_1:
    // 0x8009D8C8: lw          $v0, 0x104($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X104);
    // 0x8009D8CC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009D8D0: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8009D8D4: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x8009D8D8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8009D8DC: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8009D8E0: jal         0x800C301C
    // 0x8009D8E4: lh          $a1, -0x6E00($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X6E00);
    func_800C301C(rdram, ctx);
        goto after_2;
    // 0x8009D8E4: lh          $a1, -0x6E00($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X6E00);
    after_2:
    // 0x8009D8E8: lw          $t9, 0x104($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X104);
    // 0x8009D8EC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8009D8F0: jal         0x800C31DC
    // 0x8009D8F4: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    func_800C31DC(rdram, ctx);
        goto after_3;
    // 0x8009D8F4: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    after_3:
    // 0x8009D8F8: lw          $t0, 0x104($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X104);
    // 0x8009D8FC: jal         0x800C3BDC
    // 0x8009D900: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    func_800C3BDC(rdram, ctx);
        goto after_4;
    // 0x8009D900: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    after_4:
    // 0x8009D904: lw          $v0, 0x104($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X104);
    // 0x8009D908: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x8009D90C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8009D910: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x8009D914: lw          $v0, 0x104($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X104);
    // 0x8009D918: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x8009D91C: sltiu       $at, $t3, 0x4
    ctx->r1 = ctx->r11 < 0X4 ? 1 : 0;
    // 0x8009D920: bnel        $at, $zero, L_8009D930
    if (ctx->r1 != 0) {
        // 0x8009D924: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009D930;
    }
    goto skip_0;
    // 0x8009D924: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8009D928: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8009D92C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D930:
    // 0x8009D930: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009D934: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009D938: jr          $ra
    // 0x8009D93C: nop

    return;
    // 0x8009D93C: nop

;}
RECOMP_FUNC void baphysics_reset_gravity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BC6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BC70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BC74: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8009BC78: jal         0x8009BCB4
    // 0x8009BC7C: lw          $a1, 0x7EF0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7EF0);
    baphysics_set_gravity(rdram, ctx);
        goto after_0;
    // 0x8009BC7C: lw          $a1, 0x7EF0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7EF0);
    after_0:
    // 0x8009BC80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BC84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BC88: jr          $ra
    // 0x8009BC8C: nop

    return;
    // 0x8009BC8C: nop

;}
RECOMP_FUNC void func_808056B8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808056B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808056BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808056C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808056C4: jal         0x80100094
    // 0x808056C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808056C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808056CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808056D0: jal         0x8010A570
    // 0x808056D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x808056D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808056D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808056DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808056E0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808056E4: swc1        $f4, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f4.u32l;
    // 0x808056E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808056EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808056F0: jr          $ra
    // 0x808056F4: nop

    return;
    // 0x808056F4: nop

;}
RECOMP_FUNC void func_808001FC_chdinofamilysick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800204: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800208: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080020C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800210: addiu       $a0, $zero, 0x52D
    ctx->r4 = ADD32(0, 0X52D);
    // 0x80800214: jal         0x800882C0
    // 0x80800218: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800218: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8080021C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800220: jal         0x80088C00
    // 0x80800224: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800224: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800228: jal         0x80088C08
    // 0x8080022C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _gspropctrl_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x8080022C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800234: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800238: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080023C: jr          $ra
    // 0x80800240: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    return;
    // 0x80800240: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
;}
RECOMP_FUNC void func_80800390_suegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800390: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80800394: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800398: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8080039C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003A0: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x808003A4: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x808003A8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x808003AC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x808003B0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x808003B4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x808003B8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x808003BC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x808003C0: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x808003C4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x808003C8: jal         0x80100094
    // 0x808003CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003D0: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x808003D4: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x808003D8: jal         0x800EA068
    // 0x808003DC: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    func_800EA068(rdram, ctx);
        goto after_1;
    // 0x808003DC: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_1:
    // 0x808003E0: beq         $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808003E4: addiu       $s5, $sp, 0x9C
        ctx->r21 = ADD32(ctx->r29, 0X9C);
            goto L_808004FC;
    }
    // 0x808003E4: addiu       $s5, $sp, 0x9C
    ctx->r21 = ADD32(ctx->r29, 0X9C);
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003EC: jal         0x80800BFC
    // 0x808003F0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    suegg_entrypoint_18(rdram, ctx);
        goto after_2;
    // 0x808003F0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_2:
    // 0x808003F4: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x808003F8: jal         0x800EE7F8
    // 0x808003FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808003FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800400: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800404: jal         0x800EA068
    // 0x80800408: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800EA068(rdram, ctx);
        goto after_4;
    // 0x80800408: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_4:
    // 0x8080040C: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80800410: jal         0x800F5898
    // 0x80800414: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_5;
    // 0x80800414: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_5:
    // 0x80800418: blez        $v0, L_808004FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080041C: addiu       $s7, $sp, 0x7C
        ctx->r23 = ADD32(ctx->r29, 0X7C);
            goto L_808004FC;
    }
    // 0x8080041C: addiu       $s7, $sp, 0x7C
    ctx->r23 = ADD32(ctx->r29, 0X7C);
    // 0x80800420: addiu       $s4, $sp, 0x84
    ctx->r20 = ADD32(ctx->r29, 0X84);
    // 0x80800424: addiu       $s3, $sp, 0x64
    ctx->r19 = ADD32(ctx->r29, 0X64);
    // 0x80800428: addiu       $s2, $sp, 0x68
    ctx->r18 = ADD32(ctx->r29, 0X68);
    // 0x8080042C: addiu       $s1, $sp, 0x6C
    ctx->r17 = ADD32(ctx->r29, 0X6C);
L_80800430:
    // 0x80800430: jal         0x800F6438
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_6;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800438: beq         $v0, $zero, L_808004E8
    if (ctx->r2 == 0) {
        // 0x8080043C: lw          $t6, 0xB4($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XB4);
            goto L_808004E8;
    }
    // 0x8080043C: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x80800440: lh          $t7, 0x3A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X3A);
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: beq         $s0, $t7, L_808004E8
    if (ctx->r16 == ctx->r15) {
        // 0x8080044C: nop
    
            goto L_808004E8;
    }
    // 0x8080044C: nop

    // 0x80800450: jal         0x800F5A00
    // 0x80800454: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F5A00(rdram, ctx);
        goto after_7;
    // 0x80800454: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80800458: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080045C: jal         0x800EEB40
    // 0x80800460: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EEB40(rdram, ctx);
        goto after_8;
    // 0x80800460: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_8:
    // 0x80800464: bltz        $s6, L_8080047C
    if (SIGNED(ctx->r22) < 0) {
        // 0x80800468: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_8080047C;
    }
    // 0x80800468: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8080046C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80800470: nop

    // 0x80800474: bc1f        L_808004E8
    if (!c1cs) {
        // 0x80800478: nop
    
            goto L_808004E8;
    }
    // 0x80800478: nop

L_8080047C:
    // 0x8080047C: beq         $fp, $zero, L_808004A4
    if (ctx->r30 == 0) {
        // 0x80800480: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004A4;
    }
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800484: jal         0x800F53D0
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F53D0(rdram, ctx);
        goto after_9;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080048C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800490: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800494: jal         0x800842C0
    // 0x80800498: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    _bsfirstp_entrypoint_7(rdram, ctx);
        goto after_10;
    // 0x80800498: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_10:
    // 0x8080049C: b           L_808004B8
    // 0x808004A0: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
        goto L_808004B8;
    // 0x808004A0: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
L_808004A4:
    // 0x808004A4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808004A8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x808004AC: jal         0x800F551C
    // 0x808004B0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_800F551C(rdram, ctx);
        goto after_11;
    // 0x808004B0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_11:
    // 0x808004B4: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
L_808004B8:
    // 0x808004B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808004BC: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x808004C0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808004C4: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x808004C8: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x808004CC: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x808004D0: jal         0x800F0734
    // 0x808004D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F0734(rdram, ctx);
        goto after_12;
    // 0x808004D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x808004D8: beq         $v0, $zero, L_808004E8
    if (ctx->r2 == 0) {
        // 0x808004DC: nop
    
            goto L_808004E8;
    }
    // 0x808004DC: nop

    // 0x808004E0: or          $s6, $s0, $zero
    ctx->r22 = ctx->r16 | 0;
    // 0x808004E4: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
L_808004E8:
    // 0x808004E8: jal         0x800F5898
    // 0x808004EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_13;
    // 0x808004EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_13:
    // 0x808004F0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808004F4: bne         $at, $zero, L_80800430
    if (ctx->r1 != 0) {
        // 0x808004F8: nop
    
            goto L_80800430;
    }
    // 0x808004F8: nop

L_808004FC:
    // 0x808004FC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80800500: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80800504: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80800508: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8080050C: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80800510: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800514: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80800518: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8080051C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80800520: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80800524: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80800528: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8080052C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80800530: jr          $ra
    // 0x80800534: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80800534: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void _idtwinkle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DE8: syscall     742
    recomp_syscall_handler(rdram, ctx, 0x80088DE8);
    return;
    // 0x80088DEC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsbshock_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800840: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800844: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(116, 0X880) << 16);
    // 0x80800848: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080084C: jr          $ra
    // 0x80800850: lw          $v0, 0x880($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(116, 0X880));
    return;
    // 0x80800850: lw          $v0, 0x880($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(116, 0X880));
    // 0x80800854: nop

    // 0x80800858: nop

    // 0x8080085C: nop

;}
RECOMP_FUNC void chkingjinjobits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C4: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x808007C8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x808007CC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x808007D0: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x808007D4: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x808007D8: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x808007DC: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x808007E0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808007E4: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x808007E8: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x808007EC: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x808007F0: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x808007F4: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808007F8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808007FC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800800: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800804: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800808: jal         0x80106790
    // 0x8080080C: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080080C: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    after_0:
    // 0x80800810: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
    // 0x80800814: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800818: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    // 0x8080081C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800820: beq         $t7, $zero, L_80800854
    if (ctx->r15 == 0) {
        // 0x80800824: lui         $a3, 0x453B
        ctx->r7 = S32(0X453B << 16);
            goto L_80800854;
    }
    // 0x80800824: lui         $a3, 0x453B
    ctx->r7 = S32(0X453B << 16);
    // 0x80800828: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1464, 0XA74) << 16);
    // 0x8080082C: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80800830: lwc1        $f4, 0xA74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1464, 0XA74));
    // 0x80800834: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80800838: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    // 0x8080083C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80800840: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800844: jal         0x800F12D4
    // 0x80800848: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x80800848: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    after_1:
    // 0x8080084C: b           L_80800878
    // 0x80800850: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_80800878;
    // 0x80800850: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80800854:
    // 0x80800854: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800858: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x8080085C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800860: lwc1        $f12, 0x58($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X58);
    // 0x80800864: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80800868: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    // 0x8080086C: jal         0x800F12D4
    // 0x80800870: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F12D4(rdram, ctx);
        goto after_2;
    // 0x80800870: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80800874: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80800878:
    // 0x80800878: sll         $t8, $s2, 4
    ctx->r24 = S32(ctx->r18 << 4);
    // 0x8080087C: addu        $s5, $t8, $s1
    ctx->r21 = ADD32(ctx->r24, ctx->r17);
    // 0x80800880: sltu        $at, $s1, $s5
    ctx->r1 = ctx->r17 < ctx->r21 ? 1 : 0;
    // 0x80800884: beq         $at, $zero, L_808009A8
    if (ctx->r1 == 0) {
        // 0x80800888: addiu       $s4, $zero, 0xFF
        ctx->r20 = ADD32(0, 0XFF);
            goto L_808009A8;
    }
    // 0x80800888: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // 0x8080088C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800890: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800894: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800898: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(1464, 0XAC8) << 16);
    // 0x8080089C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808008A0: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x808008A4: addiu       $s3, $s3, 0xAC8
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1464, 0XAC8));
    // 0x808008A8: addiu       $s2, $sp, 0x70
    ctx->r18 = ADD32(ctx->r29, 0X70);
L_808008AC:
    // 0x808008AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808008B0: jal         0x800EE88C
    // 0x808008B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x808008B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x808008B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808008BC: jal         0x800EEAD4
    // 0x808008C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_4;
    // 0x808008C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x808008C4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808008C8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808008CC: bc1fl       L_808008E0
    if (!c1cs) {
        // 0x808008D0: add.s       $f8, $f20, $f22
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f22.fl;
            goto L_808008E0;
    }
    goto skip_0;
    // 0x808008D0: add.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f22.fl;
    skip_0:
    // 0x808008D4: b           L_80800998
    // 0x808008D8: sb          $zero, 0xF($s0)
    MEM_B(0XF, ctx->r16) = 0;
        goto L_80800998;
    // 0x808008D8: sb          $zero, 0xF($s0)
    MEM_B(0XF, ctx->r16) = 0;
    // 0x808008DC: add.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f22.fl;
L_808008E0:
    // 0x808008E0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808008E4: nop

    // 0x808008E8: bc1fl       L_808008FC
    if (!c1cs) {
        // 0x808008EC: mfc1        $a2, $f22
        ctx->r6 = (int32_t)ctx->f22.u32l;
            goto L_808008FC;
    }
    goto skip_1;
    // 0x808008EC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    skip_1:
    // 0x808008F0: b           L_80800998
    // 0x808008F4: sb          $s4, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r20;
        goto L_80800998;
    // 0x808008F4: sb          $s4, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r20;
    // 0x808008F8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
L_808008FC:
    // 0x808008FC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800900: sub.s       $f12, $f2, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x80800904: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    // 0x80800908: jal         0x800F10B4
    // 0x8080090C: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x8080090C: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    after_5:
    // 0x80800910: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800914: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800918: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8080091C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800920: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80800924: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80800928: nop

    // 0x8080092C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80800930: beql        $t0, $zero, L_80800980
    if (ctx->r8 == 0) {
        // 0x80800934: mfc1        $t0, $f10
        ctx->r8 = (int32_t)ctx->f10.u32l;
            goto L_80800980;
    }
    goto skip_2;
    // 0x80800934: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    skip_2:
    // 0x80800938: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080093C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800940: sub.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80800944: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80800948: nop

    // 0x8080094C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800950: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80800954: nop

    // 0x80800958: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8080095C: bne         $t0, $zero, L_80800974
    if (ctx->r8 != 0) {
        // 0x80800960: nop
    
            goto L_80800974;
    }
    // 0x80800960: nop

    // 0x80800964: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80800968: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080096C: b           L_8080098C
    // 0x80800970: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8080098C;
    // 0x80800970: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80800974:
    // 0x80800974: b           L_8080098C
    // 0x80800978: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8080098C;
    // 0x80800978: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8080097C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
L_80800980:
    // 0x80800980: nop

    // 0x80800984: bltz        $t0, L_80800974
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800988: nop
    
            goto L_80800974;
    }
    // 0x80800988: nop

L_8080098C:
    // 0x8080098C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800990: sb          $t0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r8;
    // 0x80800994: nop

L_80800998:
    // 0x80800998: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8080099C: sltu        $at, $s1, $s5
    ctx->r1 = ctx->r17 < ctx->r21 ? 1 : 0;
    // 0x808009A0: bne         $at, $zero, L_808008AC
    if (ctx->r1 != 0) {
        // 0x808009A4: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_808008AC;
    }
    // 0x808009A4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_808009A8:
    // 0x808009A8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x808009AC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808009B0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808009B4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808009B8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808009BC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808009C0: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x808009C4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x808009C8: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x808009CC: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x808009D0: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x808009D4: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x808009D8: jr          $ra
    // 0x808009DC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x808009DC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80104248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010424C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104250: jal         0x80104200
    // 0x80104254: lh          $a0, 0x8C($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X8C);
    func_80104200(rdram, ctx);
        goto after_0;
    // 0x80104254: lh          $a0, 0x8C($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X8C);
    after_0:
    // 0x80104258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010425C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80104260: jr          $ra
    // 0x80104264: nop

    return;
    // 0x80104264: nop

;}
RECOMP_FUNC void basudie_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808000F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800100: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800104: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800108: jal         0x80800020
    // 0x8080010C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    basudie_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080010C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800110: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800114: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800120: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800124: jal         0x8009FFD8
    // 0x80800128: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800128: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: jal         0x8009C128
    // 0x80800134: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8009C128(rdram, ctx);
        goto after_2;
    // 0x80800134: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: jal         0x800A32C4
    // 0x80800140: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800A32C4(rdram, ctx);
        goto after_3;
    // 0x80800140: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80800144: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800148: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8080014C: jal         0x800F1E6C
    // 0x80800150: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800F1E6C(rdram, ctx);
        goto after_4;
    // 0x80800150: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_4:
    // 0x80800154: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800158: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080015C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800160: jal         0x800136E4
    // 0x80800164: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x80800164: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_5:
    // 0x80800168: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080016C: jal         0x8009C914
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_6;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800174: jal         0x8009C974
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_7;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: jal         0x8009B9B0
    // 0x80800184: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x80800184: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_8:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: jal         0x8009B9C0
    // 0x80800190: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_9;
    // 0x80800190: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_9:
    // 0x80800194: jal         0x8009BB00
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080019C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x8009BA68
    // 0x808001A8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x808001A8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_11:
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: jal         0x8009BA58
    // 0x808001B4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_12;
    // 0x808001B4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_12:
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x8009BCB4
    // 0x808001C0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    baphysics_set_gravity(rdram, ctx);
        goto after_13;
    // 0x808001C0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_13:
    // 0x808001C4: jal         0x8008E944
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_14;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808001CC: jal         0x8009514C
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009514C(rdram, ctx);
        goto after_15;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: jal         0x800A4DFC
    // 0x808001DC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A4DFC(rdram, ctx);
        goto after_16;
    // 0x808001DC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_16:
    // 0x808001E0: jal         0x800A4C68
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_17;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808001E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001EC: jal         0x800C52F4
    // 0x808001F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C52F4(rdram, ctx);
        goto after_18;
    // 0x808001F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
    // 0x808001F4: jal         0x800A4CA8
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_19;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808001FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800200: jal         0x80089288
    // 0x80800204: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    _ncbadie_entrypoint_3(rdram, ctx);
        goto after_20;
    // 0x80800204: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_20:
    // 0x80800208: jal         0x800A0180
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0180(rdram, ctx);
        goto after_21;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800218: jal         0x80085338
    // 0x8080021C: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    _batimer_set(rdram, ctx);
        goto after_22;
    // 0x8080021C: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    after_22:
    // 0x80800220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800224: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800228: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8080022C: jr          $ra
    // 0x80800230: nop

    return;
    // 0x80800230: nop

;}
RECOMP_FUNC void _subaddiedialog_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A1F8: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A1F8);
    return;
    // 0x8008A1FC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80098890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098890: jr          $ra
    // 0x80098894: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x80098894: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800F8A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8A80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8A88: jal         0x800F88A0
    // 0x800F8A8C: nop

    func_800F88A0(rdram, ctx);
        goto after_0;
    // 0x800F8A8C: nop

    after_0:
    // 0x800F8A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8A94: lbu         $v0, 0x21($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X21);
    // 0x800F8A98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8A9C: jr          $ra
    // 0x800F8AA0: nop

    return;
    // 0x800F8AA0: nop

;}
RECOMP_FUNC void func_8009FF44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FF44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009FF48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009FF4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009FF50: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8009FF54: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8009FF58: jal         0x8008CABC
    // 0x8009FF5C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8009FF5C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8009FF60: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8009FF64: jal         0x8008B264
    // 0x8009FF68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getIndex(rdram, ctx);
        goto after_1;
    // 0x8009FF68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8009FF6C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8009FF70: beql        $v0, $a1, L_8009FF8C
    if (ctx->r2 == ctx->r5) {
        // 0x8009FF74: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8009FF8C;
    }
    goto skip_0;
    // 0x8009FF74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x8009FF78: jal         0x8008AED4
    // 0x8009FF7C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x8009FF7C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8009FF80: jal         0x8008B064
    // 0x8009FF84: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_start(rdram, ctx);
        goto after_3;
    // 0x8009FF84: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x8009FF88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_8009FF8C:
    // 0x8009FF8C: jal         0x8008CA4C
    // 0x8009FF90: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008CA4C(rdram, ctx);
        goto after_4;
    // 0x8009FF90: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8009FF94: lui         $a1, 0x3E70
    ctx->r5 = S32(0X3E70 << 16);
    // 0x8009FF98: lui         $a2, 0x407F
    ctx->r6 = S32(0X407F << 16);
    // 0x8009FF9C: ori         $a2, $a2, 0x34D7
    ctx->r6 = ctx->r6 | 0X34D7;
    // 0x8009FFA0: ori         $a1, $a1, 0x20C5
    ctx->r5 = ctx->r5 | 0X20C5;
    // 0x8009FFA4: jal         0x8008C9BC
    // 0x8009FFA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    baanim_setDurationRange(rdram, ctx);
        goto after_5;
    // 0x8009FFA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x8009FFAC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009FFB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8009FFB4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8009FFB8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8009FFBC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8009FFC0: jal         0x8008C9F0
    // 0x8009FFC4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_6;
    // 0x8009FFC4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x8009FFC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009FFCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009FFD0: jr          $ra
    // 0x8009FFD4: nop

    return;
    // 0x8009FFD4: nop

;}
RECOMP_FUNC void chfairgroundworker_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(840, 0X398) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x398
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(840, 0X398));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x398
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(840, 0X398));
;}
RECOMP_FUNC void func_808001A4_bskazstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001B4: jal         0x8008E39C
    // 0x808001B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8008E39C(rdram, ctx);
        goto after_0;
    // 0x808001B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: jal         0x8009EF10
    // 0x808001C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x808001C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808001C8: beq         $v0, $zero, L_8080020C
    if (ctx->r2 == 0) {
        // 0x808001CC: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8080020C;
    }
    // 0x808001CC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808001D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001D4: beq         $v0, $at, L_808001EC
    if (ctx->r2 == ctx->r1) {
        // 0x808001D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001EC;
    }
    // 0x808001D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001DC: beq         $v0, $at, L_80800208
    if (ctx->r2 == ctx->r1) {
        // 0x808001E0: addiu       $t8, $zero, 0xC7
        ctx->r24 = ADD32(0, 0XC7);
            goto L_80800208;
    }
    // 0x808001E0: addiu       $t8, $zero, 0xC7
    ctx->r24 = ADD32(0, 0XC7);
    // 0x808001E4: b           L_8080020C
    // 0x808001E8: nop

        goto L_8080020C;
    // 0x808001E8: nop

L_808001EC:
    // 0x808001EC: beq         $v1, $zero, L_80800200
    if (ctx->r3 == 0) {
        // 0x808001F0: addiu       $t7, $zero, 0xBC
        ctx->r15 = ADD32(0, 0XBC);
            goto L_80800200;
    }
    // 0x808001F0: addiu       $t7, $zero, 0xBC
    ctx->r15 = ADD32(0, 0XBC);
    // 0x808001F4: addiu       $t6, $zero, 0xC7
    ctx->r14 = ADD32(0, 0XC7);
    // 0x808001F8: b           L_8080020C
    // 0x808001FC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
        goto L_8080020C;
    // 0x808001FC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_80800200:
    // 0x80800200: b           L_8080020C
    // 0x80800204: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_8080020C;
    // 0x80800204: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80800208:
    // 0x80800208: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_8080020C:
    // 0x8080020C: beql        $v1, $zero, L_80800254
    if (ctx->r3 == 0) {
        // 0x80800210: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800254;
    }
    goto skip_0;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800214: jal         0x8008E3E8
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E3E8(rdram, ctx);
        goto after_2;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080021C: beql        $v0, $zero, L_80800230
    if (ctx->r2 == 0) {
        // 0x80800220: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800230;
    }
    goto skip_1;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800224: jal         0x80085078
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800230:
    // 0x80800230: jal         0x80091A58
    // 0x80800234: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_4;
    // 0x80800234: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x80800238: beq         $v0, $zero, L_80800284
    if (ctx->r2 == 0) {
        // 0x8080023C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800284;
    }
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800240: jal         0x80085008
    // 0x80800244: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bashoes_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80800244: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800248: b           L_80800288
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800288;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800254:
    // 0x80800254: jal         0x800919F4
    // 0x80800258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_6;
    // 0x80800258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080025C: beq         $v0, $zero, L_80800268
    if (ctx->r2 == 0) {
        // 0x80800260: addiu       $t9, $zero, 0xDD
        ctx->r25 = ADD32(0, 0XDD);
            goto L_80800268;
    }
    // 0x80800260: addiu       $t9, $zero, 0xDD
    ctx->r25 = ADD32(0, 0XDD);
    // 0x80800264: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_80800268:
    // 0x80800268: jal         0x80097FB8
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097FB8(rdram, ctx);
        goto after_7;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800270: beql        $v0, $zero, L_80800288
    if (ctx->r2 == 0) {
        // 0x80800274: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800288;
    }
    goto skip_2;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800278: jal         0x800832F8
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800280: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80800284:
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800288:
    // 0x80800288: jal         0x80091A58
    // 0x8080028C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_9;
    // 0x8080028C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x80800290: beq         $v0, $zero, L_808002C4
    if (ctx->r2 == 0) {
        // 0x80800294: nop
    
            goto L_808002C4;
    }
    // 0x80800294: nop

    // 0x80800298: jal         0x8008D790
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D790(rdram, ctx);
        goto after_10;
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808002A0: beq         $v0, $zero, L_808002B8
    if (ctx->r2 == 0) {
        // 0x808002A4: nop
    
            goto L_808002B8;
    }
    // 0x808002A4: nop

    // 0x808002A8: jal         0x80084978
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baduo_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808002B0: b           L_808002C4
    // 0x808002B4: nop

        goto L_808002C4;
    // 0x808002B4: nop

L_808002B8:
    // 0x808002B8: jal         0x800832F0
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808002C0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_808002C4:
    // 0x808002C4: jal         0x80097AD0
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_13;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808002CC: beq         $v0, $zero, L_808002E0
    if (ctx->r2 == 0) {
        // 0x808002D0: nop
    
            goto L_808002E0;
    }
    // 0x808002D0: nop

    // 0x808002D4: jal         0x800848A8
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_14;
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808002DC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_808002E0:
    // 0x808002E0: jal         0x8008DF18
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_15;
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808002E8: beq         $v0, $zero, L_808002FC
    if (ctx->r2 == 0) {
        // 0x808002EC: nop
    
            goto L_808002FC;
    }
    // 0x808002EC: nop

    // 0x808002F0: jal         0x800848B0
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_16;
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808002F8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_808002FC:
    // 0x808002FC: jal         0x8008E35C
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_17;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800304: beq         $v0, $zero, L_80800310
    if (ctx->r2 == 0) {
        // 0x80800308: addiu       $t0, $zero, 0x15D
        ctx->r8 = ADD32(0, 0X15D);
            goto L_80800310;
    }
    // 0x80800308: addiu       $t0, $zero, 0x15D
    ctx->r8 = ADD32(0, 0X15D);
    // 0x8080030C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_80800310:
    // 0x80800310: jal         0x8008DD04
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_18;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800318: beq         $v0, $zero, L_80800328
    if (ctx->r2 == 0) {
        // 0x8080031C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800328;
    }
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800320: addiu       $t1, $zero, 0xDF
    ctx->r9 = ADD32(0, 0XDF);
    // 0x80800324: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_80800328:
    // 0x80800328: jal         0x800A02DC
    // 0x8080032C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800A02DC(rdram, ctx);
        goto after_19;
    // 0x8080032C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_19:
    // 0x80800330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800334: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800338: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080033C: jr          $ra
    // 0x80800340: nop

    return;
    // 0x80800340: nop

;}
RECOMP_FUNC void func_800F89BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F89BC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F89C0: lbu         $t6, 0x54F8($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X54F8);
    // 0x800F89C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F89C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F89CC: bne         $t6, $at, L_800F89DC
    if (ctx->r14 != ctx->r1) {
        // 0x800F89D0: nop
    
            goto L_800F89DC;
    }
    // 0x800F89D0: nop

    // 0x800F89D4: jr          $ra
    // 0x800F89D8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x800F89D8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_800F89DC:
    // 0x800F89DC: jr          $ra
    // 0x800F89E0: nop

    return;
    // 0x800F89E0: nop

;}
RECOMP_FUNC void func_80090B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090B90: jr          $ra
    // 0x80090B94: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x80090B94: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _chpotogoldgame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875B0: syscall     592
    recomp_syscall_handler(rdram, ctx, 0x800875B0);
    return;
    // 0x800875B4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void baboost_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002DC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x808002E0: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    // 0x808002E4: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x808002E8: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x808002EC: bnel        $t8, $zero, L_80800300
    if (ctx->r24 != 0) {
        // 0x808002F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800300;
    }
    goto skip_0;
    // 0x808002F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002F4: jal         0x800845A0
    // 0x808002F8: nop

    _baboost_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808002F8: nop

    after_0:
    // 0x808002FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800300:
    // 0x80800300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800304: jr          $ra
    // 0x80800308: nop

    return;
    // 0x80800308: nop

;}
RECOMP_FUNC void func_80800564_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800564: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800568: sh          $zero, 0x6($a1)
    MEM_H(0X6, ctx->r5) = 0;
    // 0x8080056C: jr          $ra
    // 0x80800570: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    return;
    // 0x80800570: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
;}
RECOMP_FUNC void func_800CB9D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB9D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB9DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB9E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CB9E4: jal         0x80087EC8
    // 0x800CB9E8: addiu       $a0, $a0, -0x5180
    ctx->r4 = ADD32(ctx->r4, -0X5180);
    _gcboundDll_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800CB9E8: addiu       $a0, $a0, -0x5180
    ctx->r4 = ADD32(ctx->r4, -0X5180);
    after_0:
    // 0x800CB9EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB9F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB9F4: jr          $ra
    // 0x800CB9F8: nop

    return;
    // 0x800CB9F8: nop

;}
RECOMP_FUNC void func_8080021C_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080021C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800220: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800224: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800228: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8080022C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800230: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800234: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800238: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080023C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800240: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800244: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800248: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8080024C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800250: beq         $t6, $at, L_8080026C
    if (ctx->r14 == ctx->r1) {
        // 0x80800254: or          $s4, $a0, $zero
        ctx->r20 = ctx->r4 | 0;
            goto L_8080026C;
    }
    // 0x80800254: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800258: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080025C: beq         $t6, $at, L_808002C8
    if (ctx->r14 == ctx->r1) {
        // 0x80800260: lui         $t9, 0x8080
        ctx->r25 = S32(RELOC_HI16(1824, 0X1554) << 16);
            goto L_808002C8;
    }
    // 0x80800260: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1824, 0X1554) << 16);
    // 0x80800264: b           L_808003DC
    // 0x80800268: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_808003DC;
    // 0x80800268: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8080026C:
    // 0x8080026C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800270: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x80800274: addiu       $a2, $s0, 0xA
    ctx->r6 = ADD32(ctx->r16, 0XA);
L_80800278:
    // 0x80800278: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8080027C: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800280: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800284: jal         0x80087CF8
    // 0x80800288: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_0;
    // 0x80800288: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8080028C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800290: bnel        $s0, $s1, L_80800278
    if (ctx->r16 != ctx->r17) {
        // 0x80800294: addiu       $a2, $s0, 0xA
        ctx->r6 = ADD32(ctx->r16, 0XA);
            goto L_80800278;
    }
    goto skip_0;
    // 0x80800294: addiu       $a2, $s0, 0xA
    ctx->r6 = ADD32(ctx->r16, 0XA);
    skip_0:
    // 0x80800298: lw          $a1, 0x1C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X1C);
    // 0x8080029C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808002A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002A4: beql        $a1, $at, L_808003DC
    if (ctx->r5 == ctx->r1) {
        // 0x808002A8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_808003DC;
    }
    goto skip_1;
    // 0x808002A8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x808002AC: jal         0x80087D70
    // 0x808002B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_27(rdram, ctx);
        goto after_1;
    // 0x808002B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x808002B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002B8: jal         0x80087DE0
    // 0x808002BC: lw          $a1, 0x1C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X1C);
    _gcnewoption_entrypoint_41(rdram, ctx);
        goto after_2;
    // 0x808002BC: lw          $a1, 0x1C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X1C);
    after_2:
    // 0x808002C0: b           L_808003DC
    // 0x808002C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_808003DC;
    // 0x808002C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808002C8:
    // 0x808002C8: addiu       $t9, $t9, 0x1554
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1824, 0X1554));
    // 0x808002CC: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x808002D0: addiu       $s5, $sp, 0x4C
    ctx->r21 = ADD32(ctx->r29, 0X4C);
    // 0x808002D4: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1824, 0X155C) << 16);
    // 0x808002D8: sw          $at, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r1;
    // 0x808002DC: lhu         $at, 0x4($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X4);
    // 0x808002E0: addiu       $t2, $t2, 0x155C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1824, 0X155C));
    // 0x808002E4: addiu       $s6, $sp, 0x44
    ctx->r22 = ADD32(ctx->r29, 0X44);
    // 0x808002E8: sh          $at, 0x4($s5)
    MEM_H(0X4, ctx->r21) = ctx->r1;
    // 0x808002EC: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x808002F0: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(1824, 0X14F4) << 16);
    // 0x808002F4: addiu       $s3, $s3, 0x14F4
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1824, 0X14F4));
    // 0x808002F8: sw          $at, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r1;
    // 0x808002FC: lhu         $at, 0x4($t2)
    ctx->r1 = MEM_HU(ctx->r10, 0X4);
    // 0x80800300: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800304: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800308: sh          $at, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r1;
    // 0x8080030C: lw          $v0, 0x30($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X30);
    // 0x80800310: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x80800314: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x80800318: lbu         $t7, 0x4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4);
    // 0x8080031C: blez        $t7, L_808003A4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80800320: addiu       $a2, $s0, 0xA
        ctx->r6 = ADD32(ctx->r16, 0XA);
            goto L_808003A4;
    }
    // 0x80800320: addiu       $a2, $s0, 0xA
    ctx->r6 = ADD32(ctx->r16, 0XA);
L_80800324:
    // 0x80800324: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80800328: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8080032C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800330: jal         0x80087CF8
    // 0x80800334: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800334: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800338: lw          $t9, 0x30($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X30);
    // 0x8080033C: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x80800340: addu        $t3, $s3, $t1
    ctx->r11 = ADD32(ctx->r19, ctx->r9);
    // 0x80800344: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x80800348: addu        $t4, $t2, $s1
    ctx->r12 = ADD32(ctx->r10, ctx->r17);
    // 0x8080034C: jal         0x800FCF50
    // 0x80800350: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    func_800FCF50(rdram, ctx);
        goto after_4;
    // 0x80800350: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    after_4:
    // 0x80800354: beq         $v0, $zero, L_80800374
    if (ctx->r2 == 0) {
        // 0x80800358: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800374;
    }
    // 0x80800358: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080035C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800360: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800364: jal         0x80087D00
    // 0x80800368: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    _gcnewoption_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x80800368: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_5:
    // 0x8080036C: b           L_80800384
    // 0x80800370: lw          $v0, 0x30($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X30);
        goto L_80800384;
    // 0x80800370: lw          $v0, 0x30($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X30);
L_80800374:
    // 0x80800374: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800378: jal         0x80087D00
    // 0x8080037C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    _gcnewoption_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x8080037C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_6:
    // 0x80800380: lw          $v0, 0x30($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X30);
L_80800384:
    // 0x80800384: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800388: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8080038C: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x80800390: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x80800394: lbu         $t7, 0x4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4);
    // 0x80800398: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8080039C: bnel        $at, $zero, L_80800324
    if (ctx->r1 != 0) {
        // 0x808003A0: addiu       $a2, $s0, 0xA
        ctx->r6 = ADD32(ctx->r16, 0XA);
            goto L_80800324;
    }
    goto skip_2;
    // 0x808003A0: addiu       $a2, $s0, 0xA
    ctx->r6 = ADD32(ctx->r16, 0XA);
    skip_2:
L_808003A4:
    // 0x808003A4: lw          $t8, 0x1C($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X1C);
    // 0x808003A8: bnel        $t8, $v0, L_808003DC
    if (ctx->r24 != ctx->r2) {
        // 0x808003AC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_808003DC;
    }
    goto skip_3;
    // 0x808003AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x808003B0: lw          $a1, 0x18($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X18);
    // 0x808003B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808003B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808003BC: beql        $a1, $at, L_808003DC
    if (ctx->r5 == ctx->r1) {
        // 0x808003C0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_808003DC;
    }
    goto skip_4;
    // 0x808003C0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x808003C4: jal         0x80087D70
    // 0x808003C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_27(rdram, ctx);
        goto after_7;
    // 0x808003C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x808003CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808003D0: jal         0x80087DE0
    // 0x808003D4: lw          $a1, 0x18($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X18);
    _gcnewoption_entrypoint_41(rdram, ctx);
        goto after_8;
    // 0x808003D4: lw          $a1, 0x18($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X18);
    after_8:
    // 0x808003D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808003DC:
    // 0x808003DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003E0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808003E4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808003E8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808003EC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808003F0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808003F4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x808003F8: jr          $ra
    // 0x808003FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x808003FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _chkingjinjobits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086790: syscall     372
    recomp_syscall_handler(rdram, ctx, 0x80086790);
    return;
    // 0x80086794: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _sucoaster_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A188: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A188);
    return;
    // 0x8008A18C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_80801274_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801274: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80801278: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080127C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80801280: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80801284: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80801288: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080128C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80801290: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801294: lbu         $a1, 0x60($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X60);
    // 0x80801298: jal         0x80800CB8
    // 0x8080129C: lh          $a0, 0x58($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X58);
    func_80800CB8_ncpoducam(rdram, ctx);
        goto after_0;
    // 0x8080129C: lh          $a0, 0x58($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X58);
    after_0:
    // 0x808012A0: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x808012A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808012A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808012AC: jal         0x80089E08
    // 0x808012B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _suspline_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x808012B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x808012B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808012B8: jal         0x8001B668
    // 0x808012BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8001B668(rdram, ctx);
        goto after_2;
    // 0x808012BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x808012C0: sh          $v0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r2;
    // 0x808012C4: jal         0x8001B798
    // 0x808012C8: lh          $a0, 0x0($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X0);
    func_8001B798(rdram, ctx);
        goto after_3;
    // 0x808012C8: lh          $a0, 0x0($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X0);
    after_3:
    // 0x808012CC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808012D0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808012D4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808012D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808012DC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x808012E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808012E4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808012E8: jal         0x80089E10
    // 0x808012EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _suspline_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x808012EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x808012F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808012F4: addiu       $s1, $sp, 0x60
    ctx->r17 = ADD32(ctx->r29, 0X60);
L_808012F8:
    // 0x808012F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808012FC: jal         0x80089DC8
    // 0x80801300: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _suspline_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80801300: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80801304: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80801308: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080130C: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x80801310: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80801314: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80801318: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x8080131C: bne         $at, $zero, L_808012F8
    if (ctx->r1 != 0) {
        // 0x80801320: sw          $v0, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r2;
            goto L_808012F8;
    }
    // 0x80801320: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x80801324: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801328: addiu       $s1, $sp, 0x54
    ctx->r17 = ADD32(ctx->r29, 0X54);
L_8080132C:
    // 0x8080132C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801330: jal         0x80089DD0
    // 0x80801334: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _suspline_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80801334: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80801338: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x8080133C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801340: sll         $t3, $s0, 16
    ctx->r11 = S32(ctx->r16 << 16);
    // 0x80801344: sra         $s0, $t3, 16
    ctx->r16 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80801348: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8080134C: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x80801350: bne         $at, $zero, L_8080132C
    if (ctx->r1 != 0) {
        // 0x80801354: sw          $v0, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r2;
            goto L_8080132C;
    }
    // 0x80801354: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x80801358: lh          $t5, 0x58($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X58);
    // 0x8080135C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80801360: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801364: sh          $t5, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r13;
    // 0x80801368: lh          $t6, 0x4E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4E);
    // 0x8080136C: addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
    // 0x80801370: addiu       $s4, $sp, 0x4E
    ctx->r20 = ADD32(ctx->r29, 0X4E);
    // 0x80801374: beq         $t6, $s1, L_80801424
    if (ctx->r14 == ctx->r17) {
        // 0x80801378: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80801424;
    }
    // 0x80801378: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_8080137C:
    // 0x8080137C: jal         0x800A5800
    // 0x80801380: nop

    func_800A5800(rdram, ctx);
        goto after_7;
    // 0x80801380: nop

    after_7:
    // 0x80801384: jal         0x80085580
    // 0x80801388: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80801388: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_8:
    // 0x8080138C: jal         0x80085590
    // 0x80801390: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    _cadbfunc_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80801390: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_9:
    // 0x80801394: jal         0x800855D0
    // 0x80801398: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    _cadbfunc_entrypoint_10(rdram, ctx);
        goto after_10;
    // 0x80801398: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_10:
    // 0x8080139C: jal         0x800855E0
    // 0x808013A0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    _cadbfunc_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x808013A0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_11:
    // 0x808013A4: jal         0x800855F0
    // 0x808013A8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    _cadbfunc_entrypoint_14(rdram, ctx);
        goto after_12;
    // 0x808013A8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_12:
    // 0x808013AC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x808013B0: jal         0x80085668
    // 0x808013B4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_13;
    // 0x808013B4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_13:
    // 0x808013B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808013BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808013C0: jal         0x80089D78
    // 0x808013C4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    _suspline_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x808013C4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_14:
    // 0x808013C8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x808013CC: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x808013D0: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x808013D4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x808013D8: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x808013DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808013E0: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x808013E4: sll         $t7, $s0, 16
    ctx->r15 = S32(ctx->r16 << 16);
    // 0x808013E8: addiu       $t0, $t9, 0xC
    ctx->r8 = ADD32(ctx->r25, 0XC);
    // 0x808013EC: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x808013F0: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x808013F4: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x808013F8: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x808013FC: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x80801400: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x80801404: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x80801408: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x8080140C: sra         $s0, $t7, 16
    ctx->r16 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80801410: jal         0x80085600
    // 0x80801414: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    _cadbfunc_entrypoint_16(rdram, ctx);
        goto after_15;
    // 0x80801414: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_15:
    // 0x80801418: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8080141C: bne         $a0, $s1, L_8080137C
    if (ctx->r4 != ctx->r17) {
        // 0x80801420: nop
    
            goto L_8080137C;
    }
    // 0x80801420: nop

L_80801424:
    // 0x80801424: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801428: jal         0x80089DC8
    // 0x8080142C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suspline_entrypoint_10(rdram, ctx);
        goto after_16;
    // 0x8080142C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80801430: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801434: jal         0x800F0EF0
    // 0x80801438: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800F0EF0(rdram, ctx);
        goto after_17;
    // 0x80801438: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
    // 0x8080143C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80801440: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801444: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80801448: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080144C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80801450: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80801454: jr          $ra
    // 0x80801458: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80801458: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void _ncpod_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800894C0: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800894C0);
    return;
    // 0x800894C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80806C54_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806C54: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80806C58: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80806C5C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80806C60: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80806C64: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80806C68: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80806C6C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80806C70: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80806C74: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80806C78: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80806C7C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80806C80: jal         0x80100094
    // 0x80806C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806C88: jal         0x80088360
    // 0x80806C8C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80806C8C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    after_1:
    // 0x80806C90: lhu         $t8, 0x6E($s3)
    ctx->r24 = MEM_HU(ctx->r19, 0X6E);
    // 0x80806C94: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80806C98: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80806C9C: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80806CA0: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80806CA4: sh          $t0, 0x6E($s3)
    MEM_H(0X6E, ctx->r19) = ctx->r8;
    // 0x80806CA8: lw          $t1, 0x6C($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X6C);
    // 0x80806CAC: addiu       $s2, $zero, 0x42
    ctx->r18 = ADD32(0, 0X42);
    // 0x80806CB0: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x80806CB4: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x80806CB8: beq         $t2, $zero, L_80806D4C
    if (ctx->r10 == 0) {
        // 0x80806CBC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(804, 0X7D70) << 16);
            goto L_80806D4C;
    }
    // 0x80806CBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7D70) << 16);
    // 0x80806CC0: lwc1        $f24, 0x7D70($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7D70));
    // 0x80806CC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80806CC8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80806CCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7D74) << 16);
    // 0x80806CD0: lwc1        $f20, 0x7D74($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7D74));
L_80806CD4:
    // 0x80806CD4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80806CD8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80806CDC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80806CE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80806CE4: jal         0x80087B08
    // 0x80806CE8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _gczoombox_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80806CE8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80806CEC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80806CF0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80806CF4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80806CF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80806CFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80806D00: jal         0x80087BB0
    // 0x80806D04: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    _gczoombox_entrypoint_26(rdram, ctx);
        goto after_3;
    // 0x80806D04: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    after_3:
    // 0x80806D08: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80806D0C: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x80806D10: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80806D14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80806D18: mul.s       $f12, $f6, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80806D1C: jal         0x800C9F48
    // 0x80806D20: nop

    func_800C9F48(rdram, ctx);
        goto after_4;
    // 0x80806D20: nop

    after_4:
    // 0x80806D24: jal         0x8001ACCC
    // 0x80806D28: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    heap_alloc(rdram, ctx);
        goto after_5;
    // 0x80806D28: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_5:
    // 0x80806D2C: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x80806D30: lw          $t3, 0x6C($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X6C);
    // 0x80806D34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80806D38: addiu       $s2, $s2, 0x26
    ctx->r18 = ADD32(ctx->r18, 0X26);
    // 0x80806D3C: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x80806D40: sltu        $at, $s0, $t4
    ctx->r1 = ctx->r16 < ctx->r12 ? 1 : 0;
    // 0x80806D44: bne         $at, $zero, L_80806CD4
    if (ctx->r1 != 0) {
        // 0x80806D48: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80806CD4;
    }
    // 0x80806D48: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80806D4C:
    // 0x80806D4C: jal         0x8001ACCC
    // 0x80806D50: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    heap_alloc(rdram, ctx);
        goto after_6;
    // 0x80806D50: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_6:
    // 0x80806D54: sh          $zero, 0x26($s4)
    MEM_H(0X26, ctx->r20) = 0;
    // 0x80806D58: lh          $t5, 0x26($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X26);
    // 0x80806D5C: sw          $v0, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->r2;
    // 0x80806D60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80806D64: jal         0x808073AC
    // 0x80806D68: sh          $t5, 0x24($s4)
    MEM_H(0X24, ctx->r20) = ctx->r13;
    func_808073AC_chgameselect(rdram, ctx);
        goto after_7;
    // 0x80806D68: sh          $t5, 0x24($s4)
    MEM_H(0X24, ctx->r20) = ctx->r13;
    after_7:
    // 0x80806D6C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80806D70: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80806D74: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80806D78: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80806D7C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80806D80: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80806D84: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80806D88: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80806D8C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80806D90: jr          $ra
    // 0x80806D94: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80806D94: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void bsride_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808006C0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(348, 0XA80) << 16);
    // 0x808006C4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808006C8: jr          $ra
    // 0x808006CC: lw          $v0, 0xA80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(348, 0XA80));
    return;
    // 0x808006CC: lw          $v0, 0xA80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(348, 0XA80));
;}
RECOMP_FUNC void _chmermaidstatue_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086238: syscall     292
    recomp_syscall_handler(rdram, ctx, 0x80086238);
    return;
    // 0x8008623C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
