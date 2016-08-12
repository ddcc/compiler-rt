// RUN: %clangxx_msan -O0 -g %s -o %t && %run %t
// REQUIRES: stable-runtime

// XFAIL: target-is-mips64el

#include <assert.h>
#include <malloc.h>

#include <sanitizer/msan_interface.h>

int main(void) {
  struct mallinfo mi = mallinfo();
  assert(__msan_test_shadow(&mi, sizeof(mi)) == -1);
  return 0;
}
