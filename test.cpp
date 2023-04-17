#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int C(ll l1,ll l2)
{
    if(l1==0||l2>l1)
        return 0;
    //C^{l2}_{l1} l1里选l2个
    if(l2==l1)
        return 1;
    ll rs1=1;
    for(int i=1;i<=l1;i++)
    {
        rs1*=i;
    }
    ll rs2=1;
    for(int i=1;i<=l2;i++)
    {
        rs2*=i;
    }
    ll rs3=1;
    for(int i=1;i<=l1-l2;i++)
    {
        rs3*=i;
    }
    return rs1/(rs2*rs3);

}
int main()
{

    int n=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int l1=c;
        int l2=d;
        int ls=0;
        int n1=0;
        while(l1||l2)
        {
            int p=l1%2;
            int q=l2%2;
            if(p==1&&q==0)
            {
                ls=0;
                break;
            }
            else if(p==1)
            {
                n1+=1;
            }
            else if(p==0&&q==1)
            {
                ls+=1;
            }
            l1>>=1;
            l2>>=1;
        }
        int rs=0;
        for(int i=a-n1;i<=b-n1;i++)
        {
            rs+=C(ls,i);
        }
        cout<<rs<<endl;
    }
}