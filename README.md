# Compiling The Code

There are multiple methods for compiling and running this code:

- Opening the project in [Code Blocks](https://www.codeblocks.org/downloads/binaries/)

  1. Open [Code Blocks](https://www.codeblocks.org/downloads/binaries/).
  2. Click on `File` in the top menu and select `Open...`.
  3. Navigate to the folder where you have saved the project. The folder name is `Homework`.
  4. Select the file `Homework.cbp` and click `Open`.
  5. Once the project is loaded, select on top menu `Build and Run`.

- Compiling the code with the [MinGW compiler](https://www.mingw-w64.org/downloads/) (or any other), which must be installed locally; After installation, set a System Variable Path to MinGW's `bin` folder. To see if the installation worked, open Command Prompt and type `gcc --version`. If it worked, go to the root directory `Homework` and run `gcc -o main.c book_division.c`. 

- In any compatible IDE, create a `blank project` and import the following files:`main.c`, `book_division.c` and `book_division.h`.

