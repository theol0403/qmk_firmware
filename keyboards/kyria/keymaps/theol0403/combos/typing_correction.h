#define BEGIN_CORRECTIVE_BIGRAMS combo_bi_th
SUBS(bi_th, "th", HM_T, HM_H)
SUBS(bi_he, "he", HM_H, THMB_L2)
SUBS(bi_in, "in", HM_I, HM_N)
SUBS(bi_er, "er", THMB_L2, KC_R)
SUBS(bi_an, "an", HM_A, HM_N)
SUBS(bi_on, "on", HM_O, HM_N)
SUBS(bi_at, "at", HM_A, HM_T)
SUBS(bi_en, "en", THMB_L2, HM_N)
SUBS(bi_nd, "nd", HM_N, KC_D)
SUBS(bi_es, "es", THMB_L2, HM_S)
SUBS(bi_or, "or", HM_O, KC_R)
SUBS(bi_te, "te", HM_T, THMB_L2)
SUBS(bi_of, "of", HM_O, KC_F)
SUBS(bi_ed, "ed", THMB_L2, KC_D)
SUBS(bi_is, "is", HM_I, HM_S)
// SUBS(bi_al, "al", HM_A, KC_L)
SUBS(bi_ar, "ar", HM_A, KC_R)
SUBS(bi_st, "st", HM_S, HM_T)
SUBS(bi_to, "to", HM_T, HM_O)
SUBS(bi_nt, "nt", HM_N, HM_T)
SUBS(bi_ng, "ng", HM_N, KC_G)
SUBS(bi_ha, "ha", HM_H, HM_A)
SUBS(bi_as, "as", HM_A, HM_S)
SUBS(bi_io, "io", HM_I, HM_O)
// SUBS(bi_le, "le", KC_L, THMB_L2)
SUBS(bi_ve, "ve", KC_V, THMB_L2)
SUBS(bi_co, "co", KC_C, HM_O)
SUBS(bi_me, "me", KC_M, THMB_L2)
SUBS(bi_ea, "ea", THMB_L2, HM_A)
SUBS(bi_ch, "ch", KC_C, HM_H)
SUBS(bi_do, "do", KC_D, HM_O)
SUBS(bi_us, "us", KC_U, HM_S)
SUBS(bi_we, "we", KC_W, THMB_L2)
SUBS(bi_up, "up", KC_U, KC_P)
// SUBS(bi_if, "if", HM_I, KC_F)
#define END_CORRECTIVE_BIGRAMS combo_bi_up

#define BEGIN_TRIGRAMS combo_tri_the
SUBS(tri_the, "the", HM_T, HM_H, THMB_L2)
SUBS(tri_and, "and", HM_A, HM_N, KC_D)
SUBS(tri_ing, "ing", HM_I, HM_N, KC_G)
SUBS(tri_ion, "ion", HM_I, HM_O, HM_N)
SUBS(tri_tio, "tio", HM_T, HM_I, HM_O)
SUBS(tri_ent, "ent", THMB_L2, HM_N, HM_T)
// SUBS(tri_ati, "ati", HM_A, HM_T, HM_I)
SUBS(tri_for, "for", KC_F, HM_O, KC_R)
SUBS(tri_her, "her", HM_H, THMB_L2, KC_R)
SUBS(tri_ter, "ter", HM_T, THMB_L2, KC_R)
SUBS(tri_hat, "hat", HM_H, HM_A, HM_T)
SUBS(tri_tha, "tha", HM_T, HM_H, HM_A)
SUBS(tri_ere, "ere", THMB_L2, KC_R, THMB_L2)
SUBS(tri_ate, "ate", HM_A, HM_T, THMB_L2)
SUBS(tri_his, "his", HM_H, HM_I, HM_S)
SUBS(tri_con, "con", KC_C, HM_O, HM_N)
SUBS(tri_res, "res", KC_R, THMB_L2, HM_S)
SUBS(tri_ver, "ver", KC_V, THMB_L2, KC_R)
SUBS(tri_ons, "ons", HM_O, HM_N, HM_S)
SUBS(tri_nce, "nce", HM_N, KC_C, THMB_L2)
SUBS(tri_men, "men", KC_M, THMB_L2, HM_N)
// SUBS(tri_ith, "ith", HM_I, HM_T, HM_H)
// SUBS(tri_ted, "ted", HM_T, THMB_L2, KC_D)
SUBS(tri_ers, "ers", THMB_L2, KC_R, HM_S)
SUBS(tri_pro, "pro", KC_P, KC_R, HM_O)
SUBS(tri_thi, "thi", HM_T, HM_H, HM_I)
SUBS(tri_wit, "wit", KC_W, HM_I, HM_T)
SUBS(tri_are, "are", HM_A, KC_R, THMB_L2)
SUBS(tri_not, "not", HM_N, HM_O, HM_T)
SUBS(tri_ive, "ive", HM_I, KC_V, THMB_L2)
SUBS(tri_was, "was", KC_W, HM_A, HM_S)
// SUBS(tri_ect, "ect", THMB_L2, KC_C, HM_T)
// SUBS(tri_com, "com", KC_C, HM_O, KC_M)
SUBS(tri_int, "int", HM_I, HM_N, HM_T)
SUBS(tri_one, "one", HM_O, HM_N, THMB_L2)
SUBS(tri_you, "you", HM_Y, HM_O, KC_U)
SUBS(ng_ions, "ions", HM_I, HM_O, HM_N, HM_S)
SUBS(ng_tion, "tion", HM_T, HM_I, HM_O, HM_N)
#define END_TRIGRAMS combo_ng_tion
