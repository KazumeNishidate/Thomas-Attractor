#include "rw.h"
#include "prototypes.h"

int main (void) {
  double mu = 0;
  gsl_odeiv2_system sys ={func, jac, 3, &mu};
  gsl_odeiv2_driver *d =
    gsl_odeiv2_driver_alloc_y_new(&sys,
				  gsl_odeiv2_step_rk8pd,
                                  1e-6, 1e-6, 0.0);
  int i;
  double t = 0.0;
  double y[3] = {1.0, 1.0, 2.0};

  for (i = 1; i <= 100000; i++) {
      double ti = i /10.0 ;
      int status = gsl_odeiv2_driver_apply(d, &t, ti, y);

      if (status != GSL_SUCCESS) {
          printf ("error, return value=%d\n", status);
          break;
      }
      //      printf ("%.5e %.5e %.5e\n", y[0], y[1], y[2]);
      egg_disp(y);
  }

  gsl_odeiv2_driver_free (d);
  return 0;
}
