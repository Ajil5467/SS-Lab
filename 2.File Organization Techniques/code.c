
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
  FILE *f1, *f2, *f3, *f4, *f5;
  int len, i, pos = 1;
  char arg[20], mne[20], opnd[20], la[20], name[20], mne1[20], opnd1[20],
      pos1[10], pos2[10];
  f1 = fopen(argv[1], "r");
  f2 = fopen(argv[2], "w+");
  f3 = fopen(argv[3], "w+");
  f4 = fopen(argv[4], "w+");
  f5 = fopen(argv[5], "w+");
  fscanf(f1, "%s%s%s", la, mne, opnd);
  while (strcmp(mne, "END") != 0) {
    if (strcmp(mne, "MACRO") == 0) {
      fprintf(f2, "%s\n", la);
      fseek(f2, SEEK_SET, 0);
      fprintf(f3, "%s\t%s\n", la, opnd);
      fscanf(f1, "%s%s%s", la, mne, opnd);
      while (strcmp(mne, "MEND") != 0) {
        if (opnd[0] == '&') {
          snprintf(pos1, 20, "%d", pos);
          strcpy(pos2, "?");
          strcpy(opnd, strcat(pos2, pos1));
          pos = pos + 1;
        }
        fprintf(f3, "%s\t%s\n", mne, opnd);
        fscanf(f1, "%s%s%s", la, mne, opnd);
      }
      fprintf(f3, "%s", mne);
    } else {
      fscanf(f2, "%s", name);
      if (strcmp(mne, name) == 0) {
        len = strlen(opnd);
        for (i = 0; i < len; i++) {
          if (opnd[i] != ',')
            fprintf(f4, "%c", opnd[i]);
          else
            fprintf(f4, "\n");
        }
        fseek(f3, SEEK_SET, 0);
        fseek(f4, SEEK_SET, 0);
        fscanf(f3, "%s%s", mne1, opnd1);
        fprintf(f5, ".\t%s\t%s\n", mne1, opnd);
        fscanf(f3, "%s%s", mne1, opnd1);
        while (strcmp(mne1, "MEND") != 0) {
          if ((opnd[0] == '?')) {
            fscanf(f4, "%s", arg);
            fprintf(f5, "-\t%s\t%s\n", mne1, arg);
          } else
            fprintf(f5, "-\t%s\t%s\n", mne1, opnd1);
          fscanf(f3, "%s%s", mne1, opnd1);
        }
      } else
        fprintf(f5, "%s\t%s\t%s\n", la, mne, opnd);
    }
    fscanf(f1, "%s%s%s", la, mne, opnd);
  }
  fprintf(f5, "%s\t%s\t%s", la, mne, opnd);
  fclose(f1);
  fclose(f2);
  fclose(f3);
  fclose(f4);
  fclose(f5);
  printf("files to be viewed \n");
  printf("1. namtab.txt\n");
  printf("2. deftab.txt\n");
  printf("3. argtab.txt\n");
  printf("4. op.txt\n");
}
