char * defangIPaddr(char * address){
    int n = strlen(address);
    char * ans = (char*)malloc(sizeof(char) * (3 * n));
    int len = 0;
    for (int i = 0; i < n; i++) {
        ans[len++] = address[i];
        if (address[i + 1] == '.') {
            ans[len++] = '[';
            ans[len++] = address[i + 1];
            ans[len++] = ']';
            i++;
        }
    }
    ans[len] = '\0';
    return ans;
}