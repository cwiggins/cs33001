#==============================================================
# string

CPP     = g++
OPTIONS = -pg -Wall -W -Wunused -Wuninitialized -Wshadow 
EXE1 = test_default_ctor test_c_str_ctor test_relational_operators test_copy_ctor test_findchar
EXE2 = test_length test_subscript test_concatenation test_substr test_findstr test_input test_reallocate test_split
EXE3 = test_swap test_assign test_getline test_atoi 
LOGV = log_view
#=============================================================
msg:
	@echo 'Targets are:'
	@echo '  logview'
	@echo '  string'
	@echo '  leaktest'
	@echo '  test_XXX  (where test_XXX is a test program)'
	@echo '  clean'
	@echo '  splits'
	@echo '  tests'
#==============================================================
# Run all tests
logview:$(EXE1) $(EXE2) $(EXE3) $(LOGV)
	./test_default_ctor
	./test_c_str_ctor 
	./test_length
	./test_subscript
	./test_concatenation
	./test_substr
	./test_findstr
	./test_findchar
	./test_relational_operators
	./test_input 
	./test_reallocate
	./test_copy_ctor
	./test_swap
	./test_assign
	./test_atoi
	./test_getline
	./test_split
	./log_view all log_3_medium.txt
	
splits: $(EXE1) $(EXE2) $(EXE3)
	./test_default_ctor
	./test_c_str_ctor
	./test_length
	./test_subscript
	./test_concatenation
	./test_substr
	./test_findstr
	./test_findchar 
	./test_relational_operators
	./test_input
	./test_reallocate
	./test_copy_ctor
	./test_swap
	./test_assign
	./test_getline
	./test_atoi 
	./test_split
	
tests:$(EXE1) $(EXE2) $(EXE3)
	./test_default_ctor
	./test_c_str_ctor
	./test_length
	./test_subscript
	./test_concatenation
	./test_substr
	./test_findstr
	./test_findchar
	./test_relational_operators
	./test_input 
	./test_reallocate
	./test_copy_ctor
	./test_swap
	./test_assign 
	./test_getline
	./test_atoi 
	./test_split
	
string: $(EXE1) $(EXE2) $(EXE3)
	./test_default_ctor
	./test_c_str_ctor
	./test_length 
	./test_subscript
	./test_concatenation
	./test_substr
	./test_findstr 
	./test_findchar
	./test_relational_operators
	./test_input
	./test_reallocate
	./test_split
	./test_copy_ctor
	./test_swap
	./test_assign
	./test_getline
	./test_atoi
#==============================================================
# string type
string.o: string.h string.cpp
	$(CPP) -c $(OPTIONS) string.cpp
	
#===============================================================
#logentry type
logentry.o: string.h logentry.h logentry.cpp
	$(CPP) -c $(OPTIONS) logentry.cpp
	
#===============================================================
#logview program
log_view: logview.o logentry.o string.o
	$(CPP) string.o logentry.o logview.o -o log_view
	
logview.o: logview.cpp logentry.h string.h
	$(CPP) -c $(OPTIONS) logview.cpp

#===========================================================================
# Compile test programs
#----------------------------------------------------------------------------
test_%: string.o test_%.o
	$(CPP) string.o test_$*.o -o test_$*

test_%.o: string.h test_%.cpp
	$(CPP) $(OPTIONS) -c test_$*.cpp

#===========================================================================
leaktest: $(EXE1) $(EXE2) $(EXE3) $(LOGV)
	valgrind ./test_default_ctor
	valgrind ./test_c_str_ctor
	valgrind ./test_length
	valgrind ./test_subscript
	valgrind ./test_concatenation
	valgrind ./test_substr
	valgrind ./test_findstr
	valgrind ./test_findchar
	valgrind ./test_relational_operators
	valgrind ./test_input
	valgrind ./test_reallocate
	valgrind ./test_split
	valgrind ./test_copy_ctor
	valgrind ./test_swap
	valgrind ./test_assign
	valgrind ./test_getline
	valgrind ./test_atoi
	valgrind ./log_view all log_3_medium.txt
	valgrind ./log_view host log_3_medium.txt
	valgrind ./log_view bytes log_3_medium.txt
	
#===========================================================================
.PRECIOUS: test_%.o string.o

#==============================================================
# clean should remove all .o files and all executables
clean:
	rm -f *.o
	rm -f test_default_ctor test_c_str_ctor test_substr test_findstr
	rm -f test_length test_subscript test_concatenation test_input
	rm -f test_relational_operators test_reallocate test_split
	rm -f test_copy_ctor test_swap test_assign test_findchar
	rm -f test_getline test_atoi
	rm -f log_view
	
