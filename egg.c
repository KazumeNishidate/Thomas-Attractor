#include <eggx.h>
#include <stdio.h>
#include  <stdlib.h>
#include  <math.h>
#include  <string.h>
#include  <X11/Xlib.h>
#include  <X11/Xutil.h>
#include "rw.h"
#include "prototypes.h"
#define PI 3.14159265359
#define MYCOLOR IDL2_MAC_STYLE
#define X_MAX 800
#define Y_MAX 800
#define SCALE 90
#define XSHIFT 300
#define YSHIFT 300
#define CLRDIV 200

void egg_disp(const double y[]){
  static int cnt=0, win;
  int c_r, c_g, c_b;
  int xpt, ypt, zpt;
  double xd_psi, xd_theta, xd_phi;  // [radian]
  double xd_a11, xd_a12, xd_a13;
  double xd_a21, xd_a22, xd_a23;
  double xd_a31, xd_a32, xd_a33;  
  int xpt_xyz, ypt_xyz;
  
  if(cnt==0){
    gsetinitialbgcolor("white") ;
    win=gopen(X_MAX,Y_MAX);
    layer(win, 0, 1);
    xd_psi   = 1.2;
    xd_theta = 0.0;
    xd_phi   = 1.2;
    xd_a11= cos(xd_phi)*cos(xd_psi)+sin(xd_phi)*sin(xd_theta)*sin(xd_psi);
    xd_a12=-sin(xd_phi)*cos(xd_psi)+cos(xd_phi)*sin(xd_theta)*sin(xd_psi);
    xd_a13= cos(xd_theta)*sin(xd_psi);
    xd_a21= sin(xd_phi)*cos(xd_theta);
    xd_a22= cos(xd_phi)*cos(xd_theta);
    xd_a23=-sin(xd_theta);
    // just in case
    xd_a31=-cos(xd_phi)*sin(xd_psi)+sin(xd_phi)*sin(xd_theta)*cos(xd_psi);
    xd_a32= sin(xd_phi)*cos(xd_psi)+cos(xd_phi)*sin(xd_theta)*cos(xd_psi);
    xd_a33= cos(xd_theta)*cos(xd_psi);
  }
  xpt = (int)(y[0]*SCALE);
  ypt = (int)(y[1]*SCALE);
  zpt = (int)(y[2]*SCALE);
  xpt_xyz = (int)(xpt*xd_a11 + ypt*xd_a12 + zpt*xd_a13)+XSHIFT;
  ypt_xyz = (int)(xpt*xd_a21 + ypt*xd_a22 + zpt*xd_a23)+YSHIFT;
  newcolor(win, "White");
  
  makecolor(MYCOLOR,100, 0.0,cnt%CLRDIV, &c_r,&c_g,&c_b);
  newrgbcolor(win,c_r,c_g,c_b);
  fillcirc(win, xpt_xyz, ypt_xyz, 4, 4);

  copylayer(win, 1, 0);
  cnt++;  
}
