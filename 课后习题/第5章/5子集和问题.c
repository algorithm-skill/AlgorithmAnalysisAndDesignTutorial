void NonRecursComput(int cm, int cn, int k, int b[])
{
    int lev = 0, t, a[MAX], x[MAX], i;  //数组a[]存放选定的和项,a中当前存放的数可能与前一个刚选过的数相同
    //lev记录当前选到数的个数，x[lev]记录在这k个数中被选到数的下标
    bool flag = 0;
    x[0] = -1;
    while(lev >= 0){
        x[lev] = x[lev] + 1;
        if(x[lev] == k)
        {
            lev--;
            cm = cm + a[lev];
            cn++;
        }
        else
        {
            if((cm >= b[x[lev]]) && (cn > 0))
            {
                //如(cm-b[x[lev]] >= 0, 则尝试再用b[x[lev]]作为第1个和项)
                a[lev] = b[x[lev]];
                cm = cm - a[lev];
                cn--;
                if((cm == 0) && (cn >= 0))      //已满足要求
                {
                    cout<<"the possible digital sequence:";
                    for(i = 0; i <= lev; i++)
                        cout<<b[x[i]]<<"、";
                    cout<<endl;
                    return;
                }
                t = x[lev];
                lev++;
                if(cm - b[t] < 0)
                    x[lev] = t;     //重新设置起点位置
                else
                    x[lev] = t - 1;
            }
            if((cn < 0) && (cm > 0))
            {
                lev = -1;
                break;
            }
        }
        
        
        
    }
    if (lev == 1)
            cout<<"Impossible!"<<endl;  //回溯根部又无路可走，无解
        return;
    

}