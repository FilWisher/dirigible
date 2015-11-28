#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int
main (int argc, char **argv)
{
  key_t shm_key = ftok("./makefile", 'b');
  
  int shmid = shmget(shm_key, 1024, 0644 | IPC_CREAT);
  char *data = (char *)shmat(shmid, (void *)0, 0);
  if (data == (char *)-1)
    perror("shmat failed");

  key_t sem_key = ftok("./makefile", 'E');
  int semid = semget(sem_key, 10, 0666 | IPC_CREAT);

 
  sprintf(data, "%s\n", argv[1]);
  
  getchar();
  
  
  if (shmdt(data) < 0)
    perror("shmdt failed");
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}
