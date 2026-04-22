#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    int id1, id2, id3, id4, temp;

    id1 = fork();

    if (id1 != 0) {
        id2 = fork();
        if (id2 != 0) {
            wait(NULL);
            wait(NULL);
            exit(1);
        }
        printf("Processo %i filho de %i\n", getpid(), getppid());
    } else {
        printf("Processo %i filho de %i\n", getpid(), getppid());
    }

    for (int i = 0; i < 2; i++) {
        id4 = fork();
        wait(NULL);
        if (id4 == 0) {
            printf("Processo %i filho de %i\n", getpid(), getppid());
            wait(NULL);
            exit(1);
        };
    };
}