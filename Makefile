a.out: main.o Member.o
	clang++-5.0 main.o Member.o -o a.out
main.o: main.cpp
	clang++-5.0 -c main.cpp
Member.o: Member.cpp Member.h
	clang++-5.0 -c Member.cpp
clean:
	rm *.o a.out
