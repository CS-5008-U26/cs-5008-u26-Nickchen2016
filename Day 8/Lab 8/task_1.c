#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define ANIMAL_NODE 0
#define QUESTION_NODE 1


typedef struct zooNode_struct {
    int type; // Set the node type to either ANIMAL or QUESTION_NODE
    char *animalName; // Only used when type is ANIMAL_NODE
    char *questionText; // Only used when type is QUESTION_NODE
    struct zooNode_struct *noChild;
    struct zooNode_struct *yesChild;
} zooNode;

zooNode *createAnimalNode(char *animalName) {
    zooNode *node = malloc(sizeof(zooNode));
    node->type = ANIMAL_NODE;
    node->animalName = strdup(animalName);
    node->questionText = NULL;
    node->noChild = NULL;
    node->yesChild = NULL;
    return node;

}

zooNode *createQuestionNode(char *questionText, zooNode *noAnimal, zooNode *yesAnimal) {
    zooNode *node = malloc(sizeof(zooNode));
    node->type = QUESTION_NODE;
    node->animalName = NULL;
    node->questionText = strdup(questionText);
    node->noChild = noAnimal;
    node->yesChild = yesAnimal;
    return node;

}

int main () {
    return 0;
}