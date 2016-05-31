CC=g++
C++FLAGS=-Wall -std=c++11



OBJ=main.o
PROG=Maxpath

%.o : %.cpp
	$(CC)  -c $< -o $@ $(C++FLAGS)

all:
	make $(PROG)
	



$(PROG): $(OBJ)
	$(CC) $(C++FLAG) -o $@ $(OBJ)


clean:
	(rm -f *.o;)
	rm -f $(PROG)
