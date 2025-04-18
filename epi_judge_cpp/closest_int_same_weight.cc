#include "test_framework/generic_test.h"

int getWeight (unsigned long long x) {
  int result = 0;
  for (int i = 0; i < 64; i++) {
    result += x & 0x1;
    x = x >> 1;
  }
  return result;
}

unsigned long long ClosestIntSameBitCount(unsigned long long x) {

  unsigned long long result = x;
  int target_weight = getWeight(x);
  bool searching = true;
  int i = 1;

  while (searching) {
    if (getWeight(x + i) == target_weight) return x + i;
    if (x-i >= 0 && getWeight(x - i) == target_weight) return x - i;

    i++;
  }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount,
                         DefaultComparator{}, param_names);
}
