#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main(int argc, char **argv) {

  screen s;
  struct matrix * edges;
  struct matrix * transform;

  //temp?
  color c;
  c.red = 0;
  c.green = 0;
  c.blue = 255;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );

  //temporary test cases (until parser works)
  add_edge(edges, 100, 100, 0, 200, 200, 0);
  add_edge(edges, 100, 100, 0, 100, 400, 0);
  printf("works\n");

  draw_lines(edges, s, c);
  display(s);

  transform = make_translate(10, 0, 0);
  matrix_mult(edges, transform);

  draw_lines(edges, s, c);
  display(s);



  free_matrix( edges );
  free_matrix( transform );
}
