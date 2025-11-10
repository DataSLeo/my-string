#include "smystring.h"
#include "bop_mystring.h"
#include <stdlib.h>
#include <ctype.h>

int counter_string(char *buff) {

    int length = 0;

    if(buff == NULL) return length;

    while(1) {
        
        if(buff[length] == '\0') break;
        length++;
    
    }

    return length;

}

enum ErrorMyString gete_string(struct MyString object_string) {
    return object_string.id_error;
}
  
char *getp_string(struct MyString object_string) {
    return object_string.phrase == NULL ? (char*) '\0' : object_string.phrase;
}

enum ErrorMyString initwp_string(struct MyString *object_string, char *phrase) {

    int length_phrase = counter_string(phrase);

    object_string->phrase = (char*) calloc(length_phrase + 1, sizeof(char));

    if(object_string->phrase == NULL) {
        object_string->id_error = MYSTRING_PHRASE_NOT_INITIALIZED;
        return MYSTRING_PHRASE_NOT_INITIALIZED;
    }

    for(int i = 0; i < length_phrase; i++) {
        object_string->phrase[i] = phrase[i];
    }

    object_string->phrase[length_phrase] = '\0';
    object_string->length = length_phrase;
    object_string->id_error = MYSTRING_NONE;

    return MYSTRING_NONE;
    
}

int equals_string(struct MyString object_string1, struct MyString object_string2) {
    
    int length_os1 = object_string1.length;
    int length_os2 = object_string2.length;

    if(length_os1 != length_os2) return 0;

    for(int i = 0; i < length_os1; i++) {
        if(object_string1.phrase[i] != object_string2.phrase[i]) return 0; 
    }

    return 1;

}

enum ErrorMyString assign_string(struct MyString *origin, char *phrase) {
    
    // Mark id_error and length as undefined to ensure fresh execution
    origin->id_error = ID_ERROR_RESETED;
    origin->length = LENGTH_RESETED;
    

    int length_phrase = counter_string(phrase);
    
    origin->phrase = (char*) realloc((char*) origin->phrase, (length_phrase + 1) * sizeof(char));
    
    if(origin->phrase == NULL) {
        origin->id_error = MYSTRING_PHRASE_CANNOT_BE_RELOCATED;
        return MYSTRING_PHRASE_CANNOT_BE_RELOCATED;
    }

    for(int i = 0; i < length_phrase; i++) {
        origin->phrase[i] = phrase[i];
    }

    origin->phrase[length_phrase] = '\0';
    origin->length = length_phrase; 
    origin->id_error = MYSTRING_NONE;

    return MYSTRING_NONE;
}

enum ErrorMyString concat_string(struct MyString *object_string, char* phrase){    
    
    // Mark id_error and length as undefined to ensure fresh execution
    object_string->id_error = ID_ERROR_RESETED;
    int length_tmp = object_string->length;
    object_string->length = LENGTH_RESETED;


    int length_phrase = counter_string(phrase);

    int sum = length_phrase + length_tmp;
    
    object_string->phrase = (char*) realloc(object_string->phrase, (sum + 1) * sizeof(char));

    if(object_string->phrase == NULL) {
        object_string->id_error = MYSTRING_PHRASE_CANNOT_BE_RELOCATED;
        return MYSTRING_PHRASE_CANNOT_BE_RELOCATED;
    }

    for(int i = 0; i < length_phrase; i++, length_tmp++) {
        object_string->phrase[length_tmp] = phrase[i];
    }

    object_string->phrase[sum] = '\0';
    object_string->length = sum;

    object_string->id_error = MYSTRING_NONE;
    return MYSTRING_NONE;
}

enum ErrorMyString remasp_string(struct MyString *object_string) {

    // Mark id_error and length as undefined to ensure fresh execution
    object_string->id_error = ID_ERROR_RESETED;
    int length_tmp = object_string->length;
    object_string->length = LENGTH_RESETED;    

    int how_many_spaces = 0; 

    for(int i = 0; i < length_tmp; i++) {
        if(object_string->phrase[i] == ' '){
            how_many_spaces++;
        }
    }


    int length_phrase_no_space = length_tmp - how_many_spaces;

    char buff[length_phrase_no_space];

    for(int i = 0, index_buff = 0; i < length_tmp; i++) {
        if(object_string->phrase[i] != ' ') {
            buff[index_buff] = object_string->phrase[i];
            index_buff++;
        }
    }

    // For more security 
    free(object_string->phrase);
    object_string->phrase = NULL;

    
    object_string->phrase = (char*) calloc(length_phrase_no_space + 1, sizeof(char));
    
    if(object_string->phrase == NULL) {
        object_string->id_error = MYSTRING_PHRASE_NOT_INITIALIZED;
        return MYSTRING_PHRASE_NOT_INITIALIZED;
    }

    for(int i = 0; i < length_phrase_no_space; i++) {
        object_string->phrase[i] = buff[i];
    }

    object_string->phrase[length_phrase_no_space] = '\0';
    object_string->length = length_phrase_no_space;

    object_string->id_error = MYSTRING_NONE;
    return MYSTRING_NONE;
}

#include <stdio.h>

enum ErrorMyString lstrip_string(struct MyString *object_string) {

    if (object_string->phrase == NULL || object_string == NULL) {
        object_string->id_error = MYSTRING_PHRASE_NOT_INITIALIZED;
        return MYSTRING_PHRASE_NOT_INITIALIZED;
    }

    /** 
     * PS: In addition to resetting the state of MyString object_string, we should ALWAYS modify the copy.
     * If this doesn't happen, we need to free object_string and then call calloc / malloc or some other function that might,
     * return NULL or throw an error, causing us to lose the original string.
     */

    // Reseting state 

    object_string->id_error = ID_ERROR_RESETED;
    
    int copy_original_length = object_string->length;
    object_string->length = LENGTH_RESETED;


    // Making a copy to work

    enum ErrorMyString e;

    struct MyString copy_original_phrase;
    e = initwp_string(&copy_original_phrase, object_string->phrase);

    if(e != MYSTRING_NONE) {
        object_string->id_error = e;
        object_string->length = copy_original_length;
        return e;
    }


    // Counting how many times the space appears
    
    int spaces_inside_at_beggining = 0;

    for(int i = 0; i < copy_original_length; i++) {
        
        if(
            copy_original_phrase.phrase[i] == ' ' ||
            copy_original_phrase.phrase[i] == '\n' ||
            copy_original_phrase.phrase[i] == '\t' ||
            copy_original_phrase.phrase[i] == '\r'
        ) {
        
            spaces_inside_at_beggining++;

        } else {
        
            break;
        
        }

    }

    // Skiping the spaces and add the original sentence

    int buff_length = copy_original_length - spaces_inside_at_beggining; 
    char buff[buff_length];

    for(int i = spaces_inside_at_beggining, i_buff = 0; i < copy_original_length; i++, i_buff++) {
        buff[i_buff] = copy_original_phrase.phrase[i];
    }  

    buff[buff_length] = '\0';    


    // Adding a new phrase by buff 
    e = assign_string(object_string, buff);


    if(e != MYSTRING_NONE) {
        object_string->id_error = e;
        object_string->length = copy_original_length;
        return e;      
    }


    object_string->id_error = MYSTRING_NONE;
    object_string->phrase[object_string->length] = '\0';

    del_string(&copy_original_phrase);
    return MYSTRING_NONE;
}

enum ErrorMyString touppercase_string(struct MyString *object_string) {

    if(object_string->phrase == NULL) {
        object_string->id_error = MYSTRING_PHRASE_NOT_INITIALIZED;
        return MYSTRING_PHRASE_NOT_INITIALIZED;    
    }

    if(object_string->phrase[0] == '\0') {
        object_string->id_error = MYSTRING_OPERATION_NEEDS_A_PHRASE;
        return MYSTRING_OPERATION_NEEDS_A_PHRASE;
    }


    // RESET
    object_string->id_error = ID_ERROR_RESETED;

    int copy_length = object_string->length;
    object_string->length = LENGTH_RESETED;

    char copy_phrase[copy_length+1];

    for(int i = 0; i < copy_length; i++) {
        copy_phrase[i] = object_string->phrase[i];
    }

    copy_phrase[copy_length] = '\0';


    // TOUPPER
    struct MyString temporary_object;
    char buff[copy_length+1];
    
    for(int i = 0; i < copy_length; i++) {
    
        char result = toupper(copy_phrase[i]); 
        buff[i] = result;
    
    }

    buff[copy_length] = '\0';


    // CLOSING STRING
    enum ErrorMyString e;

    e = assign_string(object_string, buff);
    
    if(e != MYSTRING_NONE) {
        object_string->id_error = e;
        object_string->length = copy_length;
        return e;
    }

    return MYSTRING_NONE;

}

int isequal_string(struct MyString object_string, char *phrase) {

    int length_os = object_string.length;
    int length_phrase = counter_string(phrase);

    if(length_os != length_phrase) return 0;

    for(int i = 0; i < length_os; i++) {
        if(object_string.phrase[i] != phrase[i]) return 0; 
    }

    return 1;

}