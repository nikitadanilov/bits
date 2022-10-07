/* $(CC) -O3 -fcoroutines -Wall -I/usr/local/include gen.cpp -L/usr/local/lib -lcppcoro -lstdc++ -ogen */
/* https://github.com/andreasbuhr/cppcoro */
#include <memory>
#include <string>
#include <cassert>
#include <iostream>
#include <coroutine>
#include <cppcoro/generator.hpp>

struct tnode;
using tree = std::shared_ptr<tnode>;
struct tnode {
	tree left;
	tree right;
	tnode() {};
	tnode(tree l, tree r) : left(l), right(r) {}
};

auto print(tree t) -> std::string {
	return  t ? (std::string{"["} + print(t->left) + " "
		     + print(t->right) + "]") : "*";
}

cppcoro::generator<tree> gen(int n) {
	if (n == 0) {
		co_yield nullptr;
	} else {
		for (int i = 0; i < n; ++i) {
			for (auto left : gen(i)) {
				for (auto right : gen(n - i - 1)) {
					co_yield tree(new tnode(left, right));
				}
			}
		}
	}
}

int main(int argc, char **argv) {
	for (auto t : gen(std::atoi(argv[1]))) {
		std::cout << print(t) << std::endl;
	}
}
