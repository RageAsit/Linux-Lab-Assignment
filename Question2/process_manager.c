#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child Process
        printf("Child Process Started. PID = %d\n", getpid());

        // Simulate an unresponsive child
        sleep(10);

        printf("Child Process Finished.\n");
        exit(0);
    } else {
        // Parent Process
        printf("Parent Process. PID = %d\n", getpid());
        printf("Created Child with PID = %d\n", pid);

        sleep(3);

        printf("Checking child process...\n");
        printf("Child is taking too long. Sending SIGTERM...\n");

        kill(pid, SIGTERM);

        waitpid(pid, NULL, 0);

        printf("Child process terminated successfully.\n");
        printf("Zombie process prevented using waitpid().\n");
    }

    return 0;
}