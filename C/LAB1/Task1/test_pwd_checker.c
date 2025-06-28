#include <assert.h>
#include <stdio.h>
#include "pwd_checker.h"

int main() {
    printf("Running tests...\n\n");

    // ✅ Test Case 1: This password should pass all checks
    const char *test1_first = "Abraham";
    const char *test1_last = "Garcia";
    const char *test1_pwd = "qrtv?,mp!ltrA0b13rab4ham";  
    bool test1 = check_password(test1_first, test1_last, test1_pwd);
    assert(test1);  // ✅ Should pass

    printf("Congrats! The first test case passed.\n\n");

    // ❌ Test Case 2: Too short (Fails check_length)
    const char *test2_first = "John";
    const char *test2_last = "Doe";
    const char *test2_pwd = "Short1";  // 🚨 Too short, should fail check_length()
    bool test2 = check_password(test2_first, test2_last, test2_pwd);
    assert(!test2);  // ✅ Should fail

    // ❌ Test Case 3: No uppercase letter (Fails check_upper)
    const char *test3_pwd = "alllowercase1";
    bool test3 = check_password(test2_first, test2_last, test3_pwd);
    assert(!test3);  // ✅ Should fail

    // ❌ Test Case 4: No number (Fails check_number)
    const char *test4_pwd = "NoNumbersHere";
    bool test4 = check_password(test2_first, test2_last, test4_pwd);
    assert(!test4);  // ✅ Should fail

    // ❌ Test Case 5: Contains first name (Fails check_name)
    const char *test5_pwd = "JohnRocks123";
    bool test5 = check_password(test2_first, test2_last, test5_pwd);
    assert(!test5);  // ✅ Should fail

    printf("Congrats! You have passed all of the test cases!\n");
    return 0;
}
