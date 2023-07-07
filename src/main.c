#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/vector.h"

void print_int_vec(Vec* vec) {
    for(int i = 0; i < vec->capacity; i++) {
        int num = *(int*)vec_at(vec, i);
        printf("%d ", num);
    }
    printf("\n");
}

void print_char_vec(Vec* vec) {
    for(int i = 0; i < vec->capacity; i++) {
        char chr = *(char*)vec_at(vec, i);
        printf("%c", chr);
    }
    printf("\n");
}

typedef struct Item {
    float price;
    int stock;
    char name[24];
} Item;

void print_item_vec(Vec* vec) {
    for(int i = 0; i < vec->capacity; i++) {
        Item* item = (Item*)vec_at(vec, i);
        printf("------------------\n");
        printf("Item: ");
        puts(item->name);
        printf("Cost: %f\n", item->price);
        printf("In-Stock: %d\n", item->stock);
    }
}

Item new_item(float price, int stock, char name[]) {
    Item new_item;
    new_item.price = price;
    new_item.stock = stock;
    memmove(new_item.name, name, sizeof(char)*24);
    return new_item;
}

int main() {
    Vec int_vec = vec_new(5, sizeof(int));

    for(int i = 0; i < 35; i++) {
        vec_push(&int_vec, &i);
    }
  
    int num = 100;
    vec_push(&int_vec, &num);
    
    for(int i = 0; i < 25; i++) {
        vec_pop_back(&int_vec);
    }

    printf("int_vec: ");
    print_int_vec(&int_vec);
    vec_free(&int_vec);

    char char_array[12] = "hello world!";
    Vec char_vec = vec_from_array(&char_array, 12, sizeof(char));
    printf("char_vec: ");
    print_char_vec(&char_vec);
    vec_pop_back(&char_vec);
    vec_push(&char_vec, "?");
    print_char_vec(&char_vec);
    vec_free(&char_vec);

    Item items[3] = {
        new_item(1.50, 35, "Candy Bar"),
        new_item(0.5, 71, "Apple"),
        new_item(3.50, 13, "Soup"),
    };

    Vec item_vec = vec_from_array(&items, 3, sizeof(Item));

    Item* a = (Item*)vec_at(&item_vec, 0);
    a->stock -= 1;
    vec_pop_at(&item_vec, 1);

    print_item_vec(&item_vec);

    vec_at(&item_vec, 8);

    return 0;
}

//gcc -pedantic -Wall --std=c17 src/main.c src/vector.c -o target/main.exe
//./target/main.exe
/* 
OUTPUT:

int_vec: 0 1 2 3 4 5 6 7 8 9 10 
char_vec: hello world!
hello world?
------------------
Item: Candy Bar
Cost: 1.500000
In-Stock: 34
------------------
Item: Soup
Cost: 3.500000
In-Stock: 13
ERROR: Tried to access mem in vec that is out of bounds!

*/