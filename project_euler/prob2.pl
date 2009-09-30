#!/usr/bin/perl
$total = 2;
$fib1 = 2;
$fib2 = 1;
while($total < 4000000) {
  $tmp = $fib1;
  $fib1 = $fib1 + $fib2;
  $fib2 = $tmp;
  $total += ($fib1 % 2 == 0) ? $fib1:0;
  print "$fib1\n";
}

print "$total\n";
