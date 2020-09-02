CXXFLAGS= -std=c++14 -O2 -W -Wall -Wextra -pedantic
OBJFILES= lab1.m.o

lab1: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

lab1-bonus: lab1-bonus.m.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES) lab1-bonus.m.o lab1 lab1-bonus.m.o lab1-bonus

.PHONY: clean
