#	g++ -DLOCAL -O2 -std=c++17 -Wall -Wextra -pedantic -Wshadow -Wno-variadic-macros -D_GLIBCXX_DEBUG  -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined T.cpp -o T


cmp:
	g++ -DLOCAL -DUBUNTU -O2 -std=c++17 -Wall -Wextra -pedantic -Wshadow -Wno-variadic-macros -D_GLIBCXX_DEBUG  -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -I/mnt/C/users/ishan/coding_stuff/cp/testing/ solve.cpp -o solve
run:
	time ./solve < in
#precompile:
#	g++ -DLOCAL -DUBUNTU -O2 -std=c++17 -Wall -Wextra -pedantic -Wshadow -Wno-variadic-macros -D_GLIBCXX_DEBUG  -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined debugger.hpp
fast:
	g++ -O3 solve.cpp -o solve

