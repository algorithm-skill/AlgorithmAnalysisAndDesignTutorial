void NonRecursComput(int cm, int cn, int k, int b[])
{
    int lev = 0, t, a[MAX], x[MAX], i;  //����a[]���ѡ���ĺ���,a�е�ǰ��ŵ���������ǰһ����ѡ��������ͬ
    //lev��¼��ǰѡ�����ĸ�����x[lev]��¼����k�����б�ѡ�������±�
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
                //��(cm-b[x[lev]] >= 0, ��������b[x[lev]]��Ϊ��1������)
                a[lev] = b[x[lev]];
                cm = cm - a[lev];
                cn--;
                if((cm == 0) && (cn >= 0))      //������Ҫ��
                {
                    cout<<"the possible digital sequence:";
                    for(i = 0; i <= lev; i++)
                        cout<<b[x[i]]<<"��";
                    cout<<endl;
                    return;
                }
                t = x[lev];
                lev++;
                if(cm - b[t] < 0)
                    x[lev] = t;     //�����������λ��
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
            cout<<"Impossible!"<<endl;  //���ݸ�������·���ߣ��޽�
        return;
    

}