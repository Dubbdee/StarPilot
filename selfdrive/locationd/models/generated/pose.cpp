#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3844491001847189814) {
   out_3844491001847189814[0] = delta_x[0] + nom_x[0];
   out_3844491001847189814[1] = delta_x[1] + nom_x[1];
   out_3844491001847189814[2] = delta_x[2] + nom_x[2];
   out_3844491001847189814[3] = delta_x[3] + nom_x[3];
   out_3844491001847189814[4] = delta_x[4] + nom_x[4];
   out_3844491001847189814[5] = delta_x[5] + nom_x[5];
   out_3844491001847189814[6] = delta_x[6] + nom_x[6];
   out_3844491001847189814[7] = delta_x[7] + nom_x[7];
   out_3844491001847189814[8] = delta_x[8] + nom_x[8];
   out_3844491001847189814[9] = delta_x[9] + nom_x[9];
   out_3844491001847189814[10] = delta_x[10] + nom_x[10];
   out_3844491001847189814[11] = delta_x[11] + nom_x[11];
   out_3844491001847189814[12] = delta_x[12] + nom_x[12];
   out_3844491001847189814[13] = delta_x[13] + nom_x[13];
   out_3844491001847189814[14] = delta_x[14] + nom_x[14];
   out_3844491001847189814[15] = delta_x[15] + nom_x[15];
   out_3844491001847189814[16] = delta_x[16] + nom_x[16];
   out_3844491001847189814[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2069018563570238764) {
   out_2069018563570238764[0] = -nom_x[0] + true_x[0];
   out_2069018563570238764[1] = -nom_x[1] + true_x[1];
   out_2069018563570238764[2] = -nom_x[2] + true_x[2];
   out_2069018563570238764[3] = -nom_x[3] + true_x[3];
   out_2069018563570238764[4] = -nom_x[4] + true_x[4];
   out_2069018563570238764[5] = -nom_x[5] + true_x[5];
   out_2069018563570238764[6] = -nom_x[6] + true_x[6];
   out_2069018563570238764[7] = -nom_x[7] + true_x[7];
   out_2069018563570238764[8] = -nom_x[8] + true_x[8];
   out_2069018563570238764[9] = -nom_x[9] + true_x[9];
   out_2069018563570238764[10] = -nom_x[10] + true_x[10];
   out_2069018563570238764[11] = -nom_x[11] + true_x[11];
   out_2069018563570238764[12] = -nom_x[12] + true_x[12];
   out_2069018563570238764[13] = -nom_x[13] + true_x[13];
   out_2069018563570238764[14] = -nom_x[14] + true_x[14];
   out_2069018563570238764[15] = -nom_x[15] + true_x[15];
   out_2069018563570238764[16] = -nom_x[16] + true_x[16];
   out_2069018563570238764[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6387883902503614403) {
   out_6387883902503614403[0] = 1.0;
   out_6387883902503614403[1] = 0.0;
   out_6387883902503614403[2] = 0.0;
   out_6387883902503614403[3] = 0.0;
   out_6387883902503614403[4] = 0.0;
   out_6387883902503614403[5] = 0.0;
   out_6387883902503614403[6] = 0.0;
   out_6387883902503614403[7] = 0.0;
   out_6387883902503614403[8] = 0.0;
   out_6387883902503614403[9] = 0.0;
   out_6387883902503614403[10] = 0.0;
   out_6387883902503614403[11] = 0.0;
   out_6387883902503614403[12] = 0.0;
   out_6387883902503614403[13] = 0.0;
   out_6387883902503614403[14] = 0.0;
   out_6387883902503614403[15] = 0.0;
   out_6387883902503614403[16] = 0.0;
   out_6387883902503614403[17] = 0.0;
   out_6387883902503614403[18] = 0.0;
   out_6387883902503614403[19] = 1.0;
   out_6387883902503614403[20] = 0.0;
   out_6387883902503614403[21] = 0.0;
   out_6387883902503614403[22] = 0.0;
   out_6387883902503614403[23] = 0.0;
   out_6387883902503614403[24] = 0.0;
   out_6387883902503614403[25] = 0.0;
   out_6387883902503614403[26] = 0.0;
   out_6387883902503614403[27] = 0.0;
   out_6387883902503614403[28] = 0.0;
   out_6387883902503614403[29] = 0.0;
   out_6387883902503614403[30] = 0.0;
   out_6387883902503614403[31] = 0.0;
   out_6387883902503614403[32] = 0.0;
   out_6387883902503614403[33] = 0.0;
   out_6387883902503614403[34] = 0.0;
   out_6387883902503614403[35] = 0.0;
   out_6387883902503614403[36] = 0.0;
   out_6387883902503614403[37] = 0.0;
   out_6387883902503614403[38] = 1.0;
   out_6387883902503614403[39] = 0.0;
   out_6387883902503614403[40] = 0.0;
   out_6387883902503614403[41] = 0.0;
   out_6387883902503614403[42] = 0.0;
   out_6387883902503614403[43] = 0.0;
   out_6387883902503614403[44] = 0.0;
   out_6387883902503614403[45] = 0.0;
   out_6387883902503614403[46] = 0.0;
   out_6387883902503614403[47] = 0.0;
   out_6387883902503614403[48] = 0.0;
   out_6387883902503614403[49] = 0.0;
   out_6387883902503614403[50] = 0.0;
   out_6387883902503614403[51] = 0.0;
   out_6387883902503614403[52] = 0.0;
   out_6387883902503614403[53] = 0.0;
   out_6387883902503614403[54] = 0.0;
   out_6387883902503614403[55] = 0.0;
   out_6387883902503614403[56] = 0.0;
   out_6387883902503614403[57] = 1.0;
   out_6387883902503614403[58] = 0.0;
   out_6387883902503614403[59] = 0.0;
   out_6387883902503614403[60] = 0.0;
   out_6387883902503614403[61] = 0.0;
   out_6387883902503614403[62] = 0.0;
   out_6387883902503614403[63] = 0.0;
   out_6387883902503614403[64] = 0.0;
   out_6387883902503614403[65] = 0.0;
   out_6387883902503614403[66] = 0.0;
   out_6387883902503614403[67] = 0.0;
   out_6387883902503614403[68] = 0.0;
   out_6387883902503614403[69] = 0.0;
   out_6387883902503614403[70] = 0.0;
   out_6387883902503614403[71] = 0.0;
   out_6387883902503614403[72] = 0.0;
   out_6387883902503614403[73] = 0.0;
   out_6387883902503614403[74] = 0.0;
   out_6387883902503614403[75] = 0.0;
   out_6387883902503614403[76] = 1.0;
   out_6387883902503614403[77] = 0.0;
   out_6387883902503614403[78] = 0.0;
   out_6387883902503614403[79] = 0.0;
   out_6387883902503614403[80] = 0.0;
   out_6387883902503614403[81] = 0.0;
   out_6387883902503614403[82] = 0.0;
   out_6387883902503614403[83] = 0.0;
   out_6387883902503614403[84] = 0.0;
   out_6387883902503614403[85] = 0.0;
   out_6387883902503614403[86] = 0.0;
   out_6387883902503614403[87] = 0.0;
   out_6387883902503614403[88] = 0.0;
   out_6387883902503614403[89] = 0.0;
   out_6387883902503614403[90] = 0.0;
   out_6387883902503614403[91] = 0.0;
   out_6387883902503614403[92] = 0.0;
   out_6387883902503614403[93] = 0.0;
   out_6387883902503614403[94] = 0.0;
   out_6387883902503614403[95] = 1.0;
   out_6387883902503614403[96] = 0.0;
   out_6387883902503614403[97] = 0.0;
   out_6387883902503614403[98] = 0.0;
   out_6387883902503614403[99] = 0.0;
   out_6387883902503614403[100] = 0.0;
   out_6387883902503614403[101] = 0.0;
   out_6387883902503614403[102] = 0.0;
   out_6387883902503614403[103] = 0.0;
   out_6387883902503614403[104] = 0.0;
   out_6387883902503614403[105] = 0.0;
   out_6387883902503614403[106] = 0.0;
   out_6387883902503614403[107] = 0.0;
   out_6387883902503614403[108] = 0.0;
   out_6387883902503614403[109] = 0.0;
   out_6387883902503614403[110] = 0.0;
   out_6387883902503614403[111] = 0.0;
   out_6387883902503614403[112] = 0.0;
   out_6387883902503614403[113] = 0.0;
   out_6387883902503614403[114] = 1.0;
   out_6387883902503614403[115] = 0.0;
   out_6387883902503614403[116] = 0.0;
   out_6387883902503614403[117] = 0.0;
   out_6387883902503614403[118] = 0.0;
   out_6387883902503614403[119] = 0.0;
   out_6387883902503614403[120] = 0.0;
   out_6387883902503614403[121] = 0.0;
   out_6387883902503614403[122] = 0.0;
   out_6387883902503614403[123] = 0.0;
   out_6387883902503614403[124] = 0.0;
   out_6387883902503614403[125] = 0.0;
   out_6387883902503614403[126] = 0.0;
   out_6387883902503614403[127] = 0.0;
   out_6387883902503614403[128] = 0.0;
   out_6387883902503614403[129] = 0.0;
   out_6387883902503614403[130] = 0.0;
   out_6387883902503614403[131] = 0.0;
   out_6387883902503614403[132] = 0.0;
   out_6387883902503614403[133] = 1.0;
   out_6387883902503614403[134] = 0.0;
   out_6387883902503614403[135] = 0.0;
   out_6387883902503614403[136] = 0.0;
   out_6387883902503614403[137] = 0.0;
   out_6387883902503614403[138] = 0.0;
   out_6387883902503614403[139] = 0.0;
   out_6387883902503614403[140] = 0.0;
   out_6387883902503614403[141] = 0.0;
   out_6387883902503614403[142] = 0.0;
   out_6387883902503614403[143] = 0.0;
   out_6387883902503614403[144] = 0.0;
   out_6387883902503614403[145] = 0.0;
   out_6387883902503614403[146] = 0.0;
   out_6387883902503614403[147] = 0.0;
   out_6387883902503614403[148] = 0.0;
   out_6387883902503614403[149] = 0.0;
   out_6387883902503614403[150] = 0.0;
   out_6387883902503614403[151] = 0.0;
   out_6387883902503614403[152] = 1.0;
   out_6387883902503614403[153] = 0.0;
   out_6387883902503614403[154] = 0.0;
   out_6387883902503614403[155] = 0.0;
   out_6387883902503614403[156] = 0.0;
   out_6387883902503614403[157] = 0.0;
   out_6387883902503614403[158] = 0.0;
   out_6387883902503614403[159] = 0.0;
   out_6387883902503614403[160] = 0.0;
   out_6387883902503614403[161] = 0.0;
   out_6387883902503614403[162] = 0.0;
   out_6387883902503614403[163] = 0.0;
   out_6387883902503614403[164] = 0.0;
   out_6387883902503614403[165] = 0.0;
   out_6387883902503614403[166] = 0.0;
   out_6387883902503614403[167] = 0.0;
   out_6387883902503614403[168] = 0.0;
   out_6387883902503614403[169] = 0.0;
   out_6387883902503614403[170] = 0.0;
   out_6387883902503614403[171] = 1.0;
   out_6387883902503614403[172] = 0.0;
   out_6387883902503614403[173] = 0.0;
   out_6387883902503614403[174] = 0.0;
   out_6387883902503614403[175] = 0.0;
   out_6387883902503614403[176] = 0.0;
   out_6387883902503614403[177] = 0.0;
   out_6387883902503614403[178] = 0.0;
   out_6387883902503614403[179] = 0.0;
   out_6387883902503614403[180] = 0.0;
   out_6387883902503614403[181] = 0.0;
   out_6387883902503614403[182] = 0.0;
   out_6387883902503614403[183] = 0.0;
   out_6387883902503614403[184] = 0.0;
   out_6387883902503614403[185] = 0.0;
   out_6387883902503614403[186] = 0.0;
   out_6387883902503614403[187] = 0.0;
   out_6387883902503614403[188] = 0.0;
   out_6387883902503614403[189] = 0.0;
   out_6387883902503614403[190] = 1.0;
   out_6387883902503614403[191] = 0.0;
   out_6387883902503614403[192] = 0.0;
   out_6387883902503614403[193] = 0.0;
   out_6387883902503614403[194] = 0.0;
   out_6387883902503614403[195] = 0.0;
   out_6387883902503614403[196] = 0.0;
   out_6387883902503614403[197] = 0.0;
   out_6387883902503614403[198] = 0.0;
   out_6387883902503614403[199] = 0.0;
   out_6387883902503614403[200] = 0.0;
   out_6387883902503614403[201] = 0.0;
   out_6387883902503614403[202] = 0.0;
   out_6387883902503614403[203] = 0.0;
   out_6387883902503614403[204] = 0.0;
   out_6387883902503614403[205] = 0.0;
   out_6387883902503614403[206] = 0.0;
   out_6387883902503614403[207] = 0.0;
   out_6387883902503614403[208] = 0.0;
   out_6387883902503614403[209] = 1.0;
   out_6387883902503614403[210] = 0.0;
   out_6387883902503614403[211] = 0.0;
   out_6387883902503614403[212] = 0.0;
   out_6387883902503614403[213] = 0.0;
   out_6387883902503614403[214] = 0.0;
   out_6387883902503614403[215] = 0.0;
   out_6387883902503614403[216] = 0.0;
   out_6387883902503614403[217] = 0.0;
   out_6387883902503614403[218] = 0.0;
   out_6387883902503614403[219] = 0.0;
   out_6387883902503614403[220] = 0.0;
   out_6387883902503614403[221] = 0.0;
   out_6387883902503614403[222] = 0.0;
   out_6387883902503614403[223] = 0.0;
   out_6387883902503614403[224] = 0.0;
   out_6387883902503614403[225] = 0.0;
   out_6387883902503614403[226] = 0.0;
   out_6387883902503614403[227] = 0.0;
   out_6387883902503614403[228] = 1.0;
   out_6387883902503614403[229] = 0.0;
   out_6387883902503614403[230] = 0.0;
   out_6387883902503614403[231] = 0.0;
   out_6387883902503614403[232] = 0.0;
   out_6387883902503614403[233] = 0.0;
   out_6387883902503614403[234] = 0.0;
   out_6387883902503614403[235] = 0.0;
   out_6387883902503614403[236] = 0.0;
   out_6387883902503614403[237] = 0.0;
   out_6387883902503614403[238] = 0.0;
   out_6387883902503614403[239] = 0.0;
   out_6387883902503614403[240] = 0.0;
   out_6387883902503614403[241] = 0.0;
   out_6387883902503614403[242] = 0.0;
   out_6387883902503614403[243] = 0.0;
   out_6387883902503614403[244] = 0.0;
   out_6387883902503614403[245] = 0.0;
   out_6387883902503614403[246] = 0.0;
   out_6387883902503614403[247] = 1.0;
   out_6387883902503614403[248] = 0.0;
   out_6387883902503614403[249] = 0.0;
   out_6387883902503614403[250] = 0.0;
   out_6387883902503614403[251] = 0.0;
   out_6387883902503614403[252] = 0.0;
   out_6387883902503614403[253] = 0.0;
   out_6387883902503614403[254] = 0.0;
   out_6387883902503614403[255] = 0.0;
   out_6387883902503614403[256] = 0.0;
   out_6387883902503614403[257] = 0.0;
   out_6387883902503614403[258] = 0.0;
   out_6387883902503614403[259] = 0.0;
   out_6387883902503614403[260] = 0.0;
   out_6387883902503614403[261] = 0.0;
   out_6387883902503614403[262] = 0.0;
   out_6387883902503614403[263] = 0.0;
   out_6387883902503614403[264] = 0.0;
   out_6387883902503614403[265] = 0.0;
   out_6387883902503614403[266] = 1.0;
   out_6387883902503614403[267] = 0.0;
   out_6387883902503614403[268] = 0.0;
   out_6387883902503614403[269] = 0.0;
   out_6387883902503614403[270] = 0.0;
   out_6387883902503614403[271] = 0.0;
   out_6387883902503614403[272] = 0.0;
   out_6387883902503614403[273] = 0.0;
   out_6387883902503614403[274] = 0.0;
   out_6387883902503614403[275] = 0.0;
   out_6387883902503614403[276] = 0.0;
   out_6387883902503614403[277] = 0.0;
   out_6387883902503614403[278] = 0.0;
   out_6387883902503614403[279] = 0.0;
   out_6387883902503614403[280] = 0.0;
   out_6387883902503614403[281] = 0.0;
   out_6387883902503614403[282] = 0.0;
   out_6387883902503614403[283] = 0.0;
   out_6387883902503614403[284] = 0.0;
   out_6387883902503614403[285] = 1.0;
   out_6387883902503614403[286] = 0.0;
   out_6387883902503614403[287] = 0.0;
   out_6387883902503614403[288] = 0.0;
   out_6387883902503614403[289] = 0.0;
   out_6387883902503614403[290] = 0.0;
   out_6387883902503614403[291] = 0.0;
   out_6387883902503614403[292] = 0.0;
   out_6387883902503614403[293] = 0.0;
   out_6387883902503614403[294] = 0.0;
   out_6387883902503614403[295] = 0.0;
   out_6387883902503614403[296] = 0.0;
   out_6387883902503614403[297] = 0.0;
   out_6387883902503614403[298] = 0.0;
   out_6387883902503614403[299] = 0.0;
   out_6387883902503614403[300] = 0.0;
   out_6387883902503614403[301] = 0.0;
   out_6387883902503614403[302] = 0.0;
   out_6387883902503614403[303] = 0.0;
   out_6387883902503614403[304] = 1.0;
   out_6387883902503614403[305] = 0.0;
   out_6387883902503614403[306] = 0.0;
   out_6387883902503614403[307] = 0.0;
   out_6387883902503614403[308] = 0.0;
   out_6387883902503614403[309] = 0.0;
   out_6387883902503614403[310] = 0.0;
   out_6387883902503614403[311] = 0.0;
   out_6387883902503614403[312] = 0.0;
   out_6387883902503614403[313] = 0.0;
   out_6387883902503614403[314] = 0.0;
   out_6387883902503614403[315] = 0.0;
   out_6387883902503614403[316] = 0.0;
   out_6387883902503614403[317] = 0.0;
   out_6387883902503614403[318] = 0.0;
   out_6387883902503614403[319] = 0.0;
   out_6387883902503614403[320] = 0.0;
   out_6387883902503614403[321] = 0.0;
   out_6387883902503614403[322] = 0.0;
   out_6387883902503614403[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6400885410956827677) {
   out_6400885410956827677[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6400885410956827677[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6400885410956827677[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6400885410956827677[3] = dt*state[12] + state[3];
   out_6400885410956827677[4] = dt*state[13] + state[4];
   out_6400885410956827677[5] = dt*state[14] + state[5];
   out_6400885410956827677[6] = state[6];
   out_6400885410956827677[7] = state[7];
   out_6400885410956827677[8] = state[8];
   out_6400885410956827677[9] = state[9];
   out_6400885410956827677[10] = state[10];
   out_6400885410956827677[11] = state[11];
   out_6400885410956827677[12] = state[12];
   out_6400885410956827677[13] = state[13];
   out_6400885410956827677[14] = state[14];
   out_6400885410956827677[15] = state[15];
   out_6400885410956827677[16] = state[16];
   out_6400885410956827677[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6156434988829804866) {
   out_6156434988829804866[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6156434988829804866[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6156434988829804866[2] = 0;
   out_6156434988829804866[3] = 0;
   out_6156434988829804866[4] = 0;
   out_6156434988829804866[5] = 0;
   out_6156434988829804866[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6156434988829804866[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6156434988829804866[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6156434988829804866[9] = 0;
   out_6156434988829804866[10] = 0;
   out_6156434988829804866[11] = 0;
   out_6156434988829804866[12] = 0;
   out_6156434988829804866[13] = 0;
   out_6156434988829804866[14] = 0;
   out_6156434988829804866[15] = 0;
   out_6156434988829804866[16] = 0;
   out_6156434988829804866[17] = 0;
   out_6156434988829804866[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6156434988829804866[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6156434988829804866[20] = 0;
   out_6156434988829804866[21] = 0;
   out_6156434988829804866[22] = 0;
   out_6156434988829804866[23] = 0;
   out_6156434988829804866[24] = 0;
   out_6156434988829804866[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6156434988829804866[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6156434988829804866[27] = 0;
   out_6156434988829804866[28] = 0;
   out_6156434988829804866[29] = 0;
   out_6156434988829804866[30] = 0;
   out_6156434988829804866[31] = 0;
   out_6156434988829804866[32] = 0;
   out_6156434988829804866[33] = 0;
   out_6156434988829804866[34] = 0;
   out_6156434988829804866[35] = 0;
   out_6156434988829804866[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6156434988829804866[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6156434988829804866[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6156434988829804866[39] = 0;
   out_6156434988829804866[40] = 0;
   out_6156434988829804866[41] = 0;
   out_6156434988829804866[42] = 0;
   out_6156434988829804866[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6156434988829804866[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6156434988829804866[45] = 0;
   out_6156434988829804866[46] = 0;
   out_6156434988829804866[47] = 0;
   out_6156434988829804866[48] = 0;
   out_6156434988829804866[49] = 0;
   out_6156434988829804866[50] = 0;
   out_6156434988829804866[51] = 0;
   out_6156434988829804866[52] = 0;
   out_6156434988829804866[53] = 0;
   out_6156434988829804866[54] = 0;
   out_6156434988829804866[55] = 0;
   out_6156434988829804866[56] = 0;
   out_6156434988829804866[57] = 1;
   out_6156434988829804866[58] = 0;
   out_6156434988829804866[59] = 0;
   out_6156434988829804866[60] = 0;
   out_6156434988829804866[61] = 0;
   out_6156434988829804866[62] = 0;
   out_6156434988829804866[63] = 0;
   out_6156434988829804866[64] = 0;
   out_6156434988829804866[65] = 0;
   out_6156434988829804866[66] = dt;
   out_6156434988829804866[67] = 0;
   out_6156434988829804866[68] = 0;
   out_6156434988829804866[69] = 0;
   out_6156434988829804866[70] = 0;
   out_6156434988829804866[71] = 0;
   out_6156434988829804866[72] = 0;
   out_6156434988829804866[73] = 0;
   out_6156434988829804866[74] = 0;
   out_6156434988829804866[75] = 0;
   out_6156434988829804866[76] = 1;
   out_6156434988829804866[77] = 0;
   out_6156434988829804866[78] = 0;
   out_6156434988829804866[79] = 0;
   out_6156434988829804866[80] = 0;
   out_6156434988829804866[81] = 0;
   out_6156434988829804866[82] = 0;
   out_6156434988829804866[83] = 0;
   out_6156434988829804866[84] = 0;
   out_6156434988829804866[85] = dt;
   out_6156434988829804866[86] = 0;
   out_6156434988829804866[87] = 0;
   out_6156434988829804866[88] = 0;
   out_6156434988829804866[89] = 0;
   out_6156434988829804866[90] = 0;
   out_6156434988829804866[91] = 0;
   out_6156434988829804866[92] = 0;
   out_6156434988829804866[93] = 0;
   out_6156434988829804866[94] = 0;
   out_6156434988829804866[95] = 1;
   out_6156434988829804866[96] = 0;
   out_6156434988829804866[97] = 0;
   out_6156434988829804866[98] = 0;
   out_6156434988829804866[99] = 0;
   out_6156434988829804866[100] = 0;
   out_6156434988829804866[101] = 0;
   out_6156434988829804866[102] = 0;
   out_6156434988829804866[103] = 0;
   out_6156434988829804866[104] = dt;
   out_6156434988829804866[105] = 0;
   out_6156434988829804866[106] = 0;
   out_6156434988829804866[107] = 0;
   out_6156434988829804866[108] = 0;
   out_6156434988829804866[109] = 0;
   out_6156434988829804866[110] = 0;
   out_6156434988829804866[111] = 0;
   out_6156434988829804866[112] = 0;
   out_6156434988829804866[113] = 0;
   out_6156434988829804866[114] = 1;
   out_6156434988829804866[115] = 0;
   out_6156434988829804866[116] = 0;
   out_6156434988829804866[117] = 0;
   out_6156434988829804866[118] = 0;
   out_6156434988829804866[119] = 0;
   out_6156434988829804866[120] = 0;
   out_6156434988829804866[121] = 0;
   out_6156434988829804866[122] = 0;
   out_6156434988829804866[123] = 0;
   out_6156434988829804866[124] = 0;
   out_6156434988829804866[125] = 0;
   out_6156434988829804866[126] = 0;
   out_6156434988829804866[127] = 0;
   out_6156434988829804866[128] = 0;
   out_6156434988829804866[129] = 0;
   out_6156434988829804866[130] = 0;
   out_6156434988829804866[131] = 0;
   out_6156434988829804866[132] = 0;
   out_6156434988829804866[133] = 1;
   out_6156434988829804866[134] = 0;
   out_6156434988829804866[135] = 0;
   out_6156434988829804866[136] = 0;
   out_6156434988829804866[137] = 0;
   out_6156434988829804866[138] = 0;
   out_6156434988829804866[139] = 0;
   out_6156434988829804866[140] = 0;
   out_6156434988829804866[141] = 0;
   out_6156434988829804866[142] = 0;
   out_6156434988829804866[143] = 0;
   out_6156434988829804866[144] = 0;
   out_6156434988829804866[145] = 0;
   out_6156434988829804866[146] = 0;
   out_6156434988829804866[147] = 0;
   out_6156434988829804866[148] = 0;
   out_6156434988829804866[149] = 0;
   out_6156434988829804866[150] = 0;
   out_6156434988829804866[151] = 0;
   out_6156434988829804866[152] = 1;
   out_6156434988829804866[153] = 0;
   out_6156434988829804866[154] = 0;
   out_6156434988829804866[155] = 0;
   out_6156434988829804866[156] = 0;
   out_6156434988829804866[157] = 0;
   out_6156434988829804866[158] = 0;
   out_6156434988829804866[159] = 0;
   out_6156434988829804866[160] = 0;
   out_6156434988829804866[161] = 0;
   out_6156434988829804866[162] = 0;
   out_6156434988829804866[163] = 0;
   out_6156434988829804866[164] = 0;
   out_6156434988829804866[165] = 0;
   out_6156434988829804866[166] = 0;
   out_6156434988829804866[167] = 0;
   out_6156434988829804866[168] = 0;
   out_6156434988829804866[169] = 0;
   out_6156434988829804866[170] = 0;
   out_6156434988829804866[171] = 1;
   out_6156434988829804866[172] = 0;
   out_6156434988829804866[173] = 0;
   out_6156434988829804866[174] = 0;
   out_6156434988829804866[175] = 0;
   out_6156434988829804866[176] = 0;
   out_6156434988829804866[177] = 0;
   out_6156434988829804866[178] = 0;
   out_6156434988829804866[179] = 0;
   out_6156434988829804866[180] = 0;
   out_6156434988829804866[181] = 0;
   out_6156434988829804866[182] = 0;
   out_6156434988829804866[183] = 0;
   out_6156434988829804866[184] = 0;
   out_6156434988829804866[185] = 0;
   out_6156434988829804866[186] = 0;
   out_6156434988829804866[187] = 0;
   out_6156434988829804866[188] = 0;
   out_6156434988829804866[189] = 0;
   out_6156434988829804866[190] = 1;
   out_6156434988829804866[191] = 0;
   out_6156434988829804866[192] = 0;
   out_6156434988829804866[193] = 0;
   out_6156434988829804866[194] = 0;
   out_6156434988829804866[195] = 0;
   out_6156434988829804866[196] = 0;
   out_6156434988829804866[197] = 0;
   out_6156434988829804866[198] = 0;
   out_6156434988829804866[199] = 0;
   out_6156434988829804866[200] = 0;
   out_6156434988829804866[201] = 0;
   out_6156434988829804866[202] = 0;
   out_6156434988829804866[203] = 0;
   out_6156434988829804866[204] = 0;
   out_6156434988829804866[205] = 0;
   out_6156434988829804866[206] = 0;
   out_6156434988829804866[207] = 0;
   out_6156434988829804866[208] = 0;
   out_6156434988829804866[209] = 1;
   out_6156434988829804866[210] = 0;
   out_6156434988829804866[211] = 0;
   out_6156434988829804866[212] = 0;
   out_6156434988829804866[213] = 0;
   out_6156434988829804866[214] = 0;
   out_6156434988829804866[215] = 0;
   out_6156434988829804866[216] = 0;
   out_6156434988829804866[217] = 0;
   out_6156434988829804866[218] = 0;
   out_6156434988829804866[219] = 0;
   out_6156434988829804866[220] = 0;
   out_6156434988829804866[221] = 0;
   out_6156434988829804866[222] = 0;
   out_6156434988829804866[223] = 0;
   out_6156434988829804866[224] = 0;
   out_6156434988829804866[225] = 0;
   out_6156434988829804866[226] = 0;
   out_6156434988829804866[227] = 0;
   out_6156434988829804866[228] = 1;
   out_6156434988829804866[229] = 0;
   out_6156434988829804866[230] = 0;
   out_6156434988829804866[231] = 0;
   out_6156434988829804866[232] = 0;
   out_6156434988829804866[233] = 0;
   out_6156434988829804866[234] = 0;
   out_6156434988829804866[235] = 0;
   out_6156434988829804866[236] = 0;
   out_6156434988829804866[237] = 0;
   out_6156434988829804866[238] = 0;
   out_6156434988829804866[239] = 0;
   out_6156434988829804866[240] = 0;
   out_6156434988829804866[241] = 0;
   out_6156434988829804866[242] = 0;
   out_6156434988829804866[243] = 0;
   out_6156434988829804866[244] = 0;
   out_6156434988829804866[245] = 0;
   out_6156434988829804866[246] = 0;
   out_6156434988829804866[247] = 1;
   out_6156434988829804866[248] = 0;
   out_6156434988829804866[249] = 0;
   out_6156434988829804866[250] = 0;
   out_6156434988829804866[251] = 0;
   out_6156434988829804866[252] = 0;
   out_6156434988829804866[253] = 0;
   out_6156434988829804866[254] = 0;
   out_6156434988829804866[255] = 0;
   out_6156434988829804866[256] = 0;
   out_6156434988829804866[257] = 0;
   out_6156434988829804866[258] = 0;
   out_6156434988829804866[259] = 0;
   out_6156434988829804866[260] = 0;
   out_6156434988829804866[261] = 0;
   out_6156434988829804866[262] = 0;
   out_6156434988829804866[263] = 0;
   out_6156434988829804866[264] = 0;
   out_6156434988829804866[265] = 0;
   out_6156434988829804866[266] = 1;
   out_6156434988829804866[267] = 0;
   out_6156434988829804866[268] = 0;
   out_6156434988829804866[269] = 0;
   out_6156434988829804866[270] = 0;
   out_6156434988829804866[271] = 0;
   out_6156434988829804866[272] = 0;
   out_6156434988829804866[273] = 0;
   out_6156434988829804866[274] = 0;
   out_6156434988829804866[275] = 0;
   out_6156434988829804866[276] = 0;
   out_6156434988829804866[277] = 0;
   out_6156434988829804866[278] = 0;
   out_6156434988829804866[279] = 0;
   out_6156434988829804866[280] = 0;
   out_6156434988829804866[281] = 0;
   out_6156434988829804866[282] = 0;
   out_6156434988829804866[283] = 0;
   out_6156434988829804866[284] = 0;
   out_6156434988829804866[285] = 1;
   out_6156434988829804866[286] = 0;
   out_6156434988829804866[287] = 0;
   out_6156434988829804866[288] = 0;
   out_6156434988829804866[289] = 0;
   out_6156434988829804866[290] = 0;
   out_6156434988829804866[291] = 0;
   out_6156434988829804866[292] = 0;
   out_6156434988829804866[293] = 0;
   out_6156434988829804866[294] = 0;
   out_6156434988829804866[295] = 0;
   out_6156434988829804866[296] = 0;
   out_6156434988829804866[297] = 0;
   out_6156434988829804866[298] = 0;
   out_6156434988829804866[299] = 0;
   out_6156434988829804866[300] = 0;
   out_6156434988829804866[301] = 0;
   out_6156434988829804866[302] = 0;
   out_6156434988829804866[303] = 0;
   out_6156434988829804866[304] = 1;
   out_6156434988829804866[305] = 0;
   out_6156434988829804866[306] = 0;
   out_6156434988829804866[307] = 0;
   out_6156434988829804866[308] = 0;
   out_6156434988829804866[309] = 0;
   out_6156434988829804866[310] = 0;
   out_6156434988829804866[311] = 0;
   out_6156434988829804866[312] = 0;
   out_6156434988829804866[313] = 0;
   out_6156434988829804866[314] = 0;
   out_6156434988829804866[315] = 0;
   out_6156434988829804866[316] = 0;
   out_6156434988829804866[317] = 0;
   out_6156434988829804866[318] = 0;
   out_6156434988829804866[319] = 0;
   out_6156434988829804866[320] = 0;
   out_6156434988829804866[321] = 0;
   out_6156434988829804866[322] = 0;
   out_6156434988829804866[323] = 1;
}
void h_4(double *state, double *unused, double *out_3850105333082396155) {
   out_3850105333082396155[0] = state[6] + state[9];
   out_3850105333082396155[1] = state[7] + state[10];
   out_3850105333082396155[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8784638092414987960) {
   out_8784638092414987960[0] = 0;
   out_8784638092414987960[1] = 0;
   out_8784638092414987960[2] = 0;
   out_8784638092414987960[3] = 0;
   out_8784638092414987960[4] = 0;
   out_8784638092414987960[5] = 0;
   out_8784638092414987960[6] = 1;
   out_8784638092414987960[7] = 0;
   out_8784638092414987960[8] = 0;
   out_8784638092414987960[9] = 1;
   out_8784638092414987960[10] = 0;
   out_8784638092414987960[11] = 0;
   out_8784638092414987960[12] = 0;
   out_8784638092414987960[13] = 0;
   out_8784638092414987960[14] = 0;
   out_8784638092414987960[15] = 0;
   out_8784638092414987960[16] = 0;
   out_8784638092414987960[17] = 0;
   out_8784638092414987960[18] = 0;
   out_8784638092414987960[19] = 0;
   out_8784638092414987960[20] = 0;
   out_8784638092414987960[21] = 0;
   out_8784638092414987960[22] = 0;
   out_8784638092414987960[23] = 0;
   out_8784638092414987960[24] = 0;
   out_8784638092414987960[25] = 1;
   out_8784638092414987960[26] = 0;
   out_8784638092414987960[27] = 0;
   out_8784638092414987960[28] = 1;
   out_8784638092414987960[29] = 0;
   out_8784638092414987960[30] = 0;
   out_8784638092414987960[31] = 0;
   out_8784638092414987960[32] = 0;
   out_8784638092414987960[33] = 0;
   out_8784638092414987960[34] = 0;
   out_8784638092414987960[35] = 0;
   out_8784638092414987960[36] = 0;
   out_8784638092414987960[37] = 0;
   out_8784638092414987960[38] = 0;
   out_8784638092414987960[39] = 0;
   out_8784638092414987960[40] = 0;
   out_8784638092414987960[41] = 0;
   out_8784638092414987960[42] = 0;
   out_8784638092414987960[43] = 0;
   out_8784638092414987960[44] = 1;
   out_8784638092414987960[45] = 0;
   out_8784638092414987960[46] = 0;
   out_8784638092414987960[47] = 1;
   out_8784638092414987960[48] = 0;
   out_8784638092414987960[49] = 0;
   out_8784638092414987960[50] = 0;
   out_8784638092414987960[51] = 0;
   out_8784638092414987960[52] = 0;
   out_8784638092414987960[53] = 0;
}
void h_10(double *state, double *unused, double *out_5130122425703055042) {
   out_5130122425703055042[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5130122425703055042[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5130122425703055042[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3246782689811755505) {
   out_3246782689811755505[0] = 0;
   out_3246782689811755505[1] = 9.8100000000000005*cos(state[1]);
   out_3246782689811755505[2] = 0;
   out_3246782689811755505[3] = 0;
   out_3246782689811755505[4] = -state[8];
   out_3246782689811755505[5] = state[7];
   out_3246782689811755505[6] = 0;
   out_3246782689811755505[7] = state[5];
   out_3246782689811755505[8] = -state[4];
   out_3246782689811755505[9] = 0;
   out_3246782689811755505[10] = 0;
   out_3246782689811755505[11] = 0;
   out_3246782689811755505[12] = 1;
   out_3246782689811755505[13] = 0;
   out_3246782689811755505[14] = 0;
   out_3246782689811755505[15] = 1;
   out_3246782689811755505[16] = 0;
   out_3246782689811755505[17] = 0;
   out_3246782689811755505[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3246782689811755505[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3246782689811755505[20] = 0;
   out_3246782689811755505[21] = state[8];
   out_3246782689811755505[22] = 0;
   out_3246782689811755505[23] = -state[6];
   out_3246782689811755505[24] = -state[5];
   out_3246782689811755505[25] = 0;
   out_3246782689811755505[26] = state[3];
   out_3246782689811755505[27] = 0;
   out_3246782689811755505[28] = 0;
   out_3246782689811755505[29] = 0;
   out_3246782689811755505[30] = 0;
   out_3246782689811755505[31] = 1;
   out_3246782689811755505[32] = 0;
   out_3246782689811755505[33] = 0;
   out_3246782689811755505[34] = 1;
   out_3246782689811755505[35] = 0;
   out_3246782689811755505[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3246782689811755505[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3246782689811755505[38] = 0;
   out_3246782689811755505[39] = -state[7];
   out_3246782689811755505[40] = state[6];
   out_3246782689811755505[41] = 0;
   out_3246782689811755505[42] = state[4];
   out_3246782689811755505[43] = -state[3];
   out_3246782689811755505[44] = 0;
   out_3246782689811755505[45] = 0;
   out_3246782689811755505[46] = 0;
   out_3246782689811755505[47] = 0;
   out_3246782689811755505[48] = 0;
   out_3246782689811755505[49] = 0;
   out_3246782689811755505[50] = 1;
   out_3246782689811755505[51] = 0;
   out_3246782689811755505[52] = 0;
   out_3246782689811755505[53] = 1;
}
void h_13(double *state, double *unused, double *out_4607070015010854051) {
   out_4607070015010854051[0] = state[3];
   out_4607070015010854051[1] = state[4];
   out_4607070015010854051[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6449832155962230855) {
   out_6449832155962230855[0] = 0;
   out_6449832155962230855[1] = 0;
   out_6449832155962230855[2] = 0;
   out_6449832155962230855[3] = 1;
   out_6449832155962230855[4] = 0;
   out_6449832155962230855[5] = 0;
   out_6449832155962230855[6] = 0;
   out_6449832155962230855[7] = 0;
   out_6449832155962230855[8] = 0;
   out_6449832155962230855[9] = 0;
   out_6449832155962230855[10] = 0;
   out_6449832155962230855[11] = 0;
   out_6449832155962230855[12] = 0;
   out_6449832155962230855[13] = 0;
   out_6449832155962230855[14] = 0;
   out_6449832155962230855[15] = 0;
   out_6449832155962230855[16] = 0;
   out_6449832155962230855[17] = 0;
   out_6449832155962230855[18] = 0;
   out_6449832155962230855[19] = 0;
   out_6449832155962230855[20] = 0;
   out_6449832155962230855[21] = 0;
   out_6449832155962230855[22] = 1;
   out_6449832155962230855[23] = 0;
   out_6449832155962230855[24] = 0;
   out_6449832155962230855[25] = 0;
   out_6449832155962230855[26] = 0;
   out_6449832155962230855[27] = 0;
   out_6449832155962230855[28] = 0;
   out_6449832155962230855[29] = 0;
   out_6449832155962230855[30] = 0;
   out_6449832155962230855[31] = 0;
   out_6449832155962230855[32] = 0;
   out_6449832155962230855[33] = 0;
   out_6449832155962230855[34] = 0;
   out_6449832155962230855[35] = 0;
   out_6449832155962230855[36] = 0;
   out_6449832155962230855[37] = 0;
   out_6449832155962230855[38] = 0;
   out_6449832155962230855[39] = 0;
   out_6449832155962230855[40] = 0;
   out_6449832155962230855[41] = 1;
   out_6449832155962230855[42] = 0;
   out_6449832155962230855[43] = 0;
   out_6449832155962230855[44] = 0;
   out_6449832155962230855[45] = 0;
   out_6449832155962230855[46] = 0;
   out_6449832155962230855[47] = 0;
   out_6449832155962230855[48] = 0;
   out_6449832155962230855[49] = 0;
   out_6449832155962230855[50] = 0;
   out_6449832155962230855[51] = 0;
   out_6449832155962230855[52] = 0;
   out_6449832155962230855[53] = 0;
}
void h_14(double *state, double *unused, double *out_3610332955332281780) {
   out_3610332955332281780[0] = state[6];
   out_3610332955332281780[1] = state[7];
   out_3610332955332281780[2] = state[8];
}
void H_14(double *state, double *unused, double *out_5698865124955079127) {
   out_5698865124955079127[0] = 0;
   out_5698865124955079127[1] = 0;
   out_5698865124955079127[2] = 0;
   out_5698865124955079127[3] = 0;
   out_5698865124955079127[4] = 0;
   out_5698865124955079127[5] = 0;
   out_5698865124955079127[6] = 1;
   out_5698865124955079127[7] = 0;
   out_5698865124955079127[8] = 0;
   out_5698865124955079127[9] = 0;
   out_5698865124955079127[10] = 0;
   out_5698865124955079127[11] = 0;
   out_5698865124955079127[12] = 0;
   out_5698865124955079127[13] = 0;
   out_5698865124955079127[14] = 0;
   out_5698865124955079127[15] = 0;
   out_5698865124955079127[16] = 0;
   out_5698865124955079127[17] = 0;
   out_5698865124955079127[18] = 0;
   out_5698865124955079127[19] = 0;
   out_5698865124955079127[20] = 0;
   out_5698865124955079127[21] = 0;
   out_5698865124955079127[22] = 0;
   out_5698865124955079127[23] = 0;
   out_5698865124955079127[24] = 0;
   out_5698865124955079127[25] = 1;
   out_5698865124955079127[26] = 0;
   out_5698865124955079127[27] = 0;
   out_5698865124955079127[28] = 0;
   out_5698865124955079127[29] = 0;
   out_5698865124955079127[30] = 0;
   out_5698865124955079127[31] = 0;
   out_5698865124955079127[32] = 0;
   out_5698865124955079127[33] = 0;
   out_5698865124955079127[34] = 0;
   out_5698865124955079127[35] = 0;
   out_5698865124955079127[36] = 0;
   out_5698865124955079127[37] = 0;
   out_5698865124955079127[38] = 0;
   out_5698865124955079127[39] = 0;
   out_5698865124955079127[40] = 0;
   out_5698865124955079127[41] = 0;
   out_5698865124955079127[42] = 0;
   out_5698865124955079127[43] = 0;
   out_5698865124955079127[44] = 1;
   out_5698865124955079127[45] = 0;
   out_5698865124955079127[46] = 0;
   out_5698865124955079127[47] = 0;
   out_5698865124955079127[48] = 0;
   out_5698865124955079127[49] = 0;
   out_5698865124955079127[50] = 0;
   out_5698865124955079127[51] = 0;
   out_5698865124955079127[52] = 0;
   out_5698865124955079127[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_3844491001847189814) {
  err_fun(nom_x, delta_x, out_3844491001847189814);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2069018563570238764) {
  inv_err_fun(nom_x, true_x, out_2069018563570238764);
}
void pose_H_mod_fun(double *state, double *out_6387883902503614403) {
  H_mod_fun(state, out_6387883902503614403);
}
void pose_f_fun(double *state, double dt, double *out_6400885410956827677) {
  f_fun(state,  dt, out_6400885410956827677);
}
void pose_F_fun(double *state, double dt, double *out_6156434988829804866) {
  F_fun(state,  dt, out_6156434988829804866);
}
void pose_h_4(double *state, double *unused, double *out_3850105333082396155) {
  h_4(state, unused, out_3850105333082396155);
}
void pose_H_4(double *state, double *unused, double *out_8784638092414987960) {
  H_4(state, unused, out_8784638092414987960);
}
void pose_h_10(double *state, double *unused, double *out_5130122425703055042) {
  h_10(state, unused, out_5130122425703055042);
}
void pose_H_10(double *state, double *unused, double *out_3246782689811755505) {
  H_10(state, unused, out_3246782689811755505);
}
void pose_h_13(double *state, double *unused, double *out_4607070015010854051) {
  h_13(state, unused, out_4607070015010854051);
}
void pose_H_13(double *state, double *unused, double *out_6449832155962230855) {
  H_13(state, unused, out_6449832155962230855);
}
void pose_h_14(double *state, double *unused, double *out_3610332955332281780) {
  h_14(state, unused, out_3610332955332281780);
}
void pose_H_14(double *state, double *unused, double *out_5698865124955079127) {
  H_14(state, unused, out_5698865124955079127);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
