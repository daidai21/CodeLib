/* =============================================================================
> File Name: implement_class_encapsulation_example.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Mon 16 Dec 2019 09:48:34 PM CST
============================================================================= */


/**
 * implement OOP with C
 */

// TODO: inheritance, ploymorphism


#include <stdio.h>
#include <stdlib.h>


typedef struct {
  double length;
  double breadth;
  double height;
} Box;


Box* Box_molloc(double length, double breadth, double height) {
  Box* result = (Box* ) malloc(sizeof(Box));
  result->length = length;
  result->breadth = breadth;
  result->height = height;
  return result;
}


void Box_free(Box* box) {
  free(box);
}


void Box_set_length(Box* box, double length) {
  box->length = length;
}


void Box_set_breadth(Box* box, double breadth) {
  box->breadth = breadth;
}


void Box_set_height(Box* box, double height) {
  box->height = height;
}

double Box_get_volume(const Box* box) {
  return box->length * box->breadth * box->height;
}

void Box_output(const Box* box) {
  printf("++++++++++++++++++++\n");
  printf("class Box: \n");
  printf("length is %lf, breadth is %lf, height is %lf\n", 
    box->length, box->breadth, box->height);
  printf("volume is %lf\n", Box_get_volume(box));
  printf("++++++++++++++++++++\n");
}


int main() {
  Box* box = Box_molloc(1, 2, 3);
  Box_output(box);
  Box_set_length(box, 4);
  Box_set_breadth(box, 5);
  Box_set_height(box, 6);
  Box_output(box);
  Box_free(box);

  return 0;
}

