#include<bits/stdc++.h>

#define mp make_pair
#define f first
#define s second
#define mt make_tuple
const int INF = 1e9;

using namespace std;

struct retangulo{
	pair<double,double> Ecima,Ebaixo,Dcima,Dbaixo;
};

bool maior_cb( retangulo &p1, retangulo &ret ){
	return p1.Ebaixo.f <= ret.Ecima.f && p1.Dbaixo.f >= ret.Dcima.f;
}

bool maior_lo( retangulo &p1, retangulo &ret ){
	return p1.Ecima.s >= ret.Ecima.s && p1.Ebaixo.s <= ret.Ebaixo.s;
}

double distpp(pair<double,double> p1, pair<double,double> p2){
	return sqrt(pow(p2.f-p1.f,2)+pow(p2.s-p1.s,2));
}

bool lado(retangulo &p1, retangulo &ret, int AAH){
	double temp = 0;	
	if( p1.Ebaixo.s > ret.Ecima.s ){
		if( (p1.Dcima.f <= ret.Dcima.f && p1.Ecima.f >= ret.Ecima.f || p1.Ecima.f <= ret.Dcima.f && p1.Dcima.f > ret.Dcima.f || p1.Ecima.f < ret.Ecima.f && p1.Dcima.f >= ret.Ecima.f) || maior_cb(p1,ret) ){
			
			temp = p1.Ebaixo.s - ret.Ecima.s;

		}else{
			//distpp
			if( p1.Dcima.f < ret.Ecima.f){ temp = distpp(p1.Dbaixo, ret.Ecima); }
			else{ temp = distpp(p1.Ebaixo, ret.Dcima);}
		}
	}else if( p1.Ecima.s < ret.Ebaixo.s){

		if( (p1.Dcima.f <= ret.Dcima.f && p1.Ecima.f >= ret.Ecima.f || p1.Ecima.f <= ret.Dcima.f && p1.Dcima.f > ret.Dcima.f || p1.Ecima.f < ret.Ecima.f && p1.Dcima.f >= ret.Ecima.f) || maior_cb(p1,ret) ){
			
			temp = ret.Ebaixo.s - p1.Ecima.s;

		}else{
			//distpp
			if( p1.Dcima.f < ret.Dbaixo.f){ temp = distpp(p1.Dcima, ret.Ebaixo);}
			else{ temp = distpp(p1.Ecima, ret.Dbaixo);}
		}
	}else if( p1.Ecima.f > ret.Dcima.f){
		if( (p1.Ebaixo.s >= ret.Dbaixo.s && p1.Ecima.s <= ret.Dcima.s || p1.Ebaixo.s <= ret.Dcima.s && p1.Ecima.s > ret.Dcima.s || p1.Ecima.s >= ret.Dbaixo.s && p1.Ebaixo.s < ret.Dbaixo.s) || maior_lo(p1,ret)){
			
			temp = p1.Ecima.f - ret.Dcima.f;

		}else{
			//distpp
			if( p1.Dbaixo.s > ret.Ecima.s ){ temp = distpp(p1.Ebaixo, ret.Dcima ); }
			else{ temp = distpp(p1.Ecima, ret.Dbaixo); }
		}
	}else if( p1.Dcima.f < ret.Ecima.f){
		
		if( (p1.Ebaixo.s >= ret.Dbaixo.s && p1.Ecima.s <= ret.Dcima.s || p1.Ebaixo.s <= ret.Dcima.s && p1.Ecima.s > ret.Dcima.s || p1.Ecima.s >= ret.Dbaixo.s && p1.Ebaixo.s < ret.Dbaixo.s) || maior_lo(p1,ret)){
			
			temp = ret.Ecima.f - p1.Dcima.f;

		}else{
			//distpp
			if( p1.Dbaixo.s > ret.Ecima.s ){ temp = distpp( p1.Dbaixo, ret.Ecima );}
			else{ temp = distpp( p1.Dcima, ret.Ebaixo);}
		}
	}
	return ( temp <= AAH ? true : false );
}

bool veri(retangulo &ret, retangulo &p2){
	
}

int main(){
	
	cin.tie(0); ios::sync_with_stdio(0);
	
	int n, AAH;
	cin >> n >> AAH;
	
	retangulo andares[n];

	for(int i=0; i < n; i++){
		double xc,yc,lar;
		cin >> xc >> yc >> lar;
		andares[i].Ecima = mp(xc-lar/2,yc+lar/2);
		andares[i].Ebaixo = mp(xc-lar/2,yc-lar/2);
		andares[i].Dcima = mp(xc+lar/2,yc+lar/2);
		andares[i].Dbaixo = mp(xc+lar/2,yc-lar/2);
	}

	bool fail = false;
	for(int i=0; i < n-1; i++){
		if( !veri(andares[i],andares[i+1])){
			if( !lado( andares[i], andares[i+1], AAH ) ){ 
				fail = true;
				break; 
			}
		}
	}
	
	if( fail ){
		cout << "OUCH\n";	
	}else{
		cout << "YEAH\n";
	}
	
	return 0;	
}
