#ifndef TD_APNG_H
#define TD_APNG_H

#include <sys/stat.h>  
#include <sys/types.h>    
#include <sys/stat.h>    
#include <fcntl.h>

typedef enum {
    YY_PNG_ALPHA_TYPE_PALEETE = 1 << 0,
    YY_PNG_ALPHA_TYPE_COLOR = 1 << 1,
    YY_PNG_ALPHA_TYPE_ALPHA = 1 << 2,
} yy_png_alpha_type;

typedef enum {
    YY_PNG_DISPOSE_OP_NONE = 0,
    YY_PNG_DISPOSE_OP_BACKGROUND = 1,
    YY_PNG_DISPOSE_OP_PREVIOUS = 2,
} yy_png_dispose_op;

typedef enum {
    YY_PNG_BLEND_OP_SOURCE = 0,
    YY_PNG_BLEND_OP_OVER = 1,
} yy_png_blend_op;

typedef struct {
    uint32_t width;             ///< pixel count, should not be zero
    uint32_t height;            ///< pixel count, should not be zero
    uint8_t bit_depth;          ///< expected: 1, 2, 4, 8, 16
    uint8_t color_type;         ///< see yy_png_alpha_type
    uint8_t compression_method; ///< 0 (deflate/inflate)
    uint8_t filter_method;      ///< 0 (adaptive filtering with five basic filter types)
    uint8_t interlace_method;   ///< 0 (no interlace) or 1 (Adam7 interlace)
} yy_png_chunk_IHDR;

typedef struct {
    uint32_t sequence_number;  ///< sequence number of the animation chunk, starting from 0
    uint32_t width;            ///< width of the following frame
    uint32_t height;           ///< height of the following frame
    uint32_t x_offset;         ///< x position at which to render the following frame
    uint32_t y_offset;         ///< y position at which to render the following frame
    uint16_t delay_num;        ///< frame delay fraction numerator
    uint16_t delay_den;        ///< frame delay fraction denominator
    uint8_t dispose_op;        ///< see yy_png_dispose_op
    uint8_t blend_op;          ///< see yy_png_blend_op
} yy_png_chunk_fcTL;

typedef struct {
    uint32_t offset; ///< chunk offset in PNG data
    uint32_t fourcc; ///< chunk fourcc
    uint32_t length; ///< chunk data length
    uint32_t crc32;  ///< chunk crc32
} yy_png_chunk_info;

typedef struct {
    uint32_t chunk_index; ///< the first `fdAT`/`IDAT` chunk index
    uint32_t chunk_num;   ///< the `fdAT`/`IDAT` chunk count
    uint32_t chunk_size;  ///< the `fdAT`/`IDAT` chunk bytes
    yy_png_chunk_fcTL frame_control;
} yy_png_frame_info;

typedef struct {
    yy_png_chunk_IHDR header;   ///< png header
    yy_png_chunk_info *chunks;      ///< chunks
    uint32_t chunk_num;          ///< count of chunks
    
    yy_png_frame_info *apng_frames; ///< frame info, NULL if not apng
    uint32_t apng_frame_num;     ///< 0 if not apng
    uint32_t apng_loop_num;      ///< 0 indicates infinite looping
    
    uint32_t *apng_shared_chunk_indexs; ///< shared chunk index
    uint32_t apng_shared_chunk_num;     ///< shared chunk count
    uint32_t apng_shared_chunk_size;    ///< shared chunk bytes
    uint32_t apng_shared_insert_index;  ///< shared chunk insert index
    TDBOOL apng_first_frame_is_cover;     ///< the first frame is same as png (cover)
} yy_png_info;

typedef struct {
	yy_png_info *png_info;
	int width;
	int height;
	int frame_num;
	int apngSize;
	char * apngData;
	HDC pCanvasDC;
} TDAPNG,*PTDAPNG;

#endif
