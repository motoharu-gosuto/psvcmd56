#include "ECDSA.h"

#include <string>

#include <openssl/obj_mac.h>
#include <openssl/ec.h>

#include <iostream>
#include <iomanip>

EC_GROUP *create_curve(const unsigned char a_bin[0x1C], const unsigned char b_bin[0x1C], const unsigned char p_bin[0x1C], const unsigned char order_bin[0x1C], const unsigned char x_bin[0x1C], const unsigned char y_bin[0x1C])
{
   EC_GROUP* result_curve = nullptr;

   BN_CTX* ctx;
   
   // Set up the BN_CTX
   if(NULL != (ctx = BN_CTX_new()))
   {
      BIGNUM* a; 

      //Set the values for the various parameters
      if(NULL != (a = BN_bin2bn(a_bin, 0x1C, NULL)))
      {
         BIGNUM* b; 

         if(NULL != (b = BN_bin2bn(b_bin, 0x1C, NULL)))
         {
            BIGNUM* p; 
            
            if(NULL != (p = BN_bin2bn(p_bin, 0x1C, NULL)))
            {
               BIGNUM* order; 
               
               if(NULL != (order = BN_bin2bn(order_bin, 0x1C, NULL)))
               {
                  BIGNUM* x; 

                  if(NULL != (x = BN_bin2bn(x_bin, 0x1C, NULL)))
                  {
                     BIGNUM* y;

                     if(NULL != (y = BN_bin2bn(y_bin, 0x1C, NULL)))
                     {
                        EC_GROUP* curve;

                        //Create the curve
                        if(NULL != (curve = EC_GROUP_new_curve_GFp(p, a, b, ctx)))
                        {
                           EC_POINT *generator;

                           //Create the generator
                           if(NULL != (generator = EC_POINT_new(curve)))
                           {
                              if(1 == EC_POINT_set_affine_coordinates_GFp(curve, generator, x, y, ctx))
                              {
                                 //Set the generator and the order
                                 if(1 == EC_GROUP_set_generator(curve, generator, order, NULL))
                                 {
                                    result_curve = curve;
                                 }
                              }

                              EC_POINT_free(generator);
                           }
                        }

                        BN_free(y);
                     }

                     BN_free(x);
                  }

                  BN_free(order);
               }
               
               BN_free(p);
            }

            BN_free(b);
         }

         BN_free(a);
      }

      BN_CTX_free(ctx);
   }

   return result_curve;
}

int print_bignum(const BIGNUM* b)
{
   unsigned char bc[0x1C];

   BN_bn2bin(b, bc);

   for(int i = 0; i < 0x1C; i++)
   {
      std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)bc[i];
   }

   std::cout << std::endl;

   return 0;
}

int ec_field_inverse_mod_ord(const EC_GROUP *curve, BIGNUM *res, const BIGNUM *x, BN_CTX *ctx)
{
   const BIGNUM* order = EC_GROUP_get0_order(curve);
   BN_MONT_CTX* mont_data = EC_GROUP_get_mont_data(curve);

   BIGNUM* e = NULL;
    
   int result = 0;

   BN_CTX_start(ctx);

   if (NULL != (e = BN_CTX_get(ctx)))
   {
      // We want inverse in constant time, therefore we utilize the fact
      // order must be prime and use Fermats Little Theorem instead.
    
      if (BN_set_word(e, 2) == 1)
      {
         if (BN_sub(e, order, e) == 1)
         {
             // Exponent e is public.
             // No need for scatter-gather or BN_FLG_CONSTTIME.
    
             if (BN_mod_exp_mont(res, x, e, order, ctx, mont_data) == 1)
             {
                result = 1;
             }
         }
      }
   }

   BN_CTX_end(ctx);

   return result;
}

int ec_group_do_inverse_ord(const EC_GROUP *curve, BIGNUM *res, const BIGNUM *x, BN_CTX *ctx)
{
    return ec_field_inverse_mod_ord(curve, res, x, ctx);
}

int ecdsa_verify(ecdsa_signature *sig, unsigned char M[0x1C], const ecdsa_point* Qa, const ecdsa_params* params)
{
   int result = -1;

   EC_GROUP* curve = create_curve(params->A, params->B, params->P, params->N, params->G.X, params->G.Y);

   if(curve != NULL)
   {
      EC_KEY* key = EC_KEY_new();

      if(key != NULL)
      {
         if(EC_KEY_set_group(key, curve) == 1)
         {
            EC_POINT* qa;

            if(NULL != (qa = EC_POINT_new(curve)))
            {
               BIGNUM* qax;

               if(NULL != (qax = BN_bin2bn(Qa->X, 0x1C, NULL)))
               {
                  BIGNUM* qay;

                  if(NULL != (qay = BN_bin2bn(Qa->Y, 0x1C, NULL)))
                  {
                     if(EC_KEY_set_public_key_affine_coordinates(key, qax, qay) == 1)
                     {
                        BIGNUM* r;

                        if(NULL != (r = BN_bin2bn(sig->r, 0x1C, NULL)))
                        {
                           BIGNUM* s;
                           if(NULL != (s = BN_bin2bn(sig->s, 0x1C, NULL)))
                           {
                              ECDSA_SIG* signature = ECDSA_SIG_new();
                              if(signature != NULL)
                              {
                                 ECDSA_SIG_set0(signature, r, s);

                                 int ver_res = ECDSA_do_verify(M, 0x1C, signature, key);

                                 if(ver_res == 1)
                                 {
                                    //std::cout << "signature is valid" << std::endl;
                                    result = 0;
                                 }
                                 else if(ver_res == 0)
                                 {
                                    //std::cout << "signature is invalid" << std::endl;
                                    result = -1;
                                 }
                                 else
                                 {
                                    //std::cout << "unknown error" << std::endl;
                                    result = -1;
                                 }

                                 ECDSA_SIG_free(signature);
                              }

                              BN_free(s);
                           }

                           BN_free(r);
                        }
                     }

                     BN_free(qay);
                  }

                  BN_free(qax);
               }

               EC_POINT_free(qa);
            }
         }

         EC_KEY_free(key);
      }

      EC_GROUP_free(curve);
   }

   return result;
}

int ecdsa_sign(unsigned char M[0x1C], unsigned const char* Pk, const ecdsa_params* params, const unsigned char nonce[0x1C], ecdsa_signature* sig_res)
{
   int result = -1;

   EC_GROUP* curve = create_curve(params->A, params->B, params->P, params->N, params->G.X, params->G.Y);

   if(curve != NULL)
   {
      EC_KEY* key = EC_KEY_new();

      if(key != NULL)
      {
         if(EC_KEY_set_group(key, curve) == 1)
         {
            BIGNUM* pk;

            if(NULL != (pk = BN_bin2bn(Pk, 0x1C, NULL)))
            {
               if(EC_KEY_set_private_key(key, pk) == 1)
               {
                  BIGNUM* k = BN_secure_new();

                  if(k != NULL)
                  {
                     BIGNUM* r = BN_new();

                     if(r != NULL)
                     {
                        BIGNUM* X = BN_new();

                        if(X != NULL)
                        {
                           EC_POINT* tmp_point;

                           if(NULL != (tmp_point = EC_POINT_new(curve)))
                           {
                              const BIGNUM* order = EC_GROUP_get0_order(curve);
                              int order_bits = BN_num_bits(order);

                              if(BN_set_bit(k, order_bits) == 1)
                              {
                                 if(BN_set_bit(r, order_bits) == 1)
                                 {
                                    if(BN_set_bit(X, order_bits) == 1)
                                    {
                                       BN_CTX* ctx = BN_CTX_new();

                                       if(NULL != ctx)
                                       {
                                          // initialize nonce

                                          if(NULL != (BN_bin2bn(nonce, 0x1C, k)))
                                          {
                                             // compute tmp_point = generator * k
                                             if (EC_POINT_mul(curve, tmp_point, k, NULL, NULL, ctx) == 1)
                                             {
                                                // get coodrinates into X
                                                if (EC_POINT_get_affine_coordinates(curve, tmp_point, X, NULL, ctx) == 1)
                                                {
                                                   // calculate r
                                                   if (BN_nnmod(r, X, order, ctx) == 1)
                                                   {
                                                      // calculate k
                                                      if (ec_group_do_inverse_ord(curve, k, k, ctx) == 1)
                                                      {
                                                         BIGNUM* rp = r;
                                                         BIGNUM* kinvp = k;

                                                         ECDSA_SIG* signature = ECDSA_do_sign_ex(M, 0x1C, kinvp, rp, key);

                                                         if(signature != NULL)
                                                         {
                                                            const BIGNUM* r_sig = ECDSA_SIG_get0_r(signature);
                                                            
                                                            if(BN_bn2bin(r_sig, sig_res->r) == 0x1C)
                                                            {
                                                               const BIGNUM* s_sig = ECDSA_SIG_get0_s(signature);

                                                               if(BN_bn2bin(s_sig, sig_res->s) == 0x1C)
                                                               {
                                                                  std::cout << "rp:" << std::endl;
                                                                  print_bignum(rp);
                                                                  std::cout << "kinvp:" << std::endl;
                                                                  print_bignum(kinvp);
                                                                  std::cout << "r_sig:" << std::endl;
                                                                  print_bignum(r_sig);
                                                                  std::cout << "s_sig:" << std::endl;
                                                                  print_bignum(s_sig);
                                                            

                                                                  result = 0;
                                                               }
                                                            }
                                                         }

                                                         ECDSA_SIG_free(signature);
                                                      }
                                                   }
                                                }
                                             }
                                          }

                                          BN_CTX_free(ctx);
                                       }
                                    }
                                 }
                              }
                              
                              EC_POINT_free(tmp_point);
                           }

                           BN_clear_free(X);
                        }

                        BN_clear_free(r);
                     }

                     BN_clear_free(k);
                  }
               }

               BN_free(pk);
            }
         }

         EC_KEY_free(key);
      }

      EC_GROUP_free(curve);
   }

   return result;
}

int ecc_multiply(const ecdsa_params* params, const ecdsa_point* input, const unsigned char multiplier[0x1C], ecdsa_point* output)
{
   int result = -1;

   EC_GROUP* curve = create_curve(params->A, params->B, params->P, params->N, params->G.X, params->G.Y);

   if(curve != NULL)
   {
      EC_POINT* input_curve_point;

      if(NULL != (input_curve_point = EC_POINT_new(curve)))
      {
         BIGNUM* input_curve_point_x_bn;

         if(NULL != (input_curve_point_x_bn = BN_bin2bn(input->X, 0x1C, NULL)))
         {
            BIGNUM* input_curve_point_y_bn;

            if(NULL != (input_curve_point_y_bn = BN_bin2bn(input->Y, 0x1C, NULL)))
            {
               BN_CTX* ctx = BN_CTX_new();

               if(NULL != ctx)
               {
                  if(EC_POINT_set_affine_coordinates(curve, input_curve_point, input_curve_point_x_bn, input_curve_point_y_bn, ctx) == 1)
                  {
                     BIGNUM* multiplier_bn;

                     if(NULL != (multiplier_bn = BN_bin2bn(multiplier, 0x1C, NULL)))
                     {
                        EC_POINT* tmp_point;

                        if(NULL != (tmp_point = EC_POINT_new(curve)))
                        {
                           if (EC_POINT_mul(curve, tmp_point, NULL, input_curve_point, multiplier_bn, ctx) == 1)
                           {
                              BIGNUM* output_curve_point_x = BN_new();

                              if(output_curve_point_x != NULL)
                              {
                                 BIGNUM* output_curve_point_y = BN_new();

                                 if(output_curve_point_y != NULL)
                                 {
                                    if (EC_POINT_get_affine_coordinates(curve, tmp_point, output_curve_point_x, output_curve_point_y, ctx) == 1)
                                    {
                                       if(BN_bn2bin(output_curve_point_x, output->X) == 0x1C)
                                       {
                                          if(BN_bn2bin(output_curve_point_y, output->Y) == 0x1C)
                                          {
                                             std::cout << "rp:" << std::endl;
                                             print_bignum(output_curve_point_x);
                                             std::cout << "kinvp:" << std::endl;
                                             print_bignum(output_curve_point_y);
                                          
                                             result = 0;
                                          }
                                       }
                                    }

                                    BN_clear_free(output_curve_point_y);
                                 }

                                 BN_clear_free(output_curve_point_x);
                              }
                           }

                           EC_POINT_free(tmp_point);
                        }

                        BN_free(multiplier_bn);
                     }

                  }

                  BN_CTX_free(ctx);
               }

               BN_free(input_curve_point_y_bn);
            }

            BN_free(input_curve_point_x_bn);
         }

         EC_POINT_free(input_curve_point);
      }

      EC_GROUP_free(curve);
   }

   return result;
}

int ecc_modulus(const unsigned char* nonce, int nonce_size, const unsigned char* N, int N_size, unsigned char* output)
{
   int result = -1;

   BN_CTX* ctx = BN_CTX_new();

   if(NULL != ctx)
   {
      BIGNUM* nonce_bn;

      if(NULL != (nonce_bn = BN_bin2bn(nonce, nonce_size, NULL)))
      {
         BIGNUM* N_bn;

         if(NULL != (N_bn = BN_bin2bn(N, N_size, NULL)))
         {
            BIGNUM* rem = BN_new();

            if(BN_mod(rem, nonce_bn, N_bn, ctx) == 1)
            {
               if(BN_bn2bin(rem, output) == N_size)
               {
                  result = 0;
               }

               BN_free(rem);
            }

            BN_free(N_bn);
         }

         BN_free(nonce_bn);
      }

      BN_CTX_free(ctx);
   }

   return result;
}