#include "ft_lists.h"
#include "tinytest.h"

void	new_list_size_10()
{
	t_list	*lst = list_new(10);

	ASSERT_EQUALS(sizeof(t_list), sizeof(*lst));
	ASSERT("Pointer equal NULL !", lst != NULL);
	ASSERT_EQUALS(lst->start, NULL);
	ASSERT_EQUALS(lst->end, NULL);
	ASSERT_EQUALS(lst->start, NULL);
	ASSERT_EQUALS(lst->count, 0);
	ASSERT_EQUALS(lst->current, 0);
	ASSERT_EQUALS(lst->elem_size, 10);
}

int	main(void)
{
	RUN(new_list_size_10);
	return (TEST_REPORT());
}
