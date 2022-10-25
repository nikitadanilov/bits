/* gcc -fplan9-extensions unnamed.c */

struct foo {
	int something;
};

struct lockedfoo {
	struct foo;
};

struct lockedfoo *lock(struct foo *m) {
	/* lock &m->lock... */
	return (void *)m;
}

struct foo *unlock(struct lockedfoo *lm) {
	/* unlock &m->lock... */
	return (void *)lm;
}

void use(struct lockedfoo *lf)
{
	lf->something++;
}

int main(int argc, char **argv)
{
	struct foo f;
	struct lockedfoo *lf = lock(&f);

	use(lf);
	unlock(lf);
	return 0;
}
