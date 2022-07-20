CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD 
OBJECTS = start.o DcTims.o gooseNestings.o goToDcTims.o main.o player.o property.o grid.o templatedesign.o randomUint.o ownable.o subject.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = test

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}


clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}