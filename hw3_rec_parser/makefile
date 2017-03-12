SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:%.cpp=%.o)

CPP =g++

CFLAGS = -Wall --pedantic-error -O2


program: ${OBJECTS}
	${CPP} ${OBJECTS} -o program

%.o:%.cpp ${HEADERS}
	${CPP} -c $<

.PHONY: checks
checks: ${OBJECTS}
	${CPP} ${CFLAGS} ${OBJECTS} -o warn

%.o:%.cpp ${HEADERS}
	${CPP} ${CFLAGS} -c $<

.PHONY: debug
debug: CFLAGS = -g -Wall --pedantic-errors
debug: program

.PHONY: clean
clean:
	-@rm -f program
	-@rm -f warn
	-@rm -f *.o
	-@rm -f a.out
