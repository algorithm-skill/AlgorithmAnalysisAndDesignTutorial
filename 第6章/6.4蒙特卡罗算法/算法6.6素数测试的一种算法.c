/**
 * �������Ե�һ���㷨
 * ���룺������n
 * ������������nΪ��������ô�ͷ���TRUE, �������n��Ϊ��������ô����FALSE
 **/
BOOL prime_test1(int n)
{
    if(exp_mod(n, 2, n-1) == 1)
        return TRUE;                    /*����������α����*/
    else
        return FALSE;                   /*��������*/
}

