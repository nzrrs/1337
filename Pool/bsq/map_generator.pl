#!/usr/bin/perl
use strict;
use warnings;

# usage: perl map_generator.pl <size> [obstacle_density(0-100)] [empty] [full] [square]
# writes a valid, randomly generated bsq map to stdout

my $size    = shift @ARGV // 10;
my $density = shift @ARGV // 20;
my $empty   = shift @ARGV // '.';
my $full    = shift @ARGV // 'o';
my $square  = shift @ARGV // 'x';

die "size must be a positive integer\n" if $size !~ /^\d+$/ || $size <= 0;
die "density must be between 0 and 100\n" if $density < 0 || $density > 100;

print "$size$empty$full$square\n";
for my $row (1 .. $size) {
    my $line = '';
    for my $col (1 .. $size) {
        $line .= (int(rand(100)) < $density) ? $full : $empty;
    }
    print "$line\n";
}
