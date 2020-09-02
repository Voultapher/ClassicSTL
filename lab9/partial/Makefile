CXXFLAGS= -std=c++17 -O2 -W -Wall -Wextra -pedantic
OBJFILES= lab9.m.o

lab9: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES) lab9

.PHONY: clean
