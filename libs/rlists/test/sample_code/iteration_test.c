#include <ft_lists.h>
#include <stdio.h>

typedef struct	s_sample
{
	float x;
	float y;
	float z;
	float w;
}		t_sample;

t_sample	*sample_new(float x, float y, float z, float w)
{
	t_sample *ret;

	ret = malloc(sizeof(struct s_sample));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	ret->w = w;
	return (ret);
}

int		main(void)
{
	t_list	*list;

	// initializer to the list (the size is purely informational and could be set to 0
	// (might remove this i dont know)
	list = list_new(sizeof(t_sample));
	// you just add some pointers into the list
	list_push_back(list, sample_new(0, 4, 2, 7));
	list_push_back(list, sample_new(1, 3, 9, 6));
	list_push_back(list, sample_new(2, 2, 6, 5));
	list_push_back(list, sample_new(3, 1, 2, 4));
	list_push_back(list, sample_new(4, 2, 5, 3));
	list_push_back(list, sample_new(5, 3, 3, 2));
	list_push_back(list, sample_new(6, 4, 6, 1));
	list_push_back(list, sample_new(7, 5, 1, 0));
	
	// now for iteration, its very simple, you have many ways to do it, the easiest one
	// and most common one is probably this one
	t_sample *iterator;
	t_node	*prev_node;
	t_node	*next_node;

	while ((iterator = list_next(list)) != NULL)
		printf("%f : %f : %f : %f\n",
			iterator->x,
			iterator->y,
			iterator->z,
			iterator->w);
	printf("\n\n");
	// and here, you just printed the whole list, but now the iterator
	// is at the end you can reset it by setting it back to start
	list_set_start(list);
	while ((iterator = list_next(list)) != NULL)
		printf("%f : %f : %f : %f\n",
			iterator->x,
			iterator->y,
			iterator->z,
			iterator->w);
	printf("\n\n");
	//... and print all over again
	// you can also do it the ther way, by setting it at the end
	list_set_end(list);
	while ((iterator = list_prev(list)) != NULL)
		printf("%f : %f : %f : %f\n",
			iterator->x,
			iterator->y,
			iterator->z,
			iterator->w);
	printf("\n\n");
	// you might need to get information about the previous and next node of the node you're currently at
	// you can get them this way
	list_set_start(list);
	while ((iterator = list_next(list)) != NULL)
	{
		if (list->iterator == NULL)
			break ;
		prev_node = list->iterator->prev;
		next_node = list->iterator->next;
		//BUT BE AWARE the list_next method return you the data of the current node, and iterate list->iterator
		//which means for the first iteration of the loop, you're already at index 1 so previous point on index 0
		//list->iterator WILL BE NULL at the last iteration, since it return the value, then iterate (might be a lack
		//of design, would be happy to speak about it)
		printf("%f : %f : %f : %f\n",
			((t_sample *)prev_node->data)->x,
			((t_sample *)prev_node->data)->y,
			((t_sample *)prev_node->data)->z,
			((t_sample *)prev_node->data)->w);
	}
	printf("\n\n");
}
