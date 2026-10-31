#Makefile

src =   $(wildcard main.cpp src/*.cpp)

obj =   $(src:.cpp=.o)

comp  =   clang++

bin =   gameoflife

bintest	=	test

cxxflags   =   -std=c++20 -g3

ldflags	=	-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all: $(bin)

$(bin): $(obj)
	    $(comp) $(obj) $(cxxflags) $(ldflags) -o $(bin)

%.o: %.cpp
	$(comp) $(cxxflags) -c $< -o $@

clean:
	    rm -f $(obj)

fclean:	clean
	rm -f $(bin)
	rm -f $(bintest)
	rm -f *.gcno *.gcda

re: fclean all

unittest:
	$(cc) $(cxxflags) src/*.cpp testfile/unittest.cpp -lcriterion --coverage -o $(bintest)
	rm -f *.gcno *.gcda
