#include "test_framework/generic_test.h"

long long SwapBits(long long x, int i, int j) {
  if (
    ((x >> i) & 0x1) == ((x >> j) & 0x1)
  ) return x;

  x ^= 1L << i;
  x ^= 1L << j;

  return x;
}

unsigned long long ReverseBits(unsigned long long x) {

  for (int i=0; i < 64/2; i++) {
    x = SwapBits(x, i, 63 - i);
  }

  return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
