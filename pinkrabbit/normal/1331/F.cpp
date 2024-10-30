#include <cstdio>
#include <cstring>

char table[118][5] = {
"Ac",
"Al",
"Am",
"Sb",
"Ar",
"As",
"At",
"Ba",
"Bk",
"Be",
"Bi",
"B",
"Br",
"Cd",
"Ca",
"Cf",
"C",
"Ce",
"Cs",
"Cl",
"Cr",
"Co",
"Cu",
"Cm",
"Dy",
"Es",
"Rf",
"Db",
"Er",
"Eu",
"Fm",
"F",
"Fr",
"Gd",
"Ga",
"Ge",
"Au",
"Hf",
"He",
"Ho",
"H",
"In",
"I",
"Ir",
"Fe",
"Kr",
"La",
"Lr",
"Pb",
"Li",
"Lu",
"Mg",
"Mn",
"Md",
"Hg",
"Mo",
"Nd",
"Ne",
"Np",
"Ni",
"Nb",
"N",
"No",
"Os",
"O",
"Pd",
"P",
"Pt",
"Pu",
"Po",
"K",
"Pr",
"Pm",
"Pa",
"Ra",
"Rn",
"Re",
"Rh",
"Rb",
"Ru",
"Sm",
"Sc",
"Se",
"Si",
"Ag",
"Na",
"Sr",
"S",
"Ta",
"Tc",
"Te",
"Tb",
"Tl",
"Th",
"Tm",
"Sn",
"Ti",
"W",
"U",
"V",
"Xe",
"Yb",
"Y",
"Zn",
"Zr",
"Sg",
"Bh",
"Hs",
"Mt",
"Ds",
"Rg",
"Cn",
"Nh",
"Fl",
"Mc",
"Lv",
"Ts",
"Og"};

char str[55];
int N, f[55];

int main() {
	scanf("%s", str + 1);
	N = strlen(str + 1);
	f[0] = 1;
	for (int i = 1; i <= N; ++i) {
		f[i] = 0;
		for (int j = 0; j < 118; ++j) {
			int len = strlen(table[j]);
			if (len == 1 && str[i] == table[j][0] && f[i - 1]) f[i] = 1;
			if (len == 2 && i >= 2 && str[i] == table[j][1] - 'a' + 'A' && str[i - 1] == table[j][0] && f[i - 2]) f[i] = 1;
		}
	}
	printf(f[N] ? "YES" : "NO");
	return 0;
}