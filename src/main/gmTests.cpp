#include "../GameManager.h"

#ifdef __WIN32__
#include <windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow) {
  printf("OS: Windows\n");
  int w_argc = 0;
  LPWSTR* w_argv = CommandLineToArgvW(GetCommandLineW(), &w_argc);
  if (w_argv) {
    char** my_argv = new char*[w_argc];
    int my_argc = 0;

    for (int i = 0; i < w_argc; ++i) {
      int w_len = lstrlenW(w_argv[i]);
      int len = WideCharToMultiByte(CP_ACP, 0, w_argv[i], w_len, NULL, 0, NULL, NULL);
      my_argv[my_argc] = new char[len+1];
      WideCharToMultiByte(CP_ACP, 0, w_argv[i], w_len, my_argv[my_argc], len+1, NULL, NULL);
      ++my_argc;
    }

    main(my_argc, my_argv);

    for (int i = 0; i < my_argc; ++i) {
      delete[] my_argv[i];
    }
    delete[] my_argv;

    LocalFree(w_argv);
  }
  return 0;
}
#endif

int main (int argc, char *argv [])
{
  GameManager gm;
  if(gm.init(0 , 10)==0)
    gm.run();
  else
    printf("Could not open the game\n");
  return 0;
}
