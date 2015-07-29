CXX = gcc
CFLAGS = -g
CLEANFILES = compare_ignore_join_detach compare_join_detach investigate_thread_attributes

all: compare_ignore_join_detach compare_join_detach investigate_thread_attributes 

compare_ignore_join_detach: compare_ignore_join_detach.c
	$(CXX) -o compare_ignore_join_detach $(CFLAGS) -pthread compare_ignore_join_detach.c

compare_join_detach: compare_join_detach.c
	$(CXX) -o compare_join_detach $(CFLAGS) -pthread compare_join_detach.c

investigate_thread_attributes: investigate_thread_attributes.c
	$(CXX) -o investigate_thread_attributes $(CFLAGS) -pthread investigate_thread_attributes.c

clean :
	rm -f $(CLEANFILES)
