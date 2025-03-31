#include <bits/stdc++.h>
 using namespace std;
 
 #define _ cin.tie(0);ios::sync_with_stdio(0);
 #define mp make_pair
 #define mt make_tuple
 #define f first
 #define s second
 
bool prod( pair<double,double> p1, pair<double, double> p2 ){
	double produto = p1.f * p2.s - p1.s * p2.f;
	return (produto >= 0 ? true : false );  
}

int main() {
 	_	
 	
 	int pretos,brancos;
 	while(cin >> pretos >> brancos){
 
 		vector<pair<double,double>> pret,branc;
  
 		for(int i=0; i < pretos; i++){
 			double x,y;
 			cin >> x >> y;
     		pret.push_back(mp(x,y));			
 		}
 	
 		for(int i=0; i < brancos; i++){
 			double x,y;
 			cin >> x >> y;
 			branc.push_back(mp(x,y));
 		}
        
 
 		int contador;
		double energia = 0;
 		pair<double,double> ij, jc, ci, ip, jp, cp;
		
		for(int i = 0; i < pret.size() - 2; i++){
 			for(int j = i + 1; j < pret.size() - 1; j++){
 				for(int c = j + 1; c < pret.size(); c++){
					contador = 0;
					ij = mp( pret[j].f - pret[i].f, pret[j].s - pret[i].s);
					jc = mp( pret[c].f - pret[j].f, pret[c].s - pret[j].s);
					ci = mp( pret[i].f - pret[c].f, pret[i].s - pret[c].s);
 					for(int v=0;  v < branc.size(); v++){
						ip = mp( branc[v].f - pret[i].f, branc[v].s - pret[i].s);
						jp = mp( branc[v].f - pret[j].f, branc[v].s - pret[j].s);
						cp = mp( branc[v].f - pret[c].f, branc[v].s - pret[c].s);
 						if( prod(ij, ip) && prod(jc, jp) && prod(ci, cp) ){
							contador++;
						}
 					}
 					energia += pow(contador,2);
 				}
 			}
 		}
 		
 		cout << energia << '\n';
 	}
 	
     return 0;
 }
