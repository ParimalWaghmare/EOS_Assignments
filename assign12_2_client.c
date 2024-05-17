#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int num1, num2, result;
    int clireq_fd, clires_fd;

    // Prompt the user to enter two numbers
    printf("Enter 2 numbers: ");
    scanf("%d %d", &num1, &num2);

    // Open the FIFO for writing the request
    clireq_fd = open("/home/parimal/Desktop/Practice/EOS_Practice/fifo1", O_WRONLY);
    if (clireq_fd < 0) {
        perror("open() failed");
        _exit(1);
    }

    // Write the two numbers to the FIFO
    write(clireq_fd, &num1, sizeof(num1));
    write(clireq_fd, &num2, sizeof(num2));
    close(clireq_fd);

    // Open the FIFO for reading the response
    clires_fd = open("/home/parimal/Desktop/Practice/EOS_Practice/fifo2", O_RDONLY);
    if (clires_fd < 0) {
        perror("open() failed");
        _exit(1);
    }

    // Read the result from the FIFO
    read(clires_fd, &result, sizeof(result));
    close(clires_fd);

    // Print the result
    printf("The sum is %d\n", result);

    return 0;
}

