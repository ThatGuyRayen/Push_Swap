/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:40:03 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/11 18:40:04 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>
int main(void)
{
    char test_chars[] = {'a', 'z', 'm', 'Z', 'A', 'm', '0', '@', '\n'};
    int size = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("Testing ft_tolower:\n");
    for (int i = 0; i < size; i++)
    {
        char original = test_chars[i];
        char converted = ft_toupper(original);
        printf("Original: %c (ASCII %d) -> Uppercase: %c (ASCII %d)\n",
               original, original, converted, converted);
    }

    return 0;
}
*/
