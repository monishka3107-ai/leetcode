#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    int count[26] = {0};
    int i = 0;
    for (; s[i] && t[i]; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    if (s[i] || t[i]) return false;   // different lengths
    for (int j = 0; j < 26; j++)
        if (count[j]) return false;
    return true;
}