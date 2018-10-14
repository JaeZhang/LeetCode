/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes,int* returnSize) {
	if (r * c != numsRowSize * numsColSize) {
		r = numsRowSize;
		c = numsColSize;
	}

    int** res = (int**) malloc (r * sizeof(int*));
    * columnSizes = (int*) malloc (r * sizeof(int));
    for(int i = 0; i < r; i ++) {
    	res[i] = (int*) malloc (c * sizeof(int));
    	(*columnSizes)[i] = c;
    }


    for (int i = 0; i < r*c; i ++) {
    	res[i/c][i%c] = nums[i/numsColSize][i%numsColSize];
    }

    *returnSize = r;
    return res;

}