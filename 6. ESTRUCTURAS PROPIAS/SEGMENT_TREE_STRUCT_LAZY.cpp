#include <bits/stdc++.h>
using namespace std;

struct STreeLazy{
	STreeLazy *left,*right;
	int l,r,m,sum,lazy,stat;

	STreeLazy(int l, int r) : l(l),r(r),sum(0),lazy(0),stat(0){
		if(l!=r){
			m = (l+r)/2;
			left = new STreeLazy(l,m);
			right = new STreeLazy(m+1,r);
		}
	}
	void propagation(){
		sum = lazy*(r-l+1);
		if(l!=r){
			if(left->stat==0)left -> lazy = lazy; left -> stat = 0;
			if(right->stat==0)right -> lazy = lazy; right -> stat = 0;
		}	
		stat = 1;
	}
	void update(int a, int b, int val){
		propagation();
		if(a>r || b<l) return ;
		if(a<=l && r<=b){
			lazy = val;
			propagation();
			return ;
		}
		left->update(a,b,val);
		right->update(a,b,val);
		sum = left->sum + right->sum;
	}
	int query(int a, int b){
		propagation();
		if(a>r || b<l) return 0;
		if(a<=l && r<=b) return sum;
		return left->query(a,b)+right->query(a,b);
	}
};

int main(){
	int n,x;
	cin >> n;
	STreeLazy st(0,n-1);
	for(int i = 0 ; i< n; i++) {
		cin >>x;
		st.update(i,i,x);
	}
		cout << st.query(0,n-1)<<" ";
	for(int i = 0;i<n;i++){
	}
	cout <<endl;
	return 0 ;
}