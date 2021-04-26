#include <string>
#include <vector>

using namespace std;

int minNum = 0;
void dfs(vector<int> numbers, int cur, int sum, int isPlus, int target)
{
    printf("num: %d\n", numbers.size());
    if (sum + (isPlus * numbers[cur]) == target && cur == numbers.size() - 1)
    {
        printf("!!!");
        minNum++;
        return;
    }
    else if (cur < numbers.size() - 1)
    {
        dfs(numbers, cur + 1, sum + (isPlus * numbers[cur]), 1, target);
        dfs(numbers, cur + 1, sum + (isPlus * numbers[cur]), -1, target);
    }

    return;
}
int solution(vector<int> numbers, int target)
{
    int answer = 0;

    dfs(numbers, 0, 0, 1, target);
    dfs(numbers, 0, 0, -1, target);

    answer = minNum;
    return answer;
}

int main()
{
    vector<int> numbers(5, 1);
    printf("%d\n", solution(numbers, 3));
    return 0;
}