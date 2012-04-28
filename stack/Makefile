#============================================================================
#  stack class makefile
#===========================================================================

CPP          = g++
CPP_FLAGS    = -g -Wall -W -Wunused -Wuninitialized -Wshadow 
INCLUDE_OPT  = -iquote . -iquote ../string
TEST_1 =test_stack_int test_stack_double test_stack_string
TEST_2 =test_stack_float 
TEST_3 =
POSTF = post_fix
ASSEM = assem_bler
 #=====================================================================================
#-------------------------------------------------------------------------------
STRING_DIR = ../string/

#===========================================================================
msg:
	@echo 'Targets for compiling test programs:'
	@echo '   tests'
	@echo '   clean'
	@echo ' postfix'
	@echo ' assembler'
	
#===========================================================================
# Compile string.o
string.o:	${STRING_DIR}string.h  ${STRING_DIR}string.cpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c ${STRING_DIR}string.cpp

#===========================================================================
# Compile test programs
#----------------------------------------------------------------------------
test_%: string.o test_%.o
	${CPP} string.o test_$*.o -o test_$*

test_%.o: ${STRING_DIR}string.h stack.h test_%.cpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c test_$*.cpp
	
#=============================================================================
#make the conversions
#=============================================================================

postfixcon.o: ${STRING_DIR}string.h stack.h postfixcon.h
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c postfixcon.cpp


#===========================================================================
# make assembler
#===========================================================================
assem_bler: string.o assembler.o postfixcon.o
	${CPP} string.o assembler.o postfixcon.o -o assem_bler
	
assembler.o: ${STRING_DIR}string.h stack.h assembler.cpp postfixcon.h
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c assembler.cpp

#===========================================================================
# make postfix
# =========================================================================
post_fix: string.o postfix.o postfixcon.o
	${CPP} string.o postfix.o postfixcon.o -o post_fix
	
	
	
postfix.o: ${STRING_DIR}string.h stack.h postfix.cpp postfixcon.h
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c postfix.cpp

#===========================================================================
# Run test programs 

assembler: ${TEST_1} ${TEST_2} ${TEST_3} ${POSTF} ${ASSEM}
	./test_stack_double
	./test_stack_float
	./test_stack_int
	./test_stack_string
	./post_fix data3-1.txt result.txt
	./post_fix data3-1.txt
	./assem_bler data3-1.txt result2.txt
	./assem_bler data3-1.txt

postfix: ${TEST_1} ${TEST_2} ${TEST_3} ${POSTF}
	./test_stack_double
	./test_stack_int
	./test_stack_string
	./test_stack_float
	./post_fix data1.txt result.txt
	./post_fix data1.txt 

tests: ${TEST_1} ${TEST_2} ${TEST_3} ${POSTF} 
	./test_stack_int
	./test_stack_double
	./test_stack_string
	./test_stack_float
	./post_fix data1.txt result.txt

#===========================================================================
# Run memory tests

memtests: ${TEST_1} ${TEST_2} ${TEST_3} ${POSTF} ${ASSEM}
	valgrind ./test_stack_int 
	valgrind ./test_stack_double
	valgrind ./test_stack_string
	valgrind ./test_stack_float
	valgrind ./post_fix data3-1.txt result.txt
	valgrind ./assem_bler data3-1.txt result2.txt

#===========================================================================
.PRECIOUS: test_%.o string.o

#============================================================================
clean:
	rm -f *.o a.out
	rm -f test_stack_double
	rm -f test_stack_int
	rm -f test_stack_string test_stack_float
	rm -f post_fix
	rm -f assem_bler
