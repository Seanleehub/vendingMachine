

#include "vm.h"
#include "vm_utility.h"
#include "vm_options.h"

/****************************************************************************
* Menu option #1: Purchase Product
* Allows the user to purchase a product by specifying the product name and
* insert coins into the system in an interactive fashion. User is given any
* change necessary.
****************************************************************************/
void purchaseProduct(VendingMachineType* vm)
{
   char inputProductName[PRODUCT_NAME_MAX + EXTRA_SPACES];
   
   printf("Enter a product name (140 characters): ");
	fgets(inputProductName, PRODUCT_NAME_MAX + EXTRA_SPACES, stdin);
}

/****************************************************************************
* Menu option #2: Display Products
* Allows the user to view all products in the vending machine.
****************************************************************************/
void displayProducts(VendingMachineType* vm)
{
   productPtr currentProduct = vm->headProduct;
   printf("Product                    Brand      Price Qty\n");
   printf("-------------------------- ---------- ----- ---\n");
   
   while(currentProduct != NULL)
   {
      printf("%-26s %-10s $%.2-5d %-3d\n",
             currentProduct->name, currentProduct->brand,
             (double)(currentProduct->price)/100,currentProduct->qty);
      
      currentProduct = currentProduct->nextProduct;  
   }
}

/****************************************************************************
* Menu option #3: Save and Exit
* Saves all system data back to the original files. This function does not
* terminate the program - this is left to the main() function instead.
****************************************************************************/
void saveData(VendingMachineType* vm, char* stockFile, char* coinsFile)
{
   productPtr currentProduct = vm -> headProduct;
   FILE *stockFileHandle, *coinsFileHandle;
   
   /*File validation*/
   if((stockFileHandle = fopen(stockFile, "w")) == NULL){
      fprintf(stderr, "\nError: %s cannot be written\n", stockFile);
      return;
   }
   
   if((coinsFileHandle = fopen(coinsFile, "w")) == NULL){
      fprintf(stderr, "\nError: %s cannot be written\n", coinsFile);
      return;
   }
   
   /*Cycles through products/coins and prints them out*/
   while(currentProduct != NULL){
      currentProduct = vm->headProduct;
      
      fprintf(stockFileHandle, "%s|%s|%d|%d\n",
              currentProduct->name, currentProduct->brand,
              currentProduct->price, currentProduct->qty);
      
      /*while(currentItem != NULL){
         fprintf(coinsFileHandle, "%s|%s|%s|%d.%02d|%d.%02d|%d.%02d|%s\n",
                 currentItem->itemID, currentCategory->categoryID,
                 currentItem->itemName, currentItem->prices[0].dollars,
                 currentItem->prices[0].cents, currentItem->prices[1].dollars,
                 currentItem->prices[1].cents, currentItem->prices[2].dollars,
                 currentItem->prices[2].cents, currentItem->itemDescription);
         
         currentItem = currentItem->nextItem;
      }*/
      currentProduct = currentProduct->nextProduct;
   }
   fclose(stockFileHandle);
   fclose(coinsFileHandle);
   return;
   
   
   
   
   
}

/****************************************************************************
* Menu option #4: Add Product
* Allows a supplier to add a new product to the vending machine. All
* necessary information is prompted for.
****************************************************************************/
void addProduct(VendingMachineType* vm)
{
	char inputProductName[PRODUCT_NAME_MAX + EXTRA_SPACES];
	char inputBrandName[PRODUCT_BRAND_MAX + EXTRA_SPACES];
	char inputCoins[DISTINCT_COINS+EXTRA_SPACES];

	printf("Add Product\n");
	printf("-----------\n\n");
	printf("Name (1-40 characters): ");
	fgets(inputProductName, PRODUCT_NAME_MAX + EXTRA_SPACES, stdin);
	printf("\nBrand (1-20 characters): ");
	fgets(inputBrandName, PRODUCT_BRAND_MAX + EXTRA_SPACES, stdin);
	printf("\nPrice (in cents): ");
	fgets(inputCoins, DISTINCT_COINS + EXTRA_SPACES, stdin);

	

}

/****************************************************************************
* Menu option #5: Remove Product
* Allows a supplier to remove a product from the vending machine.
****************************************************************************/
void removeProduct(VendingMachineType* vm)
{
	char inputProductName[PRODUCT_NAME_MAX + EXTRA_SPACES];

	printf("Delete Product\n");
	printf("--------------\n\n");
	printf("Name (1-40 characters): ");
	fgets(inputProductName, PRODUCT_NAME_MAX + EXTRA_SPACES, stdin);
	printf("%s has been removed from the vending machine.", inputProductName);

}

/****************************************************************************
* Menu option #6: Display Coins
* Allows a supplier to view a summary of all coins in the vending machine.
****************************************************************************/
void displayCoins(VendingMachineType* vm)
{
   /*productPtr currentProduct = vm->headProduct;*/
   printf("Coin  Quantity Value\n");
   printf("----- -------- --------\n");
	int i=0;
   
   while(i<DISTINCT_COINS)
   {
      printf("$%.2-5f %7d $%7d\n",
             (double)(vm->coins[i].value)/100, vm->coins[i].qty, 0);
      
      i++; 
   }
	
	printf("               --------\n");
	printf("Total Value:          \n\n");
}

/****************************************************************************
* Menu option #7: Restock Products
* Allows the supplier to restock the vending machine products to the default
* level. The STOCK_DEFAULT constant from vm.h is used here.
****************************************************************************/
void restockProducts(VendingMachineType* vm)
{
}

/****************************************************************************
* Menu option #8: Restock Coins
* Allows the supplier to restock the vending machine coins to the default
* level. The COINS_DEFAULT constant from vm.h is used here.
****************************************************************************/
void restockCoins(VendingMachineType* vm)
{
}
