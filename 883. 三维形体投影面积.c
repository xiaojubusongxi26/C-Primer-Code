int projectionArea(int** grid, int gridSize, int* gridColSize){
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < gridSize; i++) {
        int maxX = 0, maxY = 0;
        for (int j = 0; j < *gridColSize; j++) {
            // 从x方向看每一列的最高
            if (grid[i][j] > maxX) {
                maxX = grid[i][j];
            }
            // 从y方向看每一行的最高
            if (grid[j][i] > maxY) {
                maxY = grid[j][i];
            }
            // 只要在该位置有立方体，就 + 1
            if (grid[i][j] > 0) {
                z += 1;
            }
        }
        x += maxX;
        y += maxY;
    }
    return x + y + z;
}