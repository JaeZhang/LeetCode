/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    int i, j;
    int** res = (int**) malloc((*AColSizes) * sizeof(int*));
    *columnSizes = (int*) malloc ((*AColSizes) * sizeof(int));

    for (i = 0; i < *AColSizes; i ++) {
        res[i] = (int*) malloc (ARowSize * sizeof(int));
        (*columnSizes)[i] = ARowSize;
    }

    for (i = 0; i < ARowSize; i ++) {

        for (j = 0; j < *AColSizes; j ++) {
            res[j][i] = A[i][j];

        }
    }
    
    *returnSize = *AColSizes;
    return res;
}