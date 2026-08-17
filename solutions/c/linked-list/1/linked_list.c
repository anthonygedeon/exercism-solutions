#include "linked_list.h"
#include <stdlib.h>

struct list_node
{
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list
{
   struct list_node *first, *last;
};

struct list *list_create(void)
{
   struct list *l = malloc(sizeof(struct list));
   l->first = NULL;
   l->last = NULL;
   return l;
}

size_t list_count(const struct list *list)
{
   size_t length = 0;
   for (struct list_node *node = list->first; node != NULL; node = node->next)
      length++;
   return length;
}

void list_push(struct list *list, ll_data_t item_data)
{
   struct list_node *node =
       (struct list_node *)malloc(sizeof(struct list_node));

   if (list_count(list) == 0)
   {
     node->prev = NULL;
     node->next = NULL;
     node->data = item_data;
     list->first = list->last = node;
   }
   else
   {
     node->next = NULL;
     node->prev = list->last;
     node->data = item_data;
     list->last = node;
   }
}

ll_data_t list_pop(struct list *list)
{
  ll_data_t data = list->last->data;
  list->last = list->last->prev;
  return data;
}

ll_data_t list_shift(struct list *list)
{
  struct list_node *f_head = list->first;

  list->first = list->first->next;

  return f_head->data; 
}

// void list_unshift(struct list *list, ll_data_t item_data) {}


// void list_delete(struct list *list, ll_data_t data) {}

void list_destroy(struct list *list)
{
    struct list_node *node = NULL;
    for (node = list->last; node != NULL;)
    {
      struct list_node *tmp = node->prev;
      free(node);
      node = tmp;
    }

    free(list);
}
