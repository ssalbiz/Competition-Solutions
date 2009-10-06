#!/usr/bin/perl
my $limit = 2000000; #approx sqrt
my $i = 2;
my @cands = (1..$limit);
#sieve of eratosthenes to precompute primes

while($i < ($limit)) {
  $k = $i;
  while($k < $limit && $cands[$i-1] >0) {
    $k += $i;
    $cands[$k-1] = 0;
  }
  $i++;
}
@primes;
foreach $pot(@cands) {
  if ($pot > 1) {
    push(@primes, $pot);
  }
}
print "Finished Pre-computation\n";
my $total = 0;
$i = 1;
my $divisors = 1;
my @powers = ();
while ($divisors < 500) { #500 is the number of proper divisors being searched for
  $total += $i++;
  $divisors = 1;
  my $tmp = $total;
  my $power = 0;

  foreach $pr(@primes) {
    $power = 0;
    while ($tmp % $pr == 0 && $tmp >= $pr) {
      $power++; 
      $tmp /= $pr;
    }
    $divisors *= $power+1;
    if ($tmp == 1 || $tmp < $pr) { last; }
  }
}

print "$total\n";


