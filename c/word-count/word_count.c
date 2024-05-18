#include "word_count.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <regex.h>

/**
 * Test regex against string. Requires 2D char array large enough to store found matches.
 * 
 * @param source 
 * @param pattern 
 * @param matches 
 * @return int - Number of matches found
 */
int findall(const char *source, const char *pattern, char matches[][MAX_WORD_LENGTH]) {
	size_t count = 0;
	size_t maxMatches = 1024;
	size_t maxGroups = maxMatches;
  
	regex_t regexCompiled;
	regmatch_t groupArray[maxGroups];
	char * cursor = (char*)source;

	if (regcomp(&regexCompiled, pattern, REG_EXTENDED)) {
		printf("Could not compile regular expression.\n");
		return -1;
	}

	for (size_t m = 0; m < maxMatches; m ++) {
      if (regexec(&regexCompiled, cursor, maxGroups, groupArray, 0)) break;  // No more matches

		unsigned int offset = 0;
		for (size_t g = 0; g < maxGroups; g++) {
			if (groupArray[g].rm_so == -1) break;  // No more groups
			if (g == 0) offset = groupArray[g].rm_eo;
			
			char cursorCopy[strlen(cursor) + 1];

			strcpy(cursorCopy, cursor);
			cursorCopy[groupArray[g].rm_eo] = 0;

			int len = groupArray[0].rm_eo - groupArray[0].rm_so;
			memcpy(matches[m], cursorCopy + groupArray[0].rm_so, len);
			matches[m][len] = '\0';
			count++;
        }

      cursor += offset;
	}

	regfree(&regexCompiled);

	return count;
}

int key_exist(word_count_word_t *haystack, char *needle, int size) {
	for (int i = 0; i < size; i++) {
		if (strcmp(haystack[i].text, needle) == 0) {
			return i;
		}
	}
	return -1;
}

int count_words(const char *sentence, word_count_word_t *words) {
	if (sentence == NULL || words == NULL) {
		return -1;
	}

	char matches[MAX_WORDS][MAX_WORD_LENGTH];
	for (int i = 0; i < MAX_WORDS; i++) {
		memset(matches[i], '\0', MAX_WORD_LENGTH);
	}

	int i = 0;
	char text[strlen(sentence) + 1];
	for (i = 0; sentence[i] != '\0'; i++) {
		text[i] = tolower(sentence[i]);
	}
	text[i] = '\0';

	int size = findall(text, WORD_REGEX, matches);
	if (size == -1) {
		return -1;
	}
	
	int word_count = 0;
	int word_index = 0;
	
	for(int i = 0; i < size; i++) {
		if (strcmp(matches[i], "") != 0) {
			int key_index;
			if ((key_index = key_exist(words, matches[i], size)) == -1) {
				memcpy(words[word_index].text, matches[i], strlen(matches[i]));
				words[word_index].count = 1;
				word_index++;
				word_count++;
			} else {
				words[key_index].count++;
			}
		}
	}

	return word_count;
}

