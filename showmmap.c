#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char *argv[])
{
    char *addr;
    int fd;
    struct stat sb;
    off_t offset;
    ssize_t length;
    int i,j;

    if (argc < 2 || argc > 4) {
        fprintf(stderr, "%s file [offset] [length]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        handle_error("open");

    if (fstat(fd, &sb) == -1)           /* To obtain file size */
        handle_error("fstat");

    offset = 0;
    if (argc > 2) {
        offset = strtol(argv[2],NULL,0);
        if (offset >= sb.st_size) {
            fprintf(stderr, "offset is past end of file\n");
            exit(EXIT_FAILURE);
        }
    }

    length = sb.st_size - offset;
    if (argc == 4) {
        length = strtol(argv[3],NULL,0);
        if ((offset + length) > sb.st_size)
            length = sb.st_size - offset;
        /* Can't display bytes past end of file */
    }

    addr = (char*)mmap(NULL, length + offset, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED)
        handle_error("mmap");

    for (i=0; i<length; i=i+16) {
        printf("0x%08lx:",offset+i);
        for (j=0; j<16; ++j) {
            printf("%s",((j%4)==0)?" ":"");
            if ((i+j)<length) {
                printf("%02x",(*(addr+offset+i+j)&0xff));
            } else {
                printf("  ");
            }
        }
        printf(" ");
        for (j=0; j<16; ++j) {
            int c=(*(addr+offset+i+j)&0xff);
            if ((i+j)<length) {
                printf("%c",((c<32)||(c>126))?'.':c);
            }
        }
        printf("\n");
    }

    exit(EXIT_SUCCESS);
}

