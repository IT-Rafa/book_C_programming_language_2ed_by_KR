/**
 * @file exercise_2-4.c
 * @brief Exercise 2-4 from section 2.8
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-9-12
 * 
 */

/* LIBRARIES */
#include <stdio.h>

/* SYMBOLIC CONSTANTS */

/* EXTERNAL VARIABLES */
/* FUNCTIONS DECLARATIONS */
int squeeze(char st[], char clist[]);
/* FUNCTIONS DEFINITIONS */

/**
 * @brief Exercise 2-4 from section 2.8.
 * Exercise 2-4. Write an alternate version of squeeze(s1, s2) that deletes   
 * each character in s1 that match any character in the string s2.
 * 
 * @return int State of program value
 */
int main(void)
{
    int n;
    char s[] = "number1, number2";
    char cList[] = "number, ";
    printf("del chars in string: \"%s\"\nfrom string: \"%s\"\n", cList, s);
    n = squeeze(s, cList);
    printf("%d chars deleted\nResult:\n\"%s\"\n", n, s);

    return 0;
}
/**
 * @brief deletes each character in st that match any character in the string clist
 * 
 * @param st String to be modified
 * @param clist String with the chars to delete
 * @return int Number of deleted chars
 */
int squeeze(char st[], char clist[])
{
    int n = 0;
    int i; // original index
    int j; // new index
    //step through original string
    for (i = j = 0; st[i] != '\0'; i++) {
        // Compare with each char in cList
        int find = 0;
        for (int x = 0; clist[x] != '\0' && find == 0; x++) {
            if (st[i] == clist[x]) {
                find = 1;
            }
        }
        // move no coincident char
        if (find != 1) {
            st[j++] = st[i];
            ++n;
        }
    }
    // new end-of-string
    st[j] = '\0';
    return i - n;
}
