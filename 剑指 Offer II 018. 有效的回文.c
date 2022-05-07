bool isPalindrome(char * s){
    int left = 0, right = strlen(s) - 1;
    while (left < right) {
        if (isalpha(s[left]) || isdigit(s[left])) {
            s[left] = tolower(s[left]);
        } else {
            left++;
            continue;
        }
        if (isalpha(s[right]) || isdigit(s[right])) {
            s[right] = tolower(s[right]);
        } else {
            right--;
            continue;
        }
        if (s[left] == s[right]) {
            left++;
            right--;
            continue;
        } else {
            return false;
        }
    }
    printf("%d %d", left, right);
    if (s[left] == s[right]) {
        return true;
    } else {
        return false;
    }
}