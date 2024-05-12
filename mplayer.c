#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>

void play_mp3(char *filename) {
    pid_t pid = fork();
    if (pid == 0) {
        execlp("mpg123", "mpg123", "-q", filename, NULL);
        perror("Failed to execute mpg123");
        exit(1);
    } else if (pid < 0) {
        perror("Fork failed");
    } else {
        waitpid(pid, NULL, 0);
    }
}

void print_logo() {
    printf("\n");
    printf("  ____  _            ____  _     _            _      \n");
    printf(" / ___|| |_ _ __ ___/ ___|| |__ (_)_ __   ___| | __  \n");
    printf(" \\___ \\| __| '__/ _ \\___ \\| '_ \\| | '_ \\ / __| |/ /  \n");
    printf("  ___) | |_| | | (_) |__) | | | | | | | | (__|   <   \n");
    printf(" |____/ \\__|_|  \\___/____/|_| |_|_|_| |_|\\___|_|\\_\\  \n");
    printf("                                                     \n");
    printf("-----------------------------------------------------\n");
}

void display_menu() {
    printf("\n");
    printf("Menu:\n");
    printf("1. Skip this song\n");
    printf("2. Quit\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    print_logo();

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(argv[1])) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strstr(ent->d_name, ".mp3") != NULL) {
                char path[256];
                snprintf(path, sizeof(path), "%s/%s", argv[1], ent->d_name);
                printf("Playing: %s\n", ent->d_name);
                play_mp3(path);

                // Display menu
                int choice;
                do {
                    display_menu();
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    switch (choice) {
                        case 1:
                            printf("Skipping this song...\n");
                            break;
                        case 2:
                            printf("Quitting the player...\n");
                            closedir(dir);
                            return 0;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (choice != 1 && choice != 2);
            }
        }
        closedir(dir);
    } else {
        perror("Failed to open directory");
        return 1;
    }

    printf("No more songs to play. Exiting...\n");

    return 0;
}

