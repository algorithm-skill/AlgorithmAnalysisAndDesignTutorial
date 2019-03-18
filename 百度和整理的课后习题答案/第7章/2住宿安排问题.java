//Ô­ÎÄ£ºhttps://blog.csdn.net/q22232222/article/details/25038757

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
 
public class CheckIn {
 
	/**
	 * @param args
	 */
	static boolean check[][] = new boolean[20][2];
	static int v[][] = new int[20][2];
	static int f[][] = new int[20][20];
	static boolean used[] = new boolean[20];
	static int linkey[] = new int[20];
	static int n, m;
	static ArrayList<Integer> a = new ArrayList<Integer>();
	static ArrayList<Integer> b = new ArrayList<Integer>();
 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
 
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		m = scan.nextInt();
		for (int i = 0; i < m; i++) {
			v[i][0] = scan.nextInt();
			v[i][1] = scan.nextInt();
			f[v[i][0]][v[i][1]] = f[v[i][1]][v[i][0]] = 1;
		}
		if (divide(0)) {
			for (int i = 0; i <= n; i++) {
				if (check[i][0]) {
					a.add(i);
				}
				if (check[i][1]) {
					b.add(i);
				}
			}
			int t = 0;
			for (int i = 0; i < a.size(); i++) {
				Arrays.fill(used, false);
				if (hungary(i))
					t++;
			}
			System.out.println(t);
			for (int i = 0; i < b.size(); i++) {
				System.out.println(b.get(i) + " " + a.get(linkey[i]));
			}
		}
		else
		{
			System.out.println("no");
		}
	}
 
	private static boolean hungary(int i) {
		// TODO Auto-generated method stub
 
		for (int j = 0; j < b.size(); j++) {
			if (used[j] == false && f[a.get(i)][b.get(j)] == 1) {
				used[j] = true;
				if (linkey[j] == 0 || hungary(linkey[j])) {
					linkey[j] = i;
					return true;
				}
			}
		}
		return false;
	}
 
	private static boolean divide(int x) {
		// TODO Auto-generated method stub
		if (x == m)
			return true;
		if (check[v[x][0]][0] && check[v[x][1]][0]
				|| (check[v[x][0]][1] && check[v[x][1]][1]))
			return false;
		if (check[v[x][0]][0]) {
			check[v[x][1]][1] = true;
			if (divide(x + 1))
				return true;
			check[v[x][1]][1] = false;
		} else if (check[v[x][0]][1]) {
			check[v[x][1]][0] = true;
			if (divide(x + 1))
				return true;
			check[v[x][1]][0] = false;
		} else if (check[v[x][1]][0]) {
			check[v[x][0]][1] = true;
			if (divide(x + 1))
				return true;
			check[v[x][0]][1] = false;
		} else if (check[v[x][1]][1]) {
			check[v[x][0]][0] = true;
			if (divide(x + 1))
				return true;
			check[v[x][0]][0] = false;
		} else {
			check[v[x][0]][0] = true;
			check[v[x][1]][1] = true;
			if (divide(x + 1))
				return true;
			check[v[x][0]][0] = false;
			check[v[x][1]][1] = false;
 
			check[v[x][0]][1] = true;
			check[v[x][1]][0] = true;
			if (divide(x + 1))
				return true;
			check[v[x][0]][1] = false;
			check[v[x][1]][0] = false;
		}
		return false;
	}
 
}
 