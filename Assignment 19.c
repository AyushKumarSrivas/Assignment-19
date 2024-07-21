Handling multiple Strings in C Language

1. Write a program to find the number of vowels in each of the 5 strings stored in two
dimensional arrays, taken from the user.
2. Write a program to sort 10 city names stored in two dimensional arrays, taken from
the user.
3. Write a program to read and display a 2D array of strings in C language.
4. Write a program to search a string in the list of strings.
5. Suppose we have a list of email addresses, check whether all email addresses have
‘@’ in it. Print the odd email out.
6. Write a program to print the strings which are palindrome in the list of strings.
7. From the list of IP addresses, check whether all ip addresses are valid.
8. Given a list of words followed by two words, the task is to find the minimum distance
between the given two words in the list of words.
(Example : s = {“the”,”quick”,”brown”,”fox”,”quick”}
word1 = “the”, word2 = “fox”, OUTPUT : 1 )
9. Write a program that asks the user to enter a username. If the username entered is
one of the names in the list then the user is allowed to calculate the factorial of a
number. Otherwise, an error message is displayed
10. Create an authentication system. It should be menu driven.

Solution:-

1. #include <stdio.h>
#include <string.h>

int countVowels(char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    char strings[5][100];
    
    for (int i = 0; i < 5; i++) {
        printf("Enter string %d: ", i + 1);
        gets(strings[i]);
    }
    
    for (int i = 0; i < 5; i++) {
        printf("Number of vowels in string %d: %d\n", i + 1, countVowels(strings[i]));
    }
    
    return 0;
}

2. #include <stdio.h>
#include <string.h>

void sortCities(char cities[][100], int n) {
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(cities[i], cities[j]) > 0) {
                strcpy(temp, cities[i]);
                strcpy(cities[i], cities[j]);
                strcpy(cities[j], temp);
            }
        }
    }
}

int main() {
    char cities[10][100];
    
    for (int i = 0; i < 10; i++) {
        printf("Enter city name %d: ", i + 1);
        gets(cities[i]);
    }
    
    sortCities(cities, 10);
    
    printf("Sorted city names:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\n", cities[i]);
    }
    
    return 0;
}

3. #include <stdio.h>

int main() {
    char strings[5][100];
    
    for (int i = 0; i < 5; i++) {
        printf("Enter string %d: ", i + 1);
        gets(strings[i]);
    }
    
    printf("The entered strings are:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", strings[i]);
    }
    
    return 0;
}

4. #include <stdio.h>
#include <string.h>

int main() {
    char strings[5][100];
    char search[100];
    int found = 0;
    
    for (int i = 0; i < 5; i++) {
        printf("Enter string %d: ", i + 1);
        gets(strings[i]);
    }
    
    printf("Enter the string to search: ");
    gets(search);
    
    for (int i = 0; i < 5; i++) {
        if (strcmp(strings[i], search) == 0) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("String found.\n");
    } else {
        printf("String not found.\n");
    }
    
    return 0;
}

5. #include <stdio.h>
#include <string.h>

int isValidEmail(char email[]) {
    return strchr(email, '@') != NULL;
}

int main() {
    char emails[5][100];
    int allValid = 1;
    
    for (int i = 0; i < 5; i++) {
        printf("Enter email %d: ", i + 1);
        gets(emails[i]);
    }
    
    for (int i = 0; i < 5; i++) {
        if (!isValidEmail(emails[i])) {
            allValid = 0;
            printf("Invalid email: %s\n", emails[i]);
        }
    }
    
    if (allValid) {
        printf("All emails are valid.\n");
    } else {
        printf("Some emails are invalid.\n");
    }
    
    return 0;
}

6. #include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char strings[5][100];
    
    for (int i = 0; i < 5; i++) {
        printf("Enter string %d: ", i + 1);
        gets(strings[i]);
    }
    
    printf("Palindrome strings:\n");
    for (int i = 0; i < 5; i++) {
        if (isPalindrome(strings[i])) {
            printf("%s\n", strings[i]);
        }
    }
    
    return 0;
}

7. #include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isValidIP(char ip[]) {
    int dots = 0;
    char *ptr = strtok(ip, ".");
    while (ptr) {
        if (!isdigit(*ptr) || atoi(ptr) < 0 || atoi(ptr) > 255) {
            return 0;
        }
        ptr = strtok(NULL, ".");
        dots++;
    }
    return dots == 4;
}

int main() {
    char ips[5][100];
    int allValid = 1;
    
    for (int i = 0; i < 5; i++) {
        printf("Enter IP address %d: ", i + 1);
        gets(ips[i]);
    }
    
    for (int i = 0; i < 5; i++) {
        char ipCopy[100];
        strcpy(ipCopy, ips[i]);
        if (!isValidIP(ipCopy)) {
            allValid = 0;
            printf("Invalid IP: %s\n", ips[i]);
        }
    }
    
    if (allValid) {
        printf("All IP addresses are valid.\n");
    } else {
        printf("Some IP addresses are invalid.\n");
    }
    
    return 0;
}

8. #include <stdio.h>
#include <string.h>
#include <limits.h>

int minDistance(char words[][20], int n, char *word1, char *word2) {
    int pos1 = -1, pos2 = -1;
    int minDist = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        if (strcmp(words[i], word1) == 0) {
            pos1 = i;
        }
        if (strcmp(words[i], word2) == 0) {
            pos2 = i;
        }
        if (pos1 != -1 && pos2 != -1) {
            int dist = abs(pos1 - pos2);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    
    return minDist;
}

int main() {
    char words[5][20] = {"the", "quick", "brown", "fox", "quick"};
    char word1[20], word2[20];
    
    printf("Enter the first word: ");
    gets(word1);
    
    printf("Enter the second word: ");
    gets(word2);
    
    int distance = minDistance(words, 5, word1, word2);
    
    if (distance == INT_MAX) {
        printf("Words not found in the list.\n");
    } else {
        printf("The minimum distance between the words is: %d\n", distance);
    }
    
    return 0;
}

9. #include <stdio.h>
#include <string.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    char usernames[5][20] = {"alice", "bob", "carol", "dave", "eve"};
    char input[20];
    int valid = 0;
    
    printf("Enter your username: ");
    gets(input);
    
    for (int i = 0; i < 5; i++) {
        if (strcmp(usernames[i], input) == 0) {
            valid = 1;
            break;
        }
    }
    
    if (valid) {
        int number;
        printf("Enter a number to calculate its factorial: ");
        scanf("%d", &number);
        printf("The factorial of %d is %d\n", number, factorial(number));
    } else {
        printf("Invalid username.\n");
    }
    
    return 0;
}

10. #include <stdio.h>
#include <string.h>

char usernames[5][20] = {"alice", "bob", "carol", "dave", "eve"};
char passwords[5][20] = {"alice123", "bob123", "carol123", "dave123", "eve123"};

int authenticate(char username[], char password[]) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(usernames[i], username) == 0 && strcmp(passwords[i], password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char username[20], password[20];
    int choice;
    
    while (1) {
        printf("1. Login\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            
            if (authenticate(username, password)) {
                printf("Login successful!\n");
                // Perform actions for logged in user
            } else {
                printf("Invalid username or password.\n");
            }
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
ss