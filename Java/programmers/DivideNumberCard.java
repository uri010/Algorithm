package programmers;

public class DivideNumberCard {

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public int solution(int[] arrayA, int[] arrayB) {
        int answer = 0;
        int gcdA = 0, gcdB = 0;
        for (int i = 0; i < arrayA.length; i++) {
            gcdA = gcd(gcdA, arrayA[i]);
            gcdB = gcd(gcdB, arrayB[i]);
        }

        if (gcdA == 0) {
            return gcdB;
        } else if (gcdB == 0) {
            return gcdA;
        }

        if (gcdA > gcdB) {
            boolean flagA = true;
            for (int i = 0; i < arrayB.length; i++) {
                if (arrayB[i] % gcdA == 0) {
                    flagA = false;
                    break;
                }
            }
            if (flagA) {
                return gcdA;
            }
        } else {
            boolean flagB = true;
            for (int i = 0; i < arrayA.length; i++) {
                if (arrayA[i] % gcdB == 0) {
                    flagB = false;
                    break;
                }
            }
            if (flagB) {
                return gcdB;
            }
        }
        return answer;
    }
}