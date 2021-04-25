/**
 * Exercise 1 - FUNctions!
 *
 * Please read the comments below carefully, they describe your task in detail.
 * Any clarifications and corrections will be posted to Piazza so please keep
 * an eye on the forum!
 *
 * Starter code: Mustafa Quraish, 2021
 */

#include <stdio.h>
// NO additional imports allowed. You *can* make helper functions if you wish.

//-----------------------------------------------------------------------------
#define PRIME 1
#define NO_PRIME 0

int is_prime(int check_val)
{
  /**
   * If `check_val` is a positive prime number (e.g., 2, 3, 5, 7, 11, etc)
   * return 1, otherwise return 0
   */
  if (check_val <= 1){
    return NO_PRIME;
  }else{
    for(int i = 2; i<check_val;i++){
      if (check_val % i == 0){
          return NO_PRIME;
      }
    }
  }
  
  return PRIME; // Replace this
}

float calculate_gpv(int grade){
  /**
   * Given grade as a percentage course grade, return the corresponding grade
   * point value as calculated by the University of Toronto grading scheme
   * (https://www.utsc.utoronto.ca/registrar/u-t-grading-scheme)
   * if grade is not a valid grade, return -1
   */
  float gpa = 0.0;
  if (grade >= 85 && grade <= 100 ){
    gpa = 4.0;
  }else if(grade <= 84 && grade >= 80){
    gpa = 3.7;
  }else if(grade <= 79 && grade >= 77){
    gpa = 3.3;
  }else if(grade <= 76 && grade >= 73){
    gpa = 3.0;
  }else if(grade <= 72 && grade >= 70){
    gpa = 2.7;
  }else if(grade <= 69 && grade >= 67){
    gpa = 2.3;
  }else if(grade <= 66 && grade >= 63){
    gpa = 2.0;
  }else if(grade <= 62 && grade >= 60){
    gpa = 1.7;
  }else if(grade <= 59 && grade >= 57){
    gpa = 1.3;
  }else if(grade <= 56 && grade >= 53){
    gpa = 1.0;
  }else if(grade <= 52 && grade >= 50){
    gpa = 0.7;
  }else if(grade <= 49 && grade >= 0){
    gpa = 0.0;
  }else{
    gpa = -1.0;
  }
  return gpa;
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

  int prime_result1 = is_prime(2);
  int prime_result2 = is_prime(1);
  if (prime_result1 == 1 && prime_result2 == 0)
  {
    printf("- is_prime() returning correct results for sample input\n");
  }
  else
  {
    printf("- is_prime() not returning correct results for sample input\n");
  }

  float gpv_result1 = calculate_gpv(93);
  float gpv_result2 = calculate_gpv(75);
  printf("- calculate_gpv():\n");
  printf("\tExpected result: 93 -> 4.0, 75 -> 3.0\n");
  printf("\tYour solution: 93 -> %.1f, 75 -> %.1f\n", gpv_result1, gpv_result2);
  return 0;
}
#endif
