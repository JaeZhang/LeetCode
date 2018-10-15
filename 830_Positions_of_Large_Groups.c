/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char* S, int** columnSizes, int* returnSize) {
    int** res = (int**) malloc (1000 * sizeof(int*));
    int size = 0;
    int i = 0;
    int j = 0;
    while (S[i]) {
    	while (S[i] == S[j]) {
    		j ++;
    	}
    	if (j - i >= 3) {
    		res[size] = (int*) malloc (2 * sizeof(int));
    		res[size][0] = i;
    		res[size][1] = j - 1;
    		size ++;
    	}
    	i = j;

    }

    *returnSize = size;
    *columnSizes = (int*) malloc ((size) * sizeof(int));
    for (i = 0; i < size; i ++) {
    	(*columnSizes)[i] = 2;
    }
    return res;

}