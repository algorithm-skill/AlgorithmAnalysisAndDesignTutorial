void match_random(char S[], long n, char P[], long m, long &loc, long R[])
{
    long q;
    random_seed(0);
    q = random(1, num);                         /*numΪ����R�е�Ԫ����Ŀ*/
    q = R(q);
    match_random(S[], n, P[], m, loc, q);
}