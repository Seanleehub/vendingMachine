

#include "vm.h"
#include "vm_utility.h"
#include "vm_options.h"

/****************************************************************************
* Function readRestOfLine() is used for buffer clearing.
* Please refer to "test_fgets.c" on Blackboard:
* "Course Documents"->"Function Examples"->"Input Validation Examples"
****************************************************************************/
void readRestOfLine()
{
   int c;

   /* Read until the end of the line or end-of-file. */
   while ((c = fgetc(stdin)) != '\n' && c != EOF);

   /* Clear the error and end-of-file flags. */
   clearerr(stdin);
}


/****************************************************************************
* Initialises the system to a safe empty state.
****************************************************************************/
int systemInit(VendingMachineType* vm)
{
   vm->headProduct = NULL;
   vm->totalProducts = 0;
   return SUCCESS;
}

/****************************************************************************
 * create the product node.
 ****************************************************************************/
void createProductNode(productPtr productNode, char *pName,
                       char *pBrand, char *pPrice, char *pQty)
{
   int price;
   int qty;
   
   /*Initializes some important values*/
   /*productNode->nextProduct = NULL;*/
   price = atoi(pPrice);
   qty = atoi(pQty);
   
   /*Inserts data into the node*/
   strcpy(productNode->name, pName);
   strcpy(productNode->brand, pBrand);
   productNode->price = price;
   productNode->qty= qty;
   
   return;
   
}

/****************************************************************************
 * Inserts the data into the product node.
 ****************************************************************************/
void insertProductNode(VendingMachineType *vm, productPtr product)
{
   productPtr currentNode, prevNode;
	prevNode=vm->headProduct;
	
   
   /*Sets selected product*/
   /*currentNode = vm->headProduct;
   prevNode = NULL;
   
   Alters pointers to insert the new node
	product->nextProduct = currentNode;
   
   if(prevNode == NULL)
   {
      vm->headProduct = product;
   }
   else
   {
      prevNode->nextProduct = product;
   }
   */
   /*Increases product list size*/
	if(prevNode==NULL)
	{
		vm->headProduct=product;
	}
	else
	{
		currentNode=prevNode->nextProduct;
		product->nextProduct=currentNode;
		vm->headProduct=product;
	}
   vm->totalProducts++;
   
	return;
}

/****************************************************************************
* Loads all data into the system.
****************************************************************************/
int loadData(VendingMachineType* vm, char* stockfile, char* coinsFile)
{
   FILE *stockfileData;
	FILE *coinsfileData;
	
   char fileLine[BUFFERSIZE];
   char *name;
   char *brand;
   char *price;
   char *qty;
	char *c_qty;
	char *c_value;
	int i, cqty, cvalue;
	
	CoinType coin1;
	productPtr product;
	i = 0;
	
	/* load data from the stocks.csv */
   if((stockfileData = fopen(stockfile,"r"))==NULL)
   {
	   fprintf(stderr,"\nError :%s does not exit\n",stockfile);
	   return FAILURE;
   }
   
   while(fgets(fileLine, BUFFERSIZE, stockfileData)!=NULL)
   {
	   if((product=(productPtr)safeMalloc(sizeof(productPtr)))==NULL)
      {
		   printf("Unable to allocate memory");
		   return FAILURE;
	   }
      
      name = strtok(fileLine, ",\n");
      brand = strtok(NULL, ",\n");
      price = strtok(NULL, ",\n");
      qty = strtok(NULL, ",\n");

		createProductNode(product, name, brand, price, qty);
      insertProductNode(vm, product);
      
	}fclose(stockfileData);
	
	/* load data from the coins.csv */
	if((coinsfileData=fopen(coinsFile,"r"))==NULL)
	{
		fprintf(stderr,"\nError :%s does not exit\n",coinsFile);
	   return FAILURE;
	}
	
	while (fgets(fileLine, BUFFERSIZE, coinsfileData)!=NULL)
	{
		c_value = strtok(fileLine, ",\n");
		c_qty = strtok(NULL, ",\n");
		
		cqty = atoi(c_qty);
		cvalue = atoi(c_value);
		coin1.qty = cqty;
		coin1.value = cvalue;
		vm->coins[i] = coin1;
		i++;
		
	}fclose(coinsfileData);
   
   return SUCCESS;
}

/****************************************************************************
* Deallocates memory used in the program.
****************************************************************************/
void systemFree(VendingMachineType* vm)
{

	productPtr currentNode = vm->headProduct;
	productPtr nextProduct = NULL;
   
   /*Cycles through all products and coins and frees up the memory*/
   while(currentNode != NULL)
   {
      nextProduct = currentNode->nextProduct;
      currentNode = vm->headProduct;
      
      free(currentNode);
      currentNode = nextProduct;
   }
   
   return;

}

/****************************************************************************
 * Validates user input. Flushes out buffer if input is incorrect.
 ****************************************************************************/
int inputValidate(char *input, int bufferSize)
{
   if(input[strlen(input) - 1] != '\n')
   {
      printf("YOUR INPUT WAS TOO LONG. PLEASE REENTER.\n");
      readRestOfLine();
      return TRUE;
   }
   else
   {
      input[strlen(input) - 1] = '\0';
   }
   return FALSE;
}

/****************************************************************************
 * Safely allocates memory for node.
 ****************************************************************************/
void *safeMalloc(size_t size)
{
   productPtr nodePtr;
   if((nodePtr = (productPtr)malloc(size)) == NULL)
   {
      fprintf(stderr, "\nERROR: UNABLE TO ALLOCATE MEMORY\n");
      return NULL;
   }
   return nodePtr;
}
