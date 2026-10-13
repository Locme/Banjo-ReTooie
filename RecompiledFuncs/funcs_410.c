#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800798_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800798: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080079C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007A4: jal         0x8009E6EC
    // 0x808007A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808007A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808007AC: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x808007B0: beq         $v0, $at, L_808007C8
    if (ctx->r2 == ctx->r1) {
        // 0x808007B4: addiu       $at, $zero, 0x4B
        ctx->r1 = ADD32(0, 0X4B);
            goto L_808007C8;
    }
    // 0x808007B4: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x808007B8: beql        $v0, $at, L_808007E8
    if (ctx->r2 == ctx->r1) {
        // 0x808007BC: lw          $t6, 0x160($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X160);
            goto L_808007E8;
    }
    goto skip_0;
    // 0x808007BC: lw          $t6, 0x160($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X160);
    skip_0:
    // 0x808007C0: b           L_80800830
    // 0x808007C4: nop

        goto L_80800830;
    // 0x808007C4: nop

L_808007C8:
    // 0x808007C8: jal         0x808000F0
    // 0x808007CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000F0_bsride(rdram, ctx);
        goto after_1;
    // 0x808007CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D4: jal         0x8009E830
    // 0x808007D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_2;
    // 0x808007D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808007DC: b           L_8080083C
    // 0x808007E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080083C;
    // 0x808007E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007E4: lw          $t6, 0x160($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X160);
L_808007E8:
    // 0x808007E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007F0: bne         $t6, $at, L_80800814
    if (ctx->r14 != ctx->r1) {
        // 0x808007F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800814;
    }
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F8: jal         0x808006D0
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006D0_bsride(rdram, ctx);
        goto after_3;
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800804: jal         0x8009E830
    // 0x80800808: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_4;
    // 0x80800808: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8080080C: b           L_8080083C
    // 0x80800810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080083C;
    // 0x80800810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800814:
    // 0x80800814: jal         0x808006D0
    // 0x80800818: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808006D0_bsride(rdram, ctx);
        goto after_5;
    // 0x80800818: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800820: jal         0x8009E830
    // 0x80800824: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_6;
    // 0x80800824: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800828: b           L_8080083C
    // 0x8080082C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080083C;
    // 0x8080082C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800830:
    // 0x80800830: jal         0x80099B94
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_7;
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080083C:
    // 0x8080083C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800844: jr          $ra
    // 0x80800848: nop

    return;
    // 0x80800848: nop

;}
RECOMP_FUNC void func_80800128_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080012C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800130: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800134: jal         0x8009EF1C
    // 0x80800138: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800138: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: jal         0x8009EF10
    // 0x80800144: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800144: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800148: beq         $v0, $zero, L_8080016C
    if (ctx->r2 == 0) {
        // 0x8080014C: lwc1        $f12, 0x24($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8080016C;
    }
    // 0x8080014C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800150: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800154: beq         $v0, $at, L_80800180
    if (ctx->r2 == ctx->r1) {
        // 0x80800158: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800180;
    }
    // 0x80800158: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080015C: beql        $v0, $at, L_808001A8
    if (ctx->r2 == ctx->r1) {
        // 0x80800160: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_808001A8;
    }
    goto skip_0;
    // 0x80800160: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_0:
    // 0x80800164: b           L_808001C4
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001C4;
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080016C:
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800170: jal         0x8009B9B0
    // 0x80800174: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800174: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800178: b           L_808001C4
    // 0x8080017C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001C4;
    // 0x8080017C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800180:
    // 0x80800180: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800184: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800188: jal         0x800F1214
    // 0x8080018C: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x8080018C: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    after_3:
    // 0x80800190: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800194: jal         0x8009B9B0
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080019C: b           L_808001C4
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001C4;
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
L_808001A8:
    // 0x808001A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001AC: jal         0x800F1214
    // 0x808001B0: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800F1214(rdram, ctx);
        goto after_5;
    // 0x808001B0: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_5:
    // 0x808001B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001B8: jal         0x8009B9B0
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001C4:
    // 0x808001C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001CC: jr          $ra
    // 0x808001D0: nop

    return;
    // 0x808001D0: nop

;}
RECOMP_FUNC void func_808010DC_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808010E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808010E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808010E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808010EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808010F0: jal         0x80800F88
    // 0x808010F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_80800F88_bswasher(rdram, ctx);
        goto after_0;
    // 0x808010F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x808010F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010FC: jal         0x8009D3A8
    // 0x80801100: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x80801100: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801104: jal         0x80800000
    // 0x80801108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bswasher(rdram, ctx);
        goto after_2;
    // 0x80801108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080110C: jal         0x8009EF10
    // 0x80801110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_3;
    // 0x80801110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801114: bne         $v0, $zero, L_80801120
    if (ctx->r2 != 0) {
        // 0x80801118: nop
    
            goto L_80801120;
    }
    // 0x80801118: nop

    // 0x8080111C: addiu       $s1, $zero, 0x32
    ctx->r17 = ADD32(0, 0X32);
L_80801120:
    // 0x80801120: jal         0x8008DD04
    // 0x80801124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_4;
    // 0x80801124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801128: beq         $v0, $zero, L_80801134
    if (ctx->r2 == 0) {
        // 0x8080112C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801134;
    }
    // 0x8080112C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801130: addiu       $s1, $zero, 0x36
    ctx->r17 = ADD32(0, 0X36);
L_80801134:
    // 0x80801134: jal         0x80091A58
    // 0x80801138: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_5;
    // 0x80801138: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x8080113C: beq         $v0, $zero, L_80801148
    if (ctx->r2 == 0) {
        // 0x80801140: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801148;
    }
    // 0x80801140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801144: addiu       $s1, $zero, 0x35
    ctx->r17 = ADD32(0, 0X35);
L_80801148:
    // 0x80801148: jal         0x80091A58
    // 0x8080114C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_6;
    // 0x8080114C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80801150: beq         $v0, $zero, L_8080115C
    if (ctx->r2 == 0) {
        // 0x80801154: nop
    
            goto L_8080115C;
    }
    // 0x80801154: nop

    // 0x80801158: addiu       $s1, $zero, 0x38
    ctx->r17 = ADD32(0, 0X38);
L_8080115C:
    // 0x8080115C: jal         0x8008E148
    // 0x80801160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_7;
    // 0x80801160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801164: beq         $v0, $zero, L_80801178
    if (ctx->r2 == 0) {
        // 0x80801168: nop
    
            goto L_80801178;
    }
    // 0x80801168: nop

    // 0x8080116C: jal         0x800848B0
    // 0x80801170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_8;
    // 0x80801170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801174: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80801178:
    // 0x80801178: jal         0x80800300
    // 0x8080117C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800300_bswasher(rdram, ctx);
        goto after_9;
    // 0x8080117C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801184: jal         0x8009E5C8
    // 0x80801188: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x80801188: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x8080118C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801190: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801194: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801198: jr          $ra
    // 0x8080119C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080119C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80081D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081D34: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80081D38: addiu       $v0, $v0, 0x2540
    ctx->r2 = ADD32(ctx->r2, 0X2540);
    // 0x80081D3C: subu        $v1, $a0, $v0
    ctx->r3 = SUB32(ctx->r4, ctx->r2);
    // 0x80081D40: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80081D44: bgez        $t6, L_80081D54
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80081D48: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80081D54;
    }
    // 0x80081D48: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80081D4C: jr          $ra
    // 0x80081D50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80081D50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80081D54:
    // 0x80081D54: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80081D58: addiu       $t7, $t7, -0x5678
    ctx->r15 = ADD32(ctx->r15, -0X5678);
    // 0x80081D5C: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x80081D60: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80081D64: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80081D68: beq         $at, $zero, L_80081D78
    if (ctx->r1 == 0) {
        // 0x80081D6C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80081D78;
    }
    // 0x80081D6C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80081D70: jr          $ra
    // 0x80081D74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80081D74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80081D78:
    // 0x80081D78: jr          $ra
    // 0x80081D7C: nop

    return;
    // 0x80081D7C: nop

;}
RECOMP_FUNC void basub_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080052C: jal         0x80800458
    // 0x80800530: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800458_basub(rdram, ctx);
        goto after_0;
    // 0x80800530: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80800534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080053C: jr          $ra
    // 0x80800540: nop

    return;
    // 0x80800540: nop

;}
RECOMP_FUNC void sufreezy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080005C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800064: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800068: jal         0x80100094
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800070: jal         0x8008A040
    // 0x80800074: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800074: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800078: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080007C: jal         0x8010A570
    // 0x80800080: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x80800080: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800084: beql        $s0, $zero, L_808000C0
    if (ctx->r16 == 0) {
        // 0x80800088: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808000C0;
    }
    goto skip_0;
    // 0x80800088: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x8080008C: lbu         $t6, 0x7B($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7B);
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800098: andi        $t7, $t6, 0xFFFB
    ctx->r15 = ctx->r14 & 0XFFFB;
    // 0x8080009C: jal         0x80102190
    // 0x808000A0: sb          $t7, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r15;
    func_80102190(rdram, ctx);
        goto after_3;
    // 0x808000A0: sb          $t7, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r15;
    after_3:
    // 0x808000A4: jal         0x8010A590
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_4;
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808000B4: jal         0x8010108C
    // 0x808000B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_5;
    // 0x808000B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x808000BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808000C0:
    // 0x808000C0: jal         0x80100094
    // 0x808000C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x808000C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808000C8: jal         0x8008A020
    // 0x808000CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x808000CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808000D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000DC: jr          $ra
    // 0x808000E0: nop

    return;
    // 0x808000E0: nop

;}
RECOMP_FUNC void func_808002C8_chgoldstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002D0: jal         0x8008A498
    // 0x808002D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808002D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002D8: jal         0x8010D278
    // 0x808002DC: nop

    func_8010D278(rdram, ctx);
        goto after_1;
    // 0x808002DC: nop

    after_1:
    // 0x808002E0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x808002E4: bne         $v0, $at, L_808002FC
    if (ctx->r2 != ctx->r1) {
        // 0x808002E8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002FC;
    }
    // 0x808002E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002EC: jal         0x80800150
    // 0x808002F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800150_chgoldstatue(rdram, ctx);
        goto after_2;
    // 0x808002F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x808002F4: b           L_80800320
    // 0x808002F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800320;
    // 0x808002F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002FC:
    // 0x808002FC: jal         0x800DA524
    // 0x80800300: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x80800300: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_3:
    // 0x80800304: jal         0x80088848
    // 0x80800308: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800308: nop

    after_4:
    // 0x8080030C: beq         $v0, $zero, L_8080031C
    if (ctx->r2 == 0) {
        // 0x80800310: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080031C;
    }
    // 0x80800310: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800314: jal         0x80800150
    // 0x80800318: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800150_chgoldstatue(rdram, ctx);
        goto after_5;
    // 0x80800318: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
L_8080031C:
    // 0x8080031C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800320:
    // 0x80800320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800324: jr          $ra
    // 0x80800328: nop

    return;
    // 0x80800328: nop

;}
RECOMP_FUNC void func_800F67EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F67EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F67F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F67F4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F67F8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F67FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F6800: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6804: jal         0x8009E6F8
    // 0x800F6808: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x800F6808: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F680C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6810: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800F6814: jal         0x8009CA70
    // 0x800F6818: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_8009CA70(rdram, ctx);
        goto after_1;
    // 0x800F6818: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_1:
    // 0x800F681C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F6824: jr          $ra
    // 0x800F6828: nop

    return;
    // 0x800F6828: nop

;}
RECOMP_FUNC void func_808003DC_suautobaddies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003E4: jal         0x80087508
    // 0x808003E8: nop

    _chlensflare_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808003E8: nop

    after_0:
    // 0x808003EC: beq         $v0, $zero, L_8080040C
    if (ctx->r2 == 0) {
        // 0x808003F0: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_8080040C;
    }
    // 0x808003F0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808003F4: addiu       $a0, $a0, 0x6D68
    ctx->r4 = ADD32(ctx->r4, 0X6D68);
    // 0x808003F8: addiu       $a1, $zero, 0x3FE
    ctx->r5 = ADD32(0, 0X3FE);
    // 0x808003FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800400: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800404: jal         0x80086D48
    // 0x80800408: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chbaddiesetup_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800408: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
L_8080040C:
    // 0x8080040C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800410: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800414: jr          $ra
    // 0x80800418: nop

    return;
    // 0x80800418: nop

;}
RECOMP_FUNC void func_80014FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014FE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80014FEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80014FF0: jal         0x8002F8A0
    // 0x80014FF4: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_0;
    // 0x80014FF4: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_0:
    // 0x80014FF8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80014FFC: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x80015000: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80015004: beq         $v0, $zero, L_80015024
    if (ctx->r2 == 0) {
        // 0x80015008: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80015024;
    }
    // 0x80015008: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001500C: beq         $v0, $at, L_80015024
    if (ctx->r2 == ctx->r1) {
        // 0x80015010: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80015024;
    }
    // 0x80015010: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80015014: beq         $v0, $at, L_80015038
    if (ctx->r2 == ctx->r1) {
        // 0x80015018: lui         $t7, 0x8004
        ctx->r15 = S32(0X8004 << 16);
            goto L_80015038;
    }
    // 0x80015018: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001501C: b           L_80015044
    // 0x80015020: nop

        goto L_80015044;
    // 0x80015020: nop

L_80015024:
    // 0x80015024: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80015028: addiu       $t6, $t6, -0xB20
    ctx->r14 = ADD32(ctx->r14, -0XB20);
    // 0x8001502C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80015030: b           L_80015044
    // 0x80015034: sw          $t6, -0x7098($at)
    MEM_W(-0X7098, ctx->r1) = ctx->r14;
        goto L_80015044;
    // 0x80015034: sw          $t6, -0x7098($at)
    MEM_W(-0X7098, ctx->r1) = ctx->r14;
L_80015038:
    // 0x80015038: addiu       $t7, $t7, -0xAD0
    ctx->r15 = ADD32(ctx->r15, -0XAD0);
    // 0x8001503C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80015040: sw          $t7, -0x7098($at)
    MEM_W(-0X7098, ctx->r1) = ctx->r15;
L_80015044:
    // 0x80015044: jal         0x8002F780
    // 0x80015048: lw          $a0, -0x7098($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7098);
    osViSetMode_recomp(rdram, ctx);
        goto after_1;
    // 0x80015048: lw          $a0, -0x7098($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7098);
    after_1:
    // 0x8001504C: jal         0x8002FBB0
    // 0x80015050: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_2;
    // 0x80015050: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80015054: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80015058: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001505C: sw          $t8, -0x6900($at)
    MEM_W(-0X6900, ctx->r1) = ctx->r24;
    // 0x80015060: jal         0x8002FC20
    // 0x80015064: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_3;
    // 0x80015064: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_3:
    // 0x80015068: jal         0x8002FC20
    // 0x8001506C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_4;
    // 0x8001506C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80015070: jal         0x8002FC20
    // 0x80015074: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_5;
    // 0x80015074: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_5:
    // 0x80015078: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001507C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80015080: addiu       $a1, $a1, -0x7018
    ctx->r5 = ADD32(ctx->r5, -0X7018);
    // 0x80015084: addiu       $a0, $a0, -0x7030
    ctx->r4 = ADD32(ctx->r4, -0X7030);
    // 0x80015088: jal         0x8002E070
    // 0x8001508C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_6;
    // 0x8001508C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_6:
    // 0x80015090: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80015094: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80015098: addiu       $a1, $a1, -0x6FD8
    ctx->r5 = ADD32(ctx->r5, -0X6FD8);
    // 0x8001509C: addiu       $a0, $a0, -0x6FF0
    ctx->r4 = ADD32(ctx->r4, -0X6FF0);
    // 0x800150A0: jal         0x8002E070
    // 0x800150A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_7;
    // 0x800150A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x800150A8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800150AC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800150B0: addiu       $a1, $a1, -0x6FB8
    ctx->r5 = ADD32(ctx->r5, -0X6FB8);
    // 0x800150B4: addiu       $a0, $a0, -0x6FD0
    ctx->r4 = ADD32(ctx->r4, -0X6FD0);
    // 0x800150B8: jal         0x8002E070
    // 0x800150BC: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_8;
    // 0x800150BC: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_8:
    // 0x800150C0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800150C4: addiu       $a0, $a0, -0x7030
    ctx->r4 = ADD32(ctx->r4, -0X7030);
    // 0x800150C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800150CC: jal         0x8002FD80
    // 0x800150D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osViSetEvent_recomp(rdram, ctx);
        goto after_9;
    // 0x800150D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x800150D4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800150D8: sh          $zero, -0x70A0($at)
    MEM_H(-0X70A0, ctx->r1) = 0;
    // 0x800150DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800150E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800150E4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800150E8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800150EC: sh          $t9, -0x709C($at)
    MEM_H(-0X709C, ctx->r1) = ctx->r25;
    // 0x800150F0: addiu       $v1, $v1, -0x7030
    ctx->r3 = ADD32(ctx->r3, -0X7030);
    // 0x800150F4: addiu       $v0, $v0, -0x7070
    ctx->r2 = ADD32(ctx->r2, -0X7070);
L_800150F8:
    // 0x800150F8: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800150FC: sw          $zero, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = 0;
    // 0x80015100: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x80015104: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x80015108: bne         $v0, $v1, L_800150F8
    if (ctx->r2 != ctx->r3) {
        // 0x8001510C: sw          $zero, -0x20($v0)
        MEM_W(-0X20, ctx->r2) = 0;
            goto L_800150F8;
    }
    // 0x8001510C: sw          $zero, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = 0;
    // 0x80015110: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80015114: addiu       $t0, $t0, -0x6EC8
    ctx->r8 = ADD32(ctx->r8, -0X6EC8);
    // 0x80015118: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8001511C: jal         0x80015178
    // 0x80015120: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80015178(rdram, ctx);
        goto after_10;
    // 0x80015120: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x80015124: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80015128: addiu       $t1, $t1, -0x6900
    ctx->r9 = ADD32(ctx->r9, -0X6900);
    // 0x8001512C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80015130: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80015134: lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // 0x80015138: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x8001513C: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80015140: addiu       $a3, $a3, 0x546C
    ctx->r7 = ADD32(ctx->r7, 0X546C);
    // 0x80015144: addiu       $a1, $a1, -0x6D10
    ctx->r5 = ADD32(ctx->r5, -0X6D10);
    // 0x80015148: addiu       $a0, $a0, -0x6EC0
    ctx->r4 = ADD32(ctx->r4, -0X6EC0);
    // 0x8001514C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80015150: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80015154: jal         0x8001DCB0
    // 0x80015158: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001DCB0(rdram, ctx);
        goto after_11;
    // 0x80015158: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
    // 0x8001515C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80015160: jal         0x8002E510
    // 0x80015164: addiu       $a0, $a0, -0x6EC0
    ctx->r4 = ADD32(ctx->r4, -0X6EC0);
    osStartThread_recomp(rdram, ctx);
        goto after_12;
    // 0x80015164: addiu       $a0, $a0, -0x6EC0
    ctx->r4 = ADD32(ctx->r4, -0X6EC0);
    after_12:
    // 0x80015168: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001516C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80015170: jr          $ra
    // 0x80015174: nop

    return;
    // 0x80015174: nop

;}
RECOMP_FUNC void _bavan_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085368: syscall     159
    recomp_syscall_handler(rdram, ctx, 0x80085368);
    return;
    // 0x8008536C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_8010AD4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AD4C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010AD50: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8010AD54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010AD58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010AD5C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8010AD60: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8010AD64: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8010AD68: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8010AD6C: jal         0x800EC708
    // 0x8010AD70: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_800EC708(rdram, ctx);
        goto after_0;
    // 0x8010AD70: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8010AD74: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8010AD78: jal         0x8010A40C
    // 0x8010AD7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A40C(rdram, ctx);
        goto after_1;
    // 0x8010AD7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8010AD80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010AD84: lwc1        $f6, 0x6518($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6518);
    // 0x8010AD88: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010AD8C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8010AD90: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010AD94: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8010AD98: addiu       $a2, $a2, 0x6F30
    ctx->r6 = ADD32(ctx->r6, 0X6F30);
    // 0x8010AD9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010ADA0: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010ADA4: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8010ADA8: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8010ADAC: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8010ADB0: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x8010ADB4: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8010ADB8: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8010ADBC: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8010ADC0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8010ADC4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8010ADC8: jal         0x800BF340
    // 0x8010ADCC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800BF340(rdram, ctx);
        goto after_2;
    // 0x8010ADCC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8010ADD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010ADD4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8010ADD8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8010ADDC: jal         0x800EE7F8
    // 0x8010ADE0: addiu       $a0, $a0, 0x6F20
    ctx->r4 = ADD32(ctx->r4, 0X6F20);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x8010ADE0: addiu       $a0, $a0, 0x6F20
    ctx->r4 = ADD32(ctx->r4, 0X6F20);
    after_3:
    // 0x8010ADE4: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010ADE8: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8010ADEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010ADF0: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8010ADF4: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x8010ADF8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8010ADFC: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8010AE00: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x8010AE04: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8010AE08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8010AE0C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8010AE10: beq         $t6, $zero, L_8010AE20
    if (ctx->r14 == 0) {
        // 0x8010AE14: nop
    
            goto L_8010AE20;
    }
    // 0x8010AE14: nop

    // 0x8010AE18: b           L_8010AE20
    // 0x8010AE1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8010AE20;
    // 0x8010AE1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8010AE20:
    // 0x8010AE20: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8010AE24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8010AE28: jr          $ra
    // 0x8010AE2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8010AE2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void chpowerhutwitchy_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1080, 0XC00) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0xC00
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1080, 0XC00));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0xC00
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1080, 0XC00));
;}
RECOMP_FUNC void func_800A3378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3378: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A337C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A3380: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A3384: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x800A3388: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A338C: jr          $ra
    // 0x800A3390: nop

    return;
    // 0x800A3390: nop

;}
RECOMP_FUNC void gsmaker_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080075C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800764: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800768: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080076C: jal         0x8080051C
    // 0x80800770: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    gsmaker_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x80800770: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800774: bne         $v0, $zero, L_80800784
    if (ctx->r2 != 0) {
        // 0x80800778: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800784;
    }
    // 0x80800778: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080077C: b           L_80800794
    // 0x80800780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800794;
    // 0x80800780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800784:
    // 0x80800784: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800788: jal         0x8080038C
    // 0x8080078C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    gsmaker_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x8080078C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800790: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800794:
    // 0x80800794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080079C: jr          $ra
    // 0x808007A0: nop

    return;
    // 0x808007A0: nop

;}
RECOMP_FUNC void func_80800008_ncbaclimb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x80112524
    // 0x80800014: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800014: nop

    after_0:
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800020: jr          $ra
    // 0x80800024: nop

    return;
    // 0x80800024: nop

;}
RECOMP_FUNC void func_800F22EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F22EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F22F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F22F4: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800F22F8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F22FC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F2300: nop

    // 0x800F2304: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F2308: jal         0x8002DCA0
    // 0x800F230C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800F230C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800F2310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F2314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F2318: jr          $ra
    // 0x800F231C: nop

    return;
    // 0x800F231C: nop

;}
RECOMP_FUNC void func_80800318_ncbaspline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800318: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8080031C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800320: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800324: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800328: jal         0x80800008
    // 0x8080032C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    func_80800008_ncbaspline(rdram, ctx);
        goto after_0;
    // 0x8080032C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800330: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: jal         0x80800130
    // 0x8080033C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80800130_ncbaspline(rdram, ctx);
        goto after_1;
    // 0x8080033C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800348: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8080034C: jal         0x8080017C
    // 0x80800350: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    func_8080017C_ncbaspline(rdram, ctx);
        goto after_2;
    // 0x80800350: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    after_2:
    // 0x80800354: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800358: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x8080035C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800360: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x80800364: jal         0x800C7FD4
    // 0x80800368: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    func_800C7FD4(rdram, ctx);
        goto after_3;
    // 0x80800368: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    after_3:
    // 0x8080036C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80800370: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x80800374: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800378: lui         $a2, 0xC47A
    ctx->r6 = S32(0XC47A << 16);
    // 0x8080037C: jal         0x800C7FD4
    // 0x80800380: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    func_800C7FD4(rdram, ctx);
        goto after_4;
    // 0x80800380: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    after_4:
    // 0x80800384: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800388: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080038C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800390: jal         0x800C7A68
    // 0x80800394: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_800C7A68(rdram, ctx);
        goto after_5;
    // 0x80800394: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_5:
    // 0x80800398: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080039C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x808003A0: jal         0x800C7A68
    // 0x808003A4: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_800C7A68(rdram, ctx);
        goto after_6;
    // 0x808003A4: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_6:
    // 0x808003A8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808003AC: jal         0x800EEAD4
    // 0x808003B0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800EEAD4(rdram, ctx);
        goto after_7;
    // 0x808003B0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_7:
    // 0x808003B4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x808003B8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808003BC: jal         0x800EEAD4
    // 0x808003C0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800EEAD4(rdram, ctx);
        goto after_8;
    // 0x808003C0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_8:
    // 0x808003C4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003C8: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808003CC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x808003D0: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    // 0x808003D4: jal         0x800F2100
    // 0x808003D8: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_9;
    // 0x808003D8: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    after_9:
    // 0x808003DC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808003E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003E4: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808003E8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808003EC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808003F0: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808003F4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808003F8: bc1f        L_808005B8
    if (!c1cs) {
        // 0x808003FC: nop
    
            goto L_808005B8;
    }
    // 0x808003FC: nop

    // 0x80800400: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800404: lui         $a2, 0x4422
    ctx->r6 = S32(0X4422 << 16);
    // 0x80800408: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080040C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80800410: bc1f        L_80800428
    if (!c1cs) {
        // 0x80800414: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_80800428;
    }
    // 0x80800414: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800418: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080041C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800420: b           L_80800430
    // 0x80800424: nop

        goto L_80800430;
    // 0x80800424: nop

L_80800428:
    // 0x80800428: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080042C: nop

L_80800430:
    // 0x80800430: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3062, 0XA38) << 16);
    // 0x80800434: lwc1        $f16, 0xA38($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3062, 0XA38));
    // 0x80800438: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8080043C: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x80800440: nop

    // 0x80800444: bc1fl       L_8080047C
    if (!c1cs) {
        // 0x80800448: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8080047C;
    }
    goto skip_0;
    // 0x80800448: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8080044C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3062, 0XA3C) << 16);
    // 0x80800450: lwc1        $f14, 0xA3C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3062, 0XA3C));
    // 0x80800454: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3062, 0XA40) << 16);
    // 0x80800458: lwc1        $f18, 0xA40($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3062, 0XA40));
    // 0x8080045C: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x80800460: jal         0x800F10B4
    // 0x80800464: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x80800464: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x80800468: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080046C: mul.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800470: b           L_808004C0
    // 0x80800474: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
        goto L_808004C0;
    // 0x80800474: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x80800478: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8080047C:
    // 0x8080047C: lui         $a3, 0x44BB
    ctx->r7 = S32(0X44BB << 16);
    // 0x80800480: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80800484: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800488: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080048C: bc1fl       L_808004C0
    if (!c1cs) {
        // 0x80800490: lw          $t8, 0x44($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X44);
            goto L_808004C0;
    }
    goto skip_1;
    // 0x80800490: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    skip_1:
    // 0x80800494: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800498: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080049C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808004A0: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x808004A4: jal         0x800F10B4
    // 0x808004A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x808004A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x808004AC: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808004B0: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x808004B4: mul.s       $f14, $f0, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808004B8: nop

    // 0x808004BC: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
L_808004C0:
    // 0x808004C0: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    // 0x808004C4: jal         0x800F2100
    // 0x808004C8: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    mlAbsF(rdram, ctx);
        goto after_12;
    // 0x808004C8: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    after_12:
    // 0x808004CC: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808004D0: jal         0x800F2100
    // 0x808004D4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    mlAbsF(rdram, ctx);
        goto after_13;
    // 0x808004D4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x808004D8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808004DC: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808004E0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808004E4: nop

    // 0x808004E8: bc1fl       L_80800518
    if (!c1cs) {
        // 0x808004EC: lw          $t9, 0x44($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X44);
            goto L_80800518;
    }
    goto skip_2;
    // 0x808004EC: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    skip_2:
    // 0x808004F0: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x808004F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3062, 0XA44) << 16);
    // 0x808004F8: lwc1        $f16, 0xA44($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3062, 0XA44));
    // 0x808004FC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800500: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80800504: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800508: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8080050C: b           L_8080051C
    // 0x80800510: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
        goto L_8080051C;
    // 0x80800510: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800514: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
L_80800518:
    // 0x80800518: swc1        $f14, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f14.u32l;
L_8080051C:
    // 0x8080051C: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x80800520: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800524: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x80800528: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8080052C: jal         0x800C7FD4
    // 0x80800530: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    func_800C7FD4(rdram, ctx);
        goto after_14;
    // 0x80800530: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    after_14:
    // 0x80800534: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800538: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8080053C: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x80800540: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80800544: swc1        $f0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f0.u32l;
    // 0x80800548: bc1fl       L_80800580
    if (!c1cs) {
        // 0x8080054C: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_80800580;
    }
    goto skip_3;
    // 0x8080054C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_3:
    // 0x80800550: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x80800554: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800558: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080055C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800560: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80800564: nop

    // 0x80800568: bc1fl       L_80800580
    if (!c1cs) {
        // 0x8080056C: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_80800580;
    }
    goto skip_4;
    // 0x8080056C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_4:
    // 0x80800570: lbu         $t1, 0x2F($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2F);
    // 0x80800574: beq         $t1, $zero, L_808005B0
    if (ctx->r9 == 0) {
        // 0x80800578: nop
    
            goto L_808005B0;
    }
    // 0x80800578: nop

    // 0x8080057C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_80800580:
    // 0x80800580: nop

    // 0x80800584: bc1fl       L_808005C4
    if (!c1cs) {
        // 0x80800588: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_808005C4;
    }
    goto skip_5;
    // 0x80800588: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_5:
    // 0x8080058C: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x80800590: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800594: c.eq.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl == ctx->f10.fl;
    // 0x80800598: nop

    // 0x8080059C: bc1fl       L_808005C4
    if (!c1cs) {
        // 0x808005A0: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_808005C4;
    }
    goto skip_6;
    // 0x808005A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_6:
    // 0x808005A4: lbu         $t2, 0x2E($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2E);
    // 0x808005A8: bnel        $t2, $zero, L_808005C4
    if (ctx->r10 != 0) {
        // 0x808005AC: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_808005C4;
    }
    goto skip_7;
    // 0x808005AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_7:
L_808005B0:
    // 0x808005B0: b           L_808005E0
    // 0x808005B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005E0;
    // 0x808005B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005B8:
    // 0x808005B8: b           L_808005E0
    // 0x808005BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005E0;
    // 0x808005BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808005C0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_808005C4:
    // 0x808005C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x808005C8: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x808005CC: nop

    // 0x808005D0: bc1t        L_808005E0
    if (c1cs) {
        // 0x808005D4: nop
    
            goto L_808005E0;
    }
    // 0x808005D4: nop

    // 0x808005D8: b           L_808005E0
    // 0x808005DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005E0;
    // 0x808005DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005E0:
    // 0x808005E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005E8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x808005EC: jr          $ra
    // 0x808005F0: nop

    return;
    // 0x808005F0: nop

;}
RECOMP_FUNC void func_80012EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012EDC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80012EE0: jr          $ra
    // 0x80012EE4: addiu       $v0, $v0, 0x6A78
    ctx->r2 = ADD32(ctx->r2, 0X6A78);
    return;
    // 0x80012EE4: addiu       $v0, $v0, 0x6A78
    ctx->r2 = ADD32(ctx->r2, 0X6A78);
;}
RECOMP_FUNC void bsbtrot_entrypoint_46(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802818: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080281C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802820: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802824: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802828: jal         0x8008CABC
    // 0x8080282C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080282C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80802830: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80802834: jal         0x808004B4
    // 0x80802838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80802838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080283C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802840: jal         0x80095738
    // 0x80802844: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x80802844: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_2:
    // 0x80802848: beq         $v0, $zero, L_80802860
    if (ctx->r2 == 0) {
        // 0x8080284C: nop
    
            goto L_80802860;
    }
    // 0x8080284C: nop

    // 0x80802850: jal         0x8009B7C0
    // 0x80802854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_3;
    // 0x80802854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80802858: b           L_8080286C
    // 0x8080285C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080286C;
    // 0x8080285C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802860:
    // 0x80802860: jal         0x80800438
    // 0x80802864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800438_bsbtrot(rdram, ctx);
        goto after_4;
    // 0x80802864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80802868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080286C:
    // 0x8080286C: jal         0x8009BB24
    // 0x80802870: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_5;
    // 0x80802870: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x80802874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802878: jal         0x80091A30
    // 0x8080287C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_6;
    // 0x8080287C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x80802880: beq         $v0, $zero, L_808028A8
    if (ctx->r2 == 0) {
        // 0x80802884: lwc1        $f6, 0x28($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
            goto L_808028A8;
    }
    // 0x80802884: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80802888: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080288C: nop

    // 0x80802890: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80802894: nop

    // 0x80802898: bc1fl       L_808028AC
    if (!c1cs) {
        // 0x8080289C: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_808028AC;
    }
    goto skip_0;
    // 0x8080289C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_0:
    // 0x808028A0: jal         0x8009BC6C
    // 0x808028A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_7;
    // 0x808028A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_808028A8:
    // 0x808028A8: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
L_808028AC:
    // 0x808028AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808028B0: beq         $v0, $at, L_808028E0
    if (ctx->r2 == ctx->r1) {
        // 0x808028B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808028E0;
    }
    // 0x808028B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808028B8: beq         $v0, $at, L_80802900
    if (ctx->r2 == ctx->r1) {
        // 0x808028BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802900;
    }
    // 0x808028BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808028C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808028C4: beq         $v0, $at, L_80802920
    if (ctx->r2 == ctx->r1) {
        // 0x808028C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802920;
    }
    // 0x808028C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808028CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808028D0: beq         $v0, $at, L_80802948
    if (ctx->r2 == ctx->r1) {
        // 0x808028D4: nop
    
            goto L_80802948;
    }
    // 0x808028D4: nop

    // 0x808028D8: b           L_8080296C
    // 0x808028DC: nop

        goto L_8080296C;
    // 0x808028DC: nop

L_808028E0:
    // 0x808028E0: jal         0x8008B324
    // 0x808028E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_8;
    // 0x808028E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x808028E8: beq         $v0, $zero, L_8080296C
    if (ctx->r2 == 0) {
        // 0x808028EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080296C;
    }
    // 0x808028EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808028F0: jal         0x808025D8
    // 0x808028F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808025D8_bsbtrot(rdram, ctx);
        goto after_9;
    // 0x808028F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x808028F8: b           L_8080296C
    // 0x808028FC: nop

        goto L_8080296C;
    // 0x808028FC: nop

L_80802900:
    // 0x80802900: jal         0x8008DF8C
    // 0x80802904: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_10;
    // 0x80802904: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_10:
    // 0x80802908: beq         $v0, $zero, L_8080296C
    if (ctx->r2 == 0) {
        // 0x8080290C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080296C;
    }
    // 0x8080290C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802910: jal         0x808025D8
    // 0x80802914: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808025D8_bsbtrot(rdram, ctx);
        goto after_11;
    // 0x80802914: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x80802918: b           L_8080296C
    // 0x8080291C: nop

        goto L_8080296C;
    // 0x8080291C: nop

L_80802920:
    // 0x80802920: jal         0x8009D3A8
    // 0x80802924: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_12;
    // 0x80802924: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80802928: jal         0x8008E078
    // 0x8080292C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_13;
    // 0x8080292C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80802930: beq         $v0, $zero, L_8080296C
    if (ctx->r2 == 0) {
        // 0x80802934: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080296C;
    }
    // 0x80802934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802938: jal         0x808025D8
    // 0x8080293C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808025D8_bsbtrot(rdram, ctx);
        goto after_14;
    // 0x8080293C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x80802940: b           L_8080296C
    // 0x80802944: nop

        goto L_8080296C;
    // 0x80802944: nop

L_80802948:
    // 0x80802948: jal         0x8008B324
    // 0x8080294C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_15;
    // 0x8080294C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_15:
    // 0x80802950: beq         $v0, $zero, L_80802960
    if (ctx->r2 == 0) {
        // 0x80802954: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802960;
    }
    // 0x80802954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802958: addiu       $t6, $zero, 0x15
    ctx->r14 = ADD32(0, 0X15);
    // 0x8080295C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80802960:
    // 0x80802960: jal         0x808007E0
    // 0x80802964: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_808007E0_bsbtrot(rdram, ctx);
        goto after_16;
    // 0x80802964: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_16:
    // 0x80802968: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_8080296C:
    // 0x8080296C: jal         0x8008E078
    // 0x80802970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_17;
    // 0x80802970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80802974: bnel        $v0, $zero, L_808029A8
    if (ctx->r2 != 0) {
        // 0x80802978: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808029A8;
    }
    goto skip_1;
    // 0x80802978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080297C: jal         0x8008E260
    // 0x80802980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_18;
    // 0x80802980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80802984: beq         $v0, $zero, L_80802990
    if (ctx->r2 == 0) {
        // 0x80802988: addiu       $t7, $zero, 0x3D
        ctx->r15 = ADD32(0, 0X3D);
            goto L_80802990;
    }
    // 0x80802988: addiu       $t7, $zero, 0x3D
    ctx->r15 = ADD32(0, 0X3D);
    // 0x8080298C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80802990:
    // 0x80802990: jal         0x8008E35C
    // 0x80802994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_19;
    // 0x80802994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80802998: beq         $v0, $zero, L_808029A4
    if (ctx->r2 == 0) {
        // 0x8080299C: addiu       $t8, $zero, 0x4C
        ctx->r24 = ADD32(0, 0X4C);
            goto L_808029A4;
    }
    // 0x8080299C: addiu       $t8, $zero, 0x4C
    ctx->r24 = ADD32(0, 0X4C);
    // 0x808029A0: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_808029A4:
    // 0x808029A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808029A8:
    // 0x808029A8: jal         0x8009E5C8
    // 0x808029AC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_20;
    // 0x808029AC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_20:
    // 0x808029B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808029B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808029B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808029BC: jr          $ra
    // 0x808029C0: nop

    return;
    // 0x808029C0: nop

;}
RECOMP_FUNC void func_8080219C_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080219C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808021A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808021A4: lbu         $a1, 0x28($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X28);
    // 0x808021A8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808021AC: beq         $a1, $zero, L_808021C4
    if (ctx->r5 == 0) {
        // 0x808021B0: andi        $a0, $a1, 0xFF
        ctx->r4 = ctx->r5 & 0XFF;
            goto L_808021C4;
    }
    // 0x808021B0: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x808021B4: jal         0x800E8C08
    // 0x808021B8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800E8C08(rdram, ctx);
        goto after_0;
    // 0x808021B8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808021BC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808021C0: sb          $zero, 0x28($a2)
    MEM_B(0X28, ctx->r6) = 0;
L_808021C4:
    // 0x808021C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808021C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808021CC: jr          $ra
    // 0x808021D0: nop

    return;
    // 0x808021D0: nop

;}
RECOMP_FUNC void gcgoto_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808005D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808005D8: jal         0x80015FA0
    // 0x808005DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80015FA0(rdram, ctx);
        goto after_0;
    // 0x808005DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808005E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005E4: bne         $v0, $at, L_80800614
    if (ctx->r2 != ctx->r1) {
        // 0x808005E8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800614;
    }
    // 0x808005E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808005EC: jal         0x800A7AD4
    // 0x808005F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A7AD4(rdram, ctx);
        goto after_1;
    // 0x808005F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808005F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005F8: jal         0x800FC1CC
    // 0x808005FC: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    func_800FC1CC(rdram, ctx);
        goto after_2;
    // 0x808005FC: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    after_2:
    // 0x80800600: jal         0x800FE3EC
    // 0x80800604: nop

    func_800FE3EC(rdram, ctx);
        goto after_3;
    // 0x80800604: nop

    after_3:
    // 0x80800608: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080060C: jal         0x808005BC
    // 0x80800610: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    gcgoto_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800610: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_4:
L_80800614:
    // 0x80800614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080061C: jr          $ra
    // 0x80800620: nop

    return;
    // 0x80800620: nop

;}
RECOMP_FUNC void _bstrexlarge_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084020: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084020);
    return;
    // 0x80084024: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8080000C_chspotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800020: jal         0x80100094
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800028: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080002C: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x80800030: jal         0x800EE7F8
    // 0x80800034: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800034: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800038: jal         0x800DA298
    // 0x8080003C: addiu       $a0, $zero, 0x9C
    ctx->r4 = ADD32(0, 0X9C);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080003C: addiu       $a0, $zero, 0x9C
    ctx->r4 = ADD32(0, 0X9C);
    after_2:
    // 0x80800040: bnel        $v0, $zero, L_80800058
    if (ctx->r2 != 0) {
        // 0x80800044: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800058;
    }
    goto skip_0;
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800048: jal         0x808008EC
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008EC_chspotlight(rdram, ctx);
        goto after_3;
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800050: bne         $v0, $zero, L_80800068
    if (ctx->r2 != 0) {
        // 0x80800054: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800068;
    }
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800058:
    // 0x80800058: jal         0x80101FDC
    // 0x8080005C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x8080005C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x80800060: b           L_808000AC
    // 0x80800064: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
        goto L_808000AC;
    // 0x80800064: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
L_80800068:
    // 0x80800068: jal         0x808008A4
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008A4_chspotlight(rdram, ctx);
        goto after_5;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800070: beql        $v0, $zero, L_808000AC
    if (ctx->r2 == 0) {
        // 0x80800074: lhu         $t6, 0x76($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X76);
            goto L_808000AC;
    }
    goto skip_1;
    // 0x80800074: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    skip_1:
    // 0x80800078: jal         0x80106790
    // 0x8080007C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x8080007C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_6:
    // 0x80800080: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800084: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x80800088: jal         0x800EE7F8
    // 0x8080008C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8080008C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_7:
    // 0x80800090: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x80102D78
    // 0x8080009C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80102D78(rdram, ctx);
        goto after_8;
    // 0x8080009C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_8:
    // 0x808000A0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808000A4: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x808000A8: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
L_808000AC:
    // 0x808000AC: addiu       $t8, $s1, 0x10
    ctx->r24 = ADD32(ctx->r17, 0X10);
    // 0x808000B0: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808000B4: slti        $at, $t7, 0x34
    ctx->r1 = SIGNED(ctx->r15) < 0X34 ? 1 : 0;
    // 0x808000B8: beql        $at, $zero, L_80800124
    if (ctx->r1 == 0) {
        // 0x808000BC: sw          $zero, 0x0($s1)
        MEM_W(0X0, ctx->r17) = 0;
            goto L_80800124;
    }
    goto skip_2;
    // 0x808000BC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    skip_2:
    // 0x808000C0: jal         0x800C8A98
    // 0x808000C4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    func_800C8A98(rdram, ctx);
        goto after_9;
    // 0x808000C4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_9:
    // 0x808000C8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x808000CC: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808000D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808000D4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1004, 0X990) << 16);
    // 0x808000D8: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x808000DC: addiu       $a1, $a1, 0x990
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1004, 0X990));
    // 0x808000E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000E4: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x808000E8: jal         0x800C8D4C
    // 0x808000EC: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    func_800C8D4C(rdram, ctx);
        goto after_10;
    // 0x808000EC: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    after_10:
    // 0x808000F0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1004, 0X998) << 16);
    // 0x808000F4: addiu       $a1, $a1, 0x998
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1004, 0X998));
    // 0x808000F8: jal         0x800C8E84
    // 0x808000FC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800C8E84(rdram, ctx);
        goto after_11;
    // 0x808000FC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_11:
    // 0x80800100: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800104: jal         0x800C8CB8
    // 0x80800108: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800C8CB8(rdram, ctx);
        goto after_12;
    // 0x80800108: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x8080010C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800110: jal         0x800C8FE0
    // 0x80800114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_13;
    // 0x80800114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800118: b           L_80800128
    // 0x8080011C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
        goto L_80800128;
    // 0x8080011C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800120: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_80800124:
    // 0x80800124: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_80800128:
    // 0x80800128: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080012C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800130: jal         0x800DC178
    // 0x80800134: nop

    func_800DC178(rdram, ctx);
        goto after_14;
    // 0x80800134: nop

    after_14:
    // 0x80800138: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080013C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800140: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800144: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800148: jal         0x800DC178
    // 0x8080014C: swc1        $f0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_15;
    // 0x8080014C: swc1        $f0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f0.u32l;
    after_15:
    // 0x80800150: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800154: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800158: jal         0x800DC298
    // 0x8080015C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_800DC298(rdram, ctx);
        goto after_16;
    // 0x8080015C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x80800160: beq         $v0, $zero, L_80800178
    if (ctx->r2 == 0) {
        // 0x80800164: lwc1        $f8, 0x28($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800178;
    }
    // 0x80800164: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800168: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080016C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800170: b           L_80800184
    // 0x80800174: nop

        goto L_80800184;
    // 0x80800174: nop

L_80800178:
    // 0x80800178: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080017C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800180: nop

L_80800184:
    // 0x80800184: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800188: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8080018C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800190: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800194: jal         0x800DC178
    // 0x80800198: swc1        $f10, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f10.u32l;
    func_800DC178(rdram, ctx);
        goto after_17;
    // 0x80800198: swc1        $f10, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f10.u32l;
    after_17:
    // 0x8080019C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808001A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001A4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808001A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001AC: jal         0x800DC178
    // 0x808001B0: swc1        $f0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_18;
    // 0x808001B0: swc1        $f0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f0.u32l;
    after_18:
    // 0x808001B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808001B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001BC: jal         0x800DC298
    // 0x808001C0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_800DC298(rdram, ctx);
        goto after_19;
    // 0x808001C0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_19:
    // 0x808001C4: beq         $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001C8: lwc1        $f16, 0x28($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
            goto L_808001DC;
    }
    // 0x808001C8: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808001CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808001D4: b           L_808001E8
    // 0x808001D8: nop

        goto L_808001E8;
    // 0x808001D8: nop

L_808001DC:
    // 0x808001DC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808001E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808001E4: nop

L_808001E8:
    // 0x808001E8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808001EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1004, 0X970) << 16);
    // 0x808001F0: swc1        $f18, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f18.u32l;
    // 0x808001F4: lwc1        $f4, 0x970($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1004, 0X970));
    // 0x808001F8: swc1        $f4, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f4.u32l;
    // 0x808001FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800200: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800204: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800208: jr          $ra
    // 0x8080020C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080020C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800B7B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7B44: beq         $a0, $zero, L_800B7B5C
    if (ctx->r4 == 0) {
        // 0x800B7B48: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800B7B5C;
    }
    // 0x800B7B48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7B4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B7B50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7B54: jr          $ra
    // 0x800B7B58: sb          $t6, -0x7E6D($at)
    MEM_B(-0X7E6D, ctx->r1) = ctx->r14;
    return;
    // 0x800B7B58: sb          $t6, -0x7E6D($at)
    MEM_B(-0X7E6D, ctx->r1) = ctx->r14;
L_800B7B5C:
    // 0x800B7B5C: sb          $zero, -0x7E6D($at)
    MEM_B(-0X7E6D, ctx->r1) = 0;
    // 0x800B7B60: jr          $ra
    // 0x800B7B64: nop

    return;
    // 0x800B7B64: nop

;}
RECOMP_FUNC void _sulights_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8E0: syscall     854
    recomp_syscall_handler(rdram, ctx, 0x8008A8E0);
    return;
    // 0x8008A8E4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800244_chhoney(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800244: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800248: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080024C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800250: jal         0x8001211C
    // 0x80800254: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x80800254: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800258: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x8080025C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800260: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800264: sll         $t6, $a1, 26
    ctx->r14 = S32(ctx->r5 << 26);
    // 0x80800268: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8080026C: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x80800270: sltiu       $a1, $t7, 0x1
    ctx->r5 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: jal         0x8008A4B0
    // 0x8080027C: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080027C: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80800280: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800284: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800288: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8080028C: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x80800290: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x80800294: lw          $a1, 0x24($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X24);
    // 0x80800298: srl         $t0, $a1, 22
    ctx->r8 = S32(U32(ctx->r5) >> 22);
    // 0x8080029C: beq         $t0, $at, L_808002BC
    if (ctx->r8 == ctx->r1) {
        // 0x808002A0: addiu       $at, $zero, 0x22B
        ctx->r1 = ADD32(0, 0X22B);
            goto L_808002BC;
    }
    // 0x808002A0: addiu       $at, $zero, 0x22B
    ctx->r1 = ADD32(0, 0X22B);
    // 0x808002A4: beq         $t0, $at, L_808002E8
    if (ctx->r8 == ctx->r1) {
        // 0x808002A8: addiu       $at, $zero, 0x22C
        ctx->r1 = ADD32(0, 0X22C);
            goto L_808002E8;
    }
    // 0x808002A8: addiu       $at, $zero, 0x22C
    ctx->r1 = ADD32(0, 0X22C);
    // 0x808002AC: beql        $t0, $at, L_808002D0
    if (ctx->r8 == ctx->r1) {
        // 0x808002B0: lbu         $t3, 0x79($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X79);
            goto L_808002D0;
    }
    goto skip_0;
    // 0x808002B0: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    skip_0:
    // 0x808002B4: b           L_80800300
    // 0x808002B8: nop

        goto L_80800300;
    // 0x808002B8: nop

L_808002BC:
    // 0x808002BC: lbu         $t1, 0x79($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X79);
    // 0x808002C0: andi        $t2, $t1, 0xFF0F
    ctx->r10 = ctx->r9 & 0XFF0F;
    // 0x808002C4: b           L_80800300
    // 0x808002C8: sb          $t2, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r10;
        goto L_80800300;
    // 0x808002C8: sb          $t2, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r10;
    // 0x808002CC: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
L_808002D0:
    // 0x808002D0: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x808002D4: ori         $t5, $t4, 0x20
    ctx->r13 = ctx->r12 | 0X20;
    // 0x808002D8: jal         0x80800000
    // 0x808002DC: sb          $t5, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r13;
    func_80800000_chhoney(rdram, ctx);
        goto after_2;
    // 0x808002DC: sb          $t5, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r13;
    after_2:
    // 0x808002E0: b           L_80800300
    // 0x808002E4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
        goto L_80800300;
    // 0x808002E4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
L_808002E8:
    // 0x808002E8: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    // 0x808002EC: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x808002F0: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808002F4: jal         0x80800000
    // 0x808002F8: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
    func_80800000_chhoney(rdram, ctx);
        goto after_3;
    // 0x808002F8: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
    after_3:
    // 0x808002FC: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
L_80800300:
    // 0x80800300: jal         0x800DA298
    // 0x80800304: addiu       $a0, $zero, 0x64C
    ctx->r4 = ADD32(0, 0X64C);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800304: addiu       $a0, $zero, 0x64C
    ctx->r4 = ADD32(0, 0X64C);
    after_4:
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: jal         0x8010A5B0
    // 0x80800310: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010A5B0(rdram, ctx);
        goto after_5;
    // 0x80800310: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80800314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800318: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080031C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800320: jr          $ra
    // 0x80800324: nop

    return;
    // 0x80800324: nop

;}
RECOMP_FUNC void func_80800450_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800450: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800454: slti        $at, $a1, 0x58
    ctx->r1 = SIGNED(ctx->r5) < 0X58 ? 1 : 0;
    // 0x80800458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080045C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800460: bne         $at, $zero, L_8080047C
    if (ctx->r1 != 0) {
        // 0x80800464: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_8080047C;
    }
    // 0x80800464: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800468: addiu       $at, $zero, 0xA1
    ctx->r1 = ADD32(0, 0XA1);
    // 0x8080046C: beq         $a1, $at, L_808004B0
    if (ctx->r5 == ctx->r1) {
        // 0x80800470: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_808004B0;
    }
    // 0x80800470: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800474: b           L_8080070C
    // 0x80800478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080070C;
    // 0x80800478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080047C:
    // 0x8080047C: addiu       $t6, $a1, -0x1F
    ctx->r14 = ADD32(ctx->r5, -0X1F);
    // 0x80800480: sltiu       $at, $t6, 0x39
    ctx->r1 = ctx->r14 < 0X39 ? 1 : 0;
    // 0x80800484: beq         $at, $zero, L_80800700
    if (ctx->r1 == 0) {
        // 0x80800488: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800700;
    }
    // 0x80800488: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080048C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X2290) << 16);
    // 0x80800490: addu        $at, $at, $t6
    gpr jr_addend_80800498 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800494: lw          $t6, 0x2290($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1688, 0X2290));
    // 0x80800498: jr          $t6
    // 0x8080049C: nop

    switch (jr_addend_80800498 >> 2) {
        case 0: goto L_808006B4; break;
        case 1: goto L_80800700; break;
        case 2: goto L_80800700; break;
        case 3: goto L_80800700; break;
        case 4: goto L_80800700; break;
        case 5: goto L_80800700; break;
        case 6: goto L_80800700; break;
        case 7: goto L_80800700; break;
        case 8: goto L_80800700; break;
        case 9: goto L_80800700; break;
        case 10: goto L_80800700; break;
        case 11: goto L_80800700; break;
        case 12: goto L_80800700; break;
        case 13: goto L_80800700; break;
        case 14: goto L_80800700; break;
        case 15: goto L_8080055C; break;
        case 16: goto L_80800578; break;
        case 17: goto L_80800700; break;
        case 18: goto L_80800700; break;
        case 19: goto L_80800618; break;
        case 20: goto L_80800700; break;
        case 21: goto L_80800700; break;
        case 22: goto L_80800700; break;
        case 23: goto L_80800700; break;
        case 24: goto L_80800700; break;
        case 25: goto L_80800700; break;
        case 26: goto L_80800700; break;
        case 27: goto L_80800700; break;
        case 28: goto L_80800700; break;
        case 29: goto L_80800700; break;
        case 30: goto L_808004F8; break;
        case 31: goto L_80800700; break;
        case 32: goto L_80800700; break;
        case 33: goto L_80800700; break;
        case 34: goto L_80800700; break;
        case 35: goto L_80800700; break;
        case 36: goto L_80800700; break;
        case 37: goto L_80800700; break;
        case 38: goto L_80800700; break;
        case 39: goto L_80800700; break;
        case 40: goto L_80800700; break;
        case 41: goto L_80800700; break;
        case 42: goto L_808004A0; break;
        case 43: goto L_80800700; break;
        case 44: goto L_80800700; break;
        case 45: goto L_80800700; break;
        case 46: goto L_80800700; break;
        case 47: goto L_80800700; break;
        case 48: goto L_80800700; break;
        case 49: goto L_80800700; break;
        case 50: goto L_80800700; break;
        case 51: goto L_808005A4; break;
        case 52: goto L_80800700; break;
        case 53: goto L_80800700; break;
        case 54: goto L_80800700; break;
        case 55: goto L_80800700; break;
        case 56: goto L_808005C0; break;
        default: switch_error(__func__, 0x80800498, 0x80802290);
    }
    // 0x8080049C: nop

L_808004A0:
    // 0x808004A0: jal         0x80801F74
    // 0x808004A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80801F74_chhumba(rdram, ctx);
        goto after_0;
    // 0x808004A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x808004A8: b           L_8080070C
    // 0x808004AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x808004AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004B0:
    // 0x808004B0: lhu         $v0, 0x72($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X72);
    // 0x808004B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808004B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808004BC: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x808004C0: beq         $t8, $at, L_808004D8
    if (ctx->r24 == ctx->r1) {
        // 0x808004C4: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_808004D8;
    }
    // 0x808004C4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x808004C8: beq         $t8, $at, L_808004E8
    if (ctx->r24 == ctx->r1) {
        // 0x808004CC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808004E8;
    }
    // 0x808004CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808004D0: b           L_8080070C
    // 0x808004D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x808004D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004D8:
    // 0x808004D8: jal         0x80800E44
    // 0x808004DC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800E44_chhumba(rdram, ctx);
        goto after_1;
    // 0x808004DC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_1:
    // 0x808004E0: b           L_8080070C
    // 0x808004E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x808004E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004E8:
    // 0x808004E8: jal         0x80800E44
    // 0x808004EC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80800E44_chhumba(rdram, ctx);
        goto after_2;
    // 0x808004EC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x808004F0: b           L_8080070C
    // 0x808004F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x808004F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004F8:
    // 0x808004F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808004FC: jal         0x80800238
    // 0x80800500: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_80800238_chhumba(rdram, ctx);
        goto after_3;
    // 0x80800500: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x80800504: addiu       $a0, $zero, 0x29F
    ctx->r4 = ADD32(0, 0X29F);
    // 0x80800508: jal         0x801084B0
    // 0x8080050C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_801084B0(rdram, ctx);
        goto after_4;
    // 0x8080050C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x80800510: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x80800514: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800518: jal         0x800EE7F8
    // 0x8080051C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x8080051C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_5:
    // 0x80800520: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800524: jal         0x8010D254
    // 0x80800528: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    func_8010D254(rdram, ctx);
        goto after_6;
    // 0x80800528: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    after_6:
    // 0x8080052C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800530: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800534: lbu         $t0, 0x74($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X74);
    // 0x80800538: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8080053C: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x80800540: sb          $t1, 0x74($v1)
    MEM_B(0X74, ctx->r3) = ctx->r9;
    // 0x80800544: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80800548: sw          $t2, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->r10;
    // 0x8080054C: jal         0x80800E44
    // 0x80800550: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80800E44_chhumba(rdram, ctx);
        goto after_7;
    // 0x80800550: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x80800554: b           L_8080070C
    // 0x80800558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x80800558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080055C:
    // 0x8080055C: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x80800560: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800564: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800568: jal         0x80801DB0
    // 0x8080056C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80801DB0_chhumba(rdram, ctx);
        goto after_8;
    // 0x8080056C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x80800570: b           L_8080070C
    // 0x80800574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x80800574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800578:
    // 0x80800578: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x8080057C: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x80800580: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800584: bnel        $t4, $at, L_8080070C
    if (ctx->r12 != ctx->r1) {
        // 0x80800588: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080070C;
    }
    goto skip_0;
    // 0x80800588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080058C: jal         0x80090708
    // 0x80800590: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_9;
    // 0x80800590: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80800594: jal         0x80090708
    // 0x80800598: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090708(rdram, ctx);
        goto after_10;
    // 0x80800598: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x8080059C: b           L_8080070C
    // 0x808005A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x808005A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005A4:
    // 0x808005A4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x808005A8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1688, 0X2684) << 16);
    // 0x808005AC: addiu       $a0, $a0, 0x2684
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1688, 0X2684));
    // 0x808005B0: jal         0x80088090
    // 0x808005B4: lw          $a1, 0x38($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x808005B4: lw          $a1, 0x38($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X38);
    after_11:
    // 0x808005B8: b           L_8080070C
    // 0x808005BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x808005BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005C0:
    // 0x808005C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808005C4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808005C8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808005CC: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x808005D0: and         $t7, $a1, $at
    ctx->r15 = ctx->r5 & ctx->r1;
    // 0x808005D4: srl         $a1, $t7, 16
    ctx->r5 = S32(U32(ctx->r15) >> 16);
    // 0x808005D8: jal         0x80088078
    // 0x808005DC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x808005DC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_12:
    // 0x808005E0: beq         $v0, $zero, L_80800610
    if (ctx->r2 == 0) {
        // 0x808005E4: lw          $t9, 0x30($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X30);
            goto L_80800610;
    }
    // 0x808005E4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x808005E8: lhu         $t0, 0x76($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X76);
    // 0x808005EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005F0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x808005F4: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x808005F8: beq         $t1, $at, L_80800608
    if (ctx->r9 == ctx->r1) {
        // 0x808005FC: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800608;
    }
    // 0x808005FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800600: jal         0x80800028
    // 0x80800604: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800028_chhumba(rdram, ctx);
        goto after_13;
    // 0x80800604: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
L_80800608:
    // 0x80800608: b           L_8080070C
    // 0x8080060C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8080070C;
    // 0x8080060C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800610:
    // 0x80800610: b           L_8080070C
    // 0x80800614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x80800614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800618:
    // 0x80800618: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8080061C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80800620: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800624: lhu         $v0, 0x72($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X72);
    // 0x80800628: addiu       $a1, $zero, 0x11AF
    ctx->r5 = ADD32(0, 0X11AF);
    // 0x8080062C: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x80800630: beq         $t3, $at, L_80800648
    if (ctx->r11 == ctx->r1) {
        // 0x80800634: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_80800648;
    }
    // 0x80800634: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80800638: beq         $t3, $at, L_80800658
    if (ctx->r11 == ctx->r1) {
        // 0x8080063C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800658;
    }
    // 0x8080063C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800640: b           L_80800668
    // 0x80800644: nop

        goto L_80800668;
    // 0x80800644: nop

L_80800648:
    // 0x80800648: jal         0x80800338
    // 0x8080064C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800338_chhumba(rdram, ctx);
        goto after_14;
    // 0x8080064C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_14:
    // 0x80800650: b           L_8080070C
    // 0x80800654: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x80800654: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800658:
    // 0x80800658: jal         0x80800E44
    // 0x8080065C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80800E44_chhumba(rdram, ctx);
        goto after_15;
    // 0x8080065C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_15:
    // 0x80800660: b           L_8080070C
    // 0x80800664: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x80800664: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800668:
    // 0x80800668: jal         0x800904C8
    // 0x8080066C: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800904C8(rdram, ctx);
        goto after_16;
    // 0x8080066C: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_16:
    // 0x80800670: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80800674: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800678: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080067C: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x80800680: addiu       $a1, $zero, 0x11A4
    ctx->r5 = ADD32(0, 0X11A4);
    // 0x80800684: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80800688: bgez        $t7, L_808006A4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8080068C: nop
    
            goto L_808006A4;
    }
    // 0x8080068C: nop

    // 0x80800690: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80800694: jal         0x80800338
    // 0x80800698: addiu       $a1, $zero, 0x11BD
    ctx->r5 = ADD32(0, 0X11BD);
    func_80800338_chhumba(rdram, ctx);
        goto after_17;
    // 0x80800698: addiu       $a1, $zero, 0x11BD
    ctx->r5 = ADD32(0, 0X11BD);
    after_17:
    // 0x8080069C: b           L_8080070C
    // 0x808006A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x808006A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006A4:
    // 0x808006A4: jal         0x80800338
    // 0x808006A8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800338_chhumba(rdram, ctx);
        goto after_18;
    // 0x808006A8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_18:
    // 0x808006AC: b           L_8080070C
    // 0x808006B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x808006B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006B4:
    // 0x808006B4: jal         0x801015D0
    // 0x808006B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_801015D0(rdram, ctx);
        goto after_19;
    // 0x808006B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_19:
    // 0x808006BC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x808006C0: jal         0x801039E4
    // 0x808006C4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_801039E4(rdram, ctx);
        goto after_20;
    // 0x808006C4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_20:
    // 0x808006C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808006CC: jal         0x80103CB8
    // 0x808006D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80103CB8(rdram, ctx);
        goto after_21;
    // 0x808006D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_21:
    // 0x808006D4: lbu         $t1, 0x17($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X17);
    // 0x808006D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808006DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006E0: ori         $t9, $t1, 0x1
    ctx->r25 = ctx->r9 | 0X1;
    // 0x808006E4: jal         0x800DF744
    // 0x808006E8: sb          $t9, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r25;
    func_800DF744(rdram, ctx);
        goto after_22;
    // 0x808006E8: sb          $t9, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r25;
    after_22:
    // 0x808006EC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808006F0: jal         0x800DF744
    // 0x808006F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_23;
    // 0x808006F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x808006F8: b           L_8080070C
    // 0x808006FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080070C;
    // 0x808006FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800700:
    // 0x80800700: b           L_8080070C
    // 0x80800704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080070C;
    // 0x80800704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080070C:
    // 0x8080070C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800710: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800714: jr          $ra
    // 0x80800718: nop

    return;
    // 0x80800718: nop

;}
RECOMP_FUNC void func_80800000_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800010: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800014: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800018: ori         $t7, $a2, 0xE
    ctx->r15 = ctx->r6 | 0XE;
    // 0x8080001C: addiu       $t8, $zero, 0x33
    ctx->r24 = ADD32(0, 0X33);
    // 0x80800020: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800024: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80800028: jal         0x8008A208
    // 0x8080002C: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x8080002C: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x80800030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800034: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void _dbid_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800879C0: syscall     646
    recomp_syscall_handler(rdram, ctx, 0x800879C0);
    return;
    // 0x800879C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085650: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085650);
    return;
    // 0x80085654: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void _subaddiestore_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F08: syscall     815
    recomp_syscall_handler(rdram, ctx, 0x80089F08);
    return;
    // 0x80089F0C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800B7F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7F14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7F18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7F1C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7F20: lui         $t8, 0x12
    ctx->r24 = S32(0X12 << 16);
    // 0x800B7F24: addiu       $t8, $t8, -0x59D0
    ctx->r24 = ADD32(ctx->r24, -0X59D0);
    // 0x800B7F28: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B7F2C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B7F30: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800B7F34: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B7F38: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B7F3C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7F40: lui         $t1, 0xE300
    ctx->r9 = S32(0XE300 << 16);
    // 0x800B7F44: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800B7F48: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800B7F4C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B7F50: ori         $t1, $t1, 0x1201
    ctx->r9 = ctx->r9 | 0X1201;
    // 0x800B7F54: addiu       $t0, $t0, -0x7D40
    ctx->r8 = ADD32(ctx->r8, -0X7D40);
    // 0x800B7F58: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800B7F5C: lbu         $t2, 0x6($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X6);
    // 0x800B7F60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B7F64: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x800B7F68: bne         $t2, $at, L_800B7F78
    if (ctx->r10 != ctx->r1) {
        // 0x800B7F6C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800B7F78;
    }
    // 0x800B7F6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800B7F70: b           L_800B7F7C
    // 0x800B7F74: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
        goto L_800B7F7C;
    // 0x800B7F74: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
L_800B7F78:
    // 0x800B7F78: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_800B7F7C:
    // 0x800B7F7C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7F80: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800B7F84: lui         $t9, 0xFF2F
    ctx->r25 = S32(0XFF2F << 16);
    // 0x800B7F88: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B7F8C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B7F90: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B7F94: lbu         $t1, 0x1($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1);
    // 0x800B7F98: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x800B7F9C: lbu         $t5, 0x2($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X2);
    // 0x800B7FA0: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x800B7FA4: lbu         $t1, 0x3($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X3);
    // 0x800B7FA8: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800B7FAC: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x800B7FB0: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B7FB4: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x800B7FB8: or          $t8, $t7, $t1
    ctx->r24 = ctx->r15 | ctx->r9;
    // 0x800B7FBC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B7FC0: lbu         $t2, 0x9($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X9);
    // 0x800B7FC4: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x800B7FC8: ori         $t5, $t5, 0xA01
    ctx->r13 = ctx->r13 | 0XA01;
    // 0x800B7FCC: beq         $t2, $zero, L_800B8054
    if (ctx->r10 == 0) {
        // 0x800B7FD0: lui         $t6, 0xFC11
        ctx->r14 = S32(0XFC11 << 16);
            goto L_800B8054;
    }
    // 0x800B7FD0: lui         $t6, 0xFC11
    ctx->r14 = S32(0XFC11 << 16);
    // 0x800B7FD4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7FD8: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x800B7FDC: ori         $t5, $t5, 0xA01
    ctx->r13 = ctx->r13 | 0XA01;
    // 0x800B7FE0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B7FE4: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B7FE8: lui         $t3, 0x10
    ctx->r11 = S32(0X10 << 16);
    // 0x800B7FEC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800B7FF0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B7FF4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7FF8: lui         $t9, 0xFC11
    ctx->r25 = S32(0XFC11 << 16);
    // 0x800B7FFC: lui         $t7, 0xFF0F
    ctx->r15 = S32(0XFF0F << 16);
    // 0x800B8000: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800B8004: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B8008: ori         $t7, $t7, 0xF3FF
    ctx->r15 = ctx->r15 | 0XF3FF;
    // 0x800B800C: ori         $t9, $t9, 0x7E03
    ctx->r25 = ctx->r25 | 0X7E03;
    // 0x800B8010: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B8014: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800B8018: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B801C: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x800B8020: lui         $t2, 0xC18
    ctx->r10 = S32(0XC18 << 16);
    // 0x800B8024: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800B8028: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800B802C: ori         $t2, $t2, 0x4A40
    ctx->r10 = ctx->r10 | 0X4A40;
    // 0x800B8030: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x800B8034: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B8038: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800B803C: lbu         $a1, 0x9($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X9);
    // 0x800B8040: jal         0x800B7EA0
    // 0x800B8044: addiu       $a1, $a1, 0xC24
    ctx->r5 = ADD32(ctx->r5, 0XC24);
    func_800B7EA0(rdram, ctx);
        goto after_0;
    // 0x800B8044: addiu       $a1, $a1, 0xC24
    ctx->r5 = ADD32(ctx->r5, 0XC24);
    after_0:
    // 0x800B8048: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800B804C: b           L_800B80A8
    // 0x800B8050: addiu       $t0, $t0, -0x7D40
    ctx->r8 = ADD32(ctx->r8, -0X7D40);
        goto L_800B80A8;
    // 0x800B8050: addiu       $t0, $t0, -0x7D40
    ctx->r8 = ADD32(ctx->r8, -0X7D40);
L_800B8054:
    // 0x800B8054: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B8058: ori         $t6, $t6, 0x9623
    ctx->r14 = ctx->r14 | 0X9623;
    // 0x800B805C: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800B8060: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800B8064: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B8068: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B806C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800B8070: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B8074: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x800B8078: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x800B807C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800B8080: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800B8084: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800B8088: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B808C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B8090: ori         $t8, $t8, 0x4A40
    ctx->r24 = ctx->r24 | 0X4A40;
    // 0x800B8094: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x800B8098: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800B809C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B80A0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B80A4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_800B80A8:
    // 0x800B80A8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B80AC: sb          $t2, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r10;
    // 0x800B80B0: jal         0x800D3724
    // 0x800B80B4: lbu         $a0, 0x6($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X6);
    func_800D3724(rdram, ctx);
        goto after_1;
    // 0x800B80B4: lbu         $a0, 0x6($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X6);
    after_1:
    // 0x800B80B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B80BC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800B80C0: addiu       $t0, $t0, -0x7D40
    ctx->r8 = ADD32(ctx->r8, -0X7D40);
    // 0x800B80C4: sb          $v0, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r2;
    // 0x800B80C8: jr          $ra
    // 0x800B80CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B80CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void idtwinkle_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800148: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8080014C: lh          $t6, 0x26($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X26);
    // 0x80800150: lh          $v0, 0x24($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X24);
    // 0x80800154: bnel        $t6, $v0, L_8080017C
    if (ctx->r14 != ctx->r2) {
        // 0x80800158: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_8080017C;
    }
    goto skip_0;
    // 0x80800158: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8080015C: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x80800160: lh          $v0, 0x24($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X24);
    // 0x80800164: sh          $t7, 0xE($a3)
    MEM_H(0XE, ctx->r7) = ctx->r15;
    // 0x80800168: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x8080016C: sh          $t8, 0x10($a3)
    MEM_H(0X10, ctx->r7) = ctx->r24;
    // 0x80800170: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x80800174: sh          $t9, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r25;
    // 0x80800178: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
L_8080017C:
    // 0x8080017C: jr          $ra
    // 0x80800180: sh          $t0, 0x24($a3)
    MEM_H(0X24, ctx->r7) = ctx->r8;
    return;
    // 0x80800180: sh          $t0, 0x24($a3)
    MEM_H(0X24, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80800ECC_chheggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ECC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800ED0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800ED4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800ED8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800EDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800EE0: jal         0x80100094
    // 0x80800EE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800EE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800EE8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800EEC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800EF0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800EF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800EF8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800EFC: bnel        $t7, $at, L_80800F34
    if (ctx->r15 != ctx->r1) {
        // 0x80800F00: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_80800F34;
    }
    goto skip_0;
    // 0x80800F00: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80800F04: jal         0x80089C30
    // 0x80800F08: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800F08: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x80800F0C: beq         $v0, $zero, L_80800F1C
    if (ctx->r2 == 0) {
        // 0x80800F10: nop
    
            goto L_80800F1C;
    }
    // 0x80800F10: nop

    // 0x80800F14: jal         0x800FFA88
    // 0x80800F18: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_2;
    // 0x80800F18: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_2:
L_80800F1C:
    // 0x80800F1C: jal         0x80106790
    // 0x80800F20: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80800F20: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_3:
    // 0x80800F24: lbu         $t9, 0x65($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X65);
    // 0x80800F28: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80800F2C: sb          $t0, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r8;
    // 0x80800F30: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_80800F34:
    // 0x80800F34: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80800F38: sltiu       $at, $t2, 0x13
    ctx->r1 = ctx->r10 < 0X13 ? 1 : 0;
    // 0x80800F3C: beq         $at, $zero, L_80801550
    if (ctx->r1 == 0) {
        // 0x80800F40: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80801550;
    }
    // 0x80800F40: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800F44: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2456, 0X1BE4) << 16);
    // 0x80800F48: addu        $at, $at, $t2
    gpr jr_addend_80800F50 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80800F4C: lw          $t2, 0x1BE4($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2456, 0X1BE4));
    // 0x80800F50: jr          $t2
    // 0x80800F54: nop

    switch (jr_addend_80800F50 >> 2) {
        case 0: goto L_80800F58; break;
        case 1: goto L_80801550; break;
        case 2: goto L_80800F98; break;
        case 3: goto L_80800FBC; break;
        case 4: goto L_80801020; break;
        case 5: goto L_80801044; break;
        case 6: goto L_808010BC; break;
        case 7: goto L_80801100; break;
        case 8: goto L_8080114C; break;
        case 9: goto L_80801170; break;
        case 10: goto L_808011B4; break;
        case 11: goto L_808011E0; break;
        case 12: goto L_808012E4; break;
        case 13: goto L_80801550; break;
        case 14: goto L_80801364; break;
        case 15: goto L_808013F4; break;
        case 16: goto L_80801418; break;
        case 17: goto L_808014A8; break;
        case 18: goto L_80801548; break;
        default: switch_error(__func__, 0x80800F50, 0x80801BE4);
    }
    // 0x80800F54: nop

L_80800F58:
    // 0x80800F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F5C: jal         0x80100094
    // 0x80800F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800F6C: jal         0x80800000
    // 0x80800F70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800000_chheggy(rdram, ctx);
        goto after_5;
    // 0x80800F70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800F74: jal         0x800DA544
    // 0x80800F78: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x80800F78: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_6:
    // 0x80800F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F80: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800F84: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80800F88: jal         0x80800750
    // 0x80800F8C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_80800750_chheggy(rdram, ctx);
        goto after_7;
    // 0x80800F8C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_7:
    // 0x80800F90: b           L_80801554
    // 0x80800F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x80800F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F98:
    // 0x80800F98: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800F9C: addiu       $t3, $zero, 0xCB
    ctx->r11 = ADD32(0, 0XCB);
    // 0x80800FA0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800FA4: addiu       $a1, $zero, 0x153C
    ctx->r5 = ADD32(0, 0X153C);
    // 0x80800FA8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800FAC: jal         0x8008A208
    // 0x80800FB0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800FB0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80800FB4: b           L_80801554
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800FBC:
    // 0x80800FBC: jal         0x800DA298
    // 0x80800FC0: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x80800FC0: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    after_9:
    // 0x80800FC4: bnel        $v0, $zero, L_80800FE0
    if (ctx->r2 != 0) {
        // 0x80800FC8: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80800FE0;
    }
    goto skip_1;
    // 0x80800FC8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80800FCC: jal         0x800DA298
    // 0x80800FD0: addiu       $a0, $zero, 0x3E6
    ctx->r4 = ADD32(0, 0X3E6);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80800FD0: addiu       $a0, $zero, 0x3E6
    ctx->r4 = ADD32(0, 0X3E6);
    after_10:
    // 0x80800FD4: beq         $v0, $zero, L_80801000
    if (ctx->r2 == 0) {
        // 0x80800FD8: addiu       $a1, $zero, 0x153D
        ctx->r5 = ADD32(0, 0X153D);
            goto L_80801000;
    }
    // 0x80800FD8: addiu       $a1, $zero, 0x153D
    ctx->r5 = ADD32(0, 0X153D);
    // 0x80800FDC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80800FE0:
    // 0x80800FE0: addiu       $t4, $zero, 0xCB
    ctx->r12 = ADD32(0, 0XCB);
    // 0x80800FE4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800FE8: addiu       $a1, $zero, 0x153E
    ctx->r5 = ADD32(0, 0X153E);
    // 0x80800FEC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800FF0: jal         0x8008A208
    // 0x80800FF4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80800FF4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_11:
    // 0x80800FF8: b           L_80801554
    // 0x80800FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x80800FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801000:
    // 0x80801000: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801004: addiu       $t5, $zero, 0xCB
    ctx->r13 = ADD32(0, 0XCB);
    // 0x80801008: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080100C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80801010: jal         0x8008A208
    // 0x80801014: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80801014: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_12:
    // 0x80801018: b           L_80801554
    // 0x8080101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x8080101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801020:
    // 0x80801020: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801024: addiu       $t6, $zero, 0xCB
    ctx->r14 = ADD32(0, 0XCB);
    // 0x80801028: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080102C: addiu       $a1, $zero, 0x153F
    ctx->r5 = ADD32(0, 0X153F);
    // 0x80801030: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80801034: jal         0x8008A208
    // 0x80801038: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80801038: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x8080103C: b           L_80801554
    // 0x80801040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x80801040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801044:
    // 0x80801044: jal         0x800DA298
    // 0x80801048: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x80801048: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    after_14:
    // 0x8080104C: beq         $v0, $zero, L_80801060
    if (ctx->r2 == 0) {
        // 0x80801050: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801060;
    }
    // 0x80801050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801054: addiu       $t7, $zero, 0x515
    ctx->r15 = ADD32(0, 0X515);
    // 0x80801058: b           L_80801068
    // 0x8080105C: sw          $t7, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r15;
        goto L_80801068;
    // 0x8080105C: sw          $t7, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r15;
L_80801060:
    // 0x80801060: addiu       $t8, $zero, 0x516
    ctx->r24 = ADD32(0, 0X516);
    // 0x80801064: sw          $t8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r24;
L_80801068:
    // 0x80801068: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x8080106C: addiu       $at, $zero, 0x515
    ctx->r1 = ADD32(0, 0X515);
    // 0x80801070: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80801074: bne         $t9, $at, L_80801084
    if (ctx->r25 != ctx->r1) {
        // 0x80801078: nop
    
            goto L_80801084;
    }
    // 0x80801078: nop

    // 0x8080107C: b           L_80801084
    // 0x80801080: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80801084;
    // 0x80801080: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80801084:
    // 0x80801084: jal         0x80800000
    // 0x80801088: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80800000_chheggy(rdram, ctx);
        goto after_15;
    // 0x80801088: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_15:
    // 0x8080108C: jal         0x800DA298
    // 0x80801090: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    func_800DA298(rdram, ctx);
        goto after_16;
    // 0x80801090: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    after_16:
    // 0x80801094: beq         $v0, $zero, L_808010A4
    if (ctx->r2 == 0) {
        // 0x80801098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010A4;
    }
    // 0x80801098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080109C: b           L_808010A8
    // 0x808010A0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
        goto L_808010A8;
    // 0x808010A0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_808010A4:
    // 0x808010A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_808010A8:
    // 0x808010A8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808010AC: jal         0x80800750
    // 0x808010B0: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_80800750_chheggy(rdram, ctx);
        goto after_17;
    // 0x808010B0: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_17:
    // 0x808010B4: b           L_80801554
    // 0x808010B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x808010B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808010BC:
    // 0x808010BC: lw          $t0, 0x34($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X34);
    // 0x808010C0: addiu       $at, $zero, 0x515
    ctx->r1 = ADD32(0, 0X515);
    // 0x808010C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808010C8: bne         $t0, $at, L_808010D8
    if (ctx->r8 != ctx->r1) {
        // 0x808010CC: lw          $t1, 0x34($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X34);
            goto L_808010D8;
    }
    // 0x808010CC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x808010D0: b           L_808010DC
    // 0x808010D4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
        goto L_808010DC;
    // 0x808010D4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_808010D8:
    // 0x808010D8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_808010DC:
    // 0x808010DC: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x808010E0: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x808010E4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x808010E8: jal         0x80090734
    // 0x808010EC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    func_80090734(rdram, ctx);
        goto after_18;
    // 0x808010EC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_18:
    // 0x808010F0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808010F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808010F8: b           L_80801550
    // 0x808010FC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80801550;
    // 0x808010FC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80801100:
    // 0x80801100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801108: jal         0x801000D8
    // 0x8080110C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_801000D8(rdram, ctx);
        goto after_19;
    // 0x8080110C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_19:
    // 0x80801110: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801114: jal         0x80090708
    // 0x80801118: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_20;
    // 0x80801118: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x8080111C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80801120: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80801124: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    // 0x80801128: jal         0x80089FD0
    // 0x8080112C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _subaddieitem_entrypoint_0(rdram, ctx);
        goto after_21;
    // 0x8080112C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_21:
    // 0x80801130: jal         0x80089FE0
    // 0x80801134: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _subaddieitem_entrypoint_2(rdram, ctx);
        goto after_22;
    // 0x80801134: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_22:
    // 0x80801138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080113C: jal         0x80108B04
    // 0x80801140: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_23;
    // 0x80801140: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x80801144: b           L_80801554
    // 0x80801148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x80801148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080114C:
    // 0x8080114C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801150: jal         0x80100094
    // 0x80801154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_24;
    // 0x80801154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x80801158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080115C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801160: jal         0x80800000
    // 0x80801164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800000_chheggy(rdram, ctx);
        goto after_25;
    // 0x80801164: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_25:
    // 0x80801168: b           L_80801554
    // 0x8080116C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x8080116C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801170:
    // 0x80801170: lw          $t3, 0x34($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X34);
    // 0x80801174: addiu       $at, $zero, 0x515
    ctx->r1 = ADD32(0, 0X515);
    // 0x80801178: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8080117C: bne         $t3, $at, L_8080118C
    if (ctx->r11 != ctx->r1) {
        // 0x80801180: lw          $t4, 0x34($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X34);
            goto L_8080118C;
    }
    // 0x80801180: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80801184: b           L_80801190
    // 0x80801188: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80801190;
    // 0x80801188: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8080118C:
    // 0x8080118C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80801190:
    // 0x80801190: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x80801194: subu        $t5, $t5, $a2
    ctx->r13 = SUB32(ctx->r13, ctx->r6);
    // 0x80801198: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8080119C: jal         0x80090734
    // 0x808011A0: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    func_80090734(rdram, ctx);
        goto after_26;
    // 0x808011A0: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_26:
    // 0x808011A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808011A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808011AC: b           L_80801550
    // 0x808011B0: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80801550;
    // 0x808011B0: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808011B4:
    // 0x808011B4: jal         0x80090708
    // 0x808011B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_27;
    // 0x808011B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_27:
    // 0x808011BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808011C0: addiu       $t6, $zero, 0xCB
    ctx->r14 = ADD32(0, 0XCB);
    // 0x808011C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808011C8: addiu       $a1, $zero, 0x1540
    ctx->r5 = ADD32(0, 0X1540);
    // 0x808011CC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808011D0: jal         0x8008A208
    // 0x808011D4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_28;
    // 0x808011D4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_28:
    // 0x808011D8: b           L_80801554
    // 0x808011DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x808011DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808011E0:
    // 0x808011E0: jal         0x800F54E4
    // 0x808011E4: nop

    func_800F54E4(rdram, ctx);
        goto after_29;
    // 0x808011E4: nop

    after_29:
    // 0x808011E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808011EC: jal         0x800F82D4
    // 0x808011F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_30;
    // 0x808011F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_30:
    // 0x808011F4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x808011F8: sll         $t8, $v0, 11
    ctx->r24 = S32(ctx->r2 << 11);
    // 0x808011FC: bgez        $t8, L_80801298
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801200: sll         $t6, $v0, 12
        ctx->r14 = S32(ctx->r2 << 12);
            goto L_80801298;
    }
    // 0x80801200: sll         $t6, $v0, 12
    ctx->r14 = S32(ctx->r2 << 12);
    // 0x80801204: jal         0x800DA298
    // 0x80801208: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    func_800DA298(rdram, ctx);
        goto after_31;
    // 0x80801208: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    after_31:
    // 0x8080120C: beq         $v0, $zero, L_8080125C
    if (ctx->r2 == 0) {
        // 0x80801210: lw          $t2, 0x34($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X34);
            goto L_8080125C;
    }
    // 0x80801210: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80801214: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80801218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080121C: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x80801220: lw          $t9, 0x60($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X60);
    // 0x80801224: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801228: sw          $t9, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r25;
    // 0x8080122C: jal         0x801058C4
    // 0x80801230: lw          $a1, 0x58($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X58);
    func_801058C4(rdram, ctx);
        goto after_32;
    // 0x80801230: lw          $a1, 0x58($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X58);
    after_32:
    // 0x80801234: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80801238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080123C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80801240: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x80801244: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80801248: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8080124C: jal         0x80800750
    // 0x80801250: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    func_80800750_chheggy(rdram, ctx);
        goto after_33;
    // 0x80801250: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_33:
    // 0x80801254: b           L_808012D4
    // 0x80801258: nop

        goto L_808012D4;
    // 0x80801258: nop

L_8080125C:
    // 0x8080125C: lw          $t3, 0x5C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X5C);
    // 0x80801260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801264: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x80801268: sw          $t3, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r11;
    // 0x8080126C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80801270: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80801274: jal         0x801058C4
    // 0x80801278: lw          $a1, 0x48($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X48);
    func_801058C4(rdram, ctx);
        goto after_34;
    // 0x80801278: lw          $a1, 0x48($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X48);
    after_34:
    // 0x8080127C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801280: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80801284: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80801288: jal         0x80800750
    // 0x8080128C: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    func_80800750_chheggy(rdram, ctx);
        goto after_35;
    // 0x8080128C: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_35:
    // 0x80801290: b           L_808012D4
    // 0x80801294: nop

        goto L_808012D4;
    // 0x80801294: nop

L_80801298:
    // 0x80801298: bgez        $t6, L_808012D4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080129C: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_808012D4;
    }
    // 0x8080129C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808012A0: lw          $t8, 0x60($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X60);
    // 0x808012A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012A8: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x808012AC: sw          $t8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r24;
    // 0x808012B0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x808012B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808012B8: jal         0x801058C4
    // 0x808012BC: lw          $a1, 0x50($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X50);
    func_801058C4(rdram, ctx);
        goto after_36;
    // 0x808012BC: lw          $a1, 0x50($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X50);
    after_36:
    // 0x808012C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012C4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808012C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808012CC: jal         0x80800750
    // 0x808012D0: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    func_80800750_chheggy(rdram, ctx);
        goto after_37;
    // 0x808012D0: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_37:
L_808012D4:
    // 0x808012D4: jal         0x80105BAC
    // 0x808012D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105BAC(rdram, ctx);
        goto after_38;
    // 0x808012D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x808012DC: b           L_80801554
    // 0x808012E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x808012E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808012E4:
    // 0x808012E4: jal         0x80105634
    // 0x808012E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105634(rdram, ctx);
        goto after_39;
    // 0x808012E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x808012EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808012F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808012F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808012F8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x808012FC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801300: jal         0x800EE7F8
    // 0x80801304: addiu       $a0, $a0, 0x64
    ctx->r4 = ADD32(ctx->r4, 0X64);
    func_800EE7F8(rdram, ctx);
        goto after_40;
    // 0x80801304: addiu       $a0, $a0, 0x64
    ctx->r4 = ADD32(ctx->r4, 0X64);
    after_40:
    // 0x80801308: jal         0x80106790
    // 0x8080130C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_41;
    // 0x8080130C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_41:
    // 0x80801310: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801314: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80801318: jal         0x800EE7F8
    // 0x8080131C: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    func_800EE7F8(rdram, ctx);
        goto after_42;
    // 0x8080131C: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_42:
    // 0x80801320: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80801324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801328: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8080132C: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x80801330: bgez        $t2, L_80801354
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80801334: addiu       $a3, $zero, 0x30
        ctx->r7 = ADD32(0, 0X30);
            goto L_80801354;
    }
    // 0x80801334: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x80801338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080133C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80801340: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80801344: jal         0x808006C4
    // 0x80801348: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_808006C4_chheggy(rdram, ctx);
        goto after_43;
    // 0x80801348: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_43:
    // 0x8080134C: b           L_80801554
    // 0x80801350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x80801350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801354:
    // 0x80801354: jal         0x808006C4
    // 0x80801358: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_808006C4_chheggy(rdram, ctx);
        goto after_44;
    // 0x80801358: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_44:
    // 0x8080135C: b           L_80801554
    // 0x80801360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x80801360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801364:
    // 0x80801364: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801368: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8080136C: jal         0x8010114C
    // 0x80801370: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_45;
    // 0x80801370: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_45:
    // 0x80801374: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801378: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080137C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801380: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x80801384: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801388: jal         0x800EE7F8
    // 0x8080138C: addiu       $a0, $a0, 0x64
    ctx->r4 = ADD32(ctx->r4, 0X64);
    func_800EE7F8(rdram, ctx);
        goto after_46;
    // 0x8080138C: addiu       $a0, $a0, 0x64
    ctx->r4 = ADD32(ctx->r4, 0X64);
    after_46:
    // 0x80801390: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80801394: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80801398: sll         $t4, $v0, 11
    ctx->r12 = S32(ctx->r2 << 11);
    // 0x8080139C: bgez        $t4, L_808013C8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808013A0: sll         $t7, $v0, 12
        ctx->r15 = S32(ctx->r2 << 12);
            goto L_808013C8;
    }
    // 0x808013A0: sll         $t7, $v0, 12
    ctx->r15 = S32(ctx->r2 << 12);
    // 0x808013A4: jal         0x800D7520
    // 0x808013A8: lw          $a0, 0x4C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X4C);
    func_800D7520(rdram, ctx);
        goto after_47;
    // 0x808013A8: lw          $a0, 0x4C($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X4C);
    after_47:
    // 0x808013AC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808013B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808013B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808013B8: jal         0x800C7A68
    // 0x808013BC: addiu       $a2, $a2, 0x70
    ctx->r6 = ADD32(ctx->r6, 0X70);
    func_800C7A68(rdram, ctx);
        goto after_48;
    // 0x808013BC: addiu       $a2, $a2, 0x70
    ctx->r6 = ADD32(ctx->r6, 0X70);
    after_48:
    // 0x808013C0: b           L_80801554
    // 0x808013C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x808013C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808013C8:
    // 0x808013C8: bgez        $t7, L_80801550
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808013CC: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_80801550;
    }
    // 0x808013CC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x808013D0: jal         0x800D7520
    // 0x808013D4: lw          $a0, 0x54($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X54);
    func_800D7520(rdram, ctx);
        goto after_49;
    // 0x808013D4: lw          $a0, 0x54($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X54);
    after_49:
    // 0x808013D8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808013DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808013E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808013E4: jal         0x800C7A68
    // 0x808013E8: addiu       $a2, $a2, 0x70
    ctx->r6 = ADD32(ctx->r6, 0X70);
    func_800C7A68(rdram, ctx);
        goto after_50;
    // 0x808013E8: addiu       $a2, $a2, 0x70
    ctx->r6 = ADD32(ctx->r6, 0X70);
    after_50:
    // 0x808013EC: b           L_80801554
    // 0x808013F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x808013F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808013F4:
    // 0x808013F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808013F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808013FC: jal         0x800F54E4
    // 0x80801400: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    func_800F54E4(rdram, ctx);
        goto after_51;
    // 0x80801400: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    after_51:
    // 0x80801404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801408: jal         0x8010CD50
    // 0x8080140C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010CD50(rdram, ctx);
        goto after_52;
    // 0x8080140C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_52:
    // 0x80801410: b           L_80801550
    // 0x80801414: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
        goto L_80801550;
    // 0x80801414: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80801418:
    // 0x80801418: jal         0x800F54E4
    // 0x8080141C: nop

    func_800F54E4(rdram, ctx);
        goto after_53;
    // 0x8080141C: nop

    after_53:
    // 0x80801420: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801424: jal         0x800F82D4
    // 0x80801428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_54;
    // 0x80801428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_54:
    // 0x8080142C: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80801430: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x80801434: bgez        $t1, L_80801470
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80801438: nop
    
            goto L_80801470;
    }
    // 0x80801438: nop

    // 0x8080143C: jal         0x800DA544
    // 0x80801440: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    func_800DA544(rdram, ctx);
        goto after_55;
    // 0x80801440: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    after_55:
    // 0x80801444: jal         0x800D3EF4
    // 0x80801448: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800D3EF4(rdram, ctx);
        goto after_56;
    // 0x80801448: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_56:
    // 0x8080144C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801450: addiu       $t2, $zero, 0xCB
    ctx->r10 = ADD32(0, 0XCB);
    // 0x80801454: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801458: addiu       $a1, $zero, 0x1541
    ctx->r5 = ADD32(0, 0X1541);
    // 0x8080145C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80801460: jal         0x8008A208
    // 0x80801464: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_57;
    // 0x80801464: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_57:
    // 0x80801468: b           L_80801554
    // 0x8080146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x8080146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801470:
    // 0x80801470: jal         0x800DA544
    // 0x80801474: addiu       $a0, $zero, 0x3E6
    ctx->r4 = ADD32(0, 0X3E6);
    func_800DA544(rdram, ctx);
        goto after_58;
    // 0x80801474: addiu       $a0, $zero, 0x3E6
    ctx->r4 = ADD32(0, 0X3E6);
    after_58:
    // 0x80801478: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8080147C: jal         0x800C7074
    // 0x80801480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7074(rdram, ctx);
        goto after_59;
    // 0x80801480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_59:
    // 0x80801484: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801488: addiu       $t3, $zero, 0xCB
    ctx->r11 = ADD32(0, 0XCB);
    // 0x8080148C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80801490: addiu       $a1, $zero, 0x1542
    ctx->r5 = ADD32(0, 0X1542);
    // 0x80801494: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80801498: jal         0x8008A208
    // 0x8080149C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_60;
    // 0x8080149C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_60:
    // 0x808014A0: b           L_80801554
    // 0x808014A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x808014A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808014A8:
    // 0x808014A8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x808014AC: sll         $t5, $v0, 11
    ctx->r13 = S32(ctx->r2 << 11);
    // 0x808014B0: bgez        $t5, L_808014F8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808014B4: sll         $t0, $v0, 12
        ctx->r8 = S32(ctx->r2 << 12);
            goto L_808014F8;
    }
    // 0x808014B4: sll         $t0, $v0, 12
    ctx->r8 = S32(ctx->r2 << 12);
    // 0x808014B8: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x808014BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014C0: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x808014C4: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x808014C8: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x808014CC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x808014D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808014D4: jal         0x801058C4
    // 0x808014D8: lw          $a1, 0x4C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4C);
    func_801058C4(rdram, ctx);
        goto after_61;
    // 0x808014D8: lw          $a1, 0x4C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X4C);
    after_61:
    // 0x808014DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014E0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808014E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808014E8: jal         0x80800750
    // 0x808014EC: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    func_80800750_chheggy(rdram, ctx);
        goto after_62;
    // 0x808014EC: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_62:
    // 0x808014F0: b           L_80801538
    // 0x808014F4: nop

        goto L_80801538;
    // 0x808014F4: nop

L_808014F8:
    // 0x808014F8: bgez        $t0, L_80801538
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808014FC: nop
    
            goto L_80801538;
    }
    // 0x808014FC: nop

    // 0x80801500: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80801504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801508: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x8080150C: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x80801510: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x80801514: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80801518: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080151C: jal         0x801058C4
    // 0x80801520: lw          $a1, 0x54($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X54);
    func_801058C4(rdram, ctx);
        goto after_63;
    // 0x80801520: lw          $a1, 0x54($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X54);
    after_63:
    // 0x80801524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801528: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8080152C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801530: jal         0x80800750
    // 0x80801534: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    func_80800750_chheggy(rdram, ctx);
        goto after_64;
    // 0x80801534: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_64:
L_80801538:
    // 0x80801538: jal         0x80105BAC
    // 0x8080153C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105BAC(rdram, ctx);
        goto after_65;
    // 0x8080153C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
    // 0x80801540: b           L_80801554
    // 0x80801544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801554;
    // 0x80801544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801548:
    // 0x80801548: jal         0x8080087C
    // 0x8080154C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080087C_chheggy(rdram, ctx);
        goto after_66;
    // 0x8080154C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
L_80801550:
    // 0x80801550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801554:
    // 0x80801554: jal         0x80102424
    // 0x80801558: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80102424(rdram, ctx);
        goto after_67;
    // 0x80801558: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_67:
    // 0x8080155C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801560: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801564: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801568: jr          $ra
    // 0x8080156C: nop

    return;
    // 0x8080156C: nop

;}
RECOMP_FUNC void _bsclimb_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F28: syscall     34
    recomp_syscall_handler(rdram, ctx, 0x80082F28);
    return;
    // 0x80082F2C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80806AD0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806AD0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80806AD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80806AD8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80806ADC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80806AE0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80806AE4: jal         0x800D9004
    // 0x80806AE8: lw          $s0, 0x188($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X188);
    func_800D9004(rdram, ctx);
        goto after_0;
    // 0x80806AE8: lw          $s0, 0x188($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X188);
    after_0:
    // 0x80806AEC: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA55C) << 16);
    // 0x80806AF0: lwc1        $f12, -0x5AA4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA55C));
    // 0x80806AF4: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80806AF8: lw          $a2, 0x1F0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1F0);
    // 0x80806AFC: sub.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80806B00: addiu       $a0, $s0, 0x210
    ctx->r4 = ADD32(ctx->r16, 0X210);
    // 0x80806B04: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80806B08: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80806B0C: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80806B10: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80806B14: jal         0x808057C8
    // 0x80806B18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_808057C8_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80806B18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80806B1C: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80806B20: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80806B24: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80806B28: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80806B2C: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x80806B30: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80806B34: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80806B38: bc1tl       L_80806B5C
    if (c1cs) {
        // 0x80806B3C: swc1        $f12, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
            goto L_80806B5C;
    }
    goto skip_0;
    // 0x80806B3C: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    skip_0:
    // 0x80806B40: lw          $a2, 0x1F0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1F0);
    // 0x80806B44: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80806B48: jal         0x808057C8
    // 0x80806B4C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_808057C8_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80806B4C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80806B50: b           L_80806B5C
    // 0x80806B54: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
        goto L_80806B5C;
    // 0x80806B54: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80806B58: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
L_80806B5C:
    // 0x80806B5C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80806B60: jal         0x808052A4
    // 0x80806B64: addiu       $a1, $s0, 0x214
    ctx->r5 = ADD32(ctx->r16, 0X214);
    func_808052A4_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80806B64: addiu       $a1, $s0, 0x214
    ctx->r5 = ADD32(ctx->r16, 0X214);
    after_3:
    // 0x80806B68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80806B6C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80806B70: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80806B74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80806B78: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80806B7C: jr          $ra
    // 0x80806B80: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    return;
    // 0x80806B80: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
;}
RECOMP_FUNC void bamotor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800040: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800044: jal         0x800918F8
    // 0x80800048: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    bakey_getControllerIndex(rdram, ctx);
        goto after_0;
    // 0x80800048: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080004C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800050: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800054: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800058: jal         0x800187B4
    // 0x8080005C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_800187B4(rdram, ctx);
        goto after_1;
    // 0x8080005C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void chclockworkmouse_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080366C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1564, 0X3EF0) << 16);
    // 0x80803670: jr          $ra
    // 0x80803674: addiu       $v0, $v0, 0x3EF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1564, 0X3EF0));
    return;
    // 0x80803674: addiu       $v0, $v0, 0x3EF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1564, 0X3EF0));
;}
RECOMP_FUNC void _bskazstilt_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083698: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083698);
    return;
    // 0x8008369C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bsblongleg_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A10: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A10);
    return;
    // 0x80082A14: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800A14_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A14: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800A18: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800A1C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A28: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(896, 0X11F0) << 16);
    // 0x80800A2C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80800A30: addiu       $a2, $a2, 0x11F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(896, 0X11F0));
    // 0x80800A34: jal         0x80089D20
    // 0x80800A38: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800A38: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x80800A3C: beq         $v0, $zero, L_80800AA4
    if (ctx->r2 == 0) {
        // 0x80800A40: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_80800AA4;
    }
    // 0x80800A40: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800A44: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800A48: jal         0x8008A0E0
    // 0x80800A4C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800A4C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800A50: beq         $v0, $zero, L_80800A8C
    if (ctx->r2 == 0) {
        // 0x80800A54: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_80800A8C;
    }
    // 0x80800A54: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800A58: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800A5C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800A60: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800A64: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(896, 0X1364) << 16);
    // 0x80800A68: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800A6C: addiu       $t6, $t6, 0x1364
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(896, 0X1364));
    // 0x80800A70: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800A74: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800A78: bc1f        L_80800A84
    if (!c1cs) {
        // 0x80800A7C: addiu       $a3, $zero, 0x6
        ctx->r7 = ADD32(0, 0X6);
            goto L_80800A84;
    }
    // 0x80800A7C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80800A80: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
L_80800A84:
    // 0x80800A84: jal         0x800BBCB8
    // 0x80800A88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x80800A88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_2:
L_80800A8C:
    // 0x80800A8C: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80800A90: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800A94: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800A98: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800A9C: jal         0x80089BF8
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiejoy_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80800AA4:
    // 0x80800AA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800AA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800AAC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800AB0: jr          $ra
    // 0x80800AB4: nop

    return;
    // 0x80800AB4: nop

;}
RECOMP_FUNC void _gspropctrl_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BD8: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088BD8);
    return;
    // 0x80088BDC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void gcnewoption_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080148C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80801490: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80801494: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801498: jr          $ra
    // 0x8080149C: sh          $t6, 0xB0($t8)
    MEM_H(0XB0, ctx->r24) = ctx->r14;
    return;
    // 0x8080149C: sh          $t6, 0xB0($t8)
    MEM_H(0XB0, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void bsjump_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E40: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800E44: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(216, 0X1140) << 16);
    // 0x80800E48: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800E4C: jr          $ra
    // 0x80800E50: lw          $v0, 0x1140($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(216, 0X1140));
    return;
    // 0x80800E50: lw          $v0, 0x1140($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(216, 0X1140));
;}
RECOMP_FUNC void func_808000AC_chmricecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000B8: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808000BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000C4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808000C8: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x808000CC: beq         $at, $zero, L_808004F8
    if (ctx->r1 == 0) {
        // 0x808000D0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808004F8;
    }
    // 0x808000D0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808000D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1224, 0X880) << 16);
    // 0x808000D8: addu        $at, $at, $t8
    gpr jr_addend_808000E0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808000DC: lw          $t8, 0x880($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1224, 0X880));
    // 0x808000E0: jr          $t8
    // 0x808000E4: nop

    switch (jr_addend_808000E0 >> 2) {
        case 0: goto L_808000E8; break;
        case 1: goto L_808000F8; break;
        case 2: goto L_808004F8; break;
        case 3: goto L_8080012C; break;
        case 4: goto L_8080015C; break;
        case 5: goto L_808004CC; break;
        case 6: goto L_808004F8; break;
        case 7: goto L_808002E0; break;
        case 8: goto L_808003AC; break;
        default: switch_error(__func__, 0x808000E0, 0x80800880);
    }
    // 0x808000E4: nop

L_808000E8:
    // 0x808000E8: jal         0x80800778
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800778_chmricecube(rdram, ctx);
        goto after_0;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808000F0: b           L_808004FC
    // 0x808000F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004FC;
    // 0x808000F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000F8:
    // 0x808000F8: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x80800104: jal         0x80800850
    // 0x80800108: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_80800850_chmricecube(rdram, ctx);
        goto after_1;
    // 0x80800108: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_1:
    // 0x8080010C: jal         0x80101DDC
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_2;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800114: beq         $v0, $zero, L_808004F8
    if (ctx->r2 == 0) {
        // 0x80800118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004F8;
    }
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x80102424
    // 0x80800120: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800120: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800124: b           L_808004FC
    // 0x80800128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004FC;
    // 0x80800128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080012C:
    // 0x8080012C: jal         0x80101DDC
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_4;
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800134: beql        $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x80800138: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808004FC;
    }
    goto skip_0;
    // 0x80800138: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080013C: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800148: andi        $t3, $t2, 0xFFF7
    ctx->r11 = ctx->r10 & 0XFFF7;
    // 0x8080014C: jal         0x80102424
    // 0x80800150: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80800150: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    after_5:
    // 0x80800154: b           L_808004FC
    // 0x80800158: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004FC;
    // 0x80800158: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080015C:
    // 0x8080015C: jal         0x800D8FF8
    // 0x80800160: nop

    func_800D8FF8(rdram, ctx);
        goto after_6;
    // 0x80800160: nop

    after_6:
    // 0x80800164: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800168: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080016C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800170: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800174: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800178: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080017C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800180: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800184: jal         0x800F15F8
    // 0x80800188: nop

    func_800F15F8(rdram, ctx);
        goto after_7;
    // 0x80800188: nop

    after_7:
    // 0x8080018C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800190: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800194: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800198: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x8080019C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808001A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808001A4: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x808001A8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808001AC: jal         0x800EF1B8
    // 0x808001B0: nop

    func_800EF1B8(rdram, ctx);
        goto after_8;
    // 0x808001B0: nop

    after_8:
    // 0x808001B4: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x808001B8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808001BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001C0: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x808001C4: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    // 0x808001C8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808001CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001D0: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808001D4: lwc1        $f12, 0x30($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808001D8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808001DC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808001E0: jal         0x800F15F8
    // 0x808001E4: nop

    func_800F15F8(rdram, ctx);
        goto after_9;
    // 0x808001E4: nop

    after_9:
    // 0x808001E8: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x808001EC: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808001F0: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808001F4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x808001F8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808001FC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80800200: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x80800204: jal         0x800EFC7C
    // 0x80800208: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800EFC7C(rdram, ctx);
        goto after_10;
    // 0x80800208: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x8080020C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1224, 0X8A4) << 16);
    // 0x80800210: lwc1        $f8, 0x8A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1224, 0X8A4));
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080021C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800220: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800224: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1224, 0X980) << 16);
    // 0x80800228: bc1f        L_808002D0
    if (!c1cs) {
        // 0x8080022C: nop
    
            goto L_808002D0;
    }
    // 0x8080022C: nop

    // 0x80800230: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080023C: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800240: bltz        $t9, L_8080025C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800244: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1224, 0X970) << 16);
            goto L_8080025C;
    }
    // 0x80800244: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1224, 0X970) << 16);
    // 0x80800248: jal         0x80089D18
    // 0x8080024C: addiu       $a2, $a2, 0x970
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1224, 0X970));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x8080024C: addiu       $a2, $a2, 0x970
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1224, 0X970));
    after_11:
    // 0x80800250: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800254: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80800258: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_8080025C:
    // 0x8080025C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800260: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800264: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800268: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080026C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800270: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800274: lui         $at, 0x45FA
    ctx->r1 = S32(0X45FA << 16);
    // 0x80800278: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8080027C: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x80800280: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800284: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800288: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080028C: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80800290: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800294: nop

    // 0x80800298: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8080029C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x808002A0: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808002A4: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x808002A8: nop

    // 0x808002AC: bc1fl       L_808004FC
    if (!c1cs) {
        // 0x808002B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808004FC;
    }
    goto skip_1;
    // 0x808002B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808002B4: jal         0x80085710
    // 0x808002B8: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_12;
    // 0x808002B8: nop

    after_12:
    // 0x808002BC: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    // 0x808002C0: jal         0x800887D8
    // 0x808002C4: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_13;
    // 0x808002C4: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    after_13:
    // 0x808002C8: b           L_808004FC
    // 0x808002CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004FC;
    // 0x808002CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002D0:
    // 0x808002D0: jal         0x80089D50
    // 0x808002D4: addiu       $a3, $a3, 0x980
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1224, 0X980));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x808002D4: addiu       $a3, $a3, 0x980
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1224, 0X980));
    after_14:
    // 0x808002D8: b           L_808004FC
    // 0x808002DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004FC;
    // 0x808002DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002E0:
    // 0x808002E0: jal         0x800D8FF8
    // 0x808002E4: nop

    func_800D8FF8(rdram, ctx);
        goto after_15;
    // 0x808002E4: nop

    after_15:
    // 0x808002E8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808002EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808002F0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808002F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002F8: lwc1        $f12, 0x30($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808002FC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800300: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800304: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800308: jal         0x800F15F8
    // 0x8080030C: nop

    func_800F15F8(rdram, ctx);
        goto after_16;
    // 0x8080030C: nop

    after_16:
    // 0x80800310: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800314: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800318: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8080031C: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800320: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800324: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800328: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080032C: mul.s       $f18, $f2, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80800330: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1224, 0X990) << 16);
    // 0x80800334: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80800338: addiu       $a1, $a1, 0x990
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1224, 0X990));
    // 0x8080033C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800340: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80800344: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80800348: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080034C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800350: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80800354: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80800358: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8080035C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80800360: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800364: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80800368: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080036C: bc1f        L_808004F8
    if (!c1cs) {
        // 0x80800370: swc1        $f10, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
            goto L_808004F8;
    }
    // 0x80800370: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x80800374: jal         0x800C4AF0
    // 0x80800378: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    func_800C4AF0(rdram, ctx);
        goto after_17;
    // 0x80800378: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    after_17:
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800380: jal         0x80102424
    // 0x80800384: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_18;
    // 0x80800384: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_18:
    // 0x80800388: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080038C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800390: addiu       $a0, $zero, 0x439
    ctx->r4 = ADD32(0, 0X439);
    // 0x80800394: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800398: addiu       $a2, $zero, 0x3E7
    ctx->r6 = ADD32(0, 0X3E7);
    // 0x8080039C: jal         0x80101180
    // 0x808003A0: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    func_80101180(rdram, ctx);
        goto after_19;
    // 0x808003A0: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    after_19:
    // 0x808003A4: b           L_808004FC
    // 0x808003A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004FC;
    // 0x808003A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003AC:
    // 0x808003AC: jal         0x800D9078
    // 0x808003B0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_20;
    // 0x808003B0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_20:
    // 0x808003B4: jal         0x800D8FF8
    // 0x808003B8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_21;
    // 0x808003B8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_21:
    // 0x808003BC: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x808003C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003C4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x808003C8: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808003CC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003D0: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x808003D4: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    // 0x808003D8: jal         0x800F12D4
    // 0x808003DC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F12D4(rdram, ctx);
        goto after_22;
    // 0x808003DC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_22:
    // 0x808003E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003E8: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x808003EC: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808003F0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003F4: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x808003F8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x808003FC: jal         0x800F12D4
    // 0x80800400: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_23;
    // 0x80800400: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_23:
    // 0x80800404: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800408: jal         0x80102FDC
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_24;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800410: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800414: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800418: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080041C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800420: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800424: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800428: jal         0x800F12D4
    // 0x8080042C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F12D4(rdram, ctx);
        goto after_25;
    // 0x8080042C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_25:
    // 0x80800430: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800438: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8080043C: jal         0x80089C98
    // 0x80800440: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_26;
    // 0x80800440: nop

    after_26:
    // 0x80800444: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800448: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080044C: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800450: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800454: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800458: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x8080045C: nop

    // 0x80800460: bc1fl       L_80800494
    if (!c1cs) {
        // 0x80800464: lwc1        $f8, 0x30($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
            goto L_80800494;
    }
    goto skip_2;
    // 0x80800464: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    skip_2:
    // 0x80800468: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080046C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800470: lwc1        $f12, 0x30($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800474: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800478: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8080047C: jal         0x800F15F8
    // 0x80800480: nop

    func_800F15F8(rdram, ctx);
        goto after_27;
    // 0x80800480: nop

    after_27:
    // 0x80800484: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80800488: jal         0x808007B0
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007B0_chmricecube(rdram, ctx);
        goto after_28;
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800490: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
L_80800494:
    // 0x80800494: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800498: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080049C: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x808004A0: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x808004A4: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x808004A8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x808004AC: beql        $t4, $zero, L_808004FC
    if (ctx->r12 == 0) {
        // 0x808004B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808004FC;
    }
    goto skip_3;
    // 0x808004B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x808004B4: jal         0x800DA544
    // 0x808004B8: addiu       $a0, $zero, 0x31B
    ctx->r4 = ADD32(0, 0X31B);
    func_800DA544(rdram, ctx);
        goto after_29;
    // 0x808004B8: addiu       $a0, $zero, 0x31B
    ctx->r4 = ADD32(0, 0X31B);
    after_29:
    // 0x808004BC: jal         0x80088830
    // 0x808004C0: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_30;
    // 0x808004C0: nop

    after_30:
    // 0x808004C4: b           L_808004FC
    // 0x808004C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004FC;
    // 0x808004C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004CC:
    // 0x808004CC: jal         0x80800850
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800850_chmricecube(rdram, ctx);
        goto after_31;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x808004D4: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004DC: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x808004E0: jal         0x80101DDC
    // 0x808004E4: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    func_80101DDC(rdram, ctx);
        goto after_32;
    // 0x808004E4: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    after_32:
    // 0x808004E8: beq         $v0, $zero, L_808004F8
    if (ctx->r2 == 0) {
        // 0x808004EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004F8;
    }
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F0: jal         0x80102424
    // 0x808004F4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_33;
    // 0x808004F4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_33:
L_808004F8:
    // 0x808004F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004FC:
    // 0x808004FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800500: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800504: jr          $ra
    // 0x80800508: nop

    return;
    // 0x80800508: nop

;}
RECOMP_FUNC void func_800CA5F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA5F8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CA5FC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800CA600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA608: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800CA60C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800CA610: jal         0x800EFA4C
    // 0x800CA614: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800CA614: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x800CA618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA61C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA620: jr          $ra
    // 0x800CA624: nop

    return;
    // 0x800CA624: nop

;}
RECOMP_FUNC void _idtwinkle_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E00: syscall     742
    recomp_syscall_handler(rdram, ctx, 0x80088E00);
    return;
    // 0x80088E04: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bsbshock_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007E0: jal         0x8009E704
    // 0x808007E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getNextState(rdram, ctx);
        goto after_0;
    // 0x808007E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808007E8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808007EC: beql        $v0, $at, L_80800800
    if (ctx->r2 == ctx->r1) {
        // 0x808007F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800800;
    }
    goto skip_0;
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808007F4: jal         0x8009BC6C
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800800:
    // 0x80800800: jal         0x800A0CE8
    // 0x80800804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CE8(rdram, ctx);
        goto after_2;
    // 0x80800804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080080C: jal         0x800A0CF4
    // 0x80800810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_3;
    // 0x80800810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800818: jal         0x80093300
    // 0x8080081C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093300(rdram, ctx);
        goto after_4;
    // 0x8080081C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800824: jal         0x8009C1B4
    // 0x80800828: lui         $a1, 0x42AE
    ctx->r5 = S32(0X42AE << 16);
    func_8009C1B4(rdram, ctx);
        goto after_5;
    // 0x80800828: lui         $a1, 0x42AE
    ctx->r5 = S32(0X42AE << 16);
    after_5:
    // 0x8080082C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800830: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800834: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800838: jr          $ra
    // 0x8080083C: nop

    return;
    // 0x8080083C: nop

;}
RECOMP_FUNC void func_800EB8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB8C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EB8C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EB8C8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800EB8CC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800EB8D0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800EB8D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800EB8D8: jal         0x800E9DCC
    // 0x800EB8DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800E9DCC(rdram, ctx);
        goto after_0;
    // 0x800EB8DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800EB8E0: beq         $v0, $zero, L_800EB9D4
    if (ctx->r2 == 0) {
        // 0x800EB8E4: lui         $s1, 0x8013
        ctx->r17 = S32(0X8013 << 16);
            goto L_800EB9D4;
    }
    // 0x800EB8E4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800EB8E8: addiu       $s1, $s1, 0x2EA0
    ctx->r17 = ADD32(ctx->r17, 0X2EA0);
    // 0x800EB8EC: lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X10);
    // 0x800EB8F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800EB8F4: beq         $v1, $at, L_800EB904
    if (ctx->r3 == ctx->r1) {
        // 0x800EB8F8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800EB904;
    }
    // 0x800EB8F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EB8FC: bne         $v1, $at, L_800EB9D4
    if (ctx->r3 != ctx->r1) {
        // 0x800EB900: nop
    
            goto L_800EB9D4;
    }
    // 0x800EB900: nop

L_800EB904:
    // 0x800EB904: jal         0x800E9E88
    // 0x800EB908: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800E9E88(rdram, ctx);
        goto after_1;
    // 0x800EB908: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x800EB90C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EB910: jal         0x800E9EB4
    // 0x800EB914: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800E9EB4(rdram, ctx);
        goto after_2;
    // 0x800EB914: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x800EB918: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800EB91C: beq         $at, $zero, L_800EB9D4
    if (ctx->r1 == 0) {
        // 0x800EB920: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800EB9D4;
    }
    // 0x800EB920: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800EB924: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
L_800EB928:
    // 0x800EB928: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x800EB92C: bnel        $t6, $zero, L_800EB9C8
    if (ctx->r14 != 0) {
        // 0x800EB930: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800EB9C8;
    }
    goto skip_0;
    // 0x800EB930: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x800EB934: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x800EB938: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x800EB93C: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    // 0x800EB940: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800EB944: subu        $v0, $t7, $t8
    ctx->r2 = SUB32(ctx->r15, ctx->r24);
    // 0x800EB948: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EB94C: subu        $v1, $t9, $t0
    ctx->r3 = SUB32(ctx->r25, ctx->r8);
    // 0x800EB950: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x800EB954: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x800EB958: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x800EB95C: sll         $t9, $a1, 30
    ctx->r25 = S32(ctx->r5 << 30);
    // 0x800EB960: subu        $a0, $t1, $t2
    ctx->r4 = SUB32(ctx->r9, ctx->r10);
    // 0x800EB964: mflo        $t3
    ctx->r11 = lo;
    // 0x800EB968: nop

    // 0x800EB96C: nop

    // 0x800EB970: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EB974: mflo        $t4
    ctx->r12 = lo;
    // 0x800EB978: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800EB97C: nop

    // 0x800EB980: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EB984: mflo        $t6
    ctx->r14 = lo;
    // 0x800EB988: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x800EB98C: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800EB990: beql        $at, $zero, L_800EB9C8
    if (ctx->r1 == 0) {
        // 0x800EB994: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800EB9C8;
    }
    goto skip_1;
    // 0x800EB994: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_1:
    // 0x800EB998: bgez        $t9, L_800EB9A8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800EB99C: lw          $v1, 0x10($s1)
        ctx->r3 = MEM_W(ctx->r17, 0X10);
            goto L_800EB9A8;
    }
    // 0x800EB99C: lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X10);
    // 0x800EB9A0: b           L_800EB9AC
    // 0x800EB9A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800EB9AC;
    // 0x800EB9A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800EB9A8:
    // 0x800EB9A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EB9AC:
    // 0x800EB9AC: bnel        $v0, $v1, L_800EB9C8
    if (ctx->r2 != ctx->r3) {
        // 0x800EB9B0: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800EB9C8;
    }
    goto skip_2;
    // 0x800EB9B0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_2:
    // 0x800EB9B4: sw          $a2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r6;
    // 0x800EB9B8: sw          $s3, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r19;
    // 0x800EB9BC: sw          $s0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r16;
    // 0x800EB9C0: sw          $v1, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r3;
    // 0x800EB9C4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_800EB9C8:
    // 0x800EB9C8: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
    // 0x800EB9CC: bnel        $at, $zero, L_800EB928
    if (ctx->r1 != 0) {
        // 0x800EB9D0: lw          $a1, 0x8($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X8);
            goto L_800EB928;
    }
    goto skip_3;
    // 0x800EB9D0: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    skip_3:
L_800EB9D4:
    // 0x800EB9D4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800EB9D8: addiu       $s1, $s1, 0x2EA0
    ctx->r17 = ADD32(ctx->r17, 0X2EA0);
    // 0x800EB9DC: jal         0x800E9DC4
    // 0x800EB9E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800E9DC4(rdram, ctx);
        goto after_3;
    // 0x800EB9E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x800EB9E4: beql        $v0, $zero, L_800EBB18
    if (ctx->r2 == 0) {
        // 0x800EB9E8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800EBB18;
    }
    goto skip_4;
    // 0x800EB9E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x800EB9EC: lw          $t0, 0x10($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X10);
    // 0x800EB9F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800EB9F4: bnel        $t0, $at, L_800EBB18
    if (ctx->r8 != ctx->r1) {
        // 0x800EB9F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800EBB18;
    }
    goto skip_5;
    // 0x800EB9F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x800EB9FC: jal         0x800E9D68
    // 0x800EBA00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800E9D68(rdram, ctx);
        goto after_4;
    // 0x800EBA00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x800EBA04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EBA08: jal         0x800E9D90
    // 0x800EBA0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800E9D90(rdram, ctx);
        goto after_5;
    // 0x800EBA0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x800EBA10: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800EBA14: beq         $at, $zero, L_800EBB14
    if (ctx->r1 == 0) {
        // 0x800EBA18: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800EBB14;
    }
    // 0x800EBA18: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800EBA1C: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
L_800EBA20:
    // 0x800EBA20: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    // 0x800EBA24: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800EBA28: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800EBA2C: subu        $v0, $t1, $t2
    ctx->r2 = SUB32(ctx->r9, ctx->r10);
    // 0x800EBA30: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EBA34: subu        $v1, $t3, $t4
    ctx->r3 = SUB32(ctx->r11, ctx->r12);
    // 0x800EBA38: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x800EBA3C: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x800EBA40: lw          $t1, 0xC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XC);
    // 0x800EBA44: subu        $a0, $t5, $t6
    ctx->r4 = SUB32(ctx->r13, ctx->r14);
    // 0x800EBA48: mflo        $t7
    ctx->r15 = lo;
    // 0x800EBA4C: nop

    // 0x800EBA50: nop

    // 0x800EBA54: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EBA58: mflo        $t8
    ctx->r24 = lo;
    // 0x800EBA5C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800EBA60: nop

    // 0x800EBA64: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EBA68: mflo        $t0
    ctx->r8 = lo;
    // 0x800EBA6C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x800EBA70: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800EBA74: beql        $at, $zero, L_800EBB08
    if (ctx->r1 == 0) {
        // 0x800EBA78: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800EBB08;
    }
    goto skip_6;
    // 0x800EBA78: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_6:
    // 0x800EBA7C: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x800EBA80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EBA84: beql        $v0, $zero, L_800EBAF4
    if (ctx->r2 == 0) {
        // 0x800EBA88: lw          $t2, 0x10($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X10);
            goto L_800EBAF4;
    }
    goto skip_7;
    // 0x800EBA88: lw          $t2, 0x10($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X10);
    skip_7:
    // 0x800EBA8C: jalr        $v0
    // 0x800EBA90: lw          $a1, 0x24($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X24);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x800EBA90: lw          $a1, 0x24($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X24);
    after_6:
    // 0x800EBA94: beql        $v0, $zero, L_800EBB08
    if (ctx->r2 == 0) {
        // 0x800EBA98: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800EBB08;
    }
    goto skip_8;
    // 0x800EBA98: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_8:
    // 0x800EBA9C: lh          $t2, 0x4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4);
    // 0x800EBAA0: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x800EBAA4: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x800EBAA8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800EBAAC: subu        $v0, $t2, $t3
    ctx->r2 = SUB32(ctx->r10, ctx->r11);
    // 0x800EBAB0: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EBAB4: subu        $v1, $t4, $t5
    ctx->r3 = SUB32(ctx->r12, ctx->r13);
    // 0x800EBAB8: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x800EBABC: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x800EBAC0: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    // 0x800EBAC4: mflo        $t8
    ctx->r24 = lo;
    // 0x800EBAC8: nop

    // 0x800EBACC: nop

    // 0x800EBAD0: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EBAD4: mflo        $t9
    ctx->r25 = lo;
    // 0x800EBAD8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800EBADC: nop

    // 0x800EBAE0: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EBAE4: mflo        $t1
    ctx->r9 = lo;
    // 0x800EBAE8: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x800EBAEC: nop

    // 0x800EBAF0: lw          $t2, 0x10($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X10);
L_800EBAF4:
    // 0x800EBAF4: sw          $a1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r5;
    // 0x800EBAF8: sw          $s3, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r19;
    // 0x800EBAFC: sw          $s0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r16;
    // 0x800EBB00: sw          $t2, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r10;
    // 0x800EBB04: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_800EBB08:
    // 0x800EBB08: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800EBB0C: bnel        $at, $zero, L_800EBA20
    if (ctx->r1 != 0) {
        // 0x800EBB10: lh          $t1, 0x4($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X4);
            goto L_800EBA20;
    }
    goto skip_9;
    // 0x800EBB10: lh          $t1, 0x4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4);
    skip_9:
L_800EBB14:
    // 0x800EBB14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800EBB18:
    // 0x800EBB18: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800EBB1C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800EBB20: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800EBB24: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800EBB28: jr          $ra
    // 0x800EBB2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800EBB2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
