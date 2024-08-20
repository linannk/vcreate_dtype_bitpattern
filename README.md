# vcreate_dtype
Display the hex representation of float value. So `vcreate_dtype` can
be use to create a value from constant.

Example: initializing a vector `{ 0.1, 0.2, 0.3, 0.4 }`

```bash
$ ./vcreate_dtype_bitpattern 0.1 0.2 0.3 0.4
---------------f32-------------
vcreate_f32(bitpattern)
vcombine_f32(float32x2_t, float32x2_t);
[0]: 0.100000: 0x3dcccccd
[1]: 0.200000: 0x3e4ccccd
[2]: 0.300000: 0x3e99999a
[3]: 0.400000: 0x3ecccccd
vcreate_f32(0x3e4ccccd3dcccccd)
vcreate_f32(0x3ecccccd3e99999a)
---------------f64-------------
vcreate_f64(bitpattern)
vcombine_f64(float64x1_t, float64x1_t);
[0]: 0.100000: 0x3fb999999999999a vcreate_f64(0x3fb999999999999a)
[1]: 0.200000: 0x3fc999999999999a vcreate_f64(0x3fc999999999999a)
[2]: 0.300000: 0x3fd3333333333333 vcreate_f64(0x3fd3333333333333)
[3]: 0.400000: 0x3fd999999999999a vcreate_f64(0x3fd999999999999a)
```

In code we can write:
```c++
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
```

You can compile the above code for android platform for testing
```bash
$ ${path_to_standalone_toolchain}/bin/aarch64-linux-android-clang++ test_arm.cc -fPIC -fPIE -pie -o test_arm
$ adb push test_arm /data/local/tmp
$ adb shell /data/local/tmp/test_arm

----------------f32----------------
0.100000 0.200000 0.300000 0.400000
----------------f64----------------
0.100000 0.200000
```
