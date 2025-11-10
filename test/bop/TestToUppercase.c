#include "criterion/criterion.h"
#include "mystring.h"

/**
 * SCENARIO: 
 * 
 * 1. When sending a string with only one character, it should replace the same character, but in uppercase.
 * 2. When sending a string, it should replace the same character in uppercase.
 * 3. When sending an object that has not been initialized, it should return the error MYSTRING_PHRASE_NOT_INITIALIZED.
 * 4. When sending an object and the phrase is empty, it should return the error MYSTRING_OPERATION_NEEDS_A_PHRASE.
 */


Test(TestToUppercase, WhenSendACharacterLowercase_ThenReturnUppercase) {

    struct MyString object;
    struct MyString expected;

    initwp_string(&object, "a");
    initwp_string(&expected, "A");

    enum ErrorMyString e = touppercase_string(&object);
    
    cr_assert(equals_string(object, expected), "Expected 'A', got %s", object.phrase);
    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected MYSTRING_NONE (0), got %d", object.id_error);
    cr_assert_eq(e, MYSTRING_NONE, "Expected MYSTRING_NONE (0), got %d", e);

    del_string(&object);
    del_string(&expected);

}

Test(TestToUppercase, WhenSendAPhraseLowercase_ThenReturnToUppercase) {

    struct MyString object;
    struct MyString expected;

    initwp_string(&object, "foo and bar");
    initwp_string(&expected, "FOO AND BAR");

    enum ErrorMyString e = touppercase_string(&object);

    cr_assert(equals_string(object, expected), "Expected 'FOO AND BAR', got %s", object.phrase);
    cr_assert_eq(object.id_error, MYSTRING_NONE, "Expected MYSTRING_NONE (0), got %d", object.id_error);
    cr_assert_eq(e, MYSTRING_NONE, "Expected MYSTRING_NONE (0), got %d", e);

    del_string(&object);
    del_string(&expected);

}

Test(TestToUppercase, WhenSendADeletedObject_ThenReturnErrorMyStringPhraseNotInitialized) {

    struct MyString object;

    enum ErrorMyString e = touppercase_string(&object);

    cr_assert_eq(object.id_error, MYSTRING_PHRASE_NOT_INITIALIZED, "Expected MYSTRING_PHRASE_NOT_INITIALIZED (1), got %d", object.id_error);
    cr_assert_eq(e, MYSTRING_PHRASE_NOT_INITIALIZED, "Expected MYSTRING_PHRASE_NOT_INITIALIZED (1), got %d", e);

    del_string(&object);

}

Test(TestToUppercase, WhenSendAnEmptyPhrase_ThenReturnErrorMyStringOperationNeedsAPhrase) {

    struct MyString object;
    initwp_string(&object, "");

    enum ErrorMyString e = touppercase_string(&object);

    cr_assert_eq(object.id_error, MYSTRING_OPERATION_NEEDS_A_PHRASE, "Expected MYSTRING_OPERATION_NEEDS_A_PHRASE (4), got %d", object.id_error);
    cr_assert_eq(e, MYSTRING_OPERATION_NEEDS_A_PHRASE, "Expected MYSTRING_OPERATION_NEEDS_A_PHRASE (4), got %d", e);

    del_string(&object);

}