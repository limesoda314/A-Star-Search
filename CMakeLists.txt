CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test.out
	test.cpp
	src/AStar.cpp
	src/Board.cpp
	src/Problem.cpp
	src/Tree.cpp
)

ADD_EXECUTABLE(main.out
	main.cpp
	src/AStar.cpp
	src/Board.cpp
	src/Problem.cpp
	src/Tree.cpp
)

ADD_COMPILE_OPTIONS(-g -O0 -fno-inline)