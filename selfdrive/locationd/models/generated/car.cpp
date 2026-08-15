#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1189195778593529110) {
   out_1189195778593529110[0] = delta_x[0] + nom_x[0];
   out_1189195778593529110[1] = delta_x[1] + nom_x[1];
   out_1189195778593529110[2] = delta_x[2] + nom_x[2];
   out_1189195778593529110[3] = delta_x[3] + nom_x[3];
   out_1189195778593529110[4] = delta_x[4] + nom_x[4];
   out_1189195778593529110[5] = delta_x[5] + nom_x[5];
   out_1189195778593529110[6] = delta_x[6] + nom_x[6];
   out_1189195778593529110[7] = delta_x[7] + nom_x[7];
   out_1189195778593529110[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2345758885708007068) {
   out_2345758885708007068[0] = -nom_x[0] + true_x[0];
   out_2345758885708007068[1] = -nom_x[1] + true_x[1];
   out_2345758885708007068[2] = -nom_x[2] + true_x[2];
   out_2345758885708007068[3] = -nom_x[3] + true_x[3];
   out_2345758885708007068[4] = -nom_x[4] + true_x[4];
   out_2345758885708007068[5] = -nom_x[5] + true_x[5];
   out_2345758885708007068[6] = -nom_x[6] + true_x[6];
   out_2345758885708007068[7] = -nom_x[7] + true_x[7];
   out_2345758885708007068[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6501999113898700908) {
   out_6501999113898700908[0] = 1.0;
   out_6501999113898700908[1] = 0.0;
   out_6501999113898700908[2] = 0.0;
   out_6501999113898700908[3] = 0.0;
   out_6501999113898700908[4] = 0.0;
   out_6501999113898700908[5] = 0.0;
   out_6501999113898700908[6] = 0.0;
   out_6501999113898700908[7] = 0.0;
   out_6501999113898700908[8] = 0.0;
   out_6501999113898700908[9] = 0.0;
   out_6501999113898700908[10] = 1.0;
   out_6501999113898700908[11] = 0.0;
   out_6501999113898700908[12] = 0.0;
   out_6501999113898700908[13] = 0.0;
   out_6501999113898700908[14] = 0.0;
   out_6501999113898700908[15] = 0.0;
   out_6501999113898700908[16] = 0.0;
   out_6501999113898700908[17] = 0.0;
   out_6501999113898700908[18] = 0.0;
   out_6501999113898700908[19] = 0.0;
   out_6501999113898700908[20] = 1.0;
   out_6501999113898700908[21] = 0.0;
   out_6501999113898700908[22] = 0.0;
   out_6501999113898700908[23] = 0.0;
   out_6501999113898700908[24] = 0.0;
   out_6501999113898700908[25] = 0.0;
   out_6501999113898700908[26] = 0.0;
   out_6501999113898700908[27] = 0.0;
   out_6501999113898700908[28] = 0.0;
   out_6501999113898700908[29] = 0.0;
   out_6501999113898700908[30] = 1.0;
   out_6501999113898700908[31] = 0.0;
   out_6501999113898700908[32] = 0.0;
   out_6501999113898700908[33] = 0.0;
   out_6501999113898700908[34] = 0.0;
   out_6501999113898700908[35] = 0.0;
   out_6501999113898700908[36] = 0.0;
   out_6501999113898700908[37] = 0.0;
   out_6501999113898700908[38] = 0.0;
   out_6501999113898700908[39] = 0.0;
   out_6501999113898700908[40] = 1.0;
   out_6501999113898700908[41] = 0.0;
   out_6501999113898700908[42] = 0.0;
   out_6501999113898700908[43] = 0.0;
   out_6501999113898700908[44] = 0.0;
   out_6501999113898700908[45] = 0.0;
   out_6501999113898700908[46] = 0.0;
   out_6501999113898700908[47] = 0.0;
   out_6501999113898700908[48] = 0.0;
   out_6501999113898700908[49] = 0.0;
   out_6501999113898700908[50] = 1.0;
   out_6501999113898700908[51] = 0.0;
   out_6501999113898700908[52] = 0.0;
   out_6501999113898700908[53] = 0.0;
   out_6501999113898700908[54] = 0.0;
   out_6501999113898700908[55] = 0.0;
   out_6501999113898700908[56] = 0.0;
   out_6501999113898700908[57] = 0.0;
   out_6501999113898700908[58] = 0.0;
   out_6501999113898700908[59] = 0.0;
   out_6501999113898700908[60] = 1.0;
   out_6501999113898700908[61] = 0.0;
   out_6501999113898700908[62] = 0.0;
   out_6501999113898700908[63] = 0.0;
   out_6501999113898700908[64] = 0.0;
   out_6501999113898700908[65] = 0.0;
   out_6501999113898700908[66] = 0.0;
   out_6501999113898700908[67] = 0.0;
   out_6501999113898700908[68] = 0.0;
   out_6501999113898700908[69] = 0.0;
   out_6501999113898700908[70] = 1.0;
   out_6501999113898700908[71] = 0.0;
   out_6501999113898700908[72] = 0.0;
   out_6501999113898700908[73] = 0.0;
   out_6501999113898700908[74] = 0.0;
   out_6501999113898700908[75] = 0.0;
   out_6501999113898700908[76] = 0.0;
   out_6501999113898700908[77] = 0.0;
   out_6501999113898700908[78] = 0.0;
   out_6501999113898700908[79] = 0.0;
   out_6501999113898700908[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_964843116983098162) {
   out_964843116983098162[0] = state[0];
   out_964843116983098162[1] = state[1];
   out_964843116983098162[2] = state[2];
   out_964843116983098162[3] = state[3];
   out_964843116983098162[4] = state[4];
   out_964843116983098162[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_964843116983098162[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_964843116983098162[7] = state[7];
   out_964843116983098162[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4450222731618984987) {
   out_4450222731618984987[0] = 1;
   out_4450222731618984987[1] = 0;
   out_4450222731618984987[2] = 0;
   out_4450222731618984987[3] = 0;
   out_4450222731618984987[4] = 0;
   out_4450222731618984987[5] = 0;
   out_4450222731618984987[6] = 0;
   out_4450222731618984987[7] = 0;
   out_4450222731618984987[8] = 0;
   out_4450222731618984987[9] = 0;
   out_4450222731618984987[10] = 1;
   out_4450222731618984987[11] = 0;
   out_4450222731618984987[12] = 0;
   out_4450222731618984987[13] = 0;
   out_4450222731618984987[14] = 0;
   out_4450222731618984987[15] = 0;
   out_4450222731618984987[16] = 0;
   out_4450222731618984987[17] = 0;
   out_4450222731618984987[18] = 0;
   out_4450222731618984987[19] = 0;
   out_4450222731618984987[20] = 1;
   out_4450222731618984987[21] = 0;
   out_4450222731618984987[22] = 0;
   out_4450222731618984987[23] = 0;
   out_4450222731618984987[24] = 0;
   out_4450222731618984987[25] = 0;
   out_4450222731618984987[26] = 0;
   out_4450222731618984987[27] = 0;
   out_4450222731618984987[28] = 0;
   out_4450222731618984987[29] = 0;
   out_4450222731618984987[30] = 1;
   out_4450222731618984987[31] = 0;
   out_4450222731618984987[32] = 0;
   out_4450222731618984987[33] = 0;
   out_4450222731618984987[34] = 0;
   out_4450222731618984987[35] = 0;
   out_4450222731618984987[36] = 0;
   out_4450222731618984987[37] = 0;
   out_4450222731618984987[38] = 0;
   out_4450222731618984987[39] = 0;
   out_4450222731618984987[40] = 1;
   out_4450222731618984987[41] = 0;
   out_4450222731618984987[42] = 0;
   out_4450222731618984987[43] = 0;
   out_4450222731618984987[44] = 0;
   out_4450222731618984987[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4450222731618984987[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4450222731618984987[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4450222731618984987[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4450222731618984987[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4450222731618984987[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4450222731618984987[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4450222731618984987[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4450222731618984987[53] = -9.8100000000000005*dt;
   out_4450222731618984987[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4450222731618984987[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4450222731618984987[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4450222731618984987[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4450222731618984987[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4450222731618984987[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4450222731618984987[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4450222731618984987[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4450222731618984987[62] = 0;
   out_4450222731618984987[63] = 0;
   out_4450222731618984987[64] = 0;
   out_4450222731618984987[65] = 0;
   out_4450222731618984987[66] = 0;
   out_4450222731618984987[67] = 0;
   out_4450222731618984987[68] = 0;
   out_4450222731618984987[69] = 0;
   out_4450222731618984987[70] = 1;
   out_4450222731618984987[71] = 0;
   out_4450222731618984987[72] = 0;
   out_4450222731618984987[73] = 0;
   out_4450222731618984987[74] = 0;
   out_4450222731618984987[75] = 0;
   out_4450222731618984987[76] = 0;
   out_4450222731618984987[77] = 0;
   out_4450222731618984987[78] = 0;
   out_4450222731618984987[79] = 0;
   out_4450222731618984987[80] = 1;
}
void h_25(double *state, double *unused, double *out_8665973258652204113) {
   out_8665973258652204113[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2691189112013536329) {
   out_2691189112013536329[0] = 0;
   out_2691189112013536329[1] = 0;
   out_2691189112013536329[2] = 0;
   out_2691189112013536329[3] = 0;
   out_2691189112013536329[4] = 0;
   out_2691189112013536329[5] = 0;
   out_2691189112013536329[6] = 1;
   out_2691189112013536329[7] = 0;
   out_2691189112013536329[8] = 0;
}
void h_24(double *state, double *unused, double *out_410814621539293905) {
   out_410814621539293905[0] = state[4];
   out_410814621539293905[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6536876074055658896) {
   out_6536876074055658896[0] = 0;
   out_6536876074055658896[1] = 0;
   out_6536876074055658896[2] = 0;
   out_6536876074055658896[3] = 0;
   out_6536876074055658896[4] = 1;
   out_6536876074055658896[5] = 0;
   out_6536876074055658896[6] = 0;
   out_6536876074055658896[7] = 0;
   out_6536876074055658896[8] = 0;
   out_6536876074055658896[9] = 0;
   out_6536876074055658896[10] = 0;
   out_6536876074055658896[11] = 0;
   out_6536876074055658896[12] = 0;
   out_6536876074055658896[13] = 0;
   out_6536876074055658896[14] = 1;
   out_6536876074055658896[15] = 0;
   out_6536876074055658896[16] = 0;
   out_6536876074055658896[17] = 0;
}
void h_30(double *state, double *unused, double *out_7146001406568370401) {
   out_7146001406568370401[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7218885442141144527) {
   out_7218885442141144527[0] = 0;
   out_7218885442141144527[1] = 0;
   out_7218885442141144527[2] = 0;
   out_7218885442141144527[3] = 0;
   out_7218885442141144527[4] = 1;
   out_7218885442141144527[5] = 0;
   out_7218885442141144527[6] = 0;
   out_7218885442141144527[7] = 0;
   out_7218885442141144527[8] = 0;
}
void h_26(double *state, double *unused, double *out_8994095081044175741) {
   out_8994095081044175741[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6432692430887592553) {
   out_6432692430887592553[0] = 0;
   out_6432692430887592553[1] = 0;
   out_6432692430887592553[2] = 0;
   out_6432692430887592553[3] = 0;
   out_6432692430887592553[4] = 0;
   out_6432692430887592553[5] = 0;
   out_6432692430887592553[6] = 0;
   out_6432692430887592553[7] = 1;
   out_6432692430887592553[8] = 0;
}
void h_27(double *state, double *unused, double *out_2563453822919009723) {
   out_2563453822919009723[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4995291370957201310) {
   out_4995291370957201310[0] = 0;
   out_4995291370957201310[1] = 0;
   out_4995291370957201310[2] = 0;
   out_4995291370957201310[3] = 1;
   out_4995291370957201310[4] = 0;
   out_4995291370957201310[5] = 0;
   out_4995291370957201310[6] = 0;
   out_4995291370957201310[7] = 0;
   out_4995291370957201310[8] = 0;
}
void h_29(double *state, double *unused, double *out_7243412774072000009) {
   out_7243412774072000009[0] = state[1];
}
void H_29(double *state, double *unused, double *out_6708654097826752343) {
   out_6708654097826752343[0] = 0;
   out_6708654097826752343[1] = 1;
   out_6708654097826752343[2] = 0;
   out_6708654097826752343[3] = 0;
   out_6708654097826752343[4] = 0;
   out_6708654097826752343[5] = 0;
   out_6708654097826752343[6] = 0;
   out_6708654097826752343[7] = 0;
   out_6708654097826752343[8] = 0;
}
void h_28(double *state, double *unused, double *out_2438219444741835922) {
   out_2438219444741835922[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6655690958813268699) {
   out_6655690958813268699[0] = 1;
   out_6655690958813268699[1] = 0;
   out_6655690958813268699[2] = 0;
   out_6655690958813268699[3] = 0;
   out_6655690958813268699[4] = 0;
   out_6655690958813268699[5] = 0;
   out_6655690958813268699[6] = 0;
   out_6655690958813268699[7] = 0;
   out_6655690958813268699[8] = 0;
}
void h_31(double *state, double *unused, double *out_4870101409016015197) {
   out_4870101409016015197[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7058900533120944029) {
   out_7058900533120944029[0] = 0;
   out_7058900533120944029[1] = 0;
   out_7058900533120944029[2] = 0;
   out_7058900533120944029[3] = 0;
   out_7058900533120944029[4] = 0;
   out_7058900533120944029[5] = 0;
   out_7058900533120944029[6] = 0;
   out_7058900533120944029[7] = 0;
   out_7058900533120944029[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_1189195778593529110) {
  err_fun(nom_x, delta_x, out_1189195778593529110);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2345758885708007068) {
  inv_err_fun(nom_x, true_x, out_2345758885708007068);
}
void car_H_mod_fun(double *state, double *out_6501999113898700908) {
  H_mod_fun(state, out_6501999113898700908);
}
void car_f_fun(double *state, double dt, double *out_964843116983098162) {
  f_fun(state,  dt, out_964843116983098162);
}
void car_F_fun(double *state, double dt, double *out_4450222731618984987) {
  F_fun(state,  dt, out_4450222731618984987);
}
void car_h_25(double *state, double *unused, double *out_8665973258652204113) {
  h_25(state, unused, out_8665973258652204113);
}
void car_H_25(double *state, double *unused, double *out_2691189112013536329) {
  H_25(state, unused, out_2691189112013536329);
}
void car_h_24(double *state, double *unused, double *out_410814621539293905) {
  h_24(state, unused, out_410814621539293905);
}
void car_H_24(double *state, double *unused, double *out_6536876074055658896) {
  H_24(state, unused, out_6536876074055658896);
}
void car_h_30(double *state, double *unused, double *out_7146001406568370401) {
  h_30(state, unused, out_7146001406568370401);
}
void car_H_30(double *state, double *unused, double *out_7218885442141144527) {
  H_30(state, unused, out_7218885442141144527);
}
void car_h_26(double *state, double *unused, double *out_8994095081044175741) {
  h_26(state, unused, out_8994095081044175741);
}
void car_H_26(double *state, double *unused, double *out_6432692430887592553) {
  H_26(state, unused, out_6432692430887592553);
}
void car_h_27(double *state, double *unused, double *out_2563453822919009723) {
  h_27(state, unused, out_2563453822919009723);
}
void car_H_27(double *state, double *unused, double *out_4995291370957201310) {
  H_27(state, unused, out_4995291370957201310);
}
void car_h_29(double *state, double *unused, double *out_7243412774072000009) {
  h_29(state, unused, out_7243412774072000009);
}
void car_H_29(double *state, double *unused, double *out_6708654097826752343) {
  H_29(state, unused, out_6708654097826752343);
}
void car_h_28(double *state, double *unused, double *out_2438219444741835922) {
  h_28(state, unused, out_2438219444741835922);
}
void car_H_28(double *state, double *unused, double *out_6655690958813268699) {
  H_28(state, unused, out_6655690958813268699);
}
void car_h_31(double *state, double *unused, double *out_4870101409016015197) {
  h_31(state, unused, out_4870101409016015197);
}
void car_H_31(double *state, double *unused, double *out_7058900533120944029) {
  H_31(state, unused, out_7058900533120944029);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
