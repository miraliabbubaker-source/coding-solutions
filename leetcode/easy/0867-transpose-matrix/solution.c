#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize,
                int* returnSize, int** returnColumnSizes)
{
    int m = matrixSize;
    int n = matrixColSize[0];

    int **ans = (int**)malloc(n * sizeof(int*));

    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        ans[i] = (int*)malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans[j][i] = matrix[i][j];
        }
    }

    return ans;
}