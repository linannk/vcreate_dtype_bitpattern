#include <iostream>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  union xu {
    float f32;
    uint32_t u32;
  } x;

  for (int i = 0; i < argc; ++i) {
    if (0 == strcmp(argv[i], "-h") || 0 == strcmp(argv[i], "--help")) {
      fprintf(stderr, "%s V0 ... Vn\n", argv[0]);
      exit(0);
    }
  }

  fprintf(stdout, "---------------f32-------------\n");
  fprintf(stdout, "vcreate_f32(bitpattern)\n");
  fprintf(stdout, "vcombine_f32(float32x2_t, float32x2_t);\n");
  for (int i = 1; i < argc; ++i) {
    char *endptr;
    float f = strtof(argv[i], &endptr);
    x.f32 = f;

    fprintf(stdout, "[%d]: %f: 0x%08x\n", i - 1, x.f32, x.u32);
  }

  for (int i = 1; i < (argc - 1); i += 2) {
    xu x0, x1;
    char* endptr;

    x0.f32 = strtof(argv[i], &endptr);
    x1.f32 = strtof(argv[i + 1], &endptr);

    fprintf(stdout, "vcreate_f32(0x%08x%08x)\n", x1.u32, x0.u32);
  }

  fprintf(stdout, "---------------f64-------------\n");
  fprintf(stdout, "vcreate_f64(bitpattern)\n");
  fprintf(stdout, "vcombine_f64(float64x1_t, float64x1_t);\n");
  for (int i = 1; i < argc; ++i) {
    union {
      double f64;
      uint64_t u64;
    } fu64;
    char* endptr;
    fu64.f64 = strtod(argv[i], &endptr);

    fprintf(stdout, "[%d]: %lf: 0x%016lx vcreate_f64(0x%016lx)\n", i - 1,
            fu64.f64, fu64.u64, fu64.u64);
  }

  return 0;
}
