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

//==================================================

/*
//r3 = 3
int init_loc_C164EA(int r3) //init sd
{
    int r2 = 0;
    int r7 = &var_20;
    int r0 = r3;
    int r1 = &var_78; //sp
    //STR.W		R2, [R7,#-0x58]!
    int r0 = SceSdstor.SceSdifForDriver._imp_initialize_sd_device_c1271539();
}

//ctx[0x40] can only be equal to 1 in this scenario
int init loc_C164B0(int r8, int r9) //init sd
{
    char r0 = ctx[0x40];
    int r1 = &var_78; //sp
    int r0 = SceSdstor.SceSdifForDriver._imp_initialize_sd_device_c1271539();
    
    int r6 = r0;
    if(r0 == 0)
    {
        //goto loc_C1651C
    }
    else
    {
        if(r0 == r9)
        {
            //goto loc_C163D6
        }
        else
        {
            int r8 = r8 - 1;
            if(r8 == 0)
            {
                //goto loc_C163D6
            }
            else
            {
                //goto loc_C164B0 - continue iteration
            }
        }
    }
}

int loc_C164A0()
{
    int r9 = 0x8032001A; //error on which initialization must be terminated
    int r8 = 2; //number of iterations to try
    int r3 = 0;
    var_78 = r3;
    
    loc_C164B0(r8, r9);
}

int loc_C16492()
{
    int r0 = SceSdstor.SceSysrootForDriver._imp_check_boot_type_indicator_55392965();
    if(r0 != 0)
    {
        //sd init
    
        //goto loc_C164A0
    }
    else
    {
        int r0 = SceSdstor.SceSysrootForDriver._imp_return_zero_f804f761();
        if(r0 == 0)
        {
            //goto loc_C163D6
        }
        else
        {
            //sd init
        
            //goto loc_C164A0
        }
    }
}

//r3 = 1
int init_loc_C1645E() //init mmc
{
    int r2 = 0;
    int r7 = &var_20;
    int r0 = r3;
    int r1 = &var_78; //sp
    //STR.W		R2, [R7,#-0x58]!
    
    int r0 = SceSdstor.SceSdifForDriver._imp_initialize_mmc_device_22c82e79(r0, r1);
    
    int r6 = r0;
    if(r0 == 0)
    {
        //goto loc_C16652
    }
    else
    {
        int r3 = 0x8032001A;
        if(r0 == r3)
        {
            //sd init
        
            //goto loc_C16492
            loc_C16492();
        }
        else
        {
            char r0 = r4[0x40];
            int r1 = &var_78; //sp
            int r0 = SceSdstor.SceSdifForDriver._imp_initialize_mmc_device_22c82e79(r0, r1);
            
            int r6 = r0;
            if(r0 == 0)
            {
                //goto loc_C16652
            }
            else
            {
                //sd init
            
                //goto loc_C16492
                loc_C16492();
            }
        }
    }
}

//r3 is 0
int init_loc_C163A4(int r3) //init mmc
{
    int r7 = &var_20;
    int r0 = r3;
    int r1 = &var_78; //sp
    //STR.W		R3, [R7,#-0x58]!
    
    int r0 = SceSdstor.SceSdifForDriver._imp_initialize_mmc_device_22c82e79(r0, r1);
}


int exit_loc_C16394(int r0, int var_24, int var_009EA004*)
{
    if(var_24 == *(var_009EA004))
        return r0;
    else
        return STACK_FAIL;
}

int proc_initialize_sd_card_C162D0(void* ctx)
{
    //var_78=	-0x78
    //var_68=	-0x68
    //var_64=	-0x64
    //var_48=	-0x48
    //var_24=	-0x24
    //var_20=	-0x20

    int r5 = &var_009EA004;
    int r4 = ctx;
    int r3 = *var_009EA004;
    
    int var_24 = *(var_009EA004);
    
    int r0 = SceSdstor.SceThreadmgrForDriver._imp_70627f3a()
    if(r0 < 0)
        return exit_loc_C16394(r0, var_24, &var_009EA004);

    int r6 = 0;
    int r0 = ctx;
    ctx[0x42] = 0;
    ctx[0x43] = 0;
    ctx[0x44] = 0;
    ctx[0x48] = 0;
    ctx[0x4C] = 0;
    ctx[0x50] = 0;

    //to trigger sd or mmc init these conditions must be met:  
    //ctx[0x40] == 1 - device index
    //ctx[0x41] != 1 && ctx[0x41] != 2 - ?
    //ctx[0x42] != 1 && ctx[0x42] != 2 - ?
    
    int r0 = SceSdstor.SceThreadmgrForDriver._imp_db395782();
    if(r0 < 0)
        return exit_loc_C16394(r0, var_24, &var_009EA004);
        
    int r0 = ctx;
    
    int r0 = SceSdstor.SceThreadmgrForDriver._imp_70627f3a();
    if(r0 < 0)
        return exit_loc_C16394(r0, var_24, &var_009EA004);

    char r3 = ctx[0x42]; // ?
    if(r3 == 2)
    {
        //loc_C163F2:
        
        int r0 = r4; //ctx
        int r0 = SceSdstor.SceThreadmgrForDriver._imp_db395782();
        
        if(r0 >= 0)
        {
            int r0 = 0x80010013;
            return exit_loc_C16394(r0, var_24, &var_009EA004)
        }
        else
        {
            //loc_C16404:
            
            if(r2 != 2) // what is R2 ???
            {
                //goto loc_C16350 - sd init
            }
            else
            {
                //loc_C16408:
                
                int r0 = 1;
                int r0 = SceSdstor.SceSysconForDriver._imp_710a7cf0();
                int r6 = R0 - 0;
                if(r6 >= 0)
                {
                    char r3 = ctx[0x40];
                    //goto loc_C16348 - possible to trigger mmc or sd init
                }
                else
                {
                    //loc_C16418:
                    
                    int r0 = r4;
                    int r0 = SceSdstor.SceThreadmgrForDriver._imp_db395782();
                    //ANDS.W		R0, R0,	R0,ASR#32
                    //IT CC
                    //MOVCC		R0, R6
                    return exit_loc_C16394(r0, var_24, &var_009EA004);
                }
            }
        }
    }
    else
    {  
        if(r3 == 1)
        {
            //loc_C163DC:
            
            int r0 = r4;
            int r0 = SceSdstor.SceThreadmgrForDriver._imp_db395782();
            if(r0 >= 0)
                R0 = 0;
            return exit_loc_C16394(r0, var_24, &var_009EA004)
        }
        else
        {
            char r0 = ctx[0x40]; //device index
            if(r0 == 1)
            {
                //goto loc_C163EA
            }
            else
            {
                char r2 = ctx[0x41]; // ?
                if(r2 == 2)
                {
                    //goto loc_C16428
                }
                else
                {
                    if(r2 != 1)
                    {
                        char r3 = r0;
                        
                        //loc_C16338:
                        
                        char r2 = ctx[0x41];
                        
                        if(r3 == 3)
                        {
                            //goto loc_C16404
                        }
                        else
                        {
                            if(r2 == 2)
                            {
                                //goto loc_C16408
                            }
                            else
                            {
                                if(r6 != 0) //what is the point ??? it is constant
                                {
                                    //goto loc_C16418
                                }
                                else
                                {
                                    //loc_C16348:
                                    if(r3 == 1)
                                    {
                                        //init mmc or sd init
                                        
                                        //goto loc_C1645E
                                        init_loc_C1645E(r3); // this is the only place where code branches to this label
                                    }
                                    else
                                    {
                                        if(r3 == 0)
                                        {
                                            //init mmc
                                        
                                            //goto loc_C163A4
                                            init_loc_C163A4(r3); // this is the only place where code branches to this label
                                        }
                                        else
                                        {
                                            //loc_C16350:
                                            
                                            char r7 = ctx[0x41];
                                            if(r7 == 2)
                                            {
                                                //goto loc_C164CA
                                            }
                                            else
                                            {
                                                if(r3 == 3)
                                                {
                                                    //init sd
                                                
                                                    //goto loc_C164EA
                                                    init_loc_C164EA(); // this is the only place where code branches to this label
                                                }
                                                else
                                                {
                                                    if(r7 != 3)
                                                    {
                                                        int r6 = -1;
                                                        int r8 = 0;
                                                        
                                                        //loc_C16370:
                                                        
                                                        if(r7 == 2)
                                                        {
                                                            //goto loc_C165A0
                                                        }
                                                        else
                                                        {
                                                            //loc_C16376:
                                                            
                                                            int r3 = 0;
                                                            int r0 = r4; //ctx
                                                            
                                                            ctx[0x42] = r3;
                                                            ctx[0x50] = r3;
                                                            
                                                            if(r8 != 0) //what is the point, it is constant ???
                                                            {
                                                                //goto loc_C165EA
                                                            }
                                                            else
                                                            {
                                                                int r0 = SceSdstor.SceThreadmgrForDriver._imp_db395782();
                                                                //ANDS.W		R0, R0,	R0,ASR#32
                                                                //IT CC
                                                                //MOVCC		R0, R6
                                                                
                                                                return exit_loc_C16394(r0, var_24, &var_009EA004);
                                                            }
                                                        }
                                                    }
                                                    else
                                                    {
                                                        //goto loc_C16554
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        //goto loc_C16454
                    }
                }
            }
        }
    }
}
*/