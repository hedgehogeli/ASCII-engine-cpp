CXX = g++ 
CXXFLAGS = -std=c++14 -Wall -MMD -lncurses -g
EXEC = main
OBJECTS = main.o gameObj.o engine.o model.o cell.o textView.o curseView.o controller.o curseControl.o collider.o dmgCollide.o stopCollide.o bounceCollide.o gameEndCollide.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} ${GIVEN} -o ${EXEC} ${CXXFLAGS}
	
-include ${DEPENDS}

.PHONY:clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
