#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	long day, num, i, k;
	cin >> num;
	cin >> k;
	vector<long> n;
	for(i=0;i<num;i++){
		long temp;
		cin >> temp;
		n.push_back(temp);
	}
	auto min = min_element(begin(n), end(n));
	auto max = max_element(begin(n), end(n));
	while (*min<*max-k){
		while (*min<*max-k){
			day++;
			*min = *min + 1;
			*max = *max - 1;
		}
		min = min_element(begin(n), end(n));
		max = max_element(begin(n), end(n));
		cout << endl;
	}
	cout << day;
}