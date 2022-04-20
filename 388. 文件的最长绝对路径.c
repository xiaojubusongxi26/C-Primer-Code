#define MAX(a, b) ((a) > (b) ? (a) : (b))
int lengthLongestPath(char * input){
    int n = strlen(input);
    int pos = 0, ans = 0;
    int* stack = (int*)malloc(sizeof(int) * n);
    int top = 0;

    while (pos < n) {
        int depth = 1;
        while (pos < n && input[pos] == '\t') {
            pos++;
            depth++;
        }
        bool isFile = false;
        int len = 0;
        while (pos < n && input[pos] != '\n') {
            if (input[pos] == '.') {
                isFile = true;
            }
            len++;
            pos++;
        }
        pos++;

        // 当当前的top值大于深度，回退
        while (top >= depth) {
            top--;
        }
        if (top > 0) {
            len += stack[top - 1] + 1;
        }
        if (isFile) {
            ans = MAX(ans, len);
        } else {
            stack[top++] = len;
        }
    }
    free(stack);
    return ans;
}