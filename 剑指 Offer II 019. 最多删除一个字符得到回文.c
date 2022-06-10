bool del (char *s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        } else {
            left++;
            right--;
        }
    }
    return true;
}
bool validPalindrome(char * s){
    int n = strlen(s);
    int left = 0, right = n - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return del(s, left + 1, right) || del(s, left, right - 1);
        } else {
            left++;
            right--;
        }
    }
    return true;
}