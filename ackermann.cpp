/*
 * Iterative computation of the Ackermann function
 * (https://en.wikipedia.org/wiki/Ackermann_function).
 */
#include <iostream>       // std::cout
#include <vector>         // std::vector
#include <stdlib.h>       // atol

int main(int argc, char **argv)
{
	std::vector<long> s;
	long              n;
	long              m;

	n = atol(argv[1]);
	m = atol(argv[2]);

	s.push_back(n);
	s.push_back(m);
	while (s.size() != 1) {
		n = s.back();
		s.pop_back();
		m = s.back();
		s.pop_back();
		if (m == 0)
			s.push_back(n + 1);
		else if (n == 0) {
			s.push_back(m - 1);
			s.push_back(1);
		} else {
			s.push_back(m - 1);
			s.push_back(m);
			s.push_back(n - 1);
		}
		std::cout << "[";
		for (const auto i: s)
			std::cout << i << " ";
		std::cout << "]\n";
	}
	return 0;
}
