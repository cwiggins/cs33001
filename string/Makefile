#==============================================================
# string

CPP     = g++
OPTIONS = -g -Wall -W -Wunused -Wuninitialized -Wshadow 

EXE1 = test_default_ctor test_c_str_ctor test_relational_operators test_copy_ctor
EXE2 = test_length test_subscript test_concatenation test_substr test_findstr test_input test_reallocate test_split
EXE3 = test_swap test_assign
#=============================================================
msg:
	@echo 'Targets are:'
	@echo '  string'
	@echo '  leaktest'
	@echo '  test_XXX  (where test_XXX is a test program)'
	@echo '  clean'
	@echo '  splits'
	@echo '  logview'
#==============================================================
# Run all tests
string: $(EXE1) $(EXE2) $(EXE3)
	./test_default_ctor
	./test_c_str_ctor
	./test_length 
	./test_subscript
	./test_concatenation
	./test_substr
	./test_findstr
	./test_relational_operators
	./test_input
	./test_reallocate
	./test_split
	./test_copy_ctor
	./test_swap
	./test_assign
#==============================================================
# string type
string.o: string.h string.cpp
	$(CPP) -c $(OPTIONS) string.cpp

#===========================================================================
# Compile test programs
#----------------------------------------------------------------------------
test_%: string.o test_%.o
	$(CPP) string.o test_$*.o -o test_$*

test_%.o: string.h test_%.cpp
	$(CPP) $(OPTIONS) -c test_$*.cpp
	
#================================================================
#run all tests
splits: $(EXE1) $(EXE2) $(EXE3)
	./test_default_ctor
	./test_c_str_ctor
	./test_length
	./test_subscript
	./test_concatenation
	./test_substr
	./test_findstr
	./test_relational_operators
	./test_input
	./test_reallocate
	./test_split
	./test_copy_ctor
	./test_swap
	./test_assign
	
#====================================================
#string type
string.o: string.h string.cpp
	$(CPP) -c $(OPTIONS) string.cpp
	
#++++++++++++++++++++++++++++++++++++++++++++++++++++++
#compile test programs
#-----------------------------------------------------
test_%: string.o test_%.o
	$(CPP) string.o test_$*.o -o test_$*
	
test_%.o: string.h test_%.cpp
	$(CPP) $(OPTIONS) -c test_$*.cpp

#===========================================================================
leaktest: $(EXE1) $(EXE2) $(EXE3)
	valgrind ./test_default_ctor
	valgrind ./test_c_str_ctor
	valgrind ./test_length
	valgrind ./test_subscript
	valgrind ./test_concatenation
	valgrind ./test_substr
	valgrind ./test_findstr
	valgrind ./test_relational_operators
	valgrind ./test_input
	valgrind ./test_reallocate
	valgrind ./test_split
	valgrind ./test_copy_ctor.cpp
	valgrind ./test_swap
	valgrind ./test_assign
	
#===========================================================================
.PRECIOUS: test_%.o string.o

#==============================================================
# clean should remove all .o files and all executables
clean:
	rm -f *.o
	rm -f test_default_ctor test_c_str_ctor test_substr test_findstr
	rm -f test_length test_subscript test_concatenation test_input
	rm -f test_relational_operators test_reallocate test_split
	rm -f test_copy_ctor test_swap test_assign
	
