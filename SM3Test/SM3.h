//
//  SM3.hpp
//  TestSM3
//
//  Created by iOS Developer on 2017/6/14.
//  Copyright © 2017年 Bankeys. All rights reserved.
//

//Testing data from SM3 Standards
//http://www.oscca.gov.cn/News/201012/News_1199.htm
// Sample 1
// Input:"abc"
// Output:66c7f0f4 62eeedd9 d1f2d46b dc10e4e2 4167c487 5cf2f7a2 297da02b 8f4ba8e0

// Sample 2
// Input:"abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcd"
// Outpuf:debe9ff9 2275b8a1 38604889 c18e5a4d 6fdb70e5 387e5765 293dcba3 9c0c5732


#ifndef SM3_h
#define SM3_h

#include <stdio.h>
#include <string.h>

/**
 * \brief          SM3 context structure
 */
typedef struct
{
    uint32_t total[2];     /*!< number of bytes processed  */
    uint32_t state[8];     /*!< intermediate digest state  */
    unsigned char buffer[64];   /*!< data block being processed */
    
    unsigned char ipad[64];     /*!< HMAC: inner padding        */
    unsigned char opad[64];     /*!< HMAC: outer padding        */
    
}
sm3_context;

#ifdef __cplusplus
extern "C" {
#endif
    
    /**
     * \brief          SM3 context setup
     *
     * \param ctx      context to be initialized
     */
    void sm3_starts( sm3_context *ctx );
    
    /**
     * \brief          SM3 process buffer
     *
     * \param ctx      SM3 context
     * \param input    buffer holding the  data
     * \param ilen     length of the input data
     */
    void sm3_update( sm3_context *ctx, unsigned char *input, int ilen );
    
    /**
     * \brief          SM3 final digest
     *
     * \param ctx      SM3 context
     */
    void sm3_finish( sm3_context *ctx, unsigned char output[32] );
    
    /**
     * \brief          Output = SM3( input buffer )
     *
     * \param input    buffer holding the  data
     * \param ilen     length of the input data
     * \param output   SM3 checksum result
     */
    void sm3( unsigned char *input, int ilen,
             unsigned char output[32]);
    
    /**
     * \brief          Output = SM3( file contents )
     *
     * \param path     input file name
     * \param output   SM3 checksum result
     *
     * \return         0 if successful, 1 if fopen failed,
     *                 or 2 if fread failed
     */
    int sm3_file( char *path, unsigned char output[32] );
    
    /**
     * \brief          SM3 HMAC context setup
     *
     * \param ctx      HMAC context to be initialized
     * \param key      HMAC secret key
     * \param keylen   length of the HMAC key
     */
    void sm3_hmac_starts( sm3_context *ctx, unsigned char *key, int keylen);
    
    /**
     * \brief          SM3 HMAC process buffer
     *
     * \param ctx      HMAC context
     * \param input    buffer holding the  data
     * \param ilen     length of the input data
     */
    void sm3_hmac_update( sm3_context *ctx, unsigned char *input, int ilen );
    
    /**
     * \brief          SM3 HMAC final digest
     *
     * \param ctx      HMAC context
     * \param output   SM3 HMAC checksum result
     */
    void sm3_hmac_finish( sm3_context *ctx, unsigned char output[32] );
    
    /**
     * \brief          Output = HMAC-SM3( hmac key, input buffer )
     *
     * \param key      HMAC secret key
     * \param keylen   length of the HMAC key
     * \param input    buffer holding the  data
     * \param ilen     length of the input data
     * \param output   HMAC-SM3 result 
     */  
    void sm3_hmac( unsigned char *key, int keylen,  
                  unsigned char *input, int ilen,  
                  unsigned char output[32] );  
    
    
#ifdef __cplusplus  
}  
#endif  

#endif /* SM3_hpp */
