#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler function for SIGUSR1
void handle_sigusr1(int signal) {
    printf("Received SIGUSR1 signal (%d)\n", signal);
}

int main() {
    // Set up the signal handler for SIGUSR1
    if (signal(SIGUSR1, handle_sigusr1) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    // Print the process ID so it can be used to send signals
    printf("Process ID: %d\n", getpid());

    // Pause the process to wait for signals
    while (1) {
        pause(); // Wait for a signal to arrive
    }

    return 0;
}