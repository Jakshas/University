import java.util.Calendar;
import java.util.Iterator;

import structures.*;

public class Main {
    public static void main(String[] args) throws Exception {
        {        
            OrderedList<Integer> o= new OrderedList<>();
            o.insert(1);
            o.insert(0);
            o.insert(2);
            System.out.println(o.at(0));
            System.out.println(o);
            System.out.println(o.min());
            System.out.println(o.max());
            System.out.println(o.search(1));
            //o.remove(2);
            System.out.println(o.index(1));
            for (Integer i : o) {
                System.out.print(i+" ");
            }
            System.out.println();
            Iterator<Integer> iter = o.iterator();
            while(iter.hasNext()){
                int ii=iter.next();
                if(ii==1){
                    iter.remove();
                }
            }
            for (Integer i : o) {
                System.out.print(i+" ");
            }
        }
        System.out.println();
        System.out.println("---------------");
        {
            OrderedList<String> o= new OrderedList<>();
            o.insert("1");
            o.insert("0");
            o.insert("2");
            System.out.println(o.at(0));
            System.out.println(o);
            System.out.println(o.min());
            System.out.println(o.max());
            System.out.println(o.search("1"));
            //o.remove(2);
            System.out.println(o.index("1"));
            for (String i : o) {
                System.out.print(i+" ");
            }
            System.out.println();
            Iterator<String> iter = o.iterator();
            while(iter.hasNext()){
                String ii=iter.next();
                if(ii=="1"){
                    iter.remove();
                }
            }
            for (String i : o) {
                System.out.print(i+" ");
            }
        }
        System.out.println();
        System.out.println("---------------");
        {
            OrderedList<Calendar> o= new OrderedList<>();
            Calendar cal1= Calendar.getInstance();
            Calendar cal2= Calendar.getInstance();
            Calendar cal3= Calendar.getInstance();
            cal1.add(1, 1);
            cal2.add(1, 3);
            cal3.add(1, 2);
            o.insert(cal2);
            o.insert(cal1);
            o.insert(cal3);
            System.out.println(o.at(0).get(1));
            //System.out.println(o);
            System.out.println(o.min().get(1));
            System.out.println(o.max().get(1));
            System.out.println(o.search(cal1));
            //o.remove(2);
            System.out.println(o.index(cal2));
            for (Calendar i : o) {
                System.out.print(i.get(1)+" ");
            }
            System.out.println();
            Iterator<Calendar> iter = o.iterator();
            while(iter.hasNext()){
                Calendar ii=iter.next();
                if(ii==cal3){
                    iter.remove();
                }
            }
            for (Calendar i : o) {
                System.out.print(i.get(1)+" ");
            }
        }
    }; 
}

