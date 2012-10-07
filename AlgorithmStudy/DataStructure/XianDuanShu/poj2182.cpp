#include <iostream>
using namespace std;

struct Node
{
	int l, r, len;
}no[32005];

int ord[8005], ans[8005], N;
//Node的l, r分别表示节点的左和右,len表示这个区间段还有多少个值是没有去掉的，是可以用的

void create_tree(int l, int r, int root)
{
	no[root].l = l, no[root].r = r, no[root].len = r-l+1;
	if(l < r)
	{
		int mid = (l+r)>>1;
		create_tree(l, mid, root*2);
		create_tree(mid+1, r, root*2+1);
	}
}//建树的时候，每个区间的所有数都可以用，所以长度为r-l+1

int query(int root, int num)
{
	no[root].len--;//查询到一个节点的时候，如果是该节点就返回，父节点的可用数减1
	if(no[root].l == no[root].r)	return no[root].l;//当左右相等时，表示不能再递归下去，那么就找到了
	if(num > no[root*2].len)//如果num比做节点可以数的数字大，那么只能在右节点中寻找
		return query(root*2+1, num-no[root*2].len);
	return query(root*2, num);
}

int main()
{
	scanf("%d", &N);
	for(int i=2; i<=N; i++)
		scanf("%d", &ord[i]);
	create_tree(1, N, 1);
	for(int i=N; i>1; i--)
		ans[i] = query(1, ord[i]+1);//每次去掉当前获得的值，查询在剩下的数中排行第n的数
	ans[1] = query(1, 1);
	for(int i=1; i<=N; i++)
		printf("%d\n", ans[i]);
	return 0;
}