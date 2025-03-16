#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0);ios::sync_with_stdio(0);
#define mp make_pair
#define mt make_tuple
#define f first
#define s second

bool lado( vector<double> &reta, pair<double,double> &ponto){ // verificar lado da circunferencia
	return ( ponto.s > (reta[0] * ponto.f + reta[2]) ? true : false);
}

bool veri( vector<double> &reta, pair<double,double> &ponto){ // verificar se atingi algum ponto
	return ( ponto.s == (reta[0] * ponto.f + reta[2]) ? true : false);
}

double distRetaPonto( vector<double> &reta, pair<double,double> &ponto){
	return abs(reta[0] * ponto.f + reta[1] * ponto.s + reta[2] )/sqrt(pow(reta[0],2) + pow(reta[1],2));
}

double coefi( pair<double,double> &p1, pair<double,double> &p2){
	return (p2.s - p1.s)/(p2.f - p1.f);
}

vector<double> reta( pair<double,double> &p1, pair<double,double> &p2){
	double m = coefi(p1,p2);
	vector<double> seq (3, 0);
	seq[0] = m;
	seq[1] = 1;
	seq[2] = p1.s - m * p1.f;
	return seq;
}

int main() {
	_	

	int t;
	while(cin >> t, t != 0){
		
		vector<pair<double,double>> pontos;

		for(int i=0; i < t; i++){
			double x, y;
			cin >> x >> y;
			pontos.push_back(mp(x,y));
		}


		double menor = 99999, tempcima, tempbaixo;
		for(int i=0; i < pontos.size() - 1; i++){
			for(int j = i + 1; j < pontos.size(); j++){
				tempcima = 0; tempbaixo = 0;
				if( pontos[i].f == pontos[j].f){
				 	for(int c =0; c < pontos.size(); c++){
						if(pontos[c].f == pontos[i].f) continue;
						if( pontos[c].f < pontos[i].f){
							tempcima += pontos[i].f - pontos[c].f;
						}else{
							tempbaixo += pontos[c].f - pontos[i].f;
						}
					}
				}else{
					vector<double> linha = reta(pontos[i], pontos[j]);
					for(int c=0; c < pontos.size(); c++){
						if( veri(linha, pontos[c])) continue;
						if( lado( linha, pontos[c]) ){
							tempcima += distRetaPonto(linha, pontos[c]); 
						}else{
							tempbaixo += distRetaPonto(linha, pontos[c]);
						}	
					}
				}
				menor = min(menor, abs(tempcima - tempbaixo));
			}
		}
		cout << fixed << setprecision(3);
		cout << menor << '\n';
	}
	
    return 0;
}

