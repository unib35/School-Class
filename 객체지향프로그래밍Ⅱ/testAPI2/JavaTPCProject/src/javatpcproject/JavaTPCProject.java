package javatpcproject;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import kr.inflearn.BookDTO;

public class JavaTPCProject {

    public static void main(String[] args) {
        BookDTO dto = new BookDTO("LEE", 20000, "DEU", 60);
        
        Gson g = new Gson();
        //Object(BookDTO) -> json
        String dtojson = g.toJson(dto);
        //System.out.println(dtojson);
        
        //json -> Object(BookDTO)
        BookDTO dto1 = g.fromJson(dtojson, BookDTO.class); //json 파일을 BookDTO 클래스로 바꾼다.
        System.out.println(dto1);
        //System.out.println(dto1.getPage());
        
        //Object(List<BookDTO>) -> json(String)
        List<BookDTO> lst = new ArrayList<BookDTO>();
        lst.add(new BookDTO("java1,", 22000, "deucom", 505));
        lst.add(new BookDTO("java2,", 23000, "deucom", 605));
        lst.add(new BookDTO("java3,", 24000, "deucom", 1205));
        String lstjson = g.toJson(lst);
        System.out.println(lstjson);
        
        //json -> Object(List<BookDTO>)
        List<BookDTO> lst1 = g.fromJson(lstjson, new TypeToken<List<BookDTO>>(){}.getType());
        for(BookDTO vo : lst1){
            System.out.println(vo);
        }
        
        
        
        System.out.println(lst1.get(2).getPage() + "pages");
    }
    
}
