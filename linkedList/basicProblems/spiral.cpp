// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>v(rows*cols,vector<int>(2,0));
        int rend=rStart+1;
        int cend=cStart+1;
         int k=0;
        while(k<rows*cols){
            for(int i=cStart;i<cend && k<rows*cols;i++){
                if(i>=0 && i<cols && rStart>=0 && rStart<rows){
                v[k][0]=rStart;
                v[k][1]=i;
                k++;
                }
                cStart--;
            }
                for(int i=rStart;i<rend && k<rows*cols;i++){
                if(i>=0 && i<rows && cend>=0 && cend<cols){
                v[k][0]=i;
                v[k][1]=cend;
                k++;
                }
                rStart--;
            }
            for(int i=cend;i>cStart && k<rows*cols;i--){
                if(i>=0 && i<cols && rend>=0 && rend<rows){
                v[k][0]=rend;
                v[k][1]=i;
                k++;
                }
                cend++;
            }
            for(int i=rend;i>rStart && k<rows*cols;i--){
                if(i>=0 && i<rows && cStart>=0 && cStart<cols){
                v[k][0]=i;
                v[k][1]=cStart;
                k++;
                }
                rend++;
            }

        }
          return v;     
     }

int main() {
    // Write C++ code here
    vector<vector<int>>v=spiralMatrixIII(5,6,1,4);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
  

    return 0;
}