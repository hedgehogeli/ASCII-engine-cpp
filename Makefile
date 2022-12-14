CXX = g++ 
CXXFLAGS = -std=c++14 -Wall -MMD -lncurses -g
EXEC = game1
OBJECTS = spaceInvaders.o gameObj.o engine.o model.o cell.o textView.o curseView.o controller.o curseControl.o collider.o dmgCollide.o stopCollide.o bounceCollide.o gameEndCollide.o boundaryCollide.o boundaryEndCollide.o boundaryDestroyCollide.o mvmt.o acceleration.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} ${GIVEN} -o ${EXEC} ${CXXFLAGS}
	
-include ${DEPENDS}

.PHONY:clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
