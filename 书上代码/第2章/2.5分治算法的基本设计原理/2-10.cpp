/*�����㷨��һ�㻯���ģʽ*/
divide-and-conquer(P)       //conquer ��������ܣ�ȡʤ
{
    if(|P| <= n0)
        adhoc(P);
    divide P into smaller subinstances P1,P2,...,Pk;
    for(i = 1; i <= k; i++)
        yi  =   divide-and-conquer(Pi);
    return merge(y1, y2, ..., yk);
}