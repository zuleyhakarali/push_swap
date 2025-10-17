#include "push_swap.h"

int *bubble_sort(int size, int *arr)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
    return (arr);
}

void arr_to_idx(int size, int *arr, t_list **stack)
{
    int i;
    t_list *tmp;

    tmp = (*stack);
    while (tmp)
    {
        i = 0;
        while (i < size)
        {
            if (tmp->content == arr[i])
            {
                tmp->index = i;
                break;
            }
            i++;
        }
        tmp = tmp->next;
    }
}

void indexing(t_list **stack)
{
    int *arr;
    int size;
    int i;
    t_list *tmp;

    size = ft_lstsize(*stack);
    arr = malloc(size * sizeof(int));
    if (!arr)
        return;
    tmp = (*stack);
    i = 0;
    while (tmp)
    {
        arr[i++] = tmp->content;
        tmp = tmp->next;
    }
    bubble_sort(size, arr);
    arr_to_idx(size, arr, stack);
    free(arr);
}