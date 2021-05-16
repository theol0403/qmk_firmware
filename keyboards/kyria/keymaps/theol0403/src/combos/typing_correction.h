#define BEGIN_BIGRAMS combo_bi_th
// SUBS(bi_th, "th", U_T, U_H)
// SUBS(bi_he, "he", U_H, T_L2)
// SUBS(bi_in, "in", U_I, U_N)
// SUBS(bi_er, "er", T_L2, KC_R)
// SUBS(bi_an, "an", U_A, U_N)
// SUBS(bi_on, "on", U_O, U_N)
// SUBS(bi_at, "at", U_A, U_T)
// SUBS(bi_en, "en", T_L2, U_N)
// SUBS(bi_nd, "nd", U_N, KC_D)
// SUBS(bi_es, "es", T_L2, U_S)
// SUBS(bi_or, "or", U_O, KC_R)
// SUBS(bi_te, "te", U_T, T_L2)
// SUBS(bi_of, "of", U_O, KC_F)
// SUBS(bi_ed, "ed", T_L2, KC_D)
// SUBS(bi_is, "is", U_I, U_S)
// SUBS(bi_al, "al", U_A, KC_L)
// SUBS(bi_ar, "ar", U_A, KC_R)
// SUBS(bi_st, "st", U_S, U_T)
// SUBS(bi_to, "to", U_T, U_O)
// SUBS(bi_nt, "nt", U_N, U_T)
// SUBS(bi_ng, "ng", U_N, KC_G)
// SUBS(bi_ha, "ha", U_H, U_A)
// SUBS(bi_as, "as", U_A, U_S)
// SUBS(bi_io, "io", U_I, U_O)
// SUBS(bi_le, "le", KC_L, T_L2)
// SUBS(bi_ve, "ve", KC_V, T_L2)
// SUBS(bi_co, "co", KC_C, U_O)
// SUBS(bi_me, "me", KC_M, T_L2)
// SUBS(bi_ea, "ea", T_L2, U_A)
// SUBS(bi_ch, "ch", KC_C, U_H)
// SUBS(bi_do, "do", KC_D, U_O)
// SUBS(bi_us, "us", KC_U, U_S)
// SUBS(bi_we, "we", KC_W, T_L2)
// SUBS(bi_up, "up", KC_U, KC_P)
// SUBS(bi_if, "if", U_I, KC_F)
#define END_BIGRAMS combo_bi_th

#define BEGIN_TRIGRAMS combo_tri_the
SUBS(tri_the, "the", U_T, U_H, T_L2)
// SUBS(tri_and, "and", U_A, U_N, KC_D)
// SUBS(tri_ing, "ing", U_I, U_N, KC_G)
SUBS(tri_ion, "ion", U_I, U_O, U_N)
// SUBS(tri_tio, "tio", U_T, U_I, U_O)
// SUBS(tri_ent, "ent", T_L2, U_N, U_T)
// SUBS(tri_ati, "ati", U_A, U_T, U_I)
// SUBS(tri_for, "for", KC_F, U_O, KC_R)
// SUBS(tri_her, "her", U_H, T_L2, KC_R)
// SUBS(tri_ter, "ter", U_T, T_L2, KC_R)
// SUBS(tri_hat, "hat", U_H, U_A, U_T)
// SUBS(tri_tha, "tha", U_T, U_H, U_A)
// SUBS(tri_ate, "ate", U_A, U_T, T_L2)
// SUBS(tri_his, "his", U_H, U_I, U_S)
// SUBS(tri_con, "con", KC_C, U_O, U_N)
// SUBS(tri_res, "res", KC_R, T_L2, U_S)
// SUBS(tri_ver, "ver", KC_V, T_L2, KC_R)
// SUBS(tri_ons, "ons", U_O, U_N, U_S)
// SUBS(tri_nce, "nce", U_N, KC_C, T_L2)
// SUBS(tri_men, "men", KC_M, T_L2, U_N)
// SUBS(tri_ith, "ith", U_I, U_T, U_H)
// SUBS(tri_ted, "ted", U_T, T_L2, KC_D)
// SUBS(tri_ers, "ers", T_L2, KC_R, U_S)
// SUBS(tri_pro, "pro", KC_P, KC_R, U_O)
// SUBS(tri_thi, "thi", U_T, U_H, U_I)
// SUBS(tri_wit, "wit", KC_W, U_I, U_T)
// SUBS(tri_are, "are", U_A, KC_R, T_L2)
// SUBS(tri_not, "not", U_N, U_O, U_T)
// SUBS(tri_ive, "ive", U_I, KC_V, T_L2)
// SUBS(tri_was, "was", KC_W, U_A, U_S)
// SUBS(tri_ect, "ect", T_L2, KC_C, U_T)
// SUBS(tri_com, "com", KC_C, U_O, KC_M)
// SUBS(tri_int, "int", U_I, U_N, U_T)
// SUBS(tri_one, "one", U_O, U_N, T_L2)
// SUBS(tri_you, "you", U_Y, U_O, KC_U)
// SUBS(ng_ions, "ions", U_I, U_O, U_N, U_S)
// SUBS(ng_tion, "tion", U_T, U_I, U_O, U_N)
#define END_TRIGRAMS combo_tri_ion
