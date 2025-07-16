# SHA256Gen-C

Simple SHA-256 hash generator written in C using OpenSSL.

## Description

This program generates SHA-256 hashes for either input strings or files. It uses the OpenSSL library to perform the hashing operations and supports command-line arguments for ease of use.

## Features

- Generate SHA-256 hashes for text strings.
- Generate SHA-256 hashes for files.
- Simple command-line interface.
- Error handling for invalid inputs and file operations.

## Requirements

- C compiler (e.g., `gcc`)
- OpenSSL library (`libcrypto`)

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/3sus/sha256gen-c.git
   cd sha256gen-c
   ```

2. Compile the program with OpenSSL:
   ```bash
   gcc -o sha256gen sha256gen.c -lcrypto
   ```

   Ensure the OpenSSL development libraries are installed. On Debian-based systems, you can install them with:
   ```bash
   sudo apt-get install libssl-dev
   ```

   On Red Hat-based systems:
   ```bash
   sudo dnf install openssl-devel
   ```

## Usage

Run the program from the command line with one of the following formats:

- **Hash a string**:
   ```bash
   ./sha256gen "your_string_here"
   ```
   Example:
   ```bash
   ./sha256gen "Hello, World!"
   ```
   Output:
   ```
   SHA-256 hash: a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e
   ```

- **Hash a file**:
   ```bash
   ./sha256gen -f filename
   ```
   Example:
   ```bash
   ./sha256gen -f example.txt
   ```
   Output:
   ```
   SHA-256 hash of file 'example.txt': <hash_value>
   ```

## Error Handling

- If no arguments are provided, the program displays usage instructions.
- If an empty string or filename is provided, an error message is shown.
- File operations include checks for file existence and read errors.
- Memory allocation failures are handled gracefully.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please submit a pull request or open an issue on the [GitHub repository](https://github.com/3sus/sha256gen-c).

## Author

- 3sus (c) 2025