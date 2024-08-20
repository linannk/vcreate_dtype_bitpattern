#include <arm_neon.h>
#include <stdio.h>

int main(int argc, char** argv) {
  // init v to { 0.1, 0.2, 0.3, 0.4 }
  float32x4_t v = vcombine_f32(vcreate_f32(0x3e4ccccd3dcccccd),
                               vcreate_f32(0x3ecccccd3e99999a));

  float data[4];

  vst1q_f32(data, v);

  fprintf(stdout, "%f %f %f %f\n",
    data[0], data[1], data[2], data[3]);
  return 0;
}

