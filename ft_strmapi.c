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