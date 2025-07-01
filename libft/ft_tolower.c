/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpandya <tpandya@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:39:56 by tpandya           #+#    #+#             */
/*   Updated: 2025/05/11 18:39:57 by tpandya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
#include <stdio.h>
int main(void)
{
    char test_chars[] = {'A', 'Z', 'M', 'a', 'z', 'm', '0', '@', '\n'};
    int size = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("Testing ft_tolower:\n");
    for (int i = 0; i < size; i++)
    {
        char original = test_chars[i];
        char converted = ft_tolower(original);
        printf("Original: %c (ASCII %d) -> Lowercase: %c (ASCII %d)\n", 
               original, original, converted, converted);
    }
    
    return 0;
}
*/
