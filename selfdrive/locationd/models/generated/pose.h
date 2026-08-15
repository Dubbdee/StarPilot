#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3844491001847189814);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2069018563570238764);
void pose_H_mod_fun(double *state, double *out_6387883902503614403);
void pose_f_fun(double *state, double dt, double *out_6400885410956827677);
void pose_F_fun(double *state, double dt, double *out_6156434988829804866);
void pose_h_4(double *state, double *unused, double *out_3850105333082396155);
void pose_H_4(double *state, double *unused, double *out_8784638092414987960);
void pose_h_10(double *state, double *unused, double *out_5130122425703055042);
void pose_H_10(double *state, double *unused, double *out_3246782689811755505);
void pose_h_13(double *state, double *unused, double *out_4607070015010854051);
void pose_H_13(double *state, double *unused, double *out_6449832155962230855);
void pose_h_14(double *state, double *unused, double *out_3610332955332281780);
void pose_H_14(double *state, double *unused, double *out_5698865124955079127);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}