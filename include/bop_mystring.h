#ifndef __BOP_MYSTRING_H__
#define __BOP_MYSTRING_H__

/**
* @date 2025-10-10
* @author Leonardo Alves
* @file bop_mystring.h
* @brief Basic Operations for MyString
* 
* This header provides basic functions to manipulate MyString objects.
*/


/**
* @brief Returns the length of a null terminated string.
* 
* @param buff Pointer to the string to measure.
* 
* @return Length of the string. Return 0 if buff is NULL.
*/
int counter_string(char *buff);


/** 
* @brief Get the id_error of MyString object.
* 
* @param object_string The MyString object. 
*
* @return The id_error. 
*/
enum ErrorMyString gete_string(struct MyString object_string);


/**
* @brief Get the phrase of MyString object.
* 
* @param object_string The MyString object. 
*
* @return The phrase on success, Empty char pointer if not initialized phrase. 
*/
char *getp_string(struct MyString object_string);


/** 
* @brief initialize a MyString with given phrase.
* 
* @param object_string Pointer to the MyString object to initialize.
* @param phrase String to copy into object_string. 
*
* @return MYSTRING_NONE on success, MYSTRING_PHRASE_NOT_INITIALIZED if memory allocation fails. 
*/
enum ErrorMyString initwp_string(struct MyString *object_string, char *phrase);


/** 
* @brief Compares two MyString object for equality.

@param object_string1 First MyString object.
@param object_string2 Second MyString object. 

@return 1 if the strings are equals, 0 otherwise.
*/
int equals_string(struct MyString object_string1, struct MyString object_string2);


/**
* @brief Assign a new phrase to an existing MyString object.
*
* @param origin Pointer to the MyString object to modify.
* @param phrase New string to assign.
* 
* @return MYSTRING_NONE on success, MYSTRING_PHRASE_CANNOT_BE_RELOCATED if memory relocation fails. 
*/
enum ErrorMyString assign_string(struct MyString *origin, char *phrase);


/**
* @brief Concatenates a new Phrase to an initialized MyString object.
*
* @param object_string Pointer to the MyString object to concat.
* @param phrase The phrase will be concated in the object_string.
* 
* @return MYSTRING_NONE on success, MYSTRING_PHRASE_CANNOT_BE_RELOCATED if memory relocation fails. 
*/
enum ErrorMyString concat_string(struct MyString *object_string, char* phrase);


/**
* @brief Removes all spaces from an initialized MyString object.
*
* @param object_string Pointer to the MyString object.
* 
* @return MYSTRING_NONE on success, MYSTRING_PHRASE_NOT_INITIALIZED if memory allocation fails.  
*/
enum ErrorMyString remasp_string(struct MyString *object_string);


/**
* @brief Remove spaces and special character ('\\n', '\\t', '\\r') from the beggining of an initialized MyString object.
*
* @param object_string Pointer to the MyString object.
* 
* @return MYSTRING_NONE on success, MYSTRING_PHRASE_NOT_INITIALIZED if memory allocation fails, MYSTRING_PHRASE_CANNOT_BE_RELOCATED if memory relocation fails.
*/
enum ErrorMyString lstrip_string(struct MyString *object_string); 


/**
* @brief To uppercase the phrase of MyString object.
*
* @param object_string Pointer to the MyString object.
* 
* @return MYSTRING_NONE on success, MYSTRING_PHRASE_NOT_INITIALIZED if memory allocation fails, MYSTRING_OPERATION_NEEDS_A_PHRASE if phrase is empty.
*/
enum ErrorMyString touppercase_string(struct MyString *object_string);

#endif
