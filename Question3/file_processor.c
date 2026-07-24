#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char buffer[100];

    // Create and open the file
    fd = open("employees.txt", O_CREAT | O_RDWR, 0644);

    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // Write employee records
    write(fd, "101 Alice Manager\n", 18);
    write(fd, "102 Bob Engineer\n", 17);
    write(fd, "103 Charlie HR\n", 15);

    // Update Bob's record using lseek()
    lseek(fd, 22, SEEK_SET);
    write(fd, "Senior Engineer", 15);

    // Read the file from the beginning
    lseek(fd, 0, SEEK_SET);

    int bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    buffer[bytesRead] = '\0';

    printf("Employee Records:\n");
    printf("%s\n", buffer);

    close(fd);

    return 0;
}