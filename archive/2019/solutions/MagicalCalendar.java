
import java.util.*;
import java.io.*;

// By Ayush Varshney
public class MagicalCalendar {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        HashMap<String, Integer> monthToValue = new HashMap<>();
        HashMap<Integer, String> valueToMonth = new HashMap<>();
        SortedMap<String, Integer> calendar = new TreeMap<>();
        
        monthToValue.put("January", 100);
        monthToValue.put("February", 200);
        monthToValue.put("March", 300);
        monthToValue.put("April", 400);
        monthToValue.put("May", 500);
        monthToValue.put("June", 600);
        monthToValue.put("July", 700);
        monthToValue.put("August", 800);
        monthToValue.put("September", 900);
        monthToValue.put("October", 1000);
        monthToValue.put("November", 1100);
        monthToValue.put("December", 1200);
        
        valueToMonth.put(100, "January");
        valueToMonth.put(200, "February");
        valueToMonth.put(300, "March");
        valueToMonth.put(400, "April");
        valueToMonth.put(500, "May");
        valueToMonth.put(600, "June");
        valueToMonth.put(700, "July");
        valueToMonth.put(800, "August");
        valueToMonth.put(900, "September");
        valueToMonth.put(1000, "October");
        valueToMonth.put(1100, "November");
        valueToMonth.put(1200, "December");
        
        while (n-- > 0) {
            String input = sc.next();
            String name = sc.next();
            if (input.equals("ADD")) {
                if (!calendar.containsKey(name))
                    calendar.put(name, monthToValue.get(sc.next()) + sc.nextInt());
                else {
                    sc.next();
                    sc.next();
                }
            } else if (input.equals("DELETE")) {
                if (calendar.containsKey(name))
                    calendar.remove(name);
            } else if (input.equals("RESCHEDULE")) {
                if (calendar.containsKey(name))
                    calendar.put(name, monthToValue.get(sc.next()) + sc.nextInt());
                else {
                    sc.next();
                    sc.next();
                }
            } else {
                if (calendar.containsKey(name)) {
                    System.out.println(valueToMonth.get((calendar.get(name)/100)*100) + " " + calendar.get(name)%100);
                } else {
                    System.out.println("NOT SCHEDULED");
                }
            }
        }
        
        calendar = sortByValues(calendar);
        for (String name : calendar.keySet()){
            System.out.print(name + " ");
        }
        sc.close();
    }

    static SortedMap<String, Integer> sortByValues(SortedMap<String, Integer> map) {
        Comparator<String> valueComparator = new Comparator<String>() {
            public int compare(String s1, String s2) {
                int compare = map.get(s1).compareTo(map.get(s2));
                if (compare == 0)
                    return s1.compareTo(s2);
                else
                    return compare;
            }
        };
        SortedMap<String, Integer> sortedByValues = new TreeMap<String, Integer>(valueComparator);
        sortedByValues.putAll(map);
        return sortedByValues;
    }
	
}