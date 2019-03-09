// https://blog.csdn.net/q22232222/article/details/25060365

package com.bluecup.org;
 
import java.util.Arrays;
import java.util.Scanner;
 
public class KM_Min {
 
	/**
	 * @param args
	 */
	static int n, m, k, p;
	static int a[] = new int[20];
	static int b[] = new int[20];
	static int map1[][] = new int[20][20];
	static int map2[][] = new int[20][20];
	static int f[][] = new int[20][20];
	static int lx[] = new int[20];
	static int ly[] = new int[20];
	static boolean edge[][] = new boolean[20][20];
 
	static boolean xmatch[] = new boolean[10];
	static boolean ymatch[] = new boolean[10];
	static int match[] = new int[10];
 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
 
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		m = scan.nextInt();
		k = scan.nextInt();
		p = scan.nextInt();
		for (int i = 1; i <= n; i++) {
			a[i] = scan.nextInt();
			b[i] = i + 1;
		}
 
		for (int i = 1; i <= m; i++) {
			Arrays.fill(map1[i], 1000);
			Arrays.fill(f[i], 1000);
			Arrays.fill(map2[i], 1000);
		}
 
		for (int i = 0; i < k; i++) {
			int a, b;
			a = scan.nextInt();
			b = scan.nextInt();
			map1[a][b] = map1[b][a] = scan.nextInt();
		}
		for (int i = 0; i < p; i++) {
			int a, b;
			a = scan.nextInt();
			b = scan.nextInt();
			map2[a][b] = f[a][b] = scan.nextInt();
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++)
				for (int k = 1; k <= m; k++) {
					if (i != j && i != k && j != k)
						if (map1[j][k] > map1[j][i] + map1[i][k])
							map1[j][k] = map1[j][i] + map1[i][k];
				}
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= m; k++) {
					if (f[j][k] > map2[j][i] + map1[i][k])
						f[j][k] = map2[j][i] + map1[i][k];
				}
		}
 
		for (int i = 1; i <= n; i++) {
 
			lx[i] = Integer.MAX_VALUE;
			for (int j = 1; j <= n; j++)
				if (f[i][a[j]] < lx[i])
					lx[i] = f[i][a[j]];
		}
		while (true) {
			for (int i = 1; i <= n; i++) {
 
				for (int j = 1; j <= n; j++)
					if (f[i][a[j]] == lx[i] + ly[j])
						edge[i][j] = true;
					else
						edge[i][j] = false;
			}
			for (int i = 1; i <= n; i++)
				match[i] = -1;
			int value = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					xmatch[j] = false;
					ymatch[j] = false;
				}
				if (hungary(i)) {
					value++;
				} else {
					xmatch[i] = true;
					break;
				}
			}
			if (value >= n)
				break;
			int ex;
			ex = Integer.MAX_VALUE;
			for (int i = 1; i <= n; i++) {
 
				for (int j = 1; j <= n && xmatch[i]; j++) {
 
					if (!ymatch[j] && ex > (lx[i] + ly[j] - f[i][a[j]])) {
						ex = lx[i] + ly[j] - f[i][a[j]];
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				if (xmatch[i]) {
					lx[i] = lx[i] - ex;
				}
				if (ymatch[i]) {
					ly[i] = ly[i] + ex;
				}
			}
 
		}
		int cost = 0;
		for (int i = 1; i <= n; i++) {
			System.out.println(a[match[i]]);
			cost += f[i][a[match[i]]];
		}
		System.out.println(cost + "×îÐ¡Öµ");
	}
 
	private static boolean hungary(int x) {
		// TODO Auto-generated method stub
		for (int i = 1; i <= n; i++) {
			if (!ymatch[i] && edge[x][i]) {
				ymatch[i] = true;
				if (match[i] == -1 || hungary(match[i])) {
					match[i] = x;
					return true;
				}
				if (match[i] != -1)
					xmatch[match[i]] = true;
			}
		}
		return false;
	}
 
}