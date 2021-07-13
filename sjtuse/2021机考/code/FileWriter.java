package code;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;

/**
 * 用于输出文件
 */
public class FileWriter {
    public static void write(String filePath,String text){
        try {

            File f = new File(filePath);
            FileOutputStream fop = new FileOutputStream(f);
            // 构建FileOutputStream对象,文件不存在会自动新建
            OutputStreamWriter writer = new OutputStreamWriter(fop, "UTF-8");
            // 构建OutputStreamWriter对象,参数可以指定编码,默认为操作系统默认编码,windows上是gbk
            writer.append(text);
            writer.close();
            // 关闭写入流,同时会把缓冲区内容写入文件,所以上面的注释掉
            fop.close();
            // 关闭输出流,释放系统资源
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
