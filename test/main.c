#include "../src/KMP.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char* txt1 = "aaababcabcbbccc";
    char* part1 = "abcabc";
    char* part2 = "ccc";

    //usage 1:
    printf("kmp result1 = %s\n", kmp_strstr(txt1, part1));
    printf("strstr result1 = %s\n", strstr(txt1, part1));

    //usage 2:
    void* dp = dp_construct(part2);
    printf("kmp result2 = %s\n", kmp_strstr_dp(txt1, part2, dp));
    printf("strstr result2 = %s\n", strstr(txt1, part2));
    dp_destroy(dp); //important!!

    return 0;
}