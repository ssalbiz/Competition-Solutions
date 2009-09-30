#!/usr/bin/perl

#difference of sum of squares and square of sum

@list = (1..100);
$sqsum = 0;
foreach $i(@list) {
  $sqsum += $i;
}
$sqsum *= $sqsum;

$sumsq = scalar(@list)*(scalar(@list)+1)*(2*scalar(@list)+1)/6;

print $sqsum - $sumsq,"\n";
