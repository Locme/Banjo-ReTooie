#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808011DC_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808011E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808011E4: jal         0x808001A8
    // 0x808011E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_808001A8_bswasher(rdram, ctx);
        goto after_0;
    // 0x808011E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011EC: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x808011F0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808011F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808011F8: addiu       $a1, $zero, 0x358
    ctx->r5 = ADD32(0, 0X358);
    // 0x808011FC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80801200: jal         0x80085150
    // 0x80801204: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _baspin_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801204: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80801208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080120C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801210: jr          $ra
    // 0x80801214: nop

    return;
    // 0x80801214: nop

;}
RECOMP_FUNC void gsworldDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080055C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800564: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800568: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2862, 0X590) << 16);
    // 0x8080056C: addiu       $a2, $a2, 0x590
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2862, 0X590));
    // 0x80800570: lhu         $a1, 0x2($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X2);
    // 0x80800574: jal         0x8080054C
    // 0x80800578: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8080054C_gsworldDll(rdram, ctx);
        goto after_0;
    // 0x80800578: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8080057C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800580: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800584: jr          $ra
    // 0x80800588: nop

    return;
    // 0x80800588: nop

    // 0x8080058C: nop

;}
RECOMP_FUNC void func_8009E8D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E8D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E8D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E8DC: jal         0x800C6E60
    // 0x8009E8E0: nop

    func_800C6E60(rdram, ctx);
        goto after_0;
    // 0x8009E8E0: nop

    after_0:
    // 0x8009E8E4: jal         0x800D3B60
    // 0x8009E8E8: nop

    func_800D3B60(rdram, ctx);
        goto after_1;
    // 0x8009E8E8: nop

    after_1:
    // 0x8009E8EC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009E8F0: addiu       $v1, $v1, 0x7068
    ctx->r3 = ADD32(ctx->r3, 0X7068);
    // 0x8009E8F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8009E8F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009E8FC: addiu       $a1, $a1, 0x7040
    ctx->r5 = ADD32(ctx->r5, 0X7040);
    // 0x8009E900: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009E904: sb          $v0, 0xC($a1)
    MEM_B(0XC, ctx->r5) = ctx->r2;
    // 0x8009E908: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x8009E90C: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // 0x8009E910: sb          $zero, 0xD($v1)
    MEM_B(0XD, ctx->r3) = 0;
    // 0x8009E914: sb          $zero, 0xE($v1)
    MEM_B(0XE, ctx->r3) = 0;
    // 0x8009E918: sb          $zero, 0xF($v1)
    MEM_B(0XF, ctx->r3) = 0;
    // 0x8009E91C: sb          $t6, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r14;
    // 0x8009E920: addiu       $a0, $zero, 0x3EC
    ctx->r4 = ADD32(0, 0X3EC);
    // 0x8009E924: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8009E928: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x8009E92C: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x8009E930: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8009E934: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8009E938: jal         0x800DA524
    // 0x8009E93C: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x8009E93C: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    after_2:
    // 0x8009E940: jal         0x8009EAE8
    // 0x8009E944: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8009EAE8(rdram, ctx);
        goto after_3;
    // 0x8009E944: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8009E948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E94C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E950: jr          $ra
    // 0x8009E954: nop

    return;
    // 0x8009E954: nop

;}
RECOMP_FUNC void func_801125B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801125B0: jr          $ra
    // 0x801125B4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x801125B4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080021C_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080021C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800220: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800224: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800228: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080022C: jal         0x8009E77C
    // 0x80800230: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x80800230: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_0:
    // 0x80800234: bne         $v0, $zero, L_80800298
    if (ctx->r2 != 0) {
        // 0x80800238: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800298;
    }
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x80084538
    // 0x80800240: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _babackpack_set_state(rdram, ctx);
        goto after_1;
    // 0x80800240: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: jal         0x800A0CD0
    // 0x8080024C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CD0(rdram, ctx);
        goto after_2;
    // 0x8080024C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800250: jal         0x8009EFA8
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_3;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800258: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x8080025C: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: jal         0x8009F1C8
    // 0x80800268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_4;
    // 0x80800268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800274: jal         0x8009F1C8
    // 0x80800278: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_5;
    // 0x80800278: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: lui         $a1, 0x4254
    ctx->r5 = S32(0X4254 << 16);
    // 0x80800284: jal         0x800959C8
    // 0x80800288: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    func_800959C8(rdram, ctx);
        goto after_6;
    // 0x80800288: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    after_6:
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x8009590C
    // 0x80800294: lui         $a1, 0x4254
    ctx->r5 = S32(0X4254 << 16);
    func_8009590C(rdram, ctx);
        goto after_7;
    // 0x80800294: lui         $a1, 0x4254
    ctx->r5 = S32(0X4254 << 16);
    after_7:
L_80800298:
    // 0x80800298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080029C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002A4: jr          $ra
    // 0x808002A8: nop

    return;
    // 0x808002A8: nop

;}
RECOMP_FUNC void func_80029670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029670: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80029674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029678: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002967C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80029680: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80029684: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80029688: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x8002968C: beq         $t7, $zero, L_80029754
    if (ctx->r15 == 0) {
        // 0x80029690: sw          $t7, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r15;
            goto L_80029754;
    }
    // 0x80029690: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_80029694:
    // 0x80029694: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80029698: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8002969C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800296A0: bne         $t9, $t0, L_8002973C
    if (ctx->r25 != ctx->r8) {
        // 0x800296A4: nop
    
            goto L_8002973C;
    }
    // 0x800296A4: nop

    // 0x800296A8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800296AC: beq         $t1, $zero, L_800296C8
    if (ctx->r9 == 0) {
        // 0x800296B0: nop
    
            goto L_800296C8;
    }
    // 0x800296B0: nop

    // 0x800296B4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800296B8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800296BC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800296C0: b           L_800296D8
    // 0x800296C4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
        goto L_800296D8;
    // 0x800296C4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_800296C8:
    // 0x800296C8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800296CC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800296D0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800296D4: sw          $t6, 0x64($t7)
    MEM_W(0X64, ctx->r15) = ctx->r14;
L_800296D8:
    // 0x800296D8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800296DC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800296E0: lw          $t9, 0x68($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X68);
    // 0x800296E4: bne         $t9, $t0, L_800296F8
    if (ctx->r25 != ctx->r8) {
        // 0x800296E8: nop
    
            goto L_800296F8;
    }
    // 0x800296E8: nop

    // 0x800296EC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800296F0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800296F4: sw          $t1, 0x68($t2)
    MEM_W(0X68, ctx->r10) = ctx->r9;
L_800296F8:
    // 0x800296F8: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800296FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80029700: jal         0x800E90A4
    // 0x80029704: lw          $a0, 0x20($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X20);
    func_800E90A4(rdram, ctx);
        goto after_0;
    // 0x80029704: lw          $a0, 0x20($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X20);
    after_0:
    // 0x80029708: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8002970C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80029710: lw          $t5, 0x6C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X6C);
    // 0x80029714: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80029718: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8002971C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80029720: sw          $t7, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->r15;
    // 0x80029724: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80029728: lbu         $t0, 0x89($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X89);
    // 0x8002972C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80029730: sb          $t1, 0x89($t9)
    MEM_B(0X89, ctx->r25) = ctx->r9;
    // 0x80029734: b           L_8002975C
    // 0x80029738: nop

        goto L_8002975C;
    // 0x80029738: nop

L_8002973C:
    // 0x8002973C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80029740: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80029744: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80029748: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8002974C: bne         $t4, $zero, L_80029694
    if (ctx->r12 != 0) {
        // 0x80029750: sw          $t4, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r12;
            goto L_80029694;
    }
    // 0x80029750: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
L_80029754:
    // 0x80029754: b           L_8002975C
    // 0x80029758: nop

        goto L_8002975C;
    // 0x80029758: nop

L_8002975C:
    // 0x8002975C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029760: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80029764: jr          $ra
    // 0x80029768: nop

    return;
    // 0x80029768: nop

;}
RECOMP_FUNC void func_80106C08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106C08: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80106C0C: lw          $v1, 0x6EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6EF0);
    // 0x80106C10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106C18: bnel        $v1, $zero, L_80106C3C
    if (ctx->r3 != 0) {
        // 0x80106C1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106C3C;
    }
    goto skip_0;
    // 0x80106C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80106C20: jal         0x800B3310
    // 0x80106C24: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800B3310(rdram, ctx);
        goto after_0;
    // 0x80106C24: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80106C28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106C2C: sw          $v0, 0x6EF0($at)
    MEM_W(0X6EF0, ctx->r1) = ctx->r2;
    // 0x80106C30: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80106C34: lw          $v1, 0x6EF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6EF0);
    // 0x80106C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106C3C:
    // 0x80106C3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106C40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80106C44: jr          $ra
    // 0x80106C48: nop

    return;
    // 0x80106C48: nop

;}
RECOMP_FUNC void func_80109748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109748: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8010974C: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x80109750: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x80109754: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x80109758: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x8010975C: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x80109760: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x80109764: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x80109768: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x8010976C: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x80109770: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x80109774: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x80109778: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x8010977C: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x80109780: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x80109784: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x80109788: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8010978C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80109790: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80109794: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80109798: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x8010979C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801097A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801097A4: blez        $a1, L_80109888
    if (SIGNED(ctx->r5) <= 0) {
        // 0x801097A8: swc1        $f6, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
            goto L_80109888;
    }
    // 0x801097A8: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x801097AC: mtc1        $a2, $f18
    ctx->f18.u32l = ctx->r6;
    // 0x801097B0: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x801097B4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801097B8: cvt.s.w     $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    ctx->f24.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801097BC: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x801097C0: lwc1        $f28, 0xC0($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x801097C4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801097C8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801097CC: cvt.s.w     $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    ctx->f26.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801097D0: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x801097D4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801097D8: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x801097DC: addiu       $fp, $fp, 0x4688
    ctx->r30 = ADD32(ctx->r30, 0X4688);
    // 0x801097E0: addiu       $s7, $sp, 0xA4
    ctx->r23 = ADD32(ctx->r29, 0XA4);
    // 0x801097E4: addiu       $s6, $sp, 0x98
    ctx->r22 = ADD32(ctx->r29, 0X98);
    // 0x801097E8: lw          $s5, 0xC4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC4);
    // 0x801097EC: lw          $s4, 0xCC($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XCC);
    // 0x801097F0: lw          $s3, 0xC8($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC8);
    // 0x801097F4: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
L_801097F8:
    // 0x801097F8: jal         0x800DC178
    // 0x801097FC: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x801097FC: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_0:
    // 0x80109800: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80109804: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80109808: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8010980C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80109810: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    // 0x80109814: jal         0x800DC178
    // 0x80109818: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80109818: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8010981C: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x80109820: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80109824: jal         0x800DC178
    // 0x80109828: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80109828: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_2:
    // 0x8010982C: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    // 0x80109830: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80109834: jal         0x800DC178
    // 0x80109838: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80109838: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_3:
    // 0x8010983C: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    // 0x80109840: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80109844: jal         0x800DC128
    // 0x80109848: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800DC128(rdram, ctx);
        goto after_4;
    // 0x80109848: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_4:
    // 0x8010984C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80109850: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80109854: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80109858: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8010985C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80109860: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80109864: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    // 0x80109868: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x8010986C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80109870: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80109874: jal         0x800B4470
    // 0x80109878: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800B4470(rdram, ctx);
        goto after_5;
    // 0x80109878: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8010987C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80109880: bnel        $s0, $s2, L_801097F8
    if (ctx->r16 != ctx->r18) {
        // 0x80109884: mov.s       $f12, $f24
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
            goto L_801097F8;
    }
    goto skip_0;
    // 0x80109884: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    skip_0:
L_80109888:
    // 0x80109888: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x8010988C: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80109890: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x80109894: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x80109898: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x8010989C: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x801098A0: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x801098A4: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x801098A8: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x801098AC: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x801098B0: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x801098B4: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x801098B8: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x801098BC: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x801098C0: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x801098C4: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x801098C8: jr          $ra
    // 0x801098CC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x801098CC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_80800008_babuzz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(481, 0X2D0) << 16);
    // 0x80800014: jal         0x800F0F9C
    // 0x80800018: lwc1        $f14, 0x2D0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(481, 0X2D0));
    func_800F0F9C(rdram, ctx);
        goto after_0;
    // 0x80800018: lwc1        $f14, 0x2D0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(481, 0X2D0));
    after_0:
    // 0x8080001C: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800020: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800024: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800028: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080002C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80800030: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80800034: nop

    // 0x80800038: bc1fl       L_80800050
    if (!c1cs) {
        // 0x8080003C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800050;
    }
    goto skip_0;
    // 0x8080003C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x80800040: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800044: nop

    // 0x80800048: sub.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8080004C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80800050:
    // 0x80800050: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800054: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(481, 0X2D4) << 16);
    // 0x80800058: lwc1        $f10, 0x2D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(481, 0X2D4));
    // 0x8080005C: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8080006C: jr          $ra
    // 0x80800070: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80800070: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void _badeathmatch_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085518: syscall     165
    recomp_syscall_handler(rdram, ctx, 0x80085518);
    return;
    // 0x8008551C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800C70_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C78: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800C7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C84: bne         $a1, $at, L_80800CDC
    if (ctx->r5 != ctx->r1) {
        // 0x80800C88: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800CDC;
    }
    // 0x80800C88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800C8C: jal         0x80801188
    // 0x80800C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801188_chterryegg(rdram, ctx);
        goto after_0;
    // 0x80800C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800C98: jal         0x80800CF4
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CF4_chterryegg(rdram, ctx);
        goto after_1;
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800CA0: jal         0x800DC0C0
    // 0x80800CA4: nop

    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x80800CA4: nop

    after_2:
    // 0x80800CA8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800CAC: jal         0x80101EE4
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101EE4(rdram, ctx);
        goto after_3;
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800CB4: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800CB8: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x80800CBC: jal         0x800DA298
    // 0x80800CC0: addiu       $a0, $t6, 0x143
    ctx->r4 = ADD32(ctx->r14, 0X143);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800CC0: addiu       $a0, $t6, 0x143
    ctx->r4 = ADD32(ctx->r14, 0X143);
    after_4:
    // 0x80800CC4: bne         $v0, $zero, L_80800CD4
    if (ctx->r2 != 0) {
        // 0x80800CC8: nop
    
            goto L_80800CD4;
    }
    // 0x80800CC8: nop

    // 0x80800CCC: jal         0x800FFAB0
    // 0x80800CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80800CD4:
    // 0x80800CD4: b           L_80800CE0
    // 0x80800CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CE0;
    // 0x80800CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CDC:
    // 0x80800CDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CE0:
    // 0x80800CE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CEC: jr          $ra
    // 0x80800CF0: nop

    return;
    // 0x80800CF0: nop

;}
RECOMP_FUNC void func_8008B64C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B64C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B650: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008B654: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
    // 0x8008B658: lw          $a0, 0x6CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6CC0);
    // 0x8008B65C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B660: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B664: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8008B668: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008B66C: beq         $at, $zero, L_8008B6BC
    if (ctx->r1 == 0) {
        // 0x8008B670: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8008B6BC;
    }
    // 0x8008B670: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008B674: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
L_8008B678:
    // 0x8008B678: beql        $t6, $zero, L_8008B6A8
    if (ctx->r14 == 0) {
        // 0x8008B67C: addiu       $s0, $s0, 0x6
        ctx->r16 = ADD32(ctx->r16, 0X6);
            goto L_8008B6A8;
    }
    goto skip_0;
    // 0x8008B67C: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    skip_0:
    // 0x8008B680: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8008B684: beql        $a0, $zero, L_8008B69C
    if (ctx->r4 == 0) {
        // 0x8008B688: sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
            goto L_8008B69C;
    }
    goto skip_1;
    // 0x8008B688: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    skip_1:
    // 0x8008B68C: jal         0x800DFCC0
    // 0x8008B690: nop

    func_800DFCC0(rdram, ctx);
        goto after_0;
    // 0x8008B690: nop

    after_0:
    // 0x8008B694: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x8008B698: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
L_8008B69C:
    // 0x8008B69C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008B6A0: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
    // 0x8008B6A4: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
L_8008B6A8:
    // 0x8008B6A8: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8008B6AC: bnel        $at, $zero, L_8008B678
    if (ctx->r1 != 0) {
        // 0x8008B6B0: lh          $t6, 0x4($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X4);
            goto L_8008B678;
    }
    goto skip_2;
    // 0x8008B6B0: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    skip_2:
    // 0x8008B6B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B6B8: lw          $a0, 0x6CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6CC0);
L_8008B6BC:
    // 0x8008B6BC: jal         0x8001B084
    // 0x8008B6C0: nop

    heap_free(rdram, ctx);
        goto after_1;
    // 0x8008B6C0: nop

    after_1:
    // 0x8008B6C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B6C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B6CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B6D0: sw          $zero, 0x6CC4($at)
    MEM_W(0X6CC4, ctx->r1) = 0;
    // 0x8008B6D4: sw          $zero, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = 0;
    // 0x8008B6D8: jr          $ra
    // 0x8008B6DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8008B6DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80804304_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804304: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80804308: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8080430C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80804310: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80804314: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80804318: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8080431C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80804320: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80804324: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80804328: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8080432C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80804330: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80804334: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80804338: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8080433C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80804340: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80804344: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80804348: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080434C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80804350: jal         0x80106790
    // 0x80804354: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80804354: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80804358: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080435C: jal         0x80100094
    // 0x80804360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80804360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80804364: sw          $v0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r2;
    // 0x80804368: lbu         $t6, 0x3A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3A);
    // 0x8080436C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80804370: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80804374: blez        $t6, L_8080467C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80804378: addiu       $fp, $sp, 0xA0
        ctx->r30 = ADD32(ctx->r29, 0XA0);
            goto L_8080467C;
    }
    // 0x80804378: addiu       $fp, $sp, 0xA0
    ctx->r30 = ADD32(ctx->r29, 0XA0);
    // 0x8080437C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80804380: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80804384: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80804388: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8080438C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80804390: addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
    // 0x80804394: addiu       $s6, $sp, 0xAC
    ctx->r22 = ADD32(ctx->r29, 0XAC);
    // 0x80804398: addiu       $s5, $sp, 0xC0
    ctx->r21 = ADD32(ctx->r29, 0XC0);
    // 0x8080439C: lw          $t7, 0x6C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X6C);
L_808043A0:
    // 0x808043A0: addiu       $s3, $s1, 0x4
    ctx->r19 = ADD32(ctx->r17, 0X4);
    // 0x808043A4: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x808043A8: beql        $s2, $t8, L_80804668
    if (ctx->r18 == ctx->r24) {
        // 0x808043AC: lw          $t3, 0xD0($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XD0);
            goto L_80804668;
    }
    goto skip_0;
    // 0x808043AC: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    skip_0:
    // 0x808043B0: jal         0x80106790
    // 0x808043B4: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x808043B4: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    after_2:
    // 0x808043B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808043BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808043C0: jal         0x80089AD0
    // 0x808043C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _sukickball_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x808043C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x808043C8: beq         $v0, $zero, L_80804404
    if (ctx->r2 == 0) {
        // 0x808043CC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804404;
    }
    // 0x808043CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808043D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808043D4: jal         0x80089AD8
    // 0x808043D8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x808043D8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x808043DC: jal         0x80106790
    // 0x808043E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x808043E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808043E4: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808043E8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808043EC: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
    // 0x808043F0: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808043F4: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
    // 0x808043F8: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808043FC: b           L_8080440C
    // 0x80804400: swc1        $f8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f8.u32l;
        goto L_8080440C;
    // 0x80804400: swc1        $f8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f8.u32l;
L_80804404:
    // 0x80804404: jal         0x800F5A00
    // 0x80804408: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800F5A00(rdram, ctx);
        goto after_6;
    // 0x80804408: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_6:
L_8080440C:
    // 0x8080440C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80804410: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x80804414: jal         0x800EFFB4
    // 0x80804418: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800EFFB4(rdram, ctx);
        goto after_7;
    // 0x80804418: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_7:
    // 0x8080441C: beql        $v0, $zero, L_80804668
    if (ctx->r2 == 0) {
        // 0x80804420: lw          $t3, 0xD0($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XD0);
            goto L_80804668;
    }
    goto skip_1;
    // 0x80804420: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    skip_1:
    // 0x80804424: jal         0x800EEF94
    // 0x80804428: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    func_800EEF94(rdram, ctx);
        goto after_8;
    // 0x80804428: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    after_8:
    // 0x8080442C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80804430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804434: jal         0x80089AC8
    // 0x80804438: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_9;
    // 0x80804438: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x8080443C: beq         $v0, $zero, L_80804468
    if (ctx->r2 == 0) {
        // 0x80804440: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804468;
    }
    // 0x80804440: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804444: jal         0x800F5D70
    // 0x80804448: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800F5D70(rdram, ctx);
        goto after_10;
    // 0x80804448: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_10:
    // 0x8080444C: jal         0x800EEF94
    // 0x80804450: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800EEF94(rdram, ctx);
        goto after_11;
    // 0x80804450: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_11:
    // 0x80804454: jal         0x800D8FF8
    // 0x80804458: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800D8FF8(rdram, ctx);
        goto after_12;
    // 0x80804458: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_12:
    // 0x8080445C: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80804460: b           L_80804480
    // 0x80804464: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
        goto L_80804480;
    // 0x80804464: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_80804468:
    // 0x80804468: jal         0x800EEF94
    // 0x8080446C: addiu       $a0, $s4, 0x28
    ctx->r4 = ADD32(ctx->r20, 0X28);
    func_800EEF94(rdram, ctx);
        goto after_13;
    // 0x8080446C: addiu       $a0, $s4, 0x28
    ctx->r4 = ADD32(ctx->r20, 0X28);
    after_13:
    // 0x80804470: jal         0x800D8FF8
    // 0x80804474: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800D8FF8(rdram, ctx);
        goto after_14;
    // 0x80804474: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_14:
    // 0x80804478: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8080447C: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_80804480:
    // 0x80804480: c.lt.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl < ctx->f22.fl;
    // 0x80804484: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80804488: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080448C: bc1fl       L_808045A4
    if (!c1cs) {
        // 0x80804490: mfc1        $a2, $f26
        ctx->r6 = (int32_t)ctx->f26.u32l;
            goto L_808045A4;
    }
    goto skip_2;
    // 0x80804490: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    skip_2:
    // 0x80804494: jal         0x80089AC8
    // 0x80804498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_15;
    // 0x80804498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080449C: beq         $v0, $zero, L_80804530
    if (ctx->r2 == 0) {
        // 0x808044A0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80804530;
    }
    // 0x808044A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808044A4: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x808044A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808044AC: jal         0x80089B00
    // 0x808044B0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    _sukickball_entrypoint_13(rdram, ctx);
        goto after_16;
    // 0x808044B0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_16:
    // 0x808044B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808044B8: jal         0x800F8294
    // 0x808044BC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800F8294(rdram, ctx);
        goto after_17;
    // 0x808044BC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_17:
    // 0x808044C0: lhu         $t9, 0x72($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X72);
    // 0x808044C4: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1608, 0X541C) << 16);
    // 0x808044C8: addiu       $t1, $t1, 0x541C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1608, 0X541C));
    // 0x808044CC: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x808044D0: bnel        $s7, $t0, L_80804668
    if (ctx->r23 != ctx->r8) {
        // 0x808044D4: lw          $t3, 0xD0($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XD0);
            goto L_80804668;
    }
    goto skip_3;
    // 0x808044D4: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    skip_3:
    // 0x808044D8: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x808044DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808044E0: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x808044E4: sw          $at, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r1;
    // 0x808044E8: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x808044EC: sw          $t3, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r11;
    // 0x808044F0: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x808044F4: jal         0x800F5A00
    // 0x808044F8: sw          $at, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r1;
    func_800F5A00(rdram, ctx);
        goto after_18;
    // 0x808044F8: sw          $at, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r1;
    after_18:
    // 0x808044FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804500: jal         0x80102D78
    // 0x80804504: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    func_80102D78(rdram, ctx);
        goto after_19;
    // 0x80804504: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    after_19:
    // 0x80804508: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080450C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80804510: jal         0x800EF1B8
    // 0x80804514: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_20;
    // 0x80804514: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_20:
    // 0x80804518: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080451C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80804520: jal         0x800F7700
    // 0x80804524: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800F7700(rdram, ctx);
        goto after_21;
    // 0x80804524: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_21:
    // 0x80804528: b           L_80804668
    // 0x8080452C: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
        goto L_80804668;
    // 0x8080452C: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
L_80804530:
    // 0x80804530: addiu       $s0, $s4, 0x4
    ctx->r16 = ADD32(ctx->r20, 0X4);
    // 0x80804534: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80804538: jal         0x80089B00
    // 0x8080453C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _sukickball_entrypoint_13(rdram, ctx);
        goto after_22;
    // 0x8080453C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_22:
    // 0x80804540: lhu         $t4, 0x72($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X72);
    // 0x80804544: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80804548: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x8080454C: bnel        $s7, $t5, L_80804668
    if (ctx->r23 != ctx->r13) {
        // 0x80804550: lw          $t3, 0xD0($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XD0);
            goto L_80804668;
    }
    goto skip_4;
    // 0x80804550: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    skip_4:
    // 0x80804554: lbu         $t7, 0x65($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X65);
    // 0x80804558: swc1        $f28, 0x58($s4)
    MEM_W(0X58, ctx->r20) = ctx->f28.u32l;
    // 0x8080455C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80804560: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80804564: jal         0x80800B4C
    // 0x80804568: sb          $t8, 0x65($s4)
    MEM_B(0X65, ctx->r20) = ctx->r24;
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_23;
    // 0x80804568: sb          $t8, 0x65($s4)
    MEM_B(0X65, ctx->r20) = ctx->r24;
    after_23:
    // 0x8080456C: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80804570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804574: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80804578: mul.s       $f16, $f10, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x8080457C: jal         0x80102D78
    // 0x80804580: swc1        $f16, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->f16.u32l;
    func_80102D78(rdram, ctx);
        goto after_24;
    // 0x80804580: swc1        $f16, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->f16.u32l;
    after_24:
    // 0x80804584: swc1        $f0, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->f0.u32l;
    // 0x80804588: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080458C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80804590: lwc1        $f18, 0x24($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80804594: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80804598: b           L_80804664
    // 0x8080459C: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
        goto L_80804664;
    // 0x8080459C: swc1        $f6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f6.u32l;
    // 0x808045A0: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
L_808045A4:
    // 0x808045A4: jal         0x80089B00
    // 0x808045A8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _sukickball_entrypoint_13(rdram, ctx);
        goto after_25;
    // 0x808045A8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_25:
    // 0x808045AC: jal         0x800DC0C0
    // 0x808045B0: nop

    func_800DC0C0(rdram, ctx);
        goto after_26;
    // 0x808045B0: nop

    after_26:
    // 0x808045B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808045B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808045BC: nop

    // 0x808045C0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808045C4: nop

    // 0x808045C8: bc1fl       L_808045F8
    if (!c1cs) {
        // 0x808045CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808045F8;
    }
    goto skip_5;
    // 0x808045CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x808045D0: lw          $a1, 0x6C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X6C);
    // 0x808045D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808045D8: andi        $t9, $a1, 0x1FF
    ctx->r25 = ctx->r5 & 0X1FF;
    // 0x808045DC: jal         0x80089AF8
    // 0x808045E0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_27;
    // 0x808045E0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_27:
    // 0x808045E4: bne         $v0, $zero, L_808045F4
    if (ctx->r2 != 0) {
        // 0x808045E8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808045F4;
    }
    // 0x808045E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808045EC: jal         0x80800BCC
    // 0x808045F0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80800BCC_chstoneballcontrol(rdram, ctx);
        goto after_28;
    // 0x808045F0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_28:
L_808045F4:
    // 0x808045F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808045F8:
    // 0x808045F8: jal         0x80089AC8
    // 0x808045FC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_29;
    // 0x808045FC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_29:
    // 0x80804600: beq         $v0, $zero, L_80804654
    if (ctx->r2 == 0) {
        // 0x80804604: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804654;
    }
    // 0x80804604: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80804608: jal         0x800F52B8
    // 0x8080460C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_800F52B8(rdram, ctx);
        goto after_30;
    // 0x8080460C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_30:
    // 0x80804610: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804614: bne         $v0, $at, L_80804654
    if (ctx->r2 != ctx->r1) {
        // 0x80804618: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80804654;
    }
    // 0x80804618: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080461C: jal         0x800F5A00
    // 0x80804620: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    func_800F5A00(rdram, ctx);
        goto after_31;
    // 0x80804620: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    after_31:
    // 0x80804624: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80804628: jal         0x800F1DF4
    // 0x8080462C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_32;
    // 0x8080462C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_32:
    // 0x80804630: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    // 0x80804634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804638: jal         0x80800B4C
    // 0x8080463C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_33;
    // 0x8080463C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_33:
    // 0x80804640: jal         0x800D8FF8
    // 0x80804644: nop

    func_800D8FF8(rdram, ctx);
        goto after_34;
    // 0x80804644: nop

    after_34:
    // 0x80804648: mul.s       $f10, $f24, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f30.fl);
    // 0x8080464C: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80804650: swc1        $f16, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f16.u32l;
L_80804654:
    // 0x80804654: lbu         $t2, 0x65($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X65);
    // 0x80804658: swc1        $f28, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f28.u32l;
    // 0x8080465C: ori         $t1, $t2, 0x10
    ctx->r9 = ctx->r10 | 0X10;
    // 0x80804660: sb          $t1, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r9;
L_80804664:
    // 0x80804664: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
L_80804668:
    // 0x80804668: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8080466C: lbu         $t4, 0x3A($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X3A);
    // 0x80804670: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80804674: bnel        $at, $zero, L_808043A0
    if (ctx->r1 != 0) {
        // 0x80804678: lw          $t7, 0x6C($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X6C);
            goto L_808043A0;
    }
    goto skip_6;
    // 0x80804678: lw          $t7, 0x6C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X6C);
    skip_6:
L_8080467C:
    // 0x8080467C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80804680: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80804684: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80804688: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8080468C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80804690: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80804694: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80804698: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8080469C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x808046A0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x808046A4: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x808046A8: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x808046AC: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x808046B0: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x808046B4: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x808046B8: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x808046BC: jr          $ra
    // 0x808046C0: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x808046C0: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_800CF580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF580: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CF584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF588: jal         0x800A9C98
    // 0x800CF58C: nop

    func_800A9C98(rdram, ctx);
        goto after_0;
    // 0x800CF58C: nop

    after_0:
    // 0x800CF590: beq         $v0, $zero, L_800CF5A0
    if (ctx->r2 == 0) {
        // 0x800CF594: nop
    
            goto L_800CF5A0;
    }
    // 0x800CF594: nop

    // 0x800CF598: b           L_800CF630
    // 0x800CF59C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CF630;
    // 0x800CF59C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF5A0:
    // 0x800CF5A0: jal         0x800D3E40
    // 0x800CF5A4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800D3E40(rdram, ctx);
        goto after_1;
    // 0x800CF5A4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_1:
    // 0x800CF5A8: beq         $v0, $zero, L_800CF5B8
    if (ctx->r2 == 0) {
        // 0x800CF5AC: nop
    
            goto L_800CF5B8;
    }
    // 0x800CF5AC: nop

    // 0x800CF5B0: b           L_800CF630
    // 0x800CF5B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CF630;
    // 0x800CF5B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF5B8:
    // 0x800CF5B8: jal         0x800F54E4
    // 0x800CF5BC: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x800CF5BC: nop

    after_2:
    // 0x800CF5C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800CF5C4: jal         0x800F6BE4
    // 0x800CF5C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_3;
    // 0x800CF5C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800CF5CC: bne         $v0, $zero, L_800CF5DC
    if (ctx->r2 != 0) {
        // 0x800CF5D0: nop
    
            goto L_800CF5DC;
    }
    // 0x800CF5D0: nop

    // 0x800CF5D4: b           L_800CF630
    // 0x800CF5D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CF630;
    // 0x800CF5D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF5DC:
    // 0x800CF5DC: jal         0x800F6D24
    // 0x800CF5E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F6D24(rdram, ctx);
        goto after_4;
    // 0x800CF5E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x800CF5E4: beq         $v0, $zero, L_800CF5F4
    if (ctx->r2 == 0) {
        // 0x800CF5E8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800CF5F4;
    }
    // 0x800CF5E8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800CF5EC: b           L_800CF630
    // 0x800CF5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CF630;
    // 0x800CF5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF5F4:
    // 0x800CF5F4: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x800CF5F8: jal         0x800F64A4
    // 0x800CF5FC: ori         $a1, $a1, 0xA000
    ctx->r5 = ctx->r5 | 0XA000;
    func_800F64A4(rdram, ctx);
        goto after_5;
    // 0x800CF5FC: ori         $a1, $a1, 0xA000
    ctx->r5 = ctx->r5 | 0XA000;
    after_5:
    // 0x800CF600: beq         $v0, $zero, L_800CF610
    if (ctx->r2 == 0) {
        // 0x800CF604: nop
    
            goto L_800CF610;
    }
    // 0x800CF604: nop

    // 0x800CF608: b           L_800CF630
    // 0x800CF60C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CF630;
    // 0x800CF60C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CF610:
    // 0x800CF610: jal         0x800F8B88
    // 0x800CF614: nop

    func_800F8B88(rdram, ctx);
        goto after_6;
    // 0x800CF614: nop

    after_6:
    // 0x800CF618: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CF61C: bnel        $v0, $at, L_800CF630
    if (ctx->r2 != ctx->r1) {
        // 0x800CF620: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800CF630;
    }
    goto skip_0;
    // 0x800CF620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800CF624: b           L_800CF630
    // 0x800CF628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CF630;
    // 0x800CF628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CF62C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CF630:
    // 0x800CF630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CF638: jr          $ra
    // 0x800CF63C: nop

    return;
    // 0x800CF63C: nop

;}
RECOMP_FUNC void func_8009BFCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BFCC: lw          $t6, 0xDC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XDC);
    // 0x8009BFD0: jr          $ra
    // 0x8009BFD4: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    return;
    // 0x8009BFD4: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
;}
RECOMP_FUNC void func_8010072C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010072C: beql        $a0, $zero, L_8010077C
    if (ctx->r4 == 0) {
        // 0x80100730: lbu         $t2, 0x0($a1)
        ctx->r10 = MEM_BU(ctx->r5, 0X0);
            goto L_8010077C;
    }
    goto skip_0;
    // 0x80100730: lbu         $t2, 0x0($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X0);
    skip_0:
    // 0x80100734: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80100738: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x8010073C: xor         $v0, $t6, $t7
    ctx->r2 = ctx->r14 ^ ctx->r15;
    // 0x80100740: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80100744: beq         $v0, $zero, L_801007B0
    if (ctx->r2 == 0) {
        // 0x80100748: nop
    
            goto L_801007B0;
    }
    // 0x80100748: nop

    // 0x8010074C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80100750: lbu         $t9, 0x1($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1);
    // 0x80100754: xor         $v0, $t8, $t9
    ctx->r2 = ctx->r24 ^ ctx->r25;
    // 0x80100758: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8010075C: beq         $v0, $zero, L_801007B0
    if (ctx->r2 == 0) {
        // 0x80100760: nop
    
            goto L_801007B0;
    }
    // 0x80100760: nop

    // 0x80100764: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80100768: lbu         $t1, 0x2($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X2);
    // 0x8010076C: xor         $v0, $t0, $t1
    ctx->r2 = ctx->r8 ^ ctx->r9;
    // 0x80100770: jr          $ra
    // 0x80100774: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x80100774: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80100778: lbu         $t2, 0x0($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X0);
L_8010077C:
    // 0x8010077C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80100780: xor         $v0, $v1, $t2
    ctx->r2 = ctx->r3 ^ ctx->r10;
    // 0x80100784: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80100788: beq         $v0, $zero, L_801007B0
    if (ctx->r2 == 0) {
        // 0x8010078C: nop
    
            goto L_801007B0;
    }
    // 0x8010078C: nop

    // 0x80100790: lbu         $t3, 0x1($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X1);
    // 0x80100794: xor         $v0, $v1, $t3
    ctx->r2 = ctx->r3 ^ ctx->r11;
    // 0x80100798: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8010079C: beq         $v0, $zero, L_801007B0
    if (ctx->r2 == 0) {
        // 0x801007A0: nop
    
            goto L_801007B0;
    }
    // 0x801007A0: nop

    // 0x801007A4: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x801007A8: xor         $v0, $v1, $t4
    ctx->r2 = ctx->r3 ^ ctx->r12;
    // 0x801007AC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_801007B0:
    // 0x801007B0: jr          $ra
    // 0x801007B4: nop

    return;
    // 0x801007B4: nop

;}
RECOMP_FUNC void func_800F5D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5D70: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5D74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5D78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5D7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5D80: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5D84: jal         0x8009BB24
    // 0x800F5D88: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8009BB24(rdram, ctx);
        goto after_0;
    // 0x800F5D88: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5D90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5D94: jr          $ra
    // 0x800F5D98: nop

    return;
    // 0x800F5D98: nop

;}
RECOMP_FUNC void _bskazpaddle_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083538: syscall     65
    recomp_syscall_handler(rdram, ctx, 0x80083538);
    return;
    // 0x8008353C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80095790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095790: jr          $ra
    // 0x80095794: addiu       $v0, $zero, 0xAC
    ctx->r2 = ADD32(0, 0XAC);
    return;
    // 0x80095794: addiu       $v0, $zero, 0xAC
    ctx->r2 = ADD32(0, 0XAC);
;}
RECOMP_FUNC void sucoasterdata_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800004: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(3282, 0X3C0) << 16);
    // 0x80800008: lhu         $t8, 0x3C0($t8)
    ctx->r24 = MEM_HU(ctx->r24, (int16_t)RELOC_LO16(3282, 0X3C0));
    // 0x8080000C: lw          $v0, 0x24($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X24);
    // 0x80800010: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3282, 0X41C) << 16);
    // 0x80800014: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800018: srl         $t7, $v0, 22
    ctx->r15 = S32(U32(ctx->r2) >> 22);
    // 0x8080001C: bne         $t7, $t8, L_8080002C
    if (ctx->r15 != ctx->r24) {
        // 0x80800020: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8080002C;
    }
    // 0x80800020: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80800024: jr          $ra
    // 0x80800028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080002C:
    // 0x8080002C: addiu       $a0, $a0, 0x41C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3282, 0X41C));
    // 0x80800030: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_80800034:
    // 0x80800034: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x80800038: bnel        $v0, $t9, L_8080004C
    if (ctx->r2 != ctx->r25) {
        // 0x8080003C: lhu         $t0, 0x5C($a0)
        ctx->r8 = MEM_HU(ctx->r4, 0X5C);
            goto L_8080004C;
    }
    goto skip_0;
    // 0x8080003C: lhu         $t0, 0x5C($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X5C);
    skip_0:
    // 0x80800040: jr          $ra
    // 0x80800044: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800044: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800048: lhu         $t0, 0x5C($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X5C);
L_8080004C:
    // 0x8080004C: bnel        $v0, $t0, L_80800060
    if (ctx->r2 != ctx->r8) {
        // 0x80800050: lhu         $t1, 0xB8($a0)
        ctx->r9 = MEM_HU(ctx->r4, 0XB8);
            goto L_80800060;
    }
    goto skip_1;
    // 0x80800050: lhu         $t1, 0xB8($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0XB8);
    skip_1:
    // 0x80800054: jr          $ra
    // 0x80800058: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x80800058: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8080005C: lhu         $t1, 0xB8($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0XB8);
L_80800060:
    // 0x80800060: bnel        $v0, $t1, L_80800074
    if (ctx->r2 != ctx->r9) {
        // 0x80800064: lhu         $t2, 0x114($a0)
        ctx->r10 = MEM_HU(ctx->r4, 0X114);
            goto L_80800074;
    }
    goto skip_2;
    // 0x80800064: lhu         $t2, 0x114($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X114);
    skip_2:
    // 0x80800068: jr          $ra
    // 0x8080006C: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x8080006C: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x80800070: lhu         $t2, 0x114($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X114);
L_80800074:
    // 0x80800074: bnel        $v0, $t2, L_80800088
    if (ctx->r2 != ctx->r10) {
        // 0x80800078: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80800088;
    }
    goto skip_3;
    // 0x80800078: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_3:
    // 0x8080007C: jr          $ra
    // 0x80800080: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x80800080: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x80800084: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80800088:
    // 0x80800088: bne         $v1, $a1, L_80800034
    if (ctx->r3 != ctx->r5) {
        // 0x8080008C: addiu       $a0, $a0, 0x170
        ctx->r4 = ADD32(ctx->r4, 0X170);
            goto L_80800034;
    }
    // 0x8080008C: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    // 0x80800090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void func_800D5804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5804: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D5808: lbu         $v0, -0x481C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X481C);
    // 0x800D580C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D5810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5814: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800D5818: blez        $v0, L_800D5858
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D581C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800D5858;
    }
    // 0x800D581C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D5820: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D5824: lw          $t6, 0x7AD0($t6)
    if (tooie_more_memory()) ctx->r14 = MEM_W(ctx->r14, 0X7AD0); else ctx->r14 = MEM_W(ctx->r14, -0X4BB0);
    // 0x800D5828: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D582C: addiu       $a1, $a1, 0x7AD0
    if (tooie_more_memory()) ctx->r5 = ADD32(ctx->r5, 0X7AD0); else ctx->r5 = ADD32(ctx->r5, -0X4BB0);
    // 0x800D5830: beq         $a0, $t6, L_800D5858
    if (ctx->r4 == ctx->r14) {
        // 0x800D5834: nop
    
            goto L_800D5858;
    }
    // 0x800D5834: nop

    // 0x800D5838: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D583C:
    // 0x800D583C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D5840: beq         $at, $zero, L_800D5858
    if (ctx->r1 == 0) {
        // 0x800D5844: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800D5858;
    }
    // 0x800D5844: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800D5848: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800D584C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800D5850: bnel        $a0, $t9, L_800D583C
    if (ctx->r4 != ctx->r25) {
        // 0x800D5854: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D583C;
    }
    goto skip_0;
    // 0x800D5854: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_800D5858:
    // 0x800D5858: bnel        $v1, $v0, L_800D586C
    if (ctx->r3 != ctx->r2) {
        // 0x800D585C: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_800D586C;
    }
    goto skip_1;
    // 0x800D585C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    skip_1:
    // 0x800D5860: b           L_800D589C
    // 0x800D5864: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800D589C;
    // 0x800D5864: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D5868: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_800D586C:
    // 0x800D586C: jal         0x8001BAFC
    // 0x800D5870: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    defrag(rdram, ctx);
        goto after_0;
    // 0x800D5870: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D5874: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800D5878: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D587C: addiu       $a1, $a1, 0x7AD0
    if (tooie_more_memory()) ctx->r5 = ADD32(ctx->r5, 0X7AD0); else ctx->r5 = ADD32(ctx->r5, -0X4BB0);
    // 0x800D5880: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800D5884: beq         $v0, $a0, L_800D5898
    if (ctx->r2 == ctx->r4) {
        // 0x800D5888: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D5898;
    }
    // 0x800D5888: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D588C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800D5890: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x800D5894: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_800D5898:
    // 0x800D5898: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800D589C:
    // 0x800D589C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D58A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D58A4: jr          $ra
    // 0x800D58A8: nop

    return;
    // 0x800D58A8: nop

;}
RECOMP_FUNC void func_80800000_chlavacolumns(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80800200
    // 0x80800010: lui         $a1, 0xC3C8
    ctx->r5 = S32(0XC3C8 << 16);
    func_80800200_chlavacolumns(rdram, ctx);
        goto after_0;
    // 0x80800010: lui         $a1, 0xC3C8
    ctx->r5 = S32(0XC3C8 << 16);
    after_0:
    // 0x80800014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800018: jal         0x800EFD24
    // 0x8080001C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8080001C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800020: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x80800024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800028: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080002C: jal         0x80103014
    // 0x80800030: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    func_80103014(rdram, ctx);
        goto after_2;
    // 0x80800030: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    after_2:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void func_80800090_chbosskogsdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800094: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800098: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080009C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808000A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000A8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808000AC: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x808000B0: beq         $at, $zero, L_808003E4
    if (ctx->r1 == 0) {
        // 0x808000B4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808003E4;
    }
    // 0x808000B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808000B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2292, 0X880) << 16);
    // 0x808000BC: addu        $at, $at, $t8
    gpr jr_addend_808000C4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000C0: lw          $t8, 0x880($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2292, 0X880));
    // 0x808000C4: jr          $t8
    // 0x808000C8: nop

    switch (jr_addend_808000C4 >> 2) {
        case 0: goto L_808003E4; break;
        case 1: goto L_808000CC; break;
        case 2: goto L_808000F4; break;
        case 3: goto L_80800180; break;
        case 4: goto L_8080020C; break;
        case 5: goto L_80800298; break;
        case 6: goto L_80800340; break;
        case 7: goto L_808003E4; break;
        case 8: goto L_808003D8; break;
        default: switch_error(__func__, 0x808000C4, 0x80800880);
    }
    // 0x808000C8: nop

L_808000CC:
    // 0x808000CC: jal         0x800D90A4
    // 0x808000D0: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x808000D0: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    after_0:
    // 0x808000D4: beq         $v0, $zero, L_808003E4
    if (ctx->r2 == 0) {
        // 0x808000D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003E4;
    }
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: jal         0x80101FDC
    // 0x808000E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x808000E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808000E4: jal         0x800DA544
    // 0x808000E8: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x808000E8: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    after_2:
    // 0x808000EC: b           L_808003E4
    // 0x808000F0: nop

        goto L_808003E4;
    // 0x808000F0: nop

L_808000F4:
    // 0x808000F4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2292, 0X90C) << 16);
    // 0x808000F8: addiu       $a3, $a3, 0x90C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2292, 0X90C));
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800104: jal         0x80089D50
    // 0x80800108: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800108: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8080010C: jal         0x800D8FF8
    // 0x80800110: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x80800110: nop

    after_4:
    // 0x80800114: lui         $at, 0xC35C
    ctx->r1 = S32(0XC35C << 16);
    // 0x80800118: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080011C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80800120: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800124: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800130: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800134: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800138: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x8080013C: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800140: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80800144: nop

    // 0x80800148: bc1f        L_80800158
    if (!c1cs) {
        // 0x8080014C: nop
    
            goto L_80800158;
    }
    // 0x8080014C: nop

    // 0x80800150: jal         0x80101FDC
    // 0x80800154: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800154: swc1        $f2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f2.u32l;
    after_5:
L_80800158:
    // 0x80800158: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2292, 0X8B0) << 16);
    // 0x8080015C: addiu       $t9, $t9, 0x8B0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2292, 0X8B0));
    // 0x80800160: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800164: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800168: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080016C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800170: jal         0x800BBCB8
    // 0x80800174: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_6;
    // 0x80800174: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80800178: b           L_808003E4
    // 0x8080017C: nop

        goto L_808003E4;
    // 0x8080017C: nop

L_80800180:
    // 0x80800180: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2292, 0X90C) << 16);
    // 0x80800184: addiu       $a3, $a3, 0x90C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2292, 0X90C));
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800190: jal         0x80089D50
    // 0x80800194: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800194: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80800198: jal         0x800D8FF8
    // 0x8080019C: nop

    func_800D8FF8(rdram, ctx);
        goto after_8;
    // 0x8080019C: nop

    after_8:
    // 0x808001A0: lui         $at, 0x451B
    ctx->r1 = S32(0X451B << 16);
    // 0x808001A4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808001A8: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x808001AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001B0: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808001BC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808001C0: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x808001C4: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x808001C8: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808001CC: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x808001D0: nop

    // 0x808001D4: bc1f        L_808001E4
    if (!c1cs) {
        // 0x808001D8: nop
    
            goto L_808001E4;
    }
    // 0x808001D8: nop

    // 0x808001DC: jal         0x80101FDC
    // 0x808001E0: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x808001E0: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
    after_9:
L_808001E4:
    // 0x808001E4: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2292, 0X8B0) << 16);
    // 0x808001E8: addiu       $t0, $t0, 0x8B0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2292, 0X8B0));
    // 0x808001EC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808001F0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808001F4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808001F8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001FC: jal         0x800BBCB8
    // 0x80800200: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_10;
    // 0x80800200: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80800204: b           L_808003E4
    // 0x80800208: nop

        goto L_808003E4;
    // 0x80800208: nop

L_8080020C:
    // 0x8080020C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2292, 0X90C) << 16);
    // 0x80800210: addiu       $a3, $a3, 0x90C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2292, 0X90C));
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080021C: jal         0x80089D50
    // 0x80800220: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_11;
    // 0x80800220: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80800224: jal         0x800D8FF8
    // 0x80800228: nop

    func_800D8FF8(rdram, ctx);
        goto after_12;
    // 0x80800228: nop

    after_12:
    // 0x8080022C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80800230: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800234: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800238: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080023C: mul.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800248: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x8080024C: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800250: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800254: nop

    // 0x80800258: bc1f        L_80800270
    if (!c1cs) {
        // 0x8080025C: nop
    
            goto L_80800270;
    }
    // 0x8080025C: nop

    // 0x80800260: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800264: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800268: jal         0x80101FDC
    // 0x8080026C: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x8080026C: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    after_13:
L_80800270:
    // 0x80800270: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2292, 0X8B0) << 16);
    // 0x80800274: addiu       $t1, $t1, 0x8B0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2292, 0X8B0));
    // 0x80800278: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080027C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800280: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800284: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800288: jal         0x800BBCB8
    // 0x8080028C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_14;
    // 0x8080028C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x80800290: b           L_808003E4
    // 0x80800294: nop

        goto L_808003E4;
    // 0x80800294: nop

L_80800298:
    // 0x80800298: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080029C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2292, 0X90C) << 16);
    // 0x808002A0: addiu       $a3, $a3, 0x90C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2292, 0X90C));
    // 0x808002A4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: jal         0x80089D50
    // 0x808002B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x808002B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x808002B4: jal         0x800D8FF8
    // 0x808002B8: nop

    func_800D8FF8(rdram, ctx);
        goto after_16;
    // 0x808002B8: nop

    after_16:
    // 0x808002BC: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x808002C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808002C4: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808002C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2292, 0X8A4) << 16);
    // 0x808002CC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D4: sub.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x808002D8: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x808002DC: lwc1        $f6, 0x8A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2292, 0X8A4));
    // 0x808002E0: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808002E4: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x808002E8: nop

    // 0x808002EC: bc1f        L_80800318
    if (!c1cs) {
        // 0x808002F0: nop
    
            goto L_80800318;
    }
    // 0x808002F0: nop

    // 0x808002F4: jal         0x80101FDC
    // 0x808002F8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_17;
    // 0x808002F8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_17:
    // 0x808002FC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2292, 0X904) << 16);
    // 0x80800300: addiu       $a2, $a2, 0x904
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2292, 0X904));
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: jal         0x80089D18
    // 0x8080030C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x8080030C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_18:
    // 0x80800310: jal         0x80089D40
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_19;
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
L_80800318:
    // 0x80800318: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2292, 0X8B0) << 16);
    // 0x8080031C: addiu       $t2, $t2, 0x8B0
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2292, 0X8B0));
    // 0x80800320: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800324: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800328: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8080032C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800330: jal         0x800BBCB8
    // 0x80800334: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BBCB8(rdram, ctx);
        goto after_20;
    // 0x80800334: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_20:
    // 0x80800338: b           L_808003E4
    // 0x8080033C: nop

        goto L_808003E4;
    // 0x8080033C: nop

L_80800340:
    // 0x80800340: lhu         $t3, 0x76($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X76);
    // 0x80800344: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800348: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080034C: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80800350: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80800354: bgez        $t4, L_80800368
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800358: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80800368;
    }
    // 0x80800358: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8080035C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800360: nop

    // 0x80800364: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80800368:
    // 0x80800368: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080036C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800370: nop

    // 0x80800374: div.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80800378: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8080037C: jal         0x800D91EC
    // 0x80800380: nop

    func_800D91EC(rdram, ctx);
        goto after_21;
    // 0x80800380: nop

    after_21:
    // 0x80800384: beq         $v0, $zero, L_808003BC
    if (ctx->r2 == 0) {
        // 0x80800388: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003BC;
    }
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: jal         0x80101FDC
    // 0x80800394: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80101FDC(rdram, ctx);
        goto after_22;
    // 0x80800394: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_22:
    // 0x80800398: jal         0x80089D40
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_23;
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808003A0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2292, 0X8F8) << 16);
    // 0x808003A4: addiu       $a2, $a2, 0x8F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2292, 0X8F8));
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: jal         0x80089D18
    // 0x808003B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_24;
    // 0x808003B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_24:
    // 0x808003B4: b           L_808003E4
    // 0x808003B8: nop

        goto L_808003E4;
    // 0x808003B8: nop

L_808003BC:
    // 0x808003BC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2292, 0X8E8) << 16);
    // 0x808003C0: addiu       $a3, $a3, 0x8E8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2292, 0X8E8));
    // 0x808003C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808003C8: jal         0x80089D50
    // 0x808003CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_25;
    // 0x808003CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_25:
    // 0x808003D0: b           L_808003E4
    // 0x808003D4: nop

        goto L_808003E4;
    // 0x808003D4: nop

L_808003D8:
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003DC: jal         0x80103110
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_26;
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
L_808003E4:
    // 0x808003E4: jal         0x80103EF4
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_27;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808003EC: lhu         $t5, 0x76($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X76);
    // 0x808003F0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003F4: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808003F8: srl         $t6, $t5, 7
    ctx->r14 = S32(U32(ctx->r13) >> 7);
    // 0x808003FC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80800400: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800404: bgez        $t6, L_80800418
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800408: cvt.s.w     $f18, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800418;
    }
    // 0x80800408: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080040C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800410: nop

    // 0x80800414: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80800418:
    // 0x80800418: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080041C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800420: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800424: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800428: div.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8080042C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800430: jal         0x800F10B4
    // 0x80800434: nop

    func_800F10B4(rdram, ctx);
        goto after_28;
    // 0x80800434: nop

    after_28:
    // 0x80800438: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8080043C: add.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800440: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80800444: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800448: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080044C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800450: jr          $ra
    // 0x80800454: nop

    return;
    // 0x80800454: nop

;}
RECOMP_FUNC void func_800131C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800131C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800131C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800131C8: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800131CC: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800131D0: addiu       $a1, $a1, 0x6958
    ctx->r5 = ADD32(ctx->r5, 0X6958);
    // 0x800131D4: addiu       $a0, $a0, 0x695C
    ctx->r4 = ADD32(ctx->r4, 0X695C);
    // 0x800131D8: jal         0x8002E070
    // 0x800131DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800131DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800131E0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800131E4: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800131E8: addiu       $a1, $a1, 0x6978
    ctx->r5 = ADD32(ctx->r5, 0X6978);
    // 0x800131EC: addiu       $a0, $a0, 0x69B8
    ctx->r4 = ADD32(ctx->r4, 0X69B8);
    // 0x800131F0: jal         0x8002E070
    // 0x800131F4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x800131F4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_1:
    // 0x800131F8: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x800131FC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80013200: addiu       $a2, $a2, 0x6978
    ctx->r6 = ADD32(ctx->r6, 0X6978);
    // 0x80013204: addiu       $a1, $a1, 0x69B8
    ctx->r5 = ADD32(ctx->r5, 0X69B8);
    // 0x80013208: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x8001320C: jal         0x8002E790
    // 0x80013210: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_2;
    // 0x80013210: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x80013214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001321C: jr          $ra
    // 0x80013220: nop

    return;
    // 0x80013220: nop

;}
RECOMP_FUNC void func_808012CC_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808012D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808012D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808012D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808012DC: jal         0x80088380
    // 0x808012E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _gcstatusDll_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808012E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808012E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808012E8: bne         $v0, $at, L_80801344
    if (ctx->r2 != ctx->r1) {
        // 0x808012EC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80801344;
    }
    // 0x808012EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808012F0: jal         0x80088368
    // 0x808012F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808012F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_1:
    // 0x808012F8: blez        $v0, L_8080132C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808012FC: nop
    
            goto L_8080132C;
    }
    // 0x808012FC: nop

L_80801300:
    // 0x80801300: jal         0x800F53D0
    // 0x80801304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F53D0(rdram, ctx);
        goto after_2;
    // 0x80801304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801308: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080130C: jal         0x80085540
    // 0x80801310: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _badeathmatch_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80801310: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80801314: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801318: jal         0x80088368
    // 0x8080131C: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x8080131C: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    after_4:
    // 0x80801320: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801324: bne         $at, $zero, L_80801300
    if (ctx->r1 != 0) {
        // 0x80801328: nop
    
            goto L_80801300;
    }
    // 0x80801328: nop

L_8080132C:
    // 0x8080132C: beq         $s1, $zero, L_8080133C
    if (ctx->r17 == 0) {
        // 0x80801330: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8080133C;
    }
    // 0x80801330: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80801334: b           L_80801348
    // 0x80801338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801348;
    // 0x80801338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080133C:
    // 0x8080133C: b           L_80801348
    // 0x80801340: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80801348;
    // 0x80801340: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80801344:
    // 0x80801344: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801348:
    // 0x80801348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080134C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801350: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801354: jr          $ra
    // 0x80801358: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801358: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void gczoombox_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803218: lbu         $t6, 0x177($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X177);
    // 0x8080321C: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x80803220: bne         $t7, $zero, L_80803238
    if (ctx->r15 != 0) {
        // 0x80803224: nop
    
            goto L_80803238;
    }
    // 0x80803224: nop

    // 0x80803228: beq         $a2, $zero, L_80803238
    if (ctx->r6 == 0) {
        // 0x8080322C: nop
    
            goto L_80803238;
    }
    // 0x8080322C: nop

    // 0x80803230: bne         $a1, $zero, L_80803240
    if (ctx->r5 != 0) {
        // 0x80803234: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80803240;
    }
    // 0x80803234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803238:
    // 0x80803238: jr          $ra
    // 0x8080323C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8080323C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803240:
    // 0x80803240: sb          $zero, 0x175($a0)
    MEM_B(0X175, ctx->r4) = 0;
    // 0x80803244: blez        $a1, L_808032C0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80803248: sb          $a1, 0x174($a0)
        MEM_B(0X174, ctx->r4) = ctx->r5;
            goto L_808032C0;
    }
    // 0x80803248: sb          $a1, 0x174($a0)
    MEM_B(0X174, ctx->r4) = ctx->r5;
    // 0x8080324C: andi        $t2, $a1, 0x3
    ctx->r10 = ctx->r5 & 0X3;
    // 0x80803250: beq         $t2, $zero, L_80803280
    if (ctx->r10 == 0) {
        // 0x80803254: or          $t1, $t2, $zero
        ctx->r9 = ctx->r10 | 0;
            goto L_80803280;
    }
    // 0x80803254: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
    // 0x80803258: sll         $v1, $zero, 2
    ctx->r3 = S32(0 << 2);
    // 0x8080325C: addu        $a3, $a0, $v1
    ctx->r7 = ADD32(ctx->r4, ctx->r3);
    // 0x80803260: addu        $t0, $a2, $v1
    ctx->r8 = ADD32(ctx->r6, ctx->r3);
L_80803264:
    // 0x80803264: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80803268: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080326C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80803270: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80803274: bne         $t1, $v0, L_80803264
    if (ctx->r9 != ctx->r2) {
        // 0x80803278: sw          $t8, 0x178($a3)
        MEM_W(0X178, ctx->r7) = ctx->r24;
            goto L_80803264;
    }
    // 0x80803278: sw          $t8, 0x178($a3)
    MEM_W(0X178, ctx->r7) = ctx->r24;
    // 0x8080327C: beq         $v0, $a1, L_808032C0
    if (ctx->r2 == ctx->r5) {
        // 0x80803280: sll         $v1, $v0, 2
        ctx->r3 = S32(ctx->r2 << 2);
            goto L_808032C0;
    }
L_80803280:
    // 0x80803280: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80803284: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80803288: addu        $t1, $t9, $a2
    ctx->r9 = ADD32(ctx->r25, ctx->r6);
    // 0x8080328C: addu        $a3, $a0, $v1
    ctx->r7 = ADD32(ctx->r4, ctx->r3);
    // 0x80803290: addu        $t0, $a2, $v1
    ctx->r8 = ADD32(ctx->r6, ctx->r3);
L_80803294:
    // 0x80803294: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80803298: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8080329C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x808032A0: sw          $t3, 0x16C($a3)
    MEM_W(0X16C, ctx->r7) = ctx->r11;
    // 0x808032A4: lw          $t4, -0xC($t0)
    ctx->r12 = MEM_W(ctx->r8, -0XC);
    // 0x808032A8: sw          $t4, 0x170($a3)
    MEM_W(0X170, ctx->r7) = ctx->r12;
    // 0x808032AC: lw          $t5, -0x8($t0)
    ctx->r13 = MEM_W(ctx->r8, -0X8);
    // 0x808032B0: sw          $t5, 0x174($a3)
    MEM_W(0X174, ctx->r7) = ctx->r13;
    // 0x808032B4: lw          $t6, -0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, -0X4);
    // 0x808032B8: bne         $t0, $t1, L_80803294
    if (ctx->r8 != ctx->r9) {
        // 0x808032BC: sw          $t6, 0x178($a3)
        MEM_W(0X178, ctx->r7) = ctx->r14;
            goto L_80803294;
    }
    // 0x808032BC: sw          $t6, 0x178($a3)
    MEM_W(0X178, ctx->r7) = ctx->r14;
L_808032C0:
    // 0x808032C0: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x808032C4: beq         $at, $zero, L_80803320
    if (ctx->r1 == 0) {
        // 0x808032C8: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80803320;
    }
    // 0x808032C8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x808032CC: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x808032D0: subu        $a2, $t0, $a1
    ctx->r6 = SUB32(ctx->r8, ctx->r5);
    // 0x808032D4: andi        $t7, $a2, 0x3
    ctx->r15 = ctx->r6 & 0X3;
    // 0x808032D8: beq         $t7, $zero, L_808032FC
    if (ctx->r15 == 0) {
        // 0x808032DC: addu        $v1, $t7, $a1
        ctx->r3 = ADD32(ctx->r15, ctx->r5);
            goto L_808032FC;
    }
    // 0x808032DC: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x808032E0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x808032E4: addu        $a3, $a0, $t8
    ctx->r7 = ADD32(ctx->r4, ctx->r24);
L_808032E8:
    // 0x808032E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808032EC: sw          $zero, 0x17C($a3)
    MEM_W(0X17C, ctx->r7) = 0;
    // 0x808032F0: bne         $v1, $v0, L_808032E8
    if (ctx->r3 != ctx->r2) {
        // 0x808032F4: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_808032E8;
    }
    // 0x808032F4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x808032F8: beq         $v0, $t0, L_80803320
    if (ctx->r2 == ctx->r8) {
        // 0x808032FC: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80803320;
    }
L_808032FC:
    // 0x808032FC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80803300: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
L_80803304:
    // 0x80803304: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80803308: sw          $zero, 0x180($a3)
    MEM_W(0X180, ctx->r7) = 0;
    // 0x8080330C: sw          $zero, 0x184($a3)
    MEM_W(0X184, ctx->r7) = 0;
    // 0x80803310: sw          $zero, 0x188($a3)
    MEM_W(0X188, ctx->r7) = 0;
    // 0x80803314: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80803318: bne         $v0, $t0, L_80803304
    if (ctx->r2 != ctx->r8) {
        // 0x8080331C: sw          $zero, 0x16C($a3)
        MEM_W(0X16C, ctx->r7) = 0;
            goto L_80803304;
    }
    // 0x8080331C: sw          $zero, 0x16C($a3)
    MEM_W(0X16C, ctx->r7) = 0;
L_80803320:
    // 0x80803320: lbu         $t3, 0x177($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X177);
    // 0x80803324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80803328: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x8080332C: sb          $t4, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r12;
    // 0x80803330: jr          $ra
    // 0x80803334: nop

    return;
    // 0x80803334: nop

;}
RECOMP_FUNC void _cheggnormal_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087250: syscall     539
    recomp_syscall_handler(rdram, ctx, 0x80087250);
    return;
    // 0x80087254: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chappearfx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862D0: syscall     303
    recomp_syscall_handler(rdram, ctx, 0x800862D0);
    return;
    // 0x800862D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chhandcart_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802684: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1632, 0X4DC4) << 16);
    // 0x80802688: jr          $ra
    // 0x8080268C: addiu       $v0, $v0, 0x4DC4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1632, 0X4DC4));
    return;
    // 0x8080268C: addiu       $v0, $v0, 0x4DC4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1632, 0X4DC4));
;}
RECOMP_FUNC void func_80800478_idtwinkle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800478: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080047C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800480: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800484: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800488: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080048C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800490: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80800494: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800498: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8080049C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808004A0: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x808004A4: lh          $a1, 0xC($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XC);
    // 0x808004A8: jal         0x800DC214
    // 0x808004AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DC214(rdram, ctx);
        goto after_0;
    // 0x808004AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808004B0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808004B4: sh          $v0, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r2;
    // 0x808004B8: sh          $zero, 0x24($s1)
    MEM_H(0X24, ctx->r17) = 0;
    // 0x808004BC: addiu       $a2, $a2, -0x7210
    ctx->r6 = ADD32(ctx->r6, -0X7210);
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808004C8: jal         0x80088670
    // 0x808004CC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _glid_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808004CC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
    // 0x808004D0: lh          $a0, 0x18($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X18);
    // 0x808004D4: jal         0x800DC214
    // 0x808004D8: lh          $a1, 0x1A($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X1A);
    func_800DC214(rdram, ctx);
        goto after_2;
    // 0x808004D8: lh          $a1, 0x1A($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X1A);
    after_2:
    // 0x808004DC: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808004E0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808004E4: sh          $zero, 0x28($s1)
    MEM_H(0X28, ctx->r17) = 0;
    // 0x808004E8: addiu       $a2, $a2, -0x7218
    ctx->r6 = ADD32(ctx->r6, -0X7218);
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808004F4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x808004F8: mflo        $t6
    ctx->r14 = lo;
    // 0x808004FC: sw          $t6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r14;
    // 0x80800500: jal         0x80088670
    // 0x80800504: nop

    _glid_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800504: nop

    after_3:
    // 0x80800508: lh          $t7, 0x28($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X28);
    // 0x8080050C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800510: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800514: blez        $t7, L_8080057C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80800518: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8080057C;
    }
    // 0x80800518: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080051C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800520: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800524: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x80800528: lw          $t8, 0x2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2C);
L_8080052C:
    // 0x8080052C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800530: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x80800534: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80800538: swc1        $f20, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f20.u32l;
    // 0x8080053C: lw          $t0, 0x2C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X2C);
    // 0x80800540: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80800544: sb          $s3, 0xF($t1)
    MEM_B(0XF, ctx->r9) = ctx->r19;
    // 0x80800548: lw          $t2, 0x2C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X2C);
    // 0x8080054C: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80800550: jal         0x800DC264
    // 0x80800554: sb          $zero, 0xE($t3)
    MEM_B(0XE, ctx->r11) = 0;
    func_800DC264(rdram, ctx);
        goto after_4;
    // 0x80800554: sb          $zero, 0xE($t3)
    MEM_B(0XE, ctx->r11) = 0;
    after_4:
    // 0x80800558: lw          $t4, 0x2C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X2C);
    // 0x8080055C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800560: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80800564: swc1        $f0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f0.u32l;
    // 0x80800568: lh          $t6, 0x28($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X28);
    // 0x8080056C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800570: slt         $at, $s2, $t6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800574: bnel        $at, $zero, L_8080052C
    if (ctx->r1 != 0) {
        // 0x80800578: lw          $t8, 0x2C($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X2C);
            goto L_8080052C;
    }
    goto skip_0;
    // 0x80800578: lw          $t8, 0x2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2C);
    skip_0:
L_8080057C:
    // 0x8080057C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800580: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800584: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800588: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8080058C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800590: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800594: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800598: jr          $ra
    // 0x8080059C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080059C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void bsvan_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801814: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080181C: jal         0x800F53D0
    // 0x80801820: nop

    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x80801820: nop

    after_0:
    // 0x80801824: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801828: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080182C: jal         0x8009C128
    // 0x80801830: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x80801830: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80801834: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80801838: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8080183C: lw          $a1, 0x188($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X188);
    // 0x80801840: jal         0x800EE7F8
    // 0x80801844: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80801844: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80801848: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080184C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801850: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80801854: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801858: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080185C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801860: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801864: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80801868: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8080186C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80801870: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80801874: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80801878: jal         0x80087260
    // 0x8080187C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    _chfaircoin_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x8080187C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80801880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801884: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801888: jr          $ra
    // 0x8080188C: nop

    return;
    // 0x8080188C: nop

;}
RECOMP_FUNC void func_800FA9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA9A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FA9AC: jr          $ra
    // 0x800FA9B0: sb          $a0, 0x57B0($at)
    MEM_B(0X57B0, ctx->r1) = ctx->r4;
    return;
    // 0x800FA9B0: sb          $a0, 0x57B0($at)
    MEM_B(0X57B0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void mlspline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80800098: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8080009C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808000A0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808000A4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808000A8: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x808000AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808000B0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x808000B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808000B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000BC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x808000C0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808000C4: add.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f12.fl;
L_808000C8:
    // 0x808000C8: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808000CC: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x808000D0: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
    // 0x808000D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808000D8: add.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f10.fl;
    // 0x808000DC: mul.s       $f4, $f20, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x808000E0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808000E4: add.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x808000E8: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x808000EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808000F0: sub.s       $f6, $f2, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x808000F4: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x808000F8: mul.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x808000FC: sub.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80800100: add.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800104: swc1        $f8, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80800108: lwc1        $f8, -0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, -0X4);
    // 0x8080010C: mul.s       $f8, $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80800110: swc1        $f8, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80800114: lwc1        $f8, -0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, -0X4);
    // 0x80800118: add.s       $f12, $f8, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8080011C: bne         $v0, $a1, L_808000C8
    if (ctx->r2 != ctx->r5) {
        // 0x80800120: swc1        $f12, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f12.u32l;
            goto L_808000C8;
    }
    // 0x80800120: swc1        $f12, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f12.u32l;
    // 0x80800124: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x80800128: jr          $ra
    // 0x8080012C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8080012C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80800C04_chnutsnbolts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C0C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800C10: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1304, 0XF48) << 16);
    // 0x80800C14: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x80800C18: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800C1C: addiu       $a2, $a2, 0xF48
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1304, 0XF48));
    // 0x80800C20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800C24: jal         0x80089D20
    // 0x80800C28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800C28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C2C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1304, 0XCC0) << 16);
    // 0x80800C30: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1304, 0XF58) << 16);
    // 0x80800C34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C38: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C3C: addiu       $a3, $a3, 0xF58
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1304, 0XF58));
    // 0x80800C40: jal         0x80089D28
    // 0x80800C44: addiu       $a2, $a2, 0xCC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1304, 0XCC0));
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800C44: addiu       $a2, $a2, 0xCC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1304, 0XCC0));
    after_1:
    // 0x80800C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C50: jr          $ra
    // 0x80800C54: nop

    return;
    // 0x80800C54: nop

    // 0x80800C58: nop

    // 0x80800C5C: nop

;}
RECOMP_FUNC void func_80800CDC_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800CE8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1216, 0X1224) << 16);
    // 0x80800CEC: addiu       $a2, $a2, 0x1224
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1216, 0X1224));
    // 0x80800CF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800CF4: jal         0x800C4350
    // 0x80800CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_0;
    // 0x80800CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800CFC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800D00: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x80800D04: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1216, 0X1038) << 16);
    // 0x80800D08: lw          $t7, 0x6C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X6C);
    // 0x80800D0C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800D10: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80800D14: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80800D18: jal         0x800C32C4
    // 0x80800D1C: lbu         $a1, 0x1038($a1)
    ctx->r5 = MEM_BU(ctx->r5, (int16_t)RELOC_LO16(1216, 0X1038));
    func_800C32C4(rdram, ctx);
        goto after_1;
    // 0x80800D1C: lbu         $a1, 0x1038($a1)
    ctx->r5 = MEM_BU(ctx->r5, (int16_t)RELOC_LO16(1216, 0X1038));
    after_1:
    // 0x80800D20: jal         0x800C3BDC
    // 0x80800D24: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    func_800C3BDC(rdram, ctx);
        goto after_2;
    // 0x80800D24: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    after_2:
    // 0x80800D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D30: jr          $ra
    // 0x80800D34: nop

    return;
    // 0x80800D34: nop

;}
RECOMP_FUNC void func_808002BC_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002CC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808002D0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808002D4: jal         0x800EEB9C
    // 0x808002D8: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_0;
    // 0x808002D8: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    after_0:
    // 0x808002DC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808002E0: jal         0x800EF04C
    // 0x808002E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x808002E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808002E8: jal         0x800F54E4
    // 0x808002EC: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808002EC: nop

    after_2:
    // 0x808002F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002F4: jal         0x800F82D4
    // 0x808002F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_3;
    // 0x808002F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808002FC: jal         0x800F54E4
    // 0x80800300: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800300: nop

    after_4:
    // 0x80800304: jal         0x800F497C
    // 0x80800308: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F497C(rdram, ctx);
        goto after_5;
    // 0x80800308: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8080030C: jal         0x800F54E4
    // 0x80800310: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80800310: nop

    after_6:
    // 0x80800314: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80800318: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x8080031C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800320: jal         0x800F49D4
    // 0x80800324: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_7;
    // 0x80800324: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80800328: jal         0x800F54E4
    // 0x8080032C: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x8080032C: nop

    after_8:
    // 0x80800330: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800334: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800338: jal         0x800F4AC0
    // 0x8080033C: lui         $a2, 0x432A
    ctx->r6 = S32(0X432A << 16);
    func_800F4AC0(rdram, ctx);
        goto after_9;
    // 0x8080033C: lui         $a2, 0x432A
    ctx->r6 = S32(0X432A << 16);
    after_9:
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: jal         0x8080082C
    // 0x80800348: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080082C_chmadamegrunty(rdram, ctx);
        goto after_10;
    // 0x80800348: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x8080034C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800350: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800354: jal         0x800DC298
    // 0x80800358: nop

    func_800DC298(rdram, ctx);
        goto after_11;
    // 0x80800358: nop

    after_11:
    // 0x8080035C: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800360: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x80800364: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80800368: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x8080036C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800370: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800374: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80800378: addiu       $a0, $zero, 0x3D4
    ctx->r4 = ADD32(0, 0X3D4);
    // 0x8080037C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800380: sll         $t4, $t2, 11
    ctx->r12 = S32(ctx->r10 << 11);
    // 0x80800384: bgez        $t4, L_80800394
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800388: nop
    
            goto L_80800394;
    }
    // 0x80800388: nop

    // 0x8080038C: jal         0x80101180
    // 0x80800390: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_12;
    // 0x80800390: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
L_80800394:
    // 0x80800394: jal         0x80085710
    // 0x80800398: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_13;
    // 0x80800398: nop

    after_13:
    // 0x8080039C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003A8: jr          $ra
    // 0x808003AC: nop

    return;
    // 0x808003AC: nop

;}
RECOMP_FUNC void func_80801718_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801718: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080171C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801720: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x80801724: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801728: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080172C: bgez        $a1, L_80801774
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80801730: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80801774;
    }
    // 0x80801730: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801734: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80801738: bnel        $at, $zero, L_80801764
    if (ctx->r1 != 0) {
        // 0x8080173C: slti        $at, $s0, 0x2
        ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_80801764;
    }
    goto skip_0;
    // 0x8080173C: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    skip_0:
L_80801740:
    // 0x80801740: jal         0x808016F0
    // 0x80801744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016F0_gcnewpause(rdram, ctx);
        goto after_0;
    // 0x80801744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801748: bnel        $v0, $zero, L_80801764
    if (ctx->r2 != 0) {
        // 0x8080174C: slti        $at, $s0, 0x2
        ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_80801764;
    }
    goto skip_1;
    // 0x8080174C: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    skip_1:
    // 0x80801750: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80801754: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80801758: beq         $at, $zero, L_80801740
    if (ctx->r1 == 0) {
        // 0x8080175C: nop
    
            goto L_80801740;
    }
    // 0x8080175C: nop

    // 0x80801760: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
L_80801764:
    // 0x80801764: beql        $at, $zero, L_808017B8
    if (ctx->r1 == 0) {
        // 0x80801768: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808017B8;
    }
    goto skip_2;
    // 0x80801768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8080176C: b           L_808017B4
    // 0x80801770: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
        goto L_808017B4;
    // 0x80801770: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
L_80801774:
    // 0x80801774: blez        $a1, L_808017B4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80801778: slti        $at, $v0, 0xE
        ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
            goto L_808017B4;
    }
    // 0x80801778: slti        $at, $v0, 0xE
    ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // 0x8080177C: beql        $at, $zero, L_808017A8
    if (ctx->r1 == 0) {
        // 0x80801780: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_808017A8;
    }
    goto skip_3;
    // 0x80801780: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    skip_3:
L_80801784:
    // 0x80801784: jal         0x808016F0
    // 0x80801788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016F0_gcnewpause(rdram, ctx);
        goto after_1;
    // 0x80801788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080178C: bnel        $v0, $zero, L_808017A8
    if (ctx->r2 != 0) {
        // 0x80801790: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_808017A8;
    }
    goto skip_4;
    // 0x80801790: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    skip_4:
    // 0x80801794: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801798: slti        $at, $s0, 0xE
    ctx->r1 = SIGNED(ctx->r16) < 0XE ? 1 : 0;
    // 0x8080179C: bne         $at, $zero, L_80801784
    if (ctx->r1 != 0) {
        // 0x808017A0: nop
    
            goto L_80801784;
    }
    // 0x808017A0: nop

    // 0x808017A4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
L_808017A8:
    // 0x808017A8: bnel        $s0, $at, L_808017B8
    if (ctx->r16 != ctx->r1) {
        // 0x808017AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808017B8;
    }
    goto skip_5;
    // 0x808017AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x808017B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
L_808017B4:
    // 0x808017B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808017B8:
    // 0x808017B8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808017BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808017C0: jr          $ra
    // 0x808017C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808017C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bsbtrot_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080102C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801034: jal         0x8080061C
    // 0x80801038: nop

    func_8080061C_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80801038: nop

    after_0:
    // 0x8080103C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801044: jr          $ra
    // 0x80801048: nop

    return;
    // 0x80801048: nop

;}
RECOMP_FUNC void _sumumbofx_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089880: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089880);
    return;
    // 0x80089884: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _sujiggy_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6E0: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A6E0);
    return;
    // 0x8008A6E4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80110890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110890: jr          $ra
    // 0x80110894: lbu         $v0, 0x72($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X72);
    return;
    // 0x80110894: lbu         $v0, 0x72($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X72);
;}
RECOMP_FUNC void bstaxi_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801300: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801308: jal         0x808000D4
    // 0x8080130C: nop

    bstaxi_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080130C: nop

    after_0:
    // 0x80801310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801318: jr          $ra
    // 0x8080131C: nop

    return;
    // 0x8080131C: nop

;}
RECOMP_FUNC void chpoolkids_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1092, 0X13F0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1092, 0X13F0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1092, 0X13F0));
;}
RECOMP_FUNC void func_800D88C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D88C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D88C4: lw          $a0, -0x3FE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3FE0);
    // 0x800D88C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D88CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D88D0: beql        $a0, $zero, L_800D88EC
    if (ctx->r4 == 0) {
        // 0x800D88D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D88EC;
    }
    goto skip_0;
    // 0x800D88D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D88D8: jal         0x800B32E4
    // 0x800D88DC: nop

    freelist_defrag(rdram, ctx);
        goto after_0;
    // 0x800D88DC: nop

    after_0:
    // 0x800D88E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D88E4: sw          $v0, -0x3FE0($at)
    MEM_W(-0X3FE0, ctx->r1) = ctx->r2;
    // 0x800D88E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D88EC:
    // 0x800D88EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D88F0: jr          $ra
    // 0x800D88F4: nop

    return;
    // 0x800D88F4: nop

;}
RECOMP_FUNC void func_80020128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020128: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002012C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020130: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80020134: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80020138: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8002013C: jal         0x80027170
    // 0x80020140: lb          $a0, 0x15($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X15);
    func_80027170(rdram, ctx);
        goto after_0;
    // 0x80020140: lb          $a0, 0x15($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X15);
    after_0:
    // 0x80020144: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80020148: lwc1        $f4, 0x2C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X2C);
    // 0x8002014C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80020150: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80020154: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80020158: sh          $t9, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r25;
    // 0x8002015C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80020160: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80020164: addiu       $t1, $sp, 0x1C
    ctx->r9 = ADD32(ctx->r29, 0X1C);
    // 0x80020168: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8002016C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80020170: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80020174: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x80020178: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8002017C: ori         $a2, $zero, 0x8235
    ctx->r6 = 0 | 0X8235;
    // 0x80020180: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80020184: jal         0x80026500
    // 0x80020188: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80026500(rdram, ctx);
        goto after_1;
    // 0x80020188: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
    // 0x8002018C: b           L_80020194
    // 0x80020190: nop

        goto L_80020194;
    // 0x80020190: nop

L_80020194:
    // 0x80020194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020198: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002019C: jr          $ra
    // 0x800201A0: nop

    return;
    // 0x800201A0: nop

;}
RECOMP_FUNC void func_800EE830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE830: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800EE834: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800EE838: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800EE83C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800EE840: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800EE844: jr          $ra
    // 0x800EE848: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    return;
    // 0x800EE848: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_808001A8_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001B4: jal         0x8009EF10
    // 0x808001B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x808001B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001C0: bne         $v0, $at, L_808001CC
    if (ctx->r2 != ctx->r1) {
        // 0x808001C4: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808001CC;
    }
    // 0x808001C4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C8: addiu       $v1, $zero, 0x135
    ctx->r3 = ADD32(0, 0X135);
L_808001CC:
    // 0x808001CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808001D4: jal         0x80091A58
    // 0x808001D8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    bakey_pressed(rdram, ctx);
        goto after_1;
    // 0x808001D8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x808001DC: beq         $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x808001E0: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808001E8;
    }
    // 0x808001E0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E4: addiu       $v1, $zero, 0x134
    ctx->r3 = ADD32(0, 0X134);
L_808001E8:
    // 0x808001E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001EC: jal         0x808000F8
    // 0x808001F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_808000F8_bsbabykaz(rdram, ctx);
        goto after_2;
    // 0x808001F0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x808001F4: beq         $v0, $zero, L_80800200
    if (ctx->r2 == 0) {
        // 0x808001F8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800200;
    }
    // 0x808001F8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808001FC: addiu       $v1, $zero, 0x94
    ctx->r3 = ADD32(0, 0X94);
L_80800200:
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800208: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080020C: jr          $ra
    // 0x80800210: nop

    return;
    // 0x80800210: nop

;}
RECOMP_FUNC void func_80800248_chtemplelobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080024C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800250: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800254: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800258: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8080025C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800260: jal         0x80100094
    // 0x80800264: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800264: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800268: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8080026C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800274: beq         $a3, $at, L_808002A8
    if (ctx->r7 == ctx->r1) {
        // 0x80800278: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_808002A8;
    }
    // 0x80800278: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8080027C: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800280: beq         $a3, $at, L_80800298
    if (ctx->r7 == ctx->r1) {
        // 0x80800284: addiu       $at, $zero, 0x77
        ctx->r1 = ADD32(0, 0X77);
            goto L_80800298;
    }
    // 0x80800284: addiu       $at, $zero, 0x77
    ctx->r1 = ADD32(0, 0X77);
    // 0x80800288: beql        $a3, $at, L_8080032C
    if (ctx->r7 == ctx->r1) {
        // 0x8080028C: lbu         $t6, 0x0($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X0);
            goto L_8080032C;
    }
    goto skip_0;
    // 0x8080028C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    skip_0:
    // 0x80800290: b           L_80800370
    // 0x80800294: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
        goto L_80800370;
    // 0x80800294: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_80800298:
    // 0x80800298: jal         0x80800134
    // 0x8080029C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800134_chtemplelobbydoor(rdram, ctx);
        goto after_1;
    // 0x8080029C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808002A0: b           L_80800378
    // 0x808002A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800378;
    // 0x808002A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002A8:
    // 0x808002A8: lh          $v1, 0x20($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X20);
    // 0x808002AC: addiu       $at, $zero, 0xF39
    ctx->r1 = ADD32(0, 0XF39);
    // 0x808002B0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808002B4: beq         $v1, $at, L_808002CC
    if (ctx->r3 == ctx->r1) {
        // 0x808002B8: addiu       $at, $zero, 0xF50
        ctx->r1 = ADD32(0, 0XF50);
            goto L_808002CC;
    }
    // 0x808002B8: addiu       $at, $zero, 0xF50
    ctx->r1 = ADD32(0, 0XF50);
    // 0x808002BC: beq         $v1, $at, L_808002DC
    if (ctx->r3 == ctx->r1) {
        // 0x808002C0: nop
    
            goto L_808002DC;
    }
    // 0x808002C0: nop

    // 0x808002C4: b           L_8080032C
    // 0x808002C8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
        goto L_8080032C;
    // 0x808002C8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
L_808002CC:
    // 0x808002CC: jal         0x8010108C
    // 0x808002D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_2;
    // 0x808002D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808002D4: b           L_80800378
    // 0x808002D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800378;
    // 0x808002D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002DC:
    // 0x808002DC: jal         0x800F54E4
    // 0x808002E0: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808002E0: nop

    after_3:
    // 0x808002E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002E8: jal         0x800F7B9C
    // 0x808002EC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    func_800F7B9C(rdram, ctx);
        goto after_4;
    // 0x808002EC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    after_4:
    // 0x808002F0: jal         0x800F54E4
    // 0x808002F4: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x808002F4: nop

    after_5:
    // 0x808002F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002FC: jal         0x800F7F98
    // 0x80800300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_6;
    // 0x80800300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800304: jal         0x80085710
    // 0x80800308: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_7;
    // 0x80800308: nop

    after_7:
    // 0x8080030C: jal         0x800F54E4
    // 0x80800310: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80800310: nop

    after_8:
    // 0x80800314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800318: jal         0x800F7B9C
    // 0x8080031C: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    func_800F7B9C(rdram, ctx);
        goto after_9;
    // 0x8080031C: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    after_9:
    // 0x80800320: b           L_80800378
    // 0x80800324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800378;
    // 0x80800324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800328: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
L_8080032C:
    // 0x8080032C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800330: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x80800334: bnel        $t6, $at, L_80800370
    if (ctx->r14 != ctx->r1) {
        // 0x80800338: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80800370;
    }
    goto skip_1;
    // 0x80800338: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    skip_1:
    // 0x8080033C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800340: jal         0x800F7B9C
    // 0x80800344: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    func_800F7B9C(rdram, ctx);
        goto after_10;
    // 0x80800344: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    after_10:
    // 0x80800348: jal         0x80085710
    // 0x8080034C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_11;
    // 0x8080034C: nop

    after_11:
    // 0x80800350: jal         0x800F54E4
    // 0x80800354: nop

    func_800F54E4(rdram, ctx);
        goto after_12;
    // 0x80800354: nop

    after_12:
    // 0x80800358: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080035C: jal         0x800F7B9C
    // 0x80800360: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    func_800F7B9C(rdram, ctx);
        goto after_13;
    // 0x80800360: addiu       $a1, $zero, 0x99
    ctx->r5 = ADD32(0, 0X99);
    after_13:
    // 0x80800364: b           L_80800378
    // 0x80800368: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800378;
    // 0x80800368: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080036C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_80800370:
    // 0x80800370: jal         0x80086248
    // 0x80800374: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x80800374: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_14:
L_80800378:
    // 0x80800378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080037C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800380: jr          $ra
    // 0x80800384: nop

    return;
    // 0x80800384: nop

    // 0x80800388: nop

    // 0x8080038C: nop

;}
RECOMP_FUNC void func_808001C4_bskazmove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001D4: jal         0x8008E39C
    // 0x808001D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8008E39C(rdram, ctx);
        goto after_0;
    // 0x808001D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001DC: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001E0: nop
    
            goto L_808001EC;
    }
    // 0x808001E0: nop

    // 0x808001E4: b           L_80800248
    // 0x808001E8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_80800248;
    // 0x808001E8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_808001EC:
    // 0x808001EC: jal         0x8009BB00
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001F4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808001F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001FC: nop

    // 0x80800200: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800204: nop

    // 0x80800208: bc1f        L_80800228
    if (!c1cs) {
        // 0x8080020C: nop
    
            goto L_80800228;
    }
    // 0x8080020C: nop

    // 0x80800210: jal         0x80097FB8
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097FB8(rdram, ctx);
        goto after_2;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800218: beq         $v0, $zero, L_80800244
    if (ctx->r2 == 0) {
        // 0x8080021C: addiu       $t6, $zero, 0xC4
        ctx->r14 = ADD32(0, 0XC4);
            goto L_80800244;
    }
    // 0x8080021C: addiu       $t6, $zero, 0xC4
    ctx->r14 = ADD32(0, 0XC4);
    // 0x80800220: b           L_80800244
    // 0x80800224: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_80800244;
    // 0x80800224: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800228:
    // 0x80800228: jal         0x80097FB8
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097FB8(rdram, ctx);
        goto after_3;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800230: beql        $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x80800234: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_80800248;
    }
    goto skip_0;
    // 0x80800234: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800238: jal         0x800832F8
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800240: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800244:
    // 0x80800244: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80800248:
    // 0x80800248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080024C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800254: jr          $ra
    // 0x80800258: nop

    return;
    // 0x80800258: nop

;}
RECOMP_FUNC void chboilerboss_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(932, 0X2C9C) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x2C9C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(932, 0X2C9C));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x2C9C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(932, 0X2C9C));
;}
