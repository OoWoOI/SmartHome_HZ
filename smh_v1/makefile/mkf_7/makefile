
define fun1
	ifeq ($(1), $(2))
		RET:=true
	else
		RET:=false
	endif
		
	return RET
endef

all:
	echo $(call fun1,abc,def)
