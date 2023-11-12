import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author andre
 */
public class Cell {
    
    int R;
    int C;
    
    public Cell(int r, int c){
        R = r;
        C = c;
    }
    
    public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        ArrayList<Cell>[] room = new ArrayList[1000001];
        for (int i = 0; i <= 1000000; ++i){
            room[i] = new ArrayList();
        }
        for (int i = 1; i < m; ++i){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; ++j){
                room[Integer.parseInt(st.nextToken())].add(new Cell(i, j));
            }
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i < n; ++i){
            room[Integer.parseInt(st.nextToken())].add(new Cell(m, i));
        }
        room[0].add(new Cell(m, n));
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(0);
        while(!q.isEmpty()){
            int u = q.poll();

            for (int i = 0; i < room[u].size(); ++i){
                int d = room[u].get(i).R * room[u].get(i).C;
                if (d == 1){
                    System.out.println("yes");
                    return;
                }
                if (!room[d].isEmpty()){
                    q.add(d);
                }
            }
            room[u].clear();
        }
        System.out.println("no");
    }
}