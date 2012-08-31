#include <string.h>
#include "libc.h"

char *strtok_r(char *s, const char *sep, char **p)
{
	if (!s && !(s = *p)) return NULL;
	s += strspn(s, sep);
	if (!*s) return *p = 0;
	*p = s + strcspn(s, sep);
	if (**p) *(*p)++ = 0;
	else *p = 0;
	return s;
}

weak_alias(strtok_r, __strtok_r);
