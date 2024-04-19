//Axel Rodriguez
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26
// Trie structure
struct Trie
{
    struct TrieNode *children[ALPHABET_SIZE];
    int count;
    struct TrieNode *root
};

// Inserts the word to the trie structure
void insert(struct Trie *pTrie, char *word)
{
    struct TrieNode *crawl = pTrie->root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!crawl->children[index]) {
            crawl->children[index] = createNode();
            // Set the root pointer of the newly created node
            crawl->children[index]->root = pTrie->root;
        }
        crawl = crawl->children[index];
    }
    crawl->count = 1;
}

// computes the number of occurances of the word
int numberOfOccurances(struct Trie *pTrie, char *word)
{
    truct TrieNode *crawl = pTrie->root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!crawl->children[index]) {
            return 0;
        }
        crawl = crawl->children[index];
    }
    return (crawl != NULL && crawl->count);
}

// deallocate the trie structure
struct Trie *deallocateTrie(struct Trie *pTrie)
{
     if (root) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (root->children[i]) {
                deallocateTrieUtil(root->children[i]);
            }
        }
        free(root);
}

// Initializes a trie structure
struct Trie *createTrie()
{
    struct Trie *newTrie = (struct Trie*)malloc(sizeof(struct Trie));
    if (newTrie) {
        newTrie->root = createNode();
        newTrie->root->root = newTrie->root;
    }
    return newTrie;
}

// this function will return number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char *filename, char **pInWords)
{
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    int numWords = 0;
    char word[100]; // assuming maximum word length is 99 characters

    while (fscanf(file, "%s", word) != EOF) {
        pInWords[numWords] = (char*)malloc(strlen(word) + 1);
        strcpy(pInWords[numWords], word);
        numWords++;
    }

    fclose(file);
    return numWords;
}

int main(void)
{
	char *inWords[256];
	
	//read the number of the words in the dictionary
	int numWords = readDictionary("dictionary.txt", inWords);
	for (int i=0;i<numWords;++i)
	{
		printf("%s\n",inWords[i]);
	}
	
	struct Trie *pTrie = createTrie();
	for (int i=0;i<numWords;i++)
	{
		insert(pTrie, inWords[i]);
	}
	// parse lineby line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i=0;i<5;i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (pTrie != NULL)
		printf("There is an error in this program\n");
	return 0;
}