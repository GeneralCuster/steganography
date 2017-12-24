
main:
	g++ main.cpp -std=c++11 -I/opt/X11/include -o main
clean:
	rm -Rf *.o main main.cpp~ Makefile~ output.png .DS_Store
debug:
	g++ main.cpp -std=c++11 -g -o main
