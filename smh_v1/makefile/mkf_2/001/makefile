.PHONY:clean

OBJ = SoTest.so Test SoTest.o
LIB = SoTest
	
main:SoTest.so Test.cpp main.cpp
	g++ -l$(LIB) main.cpp Test.cpp  -o $@ -L.

libSoTest.so:libSoTest.o
	g++ -shared $^ -o $@

libSoTest.o:SoTest.cpp
	g++ -fPIC -c $^ -o $@

clean:
	$(RM) $(OBJ)
