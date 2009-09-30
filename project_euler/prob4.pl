#!/usr/bin/perl
my $num1, $num2;

my $max = 0;
for ($num1 = 100; $num1 < 1000; $num1++) {
  for ($num2 = 100; $num2 < 1000; $num2++) {
	$res = $num1*$num2;
	if ($res > $max && "$res" eq reverse("$res")) {
	  $max = $res;
	}
  }
}
print "$max\n";


