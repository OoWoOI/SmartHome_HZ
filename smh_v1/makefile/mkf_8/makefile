.PHONY:clean install


TARGET:=008_main
OBJ:=$(TARGET).o

CC=g++

PTH:=../008_main/

START_SH=$(TARGET)_start
STOP_SH=$(TARGET)_stop

$(TARGET):$(OBJ)


install:$(TARGET)
	if [ -d $(PTH) ];then\
		echo $(PTH) exist;\
	else\
		mkdir $(PTH);\
		cp $(TARGET) $(PTH);\
		echo $(TARGET)>$(PTH)$(START_SH);\ 
		echo "killall $(TARGET)">$(PTH)$(STOP_SH);\ 
		chmod a+x $(PTH)$(START_SH);\
		chmod a+x $(PTH)$(STOP_SH);\ 
	fi;\
	
clean:
	$(RM) $(TARGET) $(OBJ) $(PTH)$(TARGET) $(PTH)$(START_SH) $(PTH)$(STOP_SH)
	$(RM) -rf $(TARGET) $(OBJ)

