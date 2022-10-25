/* gcc -O3 -Wall sideeffect.c */

#include <stdio.h>
#include <string.h>

static const char x[1];

/* Returns true, if "e" has side-effects. */
#define HAS_SE(e) \
	(__builtin_object_size(&x[!!(unsigned long long)(e)], 0) == (size_t)-1)

__attribute__((pure)) int f(int a, int b)
{
	return a + b;
}

int main(int argc, char **argv)
{
	printf("%i %i %i %i %i %i %i %i [%i]\n",
	       HAS_SE(0),        /* false */
	       HAS_SE(argc++),   /* true */
	       HAS_SE(1.0/1.0),  /* false */
	       HAS_SE(1.0/0.0),  /* true -- exception */
	       HAS_SE(&x),       /* false */
	       HAS_SE(&f + 1),   /* false */
	       HAS_SE(f(2, 2)),  /* false -- pure */
	       HAS_SE(strlen("abc")),  /* false! */
	       argc);
	return 0;
}
