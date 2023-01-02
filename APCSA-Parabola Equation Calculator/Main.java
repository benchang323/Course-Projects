package Parabola;
import java.util.*;
//import Jama.Matrix;
public class Main 
{
    public static void main(String[] args) 
    {
        Scanner kb = new Scanner(System.in);
        System.out.print("\nEnter x1: ");
        double x1 = kb.nextDouble();
        System.out.print("\nEnter x2: ");
        double x2 = kb.nextDouble();
        System.out.print("\nEnter x3: ");
        double x3 = kb.nextDouble();
        System.out.print("\nEnter y1: ");
        double y1 = kb.nextDouble();
        System.out.print("\nEnter y2: ");
        double y2 = kb.nextDouble();
        System.out.print("\nEnter y3: ");
        double y3 = kb.nextDouble();

        //lagrange polynomial...I guess this is algebra 2 math (the multiplication, subtracion, addition parts)? But conceptually I learned this in calculus and linear algebra.
        double a = y1/((x1-x2)*(x1-x3)) + y2/((x2-x1)*(x2-x3)) + y3/((x3-x1)*(x3-x2));
        double b = -y1*(x2+x3)/((x1-x2)*(x1-x3)) - y2*(x1+x3)/((x2-x1)*(x2-x3)) - y3*(x1+x2)/((x3-x1)*(x3-x2));
        double c = y1*x2*x3/((x1-x2)*(x1-x3)) + y2*x1*x3/((x2-x1)*(x2-x3)) + y3*x1*x2/((x3-x1)*(x3-x2));

        //Test cases: (x1, x2, x3, y1, y2, y3) = (0, 1, 2, 3, -4, -9) / (1, 2, 3, -2, -4, -4)
        System.out.println("Quadratic: y = (" + a + ")x^2 + (" + b + ")x + (" + c + ")");
        System.out.println("Vertex: (x-(" + (-(int)b / (2 * (int)a)) + "))^2 + " + (((4 * (int)a * (int)c) - ((int)b * (int)b)) / (4 * (int)a)));
        
        /* ok....I'll redo this :(

        double[][] arrx = {{Math.pow(x1,2),x1,1}, {Math.pow(x2,2),x2,1}, {Math.pow(x3,2),x3,1}};
        double[][] arry = {{y1}, {y2}, {y3}};

        Matrix A = new Matrix(arrx);
        Matrix B = new Matrix(arry);
        Matrix ans = A.solve(B); //Matrix calculations are in Algebra 2
        double[][] arrans = ans.getArray();
        

        System.out.println("Quadratic: y = (" + (int)arrans[0][0] + ")x^2 + (" + (int)arrans[1][0] + ")x + (" + (int)arrans[2][0] + ")");
        System.out.println("Vertex: (x-(" + (-(int)arrans[1][0] / (2 * (int)arrans[0][0])) + "))^2 + " + (((4 * (int)arrans[0][0] * (int)arrans[2][0]) - ((int)arrans[1][0] * (int)arrans[1][0])) / (4 * (int)arrans[0][0])));
        */

        kb.close();
    }
}

