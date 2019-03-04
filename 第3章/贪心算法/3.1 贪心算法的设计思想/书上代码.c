greedy(S,n)
{
    solution = ?;				//将初始可行解集设置为空集
    for (i = 1; i < n; i++)		
    {
        x = select(S);
        if(feasible(solution, x))
            solution = union(solution, x);
    }
    return solution;
}