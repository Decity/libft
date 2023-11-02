/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:58:34 by elie              #+#    #+#             */
/*   Updated: 2023/11/02 17:58:36 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*cstr;

	i = 0;
	cstr = (char *)malloc((ft_strlen(s) + 1 ) * sizeof(char));
	if (!cstr)
		return (NULL);
	if (!s || !f)
		return
	while (s[i])
		cstr[i] = f(i, &s[i++]);
	return (cstr);
}
