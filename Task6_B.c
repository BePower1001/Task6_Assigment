//
// Created by adria on 07/06/2025.
//
#include <stdio.h>
#include <ctype.h>

#define NUM_PRODUCTS 7 // Number of products

// function to display product pairs
void display_product_pairs(char productNames[][20], float productPrices[]) {
    printf("\nPRODUCT PAIRS\n----------------\n");
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        printf("Product: %s, Price: %.2f", productNames[i], productPrices[i]);
        if (i < NUM_PRODUCTS - 1) {
            printf(" | Adjacent Product: %s, Price: %.2f\n", productNames[i + 1], productPrices[i + 1]);
        } else {
            printf(" | Adjacent Product: None\n");
        }
    }
}

// Function to print arrays in specified format
void print_arrays(char productNames[][20], float productPrices[], const char *header) {
    printf("%s: ", header);
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        printf("%s - %.2f", productNames[i], productPrices[i]);
        if (i < NUM_PRODUCTS - 1) printf(", ");
    }
    printf("\n");
}

// Function Bubble Sort
void single_pass_bubble_sort(char productNames[][20], float productPrices[]) {
    // Single pass to move highest price to the end
    for (int j = 0; j < NUM_PRODUCTS - 1; j++) {
        if (productPrices[j] > productPrices[j + 1]) {
            // swapping prices
            float temp_price = productPrices[j];
            productPrices[j] = productPrices[j + 1];
            productPrices[j + 1] = temp_price;
            //swapping names
            char temp_name[20];
            strcpy(temp_name, productNames[j]);
            strcpy(productNames[j], productNames[j + 1]);
            strcpy(productNames[j + 1], temp_name);
        }
    }
}
int main(void) {
    // Arrays init
    char productNames[NUM_PRODUCTS][20] = {
        "Laptop", "Phone", "Tablet", "Monitor", "Keyboard", "Mouse", "Headphones"
    };
    float productPrices[NUM_PRODUCTS] = {99.99, 49.50, 12.75, 150.00, 29.99, 75.25, 10.50};
    char choice; // Menu

    // Menu
    do {
        printf("\n++++ RETAIL STORE PRODUCT ORGANIZER ++++\n");
        printf("1. Display Product Pairs\n2. Perform Single Pass Bubble Sort\n3. Exit\n");
        printf("Enter your choice (1-3): ");
        choice = getchar();
        getchar();
        choice = tolower(choice);

        switch (choice) {
            case '1':
                display_product_pairs(productNames, productPrices);
                break;
            case '2':
                print_arrays(productNames, productPrices, "Before Sorting");
                single_pass_bubble_sort(productNames, productPrices);
                print_arrays(productNames, productPrices, "After Single Pass");
                break;
            case '3':
                printf("EXITING PROGRAM\n----------------\n");
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
                break;
        }
    } while (1); // Loop until exit
}