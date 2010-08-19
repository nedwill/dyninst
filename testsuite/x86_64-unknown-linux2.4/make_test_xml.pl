#!/usr/bin/perl

my %testResults;

my $crashed, $failed, $skipped, $passed;

while(<>)
{
    my($testname, $result) = /([\w]+).*result:.*?([\w]+)/;
    $testResults{$testname} = [] unless exists $testResults{$testName};
    push @{$testResults{$testname} }, $result;

    $crashed++ if($result eq "CRASHED");
    $failed++ if($result eq "FAILED");
    $skipped++ if($result eq "SKIPPED");
    $passed++ if($result eq "PASSED");
}

my $errors = $crashed + $skipped;
my $total = $errors + $failed + $passed;
print "<testsuite errors=\"$errors\" failures=\"$failures\" tests=\"$tests\">\n";
foreach $k(keys %testResults)
{
    print "\t<testcase classname=\"global\" name=\"$k\">\n";
    foreach $r(@{$testResults{$k}})
    {
	if($r eq "FAILED")
	{
	    print "\t\t<failure>FAILED</failure>\n";
	}
	elsif($r ne "PASSED")
	{
	    print "\t\t<error>$r</error>\n";
	}
    }
    print "\t</testcase>\n";
}
print "</testsuite>\n";
