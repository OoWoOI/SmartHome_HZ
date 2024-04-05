.PHONY: clean show


#OBJ=sub.o mult.o calc.o 
OBJ=${patsubst %.c, %.o, ${wildcard ./*.c}}
TARGET=calc


${TARGET}: $(OBJ)
	${CXX} $^ -o $@

%.o:%.c
	${CXX} -c $^ -o $@
clean:
	${RM} -rf ${OBJ} ${TARGET}


show:
	echo $(AS)
	echo $(CC)
	echo $(CPP)
	echo $(CXX)
	echo $(RM)
	echo ${patsubst %.c, %.o, $(wildcard ./*.c)}
	echo ${patsubst %.c, %.o, ./*.c}
	echo $(wildcard ./*.c)
