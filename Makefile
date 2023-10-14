compile: test.cpp design.h
	@g++ test.cpp -std=c++2a -o test.out
	@./test.out

test1:
    ifneq ($(wildcard test.out),)
		@./test.out
    else
		g++ test.cpp -std=c++2a -o test.out
		./test.out
    endif

test2: compile

clean: 
	rm *.out