#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_1189195778593529110);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2345758885708007068);
void car_H_mod_fun(double *state, double *out_6501999113898700908);
void car_f_fun(double *state, double dt, double *out_964843116983098162);
void car_F_fun(double *state, double dt, double *out_4450222731618984987);
void car_h_25(double *state, double *unused, double *out_8665973258652204113);
void car_H_25(double *state, double *unused, double *out_2691189112013536329);
void car_h_24(double *state, double *unused, double *out_410814621539293905);
void car_H_24(double *state, double *unused, double *out_6536876074055658896);
void car_h_30(double *state, double *unused, double *out_7146001406568370401);
void car_H_30(double *state, double *unused, double *out_7218885442141144527);
void car_h_26(double *state, double *unused, double *out_8994095081044175741);
void car_H_26(double *state, double *unused, double *out_6432692430887592553);
void car_h_27(double *state, double *unused, double *out_2563453822919009723);
void car_H_27(double *state, double *unused, double *out_4995291370957201310);
void car_h_29(double *state, double *unused, double *out_7243412774072000009);
void car_H_29(double *state, double *unused, double *out_6708654097826752343);
void car_h_28(double *state, double *unused, double *out_2438219444741835922);
void car_H_28(double *state, double *unused, double *out_6655690958813268699);
void car_h_31(double *state, double *unused, double *out_4870101409016015197);
void car_H_31(double *state, double *unused, double *out_7058900533120944029);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}