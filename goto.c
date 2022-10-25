#include <stdio.h>
int main(int argc, char **argv)
{
	printf("main.0\n");
	void g(void *label) {
		printf("g()\n");
		goto *label;
	};
	printf("main.1\n");
	g(&&l2);
	printf("main.2\n");
l2:
	printf("main.3\n");
	return 0;
}
