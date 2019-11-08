#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream input("level1_5.in");
    ofstream output("level1_5.out");
    int rows, cols;
    long long int max_ = INT_MIN;
    long long int  min_ = INT_MAX;
    long long int sum_ = 0;
    int t;
    input>>rows>>cols;
    for(int i=0;i<rows*cols;i++){
        input>>t;
        if(t>max_)max_=t;
        if(t<min_)min_=t;
        sum_+=t;
    }
    output<<min_<<" "<<max_<<" "<<(sum_/(rows*cols));
    input.close();
    output.close();
    return 0;
}
