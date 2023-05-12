#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int sig) {
    switch(sig) {
        case SIGABRT:
            printf("Received SIGABRT\n");
            break;
        case SIGFPE:
            printf("Received SIGFPE\n");
            break;
        case SIGILL:
            printf("Received SIGILL\n");
            break;
        case SIGINT:
            printf("Received SIGINT\n");
            break;
        case SIGSEGV:
            printf("Received SIGSEGV\n");
            break;
        case SIGTERM:
            printf("Received SIGTERM\n");
            break;
        default:
            printf("Received unknown signal\n");
            break;
    }
}

int main() {
    signal(SIGABRT, sig_handler);
    signal(SIGFPE, sig_handler);
    signal(SIGILL, sig_handler);
    signal(SIGINT, sig_handler);
    signal(SIGSEGV, sig_handler);
    signal(SIGTERM, sig_handler);

    int choice;

    printf("Enter 1 to raise SIGABRT\n");
    printf("Enter 2 to raise SIGFPE\n");
    printf("Enter 3 to raise SIGILL\n");
    printf("Enter 4 to raise SIGINT\n");
    printf("Enter 5 to raise SIGSEGV\n");
    printf("Enter 6 to raise SIGTERM\n");
    printf("Enter 0 to exit\n");

    while (1) {

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                raise(SIGABRT);
                break;
            case 2:
                raise(SIGFPE);
                break;
            case 3:
                raise(SIGILL);
                break;
            case 4:
                raise(SIGINT);
                break;
            case 5:
                raise(SIGSEGV);
                break;
            case 6:
                raise(SIGTERM);
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
