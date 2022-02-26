GCCFLAGS = -Wall -ansi -gstabs

all: mytest.out play5.out play7.out

mytest.out: card.o pokerhand.o mytest.o
	g++ -gstabs card.o pokerhand.o mytest.o -o mytest.out

play5.out: card.o pokerhand.o play5.o
	g++ -gstabs card.o pokerhand.o play5.o -o play5.out

play7.out: card.o pokerhand.o play7.o
	g++ -gstabs card.o pokerhand.o play7.o -o play7.out

mytest.o: mytest.cpp pokerhand.h
	g++ $(GCCFLAGS) -c mytest.cpp

play7.o: play7.cpp pokerhand.h
	g++ $(GCCFLAGS) -c play7.cpp

play5.o: play5.cpp pokerhand.h
	g++ $(GCCFLAGS) -c play5.cpp

pokerhand.o: pokerhand.cpp pokerhand.h
	g++ $(GCCFLAGS) -c pokerhand.cpp

card.o: card.cpp card.h
	g++ $(GCCFLAGS) -c card.cpp

clean:
	rm *.o *.out

submit:
	cp card.cpp pokerhand.h pokerhand.cpp mytest.cpp ~/cs202proj/proj2/
