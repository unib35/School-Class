package javatpcproject;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import org.json.JSONArray;
import org.json.JSONObject;
import org.json.JSONTokener;


public class JavaTPCProject_D {
    public static void main(String args[]){
        String apiURL = "https://naveropenapi.apigw.ntruss.com/map-geocode/v2/geocode?query=";
        String client_id = "idx6p03s3a";
        String client_secret="54lrPZEsesDLEmIw6IqoW251VWzU3bHAWi5GBmSZ";
    
        BufferedReader io = new BufferedReader(new InputStreamReader(System.in));
        try{
            System.out.print("주소를 입력하세요 : ");
            String address = io.readLine();
            String addr = URLEncoder.encode(address, "UTF-8"); //문자열 공백제거
            String reqUrl = apiURL + addr; 
            
            URL url = new URL(reqUrl);
            HttpURLConnection con = (HttpURLConnection)url.openConnection();
            con.setRequestMethod("GET");
            con.setRequestProperty("X-NCP-APIGW-API-KEY-ID", client_id);
            con.setRequestProperty("X-NCP-APIGW-API-KEY", client_secret);
            
            BufferedReader br;
            int responseCode = con.getResponseCode(); //응답 코드로 성공여부 확인
            //200은 성공
            if(responseCode == 200){
                br = new BufferedReader(new InputStreamReader(con.getInputStream(), "UTF-8"));
            } else{
                br = new BufferedReader(new InputStreamReader(con.getInputStream(), "UTF-8"));
            }
            
            String line;
            StringBuffer response = new StringBuffer();
            while((line = br.readLine()) != null){
                response.append(line);
            }
            br.close();
            
            JSONTokener tokener = new JSONTokener(response.toString());
            JSONObject object = new JSONObject(tokener);
            //System.out.println(object.toString(2));
            
            JSONArray arr = object.getJSONArray("addresses");
            for(int i =0;i<arr.length();i++){
                JSONObject temp = (JSONObject)arr.get(i);
                System.out.println("주소 : " + temp.get("roadAddress"));
                System.out.println("지번주소 : " + temp.get("jibunAddress"));
                System.out.println("경도 : " + temp.get("x"));
                System.out.println("위도 : " + temp.get("y"));
            }
            
        } catch(Exception e){
            e.printStackTrace();
        }
    }
    
}
