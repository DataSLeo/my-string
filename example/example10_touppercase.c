/**
 * Example 10 - Using touppercase_string function.
 * Demonstrates how to use the touppercase_string function.
 *
 * To compile:
 * gcc example/example10_touppercase.c -Iinclude -Lbuild -lmystring -o example/example10
 */


#include <stdio.h>
#include "mystring.h"


int main () {

    /** 
     * The Struct of String, if you want you can use the typedef to remove keyword "struct"
     * 
     * Initializing two MyString objects
     */
    struct MyString example;


    // Initializing a String with a phrase "this phrase will be in uppercase"
    initwp_string(&example, "this phrase will be in uppercase"); 

    if(gete_string(example)) {

        enum ErrorMyString e = gete_string(example);

        printf("Initialization failed with id error [%d]\n", e);

    }

    // To uppercase string 
    touppercase_string(&example);

    if(gete_string(example)) {

        enum ErrorMyString e = gete_string(example);

        printf("Error in uppercase with id [%d]\n", e);

    }

    printf("%s\n", getp_string(example));

    // Free the String
    del_string(&example);

    if(gete_string(example)) {

        enum ErrorMyString e = gete_string(example);

        printf("Deletation failed with id error [%d]\n", e);

    }


    printf("\n==> Everything worked perfectly. Goodbye! <==\n");

    return 0;
}