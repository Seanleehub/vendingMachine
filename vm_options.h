

#ifndef _VM_OPTIONS_H
#define _VM_OPTIONS_H

/* Function prototypes. */
void purchaseProduct(VendingMachineType*);
void displayProducts(VendingMachineType*);
void saveData(VendingMachineType*, char*, char*);
void addProduct(VendingMachineType*);
void removeProduct(VendingMachineType*);
void displayCoins(VendingMachineType*);
void restockProducts(VendingMachineType*);
void restockCoins(VendingMachineType*);

#endif
