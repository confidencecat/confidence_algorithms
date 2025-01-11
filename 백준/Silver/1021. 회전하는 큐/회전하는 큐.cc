#include <stdio.h>

int chk[55];

int main()
{
	int N, M, res = 0, cur;
	scanf("%d %d", &N, &M);

	cur = 0;
	for (int i = 0; i < M; i++)
	{
		int target;
		scanf("%d", &target);
		target--;
		int data = 0;
		while (cur != target)
		{
			if (chk[cur] == 0)
				data++;
			cur = (cur + 1) % N;
		}
		if (N - i - data > data) res += data;
		else res += N - i - data;
		chk[cur] = 1;
	}
	printf("%d", res);
}