/*分治算法的一般化设计模式*/
divide-and-conquer(P)       //conquer 征服，打败，取胜
{
    if(|P| <= n0)
        adhoc(P);
    divide P into smaller subinstances P1,P2,...,Pk;
    for(i = 1; i <= k; i++)
        yi  =   divide-and-conquer(Pi);
    return merge(y1, y2, ..., yk);
}