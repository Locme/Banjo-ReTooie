#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800F48BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F48BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F48C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F48C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F48C8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F48CC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F48D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F48D4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800F48D8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800F48DC: jal         0x800F4200
    // 0x800F48E0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800F4200(rdram, ctx);
        goto after_0;
    // 0x800F48E0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F48E4: jal         0x800D8FF8
    // 0x800F48E8: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x800F48E8: nop

    after_1:
    // 0x800F48EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F48F0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800F48F4: jal         0x800EFA20
    // 0x800F48F8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800EFA20(rdram, ctx);
        goto after_2;
    // 0x800F48F8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x800F48FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800F4900: jal         0x800EF04C
    // 0x800F4904: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x800F4904: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x800F4908: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F490C: jal         0x800F4648
    // 0x800F4910: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F4648(rdram, ctx);
        goto after_4;
    // 0x800F4910: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x800F4914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4918: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800F491C: jr          $ra
    // 0x800F4920: nop

    return;
    // 0x800F4920: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A0F8: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A0F8);
    return;
    // 0x8008A0FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bafly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800020: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800024: jal         0x80095738
    // 0x80800028: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    baflag_isTrue(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_0:
    // 0x8080002C: beq         $v0, $zero, L_80800068
    if (ctx->r2 == 0) {
        // 0x80800030: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800068;
    }
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800038: jal         0x80084B28
    // 0x8080003C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    _baeggfire_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080003C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80800040: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800044: jal         0x800EF334
    // 0x80800048: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800EF334(rdram, ctx);
        goto after_2;
    // 0x80800048: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x8080004C: jal         0x800A4C48
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C48(rdram, ctx);
        goto after_3;
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800058: jal         0x800CA9D8
    // 0x8080005C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800CA9D8(rdram, ctx);
        goto after_4;
    // 0x8080005C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80800060: b           L_808000A0
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000A0;
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800068:
    // 0x80800068: jal         0x800A4C48
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C48(rdram, ctx);
        goto after_5;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800070: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800074: jal         0x800CA740
    // 0x80800078: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800CA740(rdram, ctx);
        goto after_6;
    // 0x80800078: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x8080007C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800080: jal         0x800EF334
    // 0x80800084: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800EF334(rdram, ctx);
        goto after_7;
    // 0x80800084: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_7:
    // 0x80800088: jal         0x800A4C48
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C48(rdram, ctx);
        goto after_8;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800094: jal         0x800CA9D8
    // 0x80800098: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800CA9D8(rdram, ctx);
        goto after_9;
    // 0x80800098: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_9:
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000A0:
    // 0x808000A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void func_80801194_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801194: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080119C: jal         0x80101080
    // 0x808011A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x808011A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011A4: jal         0x80106790
    // 0x808011A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808011A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808011AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808011B0: jal         0x800866B8
    // 0x808011B4: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808011B4: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_2:
    // 0x808011B8: jal         0x800DA544
    // 0x808011BC: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x808011BC: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    after_3:
    // 0x808011C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011C8: jr          $ra
    // 0x808011CC: nop

    return;
    // 0x808011CC: nop

;}
RECOMP_FUNC void bswalk_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801228: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080122C: jal         0x8009BF5C
    // 0x80801230: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_0;
    // 0x80801230: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x80801234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801238: jal         0x8009C4CC
    // 0x8080123C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_1;
    // 0x8080123C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80801240: jal         0x8008E0E8
    // 0x80801244: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E0E8(rdram, ctx);
        goto after_2;
    // 0x80801244: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801248: beq         $v0, $zero, L_80801258
    if (ctx->r2 == 0) {
        // 0x8080124C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801258;
    }
    // 0x8080124C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801250: jal         0x80084788
    // 0x80801254: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80801254: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
L_80801258:
    // 0x80801258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080125C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801260: jr          $ra
    // 0x80801264: nop

    return;
    // 0x80801264: nop

;}
RECOMP_FUNC void func_808000D8_chlightdemon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E0: jal         0x800F54E4
    // 0x808000E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808000E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808000EC: jal         0x800F581C
    // 0x808000F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F581C(rdram, ctx);
        goto after_1;
    // 0x808000F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808000F4: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x808000F8: bgez        $t6, L_80800108
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808000FC: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800108;
    }
    // 0x808000FC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800100: jal         0x800F796C
    // 0x80800104: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800F796C(rdram, ctx);
        goto after_2;
    // 0x80800104: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
L_80800108:
    // 0x80800108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080010C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void baswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000CC: jal         0x800919F4
    // 0x808000D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_held(rdram, ctx);
        goto after_0;
    // 0x808000D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x808000D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808000D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000DC: jal         0x800919F4
    // 0x808000E0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_held(rdram, ctx);
        goto after_1;
    // 0x808000E0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x808000E4: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x808000E8: jal         0x800C6E38
    // 0x808000EC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800C6E38(rdram, ctx);
        goto after_2;
    // 0x808000EC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x808000F0: beq         $v0, $zero, L_80800114
    if (ctx->r2 == 0) {
        // 0x808000F4: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80800114;
    }
    // 0x808000F4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x808000F8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808000FC: beq         $t6, $zero, L_80800114
    if (ctx->r14 == 0) {
        // 0x80800100: nop
    
            goto L_80800114;
    }
    // 0x80800100: nop

    // 0x80800104: beq         $v1, $zero, L_80800114
    if (ctx->r3 == 0) {
        // 0x80800108: nop
    
            goto L_80800114;
    }
    // 0x80800108: nop

    // 0x8080010C: b           L_80800134
    // 0x80800110: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800134;
    // 0x80800110: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800114:
    // 0x80800114: beq         $v1, $zero, L_80800124
    if (ctx->r3 == 0) {
        // 0x80800118: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80800124;
    }
    // 0x80800118: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8080011C: b           L_80800134
    // 0x80800120: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800134;
    // 0x80800120: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800124:
    // 0x80800124: beq         $t7, $zero, L_80800134
    if (ctx->r15 == 0) {
        // 0x80800128: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800134;
    }
    // 0x80800128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080012C: b           L_80800134
    // 0x80800130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800134;
    // 0x80800130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800134:
    // 0x80800134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080013C: jr          $ra
    // 0x80800140: nop

    return;
    // 0x80800140: nop

;}
RECOMP_FUNC void func_80017070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017070: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80017074: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80017078: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001707C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80017080: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80017084: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017088: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001708C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017090: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80017094: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80017098: lw          $v1, -0x5E68($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E68);
    // 0x8001709C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800170A0: bnel        $v1, $zero, L_800170B4
    if (ctx->r3 != 0) {
        // 0x800170A4: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_800170B4;
    }
    goto skip_0;
    // 0x800170A4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x800170A8: jr          $ra
    // 0x800170AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800170AC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800170B0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_800170B4:
    // 0x800170B4: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x800170B8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800170BC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800170C0: subu        $a0, $t0, $t9
    ctx->r4 = SUB32(ctx->r8, ctx->r25);
    // 0x800170C4: sllv        $t2, $t1, $a0
    ctx->r10 = S32(ctx->r9 << (ctx->r4 & 31));
    // 0x800170C8: srlv        $v0, $t2, $a0
    ctx->r2 = S32(U32(ctx->r10) >> (ctx->r4 & 31));
    // 0x800170CC: jr          $ra
    // 0x800170D0: nop

    return;
    // 0x800170D0: nop

;}
RECOMP_FUNC void func_800DF900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF900: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800DF904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DF908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF90C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800DF910: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DF914: jal         0x80018E1C
    // 0x800DF918: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    mlMtx_push_translation(rdram, ctx);
        goto after_0;
    // 0x800DF918: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_0:
    // 0x800DF91C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800DF920: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800DF924: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x800DF928: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800DF92C: jal         0x8001980C
    // 0x800DF930: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    func_8001980C(rdram, ctx);
        goto after_1;
    // 0x800DF930: lw          $a3, 0xC($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XC);
    after_1:
    // 0x800DF934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DF93C: jr          $ra
    // 0x800DF940: nop

    return;
    // 0x800DF940: nop

;}
RECOMP_FUNC void _chpickups_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085868: syscall     177
    recomp_syscall_handler(rdram, ctx, 0x80085868);
    return;
    // 0x8008586C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void chskeletonexplode_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CA0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800CA4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800CA8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80800CAC: jal         0x80100094
    // 0x80800CB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800CB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800CB4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CB8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800CBC: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80800CC0: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80800CC4: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x80800CC8: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80800CCC: slt         $at, $t9, $a3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80800CD0: beql        $at, $zero, L_80800CE0
    if (ctx->r1 == 0) {
        // 0x80800CD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800CE0;
    }
    goto skip_0;
    // 0x80800CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800CD8: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80800CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CE0:
    // 0x80800CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CE4: jr          $ra
    // 0x80800CE8: nop

    return;
    // 0x80800CE8: nop

;}
RECOMP_FUNC void func_800BEC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEC28: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BEC2C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BEC30: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BEC34: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BEC38: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BEC3C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BEC40: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEC44: jr          $ra
    // 0x800BEC48: lw          $v0, -0x7A30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7A30);
    return;
    // 0x800BEC48: lw          $v0, -0x7A30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7A30);
;}
RECOMP_FUNC void scradar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800938: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8080093C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800940: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800944: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80800948: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8080094C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80800950: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80800954: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800958: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8080095C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800960: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800964: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800968: jal         0x800A946C
    // 0x8080096C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    func_800A946C(rdram, ctx);
        goto after_0;
    // 0x8080096C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    after_0:
    // 0x80800970: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80800974: jal         0x80800768
    // 0x80800978: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800768_scradar(rdram, ctx);
        goto after_1;
    // 0x80800978: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8080097C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800980: bne         $v0, $at, L_8080098C
    if (ctx->r2 != ctx->r1) {
        // 0x80800984: lui         $s0, 0x8080
        ctx->r16 = S32(RELOC_HI16(3126, 0XE50) << 16);
            goto L_8080098C;
    }
    // 0x80800984: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(3126, 0XE50) << 16);
    // 0x80800988: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_8080098C:
    // 0x8080098C: blez        $fp, L_808009EC
    if (SIGNED(ctx->r30) <= 0) {
        // 0x80800990: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_808009EC;
    }
    // 0x80800990: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80800994: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(3126, 0XE3C) << 16);
    // 0x80800998: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(3126, 0XE30) << 16);
    // 0x8080099C: addiu       $s2, $s2, 0xE30
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(3126, 0XE30));
    // 0x808009A0: addiu       $s3, $s3, 0xE3C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(3126, 0XE3C));
    // 0x808009A4: addiu       $s0, $s0, 0xE50
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(3126, 0XE50));
    // 0x808009A8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_808009AC:
    // 0x808009AC: jal         0x80088390
    // 0x808009B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    _gcstatusDll_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x808009B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x808009B4: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x808009B8: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x808009BC: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x808009C0: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x808009C4: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x808009C8: sh          $s1, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r17;
    // 0x808009CC: sh          $zero, 0xE($s0)
    MEM_H(0XE, ctx->r16) = 0;
    // 0x808009D0: addu        $t1, $t0, $s4
    ctx->r9 = ADD32(ctx->r8, ctx->r20);
    // 0x808009D4: sh          $t8, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r24;
    // 0x808009D8: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x808009DC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x808009E0: addiu       $s0, $s0, 0xF0
    ctx->r16 = ADD32(ctx->r16, 0XF0);
    // 0x808009E4: bne         $s5, $fp, L_808009AC
    if (ctx->r21 != ctx->r30) {
        // 0x808009E8: sb          $t2, -0xE8($s0)
        MEM_B(-0XE8, ctx->r16) = ctx->r10;
            goto L_808009AC;
    }
    // 0x808009E8: sb          $t2, -0xE8($s0)
    MEM_B(-0XE8, ctx->r16) = ctx->r10;
L_808009EC:
    // 0x808009EC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808009F0: addiu       $s7, $zero, 0x60
    ctx->r23 = ADD32(0, 0X60);
    // 0x808009F4: addiu       $s6, $zero, 0xC0
    ctx->r22 = ADD32(0, 0XC0);
L_808009F8:
    // 0x808009F8: jal         0x800F6438
    // 0x808009FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800F6438(rdram, ctx);
        goto after_3;
    // 0x808009FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80800A00: beq         $v0, $zero, L_80800ABC
    if (ctx->r2 == 0) {
        // 0x80800A04: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800ABC;
    }
    // 0x80800A04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A08: jal         0x800A940C
    // 0x80800A0C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_800A940C(rdram, ctx);
        goto after_4;
    // 0x80800A0C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_4:
    // 0x80800A10: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800A14: jal         0x80088390
    // 0x80800A18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcstatusDll_entrypoint_16(rdram, ctx);
        goto after_5;
    // 0x80800A18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800A1C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800A20: jal         0x800F53D0
    // 0x80800A24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800F53D0(rdram, ctx);
        goto after_6;
    // 0x80800A24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80800A28: jal         0x80092258
    // 0x80800A2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80092258(rdram, ctx);
        goto after_7;
    // 0x80800A2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80800A30: blez        $fp, L_80800ABC
    if (SIGNED(ctx->r30) <= 0) {
        // 0x80800A34: andi        $s3, $v0, 0xFF
        ctx->r19 = ctx->r2 & 0XFF;
            goto L_80800ABC;
    }
    // 0x80800A34: andi        $s3, $v0, 0xFF
    ctx->r19 = ctx->r2 & 0XFF;
    // 0x80800A38: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(3126, 0XE50) << 16);
    // 0x80800A3C: addiu       $s0, $s0, 0xE50
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(3126, 0XE50));
L_80800A40:
    // 0x80800A40: jal         0x80088390
    // 0x80800A44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _gcstatusDll_entrypoint_16(rdram, ctx);
        goto after_8;
    // 0x80800A44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80800A48: bnel        $v0, $s4, L_80800A94
    if (ctx->r2 != ctx->r20) {
        // 0x80800A4C: lh          $v1, 0xE($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XE);
            goto L_80800A94;
    }
    goto skip_0;
    // 0x80800A4C: lh          $v1, 0xE($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE);
    skip_0:
    // 0x80800A50: bnel        $s1, $s5, L_80800A74
    if (ctx->r17 != ctx->r21) {
        // 0x80800A54: lh          $v1, 0xC($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XC);
            goto L_80800A74;
    }
    goto skip_1;
    // 0x80800A54: lh          $v1, 0xC($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XC);
    skip_1:
    // 0x80800A58: jal         0x800A9420
    // 0x80800A5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800A9420(rdram, ctx);
        goto after_9;
    // 0x80800A5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x80800A60: beq         $v0, $zero, L_80800A70
    if (ctx->r2 == 0) {
        // 0x80800A64: addiu       $v0, $s0, 0x10
        ctx->r2 = ADD32(ctx->r16, 0X10);
            goto L_80800A70;
    }
    // 0x80800A64: addiu       $v0, $s0, 0x10
    ctx->r2 = ADD32(ctx->r16, 0X10);
    // 0x80800A68: b           L_80800AAC
    // 0x80800A6C: sb          $s6, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = ctx->r22;
        goto L_80800AAC;
    // 0x80800A6C: sb          $s6, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = ctx->r22;
L_80800A70:
    // 0x80800A70: lh          $v1, 0xC($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XC);
L_80800A74:
    // 0x80800A74: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x80800A78: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x80800A7C: sh          $t4, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r12;
    // 0x80800A80: addu        $v0, $t3, $s0
    ctx->r2 = ADD32(ctx->r11, ctx->r16);
    // 0x80800A84: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80800A88: b           L_80800AAC
    // 0x80800A8C: sb          $s7, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r23;
        goto L_80800AAC;
    // 0x80800A8C: sb          $s7, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r23;
    // 0x80800A90: lh          $v1, 0xE($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE);
L_80800A94:
    // 0x80800A94: sll         $t5, $v1, 4
    ctx->r13 = S32(ctx->r3 << 4);
    // 0x80800A98: addu        $v0, $t5, $s0
    ctx->r2 = ADD32(ctx->r13, ctx->r16);
    // 0x80800A9C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80800AA0: sh          $t6, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r14;
    // 0x80800AA4: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    // 0x80800AA8: sb          $s3, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r19;
L_80800AAC:
    // 0x80800AAC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800AB0: addiu       $s0, $s0, 0xF0
    ctx->r16 = ADD32(ctx->r16, 0XF0);
    // 0x80800AB4: bne         $s1, $fp, L_80800A40
    if (ctx->r17 != ctx->r30) {
        // 0x80800AB8: sb          $s2, 0xD($v0)
        MEM_B(0XD, ctx->r2) = ctx->r18;
            goto L_80800A40;
    }
    // 0x80800AB8: sb          $s2, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r18;
L_80800ABC:
    // 0x80800ABC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800AC0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800AC4: bne         $s2, $at, L_808009F8
    if (ctx->r18 != ctx->r1) {
        // 0x80800AC8: nop
    
            goto L_808009F8;
    }
    // 0x80800AC8: nop

    // 0x80800ACC: blez        $fp, L_80800C1C
    if (SIGNED(ctx->r30) <= 0) {
        // 0x80800AD0: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_80800C1C;
    }
    // 0x80800AD0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80800AD4: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(3126, 0XE50) << 16);
    // 0x80800AD8: addiu       $s2, $s2, 0xE50
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(3126, 0XE50));
    // 0x80800ADC: addiu       $s7, $sp, 0x80
    ctx->r23 = ADD32(ctx->r29, 0X80);
    // 0x80800AE0: addiu       $s6, $sp, 0x84
    ctx->r22 = ADD32(ctx->r29, 0X84);
    // 0x80800AE4: addiu       $s4, $sp, 0x6C
    ctx->r20 = ADD32(ctx->r29, 0X6C);
L_80800AE8:
    // 0x80800AE8: addiu       $t7, $sp, 0x78
    ctx->r15 = ADD32(ctx->r29, 0X78);
    // 0x80800AEC: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x80800AF0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800AF4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800AF8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80800AFC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80800B00: jal         0x800A8A04
    // 0x80800B04: addiu       $a3, $sp, 0x7C
    ctx->r7 = ADD32(ctx->r29, 0X7C);
    func_800A8A04(rdram, ctx);
        goto after_10;
    // 0x80800B04: addiu       $a3, $sp, 0x7C
    ctx->r7 = ADD32(ctx->r29, 0X7C);
    after_10:
    // 0x80800B08: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80800B0C: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x80800B10: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800B14: addiu       $s0, $s2, 0x10
    ctx->r16 = ADD32(ctx->r18, 0X10);
    // 0x80800B18: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80800B1C: addiu       $t1, $t0, -0x19
    ctx->r9 = ADD32(ctx->r8, -0X19);
    // 0x80800B20: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80800B24: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x80800B28: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x80800B2C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80800B30: lh          $t8, 0xC($s2)
    ctx->r24 = MEM_H(ctx->r18, 0XC);
    // 0x80800B34: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80800B38: addiu       $t6, $t5, -0x13
    ctx->r14 = ADD32(ctx->r13, -0X13);
    // 0x80800B3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800B40: beq         $t8, $zero, L_80800C10
    if (ctx->r24 == 0) {
        // 0x80800B44: sw          $t7, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r15;
            goto L_80800C10;
    }
    // 0x80800B44: sw          $t7, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r15;
    // 0x80800B48: sh          $zero, 0x14($s2)
    MEM_H(0X14, ctx->r18) = 0;
    // 0x80800B4C: sh          $zero, 0x16($s2)
    MEM_H(0X16, ctx->r18) = 0;
    // 0x80800B50: sb          $zero, 0x1C($s2)
    MEM_B(0X1C, ctx->r18) = 0;
    // 0x80800B54: jal         0x800F5A00
    // 0x80800B58: lbu         $a0, 0x1D($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X1D);
    func_800F5A00(rdram, ctx);
        goto after_11;
    // 0x80800B58: lbu         $a0, 0x1D($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X1D);
    after_11:
    // 0x80800B5C: jal         0x800F5F24
    // 0x80800B60: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    func_800F5F24(rdram, ctx);
        goto after_12;
    // 0x80800B60: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    after_12:
    // 0x80800B64: lh          $t9, 0xC($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XC);
    // 0x80800B68: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800B6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800B70: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80800B74: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800B78: bne         $at, $zero, L_80800BC4
    if (ctx->r1 != 0) {
        // 0x80800B7C: add.s       $f20, $f0, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f4.fl;
            goto L_80800BC4;
    }
    // 0x80800B7C: add.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800B80: sll         $t0, $s0, 4
    ctx->r8 = S32(ctx->r16 << 4);
L_80800B84:
    // 0x80800B84: addu        $s1, $s2, $t0
    ctx->r17 = ADD32(ctx->r18, ctx->r8);
    // 0x80800B88: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80800B8C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800B90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B94: jal         0x808007D4
    // 0x80800B98: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_808007D4_scradar(rdram, ctx);
        goto after_13;
    // 0x80800B98: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_13:
    // 0x80800B9C: addiu       $a0, $s1, 0x8
    ctx->r4 = ADD32(ctx->r17, 0X8);
    // 0x80800BA0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800BA4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80800BA8: jal         0x8080074C
    // 0x80800BAC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_8080074C_scradar(rdram, ctx);
        goto after_14;
    // 0x80800BAC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_14:
    // 0x80800BB0: lh          $t1, 0xC($s3)
    ctx->r9 = MEM_H(ctx->r19, 0XC);
    // 0x80800BB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800BB8: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800BBC: bnel        $at, $zero, L_80800B84
    if (ctx->r1 != 0) {
        // 0x80800BC0: sll         $t0, $s0, 4
        ctx->r8 = S32(ctx->r16 << 4);
            goto L_80800B84;
    }
    goto skip_2;
    // 0x80800BC0: sll         $t0, $s0, 4
    ctx->r8 = S32(ctx->r16 << 4);
    skip_2:
L_80800BC4:
    // 0x80800BC4: lh          $t2, 0xE($s2)
    ctx->r10 = MEM_H(ctx->r18, 0XE);
    // 0x80800BC8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800BCC: blez        $t2, L_80800C10
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80800BD0: sll         $t3, $s0, 4
        ctx->r11 = S32(ctx->r16 << 4);
            goto L_80800C10;
    }
    // 0x80800BD0: sll         $t3, $s0, 4
    ctx->r11 = S32(ctx->r16 << 4);
L_80800BD4:
    // 0x80800BD4: addu        $s1, $s2, $t3
    ctx->r17 = ADD32(ctx->r18, ctx->r11);
    // 0x80800BD8: addiu       $a0, $s1, 0x78
    ctx->r4 = ADD32(ctx->r17, 0X78);
    // 0x80800BDC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800BE0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80800BE4: jal         0x8080074C
    // 0x80800BE8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8080074C_scradar(rdram, ctx);
        goto after_15;
    // 0x80800BE8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_15:
    // 0x80800BEC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800BF0: addiu       $a0, $s1, 0x70
    ctx->r4 = ADD32(ctx->r17, 0X70);
    // 0x80800BF4: jal         0x808007D4
    // 0x80800BF8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_808007D4_scradar(rdram, ctx);
        goto after_16;
    // 0x80800BF8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_16:
    // 0x80800BFC: lh          $t4, 0xE($s3)
    ctx->r12 = MEM_H(ctx->r19, 0XE);
    // 0x80800C00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800C04: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80800C08: bnel        $at, $zero, L_80800BD4
    if (ctx->r1 != 0) {
        // 0x80800C0C: sll         $t3, $s0, 4
        ctx->r11 = S32(ctx->r16 << 4);
            goto L_80800BD4;
    }
    goto skip_3;
    // 0x80800C0C: sll         $t3, $s0, 4
    ctx->r11 = S32(ctx->r16 << 4);
    skip_3:
L_80800C10:
    // 0x80800C10: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80800C14: bne         $s5, $fp, L_80800AE8
    if (ctx->r21 != ctx->r30) {
        // 0x80800C18: addiu       $s2, $s2, 0xF0
        ctx->r18 = ADD32(ctx->r18, 0XF0);
            goto L_80800AE8;
    }
    // 0x80800C18: addiu       $s2, $s2, 0xF0
    ctx->r18 = ADD32(ctx->r18, 0XF0);
L_80800C1C:
    // 0x80800C1C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80800C20: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800C24: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800C28: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C2C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800C30: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800C34: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800C38: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80800C3C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80800C40: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80800C44: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80800C48: jr          $ra
    // 0x80800C4C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80800C4C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void sucoaster_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801004: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080100C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801010: sb          $a2, 0x1A($sp)
    MEM_B(0X1A, ctx->r29) = ctx->r6;
    // 0x80801014: sh          $a1, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r5;
    // 0x80801018: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080101C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80801020: jal         0x8010108C
    // 0x80801024: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    func_8010108C(rdram, ctx);
        goto after_0;
    // 0x80801024: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    after_0:
    // 0x80801028: blez        $v0, L_80801040
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080102C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801040;
    }
    // 0x8080102C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801030: jal         0x80801054
    // 0x80801034: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    sucoaster_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80801034: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80801038: b           L_80801044
    // 0x8080103C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801044;
    // 0x8080103C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801040:
    // 0x80801040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801044:
    // 0x80801044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801048: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080104C: jr          $ra
    // 0x80801050: nop

    return;
    // 0x80801050: nop

;}
RECOMP_FUNC void _badata_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084640: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084640);
    return;
    // 0x80084644: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801A5C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A64: jal         0x8080187C
    // 0x80801A68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080187C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80801A68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801A6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801A70: jal         0x800A3544
    // 0x80801A74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A3544(rdram, ctx);
        goto after_1;
    // 0x80801A74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801A78: jal         0x8080179C
    // 0x80801A7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsfirstp_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80801A7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801A80: jal         0x8080175C
    // 0x80801A84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080175C_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80801A84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80801A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A90: jr          $ra
    // 0x80801A94: nop

    return;
    // 0x80801A94: nop

;}
RECOMP_FUNC void _chintrochar_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086CA0: syscall     440
    recomp_syscall_handler(rdram, ctx, 0x80086CA0);
    return;
    // 0x80086CA4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800734_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800734: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800738: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080073C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800740: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800744: jal         0x800DA298
    // 0x80800748: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800748: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    after_0:
    // 0x8080074C: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800750: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800754: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800758: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080075C: bne         $t7, $at, L_808007C8
    if (ctx->r15 != ctx->r1) {
        // 0x80800760: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007C8;
    }
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800764: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1624, 0XCA0) << 16);
    // 0x80800768: addiu       $a3, $a3, 0xCA0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1624, 0XCA0));
    // 0x8080076C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800770: jal         0x80089D50
    // 0x80800774: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800774: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800778: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1624, 0XC88) << 16);
    // 0x8080077C: addiu       $t8, $t8, 0xC88
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1624, 0XC88));
    // 0x80800780: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80800784: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800788: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1624, 0XC94) << 16);
    // 0x8080078C: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x80800790: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80800794: addiu       $t2, $t2, 0xC94
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1624, 0XC94));
    // 0x80800798: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8080079C: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x808007A0: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x808007A4: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x808007A8: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x808007AC: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x808007B0: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x808007B4: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x808007B8: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x808007BC: jal         0x8008FA94
    // 0x808007C0: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    func_8008FA94(rdram, ctx);
        goto after_2;
    // 0x808007C0: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    after_2:
    // 0x808007C4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
L_808007C8:
    // 0x808007C8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808007CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007D0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808007D4: beq         $t6, $at, L_808007EC
    if (ctx->r14 == ctx->r1) {
        // 0x808007D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808007EC;
    }
    // 0x808007D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007DC: beq         $t6, $at, L_80800804
    if (ctx->r14 == ctx->r1) {
        // 0x808007E0: nop
    
            goto L_80800804;
    }
    // 0x808007E0: nop

    // 0x808007E4: b           L_80800828
    // 0x808007E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800828;
    // 0x808007E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007EC:
    // 0x808007EC: beq         $a2, $zero, L_80800824
    if (ctx->r6 == 0) {
        // 0x808007F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800824;
    }
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F4: jal         0x80101FDC
    // 0x808007F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x808007F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808007FC: b           L_80800828
    // 0x80800800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800828;
    // 0x80800800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800804:
    // 0x80800804: bne         $a2, $zero, L_80800814
    if (ctx->r6 != 0) {
        // 0x80800808: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800814;
    }
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080080C: jal         0x80101FDC
    // 0x80800810: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800810: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_80800814:
    // 0x80800814: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800818: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8080081C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800820: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
L_80800824:
    // 0x80800824: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800828:
    // 0x80800828: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080082C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800830: jr          $ra
    // 0x80800834: nop

    return;
    // 0x80800834: nop

;}
RECOMP_FUNC void func_800E1354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1354: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800E1358: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800E135C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E1360: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E1364: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800E1368: lbu         $v0, -0x2FFC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2FFC);
    // 0x800E136C: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x800E1370: jr          $ra
    // 0x800E1374: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
    return;
    // 0x800E1374: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
;}
RECOMP_FUNC void _bsclimb_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F00: syscall     34
    recomp_syscall_handler(rdram, ctx, 0x80082F00);
    return;
    // 0x80082F04: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_808010EC_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808010F0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1640, 0X1470) << 16);
    // 0x808010F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808010F8: addiu       $t6, $t6, 0x1470
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1640, 0X1470));
    // 0x808010FC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1640, 0X1464) << 16);
    // 0x80801100: addiu       $a0, $a0, 0x1464
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1640, 0X1464));
    // 0x80801104: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080110C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801110: jal         0x800BBCB8
    // 0x80801114: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80801114: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80801118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080111C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801120: jr          $ra
    // 0x80801124: nop

    return;
    // 0x80801124: nop

;}
RECOMP_FUNC void func_800E99E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E99E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E99E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E99E8: jal         0x800E9804
    // 0x800E99EC: nop

    func_800E9804(rdram, ctx);
        goto after_0;
    // 0x800E99EC: nop

    after_0:
    // 0x800E99F0: lbu         $t7, 0xB($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XB);
    // 0x800E99F4: ori         $t9, $t7, 0x1
    ctx->r25 = ctx->r15 | 0X1;
    // 0x800E99F8: andi        $t1, $t9, 0xF7
    ctx->r9 = ctx->r25 & 0XF7;
    // 0x800E99FC: sb          $t9, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r25;
    // 0x800E9A00: andi        $t4, $t1, 0xFB
    ctx->r12 = ctx->r9 & 0XFB;
    // 0x800E9A04: sb          $t1, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r9;
    // 0x800E9A08: sb          $t4, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r12;
    // 0x800E9A0C: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x800E9A10: sb          $t5, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r13;
    // 0x800E9A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9A1C: jr          $ra
    // 0x800E9A20: nop

    return;
    // 0x800E9A20: nop

;}
RECOMP_FUNC void _badrone_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847F8: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800847F8);
    return;
    // 0x800847FC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800CD6B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD6B4: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800CD6B8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800CD6BC: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800CD6C0: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800CD6C4: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800CD6C8: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800CD6CC: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800CD6D0: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800CD6D4: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800CD6D8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800CD6DC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800CD6E0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800CD6E4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800CD6E8: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x800CD6EC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800CD6F0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800CD6F4: beq         $v0, $zero, L_800CD70C
    if (ctx->r2 == 0) {
        // 0x800CD6F8: or          $s7, $a3, $zero
        ctx->r23 = ctx->r7 | 0;
            goto L_800CD70C;
    }
    // 0x800CD6F8: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x800CD6FC: jalr        $v0
    // 0x800CD700: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800CD700: nop

    after_0:
    // 0x800CD704: b           L_800CD710
    // 0x800CD708: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
        goto L_800CD710;
    // 0x800CD708: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_800CD70C:
    // 0x800CD70C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800CD710:
    // 0x800CD710: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x800CD714: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CD718: jal         0x800EE7F8
    // 0x800CD71C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800CD71C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800CD720: lw          $s5, 0x98($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X98);
    // 0x800CD724: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800CD728: addiu       $s6, $sp, 0x68
    ctx->r22 = ADD32(ctx->r29, 0X68);
    // 0x800CD72C: blez        $s5, L_800CD7E8
    if (SIGNED(ctx->r21) <= 0) {
        // 0x800CD730: addiu       $s3, $sp, 0x54
        ctx->r19 = ADD32(ctx->r29, 0X54);
            goto L_800CD7E8;
    }
    // 0x800CD730: addiu       $s3, $sp, 0x54
    ctx->r19 = ADD32(ctx->r29, 0X54);
L_800CD734:
    // 0x800CD734: beq         $s4, $zero, L_800CD798
    if (ctx->r20 == 0) {
        // 0x800CD738: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800CD798;
    }
    // 0x800CD738: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CD73C: lw          $v0, 0xC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XC);
    // 0x800CD740: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CD744: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800CD748: beq         $v0, $zero, L_800CD798
    if (ctx->r2 == 0) {
        // 0x800CD74C: nop
    
            goto L_800CD798;
    }
    // 0x800CD74C: nop

    // 0x800CD750: lw          $t6, 0x18($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X18);
    // 0x800CD754: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800CD758: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CD75C: sll         $t7, $t6, 27
    ctx->r15 = S32(ctx->r14 << 27);
    // 0x800CD760: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800CD764: jalr        $v0
    // 0x800CD768: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x800CD768: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x800CD76C: beql        $v0, $zero, L_800CD7D4
    if (ctx->r2 == 0) {
        // 0x800CD770: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800CD7D4;
    }
    goto skip_0;
    // 0x800CD770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x800CD774: lbu         $t2, 0x19($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X19);
    // 0x800CD778: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
    // 0x800CD77C: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x800CD780: andi        $t1, $t0, 0x1E
    ctx->r9 = ctx->r8 & 0X1E;
    // 0x800CD784: andi        $t3, $t2, 0xFFE1
    ctx->r11 = ctx->r10 & 0XFFE1;
    // 0x800CD788: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x800CD78C: sb          $t4, 0x19($s2)
    MEM_B(0X19, ctx->r18) = ctx->r12;
    // 0x800CD790: b           L_800CD7EC
    // 0x800CD794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800CD7EC;
    // 0x800CD794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CD798:
    // 0x800CD798: jal         0x800EC75C
    // 0x800CD79C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EC75C(rdram, ctx);
        goto after_3;
    // 0x800CD79C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x800CD7A0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800CD7A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CD7A8: jal         0x800EEB40
    // 0x800CD7AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEB40(rdram, ctx);
        goto after_4;
    // 0x800CD7AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x800CD7B0: add.s       $f2, $f20, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x800CD7B4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800CD7B8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800CD7BC: nop

    // 0x800CD7C0: bc1fl       L_800CD7D4
    if (!c1cs) {
        // 0x800CD7C4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800CD7D4;
    }
    goto skip_1;
    // 0x800CD7C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x800CD7C8: b           L_800CD7EC
    // 0x800CD7CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800CD7EC;
    // 0x800CD7CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CD7D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800CD7D4:
    // 0x800CD7D4: jal         0x800EF04C
    // 0x800CD7D8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x800CD7D8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_5:
    // 0x800CD7DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800CD7E0: bne         $s0, $s5, L_800CD734
    if (ctx->r16 != ctx->r21) {
        // 0x800CD7E4: nop
    
            goto L_800CD734;
    }
    // 0x800CD7E4: nop

L_800CD7E8:
    // 0x800CD7E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CD7EC:
    // 0x800CD7EC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800CD7F0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800CD7F4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800CD7F8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800CD7FC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800CD800: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800CD804: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800CD808: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x800CD80C: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x800CD810: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x800CD814: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x800CD818: jr          $ra
    // 0x800CD81C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800CD81C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80800000_chcaptainblubber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80800010: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800014: bltzl       $t9, L_8080006C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080006C;
    }
    goto skip_0;
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080001C: jal         0x8008F8B0
    // 0x80800020: nop

    func_8008F8B0(rdram, ctx);
        goto after_0;
    // 0x80800020: nop

    after_0:
    // 0x80800024: jal         0x8008F8D8
    // 0x80800028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8080002C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800034: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80800038: jal         0x8008F904
    // 0x8080003C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    func_8008F904(rdram, ctx);
        goto after_2;
    // 0x8080003C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_2:
    // 0x80800040: jal         0x8008F938
    // 0x80800044: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F938(rdram, ctx);
        goto after_3;
    // 0x80800044: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800048: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2228, 0X16C0) << 16);
    // 0x8080004C: addiu       $a0, $a0, 0x16C0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2228, 0X16C0));
    // 0x80800050: jal         0x8008F990
    // 0x80800054: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    func_8008F990(rdram, ctx);
        goto after_4;
    // 0x80800054: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_4:
    // 0x80800058: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8080005C: lbu         $t3, 0x65($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X65);
    // 0x80800060: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x80800064: sb          $t4, 0x65($t1)
    MEM_B(0X65, ctx->r9) = ctx->r12;
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080006C:
    // 0x8080006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void chmrtannoy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: addiu       $a0, $zero, 0x3E9
    ctx->r4 = ADD32(0, 0X3E9);
    // 0x8080000C: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x80800010: jal         0x800C3FC0
    // 0x80800014: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    func_800C3FC0(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
    after_0:
    // 0x80800018: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1660, 0X50) << 16);
    // 0x8080001C: lui         $a2, 0x3F14
    ctx->r6 = S32(0X3F14 << 16);
    // 0x80800020: ori         $a2, $a2, 0x7AE1
    ctx->r6 = ctx->r6 | 0X7AE1;
    // 0x80800024: lwc1        $f12, 0x50($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1660, 0X50));
    // 0x80800028: addiu       $a1, $zero, 0x3E9
    ctx->r5 = ADD32(0, 0X3E9);
    // 0x8080002C: jal         0x800C9BB4
    // 0x80800030: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_800C9BB4(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_1:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void func_80800854_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800854: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800858: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080085C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800860: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800864: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800868: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8080086C: jal         0x80110024
    // 0x80800870: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80110024(rdram, ctx);
        goto after_0;
    // 0x80800870: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800874: lh          $a3, 0x58($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X58);
    // 0x80800878: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080087C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800880: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800884: jal         0x800894E8
    // 0x80800888: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    _ncpod_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800888: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_1:
    // 0x8080088C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800890: bne         $v0, $at, L_808008A0
    if (ctx->r2 != ctx->r1) {
        // 0x80800894: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808008A0;
    }
    // 0x80800894: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800898: b           L_80800930
    // 0x8080089C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80800930;
    // 0x8080089C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_808008A0:
    // 0x808008A0: lbu         $v1, 0x60($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X60);
    // 0x808008A4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808008A8: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x808008AC: beq         $v1, $at, L_808008CC
    if (ctx->r3 == ctx->r1) {
        // 0x808008B0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_808008CC;
    }
    // 0x808008B0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808008B4: beq         $v1, $at, L_808008CC
    if (ctx->r3 == ctx->r1) {
        // 0x808008B8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_808008CC;
    }
    // 0x808008B8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808008BC: beql        $v1, $at, L_808008EC
    if (ctx->r3 == ctx->r1) {
        // 0x808008C0: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_808008EC;
    }
    goto skip_0;
    // 0x808008C0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808008C4: b           L_808008EC
    // 0x808008C8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
        goto L_808008EC;
    // 0x808008C8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_808008CC:
    // 0x808008CC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x808008D0: jal         0x8001B798
    // 0x808008D4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_8001B798(rdram, ctx);
        goto after_2;
    // 0x808008D4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_2:
    // 0x808008D8: jal         0x80089DB0
    // 0x808008DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suspline_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x808008DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808008E0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808008E4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808008E8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_808008EC:
    // 0x808008EC: beql        $t6, $zero, L_80800930
    if (ctx->r14 == 0) {
        // 0x808008F0: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80800930;
    }
    goto skip_1;
    // 0x808008F0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_1:
    // 0x808008F4: jal         0x80110024
    // 0x808008F8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80110024(rdram, ctx);
        goto after_4;
    // 0x808008F8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x808008FC: lh          $a3, 0x58($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X58);
    // 0x80800900: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800904: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800908: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080090C: jal         0x800894E8
    // 0x80800910: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    _ncpod_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800910: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_5:
    // 0x80800914: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800918: bne         $v0, $at, L_80800928
    if (ctx->r2 != ctx->r1) {
        // 0x8080091C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800928;
    }
    // 0x8080091C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800920: b           L_80800930
    // 0x80800924: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_80800930;
    // 0x80800924: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80800928:
    // 0x80800928: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x8080092C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80800930:
    // 0x80800930: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800934: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800938: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080093C: jr          $ra
    // 0x80800940: nop

    return;
    // 0x80800940: nop

;}
RECOMP_FUNC void func_800B81CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B81CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B81D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B81D4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B81D8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B81DC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800B81E0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800B81E4: jal         0x800B8148
    // 0x800B81E8: addiu       $a0, $sp, 0x47
    ctx->r4 = ADD32(ctx->r29, 0X47);
    func_800B8148(rdram, ctx);
        goto after_0;
    // 0x800B81E8: addiu       $a0, $sp, 0x47
    ctx->r4 = ADD32(ctx->r29, 0X47);
    after_0:
    // 0x800B81EC: bne         $v0, $zero, L_800B81FC
    if (ctx->r2 != 0) {
        // 0x800B81F0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800B81FC;
    }
    // 0x800B81F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B81F4: b           L_800B8C40
    // 0x800B81F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B8C40;
    // 0x800B81F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B81FC:
    // 0x800B81FC: lbu         $a1, 0x47($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X47);
    // 0x800B8200: jal         0x800B0D6C
    // 0x800B8204: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    func_800B0D6C(rdram, ctx);
        goto after_1;
    // 0x800B8204: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_1:
    // 0x800B8208: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800B820C: jal         0x800B0D60
    // 0x800B8210: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_800B0D60(rdram, ctx);
        goto after_2;
    // 0x800B8210: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x800B8214: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800B8218: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B821C: addiu       $t2, $t2, -0x7D40
    ctx->r10 = ADD32(ctx->r10, -0X7D40);
    // 0x800B8220: lw          $a0, 0x10($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X10);
    // 0x800B8224: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800B8228: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800B822C: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x800B8230: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x800B8234: bne         $a0, $at, L_800B8380
    if (ctx->r4 != ctx->r1) {
        // 0x800B8238: addu        $t0, $v0, $t6
        ctx->r8 = ADD32(ctx->r2, ctx->r14);
            goto L_800B8380;
    }
    // 0x800B8238: addu        $t0, $v0, $t6
    ctx->r8 = ADD32(ctx->r2, ctx->r14);
    // 0x800B823C: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800B8240: lui         $at, 0xFD18
    ctx->r1 = S32(0XFD18 << 16);
    // 0x800B8244: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B8248: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B824C: andi        $t3, $t9, 0xFFF
    ctx->r11 = ctx->r25 & 0XFFF;
    // 0x800B8250: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800B8254: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8258: addu        $t5, $t0, $at
    ctx->r13 = ADD32(ctx->r8, ctx->r1);
    // 0x800B825C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B8260: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B8264: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x800B8268: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B826C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B8270: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800B8274: addiu       $t8, $t7, 0x7
    ctx->r24 = ADD32(ctx->r15, 0X7);
    // 0x800B8278: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800B827C: andi        $t3, $t9, 0x1FF
    ctx->r11 = ctx->r25 & 0X1FF;
    // 0x800B8280: lui         $t1, 0xF518
    ctx->r9 = S32(0XF518 << 16);
    // 0x800B8284: sll         $t4, $t3, 9
    ctx->r12 = S32(ctx->r11 << 9);
    // 0x800B8288: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x800B828C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8290: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B8294: or          $t5, $t4, $t1
    ctx->r13 = ctx->r12 | ctx->r9;
    // 0x800B8298: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B829C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B82A0: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800B82A4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B82A8: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800B82AC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B82B0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B82B4: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B82B8: lui         $t8, 0xF400
    ctx->r24 = S32(0XF400 << 16);
    // 0x800B82BC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800B82C0: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x800B82C4: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x800B82C8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B82CC: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x800B82D0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B82D4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B82D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B82DC: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x800B82E0: andi        $t3, $t9, 0xFFF
    ctx->r11 = ctx->r25 & 0XFFF;
    // 0x800B82E4: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x800B82E8: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800B82EC: or          $t5, $t6, $t4
    ctx->r13 = ctx->r14 | ctx->r12;
    // 0x800B82F0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B82F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B82F8: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x800B82FC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B8300: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B8304: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B8308: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x800B830C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8310: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B8314: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B8318: addiu       $t3, $t9, 0x7
    ctx->r11 = ADD32(ctx->r25, 0X7);
    // 0x800B831C: sra         $t6, $t3, 3
    ctx->r14 = S32(SIGNED(ctx->r11) >> 3);
    // 0x800B8320: andi        $t4, $t6, 0x1FF
    ctx->r12 = ctx->r14 & 0X1FF;
    // 0x800B8324: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x800B8328: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x800B832C: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800B8330: or          $t7, $t5, $t1
    ctx->r15 = ctx->r13 | ctx->r9;
    // 0x800B8334: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8338: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800B833C: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800B8340: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B8344: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800B8348: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800B834C: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x800B8350: lbu         $t3, 0x3($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X3);
    // 0x800B8354: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8358: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B835C: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x800B8360: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x800B8364: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800B8368: andi        $t3, $t9, 0xFFF
    ctx->r11 = ctx->r25 & 0XFFF;
    // 0x800B836C: sll         $t6, $t3, 12
    ctx->r14 = S32(ctx->r11 << 12);
    // 0x800B8370: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x800B8374: or          $t4, $t5, $t6
    ctx->r12 = ctx->r13 | ctx->r14;
    // 0x800B8378: b           L_800B88B0
    // 0x800B837C: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
        goto L_800B88B0;
    // 0x800B837C: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
L_800B8380:
    // 0x800B8380: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x800B8384: bne         $a0, $at, L_800B84CC
    if (ctx->r4 != ctx->r1) {
        // 0x800B8388: lui         $t1, 0xF570
        ctx->r9 = S32(0XF570 << 16);
            goto L_800B84CC;
    }
    // 0x800B8388: lui         $t1, 0xF570
    ctx->r9 = S32(0XF570 << 16);
    // 0x800B838C: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x800B8390: lui         $at, 0xFD70
    ctx->r1 = S32(0XFD70 << 16);
    // 0x800B8394: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B8398: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B839C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B83A0: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x800B83A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B83A8: addu        $t5, $t0, $at
    ctx->r13 = ADD32(ctx->r8, ctx->r1);
    // 0x800B83AC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B83B0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800B83B4: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x800B83B8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B83BC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B83C0: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x800B83C4: addiu       $t7, $t4, 0x7
    ctx->r15 = ADD32(ctx->r12, 0X7);
    // 0x800B83C8: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800B83CC: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800B83D0: sll         $t3, $t9, 9
    ctx->r11 = S32(ctx->r25 << 9);
    // 0x800B83D4: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x800B83D8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B83DC: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B83E0: or          $t5, $t3, $t1
    ctx->r13 = ctx->r11 | ctx->r9;
    // 0x800B83E4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B83E8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B83EC: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800B83F0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B83F4: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x800B83F8: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800B83FC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B8400: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B8404: lui         $t7, 0xF400
    ctx->r15 = S32(0XF400 << 16);
    // 0x800B8408: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800B840C: lbu         $t8, 0x3($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X3);
    // 0x800B8410: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x800B8414: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B8418: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B841C: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x800B8420: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x800B8424: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B8428: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x800B842C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B8430: sll         $t3, $t9, 12
    ctx->r11 = S32(ctx->r25 << 12);
    // 0x800B8434: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800B8438: or          $t5, $t6, $t3
    ctx->r13 = ctx->r14 | ctx->r11;
    // 0x800B843C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8440: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B8444: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x800B8448: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x800B844C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B8450: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B8454: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x800B8458: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B845C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B8460: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B8464: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800B8468: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800B846C: andi        $t3, $t6, 0x1FF
    ctx->r11 = ctx->r14 & 0X1FF;
    // 0x800B8470: sll         $t5, $t3, 9
    ctx->r13 = S32(ctx->r11 << 9);
    // 0x800B8474: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x800B8478: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800B847C: or          $t4, $t5, $t1
    ctx->r12 = ctx->r13 | ctx->r9;
    // 0x800B8480: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8484: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B8488: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800B848C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B8490: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800B8494: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800B8498: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x800B849C: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x800B84A0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B84A4: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x800B84A8: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800B84AC: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x800B84B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B84B4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B84B8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800B84BC: andi        $t5, $t3, 0xFFF
    ctx->r13 = ctx->r11 & 0XFFF;
    // 0x800B84C0: or          $t3, $t5, $t6
    ctx->r11 = ctx->r13 | ctx->r14;
    // 0x800B84C4: b           L_800B88B0
    // 0x800B84C8: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
        goto L_800B88B0;
    // 0x800B84C8: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
L_800B84CC:
    // 0x800B84CC: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x800B84D0: bne         $a0, $at, L_800B8610
    if (ctx->r4 != ctx->r1) {
        // 0x800B84D4: lui         $t1, 0xF568
        ctx->r9 = S32(0XF568 << 16);
            goto L_800B8610;
    }
    // 0x800B84D4: lui         $t1, 0xF568
    ctx->r9 = S32(0XF568 << 16);
    // 0x800B84D8: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x800B84DC: lui         $at, 0xFD68
    ctx->r1 = S32(0XFD68 << 16);
    // 0x800B84E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B84E4: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x800B84E8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B84EC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800B84F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B84F4: addu        $t5, $t0, $at
    ctx->r13 = ADD32(ctx->r8, ctx->r1);
    // 0x800B84F8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800B84FC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B8500: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x800B8504: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8508: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B850C: addiu       $t3, $t6, 0x7
    ctx->r11 = ADD32(ctx->r14, 0X7);
    // 0x800B8510: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x800B8514: andi        $t7, $t4, 0x1FF
    ctx->r15 = ctx->r12 & 0X1FF;
    // 0x800B8518: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x800B851C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8520: lui         $t5, 0x708
    ctx->r13 = S32(0X708 << 16);
    // 0x800B8524: ori         $t5, $t5, 0x200
    ctx->r13 = ctx->r13 | 0X200;
    // 0x800B8528: or          $t9, $t8, $t1
    ctx->r25 = ctx->r24 | ctx->r9;
    // 0x800B852C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B8530: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B8534: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x800B8538: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B853C: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800B8540: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800B8544: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B8548: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B854C: lui         $t3, 0xF400
    ctx->r11 = S32(0XF400 << 16);
    // 0x800B8550: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x800B8554: lbu         $t4, 0x3($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X3);
    // 0x800B8558: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x800B855C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B8560: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x800B8564: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B8568: addiu       $t3, $t6, -0x1
    ctx->r11 = ADD32(ctx->r14, -0X1);
    // 0x800B856C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B8570: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800B8574: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x800B8578: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800B857C: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x800B8580: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x800B8584: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8588: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B858C: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800B8590: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800B8594: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B8598: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B859C: lbu         $t3, 0x2($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X2);
    // 0x800B85A0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B85A4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B85A8: addiu       $t4, $t3, 0x7
    ctx->r12 = ADD32(ctx->r11, 0X7);
    // 0x800B85AC: sra         $t7, $t4, 3
    ctx->r15 = S32(SIGNED(ctx->r12) >> 3);
    // 0x800B85B0: andi        $t5, $t7, 0x1FF
    ctx->r13 = ctx->r15 & 0X1FF;
    // 0x800B85B4: sll         $t8, $t5, 9
    ctx->r24 = S32(ctx->r13 << 9);
    // 0x800B85B8: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800B85BC: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800B85C0: or          $t9, $t8, $t1
    ctx->r25 = ctx->r24 | ctx->r9;
    // 0x800B85C4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B85C8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B85CC: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800B85D0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B85D4: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x800B85D8: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800B85DC: lbu         $t9, 0x2($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X2);
    // 0x800B85E0: lbu         $t4, 0x3($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X3);
    // 0x800B85E4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B85E8: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800B85EC: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x800B85F0: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x800B85F4: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x800B85F8: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x800B85FC: sll         $t7, $t4, 12
    ctx->r15 = S32(ctx->r12 << 12);
    // 0x800B8600: andi        $t8, $t5, 0xFFF
    ctx->r24 = ctx->r13 & 0XFFF;
    // 0x800B8604: or          $t5, $t8, $t7
    ctx->r13 = ctx->r24 | ctx->r15;
    // 0x800B8608: b           L_800B88B0
    // 0x800B860C: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
        goto L_800B88B0;
    // 0x800B860C: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
L_800B8610:
    // 0x800B8610: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800B8614: bne         $a0, $at, L_800B8754
    if (ctx->r4 != ctx->r1) {
        // 0x800B8618: lui         $t1, 0xF588
        ctx->r9 = S32(0XF588 << 16);
            goto L_800B8754;
    }
    // 0x800B8618: lui         $t1, 0xF588
    ctx->r9 = S32(0XF588 << 16);
    // 0x800B861C: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800B8620: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x800B8624: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B8628: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800B862C: andi        $t3, $t6, 0xFFF
    ctx->r11 = ctx->r14 & 0XFFF;
    // 0x800B8630: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800B8634: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8638: addu        $t8, $t0, $at
    ctx->r24 = ADD32(ctx->r8, ctx->r1);
    // 0x800B863C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800B8640: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B8644: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x800B8648: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B864C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B8650: addiu       $t5, $t7, 0x7
    ctx->r13 = ADD32(ctx->r15, 0X7);
    // 0x800B8654: sra         $t9, $t5, 3
    ctx->r25 = S32(SIGNED(ctx->r13) >> 3);
    // 0x800B8658: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x800B865C: sll         $t3, $t6, 9
    ctx->r11 = S32(ctx->r14 << 9);
    // 0x800B8660: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8664: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x800B8668: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800B866C: or          $t4, $t3, $t1
    ctx->r12 = ctx->r11 | ctx->r9;
    // 0x800B8670: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B8674: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B8678: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800B867C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8680: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800B8684: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800B8688: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B868C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B8690: lui         $t5, 0xF400
    ctx->r13 = S32(0XF400 << 16);
    // 0x800B8694: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x800B8698: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x800B869C: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x800B86A0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B86A4: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800B86A8: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x800B86AC: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x800B86B0: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800B86B4: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x800B86B8: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800B86BC: sll         $t3, $t6, 12
    ctx->r11 = S32(ctx->r14 << 12);
    // 0x800B86C0: or          $t8, $t4, $at
    ctx->r24 = ctx->r12 | ctx->r1;
    // 0x800B86C4: or          $t4, $t8, $t3
    ctx->r12 = ctx->r24 | ctx->r11;
    // 0x800B86C8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B86CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B86D0: sw          $t4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r12;
    // 0x800B86D4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800B86D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B86DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B86E0: lbu         $t5, 0x2($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X2);
    // 0x800B86E4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B86E8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B86EC: addiu       $t9, $t5, 0x7
    ctx->r25 = ADD32(ctx->r13, 0X7);
    // 0x800B86F0: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800B86F4: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x800B86F8: sll         $t3, $t8, 9
    ctx->r11 = S32(ctx->r24 << 9);
    // 0x800B86FC: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x800B8700: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800B8704: or          $t4, $t3, $t1
    ctx->r12 = ctx->r11 | ctx->r9;
    // 0x800B8708: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B870C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B8710: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800B8714: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B8718: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x800B871C: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800B8720: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x800B8724: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x800B8728: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B872C: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x800B8730: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800B8734: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800B8738: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x800B873C: andi        $t9, $t5, 0xFFF
    ctx->r25 = ctx->r13 & 0XFFF;
    // 0x800B8740: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800B8744: andi        $t3, $t8, 0xFFF
    ctx->r11 = ctx->r24 & 0XFFF;
    // 0x800B8748: or          $t8, $t3, $t6
    ctx->r24 = ctx->r11 | ctx->r14;
    // 0x800B874C: b           L_800B88B0
    // 0x800B8750: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
        goto L_800B88B0;
    // 0x800B8750: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
L_800B8754:
    // 0x800B8754: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B8758: bne         $a0, $at, L_800B88A8
    if (ctx->r4 != ctx->r1) {
        // 0x800B875C: lui         $t1, 0xF588
        ctx->r9 = S32(0XF588 << 16);
            goto L_800B88A8;
    }
    // 0x800B875C: lui         $t1, 0xF588
    ctx->r9 = S32(0XF588 << 16);
    // 0x800B8760: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x800B8764: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x800B8768: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B876C: sra         $t7, $t4, 1
    ctx->r15 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800B8770: addiu       $t5, $t7, -0x1
    ctx->r13 = ADD32(ctx->r15, -0X1);
    // 0x800B8774: andi        $t9, $t5, 0xFFF
    ctx->r25 = ctx->r13 & 0XFFF;
    // 0x800B8778: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x800B877C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8780: addu        $t6, $t0, $at
    ctx->r14 = ADD32(ctx->r8, ctx->r1);
    // 0x800B8784: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800B8788: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800B878C: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x800B8790: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8794: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B8798: sra         $t4, $t8, 1
    ctx->r12 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800B879C: addiu       $t7, $t4, 0x7
    ctx->r15 = ADD32(ctx->r12, 0X7);
    // 0x800B87A0: sra         $t5, $t7, 3
    ctx->r13 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800B87A4: andi        $t9, $t5, 0x1FF
    ctx->r25 = ctx->r13 & 0X1FF;
    // 0x800B87A8: sll         $t3, $t9, 9
    ctx->r11 = S32(ctx->r25 << 9);
    // 0x800B87AC: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x800B87B0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B87B4: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800B87B8: or          $t6, $t3, $t1
    ctx->r14 = ctx->r11 | ctx->r9;
    // 0x800B87BC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B87C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B87C4: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800B87C8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B87CC: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x800B87D0: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800B87D4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B87D8: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800B87DC: lui         $t7, 0xF400
    ctx->r15 = S32(0XF400 << 16);
    // 0x800B87E0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800B87E4: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x800B87E8: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x800B87EC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800B87F0: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x800B87F4: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x800B87F8: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x800B87FC: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x800B8800: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x800B8804: andi        $t9, $t5, 0xFFF
    ctx->r25 = ctx->r13 & 0XFFF;
    // 0x800B8808: sll         $t3, $t9, 12
    ctx->r11 = S32(ctx->r25 << 12);
    // 0x800B880C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800B8810: or          $t6, $t8, $t3
    ctx->r14 = ctx->r24 | ctx->r11;
    // 0x800B8814: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8818: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B881C: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800B8820: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x800B8824: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800B8828: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B882C: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x800B8830: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8834: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800B8838: sra         $t5, $t7, 1
    ctx->r13 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800B883C: addiu       $t9, $t5, 0x7
    ctx->r25 = ADD32(ctx->r13, 0X7);
    // 0x800B8840: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800B8844: andi        $t3, $t8, 0x1FF
    ctx->r11 = ctx->r24 & 0X1FF;
    // 0x800B8848: sll         $t6, $t3, 9
    ctx->r14 = S32(ctx->r11 << 9);
    // 0x800B884C: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x800B8850: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x800B8854: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x800B8858: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800B885C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8860: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800B8864: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B8868: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800B886C: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x800B8870: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800B8874: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x800B8878: lbu         $t9, 0x3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X3);
    // 0x800B887C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8880: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x800B8884: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800B8888: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x800B888C: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x800B8890: andi        $t9, $t5, 0xFFF
    ctx->r25 = ctx->r13 & 0XFFF;
    // 0x800B8894: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x800B8898: andi        $t6, $t3, 0xFFF
    ctx->r14 = ctx->r11 & 0XFFF;
    // 0x800B889C: or          $t3, $t6, $t8
    ctx->r11 = ctx->r14 | ctx->r24;
    // 0x800B88A0: b           L_800B88B0
    // 0x800B88A4: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
        goto L_800B88B0;
    // 0x800B88A4: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
L_800B88A8:
    // 0x800B88A8: b           L_800B8C40
    // 0x800B88AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B8C40;
    // 0x800B88AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B88B0:
    // 0x800B88B0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800B88B4: lbu         $t7, 0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2);
    // 0x800B88B8: lwc1        $f0, 0x14($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X14);
    // 0x800B88BC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800B88C0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800B88C4: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B88C8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B88CC: bgez        $t7, L_800B88E4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B88D0: mov.s       $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
            goto L_800B88E4;
    }
    // 0x800B88D0: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    // 0x800B88D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B88D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B88DC: nop

    // 0x800B88E0: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800B88E4:
    // 0x800B88E4: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x800B88E8: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800B88EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B88F0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800B88F4: bgez        $t5, L_800B8908
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B88F8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B8908;
    }
    // 0x800B88F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B88FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B8900: nop

    // 0x800B8904: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800B8908:
    // 0x800B8908: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B890C: lbu         $t9, 0x7($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X7);
    // 0x800B8910: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B8914: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800B8918: beq         $t9, $zero, L_800B892C
    if (ctx->r25 == 0) {
        // 0x800B891C: swc1        $f8, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
            goto L_800B892C;
    }
    // 0x800B891C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800B8920: lbu         $t6, 0x8($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X8);
    // 0x800B8924: bnel        $t6, $zero, L_800B8940
    if (ctx->r14 != 0) {
        // 0x800B8928: lbu         $t8, 0x1($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X1);
            goto L_800B8940;
    }
    goto skip_0;
    // 0x800B8928: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    skip_0:
L_800B892C:
    // 0x800B892C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B8930: nop

    // 0x800B8934: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B8938: sub.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800B893C: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
L_800B8940:
    // 0x800B8940: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B8944: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800B8948: bgez        $t8, L_800B895C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B894C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800B895C;
    }
    // 0x800B894C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B8950: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B8954: nop

    // 0x800B8958: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_800B895C:
    // 0x800B895C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B8960: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B8964: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800B8968: lbu         $t4, 0x4($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X4);
    // 0x800B896C: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B8970: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800B8974: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B8978: beq         $t4, $zero, L_800B89DC
    if (ctx->r12 == 0) {
        // 0x800B897C: sub.s       $f2, $f8, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f6.fl;
            goto L_800B89DC;
    }
    // 0x800B897C: sub.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800B8980: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B8984: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B8988: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B898C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800B8990: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800B8994: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800B8998: jal         0x800DC178
    // 0x800B899C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x800B899C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x800B89A0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B89A4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800B89A8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B89AC: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800B89B0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800B89B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B89B8: jal         0x800DC178
    // 0x800B89BC: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x800B89BC: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x800B89C0: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800B89C4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B89C8: addiu       $t2, $t2, -0x7D40
    ctx->r10 = ADD32(ctx->r10, -0X7D40);
    // 0x800B89CC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800B89D0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B89D4: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B89D8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
L_800B89DC:
    // 0x800B89DC: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B89E0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800B89E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B89E8: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800B89EC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x800B89F0: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800B89F4: add.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800B89F8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B89FC: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800B8A00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B8A04: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8A08: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800B8A0C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800B8A10: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800B8A14: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B8A18: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800B8A1C: sra         $t9, $t5, 16
    ctx->r25 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800B8A20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8A24: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800B8A28: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B8A2C: blez        $t9, L_800B8A3C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800B8A30: nop
    
            goto L_800B8A3C;
    }
    // 0x800B8A30: nop

    // 0x800B8A34: b           L_800B8A3C
    // 0x800B8A38: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800B8A3C;
    // 0x800B8A38: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800B8A3C:
    // 0x800B8A3C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B8A40: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800B8A44: andi        $t5, $v0, 0xFFF
    ctx->r13 = ctx->r2 & 0XFFF;
    // 0x800B8A48: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x800B8A4C: sra         $t3, $t8, 16
    ctx->r11 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800B8A50: blez        $t3, L_800B8A60
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800B8A54: trunc.w.s   $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
            goto L_800B8A60;
    }
    // 0x800B8A54: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800B8A58: b           L_800B8A60
    // 0x800B8A5C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
        goto L_800B8A60;
    // 0x800B8A5C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_800B8A60:
    // 0x800B8A60: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800B8A64: andi        $t4, $a0, 0xFFF
    ctx->r12 = ctx->r4 & 0XFFF;
    // 0x800B8A68: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x800B8A6C: sll         $t9, $t5, 12
    ctx->r25 = S32(ctx->r13 << 12);
    // 0x800B8A70: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x800B8A74: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800B8A78: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800B8A7C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800B8A80: blez        $t4, L_800B8A90
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B8A84: or          $a1, $t4, $zero
        ctx->r5 = ctx->r12 | 0;
            goto L_800B8A90;
    }
    // 0x800B8A84: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800B8A88: b           L_800B8A94
    // 0x800B8A8C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_800B8A94;
    // 0x800B8A8C: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_800B8A90:
    // 0x800B8A90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B8A94:
    // 0x800B8A94: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800B8A98: andi        $t6, $v0, 0xFFF
    ctx->r14 = ctx->r2 & 0XFFF;
    // 0x800B8A9C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x800B8AA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8AA4: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800B8AA8: lui         $t4, 0xE100
    ctx->r12 = S32(0XE100 << 16);
    // 0x800B8AAC: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B8AB0: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    // 0x800B8AB4: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800B8AB8: blez        $t7, L_800B8AC8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800B8ABC: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_800B8AC8;
    }
    // 0x800B8ABC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800B8AC0: b           L_800B8AC8
    // 0x800B8AC4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
        goto L_800B8AC8;
    // 0x800B8AC4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800B8AC8:
    // 0x800B8AC8: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x800B8ACC: or          $t3, $t9, $t8
    ctx->r11 = ctx->r25 | ctx->r24;
    // 0x800B8AD0: sw          $t3, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r11;
    // 0x800B8AD4: bgez        $a1, L_800B8B5C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800B8AD8: sw          $t4, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r12;
            goto L_800B8B5C;
    }
    // 0x800B8AD8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800B8ADC: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800B8AE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B8AE4: lwc1        $f6, 0x14($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X14);
    // 0x800B8AE8: div.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800B8AEC: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800B8AF0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800B8AF4: nop

    // 0x800B8AF8: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x800B8AFC: sra         $t6, $t7, 16
    ctx->r14 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800B8B00: bgez        $t6, L_800B8B30
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B8B04: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800B8B30;
    }
    // 0x800B8B04: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B8B08: multu       $a1, $t6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8B0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8B10: mflo        $v0
    ctx->r2 = lo;
    // 0x800B8B14: sra         $t9, $v0, 7
    ctx->r25 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800B8B18: blez        $t9, L_800B8B28
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800B8B1C: nop
    
            goto L_800B8B28;
    }
    // 0x800B8B1C: nop

    // 0x800B8B20: b           L_800B8B64
    // 0x800B8B24: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
        goto L_800B8B64;
    // 0x800B8B24: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
L_800B8B28:
    // 0x800B8B28: b           L_800B8B64
    // 0x800B8B2C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
        goto L_800B8B64;
    // 0x800B8B2C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_800B8B30:
    // 0x800B8B30: multu       $a1, $a0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8B34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8B38: mflo        $v0
    ctx->r2 = lo;
    // 0x800B8B3C: sra         $t8, $v0, 7
    ctx->r24 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800B8B40: bgez        $t8, L_800B8B50
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B8B44: nop
    
            goto L_800B8B50;
    }
    // 0x800B8B44: nop

    // 0x800B8B48: b           L_800B8B50
    // 0x800B8B4C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
        goto L_800B8B50;
    // 0x800B8B4C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
L_800B8B50:
    // 0x800B8B50: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800B8B54: b           L_800B8B64
    // 0x800B8B58: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_800B8B64;
    // 0x800B8B58: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800B8B5C:
    // 0x800B8B5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B8B60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800B8B64:
    // 0x800B8B64: bgez        $t0, L_800B8BE4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B8B68: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_800B8BE4;
    }
    // 0x800B8B68: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800B8B6C: lwc1        $f8, 0x14($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X14);
    // 0x800B8B70: div.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800B8B74: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800B8B78: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800B8B7C: nop

    // 0x800B8B80: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x800B8B84: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800B8B88: bgez        $t5, L_800B8BB8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B8B8C: or          $a0, $t5, $zero
        ctx->r4 = ctx->r13 | 0;
            goto L_800B8BB8;
    }
    // 0x800B8B8C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800B8B90: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8B94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8B98: mflo        $v0
    ctx->r2 = lo;
    // 0x800B8B9C: sra         $t7, $v0, 7
    ctx->r15 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800B8BA0: blez        $t7, L_800B8BB0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800B8BA4: nop
    
            goto L_800B8BB0;
    }
    // 0x800B8BA4: nop

    // 0x800B8BA8: b           L_800B8BE8
    // 0x800B8BAC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
        goto L_800B8BE8;
    // 0x800B8BAC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800B8BB0:
    // 0x800B8BB0: b           L_800B8BEC
    // 0x800B8BB4: negu        $t9, $a0
    ctx->r25 = SUB32(0, ctx->r4);
        goto L_800B8BEC;
    // 0x800B8BB4: negu        $t9, $a0
    ctx->r25 = SUB32(0, ctx->r4);
L_800B8BB8:
    // 0x800B8BB8: multu       $a2, $a0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8BBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B8BC0: mflo        $v0
    ctx->r2 = lo;
    // 0x800B8BC4: sra         $t6, $v0, 7
    ctx->r14 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800B8BC8: bgez        $t6, L_800B8BD8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B8BCC: nop
    
            goto L_800B8BD8;
    }
    // 0x800B8BCC: nop

    // 0x800B8BD0: b           L_800B8BD8
    // 0x800B8BD4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
        goto L_800B8BD8;
    // 0x800B8BD4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_800B8BD8:
    // 0x800B8BD8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800B8BDC: b           L_800B8BE8
    // 0x800B8BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800B8BE8;
    // 0x800B8BE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800B8BE4:
    // 0x800B8BE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800B8BE8:
    // 0x800B8BE8: negu        $t9, $a0
    ctx->r25 = SUB32(0, ctx->r4);
L_800B8BEC:
    // 0x800B8BEC: negu        $t4, $a3
    ctx->r12 = SUB32(0, ctx->r7);
    // 0x800B8BF0: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x800B8BF4: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800B8BF8: or          $t7, $t8, $t5
    ctx->r15 = ctx->r24 | ctx->r13;
    // 0x800B8BFC: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x800B8C00: lui         $t6, 0xF100
    ctx->r14 = S32(0XF100 << 16);
    // 0x800B8C04: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800B8C08: lwc1        $f4, 0x14($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X14);
    // 0x800B8C0C: trunc.w.s   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800B8C10: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800B8C14: div.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800B8C18: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800B8C1C: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800B8C20: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800B8C24: nop

    // 0x800B8C28: andi        $t3, $a2, 0xFFFF
    ctx->r11 = ctx->r6 & 0XFFFF;
    // 0x800B8C2C: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800B8C30: or          $t8, $t4, $t3
    ctx->r24 = ctx->r12 | ctx->r11;
    // 0x800B8C34: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800B8C38: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800B8C3C: sw          $v1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r3;
L_800B8C40:
    // 0x800B8C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8C44: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800B8C48: jr          $ra
    // 0x800B8C4C: nop

    return;
    // 0x800B8C4C: nop

;}
RECOMP_FUNC void func_80800878_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080087C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800880: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x80800884: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x80800888: jal         0x800DA298
    // 0x8080088C: addiu       $a0, $t6, 0xD5
    ctx->r4 = ADD32(ctx->r14, 0XD5);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080088C: addiu       $a0, $t6, 0xD5
    ctx->r4 = ADD32(ctx->r14, 0XD5);
    after_0:
    // 0x80800890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800898: jr          $ra
    // 0x8080089C: nop

    return;
    // 0x8080089C: nop

;}
RECOMP_FUNC void _bsbegghead_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082900: syscall     19
    recomp_syscall_handler(rdram, ctx, 0x80082900);
    return;
    // 0x80082904: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800D9C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9C34: lui         $t6, 0x3F80
    ctx->r14 = S32(0X3F80 << 16);
    // 0x800D9C38: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800D9C3C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800D9C40: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800D9C44: jr          $ra
    // 0x800D9C48: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    return;
    // 0x800D9C48: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80801C08_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801C0C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80801C10: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80801C14: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801C18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801C1C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801C20: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80801C24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801C28: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80801C2C: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
    // 0x80801C30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801C34:
    // 0x80801C34: jal         0x80801784
    // 0x80801C38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801784_chquiz(rdram, ctx);
        goto after_0;
    // 0x80801C38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80801C3C: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80801C40: bnel        $at, $zero, L_80801C54
    if (ctx->r1 != 0) {
        // 0x80801C44: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801C54;
    }
    goto skip_0;
    // 0x80801C44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80801C48: b           L_80801C60
    // 0x80801C4C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80801C60;
    // 0x80801C4C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80801C50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80801C54:
    // 0x80801C54: bnel        $s0, $s3, L_80801C34
    if (ctx->r16 != ctx->r19) {
        // 0x80801C58: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801C34;
    }
    goto skip_1;
    // 0x80801C58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x80801C5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80801C60:
    // 0x80801C60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801C64: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801C68: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801C6C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C70: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801C74: jr          $ra
    // 0x80801C78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801C78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808000BC_chswampplatform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C8: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808000CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000D4: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x808000D8: beq         $at, $zero, L_80800608
    if (ctx->r1 == 0) {
        // 0x808000DC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800608;
    }
    // 0x808000DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2268, 0X9B0) << 16);
    // 0x808000E4: addu        $at, $at, $t7
    gpr jr_addend_808000EC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808000E8: lw          $t7, 0x9B0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2268, 0X9B0));
    // 0x808000EC: jr          $t7
    // 0x808000F0: nop

    switch (jr_addend_808000EC >> 2) {
        case 0: goto L_808000F4; break;
        case 1: goto L_80800108; break;
        case 2: goto L_808001DC; break;
        case 3: goto L_8080023C; break;
        case 4: goto L_808002B4; break;
        case 5: goto L_80800570; break;
        case 6: goto L_808005B8; break;
        case 7: goto L_808005FC; break;
        default: switch_error(__func__, 0x808000EC, 0x808009B0);
    }
    // 0x808000F0: nop

L_808000F4:
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: jal         0x80103110
    // 0x808000FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x808000FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800100: b           L_8080060C
    // 0x80800104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080060C;
    // 0x80800104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800108:
    // 0x80800108: jal         0x800DA298
    // 0x8080010C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080010C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_1:
    // 0x80800110: beq         $v0, $zero, L_80800608
    if (ctx->r2 == 0) {
        // 0x80800114: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_80800608;
    }
    // 0x80800114: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800118: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8080011C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80800120: jal         0x80086C68
    // 0x80800124: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800124: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_2:
    // 0x80800128: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8080012C: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80800130: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080013C: jal         0x80089840
    // 0x80800140: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800140: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_3:
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x80100094
    // 0x8080014C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x8080014C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800150: jal         0x80089850
    // 0x80800154: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800154: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x80100094
    // 0x80800160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x80800160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800164: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800168: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
    // 0x8080016C: jal         0x80089908
    // 0x80800170: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    _sumumbofx_entrypoint_25(rdram, ctx);
        goto after_7;
    // 0x80800170: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80100094
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_8;
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800180: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80800184: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800188: jal         0x80089900
    // 0x8080018C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_9;
    // 0x8080018C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: jal         0x80100094
    // 0x80800198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x80800198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8080019C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001A0: jal         0x800898B8
    // 0x808001A4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_11;
    // 0x808001A4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_11:
    // 0x808001A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001B0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x808001B4: jal         0x80085708
    // 0x808001B8: addiu       $a3, $zero, 0x210
    ctx->r7 = ADD32(0, 0X210);
    _capod_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x808001B8: addiu       $a3, $zero, 0x210
    ctx->r7 = ADD32(0, 0X210);
    after_12:
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: jal         0x80101FDC
    // 0x808001C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x808001C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: jal         0x8010A800
    // 0x808001D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_14;
    // 0x808001D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x808001D4: b           L_8080060C
    // 0x808001D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080060C;
    // 0x808001D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001DC:
    // 0x808001DC: jal         0x80800804
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800804_chswampplatform(rdram, ctx);
        goto after_15;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: jal         0x80100094
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x808001F0: jal         0x800898B0
    // 0x808001F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_17;
    // 0x808001F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: jal         0x80100094
    // 0x80800200: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_18;
    // 0x80800200: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80800204: jal         0x80089918
    // 0x80800208: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_19;
    // 0x80800208: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
    // 0x8080020C: beq         $v0, $zero, L_80800608
    if (ctx->r2 == 0) {
        // 0x80800210: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800608;
    }
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: jal         0x80100094
    // 0x80800218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_20;
    // 0x80800218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x8080021C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800220: jal         0x800898D0
    // 0x80800224: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    _sumumbofx_entrypoint_18(rdram, ctx);
        goto after_21;
    // 0x80800224: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_21:
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: jal         0x80101FDC
    // 0x80800230: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_22;
    // 0x80800230: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_22:
    // 0x80800234: b           L_8080060C
    // 0x80800238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080060C;
    // 0x80800238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080023C:
    // 0x8080023C: jal         0x80800804
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800804_chswampplatform(rdram, ctx);
        goto after_23;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: jal         0x80100094
    // 0x8080024C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_24;
    // 0x8080024C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80800250: jal         0x800898B0
    // 0x80800254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_25;
    // 0x80800254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_25:
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: jal         0x80100094
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_26;
    // 0x80800260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80800264: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800268: jal         0x80089868
    // 0x8080026C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _sumumbofx_entrypoint_5(rdram, ctx);
        goto after_27;
    // 0x8080026C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_27:
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: jal         0x80100094
    // 0x80800278: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_28;
    // 0x80800278: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x8080027C: jal         0x80089918
    // 0x80800280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_29;
    // 0x80800280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_29:
    // 0x80800284: beq         $v0, $zero, L_80800608
    if (ctx->r2 == 0) {
        // 0x80800288: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800608;
    }
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: jal         0x80100094
    // 0x80800290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_30;
    // 0x80800290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80800294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800298: jal         0x800898C8
    // 0x8080029C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    _sumumbofx_entrypoint_17(rdram, ctx);
        goto after_31;
    // 0x8080029C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_31:
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: jal         0x80101FDC
    // 0x808002A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_32;
    // 0x808002A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_32:
    // 0x808002AC: b           L_8080060C
    // 0x808002B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080060C;
    // 0x808002B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002B4:
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: jal         0x80100094
    // 0x808002BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_33;
    // 0x808002BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x808002C0: jal         0x800898E8
    // 0x808002C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_34;
    // 0x808002C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_34:
    // 0x808002C8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808002CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002D0: nop

    // 0x808002D4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808002D8: nop

    // 0x808002DC: bc1fl       L_808003A8
    if (!c1cs) {
        // 0x808002E0: lw          $t5, 0x64($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X64);
            goto L_808003A8;
    }
    goto skip_0;
    // 0x808002E0: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x808002E4: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808002F0: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x808002F4: bltz        $t1, L_80800310
    if (SIGNED(ctx->r9) < 0) {
        // 0x808002F8: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(2268, 0X9D0) << 16);
            goto L_80800310;
    }
    // 0x808002F8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2268, 0X9D0) << 16);
    // 0x808002FC: jal         0x80089D18
    // 0x80800300: addiu       $a2, $a2, 0x9D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2268, 0X9D0));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_35;
    // 0x80800300: addiu       $a2, $a2, 0x9D0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2268, 0X9D0));
    after_35:
    // 0x80800304: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800308: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x8080030C: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_80800310:
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: jal         0x80100094
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_36;
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_36:
    // 0x8080031C: jal         0x800898E8
    // 0x80800320: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_37;
    // 0x80800320: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_37:
    // 0x80800324: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800328: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080032C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800330: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800334: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80800338: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080033C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800340: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800344: nop

    // 0x80800348: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080034C: jal         0x800138D0
    // 0x80800350: nop

    func_800138D0(rdram, ctx);
        goto after_38;
    // 0x80800350: nop

    after_38:
    // 0x80800354: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800358: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080035C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800360: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800364: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800368: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080036C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800370: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800374: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800378: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8080037C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800380: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800384: nop

    // 0x80800388: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080038C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800390: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x80800394: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x80800398: swc1        $f2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f2.u32l;
    // 0x8080039C: b           L_80800504
    // 0x808003A0: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
        goto L_80800504;
    // 0x808003A0: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
    // 0x808003A4: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
L_808003A8:
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808003B0: sll         $t7, $t5, 12
    ctx->r15 = S32(ctx->r13 << 12);
    // 0x808003B4: bltz        $t7, L_808003D0
    if (SIGNED(ctx->r15) < 0) {
        // 0x808003B8: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(2268, 0X9E4) << 16);
            goto L_808003D0;
    }
    // 0x808003B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2268, 0X9E4) << 16);
    // 0x808003BC: jal         0x80089D18
    // 0x808003C0: addiu       $a2, $a2, 0x9E4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2268, 0X9E4));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_39;
    // 0x808003C0: addiu       $a2, $a2, 0x9E4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2268, 0X9E4));
    after_39:
    // 0x808003C4: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x808003C8: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x808003CC: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
L_808003D0:
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D4: jal         0x80100094
    // 0x808003D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_40;
    // 0x808003D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x808003DC: jal         0x800898E8
    // 0x808003E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_21(rdram, ctx);
        goto after_41;
    // 0x808003E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_41:
    // 0x808003E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808003E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003EC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808003F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003F4: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808003F8: nop

    // 0x808003FC: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800400: jal         0x800138D0
    // 0x80800404: nop

    func_800138D0(rdram, ctx);
        goto after_42;
    // 0x80800404: nop

    after_42:
    // 0x80800408: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080040C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800410: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800414: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800418: sub.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8080041C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800420: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800424: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800428: sub.s       $f18, $f14, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8080042C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800430: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800434: swc1        $f2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f2.u32l;
    // 0x80800438: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8080043C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800440: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800444: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800448: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080044C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800450: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800454: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80800458: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080045C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800460: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800464: jal         0x800138D0
    // 0x80800468: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    func_800138D0(rdram, ctx);
        goto after_43;
    // 0x80800468: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    after_43:
    // 0x8080046C: jal         0x800F2100
    // 0x80800470: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_44;
    // 0x80800470: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_44:
    // 0x80800474: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800478: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080047C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800480: add.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80800484: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800488: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080048C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800490: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800494: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800498: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8080049C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808004A0: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808004A4: jal         0x800138D0
    // 0x808004A8: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    func_800138D0(rdram, ctx);
        goto after_45;
    // 0x808004A8: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    after_45:
    // 0x808004AC: jal         0x800F2100
    // 0x808004B0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_46;
    // 0x808004B0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_46:
    // 0x808004B4: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808004B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808004BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004C0: add.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x808004C4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808004C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808004CC: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x808004D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808004D4: mul.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x808004D8: jal         0x800138D0
    // 0x808004DC: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    func_800138D0(rdram, ctx);
        goto after_47;
    // 0x808004DC: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    after_47:
    // 0x808004E0: jal         0x800F2100
    // 0x808004E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_48;
    // 0x808004E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_48:
    // 0x808004E8: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808004EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808004F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004F4: add.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x808004F8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808004FC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800500: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
L_80800504:
    // 0x80800504: jal         0x80800804
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800804_chswampplatform(rdram, ctx);
        goto after_49;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x8080050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800510: jal         0x80100094
    // 0x80800514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_50;
    // 0x80800514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_50:
    // 0x80800518: jal         0x800898B0
    // 0x8080051C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_51;
    // 0x8080051C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_51:
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: jal         0x80100094
    // 0x80800528: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_52;
    // 0x80800528: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_52:
    // 0x8080052C: jal         0x80089918
    // 0x80800530: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_53;
    // 0x80800530: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_53:
    // 0x80800534: beql        $v0, $zero, L_8080060C
    if (ctx->r2 == 0) {
        // 0x80800538: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080060C;
    }
    goto skip_1;
    // 0x80800538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080053C: jal         0x80086AF0
    // 0x80800540: nop

    _chglowbo_entrypoint_6(rdram, ctx);
        goto after_54;
    // 0x80800540: nop

    after_54:
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800548: jal         0x80101FDC
    // 0x8080054C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_55;
    // 0x8080054C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_55:
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800554: jal         0x80100094
    // 0x80800558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_56;
    // 0x80800558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_56:
    // 0x8080055C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800560: jal         0x800898C0
    // 0x80800564: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_57;
    // 0x80800564: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_57:
    // 0x80800568: b           L_8080060C
    // 0x8080056C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080060C;
    // 0x8080056C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800570:
    // 0x80800570: jal         0x80800804
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800804_chswampplatform(rdram, ctx);
        goto after_58;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: jal         0x80100094
    // 0x80800580: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_59;
    // 0x80800580: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_59:
    // 0x80800584: jal         0x800898B0
    // 0x80800588: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_60;
    // 0x80800588: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_60:
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: jal         0x80100094
    // 0x80800594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_61;
    // 0x80800594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_61:
    // 0x80800598: jal         0x80089918
    // 0x8080059C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_62;
    // 0x8080059C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_62:
    // 0x808005A0: beq         $v0, $zero, L_80800608
    if (ctx->r2 == 0) {
        // 0x808005A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800608;
    }
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A8: jal         0x80101FDC
    // 0x808005AC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_63;
    // 0x808005AC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_63:
    // 0x808005B0: b           L_8080060C
    // 0x808005B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080060C;
    // 0x808005B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005B8:
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005BC: jal         0x80089848
    // 0x808005C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_64;
    // 0x808005C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_64:
    // 0x808005C4: jal         0x800DA524
    // 0x808005C8: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_65;
    // 0x808005C8: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_65:
    // 0x808005CC: jal         0x800DA544
    // 0x808005D0: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA544(rdram, ctx);
        goto after_66;
    // 0x808005D0: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_66:
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D8: jal         0x8010A800
    // 0x808005DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_67;
    // 0x808005DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_67:
    // 0x808005E0: jal         0x800DA544
    // 0x808005E4: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    func_800DA544(rdram, ctx);
        goto after_68;
    // 0x808005E4: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_68:
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005EC: jal         0x80101FDC
    // 0x808005F0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_69;
    // 0x808005F0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_69:
    // 0x808005F4: b           L_8080060C
    // 0x808005F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080060C;
    // 0x808005F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005FC:
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: jal         0x80103110
    // 0x80800604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_70;
    // 0x80800604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_70:
L_80800608:
    // 0x80800608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080060C:
    // 0x8080060C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800610: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800614: jr          $ra
    // 0x80800618: nop

    return;
    // 0x80800618: nop

;}
RECOMP_FUNC void subaddiecustomhits_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800200: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800204: jal         0x80104124
    // 0x80800208: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80104124(rdram, ctx);
        goto after_0;
    // 0x80800208: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080020C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800210: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x80800214: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800218: lhu         $t8, 0x12($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X12);
    // 0x8080021C: srl         $t9, $t8, 1
    ctx->r25 = S32(U32(ctx->r24) >> 1);
    // 0x80800220: bnel        $t9, $t0, L_80800270
    if (ctx->r25 != ctx->r8) {
        // 0x80800224: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800270;
    }
    goto skip_0;
    // 0x80800224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800228: jal         0x8001211C
    // 0x8080022C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8001211C(rdram, ctx);
        goto after_1;
    // 0x8080022C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800230: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800234: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800238: lw          $t1, 0x14($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X14);
    // 0x8080023C: bnel        $v0, $t1, L_80800270
    if (ctx->r2 != ctx->r9) {
        // 0x80800240: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800270;
    }
    goto skip_1;
    // 0x80800240: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80800244: jal         0x800EE7F8
    // 0x80800248: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800248: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x8080024C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80800250: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800254: beq         $v0, $zero, L_80800264
    if (ctx->r2 == 0) {
        // 0x80800258: nop
    
            goto L_80800264;
    }
    // 0x80800258: nop

    // 0x8080025C: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80800260: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_80800264:
    // 0x80800264: b           L_8080028C
    // 0x80800268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080028C;
    // 0x80800268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080026C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800270:
    // 0x80800270: jal         0x80103F38
    // 0x80800274: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80103F38(rdram, ctx);
        goto after_3;
    // 0x80800274: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800278: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8080027C: beql        $v0, $zero, L_8080028C
    if (ctx->r2 == 0) {
        // 0x80800280: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080028C;
    }
    goto skip_2;
    // 0x80800280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80800284: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80800288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080028C:
    // 0x8080028C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800290: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800294: jr          $ra
    // 0x80800298: nop

    return;
    // 0x80800298: nop

;}
RECOMP_FUNC void func_80801D8C_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801D90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801D94: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80801D98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801D9C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1016, 0X1FDC) << 16);
    // 0x80801DA0: lw          $a1, 0x70($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X70);
    // 0x80801DA4: addiu       $a3, $a3, 0x1FDC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1016, 0X1FDC));
    // 0x80801DA8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80801DAC: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x80801DB0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80801DB4: jal         0x8010D930
    // 0x80801DB8: addiu       $a2, $t6, 0x4
    ctx->r6 = ADD32(ctx->r14, 0X4);
    func_8010D930(rdram, ctx);
        goto after_0;
    // 0x80801DB8: addiu       $a2, $t6, 0x4
    ctx->r6 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x80801DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801DC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801DC4: jr          $ra
    // 0x80801DC8: nop

    return;
    // 0x80801DC8: nop

;}
RECOMP_FUNC void func_80800A34_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800A40: jal         0x80095748
    // 0x80800A44: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    baflag_isFalse(rdram, ctx);
        goto after_0;
    // 0x80800A44: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_0:
    // 0x80800A48: beq         $v0, $zero, L_80800A58
    if (ctx->r2 == 0) {
        // 0x80800A4C: nop
    
            goto L_80800A58;
    }
    // 0x80800A4C: nop

    // 0x80800A50: jal         0x808008D4
    // 0x80800A54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808008D4_bskaztorpedo(rdram, ctx);
        goto after_1;
    // 0x80800A54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80800A58:
    // 0x80800A58: jal         0x8009E6EC
    // 0x80800A5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8009E6EC(rdram, ctx);
        goto after_2;
    // 0x80800A5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800A60: slti        $at, $v0, 0x4F
    ctx->r1 = SIGNED(ctx->r2) < 0X4F ? 1 : 0;
    // 0x80800A64: bne         $at, $zero, L_80800A88
    if (ctx->r1 != 0) {
        // 0x80800A68: addiu       $t6, $v0, -0x1F
        ctx->r14 = ADD32(ctx->r2, -0X1F);
            goto L_80800A88;
    }
    // 0x80800A68: addiu       $t6, $v0, -0x1F
    ctx->r14 = ADD32(ctx->r2, -0X1F);
    // 0x80800A6C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80800A70: beq         $v0, $at, L_80800AC4
    if (ctx->r2 == ctx->r1) {
        // 0x80800A74: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800AC4;
    }
    // 0x80800A74: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800A78: beql        $v0, $at, L_80800AC8
    if (ctx->r2 == ctx->r1) {
        // 0x80800A7C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800AC8;
    }
    goto skip_0;
    // 0x80800A7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800A80: b           L_80800AD8
    // 0x80800A84: nop

        goto L_80800AD8;
    // 0x80800A84: nop

L_80800A88:
    // 0x80800A88: slti        $at, $v0, 0x2F
    ctx->r1 = SIGNED(ctx->r2) < 0X2F ? 1 : 0;
    // 0x80800A8C: bne         $at, $zero, L_80800AA4
    if (ctx->r1 != 0) {
        // 0x80800A90: addiu       $at, $zero, 0x4E
        ctx->r1 = ADD32(0, 0X4E);
            goto L_80800AA4;
    }
    // 0x80800A90: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x80800A94: beql        $v0, $at, L_80800AC8
    if (ctx->r2 == ctx->r1) {
        // 0x80800A98: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800AC8;
    }
    goto skip_1;
    // 0x80800A98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x80800A9C: b           L_80800AD8
    // 0x80800AA0: nop

        goto L_80800AD8;
    // 0x80800AA0: nop

L_80800AA4:
    // 0x80800AA4: sltiu       $at, $t6, 0x10
    ctx->r1 = ctx->r14 < 0X10 ? 1 : 0;
    // 0x80800AA8: beq         $at, $zero, L_80800AD8
    if (ctx->r1 == 0) {
        // 0x80800AAC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800AD8;
    }
    // 0x80800AAC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800AB0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(296, 0X16EC) << 16);
    // 0x80800AB4: addu        $at, $at, $t6
    gpr jr_addend_80800ABC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800AB8: lw          $t6, 0x16EC($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(296, 0X16EC));
    // 0x80800ABC: jr          $t6
    // 0x80800AC0: nop

    switch (jr_addend_80800ABC >> 2) {
        case 0: goto L_80800AC4; break;
        case 1: goto L_80800AC4; break;
        case 2: goto L_80800AC4; break;
        case 3: goto L_80800AD8; break;
        case 4: goto L_80800AD8; break;
        case 5: goto L_80800AC4; break;
        case 6: goto L_80800AD8; break;
        case 7: goto L_80800AD8; break;
        case 8: goto L_80800AD8; break;
        case 9: goto L_80800AD8; break;
        case 10: goto L_80800AD8; break;
        case 11: goto L_80800AD8; break;
        case 12: goto L_80800AD8; break;
        case 13: goto L_80800AD8; break;
        case 14: goto L_80800AC4; break;
        case 15: goto L_80800AC4; break;
        default: switch_error(__func__, 0x80800ABC, 0x808016EC);
    }
    // 0x80800AC0: nop

L_80800AC4:
    // 0x80800AC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800AC8:
    // 0x80800AC8: jal         0x8009E830
    // 0x80800ACC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_3;
    // 0x80800ACC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800AD0: b           L_80800AE4
    // 0x80800AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800AE4;
    // 0x80800AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800AD8:
    // 0x80800AD8: jal         0x808008D4
    // 0x80800ADC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808008D4_bskaztorpedo(rdram, ctx);
        goto after_4;
    // 0x80800ADC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800AE4:
    // 0x80800AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AE8: jr          $ra
    // 0x80800AEC: nop

    return;
    // 0x80800AEC: nop

;}
RECOMP_FUNC void func_800E443C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E443C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800E4440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E4444: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800E4448: jal         0x80018EFC
    // 0x800E444C: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    mlMtxSet(rdram, ctx);
        goto after_0;
    // 0x800E444C: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E4450: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E4454: jal         0x800CA7AC
    // 0x800E4458: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA7AC(rdram, ctx);
        goto after_1;
    // 0x800E4458: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_1:
    // 0x800E445C: jal         0x80018C50
    // 0x800E4460: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80018C50(rdram, ctx);
        goto after_2;
    // 0x800E4460: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800E4464: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E4468: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800E446C: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800E4470: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800E4474: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x800E4478: div.s       $f2, $f14, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800E447C: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x800E4480: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x800E4484: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800E4488: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800E448C: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800E4490: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800E4494: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800E4498: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800E449C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800E44A0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800E44A4: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x800E44A8: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800E44AC: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x800E44B0: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x800E44B4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800E44B8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800E44BC: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800E44C0: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x800E44C4: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800E44C8: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800E44CC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800E44D0: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800E44D4: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800E44D8: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    // 0x800E44DC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800E44E0: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800E44E4: jal         0x80018C50
    // 0x800E44E8: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    func_80018C50(rdram, ctx);
        goto after_3;
    // 0x800E44E8: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x800E44EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E44F0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x800E44F4: jr          $ra
    // 0x800E44F8: nop

    return;
    // 0x800E44F8: nop

;}
RECOMP_FUNC void func_800D9290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9290: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D9294: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D9298: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D929C: jal         0x800F5898
    // 0x800D92A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_0;
    // 0x800D92A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x800D92A4: blezl       $v0, L_800D92DC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D92A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D92DC;
    }
    goto skip_0;
    // 0x800D92A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_800D92AC:
    // 0x800D92AC: jal         0x800F6BE4
    // 0x800D92B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_1;
    // 0x800D92B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800D92B4: beq         $v0, $zero, L_800D92C4
    if (ctx->r2 == 0) {
        // 0x800D92B8: nop
    
            goto L_800D92C4;
    }
    // 0x800D92B8: nop

    // 0x800D92BC: jal         0x800F8EE4
    // 0x800D92C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F8EE4(rdram, ctx);
        goto after_2;
    // 0x800D92C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_800D92C4:
    // 0x800D92C4: jal         0x800F5898
    // 0x800D92C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_3;
    // 0x800D92C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_3:
    // 0x800D92CC: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D92D0: bne         $at, $zero, L_800D92AC
    if (ctx->r1 != 0) {
        // 0x800D92D4: nop
    
            goto L_800D92AC;
    }
    // 0x800D92D4: nop

    // 0x800D92D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D92DC:
    // 0x800D92DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D92E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D92E4: jr          $ra
    // 0x800D92E8: nop

    return;
    // 0x800D92E8: nop

;}
RECOMP_FUNC void bstrexsmall_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FF0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800FF4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(416, 0X1B48) << 16);
    // 0x80800FF8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800FFC: jr          $ra
    // 0x80801000: lw          $v0, 0x1B48($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B48));
    return;
    // 0x80801000: lw          $v0, 0x1B48($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B48));
;}
RECOMP_FUNC void sumissilehome_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800010: sb          $zero, 0x8($a1)
    MEM_B(0X8, ctx->r5) = 0;
    // 0x80800014: sb          $zero, 0x9($a1)
    MEM_B(0X9, ctx->r5) = 0;
    // 0x80800018: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8080001C: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x80800020: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3358, 0X320) << 16);
    // 0x80800024: lwc1        $f4, 0x320($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3358, 0X320));
    // 0x80800028: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080002C: sb          $t6, 0xA($a1)
    MEM_B(0XA, ctx->r5) = ctx->r14;
    // 0x80800030: addiu       $a0, $a1, 0xC
    ctx->r4 = ADD32(ctx->r5, 0XC);
    // 0x80800034: jal         0x8008A020
    // 0x80800038: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800038: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    after_0:
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800044: jr          $ra
    // 0x80800048: nop

    return;
    // 0x80800048: nop

;}
RECOMP_FUNC void func_800C68AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C68AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C68B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C68B4: jal         0x800EE7F8
    // 0x800C68B8: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800C68B8: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    after_0:
    // 0x800C68BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C68C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C68C4: jr          $ra
    // 0x800C68C8: nop

    return;
    // 0x800C68C8: nop

;}
RECOMP_FUNC void func_800C0710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0710: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0718: jal         0x800C0638
    // 0x800C071C: nop

    func_800C0638(rdram, ctx);
        goto after_0;
    // 0x800C071C: nop

    after_0:
    // 0x800C0720: beq         $v0, $zero, L_800C074C
    if (ctx->r2 == 0) {
        // 0x800C0724: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C074C;
    }
    // 0x800C0724: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C0728: addiu       $v0, $v0, -0x7750
    ctx->r2 = ADD32(ctx->r2, -0X7750);
    // 0x800C072C: lbu         $t7, 0x15E($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X15E);
    // 0x800C0730: lb          $t2, 0x166($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X166);
    // 0x800C0734: ori         $t0, $t7, 0x20
    ctx->r8 = ctx->r15 | 0X20;
    // 0x800C0738: sb          $t0, 0x15E($v0)
    MEM_B(0X15E, ctx->r2) = ctx->r8;
    // 0x800C073C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x800C0740: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800C0744: sb          $t1, 0x15E($v0)
    MEM_B(0X15E, ctx->r2) = ctx->r9;
    // 0x800C0748: sb          $t3, 0x166($v0)
    MEM_B(0X166, ctx->r2) = ctx->r11;
L_800C074C:
    // 0x800C074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0754: jr          $ra
    // 0x800C0758: nop

    return;
    // 0x800C0758: nop

;}
RECOMP_FUNC void func_80800708_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800708: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080070C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800710: jal         0x80800208
    // 0x80800714: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800208_bscarry(rdram, ctx);
        goto after_0;
    // 0x80800714: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800718: jal         0x800839C8
    // 0x8080071C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x8080071C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800724: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800728: jr          $ra
    // 0x8080072C: nop

    return;
    // 0x8080072C: nop

;}
RECOMP_FUNC void _chfiregen_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869C8: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x800869C8);
    return;
    // 0x800869CC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800EF0_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EF8: jal         0x80106790
    // 0x80800EFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800EFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800F00: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F08: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80800F0C: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x80800F10: bnel        $t8, $zero, L_80800F38
    if (ctx->r24 != 0) {
        // 0x80800F14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800F38;
    }
    goto skip_0;
    // 0x80800F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800F18: lhu         $t9, 0x72($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X72);
    // 0x80800F1C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800F20: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800F24: bnel        $t0, $at, L_80800F38
    if (ctx->r8 != ctx->r1) {
        // 0x80800F28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800F38;
    }
    goto skip_1;
    // 0x80800F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800F2C: jal         0x808014AC
    // 0x80800F30: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_1;
    // 0x80800F30: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x80800F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F38:
    // 0x80800F38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F3C: jr          $ra
    // 0x80800F40: nop

    return;
    // 0x80800F40: nop

;}
RECOMP_FUNC void func_80804FD4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804FD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804FD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804FDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804FE0: jal         0x80807D48
    // 0x80804FE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80804FE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80804FE8: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80804FEC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80804FF0: jal         0x8008CB10
    // 0x80804FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_1;
    // 0x80804FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80804FF8: beq         $v0, $zero, L_8080500C
    if (ctx->r2 == 0) {
        // 0x80804FFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080500C;
    }
    // 0x80804FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805000: addiu       $a1, $zero, 0x45A5
    ctx->r5 = ADD32(0, 0X45A5);
    // 0x80805004: jal         0x8009DBF0
    // 0x80805008: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DBF0(rdram, ctx);
        goto after_2;
    // 0x80805008: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
L_8080500C:
    // 0x8080500C: jal         0x8008CAEC
    // 0x80805010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_3;
    // 0x80805010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80805014: beq         $v0, $zero, L_80805030
    if (ctx->r2 == 0) {
        // 0x80805018: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805030;
    }
    // 0x80805018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080501C: jal         0x800A3410
    // 0x80805020: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A3410(rdram, ctx);
        goto after_4;
    // 0x80805020: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80805024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805028: jal         0x8009E5C8
    // 0x8080502C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bs_setState(rdram, ctx);
        goto after_5;
    // 0x8080502C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_80805030:
    // 0x80805030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80805034: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80805038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080503C: jr          $ra
    // 0x80805040: nop

    return;
    // 0x80805040: nop

;}
RECOMP_FUNC void func_800AF5C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF5C4: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x800AF5C8: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800AF5CC: lh          $t7, 0xA($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XA);
    // 0x800AF5D0: jr          $ra
    // 0x800AF5D4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    return;
    // 0x800AF5D4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
;}
RECOMP_FUNC void _gemarkersDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089758: syscall     793
    recomp_syscall_handler(rdram, ctx, 0x80089758);
    return;
    // 0x8008975C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087CC0: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087CC0);
    return;
    // 0x80087CC4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _gclightsDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E90: syscall     660
    recomp_syscall_handler(rdram, ctx, 0x80087E90);
    return;
    // 0x80087E94: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
