int firstUniqChar(char* s) {
    int i = 0;
    int j = 0;
    int check = 0;
    int ans = -1;

    for (i = 0; i < strlen(s); i++) {
        check = 0;

        for (j = 0; j < strlen(s); j++) {
            if (j == i) {
                continue;
            } 
            else if (s[i] == s[j]) {
                check = 1;
                break;
            }
        }

        if (check == 0) {
            ans = i;
            break;
        }
    }

    return ans;
}
