/**
 * Exercise 3 - Fun with Pointers
 *
 * Please read the comments below carefully, they describe your task in detail.
 * Any clarifications and corrections will be posted to Piazza so please keep
 * an eye on the forum!
 *
 * NOTE: You should NOT use array notation inside your functions. Use only
 *       pointer notation for any code that you write.
 *
 * Starter code:  Mustafa Quraish, 2020
 */

#include <stdio.h>
#include <stdlib.h>
// NO additional imports allowed. You *can* make helper functions if you wish.

#define MAX_STRING_LEN 1024

int check_str(char *str, char*a){
  if( *str != *a )
    return 0;

  while(*str!=0 && *a!=0){
    if(*(str++) != *(a++)){
      return 0;
    }
  }
  return 1;
}

char *find_last_substring(char *str, char *a)
{
  /**
   * Given a string `str` and another string `a`, return a pointer to the start
   * of the *LAST* occurrence of `a` in `str`. (Unlike ex2, where you had to
   * find the FIRST occurrence).
   *
   * For instance, if we had:                       (here)
   *                                                  V
   *      char str[MAX_STRING_LEN] = "Hello everyone, Hello world!"
   *      char *res = find_last_substring(str, "Hello");
   *
   * then, we would except `res` to be a pointer to the character marked above.
   * In particular, since the second "Hello" is at index 16, we should get
   * the following:
   *
   *      res - str == 16;      (This is pointer arithmetic)
   *
   * If `a` is not a valid substring of `str`. return NULL.
   */
  char *position = NULL;
  while(*str != '\0'){
    if(check_str(str,a)){
      position = str;
    }
    str++;
  }
  return position; // Replace with correct return
}




int check_vowel(char ch){
  //lower cases
  if(ch == 'a' ||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u'){
    return 1;
  }
  //Upper cases
  if(ch == 'A'||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U'){
    return 1;
  }
  return 0;
}

void split_vowels(char *str, char *vowels)
{
  /**
   * Move all of the vowels from `str` (in the order of appearance) to the
   * string `vowels`. (ie, after the function call `str` should not have any
   * vowels in it). You may assume there is enough space allocated in `vowels`.
   *
   * Look at the test case below for an example.
   */
  char *current = NULL;
  current = str;
  while(*str != '\0'){
    if (check_vowel(*str)){
      *vowels = *str;
      vowels++;
    }else{
      *current = *str;
      current++;
    }
    str++;
  }
  *vowels = '\0';
  *current = '\0';
  return; // Not returning anything. `str` and `vowels` modified directly.
}

// ----------------------------------------------------------------------------

// Do not change the lines above and below the main function. These
// are here to ensure that the main() function defined here does not
// Conflict with the automarker when testing your code. Changing them
// will result in a 0 for this exercise. You are free to change anything
// inside the main() function itself.
#ifndef __testing__
int main()
{
  char my_str[MAX_STRING_LEN] = "many many people have many many hobbies";
  char *res = find_last_substring(my_str, "many");
  if (res - my_str == 27){
    printf("- find_last_substring() returned the correct result!\n");
  }
  else{
    printf("! find_last_substring() did not work properly.\n");
  }

  printf("----------------------------------------------------------------\n");

  char str[MAX_STRING_LEN] = "This sentence has many vowels! AEIOU";
  char vowels[MAX_STRING_LEN];
  split_vowels(str, vowels);

  printf("(Expected Result) str: \"Ths sntnc hs mny vwls! \", "
         "vowels: \"ieeeaaoeAEIOU\"\n");
  printf("(Your Solution) str: \"%s\", vowels: \"%s\"\n", str, vowels);
}
#endif
