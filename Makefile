CC ?=gcc
exe:=cal
obj:=cal.o

.PHONY: all
all:$(obj)
	$(CC) -o $(exe) $(obj)
%.o:%.c
	$(CC) -c $^ -o $@

.PHONY:clean
clean:
	rm -rf $(obj) $(exe)