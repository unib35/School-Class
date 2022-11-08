package javatpcproject;

import java.io.InputStream;
import org.json.JSONArray;
import org.json.JSONObject;
import org.json.JSONTokener;

public class JavaTPCProject_C {
    public static void main(String args[]){
        String src = "info.json";
        InputStream is = JavaTPCProject_C.class.getResourceAsStream(src);
        if(is == null){
          throw new NullPointerException("Cannot find resource file");
        }
        //json 문자들이 토큰화되어 메모리에 올라감
        JSONTokener tokener = new JSONTokener(is);
        //json 토큰을 객체화
        JSONObject object = new JSONObject(tokener);
        JSONArray students = object.getJSONArray("students");
        for(int i=0;i<students.length();i++){
            //object를 JSONObject에 들어가기때문에 다운캐스팅 필요
            JSONObject student = (JSONObject)students.get(i);
            System.out.print(student.get("name") + "\t");
            System.out.print(student.get("address") + "\t");
            System.out.print(student.get("phone") + "\t");

            
        }
        
    }
    
}
