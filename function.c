#include "rw.h"
#include "prototypes.h"

int func(double t, const double y[], double f[],
	 void *params){
  (void)(t); /* avoid unused parameter warning */
  double mu = *(double *)params;

  f[0] = sin(y[1]) - BBB*y[0];
  f[1] = sin(y[2]) - BBB*y[1];
  f[2] = sin(y[0]) - BBB*y[2];
  return GSL_SUCCESS;
}

int jac(double t, const double y[], double *dfdy,
     double dfdt[], void *params){

  (void)(t); /* avoid unused parameter warning */
  double mu = *(double *)params; // dumy
  gsl_matrix_view dfdy_mat
    = gsl_matrix_view_array (dfdy, 3, 3);
  gsl_matrix * m = &dfdy_mat.matrix;
  gsl_matrix_set(m, 0, 0,     cos(y[0]));
  gsl_matrix_set(m, 0, 1,             0);
  gsl_matrix_set(m, 0, 2,          -BBB);
  gsl_matrix_set(m, 1, 0,             0);
  gsl_matrix_set(m, 1, 1,          -BBB);
  gsl_matrix_set(m, 1, 2,     cos(y[2]));  
  gsl_matrix_set(m, 2, 0,          -BBB);
  gsl_matrix_set(m, 2, 1,     cos(y[1]));
  gsl_matrix_set(m, 2, 2,             0);  
  dfdt[0] = 0.0;
  dfdt[1] = 0.0;
  dfdt[2] = 0.0;
  return GSL_SUCCESS;
}
