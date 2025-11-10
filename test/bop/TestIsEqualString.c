#include <criterion/criterion.h>
#include <mystring.h>

/**
 * SCENARIO:
 * 
 * 1. Test that two identical strings are considered equal.
 * 2. Test that two different strings are considered not equal.
 * 3. Test that two empty strings are considered equal.
 * 4. Test that strings with different cases are considered not equal.
 */


Test(IsEqualString, WhenTwoIdenticalStrings_ThenReturnTrue) {

    struct MyString object;
    initwp_string(&object, "foo");

    isequal_string(object, "foo");

    cr_assert_eq(isequal_string(object, "foo"), 1, "Expected 1 (true), got %d", isequal_string(object, "foo"));

    del_string(&object);

}

Test(IsEqualString, WhenTwoDifferentStrings_TheReturnFalse) {

    struct MyString object;
    initwp_string(&object, "foo");

    isequal_string(object, "bar");

    cr_assert_eq(isequal_string(object, "bar"), 0, "Expected 0 (false), got %d", isequal_string(object, "bar"));

    del_string(&object);

}

Test(IsEqualString, WhenTwoEmptyStrings_ThenReturnTrue) {

    struct MyString object;
    initwp_string(&object, "");

    isequal_string(object, "");

    cr_assert_eq(isequal_string(object, ""), 1, "Expected 1 (true), got %d", isequal_string(object, ""));

    del_string(&object);

}

Test(IsEqualString, WhenStringsWithDifferentCases_ThenReturnFalse) {

    struct MyString object;
    initwp_string(&object, "Foo");

    isequal_string(object, "foo");

    cr_assert_eq(isequal_string(object, "foo"), 0, "Expected 0 (false), got %d", isequal_string(object, "foo"));

    del_string(&object);

}