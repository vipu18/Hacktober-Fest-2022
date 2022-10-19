import java.util.ArrayList;
import java.util.List;

public class SpiratMatrix {
    public static void main(String[] args) {
        int[][] matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
        List<Integer> output = spiralmat(matrix);
        System.out.println(output);
    }

    public static List<Integer> spiralmat(int[][] marix) {
        List<Integer> ans = new ArrayList<>();
        int dir = 0, top = 0, left = 0, bottom = marix.length - 1, right = marix[0].length - 1;
        while (top <= bottom && left <= right) {
            if (dir == 0) {
                for (int i = left; i <= right; i++) {
                    ans.add(marix[top][i]);
                }
                top++;
            } else if (dir == 1) {
                for (int i = top; i <= bottom; i++) {
                    ans.add(marix[i][right]);
                }
                right--;
            } else if (dir == 2) {
                for (int i = right; i >= left; i--) {
                    ans.add(marix[bottom][i]);
                }
                bottom--;
            } else if (dir == 3) {
                for (int i = bottom; i >= top; i--) {
                    ans.add(marix[i][left]);
                }
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
}
