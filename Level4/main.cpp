#include <bits/stdc++.h>

using namespace std;

bool verify(int ox, int oy, int dx, int dy, int x_verify, int y_verify){
    double ox_c = ox+0.5;
    double oy_c = oy+0.5;
    double x1 = x_verify;
    double x2 = x_verify+1;
    double y_verify_ = y_verify + 0.5;
    double y1 = (x1-ox_c)*((double) dy/dx)+oy_c;
    double y2 = (x2-ox_c)*((double) dy/dx)+oy_c;
    if(abs(y1-y_verify_)<0.5||abs(y2-y_verify_)<0.5||(y1-y_verify_<0&&y2-y_verify_>0)||(y1-y_verify_>0&&y2-y_verify_<0)){
        return true;
    }
    return false;
}

int verification(ostream o, int ox, int oy, int dx, int dy){

}

int main()
{
    ifstream input("level3_5.in");
    ofstream output("level3.out");
    int rows, cols, n;
    for(int i = 0; i<n; i++){
        int ox,oy,dx,dy;

    }
    input.close();
    output.close();
    return 0;
}
