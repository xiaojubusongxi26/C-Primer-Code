/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs (int row, int col, bool ** ocean, const int ** heights, int m, int n) {
    if (ocean[row][col]) {
        return;
    }
    ocean[row][col] = true;
    for (int i = 0; i < 4; i++) {
        int newRow = row + dirs[i][0], newCol = col + dirs[i][1];
        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col]) {
            dfs(newRow, newCol, ocean, heights, m, n);
        }
    }
}
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes){
    int m =heightsSize;
    int n = heightsColSize[0];
    // ��������̫ƽ��ʹ�����ĵ���
    bool ** pacific = (bool **)malloc(sizeof(bool*) * m);
    bool ** atlantic = (bool **)malloc(sizeof(bool*) * m);
    for (int i = 0; i < m; i++) {
        pacific[i] = (bool*)malloc(sizeof(bool) * n);
        atlantic[i] = (bool*)malloc(sizeof(bool) * n);
        memset(pacific[i], 0, sizeof(bool) * n);
        memset(atlantic[i], 0, sizeof(bool) * n);
    }

    // ����߽翪ʼѰ���ܽ���̫ƽ��ĵ���
    for (int i = 0; i < m; i++) {
        dfs(i, 0, pacific, heights, m, n);
    }
    // ���ϱ߽翪ʼ���ܽ���̫ƽ��ĵ���
    for (int j = 1; j < n; j++) {
        dfs(0, j, pacific, heights, m, n);
    }
    // ���ұ߽�Ѱ���ܽ��������ĵ���
    for (int i = 0; i < m; i++) {
        dfs(i, n - 1, atlantic, heights, m, n);
    }
    // ���±߽�Ѱ���ܽ��������ĵ���
    for (int j = 0; j < n - 1; j++) {
        dfs(m - 1, j, atlantic, heights, m, n);
    }

    int **result = (int **)malloc(sizeof(int*) * m * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * m * n);
    int pos = 0;
    for (int i = 0; i < m * n; i++) {
        result[i] = (int *)malloc(sizeof(int) * 2);
        (*returnColumnSizes)[i] = 2;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacific[i][j] && atlantic[i][j]) {
                result[pos][0] = i;
                result[pos][1] = j;
                pos++;
            }
        }
        free(pacific[i]);
        free(atlantic[i]);
    }
    free(pacific);
    free(atlantic);
    *returnSize = pos;
    return result;
}