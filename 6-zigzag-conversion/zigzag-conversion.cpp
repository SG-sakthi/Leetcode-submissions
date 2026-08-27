class Solution {
public:
    string convert(string s, int numRows) {

 if (numRows == 1) return s;

    int n = s.length();

    // Create a matrix large enough
    vector<vector<char>> mat(numRows, vector<char>(n, ' '));

    int row = 0, col = 0;
    int i = 0;

    while (i < n) {
        // Move Down
        while (row < numRows && i < n) {
            mat[row][col] = s[i++];
            row++;
        }

        row -= 2;
        col++;

        // Move Up Diagonally
        while (row > 0 && i < n) {
            mat[row][col] = s[i++];
            row--;
            col++;
        }
    }

    string result = "";

    // Read row by row
    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < n; c++) {
            if (mat[r][c] != ' ')
                result += mat[r][c];
        }
    }

    return result;
}

    
};

/* 

P   A   H   N  => P_ _ _ A _ _ _ H _ _ _ N
A P L S I I G => A _ P _ L _ S _ I _ I _ G
Y   I   R => Y_ _ _ I _ _ _ R

s[0,0] =P            s[0,2] =A
s[1,0] =A  s[1,1] =P s[1,2]=L
s[2,0] =Y            s[2,1] =I


SAKTHIGANESH  row =3

S   H   N    => S _ _ _ H _ _ _ N 
A T I A E H => A_T
K   G   S

*/