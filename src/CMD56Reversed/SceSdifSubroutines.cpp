#include "SceSdifSubroutines.h"

/*
cmd_input* proc_get_cmd_input_ptr_C6AE40(sd_context_global*);

int proc_send_sd_command_C69C10(sd_context_global *ctx, cmd_input *cmd_data, int num0, int, num1);

int proc_C6AE78(sd_context_global *ctx, cmd_input *cmd_data);

int custom_command(sd_context_part* ctx, void* data_200, int size_200)
{
    if(ctx == 0 || data_200 == 0)
        return 0x8032000E;

    if(ctx[8] != size_200) //check buffer size
        return 0x8032000E;
        
    //get global context
    sd_context_global* gctx = ctx->gctx_ptr;
    if(gctx == 0)
        return 0x80320011;
        
    //get command buffer
    cmd_input* cmd_ctx = proc_get_cmd_input_ptr_C6AE40(gctx);
    if(cmd_ctx == 0)
        return 0x80320011;
        
    //initialize command buffer
    cmd_ctx->size = 0x240;
    cmd_ctx->unk_4 = 0x614; //?
    cmd_ctx->command = 0x38;
    cmd_ctx->argument = 0x00;
        
    cmd_ctx[0x20] = data_200; //assign result pointer
    cmd_ctx[0x24] = ctx[8]; // set buffer size - half word
    cmd_ctx[0x26] = 1; // half word - looks like number of sectors
    
    //send command
    int res = proc_send_sd_command_C69C10(gctx, cmd_ctx, 0, 0);
    
    //cycle command buffer
    proc_C6AE78(gctx, cmd_ctx)
    
    return res;
}

//proc_CMD6_C6B878
//loc_C6BAAE:
int cmd6(sd_context_part* ctx)
{
    sd_context_global* gctx = ctx->gctx_ptr;
    
    //get command buffer
    cmd_input* cmd_ctx = proc_get_cmd_input_ptr_C6AE40(gctx)
    if(cmd_ctx == 0)
        return 0x80320011;
    
    //initialize command buffer
    cmd_ctx->size = 0x240;
    cmd_ctx->unk_4 = 0x2B;
    cmd_ctx->command = 0x06;
    cmd_ctx->argument = 0x3B00000; //just some argument
    
    //send command
    int res = proc_send_sd_command_C69C10(gctx, cmd_ctx, 0, 3);
    
    //cycle command buffer
    proc_C6AE78(gctx, cmd_ctx)
    
    //STR.W		R6, [R8,#0x390]	; arg0 - struct	ptr
    
    return 0;
}

//proc_CMD2_ALL_SEND_CID_C6A3D0
int cmd2(sd_context_global *gctx, int* result)
{
    //some stuff before

    cmd_input cmd_ctx; //size is 240 - local variable
    
    //need memset?
    
    cmd_ctx.size = 0x240;
    cmd_ctx.unk_4 = 0x32;
    cmd_ctx.command = 2;
    cmd_ctx.argument = 0;
    
    cmd_ctx[0x20] = 0; //result buffer ptr
    
    sd_context_data* var_2400 = &gctx.ctx_data;
    int r1 = var_2400[0x40]; //? get pointer to stack?
    int r1 = r1[0]; //get another pointer
    
    cmd_ctx[0x6C] = &callback_C68084; // function ?
    cmd_ctx[0x70] = r1; // set ?
    cmd_ctx.unk_74 = r2; // 0
    cmd_ctx.gctx_ptr = gctx; // 0x78 gctx
    
    int r3 = 1;

    int lr = sub_C697E8(gctx, cmd_ctx, 0, 3, 1); //another function that sends commands?
    
    if(lr >= 0)
    {
        result[0x00] = cmd_ctx[0x10 + 0x00];
        result[0x04] = cmd_ctx[0x10 + 0x04];
        result[0x08] = cmd_ctx[0x10 + 0x08];
        result[0x0C] = cmd_ctx[0x10 + 0x0C];
        
        lr = 0;
    }
    
    return lr;
}
*/