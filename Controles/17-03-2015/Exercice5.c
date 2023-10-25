#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Usage: %s file1.c file2.c ...\n", argv[0]);
    return 1;
  }

  int num_files = argc - 1;
  pid_t child_pids[num_files];

  // Compile each source file using child processes
  for (int i = 1; i <= num_files; i++)
  {
    pid_t pid = fork();

    if (pid < 0)
    {
      perror("Fork failed");
      exit(1);
    }
    else if (pid == 0)
    { // Child process
      char *source_file = argv[i];
      char object_file[256];

      // Create the object file name (e.g., source.c -> source.o)
      snprintf(object_file, sizeof(object_file), "%s.o", source_file);

      execlp("gcc", "gcc", "-c", source_file, "-o", object_file, (char *)NULL);
      perror("Exec failed");
      exit(1);
    }
    else // Parent process
      child_pids[i - 1] = pid;
  }

  // Wait for all child processes to complete
  int error = 0;
  for (int i = 0; i < num_files; i++)
  {
    int status;
    if (waitpid(child_pids[i], &status, 0) == -1)
    {
      perror("Wait failed");
      exit(1);
    }

    if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
    {
      printf("Compilation error in child process %d\n", i + 1);
      error = 1;
    }
  }

  if (!error)
  {
    // If all child processes completed successfully, link the object files
    char *output_executable = "output_executable"; // Change this to your desired output executable name
    char *object_files[num_files + 1];

    for (int i = 0; i < num_files; i++)
    {
      char object_file[256];
      snprintf(object_file, sizeof(object_file), "%s.o", argv[i + 1]);
      object_files[i] = object_file;
    }

    object_files[num_files] = NULL;

    if (execvp("gcc", (char *[]){"gcc", "-o", output_executable, *object_files, NULL}) == -1)
    {
      perror("Linking failed");
      exit(1);
    }
  }

  return 0;
}