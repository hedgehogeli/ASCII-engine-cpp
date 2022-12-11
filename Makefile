CXX = g++ 
CXXFLAG = -std=c++14 -Wall -g -MMD 		#consider -g for debugger
EXEC = main
OBJECTS = main.o engine.o model.o cell.o textView.o curseView.o controller.o curseControl.o gameObj.o CharGameObj.o  # RectGameObj.o BmpGameObj.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}
	
-include ${DEPENDS}

.PHONY:clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
