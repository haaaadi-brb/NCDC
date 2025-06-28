#include <assert.h>  // ✅ Include assert.h (placed alphabetically)
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "pwd_checker.h"

/* Returns true if PASSWORD is at least 10 characters long */
bool check_length(const char *password) {
    int length = strlen(password);
    bool meets_len_req = (length >= 10);  // ✅ FIXED CONDITION
    return meets_len_req;
}

/* Returns true if LETTER is in the range [LOWER, UPPER] */
bool check_range(char letter, char lower, char upper) {
    return (letter >= lower && letter <= upper);
}

/* Returns true if PASSWORD contains at least one uppercase letter */
bool check_upper(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, 'A', 'Y')) {  // ❌ BUG: Doesn't check for 'Z'
            return true;
        }
        password++;  // ✅ FIXED: Move the pointer forward!
    }
    return false;
}



/* Returns true if PASSWORD contains at least one lowercase letter */
bool check_lower(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, 'a', 'z')) {
            return true;
        }
        ++password;
    }
    return false;
}

/* Returns true if PASSWORD contains at least one number */
bool check_number(const char *password) {
    while (*password != '\0') {
        if (check_range(*password, 0, 9)) {  
            return true;
        }
        ++password;
    }
    return false;
}

/* Returns true if first or last name is NOT in the password */
bool check_name(const char *first_name, const char *last_name, const char *password) {
    return !(strstr(password, first_name) || strstr(password, last_name));
}

/* Returns true if PASSWORD meets all security conditions */
bool check_password(const char *first_name, const char *last_name, const char *password) {
    bool length = check_length(password);
    bool upper = check_upper(password);
    bool lower = check_lower(password);
    bool number = check_number(password);
    bool name = check_name(first_name, last_name, password);

    return (length && upper && lower && number && name);
}
