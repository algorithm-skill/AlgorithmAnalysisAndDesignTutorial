void match_random(char S[], long n, char P[], long m, long &loc, long R[])
{
    long q;
    random_seed(0);
    q = random(1, num);                         /*num为数组R中的元素数目*/
    q = R(q);
    match_random(S[], n, P[], m, loc, q);
}