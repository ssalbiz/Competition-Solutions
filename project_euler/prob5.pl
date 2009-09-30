#!/usr/bin/perl

@list = (1..20);

for ($i = 0; $i < 19; $i++) {
  for ($k = $i+1; $k < 20; $k++) {
   if ($list[$k] % $list[$i] == 0) {
     $list[$k] = $list[$k]/$list[$i];
   }
  }
}
$total =1;
for ($i = 0; $i < 20; $i++) {
  $total *= $list[$i];
}

print "$total\n";
