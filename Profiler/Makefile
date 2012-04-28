# Make file for Profiler

###############################################################
# Variables
CPP      = g++
#CPP_OPTS = -g -Wall
CPP_OPTS = -g -Wall -W -Wunused -Wuninitialized -Wshadow 

###############################################################
# The first rule is run of only make is typed
msg:
	@echo 'Targets are:'
	@echo '  profiler:'
	@echo '  sort:'
	@echo '  gprof:'
	@echo '  clean:'

###############################################################
profiler : main.o ASTree.o 
	$(CPP) $(CPP_OPTS) -o profiler main.o ASTree.o 
  
main.o : main.cpp ASTree.hpp
	$(CPP) $(CPP_OPTS) -c main.cpp

ASTree.o   : ASTree.hpp ASTree.cpp
	$(CPP) $(CPP_OPTS) -c ASTree.cpp

#==============================================================
# sort
sort: sort.o sort_lib.o
	$(CPP) $(CPP_OPTS) -o sort sort.o sort_lib.o

sort.o: sort_lib.h sort.cpp
	$(CPP) $(CPP_OPTS) -c sort.cpp

sort_lib.o: sort_lib.h sort_lib.cpp
	$(CPP) $(CPP_OPTS) -c sort_lib.cpp

#==============================================================
# p-sort
# p-sort.cpp.xml.cpp
# p-sort_lib.cpp.xml.cpp
p-sort: profile.o p-sort.cpp.xml.o p-sort_lib.cpp.xml.o
	$(CPP) $(CPP_OPTS) -o p-sort profile.o p-sort.cpp.xml.o p-sort_lib.cpp.xml.o

p-sort.cpp.xml.o: profile.hpp sort_lib.h p-sort.cpp.xml.cpp
	$(CPP) $(CPP_OPTS) -c p-sort.cpp.xml.cpp

p-sort_lib.cpp.xml.o: profile.hpp sort_lib.h p-sort_lib.cpp.xml.cpp
	$(CPP) $(CPP_OPTS) -c p-sort_lib.cpp.xml.cpp

profile.o: profile.hpp profile.cpp
	$(CPP) $(CPP_OPTS) -c profile.cpp

#==============================================================
# Profiling version of sort
gprof: CPP_OPTS   = -g -Wall -pg
gprof: clean sort
	@echo -n ''

###############################################################
#This will clean up everything via "make clean"
clean:
	rm -f profiler
	rm -f sort
	rm -f *.o
	rm -f p-*
	rm -f gmon.out

