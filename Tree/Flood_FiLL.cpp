#include<bits/stdc++.h>
using namespace std;
const int MAX = 51;
class Solution {
public:
    
    bool safe(int row, int col,vector<vector<int>> &image,int n,int m, bool visited[][MAX],int r,int c){
        if (row == -1 || row == n || col == -1 || col == m || visited[row][col]                                        || image[row][col] !=image[r][c])
            return false;

        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();
        // cout<<row<<" "<<col<<endl;
        // return image;
        bool visited[row][MAX];
        memset(visited,false,sizeof(visited));
        stack< pair<int,int> > s;
        s.push({sr,sc});
        vector<vector<int>> image2(row,vector<int> (col,0));
        while(!s.empty()){
            pair<int,int> x = s.top();
            s.pop();
            int r = x.first;
            int c = x.second;
            visited[r][c] = true;
            image2[r][c] = newColor;
            if(safe(r+1,c,image,row,col,visited,r,c)){
                s.push({r+1,c});
            }
            if(safe(r,c+1,image,row,col,visited,r,c)){
                s.push({r,c+1});
            }
            if(safe(r-1,c,image,row,col,visited,r,c)){
                s.push({r-1,c});
            }
            if(safe(r,c-1,image,row,col,visited,r,c)){
                s.push({r,c-1});
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visited[i][j])image2[i][j] = image[i][j];
            }
        }
        return image2;
    }
};