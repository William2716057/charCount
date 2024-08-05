#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//max string length
#define MAX_LENGTH 1000

//max pair number
#define MAX_PAIRS 100

typedef struct {
    char pair[3]; // Pair will be stored as a string of length 2 + null terminator
    int count;
} PairCount;

void add_or_increment_pair(PairCount pairs[], int *num_pairs, const char *pair) {
    for (int i = 0; i < *num_pairs; ++i) {
        if (strcmp(pairs[i].pair, pair) == 0) {
            pairs[i].count++;
            return;
        }
    }

//add new pairs to list
    if (*num_pairs < MAX_PAIRS) {
        strcpy(pairs[*num_pairs].pair, pair);
        pairs[*num_pairs].count = 1;
        (*num_pairs)++;
    }
}

//main
int main() {
    char str[MAX_LENGTH];
    PairCount pairs[MAX_PAIRS];
    int num_pairs = 0;

    // Read the input string
    printf("Enter the string of paired characters:\n");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

//remove newline char from input if present

str[strcspn(str, "\n")] = '\0';

    // Process the input string
    char *token = strtok(str, " ");
    while (token != NULL) {
        if (strlen(token) == 2) {
            add_or_increment_pair(pairs, &num_pairs, token);
        }
        token = strtok(NULL, " ");
    }
	//print results
    printf("Pair counts:\n");
    for (int i = 0; i < num_pairs; ++i) {
        printf("%s: %d\n", pairs[i].pair, pairs[i].count);
    }

    return 0;
}
