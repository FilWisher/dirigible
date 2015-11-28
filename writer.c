#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int
main (int argc, char **argv)
{
  //char *shared_memory = (char *) shmat(argv[1], NULL, SHM_RND | I_SWUSR | I_SRUSR);

  key_t shm_key = ftok("./makefile", 'b');
  int shmid = shmget(shm_key, 1024, 0644);
  char *data = (char *)shmat(shmid, (void *)0, 0);
  if (data == (char *)-1)
    perror("shmat failed");


  printf(data);
 
 
  if (shmdt(data) < 0)
    perror("shmdt failed");
  shmctl(shmid, IPC_RMID, NULL);
  
  return 0;
}
