char* kmp_strstr(char* txt, char* pattern);

char* kmp_strstr_dp(char* txt, char* pattern, void* dp);
void* dp_construct(char* pattern);
void dp_destroy(void* dp);
