#include <stdio.h>
int main(int argc, char* argv[]){
   
  char *filename = argv[1];
  //printf("file is: %s\n", filename);


  FILE *f = NULL;

  if ((f = fopen(filename, "r")) == NULL)
    return -1; 
  
  int N = 0;
  int N_edges = 0;
 
  fscanf(f, "%d\t%d", &N, &N);  
  fscanf(f, "%d", &N_edges);

  //printf("The graph vertex count is %d with %d egdes.\n", N, N_edges);

  printf("%d\t%d\n", N, N);
  printf("%d\n", N_edges);

  FILE *f_wtr;

  if((f_wtr = fopen("scale16_s.bin","wb")) == NULL)  // w for write, b for binary
    return -1;



  int vert_from, vert_to, weight;
  vert_from = -1;
  vert_to = -1;
  
  //int is_EOF;
  //while((is_EOF = fscanf(f, "%d %d", &vert_from, &vert_to)) != EOF){
  for(int i=0; i< N_edges; i++){
    // printf("i = %d\n", i);
    fscanf(f, "%d\t%d\t%d", &vert_from, &vert_to, &weight);
    //printf("read %d --> %d, w = %d\n", vert_from, vert_to, weight);
    //printf("%d\t%d\t%d\n", vert_from, vert_to, weight);
    fwrite(&vert_from, sizeof(vert_from), 1, f_wtr); 
    fwrite(&vert_to, sizeof(vert_from), 1, f_wtr);
    fwrite(&weight, sizeof(vert_from), 1, f_wtr);
  }

  fclose(f);
  fclose(f_wtr);

  return 0;
}
