#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of ints,
 * printing the current element every time it is compared to value
 *
 * @list: pointer to the head of the skip list to sort in,
 * list is sorted in ascending order
 * @value: the value to search for
 *
 * Return: pointer to the first node in the list where value is located,
 * or NULL if value is not in the list or head of the list is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *mover = NULL, *express = NULL;
	char string1[24] = "Value checked at index ";
	char string2[29] = "Value found between indexes ";

	if (list == NULL)
		return (NULL);
	mover = list;
	express = list;
	while (express->express)
	{
		mover = express;
		express = express->express;
		printf("%s[%ld] = [%d]\n", string1, express->index, express->n);
		if (express->n >= value)
			break;
		if (express->express == NULL)
		{
			mover = express;
			while (express->next)
				express = express->next;
		}
	}
	printf("%s[%ld] and [%ld]\n", string2, mover->index, express->index);
	while (mover->next && mover->index != express->index)
	{
		printf("%s[%ld] = [%d]\n", string1, mover->index, mover->n);
		if (mover->n >= value)
			break;
		mover = mover->next;
	}
	if (mover->next == NULL)
		printf("%s[%ld] = [%d]\n", string1, mover->index, mover->n);
	if (mover->n == value)
		return (mover);
	return (NULL);
}
