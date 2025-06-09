//
// Created by adria on 01/06/2025.
//
#include <stdio.h>

#define NUM_PRODUCTS 7 // Number of products
int main(void) {
    // initialising arrays
    char productNames[NUM_PRODUCTS][20] = {
        "Laptop", "Phone", "Tablet", "Monitor", "Keyboard", "Mouse", "Headphones"
    };
    float productPrices[NUM_PRODUCTS] = {12.45, 78.50, 98.75, 120.00, 87.23, 85.21, 10.88};
    char choice; // Menu choice

    printf("++++ RETAIL STORE PRODUCT ORGANIZER ++++\n");
    printf("a. Display Product Pairs\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    getchar();
    if (choice == 'a' || choice == 'A') {
        //product pairs
        printf("\nPRODUCT PAIRS\n----------------\n");
        for (int i = 0; i < NUM_PRODUCTS; i++) {
            printf("Product: %s, Price: %.2f", productNames[i], productPrices[i]);
            if (i < NUM_PRODUCTS - 1) {
                // print product if it exists
                printf(" | Adjacent Product: %s, Price: %.2f\n", productNames[i + 1], productPrices[i + 1]);
            } else {
                // no product for the last item
                printf(" | Adjacent Product: None\n");
            }
        }
    } else {
        printf("Invalid choice. Please enter 'a' or 'A'.\n");
        return 1;
    }
    return 0;
}