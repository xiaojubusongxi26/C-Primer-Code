int projectionArea(int** grid, int gridSize, int* gridColSize){
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < gridSize; i++) {
        int maxX = 0, maxY = 0;
        for (int j = 0; j < *gridColSize; j++) {
            // ��x����ÿһ�е����
            if (grid[i][j] > maxX) {
                maxX = grid[i][j];
            }
            // ��y����ÿһ�е����
            if (grid[j][i] > maxY) {
                maxY = grid[j][i];
            }
            // ֻҪ�ڸ�λ���������壬�� + 1
            if (grid[i][j] > 0) {
                z += 1;
            }
        }
        x += maxX;
        y += maxY;
    }
    return x + y + z;
}