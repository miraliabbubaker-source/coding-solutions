#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize,
                    int r, int c, int* returnSize,
                    int** returnColumnSizes)
{
    if (matSize * matColSize[0] != r * c)
    {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }

    int **res = (int**)malloc(r * sizeof(int*));
    *returnColumnSizes = (int*)malloc(r * sizeof(int));

    for (int i = 0; i < r; i++)
    {
        res[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    *returnSize = r;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int k = i * c + j;
            res[i][j] = mat[k / matColSize[0]][k % matColSize[0]];
        }
    }

    return res;
}