#include <iostream>
using namespace std;

struct Node
{
	int l, r, len;
}no[32005];

int ord[8005], ans[8005], N;
//Node��l, r�ֱ��ʾ�ڵ�������,len��ʾ�������λ��ж��ٸ�ֵ��û��ȥ���ģ��ǿ����õ�

void create_tree(int l, int r, int root)
{
	no[root].l = l, no[root].r = r, no[root].len = r-l+1;
	if(l < r)
	{
		int mid = (l+r)>>1;
		create_tree(l, mid, root*2);
		create_tree(mid+1, r, root*2+1);
	}
}//������ʱ��ÿ��������������������ã����Գ���Ϊr-l+1

int query(int root, int num)
{
	no[root].len--;//��ѯ��һ���ڵ��ʱ������Ǹýڵ�ͷ��أ����ڵ�Ŀ�������1
	if(no[root].l == no[root].r)	return no[root].l;//���������ʱ����ʾ�����ٵݹ���ȥ����ô���ҵ���
	if(num > no[root*2].len)//���num�����ڵ�����������ִ���ôֻ�����ҽڵ���Ѱ��
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
		ans[i] = query(1, ord[i]+1);//ÿ��ȥ����ǰ��õ�ֵ����ѯ��ʣ�µ��������е�n����
	ans[1] = query(1, 1);
	for(int i=1; i<=N; i++)
		printf("%d\n", ans[i]);
	return 0;
}