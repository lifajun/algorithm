/*
ID: lifajun2
PROG: packrec
LANG: C++
*/
#include <cstdio>
#include <cstring>

struct box
{
    int h,w;
};
struct box rectangle[6],rect[6],ans[6];
bool used[6],ro[6];
int p,s=10000,w,h;
 
int max(int a,int b)
{
    if (a>b) return a;
    else return b;
}
void judge()
{
    int i,j,temp;
    if (w>h)
    {
        temp=w;
        w=h;
        h=temp;
    }    
    if (w*h<=s)
    {
        if (w*h==s) 
        {
            for (i=1;i<=p;i++) 
            if (w==ans[i].w) return;
            for (i=1;i<=p;i++)
            if (w<ans[i].w)
            {
                for (j=p+1;j>i;j--)ans[j]=ans[j-1];
                ans[i].w=w;
                ans[i].h=h;
                p++;
                return;
            }
            p++;
            ans[p].h=h;
            ans[p].w=w;
        }    
        else
        {
            s=w*h;
            p=1;
            ans[p].h=h;
            ans[p].w=w;
        }
    }
}
void work()
{    
    //Case 1
    w=rect[1].w+rect[2].w+rect[3].w+rect[4].w;
    h=max(rect[1].h,rect[2].h);
    h=max(h,rect[3].h);
    h=max(h,rect[4].h);
    judge();
 
    //Case 2
    w=max(rect[1].w+rect[2].w+rect[3].w,rect[4].w);
    h=max(rect[1].h,rect[2].h);
    h=max(h,rect[3].h);
    h+=rect[4].h;
    judge();
 
    //Case 3
    w=max(rect[1].w+rect[2].w,rect[3].w)+rect[4].w;
    h=max(max(rect[1].h,rect[2].h)+rect[3].h,rect[4].h);
    judge();
 
    //Case 4
    w=rect[1].w+max(rect[2].w,rect[3].w)+rect[4].w;
    h=max(rect[1].h,rect[4].h);
    h=max(h,rect[2].h+rect[3].h);
    judge();
 
    //Case 6
    if (rect[3].h>=rect[2].h+rect[4].h)
    {
        w=max(rect[3].w+rect[2].w,rect[3].w+rect[4].w);
        w=max(w,rect[1].w);
        h=rect[1].h+rect[3].h;
        judge();
        return;
    }
    if (rect[3].h>rect[4].h)
    {
        w=max(rect[1].w+rect[2].w,rect[2].w+rect[3].w);
        w=max(w,rect[4].w+rect[3].w); 
        h=max(rect[1].h+rect[3].h,rect[2].h+rect[4].h);
        judge();
        return;
    }
    if (rect[3].h==rect[4].h)
    {
        w=max(rect[1].w+rect[2].w,rect[3].w+rect[4].w);
        h=max(rect[1].h,rect[2].h)+rect[3].h;
        judge();
        return;
    }
    if (rect[3].h<rect[4].h && rect[4].h<rect[3].h+rect[1].h)
    {
        w=max(rect[1].w+rect[2].w,rect[1].w+rect[4].w);
        w=max(w,rect[3].w+rect[4].w);
        h=max(rect[1].h+rect[3].h,rect[2].h+rect[4].h);
        judge();
        return;
    }
    w=max(rect[2].w,rect[1].w+rect[4].w);
    w=max(w,rect[3].w+rect[4].w);
    h=rect[4].h+rect[2].h;
    judge();    
}
void exchange(int i)
{
    int temp;
    temp=rect[i].h;
    rect[i].h=rect[i].w;
    rect[i].w=temp;
}    
void rotate(int depth)
{
    if (depth==5)
    {
        work();
        return;
    }
    if (!ro[depth])
    {
        ro[depth]=true;
        exchange(depth);
        rotate(depth+1);
        ro[depth]=false;
        exchange(depth);
        rotate(depth+1);
    }    
}        
void search(int depth)
{
    int i;
    if (depth==5)
    {
        rotate(1);
        return;
    }
    for (i=1;i<5;i++)
    {
        if (!used[i])
        {
            rect[depth]=rectangle[i];
            used[i]=true;
            search(depth+1);
            used[i]=false;
        }
    }
}                
 
int main()
{
    int i;
    FILE *in=fopen("packrec.in","r"),*out=fopen("packrec.out","w");
 
    memset(ans,0,sizeof(ans));
    for (i=1;i<5;i++) fscanf(in,"%d%d",&rectangle[i].h,&rectangle[i].w);
    fclose(in);
    search(1);
    fprintf(out,"%d\n",s);
    for (i=1;i<=p;i++)
    {
        fprintf(out,"%d %d\n",ans[i].w,ans[i].h);
    }
    fclose(out);
}