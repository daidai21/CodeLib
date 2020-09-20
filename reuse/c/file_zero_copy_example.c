/* ****************************************************************************
 * File Name   : file_zero_copy_example.c
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 三  9/16 20:05:44 2020
 *************************************************************************** */

#include <stdio.h>     // For FILE, fopen(), feof(), fread(), fwrite(), fclose()
#include <string.h>    // For strcmp()
#include <sys/stat.h>  // For struct stat, fstat(),
#include <sys/types.h> // For
#include <fcntl.h>     // For open(), O_RDONLY, O_CREAT, O_WRONLY
#include <stdlib.h>    // For exit(),
#include <unistd.h>    // For close()

#if __APPLE__
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#elif
#include <sys/sendfile.h> // For sendfile(),
#endif

void copy(const char *src_path, const char *dst_path);
void zero_copy(const char *src_path, const char *dst_path);

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    printf("usage: %s <source> <destination> <mode> \n", argv[0]);
    return 1;
  }

  if (strcmp(argv[3], "copy"))
  {
    copy(argv[1], argv[2]);
  }
  else if (strcmp(argv[3], "zero_copy"))
  {
    zero_copy(argv[1], argv[2]);
  }

  return 0;
}

void copy(const char *src_path, const char *dst_path)
{
  FILE *src;
  FILE *dst;
  int buf_size = 8 * 1024;
  char buf[buf_size];
  size_t length;

  src = fopen(src_path, "rb");
  dst = fopen(dst_path, "wb");

  while (!feof(src))
  {
    length = fread(buf, 1, buf_size, src);
    fwrite(buf, 1, length, dst);
  }

  fclose(src);
  fclose(dst);
}

void zero_copy(const char *src_path, const char *dst_path)
{
  int src;
  int dst;
  struct stat stat_buf;
  off_t offset = 0;
  int rc;

  src = open(src_path, O_RDONLY);
  fstat(src, &stat_buf);
  dst = open(dst_path, O_WRONLY | O_CREAT, stat_buf.st_mode);
#if __APPLE__
  rc = sendfile(src, dst, offset, &stat_buf.st_size, NULL, 0); // BUG
  printf("MacOX\n");
#else
  rc = sendfile(dst, src, &offset, stat_buf.st_size);
  printf("Linux\n");
#endif
  printf("rc %d\n", rc);
  printf("stat_buf.st_size %lld\n", stat_buf.st_size);
  if (rc != stat_buf.st_size)
  {
    fprintf(stderr, "incomplete transfer from sendfile: %d of %d bytes\n", rc, (int)stat_buf.st_size);
    exit(1);
  }

  close(dst);
  close(src);
}
