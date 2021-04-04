/**
 * Exercise 7 - Convolutions and Edge detection!
 *
 * Please read the comments below carefully, they describe your task in detail.
 * Any clarifications and corrections will be posted to Piazza so please keep
 * an eye on the forum!
 *
 * Starter code:  Mustafa Quraish, 2020
 */

#include "imgUtils.c"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Image dimensions
#define SIZEX 1200
#define SIZEY 1088

// Kernel size
#define K_SIZE 3

// Declaration of the X and Y kernel matrices.
double GX[K_SIZE][K_SIZE] = {
    {1, 0, -1},
    {2, 0, -2},
    {1, 0, -1},
};

double GY[K_SIZE][K_SIZE] = {
    {1, 2, 1},
    {0, 0, 0},
    {-1, -2, -1},
};

/*****************************************************************************/

double convolve(unsigned char inp[SIZEY][SIZEX], int px, int py,
                double kernel[K_SIZE][K_SIZE])
{
  /**
   * Perform the convolution of the given kernel and the image with (px, py) as
   * the center pixel. In essense, the center of the kernel is placed at the
   * given pixel, and you compute weighted sum (refer to tha handout for an
   * example) and return it.
   *
   * If (px, py) is one of the pixels at the edge of the screen (and thus part
   * of the kernel is leaking outside the image), you may assume that those
   * pixels are black. In other words, you should pretend that all pixels
   * outside the image are just black for the sake of computation.
   *
   * Note: In this case, the weighted sum is also an integer because of GX and
   *       GY. However, in general the kernels can have floating point values,
   *       so doing it this way will let you generalize your solution much more
   *       easily if you wish to do so.
   */

  double sum = 0;

  for( int y=py-1; y<py+K_SIZE-1; y++ ) {
    for( int x=px-1; x<px+K_SIZE-1; x++) {
      if( x>=0 && x<SIZEX && y>=0 && y<SIZEY) {
        sum += inp[y][x] * kernel[y-py+1][x-px+1];
      }
    }
  }


/*
  for(int x = 0; x<K_SIZE;x++){
    for(int y = 0; y<K_SIZE;y++){
      if(px+x-1 < 0 || px+x+1 >= SIZEX || py+y-1 < 0|| py+y+1 >=SIZEY){
        sum += 0;
      }else{
        sum += kernel[y][x] * inp[py+y-1][px+x-1];
      }
    }
  }
*/
  return sum; // Return with the correct value
}

void sobel(unsigned char inp[SIZEY][SIZEX], unsigned char out[SIZEY][SIZEX])
{
  /**
   * Given an input image, perform the Sobel edge detection algorithm and store
   * the output in `out`.  Remember that this boils down to:
   *
   * for pixel in input:
   *    g_x = convolve GX at pixel
   *    g_y = convolve GY at pixel
   *    set corresponding output pixel to sqrt(g_x^2 + g_y^2)
   *
   * Note: The expression sqrt(g_x^2 + g_y^2) may result in values greater than
   *       255. If the value is greater, just set it equal to 255. Round down
   *       in case of floating point values.
   */
  for( int py=0; py<SIZEY; py++ ) {
    for( int px=0; px<SIZEX; px++ ) {

      

      double gx = convolve(inp, px, py,  GX);
      double gy = convolve(inp, px, py,  GY);

      int output = sqrt( gx * gx + gy * gy);
      if( output > 255)
        output = 255;

      out[py][px] = output;

    }
  }

  return; // Update `out` before returning
}

/*****************************************************************************/

#ifndef __testing__ // You know the drill, don't remove this

int main()
{
  /* Feel free to change the contents INSIDE the main function to help test */

  // Initialize the 2D-arrays that will store the values of the pixels
  unsigned char (*data)[SIZEY] = malloc( sizeof (unsigned char[SIZEY][SIZEX] ));
  unsigned char edge[SIZEY][SIZEX];

  // We will store the values of the input image
  printf("Try to read file...\n");
  readPGM("tartarglia.pgm", &data[0][0]);
  printf("finlished read file.\n");

  // Test convolve()
  /*double res = convolve(data, 0, 0, GY);
  if (res != -132.0)
  {
    printf("Error: convolve() test 1 output incorrect.\n");
    printf("Expected: %f,  Yours: %f\n", -132.0, res);
    exit(1);
  }

  // Pixel somewhere in the middle
  res = convolve(data, 324, 218, GX);
  if (res != -21.0)
  {
    printf("Error: convolve() test 2 output incorrect.\n");
    printf("Expected: %f,  Yours: %f\n", -21.0, res);
    exit(1);
  }

  printf("- convolve() output was correct.\n");
*/
  // Call the sobel function
  sobel(data, edge);

  // Write the values to the output image
  writePGM("output-tar.pgm", &edge[0][0]);

  // Compare to the expected image
  readPGM("expected.pgm", &data[0][0]);

  for (int i = 0; i < SIZEX; i++)
  {
    for (int j = 0; j < SIZEY; j++)
    {
      if (data[j][i] != edge[j][i])
      {
        printf("Error: Pixel (x=%d, y=%d) has the wrong colour.\n", i, j);
        printf("Expected: %u,  Yours: %u\n", data[j][i], edge[j][i]);
        exit(1);
      }
    }
  }

  printf("- sobel() output was correct.\n");
  return 0;
}

#endif
