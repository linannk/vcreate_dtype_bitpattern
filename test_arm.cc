#include <arm_neon.h>
#include <stdio.h>

int main(int argc, char** argv) {
  // init v to { 0.1, 0.2, 0.3, 0.4 }
  float32x4_t v = vcombine_f32(vcreate_f32(0x3e4ccccd3dcccccd),
                               vcreate_f32(0x3ecccccd3e99999a));

  float data[4];

  vst1q_f32(data, v);

  fprintf(stdout, "----------------f32----------------\n");
  fprintf(stdout, "%f %f %f %f\n",
    data[0], data[1], data[2], data[3]);

  fprintf(stdout, "----------------f64----------------\n");

  // init v64 to {0.1, 0.2}
  float64x2_t v64 = vcombine_f64(
    vcreate_f64(0x3fb999999999999a),
    vcreate_f64(0x3fc999999999999a)
  );

  double data64[2];

  vst1q_f64(data64, v64);
  fprintf(stdout, "%lf %lf\n", data64[0], data64[1]);

  return 0;
}

