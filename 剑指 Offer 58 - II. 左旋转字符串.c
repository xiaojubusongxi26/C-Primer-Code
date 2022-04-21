void reverse(char* s, int left, int right){
    for(; left < right;){
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
}

char* reverseLeftWords(char* s, int n){
    int i, num;
    num = strlen(s);
    reverse(s,0,n-1);
    reverse(s,n,num-1);
    reverse(s,0,num-1);
    return s;
}
