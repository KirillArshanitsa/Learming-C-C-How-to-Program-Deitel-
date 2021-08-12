//
// Created by Kirill on 04.08.2021.
//

#ifndef PROJECTC_STRUCTS_H
#define PROJECTC_STRUCTS_H

#define SRC_FILE_NAME_SIZE 100
#define CODE_STR_SIZE 56
#define TABLE_ENTRY_COUNT 100
#define SML_CODE_FILE_NAME "SmlCode.txt"
#define RESULT_FILE_NAME "ResultCode.txt"

struct tableEntry{
    unsigned int symbol;
    char type;
    unsigned int location;
};

typedef tableEntry TableEntry;

struct stackNode{
    char data;
    struct stackNode* dataPtr;
};

typedef struct stackNode StackNode;
typedef StackNode* StackNodePtr;

struct stackNodeInt {
    int data;
    struct stackNodeInt* StackNodeIntPtr;
};

typedef struct stackNodeInt StackNodeInt;
typedef StackNodeInt* StackNodeIntPtr;

#endif //PROJECTC_STRUCTS_H

