HEADERS = $(wildcard *.h)
CFILES = $(wildcard *.c)
OBJECTS = $(CFILES:%.c=%.o)
EXE = treetest

C_FLAGS = -Wall --pedantic-errors -O2

CC = gcc

treetest: ${CFILES} ${HEADER}
	${CC} ${C_FLAGS} ${CFILES} -o ${EXE}

%.o: %.cpp ${HEADERS}
	${CC} -c $<

.PHONY: clean

clean:
	-@rm -f ${OBJECTS}
	-@rm -f ${EXE}
