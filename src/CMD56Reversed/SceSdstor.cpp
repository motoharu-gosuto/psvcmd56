char dword_C1A508[] = 
{
   0xDC, // SceSdif0
   0xDD, // SceSdif1
   0x3C, // SceMsifIns
   0x0F, // ?
   0xDF, // SceSdif3
}; // interrupt codes

char dword_C1A510[] =
{
   0x00,
   0x01,
   0x02,
   0x03,
   0x04,
}; //array indexes

int proc_SceSdstor_suspend_callback_handlerC17BE0(int resume, int eventid, suspend_args_t *args, void *opt)
{

}

int proc_SceSdstorIntr_thread_callback_C18650(SceSize args, void *argp)
{
    /*
    timeout= -0x80
    sector=	-0x78
    ctx_index_arg= -0x70
    var_6C=	-0x6C
    var_68=	-0x68
    unk0= -0x64
    var_60=	-0x60
    ctx_index= -0x5C
    var_58=	-0x58
    var_54=	-0x54
    var_50=	-0x50
    var_4C=	-0x4C
    var_48=	-0x48
    var_44=	-0x44
    outBits= -0x40
    var_38=	-0x38
    var_2C=	-0x2C //cookie
    */

    int r2 = var_009EA004;
    int r1 = r1[0];
    int r3 = 0x00BDFB20; //1B20
    
    int r2 = r2[0];
    
    int r1 = r1 + r1 * 4;
    var_2C = r2;
    
    int r10 = r3 + r1 * 8;
    int r0 = SceSdstor.SceSysrootForDriver._imp_check_boot_type_indicator_55392965 ; ksceSysrootIsManufacturingMode
    
    if(r0 != 0)
    {
       //loc_C18FD6:
       int r0 = r10[0x24];
       int r0 = proc_get_sd_init_context_C15DF4(r0);
       int r4 = r0;
       int r0 = proc_initialize_generic_1_C15E50(r0);
       int r3 = 0x80010013;
       if(r0 != r3)
       {
         int r3 = 1;
         r10[0x25] = r3;
       }
       
       if(r0 == r3)
       {
         int r0 = r4;
         sub_C1626C();
       }
    }
    
    //loc_C1867E:
    int r4 = r10[0xC]
    int r5 = &dword_C1A508; //interrupt codes
    var_60 = r5;
    
    int r3 = r4[8];
    int r1 = r4[9];
    int r5 = r5[3]; //get interrupt code
    
    int r0 = r5;
    int r0 = SceSdstor.SceIntrmgrForDriver._imp_enable_interrupt_901e41d8(r0);
    if(r0 >= 0)
    {
        int r0 = r5;
        int r1 = r4[0xA];
        int r0 = SceSdstor.SceIntrmgrForDriver._imp_enable_interrupt_901e41d8(r0);
    }
    
    //loc_C186A4:
    int r5 = 0x00BDFBF0; //1BF0
    int r11 = r10 + 0x14;
    int r8 = r11;
    var_68 = r5;
    
    int r5 = &dword_C1A530;
    var_6C = r5;
    
    int r5 = &dword_C1A510;
    var_54 = r5;
    
    int r5 = 0x00BDF720; //1720
    var_48 = r5;
    
    int r5 = &dword_C1A4F8;
    var_50 = r5;
    
    int r5 = 0x00BDF920; //1920
    var_58 = r5;
    
    //loc_C186E6:
    while(true)
    {
        int r7 = r10[0x25];
        int r4 = 0;
        var_6C = r5;
        int r3 = &outBits;
        int r0 = r10[4];
        int r1 = 0x1113;
        timeout = r4;
        int r2 = 5;
        outBits = r4;
        int r4 = r5[r7*4];
        int r0 = SceSdstor.SceThreadmgrForDriver._imp_ksceKernelWaitEventFlag_0c1d3f20(r0,r1,r2,r3,arg4);
        
        int r3 = outBits;
        if(r3 != 0)
            break;
    }
    
    int r1 = r3 << 0x1F;
    int r9 = 5;
    if(r1 >= 0)
    {
        //goto loc_C1876E
    }
    else
    {
        //loc_C18714:
        if(r7 == 1)
        {
            //goto loc_C18C90:
        }
        else
        {
            //loc_C1871A:
            int r6 = r3 << 0x1B;
            if(r6 >= 0)
            {
                //goto loc_C18736
            }
            else
            {
                if(r7 == 2)
                {
                    //goto loc_C18736
                }
                else
                {
                    //loc_C18722:
                    int r3 = r3 & (~1);
                    outBits = r3;
                    
                    if(r7 != 1)
                    {
                        int r2 = r7;
                    }
                    
                    if(r7 == 1)
                    {
                        //goto loc_C18796
                    }
                    else
                    {
                        //goto loc_C18730
                    }
                }
            }
        }
    }
    
    //loc_C18730:
    {
        int r5 = var_6C;
        int r4 = r5[r2 * 4];
        //goto loc_C18736
    }
    
    //loc_C18736:
    {
        int r3 = r4;
        int r11 = r3 & 0x100;
        if(r11 != 0)
        {
            //goto loc_C187C0
        }
        
        int r5 = r3 << 0x13;
        if(r5 < 0)
        {
            //goto loc_C187EE
        }
     
        int r0 = r3 << 0x1B;
        if(r0 < 0)
        {
            //goto loc_C1880A
        }
        
        int r6 = r3 & 1;
        if(r6 != 0)
        {
            //goto loc_C187E4
        }
        
        int r6 = outBits;
        int r3 = r6;
        
        //goto loc_C18750:
    }
    
    //loc_C18750:
    {
        //BICS		R3, R6
        int r1 = r6;
        int r0 = r10[8];
        outBits = r3;
        SceSdstor.SceThreadmgrForDriver._imp_d4780c3e();
        int r9 = r9 - 1;
        
        if(r9 == 0)
        {
            //goto loc_C186E6 - goto listening event again
        }
        else
        {
            int r3 = outBits;
            if(r3 == 0)
            {
                //goto loc_C186E6 - goto listening event again
            }
            else
            {
                int r1 = r3 << 0x1F;
                if(r1 < 0)
                {
                    //goto loc_C18714
                }
                else
                {
                    //goto loc_C1876E
                }
            }
        }
    }

    //loc_C1876E:
    {
        int r2 = r3 << 0x1E;
        if(r2 >= 0)
        {
            //goto loc_C1871A
        }
        else
        {
            if(r7 != 1)
            {
                //goto loc_C1871A
            }
            else
            {
                //loc_C18776:
                int r2 = r3 & (~2);
                int check = r3 & 0x10;
                int r2 = r2 | 1;
                outBits = r2;
                int r3 = r2;
                
                if(check == 0)
                {
                    //goto loc_C18736
                }
                else
                {
                    int r3 = r3 & (~1);
                    outBits = r3;
                    if(r7 != 1)
                    {
                       int r2 = r7;
                    }
                    
                    if(r7 != 1)
                    {
                        //goto loc_C18730
                    }
                    else
                    {
                        //goto loc_C18796
                    }
                }
            }
        }
    }
    
    //loc_C18796:
    {
        int r0 = r10[0x24];
        proc_get_sd_init_context_C15DF4();
        int r1 = 0x00BDFCC0; //1CC0 - MBR of game cart
        
        int r2 = 0;
        
        int r3 = r7;
        int r0 = proc_read_sector_generic_C16AF4();
        if(r0 != 0)
        {
            //goto loc_C18D18
        }
        else
        {
            int r3 = outBits;
            int r2 = r7;
            int r3 = r3 & (~0x10);
            outBits = r3;
            //goto loc_C18730
        }
    }
    
    //loc_C187C0:
    {
        int r0 = r10[0x24];
        if(r0 == 2)
        {
            //goto loc_C18AD6
        }
        else
        {
            if(r0 == 4)
            {
                //goto loc_C1892E
            }
            else
            {
                if(r0 == 1)
                {
                    //goto loc_C18A1C
                }
                else
                {
                    //loc_C187D6:
                    int r6 = 0x100;
                    int r3 = 2;
                    r10[0x25] = r3;
                    
                    //goto loc_C187E0:
                }
            }
        }
    }
    
    //loc_C187E0:
    {
        int r3 = outBits;
        //goto loc_C18750;
    }
    
    //loc_C187E4:
    {
        int r0 = r10;
        log_sd_info_to_file_C18378();
        int r3 = outBits;
        //goto loc_C18750;
    }
    
    //loc_C187EE:
    {
        int r5 = r10[0x24];
        
        if(r5 == 2)
        {
            //goto loc_C1895A
        }
        else
        {
            if(r5 == 4)
            {
                //goto loc_C18936
            }
            else
            {
                if(r5 == 1)
                {
                    //goto loc_C18B6E
                }
                else
                {
                    //loc_C18804:
                    int r6 = 0x1000;
                    //goto loc_C187E0
                }
            }
        }
    }
    
    //loc_C1880A:
    {
        int r3 = r10[0x25];
        int r6 = 0x10;
        int r5 = r10[0x24];
        
        if(r3 != 0)
        {
            //goto loc_C187E0
        }
        else
        {
            int r3 = r5 - 1;
            if(r3 > 3)
            {
                //goto loc_C187E0
            }
            else
            {
                //TBB.W		[PC,R3]
                /*
                jpt_C1881E 	; jump table for switch	statement
                DCB 0x28
                DCB 0x3D
                DCB 0x1D
                DCB 2
                */
            }
        }
    }
    
    //loc_C18826:
    {
    }
    
    //loc_C1885C:
    {
    }
    
    //loc_C18872:
    {
    }
    
    //loc_C1889C:
    {
    }
}

//I would assume these functions are interrupt handlers

void sub_C17BC8(int r0, void* r1)
{
    int r0 = r1[4];
    int r1 = 1;
    SceSdstor.SceThreadmgrForDriver._imp_d4780c3e();
}

void sub_C17BD4(int r0, void* r1)
{
    int r0 = r1[4];
    int r1 = 0x10;
    SceSdstor.SceThreadmgrForDriver._imp_d4780c3e();
}

int exit_loc_C192B0(int r0, int var_2C)
{
    if(var_2C == var_9EA004)
        return r0;
    else
        return STACK_CHECK_FAIL;
}

int proc_create_init_thread_reg_intr_suspend_callback_clear_buffers_C19004()
{
    /*
    attr= -0x60 //arg4
    var_5C = -0x5C //arg5
    var_58 = -0x58 //arg6
    
    var_48=	-0x48
    var_44=	-0x44
    var_40=	-0x40
    var_3C=	-0x3C
    var_38=	-0x38
    var_34=	-0x34
    var_30=	-0x30
    
    var_2C=	-0x2C //cookie
    */

    int r11 = &var_9EA004; //cookie
    int r4 = 00BDFBE8; 0x1BE8
    int r0 = "SceSdstor";
    int r3 = r11[0];
    int r1 = &proc_SceSdstor_suspend_callback_handlerC17BE0;
    int r5 = 0;
    int r2 = r4; //suspend_args_t

    var_2C = r3; //store cookie
    r4[0] = r5;
    r4[4] = (char)r5;
    r4[5] = (char)r5;
    int r0 = SceSdstor.SceKernelSuspendForDriver._imp_suspend_register_callback_04c05d10(r0, r1, r2);
    int r3 = r0 - 0;
    if(r3 < 0)
        r0 = r3;
        
    if(r3 < 0)
        return exit_loc_C192B0(r0, var_2C);

    r4[0] = r3;
        
    int r0 = 0x00BDFB20; //1B20
    int r1 = r5;
    int r2 = 0xC8;

    SceSdstor.SceSysclibForDriver._imp_memset_0ab9bf5c(r0, r1, r2); //set 0xC8 bytes with 0
    
    int r0 = 0x00BDF720; //1720
    int r1 = r5;
    int r2 = 0x200;
    SceSdstor.SceSysclibForDriver._imp_memset_0ab9bf5c(r0, r1, r2); //set 0x200 bytes with 0

    int r0 = 0x00BDF920; //1920
    int r1 = r5;
    int r2 = 0x200;
    SceSdstor.SceSysclibForDriver._imp_memset_0ab9bf5c(r0, r1, r2); //set 0x200 bytes with 0
    
    int r0 = 0x00BDFBF0; //1BF0
    int r1 = r5;
    int r2 = 0x3C;
    SceSdstor.SceSysclibForDriver._imp_memset_0ab9bf5c(r0, r1, r2); //set 0x3C bytes with 0
   
    //=========================
   
    int r7 = 1; //smth like counter?
    int r4 = r5; //smth like counter?
    
    int r8 = 0x00BDFBF0 ; //1BF0
    int r9 = 0x00C17BC9; //sub_C17BC8
    int r10 = 0x00C17BD5; //sub_C17BD4
    
    //loc_C190AE:
    while(true)
    {
        int r5 = r4 & 0xFF;
        if(r5 == 0)
        {
            r7 = r7 + 1;
            r4 = r4 + 1;
            continue; //continue cycle
        }
        else if(r5 == 4)
        {
            //loc_C1930C:
            int r0 = 0xB;
            //STRD.W		R1, R2,	[SP,#0x14]
            int r0 = SceSdstor.SceSysrootForDriver._imp_check_sysroot_buffer_84_8aa268d6();
            //LDRD.W		R1, R2,	[SP,#0x14]
            
            if(r0 == 0)
               break;
                
            int r6 = 0x00BDFC20; //1C20
            r8[0x30] = r10;
            r8[0x34] = r9;
            r8[0x38] = r5;
            
            //loc_C190DA:
            r6[9] = (char)r2;
            r6[0xA] = (char)r1;
            
            if(r7 == 5)
               break;
            
            r7 = r7 + 1;
            r4 = r4 + 1;
            continue; //continue cycle
        }
        else
        {
            int r3 = r5 + r5 * 2; // (ctr + ctr * 2)
            int r6 = r8 + r3 * 4; // r8 + ((ctr + ctr * 2) * 4); 0 , C, 18 - calculates ctr * C offset
            
            r8[r3 * 4] = r10;
            r6[4] = r9;
            r6[8] = r5;
            
            if(r5 == 2)
            {
                r6[9] = r2;
                r6[0xA] = r1;
                
                r7 = r7 + 1;
                r4 = r4 + 1;
                continue; //continue cycle
            }
            else if(r5 == 3)
            {
                r6[9] = r2;
                r6[0xA] = r1;
                
                r7 = r7 + 1;
                r4 = r4 + 1;
                continue; //continue cycle
            }
            else
            {
                //loc_C190DA:
                r6[9] = (char)r2;
                r6[0xA] = (char)r1;
                
                if(r7 == 5)
                   break;
                
                r7 = r7 + 1;
                r4 = r4 + 1;
                continue; //continue cycle
            }
        }
    }
    
    //=========================
    
    //loc_C190E4:
    int r1 = 0;
    int r0 = 0x00BDFC2C; //1C2C
    int r2 = 0x8C;
    SceSdstor.SceSysclibForDriver._imp_memset_0ab9bf5c(r0, r1, r2);

    int r4 = r1;
    int r10 = 0x00BDFC2C; //1C2C
    int r9 = 0x00C1A17C; // "SceSdstorIntr"
    int r8 = 0x00C18651; //proc_SceSdstorIntr_thread_callback_C18650

    int r12 = r4;
    int r6 = 1; //counter ?

    //loc_C19112:
    while(true)
    {
        int r5 = r4 & 0xFF;
        if(r5 == 0)
        {
            r6 = r6 + 1;
            r4 = r4 + 1;
            continue; //continue cycle
        }
        else if if(r5 == 4)
        {
            //loc_C192E8:
            int r0 = 0xB;
            var_48 = r12;
            int r0 = SceSdstor.SceSysrootForDriver._imp_check_sysroot_buffer_84_8aa268d6();
            int r12 = var_48;
            
            if(r0 == 0)
               break;
        }

        //loc_C19120:
        int r3 = r5 * 8 - r5;
        int lr = 0x80000;
        attr = r12;
        int r2 = 0x1C; //priority
        int r5 = r10 + r3 * 4;

        var_5C = lr; //arg5
        var_58 = r12; //arg6

        int r0 = "SceSdstorIntr";

        r10[r3*4] = r9;

        int r1 = &proc_SceSdstorIntr_thread_callback_C18650;
        int r3 = 0x2000; //stack size

        r5[4] = r8;
        r5[4 + 4] = r2;

        r5[0x0C] = r3;
        r5[0x0C + 4] = r12;

        r4[0x14] = lr;

        var_48 = r12;

        int r0 = SceSdstor.SceThreadmgrForDriver._imp_sceKernelCreateThreadForKernel_c6674e7d(r0,r1,r2,r3, attr);

        if(r0 <= 0)
            return exit_loc_C192B0(r0, var_2C);
            
        int r12 = r12;

        r5[0x18] = r0;

        if(r6 == 5)
           break;
        
        r6 = r6 + 1;
        r4 = r4 + 1;
        continue; //continue cycle
    }
    
    //=========================
    
    //loc_C19174:
    int r7 = 0x00BDFC2C; //1C2C
    int r10 = &dword_C1A510;

    var_40 = r7;

    int r12 = 0x00BDFB20; //1B20     
    int r7 = 0x00BDFBF0; //1BF0
    int r6 = 1;
    int r4 = 0;

    var_3C = r12;
    var_44 = r7;

    //loc_C191A0:
    while(true)
    {
        int r7 = r4 & 0xFF;
        if(r7 == 0)
        {
            r6 = r6 + 1;
            r4 = r4 + 1;
            continue; //continue cycle
        }
        else if(r7 == 4)
        {
            //loc_C192FE:
            int r0 = 0xB;
            int r0 = SceSdstor.SceSysrootForDriver._imp_check_sysroot_buffer_84_8aa268d6();
            if(r0 == 0)
               break;
        }

        //loc_C191AE:
        int r1 = 0;
        int r0 = "SceSdstorRequest";
        int r2 = r1;
        int r3 = r1;
        var_30 = (char)r7;
        int r8 = r10[r7];
        int r0 = SceSdstor.SceThreadmgrForDriver._imp_ksceKernelCreateEventFlag_4336baa4(r0,r1,r2,r3);
        int r9 = r0 - 0;
        if(r9 < 0)
        {
            int r0 = R9;
            return exit_loc_C192B0(r0, var_2C);
        }

        int r1 = 0;
        int r0 = "SceSdstorOpSync";
        int r2 = r1;
        int r3 = r1;
        int r0 = SceSdstor.SceThreadmgrForDriver._imp_ksceKernelCreateEventFlag_4336baa4(r0,r1,r2,r3);
        int r2 = r0 - 0;
        if(r2 < 0)
        {
            int r0 = r2;
            return exit_loc_C192B0(r0, var_2C);
        }

        int r12 = var_44;
        int r8 = r8 + r8 * 2;
        int r5 = r7 + r7 * 4;
        int r3 = r7 * 8 - r7;

        int lr = var_30;
        var_38 = r8;
        int r7 = r12 + r8 * 4;

        int r12 = var_3C;
        int r8 = &dword_C1A508;
        int r0 = r7[8];

        int r1 = (char)r7[0xA];
        int r5 = r12 + r5 * 8;
        int r12 = var_40;

        r5[8] = r2;
        r5[8+4] = r7;

        int r3 = r12 + r3 * 4;
        r5[4] = r9;
        int r0 = r8[r0];

        var_34 = r3;
        int r3 = 0;
        var_34 = r2;
        r5[0x24] = lr;
        r5[0x25] = r3;
        r5[0x10] = r2;

        r5[0x26] = r3;
        r5[0x14] = r3;
        r5[0x14 + 4] = r3;
        r5[0x1C] = r3;
        r5[0x1C + 4] = r3;
        int r0 = SceSdstor.SceIntrmgrForDriver._imp_disable_interrupt_259c6d9e(r0);
        if(r0 > 0)
        {
            int r3 = r7[8];
            int r1 = r7[9];
            int r0 = r8[r3];
            int r0 = SceSdstor.SceIntrmgrForDriver._imp_disable_interrupt_259c6d9e(r0);
        }

        int r0 = r7[8];
        int r2 = "SceSdstorCardInsert"; //name

        int r12 = var_38;
        int lr = var_44;
        int r1 = r7[9];
        int r8 = r8[r0];
        int r3 = lr[r12*4]; //func
        attr = r5; //priority ?
        int r0 = r8; //code
        int r0 = SceSdstor.SceIntrmgrForDriver._imp_register_interrupt2_96576c18(r0,r1,r2,r3,arg4);
        if(r0 < 0)
            return exit_loc_C192B0(r0, var_2C);
            
        int r2 = "SceSdstorCardRemove"
        int r1 = r7[0xA];
        int r3 = r7[4];
        int r0 = r8;
        attr = r5; //priority ?
        int r0 = SceSdstor.SceIntrmgrForDriver._imp_register_interrupt2_96576c18(r0,r1,r2,r3, arg4);
        if(r0 < 0)
            return exit_loc_C192B0(r0, var_2C);
            
        int r7 = var_34;
        int r1 = 1;
        int r2 = var_30;
        int r0 = r7[0x18];
        int r0 = SceSdstor.SceThreadmgrForDriver._imp_sceKernelStartThreadForKernel_21f5419b(r0, r1, r2);
        if(r0 < 0)
            return exit_loc_C192B0(r0, var_2C);
            
        if(r6 == 5)
           break;
        
        r6 = r6 + 1;
        r4 = r4 + 1;
        continue; //continue cycle;
    }
    
    int r0 = 0;
    return exit_loc_C192B0(r0, var_2C);
}