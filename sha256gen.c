#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void print_hash(unsigned char hash[SHA256_DIGEST_LENGTH]) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        printf("%02x", hash[i]);
    printf("\n");
}

void sha256_string(const char *input) {
    if (input == NULL || strlen(input) == 0) {
        fprintf(stderr, "Error: Input string is empty.\n");
        return;
    }
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, strlen(input));
    SHA256_Final(hash, &sha256);
    printf("SHA-256 hash: ");
    print_hash(hash);
}

int sha256_file(const char *filename) {
    if (filename == NULL || strlen(filename) == 0) {
        fprintf(stderr, "Error: Filename is empty.\n");
        return 1;
    }
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    const int bufSize = 32768;
    unsigned char *buffer = malloc(bufSize);
    if (!buffer) {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        fclose(file);
        return 1;
    }
    int bytesRead = 0;
    while ((bytesRead = fread(buffer, 1, bufSize, file)) > 0) {
        SHA256_Update(&sha256, buffer, bytesRead);
    }
    if (ferror(file)) {
        fprintf(stderr, "Error reading file.\n");
        free(buffer);
        fclose(file);
        return 1;
    }
    SHA256_Final(hash, &sha256);
    printf("SHA-256 hash of file '%s': ", filename);
    print_hash(hash);
    fclose(file);
    free(buffer);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage:\n  %s <string_to_hash>\n  %s -f <filename>\n", argv[0], argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "-f") == 0) {
        if (argc != 3) {
            fprintf(stderr, "Error: Please provide a filename after -f.\n");
            return 1;
        }
        return sha256_file(argv[2]);
    } else {
        sha256_string(argv[1]);
    }
    return 0;
}
