TARGET=a b c d

all:
	touch $(foreach v, ${TARGET}, $v.txt)
clean:
	$(RM) $(foreach v, ${TARGET}, $v.txt)
