import 'package:flutter/foundation.dart';

// This is useful for operations that take longer than a few milliseconds
// compute work like await
void main() async {
  print(await factorial(15));
}

Future<int> factorial(int value) {
  return compute(calculate, value);
}

int calculate(int value) {
  int res = 1, i;
  for (i = 2; i <= value; i++) {
    res *= i;
  }
  return res;
}
