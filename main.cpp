#include <bits/stdc++.h>

using namespace std;

#define _ cin.tie(0);ios::sync_with_stdio(0);
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
const int MAX = 1e9;

double distreta( tuple<double,double,double> reta, pair<double,double> p3){

	return abs(get<0>(reta) * p3.f + get<1>(reta) * p3.s + get<2>(reta));
}

double produto_vetorial( tuple<double,double,double> p1, tuple<double,double,double> p2){
	
	return get<0>(p1) * get<1>(p2) - get<1>(p1) * get<0>(p2);
	
}

int main(){
	_
	
	int n;
	while(cin >> n, n!=0){
		
		vector<pair<double,double>> pontos;

		for(int i=0; i < n; i++){
			double x, y;
			cin >> x >> y;
			pontos.push_back(mp(x,y));
		}

		
		tuple<double,double,double> v, u, reta;
		double menor = 1e9;
		double esquerda, direita, temp, raiz;
		for(int i=0; i < pontos.size() - 1; i++){
			for(int j = i + 1; j < pontos.size(); j++){
				v = mt(pontos[j].f - pontos[i].f, pontos[j].s - pontos[i].s,0);
				esquerda = 0; direita = 0;
	
				get<0>(reta) = -( pontos[j].s - pontos[i].s );
				get<1>(reta) = pontos[j].f - pontos[i].f;
				get<2>(reta) = -( get<1>(reta) * pontos[j].s + get<0>(reta) * pontos[j].f);
				raiz = sqrt(pow(get<0>(reta),2) + pow(get<1>(reta),2));

				for(int c=0; c < pontos.size(); c++){
					if( c == i || c == j ) continue;
					u = mt(pontos[c].f - pontos[i].f, pontos[c].s - pontos[i].s, 0 );
					temp = produto_vetorial(v,u);

					if( temp > 0 ){
						esquerda += distreta( reta , pontos[c] )/raiz ;
					}else if( temp < 0){
						direita += distreta( reta, pontos[c] )/raiz ;
					}
				}
				if( esquerda != 0 || direita != 0 ){
					menor = min(menor, fabs(direita - esquerda));
				}
			}
		}
		cout << fixed << setprecision(3);
		cout << ( menor == 1e9 ? 0 : menor ) << '\n';

	}
	
	
	return 0;
}
