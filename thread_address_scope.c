#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 

int var = 5;
int* p_var = (&var);

void* join_routine(void* params) {
	printf("joined routine.\n\taddress of var is %p.\n\taddress of p_var is %p.\n\twill sleep for 3 seconds.\n", (void*)(&var), (void*)(&p_var));
	sleep(3);	
	int ret = 42; // answer to everything
	pthread_exit((void*)&ret);
}

void* detach_routine(void* params) {
	printf("detached routine.\n\taddress of var is %p.\n\taddress of p_var is %p.\n", (void*)(&var), (void*)(&p_var));
	pthread_exit(NULL);
}

int main() {
	pthread_t to_ignore, to_join, to_detach;	
	int th1 = pthread_create(&to_join, NULL, join_routine, NULL);
	int th2 = pthread_create(&to_detach, NULL, detach_routine, NULL);
	int ret_join = 0;
	int* ptr_ret_join = &ret_join;
	pthread_join(to_join, (void**)&ptr_ret_join);
	pthread_detach(to_detach);
	return 0;
}
