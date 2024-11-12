
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

main: Carte.o main.o
	$(CXX) $^ -o $@

.PHONY: run clean

run: main
	./$<

clean:
	rm -f *.o *~ *.core 