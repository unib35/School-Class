package javatpcproject;

import org.json.JSONArray;
import org.json.JSONObject;

public class JavaTPCProject_B {
    public static void main(String args[]){
        JSONObject student1 = new JSONObject();
        student1.put("name", "lee");
        student1.put("phone", "010-8978-0178");
        student1.put("address", "Gimhae");
       
        
        JSONArray students = new JSONArray();
        students.put(student1);
        
        student1.put("name", "kim");
        student1.put("phone", "010-1234-0178");
        student1.put("address", "Busan");
        students.put(student1);
        
        JSONObject studentarr = new JSONObject();
        studentarr.put("students", students);
        System.out.println(studentarr.toString(1));
        
        
        
    }
}
