# This file provides appropriate compilation flags as environment variables (e.g. WALI_CC, WALI_LD, WALI_CFLAGS, WALI_LDFLAGS)
source wali_config.sh
$WALI_CC $WALI_CFLAGS $WALI_LDFLAGS memtest.c -o memtest.wasm
