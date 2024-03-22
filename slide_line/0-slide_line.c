#include <stdlib.h>
#include "slide_line.h"


/**
 * slide_line - Slide and merge an array of integers
 * @line: Pointer to the array of integers
 * @size: Size of the array
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j, k;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return 0;

    if (direction == SLIDE_LEFT)
    {
        for (i = 0, j = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (j != i)
                    line[j] = line[i];
                j++;
            }
        }
        for (k = j; k < size; k++)
            line[k] = 0;
    }
    else if (direction == SLIDE_RIGHT)
    {
        for (i = size - 1, j = size - 1; (int)i >= 0; i--)
        {
            if (line[i] != 0)
            {
                if (j != i)
                    line[j] = line[i];
                j--;
            }
        }
        for (k = j; (int)k >= 0; k--)
            line[k] = 0;
    }

    for (i = 0; i < size - 1; i++)
    {
        if (line[i] == line[i + 1])
        {
            line[i] *= 2;
            line[i + 1] = 0;
        }
    }

    if (direction == SLIDE_RIGHT)
    {
        for (i = size - 1, j = size - 1; (int)i >= 0; i--)
        {
            if (line[i] != 0)
            {
                if (j != i)
                    line[j] = line[i];
                j--;
            }
        }
        for (k = j; (int)k >= 0; k--)
            line[k] = 0;
    }

    return 1;
}
