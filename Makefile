CXX = gcc
CFLAGS = -g
CLEANFILES = compare_ignore_join_detach compare_join_detach investigate_thread_attributes thread_address_scope

all: compare_ignore_join_detach compare_join_detach investigate_thread_attributes thread_address_scope 

compare_ignore_join_detach: compare_ignore_join_detach.c
	$(CXX) -o compare_ignore_join_detach $(CFLAGS) -pthread compare_ignore_join_detach.c

compare_join_detach: compare_join_detach.c
	$(CXX) -o compare_join_detach $(CFLAGS) -pthread compare_join_detach.c

investigate_thread_attributes: investigate_thread_attributes.c
	$(CXX) -o investigate_thread_attributes $(CFLAGS) -pthread investigate_thread_attributes.c

thread_address_scope: thread_address_scope.c
	$(CXX) -o thread_address_scope $(CFLAGS) -pthread thread_address_scope.c

clean :
	rm -f $(CLEANFILES)
