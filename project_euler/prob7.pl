#!/usr/bin/perl
my $total = 600851475143;
my $limit = 775150; #approx sqrt
my $i = 2;
my $primes;
my @cands = (1..$limit);
#sieve of eratosthenes
#
while($i < ($limit/2)) {
  $k = $i;
  while($k < $limit && $cands[$i-1] >0) {
    $k += $i;
    $cands[$k-1] = 0;
  }
  $i++;
}

my $top = 0;
foreach $pot(@cands) {
  if ($pot > 0) {
    $top = $pot;
    $primes++;
    if ($primes == 10002) {#find 10001st prime, skipping 2, so add one
      print "$top\n";
      break;
    }
  }
}

#print "$top\n";


