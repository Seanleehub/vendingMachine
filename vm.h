

#ifndef _VM_H
#define _VM_H

/* System-wide header files. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Constants. */
#define COIN_DEFAULT 5
#define STOCK_DEFAULT 5
#define PRODUCT_NAME_MAX 40
#define PRODUCT_BRAND_MAX 20
#define DISTINCT_COINS 6

#define MAX_OPTION_INPUT 1
#define EXTRA_SPACES 2
#define BUFFERSIZE 512


typedef struct vendingMachine *vmPtr;
typedef struct productNode *productPtr;

/* Structure definitions. */
typedef struct coin
{
   unsigned qty;
   unsigned value;  /* Stored in cents (not dollars). */
} CoinType;

typedef struct productNode
{
   char name[PRODUCT_NAME_MAX + 1];
   char brand[PRODUCT_BRAND_MAX + 1];
   unsigned price;  /* Stored in cents (not dollars). */
   unsigned qty;
   struct productNode* nextProduct;
} ProductNodeType;

typedef struct vendingMachine
{
   CoinType coins[DISTINCT_COINS];
   unsigned totalCoins;
   ProductNodeType* headProduct;
   unsigned totalProducts;
} VendingMachineType;

#endif
