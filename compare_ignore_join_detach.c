#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 

void print_thread_id(const char* tag, pthread_t* ptr_thread_id) {
	printf("%s,\t", tag);
    size_t i;
    for (i = sizeof(i); i; --i)
    	printf("%02x", *(((unsigned char*) ptr_thread_id) + i - 1));
	printf(",\tsize\t%lu\n", sizeof(*ptr_thread_id));
}

void* ignore_routine(void* params) {
	printf("ignored routine.\n");
	pthread_exit(NULL);
}

void* join_routine(void* params) {
	printf("joined routine. Will sleep for 3 seconds.\n");
	sleep(3);	
	int ret = 42; // answer to everything
	pthread_exit((void*)&ret);
}

void* detach_routine(void* params) {
	printf("detached routine.\n");
	pthread_exit(NULL);
}

int main() {
	pthread_t to_ignore, to_join, to_detach;	
	int th1 = pthread_create(&to_ignore, NULL, ignore_routine, NULL);
	int th2 = pthread_create(&to_join, NULL, join_routine, NULL);
	int th3 = pthread_create(&to_detach, NULL, detach_routine, NULL);
	int ret_join = 0;
	int* ptr_ret_join = &ret_join;
	pthread_join(to_join, (void**)&ptr_ret_join);
	pthread_detach(to_detach);
	printf("thread handles are\n");
	const char* tag_ignore = "to_ignore";	
	const char* tag_join = "to_join";
	const char* tag_detach = "to_detach";
	print_thread_id(tag_ignore, &to_ignore);	
	print_thread_id(tag_join, &to_join);
	print_thread_id(tag_detach, &to_detach);
	return 0;
}
