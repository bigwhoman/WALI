#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
  int fd = open("test", O_CREAT | O_RDWR, 0644);
  ftruncate(fd, 4096);

  char *ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  ptr[0] = 'H';
  ptr[1] = 'i';
  ptr[2] = '\0';

  printf("Wrote: %s\n", ptr);

  munmap(ptr, 4096);
  close(fd);
  unlink("test");

  return 0;
}
