#include <string>
#include <vector>

using namespace std;

int minCost = 4000000;
int check[27][27] = {
    0,
};
int N = 0;
int cnt = 0;
vector<vector<int> > gBoard;
// prev_pos -> 1(top), 2(bottom), 3(left), 4(right)
void dfs(int sum, int row, int col, int prev_pos)
{
    if (sum > minCost)
        return;
    if (col + row >= (N - 1) * 2)
    {
        if (minCost > sum)
        {
            minCost = sum;
            return;
        }
    }
    int sumTemp = 0;
    // right
    if (col + 1 < N && !gBoard[row][col + 1] && !check[row][col + 1])
    {
        if (prev_pos == 4 || prev_pos == 0)
            sumTemp = 100;
        else
            sumTemp = 600;

        if (gBoard[row][col + 1] == 0 || gBoard[row][col + 1] >= sum + sumTemp)
        {
            gBoard[row][col + 1] = sum + sumTemp;
            check[row][col + 1] = 1;
            dfs(sum + sumTemp, row, col + 1, 4);
            check[row][col + 1] = 0;
        }
    }
    // bottom
    if (row + 1 < N && !gBoard[row + 1][col] && !check[row + 1][col])
    {
        if (prev_pos == 2 || prev_pos == 0)
            sumTemp = 100;
        else
            sumTemp = 600;
        if (gBoard[row + 1][col] == 0 || gBoard[row + 1][col] >= sum + sumTemp)
        {
            gBoard[row + 1][col] = sum + sumTemp;
            check[row + 1][col] = 1;
            dfs(sum + sumTemp, row + 1, col, 2);
            check[row + 1][col] = 0;
        }
    }

    // left
    if (col - 1 >= 0 && !gBoard[row][col - 1] && !check[row][col - 1])
    {
        if (prev_pos == 3)
            sumTemp = 100;
        else
            sumTemp = 600;
        if (gBoard[row][col - 1] == 0 || gBoard[row][col - 1] >= sum + sumTemp)
        {
            gBoard[row][col - 1] = sum + sumTemp;
            check[row][col - 1] = 1;
            dfs(sum + sumTemp, row, col - 1, 3);
            check[row][col - 1] = 0;
        }
    }
    // top
    if (row - 1 >= 0 && !gBoard[row - 1][col] && !check[row - 1][col])
    {
        if (prev_pos == 1)
            sumTemp = 100;
        else
            sumTemp = 600;
        if (gBoard[row - 1][col] == 0 || gBoard[row - 1][col] >= sum + sumTemp)
        {
            gBoard[row - 1][col] = sum + sumTemp;
            check[row - 1][col] = 1;
            dfs(sum + sumTemp, row - 1, col, 1);
            check[row - 1][col] = 0;
        }
    }
}
int solution(vector<vector<int> > board)
{
    gBoard = board;
    N = board.size();
    check[0][0] = 1;
    dfs(0, 0, 0, 0);
    int answer = minCost;

    return answer;
}

// #include <string>
// #include <vector>

// using namespace std;

// int minCost = 4000000;
// int check[27][27]={0,};
// int cost[27][27]={0,};
// int N=0;
// int cnt=0;
// vector<vector<int> > gBoard;
// // prev_pos -> 1(top), 2(bottom), 3(left), 4(right)
// void dfs(int sum, int depth, int row, int col, int prev_pos)
// {
//     if(sum > minCost) return;
//     if (col + row >= (N-1) * 2)
//     {
//         if (minCost > sum)
//         {
//             minCost = sum;
//             return;
//         }
//     }
//     int sumTemp = 0;
//     // right
//     if (col+1 < N && !gBoard[row][col+1] && !check[row][col+1] ) {
//         if(prev_pos==4 || prev_pos == 0) sumTemp=100;
//         else sumTemp=600;
//         check[row][col+1]=1;
//         dfs(sum+sumTemp, depth+1, row, col+1, 4);
//         check[row][col+1]=0;
//     }
//      // bottom
//     if (row+1 < N && !gBoard[row+1][col] && !check[row+1][col] ){
//         if(prev_pos==2 || prev_pos == 0 ) sumTemp=100;
//         else sumTemp=600;
//         check[row+1][col]=1;
//         dfs(sum+sumTemp, depth+1,  row+1, col, 2);
//         check[row+1][col]=0;
//     }

//     // left
//     if (col - 1 >= 0 && !gBoard[row][col-1] && !check[row][col-1] ){
//         if(prev_pos==3) sumTemp=100;
//         else sumTemp=600;
//         check[row][col-1]=1;
//         dfs(sum+sumTemp, depth+1, row, col-1, 3);
//         check[row][col-1]=0;
//     }
//     // top
//     if (row-1 >= 0 && !gBoard[row-1][col] && !check[row-1][col] ){
//         if(prev_pos==1) sumTemp=100;
//         else sumTemp=600;
//         check[row-1][col]=1;
//         dfs(sum+sumTemp, depth+1, row-1, col, 1);
//         check[row-1][col]=0;
//     }
// }
// int solution(vector<vector<int> > board)
// {
//     gBoard = board;
//     N = board.size();

//     dfs(0, 0, 0, 0, 0);
//     int answer = minCost;

//     return answer;
// }