#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LAST_NAME_SIZE 20

struct gradeNode {
	char lastName[LAST_NAME_SIZE];
	float grade;
	struct gradeNode *nextPtr;
};

typedef struct gradeNode GradeNode;
typedef GradeNode * GradeNodePtr;

int main(void) 
{

	GradeNodePtr startPtr;
	GradeNodePtr prevousPtr;
	GradeNodePtr currentPtr;
	GradeNodePtr newPtr;
	GradeNodePtr tmpPtr;


	newPtr = (GradeNodePtr) malloc(sizeof(GradeNode));
	newPtr->grade = 91.5;
	strcpy_s(newPtr->lastName, LAST_NAME_SIZE, "Jones");
	newPtr->nextPtr = NULL;
	prevousPtr = NULL;
	currentPtr = newPtr;

	startPtr = currentPtr;

	
	newPtr = (GradeNodePtr)malloc(sizeof(GradeNode));
	newPtr->grade = 91.5;
	strcpy_s(newPtr->lastName, LAST_NAME_SIZE, "Smith");
	newPtr->nextPtr = NULL;
	prevousPtr = currentPtr;
	currentPtr = newPtr;

	startPtr->nextPtr = currentPtr;


	newPtr = (GradeNodePtr)malloc(sizeof(GradeNode));
	newPtr->grade = 85.0;
	strcpy_s(newPtr->lastName, LAST_NAME_SIZE, "Adams");
	newPtr->nextPtr = startPtr;

	startPtr = newPtr;


	
	newPtr = (GradeNodePtr)malloc(sizeof(GradeNode));
	newPtr->grade = 73.5;
	strcpy_s(newPtr->lastName, LAST_NAME_SIZE, "Thompson");
	newPtr->nextPtr = NULL;
	currentPtr->nextPtr = newPtr;
	prevousPtr = currentPtr;
	currentPtr = newPtr;


	newPtr = (GradeNodePtr)malloc(sizeof(GradeNode));
	newPtr->grade = 66.5;
	strcpy_s(newPtr->lastName, LAST_NAME_SIZE, "Pritchard");
	newPtr->nextPtr = prevousPtr;

	startPtr->nextPtr->nextPtr = newPtr;

	//d
	currentPtr = startPtr;
	while (currentPtr != NULL) {
		printf("%s %.2f\n", currentPtr->lastName, currentPtr->grade);
		currentPtr = currentPtr->nextPtr;
	}

	//e
	currentPtr = startPtr;
	while (currentPtr != NULL) {
		tmpPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
		free(tmpPtr);
	}
	startPtr = NULL;

	return 0;
}