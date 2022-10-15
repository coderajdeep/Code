#include<iostream>
#include<set>
using namespace std;

struct Info {
	int id;
	int value;
	Info() {
		id = 0;
		value = 0;
	}
} pool[20];

struct COMP {
	bool operator()(const int i, const int j) {
		if(pool[i].value == pool[j].value) return pool[i].id < pool[j].id;
		return pool[i].value < pool[j].value;
	}
};

set<int, COMP> infos;


void set_operations() {
	int in = 1;
	for(int i=40; i>=10; i-=10) {
		for(int j=0; j<=15; j+=5) {

			pool[in].value = i;
			pool[in].id = j;

			infos.insert(in);
			++in;
		}
	}

	for(int i=1; i<=in; ++i) cout<<pool[i].id<<" "<<pool[i].value<<endl;
	cout<<endl;

	for(int i:infos) cout<<pool[i].id<<" "<<pool[i].value<<endl;
	cout<<endl;

	for(int i:infos) cout<<i<<" ";
	cout<<endl;
}

void set_search() {
	pool[0].value = 23;
	pool[0].id = 3;
	auto it = infos.lower_bound(0);
	int in = *it;
	cout<<pool[in].id<<" "<<pool[in].value<<endl;
	cout<<in<<endl;
	cout<<(it==infos.end()?"True":"False")<<endl;
}

int main() {
	set_operations();
	cout<<"\n\n\n";
	set_search();
	return 0;
}