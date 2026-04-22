#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int id, i;
    for(i = 0; i < 4; i++) {
        id = fork();
        if (id == 0) {
            printf("Processo %i filho de %i", getpid(), getppid());
        } else {    
            printf("Processo pai %i criou %i", getpid(), id);
            exit(1);
        }
    };
    return 1;
}