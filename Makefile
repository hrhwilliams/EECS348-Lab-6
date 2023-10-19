CPP := g++

matrix: matrix.cpp
	$(CPP) matrix.cpp -o $@
