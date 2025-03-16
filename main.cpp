#include <bits/stdc++.h>
using namespace std;

#define _ cin.tie(0);ios::sync_with_stdio(0);
#define mp make_pair
#define mt make_tuple
#define f first
#define s second

bool veri(tuple<int,int,int> &p1, tuple<int,int,int> p2){
	return  (get<0>(p1)* get<1>(p2)-(get<1>(p1)* get<0>(p2))) > 0 ? true : false;
}

int main() {
	_	
	
	int pretos,brancos;
	while(cin >> pretos >> brancos){

		vector<pair<int,int>> pret,branc;

		for(int i=0; i < pretos; i++){
			int x,y;
			cin >> x >> y;	
			pret.push_back(mp(x,y));
		}
	
		for(int i=0; i < brancos; i++){
			int x,y;
			cin >> x >> y;
			branc.push_back(mp(x,y));
		}

		tuple<int,int,int> vet[3];
		tuple<int,int,int> vet2[3];

		int contador;
		double energia = 0;
		for(int i = 0; i < pret.size() - 2; i++){
			for(int j = i + 1; j < pret.size() - 1; j++){
				for(int c = j + 1; c < pret.size(); c++){
					vet[0] = mt(pret[j].f-pret[i].f,pret[j].s-pret[i].s,0);
					vet[1] = mt(pret[c].f-pret[j].f,pret[c].s-pret[j].s,0);
					vet[2] = mt(pret[i].f-pret[c].f,pret[i].s-pret[c].s,0);
					contador = 0;
					for(int v=0;  v < branc.size(); v++){
						vet2[0] = mt(branc[v].f-pret[i].f,branc[v].s-pret[i].s,0);
						vet2[1] = mt(branc[v].f-pret[j].f,branc[v].s-pret[j].s,0);
						vet2[2] = mt(branc[v].f-pret[c].f,branc[v].s-pret[c].s,0);
						if(veri(vet2[0],vet[0]) == veri(vet2[1],vet[1]) && 
							veri(vet2[0],vet[0]) == veri(vet2[2],vet[2])){
							contador++;
						}
					}
					energia += pow(contador,2);
					memset(vet,-1,sizeof(vet));
					memset(vet2,-1,sizeof(vet2));
				}
			}
		}

		cout << energia << '\n';
	}
	
    return 0;
}

