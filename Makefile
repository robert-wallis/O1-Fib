.PHONY = debug
SOURCES=fib.cpp

fib: $(SOURCES)
	clang++ -o fib -Wall -g $?

debug: fib
	lldb fib
