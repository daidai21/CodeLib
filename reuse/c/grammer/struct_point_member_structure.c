/* ****************************************************************************
 * File Name   : reuse/c/grammer/struct_point_member_structure.c
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 三  9/16 17:26:08 2020
 *************************************************************************** */


#include <stdio.h>


struct Book {
  int id;
  char title[10];
};


int main(int argc, char* argv[]) {
  struct Book book = {
    .id = 123,
    .title = "abc"
  };

  printf("book id    %d\n", book.id);
  printf("book title %s\n", book.title);

  return 0;
}

