#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main(int argc, char **argv) {
  //note: script uploaded, can use for testing

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
  //cube
  /*
  add_edge(edges, 100, 100, 0, 200, 100, 0);
  add_edge(edges, 100, 100, 0, 100, 200, 0);
  add_edge(edges, 200, 200, 0, 200, 100, 0);
  add_edge(edges, 200, 200, 0, 100, 200, 0);

  add_edge(edges, 100, 100, 100, 200, 100, 100);
  add_edge(edges, 100, 100, 100, 100, 200, 100);
  add_edge(edges, 200, 200, 100, 200, 100, 100);
  add_edge(edges, 200, 200, 100, 100, 200, 100);

  add_edge(edges, 100, 100, 0, 100, 100, 100);
  add_edge(edges, 100, 200, 0, 100, 200, 100);
  add_edge(edges, 200, 100, 0, 200, 100, 100);
  add_edge(edges, 200, 200, 0, 200, 200, 100);

  draw_lines(edges, s, c);
  display(s);

  //translation------------------
  transform = make_translate(100, 0, 0);
  //matrix_mult(transform, edges);

  clear_screen(s);
  draw_lines(edges, s, c);
  //display(s);

  //scaling----------------------
  //transform = make_scale(2, 0.1, 1);
  //matrix_mult(transform, edges);

  clear_screen(s);
  draw_lines(edges, s, c);
  display(s);

  //rotation----------------------
  transform = make_rotZ(0.3);
  matrix_mult(transform, edges);

  clear_screen(s);
  draw_lines(edges, s, c);
  display(s);

  transform = make_rotY(0.3);
  matrix_mult(transform, edges);

  clear_screen(s);
  draw_lines(edges, s, c);
  display(s);

  transform = make_rotX(0.3);
  matrix_mult(transform, edges);

  clear_screen(s); // make sure this is called before drawing and displaying
  draw_lines(edges, s, c);
  display(s);


  free_matrix( edges );
  free_matrix( transform );
  */
}
