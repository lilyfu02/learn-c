/** 
 * Exercise 2 - Fun with Strings
 *  
 * Please read the comments below carefully, they describe your task in detail. 
 * Any clarifications and corrections will be posted to Piazza so please keep 
 * an eye on the forum!
 * 
 * Starter code: Mustafa Quraish, 2020
 */

#include <stdio.h>
// NO additional imports allowed. You *can* make helper functions, and in fact I strongly
// encourage doing so to make your life easier.

// Maximum length of a string
#define MAX_STRING_LEN 1024

//-----------------------------------------------------------------------------
int str_len(char arr[]){
  int i = 0;
  while (arr[i] != '\0'){
    i++;
  }
  return i;
}

int start_with(char *src, char *dst){
  while(*dst != '\0'){
    if(*src++ != *dst++){
      return 0;
    }
  }
  return 1;
}

void replaceSubstring(char str[], char a[], char b[])
{
  /**
   * If `a` is a substring of `str`, then the first occurence of `a` in `str`
   * is replaced with `b`.
   *
   * For example:
   *
   *    char str[50] = "Hello World!";
   *    replaceSubstring(str, "llo W", "---");
   *    printf("%s\n", str);
   *
   * should print out "He---orld!"
   *
   * You may assume that `str[]`` has enough space to store the modified string.
   * Remember that all the strings here all null-terminated, and you must
   * also null-terminate the modified string.
   */
  int pos = 0;
  int a_len = str_len(a);
  int b_len = str_len(b);
  int tail_len;
  while(str[pos] != '\0'){
    if(start_with(str+pos,a)){
      tail_len = str_len(str+pos+a_len);
      if(a_len < b_len){
        for(int i = tail_len+1;i >= 0; i--){
          str[pos+b_len+i] = str[pos+a_len+i];
        }
        for(int i = 0;i < b_len; i++){
          str[pos+i] = b[i];
        }
      }else{
        for(int i = 0;i<b_len;i++){
          str[pos+i] = b[i];
        }
        for(int i = 0;i<tail_len+1;i++){
          str[pos+b_len+i] = str[pos + a_len +i ];
        }
      }
      return;   // Just for the first time
    }
    pos++;
  }
  return; // Not returning anything. `str` is modified directly.
}

void changeSubstringCase(char str[], char a[])
{
  /**
   * If `a` is a substring of `str`, then change the case (capitalization) of
   * the first occurence of the corresponding substring in `str`. Special 
   * characters (' ', '.', ...) do not need to be handled. You should only 
   * change the letters.
   *
   * For example:
   *
   *    char str[100] = "This IS a SENTence WITH BAd CAPITalizaTION";
   *    changeSubstringCase(str, "IS a SENTence WI");
   *    printf("%s\n", str);
   *
   * should print out "This is A sentENCE wiTH BAd CAPITalizaTION".
   */
  int a_len = str_len(a);
  
  int pos = 0;
  while(str[pos] != '\0'){
    if(start_with(str+pos,a)){
      for(int i = pos;i<pos+a_len;i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
          str[i] = str[i] + 'a' - 'A';
        }else if(str[i] >= 'a' && str[i] <= 'z'){
          str[i] = str[i] - 'a' + 'A';
        }
      }
      return;
    }
    pos++;
  }
  return; // Not returning anything. `str` is modified directly.
}

//-----------------------------------------------------------------------------

// Do not change the lines above and below the main function. These
// are here to ensure that the main() function defined here does not
// Conflict with the automarker when testing your code. Changing them
// will result in a 0 for this exercise. You are free to change anything
// inside the main() function itself.
#ifndef __testing__
int main()
{
  char str[MAX_STRING_LEN] = "CSCA48 Exercise 1";

  // This should replace the substring:
  replaceSubstring(str, "C", "CSCA68");

  // This should NOT replace anything, since some of the letters
  // in `a` have a different capitalization than in the string, so it is
  // NOT a valid substring.
  replaceSubstring(str, "a68", "Winter 2020");

  // This should change the capitalization of the substring:
  changeSubstringCase(str, "A");

  // This should NOT change the capitalization, since the corresponding letters
  // in `a` are lowercase, and it is not a valid substring.
  changeSubstringCase(str, "csca48");

  printf("Expected result: \"CSCa68SCA48 Exercise 1\"\n");
  printf("  Your solution: \"%s\"\n", str);
  return 0;
}
#endif
