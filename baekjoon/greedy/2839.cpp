#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt5 = n / 5;
    int cnt3 = 0;

    for (int i = 0; i <= n / 5; i++)
    {
        if ((n - (cnt5 * 5)) % 3 == 0)
        {
            cnt3 = (n - (cnt5 * 5)) / 3;
            break;
        }
        cnt5--;
    }

    if (cnt3 + cnt5 == 0)
        cout << -1 << '\n';
    else
        cout << cnt3 + cnt5 << '\n';

    return 0;
}

// int main(){
// 	int n, t=0;
// 	scanf("%d",&n);
// 	for(;n>=0&&n%5;n-=3,t++);
// 	printf("%d", n<0?-1:n/5+t);
// 	return 0;
// }