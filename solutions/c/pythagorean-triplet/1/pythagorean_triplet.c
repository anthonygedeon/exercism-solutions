#include "pythagorean_triplet.h"

#include <stdio.h>
#include <stdlib.h>

triplets_t *triplets_with_sum(uint16_t sum)
{
  triplets_t *t = malloc(sizeof(triplets_t));
  t->count = 0;
  t->triplets = malloc(sizeof(triplet_t) * 32);

  for (int i = 1; i < sum; i++)
  {
    for (int j = i; j < sum; j++)
    {
	for (int k = j; k < sum; k++)
	{
	  if ((i * i) + (j * j) == (k * k)
	      && i < j && j < k
	      && i + j + k == sum)
	    {
	    t->triplets[t->count++] = (triplet_t){ i, j, k };
	    }
	}
      }
  }

  return t;
} 

void free_triplets(triplets_t *triplets)
{
  free(triplets->triplets);
  free(triplets);
}
