#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <stdlib.h> 
#define SHMSZ 27   
void main() {     
	char c;     
	int shmid;     
	key_t key;     
	char *shm, *s;      
	key = 5678;         
	if ((shmid = shmget(key, SHMSZ , IPC_CREAT | 0666)) < 0) 		{
	         printf("shmget error");               
		exit(1);   
	 }
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) 		{ 
	        printf("shmat error");         
		exit(1);     
	}  
      	for (s = shm; *s != '\0'; s++){         
		putchar(*s);     
		putchar(' ');      
	} 
	*shm = '*';
	exit(0); 
}
