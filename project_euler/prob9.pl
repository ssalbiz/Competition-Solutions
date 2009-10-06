#!/usr/bin/perl

#for pythagorean triple
#a^2 + b^2 = c^2
#with additional constraint a + b + c = 1000
#
#using a = 2mn, b = m^2 - n^2, c = m^2 + n^2
#using simple substitution, this gives the result m(m+n) = 500
#this can be much more cheaply computed

for ($n = 1; $n < 500; $n++) {
  for ($m = $n; $m < 500; $m++) {
    if ($m * ($m + $n) == 500) {
      print 2*$m*$n*($m*$m + $n*$n)*($m*$m - $n*$n), "\n";
      exit
    }
  }
}

