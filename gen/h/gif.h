// Code generated by puffs-gen-h. DO NOT EDIT.

// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file.

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Puffs requires a word size of at least 32 bits because it assumes that
// converting a u32 to usize will never overflow. For example, the size of a
// decoded image is often represented, explicitly or implicitly in an image
// file, as a u32, and it is convenient to compare that to a buffer size.
#if __WORDSIZE < 32
#error "Puffs requires a word size of at least 32 bits"
#endif

// PUFFS_VERSION is the major.minor version number as a uint32. The major
// number is the high 16 bits. The minor number is the low 16 bits.
//
// The intention is to bump the version number at least on every API / ABI
// backwards incompatible change.
//
// For now, the API and ABI are simply unstable and can change at any time.
//
// TODO: don't hard code this in preamble.h.
#define PUFFS_VERSION (0x00001)

#ifdef __cplusplus
extern "C" {
#endif

// ---------------- Status Codes

// Status codes are non-positive integers.
//
// The least significant bit indicates a fatal status code: an error.
typedef enum {
  puffs_gif_status_ok = 0,
  puffs_gif_error_bad_version = -1,
  puffs_gif_status_short_dst = -4,
  puffs_gif_status_short_src = -6,
} puffs_gif_status;

// ---------------- Structs

typedef struct {
  puffs_gif_status status;
  uint32_t magic;
  uint32_t f_literal_width;
  uint8_t f_stack[4096];
  uint8_t f_suffixes[4096];
  uint16_t f_prefixes[4096];
} puffs_gif_lzw_decoder;

// ---------------- Constructor and Destructor Prototypes

void puffs_gif_lzw_decoder_constructor(puffs_gif_lzw_decoder* self,
                                       uint32_t puffs_version);

void puffs_gif_lzw_decoder_destructor(puffs_gif_lzw_decoder* self);

#ifdef __cplusplus
}  // extern "C"
#endif