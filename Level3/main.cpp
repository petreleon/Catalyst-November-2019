#include <bits/stdc++.h>

using namespace std;

struct Capital{
    int x, y;
    double distance_from_candidate_capital;
    Capital(int x_, int y_, double distance_from_candidate_capital_){
        distance_from_candidate_capital = distance_from_candidate_capital_;
        x = x_;
        y = y_;
    }
};

bool operator<(Capital &c1, Capital &c2){
    if(c1.distance_from_candidate_capital!=c2.distance_from_candidate_capital){
        if(c1.distance_from_candidate_capital<c2.distance_from_candidate_capital){
            return true;
        }
        else return false;
    }else if(c1.x!=c2.x){
        return c1.x<c2.x;
    }
    else return c1.x<c2.y;
}

int main()
{
    ifstream input("level3_5.in");
    ofstream output("level3.out");
    int rows, cols;
    long long int max_ = INT_MIN;
    long long int  min_ = INT_MAX;
    long long int sum_ = 0;
    long long a, c, lands_per_countries;

    vector<long long> lands_sum_x;
    vector<long long> lands_sum_y;
    vector<long long> cells_per_land;

    vector<int> v_cols;
    vector<vector<int> > v_rows;
    vector<bool> border_cols;
    vector< vector<bool> > border;
    input>>rows>>cols;

    border_cols.resize(cols);
    border.resize(rows,border_cols);

    v_cols.resize(cols);
    v_rows.resize(rows, v_cols);

    for(long long i=0;i<rows;i++){
        for(long long j=0;j<cols;j++){
            input>>a>>c;
            v_rows[i][j]=c;
            if(c>=lands_sum_x.size()){
                lands_sum_x.resize(c+1);
                lands_sum_y.resize(c+1);
                cells_per_land.resize(c+1);
            }
            cells_per_land[c]+=1;
            lands_sum_x[c]+=i;
            lands_sum_y[c]+=j;
        }
    }
    for(long long i=0;i<rows;i++){
        for(long long j=0;j<cols;j++){
            bool border_ = false;
            if((i==0)||(i==rows-1)||(j==0)||(j==cols-1)){
                border_ = true;
            }
            else{
                if(v_rows[i][j]!=v_rows[i][j+1]||v_rows[i][j]!=v_rows[i][j-1]||v_rows[i][j]!=v_rows[i+1][j]||v_rows[i][j]!=v_rows[i-1][j]){
                    border_ = true;
                }
            }
            border[i][j]=border_;
        }
    }
    vector<long long> candidate_capitals_x(lands_sum_x.size());
    vector<long long> candidate_capitals_y(lands_sum_y.size());
    for(int i=0;i<cells_per_land.size();i++){
        candidate_capitals_x[i]=lands_sum_x[i]/cells_per_land[i];
        candidate_capitals_y[i]=lands_sum_y[i]/cells_per_land[i];
    }

    vector< vector <Capital> > PossibleCapitals(candidate_capitals_x.size());
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols;j++){
            int Country = v_rows[i][j];
            if(!border[i][j]){
                PossibleCapitals[Country].push_back(Capital(i,j, pow(pow((double)i-candidate_capitals_x[Country],2)+pow((double)j-candidate_capitals_y[Country],2),0.5)));
            }
        }
    }

    for(int i=0;i<PossibleCapitals.size();i++){
        sort(PossibleCapitals[i].begin(),PossibleCapitals[i].end());
    }
    for(int i=0;i<PossibleCapitals.size();i++){
        output<<PossibleCapitals[i][0].y<<" "<<PossibleCapitals[i][0].x<<endl;
    };
    input.close();
    output.close();
    return 0;
}
