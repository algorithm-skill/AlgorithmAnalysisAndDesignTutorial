greedy(S,n)
{
    solution = ?;				//����ʼ���н⼯����Ϊ�ռ�
    for (i = 1; i < n; i++)		
    {
        x = select(S);
        if(feasible(solution, x))
            solution = union(solution, x);
    }
    return solution;
}