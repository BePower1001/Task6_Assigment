//
// Created by adria on 08/06/2025.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PRODUCTS 7 // Number of products

// Function to display product pairs
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

// Function to print arrays in format price
void print_price_arrays(char productNames[][20], float productPrices[], const char *header) {
    printf("%s: ", header);
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        printf("%s - %.2f", productNames[i], productPrices[i]);
        if (i < NUM_PRODUCTS - 1) printf(", ");
    }
    printf("\n");
}

// Function to print names only
void print_name_arrays(char productNames[][20], const char *header) {
    printf("%s: ", header);
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        printf("%s", productNames[i]);
        if (i < NUM_PRODUCTS - 1) printf(", ");
    }
    printf("\n");
}

// Function perform single pass of Bubble Sort
void single_pass_bubble_sort(char productNames[][20], float productPrices[]) {
    for (int j = 0; j < NUM_PRODUCTS - 1; j++) {
        if (productPrices[j] > productPrices[j + 1]) {
            // swapping prices
            float temp_price = productPrices[j];
            productPrices[j] = productPrices[j + 1];
            productPrices[j + 1] = temp_price;
            // swapping names
            char temp_name[20];
            strcpy(temp_name, productNames[j]);
            strcpy(productNames[j], productNames[j + 1]);
            strcpy(productNames[j + 1], temp_name);
        }
    }
}

// func for Insertion Sort
void insertion_sort_names(char productNames[][20], float productPrices[]) {
    for (int i = 1; i < NUM_PRODUCTS; i++) {
        char key_name[20];
        strcpy(key_name, productNames[i]);
        float key_price = productPrices[i];
        int j = i - 1;
        while (j >= 0 && strcmp(productNames[j], key_name) > 0) {
            strcpy(productNames[j + 1], productNames[j]);
            productPrices[j + 1] = productPrices[j];
            j--;
        }
        strcpy(productNames[j + 1], key_name);
        productPrices[j + 1] = key_price;
    }
}

int main(void) {
    char productNames[NUM_PRODUCTS][20] = {
        "Laptop", "Phone", "Tablet", "Monitor", "Keyboard", "Mouse", "Headphones"
    };
    float productPrices[NUM_PRODUCTS] = {99.99, 49.50, 12.75, 150.00, 29.99, 75.25, 10.50};
    char choice; // Menu choice

    do {
        printf("\n++++ RETAIL STORE PRODUCT ORGANIZER ++++\n");
        printf("1. Display Product Pairs\n2. Perform Single Pass Bubble Sort\n");
        printf("3. Sort Names Alphabetically\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        choice = getchar();
        getchar();
        choice = tolower(choice);

        switch (choice) {
            case '1':
                display_product_pairs(productNames, productPrices);
                break;
            case '2':
                print_price_arrays(productNames, productPrices, "Before Sorting");
                single_pass_bubble_sort(productNames, productPrices);
                print_price_arrays(productNames, productPrices, "After Single Pass");
                break;
            case '3':
                print_name_arrays(productNames, "Before Sorting");
                insertion_sort_names(productNames, productPrices);
                print_name_arrays(productNames, "After Alphabetical Sorting");
                break;
            case '4':
                printf("EXITING PROGRAM\n----------------\n");
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter 1, 2, 3, or 4.\n");
                break;
        }
    } while (1); //loop until exit
}