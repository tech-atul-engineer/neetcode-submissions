class Solution {
public:
    bool checkSuduko(vector<vector<char>>& board, int i,int j, unordered_map<int, vector<int>>& row, unordered_map<int, vector<int>>& col){
        unordered_map<int,bool> tmp;
        for(int k=i;k<3+i;k++){
            for(int l=j;l<3+j;l++){
                if(board[k][l] != '.'){
                    char val = board[k][l];
                    if(tmp[val]) return false;
                    tmp[val] = true;
                    if(!row[k].empty() && find(row[k].begin(), row[k].end(), val) != row[k].end()) return false;
                    row[k].push_back(val);
                    if(!col[l].empty() && find(col[l].begin(), col[l].end(), val) != col[l].end()) return false;
                    col[l].push_back(val);
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, vector<int>> row,col;
        for(int i=0;i<board.size();i+=3){
            for(int j=0;j<board[0].size();j+=3){
                bool value = checkSuduko(board, i,j,row,col);
                if(!value) return false;
            }
        }
        return true;
    }
};