CXX = gcc

all: compare_ignore_join_detach compare_join_detach 

compare_ignore_join_detach: compare_ignore_join_detach.c
	$(CXX) -o compare_ignore_join_detach -pthread compare_ignore_join_detach.c

compare_join_detach: compare_join_detach.c
	$(CXX) -o compare_join_detach -pthread compare_join_detach.c
