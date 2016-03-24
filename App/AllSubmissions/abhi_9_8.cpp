// CERC 2012
// Problem C: Chemist's vows
// O(n) solution
// Author: Lech Duraj

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string E[114] = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Fl","Lv","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"};


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
    bool A[s.length()+1];
    A[0] = true;
    int r = s.length();
    for(int i=1; i<=r; i++)
    {
      A[i] = false;
      for(int q=0; q<114; q++)
      {
        int k = E[q].length();
        A[i] |= i>=k && A[i-k] && s.substr(i-k,k) == E[q];
      }
    }
    cout << (A[s.length()] ? "YES\n" : "NO\n");
  }
}
