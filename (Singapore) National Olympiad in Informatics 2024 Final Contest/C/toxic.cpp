#include "toxic.h"
using namespace std;
void determine_type(int n) {
	vector<char> ans;
	ans.push_back('T');
	for(int i=1;i<n;i++)
	{
		if(query_machine({0,i}).back()-1)ans.push_back('T');
		else ans.push_back('R');
	}
	// std::vector<int> res = query_machine({1, 0, 2, 1});
	answer_type(ans);
}
