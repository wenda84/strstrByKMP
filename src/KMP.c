#include <string.h>  //strlen
#include <stdlib.h>  //malloc free

#define ASC_NUM 256

int kmp_search(char* txt, char* pattern, void* src_dp)
{
    if(0 == txt|| 0 == pattern ||0 == src_dp)
        return -1;

    int i = 0;
    int N = strlen(txt);
    int M = strlen(pattern);
    int (*dp)[ASC_NUM] = (void*)src_dp;

    // pat 的初始态为 0
    int stat = 0;
    for(;i < N; i++)
    {
        // 计算 pat 的下一个状态
        stat = dp[stat][(int)txt[i]];
        // 到达终止态，返回结果
        if (stat == M) return i - M + 1;
    }
    
    // 没到达终止态，匹配失败
    return -1;
}

void* dp_construct(char* pattern)
{
    if(0 == pattern)
        return 0;

    int j,c;
    int str_len = strlen(pattern);
    int dp_len  = str_len*ASC_NUM*sizeof(int);

    int(*dp)[ASC_NUM] = malloc(dp_len);
    if(0 == dp)
        return 0;

    memset(dp, 0, dp_len);

    // base case
    dp[0][(int)pattern[0]] = 1;
    int shadow_state = 0;    // 影子状态 X 初始为 0

    // 当前状态 j 从 1 开始
    for (j = 1; j < str_len; j++) {
        for (c = 0; c < 256; c++) {
            if ((int)(pattern[j]) == c)
                dp[j][c] = j + 1;
            else 
                dp[j][c] = dp[shadow_state][c];
        }

        // 更新影子状态
        shadow_state = dp[shadow_state][(int)(pattern[j])];
    }

    return dp;
}

void dp_destroy(void* dp)
{
    free(dp);
}

char* kmp_strstr_dp(char* txt, char* pattern, void* dp)
{
    if(0 == txt || 0 == pattern || 0 == dp )
        return 0;

    int result = kmp_search(txt, pattern, dp);
    if(-1 == result)
        return 0;

    return (char*)(txt + result);
}

char* kmp_strstr(char* txt, char* pattern)
{
    if(0 == txt || 0 == pattern)
        return 0;

    void* dp_tmp = dp_construct(pattern);
    if(!dp_tmp)
        return 0;
    
    int result =  kmp_search(txt, pattern, dp_tmp);
    free(dp_tmp);
    
    if(-1 == result)
        return 0;

    return (char*)(txt + result);
}

