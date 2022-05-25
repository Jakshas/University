public class Zadanie4 {
    
    public triangle check_if_triangle(double x1, double y1, double x2, double y2,double x3, double y3){
        double a = x1 * (y2 - y3) + x2 * (y3 - y1) +  x3 * (y1 - y2);
        if(a == 0){
            return null;
        }
        double ac1 = Math.abs(y2 - y1);
        double cb1 = Math.abs(x2 - x1);
            
        double one =  Math.hypot(ac1, cb1);
        double ac2 = Math.abs(y2 - y3);
        double cb2 = Math.abs(x2 - x3);
            
        double two =  Math.hypot(ac2, cb2);
        double ac3 = Math.abs(y1 - y3);
        double cb3 = Math.abs(x1 - x3);
            
        double three =  Math.hypot(ac3, cb3);

        if(one == two && two == three){
            return triangle.Rownoboczny;
        }
        if (one == two || two == three || one == three) {
            return triangle.Rownoramienny;
        }
        return triangle.Roznoboczny;
    }
}
