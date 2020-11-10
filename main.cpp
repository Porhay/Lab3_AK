#include <iostream>
#include <stdio.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
  printf("Ak labwork number three\n");
  
  bool flag[] = {0, 0, 0};
 
  const char* short_opts = "l::hv::"; // short
  const struct option long_opts[]  = { // long
    {"list", optional_argument, NULL, 'l'},
    {"help", no_argument, NULL, 'h'},
    {"value", optional_argument, NULL, 'v'},
    {NULL, 0, NULL, 0}  
  };

  int opt_main = 0; 
  int a = 1;
  int opt_idx = -1;
  while ((opt_main = getopt_long(argc,argv, short_opts, long_opts, &opt_idx)) != -1){
    switch (opt_main) {
      case 'l':
        if (!flag[0]) {
          printf("Argument #%d: List", a++);
          if (optarg != NULL) printf(" = %s", optarg);
          printf("\n");
          flag[0] = 1;
        }
        break;
      case 'h': 
        if (!flag[1]) {
          printf("Argument #%d: Help\n", a++); 
          flag[2] = 1;
        }
        break;
      case 'v':
        if (!flag[2]) {
          printf("Argument #%d: Value = %s\n", a++, optarg);
          flag[3] = 1;
        }
        break;  
      case '?':
        printf("Undefined argument\n");
    }
    opt_idx = -1;
  }
  return 0;  
}

