#ifndef __SMYSTRING_H__
#define __SMYSTRING_H__

/** 
* @date 2025-10-09
* @author Leonardo Alves
* @file smystring.h
* @brief Struct for MyString
* 
* This header provides essentials functions to manipulate memory of MyString object.
*/

/**
 * @brief To indicate the id_error was reseted
 */
#define ID_ERROR_RESETED -1

/**
 * @brief To indicate the length was reseted
 */
#define LENGTH_RESETED -1

/** 
* @brief Enum of errors for MyString. 
*/
enum ErrorMyString {
    
    /**
    * @brief There is no error.
    */
    MYSTRING_NONE = 0,

    /** 
    * @brief Alocation memory fails.
    */
    MYSTRING_PHRASE_NOT_INITIALIZED,

    /** 
    * @brief Trying to clear an already MyString object. 
    */
    MYSTRING_PHRASE_ALREADY_RELEASED,

    /** 
    * @brief Relocation memory fails. 
    */
    MYSTRING_PHRASE_CANNOT_BE_RELOCATED,

    /** 
    * @brief Operation needs a phrase and does not have it. 
    */
    MYSTRING_OPERATION_NEEDS_A_PHRASE
};


/** 
* @brief The struct of MyString. 
*/
struct MyString {
    
    /** 
    * @brief The space that holds the string.
    */
    char* phrase;

    /**
    * @brief Size of string.
    */
    int length;

    /** 
    * @brief Stores the error of ErrorMyString.
    */
    enum ErrorMyString id_error;
};


/**
* @brief Return MyString object initialized, but whithout phrase.
* 
* @param object_string Pointer to the MyString object who will initialized.
* 
* @return MYSTRING_NONE on success, MYSTRING_PHRASE_NOT_INITIALIZED if memory allocation fails. 
*/
enum ErrorMyString init_string(struct MyString *object_string); 


/**
* @brief Free the memory of MyString object.
*
* @param object_string Pointer to the MyString object who will free.
* 
* @return MYSTRING_NONE on success, MYSTRING_PHRASE_ALREADY_RELEASED if your trying to clear an already MyString object.
*/
enum ErrorMyString del_string(struct MyString *object_string);

#endif