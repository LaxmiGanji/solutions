#include <string.h>
#include <stdlib.h>

char * longestPalindrome(char * s){
    int len = strlen(s);
    if (len < 2) {
        return s;
    }

    int start = 0, end = 0;
    for (int i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = fmax(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    char *substr = (char *)malloc(sizeof(char) * (end - start + 2));
    for (int i = start; i <= end; i++) {
        substr[i - start] = s[i];
    }
    substr[end - start + 1] = '\0';

    return substr;
}

int expandAroundCenter(char *s, int left, int right) {
    int L = left, R = right;
    int len = strlen(s);
    while (L >= 0 && R < len && s[L] == s[R]) {
        L--;
        R++;
    }

    return R - L - 1;
}