
#include "vm.h"
#include "vm_options.h"
#include "vm_utility.h"

int main(int argc, char *argv[])
{
   VendingMachineType vm;

   int initFlag, dataFlag;
   char optionString[MAX_OPTION_INPUT + EXTRA_SPACES];
   int optionInt;
   int quit = TRUE;
   int finish = TRUE;

   /* Initialise the vending machine to a safe empty state. */
   initFlag = systemInit(&vm);

   /* Populate the vending machine with data from the csv files. */
   /* Uncomment this line when you are ready to use command line arguments:*/
   dataFlag = loadData(&vm, argv[1], argv[2]); 

   /* Testing to see if both systemInit(.) and loadData(.) are ok */
   if (initFlag == FAILURE || dataFlag == FAILURE)
     exit(EXIT_FAILURE);

   /* Interactive menu providing user with access to the 9 menu options */
   do
   {
      finish = TRUE;
      
		do
      {
         printf("Main Menu:\n");
         printf("1) Purchase Product\n");
         printf("2) Display Products\n");
         printf("3) Save and Exit\n");
         printf("SupplierOnly Menu:\n");
         printf("4) Add Product\n");
         printf("5) Remove Product\n");
         printf("6) Display Coins\n");
         printf("7) Restock Products\n");
         printf("8) Restock Coins\n");
         printf("9) Abort\n");
         printf("\nSelect your option(1-9):");
         
         fgets(optionString, MAX_OPTION_INPUT + EXTRA_SPACES, stdin);
         finish = inputValidate(optionString, MAX_OPTION_INPUT + EXTRA_SPACES);
         
      }while(finish);
      
      optionInt = atoi(optionString);
      
      switch (optionInt) {
         case 1:
            purchaseProduct(&vm);
            break;
         case 2:
            displayProducts(&vm);
            break;
         case 3:
            saveData(&vm, argv[1], argv[2]);
            quit = FALSE;
            break;
         case 4:
            addProduct(&vm);
            break;
         case 5:
            removeProduct(&vm);
            break;
         case 6:
            displayCoins(&vm);
            break;
         case 7:
            restockProducts(&vm);
            break;
         case 8:
            restockCoins(&vm);
            break;
         case 9:
            quit = FALSE;
            printf("\n\nThank you for using this program\n\n");
            break;
         default:
            printf("\n\nUnexpected input found! Please try again!!\n");
            
		}
      
	}while(quit);
   
   /* Deallocate all dynamically allocated memory. */
   systemFree(&vm);

   exit(EXIT_SUCCESS);
}
