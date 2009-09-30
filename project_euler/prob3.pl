#!/usr/bin/perl
my $total = 600851475143;
my $limit = 775150; #approx sqrt
my $i = 2;
my @cands = (1..$limit);

while($i < $limit) {
  $k = $i;
  while($k < $limit && $cands[$i-1] >0) {
    $k += $i;
    $cands[$k-1] = 0;
  }
  $i++;
}

my $top = 0;
foreach $pot(@cands) {
  $i = $pot;
  if ($pot > 0 && $total % $pot ==0 && $pot > $top) {
    $top = $pot;
  }
}

print "$top\n";


