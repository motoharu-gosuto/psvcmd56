#include "SceMsifEcdsa.h"

#include <string>

#include <openssl/obj_mac.h>
#include <openssl/ec.h>

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

int ecdsa_verify_C8DA14_emu(ecdsa_signature *sig, unsigned char M[0x1C], const ecdsa_point* Qa, const ecdsa_params* params, int key_size_blocks, int key_size_bytes)
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

int ecdsa_verify_C8DBC0(ecdsa_signature* sig, unsigned char M[0x1C], const ecdsa_point* Qa, const ecdsa_params* params)
{
   //return ecdsa_verify_C8DA14(sig, M, Qa, params, 7, 0x1C);

   return ecdsa_verify_C8DA14_emu(sig, M, Qa, params, 7, 0x1C);
}