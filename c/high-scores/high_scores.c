#include "high_scores.h"
#include <stdint.h>
#include <stdlib.h>

int compare_scores(const void* a, const void* b);

int32_t latest(const int32_t *scores, size_t scores_len) {
	return scores[scores_len-1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
	int32_t best = scores[0];
	for (size_t i = 1; i < scores_len; i++) {
		if (best < scores[i]) {
			best = scores[i];
		}
	}
	return best;
}

int compare_scores(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {

	qsort((void *)scores, scores_len, sizeof(int32_t), compare_scores);
	
	size_t bests = 0;
	for (size_t i = 0; i < scores_len; i++) {
		output[i] = personal_best(scores, scores_len-i);
		bests++;
		if (bests == 3) {
			break;
		}
	}

	return bests;
}
