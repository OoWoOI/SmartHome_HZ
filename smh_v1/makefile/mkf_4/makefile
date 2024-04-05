.PHONY:../mkf_1 ../mkf_3/ clean

DIR=../mkf_1 ../mkf_3 

all:${DIR}


${DIR}:
	make -C $@
clean:
	echo $(shell for dir in ${DIR};do make -C $$dir clean;done)
