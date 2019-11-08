#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream input("level2_5.in");
    ofstream output("level2_5.out");
    int rows, cols;
    long long int max_ = INT_MIN;
    long long int  min_ = INT_MAX;
    long long int sum_ = 0;
    long long a, c, lands_per_countries;

    vector<int> lands;
    vector<int> v_cols;
    vector<vector<int> > v_rows;
    input>>rows>>cols;
    v_cols.resize(cols);
    v_rows.resize(rows, v_cols);
    for(long long i=0;i<rows;i++){
        for(long long j=0;j<cols;j++){
            input>>a>>c;
            v_rows[i][j]=c;
            if(c>=lands.size()){
                lands.resize(c+1);
            }
        }
    }
    for(long long i=0;i<rows;i++){
        for(long long j=0;j<cols;j++){
            if((i==0)||(i==rows-1)||(j==0)||(j==cols-1)){
                lands[v_rows[i][j]]+=1;
            }
            else{
                if(v_rows[i][j]!=v_rows[i][j+1]||v_rows[i][j]!=v_rows[i][j-1]||v_rows[i][j]!=v_rows[i+1][j]||v_rows[i][j]!=v_rows[i-1][j]){
                    lands[v_rows[i][j]]+=1;
                }
            }
        }
    }
    for(int i=0;i<lands.size();i++){
        output<<lands[i]<<endl;
    };
    input.close();
    output.close();
    return 0;
}
