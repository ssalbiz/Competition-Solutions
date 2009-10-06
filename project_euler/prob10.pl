#!/usr/bin/perl
my $limit = 2000000; #approx sqrt
my $i = 2;
my @cands = (1..$limit);
#sieve of eratosthenes
#
while($i < ($limit)) {
  $k = $i;
  while($k < $limit && $cands[$i-1] >0) {
    $k += $i;
    $cands[$k-1] = 0;
  }
  $i++;
}

my $total = 0;
foreach $pot(@cands) {
  if ($pot > 1) {
    $total += $pot;
  }
}

print "$total\n";


