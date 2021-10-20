class Solution {
public:
    void recurse_fill(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor, vector<vector<int>>& visited){
        if(sr<0 || sc< 0 || sr >= image.size() || sc >= image[0].size()) return;
        if(visited[sr][sc]) return;
        // cout<<"sr: "<<sr<<" sc: "<<sc<<endl; 
        visited[sr][sc] = 1;
        if(image[sr][sc] == oldColor){
            image[sr][sc] = newColor;
            // cout<<"Changing to: "<<image[sr][sc] <<endl;
            if(sr>0){
                // cout<<"Going up from "<<sr<<" "<< sc<<endl;
                recurse_fill(image, sr-1, sc, newColor, oldColor, visited);
            }
            if(sc>0){
                // cout<<"Going left from "<<sr<<" "<< sc<<endl;
                recurse_fill(image, sr, sc-1, newColor, oldColor, visited);
            }
            if(sr<image.size()){
                // cout<<"Going down from "<<sr<<" "<< sc<<endl;
                recurse_fill(image, sr+1, sc, newColor, oldColor, visited);;
            }
             if(sc<image[0].size()){
                 // cout<<"Going right from "<<sr<<" "<< sc<<endl;
                recurse_fill(image, sr, sc+1, newColor, oldColor, visited);
             }
        }
        
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(sr<0 || sc< 0 || sr >= image.size() || sc >= image[0].size()) return image;
        int oldColor = image[sr][sc];
        if(oldColor == newColor) return image;
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        recurse_fill(image, sr, sc, newColor, oldColor, visited);
        return image;
    }
};