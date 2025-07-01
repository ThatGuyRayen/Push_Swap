#include <stdio.h>
#include <stdlib.h>

int	get_max(int *arr, int n)
{
	int	max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

void	counting_sort(int *arr, int n, int exp)
{
	int *output = malloc(sizeof(int)*n);
	int	count[10] = {0};
	//counting occurrences of digit
	for (int i = 0; i < n; i++)
		count[(arr[i]/exp) % 10]++;
	//counting count[] to acutal position
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];
	//build output array
	for (int i = n -1; i >= 0; i--)
	{
		int digit = (arr[i]/exp) % 10;
		output[--count[digit]] = arr[i];
	}
	//copying sorted numbers back to arr
	for (int i = 0; i < n; i++)
		arr[i] = output[i];
	free(output);
}

void	radix_sort(int *arr, int n)
{
	int	max = get_max(arr, n);
	for (int exp = 1; max/exp > 0; exp *= 10)
		counting_sort(arr, n, exp);
}

int	main()
{
	int	arr[] = {123,252,1325,2,25,2,5,12};
	int	n = sizeof(arr) / sizeof (arr[0]);
	radix_sort(arr, n);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return (0);
}
