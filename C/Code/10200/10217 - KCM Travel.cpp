#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
#define MAX_INDEX 100000

using namespace std;
typedef struct Node
{
	int pos, money, hour;
} ND;

vector<vector<ND>> matrix;

int main()
{
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// loop testcase
	int t;
	for (cin >> t; t; t--)
	{
		// init
		int n, m, k;
		cin >> n >> m >> k;

		// ticket init
		matrix = vector<vector<ND>>(n + 1);
		for (; k; k--)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			matrix[a].push_back({b, c, d});
		}

		// BFS init
		int retval = INF;
		ND q[MAX_INDEX];
		int front = 0, rear = 0;
		q[rear++] = {1, 0, 0};

		// BFS search
		while (front != rear)
		{
			// get first node
			ND node = q[front++];
			front %= MAX_INDEX;

			// check available
			if (node.money > m || node.hour > retval)
				continue;
			else if (node.pos == n)
				retval = node.hour;
			else
				for (ND tempNode : matrix[node.pos])
				{
					q[rear++] = {tempNode.pos, node.money + tempNode.money, node.hour + tempNode.hour};
					rear %= MAX_INDEX;
				}
		}

		// print result
		(retval == INF) ? cout << "Poor KCM" : cout << retval;
		cout << "\n";
	}

	return 0;
}