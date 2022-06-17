void duplicateZeros(int* arr, int arrSize){
    int* ret = (int*)malloc(sizeof(int) * arrSize);
    int len = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 0) {
            printf("%d\n", arr[i]);
            ret[len++] = arr[i];
            if (len >= arrSize) {
                break;
            }
            ret[len++] = arr[i];
        } else {
            ret[len++] = arr[i];
        }
        if (len >= arrSize) {
            break;
        }
    }
    for (int i = 0; i < arrSize; i++) {
        arr[i] = ret[i];
    }
}