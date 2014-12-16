CC:=gcc
CFLAGS:=-Wall -Wextra
RM:=rm -rf
EXECUTABLE:=list
CORE:=defs.o Node.o

%.o:	%.c
	$(CC) $(CFLAGS) -c $^ -o $@

%:	%.o %.c
	$(CC) $(CFLAGS) $^ -o $@

node_test: $(CORE)

$(EXECUTABLE):	LList.o $(CORE)

clean:
	$(RM) *.o
