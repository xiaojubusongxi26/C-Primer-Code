#include <stdio.h>
int deleteMin (int*arr, int length) {
	if (length == 0) {
		printf("数组为空!\n");
		return -1;
	}
	int min = 9999, index = 0;
	int i = 0;
	for(; i < length; i++) {
		if (arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}
	arr[index] = arr[length - 1];
	return min;
}
void re (int * arr, int length) {
	if (length == 0) {
		printf("数组为空!\n");
		return;
	}
	int i = 0;
	for(; i < length / 2; i++) {
		int t = arr[i];
		arr[i] = arr[length - i - 1];
		arr[length - i - 1] = t;
	}
}
int main() {
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    re(arr, 9);
    int i;
    for (i = 0; i < 9; i++) {
    	printf("%d ", arr[i]);
	}
    return 0;
}