#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"


/*======== void parse_file () ==========
Inputs:   char * filename
          struct matrix * transform,
          struct matrix * pm,
          screen s
Returns:

Goes through the file named filename and performs all of the actions listed in that file.
The file follows the following format:
     Every command is a single character that takes up a line
     Any command that requires arguments must have those arguments in the second line.
     The commands are as follows:
         line: add a line to the edge matrix -
	    takes 6 arguemnts (x0, y0, z0, x1, y1, z1)
	 ident: set the transform matrix to the identity matrix -
	 scale: create a scale matrix,
	    then multiply the transform matrix by the scale matrix -
	    takes 3 arguments (sx, sy, sz)
	 translate: create a translation matrix,
	    then multiply the transform matrix by the translation matrix -
	    takes 3 arguments (tx, ty, tz)
	 rotate: create an rotation matrix,
	    then multiply the transform matrix by the rotation matrix -
	    takes 2 arguments (axis, theta) axis should be x y or z
	 apply: apply the current transformation matrix to the
	    edge matrix
	 display: draw the lines of the edge matrix to the screen
	    display the screen
	 save: draw the lines of the edge matrix to the screen
	    save the screen to a file -
	    takes 1 argument (file name)
	 quit: end parsing

See the file script for an example of the file format


IMPORTANT MATH NOTE:
the trig functions int math.h use radian mesure, but us normal
humans use degrees, so the file will contain degrees for rotations,
be sure to conver those degrees to radians (M_PI is the constant
for PI)
====================*/
void parse_file ( char * filename,
                  struct matrix * transform,
                  struct matrix * edges,
                  screen s) {

  printf("parsing: %s\n", filename);

  FILE *f;
  char line[256];
  clear_screen(s);

  struct matrix * temp;

  if ( strcmp(filename, "stdin") == 0 )
    f = stdin;
  else
    f = fopen(filename, "r");

  while ( fgets(line, 255, f) != NULL ) {
    line[strlen(line)-1]='\0';
    printf(":%s:\n",line);
    if (! strcmp("line", line)){
      //note still get seg faults on not enough arguments in line
      fgets(line, 255, f);
      printf("running line strtok on: %s\n", line);
      char * p;
      int x0, y0, z0, x1, y1, z1;
      p = strtok (line, " ");
      x0 = atoi(p);
      p = strtok (NULL, " ");
      y0 = atoi(p);
      p = strtok (NULL, " ");
      z0 = atoi(p);
      p = strtok (NULL, " ");
      x1 = atoi(p);
      p = strtok (NULL, " ");
      y1 = atoi(p);
      p = strtok (NULL, " ");
      z1 = atoi(p);
      add_edge(edges, x0, y0, z0, x1, y1, z1);
    }else if (! strcmp("ident", line)){
      ident(transform);
    }else if (! strcmp("scale", line)){
      fgets(line, 255, f);
      printf("running scale strtok on: %s\n", line);
      char * p;
      int sx, sy, sz;
      p = strtok (line, " ");
      sx = atoi(p);
      p = strtok (NULL, " ");
      sy = atoi(p);
      p = strtok (NULL, " ");
      sz = atoi(p);
      temp = make_scale(sx, sy, sz);
      matrix_mult(temp, transform);
    }else if (! strcmp("translate", line)){
      fgets(line, 255, f);
      printf("running translate strtok on: %s\n", line);
      char * p;
      int tx, ty, tz;
      p = strtok (line, " ");
      tx = atoi(p);
      p = strtok (NULL, " ");
      ty = atoi(p);
      p = strtok (NULL, " ");
      tz = atoi(p);
      temp = make_translate(tx, ty, tz);
      matrix_mult(temp, transform);
    }else if (! strcmp("rotate", line)){
      fgets(line, 255, f);
      printf("running rotatetranslate strtok on: %s\n", line);
      char * p;
      int theta;
      char axis;
      p = strtok (line, " ");
      theta = atoi(p);
      p = strtok (NULL, " ");
      axis = *p;
      if (axis == 'x')
	make_rotX(theta);
      else if (axis == 'y')
	make_rotY(theta);
      else if (axis == 'z')
	make_rotZ(theta);
      else{
	printf("unknown axis\n");
	break;
      }
      //convert theta to radians
      
      matrix_mult(temp, transform);
    }else if (! strcmp("apply", line)){

    }else if (! strcmp("display", line)){

    }else if (! strcmp("save", line)){

    }else if (! strcmp("quit", line)){

    }else{
      printf("encountered unknown command\n");
    }
  }
}
