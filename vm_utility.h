

#ifndef _VM_UTILITY_H
#define _VM_UTILITY_H

#define SUCCESS 1
#define FAILURE 0
#define TRUE 1
#define FALSE 0
#define TEMP_STRING_LENGTH 11

/* Function prototypes. */
void readRestOfLine();
int systemInit(VendingMachineType*);
int loadData(VendingMachineType*, char*, char*);
void systemFree(VendingMachineType*);


int inputValidate(char*,int);
void createProductNode(productPtr, char*, char*, char*, char*);
void insertProductNode(VendingMachineType *, productPtr);
void *safeMalloc(size_t size);


#endif
