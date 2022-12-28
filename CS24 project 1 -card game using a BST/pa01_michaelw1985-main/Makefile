CPP = g++ -std=c++11
CPPFLAGS = -Wall -Wno-uninitialized


#all
#all: card.o, cardBST.o, main.o
#	$(CPP) $(CPPFLAGS) $^ -c $@


#everything else
game: main.o
	$(CPP) $(CPPFLAGS) $^ -o $@

cards.o: cards.h
	$(CPP) $(CPPFLAGS) -c $^ 

utility.o: utility.cpp, utility.h
	$(CPP) $(CPPFLAGS) -c $^ 

utility: utility.o, cards.o
	$(CPP) $(CPPFLAGS) $^ -o $@

test.o: test.cpp
	$(CPP) $(CPPFLAGS) $^ -c

test: test.o
	$(CPP) $(CPPFLAGS) $^ -o $@

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c $^


