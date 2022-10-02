import "dart:io";

main() {
  var num, factorial = 1;
  stdout.write("Enter a number");
  num = int.parse(stdin.readLineSync());

  for (int i = 1; i <= num; i++) {
    factorial = factorial * i;
  }
  print("Factorial of $num is $factorial");
}
