// CERC 2012
// Problem C: Chemist's vows
// EXPTIME backtrack
// Author: Lech Duraj

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string E[114] = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Fl","Lv","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"};

bool go(string &s, int k)
{
  if (k==s.length())
    return true;
  for(int i=0; i<114; i++)
    if (s.substr(k,E[i].length())==E[i] && go(s,k+E[i].length()))
      return true;
  return false;
}

int main()
{
  int TT;
  for(int i=0; i<114; i++)
    transform(E[i].begin(), E[i].end(), E[i].begin(), ::tolower); // fajne, nie?
  cin >> TT;
  while(TT--)
  {
    string s;
    cin >> s;
    cout << (go(s,0) ? "YES\n" : "NO\n");
  }
}
