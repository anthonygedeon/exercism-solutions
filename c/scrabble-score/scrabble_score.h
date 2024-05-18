#ifndef SCRABBLE_SCORE_H
#define SCRABBLE_SCORE_H

typedef struct {
	char key;
	int  value;
} scrabble_score;

unsigned int score(const char *word);

#endif
