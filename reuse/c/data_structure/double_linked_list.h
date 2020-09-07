

// https://redisbook.readthedocs.io/en/latest/internal-datastruct/adlist.htmls
// TODO


#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__


/**
 * Double linked list node
 */
typedef struct double_linked_list_node {
  /* previous node pointer */
  struct double_linked_list_node* prev;

  /* next node pointer */
  struct double_linked_list_node* next;

  /* value pointer */
  void* value;

} double_linked_list_node ;


/**
 * Double linked list
 */
typedef struct double_linked_list {
  /* list head pointer */

  /* list tail pointer */

  /* list node size */

  /* copy function */

  /* molloc function */

  /* compare function */

} double_linked_list;


/**
 * Iterator direction
 */
/* from head to tail */
#define DOUBLE_LINKED_LIST_ITERATOR_DIRECTION_HEAD 0
/* from tail to head */
#define DOUBLE_LINKED_LIST_ITERATOR_DIRECTION_TAIL 1


/**
 * Double linked list iterator
 */
typedef struct double_linked_list_iter {
  /* next node pointer */
  double_linked_list* next;

  /* iterator direction */
  int direction;

} double_linked_list_iter;




#endif // __DOUBLE_LINKED_LIST_H__
