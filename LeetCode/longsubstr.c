#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256

int lengthOfLongestSubstring(char *s){
    int n = strlen(s);
    int i = 0, j = 0;
    int maxLen = 0;
    int charMap[MAX_CHARS];
    memset(charMap, -1, sizeof(charMap));

    while (j < n) {
        if (charMap[s[j]] != -1) {
            i = fmax(i, charMap[s[j]] + 1);
        }
        charMap[s[j]] = j;
        maxLen = fmax(maxLen, j - i + 1);
        j++;
    }

    return maxLen;
}